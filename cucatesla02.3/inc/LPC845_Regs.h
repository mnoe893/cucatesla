
/*
 * LPC845_Regs.h
 *
 *  Created on: 10 ene. 2022
 *      Author: gos
 */

#ifndef LPC845_REGS_H_
#define LPC845_REGS_H_

typedef signed char 	int8_t;
typedef unsigned char 	uint8_t;
typedef short 			int16_t;
typedef unsigned short 	uint16_t;
typedef int 			int32_t;
typedef unsigned int 	uint32_t;

#define   __I     	volatile const       /*!< Define permisos 'solo lectura' */

#define     __O     volatile             /*!< Define permisos 'solo escritura' */
#define     __IO    volatile             /*!< Define permisos 'lectura / escritura' */

/* Los siguientes defines deben usarce para miembros de estructuras */
#define     __IM     volatile const      /*! Define permisos 'solo lectura' para miembros de estructuras */
#define     __OM     volatile            /*! Define permisos 'solo escritura' para miembros de estructuras */
#define     __IOM    volatile            /*! Define permisos 'lectura / escritura' para miembros de estructuras */


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  SPI0_IRQn                    = 0,                /**< SPI0 interrupt */
  SPI1_IRQn                    = 1,                /**< SPI1 interrupt */
  DAC0_IRQn                    = 2,                /**< DAC0 interrupt */
  USART0_IRQn                  = 3,                /**< USART0 interrupt */
  USART1_IRQn                  = 4,                /**< USART1 interrupt */
  USART2_IRQn                  = 5,                /**< USART2 interrupt */
  Reserved22_IRQn              = 6,                /**< Reserved interrupt */
  I2C1_IRQn                    = 7,                /**< I2C1 interrupt */
  I2C0_IRQn                    = 8,                /**< I2C0 interrupt */
  SCT0_IRQn                    = 9,                /**< State configurable timer interrupt */
  MRT0_IRQn                    = 10,               /**< Multi-rate timer interrupt */
  CMP_CAPT_IRQn                = 11,               /**< Analog comparator interrupt or Capacitive Touch interrupt */
  WDT_IRQn                     = 12,               /**< Windowed watchdog timer interrupt */
  BOD_IRQn                     = 13,               /**< BOD interrupts */
  FLASH_IRQn                   = 14,               /**< flash interrupt */
  WKT_IRQn                     = 15,               /**< Self-wake-up timer interrupt */
  ADC0_SEQA_IRQn               = 16,               /**< ADC0 sequence A completion. */
  ADC0_SEQB_IRQn               = 17,               /**< ADC0 sequence B completion. */
  ADC0_THCMP_IRQn              = 18,               /**< ADC0 threshold compare and error. */
  ADC0_OVR_IRQn                = 19,               /**< ADC0 overrun */
  DMA0_IRQn                    = 20,               /**< DMA0 interrupt */
  I2C2_IRQn                    = 21,               /**< I2C2 interrupt */
  I2C3_IRQn                    = 22,               /**< I2C3 interrupt */
  CTIMER0_IRQn                 = 23,               /**< Timer interrupt */
  PIN_INT0_IRQn                = 24,               /**< Pin interrupt 0 or pattern match engine slice 0 interrupt */
  PIN_INT1_IRQn                = 25,               /**< Pin interrupt 1 or pattern match engine slice 1 interrupt */
  PIN_INT2_IRQn                = 26,               /**< Pin interrupt 2 or pattern match engine slice 2 interrupt */
  PIN_INT3_IRQn                = 27,               /**< Pin interrupt 3 or pattern match engine slice 3 interrupt */
  PIN_INT4_IRQn                = 28,               /**< Pin interrupt 4 or pattern match engine slice 4 interrupt */
  PIN_INT5_DAC1_IRQn           = 29,               /**< Pin interrupt 5 or pattern match engine slice 5 interrupt or DAC1 interrupt */
  PIN_INT6_USART3_IRQn         = 30,               /**< Pin interrupt 6 or pattern match engine slice 6 interrupt or UART3 interrupt */
  PIN_INT7_USART4_IRQn         = 31                /**< Pin interrupt 7 or pattern match engine slice 7 interrupt or UART4 interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */




/**
  \ingroup    CMSIS_core_register
  \defgroup   CMSIS_NVIC  Nested Vectored Interrupt Controller (NVIC)
  \brief      Type definitions for the NVIC Registers
  @{
 */

/**
  \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
typedef struct
{
  __IOM uint32_t ISER[1U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[31U];
  __IOM uint32_t ICER[1U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RESERVED1[31U];
  __IOM uint32_t ISPR[1U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[31U];
  __IOM uint32_t ICPR[1U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
  __IOM uint32_t IP[8U];                 /*!< Offset: 0x300 (R/W)  Interrupt Priority Register */
}  NVIC_Type;



#define ISE_SPI0		0x01
#define ISE_SPI1		0x02
#define ISE_DAC0		0x04
#define ISE_USART0		0x08
#define ISE_USART1		0x10
#define ISE_USART2		0x20

#define ISE_I2C1		0x80
#define ISE_I2C0		0x100
#define ISE_SCT			0x200
#define ISE_MRT			0x400

#define ISE_CMP			0x800
#define ISE_CAPT		0x800

#define ISE_WDG			0x1000
#define ISE_BOD			0x2000
#define ISE_FLASH		0x4000
#define ISE_WKT			0x8000
#define ISE_ADC_SEQA	0x10000
#define ISE_ADC_SEQB	0x20000
#define ISE_ADC_THCMP	0x40000
#define ISE_ADC_OVR		0x80000
#define ISE_SDMA		0x100000
#define ISE_I2C2		0x200000
#define ISE_I2C3		0x400000
#define ISE_CT32B0		0x800000
#define ISE_PINT0		0x1000000
#define ISE_PINT1		0x2000000
#define ISE_PINT2		0x4000000
#define ISE_PINT3		0x8000000
#define ISE_PINT4		0x10000000
#define ISE_PINT5		0x20000000
#define ISE_PINT6		0x40000000
#define ISE_PINT7		0x80000000

#define ISE_DAC1		0x20000000
#define ISE_USART3		0x40000000
#define ISE_USART4		0x80000000

#define SCS_BASE            (0xE000E000UL)                            /*!< System Control Space Base Address */
#define NVIC_BASE           (SCS_BASE +  0x0100UL)                    /*!< NVIC Base Address */
#define NVIC                ((NVIC_Type      *)     NVIC_BASE     )   /*!< NVIC configuration struct */

/*@} end of group CMSIS_NVIC */


//!< /////////////		SYSTICK		///////////////////////////

	//!< 0xE000E010UL: Registro de control del SysTick:
#define 	SYSTICK		( (systick_t *) 0xE000E010UL )

//!< Tipo de dato específico para manejar el SYSTICK
typedef struct
{
	union{
		__IO uint32_t SYST_CSR;
		struct{
			__IO uint32_t ENABLE:1;
			__IO uint32_t TICKINT:1;
			__IO uint32_t CLKSOURCE:1;
			__IO uint32_t RESERVED0:13; //bit 3 a 15
			__IO uint32_t COUNTFLAG:1;
			__IO uint32_t RESERVED1:15; //bit 17 a 31
		}bits;
	};
	__IO uint32_t SYST_RVR;
	__IO uint32_t SYST_CVR;
	__I uint32_t  SYST_CALIB;
}systick_t;

#define	SYST_CSR		SYSTICK->SYST_CSR
#define	ENABLE			SYSTICK->bits.ENABLE
#define	TICKINT			SYSTICK->bits.TICKINT
#define	CLKSOURCE		SYSTICK->bits.CLKSOURCE
#define	COUNTFLAG		SYSTICK->bits.COUNTFLAG
#define	SYST_RVR		SYSTICK->SYST_RVR
#define	SYST_CVR		SYSTICK->SYST_CVR
#define	SYST_CALIB		SYSTICK->SYST_CALIB

/* ----------------------------------------------------------------------------
   -- SWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SWM_Peripheral_Access_Layer SWM Peripheral Access Layer
 * @{
 */

/** SWM - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint32_t PINASSIGN0;                        /**< Pin assign register 0. Assign movable functions U0_TXD, U0_RXD, U0_RTS, U0_CTS., offset: 0x0 */
      __IO uint32_t PINASSIGN1;                        /**< Pin assign register 1. Assign movable functions U0_SCLK, U1_TXD, U1_RXD, U1_RTS., offset: 0x4 */
      __IO uint32_t PINASSIGN2;                        /**< Pin assign register 2. Assign movable functions U1_CTS, U1_SCLK, U2_TXD, U2_RXD., offset: 0x8 */
      __IO uint32_t PINASSIGN3;                        /**< Pin assign register 3. Assign movable function U2_RTS, U2_CTS, U2_SCLK, SPI0_SCK., offset: 0xC */
      __IO uint32_t PINASSIGN4;                        /**< Pin assign register 4. Assign movable functions SPI0_MOSI, SPI0_MISO, SPI0_SSEL0, SPI0_SSEL1., offset: 0x10 */
      __IO uint32_t PINASSIGN5;                        /**< Pin assign register 5. Assign movable functions SPI0_SSEL2, SPI0_SSEL3, SPI1_SCK, SPI1_MOSI, offset: 0x14 */
      __IO uint32_t PINASSIGN6;                        /**< Pin assign register 6. Assign movable functions SPI1_MISO, SPI1_SSEL0, SPI1_SSEL1, SCT0_IN0., offset: 0x18 */
      __IO uint32_t PINASSIGN7;                        /**< Pin assign register 7. Assign movable functions SCT_IN1, SCT_IN2, SCT_IN3, SCT_OUT0., offset: 0x1C */
      __IO uint32_t PINASSIGN8;                        /**< Pin assign register 8. Assign movable functions SCT_OUT1, SCT_OUT2, SCT_OUT3, SCT_OUT4., offset: 0x20 */
      __IO uint32_t PINASSIGN9;                        /**< Pin assign register 9. Assign movable functions SCT_OUT5, SCT_OUT6, I2C1_SDA, I2C1_SCL., offset: 0x24 */
      __IO uint32_t PINASSIGN10;                       /**< Pin assign register 10. Assign movable functions I2C2_SDA, I2C2_SCL, I2C3_SDA, I2C3_SCL., offset: 0x28 */
      __IO uint32_t PINASSIGN11;                       /**< Pin assign register 11. Assign movable functions COMP0_OUT, CLKOUT, GPIOINT_BMATCH, UART3_TXD, offset: 0x2C */
      __IO uint32_t PINASSIGN12;                       /**< Pin assign register 12. Assign movable functions UART3_RXD, UART3_SCLK, UART4_TXD, UART4_RXD., offset: 0x30 */
      __IO uint32_t PINASSIGN13;                       /**< Pin assign register 13. Assign movable functions UART4_SCLK, T0_MAT0, T0_MAT1, T0_MAT2., offset: 0x34 */
      __IO uint32_t PINASSIGN14;                       /**< Pin assign register 14. Assign movable functions T0_MAT3, T0_CAP0, T0_CAP1, T0_CAP2., offset: 0x38 */
    } PINASSIGN;
    __IO uint32_t PINASSIGN_DATA[15];                /**< Pin assign register, array offset: 0x0, array step: 0x4 */
  };
       uint8_t RESERVED_0[388];
  __IO uint32_t PINENABLE0;                        /**< Pin enable register 0. Enables fixed-pin functions ACMP_I0, ACMP_I1, SWCLK, SWDIO, XTALIN, XTALOUT, RESET, CLKIN, VDDCMP and so on., offset: 0x1C0 */
  __IO uint32_t PINENABLE1;                        /**< Pin enable register 1. Enables fixed-pin functions CAPT_X4, CAPT_X5, CAPT_X6, CAPT_X7, CAPT_X8, CAPT_X4, CAPT_YL and CAPT_YH., offset: 0x1C4 */
} SWM_Type;

/* ----------------------------------------------------------------------------
   -- SWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SWM_Register_Masks SWM Register Masks
 * @{
 */

/*! @name PINASSIGN0 - Pin assign register 0. Assign movable functions U0_TXD, U0_RXD, U0_RTS, U0_CTS. */
/*! @{ */
#define SWM_PINASSIGN0_U0_TXD_O_MASK             (0xFFU)
#define SWM_PINASSIGN0_U0_TXD_O_SHIFT            (0U)
/*! U0_TXD_O - U0_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35) .
 */
#define SWM_PINASSIGN0_U0_TXD_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_TXD_O_SHIFT)) & SWM_PINASSIGN0_U0_TXD_O_MASK)
#define SWM_PINASSIGN0_U0_RXD_I_MASK             (0xFF00U)
#define SWM_PINASSIGN0_U0_RXD_I_SHIFT            (8U)
/*! U0_RXD_I - U0_RXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN0_U0_RXD_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_RXD_I_SHIFT)) & SWM_PINASSIGN0_U0_RXD_I_MASK)
#define SWM_PINASSIGN0_U0_RTS_O_MASK             (0xFF0000U)
#define SWM_PINASSIGN0_U0_RTS_O_SHIFT            (16U)
/*! U0_RTS_O - U0_RTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN0_U0_RTS_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_RTS_O_SHIFT)) & SWM_PINASSIGN0_U0_RTS_O_MASK)
#define SWM_PINASSIGN0_U0_CTS_I_MASK             (0xFF000000U)
#define SWM_PINASSIGN0_U0_CTS_I_SHIFT            (24U)
/*! U0_CTS_I - U0_CTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN0_U0_CTS_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN0_U0_CTS_I_SHIFT)) & SWM_PINASSIGN0_U0_CTS_I_MASK)
/*! @} */

/*! @name PINASSIGN1 - Pin assign register 1. Assign movable functions U0_SCLK, U1_TXD, U1_RXD, U1_RTS. */
/*! @{ */
#define SWM_PINASSIGN1_U0_SCLK_IO_MASK           (0xFFU)
#define SWM_PINASSIGN1_U0_SCLK_IO_SHIFT          (0U)
/*! U0_SCLK_IO - U0_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN1_U0_SCLK_IO(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U0_SCLK_IO_SHIFT)) & SWM_PINASSIGN1_U0_SCLK_IO_MASK)
#define SWM_PINASSIGN1_U1_TXD_O_MASK             (0xFF00U)
#define SWM_PINASSIGN1_U1_TXD_O_SHIFT            (8U)
/*! U1_TXD_O - U1_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN1_U1_TXD_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_TXD_O_SHIFT)) & SWM_PINASSIGN1_U1_TXD_O_MASK)
#define SWM_PINASSIGN1_U1_RXD_I_MASK             (0xFF0000U)
#define SWM_PINASSIGN1_U1_RXD_I_SHIFT            (16U)
/*! U1_RXD_I - U1_RXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN1_U1_RXD_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_RXD_I_SHIFT)) & SWM_PINASSIGN1_U1_RXD_I_MASK)
#define SWM_PINASSIGN1_U1_RTS_O_MASK             (0xFF000000U)
#define SWM_PINASSIGN1_U1_RTS_O_SHIFT            (24U)
/*! U1_RTS_O - U1_RTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN1_U1_RTS_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN1_U1_RTS_O_SHIFT)) & SWM_PINASSIGN1_U1_RTS_O_MASK)
/*! @} */

/*! @name PINASSIGN2 - Pin assign register 2. Assign movable functions U1_CTS, U1_SCLK, U2_TXD, U2_RXD. */
/*! @{ */
#define SWM_PINASSIGN2_U1_CTS_I_MASK             (0xFFU)
#define SWM_PINASSIGN2_U1_CTS_I_SHIFT            (0U)
/*! U1_CTS_I - U1_CTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN2_U1_CTS_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_U1_CTS_I_SHIFT)) & SWM_PINASSIGN2_U1_CTS_I_MASK)
#define SWM_PINASSIGN2_U1_SCLK_IO_MASK           (0xFF00U)
#define SWM_PINASSIGN2_U1_SCLK_IO_SHIFT          (8U)
/*! U1_SCLK_IO - U1_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN2_U1_SCLK_IO(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_U1_SCLK_IO_SHIFT)) & SWM_PINASSIGN2_U1_SCLK_IO_MASK)
#define SWM_PINASSIGN2_U2_TXD_O_MASK             (0xFF0000U)
#define SWM_PINASSIGN2_U2_TXD_O_SHIFT            (16U)
/*! U2_TXD_O - U2_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN2_U2_TXD_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_U2_TXD_O_SHIFT)) & SWM_PINASSIGN2_U2_TXD_O_MASK)
#define SWM_PINASSIGN2_U2_RXD_I_MASK             (0xFF000000U)
#define SWM_PINASSIGN2_U2_RXD_I_SHIFT            (24U)
/*! U2_RXD_I - U2_RXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN2_U2_RXD_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN2_U2_RXD_I_SHIFT)) & SWM_PINASSIGN2_U2_RXD_I_MASK)
/*! @} */

/*! @name PINASSIGN3 - Pin assign register 3. Assign movable function U2_RTS, U2_CTS, U2_SCLK, SPI0_SCK. */
/*! @{ */
#define SWM_PINASSIGN3_U2_RTS_O_MASK             (0xFFU)
#define SWM_PINASSIGN3_U2_RTS_O_SHIFT            (0U)
/*! U2_RTS_O - U2_RTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN3_U2_RTS_O(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_U2_RTS_O_SHIFT)) & SWM_PINASSIGN3_U2_RTS_O_MASK)
#define SWM_PINASSIGN3_U2_CTS_I_MASK             (0xFF00U)
#define SWM_PINASSIGN3_U2_CTS_I_SHIFT            (8U)
/*! U2_CTS_I - U2_CTS function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN3_U2_CTS_I(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_U2_CTS_I_SHIFT)) & SWM_PINASSIGN3_U2_CTS_I_MASK)
#define SWM_PINASSIGN3_U2_SCLK_IO_MASK           (0xFF0000U)
#define SWM_PINASSIGN3_U2_SCLK_IO_SHIFT          (16U)
/*! U2_SCLK_IO - U2_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN3_U2_SCLK_IO(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_U2_SCLK_IO_SHIFT)) & SWM_PINASSIGN3_U2_SCLK_IO_MASK)
#define SWM_PINASSIGN3_SPI0_SCK_IO_MASK          (0xFF000000U)
#define SWM_PINASSIGN3_SPI0_SCK_IO_SHIFT         (24U)
/*! SPI0_SCK_IO - SPI0_SCK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN3_SPI0_SCK_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN3_SPI0_SCK_IO_SHIFT)) & SWM_PINASSIGN3_SPI0_SCK_IO_MASK)
/*! @} */

/*! @name PINASSIGN4 - Pin assign register 4. Assign movable functions SPI0_MOSI, SPI0_MISO, SPI0_SSEL0, SPI0_SSEL1. */
/*! @{ */
#define SWM_PINASSIGN4_SPI0_MOSI_IO_MASK         (0xFFU)
#define SWM_PINASSIGN4_SPI0_MOSI_IO_SHIFT        (0U)
/*! SPI0_MOSI_IO - SPI0_MOSI function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN4_SPI0_MOSI_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_SPI0_MOSI_IO_SHIFT)) & SWM_PINASSIGN4_SPI0_MOSI_IO_MASK)
#define SWM_PINASSIGN4_SPI0_MISO_IO_MASK         (0xFF00U)
#define SWM_PINASSIGN4_SPI0_MISO_IO_SHIFT        (8U)
/*! SPI0_MISO_IO - SPI0_MISIO function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN4_SPI0_MISO_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_SPI0_MISO_IO_SHIFT)) & SWM_PINASSIGN4_SPI0_MISO_IO_MASK)
#define SWM_PINASSIGN4_SPI0_SSEL0_IO_MASK        (0xFF0000U)
#define SWM_PINASSIGN4_SPI0_SSEL0_IO_SHIFT       (16U)
/*! SPI0_SSEL0_IO - SPI0_SSEL0 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN4_SPI0_SSEL0_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_SPI0_SSEL0_IO_SHIFT)) & SWM_PINASSIGN4_SPI0_SSEL0_IO_MASK)
#define SWM_PINASSIGN4_SPI0_SSEL1_IO_MASK        (0xFF000000U)
#define SWM_PINASSIGN4_SPI0_SSEL1_IO_SHIFT       (24U)
/*! SPI0_SSEL1_IO - SPI0_SSEL1 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN4_SPI0_SSEL1_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN4_SPI0_SSEL1_IO_SHIFT)) & SWM_PINASSIGN4_SPI0_SSEL1_IO_MASK)
/*! @} */

/*! @name PINASSIGN5 - Pin assign register 5. Assign movable functions SPI0_SSEL2, SPI0_SSEL3, SPI1_SCK, SPI1_MOSI */
/*! @{ */
#define SWM_PINASSIGN5_SPI0_SSEL2_IO_MASK        (0xFFU)
#define SWM_PINASSIGN5_SPI0_SSEL2_IO_SHIFT       (0U)
/*! SPI0_SSEL2_IO - SPI0_SSEL2 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN5_SPI0_SSEL2_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_SPI0_SSEL2_IO_SHIFT)) & SWM_PINASSIGN5_SPI0_SSEL2_IO_MASK)
#define SWM_PINASSIGN5_SPI0_SSEL3_IO_MASK        (0xFF00U)
#define SWM_PINASSIGN5_SPI0_SSEL3_IO_SHIFT       (8U)
/*! SPI0_SSEL3_IO - SPI0_SSEL3 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN5_SPI0_SSEL3_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_SPI0_SSEL3_IO_SHIFT)) & SWM_PINASSIGN5_SPI0_SSEL3_IO_MASK)
#define SWM_PINASSIGN5_SPI1_SCK_IO_MASK          (0xFF0000U)
#define SWM_PINASSIGN5_SPI1_SCK_IO_SHIFT         (16U)
/*! SPI1_SCK_IO - SPI1_SCK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN5_SPI1_SCK_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_SPI1_SCK_IO_SHIFT)) & SWM_PINASSIGN5_SPI1_SCK_IO_MASK)
#define SWM_PINASSIGN5_SPI1_MOSI_IO_MASK         (0xFF000000U)
#define SWM_PINASSIGN5_SPI1_MOSI_IO_SHIFT        (24U)
/*! SPI1_MOSI_IO - SPI1_MOSI function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN5_SPI1_MOSI_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN5_SPI1_MOSI_IO_SHIFT)) & SWM_PINASSIGN5_SPI1_MOSI_IO_MASK)
/*! @} */

/*! @name PINASSIGN6 - Pin assign register 6. Assign movable functions SPI1_MISO, SPI1_SSEL0, SPI1_SSEL1, SCT0_IN0. */
/*! @{ */
#define SWM_PINASSIGN6_SPI1_MISO_IO_MASK         (0xFFU)
#define SWM_PINASSIGN6_SPI1_MISO_IO_SHIFT        (0U)
/*! SPI1_MISO_IO - SPI1_MISO function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN6_SPI1_MISO_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_SPI1_MISO_IO_SHIFT)) & SWM_PINASSIGN6_SPI1_MISO_IO_MASK)
#define SWM_PINASSIGN6_SPI1_SSEL0_IO_MASK        (0xFF00U)
#define SWM_PINASSIGN6_SPI1_SSEL0_IO_SHIFT       (8U)
/*! SPI1_SSEL0_IO - SPI1_SSEL0 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN6_SPI1_SSEL0_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_SPI1_SSEL0_IO_SHIFT)) & SWM_PINASSIGN6_SPI1_SSEL0_IO_MASK)
#define SWM_PINASSIGN6_SPI1_SSEL1_IO_MASK        (0xFF0000U)
#define SWM_PINASSIGN6_SPI1_SSEL1_IO_SHIFT       (16U)
/*! SPI1_SSEL1_IO - SPI1_SSEL1 function assignment. The value is the pin number to be assigned to
 *    this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN6_SPI1_SSEL1_IO(x)          (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_SPI1_SSEL1_IO_SHIFT)) & SWM_PINASSIGN6_SPI1_SSEL1_IO_MASK)
#define SWM_PINASSIGN6_SCT0_GPIO_IN_A_I_MASK     (0xFF000000U)
#define SWM_PINASSIGN6_SCT0_GPIO_IN_A_I_SHIFT    (24U)
/*! SCT0_GPIO_IN_A_I - SCT0_GPIO_IN_A function assignment. The value is the pin number to be
 *    assigned to this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and
 *    from PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN6_SCT0_GPIO_IN_A_I(x)       (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN6_SCT0_GPIO_IN_A_I_SHIFT)) & SWM_PINASSIGN6_SCT0_GPIO_IN_A_I_MASK)
/*! @} */

/*! @name PINASSIGN7 - Pin assign register 7. Assign movable functions SCT_IN1, SCT_IN2, SCT_IN3, SCT_OUT0. */
/*! @{ */
#define SWM_PINASSIGN7_SCT0_GPIO_IN_B_I_MASK     (0xFFU)
#define SWM_PINASSIGN7_SCT0_GPIO_IN_B_I_SHIFT    (0U)
/*! SCT0_GPIO_IN_B_I - SCT0_GPIO_IN_B function assignment. The value is the pin number to be
 *    assigned to this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and
 *    from PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN7_SCT0_GPIO_IN_B_I(x)       (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_SCT0_GPIO_IN_B_I_SHIFT)) & SWM_PINASSIGN7_SCT0_GPIO_IN_B_I_MASK)
#define SWM_PINASSIGN7_SCT0_GPIO_IN_C_I_MASK     (0xFF00U)
#define SWM_PINASSIGN7_SCT0_GPIO_IN_C_I_SHIFT    (8U)
/*! SCT0_GPIO_IN_C_I - SCT0_GPIO_IN_C function assignment. The value is the pin number to be
 *    assigned to this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and
 *    from PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN7_SCT0_GPIO_IN_C_I(x)       (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_SCT0_GPIO_IN_C_I_SHIFT)) & SWM_PINASSIGN7_SCT0_GPIO_IN_C_I_MASK)
#define SWM_PINASSIGN7_SCT0_GPIO_IN_D_I_MASK     (0xFF0000U)
#define SWM_PINASSIGN7_SCT0_GPIO_IN_D_I_SHIFT    (16U)
/*! SCT0_GPIO_IN_D_I - SCT0_GPIO_IN_D function assignment. The value is the pin number to be
 *    assigned to this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and
 *    from PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN7_SCT0_GPIO_IN_D_I(x)       (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_SCT0_GPIO_IN_D_I_SHIFT)) & SWM_PINASSIGN7_SCT0_GPIO_IN_D_I_MASK)
#define SWM_PINASSIGN7_SCT_OUT0_O_MASK           (0xFF000000U)
#define SWM_PINASSIGN7_SCT_OUT0_O_SHIFT          (24U)
/*! SCT_OUT0_O - SCT_OUT0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN7_SCT_OUT0_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN7_SCT_OUT0_O_SHIFT)) & SWM_PINASSIGN7_SCT_OUT0_O_MASK)
/*! @} */

/*! @name PINASSIGN8 - Pin assign register 8. Assign movable functions SCT_OUT1, SCT_OUT2, SCT_OUT3, SCT_OUT4. */
/*! @{ */
#define SWM_PINASSIGN8_SCT_OUT1_O_MASK           (0xFFU)
#define SWM_PINASSIGN8_SCT_OUT1_O_SHIFT          (0U)
/*! SCT_OUT1_O - SCT_OUT1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN8_SCT_OUT1_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_SCT_OUT1_O_SHIFT)) & SWM_PINASSIGN8_SCT_OUT1_O_MASK)
#define SWM_PINASSIGN8_SCT_OUT2_O_MASK           (0xFF00U)
#define SWM_PINASSIGN8_SCT_OUT2_O_SHIFT          (8U)
/*! SCT_OUT2_O - SCT_OUT2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN8_SCT_OUT2_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_SCT_OUT2_O_SHIFT)) & SWM_PINASSIGN8_SCT_OUT2_O_MASK)
#define SWM_PINASSIGN8_SCT_OUT3_O_MASK           (0xFF0000U)
#define SWM_PINASSIGN8_SCT_OUT3_O_SHIFT          (16U)
/*! SCT_OUT3_O - SCT_OUT3 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN8_SCT_OUT3_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_SCT_OUT3_O_SHIFT)) & SWM_PINASSIGN8_SCT_OUT3_O_MASK)
#define SWM_PINASSIGN8_SCT_OUT4_O_MASK           (0xFF000000U)
#define SWM_PINASSIGN8_SCT_OUT4_O_SHIFT          (24U)
/*! SCT_OUT4_O - SCT_OUT4 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN8_SCT_OUT4_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN8_SCT_OUT4_O_SHIFT)) & SWM_PINASSIGN8_SCT_OUT4_O_MASK)
/*! @} */

