                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module misc
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _wtimer_remove
                                     12 	.globl _wtimer1_addrelative
                                     13 	.globl _wtimer_runcallbacks
                                     14 	.globl _wtimer_idle
                                     15 	.globl _PORTC_7
                                     16 	.globl _PORTC_6
                                     17 	.globl _PORTC_5
                                     18 	.globl _PORTC_4
                                     19 	.globl _PORTC_3
                                     20 	.globl _PORTC_2
                                     21 	.globl _PORTC_1
                                     22 	.globl _PORTC_0
                                     23 	.globl _PORTB_7
                                     24 	.globl _PORTB_6
                                     25 	.globl _PORTB_5
                                     26 	.globl _PORTB_4
                                     27 	.globl _PORTB_3
                                     28 	.globl _PORTB_2
                                     29 	.globl _PORTB_1
                                     30 	.globl _PORTB_0
                                     31 	.globl _PORTA_7
                                     32 	.globl _PORTA_6
                                     33 	.globl _PORTA_5
                                     34 	.globl _PORTA_4
                                     35 	.globl _PORTA_3
                                     36 	.globl _PORTA_2
                                     37 	.globl _PORTA_1
                                     38 	.globl _PORTA_0
                                     39 	.globl _PINC_7
                                     40 	.globl _PINC_6
                                     41 	.globl _PINC_5
                                     42 	.globl _PINC_4
                                     43 	.globl _PINC_3
                                     44 	.globl _PINC_2
                                     45 	.globl _PINC_1
                                     46 	.globl _PINC_0
                                     47 	.globl _PINB_7
                                     48 	.globl _PINB_6
                                     49 	.globl _PINB_5
                                     50 	.globl _PINB_4
                                     51 	.globl _PINB_3
                                     52 	.globl _PINB_2
                                     53 	.globl _PINB_1
                                     54 	.globl _PINB_0
                                     55 	.globl _PINA_7
                                     56 	.globl _PINA_6
                                     57 	.globl _PINA_5
                                     58 	.globl _PINA_4
                                     59 	.globl _PINA_3
                                     60 	.globl _PINA_2
                                     61 	.globl _PINA_1
                                     62 	.globl _PINA_0
                                     63 	.globl _CY
                                     64 	.globl _AC
                                     65 	.globl _F0
                                     66 	.globl _RS1
                                     67 	.globl _RS0
                                     68 	.globl _OV
                                     69 	.globl _F1
                                     70 	.globl _P
                                     71 	.globl _IP_7
                                     72 	.globl _IP_6
                                     73 	.globl _IP_5
                                     74 	.globl _IP_4
                                     75 	.globl _IP_3
                                     76 	.globl _IP_2
                                     77 	.globl _IP_1
                                     78 	.globl _IP_0
                                     79 	.globl _EA
                                     80 	.globl _IE_7
                                     81 	.globl _IE_6
                                     82 	.globl _IE_5
                                     83 	.globl _IE_4
                                     84 	.globl _IE_3
                                     85 	.globl _IE_2
                                     86 	.globl _IE_1
                                     87 	.globl _IE_0
                                     88 	.globl _EIP_7
                                     89 	.globl _EIP_6
                                     90 	.globl _EIP_5
                                     91 	.globl _EIP_4
                                     92 	.globl _EIP_3
                                     93 	.globl _EIP_2
                                     94 	.globl _EIP_1
                                     95 	.globl _EIP_0
                                     96 	.globl _EIE_7
                                     97 	.globl _EIE_6
                                     98 	.globl _EIE_5
                                     99 	.globl _EIE_4
                                    100 	.globl _EIE_3
                                    101 	.globl _EIE_2
                                    102 	.globl _EIE_1
                                    103 	.globl _EIE_0
                                    104 	.globl _E2IP_7
                                    105 	.globl _E2IP_6
                                    106 	.globl _E2IP_5
                                    107 	.globl _E2IP_4
                                    108 	.globl _E2IP_3
                                    109 	.globl _E2IP_2
                                    110 	.globl _E2IP_1
                                    111 	.globl _E2IP_0
                                    112 	.globl _E2IE_7
                                    113 	.globl _E2IE_6
                                    114 	.globl _E2IE_5
                                    115 	.globl _E2IE_4
                                    116 	.globl _E2IE_3
                                    117 	.globl _E2IE_2
                                    118 	.globl _E2IE_1
                                    119 	.globl _E2IE_0
                                    120 	.globl _B_7
                                    121 	.globl _B_6
                                    122 	.globl _B_5
                                    123 	.globl _B_4
                                    124 	.globl _B_3
                                    125 	.globl _B_2
                                    126 	.globl _B_1
                                    127 	.globl _B_0
                                    128 	.globl _ACC_7
                                    129 	.globl _ACC_6
                                    130 	.globl _ACC_5
                                    131 	.globl _ACC_4
                                    132 	.globl _ACC_3
                                    133 	.globl _ACC_2
                                    134 	.globl _ACC_1
                                    135 	.globl _ACC_0
                                    136 	.globl _WTSTAT
                                    137 	.globl _WTIRQEN
                                    138 	.globl _WTEVTD
                                    139 	.globl _WTEVTD1
                                    140 	.globl _WTEVTD0
                                    141 	.globl _WTEVTC
                                    142 	.globl _WTEVTC1
                                    143 	.globl _WTEVTC0
                                    144 	.globl _WTEVTB
                                    145 	.globl _WTEVTB1
                                    146 	.globl _WTEVTB0
                                    147 	.globl _WTEVTA
                                    148 	.globl _WTEVTA1
                                    149 	.globl _WTEVTA0
                                    150 	.globl _WTCNTR1
                                    151 	.globl _WTCNTB
                                    152 	.globl _WTCNTB1
                                    153 	.globl _WTCNTB0
                                    154 	.globl _WTCNTA
                                    155 	.globl _WTCNTA1
                                    156 	.globl _WTCNTA0
                                    157 	.globl _WTCFGB
                                    158 	.globl _WTCFGA
                                    159 	.globl _WDTRESET
                                    160 	.globl _WDTCFG
                                    161 	.globl _U1STATUS
                                    162 	.globl _U1SHREG
                                    163 	.globl _U1MODE
                                    164 	.globl _U1CTRL
                                    165 	.globl _U0STATUS
                                    166 	.globl _U0SHREG
                                    167 	.globl _U0MODE
                                    168 	.globl _U0CTRL
                                    169 	.globl _T2STATUS
                                    170 	.globl _T2PERIOD
                                    171 	.globl _T2PERIOD1
                                    172 	.globl _T2PERIOD0
                                    173 	.globl _T2MODE
                                    174 	.globl _T2CNT
                                    175 	.globl _T2CNT1
                                    176 	.globl _T2CNT0
                                    177 	.globl _T2CLKSRC
                                    178 	.globl _T1STATUS
                                    179 	.globl _T1PERIOD
                                    180 	.globl _T1PERIOD1
                                    181 	.globl _T1PERIOD0
                                    182 	.globl _T1MODE
                                    183 	.globl _T1CNT
                                    184 	.globl _T1CNT1
                                    185 	.globl _T1CNT0
                                    186 	.globl _T1CLKSRC
                                    187 	.globl _T0STATUS
                                    188 	.globl _T0PERIOD
                                    189 	.globl _T0PERIOD1
                                    190 	.globl _T0PERIOD0
                                    191 	.globl _T0MODE
                                    192 	.globl _T0CNT
                                    193 	.globl _T0CNT1
                                    194 	.globl _T0CNT0
                                    195 	.globl _T0CLKSRC
                                    196 	.globl _SPSTATUS
                                    197 	.globl _SPSHREG
                                    198 	.globl _SPMODE
                                    199 	.globl _SPCLKSRC
                                    200 	.globl _RADIOSTAT
                                    201 	.globl _RADIOSTAT1
                                    202 	.globl _RADIOSTAT0
                                    203 	.globl _RADIODATA
                                    204 	.globl _RADIODATA3
                                    205 	.globl _RADIODATA2
                                    206 	.globl _RADIODATA1
                                    207 	.globl _RADIODATA0
                                    208 	.globl _RADIOADDR
                                    209 	.globl _RADIOADDR1
                                    210 	.globl _RADIOADDR0
                                    211 	.globl _RADIOACC
                                    212 	.globl _OC1STATUS
                                    213 	.globl _OC1PIN
                                    214 	.globl _OC1MODE
                                    215 	.globl _OC1COMP
                                    216 	.globl _OC1COMP1
                                    217 	.globl _OC1COMP0
                                    218 	.globl _OC0STATUS
                                    219 	.globl _OC0PIN
                                    220 	.globl _OC0MODE
                                    221 	.globl _OC0COMP
                                    222 	.globl _OC0COMP1
                                    223 	.globl _OC0COMP0
                                    224 	.globl _NVSTATUS
                                    225 	.globl _NVKEY
                                    226 	.globl _NVDATA
                                    227 	.globl _NVDATA1
                                    228 	.globl _NVDATA0
                                    229 	.globl _NVADDR
                                    230 	.globl _NVADDR1
                                    231 	.globl _NVADDR0
                                    232 	.globl _IC1STATUS
                                    233 	.globl _IC1MODE
                                    234 	.globl _IC1CAPT
                                    235 	.globl _IC1CAPT1
                                    236 	.globl _IC1CAPT0
                                    237 	.globl _IC0STATUS
                                    238 	.globl _IC0MODE
                                    239 	.globl _IC0CAPT
                                    240 	.globl _IC0CAPT1
                                    241 	.globl _IC0CAPT0
                                    242 	.globl _PORTR
                                    243 	.globl _PORTC
                                    244 	.globl _PORTB
                                    245 	.globl _PORTA
                                    246 	.globl _PINR
                                    247 	.globl _PINC
                                    248 	.globl _PINB
                                    249 	.globl _PINA
                                    250 	.globl _DIRR
                                    251 	.globl _DIRC
                                    252 	.globl _DIRB
                                    253 	.globl _DIRA
                                    254 	.globl _DBGLNKSTAT
                                    255 	.globl _DBGLNKBUF
                                    256 	.globl _CODECONFIG
                                    257 	.globl _CLKSTAT
                                    258 	.globl _CLKCON
                                    259 	.globl _ANALOGCOMP
                                    260 	.globl _ADCCONV
                                    261 	.globl _ADCCLKSRC
                                    262 	.globl _ADCCH3CONFIG
                                    263 	.globl _ADCCH2CONFIG
                                    264 	.globl _ADCCH1CONFIG
                                    265 	.globl _ADCCH0CONFIG
                                    266 	.globl __XPAGE
                                    267 	.globl _XPAGE
                                    268 	.globl _SP
                                    269 	.globl _PSW
                                    270 	.globl _PCON
                                    271 	.globl _IP
                                    272 	.globl _IE
                                    273 	.globl _EIP
                                    274 	.globl _EIE
                                    275 	.globl _E2IP
                                    276 	.globl _E2IE
                                    277 	.globl _DPS
                                    278 	.globl _DPTR1
                                    279 	.globl _DPTR0
                                    280 	.globl _DPL1
                                    281 	.globl _DPL
                                    282 	.globl _DPH1
                                    283 	.globl _DPH
                                    284 	.globl _B
                                    285 	.globl _ACC
                                    286 	.globl _XTALREADY
                                    287 	.globl _XTALOSC
                                    288 	.globl _XTALAMPL
                                    289 	.globl _SILICONREV
                                    290 	.globl _SCRATCH3
                                    291 	.globl _SCRATCH2
                                    292 	.globl _SCRATCH1
                                    293 	.globl _SCRATCH0
                                    294 	.globl _RADIOMUX
                                    295 	.globl _RADIOFSTATADDR
                                    296 	.globl _RADIOFSTATADDR1
                                    297 	.globl _RADIOFSTATADDR0
                                    298 	.globl _RADIOFDATAADDR
                                    299 	.globl _RADIOFDATAADDR1
                                    300 	.globl _RADIOFDATAADDR0
                                    301 	.globl _OSCRUN
                                    302 	.globl _OSCREADY
                                    303 	.globl _OSCFORCERUN
                                    304 	.globl _OSCCALIB
                                    305 	.globl _MISCCTRL
                                    306 	.globl _LPXOSCGM
                                    307 	.globl _LPOSCREF
                                    308 	.globl _LPOSCREF1
                                    309 	.globl _LPOSCREF0
                                    310 	.globl _LPOSCPER
                                    311 	.globl _LPOSCPER1
                                    312 	.globl _LPOSCPER0
                                    313 	.globl _LPOSCKFILT
                                    314 	.globl _LPOSCKFILT1
                                    315 	.globl _LPOSCKFILT0
                                    316 	.globl _LPOSCFREQ
                                    317 	.globl _LPOSCFREQ1
                                    318 	.globl _LPOSCFREQ0
                                    319 	.globl _LPOSCCONFIG
                                    320 	.globl _PINSEL
                                    321 	.globl _PINCHGC
                                    322 	.globl _PINCHGB
                                    323 	.globl _PINCHGA
                                    324 	.globl _PALTRADIO
                                    325 	.globl _PALTC
                                    326 	.globl _PALTB
                                    327 	.globl _PALTA
                                    328 	.globl _INTCHGC
                                    329 	.globl _INTCHGB
                                    330 	.globl _INTCHGA
                                    331 	.globl _EXTIRQ
                                    332 	.globl _GPIOENABLE
                                    333 	.globl _ANALOGA
                                    334 	.globl _FRCOSCREF
                                    335 	.globl _FRCOSCREF1
                                    336 	.globl _FRCOSCREF0
                                    337 	.globl _FRCOSCPER
                                    338 	.globl _FRCOSCPER1
                                    339 	.globl _FRCOSCPER0
                                    340 	.globl _FRCOSCKFILT
                                    341 	.globl _FRCOSCKFILT1
                                    342 	.globl _FRCOSCKFILT0
                                    343 	.globl _FRCOSCFREQ
                                    344 	.globl _FRCOSCFREQ1
                                    345 	.globl _FRCOSCFREQ0
                                    346 	.globl _FRCOSCCTRL
                                    347 	.globl _FRCOSCCONFIG
                                    348 	.globl _DMA1CONFIG
                                    349 	.globl _DMA1ADDR
                                    350 	.globl _DMA1ADDR1
                                    351 	.globl _DMA1ADDR0
                                    352 	.globl _DMA0CONFIG
                                    353 	.globl _DMA0ADDR
                                    354 	.globl _DMA0ADDR1
                                    355 	.globl _DMA0ADDR0
                                    356 	.globl _ADCTUNE2
                                    357 	.globl _ADCTUNE1
                                    358 	.globl _ADCTUNE0
                                    359 	.globl _ADCCH3VAL
                                    360 	.globl _ADCCH3VAL1
                                    361 	.globl _ADCCH3VAL0
                                    362 	.globl _ADCCH2VAL
                                    363 	.globl _ADCCH2VAL1
                                    364 	.globl _ADCCH2VAL0
                                    365 	.globl _ADCCH1VAL
                                    366 	.globl _ADCCH1VAL1
                                    367 	.globl _ADCCH1VAL0
                                    368 	.globl _ADCCH0VAL
                                    369 	.globl _ADCCH0VAL1
                                    370 	.globl _ADCCH0VAL0
                                    371 	.globl _lcd2_display_radio_error
                                    372 	.globl _dbglink_display_radio_error
                                    373 	.globl _delay_ms
                                    374 ;--------------------------------------------------------
                                    375 ; special function registers
                                    376 ;--------------------------------------------------------
                                    377 	.area RSEG    (ABS,DATA)
      000000                        378 	.org 0x0000
                           0000E0   379 _ACC	=	0x00e0
                           0000F0   380 _B	=	0x00f0
                           000083   381 _DPH	=	0x0083
                           000085   382 _DPH1	=	0x0085
                           000082   383 _DPL	=	0x0082
                           000084   384 _DPL1	=	0x0084
                           008382   385 _DPTR0	=	0x8382
                           008584   386 _DPTR1	=	0x8584
                           000086   387 _DPS	=	0x0086
                           0000A0   388 _E2IE	=	0x00a0
                           0000C0   389 _E2IP	=	0x00c0
                           000098   390 _EIE	=	0x0098
                           0000B0   391 _EIP	=	0x00b0
                           0000A8   392 _IE	=	0x00a8
                           0000B8   393 _IP	=	0x00b8
                           000087   394 _PCON	=	0x0087
                           0000D0   395 _PSW	=	0x00d0
                           000081   396 _SP	=	0x0081
                           0000D9   397 _XPAGE	=	0x00d9
                           0000D9   398 __XPAGE	=	0x00d9
                           0000CA   399 _ADCCH0CONFIG	=	0x00ca
                           0000CB   400 _ADCCH1CONFIG	=	0x00cb
                           0000D2   401 _ADCCH2CONFIG	=	0x00d2
                           0000D3   402 _ADCCH3CONFIG	=	0x00d3
                           0000D1   403 _ADCCLKSRC	=	0x00d1
                           0000C9   404 _ADCCONV	=	0x00c9
                           0000E1   405 _ANALOGCOMP	=	0x00e1
                           0000C6   406 _CLKCON	=	0x00c6
                           0000C7   407 _CLKSTAT	=	0x00c7
                           000097   408 _CODECONFIG	=	0x0097
                           0000E3   409 _DBGLNKBUF	=	0x00e3
                           0000E2   410 _DBGLNKSTAT	=	0x00e2
                           000089   411 _DIRA	=	0x0089
                           00008A   412 _DIRB	=	0x008a
                           00008B   413 _DIRC	=	0x008b
                           00008E   414 _DIRR	=	0x008e
                           0000C8   415 _PINA	=	0x00c8
                           0000E8   416 _PINB	=	0x00e8
                           0000F8   417 _PINC	=	0x00f8
                           00008D   418 _PINR	=	0x008d
                           000080   419 _PORTA	=	0x0080
                           000088   420 _PORTB	=	0x0088
                           000090   421 _PORTC	=	0x0090
                           00008C   422 _PORTR	=	0x008c
                           0000CE   423 _IC0CAPT0	=	0x00ce
                           0000CF   424 _IC0CAPT1	=	0x00cf
                           00CFCE   425 _IC0CAPT	=	0xcfce
                           0000CC   426 _IC0MODE	=	0x00cc
                           0000CD   427 _IC0STATUS	=	0x00cd
                           0000D6   428 _IC1CAPT0	=	0x00d6
                           0000D7   429 _IC1CAPT1	=	0x00d7
                           00D7D6   430 _IC1CAPT	=	0xd7d6
                           0000D4   431 _IC1MODE	=	0x00d4
                           0000D5   432 _IC1STATUS	=	0x00d5
                           000092   433 _NVADDR0	=	0x0092
                           000093   434 _NVADDR1	=	0x0093
                           009392   435 _NVADDR	=	0x9392
                           000094   436 _NVDATA0	=	0x0094
                           000095   437 _NVDATA1	=	0x0095
                           009594   438 _NVDATA	=	0x9594
                           000096   439 _NVKEY	=	0x0096
                           000091   440 _NVSTATUS	=	0x0091
                           0000BC   441 _OC0COMP0	=	0x00bc
                           0000BD   442 _OC0COMP1	=	0x00bd
                           00BDBC   443 _OC0COMP	=	0xbdbc
                           0000B9   444 _OC0MODE	=	0x00b9
                           0000BA   445 _OC0PIN	=	0x00ba
                           0000BB   446 _OC0STATUS	=	0x00bb
                           0000C4   447 _OC1COMP0	=	0x00c4
                           0000C5   448 _OC1COMP1	=	0x00c5
                           00C5C4   449 _OC1COMP	=	0xc5c4
                           0000C1   450 _OC1MODE	=	0x00c1
                           0000C2   451 _OC1PIN	=	0x00c2
                           0000C3   452 _OC1STATUS	=	0x00c3
                           0000B1   453 _RADIOACC	=	0x00b1
                           0000B3   454 _RADIOADDR0	=	0x00b3
                           0000B2   455 _RADIOADDR1	=	0x00b2
                           00B2B3   456 _RADIOADDR	=	0xb2b3
                           0000B7   457 _RADIODATA0	=	0x00b7
                           0000B6   458 _RADIODATA1	=	0x00b6
                           0000B5   459 _RADIODATA2	=	0x00b5
                           0000B4   460 _RADIODATA3	=	0x00b4
                           B4B5B6B7   461 _RADIODATA	=	0xb4b5b6b7
                           0000BE   462 _RADIOSTAT0	=	0x00be
                           0000BF   463 _RADIOSTAT1	=	0x00bf
                           00BFBE   464 _RADIOSTAT	=	0xbfbe
                           0000DF   465 _SPCLKSRC	=	0x00df
                           0000DC   466 _SPMODE	=	0x00dc
                           0000DE   467 _SPSHREG	=	0x00de
                           0000DD   468 _SPSTATUS	=	0x00dd
                           00009A   469 _T0CLKSRC	=	0x009a
                           00009C   470 _T0CNT0	=	0x009c
                           00009D   471 _T0CNT1	=	0x009d
                           009D9C   472 _T0CNT	=	0x9d9c
                           000099   473 _T0MODE	=	0x0099
                           00009E   474 _T0PERIOD0	=	0x009e
                           00009F   475 _T0PERIOD1	=	0x009f
                           009F9E   476 _T0PERIOD	=	0x9f9e
                           00009B   477 _T0STATUS	=	0x009b
                           0000A2   478 _T1CLKSRC	=	0x00a2
                           0000A4   479 _T1CNT0	=	0x00a4
                           0000A5   480 _T1CNT1	=	0x00a5
                           00A5A4   481 _T1CNT	=	0xa5a4
                           0000A1   482 _T1MODE	=	0x00a1
                           0000A6   483 _T1PERIOD0	=	0x00a6
                           0000A7   484 _T1PERIOD1	=	0x00a7
                           00A7A6   485 _T1PERIOD	=	0xa7a6
                           0000A3   486 _T1STATUS	=	0x00a3
                           0000AA   487 _T2CLKSRC	=	0x00aa
                           0000AC   488 _T2CNT0	=	0x00ac
                           0000AD   489 _T2CNT1	=	0x00ad
                           00ADAC   490 _T2CNT	=	0xadac
                           0000A9   491 _T2MODE	=	0x00a9
                           0000AE   492 _T2PERIOD0	=	0x00ae
                           0000AF   493 _T2PERIOD1	=	0x00af
                           00AFAE   494 _T2PERIOD	=	0xafae
                           0000AB   495 _T2STATUS	=	0x00ab
                           0000E4   496 _U0CTRL	=	0x00e4
                           0000E7   497 _U0MODE	=	0x00e7
                           0000E6   498 _U0SHREG	=	0x00e6
                           0000E5   499 _U0STATUS	=	0x00e5
                           0000EC   500 _U1CTRL	=	0x00ec
                           0000EF   501 _U1MODE	=	0x00ef
                           0000EE   502 _U1SHREG	=	0x00ee
                           0000ED   503 _U1STATUS	=	0x00ed
                           0000DA   504 _WDTCFG	=	0x00da
                           0000DB   505 _WDTRESET	=	0x00db
                           0000F1   506 _WTCFGA	=	0x00f1
                           0000F9   507 _WTCFGB	=	0x00f9
                           0000F2   508 _WTCNTA0	=	0x00f2
                           0000F3   509 _WTCNTA1	=	0x00f3
                           00F3F2   510 _WTCNTA	=	0xf3f2
                           0000FA   511 _WTCNTB0	=	0x00fa
                           0000FB   512 _WTCNTB1	=	0x00fb
                           00FBFA   513 _WTCNTB	=	0xfbfa
                           0000EB   514 _WTCNTR1	=	0x00eb
                           0000F4   515 _WTEVTA0	=	0x00f4
                           0000F5   516 _WTEVTA1	=	0x00f5
                           00F5F4   517 _WTEVTA	=	0xf5f4
                           0000F6   518 _WTEVTB0	=	0x00f6
                           0000F7   519 _WTEVTB1	=	0x00f7
                           00F7F6   520 _WTEVTB	=	0xf7f6
                           0000FC   521 _WTEVTC0	=	0x00fc
                           0000FD   522 _WTEVTC1	=	0x00fd
                           00FDFC   523 _WTEVTC	=	0xfdfc
                           0000FE   524 _WTEVTD0	=	0x00fe
                           0000FF   525 _WTEVTD1	=	0x00ff
                           00FFFE   526 _WTEVTD	=	0xfffe
                           0000E9   527 _WTIRQEN	=	0x00e9
                           0000EA   528 _WTSTAT	=	0x00ea
                                    529 ;--------------------------------------------------------
                                    530 ; special function bits
                                    531 ;--------------------------------------------------------
                                    532 	.area RSEG    (ABS,DATA)
      000000                        533 	.org 0x0000
                           0000E0   534 _ACC_0	=	0x00e0
                           0000E1   535 _ACC_1	=	0x00e1
                           0000E2   536 _ACC_2	=	0x00e2
                           0000E3   537 _ACC_3	=	0x00e3
                           0000E4   538 _ACC_4	=	0x00e4
                           0000E5   539 _ACC_5	=	0x00e5
                           0000E6   540 _ACC_6	=	0x00e6
                           0000E7   541 _ACC_7	=	0x00e7
                           0000F0   542 _B_0	=	0x00f0
                           0000F1   543 _B_1	=	0x00f1
                           0000F2   544 _B_2	=	0x00f2
                           0000F3   545 _B_3	=	0x00f3
                           0000F4   546 _B_4	=	0x00f4
                           0000F5   547 _B_5	=	0x00f5
                           0000F6   548 _B_6	=	0x00f6
                           0000F7   549 _B_7	=	0x00f7
                           0000A0   550 _E2IE_0	=	0x00a0
                           0000A1   551 _E2IE_1	=	0x00a1
                           0000A2   552 _E2IE_2	=	0x00a2
                           0000A3   553 _E2IE_3	=	0x00a3
                           0000A4   554 _E2IE_4	=	0x00a4
                           0000A5   555 _E2IE_5	=	0x00a5
                           0000A6   556 _E2IE_6	=	0x00a6
                           0000A7   557 _E2IE_7	=	0x00a7
                           0000C0   558 _E2IP_0	=	0x00c0
                           0000C1   559 _E2IP_1	=	0x00c1
                           0000C2   560 _E2IP_2	=	0x00c2
                           0000C3   561 _E2IP_3	=	0x00c3
                           0000C4   562 _E2IP_4	=	0x00c4
                           0000C5   563 _E2IP_5	=	0x00c5
                           0000C6   564 _E2IP_6	=	0x00c6
                           0000C7   565 _E2IP_7	=	0x00c7
                           000098   566 _EIE_0	=	0x0098
                           000099   567 _EIE_1	=	0x0099
                           00009A   568 _EIE_2	=	0x009a
                           00009B   569 _EIE_3	=	0x009b
                           00009C   570 _EIE_4	=	0x009c
                           00009D   571 _EIE_5	=	0x009d
                           00009E   572 _EIE_6	=	0x009e
                           00009F   573 _EIE_7	=	0x009f
                           0000B0   574 _EIP_0	=	0x00b0
                           0000B1   575 _EIP_1	=	0x00b1
                           0000B2   576 _EIP_2	=	0x00b2
                           0000B3   577 _EIP_3	=	0x00b3
                           0000B4   578 _EIP_4	=	0x00b4
                           0000B5   579 _EIP_5	=	0x00b5
                           0000B6   580 _EIP_6	=	0x00b6
                           0000B7   581 _EIP_7	=	0x00b7
                           0000A8   582 _IE_0	=	0x00a8
                           0000A9   583 _IE_1	=	0x00a9
                           0000AA   584 _IE_2	=	0x00aa
                           0000AB   585 _IE_3	=	0x00ab
                           0000AC   586 _IE_4	=	0x00ac
                           0000AD   587 _IE_5	=	0x00ad
                           0000AE   588 _IE_6	=	0x00ae
                           0000AF   589 _IE_7	=	0x00af
                           0000AF   590 _EA	=	0x00af
                           0000B8   591 _IP_0	=	0x00b8
                           0000B9   592 _IP_1	=	0x00b9
                           0000BA   593 _IP_2	=	0x00ba
                           0000BB   594 _IP_3	=	0x00bb
                           0000BC   595 _IP_4	=	0x00bc
                           0000BD   596 _IP_5	=	0x00bd
                           0000BE   597 _IP_6	=	0x00be
                           0000BF   598 _IP_7	=	0x00bf
                           0000D0   599 _P	=	0x00d0
                           0000D1   600 _F1	=	0x00d1
                           0000D2   601 _OV	=	0x00d2
                           0000D3   602 _RS0	=	0x00d3
                           0000D4   603 _RS1	=	0x00d4
                           0000D5   604 _F0	=	0x00d5
                           0000D6   605 _AC	=	0x00d6
                           0000D7   606 _CY	=	0x00d7
                           0000C8   607 _PINA_0	=	0x00c8
                           0000C9   608 _PINA_1	=	0x00c9
                           0000CA   609 _PINA_2	=	0x00ca
                           0000CB   610 _PINA_3	=	0x00cb
                           0000CC   611 _PINA_4	=	0x00cc
                           0000CD   612 _PINA_5	=	0x00cd
                           0000CE   613 _PINA_6	=	0x00ce
                           0000CF   614 _PINA_7	=	0x00cf
                           0000E8   615 _PINB_0	=	0x00e8
                           0000E9   616 _PINB_1	=	0x00e9
                           0000EA   617 _PINB_2	=	0x00ea
                           0000EB   618 _PINB_3	=	0x00eb
                           0000EC   619 _PINB_4	=	0x00ec
                           0000ED   620 _PINB_5	=	0x00ed
                           0000EE   621 _PINB_6	=	0x00ee
                           0000EF   622 _PINB_7	=	0x00ef
                           0000F8   623 _PINC_0	=	0x00f8
                           0000F9   624 _PINC_1	=	0x00f9
                           0000FA   625 _PINC_2	=	0x00fa
                           0000FB   626 _PINC_3	=	0x00fb
                           0000FC   627 _PINC_4	=	0x00fc
                           0000FD   628 _PINC_5	=	0x00fd
                           0000FE   629 _PINC_6	=	0x00fe
                           0000FF   630 _PINC_7	=	0x00ff
                           000080   631 _PORTA_0	=	0x0080
                           000081   632 _PORTA_1	=	0x0081
                           000082   633 _PORTA_2	=	0x0082
                           000083   634 _PORTA_3	=	0x0083
                           000084   635 _PORTA_4	=	0x0084
                           000085   636 _PORTA_5	=	0x0085
                           000086   637 _PORTA_6	=	0x0086
                           000087   638 _PORTA_7	=	0x0087
                           000088   639 _PORTB_0	=	0x0088
                           000089   640 _PORTB_1	=	0x0089
                           00008A   641 _PORTB_2	=	0x008a
                           00008B   642 _PORTB_3	=	0x008b
                           00008C   643 _PORTB_4	=	0x008c
                           00008D   644 _PORTB_5	=	0x008d
                           00008E   645 _PORTB_6	=	0x008e
                           00008F   646 _PORTB_7	=	0x008f
                           000090   647 _PORTC_0	=	0x0090
                           000091   648 _PORTC_1	=	0x0091
                           000092   649 _PORTC_2	=	0x0092
                           000093   650 _PORTC_3	=	0x0093
                           000094   651 _PORTC_4	=	0x0094
                           000095   652 _PORTC_5	=	0x0095
                           000096   653 _PORTC_6	=	0x0096
                           000097   654 _PORTC_7	=	0x0097
                                    655 ;--------------------------------------------------------
                                    656 ; overlayable register banks
                                    657 ;--------------------------------------------------------
                                    658 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        659 	.ds 8
                                    660 ;--------------------------------------------------------
                                    661 ; internal ram data
                                    662 ;--------------------------------------------------------
                                    663 	.area DSEG    (DATA)
                                    664 ;--------------------------------------------------------
                                    665 ; overlayable items in internal ram 
                                    666 ;--------------------------------------------------------
                                    667 	.area	OSEG    (OVR,DATA)
                                    668 	.area	OSEG    (OVR,DATA)
                                    669 	.area	OSEG    (OVR,DATA)
                                    670 ;--------------------------------------------------------
                                    671 ; indirectly addressable internal ram data
                                    672 ;--------------------------------------------------------
                                    673 	.area ISEG    (DATA)
                                    674 ;--------------------------------------------------------
                                    675 ; absolute internal ram data
                                    676 ;--------------------------------------------------------
                                    677 	.area IABS    (ABS,DATA)
                                    678 	.area IABS    (ABS,DATA)
                                    679 ;--------------------------------------------------------
                                    680 ; bit data
                                    681 ;--------------------------------------------------------
                                    682 	.area BSEG    (BIT)
                                    683 ;--------------------------------------------------------
                                    684 ; paged external ram data
                                    685 ;--------------------------------------------------------
                                    686 	.area PSEG    (PAG,XDATA)
                                    687 ;--------------------------------------------------------
                                    688 ; external ram data
                                    689 ;--------------------------------------------------------
                                    690 	.area XSEG    (XDATA)
                           007020   691 _ADCCH0VAL0	=	0x7020
                           007021   692 _ADCCH0VAL1	=	0x7021
                           007020   693 _ADCCH0VAL	=	0x7020
                           007022   694 _ADCCH1VAL0	=	0x7022
                           007023   695 _ADCCH1VAL1	=	0x7023
                           007022   696 _ADCCH1VAL	=	0x7022
                           007024   697 _ADCCH2VAL0	=	0x7024
                           007025   698 _ADCCH2VAL1	=	0x7025
                           007024   699 _ADCCH2VAL	=	0x7024
                           007026   700 _ADCCH3VAL0	=	0x7026
                           007027   701 _ADCCH3VAL1	=	0x7027
                           007026   702 _ADCCH3VAL	=	0x7026
                           007028   703 _ADCTUNE0	=	0x7028
                           007029   704 _ADCTUNE1	=	0x7029
                           00702A   705 _ADCTUNE2	=	0x702a
                           007010   706 _DMA0ADDR0	=	0x7010
                           007011   707 _DMA0ADDR1	=	0x7011
                           007010   708 _DMA0ADDR	=	0x7010
                           007014   709 _DMA0CONFIG	=	0x7014
                           007012   710 _DMA1ADDR0	=	0x7012
                           007013   711 _DMA1ADDR1	=	0x7013
                           007012   712 _DMA1ADDR	=	0x7012
                           007015   713 _DMA1CONFIG	=	0x7015
                           007070   714 _FRCOSCCONFIG	=	0x7070
                           007071   715 _FRCOSCCTRL	=	0x7071
                           007076   716 _FRCOSCFREQ0	=	0x7076
                           007077   717 _FRCOSCFREQ1	=	0x7077
                           007076   718 _FRCOSCFREQ	=	0x7076
                           007072   719 _FRCOSCKFILT0	=	0x7072
                           007073   720 _FRCOSCKFILT1	=	0x7073
                           007072   721 _FRCOSCKFILT	=	0x7072
                           007078   722 _FRCOSCPER0	=	0x7078
                           007079   723 _FRCOSCPER1	=	0x7079
                           007078   724 _FRCOSCPER	=	0x7078
                           007074   725 _FRCOSCREF0	=	0x7074
                           007075   726 _FRCOSCREF1	=	0x7075
                           007074   727 _FRCOSCREF	=	0x7074
                           007007   728 _ANALOGA	=	0x7007
                           00700C   729 _GPIOENABLE	=	0x700c
                           007003   730 _EXTIRQ	=	0x7003
                           007000   731 _INTCHGA	=	0x7000
                           007001   732 _INTCHGB	=	0x7001
                           007002   733 _INTCHGC	=	0x7002
                           007008   734 _PALTA	=	0x7008
                           007009   735 _PALTB	=	0x7009
                           00700A   736 _PALTC	=	0x700a
                           007046   737 _PALTRADIO	=	0x7046
                           007004   738 _PINCHGA	=	0x7004
                           007005   739 _PINCHGB	=	0x7005
                           007006   740 _PINCHGC	=	0x7006
                           00700B   741 _PINSEL	=	0x700b
                           007060   742 _LPOSCCONFIG	=	0x7060
                           007066   743 _LPOSCFREQ0	=	0x7066
                           007067   744 _LPOSCFREQ1	=	0x7067
                           007066   745 _LPOSCFREQ	=	0x7066
                           007062   746 _LPOSCKFILT0	=	0x7062
                           007063   747 _LPOSCKFILT1	=	0x7063
                           007062   748 _LPOSCKFILT	=	0x7062
                           007068   749 _LPOSCPER0	=	0x7068
                           007069   750 _LPOSCPER1	=	0x7069
                           007068   751 _LPOSCPER	=	0x7068
                           007064   752 _LPOSCREF0	=	0x7064
                           007065   753 _LPOSCREF1	=	0x7065
                           007064   754 _LPOSCREF	=	0x7064
                           007054   755 _LPXOSCGM	=	0x7054
                           007F01   756 _MISCCTRL	=	0x7f01
                           007053   757 _OSCCALIB	=	0x7053
                           007050   758 _OSCFORCERUN	=	0x7050
                           007052   759 _OSCREADY	=	0x7052
                           007051   760 _OSCRUN	=	0x7051
                           007040   761 _RADIOFDATAADDR0	=	0x7040
                           007041   762 _RADIOFDATAADDR1	=	0x7041
                           007040   763 _RADIOFDATAADDR	=	0x7040
                           007042   764 _RADIOFSTATADDR0	=	0x7042
                           007043   765 _RADIOFSTATADDR1	=	0x7043
                           007042   766 _RADIOFSTATADDR	=	0x7042
                           007044   767 _RADIOMUX	=	0x7044
                           007084   768 _SCRATCH0	=	0x7084
                           007085   769 _SCRATCH1	=	0x7085
                           007086   770 _SCRATCH2	=	0x7086
                           007087   771 _SCRATCH3	=	0x7087
                           007F00   772 _SILICONREV	=	0x7f00
                           007F19   773 _XTALAMPL	=	0x7f19
                           007F18   774 _XTALOSC	=	0x7f18
                           007F1A   775 _XTALREADY	=	0x7f1a
                           00FC06   776 _flash_deviceid	=	0xfc06
                           00FC00   777 _flash_calsector	=	0xfc00
      0002A5                        778 _delaymstimer:
      0002A5                        779 	.ds 8
                                    780 ;--------------------------------------------------------
                                    781 ; absolute external ram data
                                    782 ;--------------------------------------------------------
                                    783 	.area XABS    (ABS,XDATA)
                                    784 ;--------------------------------------------------------
                                    785 ; external initialized ram data
                                    786 ;--------------------------------------------------------
                                    787 	.area XISEG   (XDATA)
                                    788 	.area HOME    (CODE)
                                    789 	.area GSINIT0 (CODE)
                                    790 	.area GSINIT1 (CODE)
                                    791 	.area GSINIT2 (CODE)
                                    792 	.area GSINIT3 (CODE)
                                    793 	.area GSINIT4 (CODE)
                                    794 	.area GSINIT5 (CODE)
                                    795 	.area GSINIT  (CODE)
                                    796 	.area GSFINAL (CODE)
                                    797 	.area CSEG    (CODE)
                                    798 ;--------------------------------------------------------
                                    799 ; global & static initialisations
                                    800 ;--------------------------------------------------------
                                    801 	.area HOME    (CODE)
                                    802 	.area GSINIT  (CODE)
                                    803 	.area GSFINAL (CODE)
                                    804 	.area GSINIT  (CODE)
                                    805 ;--------------------------------------------------------
                                    806 ; Home
                                    807 ;--------------------------------------------------------
                                    808 	.area HOME    (CODE)
                                    809 	.area HOME    (CODE)
                                    810 ;--------------------------------------------------------
                                    811 ; code
                                    812 ;--------------------------------------------------------
                                    813 	.area CSEG    (CODE)
                                    814 ;------------------------------------------------------------
                                    815 ;Allocation info for local variables in function 'lcd2_display_radio_error'
                                    816 ;------------------------------------------------------------
                                    817 ;err                       Allocated to registers r7 
                                    818 ;p                         Allocated to registers 
                                    819 ;------------------------------------------------------------
                                    820 ;	..\COMMON\misc.c:74: void lcd2_display_radio_error(uint8_t err)
                                    821 ;	-----------------------------------------
                                    822 ;	 function lcd2_display_radio_error
                                    823 ;	-----------------------------------------
      003A33                        824 _lcd2_display_radio_error:
                           000007   825 	ar7 = 0x07
                           000006   826 	ar6 = 0x06
                           000005   827 	ar5 = 0x05
                           000004   828 	ar4 = 0x04
                           000003   829 	ar3 = 0x03
                           000002   830 	ar2 = 0x02
                           000001   831 	ar1 = 0x01
                           000000   832 	ar0 = 0x00
      003A33 AF 82            [24]  833 	mov	r7,dpl
                                    834 ;	..\COMMON\misc.c:76: const struct errtbl __code *p = errtbl;
      003A35 7D 24            [12]  835 	mov	r5,#_errtbl
      003A37 7E 4D            [12]  836 	mov	r6,#(_errtbl >> 8)
                                    837 ;	..\COMMON\misc.c:77: do {
      003A39                        838 00107$:
                                    839 ;	..\COMMON\misc.c:78: if (p->errcode == err) {
      003A39 8D 82            [24]  840 	mov	dpl,r5
      003A3B 8E 83            [24]  841 	mov	dph,r6
      003A3D E4               [12]  842 	clr	a
      003A3E 93               [24]  843 	movc	a,@a+dptr
      003A3F FC               [12]  844 	mov	r4,a
      003A40 B5 07 01         [24]  845 	cjne	a,ar7,00106$
                                    846 ;	..\COMMON\misc.c:81: return;
      003A43 22               [24]  847 	ret
      003A44                        848 00106$:
                                    849 ;	..\COMMON\misc.c:83: ++p;
      003A44 74 03            [12]  850 	mov	a,#0x03
      003A46 2D               [12]  851 	add	a,r5
      003A47 FD               [12]  852 	mov	r5,a
      003A48 E4               [12]  853 	clr	a
      003A49 3E               [12]  854 	addc	a,r6
      003A4A FE               [12]  855 	mov	r6,a
                                    856 ;	..\COMMON\misc.c:84: } while (p->errcode != AXRADIO_ERR_NOERROR);
      003A4B 8D 82            [24]  857 	mov	dpl,r5
      003A4D 8E 83            [24]  858 	mov	dph,r6
      003A4F E4               [12]  859 	clr	a
      003A50 93               [24]  860 	movc	a,@a+dptr
      003A51 70 E6            [24]  861 	jnz	00107$
      003A53 22               [24]  862 	ret
                                    863 ;------------------------------------------------------------
                                    864 ;Allocation info for local variables in function 'dbglink_display_radio_error'
                                    865 ;------------------------------------------------------------
                                    866 ;err                       Allocated to registers 
                                    867 ;p                         Allocated to registers 
                                    868 ;------------------------------------------------------------
                                    869 ;	..\COMMON\misc.c:102: void dbglink_display_radio_error(uint8_t err)
                                    870 ;	-----------------------------------------
                                    871 ;	 function dbglink_display_radio_error
                                    872 ;	-----------------------------------------
      003A54                        873 _dbglink_display_radio_error:
                                    874 ;	..\COMMON\misc.c:104: const struct errtbl __code *p = errtbl;
                                    875 ;	..\COMMON\misc.c:105: if (!(DBGLNKSTAT & 0x10))
      003A54 E5 E2            [12]  876 	mov	a,_DBGLNKSTAT
      003A56 20 E4 01         [24]  877 	jb	acc.4,00109$
                                    878 ;	..\COMMON\misc.c:106: return;
                                    879 ;	..\COMMON\misc.c:107: do {
      003A59 22               [24]  880 	ret
      003A5A                        881 00109$:
      003A5A 7E 24            [12]  882 	mov	r6,#_errtbl
      003A5C 7F 4D            [12]  883 	mov	r7,#(_errtbl >> 8)
      003A5E                        884 00103$:
                                    885 ;	..\COMMON\misc.c:114: ++p;
      003A5E 74 03            [12]  886 	mov	a,#0x03
      003A60 2E               [12]  887 	add	a,r6
      003A61 FE               [12]  888 	mov	r6,a
      003A62 E4               [12]  889 	clr	a
      003A63 3F               [12]  890 	addc	a,r7
      003A64 FF               [12]  891 	mov	r7,a
                                    892 ;	..\COMMON\misc.c:115: } while (p->errcode != AXRADIO_ERR_NOERROR);
      003A65 8E 82            [24]  893 	mov	dpl,r6
      003A67 8F 83            [24]  894 	mov	dph,r7
      003A69 E4               [12]  895 	clr	a
      003A6A 93               [24]  896 	movc	a,@a+dptr
      003A6B 70 F1            [24]  897 	jnz	00103$
      003A6D 22               [24]  898 	ret
                                    899 ;------------------------------------------------------------
                                    900 ;Allocation info for local variables in function 'delayms_callback'
                                    901 ;------------------------------------------------------------
                                    902 ;desc                      Allocated to registers 
                                    903 ;------------------------------------------------------------
                                    904 ;	..\COMMON\misc.c:121: static void delayms_callback(struct wtimer_desc __xdata *desc)
                                    905 ;	-----------------------------------------
                                    906 ;	 function delayms_callback
                                    907 ;	-----------------------------------------
      003A6E                        908 _delayms_callback:
                                    909 ;	..\COMMON\misc.c:124: delaymstimer.handler = 0;
      003A6E 90 02 A7         [24]  910 	mov	dptr,#(_delaymstimer + 0x0002)
      003A71 E4               [12]  911 	clr	a
      003A72 F0               [24]  912 	movx	@dptr,a
      003A73 A3               [24]  913 	inc	dptr
      003A74 F0               [24]  914 	movx	@dptr,a
      003A75 22               [24]  915 	ret
                                    916 ;------------------------------------------------------------
                                    917 ;Allocation info for local variables in function 'delay_ms'
                                    918 ;------------------------------------------------------------
                                    919 ;ms                        Allocated to registers r6 r7 
                                    920 ;x                         Allocated to stack - _bp +1
                                    921 ;------------------------------------------------------------
                                    922 ;	..\COMMON\misc.c:127: __reentrantb void delay_ms(uint16_t ms) __reentrant
                                    923 ;	-----------------------------------------
                                    924 ;	 function delay_ms
                                    925 ;	-----------------------------------------
      003A76                        926 _delay_ms:
      003A76 C0 1E            [24]  927 	push	_bp
      003A78 E5 81            [12]  928 	mov	a,sp
      003A7A F5 1E            [12]  929 	mov	_bp,a
      003A7C 24 04            [12]  930 	add	a,#0x04
      003A7E F5 81            [12]  931 	mov	sp,a
      003A80 AE 82            [24]  932 	mov	r6,dpl
      003A82 AF 83            [24]  933 	mov	r7,dph
                                    934 ;	..\COMMON\misc.c:131: wtimer_remove(&delaymstimer);
      003A84 90 02 A5         [24]  935 	mov	dptr,#_delaymstimer
      003A87 C0 07            [24]  936 	push	ar7
      003A89 C0 06            [24]  937 	push	ar6
      003A8B 12 47 8D         [24]  938 	lcall	_wtimer_remove
      003A8E D0 06            [24]  939 	pop	ar6
      003A90 D0 07            [24]  940 	pop	ar7
                                    941 ;	..\COMMON\misc.c:132: x = ms;
      003A92 A8 1E            [24]  942 	mov	r0,_bp
      003A94 08               [12]  943 	inc	r0
      003A95 A6 06            [24]  944 	mov	@r0,ar6
      003A97 08               [12]  945 	inc	r0
      003A98 A6 07            [24]  946 	mov	@r0,ar7
      003A9A 08               [12]  947 	inc	r0
      003A9B 76 00            [12]  948 	mov	@r0,#0x00
      003A9D 08               [12]  949 	inc	r0
      003A9E 76 00            [12]  950 	mov	@r0,#0x00
                                    951 ;	..\COMMON\misc.c:133: delaymstimer.time = ms >> 1;
      003AA0 EF               [12]  952 	mov	a,r7
      003AA1 C3               [12]  953 	clr	c
      003AA2 13               [12]  954 	rrc	a
      003AA3 CE               [12]  955 	xch	a,r6
      003AA4 13               [12]  956 	rrc	a
      003AA5 CE               [12]  957 	xch	a,r6
      003AA6 FF               [12]  958 	mov	r7,a
      003AA7 8E 04            [24]  959 	mov	ar4,r6
      003AA9 8F 05            [24]  960 	mov	ar5,r7
      003AAB 7E 00            [12]  961 	mov	r6,#0x00
      003AAD 7F 00            [12]  962 	mov	r7,#0x00
      003AAF 90 02 A9         [24]  963 	mov	dptr,#(_delaymstimer + 0x0004)
      003AB2 EC               [12]  964 	mov	a,r4
      003AB3 F0               [24]  965 	movx	@dptr,a
      003AB4 ED               [12]  966 	mov	a,r5
      003AB5 A3               [24]  967 	inc	dptr
      003AB6 F0               [24]  968 	movx	@dptr,a
      003AB7 EE               [12]  969 	mov	a,r6
      003AB8 A3               [24]  970 	inc	dptr
      003AB9 F0               [24]  971 	movx	@dptr,a
      003ABA EF               [12]  972 	mov	a,r7
      003ABB A3               [24]  973 	inc	dptr
      003ABC F0               [24]  974 	movx	@dptr,a
                                    975 ;	..\COMMON\misc.c:134: x <<= 3;
      003ABD A8 1E            [24]  976 	mov	r0,_bp
      003ABF 08               [12]  977 	inc	r0
      003AC0 08               [12]  978 	inc	r0
      003AC1 08               [12]  979 	inc	r0
      003AC2 08               [12]  980 	inc	r0
      003AC3 E6               [12]  981 	mov	a,@r0
      003AC4 18               [12]  982 	dec	r0
      003AC5 C4               [12]  983 	swap	a
      003AC6 03               [12]  984 	rr	a
      003AC7 54 F8            [12]  985 	anl	a,#0xf8
      003AC9 C6               [12]  986 	xch	a,@r0
      003ACA C4               [12]  987 	swap	a
      003ACB 03               [12]  988 	rr	a
      003ACC C6               [12]  989 	xch	a,@r0
      003ACD 66               [12]  990 	xrl	a,@r0
      003ACE C6               [12]  991 	xch	a,@r0
      003ACF 54 F8            [12]  992 	anl	a,#0xf8
      003AD1 C6               [12]  993 	xch	a,@r0
      003AD2 66               [12]  994 	xrl	a,@r0
      003AD3 08               [12]  995 	inc	r0
      003AD4 F6               [12]  996 	mov	@r0,a
      003AD5 18               [12]  997 	dec	r0
      003AD6 18               [12]  998 	dec	r0
      003AD7 E6               [12]  999 	mov	a,@r0
      003AD8 C4               [12] 1000 	swap	a
      003AD9 03               [12] 1001 	rr	a
      003ADA 54 07            [12] 1002 	anl	a,#0x07
      003ADC 08               [12] 1003 	inc	r0
      003ADD 46               [12] 1004 	orl	a,@r0
      003ADE F6               [12] 1005 	mov	@r0,a
      003ADF 18               [12] 1006 	dec	r0
      003AE0 E6               [12] 1007 	mov	a,@r0
      003AE1 18               [12] 1008 	dec	r0
      003AE2 C4               [12] 1009 	swap	a
      003AE3 03               [12] 1010 	rr	a
      003AE4 54 F8            [12] 1011 	anl	a,#0xf8
      003AE6 C6               [12] 1012 	xch	a,@r0
      003AE7 C4               [12] 1013 	swap	a
      003AE8 03               [12] 1014 	rr	a
      003AE9 C6               [12] 1015 	xch	a,@r0
      003AEA 66               [12] 1016 	xrl	a,@r0
      003AEB C6               [12] 1017 	xch	a,@r0
      003AEC 54 F8            [12] 1018 	anl	a,#0xf8
      003AEE C6               [12] 1019 	xch	a,@r0
      003AEF 66               [12] 1020 	xrl	a,@r0
      003AF0 08               [12] 1021 	inc	r0
      003AF1 F6               [12] 1022 	mov	@r0,a
                                   1023 ;	..\COMMON\misc.c:135: delaymstimer.time -= x;
      003AF2 A8 1E            [24] 1024 	mov	r0,_bp
      003AF4 08               [12] 1025 	inc	r0
      003AF5 EC               [12] 1026 	mov	a,r4
      003AF6 C3               [12] 1027 	clr	c
      003AF7 96               [12] 1028 	subb	a,@r0
      003AF8 FC               [12] 1029 	mov	r4,a
      003AF9 ED               [12] 1030 	mov	a,r5
      003AFA 08               [12] 1031 	inc	r0
      003AFB 96               [12] 1032 	subb	a,@r0
      003AFC FD               [12] 1033 	mov	r5,a
      003AFD EE               [12] 1034 	mov	a,r6
      003AFE 08               [12] 1035 	inc	r0
      003AFF 96               [12] 1036 	subb	a,@r0
      003B00 FE               [12] 1037 	mov	r6,a
      003B01 EF               [12] 1038 	mov	a,r7
      003B02 08               [12] 1039 	inc	r0
      003B03 96               [12] 1040 	subb	a,@r0
      003B04 FF               [12] 1041 	mov	r7,a
      003B05 90 02 A9         [24] 1042 	mov	dptr,#(_delaymstimer + 0x0004)
      003B08 EC               [12] 1043 	mov	a,r4
      003B09 F0               [24] 1044 	movx	@dptr,a
      003B0A ED               [12] 1045 	mov	a,r5
      003B0B A3               [24] 1046 	inc	dptr
      003B0C F0               [24] 1047 	movx	@dptr,a
      003B0D EE               [12] 1048 	mov	a,r6
      003B0E A3               [24] 1049 	inc	dptr
      003B0F F0               [24] 1050 	movx	@dptr,a
      003B10 EF               [12] 1051 	mov	a,r7
      003B11 A3               [24] 1052 	inc	dptr
      003B12 F0               [24] 1053 	movx	@dptr,a
                                   1054 ;	..\COMMON\misc.c:136: x <<= 3;
      003B13 A8 1E            [24] 1055 	mov	r0,_bp
      003B15 08               [12] 1056 	inc	r0
      003B16 08               [12] 1057 	inc	r0
      003B17 08               [12] 1058 	inc	r0
      003B18 08               [12] 1059 	inc	r0
      003B19 E6               [12] 1060 	mov	a,@r0
      003B1A 18               [12] 1061 	dec	r0
      003B1B C4               [12] 1062 	swap	a
      003B1C 03               [12] 1063 	rr	a
      003B1D 54 F8            [12] 1064 	anl	a,#0xf8
      003B1F C6               [12] 1065 	xch	a,@r0
      003B20 C4               [12] 1066 	swap	a
      003B21 03               [12] 1067 	rr	a
      003B22 C6               [12] 1068 	xch	a,@r0
      003B23 66               [12] 1069 	xrl	a,@r0
      003B24 C6               [12] 1070 	xch	a,@r0
      003B25 54 F8            [12] 1071 	anl	a,#0xf8
      003B27 C6               [12] 1072 	xch	a,@r0
      003B28 66               [12] 1073 	xrl	a,@r0
      003B29 08               [12] 1074 	inc	r0
      003B2A F6               [12] 1075 	mov	@r0,a
      003B2B 18               [12] 1076 	dec	r0
      003B2C 18               [12] 1077 	dec	r0
      003B2D E6               [12] 1078 	mov	a,@r0
      003B2E C4               [12] 1079 	swap	a
      003B2F 03               [12] 1080 	rr	a
      003B30 54 07            [12] 1081 	anl	a,#0x07
      003B32 08               [12] 1082 	inc	r0
      003B33 46               [12] 1083 	orl	a,@r0
      003B34 F6               [12] 1084 	mov	@r0,a
      003B35 18               [12] 1085 	dec	r0
      003B36 E6               [12] 1086 	mov	a,@r0
      003B37 18               [12] 1087 	dec	r0
      003B38 C4               [12] 1088 	swap	a
      003B39 03               [12] 1089 	rr	a
      003B3A 54 F8            [12] 1090 	anl	a,#0xf8
      003B3C C6               [12] 1091 	xch	a,@r0
      003B3D C4               [12] 1092 	swap	a
      003B3E 03               [12] 1093 	rr	a
      003B3F C6               [12] 1094 	xch	a,@r0
      003B40 66               [12] 1095 	xrl	a,@r0
      003B41 C6               [12] 1096 	xch	a,@r0
      003B42 54 F8            [12] 1097 	anl	a,#0xf8
      003B44 C6               [12] 1098 	xch	a,@r0
      003B45 66               [12] 1099 	xrl	a,@r0
      003B46 08               [12] 1100 	inc	r0
      003B47 F6               [12] 1101 	mov	@r0,a
                                   1102 ;	..\COMMON\misc.c:137: delaymstimer.time += x;
      003B48 A8 1E            [24] 1103 	mov	r0,_bp
      003B4A 08               [12] 1104 	inc	r0
      003B4B E6               [12] 1105 	mov	a,@r0
      003B4C 2C               [12] 1106 	add	a,r4
      003B4D FC               [12] 1107 	mov	r4,a
      003B4E 08               [12] 1108 	inc	r0
      003B4F E6               [12] 1109 	mov	a,@r0
      003B50 3D               [12] 1110 	addc	a,r5
      003B51 FD               [12] 1111 	mov	r5,a
      003B52 08               [12] 1112 	inc	r0
      003B53 E6               [12] 1113 	mov	a,@r0
      003B54 3E               [12] 1114 	addc	a,r6
      003B55 FE               [12] 1115 	mov	r6,a
      003B56 08               [12] 1116 	inc	r0
      003B57 E6               [12] 1117 	mov	a,@r0
      003B58 3F               [12] 1118 	addc	a,r7
      003B59 FF               [12] 1119 	mov	r7,a
      003B5A 90 02 A9         [24] 1120 	mov	dptr,#(_delaymstimer + 0x0004)
      003B5D EC               [12] 1121 	mov	a,r4
      003B5E F0               [24] 1122 	movx	@dptr,a
      003B5F ED               [12] 1123 	mov	a,r5
      003B60 A3               [24] 1124 	inc	dptr
      003B61 F0               [24] 1125 	movx	@dptr,a
      003B62 EE               [12] 1126 	mov	a,r6
      003B63 A3               [24] 1127 	inc	dptr
      003B64 F0               [24] 1128 	movx	@dptr,a
      003B65 EF               [12] 1129 	mov	a,r7
      003B66 A3               [24] 1130 	inc	dptr
      003B67 F0               [24] 1131 	movx	@dptr,a
                                   1132 ;	..\COMMON\misc.c:138: x <<= 2;
      003B68 A8 1E            [24] 1133 	mov	r0,_bp
      003B6A 08               [12] 1134 	inc	r0
      003B6B E6               [12] 1135 	mov	a,@r0
      003B6C 25 E0            [12] 1136 	add	a,acc
      003B6E F6               [12] 1137 	mov	@r0,a
      003B6F 08               [12] 1138 	inc	r0
      003B70 E6               [12] 1139 	mov	a,@r0
      003B71 33               [12] 1140 	rlc	a
      003B72 F6               [12] 1141 	mov	@r0,a
      003B73 08               [12] 1142 	inc	r0
      003B74 E6               [12] 1143 	mov	a,@r0
      003B75 33               [12] 1144 	rlc	a
      003B76 F6               [12] 1145 	mov	@r0,a
      003B77 08               [12] 1146 	inc	r0
      003B78 E6               [12] 1147 	mov	a,@r0
      003B79 33               [12] 1148 	rlc	a
      003B7A F6               [12] 1149 	mov	@r0,a
      003B7B 18               [12] 1150 	dec	r0
      003B7C 18               [12] 1151 	dec	r0
      003B7D 18               [12] 1152 	dec	r0
      003B7E E6               [12] 1153 	mov	a,@r0
      003B7F 25 E0            [12] 1154 	add	a,acc
      003B81 F6               [12] 1155 	mov	@r0,a
      003B82 08               [12] 1156 	inc	r0
      003B83 E6               [12] 1157 	mov	a,@r0
      003B84 33               [12] 1158 	rlc	a
      003B85 F6               [12] 1159 	mov	@r0,a
      003B86 08               [12] 1160 	inc	r0
      003B87 E6               [12] 1161 	mov	a,@r0
      003B88 33               [12] 1162 	rlc	a
      003B89 F6               [12] 1163 	mov	@r0,a
      003B8A 08               [12] 1164 	inc	r0
      003B8B E6               [12] 1165 	mov	a,@r0
      003B8C 33               [12] 1166 	rlc	a
      003B8D F6               [12] 1167 	mov	@r0,a
                                   1168 ;	..\COMMON\misc.c:139: delaymstimer.time += x;
      003B8E A8 1E            [24] 1169 	mov	r0,_bp
      003B90 08               [12] 1170 	inc	r0
      003B91 E6               [12] 1171 	mov	a,@r0
      003B92 2C               [12] 1172 	add	a,r4
      003B93 FC               [12] 1173 	mov	r4,a
      003B94 08               [12] 1174 	inc	r0
      003B95 E6               [12] 1175 	mov	a,@r0
      003B96 3D               [12] 1176 	addc	a,r5
      003B97 FD               [12] 1177 	mov	r5,a
      003B98 08               [12] 1178 	inc	r0
      003B99 E6               [12] 1179 	mov	a,@r0
      003B9A 3E               [12] 1180 	addc	a,r6
      003B9B FE               [12] 1181 	mov	r6,a
      003B9C 08               [12] 1182 	inc	r0
      003B9D E6               [12] 1183 	mov	a,@r0
      003B9E 3F               [12] 1184 	addc	a,r7
      003B9F FF               [12] 1185 	mov	r7,a
      003BA0 90 02 A9         [24] 1186 	mov	dptr,#(_delaymstimer + 0x0004)
      003BA3 EC               [12] 1187 	mov	a,r4
      003BA4 F0               [24] 1188 	movx	@dptr,a
      003BA5 ED               [12] 1189 	mov	a,r5
      003BA6 A3               [24] 1190 	inc	dptr
      003BA7 F0               [24] 1191 	movx	@dptr,a
      003BA8 EE               [12] 1192 	mov	a,r6
      003BA9 A3               [24] 1193 	inc	dptr
      003BAA F0               [24] 1194 	movx	@dptr,a
      003BAB EF               [12] 1195 	mov	a,r7
      003BAC A3               [24] 1196 	inc	dptr
      003BAD F0               [24] 1197 	movx	@dptr,a
                                   1198 ;	..\COMMON\misc.c:140: delaymstimer.handler = delayms_callback;
      003BAE 90 02 A7         [24] 1199 	mov	dptr,#(_delaymstimer + 0x0002)
      003BB1 74 6E            [12] 1200 	mov	a,#_delayms_callback
      003BB3 F0               [24] 1201 	movx	@dptr,a
      003BB4 74 3A            [12] 1202 	mov	a,#(_delayms_callback >> 8)
      003BB6 A3               [24] 1203 	inc	dptr
      003BB7 F0               [24] 1204 	movx	@dptr,a
                                   1205 ;	..\COMMON\misc.c:141: wtimer1_addrelative(&delaymstimer);
      003BB8 90 02 A5         [24] 1206 	mov	dptr,#_delaymstimer
      003BBB 12 43 25         [24] 1207 	lcall	_wtimer1_addrelative
                                   1208 ;	..\COMMON\misc.c:142: wtimer_runcallbacks();
      003BBE 12 41 CF         [24] 1209 	lcall	_wtimer_runcallbacks
                                   1210 ;	..\COMMON\misc.c:143: do {
      003BC1                       1211 00101$:
                                   1212 ;	..\COMMON\misc.c:144: wtimer_idle(WTFLAG_CANSTANDBY);
      003BC1 75 82 02         [24] 1213 	mov	dpl,#0x02
      003BC4 12 41 4B         [24] 1214 	lcall	_wtimer_idle
                                   1215 ;	..\COMMON\misc.c:145: wtimer_runcallbacks();
      003BC7 12 41 CF         [24] 1216 	lcall	_wtimer_runcallbacks
                                   1217 ;	..\COMMON\misc.c:146: } while (delaymstimer.handler);
      003BCA 90 02 A7         [24] 1218 	mov	dptr,#(_delaymstimer + 0x0002)
      003BCD E0               [24] 1219 	movx	a,@dptr
      003BCE FE               [12] 1220 	mov	r6,a
      003BCF A3               [24] 1221 	inc	dptr
      003BD0 E0               [24] 1222 	movx	a,@dptr
      003BD1 FF               [12] 1223 	mov	r7,a
      003BD2 4E               [12] 1224 	orl	a,r6
      003BD3 70 EC            [24] 1225 	jnz	00101$
      003BD5 85 1E 81         [24] 1226 	mov	sp,_bp
      003BD8 D0 1E            [24] 1227 	pop	_bp
      003BDA 22               [24] 1228 	ret
                                   1229 	.area CSEG    (CODE)
                                   1230 	.area CONST   (CODE)
      004D24                       1231 _errtbl:
      004D24 01                    1232 	.db #0x01	; 1
      004D25 3C 4D                 1233 	.byte __str_0, (__str_0 >> 8)
      004D27 02                    1234 	.db #0x02	; 2
      004D28 4D 4D                 1235 	.byte __str_1, (__str_1 >> 8)
      004D2A 03                    1236 	.db #0x03	; 3
      004D2B 55 4D                 1237 	.byte __str_2, (__str_2 >> 8)
      004D2D 04                    1238 	.db #0x04	; 4
      004D2E 60 4D                 1239 	.byte __str_3, (__str_3 >> 8)
      004D30 05                    1240 	.db #0x05	; 5
      004D31 6B 4D                 1241 	.byte __str_4, (__str_4 >> 8)
      004D33 06                    1242 	.db #0x06	; 6
      004D34 7C 4D                 1243 	.byte __str_5, (__str_5 >> 8)
      004D36 07                    1244 	.db #0x07	; 7
      004D37 87 4D                 1245 	.byte __str_6, (__str_6 >> 8)
      004D39 00                    1246 	.db #0x00	; 0
      004D3A 00 00                 1247 	.byte #0x00,#0x00
      004D3C                       1248 __str_0:
      004D3C 45 3A 20 6E 6F 74 20  1249 	.ascii "E: not supported"
             73 75 70 70 6F 72 74
             65 64
      004D4C 00                    1250 	.db 0x00
      004D4D                       1251 __str_1:
      004D4D 45 3A 20 62 75 73 79  1252 	.ascii "E: busy"
      004D54 00                    1253 	.db 0x00
      004D55                       1254 __str_2:
      004D55 45 3A 20 74 69 6D 65  1255 	.ascii "E: timeout"
             6F 75 74
      004D5F 00                    1256 	.db 0x00
      004D60                       1257 __str_3:
      004D60 45 3A 20 69 6E 76 61  1258 	.ascii "E: invalid"
             6C 69 64
      004D6A 00                    1259 	.db 0x00
      004D6B                       1260 __str_4:
      004D6B 45 3A 20 6E 6F 20 63  1261 	.ascii "E: no chip found"
             68 69 70 20 66 6F 75
             6E 64
      004D7B 00                    1262 	.db 0x00
      004D7C                       1263 __str_5:
      004D7C 45 3A 20 72 61 6E 67  1264 	.ascii "E: ranging"
             69 6E 67
      004D86 00                    1265 	.db 0x00
      004D87                       1266 __str_6:
      004D87 45 3A 20 6C 6F 63 6B  1267 	.ascii "E: lock lost"
             20 6C 6F 73 74
      004D93 00                    1268 	.db 0x00
                                   1269 	.area XINIT   (CODE)
                                   1270 	.area CABS    (ABS,CODE)
