/******************************************************************************
Filename   : rvm_platform_STM32F767IG.h
Author     : pry
Date       : 26/06/2017
Licence    : The Unlicense; see LICENSE for details.
Description: The configuration file for STM32F767IG. The values listed here should
             be in accordance with that in the kernel.
******************************************************************************/

/* Defines *******************************************************************/
/* The generator must be enabled to use this */
/* Kernel configurations - keep the same with the kernel *********************/
/* The virtual memory start address for the kernel objects */
#define RVM_KMEM_VA_START                               (0x20003000)
/* The size of the kernel object virtual memory */
#define RVM_KMEM_SIZE                                   (0xD000)
/* The granularity of kernel memory allocation, order of 2 in bytes */
#define RVM_KMEM_SLOT_ORDER                             (4)
/* The maximum number of preemption priority levels in the system.
 * This parameter must be divisible by the word length - 32 is usually sufficient */
#define RVM_MAX_PREEMPT_PRIO                            (32)
/* Number of virtual priorities in the system */
#define RVM_MAX_PREEMPT_VPRIO                           (32)
/* Number of events */
#define RVM_EVT_NUM                                     (10)
/* Number of mappings */
#define RVM_MAP_NUM                                     (128)

/* Initial kernel object capability limit */
#define RVM_A7M_CAP_BOOT_FRONTIER                       (9)
/* Initial kernel object memory limit */
#define RVM_A7M_KMEM_BOOT_FRONTIER                      (0x400)
/* Number of MPU regions available */
#define RVM_A7M_MPU_REGIONS                             (8)
/* Init process's first thread's entry point address */
#define RVM_A7M_INIT_ENTRY                              (0x08004000|0x01)
/* Init process's first thread's stack address */
#define RVM_A7M_INIT_STACK                              (0x2001FFF0)
/* What is the FPU type? */
#define RVM_A7M_FPU_TYPE                                (RVM_A7M_FPV5_DP)
/* Interrupt flag address */
#define RVM_A7M_VECT_FLAG_ADDR                          (0x2000FC00)
/* Shared interrupt flag region address - always 512B memory for ARMv7-M */
#define RVM_A7M_EVT_FLAG_ADDR                           (0x2000FE00)

/* Fixed info ****************************************************************/
/* What is the vector number excluding system vectors? */
#define RVM_A7M_VECT_NUM                                (110)

/* Syslib configurations *****************************************************/
/* Stack redundancy */
#define RVM_STACK_SAFE_RDCY                             (0x10)
/* Daemon process stack address and size, in bytes */
#define RVM_SFTD_STACK_BASE                             (0x20000000)
#define RVM_SFTD_STACK_SIZE                             (1024)
#define RVM_TIMD_STACK_BASE                             (0x20000000)
#define RVM_TIMD_STACK_SIZE                             (1024)
#define RVM_VMMD_STACK_BASE                             (0x20000000)
#define RVM_VMMD_STACK_SIZE                             (1024)
#define RVM_VCTD_STACK_BASE                             (0x20000000)
#define RVM_VCTD_STACK_SIZE                             (1024)

/* Is debugging output enabled? */
#define RVM_DEBUG_LOG                                   RVM_TRUE

#define RVM_A7M_USART1_ISR                              RVM_A7M_REG(0x4001101C)
#define RVM_A7M_USART1_TDR                              RVM_A7M_REG(0x40011028)

/* Print characters to console */
#define RVM_A7M_PUTCHAR(CHAR) \
do \
{ \
    RVM_A7M_USART1_TDR=(CHAR); \
    while((RVM_A7M_USART1_ISR&0x40)==0); \
} \
while(0)
/* End Defines ***************************************************************/

/* End Of File ***************************************************************/

/* Copyright (C) Evo-Devo Instrum. All rights reserved ***********************/
