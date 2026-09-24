;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (MINGW64)
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _non_fourfsk_tx1010_pattern
	.globl _fourfsk_tx1010_pattern
	.globl _onepattern
	.globl _txpattern
	.globl _main
	.globl __sdcc_external_startup
	.globl _set_receiveber
	.globl _set_transmit
	.globl _set_cw
	.globl _axradio_commsleepexit
	.globl _axradio_setup_pincfg2
	.globl _axradio_setup_pincfg1
	.globl _axradio_get_transmitter_pa_type
	.globl _axradio_check_fourfsk_modulation
	.globl _axradio_agc_thaw
	.globl _axradio_agc_freeze
	.globl _axradio_conv_freq_tohz
	.globl _axradio_transmit
	.globl _axradio_set_mode
	.globl _axradio_cansleep
	.globl _axradio_init
	.globl _pn15_output
	.globl _pn15_advance
	.globl _pn9_advance
	.globl _wtimer_runcallbacks
	.globl _wtimer_idle
	.globl _wtimer_init
	.globl _wtimer1_setconfig
	.globl _wtimer0_setconfig
	.globl _flash_apply_calibration
	.globl _enter_sleep
	.globl _hweight8
	.globl _PORTC_7
	.globl _PORTC_6
	.globl _PORTC_5
	.globl _PORTC_4
	.globl _PORTC_3
	.globl _PORTC_2
	.globl _PORTC_1
	.globl _PORTC_0
	.globl _PORTB_7
	.globl _PORTB_6
	.globl _PORTB_5
	.globl _PORTB_4
	.globl _PORTB_3
	.globl _PORTB_2
	.globl _PORTB_1
	.globl _PORTB_0
	.globl _PORTA_7
	.globl _PORTA_6
	.globl _PORTA_5
	.globl _PORTA_4
	.globl _PORTA_3
	.globl _PORTA_2
	.globl _PORTA_1
	.globl _PORTA_0
	.globl _PINC_7
	.globl _PINC_6
	.globl _PINC_5
	.globl _PINC_4
	.globl _PINC_3
	.globl _PINC_2
	.globl _PINC_1
	.globl _PINC_0
	.globl _PINB_7
	.globl _PINB_6
	.globl _PINB_5
	.globl _PINB_4
	.globl _PINB_3
	.globl _PINB_2
	.globl _PINB_1
	.globl _PINB_0
	.globl _PINA_7
	.globl _PINA_6
	.globl _PINA_5
	.globl _PINA_4
	.globl _PINA_3
	.globl _PINA_2
	.globl _PINA_1
	.globl _PINA_0
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _IP_7
	.globl _IP_6
	.globl _IP_5
	.globl _IP_4
	.globl _IP_3
	.globl _IP_2
	.globl _IP_1
	.globl _IP_0
	.globl _EA
	.globl _IE_7
	.globl _IE_6
	.globl _IE_5
	.globl _IE_4
	.globl _IE_3
	.globl _IE_2
	.globl _IE_1
	.globl _IE_0
	.globl _EIP_7
	.globl _EIP_6
	.globl _EIP_5
	.globl _EIP_4
	.globl _EIP_3
	.globl _EIP_2
	.globl _EIP_1
	.globl _EIP_0
	.globl _EIE_7
	.globl _EIE_6
	.globl _EIE_5
	.globl _EIE_4
	.globl _EIE_3
	.globl _EIE_2
	.globl _EIE_1
	.globl _EIE_0
	.globl _E2IP_7
	.globl _E2IP_6
	.globl _E2IP_5
	.globl _E2IP_4
	.globl _E2IP_3
	.globl _E2IP_2
	.globl _E2IP_1
	.globl _E2IP_0
	.globl _E2IE_7
	.globl _E2IE_6
	.globl _E2IE_5
	.globl _E2IE_4
	.globl _E2IE_3
	.globl _E2IE_2
	.globl _E2IE_1
	.globl _E2IE_0
	.globl _B_7
	.globl _B_6
	.globl _B_5
	.globl _B_4
	.globl _B_3
	.globl _B_2
	.globl _B_1
	.globl _B_0
	.globl _ACC_7
	.globl _ACC_6
	.globl _ACC_5
	.globl _ACC_4
	.globl _ACC_3
	.globl _ACC_2
	.globl _ACC_1
	.globl _ACC_0
	.globl _WTSTAT
	.globl _WTIRQEN
	.globl _WTEVTD
	.globl _WTEVTD1
	.globl _WTEVTD0
	.globl _WTEVTC
	.globl _WTEVTC1
	.globl _WTEVTC0
	.globl _WTEVTB
	.globl _WTEVTB1
	.globl _WTEVTB0
	.globl _WTEVTA
	.globl _WTEVTA1
	.globl _WTEVTA0
	.globl _WTCNTR1
	.globl _WTCNTB
	.globl _WTCNTB1
	.globl _WTCNTB0
	.globl _WTCNTA
	.globl _WTCNTA1
	.globl _WTCNTA0
	.globl _WTCFGB
	.globl _WTCFGA
	.globl _WDTRESET
	.globl _WDTCFG
	.globl _U1STATUS
	.globl _U1SHREG
	.globl _U1MODE
	.globl _U1CTRL
	.globl _U0STATUS
	.globl _U0SHREG
	.globl _U0MODE
	.globl _U0CTRL
	.globl _T2STATUS
	.globl _T2PERIOD
	.globl _T2PERIOD1
	.globl _T2PERIOD0
	.globl _T2MODE
	.globl _T2CNT
	.globl _T2CNT1
	.globl _T2CNT0
	.globl _T2CLKSRC
	.globl _T1STATUS
	.globl _T1PERIOD
	.globl _T1PERIOD1
	.globl _T1PERIOD0
	.globl _T1MODE
	.globl _T1CNT
	.globl _T1CNT1
	.globl _T1CNT0
	.globl _T1CLKSRC
	.globl _T0STATUS
	.globl _T0PERIOD
	.globl _T0PERIOD1
	.globl _T0PERIOD0
	.globl _T0MODE
	.globl _T0CNT
	.globl _T0CNT1
	.globl _T0CNT0
	.globl _T0CLKSRC
	.globl _SPSTATUS
	.globl _SPSHREG
	.globl _SPMODE
	.globl _SPCLKSRC
	.globl _RADIOSTAT
	.globl _RADIOSTAT1
	.globl _RADIOSTAT0
	.globl _RADIODATA
	.globl _RADIODATA3
	.globl _RADIODATA2
	.globl _RADIODATA1
	.globl _RADIODATA0
	.globl _RADIOADDR
	.globl _RADIOADDR1
	.globl _RADIOADDR0
	.globl _RADIOACC
	.globl _OC1STATUS
	.globl _OC1PIN
	.globl _OC1MODE
	.globl _OC1COMP
	.globl _OC1COMP1
	.globl _OC1COMP0
	.globl _OC0STATUS
	.globl _OC0PIN
	.globl _OC0MODE
	.globl _OC0COMP
	.globl _OC0COMP1
	.globl _OC0COMP0
	.globl _NVSTATUS
	.globl _NVKEY
	.globl _NVDATA
	.globl _NVDATA1
	.globl _NVDATA0
	.globl _NVADDR
	.globl _NVADDR1
	.globl _NVADDR0
	.globl _IC1STATUS
	.globl _IC1MODE
	.globl _IC1CAPT
	.globl _IC1CAPT1
	.globl _IC1CAPT0
	.globl _IC0STATUS
	.globl _IC0MODE
	.globl _IC0CAPT
	.globl _IC0CAPT1
	.globl _IC0CAPT0
	.globl _PORTR
	.globl _PORTC
	.globl _PORTB
	.globl _PORTA
	.globl _PINR
	.globl _PINC
	.globl _PINB
	.globl _PINA
	.globl _DIRR
	.globl _DIRC
	.globl _DIRB
	.globl _DIRA
	.globl _DBGLNKSTAT
	.globl _DBGLNKBUF
	.globl _CODECONFIG
	.globl _CLKSTAT
	.globl _CLKCON
	.globl _ANALOGCOMP
	.globl _ADCCONV
	.globl _ADCCLKSRC
	.globl _ADCCH3CONFIG
	.globl _ADCCH2CONFIG
	.globl _ADCCH1CONFIG
	.globl _ADCCH0CONFIG
	.globl __XPAGE
	.globl _XPAGE
	.globl _SP
	.globl _PSW
	.globl _PCON
	.globl _IP
	.globl _IE
	.globl _EIP
	.globl _EIE
	.globl _E2IP
	.globl _E2IE
	.globl _DPS
	.globl _DPTR1
	.globl _DPTR0
	.globl _DPL1
	.globl _DPL
	.globl _DPH1
	.globl _DPH
	.globl _B
	.globl _ACC
	.globl _txdata
	.globl _XTALREADY
	.globl _XTALOSC
	.globl _XTALAMPL
	.globl _SILICONREV
	.globl _SCRATCH3
	.globl _SCRATCH2
	.globl _SCRATCH1
	.globl _SCRATCH0
	.globl _RADIOMUX
	.globl _RADIOFSTATADDR
	.globl _RADIOFSTATADDR1
	.globl _RADIOFSTATADDR0
	.globl _RADIOFDATAADDR
	.globl _RADIOFDATAADDR1
	.globl _RADIOFDATAADDR0
	.globl _OSCRUN
	.globl _OSCREADY
	.globl _OSCFORCERUN
	.globl _OSCCALIB
	.globl _MISCCTRL
	.globl _LPXOSCGM
	.globl _LPOSCREF
	.globl _LPOSCREF1
	.globl _LPOSCREF0
	.globl _LPOSCPER
	.globl _LPOSCPER1
	.globl _LPOSCPER0
	.globl _LPOSCKFILT
	.globl _LPOSCKFILT1
	.globl _LPOSCKFILT0
	.globl _LPOSCFREQ
	.globl _LPOSCFREQ1
	.globl _LPOSCFREQ0
	.globl _LPOSCCONFIG
	.globl _PINSEL
	.globl _PINCHGC
	.globl _PINCHGB
	.globl _PINCHGA
	.globl _PALTRADIO
	.globl _PALTC
	.globl _PALTB
	.globl _PALTA
	.globl _INTCHGC
	.globl _INTCHGB
	.globl _INTCHGA
	.globl _EXTIRQ
	.globl _GPIOENABLE
	.globl _ANALOGA
	.globl _FRCOSCREF
	.globl _FRCOSCREF1
	.globl _FRCOSCREF0
	.globl _FRCOSCPER
	.globl _FRCOSCPER1
	.globl _FRCOSCPER0
	.globl _FRCOSCKFILT
	.globl _FRCOSCKFILT1
	.globl _FRCOSCKFILT0
	.globl _FRCOSCFREQ
	.globl _FRCOSCFREQ1
	.globl _FRCOSCFREQ0
	.globl _FRCOSCCTRL
	.globl _FRCOSCCONFIG
	.globl _DMA1CONFIG
	.globl _DMA1ADDR
	.globl _DMA1ADDR1
	.globl _DMA1ADDR0
	.globl _DMA0CONFIG
	.globl _DMA0ADDR
	.globl _DMA0ADDR1
	.globl _DMA0ADDR0
	.globl _ADCTUNE2
	.globl _ADCTUNE1
	.globl _ADCTUNE0
	.globl _ADCCH3VAL
	.globl _ADCCH3VAL1
	.globl _ADCCH3VAL0
	.globl _ADCCH2VAL
	.globl _ADCCH2VAL1
	.globl _ADCCH2VAL0
	.globl _ADCCH1VAL
	.globl _ADCCH1VAL1
	.globl _ADCCH1VAL0
	.globl _ADCCH0VAL
	.globl _ADCCH0VAL1
	.globl _ADCCH0VAL0
	.globl _acquire_agc
	.globl _errors2
	.globl _errors
	.globl _bytes
	.globl _scr
	.globl _BER_TEST
	.globl _coldstart
	.globl _axradio_statuschange
	.globl _enable_radio_interrupt_in_mcu_pin
	.globl _disable_radio_interrupt_in_mcu_pin
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$ACC$0$0 == 0x00e0
_ACC	=	0x00e0
G$B$0$0 == 0x00f0
_B	=	0x00f0
G$DPH$0$0 == 0x0083
_DPH	=	0x0083
G$DPH1$0$0 == 0x0085
_DPH1	=	0x0085
G$DPL$0$0 == 0x0082
_DPL	=	0x0082
G$DPL1$0$0 == 0x0084
_DPL1	=	0x0084
G$DPTR0$0$0 == 0x8382
_DPTR0	=	0x8382
G$DPTR1$0$0 == 0x8584
_DPTR1	=	0x8584
G$DPS$0$0 == 0x0086
_DPS	=	0x0086
G$E2IE$0$0 == 0x00a0
_E2IE	=	0x00a0
G$E2IP$0$0 == 0x00c0
_E2IP	=	0x00c0
G$EIE$0$0 == 0x0098
_EIE	=	0x0098
G$EIP$0$0 == 0x00b0
_EIP	=	0x00b0
G$IE$0$0 == 0x00a8
_IE	=	0x00a8
G$IP$0$0 == 0x00b8
_IP	=	0x00b8
G$PCON$0$0 == 0x0087
_PCON	=	0x0087
G$PSW$0$0 == 0x00d0
_PSW	=	0x00d0
G$SP$0$0 == 0x0081
_SP	=	0x0081
G$XPAGE$0$0 == 0x00d9
_XPAGE	=	0x00d9
G$_XPAGE$0$0 == 0x00d9
__XPAGE	=	0x00d9
G$ADCCH0CONFIG$0$0 == 0x00ca
_ADCCH0CONFIG	=	0x00ca
G$ADCCH1CONFIG$0$0 == 0x00cb
_ADCCH1CONFIG	=	0x00cb
G$ADCCH2CONFIG$0$0 == 0x00d2
_ADCCH2CONFIG	=	0x00d2
G$ADCCH3CONFIG$0$0 == 0x00d3
_ADCCH3CONFIG	=	0x00d3
G$ADCCLKSRC$0$0 == 0x00d1
_ADCCLKSRC	=	0x00d1
G$ADCCONV$0$0 == 0x00c9
_ADCCONV	=	0x00c9
G$ANALOGCOMP$0$0 == 0x00e1
_ANALOGCOMP	=	0x00e1
G$CLKCON$0$0 == 0x00c6
_CLKCON	=	0x00c6
G$CLKSTAT$0$0 == 0x00c7
_CLKSTAT	=	0x00c7
G$CODECONFIG$0$0 == 0x0097
_CODECONFIG	=	0x0097
G$DBGLNKBUF$0$0 == 0x00e3
_DBGLNKBUF	=	0x00e3
G$DBGLNKSTAT$0$0 == 0x00e2
_DBGLNKSTAT	=	0x00e2
G$DIRA$0$0 == 0x0089
_DIRA	=	0x0089
G$DIRB$0$0 == 0x008a
_DIRB	=	0x008a
G$DIRC$0$0 == 0x008b
_DIRC	=	0x008b
G$DIRR$0$0 == 0x008e
_DIRR	=	0x008e
G$PINA$0$0 == 0x00c8
_PINA	=	0x00c8
G$PINB$0$0 == 0x00e8
_PINB	=	0x00e8
G$PINC$0$0 == 0x00f8
_PINC	=	0x00f8
G$PINR$0$0 == 0x008d
_PINR	=	0x008d
G$PORTA$0$0 == 0x0080
_PORTA	=	0x0080
G$PORTB$0$0 == 0x0088
_PORTB	=	0x0088
G$PORTC$0$0 == 0x0090
_PORTC	=	0x0090
G$PORTR$0$0 == 0x008c
_PORTR	=	0x008c
G$IC0CAPT0$0$0 == 0x00ce
_IC0CAPT0	=	0x00ce
G$IC0CAPT1$0$0 == 0x00cf
_IC0CAPT1	=	0x00cf
G$IC0CAPT$0$0 == 0xcfce
_IC0CAPT	=	0xcfce
G$IC0MODE$0$0 == 0x00cc
_IC0MODE	=	0x00cc
G$IC0STATUS$0$0 == 0x00cd
_IC0STATUS	=	0x00cd
G$IC1CAPT0$0$0 == 0x00d6
_IC1CAPT0	=	0x00d6
G$IC1CAPT1$0$0 == 0x00d7
_IC1CAPT1	=	0x00d7
G$IC1CAPT$0$0 == 0xd7d6
_IC1CAPT	=	0xd7d6
G$IC1MODE$0$0 == 0x00d4
_IC1MODE	=	0x00d4
G$IC1STATUS$0$0 == 0x00d5
_IC1STATUS	=	0x00d5
G$NVADDR0$0$0 == 0x0092
_NVADDR0	=	0x0092
G$NVADDR1$0$0 == 0x0093
_NVADDR1	=	0x0093
G$NVADDR$0$0 == 0x9392
_NVADDR	=	0x9392
G$NVDATA0$0$0 == 0x0094
_NVDATA0	=	0x0094
G$NVDATA1$0$0 == 0x0095
_NVDATA1	=	0x0095
G$NVDATA$0$0 == 0x9594
_NVDATA	=	0x9594
G$NVKEY$0$0 == 0x0096
_NVKEY	=	0x0096
G$NVSTATUS$0$0 == 0x0091
_NVSTATUS	=	0x0091
G$OC0COMP0$0$0 == 0x00bc
_OC0COMP0	=	0x00bc
G$OC0COMP1$0$0 == 0x00bd
_OC0COMP1	=	0x00bd
G$OC0COMP$0$0 == 0xbdbc
_OC0COMP	=	0xbdbc
G$OC0MODE$0$0 == 0x00b9
_OC0MODE	=	0x00b9
G$OC0PIN$0$0 == 0x00ba
_OC0PIN	=	0x00ba
G$OC0STATUS$0$0 == 0x00bb
_OC0STATUS	=	0x00bb
G$OC1COMP0$0$0 == 0x00c4
_OC1COMP0	=	0x00c4
G$OC1COMP1$0$0 == 0x00c5
_OC1COMP1	=	0x00c5
G$OC1COMP$0$0 == 0xc5c4
_OC1COMP	=	0xc5c4
G$OC1MODE$0$0 == 0x00c1
_OC1MODE	=	0x00c1
G$OC1PIN$0$0 == 0x00c2
_OC1PIN	=	0x00c2
G$OC1STATUS$0$0 == 0x00c3
_OC1STATUS	=	0x00c3
G$RADIOACC$0$0 == 0x00b1
_RADIOACC	=	0x00b1
G$RADIOADDR0$0$0 == 0x00b3
_RADIOADDR0	=	0x00b3
G$RADIOADDR1$0$0 == 0x00b2
_RADIOADDR1	=	0x00b2
G$RADIOADDR$0$0 == 0xb2b3
_RADIOADDR	=	0xb2b3
G$RADIODATA0$0$0 == 0x00b7
_RADIODATA0	=	0x00b7
G$RADIODATA1$0$0 == 0x00b6
_RADIODATA1	=	0x00b6
G$RADIODATA2$0$0 == 0x00b5
_RADIODATA2	=	0x00b5
G$RADIODATA3$0$0 == 0x00b4
_RADIODATA3	=	0x00b4
G$RADIODATA$0$0 == 0xb4b5b6b7
_RADIODATA	=	0xb4b5b6b7
G$RADIOSTAT0$0$0 == 0x00be
_RADIOSTAT0	=	0x00be
G$RADIOSTAT1$0$0 == 0x00bf
_RADIOSTAT1	=	0x00bf
G$RADIOSTAT$0$0 == 0xbfbe
_RADIOSTAT	=	0xbfbe
G$SPCLKSRC$0$0 == 0x00df
_SPCLKSRC	=	0x00df
G$SPMODE$0$0 == 0x00dc
_SPMODE	=	0x00dc
G$SPSHREG$0$0 == 0x00de
_SPSHREG	=	0x00de
G$SPSTATUS$0$0 == 0x00dd
_SPSTATUS	=	0x00dd
G$T0CLKSRC$0$0 == 0x009a
_T0CLKSRC	=	0x009a
G$T0CNT0$0$0 == 0x009c
_T0CNT0	=	0x009c
G$T0CNT1$0$0 == 0x009d
_T0CNT1	=	0x009d
G$T0CNT$0$0 == 0x9d9c
_T0CNT	=	0x9d9c
G$T0MODE$0$0 == 0x0099
_T0MODE	=	0x0099
G$T0PERIOD0$0$0 == 0x009e
_T0PERIOD0	=	0x009e
G$T0PERIOD1$0$0 == 0x009f
_T0PERIOD1	=	0x009f
G$T0PERIOD$0$0 == 0x9f9e
_T0PERIOD	=	0x9f9e
G$T0STATUS$0$0 == 0x009b
_T0STATUS	=	0x009b
G$T1CLKSRC$0$0 == 0x00a2
_T1CLKSRC	=	0x00a2
G$T1CNT0$0$0 == 0x00a4
_T1CNT0	=	0x00a4
G$T1CNT1$0$0 == 0x00a5
_T1CNT1	=	0x00a5
G$T1CNT$0$0 == 0xa5a4
_T1CNT	=	0xa5a4
G$T1MODE$0$0 == 0x00a1
_T1MODE	=	0x00a1
G$T1PERIOD0$0$0 == 0x00a6
_T1PERIOD0	=	0x00a6
G$T1PERIOD1$0$0 == 0x00a7
_T1PERIOD1	=	0x00a7
G$T1PERIOD$0$0 == 0xa7a6
_T1PERIOD	=	0xa7a6
G$T1STATUS$0$0 == 0x00a3
_T1STATUS	=	0x00a3
G$T2CLKSRC$0$0 == 0x00aa
_T2CLKSRC	=	0x00aa
G$T2CNT0$0$0 == 0x00ac
_T2CNT0	=	0x00ac
G$T2CNT1$0$0 == 0x00ad
_T2CNT1	=	0x00ad
G$T2CNT$0$0 == 0xadac
_T2CNT	=	0xadac
G$T2MODE$0$0 == 0x00a9
_T2MODE	=	0x00a9
G$T2PERIOD0$0$0 == 0x00ae
_T2PERIOD0	=	0x00ae
G$T2PERIOD1$0$0 == 0x00af
_T2PERIOD1	=	0x00af
G$T2PERIOD$0$0 == 0xafae
_T2PERIOD	=	0xafae
G$T2STATUS$0$0 == 0x00ab
_T2STATUS	=	0x00ab
G$U0CTRL$0$0 == 0x00e4
_U0CTRL	=	0x00e4
G$U0MODE$0$0 == 0x00e7
_U0MODE	=	0x00e7
G$U0SHREG$0$0 == 0x00e6
_U0SHREG	=	0x00e6
G$U0STATUS$0$0 == 0x00e5
_U0STATUS	=	0x00e5
G$U1CTRL$0$0 == 0x00ec
_U1CTRL	=	0x00ec
G$U1MODE$0$0 == 0x00ef
_U1MODE	=	0x00ef
G$U1SHREG$0$0 == 0x00ee
_U1SHREG	=	0x00ee
G$U1STATUS$0$0 == 0x00ed
_U1STATUS	=	0x00ed
G$WDTCFG$0$0 == 0x00da
_WDTCFG	=	0x00da
G$WDTRESET$0$0 == 0x00db
_WDTRESET	=	0x00db
G$WTCFGA$0$0 == 0x00f1
_WTCFGA	=	0x00f1
G$WTCFGB$0$0 == 0x00f9
_WTCFGB	=	0x00f9
G$WTCNTA0$0$0 == 0x00f2
_WTCNTA0	=	0x00f2
G$WTCNTA1$0$0 == 0x00f3
_WTCNTA1	=	0x00f3
G$WTCNTA$0$0 == 0xf3f2
_WTCNTA	=	0xf3f2
G$WTCNTB0$0$0 == 0x00fa
_WTCNTB0	=	0x00fa
G$WTCNTB1$0$0 == 0x00fb
_WTCNTB1	=	0x00fb
G$WTCNTB$0$0 == 0xfbfa
_WTCNTB	=	0xfbfa
G$WTCNTR1$0$0 == 0x00eb
_WTCNTR1	=	0x00eb
G$WTEVTA0$0$0 == 0x00f4
_WTEVTA0	=	0x00f4
G$WTEVTA1$0$0 == 0x00f5
_WTEVTA1	=	0x00f5
G$WTEVTA$0$0 == 0xf5f4
_WTEVTA	=	0xf5f4
G$WTEVTB0$0$0 == 0x00f6
_WTEVTB0	=	0x00f6
G$WTEVTB1$0$0 == 0x00f7
_WTEVTB1	=	0x00f7
G$WTEVTB$0$0 == 0xf7f6
_WTEVTB	=	0xf7f6
G$WTEVTC0$0$0 == 0x00fc
_WTEVTC0	=	0x00fc
G$WTEVTC1$0$0 == 0x00fd
_WTEVTC1	=	0x00fd
G$WTEVTC$0$0 == 0xfdfc
_WTEVTC	=	0xfdfc
G$WTEVTD0$0$0 == 0x00fe
_WTEVTD0	=	0x00fe
G$WTEVTD1$0$0 == 0x00ff
_WTEVTD1	=	0x00ff
G$WTEVTD$0$0 == 0xfffe
_WTEVTD	=	0xfffe
G$WTIRQEN$0$0 == 0x00e9
_WTIRQEN	=	0x00e9
G$WTSTAT$0$0 == 0x00ea
_WTSTAT	=	0x00ea
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$ACC_0$0$0 == 0x00e0
_ACC_0	=	0x00e0
G$ACC_1$0$0 == 0x00e1
_ACC_1	=	0x00e1
G$ACC_2$0$0 == 0x00e2
_ACC_2	=	0x00e2
G$ACC_3$0$0 == 0x00e3
_ACC_3	=	0x00e3
G$ACC_4$0$0 == 0x00e4
_ACC_4	=	0x00e4
G$ACC_5$0$0 == 0x00e5
_ACC_5	=	0x00e5
G$ACC_6$0$0 == 0x00e6
_ACC_6	=	0x00e6
G$ACC_7$0$0 == 0x00e7
_ACC_7	=	0x00e7
G$B_0$0$0 == 0x00f0
_B_0	=	0x00f0
G$B_1$0$0 == 0x00f1
_B_1	=	0x00f1
G$B_2$0$0 == 0x00f2
_B_2	=	0x00f2
G$B_3$0$0 == 0x00f3
_B_3	=	0x00f3
G$B_4$0$0 == 0x00f4
_B_4	=	0x00f4
G$B_5$0$0 == 0x00f5
_B_5	=	0x00f5
G$B_6$0$0 == 0x00f6
_B_6	=	0x00f6
G$B_7$0$0 == 0x00f7
_B_7	=	0x00f7
G$E2IE_0$0$0 == 0x00a0
_E2IE_0	=	0x00a0
G$E2IE_1$0$0 == 0x00a1
_E2IE_1	=	0x00a1
G$E2IE_2$0$0 == 0x00a2
_E2IE_2	=	0x00a2
G$E2IE_3$0$0 == 0x00a3
_E2IE_3	=	0x00a3
G$E2IE_4$0$0 == 0x00a4
_E2IE_4	=	0x00a4
G$E2IE_5$0$0 == 0x00a5
_E2IE_5	=	0x00a5
G$E2IE_6$0$0 == 0x00a6
_E2IE_6	=	0x00a6
G$E2IE_7$0$0 == 0x00a7
_E2IE_7	=	0x00a7
G$E2IP_0$0$0 == 0x00c0
_E2IP_0	=	0x00c0
G$E2IP_1$0$0 == 0x00c1
_E2IP_1	=	0x00c1
G$E2IP_2$0$0 == 0x00c2
_E2IP_2	=	0x00c2
G$E2IP_3$0$0 == 0x00c3
_E2IP_3	=	0x00c3
G$E2IP_4$0$0 == 0x00c4
_E2IP_4	=	0x00c4
G$E2IP_5$0$0 == 0x00c5
_E2IP_5	=	0x00c5
G$E2IP_6$0$0 == 0x00c6
_E2IP_6	=	0x00c6
G$E2IP_7$0$0 == 0x00c7
_E2IP_7	=	0x00c7
G$EIE_0$0$0 == 0x0098
_EIE_0	=	0x0098
G$EIE_1$0$0 == 0x0099
_EIE_1	=	0x0099
G$EIE_2$0$0 == 0x009a
_EIE_2	=	0x009a
G$EIE_3$0$0 == 0x009b
_EIE_3	=	0x009b
G$EIE_4$0$0 == 0x009c
_EIE_4	=	0x009c
G$EIE_5$0$0 == 0x009d
_EIE_5	=	0x009d
G$EIE_6$0$0 == 0x009e
_EIE_6	=	0x009e
G$EIE_7$0$0 == 0x009f
_EIE_7	=	0x009f
G$EIP_0$0$0 == 0x00b0
_EIP_0	=	0x00b0
G$EIP_1$0$0 == 0x00b1
_EIP_1	=	0x00b1
G$EIP_2$0$0 == 0x00b2
_EIP_2	=	0x00b2
G$EIP_3$0$0 == 0x00b3
_EIP_3	=	0x00b3
G$EIP_4$0$0 == 0x00b4
_EIP_4	=	0x00b4
G$EIP_5$0$0 == 0x00b5
_EIP_5	=	0x00b5
G$EIP_6$0$0 == 0x00b6
_EIP_6	=	0x00b6
G$EIP_7$0$0 == 0x00b7
_EIP_7	=	0x00b7
G$IE_0$0$0 == 0x00a8
_IE_0	=	0x00a8
G$IE_1$0$0 == 0x00a9
_IE_1	=	0x00a9
G$IE_2$0$0 == 0x00aa
_IE_2	=	0x00aa
G$IE_3$0$0 == 0x00ab
_IE_3	=	0x00ab
G$IE_4$0$0 == 0x00ac
_IE_4	=	0x00ac
G$IE_5$0$0 == 0x00ad
_IE_5	=	0x00ad
G$IE_6$0$0 == 0x00ae
_IE_6	=	0x00ae
G$IE_7$0$0 == 0x00af
_IE_7	=	0x00af
G$EA$0$0 == 0x00af
_EA	=	0x00af
G$IP_0$0$0 == 0x00b8
_IP_0	=	0x00b8
G$IP_1$0$0 == 0x00b9
_IP_1	=	0x00b9
G$IP_2$0$0 == 0x00ba
_IP_2	=	0x00ba
G$IP_3$0$0 == 0x00bb
_IP_3	=	0x00bb
G$IP_4$0$0 == 0x00bc
_IP_4	=	0x00bc
G$IP_5$0$0 == 0x00bd
_IP_5	=	0x00bd
G$IP_6$0$0 == 0x00be
_IP_6	=	0x00be
G$IP_7$0$0 == 0x00bf
_IP_7	=	0x00bf
G$P$0$0 == 0x00d0
_P	=	0x00d0
G$F1$0$0 == 0x00d1
_F1	=	0x00d1
G$OV$0$0 == 0x00d2
_OV	=	0x00d2
G$RS0$0$0 == 0x00d3
_RS0	=	0x00d3
G$RS1$0$0 == 0x00d4
_RS1	=	0x00d4
G$F0$0$0 == 0x00d5
_F0	=	0x00d5
G$AC$0$0 == 0x00d6
_AC	=	0x00d6
G$CY$0$0 == 0x00d7
_CY	=	0x00d7
G$PINA_0$0$0 == 0x00c8
_PINA_0	=	0x00c8
G$PINA_1$0$0 == 0x00c9
_PINA_1	=	0x00c9
G$PINA_2$0$0 == 0x00ca
_PINA_2	=	0x00ca
G$PINA_3$0$0 == 0x00cb
_PINA_3	=	0x00cb
G$PINA_4$0$0 == 0x00cc
_PINA_4	=	0x00cc
G$PINA_5$0$0 == 0x00cd
_PINA_5	=	0x00cd
G$PINA_6$0$0 == 0x00ce
_PINA_6	=	0x00ce
G$PINA_7$0$0 == 0x00cf
_PINA_7	=	0x00cf
G$PINB_0$0$0 == 0x00e8
_PINB_0	=	0x00e8
G$PINB_1$0$0 == 0x00e9
_PINB_1	=	0x00e9
G$PINB_2$0$0 == 0x00ea
_PINB_2	=	0x00ea
G$PINB_3$0$0 == 0x00eb
_PINB_3	=	0x00eb
G$PINB_4$0$0 == 0x00ec
_PINB_4	=	0x00ec
G$PINB_5$0$0 == 0x00ed
_PINB_5	=	0x00ed
G$PINB_6$0$0 == 0x00ee
_PINB_6	=	0x00ee
G$PINB_7$0$0 == 0x00ef
_PINB_7	=	0x00ef
G$PINC_0$0$0 == 0x00f8
_PINC_0	=	0x00f8
G$PINC_1$0$0 == 0x00f9
_PINC_1	=	0x00f9
G$PINC_2$0$0 == 0x00fa
_PINC_2	=	0x00fa
G$PINC_3$0$0 == 0x00fb
_PINC_3	=	0x00fb
G$PINC_4$0$0 == 0x00fc
_PINC_4	=	0x00fc
G$PINC_5$0$0 == 0x00fd
_PINC_5	=	0x00fd
G$PINC_6$0$0 == 0x00fe
_PINC_6	=	0x00fe
G$PINC_7$0$0 == 0x00ff
_PINC_7	=	0x00ff
G$PORTA_0$0$0 == 0x0080
_PORTA_0	=	0x0080
G$PORTA_1$0$0 == 0x0081
_PORTA_1	=	0x0081
G$PORTA_2$0$0 == 0x0082
_PORTA_2	=	0x0082
G$PORTA_3$0$0 == 0x0083
_PORTA_3	=	0x0083
G$PORTA_4$0$0 == 0x0084
_PORTA_4	=	0x0084
G$PORTA_5$0$0 == 0x0085
_PORTA_5	=	0x0085
G$PORTA_6$0$0 == 0x0086
_PORTA_6	=	0x0086
G$PORTA_7$0$0 == 0x0087
_PORTA_7	=	0x0087
G$PORTB_0$0$0 == 0x0088
_PORTB_0	=	0x0088
G$PORTB_1$0$0 == 0x0089
_PORTB_1	=	0x0089
G$PORTB_2$0$0 == 0x008a
_PORTB_2	=	0x008a
G$PORTB_3$0$0 == 0x008b
_PORTB_3	=	0x008b
G$PORTB_4$0$0 == 0x008c
_PORTB_4	=	0x008c
G$PORTB_5$0$0 == 0x008d
_PORTB_5	=	0x008d
G$PORTB_6$0$0 == 0x008e
_PORTB_6	=	0x008e
G$PORTB_7$0$0 == 0x008f
_PORTB_7	=	0x008f
G$PORTC_0$0$0 == 0x0090
_PORTC_0	=	0x0090
G$PORTC_1$0$0 == 0x0091
_PORTC_1	=	0x0091
G$PORTC_2$0$0 == 0x0092
_PORTC_2	=	0x0092
G$PORTC_3$0$0 == 0x0093
_PORTC_3	=	0x0093
G$PORTC_4$0$0 == 0x0094
_PORTC_4	=	0x0094
G$PORTC_5$0$0 == 0x0095
_PORTC_5	=	0x0095
G$PORTC_6$0$0 == 0x0096
_PORTC_6	=	0x0096
G$PORTC_7$0$0 == 0x0097
_PORTC_7	=	0x0097
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
G$coldstart$0$0==.
_coldstart::
	.ds 1
