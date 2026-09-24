                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _non_fourfsk_tx1010_pattern
                                     12 	.globl _fourfsk_tx1010_pattern
                                     13 	.globl _onepattern
                                     14 	.globl _txpattern
                                     15 	.globl _main
                                     16 	.globl __sdcc_external_startup
                                     17 	.globl _set_receiveber
                                     18 	.globl _set_transmit
                                     19 	.globl _set_cw
                                     20 	.globl _axradio_commsleepexit
                                     21 	.globl _axradio_setup_pincfg2
                                     22 	.globl _axradio_setup_pincfg1
                                     23 	.globl _axradio_get_transmitter_pa_type
                                     24 	.globl _axradio_check_fourfsk_modulation
                                     25 	.globl _axradio_agc_thaw
                                     26 	.globl _axradio_agc_freeze
                                     27 	.globl _axradio_conv_freq_tohz
                                     28 	.globl _axradio_transmit
                                     29 	.globl _axradio_set_mode
                                     30 	.globl _axradio_cansleep
                                     31 	.globl _axradio_init
                                     32 	.globl _pn15_output
                                     33 	.globl _pn15_advance
                                     34 	.globl _pn9_advance
                                     35 	.globl _wtimer_runcallbacks
                                     36 	.globl _wtimer_idle
                                     37 	.globl _wtimer_init
                                     38 	.globl _wtimer1_setconfig
                                     39 	.globl _wtimer0_setconfig
                                     40 	.globl _flash_apply_calibration
                                     41 	.globl _enter_sleep
                                     42 	.globl _hweight8
                                     43 	.globl _PORTC_7
                                     44 	.globl _PORTC_6
                                     45 	.globl _PORTC_5
                                     46 	.globl _PORTC_4
                                     47 	.globl _PORTC_3
                                     48 	.globl _PORTC_2
                                     49 	.globl _PORTC_1
                                     50 	.globl _PORTC_0
                                     51 	.globl _PORTB_7
                                     52 	.globl _PORTB_6
                                     53 	.globl _PORTB_5
                                     54 	.globl _PORTB_4
                                     55 	.globl _PORTB_3
                                     56 	.globl _PORTB_2
                                     57 	.globl _PORTB_1
                                     58 	.globl _PORTB_0
                                     59 	.globl _PORTA_7
                                     60 	.globl _PORTA_6
                                     61 	.globl _PORTA_5
                                     62 	.globl _PORTA_4
                                     63 	.globl _PORTA_3
                                     64 	.globl _PORTA_2
                                     65 	.globl _PORTA_1
                                     66 	.globl _PORTA_0
                                     67 	.globl _PINC_7
                                     68 	.globl _PINC_6
                                     69 	.globl _PINC_5
                                     70 	.globl _PINC_4
                                     71 	.globl _PINC_3
                                     72 	.globl _PINC_2
                                     73 	.globl _PINC_1
                                     74 	.globl _PINC_0
                                     75 	.globl _PINB_7
                                     76 	.globl _PINB_6
                                     77 	.globl _PINB_5
                                     78 	.globl _PINB_4
                                     79 	.globl _PINB_3
                                     80 	.globl _PINB_2
                                     81 	.globl _PINB_1
                                     82 	.globl _PINB_0
                                     83 	.globl _PINA_7
                                     84 	.globl _PINA_6
                                     85 	.globl _PINA_5
                                     86 	.globl _PINA_4
                                     87 	.globl _PINA_3
                                     88 	.globl _PINA_2
                                     89 	.globl _PINA_1
                                     90 	.globl _PINA_0
                                     91 	.globl _CY
                                     92 	.globl _AC
                                     93 	.globl _F0
                                     94 	.globl _RS1
                                     95 	.globl _RS0
                                     96 	.globl _OV
                                     97 	.globl _F1
                                     98 	.globl _P
                                     99 	.globl _IP_7
                                    100 	.globl _IP_6
                                    101 	.globl _IP_5
                                    102 	.globl _IP_4
                                    103 	.globl _IP_3
                                    104 	.globl _IP_2
                                    105 	.globl _IP_1
                                    106 	.globl _IP_0
                                    107 	.globl _EA
                                    108 	.globl _IE_7
                                    109 	.globl _IE_6
                                    110 	.globl _IE_5
                                    111 	.globl _IE_4
                                    112 	.globl _IE_3
                                    113 	.globl _IE_2
                                    114 	.globl _IE_1
                                    115 	.globl _IE_0
                                    116 	.globl _EIP_7
                                    117 	.globl _EIP_6
                                    118 	.globl _EIP_5
                                    119 	.globl _EIP_4
                                    120 	.globl _EIP_3
                                    121 	.globl _EIP_2
                                    122 	.globl _EIP_1
                                    123 	.globl _EIP_0
                                    124 	.globl _EIE_7
                                    125 	.globl _EIE_6
                                    126 	.globl _EIE_5
                                    127 	.globl _EIE_4
                                    128 	.globl _EIE_3
                                    129 	.globl _EIE_2
                                    130 	.globl _EIE_1
                                    131 	.globl _EIE_0
                                    132 	.globl _E2IP_7
                                    133 	.globl _E2IP_6
                                    134 	.globl _E2IP_5
                                    135 	.globl _E2IP_4
                                    136 	.globl _E2IP_3
                                    137 	.globl _E2IP_2
                                    138 	.globl _E2IP_1
                                    139 	.globl _E2IP_0
                                    140 	.globl _E2IE_7
                                    141 	.globl _E2IE_6
                                    142 	.globl _E2IE_5
                                    143 	.globl _E2IE_4
                                    144 	.globl _E2IE_3
                                    145 	.globl _E2IE_2
                                    146 	.globl _E2IE_1
                                    147 	.globl _E2IE_0
                                    148 	.globl _B_7
                                    149 	.globl _B_6
                                    150 	.globl _B_5
                                    151 	.globl _B_4
                                    152 	.globl _B_3
                                    153 	.globl _B_2
                                    154 	.globl _B_1
                                    155 	.globl _B_0
                                    156 	.globl _ACC_7
                                    157 	.globl _ACC_6
                                    158 	.globl _ACC_5
                                    159 	.globl _ACC_4
                                    160 	.globl _ACC_3
                                    161 	.globl _ACC_2
                                    162 	.globl _ACC_1
                                    163 	.globl _ACC_0
                                    164 	.globl _WTSTAT
                                    165 	.globl _WTIRQEN
                                    166 	.globl _WTEVTD
                                    167 	.globl _WTEVTD1
                                    168 	.globl _WTEVTD0
                                    169 	.globl _WTEVTC
                                    170 	.globl _WTEVTC1
                                    171 	.globl _WTEVTC0
                                    172 	.globl _WTEVTB
                                    173 	.globl _WTEVTB1
                                    174 	.globl _WTEVTB0
                                    175 	.globl _WTEVTA
                                    176 	.globl _WTEVTA1
                                    177 	.globl _WTEVTA0
                                    178 	.globl _WTCNTR1
                                    179 	.globl _WTCNTB
                                    180 	.globl _WTCNTB1
                                    181 	.globl _WTCNTB0
                                    182 	.globl _WTCNTA
                                    183 	.globl _WTCNTA1
                                    184 	.globl _WTCNTA0
                                    185 	.globl _WTCFGB
                                    186 	.globl _WTCFGA
                                    187 	.globl _WDTRESET
                                    188 	.globl _WDTCFG
                                    189 	.globl _U1STATUS
                                    190 	.globl _U1SHREG
                                    191 	.globl _U1MODE
                                    192 	.globl _U1CTRL
                                    193 	.globl _U0STATUS
                                    194 	.globl _U0SHREG
                                    195 	.globl _U0MODE
                                    196 	.globl _U0CTRL
                                    197 	.globl _T2STATUS
                                    198 	.globl _T2PERIOD
                                    199 	.globl _T2PERIOD1
                                    200 	.globl _T2PERIOD0
                                    201 	.globl _T2MODE
                                    202 	.globl _T2CNT
                                    203 	.globl _T2CNT1
                                    204 	.globl _T2CNT0
                                    205 	.globl _T2CLKSRC
                                    206 	.globl _T1STATUS
                                    207 	.globl _T1PERIOD
                                    208 	.globl _T1PERIOD1
                                    209 	.globl _T1PERIOD0
                                    210 	.globl _T1MODE
                                    211 	.globl _T1CNT
                                    212 	.globl _T1CNT1
                                    213 	.globl _T1CNT0
                                    214 	.globl _T1CLKSRC
                                    215 	.globl _T0STATUS
                                    216 	.globl _T0PERIOD
                                    217 	.globl _T0PERIOD1
                                    218 	.globl _T0PERIOD0
                                    219 	.globl _T0MODE
                                    220 	.globl _T0CNT
                                    221 	.globl _T0CNT1
                                    222 	.globl _T0CNT0
                                    223 	.globl _T0CLKSRC
                                    224 	.globl _SPSTATUS
                                    225 	.globl _SPSHREG
                                    226 	.globl _SPMODE
                                    227 	.globl _SPCLKSRC
                                    228 	.globl _RADIOSTAT
                                    229 	.globl _RADIOSTAT1
                                    230 	.globl _RADIOSTAT0
                                    231 	.globl _RADIODATA
                                    232 	.globl _RADIODATA3
                                    233 	.globl _RADIODATA2
                                    234 	.globl _RADIODATA1
                                    235 	.globl _RADIODATA0
                                    236 	.globl _RADIOADDR
                                    237 	.globl _RADIOADDR1
                                    238 	.globl _RADIOADDR0
                                    239 	.globl _RADIOACC
                                    240 	.globl _OC1STATUS
                                    241 	.globl _OC1PIN
                                    242 	.globl _OC1MODE
                                    243 	.globl _OC1COMP
                                    244 	.globl _OC1COMP1
                                    245 	.globl _OC1COMP0
                                    246 	.globl _OC0STATUS
                                    247 	.globl _OC0PIN
                                    248 	.globl _OC0MODE
                                    249 	.globl _OC0COMP
                                    250 	.globl _OC0COMP1
                                    251 	.globl _OC0COMP0
                                    252 	.globl _NVSTATUS
                                    253 	.globl _NVKEY
                                    254 	.globl _NVDATA
                                    255 	.globl _NVDATA1
                                    256 	.globl _NVDATA0
                                    257 	.globl _NVADDR
                                    258 	.globl _NVADDR1
                                    259 	.globl _NVADDR0
                                    260 	.globl _IC1STATUS
                                    261 	.globl _IC1MODE
                                    262 	.globl _IC1CAPT
                                    263 	.globl _IC1CAPT1
                                    264 	.globl _IC1CAPT0
                                    265 	.globl _IC0STATUS
                                    266 	.globl _IC0MODE
                                    267 	.globl _IC0CAPT
                                    268 	.globl _IC0CAPT1
                                    269 	.globl _IC0CAPT0
                                    270 	.globl _PORTR
                                    271 	.globl _PORTC
                                    272 	.globl _PORTB
                                    273 	.globl _PORTA
                                    274 	.globl _PINR
                                    275 	.globl _PINC
                                    276 	.globl _PINB
                                    277 	.globl _PINA
                                    278 	.globl _DIRR
                                    279 	.globl _DIRC
                                    280 	.globl _DIRB
                                    281 	.globl _DIRA
                                    282 	.globl _DBGLNKSTAT
                                    283 	.globl _DBGLNKBUF
                                    284 	.globl _CODECONFIG
                                    285 	.globl _CLKSTAT
                                    286 	.globl _CLKCON
                                    287 	.globl _ANALOGCOMP
                                    288 	.globl _ADCCONV
                                    289 	.globl _ADCCLKSRC
                                    290 	.globl _ADCCH3CONFIG
                                    291 	.globl _ADCCH2CONFIG
                                    292 	.globl _ADCCH1CONFIG
                                    293 	.globl _ADCCH0CONFIG
                                    294 	.globl __XPAGE
                                    295 	.globl _XPAGE
                                    296 	.globl _SP
                                    297 	.globl _PSW
                                    298 	.globl _PCON
                                    299 	.globl _IP
                                    300 	.globl _IE
                                    301 	.globl _EIP
                                    302 	.globl _EIE
                                    303 	.globl _E2IP
                                    304 	.globl _E2IE
                                    305 	.globl _DPS
                                    306 	.globl _DPTR1
                                    307 	.globl _DPTR0
                                    308 	.globl _DPL1
                                    309 	.globl _DPL
                                    310 	.globl _DPH1
                                    311 	.globl _DPH
                                    312 	.globl _B
                                    313 	.globl _ACC
                                    314 	.globl _txdata
                                    315 	.globl _XTALREADY
                                    316 	.globl _XTALOSC
                                    317 	.globl _XTALAMPL
                                    318 	.globl _SILICONREV
                                    319 	.globl _SCRATCH3
                                    320 	.globl _SCRATCH2
                                    321 	.globl _SCRATCH1
                                    322 	.globl _SCRATCH0
                                    323 	.globl _RADIOMUX
                                    324 	.globl _RADIOFSTATADDR
                                    325 	.globl _RADIOFSTATADDR1
                                    326 	.globl _RADIOFSTATADDR0
                                    327 	.globl _RADIOFDATAADDR
                                    328 	.globl _RADIOFDATAADDR1
                                    329 	.globl _RADIOFDATAADDR0
                                    330 	.globl _OSCRUN
                                    331 	.globl _OSCREADY
                                    332 	.globl _OSCFORCERUN
                                    333 	.globl _OSCCALIB
                                    334 	.globl _MISCCTRL
                                    335 	.globl _LPXOSCGM
                                    336 	.globl _LPOSCREF
                                    337 	.globl _LPOSCREF1
                                    338 	.globl _LPOSCREF0
                                    339 	.globl _LPOSCPER
                                    340 	.globl _LPOSCPER1
                                    341 	.globl _LPOSCPER0
                                    342 	.globl _LPOSCKFILT
                                    343 	.globl _LPOSCKFILT1
                                    344 	.globl _LPOSCKFILT0
                                    345 	.globl _LPOSCFREQ
                                    346 	.globl _LPOSCFREQ1
                                    347 	.globl _LPOSCFREQ0
                                    348 	.globl _LPOSCCONFIG
                                    349 	.globl _PINSEL
                                    350 	.globl _PINCHGC
                                    351 	.globl _PINCHGB
                                    352 	.globl _PINCHGA
                                    353 	.globl _PALTRADIO
                                    354 	.globl _PALTC
                                    355 	.globl _PALTB
                                    356 	.globl _PALTA
                                    357 	.globl _INTCHGC
                                    358 	.globl _INTCHGB
                                    359 	.globl _INTCHGA
                                    360 	.globl _EXTIRQ
                                    361 	.globl _GPIOENABLE
                                    362 	.globl _ANALOGA
                                    363 	.globl _FRCOSCREF
                                    364 	.globl _FRCOSCREF1
                                    365 	.globl _FRCOSCREF0
                                    366 	.globl _FRCOSCPER
                                    367 	.globl _FRCOSCPER1
                                    368 	.globl _FRCOSCPER0
                                    369 	.globl _FRCOSCKFILT
                                    370 	.globl _FRCOSCKFILT1
                                    371 	.globl _FRCOSCKFILT0
                                    372 	.globl _FRCOSCFREQ
                                    373 	.globl _FRCOSCFREQ1
                                    374 	.globl _FRCOSCFREQ0
                                    375 	.globl _FRCOSCCTRL
                                    376 	.globl _FRCOSCCONFIG
                                    377 	.globl _DMA1CONFIG
                                    378 	.globl _DMA1ADDR
                                    379 	.globl _DMA1ADDR1
                                    380 	.globl _DMA1ADDR0
                                    381 	.globl _DMA0CONFIG
                                    382 	.globl _DMA0ADDR
                                    383 	.globl _DMA0ADDR1
                                    384 	.globl _DMA0ADDR0
                                    385 	.globl _ADCTUNE2
                                    386 	.globl _ADCTUNE1
                                    387 	.globl _ADCTUNE0
                                    388 	.globl _ADCCH3VAL
                                    389 	.globl _ADCCH3VAL1
                                    390 	.globl _ADCCH3VAL0
                                    391 	.globl _ADCCH2VAL
                                    392 	.globl _ADCCH2VAL1
                                    393 	.globl _ADCCH2VAL0
                                    394 	.globl _ADCCH1VAL
                                    395 	.globl _ADCCH1VAL1
                                    396 	.globl _ADCCH1VAL0
                                    397 	.globl _ADCCH0VAL
                                    398 	.globl _ADCCH0VAL1
                                    399 	.globl _ADCCH0VAL0
                                    400 	.globl _acquire_agc
                                    401 	.globl _errors2
                                    402 	.globl _errors
                                    403 	.globl _bytes
                                    404 	.globl _scr
                                    405 	.globl _BER_TEST
                                    406 	.globl _coldstart
                                    407 	.globl _axradio_statuschange
                                    408 	.globl _enable_radio_interrupt_in_mcu_pin
                                    409 	.globl _disable_radio_interrupt_in_mcu_pin
                                    410 ;--------------------------------------------------------
                                    411 ; special function registers
                                    412 ;--------------------------------------------------------
                                    413 	.area RSEG    (ABS,DATA)
      000000                        414 	.org 0x0000
                           0000E0   415 G$ACC$0$0 == 0x00e0
                           0000E0   416 _ACC	=	0x00e0
                           0000F0   417 G$B$0$0 == 0x00f0
                           0000F0   418 _B	=	0x00f0
                           000083   419 G$DPH$0$0 == 0x0083
                           000083   420 _DPH	=	0x0083
                           000085   421 G$DPH1$0$0 == 0x0085
                           000085   422 _DPH1	=	0x0085
                           000082   423 G$DPL$0$0 == 0x0082
                           000082   424 _DPL	=	0x0082
                           000084   425 G$DPL1$0$0 == 0x0084
                           000084   426 _DPL1	=	0x0084
                           008382   427 G$DPTR0$0$0 == 0x8382
                           008382   428 _DPTR0	=	0x8382
                           008584   429 G$DPTR1$0$0 == 0x8584
                           008584   430 _DPTR1	=	0x8584
                           000086   431 G$DPS$0$0 == 0x0086
                           000086   432 _DPS	=	0x0086
                           0000A0   433 G$E2IE$0$0 == 0x00a0
                           0000A0   434 _E2IE	=	0x00a0
                           0000C0   435 G$E2IP$0$0 == 0x00c0
                           0000C0   436 _E2IP	=	0x00c0
                           000098   437 G$EIE$0$0 == 0x0098
                           000098   438 _EIE	=	0x0098
                           0000B0   439 G$EIP$0$0 == 0x00b0
                           0000B0   440 _EIP	=	0x00b0
                           0000A8   441 G$IE$0$0 == 0x00a8
                           0000A8   442 _IE	=	0x00a8
                           0000B8   443 G$IP$0$0 == 0x00b8
                           0000B8   444 _IP	=	0x00b8
                           000087   445 G$PCON$0$0 == 0x0087
                           000087   446 _PCON	=	0x0087
                           0000D0   447 G$PSW$0$0 == 0x00d0
                           0000D0   448 _PSW	=	0x00d0
                           000081   449 G$SP$0$0 == 0x0081
                           000081   450 _SP	=	0x0081
                           0000D9   451 G$XPAGE$0$0 == 0x00d9
                           0000D9   452 _XPAGE	=	0x00d9
                           0000D9   453 G$_XPAGE$0$0 == 0x00d9
                           0000D9   454 __XPAGE	=	0x00d9
                           0000CA   455 G$ADCCH0CONFIG$0$0 == 0x00ca
                           0000CA   456 _ADCCH0CONFIG	=	0x00ca
                           0000CB   457 G$ADCCH1CONFIG$0$0 == 0x00cb
                           0000CB   458 _ADCCH1CONFIG	=	0x00cb
                           0000D2   459 G$ADCCH2CONFIG$0$0 == 0x00d2
                           0000D2   460 _ADCCH2CONFIG	=	0x00d2
                           0000D3   461 G$ADCCH3CONFIG$0$0 == 0x00d3
                           0000D3   462 _ADCCH3CONFIG	=	0x00d3
                           0000D1   463 G$ADCCLKSRC$0$0 == 0x00d1
                           0000D1   464 _ADCCLKSRC	=	0x00d1
                           0000C9   465 G$ADCCONV$0$0 == 0x00c9
                           0000C9   466 _ADCCONV	=	0x00c9
                           0000E1   467 G$ANALOGCOMP$0$0 == 0x00e1
                           0000E1   468 _ANALOGCOMP	=	0x00e1
                           0000C6   469 G$CLKCON$0$0 == 0x00c6
                           0000C6   470 _CLKCON	=	0x00c6
                           0000C7   471 G$CLKSTAT$0$0 == 0x00c7
                           0000C7   472 _CLKSTAT	=	0x00c7
                           000097   473 G$CODECONFIG$0$0 == 0x0097
                           000097   474 _CODECONFIG	=	0x0097
                           0000E3   475 G$DBGLNKBUF$0$0 == 0x00e3
                           0000E3   476 _DBGLNKBUF	=	0x00e3
                           0000E2   477 G$DBGLNKSTAT$0$0 == 0x00e2
                           0000E2   478 _DBGLNKSTAT	=	0x00e2
                           000089   479 G$DIRA$0$0 == 0x0089
                           000089   480 _DIRA	=	0x0089
                           00008A   481 G$DIRB$0$0 == 0x008a
                           00008A   482 _DIRB	=	0x008a
                           00008B   483 G$DIRC$0$0 == 0x008b
                           00008B   484 _DIRC	=	0x008b
                           00008E   485 G$DIRR$0$0 == 0x008e
                           00008E   486 _DIRR	=	0x008e
                           0000C8   487 G$PINA$0$0 == 0x00c8
                           0000C8   488 _PINA	=	0x00c8
                           0000E8   489 G$PINB$0$0 == 0x00e8
                           0000E8   490 _PINB	=	0x00e8
                           0000F8   491 G$PINC$0$0 == 0x00f8
                           0000F8   492 _PINC	=	0x00f8
                           00008D   493 G$PINR$0$0 == 0x008d
                           00008D   494 _PINR	=	0x008d
                           000080   495 G$PORTA$0$0 == 0x0080
                           000080   496 _PORTA	=	0x0080
                           000088   497 G$PORTB$0$0 == 0x0088
                           000088   498 _PORTB	=	0x0088
                           000090   499 G$PORTC$0$0 == 0x0090
                           000090   500 _PORTC	=	0x0090
                           00008C   501 G$PORTR$0$0 == 0x008c
                           00008C   502 _PORTR	=	0x008c
                           0000CE   503 G$IC0CAPT0$0$0 == 0x00ce
                           0000CE   504 _IC0CAPT0	=	0x00ce
                           0000CF   505 G$IC0CAPT1$0$0 == 0x00cf
                           0000CF   506 _IC0CAPT1	=	0x00cf
                           00CFCE   507 G$IC0CAPT$0$0 == 0xcfce
                           00CFCE   508 _IC0CAPT	=	0xcfce
                           0000CC   509 G$IC0MODE$0$0 == 0x00cc
                           0000CC   510 _IC0MODE	=	0x00cc
                           0000CD   511 G$IC0STATUS$0$0 == 0x00cd
                           0000CD   512 _IC0STATUS	=	0x00cd
                           0000D6   513 G$IC1CAPT0$0$0 == 0x00d6
                           0000D6   514 _IC1CAPT0	=	0x00d6
                           0000D7   515 G$IC1CAPT1$0$0 == 0x00d7
                           0000D7   516 _IC1CAPT1	=	0x00d7
                           00D7D6   517 G$IC1CAPT$0$0 == 0xd7d6
                           00D7D6   518 _IC1CAPT	=	0xd7d6
                           0000D4   519 G$IC1MODE$0$0 == 0x00d4
                           0000D4   520 _IC1MODE	=	0x00d4
                           0000D5   521 G$IC1STATUS$0$0 == 0x00d5
                           0000D5   522 _IC1STATUS	=	0x00d5
                           000092   523 G$NVADDR0$0$0 == 0x0092
                           000092   524 _NVADDR0	=	0x0092
                           000093   525 G$NVADDR1$0$0 == 0x0093
                           000093   526 _NVADDR1	=	0x0093
                           009392   527 G$NVADDR$0$0 == 0x9392
                           009392   528 _NVADDR	=	0x9392
                           000094   529 G$NVDATA0$0$0 == 0x0094
                           000094   530 _NVDATA0	=	0x0094
                           000095   531 G$NVDATA1$0$0 == 0x0095
                           000095   532 _NVDATA1	=	0x0095
                           009594   533 G$NVDATA$0$0 == 0x9594
                           009594   534 _NVDATA	=	0x9594
                           000096   535 G$NVKEY$0$0 == 0x0096
                           000096   536 _NVKEY	=	0x0096
                           000091   537 G$NVSTATUS$0$0 == 0x0091
                           000091   538 _NVSTATUS	=	0x0091
                           0000BC   539 G$OC0COMP0$0$0 == 0x00bc
                           0000BC   540 _OC0COMP0	=	0x00bc
                           0000BD   541 G$OC0COMP1$0$0 == 0x00bd
                           0000BD   542 _OC0COMP1	=	0x00bd
                           00BDBC   543 G$OC0COMP$0$0 == 0xbdbc
                           00BDBC   544 _OC0COMP	=	0xbdbc
                           0000B9   545 G$OC0MODE$0$0 == 0x00b9
                           0000B9   546 _OC0MODE	=	0x00b9
                           0000BA   547 G$OC0PIN$0$0 == 0x00ba
                           0000BA   548 _OC0PIN	=	0x00ba
                           0000BB   549 G$OC0STATUS$0$0 == 0x00bb
                           0000BB   550 _OC0STATUS	=	0x00bb
                           0000C4   551 G$OC1COMP0$0$0 == 0x00c4
                           0000C4   552 _OC1COMP0	=	0x00c4
                           0000C5   553 G$OC1COMP1$0$0 == 0x00c5
                           0000C5   554 _OC1COMP1	=	0x00c5
                           00C5C4   555 G$OC1COMP$0$0 == 0xc5c4
                           00C5C4   556 _OC1COMP	=	0xc5c4
                           0000C1   557 G$OC1MODE$0$0 == 0x00c1
                           0000C1   558 _OC1MODE	=	0x00c1
                           0000C2   559 G$OC1PIN$0$0 == 0x00c2
                           0000C2   560 _OC1PIN	=	0x00c2
                           0000C3   561 G$OC1STATUS$0$0 == 0x00c3
                           0000C3   562 _OC1STATUS	=	0x00c3
                           0000B1   563 G$RADIOACC$0$0 == 0x00b1
                           0000B1   564 _RADIOACC	=	0x00b1
                           0000B3   565 G$RADIOADDR0$0$0 == 0x00b3
                           0000B3   566 _RADIOADDR0	=	0x00b3
                           0000B2   567 G$RADIOADDR1$0$0 == 0x00b2
                           0000B2   568 _RADIOADDR1	=	0x00b2
                           00B2B3   569 G$RADIOADDR$0$0 == 0xb2b3
                           00B2B3   570 _RADIOADDR	=	0xb2b3
                           0000B7   571 G$RADIODATA0$0$0 == 0x00b7
                           0000B7   572 _RADIODATA0	=	0x00b7
                           0000B6   573 G$RADIODATA1$0$0 == 0x00b6
                           0000B6   574 _RADIODATA1	=	0x00b6
                           0000B5   575 G$RADIODATA2$0$0 == 0x00b5
                           0000B5   576 _RADIODATA2	=	0x00b5
                           0000B4   577 G$RADIODATA3$0$0 == 0x00b4
                           0000B4   578 _RADIODATA3	=	0x00b4
                           B4B5B6B7   579 G$RADIODATA$0$0 == 0xb4b5b6b7
                           B4B5B6B7   580 _RADIODATA	=	0xb4b5b6b7
                           0000BE   581 G$RADIOSTAT0$0$0 == 0x00be
                           0000BE   582 _RADIOSTAT0	=	0x00be
                           0000BF   583 G$RADIOSTAT1$0$0 == 0x00bf
                           0000BF   584 _RADIOSTAT1	=	0x00bf
                           00BFBE   585 G$RADIOSTAT$0$0 == 0xbfbe
                           00BFBE   586 _RADIOSTAT	=	0xbfbe
                           0000DF   587 G$SPCLKSRC$0$0 == 0x00df
                           0000DF   588 _SPCLKSRC	=	0x00df
                           0000DC   589 G$SPMODE$0$0 == 0x00dc
                           0000DC   590 _SPMODE	=	0x00dc
                           0000DE   591 G$SPSHREG$0$0 == 0x00de
                           0000DE   592 _SPSHREG	=	0x00de
                           0000DD   593 G$SPSTATUS$0$0 == 0x00dd
                           0000DD   594 _SPSTATUS	=	0x00dd
                           00009A   595 G$T0CLKSRC$0$0 == 0x009a
                           00009A   596 _T0CLKSRC	=	0x009a
                           00009C   597 G$T0CNT0$0$0 == 0x009c
                           00009C   598 _T0CNT0	=	0x009c
                           00009D   599 G$T0CNT1$0$0 == 0x009d
                           00009D   600 _T0CNT1	=	0x009d
                           009D9C   601 G$T0CNT$0$0 == 0x9d9c
                           009D9C   602 _T0CNT	=	0x9d9c
                           000099   603 G$T0MODE$0$0 == 0x0099
                           000099   604 _T0MODE	=	0x0099
                           00009E   605 G$T0PERIOD0$0$0 == 0x009e
                           00009E   606 _T0PERIOD0	=	0x009e
                           00009F   607 G$T0PERIOD1$0$0 == 0x009f
                           00009F   608 _T0PERIOD1	=	0x009f
                           009F9E   609 G$T0PERIOD$0$0 == 0x9f9e
                           009F9E   610 _T0PERIOD	=	0x9f9e
                           00009B   611 G$T0STATUS$0$0 == 0x009b
                           00009B   612 _T0STATUS	=	0x009b
                           0000A2   613 G$T1CLKSRC$0$0 == 0x00a2
                           0000A2   614 _T1CLKSRC	=	0x00a2
                           0000A4   615 G$T1CNT0$0$0 == 0x00a4
                           0000A4   616 _T1CNT0	=	0x00a4
                           0000A5   617 G$T1CNT1$0$0 == 0x00a5
                           0000A5   618 _T1CNT1	=	0x00a5
                           00A5A4   619 G$T1CNT$0$0 == 0xa5a4
                           00A5A4   620 _T1CNT	=	0xa5a4
                           0000A1   621 G$T1MODE$0$0 == 0x00a1
                           0000A1   622 _T1MODE	=	0x00a1
                           0000A6   623 G$T1PERIOD0$0$0 == 0x00a6
                           0000A6   624 _T1PERIOD0	=	0x00a6
                           0000A7   625 G$T1PERIOD1$0$0 == 0x00a7
                           0000A7   626 _T1PERIOD1	=	0x00a7
                           00A7A6   627 G$T1PERIOD$0$0 == 0xa7a6
                           00A7A6   628 _T1PERIOD	=	0xa7a6
                           0000A3   629 G$T1STATUS$0$0 == 0x00a3
                           0000A3   630 _T1STATUS	=	0x00a3
                           0000AA   631 G$T2CLKSRC$0$0 == 0x00aa
                           0000AA   632 _T2CLKSRC	=	0x00aa
                           0000AC   633 G$T2CNT0$0$0 == 0x00ac
                           0000AC   634 _T2CNT0	=	0x00ac
                           0000AD   635 G$T2CNT1$0$0 == 0x00ad
                           0000AD   636 _T2CNT1	=	0x00ad
                           00ADAC   637 G$T2CNT$0$0 == 0xadac
                           00ADAC   638 _T2CNT	=	0xadac
                           0000A9   639 G$T2MODE$0$0 == 0x00a9
                           0000A9   640 _T2MODE	=	0x00a9
                           0000AE   641 G$T2PERIOD0$0$0 == 0x00ae
                           0000AE   642 _T2PERIOD0	=	0x00ae
                           0000AF   643 G$T2PERIOD1$0$0 == 0x00af
                           0000AF   644 _T2PERIOD1	=	0x00af
                           00AFAE   645 G$T2PERIOD$0$0 == 0xafae
                           00AFAE   646 _T2PERIOD	=	0xafae
                           0000AB   647 G$T2STATUS$0$0 == 0x00ab
                           0000AB   648 _T2STATUS	=	0x00ab
                           0000E4   649 G$U0CTRL$0$0 == 0x00e4
                           0000E4   650 _U0CTRL	=	0x00e4
                           0000E7   651 G$U0MODE$0$0 == 0x00e7
                           0000E7   652 _U0MODE	=	0x00e7
                           0000E6   653 G$U0SHREG$0$0 == 0x00e6
                           0000E6   654 _U0SHREG	=	0x00e6
                           0000E5   655 G$U0STATUS$0$0 == 0x00e5
                           0000E5   656 _U0STATUS	=	0x00e5
                           0000EC   657 G$U1CTRL$0$0 == 0x00ec
                           0000EC   658 _U1CTRL	=	0x00ec
                           0000EF   659 G$U1MODE$0$0 == 0x00ef
                           0000EF   660 _U1MODE	=	0x00ef
                           0000EE   661 G$U1SHREG$0$0 == 0x00ee
                           0000EE   662 _U1SHREG	=	0x00ee
                           0000ED   663 G$U1STATUS$0$0 == 0x00ed
                           0000ED   664 _U1STATUS	=	0x00ed
                           0000DA   665 G$WDTCFG$0$0 == 0x00da
                           0000DA   666 _WDTCFG	=	0x00da
                           0000DB   667 G$WDTRESET$0$0 == 0x00db
                           0000DB   668 _WDTRESET	=	0x00db
                           0000F1   669 G$WTCFGA$0$0 == 0x00f1
                           0000F1   670 _WTCFGA	=	0x00f1
                           0000F9   671 G$WTCFGB$0$0 == 0x00f9
                           0000F9   672 _WTCFGB	=	0x00f9
                           0000F2   673 G$WTCNTA0$0$0 == 0x00f2
                           0000F2   674 _WTCNTA0	=	0x00f2
                           0000F3   675 G$WTCNTA1$0$0 == 0x00f3
                           0000F3   676 _WTCNTA1	=	0x00f3
                           00F3F2   677 G$WTCNTA$0$0 == 0xf3f2
                           00F3F2   678 _WTCNTA	=	0xf3f2
                           0000FA   679 G$WTCNTB0$0$0 == 0x00fa
                           0000FA   680 _WTCNTB0	=	0x00fa
                           0000FB   681 G$WTCNTB1$0$0 == 0x00fb
                           0000FB   682 _WTCNTB1	=	0x00fb
                           00FBFA   683 G$WTCNTB$0$0 == 0xfbfa
                           00FBFA   684 _WTCNTB	=	0xfbfa
                           0000EB   685 G$WTCNTR1$0$0 == 0x00eb
                           0000EB   686 _WTCNTR1	=	0x00eb
                           0000F4   687 G$WTEVTA0$0$0 == 0x00f4
                           0000F4   688 _WTEVTA0	=	0x00f4
                           0000F5   689 G$WTEVTA1$0$0 == 0x00f5
                           0000F5   690 _WTEVTA1	=	0x00f5
                           00F5F4   691 G$WTEVTA$0$0 == 0xf5f4
                           00F5F4   692 _WTEVTA	=	0xf5f4
                           0000F6   693 G$WTEVTB0$0$0 == 0x00f6
                           0000F6   694 _WTEVTB0	=	0x00f6
                           0000F7   695 G$WTEVTB1$0$0 == 0x00f7
                           0000F7   696 _WTEVTB1	=	0x00f7
                           00F7F6   697 G$WTEVTB$0$0 == 0xf7f6
                           00F7F6   698 _WTEVTB	=	0xf7f6
                           0000FC   699 G$WTEVTC0$0$0 == 0x00fc
                           0000FC   700 _WTEVTC0	=	0x00fc
                           0000FD   701 G$WTEVTC1$0$0 == 0x00fd
                           0000FD   702 _WTEVTC1	=	0x00fd
                           00FDFC   703 G$WTEVTC$0$0 == 0xfdfc
                           00FDFC   704 _WTEVTC	=	0xfdfc
                           0000FE   705 G$WTEVTD0$0$0 == 0x00fe
                           0000FE   706 _WTEVTD0	=	0x00fe
                           0000FF   707 G$WTEVTD1$0$0 == 0x00ff
                           0000FF   708 _WTEVTD1	=	0x00ff
                           00FFFE   709 G$WTEVTD$0$0 == 0xfffe
                           00FFFE   710 _WTEVTD	=	0xfffe
                           0000E9   711 G$WTIRQEN$0$0 == 0x00e9
                           0000E9   712 _WTIRQEN	=	0x00e9
                           0000EA   713 G$WTSTAT$0$0 == 0x00ea
                           0000EA   714 _WTSTAT	=	0x00ea
                                    715 ;--------------------------------------------------------
                                    716 ; special function bits
                                    717 ;--------------------------------------------------------
                                    718 	.area RSEG    (ABS,DATA)
      000000                        719 	.org 0x0000
                           0000E0   720 G$ACC_0$0$0 == 0x00e0
                           0000E0   721 _ACC_0	=	0x00e0
                           0000E1   722 G$ACC_1$0$0 == 0x00e1
                           0000E1   723 _ACC_1	=	0x00e1
                           0000E2   724 G$ACC_2$0$0 == 0x00e2
                           0000E2   725 _ACC_2	=	0x00e2
                           0000E3   726 G$ACC_3$0$0 == 0x00e3
                           0000E3   727 _ACC_3	=	0x00e3
                           0000E4   728 G$ACC_4$0$0 == 0x00e4
                           0000E4   729 _ACC_4	=	0x00e4
                           0000E5   730 G$ACC_5$0$0 == 0x00e5
                           0000E5   731 _ACC_5	=	0x00e5
                           0000E6   732 G$ACC_6$0$0 == 0x00e6
                           0000E6   733 _ACC_6	=	0x00e6
                           0000E7   734 G$ACC_7$0$0 == 0x00e7
                           0000E7   735 _ACC_7	=	0x00e7
                           0000F0   736 G$B_0$0$0 == 0x00f0
                           0000F0   737 _B_0	=	0x00f0
                           0000F1   738 G$B_1$0$0 == 0x00f1
                           0000F1   739 _B_1	=	0x00f1
                           0000F2   740 G$B_2$0$0 == 0x00f2
                           0000F2   741 _B_2	=	0x00f2
                           0000F3   742 G$B_3$0$0 == 0x00f3
                           0000F3   743 _B_3	=	0x00f3
                           0000F4   744 G$B_4$0$0 == 0x00f4
                           0000F4   745 _B_4	=	0x00f4
                           0000F5   746 G$B_5$0$0 == 0x00f5
                           0000F5   747 _B_5	=	0x00f5
                           0000F6   748 G$B_6$0$0 == 0x00f6
                           0000F6   749 _B_6	=	0x00f6
                           0000F7   750 G$B_7$0$0 == 0x00f7
                           0000F7   751 _B_7	=	0x00f7
                           0000A0   752 G$E2IE_0$0$0 == 0x00a0
                           0000A0   753 _E2IE_0	=	0x00a0
                           0000A1   754 G$E2IE_1$0$0 == 0x00a1
                           0000A1   755 _E2IE_1	=	0x00a1
                           0000A2   756 G$E2IE_2$0$0 == 0x00a2
                           0000A2   757 _E2IE_2	=	0x00a2
                           0000A3   758 G$E2IE_3$0$0 == 0x00a3
                           0000A3   759 _E2IE_3	=	0x00a3
                           0000A4   760 G$E2IE_4$0$0 == 0x00a4
                           0000A4   761 _E2IE_4	=	0x00a4
                           0000A5   762 G$E2IE_5$0$0 == 0x00a5
                           0000A5   763 _E2IE_5	=	0x00a5
                           0000A6   764 G$E2IE_6$0$0 == 0x00a6
                           0000A6   765 _E2IE_6	=	0x00a6
                           0000A7   766 G$E2IE_7$0$0 == 0x00a7
                           0000A7   767 _E2IE_7	=	0x00a7
                           0000C0   768 G$E2IP_0$0$0 == 0x00c0
                           0000C0   769 _E2IP_0	=	0x00c0
                           0000C1   770 G$E2IP_1$0$0 == 0x00c1
                           0000C1   771 _E2IP_1	=	0x00c1
                           0000C2   772 G$E2IP_2$0$0 == 0x00c2
                           0000C2   773 _E2IP_2	=	0x00c2
                           0000C3   774 G$E2IP_3$0$0 == 0x00c3
                           0000C3   775 _E2IP_3	=	0x00c3
                           0000C4   776 G$E2IP_4$0$0 == 0x00c4
                           0000C4   777 _E2IP_4	=	0x00c4
                           0000C5   778 G$E2IP_5$0$0 == 0x00c5
                           0000C5   779 _E2IP_5	=	0x00c5
                           0000C6   780 G$E2IP_6$0$0 == 0x00c6
                           0000C6   781 _E2IP_6	=	0x00c6
                           0000C7   782 G$E2IP_7$0$0 == 0x00c7
                           0000C7   783 _E2IP_7	=	0x00c7
                           000098   784 G$EIE_0$0$0 == 0x0098
                           000098   785 _EIE_0	=	0x0098
                           000099   786 G$EIE_1$0$0 == 0x0099
                           000099   787 _EIE_1	=	0x0099
                           00009A   788 G$EIE_2$0$0 == 0x009a
                           00009A   789 _EIE_2	=	0x009a
                           00009B   790 G$EIE_3$0$0 == 0x009b
                           00009B   791 _EIE_3	=	0x009b
                           00009C   792 G$EIE_4$0$0 == 0x009c
                           00009C   793 _EIE_4	=	0x009c
                           00009D   794 G$EIE_5$0$0 == 0x009d
                           00009D   795 _EIE_5	=	0x009d
                           00009E   796 G$EIE_6$0$0 == 0x009e
                           00009E   797 _EIE_6	=	0x009e
                           00009F   798 G$EIE_7$0$0 == 0x009f
                           00009F   799 _EIE_7	=	0x009f
                           0000B0   800 G$EIP_0$0$0 == 0x00b0
                           0000B0   801 _EIP_0	=	0x00b0
                           0000B1   802 G$EIP_1$0$0 == 0x00b1
                           0000B1   803 _EIP_1	=	0x00b1
                           0000B2   804 G$EIP_2$0$0 == 0x00b2
                           0000B2   805 _EIP_2	=	0x00b2
                           0000B3   806 G$EIP_3$0$0 == 0x00b3
                           0000B3   807 _EIP_3	=	0x00b3
                           0000B4   808 G$EIP_4$0$0 == 0x00b4
                           0000B4   809 _EIP_4	=	0x00b4
                           0000B5   810 G$EIP_5$0$0 == 0x00b5
                           0000B5   811 _EIP_5	=	0x00b5
                           0000B6   812 G$EIP_6$0$0 == 0x00b6
                           0000B6   813 _EIP_6	=	0x00b6
                           0000B7   814 G$EIP_7$0$0 == 0x00b7
                           0000B7   815 _EIP_7	=	0x00b7
                           0000A8   816 G$IE_0$0$0 == 0x00a8
                           0000A8   817 _IE_0	=	0x00a8
                           0000A9   818 G$IE_1$0$0 == 0x00a9
                           0000A9   819 _IE_1	=	0x00a9
                           0000AA   820 G$IE_2$0$0 == 0x00aa
                           0000AA   821 _IE_2	=	0x00aa
                           0000AB   822 G$IE_3$0$0 == 0x00ab
                           0000AB   823 _IE_3	=	0x00ab
                           0000AC   824 G$IE_4$0$0 == 0x00ac
                           0000AC   825 _IE_4	=	0x00ac
                           0000AD   826 G$IE_5$0$0 == 0x00ad
                           0000AD   827 _IE_5	=	0x00ad
                           0000AE   828 G$IE_6$0$0 == 0x00ae
                           0000AE   829 _IE_6	=	0x00ae
                           0000AF   830 G$IE_7$0$0 == 0x00af
                           0000AF   831 _IE_7	=	0x00af
                           0000AF   832 G$EA$0$0 == 0x00af
                           0000AF   833 _EA	=	0x00af
                           0000B8   834 G$IP_0$0$0 == 0x00b8
                           0000B8   835 _IP_0	=	0x00b8
                           0000B9   836 G$IP_1$0$0 == 0x00b9
                           0000B9   837 _IP_1	=	0x00b9
                           0000BA   838 G$IP_2$0$0 == 0x00ba
                           0000BA   839 _IP_2	=	0x00ba
                           0000BB   840 G$IP_3$0$0 == 0x00bb
                           0000BB   841 _IP_3	=	0x00bb
                           0000BC   842 G$IP_4$0$0 == 0x00bc
                           0000BC   843 _IP_4	=	0x00bc
                           0000BD   844 G$IP_5$0$0 == 0x00bd
                           0000BD   845 _IP_5	=	0x00bd
                           0000BE   846 G$IP_6$0$0 == 0x00be
                           0000BE   847 _IP_6	=	0x00be
                           0000BF   848 G$IP_7$0$0 == 0x00bf
                           0000BF   849 _IP_7	=	0x00bf
                           0000D0   850 G$P$0$0 == 0x00d0
                           0000D0   851 _P	=	0x00d0
                           0000D1   852 G$F1$0$0 == 0x00d1
                           0000D1   853 _F1	=	0x00d1
                           0000D2   854 G$OV$0$0 == 0x00d2
                           0000D2   855 _OV	=	0x00d2
                           0000D3   856 G$RS0$0$0 == 0x00d3
                           0000D3   857 _RS0	=	0x00d3
                           0000D4   858 G$RS1$0$0 == 0x00d4
                           0000D4   859 _RS1	=	0x00d4
                           0000D5   860 G$F0$0$0 == 0x00d5
                           0000D5   861 _F0	=	0x00d5
                           0000D6   862 G$AC$0$0 == 0x00d6
                           0000D6   863 _AC	=	0x00d6
                           0000D7   864 G$CY$0$0 == 0x00d7
                           0000D7   865 _CY	=	0x00d7
                           0000C8   866 G$PINA_0$0$0 == 0x00c8
                           0000C8   867 _PINA_0	=	0x00c8
                           0000C9   868 G$PINA_1$0$0 == 0x00c9
                           0000C9   869 _PINA_1	=	0x00c9
                           0000CA   870 G$PINA_2$0$0 == 0x00ca
                           0000CA   871 _PINA_2	=	0x00ca
                           0000CB   872 G$PINA_3$0$0 == 0x00cb
                           0000CB   873 _PINA_3	=	0x00cb
                           0000CC   874 G$PINA_4$0$0 == 0x00cc
                           0000CC   875 _PINA_4	=	0x00cc
                           0000CD   876 G$PINA_5$0$0 == 0x00cd
                           0000CD   877 _PINA_5	=	0x00cd
                           0000CE   878 G$PINA_6$0$0 == 0x00ce
                           0000CE   879 _PINA_6	=	0x00ce
                           0000CF   880 G$PINA_7$0$0 == 0x00cf
                           0000CF   881 _PINA_7	=	0x00cf
                           0000E8   882 G$PINB_0$0$0 == 0x00e8
                           0000E8   883 _PINB_0	=	0x00e8
                           0000E9   884 G$PINB_1$0$0 == 0x00e9
                           0000E9   885 _PINB_1	=	0x00e9
                           0000EA   886 G$PINB_2$0$0 == 0x00ea
                           0000EA   887 _PINB_2	=	0x00ea
                           0000EB   888 G$PINB_3$0$0 == 0x00eb
                           0000EB   889 _PINB_3	=	0x00eb
                           0000EC   890 G$PINB_4$0$0 == 0x00ec
                           0000EC   891 _PINB_4	=	0x00ec
                           0000ED   892 G$PINB_5$0$0 == 0x00ed
                           0000ED   893 _PINB_5	=	0x00ed
                           0000EE   894 G$PINB_6$0$0 == 0x00ee
                           0000EE   895 _PINB_6	=	0x00ee
                           0000EF   896 G$PINB_7$0$0 == 0x00ef
                           0000EF   897 _PINB_7	=	0x00ef
                           0000F8   898 G$PINC_0$0$0 == 0x00f8
                           0000F8   899 _PINC_0	=	0x00f8
                           0000F9   900 G$PINC_1$0$0 == 0x00f9
                           0000F9   901 _PINC_1	=	0x00f9
                           0000FA   902 G$PINC_2$0$0 == 0x00fa
                           0000FA   903 _PINC_2	=	0x00fa
                           0000FB   904 G$PINC_3$0$0 == 0x00fb
                           0000FB   905 _PINC_3	=	0x00fb
                           0000FC   906 G$PINC_4$0$0 == 0x00fc
                           0000FC   907 _PINC_4	=	0x00fc
                           0000FD   908 G$PINC_5$0$0 == 0x00fd
                           0000FD   909 _PINC_5	=	0x00fd
                           0000FE   910 G$PINC_6$0$0 == 0x00fe
                           0000FE   911 _PINC_6	=	0x00fe
                           0000FF   912 G$PINC_7$0$0 == 0x00ff
                           0000FF   913 _PINC_7	=	0x00ff
                           000080   914 G$PORTA_0$0$0 == 0x0080
                           000080   915 _PORTA_0	=	0x0080
                           000081   916 G$PORTA_1$0$0 == 0x0081
                           000081   917 _PORTA_1	=	0x0081
                           000082   918 G$PORTA_2$0$0 == 0x0082
                           000082   919 _PORTA_2	=	0x0082
                           000083   920 G$PORTA_3$0$0 == 0x0083
                           000083   921 _PORTA_3	=	0x0083
                           000084   922 G$PORTA_4$0$0 == 0x0084
                           000084   923 _PORTA_4	=	0x0084
                           000085   924 G$PORTA_5$0$0 == 0x0085
                           000085   925 _PORTA_5	=	0x0085
                           000086   926 G$PORTA_6$0$0 == 0x0086
                           000086   927 _PORTA_6	=	0x0086
                           000087   928 G$PORTA_7$0$0 == 0x0087
                           000087   929 _PORTA_7	=	0x0087
                           000088   930 G$PORTB_0$0$0 == 0x0088
                           000088   931 _PORTB_0	=	0x0088
                           000089   932 G$PORTB_1$0$0 == 0x0089
                           000089   933 _PORTB_1	=	0x0089
                           00008A   934 G$PORTB_2$0$0 == 0x008a
                           00008A   935 _PORTB_2	=	0x008a
                           00008B   936 G$PORTB_3$0$0 == 0x008b
                           00008B   937 _PORTB_3	=	0x008b
                           00008C   938 G$PORTB_4$0$0 == 0x008c
                           00008C   939 _PORTB_4	=	0x008c
                           00008D   940 G$PORTB_5$0$0 == 0x008d
                           00008D   941 _PORTB_5	=	0x008d
                           00008E   942 G$PORTB_6$0$0 == 0x008e
                           00008E   943 _PORTB_6	=	0x008e
                           00008F   944 G$PORTB_7$0$0 == 0x008f
                           00008F   945 _PORTB_7	=	0x008f
                           000090   946 G$PORTC_0$0$0 == 0x0090
                           000090   947 _PORTC_0	=	0x0090
                           000091   948 G$PORTC_1$0$0 == 0x0091
                           000091   949 _PORTC_1	=	0x0091
                           000092   950 G$PORTC_2$0$0 == 0x0092
                           000092   951 _PORTC_2	=	0x0092
                           000093   952 G$PORTC_3$0$0 == 0x0093
                           000093   953 _PORTC_3	=	0x0093
                           000094   954 G$PORTC_4$0$0 == 0x0094
                           000094   955 _PORTC_4	=	0x0094
                           000095   956 G$PORTC_5$0$0 == 0x0095
                           000095   957 _PORTC_5	=	0x0095
                           000096   958 G$PORTC_6$0$0 == 0x0096
                           000096   959 _PORTC_6	=	0x0096
                           000097   960 G$PORTC_7$0$0 == 0x0097
                           000097   961 _PORTC_7	=	0x0097
                                    962 ;--------------------------------------------------------
                                    963 ; overlayable register banks
                                    964 ;--------------------------------------------------------
                                    965 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        966 	.ds 8
                                    967 ;--------------------------------------------------------
                                    968 ; internal ram data
                                    969 ;--------------------------------------------------------
                                    970 	.area DSEG    (DATA)
                           000000   971 G$coldstart$0$0==.
      000022                        972 _coldstart::
      000022                        973 	.ds 1
                           000001   974 G$BER_TEST$0$0==.
      000023                        975 _BER_TEST::
      000023                        976 	.ds 1
                           000002   977 G$scr$0$0==.
      000024                        978 _scr::
      000024                        979 	.ds 4
                           000006   980 G$bytes$0$0==.
      000028                        981 _bytes::
      000028                        982 	.ds 4
                           00000A   983 G$errors$0$0==.
      00002C                        984 _errors::
      00002C                        985 	.ds 4
                           00000E   986 G$errors2$0$0==.
      000030                        987 _errors2::
      000030                        988 	.ds 4
                           000012   989 G$acquire_agc$0$0==.
      000034                        990 _acquire_agc::
      000034                        991 	.ds 1
                           000013   992 Lmain.process_ber$databyte$6$323==.
      000035                        993 _process_ber_databyte_6_323:
      000035                        994 	.ds 1
                           000014   995 Lmain.process_ber$sloc0$1$0==.
      000036                        996 _process_ber_sloc0_1_0:
      000036                        997 	.ds 1
                           000015   998 Lmain.process_ber$sloc1$1$0==.
      000037                        999 _process_ber_sloc1_1_0:
      000037                       1000 	.ds 2
                                   1001 ;--------------------------------------------------------
                                   1002 ; overlayable items in internal ram 
                                   1003 ;--------------------------------------------------------
                                   1004 	.area	OSEG    (OVR,DATA)
                                   1005 	.area	OSEG    (OVR,DATA)
                                   1006 ;--------------------------------------------------------
                                   1007 ; Stack segment in internal ram 
                                   1008 ;--------------------------------------------------------
                                   1009 	.area	SSEG
      00004C                       1010 __start__stack:
      00004C                       1011 	.ds	1
                                   1012 
                                   1013 ;--------------------------------------------------------
                                   1014 ; indirectly addressable internal ram data
                                   1015 ;--------------------------------------------------------
                                   1016 	.area ISEG    (DATA)
                                   1017 ;--------------------------------------------------------
                                   1018 ; absolute internal ram data
                                   1019 ;--------------------------------------------------------
                                   1020 	.area IABS    (ABS,DATA)
                                   1021 	.area IABS    (ABS,DATA)
                                   1022 ;--------------------------------------------------------
                                   1023 ; bit data
                                   1024 ;--------------------------------------------------------
                                   1025 	.area BSEG    (BIT)
                           000000  1026 Lmain._sdcc_external_startup$sloc0$1$0==.
      000001                       1027 __sdcc_external_startup_sloc0_1_0:
      000001                       1028 	.ds 1
                                   1029 ;--------------------------------------------------------
                                   1030 ; paged external ram data
                                   1031 ;--------------------------------------------------------
                                   1032 	.area PSEG    (PAG,XDATA)
                                   1033 ;--------------------------------------------------------
                                   1034 ; external ram data
                                   1035 ;--------------------------------------------------------
                                   1036 	.area XSEG    (XDATA)
                           007020  1037 G$ADCCH0VAL0$0$0 == 0x7020
                           007020  1038 _ADCCH0VAL0	=	0x7020
                           007021  1039 G$ADCCH0VAL1$0$0 == 0x7021
                           007021  1040 _ADCCH0VAL1	=	0x7021
                           007020  1041 G$ADCCH0VAL$0$0 == 0x7020
                           007020  1042 _ADCCH0VAL	=	0x7020
                           007022  1043 G$ADCCH1VAL0$0$0 == 0x7022
                           007022  1044 _ADCCH1VAL0	=	0x7022
                           007023  1045 G$ADCCH1VAL1$0$0 == 0x7023
                           007023  1046 _ADCCH1VAL1	=	0x7023
                           007022  1047 G$ADCCH1VAL$0$0 == 0x7022
                           007022  1048 _ADCCH1VAL	=	0x7022
                           007024  1049 G$ADCCH2VAL0$0$0 == 0x7024
                           007024  1050 _ADCCH2VAL0	=	0x7024
                           007025  1051 G$ADCCH2VAL1$0$0 == 0x7025
                           007025  1052 _ADCCH2VAL1	=	0x7025
                           007024  1053 G$ADCCH2VAL$0$0 == 0x7024
                           007024  1054 _ADCCH2VAL	=	0x7024
                           007026  1055 G$ADCCH3VAL0$0$0 == 0x7026
                           007026  1056 _ADCCH3VAL0	=	0x7026
                           007027  1057 G$ADCCH3VAL1$0$0 == 0x7027
                           007027  1058 _ADCCH3VAL1	=	0x7027
                           007026  1059 G$ADCCH3VAL$0$0 == 0x7026
                           007026  1060 _ADCCH3VAL	=	0x7026
                           007028  1061 G$ADCTUNE0$0$0 == 0x7028
                           007028  1062 _ADCTUNE0	=	0x7028
                           007029  1063 G$ADCTUNE1$0$0 == 0x7029
                           007029  1064 _ADCTUNE1	=	0x7029
                           00702A  1065 G$ADCTUNE2$0$0 == 0x702a
                           00702A  1066 _ADCTUNE2	=	0x702a
                           007010  1067 G$DMA0ADDR0$0$0 == 0x7010
                           007010  1068 _DMA0ADDR0	=	0x7010
                           007011  1069 G$DMA0ADDR1$0$0 == 0x7011
                           007011  1070 _DMA0ADDR1	=	0x7011
                           007010  1071 G$DMA0ADDR$0$0 == 0x7010
                           007010  1072 _DMA0ADDR	=	0x7010
                           007014  1073 G$DMA0CONFIG$0$0 == 0x7014
                           007014  1074 _DMA0CONFIG	=	0x7014
                           007012  1075 G$DMA1ADDR0$0$0 == 0x7012
                           007012  1076 _DMA1ADDR0	=	0x7012
                           007013  1077 G$DMA1ADDR1$0$0 == 0x7013
                           007013  1078 _DMA1ADDR1	=	0x7013
                           007012  1079 G$DMA1ADDR$0$0 == 0x7012
                           007012  1080 _DMA1ADDR	=	0x7012
                           007015  1081 G$DMA1CONFIG$0$0 == 0x7015
                           007015  1082 _DMA1CONFIG	=	0x7015
                           007070  1083 G$FRCOSCCONFIG$0$0 == 0x7070
                           007070  1084 _FRCOSCCONFIG	=	0x7070
                           007071  1085 G$FRCOSCCTRL$0$0 == 0x7071
                           007071  1086 _FRCOSCCTRL	=	0x7071
                           007076  1087 G$FRCOSCFREQ0$0$0 == 0x7076
                           007076  1088 _FRCOSCFREQ0	=	0x7076
                           007077  1089 G$FRCOSCFREQ1$0$0 == 0x7077
                           007077  1090 _FRCOSCFREQ1	=	0x7077
                           007076  1091 G$FRCOSCFREQ$0$0 == 0x7076
                           007076  1092 _FRCOSCFREQ	=	0x7076
                           007072  1093 G$FRCOSCKFILT0$0$0 == 0x7072
                           007072  1094 _FRCOSCKFILT0	=	0x7072
                           007073  1095 G$FRCOSCKFILT1$0$0 == 0x7073
                           007073  1096 _FRCOSCKFILT1	=	0x7073
                           007072  1097 G$FRCOSCKFILT$0$0 == 0x7072
                           007072  1098 _FRCOSCKFILT	=	0x7072
                           007078  1099 G$FRCOSCPER0$0$0 == 0x7078
                           007078  1100 _FRCOSCPER0	=	0x7078
                           007079  1101 G$FRCOSCPER1$0$0 == 0x7079
                           007079  1102 _FRCOSCPER1	=	0x7079
                           007078  1103 G$FRCOSCPER$0$0 == 0x7078
                           007078  1104 _FRCOSCPER	=	0x7078
                           007074  1105 G$FRCOSCREF0$0$0 == 0x7074
                           007074  1106 _FRCOSCREF0	=	0x7074
                           007075  1107 G$FRCOSCREF1$0$0 == 0x7075
                           007075  1108 _FRCOSCREF1	=	0x7075
                           007074  1109 G$FRCOSCREF$0$0 == 0x7074
                           007074  1110 _FRCOSCREF	=	0x7074
                           007007  1111 G$ANALOGA$0$0 == 0x7007
                           007007  1112 _ANALOGA	=	0x7007
                           00700C  1113 G$GPIOENABLE$0$0 == 0x700c
                           00700C  1114 _GPIOENABLE	=	0x700c
                           007003  1115 G$EXTIRQ$0$0 == 0x7003
                           007003  1116 _EXTIRQ	=	0x7003
                           007000  1117 G$INTCHGA$0$0 == 0x7000
                           007000  1118 _INTCHGA	=	0x7000
                           007001  1119 G$INTCHGB$0$0 == 0x7001
                           007001  1120 _INTCHGB	=	0x7001
                           007002  1121 G$INTCHGC$0$0 == 0x7002
                           007002  1122 _INTCHGC	=	0x7002
                           007008  1123 G$PALTA$0$0 == 0x7008
                           007008  1124 _PALTA	=	0x7008
                           007009  1125 G$PALTB$0$0 == 0x7009
                           007009  1126 _PALTB	=	0x7009
                           00700A  1127 G$PALTC$0$0 == 0x700a
                           00700A  1128 _PALTC	=	0x700a
                           007046  1129 G$PALTRADIO$0$0 == 0x7046
                           007046  1130 _PALTRADIO	=	0x7046
                           007004  1131 G$PINCHGA$0$0 == 0x7004
                           007004  1132 _PINCHGA	=	0x7004
                           007005  1133 G$PINCHGB$0$0 == 0x7005
                           007005  1134 _PINCHGB	=	0x7005
                           007006  1135 G$PINCHGC$0$0 == 0x7006
                           007006  1136 _PINCHGC	=	0x7006
                           00700B  1137 G$PINSEL$0$0 == 0x700b
                           00700B  1138 _PINSEL	=	0x700b
                           007060  1139 G$LPOSCCONFIG$0$0 == 0x7060
                           007060  1140 _LPOSCCONFIG	=	0x7060
                           007066  1141 G$LPOSCFREQ0$0$0 == 0x7066
                           007066  1142 _LPOSCFREQ0	=	0x7066
                           007067  1143 G$LPOSCFREQ1$0$0 == 0x7067
                           007067  1144 _LPOSCFREQ1	=	0x7067
                           007066  1145 G$LPOSCFREQ$0$0 == 0x7066
                           007066  1146 _LPOSCFREQ	=	0x7066
                           007062  1147 G$LPOSCKFILT0$0$0 == 0x7062
                           007062  1148 _LPOSCKFILT0	=	0x7062
                           007063  1149 G$LPOSCKFILT1$0$0 == 0x7063
                           007063  1150 _LPOSCKFILT1	=	0x7063
                           007062  1151 G$LPOSCKFILT$0$0 == 0x7062
                           007062  1152 _LPOSCKFILT	=	0x7062
                           007068  1153 G$LPOSCPER0$0$0 == 0x7068
                           007068  1154 _LPOSCPER0	=	0x7068
                           007069  1155 G$LPOSCPER1$0$0 == 0x7069
                           007069  1156 _LPOSCPER1	=	0x7069
                           007068  1157 G$LPOSCPER$0$0 == 0x7068
                           007068  1158 _LPOSCPER	=	0x7068
                           007064  1159 G$LPOSCREF0$0$0 == 0x7064
                           007064  1160 _LPOSCREF0	=	0x7064
                           007065  1161 G$LPOSCREF1$0$0 == 0x7065
                           007065  1162 _LPOSCREF1	=	0x7065
                           007064  1163 G$LPOSCREF$0$0 == 0x7064
                           007064  1164 _LPOSCREF	=	0x7064
                           007054  1165 G$LPXOSCGM$0$0 == 0x7054
                           007054  1166 _LPXOSCGM	=	0x7054
                           007F01  1167 G$MISCCTRL$0$0 == 0x7f01
                           007F01  1168 _MISCCTRL	=	0x7f01
                           007053  1169 G$OSCCALIB$0$0 == 0x7053
                           007053  1170 _OSCCALIB	=	0x7053
                           007050  1171 G$OSCFORCERUN$0$0 == 0x7050
                           007050  1172 _OSCFORCERUN	=	0x7050
                           007052  1173 G$OSCREADY$0$0 == 0x7052
                           007052  1174 _OSCREADY	=	0x7052
                           007051  1175 G$OSCRUN$0$0 == 0x7051
                           007051  1176 _OSCRUN	=	0x7051
                           007040  1177 G$RADIOFDATAADDR0$0$0 == 0x7040
                           007040  1178 _RADIOFDATAADDR0	=	0x7040
                           007041  1179 G$RADIOFDATAADDR1$0$0 == 0x7041
                           007041  1180 _RADIOFDATAADDR1	=	0x7041
                           007040  1181 G$RADIOFDATAADDR$0$0 == 0x7040
                           007040  1182 _RADIOFDATAADDR	=	0x7040
                           007042  1183 G$RADIOFSTATADDR0$0$0 == 0x7042
                           007042  1184 _RADIOFSTATADDR0	=	0x7042
                           007043  1185 G$RADIOFSTATADDR1$0$0 == 0x7043
                           007043  1186 _RADIOFSTATADDR1	=	0x7043
                           007042  1187 G$RADIOFSTATADDR$0$0 == 0x7042
                           007042  1188 _RADIOFSTATADDR	=	0x7042
                           007044  1189 G$RADIOMUX$0$0 == 0x7044
                           007044  1190 _RADIOMUX	=	0x7044
                           007084  1191 G$SCRATCH0$0$0 == 0x7084
                           007084  1192 _SCRATCH0	=	0x7084
                           007085  1193 G$SCRATCH1$0$0 == 0x7085
                           007085  1194 _SCRATCH1	=	0x7085
                           007086  1195 G$SCRATCH2$0$0 == 0x7086
                           007086  1196 _SCRATCH2	=	0x7086
                           007087  1197 G$SCRATCH3$0$0 == 0x7087
                           007087  1198 _SCRATCH3	=	0x7087
                           007F00  1199 G$SILICONREV$0$0 == 0x7f00
                           007F00  1200 _SILICONREV	=	0x7f00
                           007F19  1201 G$XTALAMPL$0$0 == 0x7f19
                           007F19  1202 _XTALAMPL	=	0x7f19
                           007F18  1203 G$XTALOSC$0$0 == 0x7f18
                           007F18  1204 _XTALOSC	=	0x7f18
                           007F1A  1205 G$XTALREADY$0$0 == 0x7f1a
                           007F1A  1206 _XTALREADY	=	0x7f1a
                           00FC06  1207 Fmain$flash_deviceid$0$0 == 0xfc06
                           00FC06  1208 _flash_deviceid	=	0xfc06
                           00FC00  1209 Fmain$flash_calsector$0$0 == 0xfc00
                           00FC00  1210 _flash_calsector	=	0xfc00
                           000000  1211 G$txdata$0$0==.
      0002AD                       1212 _txdata::
      0002AD                       1213 	.ds 8
                                   1214 ;--------------------------------------------------------
                                   1215 ; absolute external ram data
                                   1216 ;--------------------------------------------------------
                                   1217 	.area XABS    (ABS,XDATA)
                                   1218 ;--------------------------------------------------------
                                   1219 ; external initialized ram data
                                   1220 ;--------------------------------------------------------
                                   1221 	.area XISEG   (XDATA)
                                   1222 	.area HOME    (CODE)
                                   1223 	.area GSINIT0 (CODE)
                                   1224 	.area GSINIT1 (CODE)
                                   1225 	.area GSINIT2 (CODE)
                                   1226 	.area GSINIT3 (CODE)
                                   1227 	.area GSINIT4 (CODE)
                                   1228 	.area GSINIT5 (CODE)
                                   1229 	.area GSINIT  (CODE)
                                   1230 	.area GSFINAL (CODE)
                                   1231 	.area CSEG    (CODE)
                                   1232 ;--------------------------------------------------------
                                   1233 ; interrupt vector 
                                   1234 ;--------------------------------------------------------
                                   1235 	.area HOME    (CODE)
      000000                       1236 __interrupt_vect:
      000000 02 03 11         [24] 1237 	ljmp	__sdcc_gsinit_startup
      000003 32               [24] 1238 	reti
      000004                       1239 	.ds	7
      00000B 02 00 B1         [24] 1240 	ljmp	_wtimer_irq
      00000E                       1241 	.ds	5
      000013 32               [24] 1242 	reti
      000014                       1243 	.ds	7
      00001B 32               [24] 1244 	reti
      00001C                       1245 	.ds	7
      000023 02 12 09         [24] 1246 	ljmp	_axradio_isr
      000026                       1247 	.ds	5
      00002B 32               [24] 1248 	reti
      00002C                       1249 	.ds	7
      000033 02 3C 63         [24] 1250 	ljmp	_pwrmgmt_irq
      000036                       1251 	.ds	5
      00003B 32               [24] 1252 	reti
      00003C                       1253 	.ds	7
      000043 32               [24] 1254 	reti
      000044                       1255 	.ds	7
      00004B 32               [24] 1256 	reti
      00004C                       1257 	.ds	7
      000053 32               [24] 1258 	reti
      000054                       1259 	.ds	7
      00005B 02 02 A3         [24] 1260 	ljmp	_uart0_irq
      00005E                       1261 	.ds	5
      000063 02 02 DA         [24] 1262 	ljmp	_uart1_irq
      000066                       1263 	.ds	5
      00006B 32               [24] 1264 	reti
      00006C                       1265 	.ds	7
      000073 32               [24] 1266 	reti
      000074                       1267 	.ds	7
      00007B 32               [24] 1268 	reti
      00007C                       1269 	.ds	7
      000083 32               [24] 1270 	reti
      000084                       1271 	.ds	7
      00008B 32               [24] 1272 	reti
      00008C                       1273 	.ds	7
      000093 32               [24] 1274 	reti
      000094                       1275 	.ds	7
      00009B 32               [24] 1276 	reti
      00009C                       1277 	.ds	7
      0000A3 32               [24] 1278 	reti
      0000A4                       1279 	.ds	7
      0000AB 02 02 6C         [24] 1280 	ljmp	_dbglink_irq
                                   1281 ;--------------------------------------------------------
                                   1282 ; global & static initialisations
                                   1283 ;--------------------------------------------------------
                                   1284 	.area HOME    (CODE)
                                   1285 	.area GSINIT  (CODE)
                                   1286 	.area GSFINAL (CODE)
                                   1287 	.area GSINIT  (CODE)
                                   1288 	.globl __sdcc_gsinit_startup
                                   1289 	.globl __sdcc_program_startup
                                   1290 	.globl __start__stack
                                   1291 	.globl __mcs51_genXINIT
                                   1292 	.globl __mcs51_genXRAMCLEAR
                                   1293 	.globl __mcs51_genRAMCLEAR
                           000000  1294 	C$main.c$66$1$414 ==.
                                   1295 ;	main.c:66: uint8_t __data coldstart = 1; /* caution: initialization with 1 is necessary! Variables are initialized upon _sdcc_external_startup returning 0 -> the coldstart value returned from _sdcc_external startup does not survive in the coldstart case */
      00038A 75 22 01         [24] 1296 	mov	_coldstart,#0x01
                                   1297 	.area GSFINAL (CODE)
      00038D 02 00 AE         [24] 1298 	ljmp	__sdcc_program_startup
                                   1299 ;--------------------------------------------------------
                                   1300 ; Home
                                   1301 ;--------------------------------------------------------
                                   1302 	.area HOME    (CODE)
                                   1303 	.area HOME    (CODE)
      0000AE                       1304 __sdcc_program_startup:
      0000AE 02 3F 6D         [24] 1305 	ljmp	_main
                                   1306 ;	return from main will return to caller
                                   1307 ;--------------------------------------------------------
                                   1308 ; code
                                   1309 ;--------------------------------------------------------
                                   1310 	.area CSEG    (CODE)
                                   1311 ;------------------------------------------------------------
                                   1312 ;Allocation info for local variables in function 'pwrmgmt_irq'
                                   1313 ;------------------------------------------------------------
                                   1314 ;pc                        Allocated to registers r7 
                                   1315 ;------------------------------------------------------------
                           000000  1316 	Fmain$pwrmgmt_irq$0$0 ==.
                           000000  1317 	C$main.c$146$0$0 ==.
                                   1318 ;	main.c:146: static void pwrmgmt_irq(void) __interrupt(INT_POWERMGMT)
                                   1319 ;	-----------------------------------------
                                   1320 ;	 function pwrmgmt_irq
                                   1321 ;	-----------------------------------------
      003C63                       1322 _pwrmgmt_irq:
                           000007  1323 	ar7 = 0x07
                           000006  1324 	ar6 = 0x06
                           000005  1325 	ar5 = 0x05
                           000004  1326 	ar4 = 0x04
                           000003  1327 	ar3 = 0x03
                           000002  1328 	ar2 = 0x02
                           000001  1329 	ar1 = 0x01
                           000000  1330 	ar0 = 0x00
      003C63 C0 E0            [24] 1331 	push	acc
      003C65 C0 82            [24] 1332 	push	dpl
      003C67 C0 83            [24] 1333 	push	dph
      003C69 C0 07            [24] 1334 	push	ar7
      003C6B C0 D0            [24] 1335 	push	psw
      003C6D 75 D0 00         [24] 1336 	mov	psw,#0x00
                           00000D  1337 	C$main.c$148$1$0 ==.
                                   1338 ;	main.c:148: uint8_t pc = PCON;
                           00000D  1339 	C$main.c$150$1$311 ==.
                                   1340 ;	main.c:150: if (!(pc & 0x80))
      003C70 E5 87            [12] 1341 	mov	a,_PCON
      003C72 FF               [12] 1342 	mov	r7,a
      003C73 20 E7 02         [24] 1343 	jb	acc.7,00102$
                           000013  1344 	C$main.c$151$1$311 ==.
                                   1345 ;	main.c:151: return;
      003C76 80 10            [24] 1346 	sjmp	00106$
      003C78                       1347 00102$:
                           000015  1348 	C$main.c$153$1$311 ==.
                                   1349 ;	main.c:153: GPIOENABLE = 0;
      003C78 90 70 0C         [24] 1350 	mov	dptr,#_GPIOENABLE
      003C7B E4               [12] 1351 	clr	a
      003C7C F0               [24] 1352 	movx	@dptr,a
                           00001A  1353 	C$main.c$154$1$311 ==.
                                   1354 ;	main.c:154: IE = EIE = E2IE = 0;
                                   1355 ;	1-genFromRTrack replaced	mov	_E2IE,#0x00
      003C7D F5 A0            [12] 1356 	mov	_E2IE,a
                                   1357 ;	1-genFromRTrack replaced	mov	_EIE,#0x00
      003C7F F5 98            [12] 1358 	mov	_EIE,a
                                   1359 ;	1-genFromRTrack replaced	mov	_IE,#0x00
      003C81 F5 A8            [12] 1360 	mov	_IE,a
      003C83                       1361 00104$:
                           000020  1362 	C$main.c$157$1$311 ==.
                                   1363 ;	main.c:157: PCON |= 0x01;
      003C83 43 87 01         [24] 1364 	orl	_PCON,#0x01
      003C86 80 FB            [24] 1365 	sjmp	00104$
      003C88                       1366 00106$:
      003C88 D0 D0            [24] 1367 	pop	psw
      003C8A D0 07            [24] 1368 	pop	ar7
      003C8C D0 83            [24] 1369 	pop	dph
      003C8E D0 82            [24] 1370 	pop	dpl
      003C90 D0 E0            [24] 1371 	pop	acc
                           00002F  1372 	C$main.c$158$1$311 ==.
                           00002F  1373 	XFmain$pwrmgmt_irq$0$0 ==.
      003C92 32               [24] 1374 	reti
                                   1375 ;	eliminated unneeded push/pop b
                                   1376 ;------------------------------------------------------------
                                   1377 ;Allocation info for local variables in function 'correct_ber'
                                   1378 ;------------------------------------------------------------
                                   1379 ;x                         Allocated to registers 
                                   1380 ;------------------------------------------------------------
                           000030  1381 	Fmain$correct_ber$0$0 ==.
                           000030  1382 	C$main.c$161$1$311 ==.
                                   1383 ;	main.c:161: static void correct_ber(void)
                                   1384 ;	-----------------------------------------
                                   1385 ;	 function correct_ber
                                   1386 ;	-----------------------------------------
      003C93                       1387 _correct_ber:
                           000030  1388 	C$main.c$180$1$313 ==.
                                   1389 ;	main.c:180: }
                           000030  1390 	C$main.c$181$1$313 ==.
                           000030  1391 	XFmain$correct_ber$0$0 ==.
      003C93 22               [24] 1392 	ret
                                   1393 ;------------------------------------------------------------
                                   1394 ;Allocation info for local variables in function 'process_ber'
                                   1395 ;------------------------------------------------------------
                                   1396 ;st                        Allocated to registers r6 r7 
                                   1397 ;fourfsk                   Allocated to registers r5 
                                   1398 ;i                         Allocated to registers r3 
                                   1399 ;p                         Allocated to registers r6 r7 
                                   1400 ;databyte                  Allocated with name '_process_ber_databyte_6_323'
                                   1401 ;databyte                  Allocated to registers r4 
                                   1402 ;databyte                  Allocated to registers 
                                   1403 ;databyte                  Allocated to registers 
                                   1404 ;databyte                  Allocated to registers 
                                   1405 ;sloc0                     Allocated with name '_process_ber_sloc0_1_0'
                                   1406 ;sloc1                     Allocated with name '_process_ber_sloc1_1_0'
                                   1407 ;------------------------------------------------------------
                           000031  1408 	Fmain$process_ber$0$0 ==.
                           000031  1409 	C$main.c$183$1$313 ==.
                                   1410 ;	main.c:183: static void process_ber(struct axradio_status __xdata *st)
                                   1411 ;	-----------------------------------------
                                   1412 ;	 function process_ber
                                   1413 ;	-----------------------------------------
      003C94                       1414 _process_ber:
      003C94 AE 82            [24] 1415 	mov	r6,dpl
      003C96 AF 83            [24] 1416 	mov	r7,dph
                           000035  1417 	C$main.c$185$1$317 ==.
                                   1418 ;	main.c:185: uint8_t fourfsk = axradio_check_fourfsk_modulation();
      003C98 C0 07            [24] 1419 	push	ar7
      003C9A C0 06            [24] 1420 	push	ar6
      003C9C 12 3A 9A         [24] 1421 	lcall	_axradio_check_fourfsk_modulation
      003C9F AD 82            [24] 1422 	mov	r5,dpl
      003CA1 D0 06            [24] 1423 	pop	ar6
      003CA3 D0 07            [24] 1424 	pop	ar7
                           000042  1425 	C$main.c$187$2$318 ==.
                                   1426 ;	main.c:187: uint8_t i = st->u.rx.pktlen;
      003CA5 74 06            [12] 1427 	mov	a,#0x06
      003CA7 2E               [12] 1428 	add	a,r6
      003CA8 FE               [12] 1429 	mov	r6,a
      003CA9 E4               [12] 1430 	clr	a
      003CAA 3F               [12] 1431 	addc	a,r7
      003CAB FF               [12] 1432 	mov	r7,a
      003CAC 74 18            [12] 1433 	mov	a,#0x18
      003CAE 2E               [12] 1434 	add	a,r6
      003CAF F5 82            [12] 1435 	mov	dpl,a
      003CB1 E4               [12] 1436 	clr	a
      003CB2 3F               [12] 1437 	addc	a,r7
      003CB3 F5 83            [12] 1438 	mov	dph,a
      003CB5 E0               [24] 1439 	movx	a,@dptr
      003CB6 FB               [12] 1440 	mov	r3,a
      003CB7 A3               [24] 1441 	inc	dptr
      003CB8 E0               [24] 1442 	movx	a,@dptr
                           000056  1443 	C$main.c$188$2$318 ==.
                                   1444 ;	main.c:188: bytes -= i;
      003CB9 8B 00            [24] 1445 	mov	ar0,r3
      003CBB E4               [12] 1446 	clr	a
      003CBC F9               [12] 1447 	mov	r1,a
      003CBD FA               [12] 1448 	mov	r2,a
      003CBE FC               [12] 1449 	mov	r4,a
      003CBF E5 28            [12] 1450 	mov	a,_bytes
      003CC1 C3               [12] 1451 	clr	c
      003CC2 98               [12] 1452 	subb	a,r0
      003CC3 F5 28            [12] 1453 	mov	_bytes,a
      003CC5 E5 29            [12] 1454 	mov	a,(_bytes + 1)
      003CC7 99               [12] 1455 	subb	a,r1
      003CC8 F5 29            [12] 1456 	mov	(_bytes + 1),a
      003CCA E5 2A            [12] 1457 	mov	a,(_bytes + 2)
      003CCC 9A               [12] 1458 	subb	a,r2
      003CCD F5 2A            [12] 1459 	mov	(_bytes + 2),a
      003CCF E5 2B            [12] 1460 	mov	a,(_bytes + 3)
      003CD1 9C               [12] 1461 	subb	a,r4
      003CD2 F5 2B            [12] 1462 	mov	(_bytes + 3),a
                           000071  1463 	C$main.c$189$2$318 ==.
                                   1464 ;	main.c:189: acquire_agc = (0 > (int32_t)bytes);
      003CD4 A8 28            [24] 1465 	mov	r0,_bytes
      003CD6 A9 29            [24] 1466 	mov	r1,(_bytes + 1)
      003CD8 AA 2A            [24] 1467 	mov	r2,(_bytes + 2)
      003CDA E5 2B            [12] 1468 	mov	a,(_bytes + 3)
      003CDC FC               [12] 1469 	mov	r4,a
      003CDD 33               [12] 1470 	rlc	a
      003CDE E4               [12] 1471 	clr	a
      003CDF 33               [12] 1472 	rlc	a
                           00007D  1473 	C$main.c$191$2$318 ==.
                                   1474 ;	main.c:191: if (acquire_agc)
      003CE0 F5 34            [12] 1475 	mov	_acquire_agc,a
      003CE2 60 0E            [24] 1476 	jz	00102$
                           000081  1477 	C$main.c$193$3$319 ==.
                                   1478 ;	main.c:193: i += (uint8_t)bytes;
      003CE4 E5 28            [12] 1479 	mov	a,_bytes
      003CE6 FC               [12] 1480 	mov	r4,a
      003CE7 2B               [12] 1481 	add	a,r3
      003CE8 FB               [12] 1482 	mov	r3,a
                           000086  1483 	C$main.c$194$3$319 ==.
                                   1484 ;	main.c:194: bytes = 0;
      003CE9 E4               [12] 1485 	clr	a
      003CEA F5 28            [12] 1486 	mov	_bytes,a
      003CEC F5 29            [12] 1487 	mov	(_bytes + 1),a
      003CEE F5 2A            [12] 1488 	mov	(_bytes + 2),a
      003CF0 F5 2B            [12] 1489 	mov	(_bytes + 3),a
      003CF2                       1490 00102$:
                           00008F  1491 	C$main.c$197$2$318 ==.
                                   1492 ;	main.c:197: if (i)
      003CF2 EB               [12] 1493 	mov	a,r3
      003CF3 70 03            [24] 1494 	jnz	00169$
      003CF5 02 3D 9F         [24] 1495 	ljmp	00126$
      003CF8                       1496 00169$:
                           000095  1497 	C$main.c$199$3$320 ==.
                                   1498 ;	main.c:199: const uint8_t __xdata *p = st->u.rx.pktdata;
      003CF8 74 16            [12] 1499 	mov	a,#0x16
      003CFA 2E               [12] 1500 	add	a,r6
      003CFB F5 82            [12] 1501 	mov	dpl,a
      003CFD E4               [12] 1502 	clr	a
      003CFE 3F               [12] 1503 	addc	a,r7
      003CFF F5 83            [12] 1504 	mov	dph,a
      003D01 E0               [24] 1505 	movx	a,@dptr
      003D02 FE               [12] 1506 	mov	r6,a
      003D03 A3               [24] 1507 	inc	dptr
      003D04 E0               [24] 1508 	movx	a,@dptr
      003D05 FF               [12] 1509 	mov	r7,a
                           0000A3  1510 	C$main.c$203$4$321 ==.
                                   1511 ;	main.c:203: if (fourfsk)
      003D06 ED               [12] 1512 	mov	a,r5
      003D07 60 63            [24] 1513 	jz	00144$
                           0000A6  1514 	C$main.c$205$1$317 ==.
                                   1515 ;	main.c:205: do
      003D09 8E 37            [24] 1516 	mov	_process_ber_sloc1_1_0,r6
      003D0B 8F 38            [24] 1517 	mov	(_process_ber_sloc1_1_0 + 1),r7
      003D0D 8B 36            [24] 1518 	mov	_process_ber_sloc0_1_0,r3
      003D0F                       1519 00104$:
                           0000AC  1520 	C$main.c$207$6$323 ==.
                                   1521 ;	main.c:207: uint8_t databyte = *p++;
      003D0F 85 37 82         [24] 1522 	mov	dpl,_process_ber_sloc1_1_0
      003D12 85 38 83         [24] 1523 	mov	dph,(_process_ber_sloc1_1_0 + 1)
      003D15 E0               [24] 1524 	movx	a,@dptr
      003D16 F5 35            [12] 1525 	mov	_process_ber_databyte_6_323,a
      003D18 A3               [24] 1526 	inc	dptr
      003D19 85 82 37         [24] 1527 	mov	_process_ber_sloc1_1_0,dpl
      003D1C 85 83 38         [24] 1528 	mov	(_process_ber_sloc1_1_0 + 1),dph
                           0000BC  1529 	C$main.c$209$6$323 ==.
                                   1530 ;	main.c:209: errors2 += hweight8(databyte ^ 0x87);
      003D1F 74 87            [12] 1531 	mov	a,#0x87
      003D21 65 35            [12] 1532 	xrl	a,_process_ber_databyte_6_323
      003D23 F5 82            [12] 1533 	mov	dpl,a
      003D25 12 41 71         [24] 1534 	lcall	_hweight8
      003D28 A8 82            [24] 1535 	mov	r0,dpl
      003D2A E4               [12] 1536 	clr	a
      003D2B F9               [12] 1537 	mov	r1,a
      003D2C FA               [12] 1538 	mov	r2,a
      003D2D FD               [12] 1539 	mov	r5,a
      003D2E E8               [12] 1540 	mov	a,r0
      003D2F 25 30            [12] 1541 	add	a,_errors2
      003D31 F5 30            [12] 1542 	mov	_errors2,a
      003D33 E9               [12] 1543 	mov	a,r1
      003D34 35 31            [12] 1544 	addc	a,(_errors2 + 1)
      003D36 F5 31            [12] 1545 	mov	(_errors2 + 1),a
      003D38 EA               [12] 1546 	mov	a,r2
      003D39 35 32            [12] 1547 	addc	a,(_errors2 + 2)
      003D3B F5 32            [12] 1548 	mov	(_errors2 + 2),a
      003D3D ED               [12] 1549 	mov	a,r5
      003D3E 35 33            [12] 1550 	addc	a,(_errors2 + 3)
      003D40 F5 33            [12] 1551 	mov	(_errors2 + 3),a
                           0000DF  1552 	C$main.c$210$6$323 ==.
                                   1553 ;	main.c:210: errors += hweight8(databyte ^ 0xe1);
      003D42 74 E1            [12] 1554 	mov	a,#0xe1
      003D44 65 35            [12] 1555 	xrl	a,_process_ber_databyte_6_323
      003D46 F5 82            [12] 1556 	mov	dpl,a
      003D48 12 41 71         [24] 1557 	lcall	_hweight8
      003D4B AD 82            [24] 1558 	mov	r5,dpl
      003D4D 8D 01            [24] 1559 	mov	ar1,r5
      003D4F E4               [12] 1560 	clr	a
      003D50 FA               [12] 1561 	mov	r2,a
      003D51 FC               [12] 1562 	mov	r4,a
      003D52 FD               [12] 1563 	mov	r5,a
      003D53 E9               [12] 1564 	mov	a,r1
      003D54 25 2C            [12] 1565 	add	a,_errors
      003D56 F5 2C            [12] 1566 	mov	_errors,a
      003D58 EA               [12] 1567 	mov	a,r2
      003D59 35 2D            [12] 1568 	addc	a,(_errors + 1)
      003D5B F5 2D            [12] 1569 	mov	(_errors + 1),a
      003D5D EC               [12] 1570 	mov	a,r4
      003D5E 35 2E            [12] 1571 	addc	a,(_errors + 2)
      003D60 F5 2E            [12] 1572 	mov	(_errors + 2),a
      003D62 ED               [12] 1573 	mov	a,r5
      003D63 35 2F            [12] 1574 	addc	a,(_errors + 3)
      003D65 F5 2F            [12] 1575 	mov	(_errors + 3),a
                           000104  1576 	C$main.c$212$5$322 ==.
                                   1577 ;	main.c:212: while (--i);
      003D67 D5 36 A5         [24] 1578 	djnz	_process_ber_sloc0_1_0,00104$
                           000107  1579 	C$main.c$214$5$322 ==.
                                   1580 ;	main.c:214: break;
                           000107  1581 	C$main.c$217$1$317 ==.
                                   1582 ;	main.c:217: do
      003D6A 80 33            [24] 1583 	sjmp	00126$
      003D6C                       1584 00144$:
      003D6C 8B 05            [24] 1585 	mov	ar5,r3
      003D6E                       1586 00109$:
                           00010B  1587 	C$main.c$219$5$324 ==.
                                   1588 ;	main.c:219: uint8_t databyte = *p++;
      003D6E 8E 82            [24] 1589 	mov	dpl,r6
      003D70 8F 83            [24] 1590 	mov	dph,r7
      003D72 E0               [24] 1591 	movx	a,@dptr
      003D73 FC               [12] 1592 	mov	r4,a
      003D74 A3               [24] 1593 	inc	dptr
      003D75 AE 82            [24] 1594 	mov	r6,dpl
      003D77 AF 83            [24] 1595 	mov	r7,dph
                           000116  1596 	C$main.c$220$5$324 ==.
                                   1597 ;	main.c:220: errors += hweight8(databyte ^ 0x55);
      003D79 74 55            [12] 1598 	mov	a,#0x55
      003D7B 6C               [12] 1599 	xrl	a,r4
      003D7C F5 82            [12] 1600 	mov	dpl,a
      003D7E 12 41 71         [24] 1601 	lcall	_hweight8
      003D81 AC 82            [24] 1602 	mov	r4,dpl
      003D83 8C 01            [24] 1603 	mov	ar1,r4
      003D85 E4               [12] 1604 	clr	a
      003D86 FA               [12] 1605 	mov	r2,a
      003D87 FB               [12] 1606 	mov	r3,a
      003D88 FC               [12] 1607 	mov	r4,a
      003D89 E9               [12] 1608 	mov	a,r1
      003D8A 25 2C            [12] 1609 	add	a,_errors
      003D8C F5 2C            [12] 1610 	mov	_errors,a
      003D8E EA               [12] 1611 	mov	a,r2
      003D8F 35 2D            [12] 1612 	addc	a,(_errors + 1)
      003D91 F5 2D            [12] 1613 	mov	(_errors + 1),a
      003D93 EB               [12] 1614 	mov	a,r3
      003D94 35 2E            [12] 1615 	addc	a,(_errors + 2)
      003D96 F5 2E            [12] 1616 	mov	(_errors + 2),a
      003D98 EC               [12] 1617 	mov	a,r4
      003D99 35 2F            [12] 1618 	addc	a,(_errors + 3)
      003D9B F5 2F            [12] 1619 	mov	(_errors + 3),a
                           00013A  1620 	C$main.c$222$4$321 ==.
                                   1621 ;	main.c:222: while (--i);
      003D9D DD CF            [24] 1622 	djnz	r5,00109$
                           00013C  1623 	C$main.c$274$2$318 ==.
                                   1624 ;	main.c:274: }
      003D9F                       1625 00126$:
                           00013C  1626 	C$main.c$278$1$317 ==.
                                   1627 ;	main.c:278: if (!acquire_agc)
      003D9F E5 34            [12] 1628 	mov	a,_acquire_agc
                           00013E  1629 	C$main.c$279$1$317 ==.
                                   1630 ;	main.c:279: return;
      003DA1 60 2B            [24] 1631 	jz	00138$
                           000140  1632 	C$main.c$282$1$317 ==.
                                   1633 ;	main.c:282: if (errors > (((uint32_t)NUMBYTES) << 2))
      003DA3 C3               [12] 1634 	clr	c
      003DA4 74 88            [12] 1635 	mov	a,#0x88
      003DA6 95 2C            [12] 1636 	subb	a,_errors
      003DA8 74 13            [12] 1637 	mov	a,#0x13
      003DAA 95 2D            [12] 1638 	subb	a,(_errors + 1)
      003DAC E4               [12] 1639 	clr	a
      003DAD 95 2E            [12] 1640 	subb	a,(_errors + 2)
      003DAF E4               [12] 1641 	clr	a
      003DB0 95 2F            [12] 1642 	subb	a,(_errors + 3)
      003DB2 50 17            [24] 1643 	jnc	00136$
                           000151  1644 	C$main.c$283$1$317 ==.
                                   1645 ;	main.c:283: errors = (((uint32_t)NUMBYTES) << 3) - errors;
      003DB4 74 10            [12] 1646 	mov	a,#0x10
      003DB6 C3               [12] 1647 	clr	c
      003DB7 95 2C            [12] 1648 	subb	a,_errors
      003DB9 F5 2C            [12] 1649 	mov	_errors,a
      003DBB 74 27            [12] 1650 	mov	a,#0x27
      003DBD 95 2D            [12] 1651 	subb	a,(_errors + 1)
      003DBF F5 2D            [12] 1652 	mov	(_errors + 1),a
      003DC1 E4               [12] 1653 	clr	a
      003DC2 95 2E            [12] 1654 	subb	a,(_errors + 2)
      003DC4 F5 2E            [12] 1655 	mov	(_errors + 2),a
      003DC6 E4               [12] 1656 	clr	a
      003DC7 95 2F            [12] 1657 	subb	a,(_errors + 3)
      003DC9 F5 2F            [12] 1658 	mov	(_errors + 3),a
                           000168  1659 	C$main.c$291$1$317 ==.
                                   1660 ;	main.c:291: errors = errors2;
      003DCB                       1661 00136$:
                           000168  1662 	C$main.c$294$1$317 ==.
                                   1663 ;	main.c:294: correct_ber();
      003DCB 12 3C 93         [24] 1664 	lcall	_correct_ber
      003DCE                       1665 00138$:
                           00016B  1666 	C$main.c$295$1$317 ==.
                           00016B  1667 	XFmain$process_ber$0$0 ==.
      003DCE 22               [24] 1668 	ret
                                   1669 ;------------------------------------------------------------
                                   1670 ;Allocation info for local variables in function 'dump_pkt'
                                   1671 ;------------------------------------------------------------
                                   1672 ;st                        Allocated to registers 
                                   1673 ;------------------------------------------------------------
                           00016C  1674 	Fmain$dump_pkt$0$0 ==.
                           00016C  1675 	C$main.c$297$1$317 ==.
                                   1676 ;	main.c:297: static void dump_pkt(struct axradio_status __xdata *st)
                                   1677 ;	-----------------------------------------
                                   1678 ;	 function dump_pkt
                                   1679 ;	-----------------------------------------
      003DCF                       1680 _dump_pkt:
                           00016C  1681 	C$main.c$323$1$317 ==.
                                   1682 ;	main.c:323: }
                           00016C  1683 	C$main.c$323$1$317 ==.
                           00016C  1684 	XFmain$dump_pkt$0$0 ==.
      003DCF 22               [24] 1685 	ret
                                   1686 ;------------------------------------------------------------
                                   1687 ;Allocation info for local variables in function 'display_ber'
                                   1688 ;------------------------------------------------------------
                                   1689 ;st                        Allocated to registers r6 r7 
                                   1690 ;freqoffs                  Allocated to registers 
                                   1691 ;------------------------------------------------------------
                           00016D  1692 	Fmain$display_ber$0$0 ==.
                           00016D  1693 	C$main.c$325$1$317 ==.
                                   1694 ;	main.c:325: static void display_ber(struct axradio_status __xdata *st)
                                   1695 ;	-----------------------------------------
                                   1696 ;	 function display_ber
                                   1697 ;	-----------------------------------------
      003DD0                       1698 _display_ber:
      003DD0 AE 82            [24] 1699 	mov	r6,dpl
      003DD2 AF 83            [24] 1700 	mov	r7,dph
                           000171  1701 	C$main.c$327$1$332 ==.
                                   1702 ;	main.c:327: int32_t freqoffs = axradio_conv_freq_tohz(st->u.rx.phy.offset);
      003DD4 74 06            [12] 1703 	mov	a,#0x06
      003DD6 2E               [12] 1704 	add	a,r6
      003DD7 FE               [12] 1705 	mov	r6,a
      003DD8 E4               [12] 1706 	clr	a
      003DD9 3F               [12] 1707 	addc	a,r7
      003DDA FF               [12] 1708 	mov	r7,a
      003DDB 8E 82            [24] 1709 	mov	dpl,r6
      003DDD 8F 83            [24] 1710 	mov	dph,r7
      003DDF A3               [24] 1711 	inc	dptr
      003DE0 A3               [24] 1712 	inc	dptr
      003DE1 E0               [24] 1713 	movx	a,@dptr
      003DE2 FC               [12] 1714 	mov	r4,a
      003DE3 A3               [24] 1715 	inc	dptr
      003DE4 E0               [24] 1716 	movx	a,@dptr
      003DE5 FD               [12] 1717 	mov	r5,a
      003DE6 A3               [24] 1718 	inc	dptr
      003DE7 E0               [24] 1719 	movx	a,@dptr
      003DE8 FE               [12] 1720 	mov	r6,a
      003DE9 A3               [24] 1721 	inc	dptr
      003DEA E0               [24] 1722 	movx	a,@dptr
      003DEB 8C 82            [24] 1723 	mov	dpl,r4
      003DED 8D 83            [24] 1724 	mov	dph,r5
      003DEF 8E F0            [24] 1725 	mov	b,r6
      003DF1 12 07 88         [24] 1726 	lcall	_axradio_conv_freq_tohz
                           000191  1727 	C$main.c$337$1$332 ==.
                                   1728 ;	main.c:337: display_writenum16(st->u.rx.phy.rssi, 4, WRNUM_SIGNED);
                           000191  1729 	C$main.c$349$1$332 ==.
                           000191  1730 	XFmain$display_ber$0$0 ==.
      003DF4 22               [24] 1731 	ret
                                   1732 ;------------------------------------------------------------
                                   1733 ;Allocation info for local variables in function 'axradio_statuschange'
                                   1734 ;------------------------------------------------------------
                                   1735 ;st                        Allocated to registers r6 r7 
                                   1736 ;fourfsk                   Allocated to registers 
                                   1737 ;i                         Allocated to registers 
                                   1738 ;i                         Allocated to registers 
                                   1739 ;i                         Allocated to registers 
                                   1740 ;p                         Allocated to registers 
                                   1741 ;------------------------------------------------------------
                           000192  1742 	G$axradio_statuschange$0$0 ==.
                           000192  1743 	C$main.c$351$1$332 ==.
                                   1744 ;	main.c:351: void axradio_statuschange(struct axradio_status __xdata *st)
                                   1745 ;	-----------------------------------------
                                   1746 ;	 function axradio_statuschange
                                   1747 ;	-----------------------------------------
      003DF5                       1748 _axradio_statuschange:
      003DF5 AE 82            [24] 1749 	mov	r6,dpl
      003DF7 AF 83            [24] 1750 	mov	r7,dph
                           000196  1751 	C$main.c$353$1$342 ==.
                                   1752 ;	main.c:353: uint8_t fourfsk = axradio_check_fourfsk_modulation();
      003DF9 C0 07            [24] 1753 	push	ar7
      003DFB C0 06            [24] 1754 	push	ar6
      003DFD 12 3A 9A         [24] 1755 	lcall	_axradio_check_fourfsk_modulation
      003E00 D0 06            [24] 1756 	pop	ar6
      003E02 D0 07            [24] 1757 	pop	ar7
                           0001A1  1758 	C$main.c$354$1$342 ==.
                                   1759 ;	main.c:354: switch (st->status)
      003E04 8E 82            [24] 1760 	mov	dpl,r6
      003E06 8F 83            [24] 1761 	mov	dph,r7
      003E08 E0               [24] 1762 	movx	a,@dptr
      003E09 FD               [12] 1763 	mov	r5,a
      003E0A 60 36            [24] 1764 	jz	00130$
      003E0C BD 03 02         [24] 1765 	cjne	r5,#0x03,00187$
      003E0F 80 0D            [24] 1766 	sjmp	00105$
      003E11                       1767 00187$:
      003E11 BD 04 02         [24] 1768 	cjne	r5,#0x04,00188$
      003E14 80 0D            [24] 1769 	sjmp	00112$
      003E16                       1770 00188$:
      003E16 BD 05 02         [24] 1771 	cjne	r5,#0x05,00189$
      003E19 80 0D            [24] 1772 	sjmp	00121$
      003E1B                       1773 00189$:
      003E1B 02 3E 9D         [24] 1774 	ljmp	00161$
                           0001BB  1775 	C$main.c$357$2$343 ==.
                                   1776 ;	main.c:357: led0_on();
      003E1E                       1777 00105$:
      003E1E D2 89            [12] 1778 	setb	_PORTB_1
                           0001BD  1779 	C$main.c$358$2$343 ==.
                                   1780 ;	main.c:358: break;
      003E20 02 3E 9D         [24] 1781 	ljmp	00161$
                           0001C0  1782 	C$main.c$361$2$343 ==.
                                   1783 ;	main.c:361: led0_off();
      003E23                       1784 00112$:
      003E23 C2 89            [12] 1785 	clr	_PORTB_1
                           0001C2  1786 	C$main.c$362$2$343 ==.
                                   1787 ;	main.c:362: break;
      003E25 02 3E 9D         [24] 1788 	ljmp	00161$
                           0001C5  1789 	C$main.c$376$3$348 ==.
                                   1790 ;	main.c:376: case TX_RANDOM_PATTERN:
      003E28                       1791 00121$:
                           0001C5  1792 	C$main.c$378$3$348 ==.
                                   1793 ;	main.c:378: axradio_transmit((void *)0, onepattern, sizeof(onepattern));
      003E28 75 15 31         [24] 1794 	mov	_axradio_transmit_PARM_2,#_onepattern
      003E2B 75 16 50         [24] 1795 	mov	(_axradio_transmit_PARM_2 + 1),#(_onepattern >> 8)
      003E2E 75 17 80         [24] 1796 	mov	(_axradio_transmit_PARM_2 + 2),#0x80
      003E31 75 18 10         [24] 1797 	mov	_axradio_transmit_PARM_3,#0x10
      003E34 75 19 00         [24] 1798 	mov	(_axradio_transmit_PARM_3 + 1),#0x00
      003E37 90 00 00         [24] 1799 	mov	dptr,#0x0000
      003E3A 75 F0 00         [24] 1800 	mov	b,#0x00
      003E3D 12 36 0E         [24] 1801 	lcall	_axradio_transmit
                           0001DD  1802 	C$main.c$379$3$348 ==.
                                   1803 ;	main.c:379: break;
                           0001DD  1804 	C$main.c$428$2$343 ==.
                                   1805 ;	main.c:428: case AXRADIO_STAT_RECEIVE:
      003E40 80 5B            [24] 1806 	sjmp	00161$
      003E42                       1807 00130$:
                           0001DF  1808 	C$main.c$430$3$355 ==.
                                   1809 ;	main.c:430: if (acquire_agc == 1)
      003E42 74 01            [12] 1810 	mov	a,#0x01
      003E44 B5 34 0A         [24] 1811 	cjne	a,_acquire_agc,00138$
                           0001E4  1812 	C$main.c$433$6$358 ==.
                                   1813 ;	main.c:433: led0_off();
      003E47 C2 89            [12] 1814 	clr	_PORTB_1
                           0001E6  1815 	C$main.c$434$4$356 ==.
                                   1816 ;	main.c:434: acquire_agc = 2;
      003E49 75 34 02         [24] 1817 	mov	_acquire_agc,#0x02
                           0001E9  1818 	C$main.c$435$4$356 ==.
                                   1819 ;	main.c:435: axradio_agc_freeze();
      003E4C 12 39 9F         [24] 1820 	lcall	_axradio_agc_freeze
                           0001EC  1821 	C$main.c$436$4$356 ==.
                                   1822 ;	main.c:436: break;
      003E4F 80 4C            [24] 1823 	sjmp	00161$
      003E51                       1824 00138$:
                           0001EE  1825 	C$main.c$439$3$355 ==.
                                   1826 ;	main.c:439: if (acquire_agc == 2)
      003E51 74 02            [12] 1827 	mov	a,#0x02
      003E53 B5 34 05         [24] 1828 	cjne	a,_acquire_agc,00150$
                           0001F3  1829 	C$main.c$442$4$359 ==.
                                   1830 ;	main.c:442: acquire_agc = 0;
      003E56 75 34 00         [24] 1831 	mov	_acquire_agc,#0x00
                           0001F6  1832 	C$main.c$470$4$359 ==.
                                   1833 ;	main.c:470: break;
                           0001F6  1834 	C$main.c$474$3$355 ==.
                                   1835 ;	main.c:474: led0_on();
      003E59 80 42            [24] 1836 	sjmp	00161$
      003E5B                       1837 00150$:
      003E5B D2 89            [12] 1838 	setb	_PORTB_1
                           0001FA  1839 	C$main.c$475$3$355 ==.
                                   1840 ;	main.c:475: process_ber(st);
      003E5D 8E 82            [24] 1841 	mov	dpl,r6
      003E5F 8F 83            [24] 1842 	mov	dph,r7
      003E61 C0 07            [24] 1843 	push	ar7
      003E63 C0 06            [24] 1844 	push	ar6
      003E65 12 3C 94         [24] 1845 	lcall	_process_ber
      003E68 D0 06            [24] 1846 	pop	ar6
      003E6A D0 07            [24] 1847 	pop	ar7
                           000209  1848 	C$main.c$477$3$355 ==.
                                   1849 ;	main.c:477: if (!acquire_agc)
      003E6C E5 34            [12] 1850 	mov	a,_acquire_agc
      003E6E 60 2D            [24] 1851 	jz	00161$
                           00020D  1852 	C$main.c$480$3$355 ==.
                                   1853 ;	main.c:480: axradio_agc_thaw();
      003E70 C0 07            [24] 1854 	push	ar7
      003E72 C0 06            [24] 1855 	push	ar6
      003E74 12 39 A6         [24] 1856 	lcall	_axradio_agc_thaw
      003E77 D0 06            [24] 1857 	pop	ar6
      003E79 D0 07            [24] 1858 	pop	ar7
                           000218  1859 	C$main.c$481$3$355 ==.
                                   1860 ;	main.c:481: display_ber(st);
      003E7B 8E 82            [24] 1861 	mov	dpl,r6
      003E7D 8F 83            [24] 1862 	mov	dph,r7
      003E7F 12 3D D0         [24] 1863 	lcall	_display_ber
                           00021F  1864 	C$main.c$483$3$355 ==.
                                   1865 ;	main.c:483: bytes = NUMBYTES;
      003E82 75 28 E2         [24] 1866 	mov	_bytes,#0xe2
      003E85 75 29 04         [24] 1867 	mov	(_bytes + 1),#0x04
      003E88 E4               [12] 1868 	clr	a
      003E89 F5 2A            [12] 1869 	mov	(_bytes + 2),a
      003E8B F5 2B            [12] 1870 	mov	(_bytes + 3),a
                           00022A  1871 	C$main.c$484$3$355 ==.
                                   1872 ;	main.c:484: errors = 0;
      003E8D F5 2C            [12] 1873 	mov	_errors,a
      003E8F F5 2D            [12] 1874 	mov	(_errors + 1),a
      003E91 F5 2E            [12] 1875 	mov	(_errors + 2),a
      003E93 F5 2F            [12] 1876 	mov	(_errors + 3),a
                           000232  1877 	C$main.c$485$3$355 ==.
                                   1878 ;	main.c:485: errors2 = 0;
      003E95 F5 30            [12] 1879 	mov	_errors2,a
      003E97 F5 31            [12] 1880 	mov	(_errors2 + 1),a
      003E99 F5 32            [12] 1881 	mov	(_errors2 + 2),a
      003E9B F5 33            [12] 1882 	mov	(_errors2 + 3),a
                           00023A  1883 	C$main.c$491$1$342 ==.
                                   1884 ;	main.c:491: }
      003E9D                       1885 00161$:
                           00023A  1886 	C$main.c$492$1$342 ==.
                           00023A  1887 	XG$axradio_statuschange$0$0 ==.
      003E9D 22               [24] 1888 	ret
                                   1889 ;------------------------------------------------------------
                                   1890 ;Allocation info for local variables in function 'set_cw'
                                   1891 ;------------------------------------------------------------
                                   1892 ;i                         Allocated to registers 
                                   1893 ;------------------------------------------------------------
                           00023B  1894 	G$set_cw$0$0 ==.
                           00023B  1895 	C$main.c$494$1$342 ==.
                                   1896 ;	main.c:494: void set_cw(void)
                                   1897 ;	-----------------------------------------
                                   1898 ;	 function set_cw
                                   1899 ;	-----------------------------------------
      003E9E                       1900 _set_cw:
                           00023B  1901 	C$main.c$496$1$366 ==.
                                   1902 ;	main.c:496: uint8_t i = axradio_set_mode(AXRADIO_MODE_CW_TRANSMIT);
      003E9E 75 82 03         [24] 1903 	mov	dpl,#0x03
      003EA1 12 2E E3         [24] 1904 	lcall	_axradio_set_mode
      003EA4 E5 82            [12] 1905 	mov	a,dpl
                           000243  1906 	C$main.c$498$1$366 ==.
                                   1907 ;	main.c:498: if (i != AXRADIO_ERR_NOERROR)
      003EA6 60 05            [24] 1908 	jz	00106$
                           000245  1909 	C$main.c$500$2$367 ==.
                                   1910 ;	main.c:500: display_radio_error(i);
      003EA8                       1911 00123$:
                           000245  1912 	C$main.c$506$2$367 ==.
                                   1913 ;	main.c:506: enter_sleep();
      003EA8 12 4B F5         [24] 1914 	lcall	_enter_sleep
                           000248  1915 	C$main.c$509$1$366 ==.
                                   1916 ;	main.c:509: display_clear(0x00, 16);
      003EAB 80 FB            [24] 1917 	sjmp	00123$
      003EAD                       1918 00106$:
                           00024A  1919 	C$main.c$514$1$366 ==.
                                   1920 ;	main.c:514: if(axradio_get_transmitter_pa_type() == AXRADIO_DIFFERENTIAL_PA)
      003EAD 12 3A AE         [24] 1921 	lcall	_axradio_get_transmitter_pa_type
      003EB0 AF 82            [24] 1922 	mov	r7,dpl
      003EB2 BF 01 02         [24] 1923 	cjne	r7,#0x01,00134$
      003EB5 80 03            [24] 1924 	sjmp	00125$
      003EB7                       1925 00134$:
                           000254  1926 	C$main.c$516$1$366 ==.
                                   1927 ;	main.c:516: else if(axradio_get_transmitter_pa_type() == AXRADIO_SINGLE_ENDED_PA)
      003EB7 12 3A AE         [24] 1928 	lcall	_axradio_get_transmitter_pa_type
                           000257  1929 	C$main.c$517$1$366 ==.
                                   1930 ;	main.c:517: display_writestr( "SE ");
      003EBA                       1931 00125$:
                           000257  1932 	C$main.c$518$1$366 ==.
                           000257  1933 	XG$set_cw$0$0 ==.
      003EBA 22               [24] 1934 	ret
                                   1935 ;------------------------------------------------------------
                                   1936 ;Allocation info for local variables in function 'set_transmit'
                                   1937 ;------------------------------------------------------------
                                   1938 ;i                         Allocated to registers 
                                   1939 ;------------------------------------------------------------
                           000258  1940 	G$set_transmit$0$0 ==.
                           000258  1941 	C$main.c$520$1$366 ==.
                                   1942 ;	main.c:520: void set_transmit(void)
                                   1943 ;	-----------------------------------------
                                   1944 ;	 function set_transmit
                                   1945 ;	-----------------------------------------
      003EBB                       1946 _set_transmit:
                           000258  1947 	C$main.c$566$1$376 ==.
                                   1948 ;	main.c:566: i = axradio_set_mode(i);
      003EBB 75 82 18         [24] 1949 	mov	dpl,#0x18
      003EBE 12 2E E3         [24] 1950 	lcall	_axradio_set_mode
      003EC1 E5 82            [12] 1951 	mov	a,dpl
                           000260  1952 	C$main.c$568$1$376 ==.
                                   1953 ;	main.c:568: if (i != AXRADIO_ERR_NOERROR)
      003EC3 60 05            [24] 1954 	jz	00111$
                           000262  1955 	C$main.c$570$2$378 ==.
                                   1956 ;	main.c:570: display_radio_error(i);
      003EC5                       1957 00143$:
                           000262  1958 	C$main.c$576$2$378 ==.
                                   1959 ;	main.c:576: enter_sleep();
      003EC5 12 4B F5         [24] 1960 	lcall	_enter_sleep
      003EC8 80 FB            [24] 1961 	sjmp	00143$
      003ECA                       1962 00111$:
                           000267  1963 	C$main.c$579$1$376 ==.
                                   1964 ;	main.c:579: scr.w = ~0U;
      003ECA 75 24 FF         [24] 1965 	mov	(_scr + 0),#0xff
      003ECD 75 25 FF         [24] 1966 	mov	(_scr + 1),#0xff
                           00026D  1967 	C$main.c$607$1$376 ==.
                                   1968 ;	main.c:607: if(axradio_get_transmitter_pa_type() == AXRADIO_DIFFERENTIAL_PA)
      003ED0 12 3A AE         [24] 1969 	lcall	_axradio_get_transmitter_pa_type
      003ED3 AF 82            [24] 1970 	mov	r7,dpl
      003ED5 BF 01 02         [24] 1971 	cjne	r7,#0x01,00154$
      003ED8 80 03            [24] 1972 	sjmp	00145$
      003EDA                       1973 00154$:
                           000277  1974 	C$main.c$609$1$376 ==.
                                   1975 ;	main.c:609: else if(axradio_get_transmitter_pa_type() == AXRADIO_SINGLE_ENDED_PA)
      003EDA 12 3A AE         [24] 1976 	lcall	_axradio_get_transmitter_pa_type
                           00027A  1977 	C$main.c$610$1$376 ==.
                                   1978 ;	main.c:610: display_writestr( "SE ");
      003EDD                       1979 00145$:
                           00027A  1980 	C$main.c$611$1$376 ==.
                           00027A  1981 	XG$set_transmit$0$0 ==.
      003EDD 22               [24] 1982 	ret
                                   1983 ;------------------------------------------------------------
                                   1984 ;Allocation info for local variables in function 'set_receiveber'
                                   1985 ;------------------------------------------------------------
                                   1986 ;i                         Allocated to registers 
                                   1987 ;------------------------------------------------------------
                           00027B  1988 	G$set_receiveber$0$0 ==.
                           00027B  1989 	C$main.c$613$1$376 ==.
                                   1990 ;	main.c:613: void set_receiveber(void)
                                   1991 ;	-----------------------------------------
                                   1992 ;	 function set_receiveber
                                   1993 ;	-----------------------------------------
      003EDE                       1994 _set_receiveber:
                           00027B  1995 	C$main.c$656$1$392 ==.
                                   1996 ;	main.c:656: i = axradio_set_mode(i);
      003EDE 75 82 28         [24] 1997 	mov	dpl,#0x28
      003EE1 12 2E E3         [24] 1998 	lcall	_axradio_set_mode
      003EE4 E5 82            [12] 1999 	mov	a,dpl
                           000283  2000 	C$main.c$658$1$392 ==.
                                   2001 ;	main.c:658: if (i != AXRADIO_ERR_NOERROR)
      003EE6 60 05            [24] 2002 	jz	00112$
                           000285  2003 	C$main.c$660$2$394 ==.
                                   2004 ;	main.c:660: display_radio_error(i);
      003EE8                       2005 00128$:
                           000285  2006 	C$main.c$666$2$394 ==.
                                   2007 ;	main.c:666: enter_sleep();
      003EE8 12 4B F5         [24] 2008 	lcall	_enter_sleep
                           000288  2009 	C$main.c$669$1$392 ==.
                                   2010 ;	main.c:669: display_clear(0x00, 16);
      003EEB 80 FB            [24] 2011 	sjmp	00128$
      003EED                       2012 00112$:
                           00028A  2013 	C$main.c$680$1$392 ==.
                                   2014 ;	main.c:680: bytes = NUMBYTES;
      003EED 75 28 E2         [24] 2015 	mov	_bytes,#0xe2
      003EF0 75 29 04         [24] 2016 	mov	(_bytes + 1),#0x04
      003EF3 E4               [12] 2017 	clr	a
      003EF4 F5 2A            [12] 2018 	mov	(_bytes + 2),a
      003EF6 F5 2B            [12] 2019 	mov	(_bytes + 3),a
                           000295  2020 	C$main.c$681$1$392 ==.
                                   2021 ;	main.c:681: errors = 0;
      003EF8 F5 2C            [12] 2022 	mov	_errors,a
      003EFA F5 2D            [12] 2023 	mov	(_errors + 1),a
      003EFC F5 2E            [12] 2024 	mov	(_errors + 2),a
      003EFE F5 2F            [12] 2025 	mov	(_errors + 3),a
                           00029D  2026 	C$main.c$682$1$392 ==.
                                   2027 ;	main.c:682: errors2 = 0;
      003F00 F5 30            [12] 2028 	mov	_errors2,a
      003F02 F5 31            [12] 2029 	mov	(_errors2 + 1),a
      003F04 F5 32            [12] 2030 	mov	(_errors2 + 2),a
      003F06 F5 33            [12] 2031 	mov	(_errors2 + 3),a
                           0002A5  2032 	C$main.c$683$1$392 ==.
                                   2033 ;	main.c:683: acquire_agc = 1;
      003F08 75 34 01         [24] 2034 	mov	_acquire_agc,#0x01
                           0002A8  2035 	C$main.c$684$1$392 ==.
                           0002A8  2036 	XG$set_receiveber$0$0 ==.
      003F0B 22               [24] 2037 	ret
                                   2038 ;------------------------------------------------------------
                                   2039 ;Allocation info for local variables in function 'enable_radio_interrupt_in_mcu_pin'
                                   2040 ;------------------------------------------------------------
                           0002A9  2041 	G$enable_radio_interrupt_in_mcu_pin$0$0 ==.
                           0002A9  2042 	C$main.c$686$1$392 ==.
                                   2043 ;	main.c:686: void enable_radio_interrupt_in_mcu_pin(void)
                                   2044 ;	-----------------------------------------
                                   2045 ;	 function enable_radio_interrupt_in_mcu_pin
                                   2046 ;	-----------------------------------------
      003F0C                       2047 _enable_radio_interrupt_in_mcu_pin:
                           0002A9  2048 	C$main.c$688$1$405 ==.
                                   2049 ;	main.c:688: IE_4 = 1;
      003F0C D2 AC            [12] 2050 	setb	_IE_4
                           0002AB  2051 	C$main.c$689$1$405 ==.
                           0002AB  2052 	XG$enable_radio_interrupt_in_mcu_pin$0$0 ==.
      003F0E 22               [24] 2053 	ret
                                   2054 ;------------------------------------------------------------
                                   2055 ;Allocation info for local variables in function 'disable_radio_interrupt_in_mcu_pin'
                                   2056 ;------------------------------------------------------------
                           0002AC  2057 	G$disable_radio_interrupt_in_mcu_pin$0$0 ==.
                           0002AC  2058 	C$main.c$691$1$405 ==.
                                   2059 ;	main.c:691: void disable_radio_interrupt_in_mcu_pin(void)
                                   2060 ;	-----------------------------------------
                                   2061 ;	 function disable_radio_interrupt_in_mcu_pin
                                   2062 ;	-----------------------------------------
      003F0F                       2063 _disable_radio_interrupt_in_mcu_pin:
                           0002AC  2064 	C$main.c$693$1$407 ==.
                                   2065 ;	main.c:693: IE_4 = 0;
      003F0F C2 AC            [12] 2066 	clr	_IE_4
                           0002AE  2067 	C$main.c$694$1$407 ==.
                           0002AE  2068 	XG$disable_radio_interrupt_in_mcu_pin$0$0 ==.
      003F11 22               [24] 2069 	ret
                                   2070 ;------------------------------------------------------------
                                   2071 ;Allocation info for local variables in function '_sdcc_external_startup'
                                   2072 ;------------------------------------------------------------
                                   2073 ;c                         Allocated to registers 
                                   2074 ;p                         Allocated to registers 
                                   2075 ;c                         Allocated to registers 
                                   2076 ;p                         Allocated to registers 
                                   2077 ;------------------------------------------------------------
                           0002AF  2078 	G$_sdcc_external_startup$0$0 ==.
                           0002AF  2079 	C$main.c$697$1$407 ==.
                                   2080 ;	main.c:697: uint8_t _sdcc_external_startup(void)
                                   2081 ;	-----------------------------------------
                                   2082 ;	 function _sdcc_external_startup
                                   2083 ;	-----------------------------------------
      003F12                       2084 __sdcc_external_startup:
                           0002AF  2085 	C$main.c$699$2$410 ==.
                                   2086 ;	main.c:699: wtimer0_setclksrc(WTIMER0_CLKSRC, WTIMER0_PRESCALER);
      003F12 75 82 09         [24] 2087 	mov	dpl,#0x09
      003F15 12 41 96         [24] 2088 	lcall	_wtimer0_setconfig
                           0002B5  2089 	C$main.c$700$2$411 ==.
                                   2090 ;	main.c:700: wtimer1_setclksrc(CLKSRC_FRCOSC, 7);
      003F18 75 82 38         [24] 2091 	mov	dpl,#0x38
      003F1B 12 41 B0         [24] 2092 	lcall	_wtimer1_setconfig
                           0002BB  2093 	C$main.c$702$1$409 ==.
                                   2094 ;	main.c:702: coldstart = !(PCON & 0x40);
      003F1E E5 87            [12] 2095 	mov	a,_PCON
      003F20 A2 E6            [12] 2096 	mov	c,acc[6]
      003F22 B3               [12] 2097 	cpl	c
      003F23 92 01            [24] 2098 	mov	__sdcc_external_startup_sloc0_1_0,c
      003F25 E4               [12] 2099 	clr	a
      003F26 33               [12] 2100 	rlc	a
      003F27 F5 22            [12] 2101 	mov	_coldstart,a
                           0002C6  2102 	C$main.c$703$1$409 ==.
                                   2103 ;	main.c:703: ANALOGA = 0x18; /* PA[3,4] LPXOSC, other PA are used as digital pins */
      003F29 90 70 07         [24] 2104 	mov	dptr,#_ANALOGA
      003F2C 74 18            [12] 2105 	mov	a,#0x18
      003F2E F0               [24] 2106 	movx	@dptr,a
                           0002CC  2107 	C$main.c$704$1$409 ==.
                                   2108 ;	main.c:704: PORTA = 0xE7; /* pull ups except for LPXOSC pin PA[3,4]; */
      003F2F 75 80 E7         [24] 2109 	mov	_PORTA,#0xe7
                           0002CF  2110 	C$main.c$705$1$409 ==.
                                   2111 ;	main.c:705: PORTB = 0xFD | (PINB & 0x02); /* init LEDs to previous (frozen) state */
      003F32 74 02            [12] 2112 	mov	a,#0x02
      003F34 55 E8            [12] 2113 	anl	a,_PINB
      003F36 44 FD            [12] 2114 	orl	a,#0xfd
      003F38 F5 88            [12] 2115 	mov	_PORTB,a
                           0002D7  2116 	C$main.c$706$1$409 ==.
                                   2117 ;	main.c:706: PORTC = 0xFF; /* */
      003F3A 75 90 FF         [24] 2118 	mov	_PORTC,#0xff
                           0002DA  2119 	C$main.c$707$1$409 ==.
                                   2120 ;	main.c:707: PORTR = 0x0B; /* */
      003F3D 75 8C 0B         [24] 2121 	mov	_PORTR,#0x0b
                           0002DD  2122 	C$main.c$709$1$409 ==.
                                   2123 ;	main.c:709: DIRA = 0x00; /* */
      003F40 75 89 00         [24] 2124 	mov	_DIRA,#0x00
                           0002E0  2125 	C$main.c$710$1$409 ==.
                                   2126 ;	main.c:710: DIRB = 0x0e; /*  PB1 = LED; PB2 / PB3 are outputs (in case PWRAMP / ANSTSEL are used) */
      003F43 75 8A 0E         [24] 2127 	mov	_DIRB,#0x0e
                           0002E3  2128 	C$main.c$711$1$409 ==.
                                   2129 ;	main.c:711: DIRC = 0x00; /*  PC4 = button */
      003F46 75 8B 00         [24] 2130 	mov	_DIRC,#0x00
                           0002E6  2131 	C$main.c$712$1$409 ==.
                                   2132 ;	main.c:712: DIRR = 0x15; /* */
      003F49 75 8E 15         [24] 2133 	mov	_DIRR,#0x15
                           0002E9  2134 	C$main.c$714$1$409 ==.
                                   2135 ;	main.c:714: axradio_setup_pincfg1();
      003F4C 12 06 CB         [24] 2136 	lcall	_axradio_setup_pincfg1
                           0002EC  2137 	C$main.c$715$1$409 ==.
                                   2138 ;	main.c:715: DPS = 0;
      003F4F 75 86 00         [24] 2139 	mov	_DPS,#0x00
                           0002EF  2140 	C$main.c$716$1$409 ==.
                                   2141 ;	main.c:716: IE = 0x40;
      003F52 75 A8 40         [24] 2142 	mov	_IE,#0x40
                           0002F2  2143 	C$main.c$717$1$409 ==.
                                   2144 ;	main.c:717: EIE = 0x00;
      003F55 75 98 00         [24] 2145 	mov	_EIE,#0x00
                           0002F5  2146 	C$main.c$718$1$409 ==.
                                   2147 ;	main.c:718: E2IE = 0x00;
      003F58 75 A0 00         [24] 2148 	mov	_E2IE,#0x00
                           0002F8  2149 	C$main.c$720$1$409 ==.
                                   2150 ;	main.c:720: GPIOENABLE = 1; /* unfreeze GPIO */
      003F5B 90 70 0C         [24] 2151 	mov	dptr,#_GPIOENABLE
      003F5E 74 01            [12] 2152 	mov	a,#0x01
      003F60 F0               [24] 2153 	movx	@dptr,a
                           0002FE  2154 	C$main.c$721$1$409 ==.
                                   2155 ;	main.c:721: return !coldstart; /* coldstart -> return 0 -> var initialization; start from sleep -> return 1 -> no var initialization */
      003F61 E5 22            [12] 2156 	mov	a,_coldstart
      003F63 B4 01 00         [24] 2157 	cjne	a,#0x01,00111$
      003F66                       2158 00111$:
      003F66 92 01            [24] 2159 	mov  __sdcc_external_startup_sloc0_1_0,c
      003F68 E4               [12] 2160 	clr	a
      003F69 33               [12] 2161 	rlc	a
      003F6A F5 82            [12] 2162 	mov	dpl,a
                           000309  2163 	C$main.c$722$1$409 ==.
                           000309  2164 	XG$_sdcc_external_startup$0$0 ==.
      003F6C 22               [24] 2165 	ret
                                   2166 ;------------------------------------------------------------
                                   2167 ;Allocation info for local variables in function 'main'
                                   2168 ;------------------------------------------------------------
                                   2169 ;i                         Allocated to registers 
                                   2170 ;crit                      Allocated with name '_main_crit_1_414'
                                   2171 ;flg                       Allocated to registers r7 
                                   2172 ;flg                       Allocated to registers r7 
                                   2173 ;------------------------------------------------------------
                           00030A  2174 	G$main$0$0 ==.
                           00030A  2175 	C$main.c$724$1$409 ==.
                                   2176 ;	main.c:724: int main(void)
                                   2177 ;	-----------------------------------------
                                   2178 ;	 function main
                                   2179 ;	-----------------------------------------
      003F6D                       2180 _main:
                           00030A  2181 	C$main.c$731$1$414 ==.
                                   2182 ;	main.c:731: __endasm;
                           000000  2183 	G$_start__stack$0$0	= __start__stack
                                   2184 	.globl	G$_start__stack$0$0
                           00030A  2185 	C$libmftypes.h$368$4$438 ==.
                                   2186 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:368: EA = 1;
      003F6D D2 AF            [12] 2187 	setb	_EA
                           00030C  2188 	C$main.c$736$1$414 ==.
                                   2189 ;	main.c:736: flash_apply_calibration();
      003F6F 12 47 91         [24] 2190 	lcall	_flash_apply_calibration
                           00030F  2191 	C$main.c$737$1$414 ==.
                                   2192 ;	main.c:737: CLKCON = 0x00;
      003F72 75 C6 00         [24] 2193 	mov	_CLKCON,#0x00
                           000312  2194 	C$main.c$738$1$414 ==.
                                   2195 ;	main.c:738: wtimer_init();
      003F75 12 42 5F         [24] 2196 	lcall	_wtimer_init
                           000315  2197 	C$main.c$740$1$414 ==.
                                   2198 ;	main.c:740: if (coldstart)
      003F78 E5 22            [12] 2199 	mov	a,_coldstart
      003F7A 60 0B            [24] 2200 	jz	00135$
                           000319  2201 	C$main.c$742$4$417 ==.
                                   2202 ;	main.c:742: led0_off();
      003F7C C2 89            [12] 2203 	clr	_PORTB_1
                           00031B  2204 	C$main.c$750$2$415 ==.
                                   2205 ;	main.c:750: i = axradio_init();             /* to be fixed PB3 to PC4 */
      003F7E 12 2A DF         [24] 2206 	lcall	_axradio_init
      003F81 E5 82            [12] 2207 	mov	a,dpl
                           000320  2208 	C$main.c$752$2$415 ==.
                                   2209 ;	main.c:752: if (i != AXRADIO_ERR_NOERROR)
      003F83 60 07            [24] 2210 	jz	00136$
                           000322  2211 	C$main.c$763$4$427 ==.
                                   2212 ;	main.c:763: goto terminate_error;
                           000322  2213 	C$main.c$769$1$414 ==.
                                   2214 ;	main.c:769: display_writestr(radio_lcd_display);
      003F85 80 24            [24] 2215 	sjmp	00163$
      003F87                       2216 00135$:
                           000324  2217 	C$main.c$812$2$430 ==.
                                   2218 ;	main.c:812: axradio_commsleepexit();
      003F87 12 3A 96         [24] 2219 	lcall	_axradio_commsleepexit
                           000327  2220 	C$main.c$813$2$430 ==.
                                   2221 ;	main.c:813: IE_4 = 1; /* enable radio interrupt */
      003F8A D2 AC            [12] 2222 	setb	_IE_4
      003F8C                       2223 00136$:
                           000329  2224 	C$main.c$816$1$414 ==.
                                   2225 ;	main.c:816: axradio_setup_pincfg2();
      003F8C 12 06 D1         [24] 2226 	lcall	_axradio_setup_pincfg2
                           00032C  2227 	C$main.c$821$2$431 ==.
                                   2228 ;	main.c:821: set_cw();
      003F8F 12 3E 9E         [24] 2229 	lcall	_set_cw
                           00032F  2230 	C$main.c$873$1$414 ==.
                                   2231 ;	main.c:873: }
      003F92                       2232 00161$:
                           00032F  2233 	C$main.c$877$2$432 ==.
                                   2234 ;	main.c:877: wtimer_runcallbacks();
      003F92 12 44 17         [24] 2235 	lcall	_wtimer_runcallbacks
                           000332  2236 	C$main.c$879$3$432 ==.
                                   2237 ;	main.c:879: uint8_t flg = WTFLAG_CANSTANDBY;
      003F95 7F 02            [12] 2238 	mov	r7,#0x02
                           000334  2239 	C$main.c$882$3$433 ==.
                                   2240 ;	main.c:882: if (axradio_cansleep()
      003F97 C0 07            [24] 2241 	push	ar7
      003F99 12 2E D1         [24] 2242 	lcall	_axradio_cansleep
      003F9C E5 82            [12] 2243 	mov	a,dpl
      003F9E D0 07            [24] 2244 	pop	ar7
      003FA0 60 02            [24] 2245 	jz	00152$
                           00033F  2246 	C$main.c$887$3$433 ==.
                                   2247 ;	main.c:887: flg |= WTFLAG_CANSLEEP;
      003FA2 7F 03            [12] 2248 	mov	r7,#0x03
      003FA4                       2249 00152$:
                           000341  2250 	C$main.c$889$3$433 ==.
                                   2251 ;	main.c:889: wtimer_idle(flg);
      003FA4 8F 82            [24] 2252 	mov	dpl,r7
      003FA6 12 43 93         [24] 2253 	lcall	_wtimer_idle
                           000346  2254 	C$main.c$893$1$414 ==.
                                   2255 ;	main.c:893: terminate_error:
      003FA9 80 E7            [24] 2256 	sjmp	00161$
      003FAB                       2257 00163$:
                           000348  2258 	C$main.c$896$2$434 ==.
                                   2259 ;	main.c:896: wtimer_runcallbacks();
      003FAB 12 44 17         [24] 2260 	lcall	_wtimer_runcallbacks
                           00034B  2261 	C$main.c$898$3$434 ==.
                                   2262 ;	main.c:898: uint8_t flg = WTFLAG_CANSTANDBY;
      003FAE 7F 02            [12] 2263 	mov	r7,#0x02
                           00034D  2264 	C$main.c$901$3$435 ==.
                                   2265 ;	main.c:901: if (axradio_cansleep()
      003FB0 C0 07            [24] 2266 	push	ar7
      003FB2 12 2E D1         [24] 2267 	lcall	_axradio_cansleep
      003FB5 E5 82            [12] 2268 	mov	a,dpl
      003FB7 D0 07            [24] 2269 	pop	ar7
      003FB9 60 02            [24] 2270 	jz	00157$
                           000358  2271 	C$main.c$906$3$435 ==.
                                   2272 ;	main.c:906: flg |= WTFLAG_CANSLEEP;
      003FBB 7F 03            [12] 2273 	mov	r7,#0x03
      003FBD                       2274 00157$:
                           00035A  2275 	C$main.c$908$3$435 ==.
                                   2276 ;	main.c:908: wtimer_idle(flg);
      003FBD 8F 82            [24] 2277 	mov	dpl,r7
      003FBF 12 43 93         [24] 2278 	lcall	_wtimer_idle
      003FC2 80 E7            [24] 2279 	sjmp	00163$
                           000361  2280 	C$main.c$911$1$414 ==.
                           000361  2281 	XG$main$0$0 ==.
      003FC4 22               [24] 2282 	ret
                                   2283 	.area CSEG    (CODE)
                                   2284 	.area CONST   (CODE)
                           000000  2285 G$txpattern$0$0 == .
      005029                       2286 _txpattern:
      005029 55                    2287 	.db #0x55	; 85	'U'
      00502A 55                    2288 	.db #0x55	; 85	'U'
      00502B 55                    2289 	.db #0x55	; 85	'U'
      00502C 55                    2290 	.db #0x55	; 85	'U'
      00502D 55                    2291 	.db #0x55	; 85	'U'
      00502E 55                    2292 	.db #0x55	; 85	'U'
      00502F 55                    2293 	.db #0x55	; 85	'U'
      005030 55                    2294 	.db #0x55	; 85	'U'
                           000008  2295 G$onepattern$0$0 == .
      005031                       2296 _onepattern:
      005031 FF                    2297 	.db #0xff	; 255
      005032 FF                    2298 	.db #0xff	; 255
      005033 FF                    2299 	.db #0xff	; 255
      005034 FF                    2300 	.db #0xff	; 255
      005035 FF                    2301 	.db #0xff	; 255
      005036 FF                    2302 	.db #0xff	; 255
      005037 FF                    2303 	.db #0xff	; 255
      005038 FF                    2304 	.db #0xff	; 255
      005039 FF                    2305 	.db #0xff	; 255
      00503A FF                    2306 	.db #0xff	; 255
      00503B FF                    2307 	.db #0xff	; 255
      00503C FF                    2308 	.db #0xff	; 255
      00503D FF                    2309 	.db #0xff	; 255
      00503E FF                    2310 	.db #0xff	; 255
      00503F FF                    2311 	.db #0xff	; 255
      005040 FF                    2312 	.db #0xff	; 255
                           000018  2313 G$fourfsk_tx1010_pattern$0$0 == .
      005041                       2314 _fourfsk_tx1010_pattern:
      005041 1E                    2315 	.db #0x1e	; 30
      005042 1E                    2316 	.db #0x1e	; 30
      005043 1E                    2317 	.db #0x1e	; 30
      005044 1E                    2318 	.db #0x1e	; 30
      005045 1E                    2319 	.db #0x1e	; 30
      005046 1E                    2320 	.db #0x1e	; 30
      005047 1E                    2321 	.db #0x1e	; 30
      005048 1E                    2322 	.db #0x1e	; 30
                           000020  2323 G$non_fourfsk_tx1010_pattern$0$0 == .
      005049                       2324 _non_fourfsk_tx1010_pattern:
      005049 55                    2325 	.db #0x55	; 85	'U'
      00504A 55                    2326 	.db #0x55	; 85	'U'
      00504B 55                    2327 	.db #0x55	; 85	'U'
      00504C 55                    2328 	.db #0x55	; 85	'U'
      00504D 55                    2329 	.db #0x55	; 85	'U'
      00504E 55                    2330 	.db #0x55	; 85	'U'
      00504F 55                    2331 	.db #0x55	; 85	'U'
      005050 55                    2332 	.db #0x55	; 85	'U'
                                   2333 	.area XINIT   (CODE)
                                   2334 	.area CABS    (ABS,CODE)