/*! @name PINASSIGN9 - Pin assign register 9. Assign movable functions SCT_OUT5, SCT_OUT6, I2C1_SDA, I2C1_SCL. */
/*! @{ */
#define SWM_PINASSIGN9_SCT_OUT5_O_MASK           (0xFFU)
#define SWM_PINASSIGN9_SCT_OUT5_O_SHIFT          (0U)
/*! SCT_OUT5_O - SCT_OUT5 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN9_SCT_OUT5_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_SCT_OUT5_O_SHIFT)) & SWM_PINASSIGN9_SCT_OUT5_O_MASK)
#define SWM_PINASSIGN9_SCT_OUT6_O_MASK           (0xFF00U)
#define SWM_PINASSIGN9_SCT_OUT6_O_SHIFT          (8U)
/*! SCT_OUT6_O - SCT_OUT6 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN9_SCT_OUT6_O(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_SCT_OUT6_O_SHIFT)) & SWM_PINASSIGN9_SCT_OUT6_O_MASK)
#define SWM_PINASSIGN9_I2C1_SDA_IO_MASK          (0xFF0000U)
#define SWM_PINASSIGN9_I2C1_SDA_IO_SHIFT         (16U)
/*! I2C1_SDA_IO - I2C1_SDA function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN9_I2C1_SDA_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_I2C1_SDA_IO_SHIFT)) & SWM_PINASSIGN9_I2C1_SDA_IO_MASK)
#define SWM_PINASSIGN9_I2C1_SCL_IO_MASK          (0xFF000000U)
#define SWM_PINASSIGN9_I2C1_SCL_IO_SHIFT         (24U)
/*! I2C1_SCL_IO - I2C1_SCL function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN9_I2C1_SCL_IO(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN9_I2C1_SCL_IO_SHIFT)) & SWM_PINASSIGN9_I2C1_SCL_IO_MASK)
/*! @} */

/*! @name PINASSIGN10 - Pin assign register 10. Assign movable functions I2C2_SDA, I2C2_SCL, I2C3_SDA, I2C3_SCL. */
/*! @{ */
#define SWM_PINASSIGN10_I2C2_SDA_IO_MASK         (0xFFU)
#define SWM_PINASSIGN10_I2C2_SDA_IO_SHIFT        (0U)
/*! I2C2_SDA_IO - I2C1_SDA function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN10_I2C2_SDA_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN10_I2C2_SDA_IO_SHIFT)) & SWM_PINASSIGN10_I2C2_SDA_IO_MASK)
#define SWM_PINASSIGN10_I2C2_SCL_IO_MASK         (0xFF00U)
#define SWM_PINASSIGN10_I2C2_SCL_IO_SHIFT        (8U)
/*! I2C2_SCL_IO - I2C1_SCL function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN10_I2C2_SCL_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN10_I2C2_SCL_IO_SHIFT)) & SWM_PINASSIGN10_I2C2_SCL_IO_MASK)
#define SWM_PINASSIGN10_I2C3_SDA_IO_MASK         (0xFF0000U)
#define SWM_PINASSIGN10_I2C3_SDA_IO_SHIFT        (16U)
/*! I2C3_SDA_IO - I2C3_SDA function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN10_I2C3_SDA_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN10_I2C3_SDA_IO_SHIFT)) & SWM_PINASSIGN10_I2C3_SDA_IO_MASK)
#define SWM_PINASSIGN10_I2C3_SCL_IO_MASK         (0xFF000000U)
#define SWM_PINASSIGN10_I2C3_SCL_IO_SHIFT        (24U)
/*! I2C3_SCL_IO - I2C3_SCL function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN10_I2C3_SCL_IO(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN10_I2C3_SCL_IO_SHIFT)) & SWM_PINASSIGN10_I2C3_SCL_IO_MASK)
/*! @} */

/*! @name PINASSIGN11 - Pin assign register 11. Assign movable functions COMP0_OUT, CLKOUT, GPIOINT_BMATCH, UART3_TXD */
/*! @{ */
#define SWM_PINASSIGN11_COMP0_OUT_O_MASK         (0xFFU)
#define SWM_PINASSIGN11_COMP0_OUT_O_SHIFT        (0U)
/*! COMP0_OUT_O - COMP0_OUT function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN11_COMP0_OUT_O(x)           (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN11_COMP0_OUT_O_SHIFT)) & SWM_PINASSIGN11_COMP0_OUT_O_MASK)
#define SWM_PINASSIGN11_CLKOUT_O_MASK            (0xFF00U)
#define SWM_PINASSIGN11_CLKOUT_O_SHIFT           (8U)
/*! CLKOUT_O - CLKOUT function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN11_CLKOUT_O(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN11_CLKOUT_O_SHIFT)) & SWM_PINASSIGN11_CLKOUT_O_MASK)
#define SWM_PINASSIGN11_GPIO_INT_BMAT_O_MASK     (0xFF0000U)
#define SWM_PINASSIGN11_GPIO_INT_BMAT_O_SHIFT    (16U)
/*! GPIO_INT_BMAT_O - GPIO_INT_BMAT function assignment. The value is the pin number to be assigned
 *    to this function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from
 *    PIO1_0 (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN11_GPIO_INT_BMAT_O(x)       (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN11_GPIO_INT_BMAT_O_SHIFT)) & SWM_PINASSIGN11_GPIO_INT_BMAT_O_MASK)
#define SWM_PINASSIGN11_UART3_TXD_MASK           (0xFF000000U)
#define SWM_PINASSIGN11_UART3_TXD_SHIFT          (24U)
/*! UART3_TXD - UART3_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN11_UART3_TXD(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN11_UART3_TXD_SHIFT)) & SWM_PINASSIGN11_UART3_TXD_MASK)
/*! @} */

/*! @name PINASSIGN12 - Pin assign register 12. Assign movable functions UART3_RXD, UART3_SCLK, UART4_TXD, UART4_RXD. */
/*! @{ */
#define SWM_PINASSIGN12_UART3_RXD_MASK           (0xFFU)
#define SWM_PINASSIGN12_UART3_RXD_SHIFT          (0U)
/*! UART3_RXD - UART3_RXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN12_UART3_RXD(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN12_UART3_RXD_SHIFT)) & SWM_PINASSIGN12_UART3_RXD_MASK)
#define SWM_PINASSIGN12_UART3_SCLK_MASK          (0xFF00U)
#define SWM_PINASSIGN12_UART3_SCLK_SHIFT         (8U)
/*! UART3_SCLK - UART3_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN12_UART3_SCLK(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN12_UART3_SCLK_SHIFT)) & SWM_PINASSIGN12_UART3_SCLK_MASK)
#define SWM_PINASSIGN12_UART4_TXD_MASK           (0xFF0000U)
#define SWM_PINASSIGN12_UART4_TXD_SHIFT          (16U)
/*! UART4_TXD - UART4_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN12_UART4_TXD(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN12_UART4_TXD_SHIFT)) & SWM_PINASSIGN12_UART4_TXD_MASK)
#define SWM_PINASSIGN12_UART4_RXD_MASK           (0xFF000000U)
#define SWM_PINASSIGN12_UART4_RXD_SHIFT          (24U)
/*! UART4_RXD - UART4_TXD function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN12_UART4_RXD(x)             (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN12_UART4_RXD_SHIFT)) & SWM_PINASSIGN12_UART4_RXD_MASK)
/*! @} */

/*! @name PINASSIGN13 - Pin assign register 13. Assign movable functions UART4_SCLK, T0_MAT0, T0_MAT1, T0_MAT2. */
/*! @{ */
#define SWM_PINASSIGN13_UART4_SCLK_MASK          (0xFFU)
#define SWM_PINASSIGN13_UART4_SCLK_SHIFT         (0U)
/*! UART4_SCLK - UART4_SCLK function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0
 *    (=0x20) to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN13_UART4_SCLK(x)            (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN13_UART4_SCLK_SHIFT)) & SWM_PINASSIGN13_UART4_SCLK_MASK)
#define SWM_PINASSIGN13_T0_MAT0_MASK             (0xFF00U)
#define SWM_PINASSIGN13_T0_MAT0_SHIFT            (8U)
/*! T0_MAT0 - T0_MAT0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN13_T0_MAT0(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN13_T0_MAT0_SHIFT)) & SWM_PINASSIGN13_T0_MAT0_MASK)
#define SWM_PINASSIGN13_T0_MAT1_MASK             (0xFF0000U)
#define SWM_PINASSIGN13_T0_MAT1_SHIFT            (16U)
/*! T0_MAT1 - T0_MAT1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN13_T0_MAT1(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN13_T0_MAT1_SHIFT)) & SWM_PINASSIGN13_T0_MAT1_MASK)
#define SWM_PINASSIGN13_T0_MAT2_MASK             (0xFF000000U)
#define SWM_PINASSIGN13_T0_MAT2_SHIFT            (24U)
/*! T0_MAT2 - T0_MAT2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN13_T0_MAT2(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN13_T0_MAT2_SHIFT)) & SWM_PINASSIGN13_T0_MAT2_MASK)
/*! @} */

/*! @name PINASSIGN14 - Pin assign register 14. Assign movable functions T0_MAT3, T0_CAP0, T0_CAP1, T0_CAP2. */
/*! @{ */
#define SWM_PINASSIGN14_T0_MAT3_MASK             (0xFFU)
#define SWM_PINASSIGN14_T0_MAT3_SHIFT            (0U)
/*! T0_MAT3 - T0_MAT3 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN14_T0_MAT3(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN14_T0_MAT3_SHIFT)) & SWM_PINASSIGN14_T0_MAT3_MASK)
#define SWM_PINASSIGN14_T0_CAP0_MASK             (0xFF00U)
#define SWM_PINASSIGN14_T0_CAP0_SHIFT            (8U)
/*! T0_CAP0 - T0_CAP0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN14_T0_CAP0(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN14_T0_CAP0_SHIFT)) & SWM_PINASSIGN14_T0_CAP0_MASK)
#define SWM_PINASSIGN14_T0_CAP1_MASK             (0xFF0000U)
#define SWM_PINASSIGN14_T0_CAP1_SHIFT            (16U)
/*! T0_CAP1 - T0_CAP1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN14_T0_CAP1(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN14_T0_CAP1_SHIFT)) & SWM_PINASSIGN14_T0_CAP1_MASK)
#define SWM_PINASSIGN14_T0_CAP2_MASK             (0xFF000000U)
#define SWM_PINASSIGN14_T0_CAP2_SHIFT            (24U)
/*! T0_CAP2 - T0_CAP2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN14_T0_CAP2(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN14_T0_CAP2_SHIFT)) & SWM_PINASSIGN14_T0_CAP2_MASK)
/*! @} */

/*! @name PINASSIGN_DATA - Pin assign register */
/*! @{ */
#define SWM_PINASSIGN_DATA_DATA0_MASK            (0xFFU)
#define SWM_PINASSIGN_DATA_DATA0_SHIFT           (0U)
/*! DATA0 - T0_MAT3 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN_DATA_DATA0(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA0_SHIFT)) & SWM_PINASSIGN_DATA_DATA0_MASK)
#define SWM_PINASSIGN_DATA_DATA1_MASK            (0xFF00U)
#define SWM_PINASSIGN_DATA_DATA1_SHIFT           (8U)
/*! DATA1 - T0_CAP0 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN_DATA_DATA1(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA1_SHIFT)) & SWM_PINASSIGN_DATA_DATA1_MASK)
#define SWM_PINASSIGN_DATA_DATA2_MASK            (0xFF0000U)
#define SWM_PINASSIGN_DATA_DATA2_SHIFT           (16U)
/*! DATA2 - T0_CAP1 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN_DATA_DATA2(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA2_SHIFT)) & SWM_PINASSIGN_DATA_DATA2_MASK)
#define SWM_PINASSIGN_DATA_DATA3_MASK            (0xFF000000U)
#define SWM_PINASSIGN_DATA_DATA3_SHIFT           (24U)
/*! DATA3 - T0_CAP2 function assignment. The value is the pin number to be assigned to this
 *    function. The following pins are available: PIO0_0 (= 0) to PIO0_31 (= 0x1F) and from PIO1_0 (=0x20)
 *    to PIO1_21(=0x35).
 */
#define SWM_PINASSIGN_DATA_DATA3(x)              (((uint32_t)(((uint32_t)(x)) << SWM_PINASSIGN_DATA_DATA3_SHIFT)) & SWM_PINASSIGN_DATA_DATA3_MASK)
/*! @} */

/* The count of SWM_PINASSIGN_DATA */
#define SWM_PINASSIGN_DATA_COUNT                 (15U)

/*! @name PINENABLE0 - Pin enable register 0. Enables fixed-pin functions ACMP_I0, ACMP_I1, SWCLK, SWDIO, XTALIN, XTALOUT, RESET, CLKIN, VDDCMP and so on. */
/*! @{ */
#define SWM_PINENABLE0_ACMP_I1_MASK              (0x1U)
#define SWM_PINENABLE0_ACMP_I1_SHIFT             (0U)
/*! ACMP_I1 - ACMP_I1 function select.
 *  0b0..ACMP_I1 enabled on pin PIO0_00.
 *  0b1..ACMP_I1 disabled.
 */
#define SWM_PINENABLE0_ACMP_I1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I1_SHIFT)) & SWM_PINENABLE0_ACMP_I1_MASK)
#define SWM_PINENABLE0_ACMP_I2_MASK              (0x2U)
#define SWM_PINENABLE0_ACMP_I2_SHIFT             (1U)
/*! ACMP_I2 - ACMP_I2 function select.
 *  0b0..ACMP_I2 enabled on pin PIO0_1.
 *  0b1..ACMP_I2 disabled.
 */
#define SWM_PINENABLE0_ACMP_I2(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I2_SHIFT)) & SWM_PINENABLE0_ACMP_I2_MASK)
#define SWM_PINENABLE0_ACMP_I3_MASK              (0x4U)
#define SWM_PINENABLE0_ACMP_I3_SHIFT             (2U)
/*! ACMP_I3 - ACMP_I3 function select.
 *  0b0..ACMP_I3 enabled on pin PIO0_14.
 *  0b1..ACMP_I3 disabled.
 */
#define SWM_PINENABLE0_ACMP_I3(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I3_SHIFT)) & SWM_PINENABLE0_ACMP_I3_MASK)
#define SWM_PINENABLE0_ACMP_I4_MASK              (0x8U)
#define SWM_PINENABLE0_ACMP_I4_SHIFT             (3U)
/*! ACMP_I4 - ACMP_I4 function select.
 *  0b0..ACMP_I4 enabled on pin PIO0_23.
 *  0b1..ACMP_I4 disabled.
 */
#define SWM_PINENABLE0_ACMP_I4(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I4_SHIFT)) & SWM_PINENABLE0_ACMP_I4_MASK)
#define SWM_PINENABLE0_ACMP_I5_MASK              (0x10U)
#define SWM_PINENABLE0_ACMP_I5_SHIFT             (4U)
/*! ACMP_I5 - ACMP_I5 function select.
 *  0b0..ACMP_I5 enabled on pin PIO0_30.
 *  0b1..ACMP_I5 disabled.
 */
#define SWM_PINENABLE0_ACMP_I5(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ACMP_I5_SHIFT)) & SWM_PINENABLE0_ACMP_I5_MASK)
#define SWM_PINENABLE0_SWCLK_MASK                (0x20U)
#define SWM_PINENABLE0_SWCLK_SHIFT               (5U)
/*! SWCLK - SWCLK function select.
 *  0b0..SWCLK enabled on pin PIO0_3.
 *  0b1..SWCLK disabled.
 */
#define SWM_PINENABLE0_SWCLK(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_SWCLK_SHIFT)) & SWM_PINENABLE0_SWCLK_MASK)
#define SWM_PINENABLE0_SWDIO_MASK                (0x40U)
#define SWM_PINENABLE0_SWDIO_SHIFT               (6U)
/*! SWDIO - SWDIO function select.
 *  0b0..SWDIO enabled on pin PIO0_2.
 *  0b1..SWDIO disabled.
 */
#define SWM_PINENABLE0_SWDIO(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_SWDIO_SHIFT)) & SWM_PINENABLE0_SWDIO_MASK)
#define SWM_PINENABLE0_XTALIN_MASK               (0x80U)
#define SWM_PINENABLE0_XTALIN_SHIFT              (7U)
/*! XTALIN - XTALIN function select.
 *  0b0..XTALIN enabled on pin PIO0_8.
 *  0b1..XTALIN disabled.
 */
#define SWM_PINENABLE0_XTALIN(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_XTALIN_SHIFT)) & SWM_PINENABLE0_XTALIN_MASK)
#define SWM_PINENABLE0_XTALOUT_MASK              (0x100U)
#define SWM_PINENABLE0_XTALOUT_SHIFT             (8U)
/*! XTALOUT - XTALOUT function select.
 *  0b0..XTALOUT enabled on pin PIO0_9.
 *  0b1..XTALOUT disabled.
 */
#define SWM_PINENABLE0_XTALOUT(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_XTALOUT_SHIFT)) & SWM_PINENABLE0_XTALOUT_MASK)
#define SWM_PINENABLE0_RESETN_MASK               (0x200U)
#define SWM_PINENABLE0_RESETN_SHIFT              (9U)
/*! RESETN - RESETN function select.
 *  0b0..RESETN enabled on pin PIO0_5.
 *  0b1..RESETN disabled.
 */
#define SWM_PINENABLE0_RESETN(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_RESETN_SHIFT)) & SWM_PINENABLE0_RESETN_MASK)
#define SWM_PINENABLE0_CLKIN_MASK                (0x400U)
#define SWM_PINENABLE0_CLKIN_SHIFT               (10U)
/*! CLKIN - CLKIN function select.
 *  0b0..CLKIN enabled on pin PIO0_1.
 *  0b1..CLKIN disabled.
 */
#define SWM_PINENABLE0_CLKIN(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CLKIN_SHIFT)) & SWM_PINENABLE0_CLKIN_MASK)
#define SWM_PINENABLE0_VDDCMP_MASK               (0x800U)
#define SWM_PINENABLE0_VDDCMP_SHIFT              (11U)
/*! VDDCMP - VDDCMP function select.
 *  0b0..VDDCMP enabled on pin PIO0_6.
 *  0b1..VDDCMP disabled.
 */
#define SWM_PINENABLE0_VDDCMP(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_VDDCMP_SHIFT)) & SWM_PINENABLE0_VDDCMP_MASK)
#define SWM_PINENABLE0_I2C0_SDA_MASK             (0x1000U)
#define SWM_PINENABLE0_I2C0_SDA_SHIFT            (12U)
/*! I2C0_SDA - I2C0_SDA function select.
 *  0b0..I2C0_SDA enabled on pin PIO0_11.
 *  0b1..I2C0_SDA disabled.
 */
#define SWM_PINENABLE0_I2C0_SDA(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_I2C0_SDA_SHIFT)) & SWM_PINENABLE0_I2C0_SDA_MASK)
#define SWM_PINENABLE0_I2C0_SCL_MASK             (0x2000U)
#define SWM_PINENABLE0_I2C0_SCL_SHIFT            (13U)
/*! I2C0_SCL - I2C0_SCL function select.
 *  0b0..I2C0_SCL enabled on pin PIO0_10.
 *  0b1..I2C0_SCL disabled.
 */
#define SWM_PINENABLE0_I2C0_SCL(x)               (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_I2C0_SCL_SHIFT)) & SWM_PINENABLE0_I2C0_SCL_MASK)
#define SWM_PINENABLE0_ADC_0_MASK                (0x4000U)
#define SWM_PINENABLE0_ADC_0_SHIFT               (14U)
/*! ADC_0 - ADC_0 function select.
 *  0b0..ADC_0 enabled on pin PIO0_7.
 *  0b1..ADC_0 disabled.
 */
#define SWM_PINENABLE0_ADC_0(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_0_SHIFT)) & SWM_PINENABLE0_ADC_0_MASK)
#define SWM_PINENABLE0_ADC_1_MASK                (0x8000U)
#define SWM_PINENABLE0_ADC_1_SHIFT               (15U)
/*! ADC_1 - ADC_1 function select.
 *  0b0..ADC_1 enabled on pin PIO0_6.
 *  0b1..ADC_1 disabled.
 */
#define SWM_PINENABLE0_ADC_1(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_1_SHIFT)) & SWM_PINENABLE0_ADC_1_MASK)
#define SWM_PINENABLE0_ADC_2_MASK                (0x10000U)
#define SWM_PINENABLE0_ADC_2_SHIFT               (16U)
/*! ADC_2 - ADC_2 function select.
 *  0b0..ADC_2 enabled on pin PIO0_14.
 *  0b1..ADC_2 disabled.
 */
#define SWM_PINENABLE0_ADC_2(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_2_SHIFT)) & SWM_PINENABLE0_ADC_2_MASK)
#define SWM_PINENABLE0_ADC_3_MASK                (0x20000U)
#define SWM_PINENABLE0_ADC_3_SHIFT               (17U)
/*! ADC_3 - ADC_3 function select.
 *  0b0..ADC_3 enabled on pin PIO0_23.
 *  0b1..ADC_3 disabled.
 */
#define SWM_PINENABLE0_ADC_3(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_3_SHIFT)) & SWM_PINENABLE0_ADC_3_MASK)
#define SWM_PINENABLE0_ADC_4_MASK                (0x40000U)
#define SWM_PINENABLE0_ADC_4_SHIFT               (18U)
/*! ADC_4 - ADC_4 function select.
 *  0b0..ADC_4 enabled on pin PIO0_22.
 *  0b1..ADC_4 disabled.
 */
#define SWM_PINENABLE0_ADC_4(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_4_SHIFT)) & SWM_PINENABLE0_ADC_4_MASK)
#define SWM_PINENABLE0_ADC_5_MASK                (0x80000U)
#define SWM_PINENABLE0_ADC_5_SHIFT               (19U)
/*! ADC_5 - ADC_5 function select.
 *  0b0..ADC_5 enabled on pin PIO0_21.
 *  0b1..ADC_5 disabled.
 */
#define SWM_PINENABLE0_ADC_5(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_5_SHIFT)) & SWM_PINENABLE0_ADC_5_MASK)
#define SWM_PINENABLE0_ADC_6_MASK                (0x100000U)
#define SWM_PINENABLE0_ADC_6_SHIFT               (20U)
/*! ADC_6 - ADC_6 function select.
 *  0b0..ADC_6 enabled on pin PIO0_20.
 *  0b1..ADC_6 disabled.
 */
#define SWM_PINENABLE0_ADC_6(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_6_SHIFT)) & SWM_PINENABLE0_ADC_6_MASK)
#define SWM_PINENABLE0_ADC_7_MASK                (0x200000U)
#define SWM_PINENABLE0_ADC_7_SHIFT               (21U)
/*! ADC_7 - ADC_7 function select.
 *  0b0..ADC_7 enabled on pin PIO0_19.
 *  0b1..ADC_7 disabled.
 */
#define SWM_PINENABLE0_ADC_7(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_7_SHIFT)) & SWM_PINENABLE0_ADC_7_MASK)
#define SWM_PINENABLE0_ADC_8_MASK                (0x400000U)
#define SWM_PINENABLE0_ADC_8_SHIFT               (22U)
/*! ADC_8 - ADC_8 function select.
 *  0b0..ADC_8 enabled on pin PIO0_18.
 *  0b1..ADC_8 disabled.
 */
#define SWM_PINENABLE0_ADC_8(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_8_SHIFT)) & SWM_PINENABLE0_ADC_8_MASK)
#define SWM_PINENABLE0_ADC_9_MASK                (0x800000U)
#define SWM_PINENABLE0_ADC_9_SHIFT               (23U)
/*! ADC_9 - ADC_9 function select.
 *  0b0..ADC_9 enabled on pin PIO0_17.
 *  0b1..ADC_9 disabled.
 */
#define SWM_PINENABLE0_ADC_9(x)                  (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_9_SHIFT)) & SWM_PINENABLE0_ADC_9_MASK)
#define SWM_PINENABLE0_ADC_10_MASK               (0x1000000U)
#define SWM_PINENABLE0_ADC_10_SHIFT              (24U)
/*! ADC_10 - ADC_10 function select.
 *  0b0..ADC_10 enabled on pin PIO0_13.
 *  0b1..ADC_10 disabled.
 */
#define SWM_PINENABLE0_ADC_10(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_10_SHIFT)) & SWM_PINENABLE0_ADC_10_MASK)
#define SWM_PINENABLE0_ADC_11_MASK               (0x2000000U)
#define SWM_PINENABLE0_ADC_11_SHIFT              (25U)
/*! ADC_11 - ADC_11 function select.
 *  0b0..ADC_11 enabled on pin PIO0_4.
 *  0b1..ADC_11 disabled.
 */
#define SWM_PINENABLE0_ADC_11(x)                 (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_ADC_11_SHIFT)) & SWM_PINENABLE0_ADC_11_MASK)
#define SWM_PINENABLE0_DACOUT0_MASK              (0x4000000U)
#define SWM_PINENABLE0_DACOUT0_SHIFT             (26U)
/*! DACOUT0 - DACOUT0 function select.
 *  0b0..DACOUT0 enabled on pin PIO0_17.
 *  0b1..DACOUT0 disabled.
 */
#define SWM_PINENABLE0_DACOUT0(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_DACOUT0_SHIFT)) & SWM_PINENABLE0_DACOUT0_MASK)
#define SWM_PINENABLE0_DACOUT1_MASK              (0x8000000U)
#define SWM_PINENABLE0_DACOUT1_SHIFT             (27U)
/*! DACOUT1 - DACOUT1 function select.
 *  0b0..DACOUT1 enabled on pin PIO0_29.
 *  0b1..DACOUT1 disabled.
 */
#define SWM_PINENABLE0_DACOUT1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_DACOUT1_SHIFT)) & SWM_PINENABLE0_DACOUT1_MASK)
#define SWM_PINENABLE0_CAPT_X0_MASK              (0x10000000U)
#define SWM_PINENABLE0_CAPT_X0_SHIFT             (28U)
/*! CAPT_X0 - CAPT_X0 function select.
 *  0b0..CAPT_X0 enabled on pin PIO0_31.
 *  0b1..CAPT_X0 disabled.
 */
#define SWM_PINENABLE0_CAPT_X0(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CAPT_X0_SHIFT)) & SWM_PINENABLE0_CAPT_X0_MASK)
#define SWM_PINENABLE0_CAPT_X1_MASK              (0x20000000U)
#define SWM_PINENABLE0_CAPT_X1_SHIFT             (29U)
/*! CAPT_X1 - CAPT_X1 function select.
 *  0b0..CAPT_X1 enabled on pin PIO1_0.
 *  0b1..CAPT_X1 disabled.
 */
#define SWM_PINENABLE0_CAPT_X1(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CAPT_X1_SHIFT)) & SWM_PINENABLE0_CAPT_X1_MASK)
#define SWM_PINENABLE0_CAPT_X2_MASK              (0x40000000U)
#define SWM_PINENABLE0_CAPT_X2_SHIFT             (30U)
/*! CAPT_X2 - CAPT_X2 function select.
 *  0b0..CAPT_X2 enabled on pin PIO1_1.
 *  0b1..CAPT_X2 disabled.
 */
#define SWM_PINENABLE0_CAPT_X2(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CAPT_X2_SHIFT)) & SWM_PINENABLE0_CAPT_X2_MASK)
#define SWM_PINENABLE0_CAPT_X3_MASK              (0x80000000U)
#define SWM_PINENABLE0_CAPT_X3_SHIFT             (31U)
/*! CAPT_X3 - CAPT_X3 function select.
 *  0b0..CAPT_X3 enabled on pin PIO1_2.
 *  0b1..CAPT_X3 disabled.
 */