G$BER_TEST$0$0==.
_BER_TEST::
	.ds 1
G$scr$0$0==.
_scr::
	.ds 4
G$bytes$0$0==.
_bytes::
	.ds 4
G$errors$0$0==.
_errors::
	.ds 4
G$errors2$0$0==.
_errors2::
	.ds 4
G$acquire_agc$0$0==.
_acquire_agc::
	.ds 1
Lmain.process_ber$databyte$6$323==.
_process_ber_databyte_6_323:
	.ds 1
Lmain.process_ber$sloc0$1$0==.
_process_ber_sloc0_1_0:
	.ds 1
Lmain.process_ber$sloc1$1$0==.
_process_ber_sloc1_1_0:
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
Lmain._sdcc_external_startup$sloc0$1$0==.
__sdcc_external_startup_sloc0_1_0:
	.ds 1
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
G$ADCCH0VAL0$0$0 == 0x7020
_ADCCH0VAL0	=	0x7020
G$ADCCH0VAL1$0$0 == 0x7021
_ADCCH0VAL1	=	0x7021
G$ADCCH0VAL$0$0 == 0x7020
_ADCCH0VAL	=	0x7020
G$ADCCH1VAL0$0$0 == 0x7022
_ADCCH1VAL0	=	0x7022
G$ADCCH1VAL1$0$0 == 0x7023
_ADCCH1VAL1	=	0x7023
G$ADCCH1VAL$0$0 == 0x7022
_ADCCH1VAL	=	0x7022
G$ADCCH2VAL0$0$0 == 0x7024
_ADCCH2VAL0	=	0x7024
G$ADCCH2VAL1$0$0 == 0x7025
_ADCCH2VAL1	=	0x7025
G$ADCCH2VAL$0$0 == 0x7024
_ADCCH2VAL	=	0x7024
G$ADCCH3VAL0$0$0 == 0x7026
_ADCCH3VAL0	=	0x7026
G$ADCCH3VAL1$0$0 == 0x7027
_ADCCH3VAL1	=	0x7027
G$ADCCH3VAL$0$0 == 0x7026
_ADCCH3VAL	=	0x7026
G$ADCTUNE0$0$0 == 0x7028
_ADCTUNE0	=	0x7028
G$ADCTUNE1$0$0 == 0x7029
_ADCTUNE1	=	0x7029
G$ADCTUNE2$0$0 == 0x702a
_ADCTUNE2	=	0x702a
G$DMA0ADDR0$0$0 == 0x7010
_DMA0ADDR0	=	0x7010
G$DMA0ADDR1$0$0 == 0x7011
_DMA0ADDR1	=	0x7011
G$DMA0ADDR$0$0 == 0x7010
_DMA0ADDR	=	0x7010
G$DMA0CONFIG$0$0 == 0x7014
_DMA0CONFIG	=	0x7014
G$DMA1ADDR0$0$0 == 0x7012
_DMA1ADDR0	=	0x7012
G$DMA1ADDR1$0$0 == 0x7013
_DMA1ADDR1	=	0x7013
G$DMA1ADDR$0$0 == 0x7012
_DMA1ADDR	=	0x7012
G$DMA1CONFIG$0$0 == 0x7015
_DMA1CONFIG	=	0x7015
G$FRCOSCCONFIG$0$0 == 0x7070
_FRCOSCCONFIG	=	0x7070
G$FRCOSCCTRL$0$0 == 0x7071
_FRCOSCCTRL	=	0x7071
G$FRCOSCFREQ0$0$0 == 0x7076
_FRCOSCFREQ0	=	0x7076
G$FRCOSCFREQ1$0$0 == 0x7077
_FRCOSCFREQ1	=	0x7077
G$FRCOSCFREQ$0$0 == 0x7076
_FRCOSCFREQ	=	0x7076
G$FRCOSCKFILT0$0$0 == 0x7072
_FRCOSCKFILT0	=	0x7072
G$FRCOSCKFILT1$0$0 == 0x7073
_FRCOSCKFILT1	=	0x7073
G$FRCOSCKFILT$0$0 == 0x7072
_FRCOSCKFILT	=	0x7072
G$FRCOSCPER0$0$0 == 0x7078
_FRCOSCPER0	=	0x7078
G$FRCOSCPER1$0$0 == 0x7079
_FRCOSCPER1	=	0x7079
G$FRCOSCPER$0$0 == 0x7078
_FRCOSCPER	=	0x7078
G$FRCOSCREF0$0$0 == 0x7074
_FRCOSCREF0	=	0x7074
G$FRCOSCREF1$0$0 == 0x7075
_FRCOSCREF1	=	0x7075
G$FRCOSCREF$0$0 == 0x7074
_FRCOSCREF	=	0x7074
G$ANALOGA$0$0 == 0x7007
_ANALOGA	=	0x7007
G$GPIOENABLE$0$0 == 0x700c
_GPIOENABLE	=	0x700c
G$EXTIRQ$0$0 == 0x7003
_EXTIRQ	=	0x7003
G$INTCHGA$0$0 == 0x7000
_INTCHGA	=	0x7000
G$INTCHGB$0$0 == 0x7001
_INTCHGB	=	0x7001
G$INTCHGC$0$0 == 0x7002
_INTCHGC	=	0x7002
G$PALTA$0$0 == 0x7008
_PALTA	=	0x7008
G$PALTB$0$0 == 0x7009
_PALTB	=	0x7009
G$PALTC$0$0 == 0x700a
_PALTC	=	0x700a
G$PALTRADIO$0$0 == 0x7046
_PALTRADIO	=	0x7046
G$PINCHGA$0$0 == 0x7004
_PINCHGA	=	0x7004
G$PINCHGB$0$0 == 0x7005
_PINCHGB	=	0x7005
G$PINCHGC$0$0 == 0x7006
_PINCHGC	=	0x7006
G$PINSEL$0$0 == 0x700b
_PINSEL	=	0x700b
G$LPOSCCONFIG$0$0 == 0x7060
_LPOSCCONFIG	=	0x7060
G$LPOSCFREQ0$0$0 == 0x7066
_LPOSCFREQ0	=	0x7066
G$LPOSCFREQ1$0$0 == 0x7067
_LPOSCFREQ1	=	0x7067
G$LPOSCFREQ$0$0 == 0x7066
_LPOSCFREQ	=	0x7066
G$LPOSCKFILT0$0$0 == 0x7062
_LPOSCKFILT0	=	0x7062
G$LPOSCKFILT1$0$0 == 0x7063
_LPOSCKFILT1	=	0x7063
G$LPOSCKFILT$0$0 == 0x7062
_LPOSCKFILT	=	0x7062
G$LPOSCPER0$0$0 == 0x7068
_LPOSCPER0	=	0x7068
G$LPOSCPER1$0$0 == 0x7069
_LPOSCPER1	=	0x7069
G$LPOSCPER$0$0 == 0x7068
_LPOSCPER	=	0x7068
G$LPOSCREF0$0$0 == 0x7064
_LPOSCREF0	=	0x7064
G$LPOSCREF1$0$0 == 0x7065
_LPOSCREF1	=	0x7065
G$LPOSCREF$0$0 == 0x7064
_LPOSCREF	=	0x7064
G$LPXOSCGM$0$0 == 0x7054
_LPXOSCGM	=	0x7054
G$MISCCTRL$0$0 == 0x7f01
_MISCCTRL	=	0x7f01
G$OSCCALIB$0$0 == 0x7053
_OSCCALIB	=	0x7053
G$OSCFORCERUN$0$0 == 0x7050
_OSCFORCERUN	=	0x7050
G$OSCREADY$0$0 == 0x7052
_OSCREADY	=	0x7052
G$OSCRUN$0$0 == 0x7051
_OSCRUN	=	0x7051
G$RADIOFDATAADDR0$0$0 == 0x7040
_RADIOFDATAADDR0	=	0x7040
G$RADIOFDATAADDR1$0$0 == 0x7041
_RADIOFDATAADDR1	=	0x7041
G$RADIOFDATAADDR$0$0 == 0x7040
_RADIOFDATAADDR	=	0x7040
G$RADIOFSTATADDR0$0$0 == 0x7042
_RADIOFSTATADDR0	=	0x7042
G$RADIOFSTATADDR1$0$0 == 0x7043
_RADIOFSTATADDR1	=	0x7043
G$RADIOFSTATADDR$0$0 == 0x7042
_RADIOFSTATADDR	=	0x7042
G$RADIOMUX$0$0 == 0x7044
_RADIOMUX	=	0x7044
G$SCRATCH0$0$0 == 0x7084
_SCRATCH0	=	0x7084
G$SCRATCH1$0$0 == 0x7085
_SCRATCH1	=	0x7085
G$SCRATCH2$0$0 == 0x7086
_SCRATCH2	=	0x7086
G$SCRATCH3$0$0 == 0x7087
_SCRATCH3	=	0x7087
G$SILICONREV$0$0 == 0x7f00
_SILICONREV	=	0x7f00
G$XTALAMPL$0$0 == 0x7f19
_XTALAMPL	=	0x7f19
G$XTALOSC$0$0 == 0x7f18
_XTALOSC	=	0x7f18
G$XTALREADY$0$0 == 0x7f1a
_XTALREADY	=	0x7f1a
Fmain$flash_deviceid$0$0 == 0xfc06
_flash_deviceid	=	0xfc06
Fmain$flash_calsector$0$0 == 0xfc00
_flash_calsector	=	0xfc00
G$txdata$0$0==.
_txdata::
	.ds 8
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	reti
	.ds	7
	ljmp	_wtimer_irq
	.ds	5
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_axradio_isr
	.ds	5
	reti
	.ds	7
	ljmp	_pwrmgmt_irq
	.ds	5
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_uart0_irq
	.ds	5
	ljmp	_uart1_irq
	.ds	5
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	reti
	.ds	7
	ljmp	_dbglink_irq
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	C$main.c$66$1$414 ==.
;	main.c:66: uint8_t __data coldstart = 1; /* caution: initialization with 1 is necessary! Variables are initialized upon _sdcc_external_startup returning 0 -> the coldstart value returned from _sdcc_external startup does not survive in the coldstart case */
	mov	_coldstart,#0x01
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'pwrmgmt_irq'
;------------------------------------------------------------
;pc                        Allocated to registers r7 
;------------------------------------------------------------
	Fmain$pwrmgmt_irq$0$0 ==.
	C$main.c$146$0$0 ==.
