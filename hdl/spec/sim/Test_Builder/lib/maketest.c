//---------------------------------------------------------------------------
/*
 * Name:  vdma_gen.c
 *
 * Description:  Main Program for Generating VDMA Sequencer Code.
 *
*/

#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"
//#include "malloc.h"

#include "vdma_seqcode.h"
//#include "vdma_gen_struct.h"

#define  VDMA_DRAM_SIZE   2048 // Size in DW of the descriptor RAM
#define  MAX_LABELS       2048 // Maximum number of labels
#define  MAX_COMMENT 200
#define  MAX_LABEL_SIZE   32

struct
{
	DWORD data;
	char *label;
	char comment[MAX_COMMENT+1];
} dram[VDMA_DRAM_SIZE+1];

struct 
{
	char *label;                  // label string
	int address;                  // Address of the label
} vdma_labels[MAX_LABELS];


int label_compare(char *string1, char *string2)
{
	if((string1 == NULL) || (string2 == NULL) || (*string1 == '\0') || (*string2 == '\0'))
		return(0); /* no match */
	else if(strlen(string1) != strlen(string2))
		return(0); /* no match */
	else
		return(strcmp(string1, string2) == 0);
}

int program_address = 0;
int label_pointer = 0;
char last_label[100];
char out_filename[256];

FILE *outfp;
FILE *infp;

#include "model.c"
#include "vdma_seqcode_lib.c"

#define BAR0_ADDR_H ((DWORD)0xFF000000)
#define BAR0_ADDR_L ((DWORD)0x10000000)

//================================================================================================
//
// Do Some Initialization
//
//================================================================================================

maketest_init(argc,argv)
int argc;
char *argv[];
{
	int i;
	char *src, *dst;
//	char filename[256];

	src = argv[0];
	dst = out_filename;

	for(i=0; i<250; i++)
	{
		*dst = *src;
		if(*src == '\0')
		{
			dst[0]='.';
			dst[1]='h';
			dst[2]='e';
			dst[3]='x';
			dst[4]='\0';
			break;
		}
		if(*src == '.')
		{
			dst[1]='h';
			dst[2]='e';
			dst[3]='x';
			dst[4]='\0';
			break;
		}
		dst++;
		src++;
	}

	/*	Open the Hex Output File */
	if((outfp = fopen(out_filename,"wb")) == NULL)
	{
		fprintf(stderr, "Couldn't open file %s for writing\n", out_filename);
		exit(-2);
	}
	clearerr(outfp);
	fprintf(stderr, "Output file %s is open...\n", out_filename);

	/* initialize the label structure */
	for(i = 0; i < MAX_LABELS; i++)
	{
		vdma_labels[i].label     = NULL;
		vdma_labels[i].address   = -1;
	}

	/* initialize the descriptor RAM structure */
	for(i = 0; i < VDMA_DRAM_SIZE; i++)
	{
		dram[i].label      = NULL;
		dram[i].data       = 0;
		dram[i].comment[0] = '\0';
	}

	program_address = 0;
	label_pointer = 0;
	last_label[0] = '\0';

	fprintf(stderr, "Initialization complete\n");
	comment("***********************************************************************************");
	comment("*** Warning: this file is automatically generated.                              ***");
	comment("***********************************************************************************");
	comment("*** Do not edit this file directly as it is not the source!                     ***");
	comment("***********************************************************************************");

}


vdma_process(U64 descriptor_base)
{
	int i=0;
	int lines=0;
	int im;
	int address;

	fprintf(stderr, "Pass one complete:\n");
	fprintf(stderr, "    Processed %d labels\n", label_pointer);
	fprintf(stderr, "    Ended with program address=0x%04X\n", program_address);

//---------------------------------------------------------------------------------
// 2nd Pass: Now resolve label references
//---------------------------------------------------------------------------------
	for(program_address = 0; program_address < VDMA_DRAM_SIZE; program_address++)
	{
		if((dram[program_address].label != NULL) && (dram[program_address].label[0] != '\0')) /* resolve the label */
		{
//fprintf(stderr, "Resolving label %s at address=0x%04X\n", dram[program_address].label, program_address);
			if(vdma_label_lookup(dram[program_address].label, &address))
			{
				dram[program_address].data |= address & 0xFFFF;
			}
			else
			{
				if((dram[program_address].label[0] == '0') && (tolower(dram[program_address].label[1]) == 'x')) // case of the label being a number
				{
					if(sscanf(&dram[program_address].label[2], "%x", &im) == 1)
						dram[program_address].data |= im & 0xFFFF;
					else
						fprintf(stderr, "ERROR: could not resolve label %s. Appears to be a hex value?\n", dram[program_address].label);
				}
				else
					fprintf(stderr, "ERROR: could not resolve label %s\n", dram[program_address].label);
			}
			i++;
		}

//fprintf(stderr, "%d\n", program_address);

		if(dram[program_address].label != NULL)
		{
			fprintf(outfp, "0x%04X\t0x%08lX\t%s\n", program_address, dram[program_address].data, dram[program_address].comment);
			fprintf(stdout, "-- 0x%04X 0x%08lX %s\n", program_address, dram[program_address].data, dram[program_address].comment);
			wr(descriptor_base + (program_address*4), 0xF, dram[program_address].data);
			//fprintf(stdout, "wrb %08lX%08lX F %08lX\n", 0xFF000000, program_address, dram[program_address].data);
			lines++;
		}


	}


	fprintf(outfp, "// Label Listing:\n");
	// Put the label table into the output file
	for(i = 0; i < label_pointer; i++)
	{
		fprintf(outfp, "// 0x%04X : \"%s\"\n", vdma_labels[i].address, vdma_labels[i].label);
	}


//	label_pointer = 0;

	fprintf(stderr, "Pass two complete:\n");
	fprintf(stderr, "    Substituted %d references in %d words of program and data space\n", i, lines);
	fprintf(stderr, "    Created output file \"%s\"\n", out_filename);



}