#define SWM_PINENABLE0_CAPT_X3(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE0_CAPT_X3_SHIFT)) & SWM_PINENABLE0_CAPT_X3_MASK)
/*! @} */

/*! @name PINENABLE1 - Pin enable register 1. Enables fixed-pin functions CAPT_X4, CAPT_X5, CAPT_X6, CAPT_X7, CAPT_X8, CAPT_X4, CAPT_YL and CAPT_YH. */
/*! @{ */
#define SWM_PINENABLE1_CAPT_X4_MASK              (0x1U)
#define SWM_PINENABLE1_CAPT_X4_SHIFT             (0U)
/*! CAPT_X4 - CAPT_X4 function select.
 *  0b0..CAPT_X4 enabled on pin PIO1_3.
 *  0b1..CAPT_X4 disabled.
 */
#define SWM_PINENABLE1_CAPT_X4(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_X4_SHIFT)) & SWM_PINENABLE1_CAPT_X4_MASK)
#define SWM_PINENABLE1_CAPT_X5_MASK              (0x2U)
#define SWM_PINENABLE1_CAPT_X5_SHIFT             (1U)
/*! CAPT_X5 - CAPT_X5 function select.
 *  0b0..CAPT_X5 enabled on pin PIO1_4.
 *  0b1..CAPT_X5 disabled.
 */
#define SWM_PINENABLE1_CAPT_X5(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_X5_SHIFT)) & SWM_PINENABLE1_CAPT_X5_MASK)
#define SWM_PINENABLE1_CAPT_X6_MASK              (0x4U)
#define SWM_PINENABLE1_CAPT_X6_SHIFT             (2U)
/*! CAPT_X6 - CAPT_X6 function select.
 *  0b0..CAPT_X6 enabled on pin PIO1_5.
 *  0b1..CAPT_X6 disabled.
 */
#define SWM_PINENABLE1_CAPT_X6(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_X6_SHIFT)) & SWM_PINENABLE1_CAPT_X6_MASK)
#define SWM_PINENABLE1_CAPT_X7_MASK              (0x8U)
#define SWM_PINENABLE1_CAPT_X7_SHIFT             (3U)
/*! CAPT_X7 - CAPT_X7 function select.
 *  0b0..CAPT_X7 enabled on pin PIO1_6.
 *  0b1..CAPT_X7 disabled.
 */
#define SWM_PINENABLE1_CAPT_X7(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_X7_SHIFT)) & SWM_PINENABLE1_CAPT_X7_MASK)
#define SWM_PINENABLE1_CAPT_X8_MASK              (0x10U)
#define SWM_PINENABLE1_CAPT_X8_SHIFT             (4U)
/*! CAPT_X8 - CAPT_X8 function select.
 *  0b0..CAPT_X8 enabled on pin PIO1_7.
 *  0b1..CAPT_X8 disabled.
 */
#define SWM_PINENABLE1_CAPT_X8(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_X8_SHIFT)) & SWM_PINENABLE1_CAPT_X8_MASK)
#define SWM_PINENABLE1_CAPT_YL_MASK              (0x20U)
#define SWM_PINENABLE1_CAPT_YL_SHIFT             (5U)
/*! CAPT_YL - CAPT_YL function select.
 *  0b0..CAPT_YL enabled on pin PIO1_8.
 *  0b1..CAPT_YL disabled.
 */
#define SWM_PINENABLE1_CAPT_YL(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_YL_SHIFT)) & SWM_PINENABLE1_CAPT_YL_MASK)
#define SWM_PINENABLE1_CAPT_YH_MASK              (0x40U)
#define SWM_PINENABLE1_CAPT_YH_SHIFT             (6U)
/*! CAPT_YH - CAPT_YH function select.
 *  0b0..CAPT_YH enabled on pin PIO1_9.
 *  0b1..CAPT_YH disabled.
 */
#define SWM_PINENABLE1_CAPT_YH(x)                (((uint32_t)(((uint32_t)(x)) << SWM_PINENABLE1_CAPT_YH_SHIFT)) & SWM_PINENABLE1_CAPT_YH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SWM_Register_Masks */


/* SWM - Peripheral instance base addresses */
/** Peripheral SWM0 base address */
#define SWM0_BASE                                (0x4000C000u)
/** Peripheral SWM0 base pointer */
#define SWM0                                     ((SWM_Type *)SWM0_BASE)
/** Array initializer of SWM peripheral base addresses */
#define SWM_BASE_ADDRS                           { SWM0_BASE }
/** Array initializer of SWM peripheral base pointers */
#define SWM_BASE_PTRS                            { SWM0 }

/*!
 * @}
 */ /* end of group SWM_Peripheral_Access_Layer */



/* ----------------------------------------------------------------------------
   -- Acceso a SYSCON
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Acceso a SYSCON
 * @{
 */

/** SYSCON - Tipo de datos bloque de Registros */
typedef struct {
  __IO uint32_t SYSMEMREMAP;                       /**< Registro de Remp del Sistema, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SYSPLLCTRL;                        /**< Control de PLL, offset: 0x8 */
  __I  uint32_t SYSPLLSTAT;                        /**< Status de PLL, offset: 0xC */
       uint8_t RESERVED_1[16];
  __IO uint32_t SYSOSCCTRL;                        /**< Control del oscilador del sistema, offset: 0x20 */
  __IO uint32_t WDTOSCCTRL;                        /**< Control del oscilador del Watchdog, offset: 0x24 */
  __IO uint32_t FROOSCCTRL;                        /**< Control del oscilador FRO, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t FRODIRECTCLKUEN;                   /**< Registro de habilitación de update de FRO como fuente directa de clock, offset: 0x30 */
       uint8_t RESERVED_3[4];
  __IO uint32_t SYSRSTSTAT;                        /**< Registro de estado de reset, offset: 0x38 */
       uint8_t RESERVED_4[4];
  __IO uint32_t SYSPLLCLKSEL;                      /**< Registro de selección de fuente de clock del System PLL, offset: 0x40 */
  __IO uint32_t SYSPLLCLKUEN;                      /**< Registro de habilitación de update de fuente de clock del System PLL, offset: 0x44 */
  __IO uint32_t MAINCLKPLLSEL;                     /**< Registro de selección de fuente de clock del Main clock PLL, offset: 0x48 */
  __IO uint32_t MAINCLKPLLUEN;                     /**< Registro de habilitación de update de fuente de clock del Main clock PLL, offset: 0x4C */
  __IO uint32_t MAINCLKSEL;                        /**< Registro de selección de fuente de clock del Main clock, offset: 0x50 */
  __IO uint32_t MAINCLKUEN;                        /**< Registro de habilitación de update de fuente de clock del Main clock, offset: 0x54 */
  __IO uint32_t SYSAHBCLKDIV;                      /**< Registro de divisor del System clock, offset: 0x58 */
       uint8_t RESERVED_5[4];
  __IO uint32_t CAPTCLKSEL;                        /**< Registro de selección de fuente de clock del CAPT, offset: 0x60 */
  __IO uint32_t ADCCLKSEL;                         /**< Registro de selección de fuente de clock del ADC, offset: 0x64 */
  __IO uint32_t ADCCLKDIV;                         /**< Registro de divisor del ADC clock, offset: 0x68 */
  __IO uint32_t SCTCLKSEL;                         /**< Registro de selección de fuente de clock del SCT clock, offset: 0x6C */
  __IO uint32_t SCTCLKDIV;                         /**< Registro de divisor del SCT clock, offset: 0x70 */
  __IO uint32_t EXTCLKSEL;                         /**< Registro de selección de fuente de clock externo, offset: 0x74 */
       uint8_t RESERVED_6[8];
  __IO uint32_t SYSAHBCLKCTRL0;                    /**< Registro de control del grupo 0 de clock, offset: 0x80 */
  __IO uint32_t SYSAHBCLKCTRL1;                    /**< Registro de control del grupo 1 de clock, offset: 0x84 */
  __IO uint32_t PRESETCTRL0;                       /**< Registro de control del grupo 0 de reset de Periféricos, offset: 0x88 */
  __IO uint32_t PRESETCTRL1;                       /**< Registro de control del grupo 1 de reset de Periféricos, offset: 0x8C */
  __IO uint32_t FCLKSEL[11];                       /**< Registro de selección de fuente de clock de Periféricos. FCLK0SEL~FCLK4SEL son para elegir la fuente de clock UART0~UART4. FCLK5SEL~FCLK8SEL son para elegir la fuente de clock de I2C0~I2C3. FCLK9SEL~FCLK10SEL son para elegir la fuente de clock de SPI0~SPI1., array offset: 0x90, array step: 0x4 */
       uint8_t RESERVED_7[20];
  struct {                                         /* offset: 0xD0, array step: 0x10 */
    __IO uint32_t FRGDIV;                          /**< Registro de valor de divisor N del generador fraccional, array offset: 0xD0, array step: 0x10 */
    __IO uint32_t FRGMULT;                         /**< Registro de valor de multiplicador N del generador fraccional, array offset: 0xD4, array step: 0x10 */
    __IO uint32_t FRGCLKSEL;                       /**< Registro de selección de fuente de clock de FRG N, array offset: 0xD8, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } FRG[2];
  __IO uint32_t CLKOUTSEL;                         /**< Registro de selección de fuente de CLKOUT, offset: 0xF0 */
  __IO uint32_t CLKOUTDIV;                         /**< Registro de divisor de CLKOUT, offset: 0xF4 */
       uint8_t RESERVED_8[4];
  __IO uint32_t EXTTRACECMD;                       /**< Registro de comando del External trace buffer, offset: 0xFC */
  __I  uint32_t PIOPORCAP[2];                      /**< Estado de captura de POR PIO N(PIO0 tiene 32 PIOs, PIO1 tiene 22 PIOs), array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_9[44];
  __IO uint32_t IOCONCLKDIV6;                      /**< Clock 6 para filtro de glitch programable del IOCON, offset: 0x134 */
  __IO uint32_t IOCONCLKDIV5;                      /**< Clock 5 para filtro de glitch programable del IOCON, offset: 0x138 */
  __IO uint32_t IOCONCLKDIV4;                      /**< Clock 4 para filtro de glitch programable del IOCON, offset: 0x13C */
  __IO uint32_t IOCONCLKDIV3;                      /**< Clock 3 para filtro de glitch programable del IOCON, offset: 0x140 */
  __IO uint32_t IOCONCLKDIV2;                      /**< Clock 2 para filtro de glitch programable del IOCON, offset: 0x144 */
  __IO uint32_t IOCONCLKDIV1;                      /**< Clock 1 para filtro de glitch programable del IOCON, offset: 0x148 */
  __IO uint32_t IOCONCLKDIV0;                      /**< Clock 0 para filtro de glitch programable del IOCON, offset: 0x14C */
  __IO uint32_t BODCTRL;                           /**< Registro de control de BOD, offset: 0x150 */
  __IO uint32_t SYSTCKCAL;                         /**< Registro de calibración del System tick timer, offset: 0x154 */
       uint8_t RESERVED_10[24];
  __IO uint32_t IRQLATENCY;                        /**< Registro de latencia de IRQ, offset: 0x170 */
  __IO uint32_t NMISRC;                            /**< Registro de selección de fuente de NMI, offset: 0x174 */
  __IO uint32_t PINTSEL[8];                        /**< Registro de selección de Pin interrupt N, array offset: 0x178, array step: 0x4 */
       uint8_t RESERVED_11[108];
  __IO uint32_t STARTERP0;                         /**< Registro 0 de habilitación de wake up por pin Start logic 0, offset: 0x204 */
       uint8_t RESERVED_12[12];
  __IO uint32_t STARTERP1;                         /**< Registro 1 de habilitación de wake up por pin Start logic 0, offset: 0x214 */
       uint8_t RESERVED_13[24];
  __IO uint32_t PDSLEEPCFG;                        /**< Registro de configuración de Deep-sleep, offset: 0x230 */
  __IO uint32_t PDAWAKECFG;                        /**< Registro de configuración de Wake-up, offset: 0x234 */
  __IO uint32_t PDRUNCFG;                          /**< Registro de configuración de Power, offset: 0x238 */
       uint8_t RESERVED_14[444];
  __I  uint32_t DEVICE_ID;                         /**< Registro de configuración de Part ID, offset: 0x3F8 */
} SYSCON_Type;


/*! @name SYSAHBCLKCTRL0 - Registro de control de grupo 0 de System clock */
/*! @{ */
#define SYSCON_SYSAHBCLKCTRL0_GPIO0_MASK         (0x40U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO0_SHIFT        (6U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO1_MASK         (0x100000U)
#define SYSCON_SYSAHBCLKCTRL0_GPIO1_SHIFT        (20U)

#define SYSCON_SYSAHBCLKCTRL0_GPIOINT_MASK       0x10000000U
#define SYSCON_SYSAHBCLKCTRL0_GPIOINT_SHIFT      (28U)

#define SYSCON_SYSAHBCLKCTRL0_SWM_MASK           (0x80U)
#define SYSCON_SYSAHBCLKCTRL0_SWM_SHIFT          (7U)

#define SYSCON_SYSAHBCLKCTRL0_UART0_MASK         (0x4000U)
#define SYSCON_SYSAHBCLKCTRL0_UART0_SHIFT        (14U)

#define SYSCON_SYSAHBCLKCTRL0_DAC0_MASK          (0x8000000U)
#define SYSCON_SYSAHBCLKCTRL0_DAC0_SHIFT         (27U)

#define SYSCON_SYSAHBCLKCTRL1_DAC1_MASK          (0x2U)
#define SYSCON_SYSAHBCLKCTRL1_DAC1_SHIFT         (1U)

#define SYSCON_SYSAHBCLKCTRL0_ADC_MASK           (0x1000000U)
#define SYSCON_SYSAHBCLKCTRL0_ADC_SHIFT          (24U)


#define SYSCON_PRESETCTRL0_UART0_RST_N_MASK      (0x4000U)
#define SYSCON_PRESETCTRL0_UART0_RST_N_SHIFT     (14U)

#define SYSCON_PDRUNCFG_ADC_PD_MASK              (0x10U)
#define SYSCON_PDRUNCFG_ADC_PD_SHIFT             (4U)
/*! ADC_PD - ADC wake-up configuration
 *  0b0..powered
 *  0b1..powered down
 */

#define SYSCON_PDAWAKECFG_DAC0_MASK              (0x2000U)
#define SYSCON_PDAWAKECFG_DAC0_SHIFT             (13U)
#define SYSCON_PDAWAKECFG_DAC1_MASK              (0x4000U)
#define SYSCON_PDAWAKECFG_DAC1_SHIFT             (14U)


/* SYSCON - Dirección  base de la instancia del Periférico */
/** Dirección  base de Periférico SYSCON */
#define SYSCON_BASE                              (0x40048000u)
/** Puntero base de Periférico SYSCON */
#define SYSCON                                   ((SYSCON_Type *)SYSCON_BASE)
/** Array inicializador de Dirección  base de Periférico SYSCON */

#define		UARTnCLKSEL		( ( volatile uint32_t  * ) 0x40048090UL )

#define		UART0CLKSEL		UARTnCLKSEL[0]
#define		UART1CLKSEL		UARTnCLKSEL[1]
#define		UART2CLKSEL		UARTnCLKSEL[2]
#define		UART3CLKSEL		UARTnCLKSEL[3]
#define		UART4CLKSEL		UARTnCLKSEL[4]



/* ----------------------------------------------------------------------------
   -- Acceso a IOCON
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Acceso a IOCON
 * @{
 */

/** IOCON - Tipo de datos bloque de Registros */
typedef struct {
  __IO uint32_t PIO[56];                           /**< Control Digital de los pines de I/O PIO0_31 y PIO1_10, array offset: 0x0, array step: 0x4 */
} IOCON_Type;

/* ----------------------------------------------------------------------------
   -- IOCON máscaras de registros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup máscaras de registros
 * @{
 */

/*! @name PIO - Control Digital de los pines de I/O PIO0_31 y PIO1_10 */
/*! @{ */
#define IOCON_PIO_MODE_MASK                      (0x18U)
#define IOCON_PIO_MODE_SHIFT                     (3U)
/*! MODE - Elije el modo del pin (control de resistencia interna de pull-up/pull-down).
 *  0b00..Inactivo. No pull-down/pull-up.
 *  0b01..Pull-down.
 *  0b10..Pull-up.
 *  0b11..Modo Repetidor.
 */
#define IOCON_PIO_HYS_MASK                       (0x20U)
#define IOCON_PIO_HYS_SHIFT                      (5U)
/*! HYS - Histéresis.
 *  0b0..Disable
 *  0b1..Enable
 */
#define IOCON_PIO_INV_MASK                       (0x40U)
#define IOCON_PIO_INV_SHIFT                      (6U)
/*! INV - Inversión de entrada
 *  0b0..Entrada no invertida (Alto en pin se lee como 1; LOW en pin se lee como 0).
 *  0b1..Entrada invertida (Alto en pin se lee como 0; LOW en pin se lee como 1).
 */
#define IOCON_PIO_I2CMODE_MASK                   (0x300U)
#define IOCON_PIO_I2CMODE_SHIFT                  (8U)
/*! I2CMODE - Selección de modo I2C.
 *  0b00..Modo estandar/ Modo Fast I2C.
 *  0b01..Funcionalidad estandar de GPIO. Requiere pull-up externa para función GPIO.
 *  0b10..Modo I2C Fast Plus
 *  0b11..Reservado
 */
#define IOCON_PIO_OD(x)                          (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_OD_SHIFT)) & IOCON_PIO_OD_MASK)
#define IOCON_PIO_OD_MASK                        (0x400U)
#define IOCON_PIO_OD_SHIFT                       (10U)
/*! OD - Modo Open-drain.
 *  0b0..Disable.
 *  0b1..Modo Open-drain enabled. Nota: No es true open-drain.
 */
#define IOCON_PIO_MODE(x)                        (((uint32_t)(((uint32_t)(x)) << IOCON_PIO_MODE_SHIFT)) & IOCON_PIO_MODE_MASK)
#define IOCON_PIO_S_MODE_MASK                    (0x1800U)
#define IOCON_PIO_S_MODE_SHIFT                   (11U)
/*! S_MODE - Modo de muestreo de filtro digital.
 *  0b00..Bypass input filter.
 *  0b01..1 ciclo de clock. Los pulsos de entrada más angostos que 1 ciclo de clock del filtro son rechazados.
 *  0b10..2 ciclo de clock. Los pulsos de entrada más angostos que 2 ciclo de clock del filtro son rechazados.
 *  0b11..3 ciclo de clock. Los pulsos de entrada más angostos que 3 ciclo de clock del filtro son rechazados.
 */
#define IOCON_PIO_CLK_DIV_MASK                   (0xE000U)
#define IOCON_PIO_CLK_DIV_SHIFT                  (13U)
/*! CLK_DIV - Selección de divisor de clock para el clock de muestreo del filtro de entrada. Valor 0x7 está reservado.
 *  0b000..IOCONCLKDIV0
 *  0b001..IOCONCLKDIV1
 *  0b010..IOCONCLKDIV2
 *  0b011..IOCONCLKDIV3
 *  0b100..IOCONCLKDIV4
 *  0b101..IOCONCLKDIV5
 *  0b110..IOCONCLKDIV6
 */
#define IOCON_PIO_DACMODE_MASK                   (0x10000U)
#define IOCON_PIO_DACMODE_SHIFT                  (16U)
/*! DACMODE - Modo DAC enable.
 *  0b0..Disable.
 *  0b1..Enable.
 */
/*! @} */

/* Cantidad de IOCON_PIO */
#define IOCON_PIO_COUNT                          (56U)


/*!
 * @}
 */ /* Fin de máscaras de registros de IOCON */


/* IOCON - Dirección base de la instancia del periférico */
/** Dirección base del periférico IOCON */
#define IOCON_BASE                               (0x40044000u)
/** Puntero a la base del periférico IOCON */
#define IOCON                                    ((IOCON_Type *)IOCON_BASE)
/** Array inicializador de la dirección base de IOCON */
#define IOCON_BASE_ADDRS                         { IOCON_BASE }
/** Array inicializador del puntero de IOCON */
#define IOCON_BASE_PTRS                          { IOCON }

#define    IOCON_INDEX_PIO0_17       ( 0)
#define    IOCON_INDEX_PIO0_13       ( 1)
#define    IOCON_INDEX_PIO0_12       ( 2)
#define    IOCON_INDEX_PIO0_5        ( 3)
#define    IOCON_INDEX_PIO0_4        ( 4)
#define    IOCON_INDEX_PIO0_3        ( 5)
#define    IOCON_INDEX_PIO0_2        ( 6)
#define    IOCON_INDEX_PIO0_11       ( 7)
#define    IOCON_INDEX_PIO0_10       ( 8)
#define    IOCON_INDEX_PIO0_16       ( 9)
#define    IOCON_INDEX_PIO0_15       (10)
#define    IOCON_INDEX_PIO0_1        (11)
#define    IOCON_INDEX_PIO0_9        (13)
#define    IOCON_INDEX_PIO0_8        (14)
#define    IOCON_INDEX_PIO0_7        (15)
#define    IOCON_INDEX_PIO0_6        (16)
#define    IOCON_INDEX_PIO0_0        (17)
#define    IOCON_INDEX_PIO0_14       (18)
#define    IOCON_INDEX_PIO0_28       (20)
#define    IOCON_INDEX_PIO0_27       (21)
#define    IOCON_INDEX_PIO0_26       (22)
#define    IOCON_INDEX_PIO0_25       (23)
#define    IOCON_INDEX_PIO0_24       (24)
#define    IOCON_INDEX_PIO0_23       (25)
#define    IOCON_INDEX_PIO0_22       (26)
#define    IOCON_INDEX_PIO0_21       (27)
#define    IOCON_INDEX_PIO0_20       (28)
#define    IOCON_INDEX_PIO0_19       (29)
#define    IOCON_INDEX_PIO0_18       (30)
#define    IOCON_INDEX_PIO1_8        (31)
#define    IOCON_INDEX_PIO1_9        (32)
#define    IOCON_INDEX_PIO1_12       (33)
#define    IOCON_INDEX_PIO1_13       (34)
#define    IOCON_INDEX_PIO0_31       (35)
#define    IOCON_INDEX_PIO1_0        (36)
#define    IOCON_INDEX_PIO1_1        (37)
#define    IOCON_INDEX_PIO1_2        (38)
#define    IOCON_INDEX_PIO1_14       (39)
#define    IOCON_INDEX_PIO1_15       (40)
#define    IOCON_INDEX_PIO1_3        (41)
#define    IOCON_INDEX_PIO1_4        (42)
#define    IOCON_INDEX_PIO1_5        (43)
#define    IOCON_INDEX_PIO1_16       (44)
#define    IOCON_INDEX_PIO1_17       (45)
#define    IOCON_INDEX_PIO1_6        (46)
#define    IOCON_INDEX_PIO1_18       (47)
#define    IOCON_INDEX_PIO1_19       (48)
#define    IOCON_INDEX_PIO1_7        (49)
#define    IOCON_INDEX_PIO0_29       (50)
#define    IOCON_INDEX_PIO0_30       (51)
#define    IOCON_INDEX_PIO1_20       (52)
#define    IOCON_INDEX_PIO1_21       (53)
#define    IOCON_INDEX_PIO1_11       (54)
#define    IOCON_INDEX_PIO1_10       (55)


/*!
 * @}
 */ /* Final del bloque de acceso a IOCON */




/* ----------------------------------------------------------------------------
   -- Acceso a GPIO
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Acceso a GPIO
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint8_t B[2][32];                           /**< Registros de acceso a los pines de a Byte para port 0 y 1, array offset: 0x0, array step: index*0x20, index2*0x1 */
       uint8_t RESERVED_0[4032];
  __IO uint32_t W[2][32];                          /**< Registros de acceso a los pines de a Word para port 0 y 1, array offset: 0x1000, array step: index*0x80, index2*0x4 */
       uint8_t RESERVED_1[3840];
  __IO uint32_t DIR[2];                            /**< Registros de Dirección, array offset: 0x2000, array step: 0x4 */
       uint8_t RESERVED_2[120];
  __IO uint32_t MASK[2];                           /**< Registros de Máscara, array offset: 0x2080, array step: 0x4 */
       uint8_t RESERVED_3[120];
  __IO uint32_t PIN[2];                            /**< Registros de pines de los puertos, array offset: 0x2100, array step: 0x4 */
       uint8_t RESERVED_4[120];
  __IO uint32_t MPIN[2];                           /**< Registros enmascarados de los puertos, array offset: 0x2180, array step: 0x4 */
       uint8_t RESERVED_5[120];
  __IO uint32_t SET[2];                            /**< Set port, array offset: 0x2200, array step: 0x4 */
       uint8_t RESERVED_6[120];
  __O  uint32_t CLR[2];                            /**< Clear port, array offset: 0x2280, array step: 0x4 */
       uint8_t RESERVED_7[120];
  __O  uint32_t NOT[2];                            /**< Toggle port, array offset: 0x2300, array step: 0x4 */
       uint8_t RESERVED_8[120];
  __O  uint32_t DIRSET[2];                         /**< Set bits de dirección para el puerto, array offset: 0x2380, array step: 0x4 */
       uint8_t RESERVED_9[120];
  __O  uint32_t DIRCLR[2];                         /**< Clear bits de dirección para el puerto, array offset: 0x2400, array step: 0x4 */
       uint8_t RESERVED_10[120];
  __O  uint32_t DIRNOT[2];                         /**< Toggle bits de dirección para el puerto, array offset: 0x2480, array step: 0x4 */
} GPIO_Type;





/* ----------------------------------------------------------------------------
   -- Máscaras registros de GPIO
   ---------------------------------------------------------------------------- */



/* GPIO - Dirección de base de la instancia de periferico */
/** Dirección de base de periférico GPIO */
#define GPIO_BASE                                (0x0A0000000u)
/** Puntero a la base de periférico GPIO */
#define GPIO                                     ((GPIO_Type *)GPIO_BASE)

/*!
 * @}
 */ /* Final del bloque de acceso a IOCON  */

/* ----------------------------------------------------------------------------
   -- PINT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PINT_Peripheral_Access_Layer PINT Peripheral Access Layer
 * @{
 */

/** PINT - Register Layout Typedef */
typedef struct {
  __IO uint32_t ISEL;                              /**< Pin Interrupt Mode register, offset: 0x0 */
  __IO uint32_t IENR;                              /**< Pin interrupt level or rising edge interrupt enable register, offset: 0x4 */
  __O  uint32_t SIENR;                             /**< Pin interrupt level or rising edge interrupt set register, offset: 0x8 */
  __O  uint32_t CIENR;                             /**< Pin interrupt level (rising edge interrupt) clear register, offset: 0xC */
  __IO uint32_t IENF;                              /**< Pin interrupt active level or falling edge interrupt enable register, offset: 0x10 */
  __O  uint32_t SIENF;                             /**< Pin interrupt active level or falling edge interrupt set register, offset: 0x14 */
  __O  uint32_t CIENF;                             /**< Pin interrupt active level or falling edge interrupt clear register, offset: 0x18 */
  __IO uint32_t RISE;                              /**< Pin interrupt rising edge register, offset: 0x1C */
  __IO uint32_t FALL;                              /**< Pin interrupt falling edge register, offset: 0x20 */
  __IO uint32_t IST;                               /**< Pin interrupt status register, offset: 0x24 */
  __IO uint32_t PMCTRL;                            /**< Pattern match interrupt control register, offset: 0x28 */
  __IO uint32_t PMSRC;                             /**< Pattern match interrupt bit-slice source register, offset: 0x2C */
  __IO uint32_t PMCFG;                             /**< Pattern match interrupt bit slice configuration register, offset: 0x30 */
} PINT_Type;

/* ----------------------------------------------------------------------------
   -- PINT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PINT_Register_Masks PINT Register Masks
 * @{
 */

/*! @name ISEL - Pin Interrupt Mode register */
/*! @{ */
#define PINT_ISEL_PMODE_MASK                     (0xFFU)
#define PINT_ISEL_PMODE_SHIFT                    (0U)
/*! PMODE - Selects the interrupt mode for each pin interrupt. Bit n configures the pin interrupt
 *    selected in PINTSELn. 0 = Edge sensitive 1 = Level sensitive
 */