;	main.c:146: static void pwrmgmt_irq(void) __interrupt(INT_POWERMGMT)
;	-----------------------------------------
;	 function pwrmgmt_irq
;	-----------------------------------------
_pwrmgmt_irq:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	push	acc
	push	dpl
	push	dph
	push	ar7
	push	psw
	mov	psw,#0x00
	C$main.c$148$1$0 ==.
;	main.c:148: uint8_t pc = PCON;
	C$main.c$150$1$311 ==.
;	main.c:150: if (!(pc & 0x80))
	mov	a,_PCON
	mov	r7,a
	jb	acc.7,00102$
	C$main.c$151$1$311 ==.
;	main.c:151: return;
	sjmp	00106$
00102$:
	C$main.c$153$1$311 ==.
;	main.c:153: GPIOENABLE = 0;
	mov	dptr,#_GPIOENABLE
	clr	a
	movx	@dptr,a
	C$main.c$154$1$311 ==.
;	main.c:154: IE = EIE = E2IE = 0;
;	1-genFromRTrack replaced	mov	_E2IE,#0x00
	mov	_E2IE,a
;	1-genFromRTrack replaced	mov	_EIE,#0x00
	mov	_EIE,a
;	1-genFromRTrack replaced	mov	_IE,#0x00
	mov	_IE,a
