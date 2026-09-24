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
                                     11 	.globl _main
                                     12 	.globl __sdcc_external_startup
                                     13 	.globl _delay_ms
                                     14 	.globl _memcpy
                                     15 	.globl _wtimer_runcallbacks
                                     16 	.globl _wtimer_idle
                                     17 	.globl _wtimer_init
                                     18 	.globl _wtimer1_setconfig
                                     19 	.globl _wtimer0_setconfig
                                     20 	.globl _flash_apply_calibration
                                     21 	.globl _axradio_commsleepexit
                                     22 	.globl _axradio_setup_pincfg2
                                     23 	.globl _axradio_setup_pincfg1
                                     24 	.globl _axradio_transmit
                                     25 	.globl _axradio_set_default_remote_address
                                     26 	.globl _axradio_set_local_address
                                     27 	.globl _axradio_set_mode
                                     28 	.globl _axradio_cansleep
                                     29 	.globl _axradio_init
                                     30 	.globl _PORTC_7
                                     31 	.globl _PORTC_6
                                     32 	.globl _PORTC_5
                                     33 	.globl _PORTC_4
                                     34 	.globl _PORTC_3
                                     35 	.globl _PORTC_2
                                     36 	.globl _PORTC_1
                                     37 	.globl _PORTC_0
                                     38 	.globl _PORTB_7
                                     39 	.globl _PORTB_6
                                     40 	.globl _PORTB_5
                                     41 	.globl _PORTB_4
                                     42 	.globl _PORTB_3
                                     43 	.globl _PORTB_2
                                     44 	.globl _PORTB_1
                                     45 	.globl _PORTB_0
                                     46 	.globl _PORTA_7
                                     47 	.globl _PORTA_6
                                     48 	.globl _PORTA_5
                                     49 	.globl _PORTA_4
                                     50 	.globl _PORTA_3
                                     51 	.globl _PORTA_2
                                     52 	.globl _PORTA_1
                                     53 	.globl _PORTA_0
                                     54 	.globl _PINC_7
                                     55 	.globl _PINC_6
                                     56 	.globl _PINC_5
                                     57 	.globl _PINC_4
                                     58 	.globl _PINC_3
                                     59 	.globl _PINC_2
                                     60 	.globl _PINC_1
                                     61 	.globl _PINC_0
                                     62 	.globl _PINB_7
                                     63 	.globl _PINB_6
                                     64 	.globl _PINB_5
                                     65 	.globl _PINB_4
                                     66 	.globl _PINB_3
                                     67 	.globl _PINB_2
                                     68 	.globl _PINB_1
                                     69 	.globl _PINB_0
                                     70 	.globl _PINA_7
                                     71 	.globl _PINA_6
                                     72 	.globl _PINA_5
                                     73 	.globl _PINA_4
                                     74 	.globl _PINA_3
                                     75 	.globl _PINA_2
                                     76 	.globl _PINA_1
                                     77 	.globl _PINA_0
                                     78 	.globl _CY
                                     79 	.globl _AC
                                     80 	.globl _F0
                                     81 	.globl _RS1
                                     82 	.globl _RS0
                                     83 	.globl _OV
                                     84 	.globl _F1
                                     85 	.globl _P
                                     86 	.globl _IP_7
                                     87 	.globl _IP_6
                                     88 	.globl _IP_5
                                     89 	.globl _IP_4
                                     90 	.globl _IP_3
                                     91 	.globl _IP_2
                                     92 	.globl _IP_1
                                     93 	.globl _IP_0
                                     94 	.globl _EA
                                     95 	.globl _IE_7
                                     96 	.globl _IE_6
                                     97 	.globl _IE_5
                                     98 	.globl _IE_4
                                     99 	.globl _IE_3
                                    100 	.globl _IE_2
                                    101 	.globl _IE_1
                                    102 	.globl _IE_0
                                    103 	.globl _EIP_7
                                    104 	.globl _EIP_6
                                    105 	.globl _EIP_5
                                    106 	.globl _EIP_4
                                    107 	.globl _EIP_3
                                    108 	.globl _EIP_2
                                    109 	.globl _EIP_1
                                    110 	.globl _EIP_0
                                    111 	.globl _EIE_7
                                    112 	.globl _EIE_6
                                    113 	.globl _EIE_5
                                    114 	.globl _EIE_4
                                    115 	.globl _EIE_3
                                    116 	.globl _EIE_2
                                    117 	.globl _EIE_1
                                    118 	.globl _EIE_0
                                    119 	.globl _E2IP_7
                                    120 	.globl _E2IP_6
                                    121 	.globl _E2IP_5
                                    122 	.globl _E2IP_4
                                    123 	.globl _E2IP_3
                                    124 	.globl _E2IP_2
                                    125 	.globl _E2IP_1
                                    126 	.globl _E2IP_0
                                    127 	.globl _E2IE_7
                                    128 	.globl _E2IE_6
                                    129 	.globl _E2IE_5
                                    130 	.globl _E2IE_4
                                    131 	.globl _E2IE_3
                                    132 	.globl _E2IE_2
                                    133 	.globl _E2IE_1
                                    134 	.globl _E2IE_0
                                    135 	.globl _B_7
                                    136 	.globl _B_6
                                    137 	.globl _B_5
                                    138 	.globl _B_4
                                    139 	.globl _B_3
                                    140 	.globl _B_2
                                    141 	.globl _B_1
                                    142 	.globl _B_0
                                    143 	.globl _ACC_7
                                    144 	.globl _ACC_6
                                    145 	.globl _ACC_5
                                    146 	.globl _ACC_4
                                    147 	.globl _ACC_3
                                    148 	.globl _ACC_2
                                    149 	.globl _ACC_1
                                    150 	.globl _ACC_0
                                    151 	.globl _WTSTAT
                                    152 	.globl _WTIRQEN
                                    153 	.globl _WTEVTD
                                    154 	.globl _WTEVTD1
                                    155 	.globl _WTEVTD0
                                    156 	.globl _WTEVTC
                                    157 	.globl _WTEVTC1
                                    158 	.globl _WTEVTC0
                                    159 	.globl _WTEVTB
                                    160 	.globl _WTEVTB1
                                    161 	.globl _WTEVTB0
                                    162 	.globl _WTEVTA
                                    163 	.globl _WTEVTA1
                                    164 	.globl _WTEVTA0
                                    165 	.globl _WTCNTR1
                                    166 	.globl _WTCNTB
                                    167 	.globl _WTCNTB1
                                    168 	.globl _WTCNTB0
                                    169 	.globl _WTCNTA
                                    170 	.globl _WTCNTA1
                                    171 	.globl _WTCNTA0
                                    172 	.globl _WTCFGB
                                    173 	.globl _WTCFGA
                                    174 	.globl _WDTRESET
                                    175 	.globl _WDTCFG
                                    176 	.globl _U1STATUS
                                    177 	.globl _U1SHREG
                                    178 	.globl _U1MODE
                                    179 	.globl _U1CTRL
                                    180 	.globl _U0STATUS
                                    181 	.globl _U0SHREG
                                    182 	.globl _U0MODE
                                    183 	.globl _U0CTRL
                                    184 	.globl _T2STATUS
                                    185 	.globl _T2PERIOD
                                    186 	.globl _T2PERIOD1
                                    187 	.globl _T2PERIOD0
                                    188 	.globl _T2MODE
                                    189 	.globl _T2CNT
                                    190 	.globl _T2CNT1
                                    191 	.globl _T2CNT0
                                    192 	.globl _T2CLKSRC
                                    193 	.globl _T1STATUS
                                    194 	.globl _T1PERIOD
                                    195 	.globl _T1PERIOD1
                                    196 	.globl _T1PERIOD0
                                    197 	.globl _T1MODE
                                    198 	.globl _T1CNT
                                    199 	.globl _T1CNT1
                                    200 	.globl _T1CNT0
                                    201 	.globl _T1CLKSRC
                                    202 	.globl _T0STATUS
                                    203 	.globl _T0PERIOD
                                    204 	.globl _T0PERIOD1
                                    205 	.globl _T0PERIOD0
                                    206 	.globl _T0MODE
                                    207 	.globl _T0CNT
                                    208 	.globl _T0CNT1
                                    209 	.globl _T0CNT0
                                    210 	.globl _T0CLKSRC
                                    211 	.globl _SPSTATUS
                                    212 	.globl _SPSHREG
                                    213 	.globl _SPMODE
                                    214 	.globl _SPCLKSRC
                                    215 	.globl _RADIOSTAT
                                    216 	.globl _RADIOSTAT1
                                    217 	.globl _RADIOSTAT0
                                    218 	.globl _RADIODATA
                                    219 	.globl _RADIODATA3
                                    220 	.globl _RADIODATA2
                                    221 	.globl _RADIODATA1
                                    222 	.globl _RADIODATA0
                                    223 	.globl _RADIOADDR
                                    224 	.globl _RADIOADDR1
                                    225 	.globl _RADIOADDR0
                                    226 	.globl _RADIOACC
                                    227 	.globl _OC1STATUS
                                    228 	.globl _OC1PIN
                                    229 	.globl _OC1MODE
                                    230 	.globl _OC1COMP
                                    231 	.globl _OC1COMP1
                                    232 	.globl _OC1COMP0
                                    233 	.globl _OC0STATUS
                                    234 	.globl _OC0PIN
                                    235 	.globl _OC0MODE
                                    236 	.globl _OC0COMP
                                    237 	.globl _OC0COMP1
                                    238 	.globl _OC0COMP0
                                    239 	.globl _NVSTATUS
                                    240 	.globl _NVKEY
                                    241 	.globl _NVDATA
                                    242 	.globl _NVDATA1
                                    243 	.globl _NVDATA0
                                    244 	.globl _NVADDR
                                    245 	.globl _NVADDR1
                                    246 	.globl _NVADDR0
                                    247 	.globl _IC1STATUS
                                    248 	.globl _IC1MODE
                                    249 	.globl _IC1CAPT
                                    250 	.globl _IC1CAPT1
                                    251 	.globl _IC1CAPT0
                                    252 	.globl _IC0STATUS
                                    253 	.globl _IC0MODE
                                    254 	.globl _IC0CAPT
                                    255 	.globl _IC0CAPT1
                                    256 	.globl _IC0CAPT0
                                    257 	.globl _PORTR
                                    258 	.globl _PORTC
                                    259 	.globl _PORTB
                                    260 	.globl _PORTA
                                    261 	.globl _PINR
                                    262 	.globl _PINC
                                    263 	.globl _PINB
                                    264 	.globl _PINA
                                    265 	.globl _DIRR
                                    266 	.globl _DIRC
                                    267 	.globl _DIRB
                                    268 	.globl _DIRA
                                    269 	.globl _DBGLNKSTAT
                                    270 	.globl _DBGLNKBUF
                                    271 	.globl _CODECONFIG
                                    272 	.globl _CLKSTAT
                                    273 	.globl _CLKCON
                                    274 	.globl _ANALOGCOMP
                                    275 	.globl _ADCCONV
                                    276 	.globl _ADCCLKSRC
                                    277 	.globl _ADCCH3CONFIG
                                    278 	.globl _ADCCH2CONFIG
                                    279 	.globl _ADCCH1CONFIG
                                    280 	.globl _ADCCH0CONFIG
                                    281 	.globl __XPAGE
                                    282 	.globl _XPAGE
                                    283 	.globl _SP
                                    284 	.globl _PSW
                                    285 	.globl _PCON
                                    286 	.globl _IP
                                    287 	.globl _IE
                                    288 	.globl _EIP
                                    289 	.globl _EIE
                                    290 	.globl _E2IP
                                    291 	.globl _E2IE
                                    292 	.globl _DPS
                                    293 	.globl _DPTR1
                                    294 	.globl _DPTR0
                                    295 	.globl _DPL1
                                    296 	.globl _DPL
                                    297 	.globl _DPH1
                                    298 	.globl _DPH
                                    299 	.globl _B
                                    300 	.globl _ACC
                                    301 	.globl _wakeup_desc
                                    302 	.globl _XTALREADY
                                    303 	.globl _XTALOSC
                                    304 	.globl _XTALAMPL
                                    305 	.globl _SILICONREV
                                    306 	.globl _SCRATCH3
                                    307 	.globl _SCRATCH2
                                    308 	.globl _SCRATCH1
                                    309 	.globl _SCRATCH0
                                    310 	.globl _RADIOMUX
                                    311 	.globl _RADIOFSTATADDR
                                    312 	.globl _RADIOFSTATADDR1
                                    313 	.globl _RADIOFSTATADDR0
                                    314 	.globl _RADIOFDATAADDR
                                    315 	.globl _RADIOFDATAADDR1
                                    316 	.globl _RADIOFDATAADDR0
                                    317 	.globl _OSCRUN
                                    318 	.globl _OSCREADY
                                    319 	.globl _OSCFORCERUN
                                    320 	.globl _OSCCALIB
                                    321 	.globl _MISCCTRL
                                    322 	.globl _LPXOSCGM
                                    323 	.globl _LPOSCREF
                                    324 	.globl _LPOSCREF1
                                    325 	.globl _LPOSCREF0
                                    326 	.globl _LPOSCPER
                                    327 	.globl _LPOSCPER1
                                    328 	.globl _LPOSCPER0
                                    329 	.globl _LPOSCKFILT
                                    330 	.globl _LPOSCKFILT1
                                    331 	.globl _LPOSCKFILT0
                                    332 	.globl _LPOSCFREQ
                                    333 	.globl _LPOSCFREQ1
                                    334 	.globl _LPOSCFREQ0
                                    335 	.globl _LPOSCCONFIG
                                    336 	.globl _PINSEL
                                    337 	.globl _PINCHGC
                                    338 	.globl _PINCHGB
                                    339 	.globl _PINCHGA
                                    340 	.globl _PALTRADIO
                                    341 	.globl _PALTC
                                    342 	.globl _PALTB
                                    343 	.globl _PALTA
                                    344 	.globl _INTCHGC
                                    345 	.globl _INTCHGB
                                    346 	.globl _INTCHGA
                                    347 	.globl _EXTIRQ
                                    348 	.globl _GPIOENABLE
                                    349 	.globl _ANALOGA
                                    350 	.globl _FRCOSCREF
                                    351 	.globl _FRCOSCREF1
                                    352 	.globl _FRCOSCREF0
                                    353 	.globl _FRCOSCPER
                                    354 	.globl _FRCOSCPER1
                                    355 	.globl _FRCOSCPER0
                                    356 	.globl _FRCOSCKFILT
                                    357 	.globl _FRCOSCKFILT1
                                    358 	.globl _FRCOSCKFILT0
                                    359 	.globl _FRCOSCFREQ
                                    360 	.globl _FRCOSCFREQ1
                                    361 	.globl _FRCOSCFREQ0
                                    362 	.globl _FRCOSCCTRL
                                    363 	.globl _FRCOSCCONFIG
                                    364 	.globl _DMA1CONFIG
                                    365 	.globl _DMA1ADDR
                                    366 	.globl _DMA1ADDR1
                                    367 	.globl _DMA1ADDR0
                                    368 	.globl _DMA0CONFIG
                                    369 	.globl _DMA0ADDR
                                    370 	.globl _DMA0ADDR1
                                    371 	.globl _DMA0ADDR0
                                    372 	.globl _ADCTUNE2
                                    373 	.globl _ADCTUNE1
                                    374 	.globl _ADCTUNE0
                                    375 	.globl _ADCCH3VAL
                                    376 	.globl _ADCCH3VAL1
                                    377 	.globl _ADCCH3VAL0
                                    378 	.globl _ADCCH2VAL
                                    379 	.globl _ADCCH2VAL1
                                    380 	.globl _ADCCH2VAL0
                                    381 	.globl _ADCCH1VAL
                                    382 	.globl _ADCCH1VAL1
                                    383 	.globl _ADCCH1VAL0
                                    384 	.globl _ADCCH0VAL
                                    385 	.globl _ADCCH0VAL1
                                    386 	.globl _ADCCH0VAL0
                                    387 	.globl _coldstart
                                    388 	.globl _pkt_counter
                                    389 	.globl _axradio_statuschange
                                    390 	.globl _enable_radio_interrupt_in_mcu_pin
                                    391 	.globl _disable_radio_interrupt_in_mcu_pin
                                    392 ;--------------------------------------------------------
                                    393 ; special function registers
                                    394 ;--------------------------------------------------------
                                    395 	.area RSEG    (ABS,DATA)
      000000                        396 	.org 0x0000
                           0000E0   397 G$ACC$0$0 == 0x00e0
                           0000E0   398 _ACC	=	0x00e0
                           0000F0   399 G$B$0$0 == 0x00f0
                           0000F0   400 _B	=	0x00f0
                           000083   401 G$DPH$0$0 == 0x0083
                           000083   402 _DPH	=	0x0083
                           000085   403 G$DPH1$0$0 == 0x0085
                           000085   404 _DPH1	=	0x0085
                           000082   405 G$DPL$0$0 == 0x0082
                           000082   406 _DPL	=	0x0082
                           000084   407 G$DPL1$0$0 == 0x0084
                           000084   408 _DPL1	=	0x0084
                           008382   409 G$DPTR0$0$0 == 0x8382
                           008382   410 _DPTR0	=	0x8382
                           008584   411 G$DPTR1$0$0 == 0x8584
                           008584   412 _DPTR1	=	0x8584
                           000086   413 G$DPS$0$0 == 0x0086
                           000086   414 _DPS	=	0x0086
                           0000A0   415 G$E2IE$0$0 == 0x00a0
                           0000A0   416 _E2IE	=	0x00a0
                           0000C0   417 G$E2IP$0$0 == 0x00c0
                           0000C0   418 _E2IP	=	0x00c0
                           000098   419 G$EIE$0$0 == 0x0098
                           000098   420 _EIE	=	0x0098
                           0000B0   421 G$EIP$0$0 == 0x00b0
                           0000B0   422 _EIP	=	0x00b0
                           0000A8   423 G$IE$0$0 == 0x00a8
                           0000A8   424 _IE	=	0x00a8
                           0000B8   425 G$IP$0$0 == 0x00b8
                           0000B8   426 _IP	=	0x00b8
                           000087   427 G$PCON$0$0 == 0x0087
                           000087   428 _PCON	=	0x0087
                           0000D0   429 G$PSW$0$0 == 0x00d0
                           0000D0   430 _PSW	=	0x00d0
                           000081   431 G$SP$0$0 == 0x0081
                           000081   432 _SP	=	0x0081
                           0000D9   433 G$XPAGE$0$0 == 0x00d9
                           0000D9   434 _XPAGE	=	0x00d9
                           0000D9   435 G$_XPAGE$0$0 == 0x00d9
                           0000D9   436 __XPAGE	=	0x00d9
                           0000CA   437 G$ADCCH0CONFIG$0$0 == 0x00ca
                           0000CA   438 _ADCCH0CONFIG	=	0x00ca
                           0000CB   439 G$ADCCH1CONFIG$0$0 == 0x00cb
                           0000CB   440 _ADCCH1CONFIG	=	0x00cb
                           0000D2   441 G$ADCCH2CONFIG$0$0 == 0x00d2
                           0000D2   442 _ADCCH2CONFIG	=	0x00d2
                           0000D3   443 G$ADCCH3CONFIG$0$0 == 0x00d3
                           0000D3   444 _ADCCH3CONFIG	=	0x00d3
                           0000D1   445 G$ADCCLKSRC$0$0 == 0x00d1
                           0000D1   446 _ADCCLKSRC	=	0x00d1
                           0000C9   447 G$ADCCONV$0$0 == 0x00c9
                           0000C9   448 _ADCCONV	=	0x00c9
                           0000E1   449 G$ANALOGCOMP$0$0 == 0x00e1
                           0000E1   450 _ANALOGCOMP	=	0x00e1
                           0000C6   451 G$CLKCON$0$0 == 0x00c6
                           0000C6   452 _CLKCON	=	0x00c6
                           0000C7   453 G$CLKSTAT$0$0 == 0x00c7
                           0000C7   454 _CLKSTAT	=	0x00c7
                           000097   455 G$CODECONFIG$0$0 == 0x0097
                           000097   456 _CODECONFIG	=	0x0097
                           0000E3   457 G$DBGLNKBUF$0$0 == 0x00e3
                           0000E3   458 _DBGLNKBUF	=	0x00e3
                           0000E2   459 G$DBGLNKSTAT$0$0 == 0x00e2
                           0000E2   460 _DBGLNKSTAT	=	0x00e2
                           000089   461 G$DIRA$0$0 == 0x0089
                           000089   462 _DIRA	=	0x0089
                           00008A   463 G$DIRB$0$0 == 0x008a
                           00008A   464 _DIRB	=	0x008a
                           00008B   465 G$DIRC$0$0 == 0x008b
                           00008B   466 _DIRC	=	0x008b
                           00008E   467 G$DIRR$0$0 == 0x008e
                           00008E   468 _DIRR	=	0x008e
                           0000C8   469 G$PINA$0$0 == 0x00c8
                           0000C8   470 _PINA	=	0x00c8
                           0000E8   471 G$PINB$0$0 == 0x00e8
                           0000E8   472 _PINB	=	0x00e8
                           0000F8   473 G$PINC$0$0 == 0x00f8
                           0000F8   474 _PINC	=	0x00f8
                           00008D   475 G$PINR$0$0 == 0x008d
                           00008D   476 _PINR	=	0x008d
                           000080   477 G$PORTA$0$0 == 0x0080
                           000080   478 _PORTA	=	0x0080
                           000088   479 G$PORTB$0$0 == 0x0088
                           000088   480 _PORTB	=	0x0088
                           000090   481 G$PORTC$0$0 == 0x0090
                           000090   482 _PORTC	=	0x0090
                           00008C   483 G$PORTR$0$0 == 0x008c
                           00008C   484 _PORTR	=	0x008c
                           0000CE   485 G$IC0CAPT0$0$0 == 0x00ce
                           0000CE   486 _IC0CAPT0	=	0x00ce
                           0000CF   487 G$IC0CAPT1$0$0 == 0x00cf
                           0000CF   488 _IC0CAPT1	=	0x00cf
                           00CFCE   489 G$IC0CAPT$0$0 == 0xcfce
                           00CFCE   490 _IC0CAPT	=	0xcfce
                           0000CC   491 G$IC0MODE$0$0 == 0x00cc
                           0000CC   492 _IC0MODE	=	0x00cc
                           0000CD   493 G$IC0STATUS$0$0 == 0x00cd
                           0000CD   494 _IC0STATUS	=	0x00cd
                           0000D6   495 G$IC1CAPT0$0$0 == 0x00d6
                           0000D6   496 _IC1CAPT0	=	0x00d6
                           0000D7   497 G$IC1CAPT1$0$0 == 0x00d7
                           0000D7   498 _IC1CAPT1	=	0x00d7
                           00D7D6   499 G$IC1CAPT$0$0 == 0xd7d6
                           00D7D6   500 _IC1CAPT	=	0xd7d6
                           0000D4   501 G$IC1MODE$0$0 == 0x00d4
                           0000D4   502 _IC1MODE	=	0x00d4
                           0000D5   503 G$IC1STATUS$0$0 == 0x00d5
                           0000D5   504 _IC1STATUS	=	0x00d5
                           000092   505 G$NVADDR0$0$0 == 0x0092
                           000092   506 _NVADDR0	=	0x0092
                           000093   507 G$NVADDR1$0$0 == 0x0093
                           000093   508 _NVADDR1	=	0x0093
                           009392   509 G$NVADDR$0$0 == 0x9392
                           009392   510 _NVADDR	=	0x9392
                           000094   511 G$NVDATA0$0$0 == 0x0094
                           000094   512 _NVDATA0	=	0x0094
                           000095   513 G$NVDATA1$0$0 == 0x0095
                           000095   514 _NVDATA1	=	0x0095
                           009594   515 G$NVDATA$0$0 == 0x9594
                           009594   516 _NVDATA	=	0x9594
                           000096   517 G$NVKEY$0$0 == 0x0096
                           000096   518 _NVKEY	=	0x0096
                           000091   519 G$NVSTATUS$0$0 == 0x0091
                           000091   520 _NVSTATUS	=	0x0091
                           0000BC   521 G$OC0COMP0$0$0 == 0x00bc
                           0000BC   522 _OC0COMP0	=	0x00bc
                           0000BD   523 G$OC0COMP1$0$0 == 0x00bd
                           0000BD   524 _OC0COMP1	=	0x00bd
                           00BDBC   525 G$OC0COMP$0$0 == 0xbdbc
                           00BDBC   526 _OC0COMP	=	0xbdbc
                           0000B9   527 G$OC0MODE$0$0 == 0x00b9
                           0000B9   528 _OC0MODE	=	0x00b9
                           0000BA   529 G$OC0PIN$0$0 == 0x00ba
                           0000BA   530 _OC0PIN	=	0x00ba
                           0000BB   531 G$OC0STATUS$0$0 == 0x00bb
                           0000BB   532 _OC0STATUS	=	0x00bb
                           0000C4   533 G$OC1COMP0$0$0 == 0x00c4
                           0000C4   534 _OC1COMP0	=	0x00c4
                           0000C5   535 G$OC1COMP1$0$0 == 0x00c5
                           0000C5   536 _OC1COMP1	=	0x00c5
                           00C5C4   537 G$OC1COMP$0$0 == 0xc5c4
                           00C5C4   538 _OC1COMP	=	0xc5c4
                           0000C1   539 G$OC1MODE$0$0 == 0x00c1
                           0000C1   540 _OC1MODE	=	0x00c1
                           0000C2   541 G$OC1PIN$0$0 == 0x00c2
                           0000C2   542 _OC1PIN	=	0x00c2
                           0000C3   543 G$OC1STATUS$0$0 == 0x00c3
                           0000C3   544 _OC1STATUS	=	0x00c3
                           0000B1   545 G$RADIOACC$0$0 == 0x00b1
                           0000B1   546 _RADIOACC	=	0x00b1
                           0000B3   547 G$RADIOADDR0$0$0 == 0x00b3
                           0000B3   548 _RADIOADDR0	=	0x00b3
                           0000B2   549 G$RADIOADDR1$0$0 == 0x00b2
                           0000B2   550 _RADIOADDR1	=	0x00b2
                           00B2B3   551 G$RADIOADDR$0$0 == 0xb2b3
                           00B2B3   552 _RADIOADDR	=	0xb2b3
                           0000B7   553 G$RADIODATA0$0$0 == 0x00b7
                           0000B7   554 _RADIODATA0	=	0x00b7
                           0000B6   555 G$RADIODATA1$0$0 == 0x00b6
                           0000B6   556 _RADIODATA1	=	0x00b6
                           0000B5   557 G$RADIODATA2$0$0 == 0x00b5
                           0000B5   558 _RADIODATA2	=	0x00b5
                           0000B4   559 G$RADIODATA3$0$0 == 0x00b4
                           0000B4   560 _RADIODATA3	=	0x00b4
                           B4B5B6B7   561 G$RADIODATA$0$0 == 0xb4b5b6b7
                           B4B5B6B7   562 _RADIODATA	=	0xb4b5b6b7
                           0000BE   563 G$RADIOSTAT0$0$0 == 0x00be
                           0000BE   564 _RADIOSTAT0	=	0x00be
                           0000BF   565 G$RADIOSTAT1$0$0 == 0x00bf
                           0000BF   566 _RADIOSTAT1	=	0x00bf
                           00BFBE   567 G$RADIOSTAT$0$0 == 0xbfbe
                           00BFBE   568 _RADIOSTAT	=	0xbfbe
                           0000DF   569 G$SPCLKSRC$0$0 == 0x00df
                           0000DF   570 _SPCLKSRC	=	0x00df
                           0000DC   571 G$SPMODE$0$0 == 0x00dc
                           0000DC   572 _SPMODE	=	0x00dc
                           0000DE   573 G$SPSHREG$0$0 == 0x00de
                           0000DE   574 _SPSHREG	=	0x00de
                           0000DD   575 G$SPSTATUS$0$0 == 0x00dd
                           0000DD   576 _SPSTATUS	=	0x00dd
                           00009A   577 G$T0CLKSRC$0$0 == 0x009a
                           00009A   578 _T0CLKSRC	=	0x009a
                           00009C   579 G$T0CNT0$0$0 == 0x009c
                           00009C   580 _T0CNT0	=	0x009c
                           00009D   581 G$T0CNT1$0$0 == 0x009d
                           00009D   582 _T0CNT1	=	0x009d
                           009D9C   583 G$T0CNT$0$0 == 0x9d9c
                           009D9C   584 _T0CNT	=	0x9d9c
                           000099   585 G$T0MODE$0$0 == 0x0099
                           000099   586 _T0MODE	=	0x0099
                           00009E   587 G$T0PERIOD0$0$0 == 0x009e
                           00009E   588 _T0PERIOD0	=	0x009e
                           00009F   589 G$T0PERIOD1$0$0 == 0x009f
                           00009F   590 _T0PERIOD1	=	0x009f
                           009F9E   591 G$T0PERIOD$0$0 == 0x9f9e
                           009F9E   592 _T0PERIOD	=	0x9f9e
                           00009B   593 G$T0STATUS$0$0 == 0x009b
                           00009B   594 _T0STATUS	=	0x009b
                           0000A2   595 G$T1CLKSRC$0$0 == 0x00a2
                           0000A2   596 _T1CLKSRC	=	0x00a2
                           0000A4   597 G$T1CNT0$0$0 == 0x00a4
                           0000A4   598 _T1CNT0	=	0x00a4
                           0000A5   599 G$T1CNT1$0$0 == 0x00a5
                           0000A5   600 _T1CNT1	=	0x00a5
                           00A5A4   601 G$T1CNT$0$0 == 0xa5a4
                           00A5A4   602 _T1CNT	=	0xa5a4
                           0000A1   603 G$T1MODE$0$0 == 0x00a1
                           0000A1   604 _T1MODE	=	0x00a1
                           0000A6   605 G$T1PERIOD0$0$0 == 0x00a6
                           0000A6   606 _T1PERIOD0	=	0x00a6
                           0000A7   607 G$T1PERIOD1$0$0 == 0x00a7
                           0000A7   608 _T1PERIOD1	=	0x00a7
                           00A7A6   609 G$T1PERIOD$0$0 == 0xa7a6
                           00A7A6   610 _T1PERIOD	=	0xa7a6
                           0000A3   611 G$T1STATUS$0$0 == 0x00a3
                           0000A3   612 _T1STATUS	=	0x00a3
                           0000AA   613 G$T2CLKSRC$0$0 == 0x00aa
                           0000AA   614 _T2CLKSRC	=	0x00aa
                           0000AC   615 G$T2CNT0$0$0 == 0x00ac
                           0000AC   616 _T2CNT0	=	0x00ac
                           0000AD   617 G$T2CNT1$0$0 == 0x00ad
                           0000AD   618 _T2CNT1	=	0x00ad
                           00ADAC   619 G$T2CNT$0$0 == 0xadac
                           00ADAC   620 _T2CNT	=	0xadac
                           0000A9   621 G$T2MODE$0$0 == 0x00a9
                           0000A9   622 _T2MODE	=	0x00a9
                           0000AE   623 G$T2PERIOD0$0$0 == 0x00ae
                           0000AE   624 _T2PERIOD0	=	0x00ae
                           0000AF   625 G$T2PERIOD1$0$0 == 0x00af
                           0000AF   626 _T2PERIOD1	=	0x00af
                           00AFAE   627 G$T2PERIOD$0$0 == 0xafae
                           00AFAE   628 _T2PERIOD	=	0xafae
                           0000AB   629 G$T2STATUS$0$0 == 0x00ab
                           0000AB   630 _T2STATUS	=	0x00ab
                           0000E4   631 G$U0CTRL$0$0 == 0x00e4
                           0000E4   632 _U0CTRL	=	0x00e4
                           0000E7   633 G$U0MODE$0$0 == 0x00e7
                           0000E7   634 _U0MODE	=	0x00e7
                           0000E6   635 G$U0SHREG$0$0 == 0x00e6
                           0000E6   636 _U0SHREG	=	0x00e6
                           0000E5   637 G$U0STATUS$0$0 == 0x00e5
                           0000E5   638 _U0STATUS	=	0x00e5
                           0000EC   639 G$U1CTRL$0$0 == 0x00ec
                           0000EC   640 _U1CTRL	=	0x00ec
                           0000EF   641 G$U1MODE$0$0 == 0x00ef
                           0000EF   642 _U1MODE	=	0x00ef
                           0000EE   643 G$U1SHREG$0$0 == 0x00ee
                           0000EE   644 _U1SHREG	=	0x00ee
                           0000ED   645 G$U1STATUS$0$0 == 0x00ed
                           0000ED   646 _U1STATUS	=	0x00ed
                           0000DA   647 G$WDTCFG$0$0 == 0x00da
                           0000DA   648 _WDTCFG	=	0x00da
                           0000DB   649 G$WDTRESET$0$0 == 0x00db
                           0000DB   650 _WDTRESET	=	0x00db
                           0000F1   651 G$WTCFGA$0$0 == 0x00f1
                           0000F1   652 _WTCFGA	=	0x00f1
                           0000F9   653 G$WTCFGB$0$0 == 0x00f9
                           0000F9   654 _WTCFGB	=	0x00f9
                           0000F2   655 G$WTCNTA0$0$0 == 0x00f2
                           0000F2   656 _WTCNTA0	=	0x00f2
                           0000F3   657 G$WTCNTA1$0$0 == 0x00f3
                           0000F3   658 _WTCNTA1	=	0x00f3
                           00F3F2   659 G$WTCNTA$0$0 == 0xf3f2
                           00F3F2   660 _WTCNTA	=	0xf3f2
                           0000FA   661 G$WTCNTB0$0$0 == 0x00fa
                           0000FA   662 _WTCNTB0	=	0x00fa
                           0000FB   663 G$WTCNTB1$0$0 == 0x00fb
                           0000FB   664 _WTCNTB1	=	0x00fb
                           00FBFA   665 G$WTCNTB$0$0 == 0xfbfa
                           00FBFA   666 _WTCNTB	=	0xfbfa
                           0000EB   667 G$WTCNTR1$0$0 == 0x00eb
                           0000EB   668 _WTCNTR1	=	0x00eb
                           0000F4   669 G$WTEVTA0$0$0 == 0x00f4
                           0000F4   670 _WTEVTA0	=	0x00f4
                           0000F5   671 G$WTEVTA1$0$0 == 0x00f5
                           0000F5   672 _WTEVTA1	=	0x00f5
                           00F5F4   673 G$WTEVTA$0$0 == 0xf5f4
                           00F5F4   674 _WTEVTA	=	0xf5f4
                           0000F6   675 G$WTEVTB0$0$0 == 0x00f6
                           0000F6   676 _WTEVTB0	=	0x00f6
                           0000F7   677 G$WTEVTB1$0$0 == 0x00f7
                           0000F7   678 _WTEVTB1	=	0x00f7
                           00F7F6   679 G$WTEVTB$0$0 == 0xf7f6
                           00F7F6   680 _WTEVTB	=	0xf7f6
                           0000FC   681 G$WTEVTC0$0$0 == 0x00fc
                           0000FC   682 _WTEVTC0	=	0x00fc
                           0000FD   683 G$WTEVTC1$0$0 == 0x00fd
                           0000FD   684 _WTEVTC1	=	0x00fd
                           00FDFC   685 G$WTEVTC$0$0 == 0xfdfc
                           00FDFC   686 _WTEVTC	=	0xfdfc
                           0000FE   687 G$WTEVTD0$0$0 == 0x00fe
                           0000FE   688 _WTEVTD0	=	0x00fe
                           0000FF   689 G$WTEVTD1$0$0 == 0x00ff
                           0000FF   690 _WTEVTD1	=	0x00ff
                           00FFFE   691 G$WTEVTD$0$0 == 0xfffe
                           00FFFE   692 _WTEVTD	=	0xfffe
                           0000E9   693 G$WTIRQEN$0$0 == 0x00e9
                           0000E9   694 _WTIRQEN	=	0x00e9
                           0000EA   695 G$WTSTAT$0$0 == 0x00ea
                           0000EA   696 _WTSTAT	=	0x00ea
                                    697 ;--------------------------------------------------------
                                    698 ; special function bits
                                    699 ;--------------------------------------------------------
                                    700 	.area RSEG    (ABS,DATA)
      000000                        701 	.org 0x0000
                           0000E0   702 G$ACC_0$0$0 == 0x00e0
                           0000E0   703 _ACC_0	=	0x00e0
                           0000E1   704 G$ACC_1$0$0 == 0x00e1
                           0000E1   705 _ACC_1	=	0x00e1
                           0000E2   706 G$ACC_2$0$0 == 0x00e2
                           0000E2   707 _ACC_2	=	0x00e2
                           0000E3   708 G$ACC_3$0$0 == 0x00e3
                           0000E3   709 _ACC_3	=	0x00e3
                           0000E4   710 G$ACC_4$0$0 == 0x00e4
                           0000E4   711 _ACC_4	=	0x00e4
                           0000E5   712 G$ACC_5$0$0 == 0x00e5
                           0000E5   713 _ACC_5	=	0x00e5
                           0000E6   714 G$ACC_6$0$0 == 0x00e6
                           0000E6   715 _ACC_6	=	0x00e6
                           0000E7   716 G$ACC_7$0$0 == 0x00e7
                           0000E7   717 _ACC_7	=	0x00e7
                           0000F0   718 G$B_0$0$0 == 0x00f0
                           0000F0   719 _B_0	=	0x00f0
                           0000F1   720 G$B_1$0$0 == 0x00f1
                           0000F1   721 _B_1	=	0x00f1
                           0000F2   722 G$B_2$0$0 == 0x00f2
                           0000F2   723 _B_2	=	0x00f2
                           0000F3   724 G$B_3$0$0 == 0x00f3
                           0000F3   725 _B_3	=	0x00f3
                           0000F4   726 G$B_4$0$0 == 0x00f4
                           0000F4   727 _B_4	=	0x00f4
                           0000F5   728 G$B_5$0$0 == 0x00f5
                           0000F5   729 _B_5	=	0x00f5
                           0000F6   730 G$B_6$0$0 == 0x00f6
                           0000F6   731 _B_6	=	0x00f6
                           0000F7   732 G$B_7$0$0 == 0x00f7
                           0000F7   733 _B_7	=	0x00f7
                           0000A0   734 G$E2IE_0$0$0 == 0x00a0
                           0000A0   735 _E2IE_0	=	0x00a0
                           0000A1   736 G$E2IE_1$0$0 == 0x00a1
                           0000A1   737 _E2IE_1	=	0x00a1
                           0000A2   738 G$E2IE_2$0$0 == 0x00a2
                           0000A2   739 _E2IE_2	=	0x00a2
                           0000A3   740 G$E2IE_3$0$0 == 0x00a3
                           0000A3   741 _E2IE_3	=	0x00a3
                           0000A4   742 G$E2IE_4$0$0 == 0x00a4
                           0000A4   743 _E2IE_4	=	0x00a4
                           0000A5   744 G$E2IE_5$0$0 == 0x00a5
                           0000A5   745 _E2IE_5	=	0x00a5
                           0000A6   746 G$E2IE_6$0$0 == 0x00a6
                           0000A6   747 _E2IE_6	=	0x00a6
                           0000A7   748 G$E2IE_7$0$0 == 0x00a7
                           0000A7   749 _E2IE_7	=	0x00a7
                           0000C0   750 G$E2IP_0$0$0 == 0x00c0
                           0000C0   751 _E2IP_0	=	0x00c0
                           0000C1   752 G$E2IP_1$0$0 == 0x00c1
                           0000C1   753 _E2IP_1	=	0x00c1
                           0000C2   754 G$E2IP_2$0$0 == 0x00c2
                           0000C2   755 _E2IP_2	=	0x00c2
                           0000C3   756 G$E2IP_3$0$0 == 0x00c3
                           0000C3   757 _E2IP_3	=	0x00c3
                           0000C4   758 G$E2IP_4$0$0 == 0x00c4
                           0000C4   759 _E2IP_4	=	0x00c4
                           0000C5   760 G$E2IP_5$0$0 == 0x00c5
                           0000C5   761 _E2IP_5	=	0x00c5
                           0000C6   762 G$E2IP_6$0$0 == 0x00c6
                           0000C6   763 _E2IP_6	=	0x00c6
                           0000C7   764 G$E2IP_7$0$0 == 0x00c7
                           0000C7   765 _E2IP_7	=	0x00c7
                           000098   766 G$EIE_0$0$0 == 0x0098
                           000098   767 _EIE_0	=	0x0098
                           000099   768 G$EIE_1$0$0 == 0x0099
                           000099   769 _EIE_1	=	0x0099
                           00009A   770 G$EIE_2$0$0 == 0x009a
                           00009A   771 _EIE_2	=	0x009a
                           00009B   772 G$EIE_3$0$0 == 0x009b
                           00009B   773 _EIE_3	=	0x009b
                           00009C   774 G$EIE_4$0$0 == 0x009c
                           00009C   775 _EIE_4	=	0x009c
                           00009D   776 G$EIE_5$0$0 == 0x009d
                           00009D   777 _EIE_5	=	0x009d
                           00009E   778 G$EIE_6$0$0 == 0x009e
                           00009E   779 _EIE_6	=	0x009e
                           00009F   780 G$EIE_7$0$0 == 0x009f
                           00009F   781 _EIE_7	=	0x009f
                           0000B0   782 G$EIP_0$0$0 == 0x00b0
                           0000B0   783 _EIP_0	=	0x00b0
                           0000B1   784 G$EIP_1$0$0 == 0x00b1
                           0000B1   785 _EIP_1	=	0x00b1
                           0000B2   786 G$EIP_2$0$0 == 0x00b2
                           0000B2   787 _EIP_2	=	0x00b2
                           0000B3   788 G$EIP_3$0$0 == 0x00b3
                           0000B3   789 _EIP_3	=	0x00b3
                           0000B4   790 G$EIP_4$0$0 == 0x00b4
                           0000B4   791 _EIP_4	=	0x00b4
                           0000B5   792 G$EIP_5$0$0 == 0x00b5
                           0000B5   793 _EIP_5	=	0x00b5
                           0000B6   794 G$EIP_6$0$0 == 0x00b6
                           0000B6   795 _EIP_6	=	0x00b6
                           0000B7   796 G$EIP_7$0$0 == 0x00b7
                           0000B7   797 _EIP_7	=	0x00b7
                           0000A8   798 G$IE_0$0$0 == 0x00a8
                           0000A8   799 _IE_0	=	0x00a8
                           0000A9   800 G$IE_1$0$0 == 0x00a9
                           0000A9   801 _IE_1	=	0x00a9
                           0000AA   802 G$IE_2$0$0 == 0x00aa
                           0000AA   803 _IE_2	=	0x00aa
                           0000AB   804 G$IE_3$0$0 == 0x00ab
                           0000AB   805 _IE_3	=	0x00ab
                           0000AC   806 G$IE_4$0$0 == 0x00ac
                           0000AC   807 _IE_4	=	0x00ac
                           0000AD   808 G$IE_5$0$0 == 0x00ad
                           0000AD   809 _IE_5	=	0x00ad
                           0000AE   810 G$IE_6$0$0 == 0x00ae
                           0000AE   811 _IE_6	=	0x00ae
                           0000AF   812 G$IE_7$0$0 == 0x00af
                           0000AF   813 _IE_7	=	0x00af
                           0000AF   814 G$EA$0$0 == 0x00af
                           0000AF   815 _EA	=	0x00af
                           0000B8   816 G$IP_0$0$0 == 0x00b8
                           0000B8   817 _IP_0	=	0x00b8
                           0000B9   818 G$IP_1$0$0 == 0x00b9
                           0000B9   819 _IP_1	=	0x00b9
                           0000BA   820 G$IP_2$0$0 == 0x00ba
                           0000BA   821 _IP_2	=	0x00ba
                           0000BB   822 G$IP_3$0$0 == 0x00bb
                           0000BB   823 _IP_3	=	0x00bb
                           0000BC   824 G$IP_4$0$0 == 0x00bc
                           0000BC   825 _IP_4	=	0x00bc
                           0000BD   826 G$IP_5$0$0 == 0x00bd
                           0000BD   827 _IP_5	=	0x00bd
                           0000BE   828 G$IP_6$0$0 == 0x00be
                           0000BE   829 _IP_6	=	0x00be
                           0000BF   830 G$IP_7$0$0 == 0x00bf
                           0000BF   831 _IP_7	=	0x00bf
                           0000D0   832 G$P$0$0 == 0x00d0
                           0000D0   833 _P	=	0x00d0
                           0000D1   834 G$F1$0$0 == 0x00d1
                           0000D1   835 _F1	=	0x00d1
                           0000D2   836 G$OV$0$0 == 0x00d2
                           0000D2   837 _OV	=	0x00d2
                           0000D3   838 G$RS0$0$0 == 0x00d3
                           0000D3   839 _RS0	=	0x00d3
                           0000D4   840 G$RS1$0$0 == 0x00d4
                           0000D4   841 _RS1	=	0x00d4
                           0000D5   842 G$F0$0$0 == 0x00d5
                           0000D5   843 _F0	=	0x00d5
                           0000D6   844 G$AC$0$0 == 0x00d6
                           0000D6   845 _AC	=	0x00d6
                           0000D7   846 G$CY$0$0 == 0x00d7
                           0000D7   847 _CY	=	0x00d7
                           0000C8   848 G$PINA_0$0$0 == 0x00c8
                           0000C8   849 _PINA_0	=	0x00c8
                           0000C9   850 G$PINA_1$0$0 == 0x00c9
                           0000C9   851 _PINA_1	=	0x00c9
                           0000CA   852 G$PINA_2$0$0 == 0x00ca
                           0000CA   853 _PINA_2	=	0x00ca
                           0000CB   854 G$PINA_3$0$0 == 0x00cb
                           0000CB   855 _PINA_3	=	0x00cb
                           0000CC   856 G$PINA_4$0$0 == 0x00cc
                           0000CC   857 _PINA_4	=	0x00cc
                           0000CD   858 G$PINA_5$0$0 == 0x00cd
                           0000CD   859 _PINA_5	=	0x00cd
                           0000CE   860 G$PINA_6$0$0 == 0x00ce
                           0000CE   861 _PINA_6	=	0x00ce
                           0000CF   862 G$PINA_7$0$0 == 0x00cf
                           0000CF   863 _PINA_7	=	0x00cf
                           0000E8   864 G$PINB_0$0$0 == 0x00e8
                           0000E8   865 _PINB_0	=	0x00e8
                           0000E9   866 G$PINB_1$0$0 == 0x00e9
                           0000E9   867 _PINB_1	=	0x00e9
                           0000EA   868 G$PINB_2$0$0 == 0x00ea
                           0000EA   869 _PINB_2	=	0x00ea
                           0000EB   870 G$PINB_3$0$0 == 0x00eb
                           0000EB   871 _PINB_3	=	0x00eb
                           0000EC   872 G$PINB_4$0$0 == 0x00ec
                           0000EC   873 _PINB_4	=	0x00ec
                           0000ED   874 G$PINB_5$0$0 == 0x00ed
                           0000ED   875 _PINB_5	=	0x00ed
                           0000EE   876 G$PINB_6$0$0 == 0x00ee
                           0000EE   877 _PINB_6	=	0x00ee
                           0000EF   878 G$PINB_7$0$0 == 0x00ef
                           0000EF   879 _PINB_7	=	0x00ef
                           0000F8   880 G$PINC_0$0$0 == 0x00f8
                           0000F8   881 _PINC_0	=	0x00f8
                           0000F9   882 G$PINC_1$0$0 == 0x00f9
                           0000F9   883 _PINC_1	=	0x00f9
                           0000FA   884 G$PINC_2$0$0 == 0x00fa
                           0000FA   885 _PINC_2	=	0x00fa
                           0000FB   886 G$PINC_3$0$0 == 0x00fb
                           0000FB   887 _PINC_3	=	0x00fb
                           0000FC   888 G$PINC_4$0$0 == 0x00fc
                           0000FC   889 _PINC_4	=	0x00fc
                           0000FD   890 G$PINC_5$0$0 == 0x00fd
                           0000FD   891 _PINC_5	=	0x00fd
                           0000FE   892 G$PINC_6$0$0 == 0x00fe
                           0000FE   893 _PINC_6	=	0x00fe
                           0000FF   894 G$PINC_7$0$0 == 0x00ff
                           0000FF   895 _PINC_7	=	0x00ff
                           000080   896 G$PORTA_0$0$0 == 0x0080
                           000080   897 _PORTA_0	=	0x0080
                           000081   898 G$PORTA_1$0$0 == 0x0081
                           000081   899 _PORTA_1	=	0x0081
                           000082   900 G$PORTA_2$0$0 == 0x0082
                           000082   901 _PORTA_2	=	0x0082
                           000083   902 G$PORTA_3$0$0 == 0x0083
                           000083   903 _PORTA_3	=	0x0083
                           000084   904 G$PORTA_4$0$0 == 0x0084
                           000084   905 _PORTA_4	=	0x0084
                           000085   906 G$PORTA_5$0$0 == 0x0085
                           000085   907 _PORTA_5	=	0x0085
                           000086   908 G$PORTA_6$0$0 == 0x0086
                           000086   909 _PORTA_6	=	0x0086
                           000087   910 G$PORTA_7$0$0 == 0x0087
                           000087   911 _PORTA_7	=	0x0087
                           000088   912 G$PORTB_0$0$0 == 0x0088
                           000088   913 _PORTB_0	=	0x0088
                           000089   914 G$PORTB_1$0$0 == 0x0089
                           000089   915 _PORTB_1	=	0x0089
                           00008A   916 G$PORTB_2$0$0 == 0x008a
                           00008A   917 _PORTB_2	=	0x008a
                           00008B   918 G$PORTB_3$0$0 == 0x008b
                           00008B   919 _PORTB_3	=	0x008b
                           00008C   920 G$PORTB_4$0$0 == 0x008c
                           00008C   921 _PORTB_4	=	0x008c
                           00008D   922 G$PORTB_5$0$0 == 0x008d
                           00008D   923 _PORTB_5	=	0x008d
                           00008E   924 G$PORTB_6$0$0 == 0x008e
                           00008E   925 _PORTB_6	=	0x008e
                           00008F   926 G$PORTB_7$0$0 == 0x008f
                           00008F   927 _PORTB_7	=	0x008f
                           000090   928 G$PORTC_0$0$0 == 0x0090
                           000090   929 _PORTC_0	=	0x0090
                           000091   930 G$PORTC_1$0$0 == 0x0091
                           000091   931 _PORTC_1	=	0x0091
                           000092   932 G$PORTC_2$0$0 == 0x0092
                           000092   933 _PORTC_2	=	0x0092
                           000093   934 G$PORTC_3$0$0 == 0x0093
                           000093   935 _PORTC_3	=	0x0093
                           000094   936 G$PORTC_4$0$0 == 0x0094
                           000094   937 _PORTC_4	=	0x0094
                           000095   938 G$PORTC_5$0$0 == 0x0095
                           000095   939 _PORTC_5	=	0x0095
                           000096   940 G$PORTC_6$0$0 == 0x0096
                           000096   941 _PORTC_6	=	0x0096
                           000097   942 G$PORTC_7$0$0 == 0x0097
                           000097   943 _PORTC_7	=	0x0097
                                    944 ;--------------------------------------------------------
                                    945 ; overlayable register banks
                                    946 ;--------------------------------------------------------
                                    947 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        948 	.ds 8
                                    949 ;--------------------------------------------------------
                                    950 ; internal ram data
                                    951 ;--------------------------------------------------------
                                    952 	.area DSEG    (DATA)
                           000000   953 G$pkt_counter$0$0==.
      00001A                        954 _pkt_counter::
      00001A                        955 	.ds 2
                           000002   956 G$coldstart$0$0==.
      00001C                        957 _coldstart::
      00001C                        958 	.ds 1
                           000003   959 Lmain.main$saved_button_state$1$388==.
      00001D                        960 _main_saved_button_state_1_388:
      00001D                        961 	.ds 1
                                    962 ;--------------------------------------------------------
                                    963 ; overlayable items in internal ram 
                                    964 ;--------------------------------------------------------
                                    965 	.area	OSEG    (OVR,DATA)
                                    966 ;--------------------------------------------------------
                                    967 ; Stack segment in internal ram 
                                    968 ;--------------------------------------------------------
                                    969 	.area	SSEG
      000039                        970 __start__stack:
      000039                        971 	.ds	1
                                    972 
                                    973 ;--------------------------------------------------------
                                    974 ; indirectly addressable internal ram data
                                    975 ;--------------------------------------------------------
                                    976 	.area ISEG    (DATA)
                                    977 ;--------------------------------------------------------
                                    978 ; absolute internal ram data
                                    979 ;--------------------------------------------------------
                                    980 	.area IABS    (ABS,DATA)
                                    981 	.area IABS    (ABS,DATA)
                                    982 ;--------------------------------------------------------
                                    983 ; bit data
                                    984 ;--------------------------------------------------------
                                    985 	.area BSEG    (BIT)
                           000000   986 Lmain._sdcc_external_startup$sloc0$1$0==.
      000001                        987 __sdcc_external_startup_sloc0_1_0:
      000001                        988 	.ds 1
                                    989 ;--------------------------------------------------------
                                    990 ; paged external ram data
                                    991 ;--------------------------------------------------------
                                    992 	.area PSEG    (PAG,XDATA)
                                    993 ;--------------------------------------------------------
                                    994 ; external ram data
                                    995 ;--------------------------------------------------------
                                    996 	.area XSEG    (XDATA)
                           007020   997 G$ADCCH0VAL0$0$0 == 0x7020
                           007020   998 _ADCCH0VAL0	=	0x7020
                           007021   999 G$ADCCH0VAL1$0$0 == 0x7021
                           007021  1000 _ADCCH0VAL1	=	0x7021
                           007020  1001 G$ADCCH0VAL$0$0 == 0x7020
                           007020  1002 _ADCCH0VAL	=	0x7020
                           007022  1003 G$ADCCH1VAL0$0$0 == 0x7022
                           007022  1004 _ADCCH1VAL0	=	0x7022
                           007023  1005 G$ADCCH1VAL1$0$0 == 0x7023
                           007023  1006 _ADCCH1VAL1	=	0x7023
                           007022  1007 G$ADCCH1VAL$0$0 == 0x7022
                           007022  1008 _ADCCH1VAL	=	0x7022
                           007024  1009 G$ADCCH2VAL0$0$0 == 0x7024
                           007024  1010 _ADCCH2VAL0	=	0x7024
                           007025  1011 G$ADCCH2VAL1$0$0 == 0x7025
                           007025  1012 _ADCCH2VAL1	=	0x7025
                           007024  1013 G$ADCCH2VAL$0$0 == 0x7024
                           007024  1014 _ADCCH2VAL	=	0x7024
                           007026  1015 G$ADCCH3VAL0$0$0 == 0x7026
                           007026  1016 _ADCCH3VAL0	=	0x7026
                           007027  1017 G$ADCCH3VAL1$0$0 == 0x7027
                           007027  1018 _ADCCH3VAL1	=	0x7027
                           007026  1019 G$ADCCH3VAL$0$0 == 0x7026
                           007026  1020 _ADCCH3VAL	=	0x7026
                           007028  1021 G$ADCTUNE0$0$0 == 0x7028
                           007028  1022 _ADCTUNE0	=	0x7028
                           007029  1023 G$ADCTUNE1$0$0 == 0x7029
                           007029  1024 _ADCTUNE1	=	0x7029
                           00702A  1025 G$ADCTUNE2$0$0 == 0x702a
                           00702A  1026 _ADCTUNE2	=	0x702a
                           007010  1027 G$DMA0ADDR0$0$0 == 0x7010
                           007010  1028 _DMA0ADDR0	=	0x7010
                           007011  1029 G$DMA0ADDR1$0$0 == 0x7011
                           007011  1030 _DMA0ADDR1	=	0x7011
                           007010  1031 G$DMA0ADDR$0$0 == 0x7010
                           007010  1032 _DMA0ADDR	=	0x7010
                           007014  1033 G$DMA0CONFIG$0$0 == 0x7014
                           007014  1034 _DMA0CONFIG	=	0x7014
                           007012  1035 G$DMA1ADDR0$0$0 == 0x7012
                           007012  1036 _DMA1ADDR0	=	0x7012
                           007013  1037 G$DMA1ADDR1$0$0 == 0x7013
                           007013  1038 _DMA1ADDR1	=	0x7013
                           007012  1039 G$DMA1ADDR$0$0 == 0x7012
                           007012  1040 _DMA1ADDR	=	0x7012
                           007015  1041 G$DMA1CONFIG$0$0 == 0x7015
                           007015  1042 _DMA1CONFIG	=	0x7015
                           007070  1043 G$FRCOSCCONFIG$0$0 == 0x7070
                           007070  1044 _FRCOSCCONFIG	=	0x7070
                           007071  1045 G$FRCOSCCTRL$0$0 == 0x7071
                           007071  1046 _FRCOSCCTRL	=	0x7071
                           007076  1047 G$FRCOSCFREQ0$0$0 == 0x7076
                           007076  1048 _FRCOSCFREQ0	=	0x7076
                           007077  1049 G$FRCOSCFREQ1$0$0 == 0x7077
                           007077  1050 _FRCOSCFREQ1	=	0x7077
                           007076  1051 G$FRCOSCFREQ$0$0 == 0x7076
                           007076  1052 _FRCOSCFREQ	=	0x7076
                           007072  1053 G$FRCOSCKFILT0$0$0 == 0x7072
                           007072  1054 _FRCOSCKFILT0	=	0x7072
                           007073  1055 G$FRCOSCKFILT1$0$0 == 0x7073
                           007073  1056 _FRCOSCKFILT1	=	0x7073
                           007072  1057 G$FRCOSCKFILT$0$0 == 0x7072
                           007072  1058 _FRCOSCKFILT	=	0x7072
                           007078  1059 G$FRCOSCPER0$0$0 == 0x7078
                           007078  1060 _FRCOSCPER0	=	0x7078
                           007079  1061 G$FRCOSCPER1$0$0 == 0x7079
                           007079  1062 _FRCOSCPER1	=	0x7079
                           007078  1063 G$FRCOSCPER$0$0 == 0x7078
                           007078  1064 _FRCOSCPER	=	0x7078
                           007074  1065 G$FRCOSCREF0$0$0 == 0x7074
                           007074  1066 _FRCOSCREF0	=	0x7074
                           007075  1067 G$FRCOSCREF1$0$0 == 0x7075
                           007075  1068 _FRCOSCREF1	=	0x7075
                           007074  1069 G$FRCOSCREF$0$0 == 0x7074
                           007074  1070 _FRCOSCREF	=	0x7074
                           007007  1071 G$ANALOGA$0$0 == 0x7007
                           007007  1072 _ANALOGA	=	0x7007
                           00700C  1073 G$GPIOENABLE$0$0 == 0x700c
                           00700C  1074 _GPIOENABLE	=	0x700c
                           007003  1075 G$EXTIRQ$0$0 == 0x7003
                           007003  1076 _EXTIRQ	=	0x7003
                           007000  1077 G$INTCHGA$0$0 == 0x7000
                           007000  1078 _INTCHGA	=	0x7000
                           007001  1079 G$INTCHGB$0$0 == 0x7001
                           007001  1080 _INTCHGB	=	0x7001
                           007002  1081 G$INTCHGC$0$0 == 0x7002
                           007002  1082 _INTCHGC	=	0x7002
                           007008  1083 G$PALTA$0$0 == 0x7008
                           007008  1084 _PALTA	=	0x7008
                           007009  1085 G$PALTB$0$0 == 0x7009
                           007009  1086 _PALTB	=	0x7009
                           00700A  1087 G$PALTC$0$0 == 0x700a
                           00700A  1088 _PALTC	=	0x700a
                           007046  1089 G$PALTRADIO$0$0 == 0x7046
                           007046  1090 _PALTRADIO	=	0x7046
                           007004  1091 G$PINCHGA$0$0 == 0x7004
                           007004  1092 _PINCHGA	=	0x7004
                           007005  1093 G$PINCHGB$0$0 == 0x7005
                           007005  1094 _PINCHGB	=	0x7005
                           007006  1095 G$PINCHGC$0$0 == 0x7006
                           007006  1096 _PINCHGC	=	0x7006
                           00700B  1097 G$PINSEL$0$0 == 0x700b
                           00700B  1098 _PINSEL	=	0x700b
                           007060  1099 G$LPOSCCONFIG$0$0 == 0x7060
                           007060  1100 _LPOSCCONFIG	=	0x7060
                           007066  1101 G$LPOSCFREQ0$0$0 == 0x7066
                           007066  1102 _LPOSCFREQ0	=	0x7066
                           007067  1103 G$LPOSCFREQ1$0$0 == 0x7067
                           007067  1104 _LPOSCFREQ1	=	0x7067
                           007066  1105 G$LPOSCFREQ$0$0 == 0x7066
                           007066  1106 _LPOSCFREQ	=	0x7066
                           007062  1107 G$LPOSCKFILT0$0$0 == 0x7062
                           007062  1108 _LPOSCKFILT0	=	0x7062
                           007063  1109 G$LPOSCKFILT1$0$0 == 0x7063
                           007063  1110 _LPOSCKFILT1	=	0x7063
                           007062  1111 G$LPOSCKFILT$0$0 == 0x7062
                           007062  1112 _LPOSCKFILT	=	0x7062
                           007068  1113 G$LPOSCPER0$0$0 == 0x7068
                           007068  1114 _LPOSCPER0	=	0x7068
                           007069  1115 G$LPOSCPER1$0$0 == 0x7069
                           007069  1116 _LPOSCPER1	=	0x7069
                           007068  1117 G$LPOSCPER$0$0 == 0x7068
                           007068  1118 _LPOSCPER	=	0x7068
                           007064  1119 G$LPOSCREF0$0$0 == 0x7064
                           007064  1120 _LPOSCREF0	=	0x7064
                           007065  1121 G$LPOSCREF1$0$0 == 0x7065
                           007065  1122 _LPOSCREF1	=	0x7065
                           007064  1123 G$LPOSCREF$0$0 == 0x7064
                           007064  1124 _LPOSCREF	=	0x7064
                           007054  1125 G$LPXOSCGM$0$0 == 0x7054
                           007054  1126 _LPXOSCGM	=	0x7054
                           007F01  1127 G$MISCCTRL$0$0 == 0x7f01
                           007F01  1128 _MISCCTRL	=	0x7f01
                           007053  1129 G$OSCCALIB$0$0 == 0x7053
                           007053  1130 _OSCCALIB	=	0x7053
                           007050  1131 G$OSCFORCERUN$0$0 == 0x7050
                           007050  1132 _OSCFORCERUN	=	0x7050
                           007052  1133 G$OSCREADY$0$0 == 0x7052
                           007052  1134 _OSCREADY	=	0x7052
                           007051  1135 G$OSCRUN$0$0 == 0x7051
                           007051  1136 _OSCRUN	=	0x7051
                           007040  1137 G$RADIOFDATAADDR0$0$0 == 0x7040
                           007040  1138 _RADIOFDATAADDR0	=	0x7040
                           007041  1139 G$RADIOFDATAADDR1$0$0 == 0x7041
                           007041  1140 _RADIOFDATAADDR1	=	0x7041
                           007040  1141 G$RADIOFDATAADDR$0$0 == 0x7040
                           007040  1142 _RADIOFDATAADDR	=	0x7040
                           007042  1143 G$RADIOFSTATADDR0$0$0 == 0x7042
                           007042  1144 _RADIOFSTATADDR0	=	0x7042
                           007043  1145 G$RADIOFSTATADDR1$0$0 == 0x7043
                           007043  1146 _RADIOFSTATADDR1	=	0x7043
                           007042  1147 G$RADIOFSTATADDR$0$0 == 0x7042
                           007042  1148 _RADIOFSTATADDR	=	0x7042
                           007044  1149 G$RADIOMUX$0$0 == 0x7044
                           007044  1150 _RADIOMUX	=	0x7044
                           007084  1151 G$SCRATCH0$0$0 == 0x7084
                           007084  1152 _SCRATCH0	=	0x7084
                           007085  1153 G$SCRATCH1$0$0 == 0x7085
                           007085  1154 _SCRATCH1	=	0x7085
                           007086  1155 G$SCRATCH2$0$0 == 0x7086
                           007086  1156 _SCRATCH2	=	0x7086
                           007087  1157 G$SCRATCH3$0$0 == 0x7087
                           007087  1158 _SCRATCH3	=	0x7087
                           007F00  1159 G$SILICONREV$0$0 == 0x7f00
                           007F00  1160 _SILICONREV	=	0x7f00
                           007F19  1161 G$XTALAMPL$0$0 == 0x7f19
                           007F19  1162 _XTALAMPL	=	0x7f19
                           007F18  1163 G$XTALOSC$0$0 == 0x7f18
                           007F18  1164 _XTALOSC	=	0x7f18
                           007F1A  1165 G$XTALREADY$0$0 == 0x7f1a
                           007F1A  1166 _XTALREADY	=	0x7f1a
                           00FC06  1167 Fmain$flash_deviceid$0$0 == 0xfc06
                           00FC06  1168 _flash_deviceid	=	0xfc06
                           00FC00  1169 Fmain$flash_calsector$0$0 == 0xfc00
                           00FC00  1170 _flash_calsector	=	0xfc00
                           000000  1171 G$wakeup_desc$0$0==.
      0002AD                       1172 _wakeup_desc::
      0002AD                       1173 	.ds 8
                           000008  1174 Lmain.transmit_packet$demo_packet_$1$340==.
      0002B5                       1175 _transmit_packet_demo_packet__1_340:
      0002B5                       1176 	.ds 6
                                   1177 ;--------------------------------------------------------
                                   1178 ; absolute external ram data
                                   1179 ;--------------------------------------------------------
                                   1180 	.area XABS    (ABS,XDATA)
                                   1181 ;--------------------------------------------------------
                                   1182 ; external initialized ram data
                                   1183 ;--------------------------------------------------------
                                   1184 	.area XISEG   (XDATA)
                                   1185 	.area HOME    (CODE)
                                   1186 	.area GSINIT0 (CODE)
                                   1187 	.area GSINIT1 (CODE)
                                   1188 	.area GSINIT2 (CODE)
                                   1189 	.area GSINIT3 (CODE)
                                   1190 	.area GSINIT4 (CODE)
                                   1191 	.area GSINIT5 (CODE)
                                   1192 	.area GSINIT  (CODE)
                                   1193 	.area GSFINAL (CODE)
                                   1194 	.area CSEG    (CODE)
                                   1195 ;--------------------------------------------------------
                                   1196 ; interrupt vector 
                                   1197 ;--------------------------------------------------------
                                   1198 	.area HOME    (CODE)
      000000                       1199 __interrupt_vect:
      000000 02 03 11         [24] 1200 	ljmp	__sdcc_gsinit_startup
      000003 32               [24] 1201 	reti
      000004                       1202 	.ds	7
      00000B 02 00 B1         [24] 1203 	ljmp	_wtimer_irq
      00000E                       1204 	.ds	5
      000013 32               [24] 1205 	reti
      000014                       1206 	.ds	7
      00001B 32               [24] 1207 	reti
      00001C                       1208 	.ds	7
      000023 02 12 11         [24] 1209 	ljmp	_axradio_isr
      000026                       1210 	.ds	5
      00002B 32               [24] 1211 	reti
      00002C                       1212 	.ds	7
      000033 02 3C 6B         [24] 1213 	ljmp	_pwrmgmt_irq
      000036                       1214 	.ds	5
      00003B 32               [24] 1215 	reti
      00003C                       1216 	.ds	7
      000043 32               [24] 1217 	reti
      000044                       1218 	.ds	7
      00004B 32               [24] 1219 	reti
      00004C                       1220 	.ds	7
      000053 32               [24] 1221 	reti
      000054                       1222 	.ds	7
      00005B 02 02 A3         [24] 1223 	ljmp	_uart0_irq
      00005E                       1224 	.ds	5
      000063 02 02 DA         [24] 1225 	ljmp	_uart1_irq
      000066                       1226 	.ds	5
      00006B 32               [24] 1227 	reti
      00006C                       1228 	.ds	7
      000073 32               [24] 1229 	reti
      000074                       1230 	.ds	7
      00007B 32               [24] 1231 	reti
      00007C                       1232 	.ds	7
      000083 32               [24] 1233 	reti
      000084                       1234 	.ds	7
      00008B 32               [24] 1235 	reti
      00008C                       1236 	.ds	7
      000093 32               [24] 1237 	reti
      000094                       1238 	.ds	7
      00009B 32               [24] 1239 	reti
      00009C                       1240 	.ds	7
      0000A3 32               [24] 1241 	reti
      0000A4                       1242 	.ds	7
      0000AB 02 02 6C         [24] 1243 	ljmp	_dbglink_irq
                                   1244 ;--------------------------------------------------------
                                   1245 ; global & static initialisations
                                   1246 ;--------------------------------------------------------
                                   1247 	.area HOME    (CODE)
                                   1248 	.area GSINIT  (CODE)
                                   1249 	.area GSFINAL (CODE)
                                   1250 	.area GSINIT  (CODE)
                                   1251 	.globl __sdcc_gsinit_startup
                                   1252 	.globl __sdcc_program_startup
                                   1253 	.globl __start__stack
                                   1254 	.globl __mcs51_genXINIT
                                   1255 	.globl __mcs51_genXRAMCLEAR
                                   1256 	.globl __mcs51_genRAMCLEAR
                                   1257 ;------------------------------------------------------------
                                   1258 ;Allocation info for local variables in function 'main'
                                   1259 ;------------------------------------------------------------
                                   1260 ;saved_button_state        Allocated with name '_main_saved_button_state_1_388'
                                   1261 ;i                         Allocated to registers 
                                   1262 ;flg                       Allocated to registers r7 
                                   1263 ;flg                       Allocated to registers r7 
                                   1264 ;------------------------------------------------------------
                           000000  1265 	G$main$0$0 ==.
                           000000  1266 	C$main.c$281$1$388 ==.
                                   1267 ;	main.c:281: static uint8_t __data saved_button_state = 0xFF;
      00038A 75 1D FF         [24] 1268 	mov	_main_saved_button_state_1_388,#0xff
                           000003  1269 	C$main.c$66$1$388 ==.
                                   1270 ;	main.c:66: uint16_t __data pkt_counter = 0;
      00038D E4               [12] 1271 	clr	a
      00038E F5 1A            [12] 1272 	mov	_pkt_counter,a
      000390 F5 1B            [12] 1273 	mov	(_pkt_counter + 1),a
                           000008  1274 	C$main.c$67$1$388 ==.
                                   1275 ;	main.c:67: uint8_t __data coldstart = 1; /* caution: initialization with 1 is necessary! Variables are initialized upon _sdcc_external_startup returning 0 -> the coldstart value returned from _sdcc_external startup does not survive in the coldstart case */
      000392 75 1C 01         [24] 1276 	mov	_coldstart,#0x01
                                   1277 	.area GSFINAL (CODE)
      000395 02 00 AE         [24] 1278 	ljmp	__sdcc_program_startup
                                   1279 ;--------------------------------------------------------
                                   1280 ; Home
                                   1281 ;--------------------------------------------------------
                                   1282 	.area HOME    (CODE)
                                   1283 	.area HOME    (CODE)
      0000AE                       1284 __sdcc_program_startup:
      0000AE 02 3D A7         [24] 1285 	ljmp	_main
                                   1286 ;	return from main will return to caller
                                   1287 ;--------------------------------------------------------
                                   1288 ; code
                                   1289 ;--------------------------------------------------------
                                   1290 	.area CSEG    (CODE)
                                   1291 ;------------------------------------------------------------
                                   1292 ;Allocation info for local variables in function 'pwrmgmt_irq'
                                   1293 ;------------------------------------------------------------
                                   1294 ;pc                        Allocated to registers r7 
                                   1295 ;------------------------------------------------------------
                           000000  1296 	Fmain$pwrmgmt_irq$0$0 ==.
                           000000  1297 	C$main.c$74$0$0 ==.
                                   1298 ;	main.c:74: static void pwrmgmt_irq(void) __interrupt(INT_POWERMGMT)
                                   1299 ;	-----------------------------------------
                                   1300 ;	 function pwrmgmt_irq
                                   1301 ;	-----------------------------------------
      003C6B                       1302 _pwrmgmt_irq:
                           000007  1303 	ar7 = 0x07
                           000006  1304 	ar6 = 0x06
                           000005  1305 	ar5 = 0x05
                           000004  1306 	ar4 = 0x04
                           000003  1307 	ar3 = 0x03
                           000002  1308 	ar2 = 0x02
                           000001  1309 	ar1 = 0x01
                           000000  1310 	ar0 = 0x00
      003C6B C0 E0            [24] 1311 	push	acc
      003C6D C0 82            [24] 1312 	push	dpl
      003C6F C0 83            [24] 1313 	push	dph
      003C71 C0 07            [24] 1314 	push	ar7
      003C73 C0 D0            [24] 1315 	push	psw
      003C75 75 D0 00         [24] 1316 	mov	psw,#0x00
                           00000D  1317 	C$main.c$76$1$0 ==.
                                   1318 ;	main.c:76: uint8_t pc = PCON;
                           00000D  1319 	C$main.c$78$1$338 ==.
                                   1320 ;	main.c:78: if (!(pc & 0x80))
      003C78 E5 87            [12] 1321 	mov	a,_PCON
      003C7A FF               [12] 1322 	mov	r7,a
      003C7B 20 E7 02         [24] 1323 	jb	acc.7,00102$
                           000013  1324 	C$main.c$79$1$338 ==.
                                   1325 ;	main.c:79: return;
      003C7E 80 10            [24] 1326 	sjmp	00106$
      003C80                       1327 00102$:
                           000015  1328 	C$main.c$81$1$338 ==.
                                   1329 ;	main.c:81: GPIOENABLE = 0;
      003C80 90 70 0C         [24] 1330 	mov	dptr,#_GPIOENABLE
      003C83 E4               [12] 1331 	clr	a
      003C84 F0               [24] 1332 	movx	@dptr,a
                           00001A  1333 	C$main.c$82$1$338 ==.
                                   1334 ;	main.c:82: IE = EIE = E2IE = 0;
                                   1335 ;	1-genFromRTrack replaced	mov	_E2IE,#0x00
      003C85 F5 A0            [12] 1336 	mov	_E2IE,a
                                   1337 ;	1-genFromRTrack replaced	mov	_EIE,#0x00
      003C87 F5 98            [12] 1338 	mov	_EIE,a
                                   1339 ;	1-genFromRTrack replaced	mov	_IE,#0x00
      003C89 F5 A8            [12] 1340 	mov	_IE,a
      003C8B                       1341 00104$:
                           000020  1342 	C$main.c$85$1$338 ==.
                                   1343 ;	main.c:85: PCON |= 0x01;
      003C8B 43 87 01         [24] 1344 	orl	_PCON,#0x01
      003C8E 80 FB            [24] 1345 	sjmp	00104$
      003C90                       1346 00106$:
      003C90 D0 D0            [24] 1347 	pop	psw
      003C92 D0 07            [24] 1348 	pop	ar7
      003C94 D0 83            [24] 1349 	pop	dph
      003C96 D0 82            [24] 1350 	pop	dpl
      003C98 D0 E0            [24] 1351 	pop	acc
                           00002F  1352 	C$main.c$86$1$338 ==.
                           00002F  1353 	XFmain$pwrmgmt_irq$0$0 ==.
      003C9A 32               [24] 1354 	reti
                                   1355 ;	eliminated unneeded push/pop b
                                   1356 ;------------------------------------------------------------
                                   1357 ;Allocation info for local variables in function 'transmit_packet'
                                   1358 ;------------------------------------------------------------
                                   1359 ;demo_packet_              Allocated with name '_transmit_packet_demo_packet__1_340'
                                   1360 ;------------------------------------------------------------
                           000030  1361 	Fmain$transmit_packet$0$0 ==.
                           000030  1362 	C$main.c$88$1$338 ==.
                                   1363 ;	main.c:88: static void transmit_packet(void)
                                   1364 ;	-----------------------------------------
                                   1365 ;	 function transmit_packet
                                   1366 ;	-----------------------------------------
      003C9B                       1367 _transmit_packet:
                           000030  1368 	C$main.c$92$1$340 ==.
                                   1369 ;	main.c:92: ++pkt_counter;
      003C9B 05 1A            [12] 1370 	inc	_pkt_counter
      003C9D E4               [12] 1371 	clr	a
      003C9E B5 1A 02         [24] 1372 	cjne	a,_pkt_counter,00108$
      003CA1 05 1B            [12] 1373 	inc	(_pkt_counter + 1)
      003CA3                       1374 00108$:
                           000038  1375 	C$main.c$93$1$340 ==.
                                   1376 ;	main.c:93: memcpy(demo_packet_, demo_packet, sizeof(demo_packet));
      003CA3 75 2E B3         [24] 1377 	mov	_memcpy_PARM_2,#_demo_packet
      003CA6 75 2F 4D         [24] 1378 	mov	(_memcpy_PARM_2 + 1),#(_demo_packet >> 8)
      003CA9 75 30 80         [24] 1379 	mov	(_memcpy_PARM_2 + 2),#0x80
      003CAC 75 31 06         [24] 1380 	mov	_memcpy_PARM_3,#0x06
      003CAF 75 32 00         [24] 1381 	mov	(_memcpy_PARM_3 + 1),#0x00
      003CB2 90 02 B5         [24] 1382 	mov	dptr,#_transmit_packet_demo_packet__1_340
      003CB5 75 F0 00         [24] 1383 	mov	b,#0x00
      003CB8 12 43 06         [24] 1384 	lcall	_memcpy
                           000050  1385 	C$main.c$95$1$340 ==.
                                   1386 ;	main.c:95: if (framing_insert_counter)
      003CBB 90 4D B1         [24] 1387 	mov	dptr,#_framing_insert_counter
      003CBE E4               [12] 1388 	clr	a
      003CBF 93               [24] 1389 	movc	a,@a+dptr
      003CC0 60 24            [24] 1390 	jz	00102$
                           000057  1391 	C$main.c$97$2$341 ==.
                                   1392 ;	main.c:97: demo_packet_[framing_counter_pos] = pkt_counter & 0xFF ;
      003CC2 90 4D B2         [24] 1393 	mov	dptr,#_framing_counter_pos
      003CC5 E4               [12] 1394 	clr	a
      003CC6 93               [24] 1395 	movc	a,@a+dptr
      003CC7 FF               [12] 1396 	mov	r7,a
      003CC8 24 B5            [12] 1397 	add	a,#_transmit_packet_demo_packet__1_340
      003CCA F5 82            [12] 1398 	mov	dpl,a
      003CCC E4               [12] 1399 	clr	a
      003CCD 34 02            [12] 1400 	addc	a,#(_transmit_packet_demo_packet__1_340 >> 8)
      003CCF F5 83            [12] 1401 	mov	dph,a
      003CD1 AD 1A            [24] 1402 	mov	r5,_pkt_counter
      003CD3 7E 00            [12] 1403 	mov	r6,#0x00
      003CD5 ED               [12] 1404 	mov	a,r5
      003CD6 F0               [24] 1405 	movx	@dptr,a
                           00006C  1406 	C$main.c$98$2$341 ==.
                                   1407 ;	main.c:98: demo_packet_[framing_counter_pos+1] = (pkt_counter>>8) & 0xFF;
      003CD7 EF               [12] 1408 	mov	a,r7
      003CD8 04               [12] 1409 	inc	a
      003CD9 24 B5            [12] 1410 	add	a,#_transmit_packet_demo_packet__1_340
      003CDB F5 82            [12] 1411 	mov	dpl,a
      003CDD E4               [12] 1412 	clr	a
      003CDE 34 02            [12] 1413 	addc	a,#(_transmit_packet_demo_packet__1_340 >> 8)
      003CE0 F5 83            [12] 1414 	mov	dph,a
      003CE2 E5 1B            [12] 1415 	mov	a,(_pkt_counter + 1)
      003CE4 FF               [12] 1416 	mov	r7,a
      003CE5 F0               [24] 1417 	movx	@dptr,a
      003CE6                       1418 00102$:
                           00007B  1419 	C$main.c$101$1$340 ==.
                                   1420 ;	main.c:101: axradio_transmit(&remoteaddr, demo_packet_, sizeof(demo_packet));
      003CE6 75 15 B5         [24] 1421 	mov	_axradio_transmit_PARM_2,#_transmit_packet_demo_packet__1_340
      003CE9 75 16 02         [24] 1422 	mov	(_axradio_transmit_PARM_2 + 1),#(_transmit_packet_demo_packet__1_340 >> 8)
      003CEC 75 17 00         [24] 1423 	mov	(_axradio_transmit_PARM_2 + 2),#0x00
      003CEF 75 18 06         [24] 1424 	mov	_axradio_transmit_PARM_3,#0x06
      003CF2 75 19 00         [24] 1425 	mov	(_axradio_transmit_PARM_3 + 1),#0x00
      003CF5 90 4D A2         [24] 1426 	mov	dptr,#_remoteaddr
      003CF8 75 F0 80         [24] 1427 	mov	b,#0x80
      003CFB 12 36 16         [24] 1428 	lcall	_axradio_transmit
                           000093  1429 	C$main.c$102$1$340 ==.
                           000093  1430 	XFmain$transmit_packet$0$0 ==.
      003CFE 22               [24] 1431 	ret
                                   1432 ;------------------------------------------------------------
                                   1433 ;Allocation info for local variables in function 'display_transmit_packet'
                                   1434 ;------------------------------------------------------------
                           000094  1435 	Fmain$display_transmit_packet$0$0 ==.
                           000094  1436 	C$main.c$104$1$340 ==.
                                   1437 ;	main.c:104: static void display_transmit_packet(void)
                                   1438 ;	-----------------------------------------
                                   1439 ;	 function display_transmit_packet
                                   1440 ;	-----------------------------------------
      003CFF                       1441 _display_transmit_packet:
                           000094  1442 	C$main.c$119$1$343 ==.
                                   1443 ;	main.c:119: display_writehex16(pkt_counter, 4, WRNUM_PADZERO);
                           000094  1444 	C$main.c$129$1$343 ==.
                           000094  1445 	XFmain$display_transmit_packet$0$0 ==.
      003CFF 22               [24] 1446 	ret
                                   1447 ;------------------------------------------------------------
                                   1448 ;Allocation info for local variables in function 'axradio_statuschange'
                                   1449 ;------------------------------------------------------------
                                   1450 ;st                        Allocated to registers r6 r7 
                                   1451 ;------------------------------------------------------------
                           000095  1452 	G$axradio_statuschange$0$0 ==.
                           000095  1453 	C$main.c$131$1$343 ==.
                                   1454 ;	main.c:131: void axradio_statuschange(struct axradio_status __xdata *st)
                                   1455 ;	-----------------------------------------
                                   1456 ;	 function axradio_statuschange
                                   1457 ;	-----------------------------------------
      003D00                       1458 _axradio_statuschange:
                           000095  1459 	C$main.c$144$1$350 ==.
                                   1460 ;	main.c:144: switch (st->status)
      003D00 AE 82            [24] 1461 	mov	r6,dpl
      003D02 AF 83            [24] 1462 	mov  r7,dph
      003D04 E0               [24] 1463 	movx	a,@dptr
      003D05 FD               [12] 1464 	mov	r5,a
      003D06 BD 02 02         [24] 1465 	cjne	r5,#0x02,00190$
      003D09 80 1F            [24] 1466 	sjmp	00159$
      003D0B                       1467 00190$:
      003D0B BD 03 02         [24] 1468 	cjne	r5,#0x03,00191$
      003D0E 80 0A            [24] 1469 	sjmp	00105$
      003D10                       1470 00191$:
      003D10 BD 04 02         [24] 1471 	cjne	r5,#0x04,00192$
      003D13 80 0C            [24] 1472 	sjmp	00119$
      003D15                       1473 00192$:
                           0000AA  1474 	C$main.c$147$2$351 ==.
                                   1475 ;	main.c:147: led0_on();
      003D15 BD 05 20         [24] 1476 	cjne	r5,#0x05,00175$
      003D18 80 0B            [24] 1477 	sjmp	00158$
      003D1A                       1478 00105$:
      003D1A D2 89            [12] 1479 	setb	_PORTB_1
                           0000B1  1480 	C$main.c$159$2$351 ==.
                                   1481 ;	main.c:159: display_transmit_packet();
      003D1C 12 3C FF         [24] 1482 	lcall	_display_transmit_packet
                           0000B4  1483 	C$main.c$161$2$351 ==.
                                   1484 ;	main.c:161: break;
                           0000B4  1485 	C$main.c$164$2$351 ==.
                                   1486 ;	main.c:164: led0_off();
      003D1F 80 17            [24] 1487 	sjmp	00175$
      003D21                       1488 00119$:
      003D21 C2 89            [12] 1489 	clr	_PORTB_1
                           0000B8  1490 	C$main.c$203$2$351 ==.
                                   1491 ;	main.c:203: break;
                           0000B8  1492 	C$main.c$206$2$351 ==.
                                   1493 ;	main.c:206: case AXRADIO_STAT_TRANSMITDATA:
      003D23 80 13            [24] 1494 	sjmp	00175$
      003D25                       1495 00158$:
                           0000BA  1496 	C$main.c$209$2$351 ==.
                                   1497 ;	main.c:209: transmit_packet();
      003D25 12 3C 9B         [24] 1498 	lcall	_transmit_packet
                           0000BD  1499 	C$main.c$210$2$351 ==.
                                   1500 ;	main.c:210: break;
                           0000BD  1501 	C$main.c$213$2$351 ==.
                                   1502 ;	main.c:213: case AXRADIO_STAT_CHANNELSTATE:
      003D28 80 0E            [24] 1503 	sjmp	00175$
      003D2A                       1504 00159$:
                           0000BF  1505 	C$main.c$214$2$351 ==.
                                   1506 ;	main.c:214: if (st->u.cs.busy)
      003D2A 74 06            [12] 1507 	mov	a,#0x06
      003D2C 2E               [12] 1508 	add	a,r6
      003D2D FE               [12] 1509 	mov	r6,a
      003D2E E4               [12] 1510 	clr	a
      003D2F 3F               [12] 1511 	addc	a,r7
      003D30 FF               [12] 1512 	mov	r7,a
      003D31 8E 82            [24] 1513 	mov	dpl,r6
      003D33 8F 83            [24] 1514 	mov	dph,r7
      003D35 A3               [24] 1515 	inc	dptr
      003D36 A3               [24] 1516 	inc	dptr
      003D37 E0               [24] 1517 	movx	a,@dptr
                           0000CD  1518 	C$main.c$223$1$350 ==.
                                   1519 ;	main.c:223: }
      003D38                       1520 00175$:
                           0000CD  1521 	C$main.c$224$1$350 ==.
                           0000CD  1522 	XG$axradio_statuschange$0$0 ==.
      003D38 22               [24] 1523 	ret
                                   1524 ;------------------------------------------------------------
                                   1525 ;Allocation info for local variables in function 'enable_radio_interrupt_in_mcu_pin'
                                   1526 ;------------------------------------------------------------
                           0000CE  1527 	G$enable_radio_interrupt_in_mcu_pin$0$0 ==.
                           0000CE  1528 	C$main.c$226$1$350 ==.
                                   1529 ;	main.c:226: void enable_radio_interrupt_in_mcu_pin(void)
                                   1530 ;	-----------------------------------------
                                   1531 ;	 function enable_radio_interrupt_in_mcu_pin
                                   1532 ;	-----------------------------------------
      003D39                       1533 _enable_radio_interrupt_in_mcu_pin:
                           0000CE  1534 	C$main.c$228$1$377 ==.
                                   1535 ;	main.c:228: IE_4 = 1;
      003D39 D2 AC            [12] 1536 	setb	_IE_4
                           0000D0  1537 	C$main.c$229$1$377 ==.
                           0000D0  1538 	XG$enable_radio_interrupt_in_mcu_pin$0$0 ==.
      003D3B 22               [24] 1539 	ret
                                   1540 ;------------------------------------------------------------
                                   1541 ;Allocation info for local variables in function 'disable_radio_interrupt_in_mcu_pin'
                                   1542 ;------------------------------------------------------------
                           0000D1  1543 	G$disable_radio_interrupt_in_mcu_pin$0$0 ==.
                           0000D1  1544 	C$main.c$231$1$377 ==.
                                   1545 ;	main.c:231: void disable_radio_interrupt_in_mcu_pin(void)
                                   1546 ;	-----------------------------------------
                                   1547 ;	 function disable_radio_interrupt_in_mcu_pin
                                   1548 ;	-----------------------------------------
      003D3C                       1549 _disable_radio_interrupt_in_mcu_pin:
                           0000D1  1550 	C$main.c$233$1$379 ==.
                                   1551 ;	main.c:233: IE_4 = 0;
      003D3C C2 AC            [12] 1552 	clr	_IE_4
                           0000D3  1553 	C$main.c$234$1$379 ==.
                           0000D3  1554 	XG$disable_radio_interrupt_in_mcu_pin$0$0 ==.
      003D3E 22               [24] 1555 	ret
                                   1556 ;------------------------------------------------------------
                                   1557 ;Allocation info for local variables in function 'wakeup_callback'
                                   1558 ;------------------------------------------------------------
                                   1559 ;desc                      Allocated to registers 
                                   1560 ;------------------------------------------------------------
                           0000D4  1561 	Fmain$wakeup_callback$0$0 ==.
                           0000D4  1562 	C$main.c$236$1$379 ==.
                                   1563 ;	main.c:236: static void wakeup_callback(struct wtimer_desc __xdata *desc)
                                   1564 ;	-----------------------------------------
                                   1565 ;	 function wakeup_callback
                                   1566 ;	-----------------------------------------
      003D3F                       1567 _wakeup_callback:
                           0000D4  1568 	C$main.c$238$1$381 ==.
                                   1569 ;	main.c:238: desc;
                           0000D4  1570 	C$main.c$245$1$381 ==.
                           0000D4  1571 	XFmain$wakeup_callback$0$0 ==.
      003D3F 22               [24] 1572 	ret
                                   1573 ;------------------------------------------------------------
                                   1574 ;Allocation info for local variables in function '_sdcc_external_startup'
                                   1575 ;------------------------------------------------------------
                                   1576 ;c                         Allocated to registers 
                                   1577 ;p                         Allocated to registers 
                                   1578 ;c                         Allocated to registers 
                                   1579 ;p                         Allocated to registers 
                                   1580 ;------------------------------------------------------------
                           0000D5  1581 	G$_sdcc_external_startup$0$0 ==.
                           0000D5  1582 	C$main.c$247$1$381 ==.
                                   1583 ;	main.c:247: uint8_t _sdcc_external_startup(void)
                                   1584 ;	-----------------------------------------
                                   1585 ;	 function _sdcc_external_startup
                                   1586 ;	-----------------------------------------
      003D40                       1587 __sdcc_external_startup:
                           0000D5  1588 	C$main.c$249$1$383 ==.
                                   1589 ;	main.c:249: LPXOSCGM = 0x8A;
      003D40 90 70 54         [24] 1590 	mov	dptr,#_LPXOSCGM
      003D43 74 8A            [12] 1591 	mov	a,#0x8a
      003D45 F0               [24] 1592 	movx	@dptr,a
                           0000DB  1593 	C$main.c$250$2$384 ==.
                                   1594 ;	main.c:250: wtimer0_setclksrc(WTIMER0_CLKSRC, WTIMER0_PRESCALER);
      003D46 75 82 0B         [24] 1595 	mov	dpl,#0x0b
      003D49 12 3F E5         [24] 1596 	lcall	_wtimer0_setconfig
                           0000E1  1597 	C$main.c$251$2$385 ==.
                                   1598 ;	main.c:251: wtimer1_setclksrc(CLKSRC_FRCOSC, 7);
      003D4C 75 82 38         [24] 1599 	mov	dpl,#0x38
      003D4F 12 3F FF         [24] 1600 	lcall	_wtimer1_setconfig
                           0000E7  1601 	C$main.c$253$1$383 ==.
                                   1602 ;	main.c:253: LPOSCCONFIG = 0x09; /* Slow, PRESC /1, no cal. Does NOT enable LPOSC. LPOSC is enabled upon configuring WTCFGA (MODE_TX_PERIODIC and receive_ack() ) */
      003D52 90 70 60         [24] 1603 	mov	dptr,#_LPOSCCONFIG
      003D55 74 09            [12] 1604 	mov	a,#0x09
      003D57 F0               [24] 1605 	movx	@dptr,a
                           0000ED  1606 	C$main.c$255$1$383 ==.
                                   1607 ;	main.c:255: coldstart = !(PCON & 0x40);
      003D58 E5 87            [12] 1608 	mov	a,_PCON
      003D5A A2 E6            [12] 1609 	mov	c,acc[6]
      003D5C B3               [12] 1610 	cpl	c
      003D5D 92 01            [24] 1611 	mov	__sdcc_external_startup_sloc0_1_0,c
      003D5F E4               [12] 1612 	clr	a
      003D60 33               [12] 1613 	rlc	a
      003D61 F5 1C            [12] 1614 	mov	_coldstart,a
                           0000F8  1615 	C$main.c$257$1$383 ==.
                                   1616 ;	main.c:257: ANALOGA = 0x18; /* PA[3,4] LPXOSC, other PA are used as digital pins */
      003D63 90 70 07         [24] 1617 	mov	dptr,#_ANALOGA
      003D66 74 18            [12] 1618 	mov	a,#0x18
      003D68 F0               [24] 1619 	movx	@dptr,a
                           0000FE  1620 	C$main.c$258$1$383 ==.
                                   1621 ;	main.c:258: PORTA = 0xE7; /* pull ups except for LPXOSC pin PA[3,4]; */
      003D69 75 80 E7         [24] 1622 	mov	_PORTA,#0xe7
                           000101  1623 	C$main.c$259$1$383 ==.
                                   1624 ;	main.c:259: PORTB = 0xFD | (PINB & 0x02); /* init LEDs to previous (frozen) state */
      003D6C 74 02            [12] 1625 	mov	a,#0x02
      003D6E 55 E8            [12] 1626 	anl	a,_PINB
      003D70 44 FD            [12] 1627 	orl	a,#0xfd
      003D72 F5 88            [12] 1628 	mov	_PORTB,a
                           000109  1629 	C$main.c$260$1$383 ==.
                                   1630 ;	main.c:260: PORTC = 0xFF;
      003D74 75 90 FF         [24] 1631 	mov	_PORTC,#0xff
                           00010C  1632 	C$main.c$261$1$383 ==.
                                   1633 ;	main.c:261: PORTR = 0x0B;
      003D77 75 8C 0B         [24] 1634 	mov	_PORTR,#0x0b
                           00010F  1635 	C$main.c$263$1$383 ==.
                                   1636 ;	main.c:263: DIRA = 0x00;
      003D7A 75 89 00         [24] 1637 	mov	_DIRA,#0x00
                           000112  1638 	C$main.c$264$1$383 ==.
                                   1639 ;	main.c:264: DIRB = 0x0e; /*  PB1 = LED; PB2 / PB3 are outputs (in case PWRAMP / ANSTSEL are used) */
      003D7D 75 8A 0E         [24] 1640 	mov	_DIRB,#0x0e
                           000115  1641 	C$main.c$265$1$383 ==.
                                   1642 ;	main.c:265: DIRC = 0x00; /*  PC4 = button */
      003D80 75 8B 00         [24] 1643 	mov	_DIRC,#0x00
                           000118  1644 	C$main.c$266$1$383 ==.
                                   1645 ;	main.c:266: DIRR = 0x15;
      003D83 75 8E 15         [24] 1646 	mov	_DIRR,#0x15
                           00011B  1647 	C$main.c$267$1$383 ==.
                                   1648 ;	main.c:267: axradio_setup_pincfg1();
      003D86 12 06 D3         [24] 1649 	lcall	_axradio_setup_pincfg1
                           00011E  1650 	C$main.c$268$1$383 ==.
                                   1651 ;	main.c:268: DPS = 0;
      003D89 75 86 00         [24] 1652 	mov	_DPS,#0x00
                           000121  1653 	C$main.c$269$1$383 ==.
                                   1654 ;	main.c:269: IE = 0x40;
      003D8C 75 A8 40         [24] 1655 	mov	_IE,#0x40
                           000124  1656 	C$main.c$270$1$383 ==.
                                   1657 ;	main.c:270: EIE = 0x00;
      003D8F 75 98 00         [24] 1658 	mov	_EIE,#0x00
                           000127  1659 	C$main.c$271$1$383 ==.
                                   1660 ;	main.c:271: E2IE = 0x00;
      003D92 75 A0 00         [24] 1661 	mov	_E2IE,#0x00
                           00012A  1662 	C$main.c$274$1$383 ==.
                                   1663 ;	main.c:274: GPIOENABLE = 1; /* unfreeze GPIO */
      003D95 90 70 0C         [24] 1664 	mov	dptr,#_GPIOENABLE
      003D98 74 01            [12] 1665 	mov	a,#0x01
      003D9A F0               [24] 1666 	movx	@dptr,a
                           000130  1667 	C$main.c$275$1$383 ==.
                                   1668 ;	main.c:275: return !coldstart; /* coldstart -> return 0 -> var initialization; start from sleep -> return 1 -> no var initialization */
      003D9B E5 1C            [12] 1669 	mov	a,_coldstart
      003D9D B4 01 00         [24] 1670 	cjne	a,#0x01,00111$
      003DA0                       1671 00111$:
      003DA0 92 01            [24] 1672 	mov  __sdcc_external_startup_sloc0_1_0,c
      003DA2 E4               [12] 1673 	clr	a
      003DA3 33               [12] 1674 	rlc	a
      003DA4 F5 82            [12] 1675 	mov	dpl,a
                           00013B  1676 	C$main.c$276$1$383 ==.
                           00013B  1677 	XG$_sdcc_external_startup$0$0 ==.
      003DA6 22               [24] 1678 	ret
                                   1679 ;------------------------------------------------------------
                                   1680 ;Allocation info for local variables in function 'main'
                                   1681 ;------------------------------------------------------------
                                   1682 ;saved_button_state        Allocated with name '_main_saved_button_state_1_388'
                                   1683 ;i                         Allocated to registers 
                                   1684 ;flg                       Allocated to registers r7 
                                   1685 ;flg                       Allocated to registers r7 
                                   1686 ;------------------------------------------------------------
                           00013C  1687 	G$main$0$0 ==.
                           00013C  1688 	C$main.c$278$1$383 ==.
                                   1689 ;	main.c:278: int main(void)
                                   1690 ;	-----------------------------------------
                                   1691 ;	 function main
                                   1692 ;	-----------------------------------------
      003DA7                       1693 _main:
                           00013C  1694 	C$main.c$285$1$388 ==.
                                   1695 ;	main.c:285: __endasm;
                           000000  1696 	G$_start__stack$0$0	= __start__stack
                                   1697 	.globl	G$_start__stack$0$0
                           00013C  1698 	C$libmftypes.h$368$4$415 ==.
                                   1699 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:368: EA = 1;
      003DA7 D2 AF            [12] 1700 	setb	_EA
                           00013E  1701 	C$main.c$290$1$388 ==.
                                   1702 ;	main.c:290: flash_apply_calibration();
      003DA9 12 45 B5         [24] 1703 	lcall	_flash_apply_calibration
                           000141  1704 	C$main.c$291$1$388 ==.
                                   1705 ;	main.c:291: CLKCON = 0x00;
      003DAC 75 C6 00         [24] 1706 	mov	_CLKCON,#0x00
                           000144  1707 	C$main.c$292$1$388 ==.
                                   1708 ;	main.c:292: wtimer_init();
      003DAF 12 40 AE         [24] 1709 	lcall	_wtimer_init
                           000147  1710 	C$main.c$294$1$388 ==.
                                   1711 ;	main.c:294: if (coldstart)
      003DB2 E5 1C            [12] 1712 	mov	a,_coldstart
      003DB4 60 42            [24] 1713 	jz	00143$
                           00014B  1714 	C$main.c$296$4$391 ==.
                                   1715 ;	main.c:296: led0_off();
      003DB6 C2 89            [12] 1716 	clr	_PORTB_1
                           00014D  1717 	C$main.c$301$2$389 ==.
                                   1718 ;	main.c:301: wakeup_desc.handler = wakeup_callback;
      003DB8 90 02 AF         [24] 1719 	mov	dptr,#(_wakeup_desc + 0x0002)
      003DBB 74 3F            [12] 1720 	mov	a,#_wakeup_callback
      003DBD F0               [24] 1721 	movx	@dptr,a
      003DBE 74 3D            [12] 1722 	mov	a,#(_wakeup_callback >> 8)
      003DC0 A3               [24] 1723 	inc	dptr
      003DC1 F0               [24] 1724 	movx	@dptr,a
                           000157  1725 	C$main.c$307$2$389 ==.
                                   1726 ;	main.c:307: i = axradio_init();
      003DC2 12 2A E7         [24] 1727 	lcall	_axradio_init
      003DC5 E5 82            [12] 1728 	mov	a,dpl
                           00015C  1729 	C$main.c$309$2$389 ==.
                                   1730 ;	main.c:309: if (i != AXRADIO_ERR_NOERROR)
      003DC7 70 56            [24] 1731 	jnz	00162$
                           00015E  1732 	C$main.c$333$2$389 ==.
                                   1733 ;	main.c:333: axradio_set_local_address(&localaddr);
      003DC9 90 4D A7         [24] 1734 	mov	dptr,#_localaddr
      003DCC 75 F0 80         [24] 1735 	mov	b,#0x80
      003DCF 12 35 9D         [24] 1736 	lcall	_axradio_set_local_address
                           000167  1737 	C$main.c$334$2$389 ==.
                                   1738 ;	main.c:334: axradio_set_default_remote_address(&remoteaddr);
      003DD2 90 4D A2         [24] 1739 	mov	dptr,#_remoteaddr
      003DD5 75 F0 80         [24] 1740 	mov	b,#0x80
      003DD8 12 35 DB         [24] 1741 	lcall	_axradio_set_default_remote_address
                           000170  1742 	C$main.c$343$2$389 ==.
                                   1743 ;	main.c:343: delay_ms(lpxosc_settlingtime);
      003DDB 90 4D B9         [24] 1744 	mov	dptr,#_lpxosc_settlingtime
      003DDE E4               [12] 1745 	clr	a
      003DDF 93               [24] 1746 	movc	a,@a+dptr
      003DE0 FE               [12] 1747 	mov	r6,a
      003DE1 74 01            [12] 1748 	mov	a,#0x01
      003DE3 93               [24] 1749 	movc	a,@a+dptr
      003DE4 FF               [12] 1750 	mov	r7,a
      003DE5 8E 82            [24] 1751 	mov	dpl,r6
      003DE7 8F 83            [24] 1752 	mov	dph,r7
      003DE9 12 3B 06         [24] 1753 	lcall	_delay_ms
                           000181  1754 	C$main.c$384$2$389 ==.
                                   1755 ;	main.c:384: i = axradio_set_mode(RADIO_MODE);
      003DEC 75 82 31         [24] 1756 	mov	dpl,#0x31
      003DEF 12 2E EB         [24] 1757 	lcall	_axradio_set_mode
      003DF2 E5 82            [12] 1758 	mov	a,dpl
                           000189  1759 	C$main.c$386$2$389 ==.
                                   1760 ;	main.c:386: if (i != AXRADIO_ERR_NOERROR)
      003DF4 60 07            [24] 1761 	jz	00144$
                           00018B  1762 	C$main.c$387$2$389 ==.
                                   1763 ;	main.c:387: goto terminate_radio_error;
      003DF6 80 27            [24] 1764 	sjmp	00162$
      003DF8                       1765 00143$:
                           00018D  1766 	C$main.c$397$2$407 ==.
                                   1767 ;	main.c:397: axradio_commsleepexit();
      003DF8 12 3A 9E         [24] 1768 	lcall	_axradio_commsleepexit
                           000190  1769 	C$main.c$398$2$407 ==.
                                   1770 ;	main.c:398: IE_4 = 1; /* enable radio interrupt */
      003DFB D2 AC            [12] 1771 	setb	_IE_4
      003DFD                       1772 00144$:
                           000192  1773 	C$main.c$401$1$388 ==.
                                   1774 ;	main.c:401: axradio_setup_pincfg2();
      003DFD 12 06 D9         [24] 1775 	lcall	_axradio_setup_pincfg2
      003E00                       1776 00160$:
                           000195  1777 	C$main.c$408$2$408 ==.
                                   1778 ;	main.c:408: wtimer_runcallbacks();
      003E00 12 42 66         [24] 1779 	lcall	_wtimer_runcallbacks
                           000198  1780 	C$libmftypes.h$373$5$418 ==.
                                   1781 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:373: EA = 0;
      003E03 C2 AF            [12] 1782 	clr	_EA
                           00019A  1783 	C$main.c$437$3$408 ==.
                                   1784 ;	main.c:437: uint8_t flg = WTFLAG_CANSTANDBY;
      003E05 7F 02            [12] 1785 	mov	r7,#0x02
                           00019C  1786 	C$main.c$440$3$409 ==.
                                   1787 ;	main.c:440: if (axradio_cansleep()
      003E07 C0 07            [24] 1788 	push	ar7
      003E09 12 2E D9         [24] 1789 	lcall	_axradio_cansleep
      003E0C E5 82            [12] 1790 	mov	a,dpl
      003E0E D0 07            [24] 1791 	pop	ar7
      003E10 60 02            [24] 1792 	jz	00146$
                           0001A7  1793 	C$main.c$445$3$409 ==.
                                   1794 ;	main.c:445: flg |= WTFLAG_CANSLEEP;
      003E12 7F 03            [12] 1795 	mov	r7,#0x03
      003E14                       1796 00146$:
                           0001A9  1797 	C$main.c$447$3$409 ==.
                                   1798 ;	main.c:447: wtimer_idle(flg);
      003E14 8F 82            [24] 1799 	mov	dpl,r7
      003E16 12 41 E2         [24] 1800 	lcall	_wtimer_idle
                           0001AE  1801 	C$main.c$449$2$408 ==.
                                   1802 ;	main.c:449: IE_3 = 0; /* no ISR! */
      003E19 C2 AB            [12] 1803 	clr	_IE_3
                           0001B0  1804 	C$libmftypes.h$368$5$421 ==.
                                   1805 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:368: EA = 1;
      003E1B D2 AF            [12] 1806 	setb	_EA
                           0001B2  1807 	C$main.c$450$4$420 ==.
                                   1808 ;	main.c:450: __enable_irq();
                           0001B2  1809 	C$main.c$458$1$388 ==.
                                   1810 ;	main.c:458: terminate_error:
      003E1D 80 E1            [24] 1811 	sjmp	00160$
      003E1F                       1812 00162$:
                           0001B4  1813 	C$main.c$462$2$411 ==.
                                   1814 ;	main.c:462: wtimer_runcallbacks();
      003E1F 12 42 66         [24] 1815 	lcall	_wtimer_runcallbacks
                           0001B7  1816 	C$main.c$464$3$411 ==.
                                   1817 ;	main.c:464: uint8_t flg = WTFLAG_CANSTANDBY;
      003E22 7F 02            [12] 1818 	mov	r7,#0x02
                           0001B9  1819 	C$main.c$467$3$412 ==.
                                   1820 ;	main.c:467: if (axradio_cansleep()
      003E24 C0 07            [24] 1821 	push	ar7
      003E26 12 2E D9         [24] 1822 	lcall	_axradio_cansleep
      003E29 E5 82            [12] 1823 	mov	a,dpl
      003E2B D0 07            [24] 1824 	pop	ar7
      003E2D 60 02            [24] 1825 	jz	00154$
                           0001C4  1826 	C$main.c$472$3$412 ==.
                                   1827 ;	main.c:472: flg |= WTFLAG_CANSLEEP;
      003E2F 7F 03            [12] 1828 	mov	r7,#0x03
      003E31                       1829 00154$:
                           0001C6  1830 	C$main.c$474$3$412 ==.
                                   1831 ;	main.c:474: wtimer_idle(flg);
      003E31 8F 82            [24] 1832 	mov	dpl,r7
      003E33 12 41 E2         [24] 1833 	lcall	_wtimer_idle
      003E36 80 E7            [24] 1834 	sjmp	00162$
                           0001CD  1835 	C$main.c$477$1$388 ==.
                           0001CD  1836 	XG$main$0$0 ==.
      003E38 22               [24] 1837 	ret
                                   1838 	.area CSEG    (CODE)
                                   1839 	.area CONST   (CODE)
                                   1840 	.area XINIT   (CODE)
                                   1841 	.area CABS    (ABS,CODE)