#define PINT_ISEL_PMODE(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_ISEL_PMODE_SHIFT)) & PINT_ISEL_PMODE_MASK)
/*! @} */

/*! @name IENR - Pin interrupt level or rising edge interrupt enable register */
/*! @{ */
#define PINT_IENR_ENRL_MASK                      (0xFFU)
#define PINT_IENR_ENRL_SHIFT                     (0U)
/*! ENRL - Enables the rising edge or level interrupt for each pin interrupt. Bit n configures the
 *    pin interrupt selected in PINTSELn. 0 = Disable rising edge or level interrupt. 1 = Enable
 *    rising edge or level interrupt.
 */
#define PINT_IENR_ENRL(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_IENR_ENRL_SHIFT)) & PINT_IENR_ENRL_MASK)
/*! @} */

/*! @name SIENR - Pin interrupt level or rising edge interrupt set register */
/*! @{ */
#define PINT_SIENR_SETENRL_MASK                  (0xFFU)
#define PINT_SIENR_SETENRL_SHIFT                 (0U)
/*! SETENRL - Ones written to this address set bits in the IENR, thus enabling interrupts. Bit n
 *    sets bit n in the IENR register. 0 = No operation. 1 = Enable rising edge or level interrupt.
 */
#define PINT_SIENR_SETENRL(x)                    (((uint32_t)(((uint32_t)(x)) << PINT_SIENR_SETENRL_SHIFT)) & PINT_SIENR_SETENRL_MASK)
/*! @} */

/*! @name CIENR - Pin interrupt level (rising edge interrupt) clear register */
/*! @{ */
#define PINT_CIENR_CENRL_MASK                    (0xFFU)
#define PINT_CIENR_CENRL_SHIFT                   (0U)
/*! CENRL - Ones written to this address clear bits in the IENR, thus disabling the interrupts. Bit
 *    n clears bit n in the IENR register. 0 = No operation. 1 = Disable rising edge or level
 *    interrupt.
 */
#define PINT_CIENR_CENRL(x)                      (((uint32_t)(((uint32_t)(x)) << PINT_CIENR_CENRL_SHIFT)) & PINT_CIENR_CENRL_MASK)
/*! @} */

/*! @name IENF - Pin interrupt active level or falling edge interrupt enable register */
/*! @{ */
#define PINT_IENF_ENAF_MASK                      (0xFFU)
#define PINT_IENF_ENAF_SHIFT                     (0U)
/*! ENAF - Enables the falling edge or configures the active level interrupt for each pin interrupt.
 *    Bit n configures the pin interrupt selected in PINTSELn. 0 = Disable falling edge interrupt
 *    or set active interrupt level LOW. 1 = Enable falling edge interrupt enabled or set active
 *    interrupt level HIGH.
 */
#define PINT_IENF_ENAF(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_IENF_ENAF_SHIFT)) & PINT_IENF_ENAF_MASK)
/*! @} */

/*! @name SIENF - Pin interrupt active level or falling edge interrupt set register */
/*! @{ */
#define PINT_SIENF_SETENAF_MASK                  (0xFFU)
#define PINT_SIENF_SETENAF_SHIFT                 (0U)
/*! SETENAF - Ones written to this address set bits in the IENF, thus enabling interrupts. Bit n
 *    sets bit n in the IENF register. 0 = No operation. 1 = Select HIGH-active interrupt or enable
 *    falling edge interrupt.
 */
#define PINT_SIENF_SETENAF(x)                    (((uint32_t)(((uint32_t)(x)) << PINT_SIENF_SETENAF_SHIFT)) & PINT_SIENF_SETENAF_MASK)
/*! @} */

/*! @name CIENF - Pin interrupt active level or falling edge interrupt clear register */
/*! @{ */
#define PINT_CIENF_CENAF_MASK                    (0xFFU)
#define PINT_CIENF_CENAF_SHIFT                   (0U)
/*! CENAF - Ones written to this address clears bits in the IENF, thus disabling interrupts. Bit n
 *    clears bit n in the IENF register. 0 = No operation. 1 = LOW-active interrupt selected or
 *    falling edge interrupt disabled.
 */
#define PINT_CIENF_CENAF(x)                      (((uint32_t)(((uint32_t)(x)) << PINT_CIENF_CENAF_SHIFT)) & PINT_CIENF_CENAF_MASK)
/*! @} */

/*! @name RISE - Pin interrupt rising edge register */
/*! @{ */
#define PINT_RISE_RDET_MASK                      (0xFFU)
#define PINT_RISE_RDET_SHIFT                     (0U)
/*! RDET - Rising edge detect. Bit n detects the rising edge of the pin selected in PINTSELn. Read
 *    0: No rising edge has been detected on this pin since Reset or the last time a one was written
 *    to this bit. Write 0: no operation. Read 1: a rising edge has been detected since Reset or the
 *    last time a one was written to this bit. Write 1: clear rising edge detection for this pin.
 */
#define PINT_RISE_RDET(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_RISE_RDET_SHIFT)) & PINT_RISE_RDET_MASK)
/*! @} */

/*! @name FALL - Pin interrupt falling edge register */
/*! @{ */
#define PINT_FALL_FDET_MASK                      (0xFFU)
#define PINT_FALL_FDET_SHIFT                     (0U)
/*! FDET - Falling edge detect. Bit n detects the falling edge of the pin selected in PINTSELn. Read
 *    0: No falling edge has been detected on this pin since Reset or the last time a one was
 *    written to this bit. Write 0: no operation. Read 1: a falling edge has been detected since Reset or
 *    the last time a one was written to this bit. Write 1: clear falling edge detection for this
 *    pin.
 */
#define PINT_FALL_FDET(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_FALL_FDET_SHIFT)) & PINT_FALL_FDET_MASK)
/*! @} */

/*! @name IST - Pin interrupt status register */
/*! @{ */
#define PINT_IST_PSTAT_MASK                      (0xFFU)
#define PINT_IST_PSTAT_SHIFT                     (0U)
/*! PSTAT - Pin interrupt status. Bit n returns the status, clears the edge interrupt, or inverts
 *    the active level of the pin selected in PINTSELn. Read 0: interrupt is not being requested for
 *    this interrupt pin. Write 0: no operation. Read 1: interrupt is being requested for this
 *    interrupt pin. Write 1 (edge-sensitive): clear rising- and falling-edge detection for this pin.
 *    Write 1 (level-sensitive): switch the active level for this pin (in the IENF register).
 */
#define PINT_IST_PSTAT(x)                        (((uint32_t)(((uint32_t)(x)) << PINT_IST_PSTAT_SHIFT)) & PINT_IST_PSTAT_MASK)
/*! @} */

/*! @name PMCTRL - Pattern match interrupt control register */
/*! @{ */
#define PINT_PMCTRL_SEL_PMATCH_MASK              (0x1U)
#define PINT_PMCTRL_SEL_PMATCH_SHIFT             (0U)
/*! SEL_PMATCH - Specifies whether the 8 pin interrupts are controlled by the pin interrupt function or by the pattern match function.
 *  0b0..Pin interrupt. Interrupts are driven in response to the standard pin interrupt function.
 *  0b1..Pattern match. Interrupts are driven in response to pattern matches.
 */
#define PINT_PMCTRL_SEL_PMATCH(x)                (((uint32_t)(((uint32_t)(x)) << PINT_PMCTRL_SEL_PMATCH_SHIFT)) & PINT_PMCTRL_SEL_PMATCH_MASK)
#define PINT_PMCTRL_ENA_RXEV_MASK                (0x2U)
#define PINT_PMCTRL_ENA_RXEV_SHIFT               (1U)
/*! ENA_RXEV - Enables the RXEV output to the CPU and/or to a GPIO output when the specified boolean expression evaluates to true.
 *  0b0..Disabled. RXEV output to the CPU is disabled.
 *  0b1..Enabled. RXEV output to the CPU is enabled.
 */
#define PINT_PMCTRL_ENA_RXEV(x)                  (((uint32_t)(((uint32_t)(x)) << PINT_PMCTRL_ENA_RXEV_SHIFT)) & PINT_PMCTRL_ENA_RXEV_MASK)
#define PINT_PMCTRL_PMAT_MASK                    (0xFF000000U)
#define PINT_PMCTRL_PMAT_SHIFT                   (24U)
/*! PMAT - This field displays the current state of pattern matches. A 1 in any bit of this field
 *    indicates that the corresponding product term is matched by the current state of the appropriate
 *    inputs.
 */
#define PINT_PMCTRL_PMAT(x)                      (((uint32_t)(((uint32_t)(x)) << PINT_PMCTRL_PMAT_SHIFT)) & PINT_PMCTRL_PMAT_MASK)
/*! @} */

/*! @name PMSRC - Pattern match interrupt bit-slice source register */
/*! @{ */
#define PINT_PMSRC_SRC0_MASK                     (0x700U)
#define PINT_PMSRC_SRC0_SHIFT                    (8U)
/*! SRC0 - Selects the input source for bit slice 0
 *  0b000..Input 0. Selects the pin selected in the PINTSEL0 register as the source to bit slice 0.
 *  0b001..Input 1. Selects the pin selected in the PINTSEL1 register as the source to bit slice 0.
 *  0b010..Input 2. Selects the pin selected in the PINTSEL2 register as the source to bit slice 0.
 *  0b011..Input 3. Selects the pin selected in the PINTSEL3 register as the source to bit slice 0.
 *  0b100..Input 4. Selects the pin selected in the PINTSEL4 register as the source to bit slice 0.
 *  0b101..Input 5. Selects the pin selected in the PINTSEL5 register as the source to bit slice 0.
 *  0b110..Input 6. Selects the pin selected in the PINTSEL6 register as the source to bit slice 0.
 *  0b111..Input 7. Selects the pin selected in the PINTSEL7 register as the source to bit slice 0.
 */
#define PINT_PMSRC_SRC0(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC0_SHIFT)) & PINT_PMSRC_SRC0_MASK)
#define PINT_PMSRC_SRC1_MASK                     (0x3800U)
#define PINT_PMSRC_SRC1_SHIFT                    (11U)
/*! SRC1 - Selects the input source for bit slice 1
 *  0b000..Input 0. Selects the pin selected in the PINTSEL0 register as the source to bit slice 1.
 *  0b001..Input 1. Selects the pin selected in the PINTSEL1 register as the source to bit slice 1.
 *  0b010..Input 2. Selects the pin selected in the PINTSEL2 register as the source to bit slice 1.
 *  0b011..Input 3. Selects the pin selected in the PINTSEL3 register as the source to bit slice 1.
 *  0b100..Input 4. Selects the pin selected in the PINTSEL4 register as the source to bit slice 1.
 *  0b101..Input 5. Selects the pin selected in the PINTSEL5 register as the source to bit slice 1.
 *  0b110..Input 6. Selects the pin selected in the PINTSEL6 register as the source to bit slice 1.
 *  0b111..Input 7. Selects the pin selected in the PINTSEL7 register as the source to bit slice 1.
 */
#define PINT_PMSRC_SRC1(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC1_SHIFT)) & PINT_PMSRC_SRC1_MASK)
#define PINT_PMSRC_SRC2_MASK                     (0x1C000U)
#define PINT_PMSRC_SRC2_SHIFT                    (14U)
/*! SRC2 - Selects the input source for bit slice 2
 *  0b000..Input 0. Selects the pin selected in the PINTSEL0 register as the source to bit slice 2.
 *  0b001..Input 1. Selects the pin selected in the PINTSEL1 register as the source to bit slice 2.
 *  0b010..Input 2. Selects the pin selected in the PINTSEL2 register as the source to bit slice 2.
 *  0b011..Input 3. Selects the pin selected in the PINTSEL3 register as the source to bit slice 2.
 *  0b100..Input 4. Selects the pin selected in the PINTSEL4 register as the source to bit slice 2.
 *  0b101..Input 5. Selects the pin selected in the PINTSEL5 register as the source to bit slice 2.
 *  0b110..Input 6. Selects the pin selected in the PINTSEL6 register as the source to bit slice 2.
 *  0b111..Input 7. Selects the pin selected in the PINTSEL7 register as the source to bit slice 2.
 */
#define PINT_PMSRC_SRC2(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC2_SHIFT)) & PINT_PMSRC_SRC2_MASK)
#define PINT_PMSRC_SRC3_MASK                     (0xE0000U)
#define PINT_PMSRC_SRC3_SHIFT                    (17U)
/*! SRC3 - Selects the input source for bit slice 3
 *  0b000..Input 0. Selects the pin selected in the PINTSEL0 register as the source to bit slice 3.
 *  0b001..Input 1. Selects the pin selected in the PINTSEL1 register as the source to bit slice 3.
 *  0b010..Input 2. Selects the pin selected in the PINTSEL2 register as the source to bit slice 3.
 *  0b011..Input 3. Selects the pin selected in the PINTSEL3 register as the source to bit slice 3.
 *  0b100..Input 4. Selects the pin selected in the PINTSEL4 register as the source to bit slice 3.
 *  0b101..Input 5. Selects the pin selected in the PINTSEL5 register as the source to bit slice 3.
 *  0b110..Input 6. Selects the pin selected in the PINTSEL6 register as the source to bit slice 3.
 *  0b111..Input 7. Selects the pin selected in the PINTSEL7 register as the source to bit slice 3.
 */
#define PINT_PMSRC_SRC3(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC3_SHIFT)) & PINT_PMSRC_SRC3_MASK)
#define PINT_PMSRC_SRC4_MASK                     (0x700000U)
#define PINT_PMSRC_SRC4_SHIFT                    (20U)
/*! SRC4 - Selects the input source for bit slice 4
 *  0b000..Input 0. Selects the pin selected in the PINTSEL0 register as the source to bit slice 4.
 *  0b001..Input 1. Selects the pin selected in the PINTSEL1 register as the source to bit slice 4.
 *  0b010..Input 2. Selects the pin selected in the PINTSEL2 register as the source to bit slice 4.
 *  0b011..Input 3. Selects the pin selected in the PINTSEL3 register as the source to bit slice 4.
 *  0b100..Input 4. Selects the pin selected in the PINTSEL4 register as the source to bit slice 4.
 *  0b101..Input 5. Selects the pin selected in the PINTSEL5 register as the source to bit slice 4.
 *  0b110..Input 6. Selects the pin selected in the PINTSEL6 register as the source to bit slice 4.
 *  0b111..Input 7. Selects the pin selected in the PINTSEL7 register as the source to bit slice 4.
 */
#define PINT_PMSRC_SRC4(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC4_SHIFT)) & PINT_PMSRC_SRC4_MASK)
#define PINT_PMSRC_SRC5_MASK                     (0x3800000U)
#define PINT_PMSRC_SRC5_SHIFT                    (23U)
/*! SRC5 - Selects the input source for bit slice 5
 *  0b000..Input 0. Selects the pin selected in the PINTSEL0 register as the source to bit slice 5.
 *  0b001..Input 1. Selects the pin selected in the PINTSEL1 register as the source to bit slice 5.
 *  0b010..Input 2. Selects the pin selected in the PINTSEL2 register as the source to bit slice 5.
 *  0b011..Input 3. Selects the pin selected in the PINTSEL3 register as the source to bit slice 5.
 *  0b100..Input 4. Selects the pin selected in the PINTSEL4 register as the source to bit slice 5.
 *  0b101..Input 5. Selects the pin selected in the PINTSEL5 register as the source to bit slice 5.
 *  0b110..Input 6. Selects the pin selected in the PINTSEL6 register as the source to bit slice 5.
 *  0b111..Input 7. Selects the pin selected in the PINTSEL7 register as the source to bit slice 5.
 */
#define PINT_PMSRC_SRC5(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC5_SHIFT)) & PINT_PMSRC_SRC5_MASK)
#define PINT_PMSRC_SRC6_MASK                     (0x1C000000U)
#define PINT_PMSRC_SRC6_SHIFT                    (26U)
/*! SRC6 - Selects the input source for bit slice 6
 *  0b000..Input 0. Selects the pin selected in the PINTSEL0 register as the source to bit slice 6.
 *  0b001..Input 1. Selects the pin selected in the PINTSEL1 register as the source to bit slice 6.
 *  0b010..Input 2. Selects the pin selected in the PINTSEL2 register as the source to bit slice 6.
 *  0b011..Input 3. Selects the pin selected in the PINTSEL3 register as the source to bit slice 6.
 *  0b100..Input 4. Selects the pin selected in the PINTSEL4 register as the source to bit slice 6.
 *  0b101..Input 5. Selects the pin selected in the PINTSEL5 register as the source to bit slice 6.
 *  0b110..Input 6. Selects the pin selected in the PINTSEL6 register as the source to bit slice 6.
 *  0b111..Input 7. Selects the pin selected in the PINTSEL7 register as the source to bit slice 6.
 */
#define PINT_PMSRC_SRC6(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC6_SHIFT)) & PINT_PMSRC_SRC6_MASK)
#define PINT_PMSRC_SRC7_MASK                     (0xE0000000U)
#define PINT_PMSRC_SRC7_SHIFT                    (29U)
/*! SRC7 - Selects the input source for bit slice 7
 *  0b000..Input 0. Selects the pin selected in the PINTSEL0 register as the source to bit slice 7.
 *  0b001..Input 1. Selects the pin selected in the PINTSEL1 register as the source to bit slice 7.
 *  0b010..Input 2. Selects the pin selected in the PINTSEL2 register as the source to bit slice 7.
 *  0b011..Input 3. Selects the pin selected in the PINTSEL3 register as the source to bit slice 7.
 *  0b100..Input 4. Selects the pin selected in the PINTSEL4 register as the source to bit slice 7.
 *  0b101..Input 5. Selects the pin selected in the PINTSEL5 register as the source to bit slice 7.
 *  0b110..Input 6. Selects the pin selected in the PINTSEL6 register as the source to bit slice 7.
 *  0b111..Input 7. Selects the pin selected in the PINTSEL7 register as the source to bit slice 7.
 */
#define PINT_PMSRC_SRC7(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMSRC_SRC7_SHIFT)) & PINT_PMSRC_SRC7_MASK)
/*! @} */

/*! @name PMCFG - Pattern match interrupt bit slice configuration register */
/*! @{ */
#define PINT_PMCFG_PROD_ENDPTS0_MASK             (0x1U)
#define PINT_PMCFG_PROD_ENDPTS0_SHIFT            (0U)
/*! PROD_ENDPTS0 - Determines whether slice 0 is an endpoint.
 *  0b0..No effect. Slice 0 is not an endpoint.
 *  0b1..endpoint. Slice 0 is the endpoint of a product term (minterm). Pin interrupt 0 in the NVIC is raised if the minterm evaluates as true.
 */
#define PINT_PMCFG_PROD_ENDPTS0(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS0_SHIFT)) & PINT_PMCFG_PROD_ENDPTS0_MASK)
#define PINT_PMCFG_PROD_ENDPTS1_MASK             (0x2U)
#define PINT_PMCFG_PROD_ENDPTS1_SHIFT            (1U)
/*! PROD_ENDPTS1 - Determines whether slice 1 is an endpoint.
 *  0b0..No effect. Slice 1 is not an endpoint.
 *  0b1..endpoint. Slice 1 is the endpoint of a product term (minterm). Pin interrupt 1 in the NVIC is raised if the minterm evaluates as true.
 */
#define PINT_PMCFG_PROD_ENDPTS1(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS1_SHIFT)) & PINT_PMCFG_PROD_ENDPTS1_MASK)
#define PINT_PMCFG_PROD_ENDPTS2_MASK             (0x4U)
#define PINT_PMCFG_PROD_ENDPTS2_SHIFT            (2U)
/*! PROD_ENDPTS2 - Determines whether slice 2 is an endpoint.
 *  0b0..No effect. Slice 2 is not an endpoint.
 *  0b1..endpoint. Slice 2 is the endpoint of a product term (minterm). Pin interrupt 2 in the NVIC is raised if the minterm evaluates as true.
 */
#define PINT_PMCFG_PROD_ENDPTS2(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS2_SHIFT)) & PINT_PMCFG_PROD_ENDPTS2_MASK)
#define PINT_PMCFG_PROD_ENDPTS3_MASK             (0x8U)
#define PINT_PMCFG_PROD_ENDPTS3_SHIFT            (3U)
/*! PROD_ENDPTS3 - Determines whether slice 3 is an endpoint.
 *  0b0..No effect. Slice 3 is not an endpoint.
 *  0b1..endpoint. Slice 3 is the endpoint of a product term (minterm). Pin interrupt 3 in the NVIC is raised if the minterm evaluates as true.
 */
#define PINT_PMCFG_PROD_ENDPTS3(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS3_SHIFT)) & PINT_PMCFG_PROD_ENDPTS3_MASK)
#define PINT_PMCFG_PROD_ENDPTS4_MASK             (0x10U)
#define PINT_PMCFG_PROD_ENDPTS4_SHIFT            (4U)
/*! PROD_ENDPTS4 - Determines whether slice 4 is an endpoint.
 *  0b0..No effect. Slice 4 is not an endpoint.
 *  0b1..endpoint. Slice 4 is the endpoint of a product term (minterm). Pin interrupt 4 in the NVIC is raised if the minterm evaluates as true.
 */
#define PINT_PMCFG_PROD_ENDPTS4(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS4_SHIFT)) & PINT_PMCFG_PROD_ENDPTS4_MASK)
#define PINT_PMCFG_PROD_ENDPTS5_MASK             (0x20U)
#define PINT_PMCFG_PROD_ENDPTS5_SHIFT            (5U)
/*! PROD_ENDPTS5 - Determines whether slice 5 is an endpoint.
 *  0b0..No effect. Slice 5 is not an endpoint.
 *  0b1..endpoint. Slice 5 is the endpoint of a product term (minterm). Pin interrupt 5 in the NVIC is raised if the minterm evaluates as true.
 */
#define PINT_PMCFG_PROD_ENDPTS5(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS5_SHIFT)) & PINT_PMCFG_PROD_ENDPTS5_MASK)
#define PINT_PMCFG_PROD_ENDPTS6_MASK             (0x40U)
#define PINT_PMCFG_PROD_ENDPTS6_SHIFT            (6U)
/*! PROD_ENDPTS6 - Determines whether slice 6 is an endpoint.
 *  0b0..No effect. Slice 6 is not an endpoint.
 *  0b1..endpoint. Slice 6 is the endpoint of a product term (minterm). Pin interrupt 6 in the NVIC is raised if the minterm evaluates as true.
 */
#define PINT_PMCFG_PROD_ENDPTS6(x)               (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_PROD_ENDPTS6_SHIFT)) & PINT_PMCFG_PROD_ENDPTS6_MASK)
#define PINT_PMCFG_CFG0_MASK                     (0x700U)
#define PINT_PMCFG_CFG0_SHIFT                    (8U)
/*! CFG0 - Specifies the match contribution condition for bit slice 0.
 *  0b000..Constant HIGH. This bit slice always contributes to a product term match.
 *  0b001..Sticky rising edge. Match occurs if a rising edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b010..Sticky falling edge. Match occurs if a falling edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b011..Sticky rising or falling edge. Match occurs if either a rising or falling edge on the specified input
 *         has occurred since the last time the edge detection for this bit slice was cleared. This bit is only
 *         cleared when the PMCFG or the PMSRC registers are written to.
 *  0b100..High level. Match (for this bit slice) occurs when there is a high level on the input specified for this bit slice in the PMSRC register.
 *  0b101..Low level. Match occurs when there is a low level on the specified input.
 *  0b110..Constant 0. This bit slice never contributes to a match (should be used to disable any unused bit slices).
 *  0b111..Event. Non-sticky rising or falling edge. Match occurs on an event - i.e. when either a rising or
 *         falling edge is first detected on the specified input (this is a non-sticky version of value 0x3) . This bit
 *         is cleared after one clock cycle.
 */
#define PINT_PMCFG_CFG0(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG0_SHIFT)) & PINT_PMCFG_CFG0_MASK)
#define PINT_PMCFG_CFG1_MASK                     (0x3800U)
#define PINT_PMCFG_CFG1_SHIFT                    (11U)
/*! CFG1 - Specifies the match contribution condition for bit slice 1.
 *  0b000..Constant HIGH. This bit slice always contributes to a product term match.
 *  0b001..Sticky rising edge. Match occurs if a rising edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b010..Sticky falling edge. Match occurs if a falling edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b011..Sticky rising or falling edge. Match occurs if either a rising or falling edge on the specified input
 *         has occurred since the last time the edge detection for this bit slice was cleared. This bit is only
 *         cleared when the PMCFG or the PMSRC registers are written to.
 *  0b100..High level. Match (for this bit slice) occurs when there is a high level on the input specified for this bit slice in the PMSRC register.
 *  0b101..Low level. Match occurs when there is a low level on the specified input.
 *  0b110..Constant 0. This bit slice never contributes to a match (should be used to disable any unused bit slices).
 *  0b111..Event. Non-sticky rising or falling edge. Match occurs on an event - i.e. when either a rising or
 *         falling edge is first detected on the specified input (this is a non-sticky version of value 0x3) . This bit
 *         is cleared after one clock cycle.
 */
#define PINT_PMCFG_CFG1(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG1_SHIFT)) & PINT_PMCFG_CFG1_MASK)
#define PINT_PMCFG_CFG2_MASK                     (0x1C000U)
#define PINT_PMCFG_CFG2_SHIFT                    (14U)
/*! CFG2 - Specifies the match contribution condition for bit slice 2.
 *  0b000..Constant HIGH. This bit slice always contributes to a product term match.
 *  0b001..Sticky rising edge. Match occurs if a rising edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b010..Sticky falling edge. Match occurs if a falling edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b011..Sticky rising or falling edge. Match occurs if either a rising or falling edge on the specified input
 *         has occurred since the last time the edge detection for this bit slice was cleared. This bit is only
 *         cleared when the PMCFG or the PMSRC registers are written to.
 *  0b100..High level. Match (for this bit slice) occurs when there is a high level on the input specified for this bit slice in the PMSRC register.
 *  0b101..Low level. Match occurs when there is a low level on the specified input.
 *  0b110..Constant 0. This bit slice never contributes to a match (should be used to disable any unused bit slices).
 *  0b111..Event. Non-sticky rising or falling edge. Match occurs on an event - i.e. when either a rising or
 *         falling edge is first detected on the specified input (this is a non-sticky version of value 0x3) . This bit
 *         is cleared after one clock cycle.
 */
#define PINT_PMCFG_CFG2(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG2_SHIFT)) & PINT_PMCFG_CFG2_MASK)
#define PINT_PMCFG_CFG3_MASK                     (0xE0000U)
#define PINT_PMCFG_CFG3_SHIFT                    (17U)
/*! CFG3 - Specifies the match contribution condition for bit slice 3.
 *  0b000..Constant HIGH. This bit slice always contributes to a product term match.
 *  0b001..Sticky rising edge. Match occurs if a rising edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b010..Sticky falling edge. Match occurs if a falling edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b011..Sticky rising or falling edge. Match occurs if either a rising or falling edge on the specified input
 *         has occurred since the last time the edge detection for this bit slice was cleared. This bit is only
 *         cleared when the PMCFG or the PMSRC registers are written to.
 *  0b100..High level. Match (for this bit slice) occurs when there is a high level on the input specified for this bit slice in the PMSRC register.
 *  0b101..Low level. Match occurs when there is a low level on the specified input.
 *  0b110..Constant 0. This bit slice never contributes to a match (should be used to disable any unused bit slices).
 *  0b111..Event. Non-sticky rising or falling edge. Match occurs on an event - i.e. when either a rising or
 *         falling edge is first detected on the specified input (this is a non-sticky version of value 0x3) . This bit
 *         is cleared after one clock cycle.
 */