00104$:
	C$main.c$157$1$311 ==.
;	main.c:157: PCON |= 0x01;
	orl	_PCON,#0x01
	sjmp	00104$
00106$:
	pop	psw
	pop	ar7
	pop	dph
	pop	dpl
	pop	acc
	C$main.c$158$1$311 ==.
	XFmain$pwrmgmt_irq$0$0 ==.
	reti
;	eliminated unneeded push/pop b
;------------------------------------------------------------
;Allocation info for local variables in function 'correct_ber'
;------------------------------------------------------------
;x                         Allocated to registers 
;------------------------------------------------------------
	Fmain$correct_ber$0$0 ==.
	C$main.c$161$1$311 ==.
;	main.c:161: static void correct_ber(void)
;	-----------------------------------------
;	 function correct_ber
;	-----------------------------------------
_correct_ber:
	C$main.c$180$1$313 ==.
;	main.c:180: }
	C$main.c$181$1$313 ==.
	XFmain$correct_ber$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'process_ber'
;------------------------------------------------------------
;st                        Allocated to registers r6 r7 
;fourfsk                   Allocated to registers r5 
;i                         Allocated to registers r3 
;p                         Allocated to registers r6 r7 
;databyte                  Allocated with name '_process_ber_databyte_6_323'
;databyte                  Allocated to registers r4 
;databyte                  Allocated to registers 
;databyte                  Allocated to registers 
;databyte                  Allocated to registers 
;sloc0                     Allocated with name '_process_ber_sloc0_1_0'
;sloc1                     Allocated with name '_process_ber_sloc1_1_0'
;------------------------------------------------------------
	Fmain$process_ber$0$0 ==.
	C$main.c$183$1$313 ==.
