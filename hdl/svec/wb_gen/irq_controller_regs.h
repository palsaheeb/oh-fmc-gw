/*
  Register definitions for slave core: IRQ controller registers

  * File           : svec_irq_controller_regs.h
  * Author         : auto-generated by wbgen2 from svec_irq_controller_regs.wb
  * Created        : Fri Jul  5 10:18:32 2013
  * Standard       : ANSI C

    THIS FILE WAS GENERATED BY wbgen2 FROM SOURCE FILE svec_irq_controller_regs.wb
    DO NOT HAND-EDIT UNLESS IT'S ABSOLUTELY NECESSARY!

*/

#ifndef __WBGEN2_REGDEFS_SVEC_IRQ_CONTROLLER_REGS_WB
#define __WBGEN2_REGDEFS_SVEC_IRQ_CONTROLLER_REGS_WB

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


/* definitions for register: Multiple interrupt register */

/* definitions for register: Interrupt sources register  */

/* definitions for register: Interrupt enable mask register */

PACKED struct IRQ_CTRL_WB {
  /* [0x0]: REG Multiple interrupt register */
  uint32_t MULTI_IRQ;
  /* [0x4]: REG Interrupt sources register  */
  uint32_t SRC;
  /* [0x8]: REG Interrupt enable mask register */
  uint32_t EN_MASK;
};

#endif