#define PINT_PMCFG_CFG3(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG3_SHIFT)) & PINT_PMCFG_CFG3_MASK)
#define PINT_PMCFG_CFG4_MASK                     (0x700000U)
#define PINT_PMCFG_CFG4_SHIFT                    (20U)
/*! CFG4 - Specifies the match contribution condition for bit slice 4.
 *  0b000..Constant HIGH. This bit slice always contributes to a product term match.
 *  0b001..Sticky rising edge. Match occurs if a rising edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b010..Sticky falling edge. Match occurs if a falling edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b011..Sticky rising or falling edge. Match occurs if either a rising or falling edge on the specified input
 *         has occurred since the last time the edge detection for this bit slice was cleared. This bit is only
 *         cleared when the PMCFG or the PMSRC registers are written to.
 *  0b100..High level. Match (for this bit slice) occurs when there is a high level on the input specified for this bit slice in the PMSRC register.
 *  0b101..Low level. Match occurs when there is a low level on the specified input.
 *  0b110..Constant 0. This bit slice never contributes to a match (should be used to disable any unused bit slices).
 *  0b111..Event. Non-sticky rising or falling edge. Match occurs on an event - i.e. when either a rising or
 *         falling edge is first detected on the specified input (this is a non-sticky version of value 0x3) . This bit
 *         is cleared after one clock cycle.
 */
#define PINT_PMCFG_CFG4(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG4_SHIFT)) & PINT_PMCFG_CFG4_MASK)
#define PINT_PMCFG_CFG5_MASK                     (0x3800000U)
#define PINT_PMCFG_CFG5_SHIFT                    (23U)
/*! CFG5 - Specifies the match contribution condition for bit slice 5.
 *  0b000..Constant HIGH. This bit slice always contributes to a product term match.
 *  0b001..Sticky rising edge. Match occurs if a rising edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b010..Sticky falling edge. Match occurs if a falling edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b011..Sticky rising or falling edge. Match occurs if either a rising or falling edge on the specified input
 *         has occurred since the last time the edge detection for this bit slice was cleared. This bit is only
 *         cleared when the PMCFG or the PMSRC registers are written to.
 *  0b100..High level. Match (for this bit slice) occurs when there is a high level on the input specified for this bit slice in the PMSRC register.
 *  0b101..Low level. Match occurs when there is a low level on the specified input.
 *  0b110..Constant 0. This bit slice never contributes to a match (should be used to disable any unused bit slices).
 *  0b111..Event. Non-sticky rising or falling edge. Match occurs on an event - i.e. when either a rising or
 *         falling edge is first detected on the specified input (this is a non-sticky version of value 0x3) . This bit
 *         is cleared after one clock cycle.
 */
#define PINT_PMCFG_CFG5(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG5_SHIFT)) & PINT_PMCFG_CFG5_MASK)
#define PINT_PMCFG_CFG6_MASK                     (0x1C000000U)
#define PINT_PMCFG_CFG6_SHIFT                    (26U)
/*! CFG6 - Specifies the match contribution condition for bit slice 6.
 *  0b000..Constant HIGH. This bit slice always contributes to a product term match.
 *  0b001..Sticky rising edge. Match occurs if a rising edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b010..Sticky falling edge. Match occurs if a falling edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b011..Sticky rising or falling edge. Match occurs if either a rising or falling edge on the specified input
 *         has occurred since the last time the edge detection for this bit slice was cleared. This bit is only
 *         cleared when the PMCFG or the PMSRC registers are written to.
 *  0b100..High level. Match (for this bit slice) occurs when there is a high level on the input specified for this bit slice in the PMSRC register.
 *  0b101..Low level. Match occurs when there is a low level on the specified input.
 *  0b110..Constant 0. This bit slice never contributes to a match (should be used to disable any unused bit slices).
 *  0b111..Event. Non-sticky rising or falling edge. Match occurs on an event - i.e. when either a rising or
 *         falling edge is first detected on the specified input (this is a non-sticky version of value 0x3) . This bit
 *         is cleared after one clock cycle.
 */
#define PINT_PMCFG_CFG6(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG6_SHIFT)) & PINT_PMCFG_CFG6_MASK)
#define PINT_PMCFG_CFG7_MASK                     (0xE0000000U)
#define PINT_PMCFG_CFG7_SHIFT                    (29U)
/*! CFG7 - Specifies the match contribution condition for bit slice 7.
 *  0b000..Constant HIGH. This bit slice always contributes to a product term match.
 *  0b001..Sticky rising edge. Match occurs if a rising edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b010..Sticky falling edge. Match occurs if a falling edge on the specified input has occurred since the last
 *         time the edge detection for this bit slice was cleared. This bit is only cleared when the PMCFG or the
 *         PMSRC registers are written to.
 *  0b011..Sticky rising or falling edge. Match occurs if either a rising or falling edge on the specified input
 *         has occurred since the last time the edge detection for this bit slice was cleared. This bit is only
 *         cleared when the PMCFG or the PMSRC registers are written to.
 *  0b100..High level. Match (for this bit slice) occurs when there is a high level on the input specified for this bit slice in the PMSRC register.
 *  0b101..Low level. Match occurs when there is a low level on the specified input.
 *  0b110..Constant 0. This bit slice never contributes to a match (should be used to disable any unused bit slices).
 *  0b111..Event. Non-sticky rising or falling edge. Match occurs on an event - i.e. when either a rising or
 *         falling edge is first detected on the specified input (this is a non-sticky version of value 0x3) . This bit
 *         is cleared after one clock cycle.
 */
#define PINT_PMCFG_CFG7(x)                       (((uint32_t)(((uint32_t)(x)) << PINT_PMCFG_CFG7_SHIFT)) & PINT_PMCFG_CFG7_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PINT_Register_Masks */


/* PINT - Peripheral instance base addresses */
/** Peripheral PINT base address */
#define PINT_BASE                                (0xA0004000u)
/** Peripheral PINT base pointer */
#define PINT                                     ((PINT_Type *)PINT_BASE)
/** Array initializer of PINT peripheral base addresses */
#define PINT_BASE_ADDRS                          { PINT_BASE }
/** Array initializer of PINT peripheral base pointers */
#define PINT_BASE_PTRS                           { PINT }
/** Interrupt vectors for the PINT peripheral type */
#define PINT_IRQS                                { PIN_INT0_IRQn, PIN_INT1_IRQn, PIN_INT2_IRQn, PIN_INT3_IRQn, PIN_INT4_IRQn, PIN_INT5_DAC1_IRQn, PIN_INT6_USART3_IRQn, PIN_INT7_USART4_IRQn }

/*!
 * @}
 */ /* end of group PINT_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- USART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USART_Peripheral_Access_Layer USART Peripheral Access Layer
 * @{
 */

/** USART - Register Layout Typedef */
typedef struct {
  __IO uint32_t CFG;                               /**< USART Configuration register. Basic USART configuration settings that typically are not changed during operation., offset: 0x0 */
  __IO uint32_t CTL;                               /**< USART Control register. USART control settings that are more likely to change during operation., offset: 0x4 */
  __IO uint32_t STAT;                              /**< USART Status register. The complete status value can be read here. Writing ones clears some bits in the register. Some bits can be cleared by writing a 1 to them., offset: 0x8 */
  __IO uint32_t INTENSET;                          /**< Interrupt Enable read and Set register. Contains an individual interrupt enable bit for each potential USART interrupt. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set., offset: 0xC */
  __O  uint32_t INTENCLR;                          /**< Interrupt Enable Clear register. Allows clearing any combination of bits in the INTENSET register. Writing a 1 to any implemented bit position causes the corresponding bit to be cleared., offset: 0x10 */
  __I  uint32_t RXDAT;                             /**< Receiver Data register. Contains the last character received., offset: 0x14 */
  __I  uint32_t RXDATSTAT;                         /**< Receiver Data with Status register. Combines the last character received with the current USART receive status. Allows DMA or software to recover incoming data and status together., offset: 0x18 */
  __IO uint32_t TXDAT;                             /**< Transmit Data register. Data to be transmitted is written here., offset: 0x1C */
  __IO uint32_t BRG;                               /**< Baud Rate Generator register. 16-bit integer baud rate divisor value., offset: 0x20 */
  __I  uint32_t INTSTAT;                           /**< Interrupt status register. Reflects interrupts that are currently enabled., offset: 0x24 */
  __IO uint32_t OSR;                               /**< Oversample selection register for asynchronous communication., offset: 0x28 */
  __IO uint32_t ADDR;                              /**< Address register for automatic address matching., offset: 0x2C */
} USART_Type;

/* ----------------------------------------------------------------------------
   -- USART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USART_Register_Masks USART Register Masks
 * @{
 */

/*! @name CFG - USART Configuration register. Basic USART configuration settings that typically are not changed during operation. */
/*! @{ */
#define USART_CFG_ENABLE_MASK                    (0x1U)
#define USART_CFG_ENABLE_SHIFT                   (0U)
/*! ENABLE - USART Enable.
 *  0b0..Disabled. The USART is disabled and the internal state machine and counters are reset. While Enable = 0,
 *       all USART interrupts and DMA transfers are disabled. When Enable is set again, CFG and most other control
 *       bits remain unchanged. When re-enabled, the USART will immediately be ready to transmit because the
 *       transmitter has been reset and is therefore available.
 *  0b1..Enabled. The USART is enabled for operation.
 */
#define USART_CFG_ENABLE(x)                      (((uint32_t)(((uint32_t)(x)) << USART_CFG_ENABLE_SHIFT)) & USART_CFG_ENABLE_MASK)
#define USART_CFG_DATALEN_MASK                   (0xCU)
#define USART_CFG_DATALEN_SHIFT                  (2U)
/*! DATALEN - Selects the data size for the USART.
 *  0b00..7 bit Data length.
 *  0b01..8 bit Data length.
 *  0b10..9 bit data length. The 9th bit is commonly used for addressing in multidrop mode. See the ADDRDET bit in the CTL register.
 *  0b11..Reserved.
 */
#define USART_CFG_DATALEN(x)                     (((uint32_t)(((uint32_t)(x)) << USART_CFG_DATALEN_SHIFT)) & USART_CFG_DATALEN_MASK)
#define USART_CFG_PARITYSEL_MASK                 (0x30U)
#define USART_CFG_PARITYSEL_SHIFT                (4U)
/*! PARITYSEL - Selects what type of parity is used by the USART.
 *  0b00..No parity.
 *  0b01..Reserved.
 *  0b10..Even parity. Adds a bit to each character such that the number of 1s in a transmitted character is even,
 *        and the number of 1s in a received character is expected to be even.
 *  0b11..Odd parity. Adds a bit to each character such that the number of 1s in a transmitted character is odd,
 *        and the number of 1s in a received character is expected to be odd.
 */
#define USART_CFG_PARITYSEL(x)                   (((uint32_t)(((uint32_t)(x)) << USART_CFG_PARITYSEL_SHIFT)) & USART_CFG_PARITYSEL_MASK)
#define USART_CFG_STOPLEN_MASK                   (0x40U)
#define USART_CFG_STOPLEN_SHIFT                  (6U)
/*! STOPLEN - Number of stop bits appended to transmitted data. Only a single stop bit is required for received data.
 *  0b0..1 stop bit.
 *  0b1..2 stop bits. This setting should only be used for asynchronous communication.
 */
#define USART_CFG_STOPLEN(x)                     (((uint32_t)(((uint32_t)(x)) << USART_CFG_STOPLEN_SHIFT)) & USART_CFG_STOPLEN_MASK)
#define USART_CFG_CTSEN_MASK                     (0x200U)
#define USART_CFG_CTSEN_SHIFT                    (9U)
/*! CTSEN - CTS Enable. Determines whether CTS is used for flow control. CTS can be from the input
 *    pin, or from the USART's own RTS if loopback mode is enabled.
 *  0b0..No flow control. The transmitter does not receive any automatic flow control signal.
 *  0b1..Flow control enabled. The transmitter uses the CTS input (or RTS output in loopback mode) for flow control purposes.
 */
#define USART_CFG_CTSEN(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CFG_CTSEN_SHIFT)) & USART_CFG_CTSEN_MASK)
#define USART_CFG_SYNCEN_MASK                    (0x800U)
#define USART_CFG_SYNCEN_SHIFT                   (11U)
/*! SYNCEN - Selects synchronous or asynchronous operation.
 *  0b0..Asynchronous mode.
 *  0b1..Synchronous mode.
 */
#define USART_CFG_SYNCEN(x)                      (((uint32_t)(((uint32_t)(x)) << USART_CFG_SYNCEN_SHIFT)) & USART_CFG_SYNCEN_MASK)
#define USART_CFG_CLKPOL_MASK                    (0x1000U)
#define USART_CFG_CLKPOL_SHIFT                   (12U)
/*! CLKPOL - Selects the clock polarity and sampling edge of received data in synchronous mode.
 *  0b0..Falling edge. Un_RXD is sampled on the falling edge of SCLK.
 *  0b1..Rising edge. Un_RXD is sampled on the rising edge of SCLK.
 */
#define USART_CFG_CLKPOL(x)                      (((uint32_t)(((uint32_t)(x)) << USART_CFG_CLKPOL_SHIFT)) & USART_CFG_CLKPOL_MASK)
#define USART_CFG_SYNCMST_MASK                   (0x4000U)
#define USART_CFG_SYNCMST_SHIFT                  (14U)
/*! SYNCMST - Synchronous mode Master select.
 *  0b0..Slave. When synchronous mode is enabled, the USART is a slave.
 *  0b1..Master. When synchronous mode is enabled, the USART is a master.
 */
#define USART_CFG_SYNCMST(x)                     (((uint32_t)(((uint32_t)(x)) << USART_CFG_SYNCMST_SHIFT)) & USART_CFG_SYNCMST_MASK)
#define USART_CFG_LOOP_MASK                      (0x8000U)
#define USART_CFG_LOOP_SHIFT                     (15U)
/*! LOOP - Selects data loopback mode.
 *  0b0..Normal operation.
 *  0b1..Loopback mode. This provides a mechanism to perform diagnostic loopback testing for USART data. Serial
 *       data from the transmitter (Un_TXD) is connected internally to serial input of the receive (Un_RXD). Un_TXD
 *       and Un_RTS activity will also appear on external pins if these functions are configured to appear on device
 *       pins. The receiver RTS signal is also looped back to CTS and performs flow control if enabled by CTSEN.
 */
#define USART_CFG_LOOP(x)                        (((uint32_t)(((uint32_t)(x)) << USART_CFG_LOOP_SHIFT)) & USART_CFG_LOOP_MASK)
#define USART_CFG_OETA_MASK                      (0x40000U)
#define USART_CFG_OETA_SHIFT                     (18U)
/*! OETA - Output Enable Turnaround time enable for RS-485 operation.
 *  0b0..Disabled. If selected by OESEL, the Output Enable signal deasserted at the end of the last stop bit of a transmission.
 *  0b1..Enabled. If selected by OESEL, the Output Enable signal remains asserted for one character time after the
 *       end of the last stop bit of a transmission. OE will also remain asserted if another transmit begins
 *       before it is deasserted.
 */
#define USART_CFG_OETA(x)                        (((uint32_t)(((uint32_t)(x)) << USART_CFG_OETA_SHIFT)) & USART_CFG_OETA_MASK)
#define USART_CFG_AUTOADDR_MASK                  (0x80000U)
#define USART_CFG_AUTOADDR_SHIFT                 (19U)
/*! AUTOADDR - Automatic Address matching enable.
 *  0b0..Disabled. When addressing is enabled by ADDRDET, address matching is done by software. This provides the
 *       possibility of versatile addressing (e.g. respond to more than one address).
 *  0b1..Enabled. When addressing is enabled by ADDRDET, address matching is done by hardware, using the value in
 *       the ADDR register as the address to match.
 */
#define USART_CFG_AUTOADDR(x)                    (((uint32_t)(((uint32_t)(x)) << USART_CFG_AUTOADDR_SHIFT)) & USART_CFG_AUTOADDR_MASK)
#define USART_CFG_OESEL_MASK                     (0x100000U)
#define USART_CFG_OESEL_SHIFT                    (20U)
/*! OESEL - Output Enable Select.
 *  0b0..Standard. The RTS signal is used as the standard flow control function.
 *  0b1..RS-485. The RTS signal configured to provide an output enable signal to control an RS-485 transceiver.
 */
#define USART_CFG_OESEL(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CFG_OESEL_SHIFT)) & USART_CFG_OESEL_MASK)
#define USART_CFG_OEPOL_MASK                     (0x200000U)
#define USART_CFG_OEPOL_SHIFT                    (21U)
/*! OEPOL - Output Enable Polarity.
 *  0b0..Low. If selected by OESEL, the output enable is active low.
 *  0b1..High. If selected by OESEL, the output enable is active high.
 */
#define USART_CFG_OEPOL(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CFG_OEPOL_SHIFT)) & USART_CFG_OEPOL_MASK)
#define USART_CFG_RXPOL_MASK                     (0x400000U)
#define USART_CFG_RXPOL_SHIFT                    (22U)
/*! RXPOL - Receive data polarity.
 *  0b0..Standard. The RX signal is used as it arrives from the pin. This means that the RX rest value is 1, start
 *       bit is 0, data is not inverted, and the stop bit is 1.
 *  0b1..Inverted. The RX signal is inverted before being used by the USART. This means that the RX rest value is
 *       0, start bit is 1, data is inverted, and the stop bit is 0.
 */
#define USART_CFG_RXPOL(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CFG_RXPOL_SHIFT)) & USART_CFG_RXPOL_MASK)
#define USART_CFG_TXPOL_MASK                     (0x800000U)
#define USART_CFG_TXPOL_SHIFT                    (23U)
/*! TXPOL - Transmit data polarity.
 *  0b0..Standard. The TX signal is sent out without change. This means that the TX rest value is 1, start bit is
 *       0, data is not inverted, and the stop bit is 1.
 *  0b1..Inverted. The TX signal is inverted by the USART before being sent out. This means that the TX rest value
 *       is 0, start bit is 1, data is inverted, and the stop bit is 0.
 */
#define USART_CFG_TXPOL(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CFG_TXPOL_SHIFT)) & USART_CFG_TXPOL_MASK)
/*! @} */

/*! @name CTL - USART Control register. USART control settings that are more likely to change during operation. */
/*! @{ */
#define USART_CTL_TXBRKEN_MASK                   (0x2U)
#define USART_CTL_TXBRKEN_SHIFT                  (1U)
/*! TXBRKEN - Break Enable.
 *  0b0..Normal operation.
 *  0b1..Continuous break. Continuous break is sent immediately when this bit is set, and remains until this bit
 *       is cleared. A break may be sent without danger of corrupting any currently transmitting character if the
 *       transmitter is first disabled (TXDIS in CTL is set) and then waiting for the transmitter to be disabled
 *       (TXDISINT in STAT = 1) before writing 1 to TXBRKEN.
 */
#define USART_CTL_TXBRKEN(x)                     (((uint32_t)(((uint32_t)(x)) << USART_CTL_TXBRKEN_SHIFT)) & USART_CTL_TXBRKEN_MASK)
#define USART_CTL_ADDRDET_MASK                   (0x4U)
#define USART_CTL_ADDRDET_SHIFT                  (2U)
/*! ADDRDET - Enable address detect mode.
 *  0b0..Disabled. The USART presents all incoming data.
 *  0b1..Enabled. The USART receiver ignores incoming data that does not have the most significant bit of the data
 *       (typically the 9th bit) = 1. When the data MSB bit = 1, the receiver treats the incoming data normally,
 *       generating a received data interrupt. Software can then check the data to see if this is an address that
 *       should be handled. If it is, the ADDRDET bit is cleared by software and further incoming data is handled
 *       normally.
 */
#define USART_CTL_ADDRDET(x)                     (((uint32_t)(((uint32_t)(x)) << USART_CTL_ADDRDET_SHIFT)) & USART_CTL_ADDRDET_MASK)
#define USART_CTL_TXDIS_MASK                     (0x40U)
#define USART_CTL_TXDIS_SHIFT                    (6U)
/*! TXDIS - Transmit Disable.
 *  0b0..Not disabled. USART transmitter is not disabled.
 *  0b1..Disabled. USART transmitter is disabled after any character currently being transmitted is complete. This
 *       feature can be used to facilitate software flow control.
 */
#define USART_CTL_TXDIS(x)                       (((uint32_t)(((uint32_t)(x)) << USART_CTL_TXDIS_SHIFT)) & USART_CTL_TXDIS_MASK)
#define USART_CTL_CC_MASK                        (0x100U)
#define USART_CTL_CC_SHIFT                       (8U)
/*! CC - Continuous Clock generation. By default, SCLK is only output while data is being transmitted in synchronous mode.
 *  0b0..Clock on character. In synchronous mode, SCLK cycles only when characters are being sent on Un_TXD or to
 *       complete a character that is being received.
 *  0b1..Continuous clock. SCLK runs continuously in synchronous mode, allowing characters to be received on
 *       Un_RxD independently from transmission on Un_TXD).
 */
#define USART_CTL_CC(x)                          (((uint32_t)(((uint32_t)(x)) << USART_CTL_CC_SHIFT)) & USART_CTL_CC_MASK)
#define USART_CTL_CLRCCONRX_MASK                 (0x200U)
#define USART_CTL_CLRCCONRX_SHIFT                (9U)
/*! CLRCCONRX - Clear Continuous Clock.
 *  0b0..No effect. No effect on the CC bit.
 *  0b1..Auto-clear. The CC bit is automatically cleared when a complete character has been received. This bit is cleared at the same time.
 */
#define USART_CTL_CLRCCONRX(x)                   (((uint32_t)(((uint32_t)(x)) << USART_CTL_CLRCCONRX_SHIFT)) & USART_CTL_CLRCCONRX_MASK)
#define USART_CTL_AUTOBAUD_MASK                  (0x10000U)
#define USART_CTL_AUTOBAUD_SHIFT                 (16U)
/*! AUTOBAUD - Autobaud enable.
 *  0b0..Disabled. USART is in normal operating mode.
 *  0b1..Enabled. USART is in autobaud mode. This bit should only be set when the USART receiver is idle. The
 *       first start bit of RX is measured and used the update the BRG register to match the received data rate.
 *       AUTOBAUD is cleared once this process is complete, or if there is an AERR.
 */
#define USART_CTL_AUTOBAUD(x)                    (((uint32_t)(((uint32_t)(x)) << USART_CTL_AUTOBAUD_SHIFT)) & USART_CTL_AUTOBAUD_MASK)
/*! @} */

/*! @name STAT - USART Status register. The complete status value can be read here. Writing ones clears some bits in the register. Some bits can be cleared by writing a 1 to them. */
/*! @{ */
#define USART_STAT_RXRDY_MASK                    (0x1U)
#define USART_STAT_RXRDY_SHIFT                   (0U)
/*! RXRDY - Receiver Ready flag. When 1, indicates that data is available to be read from the
 *    receiver buffer. Cleared after a read of the RXDAT or RXDATSTAT registers.
 */
#define USART_STAT_RXRDY(x)                      (((uint32_t)(((uint32_t)(x)) << USART_STAT_RXRDY_SHIFT)) & USART_STAT_RXRDY_MASK)
#define USART_STAT_RXIDLE_MASK                   (0x2U)
#define USART_STAT_RXIDLE_SHIFT                  (1U)
/*! RXIDLE - Receiver Idle. When 0, indicates that the receiver is currently in the process of
 *    receiving data. When 1, indicates that the receiver is not currently in the process of receiving
 *    data.
 */
#define USART_STAT_RXIDLE(x)                     (((uint32_t)(((uint32_t)(x)) << USART_STAT_RXIDLE_SHIFT)) & USART_STAT_RXIDLE_MASK)
#define USART_STAT_TXRDY_MASK                    (0x4U)
#define USART_STAT_TXRDY_SHIFT                   (2U)
/*! TXRDY - Transmitter Ready flag. When 1, this bit indicates that data may be written to the
 *    transmit buffer. Previous data may still be in the process of being transmitted. Cleared when data
 *    is written to TXDAT. Set when the data is moved from the transmit buffer to the transmit shift
 *    register.
 */
#define USART_STAT_TXRDY(x)                      (((uint32_t)(((uint32_t)(x)) << USART_STAT_TXRDY_SHIFT)) & USART_STAT_TXRDY_MASK)
#define USART_STAT_TXIDLE_MASK                   (0x8U)
#define USART_STAT_TXIDLE_SHIFT                  (3U)
/*! TXIDLE - Transmitter Idle. When 0, indicates that the transmitter is currently in the process of
 *    sending data.When 1, indicate that the transmitter is not currently in the process of sending
 *    data.
 */
#define USART_STAT_TXIDLE(x)                     (((uint32_t)(((uint32_t)(x)) << USART_STAT_TXIDLE_SHIFT)) & USART_STAT_TXIDLE_MASK)
#define USART_STAT_CTS_MASK                      (0x10U)
#define USART_STAT_CTS_SHIFT                     (4U)
/*! CTS - This bit reflects the current state of the CTS signal, regardless of the setting of the
 *    CTSEN bit in the CFG register. This will be the value of the CTS input pin unless loopback mode
 *    is enabled.
 */
#define USART_STAT_CTS(x)                        (((uint32_t)(((uint32_t)(x)) << USART_STAT_CTS_SHIFT)) & USART_STAT_CTS_MASK)
#define USART_STAT_DELTACTS_MASK                 (0x20U)
#define USART_STAT_DELTACTS_SHIFT                (5U)
/*! DELTACTS - This bit is set when a change in the state is detected for the CTS flag above. This bit is cleared by software.
 */
#define USART_STAT_DELTACTS(x)                   (((uint32_t)(((uint32_t)(x)) << USART_STAT_DELTACTS_SHIFT)) & USART_STAT_DELTACTS_MASK)
#define USART_STAT_TXDISSTAT_MASK                (0x40U)
#define USART_STAT_TXDISSTAT_SHIFT               (6U)
/*! TXDISSTAT - Transmitter Disabled Interrupt flag. When 1, this bit indicates that the USART
 *    transmitter is fully idle after being disabled via the TXDIS in the CTL register (TXDIS = 1).
 */
#define USART_STAT_TXDISSTAT(x)                  (((uint32_t)(((uint32_t)(x)) << USART_STAT_TXDISSTAT_SHIFT)) & USART_STAT_TXDISSTAT_MASK)
#define USART_STAT_OVERRUNINT_MASK               (0x100U)
#define USART_STAT_OVERRUNINT_SHIFT              (8U)
/*! OVERRUNINT - Overrun Error interrupt flag. This flag is set when a new character is received
 *    while the receiver buffer is still in use. If this occurs, the newly received character in the
 *    shift register is lost.
 */
#define USART_STAT_OVERRUNINT(x)                 (((uint32_t)(((uint32_t)(x)) << USART_STAT_OVERRUNINT_SHIFT)) & USART_STAT_OVERRUNINT_MASK)
#define USART_STAT_RXBRK_MASK                    (0x400U)
#define USART_STAT_RXBRK_SHIFT                   (10U)
/*! RXBRK - Received Break. This bit reflects the current state of the receiver break detection
 *    logic. It is set when the Un_RXD pin remains low for 16 bit times. Note that FRAMERRINT will also
 *    be set when this condition occurs because the stop bit(s) for the character would be missing.
 *    RXBRK is cleared when the Un_RXD pin goes high.
 */
#define USART_STAT_RXBRK(x)                      (((uint32_t)(((uint32_t)(x)) << USART_STAT_RXBRK_SHIFT)) & USART_STAT_RXBRK_MASK)
#define USART_STAT_DELTARXBRK_MASK               (0x800U)
#define USART_STAT_DELTARXBRK_SHIFT              (11U)
/*! DELTARXBRK - This bit is set when a change in the state of receiver break detection occurs.Cleared by software.
 */
#define USART_STAT_DELTARXBRK(x)                 (((uint32_t)(((uint32_t)(x)) << USART_STAT_DELTARXBRK_SHIFT)) & USART_STAT_DELTARXBRK_MASK)
#define USART_STAT_START_MASK                    (0x1000U)
#define USART_STAT_START_SHIFT                   (12U)
/*! START - This bit is set when a start is detected on the receiver input. Its purpose is primarily
 *    to allow wake-up from Deep-sleep or Power-down mode immediately when a start is detected.
 *    Cleared by software.
 */
#define USART_STAT_START(x)                      (((uint32_t)(((uint32_t)(x)) << USART_STAT_START_SHIFT)) & USART_STAT_START_MASK)
#define USART_STAT_FRAMERRINT_MASK               (0x2000U)
#define USART_STAT_FRAMERRINT_SHIFT              (13U)
/*! FRAMERRINT - Framing Error interrupt flag. This flag is set when a character is received with a
 *    missing stop bit at the expected location. This could be an indication of a baud rate or
 *    configuration mismatch with the transmitting source.
 */