;	main.c:183: static void process_ber(struct axradio_status __xdata *st)
;	-----------------------------------------
;	 function process_ber
;	-----------------------------------------
_process_ber:
	mov	r6,dpl
	mov	r7,dph
	C$main.c$185$1$317 ==.
;	main.c:185: uint8_t fourfsk = axradio_check_fourfsk_modulation();
	push	ar7
	push	ar6
	lcall	_axradio_check_fourfsk_modulation
	mov	r5,dpl
	pop	ar6
	pop	ar7
	C$main.c$187$2$318 ==.
;	main.c:187: uint8_t i = st->u.rx.pktlen;
	mov	a,#0x06
	add	a,r6
	mov	r6,a
	clr	a
	addc	a,r7
	mov	r7,a
	mov	a,#0x18
	add	a,r6
	mov	dpl,a
	clr	a
	addc	a,r7
	mov	dph,a
	movx	a,@dptr
	mov	r3,a
	inc	dptr
	movx	a,@dptr
	C$main.c$188$2$318 ==.
;	main.c:188: bytes -= i;
	mov	ar0,r3
	clr	a
	mov	r1,a
	mov	r2,a
	mov	r4,a
	mov	a,_bytes
	clr	c
	subb	a,r0
	mov	_bytes,a
	mov	a,(_bytes + 1)
	subb	a,r1
	mov	(_bytes + 1),a
	mov	a,(_bytes + 2)
	subb	a,r2
	mov	(_bytes + 2),a
	mov	a,(_bytes + 3)
	subb	a,r4
	mov	(_bytes + 3),a
	C$main.c$189$2$318 ==.
