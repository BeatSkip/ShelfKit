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
                                     14 	.globl _wtimer_runcallbacks
                                     15 	.globl _wtimer_idle
                                     16 	.globl _wtimer_init
                                     17 	.globl _wtimer1_setconfig
                                     18 	.globl _wtimer0_setconfig
                                     19 	.globl _flash_apply_calibration
                                     20 	.globl _axradio_commsleepexit
                                     21 	.globl _axradio_setup_pincfg2
                                     22 	.globl _axradio_setup_pincfg1
                                     23 	.globl _axradio_get_freqoffset
                                     24 	.globl _axradio_set_freqoffset
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
                                    301 	.globl _XTALREADY
                                    302 	.globl _XTALOSC
                                    303 	.globl _XTALAMPL
                                    304 	.globl _SILICONREV
                                    305 	.globl _SCRATCH3
                                    306 	.globl _SCRATCH2
                                    307 	.globl _SCRATCH1
                                    308 	.globl _SCRATCH0
                                    309 	.globl _RADIOMUX
                                    310 	.globl _RADIOFSTATADDR
                                    311 	.globl _RADIOFSTATADDR1
                                    312 	.globl _RADIOFSTATADDR0
                                    313 	.globl _RADIOFDATAADDR
                                    314 	.globl _RADIOFDATAADDR1
                                    315 	.globl _RADIOFDATAADDR0
                                    316 	.globl _OSCRUN
                                    317 	.globl _OSCREADY
                                    318 	.globl _OSCFORCERUN
                                    319 	.globl _OSCCALIB
                                    320 	.globl _MISCCTRL
                                    321 	.globl _LPXOSCGM
                                    322 	.globl _LPOSCREF
                                    323 	.globl _LPOSCREF1
                                    324 	.globl _LPOSCREF0
                                    325 	.globl _LPOSCPER
                                    326 	.globl _LPOSCPER1
                                    327 	.globl _LPOSCPER0
                                    328 	.globl _LPOSCKFILT
                                    329 	.globl _LPOSCKFILT1
                                    330 	.globl _LPOSCKFILT0
                                    331 	.globl _LPOSCFREQ
                                    332 	.globl _LPOSCFREQ1
                                    333 	.globl _LPOSCFREQ0
                                    334 	.globl _LPOSCCONFIG
                                    335 	.globl _PINSEL
                                    336 	.globl _PINCHGC
                                    337 	.globl _PINCHGB
                                    338 	.globl _PINCHGA
                                    339 	.globl _PALTRADIO
                                    340 	.globl _PALTC
                                    341 	.globl _PALTB
                                    342 	.globl _PALTA
                                    343 	.globl _INTCHGC
                                    344 	.globl _INTCHGB
                                    345 	.globl _INTCHGA
                                    346 	.globl _EXTIRQ
                                    347 	.globl _GPIOENABLE
                                    348 	.globl _ANALOGA
                                    349 	.globl _FRCOSCREF
                                    350 	.globl _FRCOSCREF1
                                    351 	.globl _FRCOSCREF0
                                    352 	.globl _FRCOSCPER
                                    353 	.globl _FRCOSCPER1
                                    354 	.globl _FRCOSCPER0
                                    355 	.globl _FRCOSCKFILT
                                    356 	.globl _FRCOSCKFILT1
                                    357 	.globl _FRCOSCKFILT0
                                    358 	.globl _FRCOSCFREQ
                                    359 	.globl _FRCOSCFREQ1
                                    360 	.globl _FRCOSCFREQ0
                                    361 	.globl _FRCOSCCTRL
                                    362 	.globl _FRCOSCCONFIG
                                    363 	.globl _DMA1CONFIG
                                    364 	.globl _DMA1ADDR
                                    365 	.globl _DMA1ADDR1
                                    366 	.globl _DMA1ADDR0
                                    367 	.globl _DMA0CONFIG
                                    368 	.globl _DMA0ADDR
                                    369 	.globl _DMA0ADDR1
                                    370 	.globl _DMA0ADDR0
                                    371 	.globl _ADCTUNE2
                                    372 	.globl _ADCTUNE1
                                    373 	.globl _ADCTUNE0
                                    374 	.globl _ADCCH3VAL
                                    375 	.globl _ADCCH3VAL1
                                    376 	.globl _ADCCH3VAL0
                                    377 	.globl _ADCCH2VAL
                                    378 	.globl _ADCCH2VAL1
                                    379 	.globl _ADCCH2VAL0
                                    380 	.globl _ADCCH1VAL
                                    381 	.globl _ADCCH1VAL1
                                    382 	.globl _ADCCH1VAL0
                                    383 	.globl _ADCCH0VAL
                                    384 	.globl _ADCCH0VAL1
                                    385 	.globl _ADCCH0VAL0
                                    386 	.globl _pkts_missing
                                    387 	.globl _pkts_received
                                    388 	.globl _coldstart
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
                           000000   953 G$coldstart$0$0==.
      000022                        954 _coldstart::
      000022                        955 	.ds 1
                           000001   956 G$pkts_received$0$0==.
      000023                        957 _pkts_received::
      000023                        958 	.ds 2
                           000003   959 G$pkts_missing$0$0==.
      000025                        960 _pkts_missing::
      000025                        961 	.ds 2
                                    962 ;--------------------------------------------------------
                                    963 ; overlayable items in internal ram 
                                    964 ;--------------------------------------------------------
                                    965 ;--------------------------------------------------------
                                    966 ; Stack segment in internal ram 
                                    967 ;--------------------------------------------------------
                                    968 	.area	SSEG
      00003E                        969 __start__stack:
      00003E                        970 	.ds	1
                                    971 
                                    972 ;--------------------------------------------------------
                                    973 ; indirectly addressable internal ram data
                                    974 ;--------------------------------------------------------
                                    975 	.area ISEG    (DATA)
                                    976 ;--------------------------------------------------------
                                    977 ; absolute internal ram data
                                    978 ;--------------------------------------------------------
                                    979 	.area IABS    (ABS,DATA)
                                    980 	.area IABS    (ABS,DATA)
                                    981 ;--------------------------------------------------------
                                    982 ; bit data
                                    983 ;--------------------------------------------------------
                                    984 	.area BSEG    (BIT)
                           000000   985 Lmain._sdcc_external_startup$sloc0$1$0==.
      000002                        986 __sdcc_external_startup_sloc0_1_0:
      000002                        987 	.ds 1
                                    988 ;--------------------------------------------------------
                                    989 ; paged external ram data
                                    990 ;--------------------------------------------------------
                                    991 	.area PSEG    (PAG,XDATA)
                                    992 ;--------------------------------------------------------
                                    993 ; external ram data
                                    994 ;--------------------------------------------------------
                                    995 	.area XSEG    (XDATA)
                           007020   996 G$ADCCH0VAL0$0$0 == 0x7020
                           007020   997 _ADCCH0VAL0	=	0x7020
                           007021   998 G$ADCCH0VAL1$0$0 == 0x7021
                           007021   999 _ADCCH0VAL1	=	0x7021
                           007020  1000 G$ADCCH0VAL$0$0 == 0x7020
                           007020  1001 _ADCCH0VAL	=	0x7020
                           007022  1002 G$ADCCH1VAL0$0$0 == 0x7022
                           007022  1003 _ADCCH1VAL0	=	0x7022
                           007023  1004 G$ADCCH1VAL1$0$0 == 0x7023
                           007023  1005 _ADCCH1VAL1	=	0x7023
                           007022  1006 G$ADCCH1VAL$0$0 == 0x7022
                           007022  1007 _ADCCH1VAL	=	0x7022
                           007024  1008 G$ADCCH2VAL0$0$0 == 0x7024
                           007024  1009 _ADCCH2VAL0	=	0x7024
                           007025  1010 G$ADCCH2VAL1$0$0 == 0x7025
                           007025  1011 _ADCCH2VAL1	=	0x7025
                           007024  1012 G$ADCCH2VAL$0$0 == 0x7024
                           007024  1013 _ADCCH2VAL	=	0x7024
                           007026  1014 G$ADCCH3VAL0$0$0 == 0x7026
                           007026  1015 _ADCCH3VAL0	=	0x7026
                           007027  1016 G$ADCCH3VAL1$0$0 == 0x7027
                           007027  1017 _ADCCH3VAL1	=	0x7027
                           007026  1018 G$ADCCH3VAL$0$0 == 0x7026
                           007026  1019 _ADCCH3VAL	=	0x7026
                           007028  1020 G$ADCTUNE0$0$0 == 0x7028
                           007028  1021 _ADCTUNE0	=	0x7028
                           007029  1022 G$ADCTUNE1$0$0 == 0x7029
                           007029  1023 _ADCTUNE1	=	0x7029
                           00702A  1024 G$ADCTUNE2$0$0 == 0x702a
                           00702A  1025 _ADCTUNE2	=	0x702a
                           007010  1026 G$DMA0ADDR0$0$0 == 0x7010
                           007010  1027 _DMA0ADDR0	=	0x7010
                           007011  1028 G$DMA0ADDR1$0$0 == 0x7011
                           007011  1029 _DMA0ADDR1	=	0x7011
                           007010  1030 G$DMA0ADDR$0$0 == 0x7010
                           007010  1031 _DMA0ADDR	=	0x7010
                           007014  1032 G$DMA0CONFIG$0$0 == 0x7014
                           007014  1033 _DMA0CONFIG	=	0x7014
                           007012  1034 G$DMA1ADDR0$0$0 == 0x7012
                           007012  1035 _DMA1ADDR0	=	0x7012
                           007013  1036 G$DMA1ADDR1$0$0 == 0x7013
                           007013  1037 _DMA1ADDR1	=	0x7013
                           007012  1038 G$DMA1ADDR$0$0 == 0x7012
                           007012  1039 _DMA1ADDR	=	0x7012
                           007015  1040 G$DMA1CONFIG$0$0 == 0x7015
                           007015  1041 _DMA1CONFIG	=	0x7015
                           007070  1042 G$FRCOSCCONFIG$0$0 == 0x7070
                           007070  1043 _FRCOSCCONFIG	=	0x7070
                           007071  1044 G$FRCOSCCTRL$0$0 == 0x7071
                           007071  1045 _FRCOSCCTRL	=	0x7071
                           007076  1046 G$FRCOSCFREQ0$0$0 == 0x7076
                           007076  1047 _FRCOSCFREQ0	=	0x7076
                           007077  1048 G$FRCOSCFREQ1$0$0 == 0x7077
                           007077  1049 _FRCOSCFREQ1	=	0x7077
                           007076  1050 G$FRCOSCFREQ$0$0 == 0x7076
                           007076  1051 _FRCOSCFREQ	=	0x7076
                           007072  1052 G$FRCOSCKFILT0$0$0 == 0x7072
                           007072  1053 _FRCOSCKFILT0	=	0x7072
                           007073  1054 G$FRCOSCKFILT1$0$0 == 0x7073
                           007073  1055 _FRCOSCKFILT1	=	0x7073
                           007072  1056 G$FRCOSCKFILT$0$0 == 0x7072
                           007072  1057 _FRCOSCKFILT	=	0x7072
                           007078  1058 G$FRCOSCPER0$0$0 == 0x7078
                           007078  1059 _FRCOSCPER0	=	0x7078
                           007079  1060 G$FRCOSCPER1$0$0 == 0x7079
                           007079  1061 _FRCOSCPER1	=	0x7079
                           007078  1062 G$FRCOSCPER$0$0 == 0x7078
                           007078  1063 _FRCOSCPER	=	0x7078
                           007074  1064 G$FRCOSCREF0$0$0 == 0x7074
                           007074  1065 _FRCOSCREF0	=	0x7074
                           007075  1066 G$FRCOSCREF1$0$0 == 0x7075
                           007075  1067 _FRCOSCREF1	=	0x7075
                           007074  1068 G$FRCOSCREF$0$0 == 0x7074
                           007074  1069 _FRCOSCREF	=	0x7074
                           007007  1070 G$ANALOGA$0$0 == 0x7007
                           007007  1071 _ANALOGA	=	0x7007
                           00700C  1072 G$GPIOENABLE$0$0 == 0x700c
                           00700C  1073 _GPIOENABLE	=	0x700c
                           007003  1074 G$EXTIRQ$0$0 == 0x7003
                           007003  1075 _EXTIRQ	=	0x7003
                           007000  1076 G$INTCHGA$0$0 == 0x7000
                           007000  1077 _INTCHGA	=	0x7000
                           007001  1078 G$INTCHGB$0$0 == 0x7001
                           007001  1079 _INTCHGB	=	0x7001
                           007002  1080 G$INTCHGC$0$0 == 0x7002
                           007002  1081 _INTCHGC	=	0x7002
                           007008  1082 G$PALTA$0$0 == 0x7008
                           007008  1083 _PALTA	=	0x7008
                           007009  1084 G$PALTB$0$0 == 0x7009
                           007009  1085 _PALTB	=	0x7009
                           00700A  1086 G$PALTC$0$0 == 0x700a
                           00700A  1087 _PALTC	=	0x700a
                           007046  1088 G$PALTRADIO$0$0 == 0x7046
                           007046  1089 _PALTRADIO	=	0x7046
                           007004  1090 G$PINCHGA$0$0 == 0x7004
                           007004  1091 _PINCHGA	=	0x7004
                           007005  1092 G$PINCHGB$0$0 == 0x7005
                           007005  1093 _PINCHGB	=	0x7005
                           007006  1094 G$PINCHGC$0$0 == 0x7006
                           007006  1095 _PINCHGC	=	0x7006
                           00700B  1096 G$PINSEL$0$0 == 0x700b
                           00700B  1097 _PINSEL	=	0x700b
                           007060  1098 G$LPOSCCONFIG$0$0 == 0x7060
                           007060  1099 _LPOSCCONFIG	=	0x7060
                           007066  1100 G$LPOSCFREQ0$0$0 == 0x7066
                           007066  1101 _LPOSCFREQ0	=	0x7066
                           007067  1102 G$LPOSCFREQ1$0$0 == 0x7067
                           007067  1103 _LPOSCFREQ1	=	0x7067
                           007066  1104 G$LPOSCFREQ$0$0 == 0x7066
                           007066  1105 _LPOSCFREQ	=	0x7066
                           007062  1106 G$LPOSCKFILT0$0$0 == 0x7062
                           007062  1107 _LPOSCKFILT0	=	0x7062
                           007063  1108 G$LPOSCKFILT1$0$0 == 0x7063
                           007063  1109 _LPOSCKFILT1	=	0x7063
                           007062  1110 G$LPOSCKFILT$0$0 == 0x7062
                           007062  1111 _LPOSCKFILT	=	0x7062
                           007068  1112 G$LPOSCPER0$0$0 == 0x7068
                           007068  1113 _LPOSCPER0	=	0x7068
                           007069  1114 G$LPOSCPER1$0$0 == 0x7069
                           007069  1115 _LPOSCPER1	=	0x7069
                           007068  1116 G$LPOSCPER$0$0 == 0x7068
                           007068  1117 _LPOSCPER	=	0x7068
                           007064  1118 G$LPOSCREF0$0$0 == 0x7064
                           007064  1119 _LPOSCREF0	=	0x7064
                           007065  1120 G$LPOSCREF1$0$0 == 0x7065
                           007065  1121 _LPOSCREF1	=	0x7065
                           007064  1122 G$LPOSCREF$0$0 == 0x7064
                           007064  1123 _LPOSCREF	=	0x7064
                           007054  1124 G$LPXOSCGM$0$0 == 0x7054
                           007054  1125 _LPXOSCGM	=	0x7054
                           007F01  1126 G$MISCCTRL$0$0 == 0x7f01
                           007F01  1127 _MISCCTRL	=	0x7f01
                           007053  1128 G$OSCCALIB$0$0 == 0x7053
                           007053  1129 _OSCCALIB	=	0x7053
                           007050  1130 G$OSCFORCERUN$0$0 == 0x7050
                           007050  1131 _OSCFORCERUN	=	0x7050
                           007052  1132 G$OSCREADY$0$0 == 0x7052
                           007052  1133 _OSCREADY	=	0x7052
                           007051  1134 G$OSCRUN$0$0 == 0x7051
                           007051  1135 _OSCRUN	=	0x7051
                           007040  1136 G$RADIOFDATAADDR0$0$0 == 0x7040
                           007040  1137 _RADIOFDATAADDR0	=	0x7040
                           007041  1138 G$RADIOFDATAADDR1$0$0 == 0x7041
                           007041  1139 _RADIOFDATAADDR1	=	0x7041
                           007040  1140 G$RADIOFDATAADDR$0$0 == 0x7040
                           007040  1141 _RADIOFDATAADDR	=	0x7040
                           007042  1142 G$RADIOFSTATADDR0$0$0 == 0x7042
                           007042  1143 _RADIOFSTATADDR0	=	0x7042
                           007043  1144 G$RADIOFSTATADDR1$0$0 == 0x7043
                           007043  1145 _RADIOFSTATADDR1	=	0x7043
                           007042  1146 G$RADIOFSTATADDR$0$0 == 0x7042
                           007042  1147 _RADIOFSTATADDR	=	0x7042
                           007044  1148 G$RADIOMUX$0$0 == 0x7044
                           007044  1149 _RADIOMUX	=	0x7044
                           007084  1150 G$SCRATCH0$0$0 == 0x7084
                           007084  1151 _SCRATCH0	=	0x7084
                           007085  1152 G$SCRATCH1$0$0 == 0x7085
                           007085  1153 _SCRATCH1	=	0x7085
                           007086  1154 G$SCRATCH2$0$0 == 0x7086
                           007086  1155 _SCRATCH2	=	0x7086
                           007087  1156 G$SCRATCH3$0$0 == 0x7087
                           007087  1157 _SCRATCH3	=	0x7087
                           007F00  1158 G$SILICONREV$0$0 == 0x7f00
                           007F00  1159 _SILICONREV	=	0x7f00
                           007F19  1160 G$XTALAMPL$0$0 == 0x7f19
                           007F19  1161 _XTALAMPL	=	0x7f19
                           007F18  1162 G$XTALOSC$0$0 == 0x7f18
                           007F18  1163 _XTALOSC	=	0x7f18
                           007F1A  1164 G$XTALREADY$0$0 == 0x7f1a
                           007F1A  1165 _XTALREADY	=	0x7f1a
                           00FC06  1166 Fmain$flash_deviceid$0$0 == 0xfc06
                           00FC06  1167 _flash_deviceid	=	0xfc06
                           00FC00  1168 Fmain$flash_calsector$0$0 == 0xfc00
                           00FC00  1169 _flash_calsector	=	0xfc00
                                   1170 ;--------------------------------------------------------
                                   1171 ; absolute external ram data
                                   1172 ;--------------------------------------------------------
                                   1173 	.area XABS    (ABS,XDATA)
                                   1174 ;--------------------------------------------------------
                                   1175 ; external initialized ram data
                                   1176 ;--------------------------------------------------------
                                   1177 	.area XISEG   (XDATA)
                                   1178 	.area HOME    (CODE)
                                   1179 	.area GSINIT0 (CODE)
                                   1180 	.area GSINIT1 (CODE)
                                   1181 	.area GSINIT2 (CODE)
                                   1182 	.area GSINIT3 (CODE)
                                   1183 	.area GSINIT4 (CODE)
                                   1184 	.area GSINIT5 (CODE)
                                   1185 	.area GSINIT  (CODE)
                                   1186 	.area GSFINAL (CODE)
                                   1187 	.area CSEG    (CODE)
                                   1188 ;--------------------------------------------------------
                                   1189 ; interrupt vector 
                                   1190 ;--------------------------------------------------------
                                   1191 	.area HOME    (CODE)
      000000                       1192 __interrupt_vect:
      000000 02 03 11         [24] 1193 	ljmp	__sdcc_gsinit_startup
      000003 32               [24] 1194 	reti
      000004                       1195 	.ds	7
      00000B 02 00 B1         [24] 1196 	ljmp	_wtimer_irq
      00000E                       1197 	.ds	5
      000013 32               [24] 1198 	reti
      000014                       1199 	.ds	7
      00001B 32               [24] 1200 	reti
      00001C                       1201 	.ds	7
      000023 02 12 1E         [24] 1202 	ljmp	_axradio_isr
      000026                       1203 	.ds	5
      00002B 32               [24] 1204 	reti
      00002C                       1205 	.ds	7
      000033 02 3D 1E         [24] 1206 	ljmp	_pwrmgmt_irq
      000036                       1207 	.ds	5
      00003B 32               [24] 1208 	reti
      00003C                       1209 	.ds	7
      000043 32               [24] 1210 	reti
      000044                       1211 	.ds	7
      00004B 32               [24] 1212 	reti
      00004C                       1213 	.ds	7
      000053 32               [24] 1214 	reti
      000054                       1215 	.ds	7
      00005B 02 02 A3         [24] 1216 	ljmp	_uart0_irq
      00005E                       1217 	.ds	5
      000063 02 02 DA         [24] 1218 	ljmp	_uart1_irq
      000066                       1219 	.ds	5
      00006B 32               [24] 1220 	reti
      00006C                       1221 	.ds	7
      000073 32               [24] 1222 	reti
      000074                       1223 	.ds	7
      00007B 32               [24] 1224 	reti
      00007C                       1225 	.ds	7
      000083 32               [24] 1226 	reti
      000084                       1227 	.ds	7
      00008B 32               [24] 1228 	reti
      00008C                       1229 	.ds	7
      000093 32               [24] 1230 	reti
      000094                       1231 	.ds	7
      00009B 32               [24] 1232 	reti
      00009C                       1233 	.ds	7
      0000A3 32               [24] 1234 	reti
      0000A4                       1235 	.ds	7
      0000AB 02 02 6C         [24] 1236 	ljmp	_dbglink_irq
                                   1237 ;--------------------------------------------------------
                                   1238 ; global & static initialisations
                                   1239 ;--------------------------------------------------------
                                   1240 	.area HOME    (CODE)
                                   1241 	.area GSINIT  (CODE)
                                   1242 	.area GSFINAL (CODE)
                                   1243 	.area GSINIT  (CODE)
                                   1244 	.globl __sdcc_gsinit_startup
                                   1245 	.globl __sdcc_program_startup
                                   1246 	.globl __start__stack
                                   1247 	.globl __mcs51_genXINIT
                                   1248 	.globl __mcs51_genXRAMCLEAR
                                   1249 	.globl __mcs51_genRAMCLEAR
                           000000  1250 	C$main.c$65$1$347 ==.
                                   1251 ;	main.c:65: uint8_t __data coldstart = 1; /* caution: initialization with 1 is necessary! Variables are initialized upon _sdcc_external_startup returning 0 -> the coldstart value returned from _sdcc_external startup does not survive in the coldstart case */
      000396 75 22 01         [24] 1252 	mov	_coldstart,#0x01
                           000003  1253 	C$main.c$66$1$347 ==.
                                   1254 ;	main.c:66: uint16_t __data pkts_received = 0, pkts_missing = 0;
      000399 E4               [12] 1255 	clr	a
      00039A F5 23            [12] 1256 	mov	_pkts_received,a
      00039C F5 24            [12] 1257 	mov	(_pkts_received + 1),a
                           000008  1258 	C$main.c$66$1$347 ==.
                                   1259 ;	main.c:66: 
      00039E F5 25            [12] 1260 	mov	_pkts_missing,a
      0003A0 F5 26            [12] 1261 	mov	(_pkts_missing + 1),a
                                   1262 	.area GSFINAL (CODE)
      0003A2 02 00 AE         [24] 1263 	ljmp	__sdcc_program_startup
                                   1264 ;--------------------------------------------------------
                                   1265 ; Home
                                   1266 ;--------------------------------------------------------
                                   1267 	.area HOME    (CODE)
                                   1268 	.area HOME    (CODE)
      0000AE                       1269 __sdcc_program_startup:
      0000AE 02 3E 8A         [24] 1270 	ljmp	_main
                                   1271 ;	return from main will return to caller
                                   1272 ;--------------------------------------------------------
                                   1273 ; code
                                   1274 ;--------------------------------------------------------
                                   1275 	.area CSEG    (CODE)
                                   1276 ;------------------------------------------------------------
                                   1277 ;Allocation info for local variables in function 'pwrmgmt_irq'
                                   1278 ;------------------------------------------------------------
                                   1279 ;pc                        Allocated to registers r7 
                                   1280 ;------------------------------------------------------------
                           000000  1281 	Fmain$pwrmgmt_irq$0$0 ==.
                           000000  1282 	C$main.c$80$0$0 ==.
                                   1283 ;	main.c:80: static void pwrmgmt_irq(void) __interrupt(INT_POWERMGMT)
                                   1284 ;	-----------------------------------------
                                   1285 ;	 function pwrmgmt_irq
                                   1286 ;	-----------------------------------------
      003D1E                       1287 _pwrmgmt_irq:
                           000007  1288 	ar7 = 0x07
                           000006  1289 	ar6 = 0x06
                           000005  1290 	ar5 = 0x05
                           000004  1291 	ar4 = 0x04
                           000003  1292 	ar3 = 0x03
                           000002  1293 	ar2 = 0x02
                           000001  1294 	ar1 = 0x01
                           000000  1295 	ar0 = 0x00
      003D1E C0 E0            [24] 1296 	push	acc
      003D20 C0 82            [24] 1297 	push	dpl
      003D22 C0 83            [24] 1298 	push	dph
      003D24 C0 07            [24] 1299 	push	ar7
      003D26 C0 D0            [24] 1300 	push	psw
      003D28 75 D0 00         [24] 1301 	mov	psw,#0x00
                           00000D  1302 	C$main.c$82$1$0 ==.
                                   1303 ;	main.c:82: uint8_t pc = PCON;
                           00000D  1304 	C$main.c$84$1$318 ==.
                                   1305 ;	main.c:84: if (!(pc & 0x80))
      003D2B E5 87            [12] 1306 	mov	a,_PCON
      003D2D FF               [12] 1307 	mov	r7,a
      003D2E 20 E7 02         [24] 1308 	jb	acc.7,00102$
                           000013  1309 	C$main.c$85$1$318 ==.
                                   1310 ;	main.c:85: return;
      003D31 80 10            [24] 1311 	sjmp	00106$
      003D33                       1312 00102$:
                           000015  1313 	C$main.c$87$1$318 ==.
                                   1314 ;	main.c:87: GPIOENABLE = 0;
      003D33 90 70 0C         [24] 1315 	mov	dptr,#_GPIOENABLE
      003D36 E4               [12] 1316 	clr	a
      003D37 F0               [24] 1317 	movx	@dptr,a
                           00001A  1318 	C$main.c$88$1$318 ==.
                                   1319 ;	main.c:88: IE = EIE = E2IE = 0;
                                   1320 ;	1-genFromRTrack replaced	mov	_E2IE,#0x00
      003D38 F5 A0            [12] 1321 	mov	_E2IE,a
                                   1322 ;	1-genFromRTrack replaced	mov	_EIE,#0x00
      003D3A F5 98            [12] 1323 	mov	_EIE,a
                                   1324 ;	1-genFromRTrack replaced	mov	_IE,#0x00
      003D3C F5 A8            [12] 1325 	mov	_IE,a
      003D3E                       1326 00104$:
                           000020  1327 	C$main.c$91$1$318 ==.
                                   1328 ;	main.c:91: PCON |= 0x01;
      003D3E 43 87 01         [24] 1329 	orl	_PCON,#0x01
      003D41 80 FB            [24] 1330 	sjmp	00104$
      003D43                       1331 00106$:
      003D43 D0 D0            [24] 1332 	pop	psw
      003D45 D0 07            [24] 1333 	pop	ar7
      003D47 D0 83            [24] 1334 	pop	dph
      003D49 D0 82            [24] 1335 	pop	dpl
      003D4B D0 E0            [24] 1336 	pop	acc
                           00002F  1337 	C$main.c$92$1$318 ==.
                           00002F  1338 	XFmain$pwrmgmt_irq$0$0 ==.
      003D4D 32               [24] 1339 	reti
                                   1340 ;	eliminated unneeded push/pop b
                                   1341 ;------------------------------------------------------------
                                   1342 ;Allocation info for local variables in function 'axradio_statuschange'
                                   1343 ;------------------------------------------------------------
                                   1344 ;st                        Allocated to registers r6 r7 
                                   1345 ;foffs                     Allocated to registers r2 r3 r4 r5 
                                   1346 ;------------------------------------------------------------
                           000030  1347 	G$axradio_statuschange$0$0 ==.
                           000030  1348 	C$main.c$94$1$318 ==.
                                   1349 ;	main.c:94: void axradio_statuschange(struct axradio_status __xdata *st)
                                   1350 ;	-----------------------------------------
                                   1351 ;	 function axradio_statuschange
                                   1352 ;	-----------------------------------------
      003D4E                       1353 _axradio_statuschange:
                           000030  1354 	C$main.c$108$1$320 ==.
                                   1355 ;	main.c:108: switch (st->status)
      003D4E AE 82            [24] 1356 	mov	r6,dpl
      003D50 AF 83            [24] 1357 	mov  r7,dph
      003D52 E0               [24] 1358 	movx	a,@dptr
      003D53 FD               [12] 1359 	mov	r5,a
      003D54 60 03            [24] 1360 	jz	00177$
      003D56 02 3E 22         [24] 1361 	ljmp	00149$
      003D59                       1362 00177$:
                           00003B  1363 	C$main.c$112$2$321 ==.
                                   1364 ;	main.c:112: switch (st->error)
      003D59 74 01            [12] 1365 	mov	a,#0x01
      003D5B 2E               [12] 1366 	add	a,r6
      003D5C FC               [12] 1367 	mov	r4,a
      003D5D E4               [12] 1368 	clr	a
      003D5E 3F               [12] 1369 	addc	a,r7
      003D5F FD               [12] 1370 	mov	r5,a
      003D60 8C 82            [24] 1371 	mov	dpl,r4
      003D62 8D 83            [24] 1372 	mov	dph,r5
      003D64 E0               [24] 1373 	movx	a,@dptr
      003D65 FB               [12] 1374 	mov	r3,a
      003D66 60 14            [24] 1375 	jz	00113$
      003D68 BB 03 02         [24] 1376 	cjne	r3,#0x03,00179$
      003D6B 80 0F            [24] 1377 	sjmp	00113$
      003D6D                       1378 00179$:
      003D6D BB 09 02         [24] 1379 	cjne	r3,#0x09,00180$
      003D70 80 0E            [24] 1380 	sjmp	00116$
      003D72                       1381 00180$:
      003D72 BB 0A 02         [24] 1382 	cjne	r3,#0x0a,00181$
      003D75 80 05            [24] 1383 	sjmp	00113$
      003D77                       1384 00181$:
                           000059  1385 	C$main.c$121$3$322 ==.
                                   1386 ;	main.c:121: led0_off();
      003D77 BB 0B 21         [24] 1387 	cjne	r3,#0x0b,00125$
      003D7A 80 1D            [24] 1388 	sjmp	00121$
      003D7C                       1389 00113$:
      003D7C C2 89            [12] 1390 	clr	_PORTB_1
                           000060  1391 	C$main.c$122$3$322 ==.
                                   1392 ;	main.c:122: break;
                           000060  1393 	C$main.c$124$3$322 ==.
                                   1394 ;	main.c:124: case AXRADIO_ERR_RESYNC:
      003D7E 80 1B            [24] 1395 	sjmp	00125$
      003D80                       1396 00116$:
                           000062  1397 	C$main.c$125$3$322 ==.
                                   1398 ;	main.c:125: axradio_set_freqoffset(0);
      003D80 90 00 00         [24] 1399 	mov	dptr,#(0x00&0x00ff)
      003D83 E4               [12] 1400 	clr	a
      003D84 F5 F0            [12] 1401 	mov	b,a
      003D86 C0 07            [24] 1402 	push	ar7
      003D88 C0 06            [24] 1403 	push	ar6
      003D8A C0 05            [24] 1404 	push	ar5
      003D8C C0 04            [24] 1405 	push	ar4
      003D8E 12 35 7A         [24] 1406 	lcall	_axradio_set_freqoffset
      003D91 D0 04            [24] 1407 	pop	ar4
      003D93 D0 05            [24] 1408 	pop	ar5
      003D95 D0 06            [24] 1409 	pop	ar6
      003D97 D0 07            [24] 1410 	pop	ar7
                           00007B  1411 	C$main.c$130$3$322 ==.
                                   1412 ;	main.c:130: led0_on();
      003D99                       1413 00121$:
      003D99 D2 89            [12] 1414 	setb	_PORTB_1
                           00007D  1415 	C$main.c$135$2$321 ==.
                                   1416 ;	main.c:135: }
      003D9B                       1417 00125$:
                           00007D  1418 	C$main.c$137$2$321 ==.
                                   1419 ;	main.c:137: if (st->error == AXRADIO_ERR_NOERROR)
      003D9B 8C 82            [24] 1420 	mov	dpl,r4
      003D9D 8D 83            [24] 1421 	mov	dph,r5
      003D9F E0               [24] 1422 	movx	a,@dptr
      003DA0 70 08            [24] 1423 	jnz	00132$
                           000084  1424 	C$main.c$139$3$329 ==.
                                   1425 ;	main.c:139: ++pkts_received;
      003DA2 05 23            [12] 1426 	inc	_pkts_received
      003DA4 E4               [12] 1427 	clr	a
      003DA5 B5 23 02         [24] 1428 	cjne	a,_pkts_received,00184$
      003DA8 05 24            [12] 1429 	inc	(_pkts_received + 1)
      003DAA                       1430 00184$:
                           00008C  1431 	C$main.c$140$2$321 ==.
                                   1432 ;	main.c:140: led2_off();
      003DAA                       1433 00132$:
                           00008C  1434 	C$main.c$192$3$332 ==.
                                   1435 ;	main.c:192: int32_t foffs = axradio_get_freqoffset();
      003DAA C0 07            [24] 1436 	push	ar7
      003DAC C0 06            [24] 1437 	push	ar6
      003DAE 12 35 96         [24] 1438 	lcall	_axradio_get_freqoffset
      003DB1 AA 82            [24] 1439 	mov	r2,dpl
      003DB3 AB 83            [24] 1440 	mov	r3,dph
      003DB5 AC F0            [24] 1441 	mov	r4,b
      003DB7 FD               [12] 1442 	mov	r5,a
      003DB8 D0 06            [24] 1443 	pop	ar6
      003DBA D0 07            [24] 1444 	pop	ar7
                           00009E  1445 	C$main.c$194$3$332 ==.
                                   1446 ;	main.c:194: foffs -= (st->u.rx.phy.offset)>>(FREQOFFS_K); /*adjust RX frequency by low-pass filtered frequency offset */
      003DBC 74 06            [12] 1447 	mov	a,#0x06
      003DBE 2E               [12] 1448 	add	a,r6
      003DBF FE               [12] 1449 	mov	r6,a
      003DC0 E4               [12] 1450 	clr	a
      003DC1 3F               [12] 1451 	addc	a,r7
      003DC2 FF               [12] 1452 	mov	r7,a
      003DC3 8E 82            [24] 1453 	mov	dpl,r6
      003DC5 8F 83            [24] 1454 	mov	dph,r7
      003DC7 A3               [24] 1455 	inc	dptr
      003DC8 A3               [24] 1456 	inc	dptr
      003DC9 E0               [24] 1457 	movx	a,@dptr
      003DCA F8               [12] 1458 	mov	r0,a
      003DCB A3               [24] 1459 	inc	dptr
      003DCC E0               [24] 1460 	movx	a,@dptr
      003DCD F9               [12] 1461 	mov	r1,a
      003DCE A3               [24] 1462 	inc	dptr
      003DCF E0               [24] 1463 	movx	a,@dptr
      003DD0 FE               [12] 1464 	mov	r6,a
      003DD1 A3               [24] 1465 	inc	dptr
      003DD2 E0               [24] 1466 	movx	a,@dptr
      003DD3 FF               [12] 1467 	mov	r7,a
      003DD4 E9               [12] 1468 	mov	a,r1
      003DD5 C4               [12] 1469 	swap	a
      003DD6 23               [12] 1470 	rl	a
      003DD7 C8               [12] 1471 	xch	a,r0
      003DD8 C4               [12] 1472 	swap	a
      003DD9 23               [12] 1473 	rl	a
      003DDA 54 1F            [12] 1474 	anl	a,#0x1f
      003DDC 68               [12] 1475 	xrl	a,r0
      003DDD C8               [12] 1476 	xch	a,r0
      003DDE 54 1F            [12] 1477 	anl	a,#0x1f
      003DE0 C8               [12] 1478 	xch	a,r0
      003DE1 68               [12] 1479 	xrl	a,r0
      003DE2 C8               [12] 1480 	xch	a,r0
      003DE3 F9               [12] 1481 	mov	r1,a
      003DE4 EE               [12] 1482 	mov	a,r6
      003DE5 C4               [12] 1483 	swap	a
      003DE6 23               [12] 1484 	rl	a
      003DE7 54 E0            [12] 1485 	anl	a,#0xe0
      003DE9 49               [12] 1486 	orl	a,r1
      003DEA F9               [12] 1487 	mov	r1,a
      003DEB EF               [12] 1488 	mov	a,r7
      003DEC C4               [12] 1489 	swap	a
      003DED 23               [12] 1490 	rl	a
      003DEE CE               [12] 1491 	xch	a,r6
      003DEF C4               [12] 1492 	swap	a
      003DF0 23               [12] 1493 	rl	a
      003DF1 54 1F            [12] 1494 	anl	a,#0x1f
      003DF3 6E               [12] 1495 	xrl	a,r6
      003DF4 CE               [12] 1496 	xch	a,r6
      003DF5 54 1F            [12] 1497 	anl	a,#0x1f
      003DF7 CE               [12] 1498 	xch	a,r6
      003DF8 6E               [12] 1499 	xrl	a,r6
      003DF9 CE               [12] 1500 	xch	a,r6
      003DFA 30 E4 02         [24] 1501 	jnb	acc.4,00185$
      003DFD 44 E0            [12] 1502 	orl	a,#0xe0
      003DFF                       1503 00185$:
      003DFF FF               [12] 1504 	mov	r7,a
      003E00 EA               [12] 1505 	mov	a,r2
      003E01 C3               [12] 1506 	clr	c
      003E02 98               [12] 1507 	subb	a,r0
      003E03 FA               [12] 1508 	mov	r2,a
      003E04 EB               [12] 1509 	mov	a,r3
      003E05 99               [12] 1510 	subb	a,r1
      003E06 FB               [12] 1511 	mov	r3,a
      003E07 EC               [12] 1512 	mov	a,r4
      003E08 9E               [12] 1513 	subb	a,r6
      003E09 FC               [12] 1514 	mov	r4,a
      003E0A ED               [12] 1515 	mov	a,r5
      003E0B 9F               [12] 1516 	subb	a,r7
                           0000EE  1517 	C$main.c$198$3$332 ==.
                                   1518 ;	main.c:198: if (axradio_set_freqoffset(foffs) != AXRADIO_ERR_NOERROR)
      003E0C 8A 82            [24] 1519 	mov	dpl,r2
      003E0E 8B 83            [24] 1520 	mov	dph,r3
      003E10 8C F0            [24] 1521 	mov	b,r4
      003E12 12 35 7A         [24] 1522 	lcall	_axradio_set_freqoffset
      003E15 E5 82            [12] 1523 	mov	a,dpl
      003E17 60 09            [24] 1524 	jz	00149$
                           0000FB  1525 	C$main.c$199$3$332 ==.
                                   1526 ;	main.c:199: axradio_set_freqoffset(0);
      003E19 90 00 00         [24] 1527 	mov	dptr,#(0x00&0x00ff)
      003E1C E4               [12] 1528 	clr	a
      003E1D F5 F0            [12] 1529 	mov	b,a
      003E1F 12 35 7A         [24] 1530 	lcall	_axradio_set_freqoffset
                           000104  1531 	C$main.c$242$1$320 ==.
                                   1532 ;	main.c:242: }
      003E22                       1533 00149$:
                           000104  1534 	C$main.c$243$1$320 ==.
                           000104  1535 	XG$axradio_statuschange$0$0 ==.
      003E22 22               [24] 1536 	ret
                                   1537 ;------------------------------------------------------------
                                   1538 ;Allocation info for local variables in function 'enable_radio_interrupt_in_mcu_pin'
                                   1539 ;------------------------------------------------------------
                           000105  1540 	G$enable_radio_interrupt_in_mcu_pin$0$0 ==.
                           000105  1541 	C$main.c$245$1$320 ==.
                                   1542 ;	main.c:245: void enable_radio_interrupt_in_mcu_pin(void)
                                   1543 ;	-----------------------------------------
                                   1544 ;	 function enable_radio_interrupt_in_mcu_pin
                                   1545 ;	-----------------------------------------
      003E23                       1546 _enable_radio_interrupt_in_mcu_pin:
                           000105  1547 	C$main.c$247$1$338 ==.
                                   1548 ;	main.c:247: IE_4 = 1;
      003E23 D2 AC            [12] 1549 	setb	_IE_4
                           000107  1550 	C$main.c$248$1$338 ==.
                           000107  1551 	XG$enable_radio_interrupt_in_mcu_pin$0$0 ==.
      003E25 22               [24] 1552 	ret
                                   1553 ;------------------------------------------------------------
                                   1554 ;Allocation info for local variables in function 'disable_radio_interrupt_in_mcu_pin'
                                   1555 ;------------------------------------------------------------
                           000108  1556 	G$disable_radio_interrupt_in_mcu_pin$0$0 ==.
                           000108  1557 	C$main.c$250$1$338 ==.
                                   1558 ;	main.c:250: void disable_radio_interrupt_in_mcu_pin(void)
                                   1559 ;	-----------------------------------------
                                   1560 ;	 function disable_radio_interrupt_in_mcu_pin
                                   1561 ;	-----------------------------------------
      003E26                       1562 _disable_radio_interrupt_in_mcu_pin:
                           000108  1563 	C$main.c$252$1$340 ==.
                                   1564 ;	main.c:252: IE_4 = 0;
      003E26 C2 AC            [12] 1565 	clr	_IE_4
                           00010A  1566 	C$main.c$253$1$340 ==.
                           00010A  1567 	XG$disable_radio_interrupt_in_mcu_pin$0$0 ==.
      003E28 22               [24] 1568 	ret
                                   1569 ;------------------------------------------------------------
                                   1570 ;Allocation info for local variables in function '_sdcc_external_startup'
                                   1571 ;------------------------------------------------------------
                                   1572 ;c                         Allocated to registers 
                                   1573 ;p                         Allocated to registers 
                                   1574 ;c                         Allocated to registers 
                                   1575 ;p                         Allocated to registers 
                                   1576 ;------------------------------------------------------------
                           00010B  1577 	G$_sdcc_external_startup$0$0 ==.
                           00010B  1578 	C$main.c$256$1$340 ==.
                                   1579 ;	main.c:256: uint8_t _sdcc_external_startup(void)
                                   1580 ;	-----------------------------------------
                                   1581 ;	 function _sdcc_external_startup
                                   1582 ;	-----------------------------------------
      003E29                       1583 __sdcc_external_startup:
                           00010B  1584 	C$main.c$258$1$342 ==.
                                   1585 ;	main.c:258: LPXOSCGM = 0x8A;
      003E29 90 70 54         [24] 1586 	mov	dptr,#_LPXOSCGM
      003E2C 74 8A            [12] 1587 	mov	a,#0x8a
      003E2E F0               [24] 1588 	movx	@dptr,a
                           000111  1589 	C$main.c$259$2$343 ==.
                                   1590 ;	main.c:259: wtimer0_setclksrc(WTIMER0_CLKSRC, WTIMER0_PRESCALER);
      003E2F 75 82 0B         [24] 1591 	mov	dpl,#0x0b
      003E32 12 40 BC         [24] 1592 	lcall	_wtimer0_setconfig
                           000117  1593 	C$main.c$260$2$344 ==.
                                   1594 ;	main.c:260: wtimer1_setclksrc(CLKSRC_FRCOSC, 7);
      003E35 75 82 38         [24] 1595 	mov	dpl,#0x38
      003E38 12 40 D6         [24] 1596 	lcall	_wtimer1_setconfig
                           00011D  1597 	C$main.c$263$1$342 ==.
                                   1598 ;	main.c:263: coldstart = !(PCON & 0x40);
      003E3B E5 87            [12] 1599 	mov	a,_PCON
      003E3D A2 E6            [12] 1600 	mov	c,acc[6]
      003E3F B3               [12] 1601 	cpl	c
      003E40 92 02            [24] 1602 	mov	__sdcc_external_startup_sloc0_1_0,c
      003E42 E4               [12] 1603 	clr	a
      003E43 33               [12] 1604 	rlc	a
      003E44 F5 22            [12] 1605 	mov	_coldstart,a
                           000128  1606 	C$main.c$265$1$342 ==.
                                   1607 ;	main.c:265: ANALOGA = 0x18; /* PA[3,4] LPXOSC, other PA are used as digital pins */
      003E46 90 70 07         [24] 1608 	mov	dptr,#_ANALOGA
      003E49 74 18            [12] 1609 	mov	a,#0x18
      003E4B F0               [24] 1610 	movx	@dptr,a
                           00012E  1611 	C$main.c$266$1$342 ==.
                                   1612 ;	main.c:266: PORTA = 0xE7; /* pull ups except for LPXOSC pin PA[3,4] */
      003E4C 75 80 E7         [24] 1613 	mov	_PORTA,#0xe7
                           000131  1614 	C$main.c$267$1$342 ==.
                                   1615 ;	main.c:267: PORTB = 0xFD | (PINB & 0x02); /* */
      003E4F 74 02            [12] 1616 	mov	a,#0x02
      003E51 55 E8            [12] 1617 	anl	a,_PINB
      003E53 44 FD            [12] 1618 	orl	a,#0xfd
      003E55 F5 88            [12] 1619 	mov	_PORTB,a
                           000139  1620 	C$main.c$268$1$342 ==.
                                   1621 ;	main.c:268: PORTC = 0xFF; /* */
      003E57 75 90 FF         [24] 1622 	mov	_PORTC,#0xff
                           00013C  1623 	C$main.c$269$1$342 ==.
                                   1624 ;	main.c:269: PORTR = 0x0B; /* */
      003E5A 75 8C 0B         [24] 1625 	mov	_PORTR,#0x0b
                           00013F  1626 	C$main.c$271$1$342 ==.
                                   1627 ;	main.c:271: DIRA = 0x00; /* */
      003E5D 75 89 00         [24] 1628 	mov	_DIRA,#0x00
                           000142  1629 	C$main.c$272$1$342 ==.
                                   1630 ;	main.c:272: DIRB = 0x0e; /*  PB1 = LED; PB2 / PB3 are outputs (in case PWRAMP / ANSTSEL are used) */
      003E60 75 8A 0E         [24] 1631 	mov	_DIRB,#0x0e
                           000145  1632 	C$main.c$273$1$342 ==.
                                   1633 ;	main.c:273: DIRC = 0x00; /*  PC4 = Switch */
      003E63 75 8B 00         [24] 1634 	mov	_DIRC,#0x00
                           000148  1635 	C$main.c$274$1$342 ==.
                                   1636 ;	main.c:274: DIRR = 0x15; /* */
      003E66 75 8E 15         [24] 1637 	mov	_DIRR,#0x15
                           00014B  1638 	C$main.c$276$1$342 ==.
                                   1639 ;	main.c:276: axradio_setup_pincfg1();
      003E69 12 06 E0         [24] 1640 	lcall	_axradio_setup_pincfg1
                           00014E  1641 	C$main.c$277$1$342 ==.
                                   1642 ;	main.c:277: DPS = 0;
      003E6C 75 86 00         [24] 1643 	mov	_DPS,#0x00
                           000151  1644 	C$main.c$278$1$342 ==.
                                   1645 ;	main.c:278: IE = 0x40;
      003E6F 75 A8 40         [24] 1646 	mov	_IE,#0x40
                           000154  1647 	C$main.c$279$1$342 ==.
                                   1648 ;	main.c:279: EIE = 0x00;
      003E72 75 98 00         [24] 1649 	mov	_EIE,#0x00
                           000157  1650 	C$main.c$280$1$342 ==.
                                   1651 ;	main.c:280: E2IE = 0x00;
      003E75 75 A0 00         [24] 1652 	mov	_E2IE,#0x00
                           00015A  1653 	C$main.c$283$1$342 ==.
                                   1654 ;	main.c:283: GPIOENABLE = 1; /* unfreeze GPIO */
      003E78 90 70 0C         [24] 1655 	mov	dptr,#_GPIOENABLE
      003E7B 74 01            [12] 1656 	mov	a,#0x01
      003E7D F0               [24] 1657 	movx	@dptr,a
                           000160  1658 	C$main.c$284$1$342 ==.
                                   1659 ;	main.c:284: return !coldstart; /* coldstart -> return 0 -> var initialization; start from sleep -> return 1 -> no var initialization */
      003E7E E5 22            [12] 1660 	mov	a,_coldstart
      003E80 B4 01 00         [24] 1661 	cjne	a,#0x01,00111$
      003E83                       1662 00111$:
      003E83 92 02            [24] 1663 	mov  __sdcc_external_startup_sloc0_1_0,c
      003E85 E4               [12] 1664 	clr	a
      003E86 33               [12] 1665 	rlc	a
      003E87 F5 82            [12] 1666 	mov	dpl,a
                           00016B  1667 	C$main.c$285$1$342 ==.
                           00016B  1668 	XG$_sdcc_external_startup$0$0 ==.
      003E89 22               [24] 1669 	ret
                                   1670 ;------------------------------------------------------------
                                   1671 ;Allocation info for local variables in function 'main'
                                   1672 ;------------------------------------------------------------
                                   1673 ;i                         Allocated to registers 
                                   1674 ;flg                       Allocated to registers r7 
                                   1675 ;flg                       Allocated to registers r7 
                                   1676 ;------------------------------------------------------------
                           00016C  1677 	G$main$0$0 ==.
                           00016C  1678 	C$main.c$287$1$342 ==.
                                   1679 ;	main.c:287: int main(void)
                                   1680 ;	-----------------------------------------
                                   1681 ;	 function main
                                   1682 ;	-----------------------------------------
      003E8A                       1683 _main:
                           00016C  1684 	C$main.c$293$1$347 ==.
                                   1685 ;	main.c:293: __endasm;
                           000000  1686 	G$_start__stack$0$0	= __start__stack
                                   1687 	.globl	G$_start__stack$0$0
                           00016C  1688 	C$libmftypes.h$368$4$375 ==.
                                   1689 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:368: EA = 1;
      003E8A D2 AF            [12] 1690 	setb	_EA
                           00016E  1691 	C$main.c$298$1$347 ==.
                                   1692 ;	main.c:298: flash_apply_calibration();
      003E8C 12 46 8C         [24] 1693 	lcall	_flash_apply_calibration
                           000171  1694 	C$main.c$299$1$347 ==.
                                   1695 ;	main.c:299: CLKCON = 0x00;
      003E8F 75 C6 00         [24] 1696 	mov	_CLKCON,#0x00
                           000174  1697 	C$main.c$300$1$347 ==.
                                   1698 ;	main.c:300: wtimer_init();
      003E92 12 41 85         [24] 1699 	lcall	_wtimer_init
                           000177  1700 	C$main.c$302$1$347 ==.
                                   1701 ;	main.c:302: if (coldstart)
      003E95 E5 22            [12] 1702 	mov	a,_coldstart
      003E97 60 38            [24] 1703 	jz	00145$
                           00017B  1704 	C$main.c$304$4$350 ==.
                                   1705 ;	main.c:304: led0_off();
      003E99 C2 89            [12] 1706 	clr	_PORTB_1
                           00017D  1707 	C$main.c$311$2$348 ==.
                                   1708 ;	main.c:311: i = axradio_init();
      003E9B 12 2A F4         [24] 1709 	lcall	_axradio_init
      003E9E E5 82            [12] 1710 	mov	a,dpl
                           000182  1711 	C$main.c$313$2$348 ==.
                                   1712 ;	main.c:313: if (i != AXRADIO_ERR_NOERROR)
      003EA0 70 54            [24] 1713 	jnz	00164$
                           000184  1714 	C$main.c$337$2$348 ==.
                                   1715 ;	main.c:337: axradio_set_local_address(&localaddr);
      003EA2 90 4E 7E         [24] 1716 	mov	dptr,#_localaddr
      003EA5 75 F0 80         [24] 1717 	mov	b,#0x80
      003EA8 12 35 AA         [24] 1718 	lcall	_axradio_set_local_address
                           00018D  1719 	C$main.c$338$2$348 ==.
                                   1720 ;	main.c:338: axradio_set_default_remote_address(&remoteaddr);
      003EAB 90 4E 79         [24] 1721 	mov	dptr,#_remoteaddr
      003EAE 75 F0 80         [24] 1722 	mov	b,#0x80
      003EB1 12 35 E8         [24] 1723 	lcall	_axradio_set_default_remote_address
                           000196  1724 	C$main.c$351$2$348 ==.
                                   1725 ;	main.c:351: delay_ms(lpxosc_settlingtime);
      003EB4 90 4E 8A         [24] 1726 	mov	dptr,#_lpxosc_settlingtime
      003EB7 E4               [12] 1727 	clr	a
      003EB8 93               [24] 1728 	movc	a,@a+dptr
      003EB9 FE               [12] 1729 	mov	r6,a
      003EBA 74 01            [12] 1730 	mov	a,#0x01
      003EBC 93               [24] 1731 	movc	a,@a+dptr
      003EBD FF               [12] 1732 	mov	r7,a
      003EBE 8E 82            [24] 1733 	mov	dpl,r6
      003EC0 8F 83            [24] 1734 	mov	dph,r7
      003EC2 12 3B 13         [24] 1735 	lcall	_delay_ms
                           0001A7  1736 	C$main.c$416$2$348 ==.
                                   1737 ;	main.c:416: i = axradio_set_mode(RADIO_MODE);
      003EC5 75 82 33         [24] 1738 	mov	dpl,#0x33
      003EC8 12 2E F8         [24] 1739 	lcall	_axradio_set_mode
      003ECB E5 82            [12] 1740 	mov	a,dpl
                           0001AF  1741 	C$main.c$418$2$348 ==.
                                   1742 ;	main.c:418: if (i != AXRADIO_ERR_NOERROR)
      003ECD 60 07            [24] 1743 	jz	00146$
                           0001B1  1744 	C$main.c$419$2$348 ==.
                                   1745 ;	main.c:419: goto terminate_radio_error;
      003ECF 80 25            [24] 1746 	sjmp	00164$
      003ED1                       1747 00145$:
                           0001B3  1748 	C$main.c$428$2$367 ==.
                                   1749 ;	main.c:428: axradio_commsleepexit();
      003ED1 12 3A AB         [24] 1750 	lcall	_axradio_commsleepexit
                           0001B6  1751 	C$main.c$429$2$367 ==.
                                   1752 ;	main.c:429: IE_4 = 1; /* enable radio interrupt */
      003ED4 D2 AC            [12] 1753 	setb	_IE_4
      003ED6                       1754 00146$:
                           0001B8  1755 	C$main.c$432$1$347 ==.
                                   1756 ;	main.c:432: axradio_setup_pincfg2();
      003ED6 12 06 E6         [24] 1757 	lcall	_axradio_setup_pincfg2
      003ED9                       1758 00162$:
                           0001BB  1759 	C$main.c$436$2$368 ==.
                                   1760 ;	main.c:436: wtimer_runcallbacks();
      003ED9 12 43 3D         [24] 1761 	lcall	_wtimer_runcallbacks
                           0001BE  1762 	C$libmftypes.h$373$5$378 ==.
                                   1763 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:373: EA = 0;
      003EDC C2 AF            [12] 1764 	clr	_EA
                           0001C0  1765 	C$main.c$439$3$368 ==.
                                   1766 ;	main.c:439: uint8_t flg = WTFLAG_CANSTANDBY;
      003EDE 7F 02            [12] 1767 	mov	r7,#0x02
                           0001C2  1768 	C$main.c$442$3$369 ==.
                                   1769 ;	main.c:442: if (axradio_cansleep()
      003EE0 C0 07            [24] 1770 	push	ar7
      003EE2 12 2E E6         [24] 1771 	lcall	_axradio_cansleep
      003EE5 E5 82            [12] 1772 	mov	a,dpl
      003EE7 D0 07            [24] 1773 	pop	ar7
      003EE9 60 02            [24] 1774 	jz	00148$
                           0001CD  1775 	C$main.c$447$3$369 ==.
                                   1776 ;	main.c:447: flg |= WTFLAG_CANSLEEP;
      003EEB 7F 03            [12] 1777 	mov	r7,#0x03
      003EED                       1778 00148$:
                           0001CF  1779 	C$main.c$449$3$369 ==.
                                   1780 ;	main.c:449: wtimer_idle(flg);
      003EED 8F 82            [24] 1781 	mov	dpl,r7
      003EEF 12 42 B9         [24] 1782 	lcall	_wtimer_idle
                           0001D4  1783 	C$libmftypes.h$368$5$381 ==.
                                   1784 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:368: EA = 1;
      003EF2 D2 AF            [12] 1785 	setb	_EA
                           0001D6  1786 	C$main.c$451$4$380 ==.
                                   1787 ;	main.c:451: __enable_irq();
                           0001D6  1788 	C$main.c$459$1$347 ==.
                                   1789 ;	main.c:459: terminate_error:
      003EF4 80 E3            [24] 1790 	sjmp	00162$
      003EF6                       1791 00164$:
                           0001D8  1792 	C$main.c$463$2$371 ==.
                                   1793 ;	main.c:463: wtimer_runcallbacks();
      003EF6 12 43 3D         [24] 1794 	lcall	_wtimer_runcallbacks
                           0001DB  1795 	C$main.c$465$3$371 ==.
                                   1796 ;	main.c:465: uint8_t flg = WTFLAG_CANSTANDBY;
      003EF9 7F 02            [12] 1797 	mov	r7,#0x02
                           0001DD  1798 	C$main.c$468$3$372 ==.
                                   1799 ;	main.c:468: if (axradio_cansleep()
      003EFB C0 07            [24] 1800 	push	ar7
      003EFD 12 2E E6         [24] 1801 	lcall	_axradio_cansleep
      003F00 E5 82            [12] 1802 	mov	a,dpl
      003F02 D0 07            [24] 1803 	pop	ar7
      003F04 60 02            [24] 1804 	jz	00156$
                           0001E8  1805 	C$main.c$473$3$372 ==.
                                   1806 ;	main.c:473: flg |= WTFLAG_CANSLEEP;
      003F06 7F 03            [12] 1807 	mov	r7,#0x03
      003F08                       1808 00156$:
                           0001EA  1809 	C$main.c$475$3$372 ==.
                                   1810 ;	main.c:475: wtimer_idle(flg);
      003F08 8F 82            [24] 1811 	mov	dpl,r7
      003F0A 12 42 B9         [24] 1812 	lcall	_wtimer_idle
      003F0D 80 E7            [24] 1813 	sjmp	00164$
                           0001F1  1814 	C$main.c$478$1$347 ==.
                           0001F1  1815 	XG$main$0$0 ==.
      003F0F 22               [24] 1816 	ret
                                   1817 	.area CSEG    (CODE)
                                   1818 	.area CONST   (CODE)
                                   1819 	.area XINIT   (CODE)
                                   1820 	.area CABS    (ABS,CODE)