#define USART_STAT_FRAMERRINT(x)                 (((uint32_t)(((uint32_t)(x)) << USART_STAT_FRAMERRINT_SHIFT)) & USART_STAT_FRAMERRINT_MASK)
#define USART_STAT_PARITYERRINT_MASK             (0x4000U)
#define USART_STAT_PARITYERRINT_SHIFT            (14U)
/*! PARITYERRINT - Parity Error interrupt flag. This flag is set when a parity error is detected in a received character.
 */
#define USART_STAT_PARITYERRINT(x)               (((uint32_t)(((uint32_t)(x)) << USART_STAT_PARITYERRINT_SHIFT)) & USART_STAT_PARITYERRINT_MASK)
#define USART_STAT_RXNOISEINT_MASK               (0x8000U)
#define USART_STAT_RXNOISEINT_SHIFT              (15U)
/*! RXNOISEINT - Received Noise interrupt flag. Three samples of received data are taken in order to
 *    determine the value of each received data bit, except in synchronous mode. This acts as a
 *    noise filter if one sample disagrees. This flag is set when a received data bit contains one
 *    disagreeing sample. This could indicate line noise, a baud rate or character format mismatch, or
 *    loss of synchronization during data reception.
 */
#define USART_STAT_RXNOISEINT(x)                 (((uint32_t)(((uint32_t)(x)) << USART_STAT_RXNOISEINT_SHIFT)) & USART_STAT_RXNOISEINT_MASK)
#define USART_STAT_ABERR_MASK                    (0x10000U)
#define USART_STAT_ABERR_SHIFT                   (16U)
/*! ABERR - Autobaud Error. An autobaud error can occur if the BRG counts to its limit before the
 *    end of the start bit that is being measured, essentially an autobaud time-out.
 */
#define USART_STAT_ABERR(x)                      (((uint32_t)(((uint32_t)(x)) << USART_STAT_ABERR_SHIFT)) & USART_STAT_ABERR_MASK)
/*! @} */

/*! @name INTENSET - Interrupt Enable read and Set register. Contains an individual interrupt enable bit for each potential USART interrupt. A complete value may be read from this register. Writing a 1 to any implemented bit position causes that bit to be set. */
/*! @{ */
#define USART_INTENSET_RXRDYEN_MASK              (0x1U)
#define USART_INTENSET_RXRDYEN_SHIFT             (0U)
/*! RXRDYEN - When 1, enables an interrupt when there is a received character available to be read from the RXDAT register.
 */
#define USART_INTENSET_RXRDYEN(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_RXRDYEN_SHIFT)) & USART_INTENSET_RXRDYEN_MASK)
#define USART_INTENSET_TXRDYEN_MASK              (0x4U)
#define USART_INTENSET_TXRDYEN_SHIFT             (2U)
/*! TXRDYEN - When 1, enables an interrupt when the TXDAT register is available to take another character to transmit.
 */
#define USART_INTENSET_TXRDYEN(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_TXRDYEN_SHIFT)) & USART_INTENSET_TXRDYEN_MASK)
#define USART_INTENSET_TXIDLEEN_MASK             (0x8U)
#define USART_INTENSET_TXIDLEEN_SHIFT            (3U)
/*! TXIDLEEN - When 1, enables an interrupt when the transmitter becomes idle (TXIDLE = 1).
 */
#define USART_INTENSET_TXIDLEEN(x)               (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_TXIDLEEN_SHIFT)) & USART_INTENSET_TXIDLEEN_MASK)
#define USART_INTENSET_DELTACTSEN_MASK           (0x20U)
#define USART_INTENSET_DELTACTSEN_SHIFT          (5U)
/*! DELTACTSEN - When 1, enables an interrupt when there is a change in the state of the CTS input.
 */
#define USART_INTENSET_DELTACTSEN(x)             (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_DELTACTSEN_SHIFT)) & USART_INTENSET_DELTACTSEN_MASK)
#define USART_INTENSET_TXDISEN_MASK              (0x40U)
#define USART_INTENSET_TXDISEN_SHIFT             (6U)
/*! TXDISEN - When 1, enables an interrupt when the transmitter is fully disabled as indicated by
 *    the TXDISINT flag in STAT. See description of the TXDISINT bit for details.
 */
#define USART_INTENSET_TXDISEN(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_TXDISEN_SHIFT)) & USART_INTENSET_TXDISEN_MASK)
#define USART_INTENSET_OVERRUNEN_MASK            (0x100U)
#define USART_INTENSET_OVERRUNEN_SHIFT           (8U)
/*! OVERRUNEN - When 1, enables an interrupt when an overrun error occurred.
 */
#define USART_INTENSET_OVERRUNEN(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_OVERRUNEN_SHIFT)) & USART_INTENSET_OVERRUNEN_MASK)
#define USART_INTENSET_DELTARXBRKEN_MASK         (0x800U)
#define USART_INTENSET_DELTARXBRKEN_SHIFT        (11U)
/*! DELTARXBRKEN - When 1, enables an interrupt when a change of state has occurred in the detection
 *    of a received break condition (break condition asserted or deasserted).
 */
#define USART_INTENSET_DELTARXBRKEN(x)           (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_DELTARXBRKEN_SHIFT)) & USART_INTENSET_DELTARXBRKEN_MASK)
#define USART_INTENSET_STARTEN_MASK              (0x1000U)
#define USART_INTENSET_STARTEN_SHIFT             (12U)
/*! STARTEN - When 1, enables an interrupt when a received start bit has been detected.
 */
#define USART_INTENSET_STARTEN(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_STARTEN_SHIFT)) & USART_INTENSET_STARTEN_MASK)
#define USART_INTENSET_FRAMERREN_MASK            (0x2000U)
#define USART_INTENSET_FRAMERREN_SHIFT           (13U)
/*! FRAMERREN - When 1, enables an interrupt when a framing error has been detected.
 */
#define USART_INTENSET_FRAMERREN(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_FRAMERREN_SHIFT)) & USART_INTENSET_FRAMERREN_MASK)
#define USART_INTENSET_PARITYERREN_MASK          (0x4000U)
#define USART_INTENSET_PARITYERREN_SHIFT         (14U)
/*! PARITYERREN - When 1, enables an interrupt when a parity error has been detected.
 */
#define USART_INTENSET_PARITYERREN(x)            (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_PARITYERREN_SHIFT)) & USART_INTENSET_PARITYERREN_MASK)
#define USART_INTENSET_RXNOISEEN_MASK            (0x8000U)
#define USART_INTENSET_RXNOISEEN_SHIFT           (15U)
/*! RXNOISEEN - When 1, enables an interrupt when noise is detected.
 */
#define USART_INTENSET_RXNOISEEN(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_RXNOISEEN_SHIFT)) & USART_INTENSET_RXNOISEEN_MASK)
#define USART_INTENSET_ABERREN_MASK              (0x10000U)
#define USART_INTENSET_ABERREN_SHIFT             (16U)
/*! ABERREN - When 1, enables an interrupt when an autobaud error occurs.
 */
#define USART_INTENSET_ABERREN(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTENSET_ABERREN_SHIFT)) & USART_INTENSET_ABERREN_MASK)
/*! @} */

/*! @name INTENCLR - Interrupt Enable Clear register. Allows clearing any combination of bits in the INTENSET register. Writing a 1 to any implemented bit position causes the corresponding bit to be cleared. */
/*! @{ */
#define USART_INTENCLR_RXRDYCLR_MASK             (0x1U)
#define USART_INTENCLR_RXRDYCLR_SHIFT            (0U)
/*! RXRDYCLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_RXRDYCLR(x)               (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_RXRDYCLR_SHIFT)) & USART_INTENCLR_RXRDYCLR_MASK)
#define USART_INTENCLR_TXRDYCLR_MASK             (0x4U)
#define USART_INTENCLR_TXRDYCLR_SHIFT            (2U)
/*! TXRDYCLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_TXRDYCLR(x)               (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_TXRDYCLR_SHIFT)) & USART_INTENCLR_TXRDYCLR_MASK)
#define USART_INTENCLR_TXIDLECLR_MASK            (0x8U)
#define USART_INTENCLR_TXIDLECLR_SHIFT           (3U)
/*! TXIDLECLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_TXIDLECLR(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_TXIDLECLR_SHIFT)) & USART_INTENCLR_TXIDLECLR_MASK)
#define USART_INTENCLR_DELTACTSCLR_MASK          (0x20U)
#define USART_INTENCLR_DELTACTSCLR_SHIFT         (5U)
/*! DELTACTSCLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_DELTACTSCLR(x)            (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_DELTACTSCLR_SHIFT)) & USART_INTENCLR_DELTACTSCLR_MASK)
#define USART_INTENCLR_TXDISINTCLR_MASK          (0x40U)
#define USART_INTENCLR_TXDISINTCLR_SHIFT         (6U)
/*! TXDISINTCLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_TXDISINTCLR(x)            (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_TXDISINTCLR_SHIFT)) & USART_INTENCLR_TXDISINTCLR_MASK)
#define USART_INTENCLR_OVERRUNCLR_MASK           (0x100U)
#define USART_INTENCLR_OVERRUNCLR_SHIFT          (8U)
/*! OVERRUNCLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_OVERRUNCLR(x)             (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_OVERRUNCLR_SHIFT)) & USART_INTENCLR_OVERRUNCLR_MASK)
#define USART_INTENCLR_DELTARXBRKCLR_MASK        (0x800U)
#define USART_INTENCLR_DELTARXBRKCLR_SHIFT       (11U)
/*! DELTARXBRKCLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_DELTARXBRKCLR(x)          (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_DELTARXBRKCLR_SHIFT)) & USART_INTENCLR_DELTARXBRKCLR_MASK)
#define USART_INTENCLR_STARTCLR_MASK             (0x1000U)
#define USART_INTENCLR_STARTCLR_SHIFT            (12U)
/*! STARTCLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_STARTCLR(x)               (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_STARTCLR_SHIFT)) & USART_INTENCLR_STARTCLR_MASK)
#define USART_INTENCLR_FRAMERRCLR_MASK           (0x2000U)
#define USART_INTENCLR_FRAMERRCLR_SHIFT          (13U)
/*! FRAMERRCLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_FRAMERRCLR(x)             (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_FRAMERRCLR_SHIFT)) & USART_INTENCLR_FRAMERRCLR_MASK)
#define USART_INTENCLR_PARITYERRCLR_MASK         (0x4000U)
#define USART_INTENCLR_PARITYERRCLR_SHIFT        (14U)
/*! PARITYERRCLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_PARITYERRCLR(x)           (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_PARITYERRCLR_SHIFT)) & USART_INTENCLR_PARITYERRCLR_MASK)
#define USART_INTENCLR_RXNOISECLR_MASK           (0x8000U)
#define USART_INTENCLR_RXNOISECLR_SHIFT          (15U)
/*! RXNOISECLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_RXNOISECLR(x)             (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_RXNOISECLR_SHIFT)) & USART_INTENCLR_RXNOISECLR_MASK)
#define USART_INTENCLR_ABERRCLR_MASK             (0x10000U)
#define USART_INTENCLR_ABERRCLR_SHIFT            (16U)
/*! ABERRCLR - Writing 1 clears the corresponding bit in the INTENSET register.
 */
#define USART_INTENCLR_ABERRCLR(x)               (((uint32_t)(((uint32_t)(x)) << USART_INTENCLR_ABERRCLR_SHIFT)) & USART_INTENCLR_ABERRCLR_MASK)
/*! @} */

/*! @name RXDAT - Receiver Data register. Contains the last character received. */
/*! @{ */
#define USART_RXDAT_RXDAT_MASK                   (0x1FFU)
#define USART_RXDAT_RXDAT_SHIFT                  (0U)
/*! RXDAT - The USART Receiver Data register contains the next received character. The number of
 *    bits that are relevant depends on the USART configuration settings.
 */
#define USART_RXDAT_RXDAT(x)                     (((uint32_t)(((uint32_t)(x)) << USART_RXDAT_RXDAT_SHIFT)) & USART_RXDAT_RXDAT_MASK)
/*! @} */

/*! @name RXDATSTAT - Receiver Data with Status register. Combines the last character received with the current USART receive status. Allows DMA or software to recover incoming data and status together. */
/*! @{ */
#define USART_RXDATSTAT_RXDAT_MASK               (0x1FFU)
#define USART_RXDATSTAT_RXDAT_SHIFT              (0U)
/*! RXDAT - The USART Receiver Data register contains the next received character. The number of
 *    bits that are relevant depends on the USART configuration settings.
 */
#define USART_RXDATSTAT_RXDAT(x)                 (((uint32_t)(((uint32_t)(x)) << USART_RXDATSTAT_RXDAT_SHIFT)) & USART_RXDATSTAT_RXDAT_MASK)
#define USART_RXDATSTAT_FRAMERR_MASK             (0x2000U)
#define USART_RXDATSTAT_FRAMERR_SHIFT            (13U)
/*! FRAMERR - Framing Error status flag. This bit is valid when there is a character to be read in
 *    the RXDAT register and reflects the status of that character. This bit will set when the
 *    character in RXDAT was received with a missing stop bit at the expected location. This could be an
 *    indication of a baud rate or configuration mismatch with the transmitting source.
 */
#define USART_RXDATSTAT_FRAMERR(x)               (((uint32_t)(((uint32_t)(x)) << USART_RXDATSTAT_FRAMERR_SHIFT)) & USART_RXDATSTAT_FRAMERR_MASK)
#define USART_RXDATSTAT_PARITYERR_MASK           (0x4000U)
#define USART_RXDATSTAT_PARITYERR_SHIFT          (14U)
/*! PARITYERR - Parity Error status flag. This bit is valid when there is a character to be read in
 *    the RXDAT register and reflects the status of that character. This bit will be set when a
 *    parity error is detected in a received character.
 */
#define USART_RXDATSTAT_PARITYERR(x)             (((uint32_t)(((uint32_t)(x)) << USART_RXDATSTAT_PARITYERR_SHIFT)) & USART_RXDATSTAT_PARITYERR_MASK)
#define USART_RXDATSTAT_RXNOISE_MASK             (0x8000U)
#define USART_RXDATSTAT_RXNOISE_SHIFT            (15U)
/*! RXNOISE - Received Noise flag.
 */
#define USART_RXDATSTAT_RXNOISE(x)               (((uint32_t)(((uint32_t)(x)) << USART_RXDATSTAT_RXNOISE_SHIFT)) & USART_RXDATSTAT_RXNOISE_MASK)
/*! @} */

/*! @name TXDAT - Transmit Data register. Data to be transmitted is written here. */
/*! @{ */
#define USART_TXDAT_TXDAT_MASK                   (0x1FFU)
#define USART_TXDAT_TXDAT_SHIFT                  (0U)
/*! TXDAT - Writing to the USART Transmit Data Register causes the data to be transmitted as soon as
 *    the transmit shift register is available and any conditions for transmitting data are met:
 *    CTS low (if CTSEN bit = 1), TXDIS bit = 0.
 */
#define USART_TXDAT_TXDAT(x)                     (((uint32_t)(((uint32_t)(x)) << USART_TXDAT_TXDAT_SHIFT)) & USART_TXDAT_TXDAT_MASK)
/*! @} */

/*! @name BRG - Baud Rate Generator register. 16-bit integer baud rate divisor value. */
/*! @{ */
#define USART_BRG_BRGVAL_MASK                    (0xFFFFU)
#define USART_BRG_BRGVAL_SHIFT                   (0U)
/*! BRGVAL - This value is used to divide the USART input clock to determine the baud rate, based on
 *    the input clock from the FRG. 0 = FCLK is used directly by the USART function. 1 = FCLK is
 *    divided by 2 before use by the USART function. 2 = FCLK is divided by 3 before use by the USART
 *    function. 0xFFFF = FCLK is divided by 65,536 before use by the USART function.
 */
#define USART_BRG_BRGVAL(x)                      (((uint32_t)(((uint32_t)(x)) << USART_BRG_BRGVAL_SHIFT)) & USART_BRG_BRGVAL_MASK)
/*! @} */

/*! @name INTSTAT - Interrupt status register. Reflects interrupts that are currently enabled. */
/*! @{ */
#define USART_INTSTAT_RXRDY_MASK                 (0x1U)
#define USART_INTSTAT_RXRDY_SHIFT                (0U)
/*! RXRDY - Receiver Ready flag.
 */
#define USART_INTSTAT_RXRDY(x)                   (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_RXRDY_SHIFT)) & USART_INTSTAT_RXRDY_MASK)
#define USART_INTSTAT_TXRDY_MASK                 (0x4U)
#define USART_INTSTAT_TXRDY_SHIFT                (2U)
/*! TXRDY - Transmitter Ready flag.
 */
#define USART_INTSTAT_TXRDY(x)                   (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_TXRDY_SHIFT)) & USART_INTSTAT_TXRDY_MASK)
#define USART_INTSTAT_TXIDLE_MASK                (0x8U)
#define USART_INTSTAT_TXIDLE_SHIFT               (3U)
/*! TXIDLE - Transmitter idle status.
 */
#define USART_INTSTAT_TXIDLE(x)                  (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_TXIDLE_SHIFT)) & USART_INTSTAT_TXIDLE_MASK)
#define USART_INTSTAT_DELTACTS_MASK              (0x20U)
#define USART_INTSTAT_DELTACTS_SHIFT             (5U)
/*! DELTACTS - This bit is set when a change in the state of the CTS input is detected.
 */
#define USART_INTSTAT_DELTACTS(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_DELTACTS_SHIFT)) & USART_INTSTAT_DELTACTS_MASK)
#define USART_INTSTAT_TXDISINT_MASK              (0x40U)
#define USART_INTSTAT_TXDISINT_SHIFT             (6U)
/*! TXDISINT - Transmitter Disabled Interrupt flag.
 */
#define USART_INTSTAT_TXDISINT(x)                (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_TXDISINT_SHIFT)) & USART_INTSTAT_TXDISINT_MASK)
#define USART_INTSTAT_OVERRUNINT_MASK            (0x100U)
#define USART_INTSTAT_OVERRUNINT_SHIFT           (8U)
/*! OVERRUNINT - Overrun Error interrupt flag.
 */
#define USART_INTSTAT_OVERRUNINT(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_OVERRUNINT_SHIFT)) & USART_INTSTAT_OVERRUNINT_MASK)
#define USART_INTSTAT_DELTARXBRK_MASK            (0x800U)
#define USART_INTSTAT_DELTARXBRK_SHIFT           (11U)
/*! DELTARXBRK - This bit is set when a change in the state of receiver break detection occurs.
 */
#define USART_INTSTAT_DELTARXBRK(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_DELTARXBRK_SHIFT)) & USART_INTSTAT_DELTARXBRK_MASK)
#define USART_INTSTAT_START_MASK                 (0x1000U)
#define USART_INTSTAT_START_SHIFT                (12U)
/*! START - This bit is set when a start is detected on the receiver input.
 */
#define USART_INTSTAT_START(x)                   (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_START_SHIFT)) & USART_INTSTAT_START_MASK)
#define USART_INTSTAT_FRAMERRINT_MASK            (0x2000U)
#define USART_INTSTAT_FRAMERRINT_SHIFT           (13U)
/*! FRAMERRINT - Framing Error interrupt flag.
 */
#define USART_INTSTAT_FRAMERRINT(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_FRAMERRINT_SHIFT)) & USART_INTSTAT_FRAMERRINT_MASK)
#define USART_INTSTAT_PARITYERRINT_MASK          (0x4000U)
#define USART_INTSTAT_PARITYERRINT_SHIFT         (14U)
/*! PARITYERRINT - Parity Error interrupt flag.
 */
#define USART_INTSTAT_PARITYERRINT(x)            (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_PARITYERRINT_SHIFT)) & USART_INTSTAT_PARITYERRINT_MASK)
#define USART_INTSTAT_RXNOISEINT_MASK            (0x8000U)
#define USART_INTSTAT_RXNOISEINT_SHIFT           (15U)
/*! RXNOISEINT - Received Noise interrupt flag.
 */
#define USART_INTSTAT_RXNOISEINT(x)              (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_RXNOISEINT_SHIFT)) & USART_INTSTAT_RXNOISEINT_MASK)
#define USART_INTSTAT_ABERR_MASK                 (0x10000U)
#define USART_INTSTAT_ABERR_SHIFT                (16U)
/*! ABERR - Autobaud Error flag.
 */
#define USART_INTSTAT_ABERR(x)                   (((uint32_t)(((uint32_t)(x)) << USART_INTSTAT_ABERR_SHIFT)) & USART_INTSTAT_ABERR_MASK)
/*! @} */

/*! @name OSR - Oversample selection register for asynchronous communication. */
/*! @{ */
#define USART_OSR_OSRVAL_MASK                    (0xFU)
#define USART_OSR_OSRVAL_SHIFT                   (0U)
/*! OSRVAL - Oversample Selection Value. 0 to 3 = not supported 0x4 = 5 function clocks are used to
 *    transmit and receive each data bit. 0x5 = 6 function clocks are used to transmit and receive
 *    each data bit. 0xF= 16 function clocks are used to transmit and receive each data bit.
 */
#define USART_OSR_OSRVAL(x)                      (((uint32_t)(((uint32_t)(x)) << USART_OSR_OSRVAL_SHIFT)) & USART_OSR_OSRVAL_MASK)
/*! @} */

/*! @name ADDR - Address register for automatic address matching. */
/*! @{ */
#define USART_ADDR_ADDRESS_MASK                  (0xFFU)
#define USART_ADDR_ADDRESS_SHIFT                 (0U)
/*! ADDRESS - 8-bit address used with automatic address matching. Used when address detection is
 *    enabled (ADDRDET in CTL = 1) and automatic address matching is enabled (AUTOADDR in CFG = 1).
 */
#define USART_ADDR_ADDRESS(x)                    (((uint32_t)(((uint32_t)(x)) << USART_ADDR_ADDRESS_SHIFT)) & USART_ADDR_ADDRESS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USART_Register_Masks */


/* USART - Peripheral instance base addresses */
/** Peripheral USART0 base address */
#define USART0_BASE                              (0x40064000u)
/** Peripheral USART0 base pointer */
#define USART0                                   ((USART_Type *)USART0_BASE)
/** Peripheral USART1 base address */
#define USART1_BASE                              (0x40068000u)
/** Peripheral USART1 base pointer */
#define USART1                                   ((USART_Type *)USART1_BASE)
/** Peripheral USART2 base address */
#define USART2_BASE                              (0x4006C000u)
/** Peripheral USART2 base pointer */
#define USART2                                   ((USART_Type *)USART2_BASE)
/** Peripheral USART3 base address */
#define USART3_BASE                              (0x40070000u)
/** Peripheral USART3 base pointer */
#define USART3                                   ((USART_Type *)USART3_BASE)
/** Peripheral USART4 base address */
#define USART4_BASE                              (0x40074000u)
/** Peripheral USART4 base pointer */
#define USART4                                   ((USART_Type *)USART4_BASE)
/** Array initializer of USART peripheral base addresses */
#define USART_BASE_ADDRS                         { USART0_BASE, USART1_BASE, USART2_BASE, USART3_BASE, USART4_BASE }
/** Array initializer of USART peripheral base pointers */
#define USART_BASE_PTRS                          { USART0, USART1, USART2, USART3, USART4 }
/** Interrupt vectors for the USART peripheral type */
#define USART_IRQS                               { USART0_IRQn, USART1_IRQn, USART2_IRQn, PIN_INT6_USART3_IRQn, PIN_INT7_USART4_IRQn }

/*!
 * @}
 */ /* end of group USART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< ADC Control register. Contains the clock divide value, resolution selection, sampling time selection, and mode controls., offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t SEQ_CTRL[2];                       /**< ADC Conversion Sequence-n control register: Controls triggering and channel selection for conversion sequence-n. Also specifies interrupt mode for sequence-n., array offset: 0x8, array step: 0x4 */
  __I  uint32_t SEQ_GDAT[2];                       /**< ADC Sequence-n Global Data register. This register contains the result of the most recent ADC conversion performed under sequence-n., array offset: 0x10, array step: 0x4 */
       uint8_t RESERVED_1[8];
  __I  uint32_t DAT[12];                           /**< ADC Channel N Data register. This register contains the result of the most recent conversion completed on channel N., array offset: 0x20, array step: 0x4 */
  __IO uint32_t THR0_LOW;                          /**< ADC Low Compare Threshold register 0: Contains the lower threshold level for automatic threshold comparison for any channels linked to threshold pair 0., offset: 0x50 */
  __IO uint32_t THR1_LOW;                          /**< ADC Low Compare Threshold register 1: Contains the lower threshold level for automatic threshold comparison for any channels linked to threshold pair 1., offset: 0x54 */
  __IO uint32_t THR0_HIGH;                         /**< ADC High Compare Threshold register 0: Contains the upper threshold level for automatic threshold comparison for any channels linked to threshold pair 0., offset: 0x58 */
  __IO uint32_t THR1_HIGH;                         /**< ADC High Compare Threshold register 1: Contains the upper threshold level for automatic threshold comparison for any channels linked to threshold pair 1., offset: 0x5C */
  __IO uint32_t CHAN_THRSEL;                       /**< ADC Channel-Threshold Select register. Specifies which set of threshold compare registers are to be used for each channel, offset: 0x60 */
  __IO uint32_t INTEN;                             /**< ADC Interrupt Enable register. This register contains enable bits that enable the sequence-A, sequence-B, threshold compare and data overrun interrupts to be generated., offset: 0x64 */
  __IO uint32_t FLAGS;                             /**< ADC Flags register. Contains the four interrupt/DMA trigger flags and the individual component overrun and threshold-compare flags. (The overrun bits replicate information stored in the result registers)., offset: 0x68 */
  __IO uint32_t TRM;                               /**< ADC Startup register., offset: 0x6C */
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name CTRL - ADC Control register. Contains the clock divide value, resolution selection, sampling time selection, and mode controls. */
/*! @{ */
#define ADC_CTRL_CLKDIV_MASK                     (0xFFU)
#define ADC_CTRL_CLKDIV_SHIFT                    (0U)
/*! CLKDIV - In synchronous mode only, the system clock is divided by this value plus one to produce
 *    the clock for the ADC converter, which should be less than or equal to 72 MHz. Typically,
 *    software should program the smallest value in this field that yields this maximum clock rate or
 *    slightly less, but in certain cases (such as a high-impedance analog source) a slower clock may
 *    be desirable. This field is ignored in the asynchronous operating mode.
 */
#define ADC_CTRL_CLKDIV(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_CLKDIV_SHIFT)) & ADC_CTRL_CLKDIV_MASK)
#define ADC_CTRL_ASYNMODE_MASK                   (0x100U)
#define ADC_CTRL_ASYNMODE_SHIFT                  (8U)
/*! ASYNMODE - Select clock mode.
 *  0b0..Synchronous mode. The ADC clock is derived from the system clock based on the divide value selected in
 *       the CLKDIV field. The ADC clock will be started in a controlled fashion in response to a trigger to
 *       eliminate any uncertainty in the launching of an ADC conversion in response to any synchronous (on-chip) trigger.
 *       In Synchronous mode with the SYNCBYPASS bit (in a sequence control register) set, sampling of the ADC
 *       input and start of conversion will initiate 2 system clocks after the leading edge of a (synchronous) trigger
 *       pulse.
 *  0b1..Asynchronous mode. The ADC clock is based on the output of the ADC clock divider ADCCLKSEL in the SYSCON block.
 */