;	main.c:189: acquire_agc = (0 > (int32_t)bytes);
	mov	r0,_bytes
	mov	r1,(_bytes + 1)
	mov	r2,(_bytes + 2)
	mov	a,(_bytes + 3)
	mov	r4,a
	rlc	a
	clr	a
	rlc	a
	C$main.c$191$2$318 ==.
;	main.c:191: if (acquire_agc)
	mov	_acquire_agc,a
	jz	00102$
	C$main.c$193$3$319 ==.
;	main.c:193: i += (uint8_t)bytes;
	mov	a,_bytes
	mov	r4,a
	add	a,r3
	mov	r3,a
	C$main.c$194$3$319 ==.
;	main.c:194: bytes = 0;
	clr	a
	mov	_bytes,a
	mov	(_bytes + 1),a
	mov	(_bytes + 2),a
	mov	(_bytes + 3),a
00102$:
	C$main.c$197$2$318 ==.
;	main.c:197: if (i)
	mov	a,r3
	jnz	00169$
	ljmp	00126$
00169$:
	C$main.c$199$3$320 ==.
;	main.c:199: const uint8_t __xdata *p = st->u.rx.pktdata;
	mov	a,#0x16
	add	a,r6
	mov	dpl,a
	clr	a
	addc	a,r7
	mov	dph,a
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	r7,a
	C$main.c$203$4$321 ==.
;	main.c:203: if (fourfsk)
	mov	a,r5
	jz	00144$
	C$main.c$205$1$317 ==.
;	main.c:205: do
	mov	_process_ber_sloc1_1_0,r6
	mov	(_process_ber_sloc1_1_0 + 1),r7
	mov	_process_ber_sloc0_1_0,r3
00104$:
	C$main.c$207$6$323 ==.
;	main.c:207: uint8_t databyte = *p++;
	mov	dpl,_process_ber_sloc1_1_0
	mov	dph,(_process_ber_sloc1_1_0 + 1)
	movx	a,@dptr
	mov	_process_ber_databyte_6_323,a
	inc	dptr
	mov	_process_ber_sloc1_1_0,dpl
	mov	(_process_ber_sloc1_1_0 + 1),dph
	C$main.c$209$6$323 ==.
;	main.c:209: errors2 += hweight8(databyte ^ 0x87);
	mov	a,#0x87
	xrl	a,_process_ber_databyte_6_323
	mov	dpl,a
	lcall	_hweight8
	mov	r0,dpl
	clr	a
	mov	r1,a
	mov	r2,a
	mov	r5,a
	mov	a,r0
	add	a,_errors2
	mov	_errors2,a
	mov	a,r1
	addc	a,(_errors2 + 1)
	mov	(_errors2 + 1),a
	mov	a,r2
	addc	a,(_errors2 + 2)
	mov	(_errors2 + 2),a
	mov	a,r5
	addc	a,(_errors2 + 3)
	mov	(_errors2 + 3),a
	C$main.c$210$6$323 ==.
;	main.c:210: errors += hweight8(databyte ^ 0xe1);
	mov	a,#0xe1
	xrl	a,_process_ber_databyte_6_323
	mov	dpl,a
	lcall	_hweight8
	mov	r5,dpl
	mov	ar1,r5
	clr	a
	mov	r2,a
	mov	r4,a
	mov	r5,a
	mov	a,r1
	add	a,_errors
	mov	_errors,a
	mov	a,r2
	addc	a,(_errors + 1)
	mov	(_errors + 1),a
	mov	a,r4
	addc	a,(_errors + 2)
	mov	(_errors + 2),a
	mov	a,r5
	addc	a,(_errors + 3)
	mov	(_errors + 3),a
	C$main.c$212$5$322 ==.
;	main.c:212: while (--i);
	djnz	_process_ber_sloc0_1_0,00104$
	C$main.c$214$5$322 ==.
;	main.c:214: break;
	C$main.c$217$1$317 ==.
;	main.c:217: do
	sjmp	00126$
00144$:
	mov	ar5,r3
00109$:
	C$main.c$219$5$324 ==.
;	main.c:219: uint8_t databyte = *p++;
	mov	dpl,r6
	mov	dph,r7
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	mov	r6,dpl
	mov	r7,dph
	C$main.c$220$5$324 ==.
;	main.c:220: errors += hweight8(databyte ^ 0x55);
	mov	a,#0x55
	xrl	a,r4
	mov	dpl,a
	lcall	_hweight8
	mov	r4,dpl
	mov	ar1,r4
	clr	a
	mov	r2,a
	mov	r3,a
	mov	r4,a
	mov	a,r1
	add	a,_errors
	mov	_errors,a
	mov	a,r2
	addc	a,(_errors + 1)
	mov	(_errors + 1),a
	mov	a,r3
	addc	a,(_errors + 2)
	mov	(_errors + 2),a
	mov	a,r4
	addc	a,(_errors + 3)
	mov	(_errors + 3),a
	C$main.c$222$4$321 ==.
;	main.c:222: while (--i);
	djnz	r5,00109$
	C$main.c$274$2$318 ==.
;	main.c:274: }
00126$:
	C$main.c$278$1$317 ==.
;	main.c:278: if (!acquire_agc)
	mov	a,_acquire_agc
	C$main.c$279$1$317 ==.
;	main.c:279: return;
	jz	00138$
	C$main.c$282$1$317 ==.
;	main.c:282: if (errors > (((uint32_t)NUMBYTES) << 2))
	clr	c
	mov	a,#0x88
	subb	a,_errors
	mov	a,#0x13
	subb	a,(_errors + 1)
	clr	a
	subb	a,(_errors + 2)
	clr	a
	subb	a,(_errors + 3)
	jnc	00136$
	C$main.c$283$1$317 ==.
;	main.c:283: errors = (((uint32_t)NUMBYTES) << 3) - errors;
	mov	a,#0x10
	clr	c
	subb	a,_errors
	mov	_errors,a
	mov	a,#0x27
	subb	a,(_errors + 1)
	mov	(_errors + 1),a
	clr	a
	subb	a,(_errors + 2)
	mov	(_errors + 2),a
	clr	a
	subb	a,(_errors + 3)
	mov	(_errors + 3),a
	C$main.c$291$1$317 ==.
;	main.c:291: errors = errors2;
00136$:
	C$main.c$294$1$317 ==.
;	main.c:294: correct_ber();
	lcall	_correct_ber
00138$:
	C$main.c$295$1$317 ==.
	XFmain$process_ber$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'dump_pkt'
;------------------------------------------------------------
;st                        Allocated to registers 
;------------------------------------------------------------
	Fmain$dump_pkt$0$0 ==.
	C$main.c$297$1$317 ==.
;	main.c:297: static void dump_pkt(struct axradio_status __xdata *st)
;	-----------------------------------------
;	 function dump_pkt
;	-----------------------------------------
_dump_pkt:
	C$main.c$323$1$317 ==.
;	main.c:323: }
	C$main.c$323$1$317 ==.
	XFmain$dump_pkt$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'display_ber'
;------------------------------------------------------------
;st                        Allocated to registers r6 r7 
;freqoffs                  Allocated to registers 
;------------------------------------------------------------
	Fmain$display_ber$0$0 ==.
	C$main.c$325$1$317 ==.
;	main.c:325: static void display_ber(struct axradio_status __xdata *st)
;	-----------------------------------------
;	 function display_ber
;	-----------------------------------------
_display_ber:
	mov	r6,dpl
	mov	r7,dph
	C$main.c$327$1$332 ==.
;	main.c:327: int32_t freqoffs = axradio_conv_freq_tohz(st->u.rx.phy.offset);
	mov	a,#0x06
	add	a,r6
	mov	r6,a
	clr	a
	addc	a,r7
	mov	r7,a
	mov	dpl,r6
	mov	dph,r7
	inc	dptr
	inc	dptr
	movx	a,@dptr
	mov	r4,a
	inc	dptr
	movx	a,@dptr
	mov	r5,a
	inc	dptr
	movx	a,@dptr
	mov	r6,a
	inc	dptr
	movx	a,@dptr
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	_axradio_conv_freq_tohz
	C$main.c$337$1$332 ==.
;	main.c:337: display_writenum16(st->u.rx.phy.rssi, 4, WRNUM_SIGNED);
	C$main.c$349$1$332 ==.
	XFmain$display_ber$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'axradio_statuschange'
;------------------------------------------------------------
;st                        Allocated to registers r6 r7 
;fourfsk                   Allocated to registers 
;i                         Allocated to registers 
;i                         Allocated to registers 
;i                         Allocated to registers 
;p                         Allocated to registers 
;------------------------------------------------------------
	G$axradio_statuschange$0$0 ==.
	C$main.c$351$1$332 ==.
;	main.c:351: void axradio_statuschange(struct axradio_status __xdata *st)
;	-----------------------------------------
;	 function axradio_statuschange
;	-----------------------------------------
_axradio_statuschange:
	mov	r6,dpl
	mov	r7,dph
	C$main.c$353$1$342 ==.
;	main.c:353: uint8_t fourfsk = axradio_check_fourfsk_modulation();
	push	ar7
	push	ar6
	lcall	_axradio_check_fourfsk_modulation
	pop	ar6
	pop	ar7
	C$main.c$354$1$342 ==.
;	main.c:354: switch (st->status)
	mov	dpl,r6
	mov	dph,r7
	movx	a,@dptr
	mov	r5,a
	jz	00130$
	cjne	r5,#0x03,00187$
	sjmp	00105$
