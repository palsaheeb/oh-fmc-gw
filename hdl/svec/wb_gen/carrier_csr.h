/*
  Register definitions for slave core: SVEC carrier control and status registers

  * File           : svec_carrier_csr.h
  * Author         : auto-generated by wbgen2 from svec_carrier_csr.wb
  * Created        : Fri Jul  5 10:44:08 2013
  * Standard       : ANSI C

    THIS FILE WAS GENERATED BY wbgen2 FROM SOURCE FILE svec_carrier_csr.wb
    DO NOT HAND-EDIT UNLESS IT'S ABSOLUTELY NECESSARY!

*/

#ifndef __WBGEN2_REGDEFS_SVEC_CARRIER_CSR_WB
#define __WBGEN2_REGDEFS_SVEC_CARRIER_CSR_WB

#include <inttypes.h>

#if defined( __GNUC__)
#define PACKED __attribute__ ((packed))
#else
#error "Unsupported compiler?"
#endif

#ifndef __WBGEN2_MACROS_DEFINED__
#define __WBGEN2_MACROS_DEFINED__
#define WBGEN2_GEN_MASK(offset, size) (((1<<(size))-1) << (offset))
#define WBGEN2_GEN_WRITE(value, offset, size) (((value) & ((1<<(size))-1)) << (offset))
#define WBGEN2_GEN_READ(reg, offset, size) (((reg) >> (offset)) & ((1<<(size))-1))
#define WBGEN2_SIGN_EXTEND(value, bits) (((value) & (1<<bits) ? ~((1<<(bits))-1): 0 ) | (value))
#endif


/* definitions for register: Carrier type and PCB version */

/* definitions for field: PCB revision in reg: Carrier type and PCB version */
#define CARRIER_CSR_CARRIER_PCB_REV_MASK      WBGEN2_GEN_MASK(0, 5)
#define CARRIER_CSR_CARRIER_PCB_REV_SHIFT     0
#define CARRIER_CSR_CARRIER_PCB_REV_W(value)  WBGEN2_GEN_WRITE(value, 0, 5)
#define CARRIER_CSR_CARRIER_PCB_REV_R(reg)    WBGEN2_GEN_READ(reg, 0, 5)

/* definitions for field: Reserved register in reg: Carrier type and PCB version */
#define CARRIER_CSR_CARRIER_RESERVED_MASK     WBGEN2_GEN_MASK(5, 11)
#define CARRIER_CSR_CARRIER_RESERVED_SHIFT    5
#define CARRIER_CSR_CARRIER_RESERVED_W(value) WBGEN2_GEN_WRITE(value, 5, 11)
#define CARRIER_CSR_CARRIER_RESERVED_R(reg)   WBGEN2_GEN_READ(reg, 5, 11)

/* definitions for field: Carrier type in reg: Carrier type and PCB version */
#define CARRIER_CSR_CARRIER_TYPE_MASK         WBGEN2_GEN_MASK(16, 16)
#define CARRIER_CSR_CARRIER_TYPE_SHIFT        16
#define CARRIER_CSR_CARRIER_TYPE_W(value)     WBGEN2_GEN_WRITE(value, 16, 16)
#define CARRIER_CSR_CARRIER_TYPE_R(reg)       WBGEN2_GEN_READ(reg, 16, 16)

/* definitions for register: Status */

/* definitions for field: FMC 1 presence in reg: Status */
#define CARRIER_CSR_STAT_FMC0_PRES            WBGEN2_GEN_MASK(0, 1)

/* definitions for field: FMC 2 presence in reg: Status */
#define CARRIER_CSR_STAT_FMC1_PRES            WBGEN2_GEN_MASK(1, 1)

/* definitions for field: System clock PLL status in reg: Status */
#define CARRIER_CSR_STAT_SYS_PLL_LCK          WBGEN2_GEN_MASK(2, 1)

/* definitions for field: DDR3 bank 4 calibration status in reg: Status */
#define CARRIER_CSR_STAT_DDR0_CAL_DONE        WBGEN2_GEN_MASK(3, 1)

/* definitions for field: DDR3 bank 5 calibration status in reg: Status */
#define CARRIER_CSR_STAT_DDR1_CAL_DONE        WBGEN2_GEN_MASK(4, 1)

/* definitions for field: Reserved in reg: Status */
#define CARRIER_CSR_STAT_RESERVED_MASK        WBGEN2_GEN_MASK(5, 27)
#define CARRIER_CSR_STAT_RESERVED_SHIFT       5
#define CARRIER_CSR_STAT_RESERVED_W(value)    WBGEN2_GEN_WRITE(value, 5, 27)
#define CARRIER_CSR_STAT_RESERVED_R(reg)      WBGEN2_GEN_READ(reg, 5, 27)

/* definitions for register: Control */

/* definitions for field: Front panel LED manual control in reg: Control */
#define CARRIER_CSR_CTRL_FP_LEDS_MAN_MASK     WBGEN2_GEN_MASK(0, 16)
#define CARRIER_CSR_CTRL_FP_LEDS_MAN_SHIFT    0
#define CARRIER_CSR_CTRL_FP_LEDS_MAN_W(value) WBGEN2_GEN_WRITE(value, 0, 16)
#define CARRIER_CSR_CTRL_FP_LEDS_MAN_R(reg)   WBGEN2_GEN_READ(reg, 0, 16)

/* definitions for field: Reserved in reg: Control */
#define CARRIER_CSR_CTRL_RESERVED_MASK        WBGEN2_GEN_MASK(16, 16)
#define CARRIER_CSR_CTRL_RESERVED_SHIFT       16
#define CARRIER_CSR_CTRL_RESERVED_W(value)    WBGEN2_GEN_WRITE(value, 16, 16)
#define CARRIER_CSR_CTRL_RESERVED_R(reg)      WBGEN2_GEN_READ(reg, 16, 16)

PACKED struct CARRIER_CSR_WB {
  /* [0x0]: REG Carrier type and PCB version */
  uint32_t CARRIER;
  /* [0x4]: REG Status */
  uint32_t STAT;
  /* [0x8]: REG Control */
  uint32_t CTRL;
};

#endif