#define ADC_CTRL_ASYNMODE(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_ASYNMODE_SHIFT)) & ADC_CTRL_ASYNMODE_MASK)
#define ADC_CTRL_LPWRMODE_MASK                   (0x400U)
#define ADC_CTRL_LPWRMODE_SHIFT                  (10U)
/*! LPWRMODE - The low-power ADC mode
 *  0b0..The low-power ADC mode is disabled. The analog circuitry remains activated even when no conversions are requested.
 *  0b1..The low-power ADC mode is enabled. The analog circuitry is automatically powered-down when no conversions
 *       are taking place. When any (hardware or software) triggering event is detected, the analog circuitry is
 *       enabled. After the required start-up time, the requested conversion will be launched. Once the conversion
 *       completes, the analog-circuitry will again be powered-down provided no further conversions are pending.
 *       Using this mode can save an appreciable amount of current (approximately 2.5 mA) when conversions are
 *       required relatively infrequently. The penalty for using this mode is an approximately FIFTEEN ADC CLOCK delay (30
 *       clocks in 10-bit mode), based on the frequency specified in the CLKDIV field, from the time the trigger
 *       event occurs until sampling of the A/D input commences. Note: This mode will NOT power-up the A/D if the
 *       ADC_ENA bit is low.
 */
#define ADC_CTRL_LPWRMODE(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_LPWRMODE_SHIFT)) & ADC_CTRL_LPWRMODE_MASK)
#define ADC_CTRL_CALMODE_MASK                    (0x40000000U)
#define ADC_CTRL_CALMODE_SHIFT                   (30U)
/*! CALMODE - Writing a '1' to this bit will initiate a sef-calibration cycle. This bit will be
 *    automatically cleared by hardware after the calibration cycle is complete. Note: Other bits of
 *    this register may be written to concurrently with setting this bit, however once this bit has
 *    been set no further writes to this register are permitted unitl the full calibration cycle has
 *    ended.
 */
#define ADC_CTRL_CALMODE(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_CTRL_CALMODE_SHIFT)) & ADC_CTRL_CALMODE_MASK)
/*! @} */

/*! @name SEQ_CTRL - ADC Conversion Sequence-n control register: Controls triggering and channel selection for conversion sequence-n. Also specifies interrupt mode for sequence-n. */
/*! @{ */
#define ADC_SEQ_CTRL_CHANNELS_MASK               (0xFFFU)
#define ADC_SEQ_CTRL_CHANNELS_SHIFT              (0U)
/*! CHANNELS - Selects which one or more of the ADC channels will be sampled and converted when this
 *    sequence is launched. A 1 in any bit of this field will cause the corresponding channel to be
 *    included in the conversion sequence, where bit 0 corresponds to channel 0, bit 1 to channel 1
 *    and so forth. When this conversion sequence is triggered, either by a hardware trigger or via
 *    software command, ADC conversions will be performed on each enabled channel, in sequence,
 *    beginning with the lowest-ordered channel. This field can ONLY be changed while SEQA_ENA (bit 31)
 *    is LOW. It is allowed to change this field and set bit 31 in the same write.
 */
#define ADC_SEQ_CTRL_CHANNELS(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_CHANNELS_SHIFT)) & ADC_SEQ_CTRL_CHANNELS_MASK)
#define ADC_SEQ_CTRL_TRIGGER_MASK                (0x7000U)
#define ADC_SEQ_CTRL_TRIGGER_SHIFT               (12U)
/*! TRIGGER - Selects which of the available hardware trigger sources will cause this conversion
 *    sequence to be initiated. Program the trigger input number in this field. See Table 476. In order
 *    to avoid generating a spurious trigger, it is recommended writing to this field only when
 *    SEQA_ENA (bit 31) is low. It is safe to change this field and set bit 31 in the same write.
 */
#define ADC_SEQ_CTRL_TRIGGER(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_TRIGGER_SHIFT)) & ADC_SEQ_CTRL_TRIGGER_MASK)
#define ADC_SEQ_CTRL_TRIGPOL_MASK                (0x40000U)
#define ADC_SEQ_CTRL_TRIGPOL_SHIFT               (18U)
/*! TRIGPOL - Select the polarity of the selected input trigger for this conversion sequence. In
 *    order to avoid generating a spurious trigger, it is recommended writing to this field only when
 *    SEQA_ENA (bit 31) is low. It is safe to change this field and set bit 31 in the same write.
 *  0b0..Negative edge. A negative edge launches the conversion sequence on the selected trigger input.
 *  0b1..Positive edge. A positive edge launches the conversion sequence on the selected trigger input.
 */
#define ADC_SEQ_CTRL_TRIGPOL(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_TRIGPOL_SHIFT)) & ADC_SEQ_CTRL_TRIGPOL_MASK)
#define ADC_SEQ_CTRL_SYNCBYPASS_MASK             (0x80000U)
#define ADC_SEQ_CTRL_SYNCBYPASS_SHIFT            (19U)
/*! SYNCBYPASS - Setting this bit allows the hardware trigger input to bypass synchronization
 *    flip-flop stages and therefore shorten the time between the trigger input signal and the start of a
 *    conversion. There are slightly different criteria for whether or not this bit can be set
 *    depending on the clock operating mode: Synchronous mode (the ASYNMODE in the CTRL register = 0):
 *    Synchronization may be bypassed (this bit may be set) if the selected trigger source is already
 *    synchronous with the main system clock (eg. coming from an on-chip, system-clock-based timer).
 *    Whether this bit is set or not, a trigger pulse must be maintained for at least one system
 *    clock period. Asynchronous mode (the ASYNMODE in the CTRL register = 1): Synchronization may be
 *    bypassed (this bit may be set) if it is certain that the duration of a trigger input pulse
 *    will be at least one cycle of the ADC clock (regardless of whether the trigger comes from and
 *    on-chip or off-chip source). If this bit is NOT set, the trigger pulse must at least be
 *    maintained for one system clock period.
 *  0b0..Enable trigger synchronization. The hardware trigger bypass is not enabled.
 *  0b1..Bypass trigger synchronization. The hardware trigger bypass is enabled.
 */
#define ADC_SEQ_CTRL_SYNCBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_SYNCBYPASS_SHIFT)) & ADC_SEQ_CTRL_SYNCBYPASS_MASK)
#define ADC_SEQ_CTRL_START_MASK                  (0x4000000U)
#define ADC_SEQ_CTRL_START_SHIFT                 (26U)
/*! START - Writing a 1 to this field will launch one pass through this conversion sequence. The
 *    behavior will be identical to a sequence triggered by a hardware trigger. Do not write 1 to this
 *    bit if the BURST bit is set. This bit is only set to a 1 momentarily when written to launch a
 *    conversion sequence. It will consequently always read back as a zero.
 */
#define ADC_SEQ_CTRL_START(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_START_SHIFT)) & ADC_SEQ_CTRL_START_MASK)
#define ADC_SEQ_CTRL_BURST_MASK                  (0x8000000U)
#define ADC_SEQ_CTRL_BURST_SHIFT                 (27U)
/*! BURST - Writing a 1 to this bit will cause this conversion sequence to be continuously cycled
 *    through. Other sequence A triggers will be ignored while this bit is set. Repeated conversions
 *    can be halted by clearing this bit. The sequence currently in progress will be completed before
 *    conversions are terminated. Note that a new sequence could begin just before BURST is cleared.
 */
#define ADC_SEQ_CTRL_BURST(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_BURST_SHIFT)) & ADC_SEQ_CTRL_BURST_MASK)
#define ADC_SEQ_CTRL_SINGLESTEP_MASK             (0x10000000U)
#define ADC_SEQ_CTRL_SINGLESTEP_SHIFT            (28U)
/*! SINGLESTEP - When this bit is set, a hardware trigger or a write to the START bit will launch a
 *    single conversion on the next channel in the sequence instead of the default response of
 *    launching an entire sequence of conversions. Once all of the channels comprising a sequence have
 *    been converted, a subsequent trigger will repeat the sequence beginning with the first enabled
 *    channel. Interrupt generation will still occur either after each individual conversion or at
 *    the end of the entire sequence, depending on the state of the MODE bit.
 */
#define ADC_SEQ_CTRL_SINGLESTEP(x)               (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_SINGLESTEP_SHIFT)) & ADC_SEQ_CTRL_SINGLESTEP_MASK)
#define ADC_SEQ_CTRL_LOWPRIO_MASK                (0x20000000U)
#define ADC_SEQ_CTRL_LOWPRIO_SHIFT               (29U)
/*! LOWPRIO - Set priority for sequence A.
 *  0b0..Low priority. Any B trigger which occurs while an A conversion sequence is active will be ignored and lost.
 *  0b1..High priority. Setting this bit to a 1 will permit any enabled B sequence trigger (including a B sequence
 *       software start) to immediately interrupt sequence A and launch a B sequence in it's place. The conversion
 *       currently in progress will be terminated. The A sequence that was interrupted will automatically resume
 *       after the B sequence completes. The channel whose conversion was terminated will be re-sampled and the
 *       conversion sequence will resume from that point.
 */
#define ADC_SEQ_CTRL_LOWPRIO(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_LOWPRIO_SHIFT)) & ADC_SEQ_CTRL_LOWPRIO_MASK)
#define ADC_SEQ_CTRL_MODE_MASK                   (0x40000000U)
#define ADC_SEQ_CTRL_MODE_SHIFT                  (30U)
/*! MODE - Indicates whether the primary method for retrieving conversion results for this sequence
 *    will be accomplished via reading the global data register (SEQA_GDAT) at the end of each
 *    conversion, or the individual channel result registers at the end of the entire sequence. Impacts
 *    when conversion-complete interrupt/DMA trigger for sequence-A will be generated and which
 *    overrun conditions contribute to an overrun interrupt as described below.
 *  0b0..End of conversion. The sequence A interrupt/DMA trigger will be set at the end of each individual ADC
 *       conversion performed under sequence A. This flag will mirror the DATAVALID bit in the SEQA_GDAT register. The
 *       OVERRUN bit in the SEQA_GDAT register will contribute to generation of an overrun interrupt/DMA trigger
 *       if enabled.
 *  0b1..End of sequence. The sequence A interrupt/DMA trigger will be set when the entire set of sequence-A
 *       conversions completes. This flag will need to be explicitly cleared by software or by the DMA-clear signal in
 *       this mode. The OVERRUN bit in the SEQA_GDAT register will NOT contribute to generation of an overrun
 *       interrupt/DMA trigger since it is assumed this register may not be utilized in this mode.
 */
#define ADC_SEQ_CTRL_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_MODE_SHIFT)) & ADC_SEQ_CTRL_MODE_MASK)
#define ADC_SEQ_CTRL_SEQ_ENA_MASK                (0x80000000U)
#define ADC_SEQ_CTRL_SEQ_ENA_SHIFT               (31U)
/*! SEQ_ENA - Sequence Enable. In order to avoid spuriously triggering the sequence, care should be
 *    taken to only set the SEQn_ENA bit when the selected trigger input is in its INACTIVE state
 *    (as defined by the TRIGPOL bit). If this condition is not met, the sequence will be triggered
 *    immediately upon being enabled. In order to avoid spuriously triggering the sequence, care
 *    should be taken to only set the SEQn_ENA bit when the selected trigger input is in its INACTIVE
 *    state (as defined by the TRIGPOL bit). If this condition is not met, the sequence will be
 *    triggered immediately upon being enabled.
 *  0b0..Disabled. Sequence n is disabled. Sequence n triggers are ignored. If this bit is cleared while sequence
 *       n is in progress, the sequence will be halted at the end of the current conversion. After the sequence is
 *       re-enabled, a new trigger will be required to restart the sequence beginning with the next enabled channel.
 *  0b1..Enabled. Sequence n is enabled.
 */
#define ADC_SEQ_CTRL_SEQ_ENA(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_CTRL_SEQ_ENA_SHIFT)) & ADC_SEQ_CTRL_SEQ_ENA_MASK)
/*! @} */

/* The count of ADC_SEQ_CTRL */
#define ADC_SEQ_CTRL_COUNT                       (2U)

/*! @name SEQ_GDAT - ADC Sequence-n Global Data register. This register contains the result of the most recent ADC conversion performed under sequence-n. */
/*! @{ */
#define ADC_SEQ_GDAT_RESULT_MASK                 (0xFFF0U)
#define ADC_SEQ_GDAT_RESULT_SHIFT                (4U)
/*! RESULT - This field contains the 12-bit ADC conversion result from the most recent conversion
 *    performed under conversion sequence associated with this register. The result is a binary
 *    fraction representing the voltage on the currently-selected input channel as it falls within the
 *    range of VREFP to VREFN. Zero in the field indicates that the voltage on the input pin was less
 *    than, equal to, or close to that on VREFN, while 0xFFF indicates that the voltage on the input
 *    was close to, equal to, or greater than that on VREFP. DATAVALID = 1 indicates that this
 *    result has not yet been read.
 */
#define ADC_SEQ_GDAT_RESULT(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_RESULT_SHIFT)) & ADC_SEQ_GDAT_RESULT_MASK)
#define ADC_SEQ_GDAT_THCMPRANGE_MASK             (0x30000U)
#define ADC_SEQ_GDAT_THCMPRANGE_SHIFT            (16U)
/*! THCMPRANGE - Indicates whether the result of the last conversion performed was above, below or
 *    within the range established by the designated threshold comparison registers (THRn_LOW and
 *    THRn_HIGH).
 */
#define ADC_SEQ_GDAT_THCMPRANGE(x)               (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_THCMPRANGE_SHIFT)) & ADC_SEQ_GDAT_THCMPRANGE_MASK)
#define ADC_SEQ_GDAT_THCMPCROSS_MASK             (0xC0000U)
#define ADC_SEQ_GDAT_THCMPCROSS_SHIFT            (18U)
/*! THCMPCROSS - Indicates whether the result of the last conversion performed represented a
 *    crossing of the threshold level established by the designated LOW threshold comparison register
 *    (THRn_LOW) and, if so, in what direction the crossing occurred.
 */
#define ADC_SEQ_GDAT_THCMPCROSS(x)               (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_THCMPCROSS_SHIFT)) & ADC_SEQ_GDAT_THCMPCROSS_MASK)
#define ADC_SEQ_GDAT_CHN_MASK                    (0x3C000000U)
#define ADC_SEQ_GDAT_CHN_SHIFT                   (26U)
/*! CHN - These bits contain the channel from which the RESULT bits were converted (e.g. 0000
 *    identifies channel 0, 0001 channel 1, etc.).
 */
#define ADC_SEQ_GDAT_CHN(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_CHN_SHIFT)) & ADC_SEQ_GDAT_CHN_MASK)
#define ADC_SEQ_GDAT_OVERRUN_MASK                (0x40000000U)
#define ADC_SEQ_GDAT_OVERRUN_SHIFT               (30U)
/*! OVERRUN - This bit is set if a new conversion result is loaded into the RESULT field before a
 *    previous result has been read - i.e. while the DATAVALID bit is set. This bit is cleared, along
 *    with the DATAVALID bit, whenever this register is read. This bit will contribute to an overrun
 *    interrupt/DMA trigger if the MODE bit (in SEQAA_CTRL) for the corresponding sequence is set
 *    to '0' (and if the overrun interrupt is enabled).
 */
#define ADC_SEQ_GDAT_OVERRUN(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_OVERRUN_SHIFT)) & ADC_SEQ_GDAT_OVERRUN_MASK)
#define ADC_SEQ_GDAT_DATAVALID_MASK              (0x80000000U)
#define ADC_SEQ_GDAT_DATAVALID_SHIFT             (31U)
/*! DATAVALID - This bit is set to '1' at the end of each conversion when a new result is loaded
 *    into the RESULT field. It is cleared whenever this register is read. This bit will cause a
 *    conversion-complete interrupt for the corresponding sequence if the MODE bit (in SEQA_CTRL) for that
 *    sequence is set to 0 (and if the interrupt is enabled).
 */
#define ADC_SEQ_GDAT_DATAVALID(x)                (((uint32_t)(((uint32_t)(x)) << ADC_SEQ_GDAT_DATAVALID_SHIFT)) & ADC_SEQ_GDAT_DATAVALID_MASK)
/*! @} */

/* The count of ADC_SEQ_GDAT */
#define ADC_SEQ_GDAT_COUNT                       (2U)

/*! @name DAT - ADC Channel N Data register. This register contains the result of the most recent conversion completed on channel N. */
/*! @{ */
#define ADC_DAT_RESULT_MASK                      (0xFFF0U)
#define ADC_DAT_RESULT_SHIFT                     (4U)
/*! RESULT - This field contains the 12-bit ADC conversion result from the last conversion performed
 *    on this channel. This will be a binary fraction representing the voltage on the AD0[n] pin,
 *    as it falls within the range of VREFP to VREFN. Zero in the field indicates that the voltage on
 *    the input pin was less than, equal to, or close to that on VREFN, while 0xFFF indicates that
 *    the voltage on the input was close to, equal to, or greater than that on VREFP.
 */
#define ADC_DAT_RESULT(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_DAT_RESULT_SHIFT)) & ADC_DAT_RESULT_MASK)
#define ADC_DAT_THCMPRANGE_MASK                  (0x30000U)
#define ADC_DAT_THCMPRANGE_SHIFT                 (16U)
/*! THCMPRANGE - Threshold Range Comparison result. 0x0 = In Range: The last completed conversion
 *    was greater than or equal to the value programmed into the designated LOW threshold register
 *    (THRn_LOW) but less than or equal to the value programmed into the designated HIGH threshold
 *    register (THRn_HIGH). 0x1 = Below Range: The last completed conversion on was less than the value
 *    programmed into the designated LOW threshold register (THRn_LOW). 0x2 = Above Range: The last
 *    completed conversion was greater than the value programmed into the designated HIGH threshold
 *    register (THRn_HIGH). 0x3 = Reserved.
 */
#define ADC_DAT_THCMPRANGE(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_DAT_THCMPRANGE_SHIFT)) & ADC_DAT_THCMPRANGE_MASK)
#define ADC_DAT_THCMPCROSS_MASK                  (0xC0000U)
#define ADC_DAT_THCMPCROSS_SHIFT                 (18U)
/*! THCMPCROSS - Threshold Crossing Comparison result. 0x0 = No threshold Crossing detected: The
 *    most recent completed conversion on this channel had the same relationship (above or below) to
 *    the threshold value established by the designated LOW threshold register (THRn_LOW) as did the
 *    previous conversion on this channel. 0x1 = Reserved. 0x2 = Downward Threshold Crossing
 *    Detected. Indicates that a threshold crossing in the downward direction has occurred - i.e. the
 *    previous sample on this channel was above the threshold value established by the designated LOW
 *    threshold register (THRn_LOW) and the current sample is below that threshold. 0x3 = Upward
 *    Threshold Crossing Detected. Indicates that a threshold crossing in the upward direction has occurred
 *    - i.e. the previous sample on this channel was below the threshold value established by the
 *    designated LOW threshold register (THRn_LOW) and the current sample is above that threshold.
 */
#define ADC_DAT_THCMPCROSS(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_DAT_THCMPCROSS_SHIFT)) & ADC_DAT_THCMPCROSS_MASK)
#define ADC_DAT_CHANNEL_MASK                     (0x3C000000U)
#define ADC_DAT_CHANNEL_SHIFT                    (26U)
/*! CHANNEL - This field is hard-coded to contain the channel number that this particular register
 *    relates to (i.e. this field will contain 0b0000 for the DAT0 register, 0b0001 for the DAT1
 *    register, etc)
 */
#define ADC_DAT_CHANNEL(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DAT_CHANNEL_SHIFT)) & ADC_DAT_CHANNEL_MASK)
#define ADC_DAT_OVERRUN_MASK                     (0x40000000U)
#define ADC_DAT_OVERRUN_SHIFT                    (30U)
/*! OVERRUN - This bit will be set to a 1 if a new conversion on this channel completes and
 *    overwrites the previous contents of the RESULT field before it has been read - i.e. while the DONE bit
 *    is set. This bit is cleared, along with the DONE bit, whenever this register is read or when
 *    the data related to this channel is read from either of the global SEQn_GDAT registers. This
 *    bit (in any of the 12 registers) will cause an overrun interrupt/DMA trigger to be asserted if
 *    the overrun interrupt is enabled. While it is allowed to include the same channels in both
 *    conversion sequences, doing so may cause erratic behavior of the DONE and OVERRUN bits in the
 *    data registers associated with any of the channels that are shared between the two sequences. Any
 *    erratic OVERRUN behavior will also affect overrun interrupt generation, if enabled.
 */
#define ADC_DAT_OVERRUN(x)                       (((uint32_t)(((uint32_t)(x)) << ADC_DAT_OVERRUN_SHIFT)) & ADC_DAT_OVERRUN_MASK)
#define ADC_DAT_DATAVALID_MASK                   (0x80000000U)
#define ADC_DAT_DATAVALID_SHIFT                  (31U)
/*! DATAVALID - This bit is set to 1 when an ADC conversion on this channel completes. This bit is
 *    cleared whenever this register is read or when the data related to this channel is read from
 *    either of the global SEQn_GDAT registers. While it is allowed to include the same channels in
 *    both conversion sequences, doing so may cause erratic behavior of the DONE and OVERRUN bits in
 *    the data registers associated with any of the channels that are shared between the two
 *    sequences. Any erratic OVERRUN behavior will also affect overrun interrupt generation, if enabled.
 */
#define ADC_DAT_DATAVALID(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_DAT_DATAVALID_SHIFT)) & ADC_DAT_DATAVALID_MASK)
/*! @} */

/* The count of ADC_DAT */
#define ADC_DAT_COUNT                            (12U)

/*! @name THR0_LOW - ADC Low Compare Threshold register 0: Contains the lower threshold level for automatic threshold comparison for any channels linked to threshold pair 0. */
/*! @{ */
#define ADC_THR0_LOW_THRLOW_MASK                 (0xFFF0U)
#define ADC_THR0_LOW_THRLOW_SHIFT                (4U)
/*! THRLOW - Low threshold value against which ADC results will be compared
 */
#define ADC_THR0_LOW_THRLOW(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_THR0_LOW_THRLOW_SHIFT)) & ADC_THR0_LOW_THRLOW_MASK)
/*! @} */

/*! @name THR1_LOW - ADC Low Compare Threshold register 1: Contains the lower threshold level for automatic threshold comparison for any channels linked to threshold pair 1. */
/*! @{ */
#define ADC_THR1_LOW_THRLOW_MASK                 (0xFFF0U)
#define ADC_THR1_LOW_THRLOW_SHIFT                (4U)
/*! THRLOW - Low threshold value against which ADC results will be compared
 */
#define ADC_THR1_LOW_THRLOW(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_THR1_LOW_THRLOW_SHIFT)) & ADC_THR1_LOW_THRLOW_MASK)
/*! @} */

/*! @name THR0_HIGH - ADC High Compare Threshold register 0: Contains the upper threshold level for automatic threshold comparison for any channels linked to threshold pair 0. */
/*! @{ */
#define ADC_THR0_HIGH_THRHIGH_MASK               (0xFFF0U)
#define ADC_THR0_HIGH_THRHIGH_SHIFT              (4U)
/*! THRHIGH - High threshold value against which ADC results will be compared
 */
#define ADC_THR0_HIGH_THRHIGH(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_THR0_HIGH_THRHIGH_SHIFT)) & ADC_THR0_HIGH_THRHIGH_MASK)
/*! @} */

/*! @name THR1_HIGH - ADC High Compare Threshold register 1: Contains the upper threshold level for automatic threshold comparison for any channels linked to threshold pair 1. */
/*! @{ */
#define ADC_THR1_HIGH_THRHIGH_MASK               (0xFFF0U)
#define ADC_THR1_HIGH_THRHIGH_SHIFT              (4U)
/*! THRHIGH - High threshold value against which ADC results will be compared
 */
#define ADC_THR1_HIGH_THRHIGH(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_THR1_HIGH_THRHIGH_SHIFT)) & ADC_THR1_HIGH_THRHIGH_MASK)
/*! @} */

/*! @name CHAN_THRSEL - ADC Channel-Threshold Select register. Specifies which set of threshold compare registers are to be used for each channel */
/*! @{ */
#define ADC_CHAN_THRSEL_CH0_THRSEL_MASK          (0x1U)
#define ADC_CHAN_THRSEL_CH0_THRSEL_SHIFT         (0U)
/*! CH0_THRSEL - Threshold select for channel 0.
 *  0b0..Threshold 0. Results for this channel will be compared against the threshold levels indicated in the THR0_LOW and THR0_HIGH registers.
 *  0b1..Threshold 1. Results for this channel will be compared against the threshold levels indicated in the THR1_LOW and THR1_HIGH registers.
 */
#define ADC_CHAN_THRSEL_CH0_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH0_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH0_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH1_THRSEL_MASK          (0x2U)
#define ADC_CHAN_THRSEL_CH1_THRSEL_SHIFT         (1U)
/*! CH1_THRSEL - Threshold select for channel 1. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH1_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH1_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH1_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH2_THRSEL_MASK          (0x4U)
#define ADC_CHAN_THRSEL_CH2_THRSEL_SHIFT         (2U)
/*! CH2_THRSEL - Threshold select for channel 2. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH2_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH2_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH2_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH3_THRSEL_MASK          (0x8U)
#define ADC_CHAN_THRSEL_CH3_THRSEL_SHIFT         (3U)
/*! CH3_THRSEL - Threshold select for channel 3. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH3_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH3_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH3_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH4_THRSEL_MASK          (0x10U)
#define ADC_CHAN_THRSEL_CH4_THRSEL_SHIFT         (4U)
/*! CH4_THRSEL - Threshold select for channel 4. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH4_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH4_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH4_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH5_THRSEL_MASK          (0x20U)
#define ADC_CHAN_THRSEL_CH5_THRSEL_SHIFT         (5U)
/*! CH5_THRSEL - Threshold select for channel 5. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH5_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH5_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH5_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH6_THRSEL_MASK          (0x40U)
#define ADC_CHAN_THRSEL_CH6_THRSEL_SHIFT         (6U)
/*! CH6_THRSEL - Threshold select for channel 6. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH6_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH6_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH6_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH7_THRSEL_MASK          (0x80U)
#define ADC_CHAN_THRSEL_CH7_THRSEL_SHIFT         (7U)
/*! CH7_THRSEL - Threshold select for channel 7. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH7_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH7_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH7_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH8_THRSEL_MASK          (0x100U)
#define ADC_CHAN_THRSEL_CH8_THRSEL_SHIFT         (8U)
/*! CH8_THRSEL - Threshold select for channel 8. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH8_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH8_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH8_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH9_THRSEL_MASK          (0x200U)
#define ADC_CHAN_THRSEL_CH9_THRSEL_SHIFT         (9U)
/*! CH9_THRSEL - Threshold select for channel 9. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH9_THRSEL(x)            (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH9_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH9_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH10_THRSEL_MASK         (0x400U)
#define ADC_CHAN_THRSEL_CH10_THRSEL_SHIFT        (10U)
/*! CH10_THRSEL - Threshold select for channel 10. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH10_THRSEL(x)           (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH10_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH10_THRSEL_MASK)
#define ADC_CHAN_THRSEL_CH11_THRSEL_MASK         (0x800U)
#define ADC_CHAN_THRSEL_CH11_THRSEL_SHIFT        (11U)
/*! CH11_THRSEL - Threshold select for channel 11. See description for channel 0.
 */
#define ADC_CHAN_THRSEL_CH11_THRSEL(x)           (((uint32_t)(((uint32_t)(x)) << ADC_CHAN_THRSEL_CH11_THRSEL_SHIFT)) & ADC_CHAN_THRSEL_CH11_THRSEL_MASK)
/*! @} */

/*! @name INTEN - ADC Interrupt Enable register. This register contains enable bits that enable the sequence-A, sequence-B, threshold compare and data overrun interrupts to be generated. */
/*! @{ */
#define ADC_INTEN_SEQA_INTEN_MASK                (0x1U)
#define ADC_INTEN_SEQA_INTEN_SHIFT               (0U)
/*! SEQA_INTEN - Sequence A interrupt enable.
 *  0b0..Disabled. The sequence A interrupt/DMA trigger is disabled.
 *  0b1..Enabled. The sequence A interrupt/DMA trigger is enabled and will be asserted either upon completion of
 *       each individual conversion performed as part of sequence A, or upon completion of the entire A sequence of
 *       conversions, depending on the MODE bit in the SEQA_CTRL register.
 */