00187$:
	cjne	r5,#0x04,00188$
	sjmp	00112$
00188$:
	cjne	r5,#0x05,00189$
	sjmp	00121$
00189$:
	ljmp	00161$
	C$main.c$357$2$343 ==.
;	main.c:357: led0_on();
00105$:
	setb	_PORTB_1
	C$main.c$358$2$343 ==.
;	main.c:358: break;
	ljmp	00161$
	C$main.c$361$2$343 ==.
;	main.c:361: led0_off();
00112$:
	clr	_PORTB_1
	C$main.c$362$2$343 ==.
;	main.c:362: break;
	ljmp	00161$
	C$main.c$376$3$348 ==.
;	main.c:376: case TX_RANDOM_PATTERN:
00121$:
	C$main.c$378$3$348 ==.
;	main.c:378: axradio_transmit((void *)0, onepattern, sizeof(onepattern));
	mov	_axradio_transmit_PARM_2,#_onepattern
	mov	(_axradio_transmit_PARM_2 + 1),#(_onepattern >> 8)
	mov	(_axradio_transmit_PARM_2 + 2),#0x80
	mov	_axradio_transmit_PARM_3,#0x10
	mov	(_axradio_transmit_PARM_3 + 1),#0x00
	mov	dptr,#0x0000
	mov	b,#0x00
	lcall	_axradio_transmit
	C$main.c$379$3$348 ==.
;	main.c:379: break;
	C$main.c$428$2$343 ==.
;	main.c:428: case AXRADIO_STAT_RECEIVE:
	sjmp	00161$
00130$:
	C$main.c$430$3$355 ==.
;	main.c:430: if (acquire_agc == 1)
	mov	a,#0x01
	cjne	a,_acquire_agc,00138$
	C$main.c$433$6$358 ==.
;	main.c:433: led0_off();
	clr	_PORTB_1
	C$main.c$434$4$356 ==.
;	main.c:434: acquire_agc = 2;
	mov	_acquire_agc,#0x02
	C$main.c$435$4$356 ==.
;	main.c:435: axradio_agc_freeze();
	lcall	_axradio_agc_freeze
	C$main.c$436$4$356 ==.
;	main.c:436: break;
	sjmp	00161$
00138$:
	C$main.c$439$3$355 ==.
;	main.c:439: if (acquire_agc == 2)
	mov	a,#0x02
	cjne	a,_acquire_agc,00150$
	C$main.c$442$4$359 ==.
;	main.c:442: acquire_agc = 0;
	mov	_acquire_agc,#0x00
	C$main.c$470$4$359 ==.
;	main.c:470: break;
	C$main.c$474$3$355 ==.
;	main.c:474: led0_on();
	sjmp	00161$
00150$:
	setb	_PORTB_1
	C$main.c$475$3$355 ==.
;	main.c:475: process_ber(st);
	mov	dpl,r6
	mov	dph,r7
	push	ar7
	push	ar6
	lcall	_process_ber
	pop	ar6
	pop	ar7
	C$main.c$477$3$355 ==.
;	main.c:477: if (!acquire_agc)
	mov	a,_acquire_agc
	jz	00161$
	C$main.c$480$3$355 ==.
;	main.c:480: axradio_agc_thaw();
	push	ar7
	push	ar6
	lcall	_axradio_agc_thaw
	pop	ar6
	pop	ar7
	C$main.c$481$3$355 ==.
;	main.c:481: display_ber(st);
	mov	dpl,r6
	mov	dph,r7
	lcall	_display_ber
	C$main.c$483$3$355 ==.
;	main.c:483: bytes = NUMBYTES;
	mov	_bytes,#0xe2
	mov	(_bytes + 1),#0x04
	clr	a
	mov	(_bytes + 2),a
	mov	(_bytes + 3),a
	C$main.c$484$3$355 ==.
;	main.c:484: errors = 0;
	mov	_errors,a
	mov	(_errors + 1),a
	mov	(_errors + 2),a
	mov	(_errors + 3),a
	C$main.c$485$3$355 ==.
;	main.c:485: errors2 = 0;
	mov	_errors2,a
	mov	(_errors2 + 1),a
	mov	(_errors2 + 2),a
	mov	(_errors2 + 3),a
	C$main.c$491$1$342 ==.
;	main.c:491: }
00161$:
	C$main.c$492$1$342 ==.
	XG$axradio_statuschange$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'set_cw'
;------------------------------------------------------------
;i                         Allocated to registers 
;------------------------------------------------------------
	G$set_cw$0$0 ==.
	C$main.c$494$1$342 ==.
;	main.c:494: void set_cw(void)
;	-----------------------------------------
;	 function set_cw
;	-----------------------------------------
_set_cw:
	C$main.c$496$1$366 ==.
;	main.c:496: uint8_t i = axradio_set_mode(AXRADIO_MODE_CW_TRANSMIT);
	mov	dpl,#0x03
	lcall	_axradio_set_mode
	mov	a,dpl
	C$main.c$498$1$366 ==.
;	main.c:498: if (i != AXRADIO_ERR_NOERROR)
	jz	00106$
	C$main.c$500$2$367 ==.
;	main.c:500: display_radio_error(i);
00123$:
	C$main.c$506$2$367 ==.
;	main.c:506: enter_sleep();
	lcall	_enter_sleep
	C$main.c$509$1$366 ==.
;	main.c:509: display_clear(0x00, 16);
	sjmp	00123$
00106$:
	C$main.c$514$1$366 ==.
;	main.c:514: if(axradio_get_transmitter_pa_type() == AXRADIO_DIFFERENTIAL_PA)
	lcall	_axradio_get_transmitter_pa_type
	mov	r7,dpl
	cjne	r7,#0x01,00134$
	sjmp	00125$
00134$:
	C$main.c$516$1$366 ==.
;	main.c:516: else if(axradio_get_transmitter_pa_type() == AXRADIO_SINGLE_ENDED_PA)
	lcall	_axradio_get_transmitter_pa_type
	C$main.c$517$1$366 ==.
;	main.c:517: display_writestr( "SE ");
00125$:
	C$main.c$518$1$366 ==.
	XG$set_cw$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'set_transmit'
;------------------------------------------------------------
;i                         Allocated to registers 
;------------------------------------------------------------
	G$set_transmit$0$0 ==.
	C$main.c$520$1$366 ==.
;	main.c:520: void set_transmit(void)
;	-----------------------------------------
;	 function set_transmit
;	-----------------------------------------
_set_transmit:
	C$main.c$566$1$376 ==.
;	main.c:566: i = axradio_set_mode(i);
	mov	dpl,#0x18
	lcall	_axradio_set_mode
	mov	a,dpl
	C$main.c$568$1$376 ==.
;	main.c:568: if (i != AXRADIO_ERR_NOERROR)
	jz	00111$
	C$main.c$570$2$378 ==.
;	main.c:570: display_radio_error(i);
00143$:
	C$main.c$576$2$378 ==.
;	main.c:576: enter_sleep();
	lcall	_enter_sleep
	sjmp	00143$
00111$:
	C$main.c$579$1$376 ==.
;	main.c:579: scr.w = ~0U;
	mov	(_scr + 0),#0xff
	mov	(_scr + 1),#0xff
	C$main.c$607$1$376 ==.
;	main.c:607: if(axradio_get_transmitter_pa_type() == AXRADIO_DIFFERENTIAL_PA)
	lcall	_axradio_get_transmitter_pa_type
	mov	r7,dpl
	cjne	r7,#0x01,00154$
	sjmp	00145$
00154$:
	C$main.c$609$1$376 ==.
;	main.c:609: else if(axradio_get_transmitter_pa_type() == AXRADIO_SINGLE_ENDED_PA)
	lcall	_axradio_get_transmitter_pa_type
	C$main.c$610$1$376 ==.
;	main.c:610: display_writestr( "SE ");
00145$:
	C$main.c$611$1$376 ==.
	XG$set_transmit$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'set_receiveber'
;------------------------------------------------------------
;i                         Allocated to registers 
;------------------------------------------------------------
	G$set_receiveber$0$0 ==.
	C$main.c$613$1$376 ==.
;	main.c:613: void set_receiveber(void)
;	-----------------------------------------
;	 function set_receiveber
;	-----------------------------------------
_set_receiveber:
	C$main.c$656$1$392 ==.
;	main.c:656: i = axradio_set_mode(i);
	mov	dpl,#0x28
	lcall	_axradio_set_mode
	mov	a,dpl
	C$main.c$658$1$392 ==.
;	main.c:658: if (i != AXRADIO_ERR_NOERROR)
	jz	00112$
	C$main.c$660$2$394 ==.
;	main.c:660: display_radio_error(i);
00128$:
	C$main.c$666$2$394 ==.
;	main.c:666: enter_sleep();
	lcall	_enter_sleep
	C$main.c$669$1$392 ==.
;	main.c:669: display_clear(0x00, 16);
	sjmp	00128$
00112$:
	C$main.c$680$1$392 ==.
;	main.c:680: bytes = NUMBYTES;
	mov	_bytes,#0xe2
	mov	(_bytes + 1),#0x04
	clr	a
	mov	(_bytes + 2),a
	mov	(_bytes + 3),a
	C$main.c$681$1$392 ==.
;	main.c:681: errors = 0;
	mov	_errors,a
	mov	(_errors + 1),a
	mov	(_errors + 2),a
	mov	(_errors + 3),a
	C$main.c$682$1$392 ==.
;	main.c:682: errors2 = 0;
	mov	_errors2,a
	mov	(_errors2 + 1),a
	mov	(_errors2 + 2),a
	mov	(_errors2 + 3),a
	C$main.c$683$1$392 ==.
;	main.c:683: acquire_agc = 1;
	mov	_acquire_agc,#0x01
	C$main.c$684$1$392 ==.
	XG$set_receiveber$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'enable_radio_interrupt_in_mcu_pin'
;------------------------------------------------------------
	G$enable_radio_interrupt_in_mcu_pin$0$0 ==.
	C$main.c$686$1$392 ==.
