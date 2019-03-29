/*
 * Copyright 2019, DornerWorks
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DORNERWORKS_BSD)
 */
#ifndef VMLINUX_ZYNQMP_H
#define VMLINUX_ZYNQMP_H

#include <sel4arm-vmm/vm.h>

#define INTERRUPT_CORE_VIRT_MAINT         25
#define INTERRUPT_CORE_HYP_TIMER          26
#define INTERRUPT_CORE_VIRT_TIMER         27
#define INTERRUPT_CORE_LEGACY_FIQ         28
#define INTERRUPT_CORE_SEC_PHYS_TIMER     29
#define INTERRUPT_CORE_NONSEC_PHYS_TIMER  30
#define INTERRUPT_CORE_LEGACY_IRQ         31
#define INTERRUPT_RPU0_APM                40
#define INTERRUPT_RPU1_APM                41
#define INTERRUPT_OCM                     42
#define INTERRUPT_LPD_APB                 43
#define INTERRUPT_RPU0_ECC                44
#define INTERRUPT_RPU1_ECC                45
#define INTERRUPT_NAND                    46
#define INTERRUPT_QSPI                    47
#define INTERRUPT_GPIO                    48
#define INTERRUPT_I2C0                    49
#define INTERRUPT_I2C1                    50
#define INTERRUPT_SPI0                    51
#define INTERRUPT_SPI1                    52
#define INTERRUPT_UART0                   53
#define INTERRUPT_UART1                   54
#define INTERRUPT_CAN0                    55
#define INTERRUPT_CAN1                    56
#define INTERRUPT_LPD_APM                 57
#define INTERRUPT_RTC_ALARM               58
#define INTERRUPT_RTC_SECONDS             59
#define INTERRUPT_CLKMON                  60
#define INTERRUPT_IPI_CH7                 61
#define INTERRUPT_IPI_CH8                 62
#define INTERRUPT_IPI_CH9                 63
#define INTERRUPT_IPI_CH10                64
#define INTERRUPT_IPI_CH2                 65
#define INTERRUPT_IPI_CH1                 66
#define INTERRUPT_IPI_CH0                 67
#define INTERRUPT_TTC0_0                  68
#define INTERRUPT_TTC0_1                  69
#define INTERRUPT_TTC0_2                  70
#define INTERRUPT_TTC1_0                  71
#define INTERRUPT_TTC1_1                  72
#define INTERRUPT_TTC1_2                  73
#define INTERRUPT_TTC2_0                  74
#define INTERRUPT_TTC2_1                  75
#define INTERRUPT_TTC2_2                  76
#define INTERRUPT_TTC3_0                  77
#define INTERRUPT_TTC3_1                  78
#define INTERRUPT_TTC3_2                  79
#define INTERRUPT_SDIO0                   80
#define INTERRUPT_SDIO1                   81
#define INTERRUPT_SDIO0_WAKEUP            82
#define INTERRUPT_SDIO1_WAKEUP            83
#define INTERRUPT_LPD_SWDT                84
#define INTERRUPT_CSU_SWDT                85
#define INTERRUPT_LPD_ATB                 86
#define INTERRUPT_AIB                     87
#define INTERRUPT_SYSMON                  88
#define INTERRUPT_GEM0                    89
#define INTERRUPT_GEM0_WAKEUP             90
#define INTERRUPT_GEM1                    91
#define INTERRUPT_GEM1_WAKEUP             92
#define INTERRUPT_GEM2                    93
#define INTERRUPT_GEM2_WAKEUP             94
#define INTERRUPT_GEM3                    95
#define INTERRUPT_GEM3_WAKEUP             96
#define INTERRUPT_USB0_ENDPOINT_0         97
#define INTERRUPT_USB0_ENDPOINT_1         98
#define INTERRUPT_USB0_ENDPOINT_2         99
#define INTERRUPT_USB0_ENDPOINT_3         100
#define INTERRUPT_USB0_OTG                101
#define INTERRUPT_USB1_ENDPOINT_0         102
#define INTERRUPT_USB1_ENDPOINT_1         103
#define INTERRUPT_USB1_ENDPOINT_2         104
#define INTERRUPT_USB1_ENDPOINT_3         105
#define INTERRUPT_USB1_OTG                106
#define INTERRUPT_USB0_WAKEUP             107
#define INTERRUPT_USB1_WAKEUP             108
#define INTERRUPT_LPD_DMA_0               109
#define INTERRUPT_LPD_DMA_1               110
#define INTERRUPT_LPD_DMA_2               111
#define INTERRUPT_LPD_DMA_3               112
#define INTERRUPT_LPD_DMA_4               113
#define INTERRUPT_LPD_DMA_5               114
#define INTERRUPT_LPD_DMA_6               115
#define INTERRUPT_LPD_DMA_7               116
#define INTERRUPT_CSU                     117
#define INTERRUPT_CSU_DMA                 118
#define INTERRUPT_EFUSE                   119
#define INTERRUPT_XPPU                    120
#define INTERRUPT_PL_PS_GROUP0_0          121
#define INTERRUPT_PL_PS_GROUP0_1          122
#define INTERRUPT_PL_PS_GROUP0_2          123
#define INTERRUPT_PL_PS_GROUP0_3          124
#define INTERRUPT_PL_PS_GROUP0_4          125
#define INTERRUPT_PL_PS_GROUP0_5          126
#define INTERRUPT_PL_PS_GROUP0_6          127
#define INTERRUPT_PL_PS_GROUP0_7          128
#define INTERRUPT_PL_PS_GROUP1_0          136
#define INTERRUPT_PL_PS_GROUP1_1          137
#define INTERRUPT_PL_PS_GROUP1_2          138
#define INTERRUPT_PL_PS_GROUP1_3          139
#define INTERRUPT_PL_PS_GROUP1_4          140
#define INTERRUPT_PL_PS_GROUP1_5          141
#define INTERRUPT_PL_PS_GROUP1_6          142
#define INTERRUPT_PL_PS_GROUP1_7          143
#define INTERRUPT_DDR                     144
#define INTERRUPT_FPD_SWDT                145
#define INTERRUPT_PCIE_MSI0               146
#define INTERRUPT_PCIE_MSI1               147
#define INTERRUPT_PCIE_INTX               148
#define INTERRUPT_PCIE_DMA                149
#define INTERRUPT_PCIE_MSC                150
#define INTERRUPT_DISPLAYPORT             151
#define INTERRUPT_FPD_APB                 152
#define INTERRUPT_FPD_ATB                 153
#define INTERRUPT_DPDMA                   154
#define INTERRUPT_FPD_ATM                 155
#define INTERRUPT_FPD_DMA_0               156
#define INTERRUPT_FPD_DMA_1               157
#define INTERRUPT_FPD_DMA_2               158
#define INTERRUPT_FPD_DMA_3               159
#define INTERRUPT_FPD_DMA_4               160
#define INTERRUPT_FPD_DMA_5               161
#define INTERRUPT_FPD_DMA_6               162
#define INTERRUPT_FPD_DMA_7               163
#define INTERRUPT_GPU                     164
#define INTERRUPT_SATA                    165
#define INTERRUPT_FPD_XMPU                166
#define INTERRUPT_APU_VCPUMNT_0           167
#define INTERRUPT_APU_VCPUMNT_1           168
#define INTERRUPT_APU_VCPUMNT_2           169
#define INTERRUPT_APU_VCPUMNT_3           170
#define INTERRUPT_CPU_CTI_0               171
#define INTERRUPT_CPU_CTI_1               172
#define INTERRUPT_CPU_CTI_2               173
#define INTERRUPT_CPU_CTI_3               174
#define INTERRUPT_PMU_COMM_0              175
#define INTERRUPT_PMU_COMM_1              176
#define INTERRUPT_PMU_COMM_2              177
#define INTERRUPT_PMU_COMM_3              178
#define INTERRUPT_APU_COMM_0              179
#define INTERRUPT_APU_COMM_1              180
#define INTERRUPT_APU_COMM_2              181
#define INTERRUPT_APU_COMM_3              182
#define INTERRUPT_L2_CACHE                183
#define INTERRUPT_APU_EXTERROR            184
#define INTERRUPT_APU_REGERROR            185
#define INTERRUPT_CCI                     186
#define INTERRUPT_SMMU                    187
#define MAX_IRQ                           200

static const int linux_pt_irqs[] = {
    INTERRUPT_CORE_VIRT_TIMER,
};

#define LINUX_RAM_BASE       (0x800000000)
#define LINUX_RAM_END        (0x810000000)
#define LINUX_RAM_SIZE       (LINUX_RAM_END - LINUX_RAM_BASE)
#define LINUX_RAM_PADDR_BASE LINUX_RAM_BASE

/* the offset between actual physcial memory and guest physical memory */
#define LINUX_RAM_OFFSET  (0)
#define DTB_ADDR          (LINUX_RAM_BASE + 0x0C000000)
#define INITRD_MAX_SIZE   0x01900000 //25 MB
#define INITRD_ADDR       (DTB_ADDR - INITRD_MAX_SIZE) //0x80A700000

#endif /* VMLINUX_H */