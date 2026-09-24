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
                           0000E0   397 _ACC	=	0x00e0
                           0000F0   398 _B	=	0x00f0
                           000083   399 _DPH	=	0x0083
                           000085   400 _DPH1	=	0x0085
                           000082   401 _DPL	=	0x0082
                           000084   402 _DPL1	=	0x0084
                           008382   403 _DPTR0	=	0x8382
                           008584   404 _DPTR1	=	0x8584
                           000086   405 _DPS	=	0x0086
                           0000A0   406 _E2IE	=	0x00a0
                           0000C0   407 _E2IP	=	0x00c0
                           000098   408 _EIE	=	0x0098
                           0000B0   409 _EIP	=	0x00b0
                           0000A8   410 _IE	=	0x00a8
                           0000B8   411 _IP	=	0x00b8
                           000087   412 _PCON	=	0x0087
                           0000D0   413 _PSW	=	0x00d0
                           000081   414 _SP	=	0x0081
                           0000D9   415 _XPAGE	=	0x00d9
                           0000D9   416 __XPAGE	=	0x00d9
                           0000CA   417 _ADCCH0CONFIG	=	0x00ca
                           0000CB   418 _ADCCH1CONFIG	=	0x00cb
                           0000D2   419 _ADCCH2CONFIG	=	0x00d2
                           0000D3   420 _ADCCH3CONFIG	=	0x00d3
                           0000D1   421 _ADCCLKSRC	=	0x00d1
                           0000C9   422 _ADCCONV	=	0x00c9
                           0000E1   423 _ANALOGCOMP	=	0x00e1
                           0000C6   424 _CLKCON	=	0x00c6
                           0000C7   425 _CLKSTAT	=	0x00c7
                           000097   426 _CODECONFIG	=	0x0097
                           0000E3   427 _DBGLNKBUF	=	0x00e3
                           0000E2   428 _DBGLNKSTAT	=	0x00e2
                           000089   429 _DIRA	=	0x0089
                           00008A   430 _DIRB	=	0x008a
                           00008B   431 _DIRC	=	0x008b
                           00008E   432 _DIRR	=	0x008e
                           0000C8   433 _PINA	=	0x00c8
                           0000E8   434 _PINB	=	0x00e8
                           0000F8   435 _PINC	=	0x00f8
                           00008D   436 _PINR	=	0x008d
                           000080   437 _PORTA	=	0x0080
                           000088   438 _PORTB	=	0x0088
                           000090   439 _PORTC	=	0x0090
                           00008C   440 _PORTR	=	0x008c
                           0000CE   441 _IC0CAPT0	=	0x00ce
                           0000CF   442 _IC0CAPT1	=	0x00cf
                           00CFCE   443 _IC0CAPT	=	0xcfce
                           0000CC   444 _IC0MODE	=	0x00cc
                           0000CD   445 _IC0STATUS	=	0x00cd
                           0000D6   446 _IC1CAPT0	=	0x00d6
                           0000D7   447 _IC1CAPT1	=	0x00d7
                           00D7D6   448 _IC1CAPT	=	0xd7d6
                           0000D4   449 _IC1MODE	=	0x00d4
                           0000D5   450 _IC1STATUS	=	0x00d5
                           000092   451 _NVADDR0	=	0x0092
                           000093   452 _NVADDR1	=	0x0093
                           009392   453 _NVADDR	=	0x9392
                           000094   454 _NVDATA0	=	0x0094
                           000095   455 _NVDATA1	=	0x0095
                           009594   456 _NVDATA	=	0x9594
                           000096   457 _NVKEY	=	0x0096
                           000091   458 _NVSTATUS	=	0x0091
                           0000BC   459 _OC0COMP0	=	0x00bc
                           0000BD   460 _OC0COMP1	=	0x00bd
                           00BDBC   461 _OC0COMP	=	0xbdbc
                           0000B9   462 _OC0MODE	=	0x00b9
                           0000BA   463 _OC0PIN	=	0x00ba
                           0000BB   464 _OC0STATUS	=	0x00bb
                           0000C4   465 _OC1COMP0	=	0x00c4
                           0000C5   466 _OC1COMP1	=	0x00c5
                           00C5C4   467 _OC1COMP	=	0xc5c4
                           0000C1   468 _OC1MODE	=	0x00c1
                           0000C2   469 _OC1PIN	=	0x00c2
                           0000C3   470 _OC1STATUS	=	0x00c3
                           0000B1   471 _RADIOACC	=	0x00b1
                           0000B3   472 _RADIOADDR0	=	0x00b3
                           0000B2   473 _RADIOADDR1	=	0x00b2
                           00B2B3   474 _RADIOADDR	=	0xb2b3
                           0000B7   475 _RADIODATA0	=	0x00b7
                           0000B6   476 _RADIODATA1	=	0x00b6
                           0000B5   477 _RADIODATA2	=	0x00b5
                           0000B4   478 _RADIODATA3	=	0x00b4
                           B4B5B6B7   479 _RADIODATA	=	0xb4b5b6b7
                           0000BE   480 _RADIOSTAT0	=	0x00be
                           0000BF   481 _RADIOSTAT1	=	0x00bf
                           00BFBE   482 _RADIOSTAT	=	0xbfbe
                           0000DF   483 _SPCLKSRC	=	0x00df
                           0000DC   484 _SPMODE	=	0x00dc
                           0000DE   485 _SPSHREG	=	0x00de
                           0000DD   486 _SPSTATUS	=	0x00dd
                           00009A   487 _T0CLKSRC	=	0x009a
                           00009C   488 _T0CNT0	=	0x009c
                           00009D   489 _T0CNT1	=	0x009d
                           009D9C   490 _T0CNT	=	0x9d9c
                           000099   491 _T0MODE	=	0x0099
                           00009E   492 _T0PERIOD0	=	0x009e
                           00009F   493 _T0PERIOD1	=	0x009f
                           009F9E   494 _T0PERIOD	=	0x9f9e
                           00009B   495 _T0STATUS	=	0x009b
                           0000A2   496 _T1CLKSRC	=	0x00a2
                           0000A4   497 _T1CNT0	=	0x00a4
                           0000A5   498 _T1CNT1	=	0x00a5
                           00A5A4   499 _T1CNT	=	0xa5a4
                           0000A1   500 _T1MODE	=	0x00a1
                           0000A6   501 _T1PERIOD0	=	0x00a6
                           0000A7   502 _T1PERIOD1	=	0x00a7
                           00A7A6   503 _T1PERIOD	=	0xa7a6
                           0000A3   504 _T1STATUS	=	0x00a3
                           0000AA   505 _T2CLKSRC	=	0x00aa
                           0000AC   506 _T2CNT0	=	0x00ac
                           0000AD   507 _T2CNT1	=	0x00ad
                           00ADAC   508 _T2CNT	=	0xadac
                           0000A9   509 _T2MODE	=	0x00a9
                           0000AE   510 _T2PERIOD0	=	0x00ae
                           0000AF   511 _T2PERIOD1	=	0x00af
                           00AFAE   512 _T2PERIOD	=	0xafae
                           0000AB   513 _T2STATUS	=	0x00ab
                           0000E4   514 _U0CTRL	=	0x00e4
                           0000E7   515 _U0MODE	=	0x00e7
                           0000E6   516 _U0SHREG	=	0x00e6
                           0000E5   517 _U0STATUS	=	0x00e5
                           0000EC   518 _U1CTRL	=	0x00ec
                           0000EF   519 _U1MODE	=	0x00ef
                           0000EE   520 _U1SHREG	=	0x00ee
                           0000ED   521 _U1STATUS	=	0x00ed
                           0000DA   522 _WDTCFG	=	0x00da
                           0000DB   523 _WDTRESET	=	0x00db
                           0000F1   524 _WTCFGA	=	0x00f1
                           0000F9   525 _WTCFGB	=	0x00f9
                           0000F2   526 _WTCNTA0	=	0x00f2
                           0000F3   527 _WTCNTA1	=	0x00f3
                           00F3F2   528 _WTCNTA	=	0xf3f2
                           0000FA   529 _WTCNTB0	=	0x00fa
                           0000FB   530 _WTCNTB1	=	0x00fb
                           00FBFA   531 _WTCNTB	=	0xfbfa
                           0000EB   532 _WTCNTR1	=	0x00eb
                           0000F4   533 _WTEVTA0	=	0x00f4
                           0000F5   534 _WTEVTA1	=	0x00f5
                           00F5F4   535 _WTEVTA	=	0xf5f4
                           0000F6   536 _WTEVTB0	=	0x00f6
                           0000F7   537 _WTEVTB1	=	0x00f7
                           00F7F6   538 _WTEVTB	=	0xf7f6
                           0000FC   539 _WTEVTC0	=	0x00fc
                           0000FD   540 _WTEVTC1	=	0x00fd
                           00FDFC   541 _WTEVTC	=	0xfdfc
                           0000FE   542 _WTEVTD0	=	0x00fe
                           0000FF   543 _WTEVTD1	=	0x00ff
                           00FFFE   544 _WTEVTD	=	0xfffe
                           0000E9   545 _WTIRQEN	=	0x00e9
                           0000EA   546 _WTSTAT	=	0x00ea
                                    547 ;--------------------------------------------------------
                                    548 ; special function bits
                                    549 ;--------------------------------------------------------
                                    550 	.area RSEG    (ABS,DATA)
      000000                        551 	.org 0x0000
                           0000E0   552 _ACC_0	=	0x00e0
                           0000E1   553 _ACC_1	=	0x00e1
                           0000E2   554 _ACC_2	=	0x00e2
                           0000E3   555 _ACC_3	=	0x00e3
                           0000E4   556 _ACC_4	=	0x00e4
                           0000E5   557 _ACC_5	=	0x00e5
                           0000E6   558 _ACC_6	=	0x00e6
                           0000E7   559 _ACC_7	=	0x00e7
                           0000F0   560 _B_0	=	0x00f0
                           0000F1   561 _B_1	=	0x00f1
                           0000F2   562 _B_2	=	0x00f2
                           0000F3   563 _B_3	=	0x00f3
                           0000F4   564 _B_4	=	0x00f4
                           0000F5   565 _B_5	=	0x00f5
                           0000F6   566 _B_6	=	0x00f6
                           0000F7   567 _B_7	=	0x00f7
                           0000A0   568 _E2IE_0	=	0x00a0
                           0000A1   569 _E2IE_1	=	0x00a1
                           0000A2   570 _E2IE_2	=	0x00a2
                           0000A3   571 _E2IE_3	=	0x00a3
                           0000A4   572 _E2IE_4	=	0x00a4
                           0000A5   573 _E2IE_5	=	0x00a5
                           0000A6   574 _E2IE_6	=	0x00a6
                           0000A7   575 _E2IE_7	=	0x00a7
                           0000C0   576 _E2IP_0	=	0x00c0
                           0000C1   577 _E2IP_1	=	0x00c1
                           0000C2   578 _E2IP_2	=	0x00c2
                           0000C3   579 _E2IP_3	=	0x00c3
                           0000C4   580 _E2IP_4	=	0x00c4
                           0000C5   581 _E2IP_5	=	0x00c5
                           0000C6   582 _E2IP_6	=	0x00c6
                           0000C7   583 _E2IP_7	=	0x00c7
                           000098   584 _EIE_0	=	0x0098
                           000099   585 _EIE_1	=	0x0099
                           00009A   586 _EIE_2	=	0x009a
                           00009B   587 _EIE_3	=	0x009b
                           00009C   588 _EIE_4	=	0x009c
                           00009D   589 _EIE_5	=	0x009d
                           00009E   590 _EIE_6	=	0x009e
                           00009F   591 _EIE_7	=	0x009f
                           0000B0   592 _EIP_0	=	0x00b0
                           0000B1   593 _EIP_1	=	0x00b1
                           0000B2   594 _EIP_2	=	0x00b2
                           0000B3   595 _EIP_3	=	0x00b3
                           0000B4   596 _EIP_4	=	0x00b4
                           0000B5   597 _EIP_5	=	0x00b5
                           0000B6   598 _EIP_6	=	0x00b6
                           0000B7   599 _EIP_7	=	0x00b7
                           0000A8   600 _IE_0	=	0x00a8
                           0000A9   601 _IE_1	=	0x00a9
                           0000AA   602 _IE_2	=	0x00aa
                           0000AB   603 _IE_3	=	0x00ab
                           0000AC   604 _IE_4	=	0x00ac
                           0000AD   605 _IE_5	=	0x00ad
                           0000AE   606 _IE_6	=	0x00ae
                           0000AF   607 _IE_7	=	0x00af
                           0000AF   608 _EA	=	0x00af
                           0000B8   609 _IP_0	=	0x00b8
                           0000B9   610 _IP_1	=	0x00b9
                           0000BA   611 _IP_2	=	0x00ba
                           0000BB   612 _IP_3	=	0x00bb
                           0000BC   613 _IP_4	=	0x00bc
                           0000BD   614 _IP_5	=	0x00bd
                           0000BE   615 _IP_6	=	0x00be
                           0000BF   616 _IP_7	=	0x00bf
                           0000D0   617 _P	=	0x00d0
                           0000D1   618 _F1	=	0x00d1
                           0000D2   619 _OV	=	0x00d2
                           0000D3   620 _RS0	=	0x00d3
                           0000D4   621 _RS1	=	0x00d4
                           0000D5   622 _F0	=	0x00d5
                           0000D6   623 _AC	=	0x00d6
                           0000D7   624 _CY	=	0x00d7
                           0000C8   625 _PINA_0	=	0x00c8
                           0000C9   626 _PINA_1	=	0x00c9
                           0000CA   627 _PINA_2	=	0x00ca
                           0000CB   628 _PINA_3	=	0x00cb
                           0000CC   629 _PINA_4	=	0x00cc
                           0000CD   630 _PINA_5	=	0x00cd
                           0000CE   631 _PINA_6	=	0x00ce
                           0000CF   632 _PINA_7	=	0x00cf
                           0000E8   633 _PINB_0	=	0x00e8
                           0000E9   634 _PINB_1	=	0x00e9
                           0000EA   635 _PINB_2	=	0x00ea
                           0000EB   636 _PINB_3	=	0x00eb
                           0000EC   637 _PINB_4	=	0x00ec
                           0000ED   638 _PINB_5	=	0x00ed
                           0000EE   639 _PINB_6	=	0x00ee
                           0000EF   640 _PINB_7	=	0x00ef
                           0000F8   641 _PINC_0	=	0x00f8
                           0000F9   642 _PINC_1	=	0x00f9
                           0000FA   643 _PINC_2	=	0x00fa
                           0000FB   644 _PINC_3	=	0x00fb
                           0000FC   645 _PINC_4	=	0x00fc
                           0000FD   646 _PINC_5	=	0x00fd
                           0000FE   647 _PINC_6	=	0x00fe
                           0000FF   648 _PINC_7	=	0x00ff
                           000080   649 _PORTA_0	=	0x0080
                           000081   650 _PORTA_1	=	0x0081
                           000082   651 _PORTA_2	=	0x0082
                           000083   652 _PORTA_3	=	0x0083
                           000084   653 _PORTA_4	=	0x0084
                           000085   654 _PORTA_5	=	0x0085
                           000086   655 _PORTA_6	=	0x0086
                           000087   656 _PORTA_7	=	0x0087
                           000088   657 _PORTB_0	=	0x0088
                           000089   658 _PORTB_1	=	0x0089
                           00008A   659 _PORTB_2	=	0x008a
                           00008B   660 _PORTB_3	=	0x008b
                           00008C   661 _PORTB_4	=	0x008c
                           00008D   662 _PORTB_5	=	0x008d
                           00008E   663 _PORTB_6	=	0x008e
                           00008F   664 _PORTB_7	=	0x008f
                           000090   665 _PORTC_0	=	0x0090
                           000091   666 _PORTC_1	=	0x0091
                           000092   667 _PORTC_2	=	0x0092
                           000093   668 _PORTC_3	=	0x0093
                           000094   669 _PORTC_4	=	0x0094
                           000095   670 _PORTC_5	=	0x0095
                           000096   671 _PORTC_6	=	0x0096
                           000097   672 _PORTC_7	=	0x0097
                                    673 ;--------------------------------------------------------
                                    674 ; overlayable register banks
                                    675 ;--------------------------------------------------------
                                    676 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        677 	.ds 8
                                    678 ;--------------------------------------------------------
                                    679 ; internal ram data
                                    680 ;--------------------------------------------------------
                                    681 	.area DSEG    (DATA)
      00001A                        682 _pkt_counter::
      00001A                        683 	.ds 2
      00001C                        684 _coldstart::
      00001C                        685 	.ds 1
      00001D                        686 _main_saved_button_state_1_388:
      00001D                        687 	.ds 1
                                    688 ;--------------------------------------------------------
                                    689 ; overlayable items in internal ram 
                                    690 ;--------------------------------------------------------
                                    691 	.area	OSEG    (OVR,DATA)
                                    692 ;--------------------------------------------------------
                                    693 ; Stack segment in internal ram 
                                    694 ;--------------------------------------------------------
                                    695 	.area	SSEG
      000039                        696 __start__stack:
      000039                        697 	.ds	1
                                    698 
                                    699 ;--------------------------------------------------------
                                    700 ; indirectly addressable internal ram data
                                    701 ;--------------------------------------------------------
                                    702 	.area ISEG    (DATA)
                                    703 ;--------------------------------------------------------
                                    704 ; absolute internal ram data
                                    705 ;--------------------------------------------------------
                                    706 	.area IABS    (ABS,DATA)
                                    707 	.area IABS    (ABS,DATA)
                                    708 ;--------------------------------------------------------
                                    709 ; bit data
                                    710 ;--------------------------------------------------------
                                    711 	.area BSEG    (BIT)
      000001                        712 __sdcc_external_startup_sloc0_1_0:
      000001                        713 	.ds 1
                                    714 ;--------------------------------------------------------
                                    715 ; paged external ram data
                                    716 ;--------------------------------------------------------
                                    717 	.area PSEG    (PAG,XDATA)
                                    718 ;--------------------------------------------------------
                                    719 ; external ram data
                                    720 ;--------------------------------------------------------
                                    721 	.area XSEG    (XDATA)
                           007020   722 _ADCCH0VAL0	=	0x7020
                           007021   723 _ADCCH0VAL1	=	0x7021
                           007020   724 _ADCCH0VAL	=	0x7020
                           007022   725 _ADCCH1VAL0	=	0x7022
                           007023   726 _ADCCH1VAL1	=	0x7023
                           007022   727 _ADCCH1VAL	=	0x7022
                           007024   728 _ADCCH2VAL0	=	0x7024
                           007025   729 _ADCCH2VAL1	=	0x7025
                           007024   730 _ADCCH2VAL	=	0x7024
                           007026   731 _ADCCH3VAL0	=	0x7026
                           007027   732 _ADCCH3VAL1	=	0x7027
                           007026   733 _ADCCH3VAL	=	0x7026
                           007028   734 _ADCTUNE0	=	0x7028
                           007029   735 _ADCTUNE1	=	0x7029
                           00702A   736 _ADCTUNE2	=	0x702a
                           007010   737 _DMA0ADDR0	=	0x7010
                           007011   738 _DMA0ADDR1	=	0x7011
                           007010   739 _DMA0ADDR	=	0x7010
                           007014   740 _DMA0CONFIG	=	0x7014
                           007012   741 _DMA1ADDR0	=	0x7012
                           007013   742 _DMA1ADDR1	=	0x7013
                           007012   743 _DMA1ADDR	=	0x7012
                           007015   744 _DMA1CONFIG	=	0x7015
                           007070   745 _FRCOSCCONFIG	=	0x7070
                           007071   746 _FRCOSCCTRL	=	0x7071
                           007076   747 _FRCOSCFREQ0	=	0x7076
                           007077   748 _FRCOSCFREQ1	=	0x7077
                           007076   749 _FRCOSCFREQ	=	0x7076
                           007072   750 _FRCOSCKFILT0	=	0x7072
                           007073   751 _FRCOSCKFILT1	=	0x7073
                           007072   752 _FRCOSCKFILT	=	0x7072
                           007078   753 _FRCOSCPER0	=	0x7078
                           007079   754 _FRCOSCPER1	=	0x7079
                           007078   755 _FRCOSCPER	=	0x7078
                           007074   756 _FRCOSCREF0	=	0x7074
                           007075   757 _FRCOSCREF1	=	0x7075
                           007074   758 _FRCOSCREF	=	0x7074
                           007007   759 _ANALOGA	=	0x7007
                           00700C   760 _GPIOENABLE	=	0x700c
                           007003   761 _EXTIRQ	=	0x7003
                           007000   762 _INTCHGA	=	0x7000
                           007001   763 _INTCHGB	=	0x7001
                           007002   764 _INTCHGC	=	0x7002
                           007008   765 _PALTA	=	0x7008
                           007009   766 _PALTB	=	0x7009
                           00700A   767 _PALTC	=	0x700a
                           007046   768 _PALTRADIO	=	0x7046
                           007004   769 _PINCHGA	=	0x7004
                           007005   770 _PINCHGB	=	0x7005
                           007006   771 _PINCHGC	=	0x7006
                           00700B   772 _PINSEL	=	0x700b
                           007060   773 _LPOSCCONFIG	=	0x7060
                           007066   774 _LPOSCFREQ0	=	0x7066
                           007067   775 _LPOSCFREQ1	=	0x7067
                           007066   776 _LPOSCFREQ	=	0x7066
                           007062   777 _LPOSCKFILT0	=	0x7062
                           007063   778 _LPOSCKFILT1	=	0x7063
                           007062   779 _LPOSCKFILT	=	0x7062
                           007068   780 _LPOSCPER0	=	0x7068
                           007069   781 _LPOSCPER1	=	0x7069
                           007068   782 _LPOSCPER	=	0x7068
                           007064   783 _LPOSCREF0	=	0x7064
                           007065   784 _LPOSCREF1	=	0x7065
                           007064   785 _LPOSCREF	=	0x7064
                           007054   786 _LPXOSCGM	=	0x7054
                           007F01   787 _MISCCTRL	=	0x7f01
                           007053   788 _OSCCALIB	=	0x7053
                           007050   789 _OSCFORCERUN	=	0x7050
                           007052   790 _OSCREADY	=	0x7052
                           007051   791 _OSCRUN	=	0x7051
                           007040   792 _RADIOFDATAADDR0	=	0x7040
                           007041   793 _RADIOFDATAADDR1	=	0x7041
                           007040   794 _RADIOFDATAADDR	=	0x7040
                           007042   795 _RADIOFSTATADDR0	=	0x7042
                           007043   796 _RADIOFSTATADDR1	=	0x7043
                           007042   797 _RADIOFSTATADDR	=	0x7042
                           007044   798 _RADIOMUX	=	0x7044
                           007084   799 _SCRATCH0	=	0x7084
                           007085   800 _SCRATCH1	=	0x7085
                           007086   801 _SCRATCH2	=	0x7086
                           007087   802 _SCRATCH3	=	0x7087
                           007F00   803 _SILICONREV	=	0x7f00
                           007F19   804 _XTALAMPL	=	0x7f19
                           007F18   805 _XTALOSC	=	0x7f18
                           007F1A   806 _XTALREADY	=	0x7f1a
                           00FC06   807 _flash_deviceid	=	0xfc06
                           00FC00   808 _flash_calsector	=	0xfc00
      0002AD                        809 _wakeup_desc::
      0002AD                        810 	.ds 8
      0002B5                        811 _transmit_packet_demo_packet__1_340:
      0002B5                        812 	.ds 6
                                    813 ;--------------------------------------------------------
                                    814 ; absolute external ram data
                                    815 ;--------------------------------------------------------
                                    816 	.area XABS    (ABS,XDATA)
                                    817 ;--------------------------------------------------------
                                    818 ; external initialized ram data
                                    819 ;--------------------------------------------------------
                                    820 	.area XISEG   (XDATA)
                                    821 	.area HOME    (CODE)
                                    822 	.area GSINIT0 (CODE)
                                    823 	.area GSINIT1 (CODE)
                                    824 	.area GSINIT2 (CODE)
                                    825 	.area GSINIT3 (CODE)
                                    826 	.area GSINIT4 (CODE)
                                    827 	.area GSINIT5 (CODE)
                                    828 	.area GSINIT  (CODE)
                                    829 	.area GSFINAL (CODE)
                                    830 	.area CSEG    (CODE)
                                    831 ;--------------------------------------------------------
                                    832 ; interrupt vector 
                                    833 ;--------------------------------------------------------
                                    834 	.area HOME    (CODE)
      000000                        835 __interrupt_vect:
      000000 02 03 11         [24]  836 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  837 	reti
      000004                        838 	.ds	7
      00000B 02 00 B1         [24]  839 	ljmp	_wtimer_irq
      00000E                        840 	.ds	5
      000013 32               [24]  841 	reti
      000014                        842 	.ds	7
      00001B 32               [24]  843 	reti
      00001C                        844 	.ds	7
      000023 02 12 08         [24]  845 	ljmp	_axradio_isr
      000026                        846 	.ds	5
      00002B 32               [24]  847 	reti
      00002C                        848 	.ds	7
      000033 02 3B DB         [24]  849 	ljmp	_pwrmgmt_irq
      000036                        850 	.ds	5
      00003B 32               [24]  851 	reti
      00003C                        852 	.ds	7
      000043 32               [24]  853 	reti
      000044                        854 	.ds	7
      00004B 32               [24]  855 	reti
      00004C                        856 	.ds	7
      000053 32               [24]  857 	reti
      000054                        858 	.ds	7
      00005B 02 02 A3         [24]  859 	ljmp	_uart0_irq
      00005E                        860 	.ds	5
      000063 02 02 DA         [24]  861 	ljmp	_uart1_irq
      000066                        862 	.ds	5
      00006B 32               [24]  863 	reti
      00006C                        864 	.ds	7
      000073 32               [24]  865 	reti
      000074                        866 	.ds	7
      00007B 32               [24]  867 	reti
      00007C                        868 	.ds	7
      000083 32               [24]  869 	reti
      000084                        870 	.ds	7
      00008B 32               [24]  871 	reti
      00008C                        872 	.ds	7
      000093 32               [24]  873 	reti
      000094                        874 	.ds	7
      00009B 32               [24]  875 	reti
      00009C                        876 	.ds	7
      0000A3 32               [24]  877 	reti
      0000A4                        878 	.ds	7
      0000AB 02 02 6C         [24]  879 	ljmp	_dbglink_irq
                                    880 ;--------------------------------------------------------
                                    881 ; global & static initialisations
                                    882 ;--------------------------------------------------------
                                    883 	.area HOME    (CODE)
                                    884 	.area GSINIT  (CODE)
                                    885 	.area GSFINAL (CODE)
                                    886 	.area GSINIT  (CODE)
                                    887 	.globl __sdcc_gsinit_startup
                                    888 	.globl __sdcc_program_startup
                                    889 	.globl __start__stack
                                    890 	.globl __mcs51_genXINIT
                                    891 	.globl __mcs51_genXRAMCLEAR
                                    892 	.globl __mcs51_genRAMCLEAR
                                    893 ;------------------------------------------------------------
                                    894 ;Allocation info for local variables in function 'main'
                                    895 ;------------------------------------------------------------
                                    896 ;saved_button_state        Allocated with name '_main_saved_button_state_1_388'
                                    897 ;i                         Allocated to registers 
                                    898 ;flg                       Allocated to registers r7 
                                    899 ;flg                       Allocated to registers r7 
                                    900 ;------------------------------------------------------------
                                    901 ;	main.c:281: static uint8_t __data saved_button_state = 0xFF;
      00038A 75 1D FF         [24]  902 	mov	_main_saved_button_state_1_388,#0xff
                                    903 ;	main.c:66: uint16_t __data pkt_counter = 0;
      00038D E4               [12]  904 	clr	a
      00038E F5 1A            [12]  905 	mov	_pkt_counter,a
      000390 F5 1B            [12]  906 	mov	(_pkt_counter + 1),a
                                    907 ;	main.c:67: uint8_t __data coldstart = 1; /* caution: initialization with 1 is necessary! Variables are initialized upon _sdcc_external_startup returning 0 -> the coldstart value returned from _sdcc_external startup does not survive in the coldstart case */
      000392 75 1C 01         [24]  908 	mov	_coldstart,#0x01
                                    909 	.area GSFINAL (CODE)
      000395 02 00 AE         [24]  910 	ljmp	__sdcc_program_startup
                                    911 ;--------------------------------------------------------
                                    912 ; Home
                                    913 ;--------------------------------------------------------
                                    914 	.area HOME    (CODE)
                                    915 	.area HOME    (CODE)
      0000AE                        916 __sdcc_program_startup:
      0000AE 02 3D 11         [24]  917 	ljmp	_main
                                    918 ;	return from main will return to caller
                                    919 ;--------------------------------------------------------
                                    920 ; code
                                    921 ;--------------------------------------------------------
                                    922 	.area CSEG    (CODE)
                                    923 ;------------------------------------------------------------
                                    924 ;Allocation info for local variables in function 'pwrmgmt_irq'
                                    925 ;------------------------------------------------------------
                                    926 ;pc                        Allocated to registers r7 
                                    927 ;------------------------------------------------------------
                                    928 ;	main.c:74: static void pwrmgmt_irq(void) __interrupt(INT_POWERMGMT)
                                    929 ;	-----------------------------------------
                                    930 ;	 function pwrmgmt_irq
                                    931 ;	-----------------------------------------
      003BDB                        932 _pwrmgmt_irq:
                           000007   933 	ar7 = 0x07
                           000006   934 	ar6 = 0x06
                           000005   935 	ar5 = 0x05
                           000004   936 	ar4 = 0x04
                           000003   937 	ar3 = 0x03
                           000002   938 	ar2 = 0x02
                           000001   939 	ar1 = 0x01
                           000000   940 	ar0 = 0x00
      003BDB C0 E0            [24]  941 	push	acc
      003BDD C0 82            [24]  942 	push	dpl
      003BDF C0 83            [24]  943 	push	dph
      003BE1 C0 07            [24]  944 	push	ar7
      003BE3 C0 D0            [24]  945 	push	psw
      003BE5 75 D0 00         [24]  946 	mov	psw,#0x00
                                    947 ;	main.c:76: uint8_t pc = PCON;
                                    948 ;	main.c:78: if (!(pc & 0x80))
      003BE8 E5 87            [12]  949 	mov	a,_PCON
      003BEA FF               [12]  950 	mov	r7,a
      003BEB 20 E7 02         [24]  951 	jb	acc.7,00102$
                                    952 ;	main.c:79: return;
      003BEE 80 10            [24]  953 	sjmp	00106$
      003BF0                        954 00102$:
                                    955 ;	main.c:81: GPIOENABLE = 0;
      003BF0 90 70 0C         [24]  956 	mov	dptr,#_GPIOENABLE
      003BF3 E4               [12]  957 	clr	a
      003BF4 F0               [24]  958 	movx	@dptr,a
                                    959 ;	main.c:82: IE = EIE = E2IE = 0;
                                    960 ;	1-genFromRTrack replaced	mov	_E2IE,#0x00
      003BF5 F5 A0            [12]  961 	mov	_E2IE,a
                                    962 ;	1-genFromRTrack replaced	mov	_EIE,#0x00
      003BF7 F5 98            [12]  963 	mov	_EIE,a
                                    964 ;	1-genFromRTrack replaced	mov	_IE,#0x00
      003BF9 F5 A8            [12]  965 	mov	_IE,a
      003BFB                        966 00104$:
                                    967 ;	main.c:85: PCON |= 0x01;
      003BFB 43 87 01         [24]  968 	orl	_PCON,#0x01
      003BFE 80 FB            [24]  969 	sjmp	00104$
      003C00                        970 00106$:
      003C00 D0 D0            [24]  971 	pop	psw
      003C02 D0 07            [24]  972 	pop	ar7
      003C04 D0 83            [24]  973 	pop	dph
      003C06 D0 82            [24]  974 	pop	dpl
      003C08 D0 E0            [24]  975 	pop	acc
      003C0A 32               [24]  976 	reti
                                    977 ;	eliminated unneeded push/pop b
                                    978 ;------------------------------------------------------------
                                    979 ;Allocation info for local variables in function 'transmit_packet'
                                    980 ;------------------------------------------------------------
                                    981 ;demo_packet_              Allocated with name '_transmit_packet_demo_packet__1_340'
                                    982 ;------------------------------------------------------------
                                    983 ;	main.c:88: static void transmit_packet(void)
                                    984 ;	-----------------------------------------
                                    985 ;	 function transmit_packet
                                    986 ;	-----------------------------------------
      003C0B                        987 _transmit_packet:
                                    988 ;	main.c:92: ++pkt_counter;
      003C0B 05 1A            [12]  989 	inc	_pkt_counter
      003C0D E4               [12]  990 	clr	a
      003C0E B5 1A 02         [24]  991 	cjne	a,_pkt_counter,00108$
      003C11 05 1B            [12]  992 	inc	(_pkt_counter + 1)
      003C13                        993 00108$:
                                    994 ;	main.c:93: memcpy(demo_packet_, demo_packet, sizeof(demo_packet));
      003C13 75 2E 1C         [24]  995 	mov	_memcpy_PARM_2,#_demo_packet
      003C16 75 2F 4D         [24]  996 	mov	(_memcpy_PARM_2 + 1),#(_demo_packet >> 8)
      003C19 75 30 80         [24]  997 	mov	(_memcpy_PARM_2 + 2),#0x80
      003C1C 75 31 06         [24]  998 	mov	_memcpy_PARM_3,#0x06
      003C1F 75 32 00         [24]  999 	mov	(_memcpy_PARM_3 + 1),#0x00
      003C22 90 02 B5         [24] 1000 	mov	dptr,#_transmit_packet_demo_packet__1_340
      003C25 75 F0 00         [24] 1001 	mov	b,#0x00
      003C28 12 42 6F         [24] 1002 	lcall	_memcpy
                                   1003 ;	main.c:95: if (framing_insert_counter)
      003C2B 90 4D 1A         [24] 1004 	mov	dptr,#_framing_insert_counter
      003C2E E4               [12] 1005 	clr	a
      003C2F 93               [24] 1006 	movc	a,@a+dptr
      003C30 60 24            [24] 1007 	jz	00102$
                                   1008 ;	main.c:97: demo_packet_[framing_counter_pos] = pkt_counter & 0xFF ;
      003C32 90 4D 1B         [24] 1009 	mov	dptr,#_framing_counter_pos
      003C35 E4               [12] 1010 	clr	a
      003C36 93               [24] 1011 	movc	a,@a+dptr
      003C37 FF               [12] 1012 	mov	r7,a
      003C38 24 B5            [12] 1013 	add	a,#_transmit_packet_demo_packet__1_340
      003C3A F5 82            [12] 1014 	mov	dpl,a
      003C3C E4               [12] 1015 	clr	a
      003C3D 34 02            [12] 1016 	addc	a,#(_transmit_packet_demo_packet__1_340 >> 8)
      003C3F F5 83            [12] 1017 	mov	dph,a
      003C41 AD 1A            [24] 1018 	mov	r5,_pkt_counter
      003C43 7E 00            [12] 1019 	mov	r6,#0x00
      003C45 ED               [12] 1020 	mov	a,r5
      003C46 F0               [24] 1021 	movx	@dptr,a
                                   1022 ;	main.c:98: demo_packet_[framing_counter_pos+1] = (pkt_counter>>8) & 0xFF;
      003C47 EF               [12] 1023 	mov	a,r7
      003C48 04               [12] 1024 	inc	a
      003C49 24 B5            [12] 1025 	add	a,#_transmit_packet_demo_packet__1_340
      003C4B F5 82            [12] 1026 	mov	dpl,a
      003C4D E4               [12] 1027 	clr	a
      003C4E 34 02            [12] 1028 	addc	a,#(_transmit_packet_demo_packet__1_340 >> 8)
      003C50 F5 83            [12] 1029 	mov	dph,a
      003C52 E5 1B            [12] 1030 	mov	a,(_pkt_counter + 1)
      003C54 FF               [12] 1031 	mov	r7,a
      003C55 F0               [24] 1032 	movx	@dptr,a
      003C56                       1033 00102$:
                                   1034 ;	main.c:101: axradio_transmit(&remoteaddr, demo_packet_, sizeof(demo_packet));
      003C56 75 15 B5         [24] 1035 	mov	_axradio_transmit_PARM_2,#_transmit_packet_demo_packet__1_340
      003C59 75 16 02         [24] 1036 	mov	(_axradio_transmit_PARM_2 + 1),#(_transmit_packet_demo_packet__1_340 >> 8)
      003C5C 75 17 00         [24] 1037 	mov	(_axradio_transmit_PARM_2 + 2),#0x00
      003C5F 75 18 06         [24] 1038 	mov	_axradio_transmit_PARM_3,#0x06
      003C62 75 19 00         [24] 1039 	mov	(_axradio_transmit_PARM_3 + 1),#0x00
      003C65 90 4D 0B         [24] 1040 	mov	dptr,#_remoteaddr
      003C68 75 F0 80         [24] 1041 	mov	b,#0x80
      003C6B 02 35 9C         [24] 1042 	ljmp	_axradio_transmit
                                   1043 ;------------------------------------------------------------
                                   1044 ;Allocation info for local variables in function 'display_transmit_packet'
                                   1045 ;------------------------------------------------------------
                                   1046 ;	main.c:104: static void display_transmit_packet(void)
                                   1047 ;	-----------------------------------------
                                   1048 ;	 function display_transmit_packet
                                   1049 ;	-----------------------------------------
      003C6E                       1050 _display_transmit_packet:
                                   1051 ;	main.c:119: display_writehex16(pkt_counter, 4, WRNUM_PADZERO);
      003C6E 22               [24] 1052 	ret
                                   1053 ;------------------------------------------------------------
                                   1054 ;Allocation info for local variables in function 'axradio_statuschange'
                                   1055 ;------------------------------------------------------------
                                   1056 ;st                        Allocated to registers r6 r7 
                                   1057 ;------------------------------------------------------------
                                   1058 ;	main.c:131: void axradio_statuschange(struct axradio_status __xdata *st)
                                   1059 ;	-----------------------------------------
                                   1060 ;	 function axradio_statuschange
                                   1061 ;	-----------------------------------------
      003C6F                       1062 _axradio_statuschange:
                                   1063 ;	main.c:144: switch (st->status)
      003C6F AE 82            [24] 1064 	mov	r6,dpl
      003C71 AF 83            [24] 1065 	mov  r7,dph
      003C73 E0               [24] 1066 	movx	a,@dptr
      003C74 FD               [12] 1067 	mov	r5,a
      003C75 BD 02 02         [24] 1068 	cjne	r5,#0x02,00190$
      003C78 80 1A            [24] 1069 	sjmp	00159$
      003C7A                       1070 00190$:
      003C7A BD 03 02         [24] 1071 	cjne	r5,#0x03,00191$
      003C7D 80 0A            [24] 1072 	sjmp	00105$
      003C7F                       1073 00191$:
      003C7F BD 04 02         [24] 1074 	cjne	r5,#0x04,00192$
      003C82 80 0A            [24] 1075 	sjmp	00119$
      003C84                       1076 00192$:
                                   1077 ;	main.c:147: led0_on();
      003C84 BD 05 1B         [24] 1078 	cjne	r5,#0x05,00175$
      003C87 80 08            [24] 1079 	sjmp	00158$
      003C89                       1080 00105$:
      003C89 D2 89            [12] 1081 	setb	_PORTB_1
                                   1082 ;	main.c:159: display_transmit_packet();
                                   1083 ;	main.c:161: break;
                                   1084 ;	main.c:164: led0_off();
      003C8B 02 3C 6E         [24] 1085 	ljmp	_display_transmit_packet
      003C8E                       1086 00119$:
      003C8E C2 89            [12] 1087 	clr	_PORTB_1
                                   1088 ;	main.c:203: break;
                                   1089 ;	main.c:206: case AXRADIO_STAT_TRANSMITDATA:
      003C90 22               [24] 1090 	ret
      003C91                       1091 00158$:
                                   1092 ;	main.c:209: transmit_packet();
                                   1093 ;	main.c:210: break;
                                   1094 ;	main.c:213: case AXRADIO_STAT_CHANNELSTATE:
      003C91 02 3C 0B         [24] 1095 	ljmp	_transmit_packet
      003C94                       1096 00159$:
                                   1097 ;	main.c:214: if (st->u.cs.busy)
      003C94 74 06            [12] 1098 	mov	a,#0x06
      003C96 2E               [12] 1099 	add	a,r6
      003C97 FE               [12] 1100 	mov	r6,a
      003C98 E4               [12] 1101 	clr	a
      003C99 3F               [12] 1102 	addc	a,r7
      003C9A FF               [12] 1103 	mov	r7,a
      003C9B 8E 82            [24] 1104 	mov	dpl,r6
      003C9D 8F 83            [24] 1105 	mov	dph,r7
      003C9F A3               [24] 1106 	inc	dptr
      003CA0 A3               [24] 1107 	inc	dptr
      003CA1 E0               [24] 1108 	movx	a,@dptr
                                   1109 ;	main.c:223: }
      003CA2                       1110 00175$:
      003CA2 22               [24] 1111 	ret
                                   1112 ;------------------------------------------------------------
                                   1113 ;Allocation info for local variables in function 'enable_radio_interrupt_in_mcu_pin'
                                   1114 ;------------------------------------------------------------
                                   1115 ;	main.c:226: void enable_radio_interrupt_in_mcu_pin(void)
                                   1116 ;	-----------------------------------------
                                   1117 ;	 function enable_radio_interrupt_in_mcu_pin
                                   1118 ;	-----------------------------------------
      003CA3                       1119 _enable_radio_interrupt_in_mcu_pin:
                                   1120 ;	main.c:228: IE_4 = 1;
      003CA3 D2 AC            [12] 1121 	setb	_IE_4
      003CA5 22               [24] 1122 	ret
                                   1123 ;------------------------------------------------------------
                                   1124 ;Allocation info for local variables in function 'disable_radio_interrupt_in_mcu_pin'
                                   1125 ;------------------------------------------------------------
                                   1126 ;	main.c:231: void disable_radio_interrupt_in_mcu_pin(void)
                                   1127 ;	-----------------------------------------
                                   1128 ;	 function disable_radio_interrupt_in_mcu_pin
                                   1129 ;	-----------------------------------------
      003CA6                       1130 _disable_radio_interrupt_in_mcu_pin:
                                   1131 ;	main.c:233: IE_4 = 0;
      003CA6 C2 AC            [12] 1132 	clr	_IE_4
      003CA8 22               [24] 1133 	ret
                                   1134 ;------------------------------------------------------------
                                   1135 ;Allocation info for local variables in function 'wakeup_callback'
                                   1136 ;------------------------------------------------------------
                                   1137 ;desc                      Allocated to registers 
                                   1138 ;------------------------------------------------------------
                                   1139 ;	main.c:236: static void wakeup_callback(struct wtimer_desc __xdata *desc)
                                   1140 ;	-----------------------------------------
                                   1141 ;	 function wakeup_callback
                                   1142 ;	-----------------------------------------
      003CA9                       1143 _wakeup_callback:
                                   1144 ;	main.c:238: desc;
      003CA9 22               [24] 1145 	ret
                                   1146 ;------------------------------------------------------------
                                   1147 ;Allocation info for local variables in function '_sdcc_external_startup'
                                   1148 ;------------------------------------------------------------
                                   1149 ;c                         Allocated to registers 
                                   1150 ;p                         Allocated to registers 
                                   1151 ;c                         Allocated to registers 
                                   1152 ;p                         Allocated to registers 
                                   1153 ;------------------------------------------------------------
                                   1154 ;	main.c:247: uint8_t _sdcc_external_startup(void)
                                   1155 ;	-----------------------------------------
                                   1156 ;	 function _sdcc_external_startup
                                   1157 ;	-----------------------------------------
      003CAA                       1158 __sdcc_external_startup:
                                   1159 ;	main.c:249: LPXOSCGM = 0x8A;
      003CAA 90 70 54         [24] 1160 	mov	dptr,#_LPXOSCGM
      003CAD 74 8A            [12] 1161 	mov	a,#0x8a
      003CAF F0               [24] 1162 	movx	@dptr,a
                                   1163 ;	main.c:250: wtimer0_setclksrc(WTIMER0_CLKSRC, WTIMER0_PRESCALER);
      003CB0 75 82 0B         [24] 1164 	mov	dpl,#0x0b
      003CB3 12 3F 4E         [24] 1165 	lcall	_wtimer0_setconfig
                                   1166 ;	main.c:251: wtimer1_setclksrc(CLKSRC_FRCOSC, 7);
      003CB6 75 82 38         [24] 1167 	mov	dpl,#0x38
      003CB9 12 3F 68         [24] 1168 	lcall	_wtimer1_setconfig
                                   1169 ;	main.c:253: LPOSCCONFIG = 0x09; /* Slow, PRESC /1, no cal. Does NOT enable LPOSC. LPOSC is enabled upon configuring WTCFGA (MODE_TX_PERIODIC and receive_ack() ) */
      003CBC 90 70 60         [24] 1170 	mov	dptr,#_LPOSCCONFIG
      003CBF 74 09            [12] 1171 	mov	a,#0x09
      003CC1 F0               [24] 1172 	movx	@dptr,a
                                   1173 ;	main.c:255: coldstart = !(PCON & 0x40);
      003CC2 E5 87            [12] 1174 	mov	a,_PCON
      003CC4 A2 E6            [12] 1175 	mov	c,acc[6]
      003CC6 B3               [12] 1176 	cpl	c
      003CC7 92 01            [24] 1177 	mov	__sdcc_external_startup_sloc0_1_0,c
      003CC9 E4               [12] 1178 	clr	a
      003CCA 33               [12] 1179 	rlc	a
      003CCB F5 1C            [12] 1180 	mov	_coldstart,a
                                   1181 ;	main.c:257: ANALOGA = 0x18; /* PA[3,4] LPXOSC, other PA are used as digital pins */
      003CCD 90 70 07         [24] 1182 	mov	dptr,#_ANALOGA
      003CD0 74 18            [12] 1183 	mov	a,#0x18
      003CD2 F0               [24] 1184 	movx	@dptr,a
                                   1185 ;	main.c:258: PORTA = 0xE7; /* pull ups except for LPXOSC pin PA[3,4]; */
      003CD3 75 80 E7         [24] 1186 	mov	_PORTA,#0xe7
                                   1187 ;	main.c:259: PORTB = 0xFD | (PINB & 0x02); /* init LEDs to previous (frozen) state */
      003CD6 74 02            [12] 1188 	mov	a,#0x02
      003CD8 55 E8            [12] 1189 	anl	a,_PINB
      003CDA 44 FD            [12] 1190 	orl	a,#0xfd
      003CDC F5 88            [12] 1191 	mov	_PORTB,a
                                   1192 ;	main.c:260: PORTC = 0xFF;
      003CDE 75 90 FF         [24] 1193 	mov	_PORTC,#0xff
                                   1194 ;	main.c:261: PORTR = 0x0B;
      003CE1 75 8C 0B         [24] 1195 	mov	_PORTR,#0x0b
                                   1196 ;	main.c:263: DIRA = 0x00;
      003CE4 75 89 00         [24] 1197 	mov	_DIRA,#0x00
                                   1198 ;	main.c:264: DIRB = 0x0e; /*  PB1 = LED; PB2 / PB3 are outputs (in case PWRAMP / ANSTSEL are used) */
      003CE7 75 8A 0E         [24] 1199 	mov	_DIRB,#0x0e
                                   1200 ;	main.c:265: DIRC = 0x00; /*  PC4 = button */
      003CEA 75 8B 00         [24] 1201 	mov	_DIRC,#0x00
                                   1202 ;	main.c:266: DIRR = 0x15;
      003CED 75 8E 15         [24] 1203 	mov	_DIRR,#0x15
                                   1204 ;	main.c:267: axradio_setup_pincfg1();
      003CF0 12 06 D3         [24] 1205 	lcall	_axradio_setup_pincfg1
                                   1206 ;	main.c:268: DPS = 0;
      003CF3 75 86 00         [24] 1207 	mov	_DPS,#0x00
                                   1208 ;	main.c:269: IE = 0x40;
      003CF6 75 A8 40         [24] 1209 	mov	_IE,#0x40
                                   1210 ;	main.c:270: EIE = 0x00;
      003CF9 75 98 00         [24] 1211 	mov	_EIE,#0x00
                                   1212 ;	main.c:271: E2IE = 0x00;
      003CFC 75 A0 00         [24] 1213 	mov	_E2IE,#0x00
                                   1214 ;	main.c:274: GPIOENABLE = 1; /* unfreeze GPIO */
      003CFF 90 70 0C         [24] 1215 	mov	dptr,#_GPIOENABLE
      003D02 74 01            [12] 1216 	mov	a,#0x01
      003D04 F0               [24] 1217 	movx	@dptr,a
                                   1218 ;	main.c:275: return !coldstart; /* coldstart -> return 0 -> var initialization; start from sleep -> return 1 -> no var initialization */
      003D05 E5 1C            [12] 1219 	mov	a,_coldstart
      003D07 B4 01 00         [24] 1220 	cjne	a,#0x01,00111$
      003D0A                       1221 00111$:
      003D0A 92 01            [24] 1222 	mov  __sdcc_external_startup_sloc0_1_0,c
      003D0C E4               [12] 1223 	clr	a
      003D0D 33               [12] 1224 	rlc	a
      003D0E F5 82            [12] 1225 	mov	dpl,a
      003D10 22               [24] 1226 	ret
                                   1227 ;------------------------------------------------------------
                                   1228 ;Allocation info for local variables in function 'main'
                                   1229 ;------------------------------------------------------------
                                   1230 ;saved_button_state        Allocated with name '_main_saved_button_state_1_388'
                                   1231 ;i                         Allocated to registers 
                                   1232 ;flg                       Allocated to registers r7 
                                   1233 ;flg                       Allocated to registers r7 
                                   1234 ;------------------------------------------------------------
                                   1235 ;	main.c:278: int main(void)
                                   1236 ;	-----------------------------------------
                                   1237 ;	 function main
                                   1238 ;	-----------------------------------------
      003D11                       1239 _main:
                                   1240 ;	main.c:285: __endasm;
                           000000  1241 	G$_start__stack$0$0	= __start__stack
                                   1242 	.globl	G$_start__stack$0$0
                                   1243 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:368: EA = 1;
      003D11 D2 AF            [12] 1244 	setb	_EA
                                   1245 ;	main.c:290: flash_apply_calibration();
      003D13 12 45 1E         [24] 1246 	lcall	_flash_apply_calibration
                                   1247 ;	main.c:291: CLKCON = 0x00;
      003D16 75 C6 00         [24] 1248 	mov	_CLKCON,#0x00
                                   1249 ;	main.c:292: wtimer_init();
      003D19 12 40 17         [24] 1250 	lcall	_wtimer_init
                                   1251 ;	main.c:294: if (coldstart)
      003D1C E5 1C            [12] 1252 	mov	a,_coldstart
      003D1E 60 42            [24] 1253 	jz	00143$
                                   1254 ;	main.c:296: led0_off();
      003D20 C2 89            [12] 1255 	clr	_PORTB_1
                                   1256 ;	main.c:301: wakeup_desc.handler = wakeup_callback;
      003D22 90 02 AF         [24] 1257 	mov	dptr,#(_wakeup_desc + 0x0002)
      003D25 74 A9            [12] 1258 	mov	a,#_wakeup_callback
      003D27 F0               [24] 1259 	movx	@dptr,a
      003D28 74 3C            [12] 1260 	mov	a,#(_wakeup_callback >> 8)
      003D2A A3               [24] 1261 	inc	dptr
      003D2B F0               [24] 1262 	movx	@dptr,a
                                   1263 ;	main.c:307: i = axradio_init();
      003D2C 12 2A 9B         [24] 1264 	lcall	_axradio_init
      003D2F E5 82            [12] 1265 	mov	a,dpl
                                   1266 ;	main.c:309: if (i != AXRADIO_ERR_NOERROR)
      003D31 70 56            [24] 1267 	jnz	00162$
                                   1268 ;	main.c:333: axradio_set_local_address(&localaddr);
      003D33 90 4D 10         [24] 1269 	mov	dptr,#_localaddr
      003D36 75 F0 80         [24] 1270 	mov	b,#0x80
      003D39 12 35 27         [24] 1271 	lcall	_axradio_set_local_address
                                   1272 ;	main.c:334: axradio_set_default_remote_address(&remoteaddr);
      003D3C 90 4D 0B         [24] 1273 	mov	dptr,#_remoteaddr
      003D3F 75 F0 80         [24] 1274 	mov	b,#0x80
      003D42 12 35 63         [24] 1275 	lcall	_axradio_set_default_remote_address
                                   1276 ;	main.c:343: delay_ms(lpxosc_settlingtime);
      003D45 90 4D 22         [24] 1277 	mov	dptr,#_lpxosc_settlingtime
      003D48 E4               [12] 1278 	clr	a
      003D49 93               [24] 1279 	movc	a,@a+dptr
      003D4A FE               [12] 1280 	mov	r6,a
      003D4B 74 01            [12] 1281 	mov	a,#0x01
      003D4D 93               [24] 1282 	movc	a,@a+dptr
      003D4E FF               [12] 1283 	mov	r7,a
      003D4F 8E 82            [24] 1284 	mov	dpl,r6
      003D51 8F 83            [24] 1285 	mov	dph,r7
      003D53 12 3A 76         [24] 1286 	lcall	_delay_ms
                                   1287 ;	main.c:384: i = axradio_set_mode(RADIO_MODE);
      003D56 75 82 31         [24] 1288 	mov	dpl,#0x31
      003D59 12 2E 9B         [24] 1289 	lcall	_axradio_set_mode
      003D5C E5 82            [12] 1290 	mov	a,dpl
                                   1291 ;	main.c:386: if (i != AXRADIO_ERR_NOERROR)
      003D5E 60 07            [24] 1292 	jz	00144$
                                   1293 ;	main.c:387: goto terminate_radio_error;
      003D60 80 27            [24] 1294 	sjmp	00162$
      003D62                       1295 00143$:
                                   1296 ;	main.c:397: axradio_commsleepexit();
      003D62 12 3A 12         [24] 1297 	lcall	_axradio_commsleepexit
                                   1298 ;	main.c:398: IE_4 = 1; /* enable radio interrupt */
      003D65 D2 AC            [12] 1299 	setb	_IE_4
      003D67                       1300 00144$:
                                   1301 ;	main.c:401: axradio_setup_pincfg2();
      003D67 12 06 D9         [24] 1302 	lcall	_axradio_setup_pincfg2
      003D6A                       1303 00160$:
                                   1304 ;	main.c:408: wtimer_runcallbacks();
      003D6A 12 41 CF         [24] 1305 	lcall	_wtimer_runcallbacks
                                   1306 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:373: EA = 0;
      003D6D C2 AF            [12] 1307 	clr	_EA
                                   1308 ;	main.c:437: uint8_t flg = WTFLAG_CANSTANDBY;
      003D6F 7F 02            [12] 1309 	mov	r7,#0x02
                                   1310 ;	main.c:440: if (axradio_cansleep()
      003D71 C0 07            [24] 1311 	push	ar7
      003D73 12 2E 8A         [24] 1312 	lcall	_axradio_cansleep
      003D76 E5 82            [12] 1313 	mov	a,dpl
      003D78 D0 07            [24] 1314 	pop	ar7
      003D7A 60 02            [24] 1315 	jz	00146$
                                   1316 ;	main.c:445: flg |= WTFLAG_CANSLEEP;
      003D7C 7F 03            [12] 1317 	mov	r7,#0x03
      003D7E                       1318 00146$:
                                   1319 ;	main.c:447: wtimer_idle(flg);
      003D7E 8F 82            [24] 1320 	mov	dpl,r7
      003D80 12 41 4B         [24] 1321 	lcall	_wtimer_idle
                                   1322 ;	main.c:449: IE_3 = 0; /* no ISR! */
      003D83 C2 AB            [12] 1323 	clr	_IE_3
                                   1324 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:368: EA = 1;
      003D85 D2 AF            [12] 1325 	setb	_EA
                                   1326 ;	main.c:450: __enable_irq();
                                   1327 ;	main.c:458: terminate_error:
      003D87 80 E1            [24] 1328 	sjmp	00160$
      003D89                       1329 00162$:
                                   1330 ;	main.c:462: wtimer_runcallbacks();
      003D89 12 41 CF         [24] 1331 	lcall	_wtimer_runcallbacks
                                   1332 ;	main.c:464: uint8_t flg = WTFLAG_CANSTANDBY;
      003D8C 7F 02            [12] 1333 	mov	r7,#0x02
                                   1334 ;	main.c:467: if (axradio_cansleep()
      003D8E C0 07            [24] 1335 	push	ar7
      003D90 12 2E 8A         [24] 1336 	lcall	_axradio_cansleep
      003D93 E5 82            [12] 1337 	mov	a,dpl
      003D95 D0 07            [24] 1338 	pop	ar7
      003D97 60 02            [24] 1339 	jz	00154$
                                   1340 ;	main.c:472: flg |= WTFLAG_CANSLEEP;
      003D99 7F 03            [12] 1341 	mov	r7,#0x03
      003D9B                       1342 00154$:
                                   1343 ;	main.c:474: wtimer_idle(flg);
      003D9B 8F 82            [24] 1344 	mov	dpl,r7
      003D9D 12 41 4B         [24] 1345 	lcall	_wtimer_idle
      003DA0 80 E7            [24] 1346 	sjmp	00162$
                                   1347 	.area CSEG    (CODE)
                                   1348 	.area CONST   (CODE)
                                   1349 	.area XINIT   (CODE)
                                   1350 	.area CABS    (ABS,CODE)