;	main.c:686: void enable_radio_interrupt_in_mcu_pin(void)
;	-----------------------------------------
;	 function enable_radio_interrupt_in_mcu_pin
;	-----------------------------------------
_enable_radio_interrupt_in_mcu_pin:
	C$main.c$688$1$405 ==.
;	main.c:688: IE_4 = 1;
	setb	_IE_4
	C$main.c$689$1$405 ==.
	XG$enable_radio_interrupt_in_mcu_pin$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'disable_radio_interrupt_in_mcu_pin'
;------------------------------------------------------------
	G$disable_radio_interrupt_in_mcu_pin$0$0 ==.
	C$main.c$691$1$405 ==.
;	main.c:691: void disable_radio_interrupt_in_mcu_pin(void)
;	-----------------------------------------
;	 function disable_radio_interrupt_in_mcu_pin
;	-----------------------------------------
_disable_radio_interrupt_in_mcu_pin:
	C$main.c$693$1$407 ==.
;	main.c:693: IE_4 = 0;
	clr	_IE_4
	C$main.c$694$1$407 ==.
	XG$disable_radio_interrupt_in_mcu_pin$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '_sdcc_external_startup'
;------------------------------------------------------------
;c                         Allocated to registers 
;p                         Allocated to registers 
;c                         Allocated to registers 
;p                         Allocated to registers 
;------------------------------------------------------------
	G$_sdcc_external_startup$0$0 ==.
	C$main.c$697$1$407 ==.
;	main.c:697: uint8_t _sdcc_external_startup(void)
;	-----------------------------------------
;	 function _sdcc_external_startup
;	-----------------------------------------
__sdcc_external_startup:
	C$main.c$699$2$410 ==.
;	main.c:699: wtimer0_setclksrc(WTIMER0_CLKSRC, WTIMER0_PRESCALER);
	mov	dpl,#0x09
	lcall	_wtimer0_setconfig
	C$main.c$700$2$411 ==.
;	main.c:700: wtimer1_setclksrc(CLKSRC_FRCOSC, 7);
	mov	dpl,#0x38
	lcall	_wtimer1_setconfig
	C$main.c$702$1$409 ==.
;	main.c:702: coldstart = !(PCON & 0x40);
	mov	a,_PCON
	mov	c,acc[6]
	cpl	c
	mov	__sdcc_external_startup_sloc0_1_0,c
	clr	a
	rlc	a
	mov	_coldstart,a
	C$main.c$703$1$409 ==.
;	main.c:703: ANALOGA = 0x18; /* PA[3,4] LPXOSC, other PA are used as digital pins */
	mov	dptr,#_ANALOGA
	mov	a,#0x18
	movx	@dptr,a
	C$main.c$704$1$409 ==.
;	main.c:704: PORTA = 0xE7; /* pull ups except for LPXOSC pin PA[3,4]; */
	mov	_PORTA,#0xe7
	C$main.c$705$1$409 ==.
;	main.c:705: PORTB = 0xFD | (PINB & 0x02); /* init LEDs to previous (frozen) state */
	mov	a,#0x02
	anl	a,_PINB
	orl	a,#0xfd
	mov	_PORTB,a
	C$main.c$706$1$409 ==.
;	main.c:706: PORTC = 0xFF; /* */
	mov	_PORTC,#0xff
	C$main.c$707$1$409 ==.
;	main.c:707: PORTR = 0x0B; /* */
	mov	_PORTR,#0x0b
	C$main.c$709$1$409 ==.
;	main.c:709: DIRA = 0x00; /* */
	mov	_DIRA,#0x00
	C$main.c$710$1$409 ==.
;	main.c:710: DIRB = 0x0e; /*  PB1 = LED; PB2 / PB3 are outputs (in case PWRAMP / ANSTSEL are used) */
	mov	_DIRB,#0x0e
	C$main.c$711$1$409 ==.
;	main.c:711: DIRC = 0x00; /*  PC4 = button */
	mov	_DIRC,#0x00
	C$main.c$712$1$409 ==.
;	main.c:712: DIRR = 0x15; /* */
	mov	_DIRR,#0x15
	C$main.c$714$1$409 ==.
;	main.c:714: axradio_setup_pincfg1();
	lcall	_axradio_setup_pincfg1
	C$main.c$715$1$409 ==.
;	main.c:715: DPS = 0;
	mov	_DPS,#0x00
	C$main.c$716$1$409 ==.
;	main.c:716: IE = 0x40;
	mov	_IE,#0x40
	C$main.c$717$1$409 ==.
;	main.c:717: EIE = 0x00;
	mov	_EIE,#0x00
	C$main.c$718$1$409 ==.
;	main.c:718: E2IE = 0x00;
	mov	_E2IE,#0x00
	C$main.c$720$1$409 ==.
;	main.c:720: GPIOENABLE = 1; /* unfreeze GPIO */
	mov	dptr,#_GPIOENABLE
	mov	a,#0x01
	movx	@dptr,a
	C$main.c$721$1$409 ==.
;	main.c:721: return !coldstart; /* coldstart -> return 0 -> var initialization; start from sleep -> return 1 -> no var initialization */
	mov	a,_coldstart
	cjne	a,#0x01,00111$
00111$:
	mov  __sdcc_external_startup_sloc0_1_0,c
	clr	a
	rlc	a
	mov	dpl,a
	C$main.c$722$1$409 ==.
	XG$_sdcc_external_startup$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;i                         Allocated to registers 
;crit                      Allocated with name '_main_crit_1_414'
;flg                       Allocated to registers r7 
;flg                       Allocated to registers r7 
;------------------------------------------------------------
	G$main$0$0 ==.
	C$main.c$724$1$409 ==.
;	main.c:724: int main(void)
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	C$main.c$731$1$414 ==.
;	main.c:731: __endasm;
	G$_start__stack$0$0	= __start__stack
	.globl	G$_start__stack$0$0
	C$libmftypes.h$368$4$438 ==.
;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:368: EA = 1;
	setb	_EA
	C$main.c$736$1$414 ==.
;	main.c:736: flash_apply_calibration();
	lcall	_flash_apply_calibration
	C$main.c$737$1$414 ==.
;	main.c:737: CLKCON = 0x00;
	mov	_CLKCON,#0x00
	C$main.c$738$1$414 ==.
;	main.c:738: wtimer_init();
	lcall	_wtimer_init
	C$main.c$740$1$414 ==.
;	main.c:740: if (coldstart)
	mov	a,_coldstart
	jz	00135$
	C$main.c$742$4$417 ==.
;	main.c:742: led0_off();
	clr	_PORTB_1
	C$main.c$750$2$415 ==.
;	main.c:750: i = axradio_init();             /* to be fixed PB3 to PC4 */
	lcall	_axradio_init
	mov	a,dpl
	C$main.c$752$2$415 ==.
;	main.c:752: if (i != AXRADIO_ERR_NOERROR)
	jz	00136$
	C$main.c$763$4$427 ==.
;	main.c:763: goto terminate_error;
	C$main.c$769$1$414 ==.
;	main.c:769: display_writestr(radio_lcd_display);
	sjmp	00163$
00135$:
	C$main.c$812$2$430 ==.
;	main.c:812: axradio_commsleepexit();
	lcall	_axradio_commsleepexit
	C$main.c$813$2$430 ==.
;	main.c:813: IE_4 = 1; /* enable radio interrupt */
	setb	_IE_4
00136$:
	C$main.c$816$1$414 ==.
;	main.c:816: axradio_setup_pincfg2();
	lcall	_axradio_setup_pincfg2
	C$main.c$821$2$431 ==.
;	main.c:821: set_cw();
	lcall	_set_cw
	C$main.c$873$1$414 ==.
;	main.c:873: }
00161$:
	C$main.c$877$2$432 ==.
;	main.c:877: wtimer_runcallbacks();
	lcall	_wtimer_runcallbacks
	C$main.c$879$3$432 ==.
;	main.c:879: uint8_t flg = WTFLAG_CANSTANDBY;
	mov	r7,#0x02
	C$main.c$882$3$433 ==.
;	main.c:882: if (axradio_cansleep()
	push	ar7
	lcall	_axradio_cansleep
	mov	a,dpl
	pop	ar7
	jz	00152$
	C$main.c$887$3$433 ==.
;	main.c:887: flg |= WTFLAG_CANSLEEP;
	mov	r7,#0x03
00152$:
	C$main.c$889$3$433 ==.
;	main.c:889: wtimer_idle(flg);
	mov	dpl,r7
	lcall	_wtimer_idle
	C$main.c$893$1$414 ==.
;	main.c:893: terminate_error:
	sjmp	00161$
00163$:
	C$main.c$896$2$434 ==.
;	main.c:896: wtimer_runcallbacks();
	lcall	_wtimer_runcallbacks
	C$main.c$898$3$434 ==.
;	main.c:898: uint8_t flg = WTFLAG_CANSTANDBY;
	mov	r7,#0x02
	C$main.c$901$3$435 ==.
;	main.c:901: if (axradio_cansleep()
	push	ar7
	lcall	_axradio_cansleep
	mov	a,dpl
	pop	ar7
	jz	00157$
	C$main.c$906$3$435 ==.
;	main.c:906: flg |= WTFLAG_CANSLEEP;
	mov	r7,#0x03
00157$:
	C$main.c$908$3$435 ==.
;	main.c:908: wtimer_idle(flg);
	mov	dpl,r7
	lcall	_wtimer_idle
	sjmp	00163$
	C$main.c$911$1$414 ==.
	XG$main$0$0 ==.
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
G$txpattern$0$0 == .
_txpattern:
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
G$onepattern$0$0 == .
_onepattern:
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
	.db #0xff	; 255
G$fourfsk_tx1010_pattern$0$0 == .
_fourfsk_tx1010_pattern:
	.db #0x1e	; 30
	.db #0x1e	; 30
	.db #0x1e	; 30
	.db #0x1e	; 30
	.db #0x1e	; 30
	.db #0x1e	; 30
	.db #0x1e	; 30
	.db #0x1e	; 30
G$non_fourfsk_tx1010_pattern$0$0 == .
_non_fourfsk_tx1010_pattern:
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.db #0x55	; 85	'U'
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