#define ADC_INTEN_SEQA_INTEN(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_SEQA_INTEN_SHIFT)) & ADC_INTEN_SEQA_INTEN_MASK)
#define ADC_INTEN_SEQB_INTEN_MASK                (0x2U)
#define ADC_INTEN_SEQB_INTEN_SHIFT               (1U)
/*! SEQB_INTEN - Sequence B interrupt enable.
 *  0b0..Disabled. The sequence B interrupt/DMA trigger is disabled.
 *  0b1..Enabled. The sequence B interrupt/DMA trigger is enabled and will be asserted either upon completion of
 *       each individual conversion performed as part of sequence B, or upon completion of the entire B sequence of
 *       conversions, depending on the MODE bit in the SEQB_CTRL register.
 */
#define ADC_INTEN_SEQB_INTEN(x)                  (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_SEQB_INTEN_SHIFT)) & ADC_INTEN_SEQB_INTEN_MASK)
#define ADC_INTEN_OVR_INTEN_MASK                 (0x4U)
#define ADC_INTEN_OVR_INTEN_SHIFT                (2U)
/*! OVR_INTEN - Overrun interrupt enable.
 *  0b0..Disabled. The overrun interrupt is disabled.
 *  0b1..Enabled. The overrun interrupt is enabled. Detection of an overrun condition on any of the 12 channel
 *       data registers will cause an overrun interrupt/DMA trigger. In addition, if the MODE bit for a particular
 *       sequence is 0, then an overrun in the global data register for that sequence will also cause this
 *       interrupt/DMA trigger to be asserted.
 */
#define ADC_INTEN_OVR_INTEN(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_OVR_INTEN_SHIFT)) & ADC_INTEN_OVR_INTEN_MASK)
#define ADC_INTEN_ADCMPINTEN0_MASK               (0x18U)
#define ADC_INTEN_ADCMPINTEN0_SHIFT              (3U)
/*! ADCMPINTEN0 - Threshold comparison interrupt enable for channel 0.
 *  0b00..Disabled.
 *  0b01..Outside threshold.
 *  0b10..Crossing threshold.
 *  0b11..Reserved
 */
#define ADC_INTEN_ADCMPINTEN0(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN0_SHIFT)) & ADC_INTEN_ADCMPINTEN0_MASK)
#define ADC_INTEN_ADCMPINTEN1_MASK               (0x60U)
#define ADC_INTEN_ADCMPINTEN1_SHIFT              (5U)
/*! ADCMPINTEN1 - Channel 1 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN1(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN1_SHIFT)) & ADC_INTEN_ADCMPINTEN1_MASK)
#define ADC_INTEN_ADCMPINTEN2_MASK               (0x180U)
#define ADC_INTEN_ADCMPINTEN2_SHIFT              (7U)
/*! ADCMPINTEN2 - Channel 2 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN2(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN2_SHIFT)) & ADC_INTEN_ADCMPINTEN2_MASK)
#define ADC_INTEN_ADCMPINTEN3_MASK               (0x600U)
#define ADC_INTEN_ADCMPINTEN3_SHIFT              (9U)
/*! ADCMPINTEN3 - Channel 3 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN3(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN3_SHIFT)) & ADC_INTEN_ADCMPINTEN3_MASK)
#define ADC_INTEN_ADCMPINTEN4_MASK               (0x1800U)
#define ADC_INTEN_ADCMPINTEN4_SHIFT              (11U)
/*! ADCMPINTEN4 - Channel 4 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN4(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN4_SHIFT)) & ADC_INTEN_ADCMPINTEN4_MASK)
#define ADC_INTEN_ADCMPINTEN5_MASK               (0x6000U)
#define ADC_INTEN_ADCMPINTEN5_SHIFT              (13U)
/*! ADCMPINTEN5 - Channel 5 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN5(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN5_SHIFT)) & ADC_INTEN_ADCMPINTEN5_MASK)
#define ADC_INTEN_ADCMPINTEN6_MASK               (0x18000U)
#define ADC_INTEN_ADCMPINTEN6_SHIFT              (15U)
/*! ADCMPINTEN6 - Channel 6 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN6(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN6_SHIFT)) & ADC_INTEN_ADCMPINTEN6_MASK)
#define ADC_INTEN_ADCMPINTEN7_MASK               (0x60000U)
#define ADC_INTEN_ADCMPINTEN7_SHIFT              (17U)
/*! ADCMPINTEN7 - Channel 7 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN7(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN7_SHIFT)) & ADC_INTEN_ADCMPINTEN7_MASK)
#define ADC_INTEN_ADCMPINTEN8_MASK               (0x180000U)
#define ADC_INTEN_ADCMPINTEN8_SHIFT              (19U)
/*! ADCMPINTEN8 - Channel 8 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN8(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN8_SHIFT)) & ADC_INTEN_ADCMPINTEN8_MASK)
#define ADC_INTEN_ADCMPINTEN9_MASK               (0x600000U)
#define ADC_INTEN_ADCMPINTEN9_SHIFT              (21U)
/*! ADCMPINTEN9 - Channel 9 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN9(x)                 (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN9_SHIFT)) & ADC_INTEN_ADCMPINTEN9_MASK)
#define ADC_INTEN_ADCMPINTEN10_MASK              (0x1800000U)
#define ADC_INTEN_ADCMPINTEN10_SHIFT             (23U)
/*! ADCMPINTEN10 - Channel 10 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN10(x)                (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN10_SHIFT)) & ADC_INTEN_ADCMPINTEN10_MASK)
#define ADC_INTEN_ADCMPINTEN11_MASK              (0x6000000U)
#define ADC_INTEN_ADCMPINTEN11_SHIFT             (25U)
/*! ADCMPINTEN11 - Channel 21 threshold comparison interrupt enable. See description for channel 0.
 */
#define ADC_INTEN_ADCMPINTEN11(x)                (((uint32_t)(((uint32_t)(x)) << ADC_INTEN_ADCMPINTEN11_SHIFT)) & ADC_INTEN_ADCMPINTEN11_MASK)
/*! @} */

/*! @name FLAGS - ADC Flags register. Contains the four interrupt/DMA trigger flags and the individual component overrun and threshold-compare flags. (The overrun bits replicate information stored in the result registers). */
/*! @{ */
#define ADC_FLAGS_THCMP0_MASK                    (0x1U)
#define ADC_FLAGS_THCMP0_SHIFT                   (0U)
/*! THCMP0 - Threshold comparison event on Channel 0. Set to 1 upon either an out-of-range result or
 *    a threshold-crossing result if enabled to do so in the INTEN register. This bit is cleared by
 *    writing a 1.
 */
#define ADC_FLAGS_THCMP0(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP0_SHIFT)) & ADC_FLAGS_THCMP0_MASK)
#define ADC_FLAGS_THCMP1_MASK                    (0x2U)
#define ADC_FLAGS_THCMP1_SHIFT                   (1U)
/*! THCMP1 - Threshold comparison event on Channel 1. See description for channel 0.
 */
#define ADC_FLAGS_THCMP1(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP1_SHIFT)) & ADC_FLAGS_THCMP1_MASK)
#define ADC_FLAGS_THCMP2_MASK                    (0x4U)
#define ADC_FLAGS_THCMP2_SHIFT                   (2U)
/*! THCMP2 - Threshold comparison event on Channel 2. See description for channel 0.
 */
#define ADC_FLAGS_THCMP2(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP2_SHIFT)) & ADC_FLAGS_THCMP2_MASK)
#define ADC_FLAGS_THCMP3_MASK                    (0x8U)
#define ADC_FLAGS_THCMP3_SHIFT                   (3U)
/*! THCMP3 - Threshold comparison event on Channel 3. See description for channel 0.
 */
#define ADC_FLAGS_THCMP3(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP3_SHIFT)) & ADC_FLAGS_THCMP3_MASK)
#define ADC_FLAGS_THCMP4_MASK                    (0x10U)
#define ADC_FLAGS_THCMP4_SHIFT                   (4U)
/*! THCMP4 - Threshold comparison event on Channel 4. See description for channel 0.
 */
#define ADC_FLAGS_THCMP4(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP4_SHIFT)) & ADC_FLAGS_THCMP4_MASK)
#define ADC_FLAGS_THCMP5_MASK                    (0x20U)
#define ADC_FLAGS_THCMP5_SHIFT                   (5U)
/*! THCMP5 - Threshold comparison event on Channel 5. See description for channel 0.
 */
#define ADC_FLAGS_THCMP5(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP5_SHIFT)) & ADC_FLAGS_THCMP5_MASK)
#define ADC_FLAGS_THCMP6_MASK                    (0x40U)
#define ADC_FLAGS_THCMP6_SHIFT                   (6U)
/*! THCMP6 - Threshold comparison event on Channel 6. See description for channel 0.
 */
#define ADC_FLAGS_THCMP6(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP6_SHIFT)) & ADC_FLAGS_THCMP6_MASK)
#define ADC_FLAGS_THCMP7_MASK                    (0x80U)
#define ADC_FLAGS_THCMP7_SHIFT                   (7U)
/*! THCMP7 - Threshold comparison event on Channel 7. See description for channel 0.
 */
#define ADC_FLAGS_THCMP7(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP7_SHIFT)) & ADC_FLAGS_THCMP7_MASK)
#define ADC_FLAGS_THCMP8_MASK                    (0x100U)
#define ADC_FLAGS_THCMP8_SHIFT                   (8U)
/*! THCMP8 - Threshold comparison event on Channel 8. See description for channel 0.
 */
#define ADC_FLAGS_THCMP8(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP8_SHIFT)) & ADC_FLAGS_THCMP8_MASK)
#define ADC_FLAGS_THCMP9_MASK                    (0x200U)
#define ADC_FLAGS_THCMP9_SHIFT                   (9U)
/*! THCMP9 - Threshold comparison event on Channel 9. See description for channel 0.
 */
#define ADC_FLAGS_THCMP9(x)                      (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP9_SHIFT)) & ADC_FLAGS_THCMP9_MASK)
#define ADC_FLAGS_THCMP10_MASK                   (0x400U)
#define ADC_FLAGS_THCMP10_SHIFT                  (10U)
/*! THCMP10 - Threshold comparison event on Channel 10. See description for channel 0.
 */
#define ADC_FLAGS_THCMP10(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP10_SHIFT)) & ADC_FLAGS_THCMP10_MASK)
#define ADC_FLAGS_THCMP11_MASK                   (0x800U)
#define ADC_FLAGS_THCMP11_SHIFT                  (11U)
/*! THCMP11 - Threshold comparison event on Channel 11. See description for channel 0.
 */
#define ADC_FLAGS_THCMP11(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP11_SHIFT)) & ADC_FLAGS_THCMP11_MASK)
#define ADC_FLAGS_OVERRUN0_MASK                  (0x1000U)
#define ADC_FLAGS_OVERRUN0_SHIFT                 (12U)
/*! OVERRUN0 - Mirrors the OVERRRUN status flag from the result register for ADC channel 0
 */
#define ADC_FLAGS_OVERRUN0(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN0_SHIFT)) & ADC_FLAGS_OVERRUN0_MASK)
#define ADC_FLAGS_OVERRUN1_MASK                  (0x2000U)
#define ADC_FLAGS_OVERRUN1_SHIFT                 (13U)
/*! OVERRUN1 - Mirrors the OVERRRUN status flag from the result register for ADC channel 1
 */
#define ADC_FLAGS_OVERRUN1(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN1_SHIFT)) & ADC_FLAGS_OVERRUN1_MASK)
#define ADC_FLAGS_OVERRUN2_MASK                  (0x4000U)
#define ADC_FLAGS_OVERRUN2_SHIFT                 (14U)
/*! OVERRUN2 - Mirrors the OVERRRUN status flag from the result register for ADC channel 2
 */
#define ADC_FLAGS_OVERRUN2(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN2_SHIFT)) & ADC_FLAGS_OVERRUN2_MASK)
#define ADC_FLAGS_OVERRUN3_MASK                  (0x8000U)
#define ADC_FLAGS_OVERRUN3_SHIFT                 (15U)
/*! OVERRUN3 - Mirrors the OVERRRUN status flag from the result register for ADC channel 3
 */
#define ADC_FLAGS_OVERRUN3(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN3_SHIFT)) & ADC_FLAGS_OVERRUN3_MASK)
#define ADC_FLAGS_OVERRUN4_MASK                  (0x10000U)
#define ADC_FLAGS_OVERRUN4_SHIFT                 (16U)
/*! OVERRUN4 - Mirrors the OVERRRUN status flag from the result register for ADC channel 4
 */
#define ADC_FLAGS_OVERRUN4(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN4_SHIFT)) & ADC_FLAGS_OVERRUN4_MASK)
#define ADC_FLAGS_OVERRUN5_MASK                  (0x20000U)
#define ADC_FLAGS_OVERRUN5_SHIFT                 (17U)
/*! OVERRUN5 - Mirrors the OVERRRUN status flag from the result register for ADC channel 5
 */
#define ADC_FLAGS_OVERRUN5(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN5_SHIFT)) & ADC_FLAGS_OVERRUN5_MASK)
#define ADC_FLAGS_OVERRUN6_MASK                  (0x40000U)
#define ADC_FLAGS_OVERRUN6_SHIFT                 (18U)
/*! OVERRUN6 - Mirrors the OVERRRUN status flag from the result register for ADC channel 6
 */
#define ADC_FLAGS_OVERRUN6(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN6_SHIFT)) & ADC_FLAGS_OVERRUN6_MASK)
#define ADC_FLAGS_OVERRUN7_MASK                  (0x80000U)
#define ADC_FLAGS_OVERRUN7_SHIFT                 (19U)
/*! OVERRUN7 - Mirrors the OVERRRUN status flag from the result register for ADC channel 7
 */
#define ADC_FLAGS_OVERRUN7(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN7_SHIFT)) & ADC_FLAGS_OVERRUN7_MASK)
#define ADC_FLAGS_OVERRUN8_MASK                  (0x100000U)
#define ADC_FLAGS_OVERRUN8_SHIFT                 (20U)
/*! OVERRUN8 - Mirrors the OVERRRUN status flag from the result register for ADC channel 8
 */
#define ADC_FLAGS_OVERRUN8(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN8_SHIFT)) & ADC_FLAGS_OVERRUN8_MASK)
#define ADC_FLAGS_OVERRUN9_MASK                  (0x200000U)
#define ADC_FLAGS_OVERRUN9_SHIFT                 (21U)
/*! OVERRUN9 - Mirrors the OVERRRUN status flag from the result register for ADC channel 9
 */
#define ADC_FLAGS_OVERRUN9(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN9_SHIFT)) & ADC_FLAGS_OVERRUN9_MASK)
#define ADC_FLAGS_OVERRUN10_MASK                 (0x400000U)
#define ADC_FLAGS_OVERRUN10_SHIFT                (22U)
/*! OVERRUN10 - Mirrors the OVERRRUN status flag from the result register for ADC channel 10
 */
#define ADC_FLAGS_OVERRUN10(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN10_SHIFT)) & ADC_FLAGS_OVERRUN10_MASK)
#define ADC_FLAGS_OVERRUN11_MASK                 (0x800000U)
#define ADC_FLAGS_OVERRUN11_SHIFT                (23U)
/*! OVERRUN11 - Mirrors the OVERRRUN status flag from the result register for ADC channel 11
 */
#define ADC_FLAGS_OVERRUN11(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVERRUN11_SHIFT)) & ADC_FLAGS_OVERRUN11_MASK)
#define ADC_FLAGS_SEQA_OVR_MASK                  (0x1000000U)
#define ADC_FLAGS_SEQA_OVR_SHIFT                 (24U)
/*! SEQA_OVR - Mirrors the global OVERRUN status flag in the SEQA_GDAT register
 */
#define ADC_FLAGS_SEQA_OVR(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_SEQA_OVR_SHIFT)) & ADC_FLAGS_SEQA_OVR_MASK)
#define ADC_FLAGS_SEQB_OVR_MASK                  (0x2000000U)
#define ADC_FLAGS_SEQB_OVR_SHIFT                 (25U)
/*! SEQB_OVR - Mirrors the global OVERRUN status flag in the SEQB_GDAT register
 */
#define ADC_FLAGS_SEQB_OVR(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_SEQB_OVR_SHIFT)) & ADC_FLAGS_SEQB_OVR_MASK)
#define ADC_FLAGS_SEQA_INT_MASK                  (0x10000000U)
#define ADC_FLAGS_SEQA_INT_SHIFT                 (28U)
/*! SEQA_INT - Sequence A interrupt/DMA trigger. If the MODE bit in the SEQA_CTRL register is 0,
 *    this flag will mirror the DATAVALID bit in the sequence A global data register (SEQA_GDAT), which
 *    is set at the end of every ADC conversion performed as part of sequence A. It will be cleared
 *    automatically when the SEQA_GDAT register is read. If the MODE bit in the SEQA_CTRL register
 *    is 1, this flag will be set upon completion of an entire A sequence. In this case it must be
 *    cleared by writing a 1 to this SEQA_INT bit. This interrupt must be enabled in the INTEN
 *    register.
 */
#define ADC_FLAGS_SEQA_INT(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_SEQA_INT_SHIFT)) & ADC_FLAGS_SEQA_INT_MASK)
#define ADC_FLAGS_SEQB_INT_MASK                  (0x20000000U)
#define ADC_FLAGS_SEQB_INT_SHIFT                 (29U)
/*! SEQB_INT - Sequence A interrupt/DMA trigger. If the MODE bit in the SEQB_CTRL register is 0,
 *    this flag will mirror the DATAVALID bit in the sequence A global data register (SEQB_GDAT), which
 *    is set at the end of every ADC conversion performed as part of sequence B. It will be cleared
 *    automatically when the SEQB_GDAT register is read. If the MODE bit in the SEQB_CTRL register
 *    is 1, this flag will be set upon completion of an entire B sequence. In this case it must be
 *    cleared by writing a 1 to this SEQB_INT bit. This interrupt must be enabled in the INTEN
 *    register.
 */
#define ADC_FLAGS_SEQB_INT(x)                    (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_SEQB_INT_SHIFT)) & ADC_FLAGS_SEQB_INT_MASK)
#define ADC_FLAGS_THCMP_INT_MASK                 (0x40000000U)
#define ADC_FLAGS_THCMP_INT_SHIFT                (30U)
/*! THCMP_INT - Threshold Comparison Interrupt. This bit will be set if any of the THCMP flags in
 *    the lower bits of this register are set to 1 (due to an enabled out-of-range or
 *    threshold-crossing event on any channel). Each type of threshold comparison interrupt on each channel must be
 *    individually enabled in the INTEN register to cause this interrupt. This bit will be cleared
 *    when all of the individual threshold flags are cleared via writing 1s to those bits.
 */
#define ADC_FLAGS_THCMP_INT(x)                   (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_THCMP_INT_SHIFT)) & ADC_FLAGS_THCMP_INT_MASK)
#define ADC_FLAGS_OVR_INT_MASK                   (0x80000000U)
#define ADC_FLAGS_OVR_INT_SHIFT                  (31U)
/*! OVR_INT - Overrun Interrupt flag. Any overrun bit in any of the individual channel data
 *    registers will cause this interrupt. In addition, if the MODE bit in either of the SEQn_CTRL registers
 *    is 0 then the OVERRUN bit in the corresponding SEQn_GDAT register will also cause this
 *    interrupt. This interrupt must be enabled in the INTEN register. This bit will be cleared when all
 *    of the individual overrun bits have been cleared via reading the corresponding data registers.
 */
#define ADC_FLAGS_OVR_INT(x)                     (((uint32_t)(((uint32_t)(x)) << ADC_FLAGS_OVR_INT_SHIFT)) & ADC_FLAGS_OVR_INT_MASK)
/*! @} */

/*! @name TRM - ADC Startup register. */
/*! @{ */
#define ADC_TRM_VRANGE_MASK                      (0x20U)
#define ADC_TRM_VRANGE_SHIFT                     (5U)
/*! VRANGE - 1.8V to 3.6V Vdd range: This bit MUST be set to '1' if operation below 2.7V is to be
 *    used. Failure to set this bit will result in invalid ADC results. Note: This bit will not be
 *    spec'd on parts that do not support operation below 2.7V
 */
#define ADC_TRM_VRANGE(x)                        (((uint32_t)(((uint32_t)(x)) << ADC_TRM_VRANGE_SHIFT)) & ADC_TRM_VRANGE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC0 base address */
#define ADC0_BASE                                (0x4001C000u)
/** Peripheral ADC0 base pointer */
#define ADC0                                     ((ADC_Type *)ADC0_BASE)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC0_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC0 }
/** Interrupt vectors for the ADC peripheral type */
#define ADC_SEQ_IRQS                             { ADC0_SEQA_IRQn, ADC0_SEQB_IRQn }
#define ADC_THCMP_IRQS                           { ADC0_THCMP_IRQn }

/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */

/* ----------------------------------------------------------------------------
   -- DAC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Peripheral_Access_Layer DAC Peripheral Access Layer
 * @{
 */

/** DAC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< D/A Converter Register. This register contains the digital value to be converted to analog and a power control bit., offset: 0x0 */
  __IO uint32_t CTRL;                              /**< DAC Control register. This register controls DMA and timer operation., offset: 0x4 */
  __IO uint32_t CNTVAL;                            /**< DAC Counter Value register. This register contains the reload value for the DAC DMA/Interrupt timer., offset: 0x8 */
} DAC_Type;

/* ----------------------------------------------------------------------------
   -- DAC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DAC_Register_Masks DAC Register Masks
 * @{
 */

/*! @name CR - D/A Converter Register. This register contains the digital value to be converted to analog and a power control bit. */
/*! @{ */
#define DAC_CR_VALUE_MASK                        (0xFFC0U)
#define DAC_CR_VALUE_SHIFT                       (6U)
/*! VALUE - After the selected settling time after this field is written with a new VALUE, the
 *    voltage on the DAC_OUT pin (with respect to VSSA) is VALUE (VREFP - VREFN)/1024 + VREFN.
 */
#define DAC_CR_VALUE(x)                          (((uint32_t)(((uint32_t)(x)) << DAC_CR_VALUE_SHIFT)) & DAC_CR_VALUE_MASK)
#define DAC_CR_BIAS_MASK                         (0x10000U)
#define DAC_CR_BIAS_SHIFT                        (16U)
/*! BIAS - The settling time of the DAC
 *  0b0..The settling time of the DAC is 1 us max, and the maximum current is 700 uA. This allows a maximum update rate of 1 MHz.
 *  0b1..The settling time of the DAC is 2.5 us and the maximum current is 350 uA. This allows a maximum update rate of 400 kHz.
 */
#define DAC_CR_BIAS(x)                           (((uint32_t)(((uint32_t)(x)) << DAC_CR_BIAS_SHIFT)) & DAC_CR_BIAS_MASK)
/*! @} */

/*! @name CTRL - DAC Control register. This register controls DMA and timer operation. */
/*! @{ */
#define DAC_CTRL_INT_DMA_REQ_MASK                (0x1U)
#define DAC_CTRL_INT_DMA_REQ_SHIFT               (0U)
/*! INT_DMA_REQ - DMA request
 *  0b0..This bit is cleared on any write to the DACR register.
 *  0b1..This bit is set by hardware when the timer times out.
 */
#define DAC_CTRL_INT_DMA_REQ(x)                  (((uint32_t)(((uint32_t)(x)) << DAC_CTRL_INT_DMA_REQ_SHIFT)) & DAC_CTRL_INT_DMA_REQ_MASK)
#define DAC_CTRL_DBLBUF_ENA_MASK                 (0x2U)
#define DAC_CTRL_DBLBUF_ENA_SHIFT                (1U)
/*! DBLBUF_ENA - dacr double buffer
 *  0b0..DACR double-buffering is disabled.
 *  0b1..When this bit and the CNT_ENA bit are both set, the double-buffering feature in the DACR register will be
 *       enabled. Writes to the DACR register are written to a pre-buffer and then transferred to the DACR on the
 *       next time-out of the counter.
 */
#define DAC_CTRL_DBLBUF_ENA(x)                   (((uint32_t)(((uint32_t)(x)) << DAC_CTRL_DBLBUF_ENA_SHIFT)) & DAC_CTRL_DBLBUF_ENA_MASK)
#define DAC_CTRL_CNT_ENA_MASK                    (0x4U)
#define DAC_CTRL_CNT_ENA_SHIFT                   (2U)
/*! CNT_ENA - time-out counter operation
 *  0b0..Time-out counter operation is disabled.
 *  0b1..Time-out counter operation is enabled.
 */
#define DAC_CTRL_CNT_ENA(x)                      (((uint32_t)(((uint32_t)(x)) << DAC_CTRL_CNT_ENA_SHIFT)) & DAC_CTRL_CNT_ENA_MASK)
#define DAC_CTRL_DMA_ENA_MASK                    (0x8U)
#define DAC_CTRL_DMA_ENA_SHIFT                   (3U)
/*! DMA_ENA - DMA access
 *  0b0..DMA access is disabled.
 *  0b1..DMA Burst Request Input 7 is enabled for the DAC
 */
#define DAC_CTRL_DMA_ENA(x)                      (((uint32_t)(((uint32_t)(x)) << DAC_CTRL_DMA_ENA_SHIFT)) & DAC_CTRL_DMA_ENA_MASK)
/*! @} */

/*! @name CNTVAL - DAC Counter Value register. This register contains the reload value for the DAC DMA/Interrupt timer. */
/*! @{ */
#define DAC_CNTVAL_VALUE_MASK                    (0xFFFFU)
#define DAC_CNTVAL_VALUE_SHIFT                   (0U)
/*! VALUE - 16-bit reload value for the DAC interrupt/DMA timer.
 */
#define DAC_CNTVAL_VALUE(x)                      (((uint32_t)(((uint32_t)(x)) << DAC_CNTVAL_VALUE_SHIFT)) & DAC_CNTVAL_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DAC_Register_Masks */


/* DAC - Peripheral instance base addresses */
/** Peripheral DAC0 base address */
#define DAC0_BASE                                (0x40014000u)
/** Peripheral DAC0 base pointer */
#define DAC0                                     ((DAC_Type *)DAC0_BASE)
/** Peripheral DAC1 base address */
#define DAC1_BASE                                (0x40018000u)
/** Peripheral DAC1 base pointer */
#define DAC1                                     ((DAC_Type *)DAC1_BASE)
/** Array initializer of DAC peripheral base addresses */
#define DAC_BASE_ADDRS                           { DAC0_BASE, DAC1_BASE }
/** Array initializer of DAC peripheral base pointers */
#define DAC_BASE_PTRS                            { DAC0, DAC1 }

/*!
 * @}
 */ /* end of group DAC_Peripheral_Access_Layer */

//CTIMER0
//Ataque de registros
typedef struct
{
	uint32_t IR;
	uint32_t TCR;
	uint32_t TC;
	uint32_t PR;
	uint32_t PC;
	uint32_t MCR;
	uint32_t MR[4U];
	uint32_t CCR;
	uint32_t CR[4U];
	uint32_t EMR;
	uint8_t RESERVED0[52U];
	uint32_t CTCR;
	uint32_t PWMC;
	uint32_t MSR[4U];
}CTIMER0_Type;

#define CTIMER0_BASE (0x40038000U)
#define CTIMER0 ((CTIMER0_Type*)CTIMER0_BASE)
//Defines del CTimer
#define SYSCON_SYSAHBCLKCTRL0_CTIMER0_MASK (0x2000000U)//Para activar el clock, y el reset del timer
#define CTIMER0_IRQn (23U)//Para activar la interrupcion en el nvic
#define SCT_CONFIG *(uint32_t*)0x50004000
#define SCT_CTRL *(uint32_t*)0x50004004
#define SCT_OUTPUT *(uint32_t*)0x50004050
#define SCT_OUTPUTDIR *(uint32_t*)0x50004054
#define MATCHREL1 *(uint32_t*)0x50004204
#define MATCHREL2 *(uint32_t*)0x50004208



//MRT
#define MRT0_BASE (0x40004000u)
#define MRT ((MRT_Type *)MRT0_BASE)

typedef struct
{
    uint32_t INTVAL;
    uint32_t TIMER;
    uint32_t CTRL;
    uint32_t STAT;
}MRT_PART;

typedef struct{
     MRT_PART PART[4];
     uint8_t RESERVED_0[180];
     uint32_t IDLE_CH;
     uint32_t IRQ_FLAG;
} MRT_Type;


#endif /* LPC845_REGS_H_ */
