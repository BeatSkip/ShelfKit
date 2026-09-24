                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module configmaster
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _lpxosc_settlingtime
                                     12 	.globl _demo_packet
                                     13 	.globl _framing_counter_pos
                                     14 	.globl _framing_insert_counter
                                     15 	.globl _localaddr
                                     16 	.globl _remoteaddr
                                     17 	.globl _PORTC_7
                                     18 	.globl _PORTC_6
                                     19 	.globl _PORTC_5
                                     20 	.globl _PORTC_4
                                     21 	.globl _PORTC_3
                                     22 	.globl _PORTC_2
                                     23 	.globl _PORTC_1
                                     24 	.globl _PORTC_0
                                     25 	.globl _PORTB_7
                                     26 	.globl _PORTB_6
                                     27 	.globl _PORTB_5
                                     28 	.globl _PORTB_4
                                     29 	.globl _PORTB_3
                                     30 	.globl _PORTB_2
                                     31 	.globl _PORTB_1
                                     32 	.globl _PORTB_0
                                     33 	.globl _PORTA_7
                                     34 	.globl _PORTA_6
                                     35 	.globl _PORTA_5
                                     36 	.globl _PORTA_4
                                     37 	.globl _PORTA_3
                                     38 	.globl _PORTA_2
                                     39 	.globl _PORTA_1
                                     40 	.globl _PORTA_0
                                     41 	.globl _PINC_7
                                     42 	.globl _PINC_6
                                     43 	.globl _PINC_5
                                     44 	.globl _PINC_4
                                     45 	.globl _PINC_3
                                     46 	.globl _PINC_2
                                     47 	.globl _PINC_1
                                     48 	.globl _PINC_0
                                     49 	.globl _PINB_7
                                     50 	.globl _PINB_6
                                     51 	.globl _PINB_5
                                     52 	.globl _PINB_4
                                     53 	.globl _PINB_3
                                     54 	.globl _PINB_2
                                     55 	.globl _PINB_1
                                     56 	.globl _PINB_0
                                     57 	.globl _PINA_7
                                     58 	.globl _PINA_6
                                     59 	.globl _PINA_5
                                     60 	.globl _PINA_4
                                     61 	.globl _PINA_3
                                     62 	.globl _PINA_2
                                     63 	.globl _PINA_1
                                     64 	.globl _PINA_0
                                     65 	.globl _CY
                                     66 	.globl _AC
                                     67 	.globl _F0
                                     68 	.globl _RS1
                                     69 	.globl _RS0
                                     70 	.globl _OV
                                     71 	.globl _F1
                                     72 	.globl _P
                                     73 	.globl _IP_7
                                     74 	.globl _IP_6
                                     75 	.globl _IP_5
                                     76 	.globl _IP_4
                                     77 	.globl _IP_3
                                     78 	.globl _IP_2
                                     79 	.globl _IP_1
                                     80 	.globl _IP_0
                                     81 	.globl _EA
                                     82 	.globl _IE_7
                                     83 	.globl _IE_6
                                     84 	.globl _IE_5
                                     85 	.globl _IE_4
                                     86 	.globl _IE_3
                                     87 	.globl _IE_2
                                     88 	.globl _IE_1
                                     89 	.globl _IE_0
                                     90 	.globl _EIP_7
                                     91 	.globl _EIP_6
                                     92 	.globl _EIP_5
                                     93 	.globl _EIP_4
                                     94 	.globl _EIP_3
                                     95 	.globl _EIP_2
                                     96 	.globl _EIP_1
                                     97 	.globl _EIP_0
                                     98 	.globl _EIE_7
                                     99 	.globl _EIE_6
                                    100 	.globl _EIE_5
                                    101 	.globl _EIE_4
                                    102 	.globl _EIE_3
                                    103 	.globl _EIE_2
                                    104 	.globl _EIE_1
                                    105 	.globl _EIE_0
                                    106 	.globl _E2IP_7
                                    107 	.globl _E2IP_6
                                    108 	.globl _E2IP_5
                                    109 	.globl _E2IP_4
                                    110 	.globl _E2IP_3
                                    111 	.globl _E2IP_2
                                    112 	.globl _E2IP_1
                                    113 	.globl _E2IP_0
                                    114 	.globl _E2IE_7
                                    115 	.globl _E2IE_6
                                    116 	.globl _E2IE_5
                                    117 	.globl _E2IE_4
                                    118 	.globl _E2IE_3
                                    119 	.globl _E2IE_2
                                    120 	.globl _E2IE_1
                                    121 	.globl _E2IE_0
                                    122 	.globl _B_7
                                    123 	.globl _B_6
                                    124 	.globl _B_5
                                    125 	.globl _B_4
                                    126 	.globl _B_3
                                    127 	.globl _B_2
                                    128 	.globl _B_1
                                    129 	.globl _B_0
                                    130 	.globl _ACC_7
                                    131 	.globl _ACC_6
                                    132 	.globl _ACC_5
                                    133 	.globl _ACC_4
                                    134 	.globl _ACC_3
                                    135 	.globl _ACC_2
                                    136 	.globl _ACC_1
                                    137 	.globl _ACC_0
                                    138 	.globl _WTSTAT
                                    139 	.globl _WTIRQEN
                                    140 	.globl _WTEVTD
                                    141 	.globl _WTEVTD1
                                    142 	.globl _WTEVTD0
                                    143 	.globl _WTEVTC
                                    144 	.globl _WTEVTC1
                                    145 	.globl _WTEVTC0
                                    146 	.globl _WTEVTB
                                    147 	.globl _WTEVTB1
                                    148 	.globl _WTEVTB0
                                    149 	.globl _WTEVTA
                                    150 	.globl _WTEVTA1
                                    151 	.globl _WTEVTA0
                                    152 	.globl _WTCNTR1
                                    153 	.globl _WTCNTB
                                    154 	.globl _WTCNTB1
                                    155 	.globl _WTCNTB0
                                    156 	.globl _WTCNTA
                                    157 	.globl _WTCNTA1
                                    158 	.globl _WTCNTA0
                                    159 	.globl _WTCFGB
                                    160 	.globl _WTCFGA
                                    161 	.globl _WDTRESET
                                    162 	.globl _WDTCFG
                                    163 	.globl _U1STATUS
                                    164 	.globl _U1SHREG
                                    165 	.globl _U1MODE
                                    166 	.globl _U1CTRL
                                    167 	.globl _U0STATUS
                                    168 	.globl _U0SHREG
                                    169 	.globl _U0MODE
                                    170 	.globl _U0CTRL
                                    171 	.globl _T2STATUS
                                    172 	.globl _T2PERIOD
                                    173 	.globl _T2PERIOD1
                                    174 	.globl _T2PERIOD0
                                    175 	.globl _T2MODE
                                    176 	.globl _T2CNT
                                    177 	.globl _T2CNT1
                                    178 	.globl _T2CNT0
                                    179 	.globl _T2CLKSRC
                                    180 	.globl _T1STATUS
                                    181 	.globl _T1PERIOD
                                    182 	.globl _T1PERIOD1
                                    183 	.globl _T1PERIOD0
                                    184 	.globl _T1MODE
                                    185 	.globl _T1CNT
                                    186 	.globl _T1CNT1
                                    187 	.globl _T1CNT0
                                    188 	.globl _T1CLKSRC
                                    189 	.globl _T0STATUS
                                    190 	.globl _T0PERIOD
                                    191 	.globl _T0PERIOD1
                                    192 	.globl _T0PERIOD0
                                    193 	.globl _T0MODE
                                    194 	.globl _T0CNT
                                    195 	.globl _T0CNT1
                                    196 	.globl _T0CNT0
                                    197 	.globl _T0CLKSRC
                                    198 	.globl _SPSTATUS
                                    199 	.globl _SPSHREG
                                    200 	.globl _SPMODE
                                    201 	.globl _SPCLKSRC
                                    202 	.globl _RADIOSTAT
                                    203 	.globl _RADIOSTAT1
                                    204 	.globl _RADIOSTAT0
                                    205 	.globl _RADIODATA
                                    206 	.globl _RADIODATA3
                                    207 	.globl _RADIODATA2
                                    208 	.globl _RADIODATA1
                                    209 	.globl _RADIODATA0
                                    210 	.globl _RADIOADDR
                                    211 	.globl _RADIOADDR1
                                    212 	.globl _RADIOADDR0
                                    213 	.globl _RADIOACC
                                    214 	.globl _OC1STATUS
                                    215 	.globl _OC1PIN
                                    216 	.globl _OC1MODE
                                    217 	.globl _OC1COMP
                                    218 	.globl _OC1COMP1
                                    219 	.globl _OC1COMP0
                                    220 	.globl _OC0STATUS
                                    221 	.globl _OC0PIN
                                    222 	.globl _OC0MODE
                                    223 	.globl _OC0COMP
                                    224 	.globl _OC0COMP1
                                    225 	.globl _OC0COMP0
                                    226 	.globl _NVSTATUS
                                    227 	.globl _NVKEY
                                    228 	.globl _NVDATA
                                    229 	.globl _NVDATA1
                                    230 	.globl _NVDATA0
                                    231 	.globl _NVADDR
                                    232 	.globl _NVADDR1
                                    233 	.globl _NVADDR0
                                    234 	.globl _IC1STATUS
                                    235 	.globl _IC1MODE
                                    236 	.globl _IC1CAPT
                                    237 	.globl _IC1CAPT1
                                    238 	.globl _IC1CAPT0
                                    239 	.globl _IC0STATUS
                                    240 	.globl _IC0MODE
                                    241 	.globl _IC0CAPT
                                    242 	.globl _IC0CAPT1
                                    243 	.globl _IC0CAPT0
                                    244 	.globl _PORTR
                                    245 	.globl _PORTC
                                    246 	.globl _PORTB
                                    247 	.globl _PORTA
                                    248 	.globl _PINR
                                    249 	.globl _PINC
                                    250 	.globl _PINB
                                    251 	.globl _PINA
                                    252 	.globl _DIRR
                                    253 	.globl _DIRC
                                    254 	.globl _DIRB
                                    255 	.globl _DIRA
                                    256 	.globl _DBGLNKSTAT
                                    257 	.globl _DBGLNKBUF
                                    258 	.globl _CODECONFIG
                                    259 	.globl _CLKSTAT
                                    260 	.globl _CLKCON
                                    261 	.globl _ANALOGCOMP
                                    262 	.globl _ADCCONV
                                    263 	.globl _ADCCLKSRC
                                    264 	.globl _ADCCH3CONFIG
                                    265 	.globl _ADCCH2CONFIG
                                    266 	.globl _ADCCH1CONFIG
                                    267 	.globl _ADCCH0CONFIG
                                    268 	.globl __XPAGE
                                    269 	.globl _XPAGE
                                    270 	.globl _SP
                                    271 	.globl _PSW
                                    272 	.globl _PCON
                                    273 	.globl _IP
                                    274 	.globl _IE
                                    275 	.globl _EIP
                                    276 	.globl _EIE
                                    277 	.globl _E2IP
                                    278 	.globl _E2IE
                                    279 	.globl _DPS
                                    280 	.globl _DPTR1
                                    281 	.globl _DPTR0
                                    282 	.globl _DPL1
                                    283 	.globl _DPL
                                    284 	.globl _DPH1
                                    285 	.globl _DPH
                                    286 	.globl _B
                                    287 	.globl _ACC
                                    288 	.globl _XTALREADY
                                    289 	.globl _XTALOSC
                                    290 	.globl _XTALAMPL
                                    291 	.globl _SILICONREV
                                    292 	.globl _SCRATCH3
                                    293 	.globl _SCRATCH2
                                    294 	.globl _SCRATCH1
                                    295 	.globl _SCRATCH0
                                    296 	.globl _RADIOMUX
                                    297 	.globl _RADIOFSTATADDR
                                    298 	.globl _RADIOFSTATADDR1
                                    299 	.globl _RADIOFSTATADDR0
                                    300 	.globl _RADIOFDATAADDR
                                    301 	.globl _RADIOFDATAADDR1
                                    302 	.globl _RADIOFDATAADDR0
                                    303 	.globl _OSCRUN
                                    304 	.globl _OSCREADY
                                    305 	.globl _OSCFORCERUN
                                    306 	.globl _OSCCALIB
                                    307 	.globl _MISCCTRL
                                    308 	.globl _LPXOSCGM
                                    309 	.globl _LPOSCREF
                                    310 	.globl _LPOSCREF1
                                    311 	.globl _LPOSCREF0
                                    312 	.globl _LPOSCPER
                                    313 	.globl _LPOSCPER1
                                    314 	.globl _LPOSCPER0
                                    315 	.globl _LPOSCKFILT
                                    316 	.globl _LPOSCKFILT1
                                    317 	.globl _LPOSCKFILT0
                                    318 	.globl _LPOSCFREQ
                                    319 	.globl _LPOSCFREQ1
                                    320 	.globl _LPOSCFREQ0
                                    321 	.globl _LPOSCCONFIG
                                    322 	.globl _PINSEL
                                    323 	.globl _PINCHGC
                                    324 	.globl _PINCHGB
                                    325 	.globl _PINCHGA
                                    326 	.globl _PALTRADIO
                                    327 	.globl _PALTC
                                    328 	.globl _PALTB
                                    329 	.globl _PALTA
                                    330 	.globl _INTCHGC
                                    331 	.globl _INTCHGB
                                    332 	.globl _INTCHGA
                                    333 	.globl _EXTIRQ
                                    334 	.globl _GPIOENABLE
                                    335 	.globl _ANALOGA
                                    336 	.globl _FRCOSCREF
                                    337 	.globl _FRCOSCREF1
                                    338 	.globl _FRCOSCREF0
                                    339 	.globl _FRCOSCPER
                                    340 	.globl _FRCOSCPER1
                                    341 	.globl _FRCOSCPER0
                                    342 	.globl _FRCOSCKFILT
                                    343 	.globl _FRCOSCKFILT1
                                    344 	.globl _FRCOSCKFILT0
                                    345 	.globl _FRCOSCFREQ
                                    346 	.globl _FRCOSCFREQ1
                                    347 	.globl _FRCOSCFREQ0
                                    348 	.globl _FRCOSCCTRL
                                    349 	.globl _FRCOSCCONFIG
                                    350 	.globl _DMA1CONFIG
                                    351 	.globl _DMA1ADDR
                                    352 	.globl _DMA1ADDR1
                                    353 	.globl _DMA1ADDR0
                                    354 	.globl _DMA0CONFIG
                                    355 	.globl _DMA0ADDR
                                    356 	.globl _DMA0ADDR1
                                    357 	.globl _DMA0ADDR0
                                    358 	.globl _ADCTUNE2
                                    359 	.globl _ADCTUNE1
                                    360 	.globl _ADCTUNE0
                                    361 	.globl _ADCCH3VAL
                                    362 	.globl _ADCCH3VAL1
                                    363 	.globl _ADCCH3VAL0
                                    364 	.globl _ADCCH2VAL
                                    365 	.globl _ADCCH2VAL1
                                    366 	.globl _ADCCH2VAL0
                                    367 	.globl _ADCCH1VAL
                                    368 	.globl _ADCCH1VAL1
                                    369 	.globl _ADCCH1VAL0
                                    370 	.globl _ADCCH0VAL
                                    371 	.globl _ADCCH0VAL1
                                    372 	.globl _ADCCH0VAL0
                                    373 ;--------------------------------------------------------
                                    374 ; special function registers
                                    375 ;--------------------------------------------------------
                                    376 	.area RSEG    (ABS,DATA)
      000000                        377 	.org 0x0000
                           0000E0   378 _ACC	=	0x00e0
                           0000F0   379 _B	=	0x00f0
                           000083   380 _DPH	=	0x0083
                           000085   381 _DPH1	=	0x0085
                           000082   382 _DPL	=	0x0082
                           000084   383 _DPL1	=	0x0084
                           008382   384 _DPTR0	=	0x8382
                           008584   385 _DPTR1	=	0x8584
                           000086   386 _DPS	=	0x0086
                           0000A0   387 _E2IE	=	0x00a0
                           0000C0   388 _E2IP	=	0x00c0
                           000098   389 _EIE	=	0x0098
                           0000B0   390 _EIP	=	0x00b0
                           0000A8   391 _IE	=	0x00a8
                           0000B8   392 _IP	=	0x00b8
                           000087   393 _PCON	=	0x0087
                           0000D0   394 _PSW	=	0x00d0
                           000081   395 _SP	=	0x0081
                           0000D9   396 _XPAGE	=	0x00d9
                           0000D9   397 __XPAGE	=	0x00d9
                           0000CA   398 _ADCCH0CONFIG	=	0x00ca
                           0000CB   399 _ADCCH1CONFIG	=	0x00cb
                           0000D2   400 _ADCCH2CONFIG	=	0x00d2
                           0000D3   401 _ADCCH3CONFIG	=	0x00d3
                           0000D1   402 _ADCCLKSRC	=	0x00d1
                           0000C9   403 _ADCCONV	=	0x00c9
                           0000E1   404 _ANALOGCOMP	=	0x00e1
                           0000C6   405 _CLKCON	=	0x00c6
                           0000C7   406 _CLKSTAT	=	0x00c7
                           000097   407 _CODECONFIG	=	0x0097
                           0000E3   408 _DBGLNKBUF	=	0x00e3
                           0000E2   409 _DBGLNKSTAT	=	0x00e2
                           000089   410 _DIRA	=	0x0089
                           00008A   411 _DIRB	=	0x008a
                           00008B   412 _DIRC	=	0x008b
                           00008E   413 _DIRR	=	0x008e
                           0000C8   414 _PINA	=	0x00c8
                           0000E8   415 _PINB	=	0x00e8
                           0000F8   416 _PINC	=	0x00f8
                           00008D   417 _PINR	=	0x008d
                           000080   418 _PORTA	=	0x0080
                           000088   419 _PORTB	=	0x0088
                           000090   420 _PORTC	=	0x0090
                           00008C   421 _PORTR	=	0x008c
                           0000CE   422 _IC0CAPT0	=	0x00ce
                           0000CF   423 _IC0CAPT1	=	0x00cf
                           00CFCE   424 _IC0CAPT	=	0xcfce
                           0000CC   425 _IC0MODE	=	0x00cc
                           0000CD   426 _IC0STATUS	=	0x00cd
                           0000D6   427 _IC1CAPT0	=	0x00d6
                           0000D7   428 _IC1CAPT1	=	0x00d7
                           00D7D6   429 _IC1CAPT	=	0xd7d6
                           0000D4   430 _IC1MODE	=	0x00d4
                           0000D5   431 _IC1STATUS	=	0x00d5
                           000092   432 _NVADDR0	=	0x0092
                           000093   433 _NVADDR1	=	0x0093
                           009392   434 _NVADDR	=	0x9392
                           000094   435 _NVDATA0	=	0x0094
                           000095   436 _NVDATA1	=	0x0095
                           009594   437 _NVDATA	=	0x9594
                           000096   438 _NVKEY	=	0x0096
                           000091   439 _NVSTATUS	=	0x0091
                           0000BC   440 _OC0COMP0	=	0x00bc
                           0000BD   441 _OC0COMP1	=	0x00bd
                           00BDBC   442 _OC0COMP	=	0xbdbc
                           0000B9   443 _OC0MODE	=	0x00b9
                           0000BA   444 _OC0PIN	=	0x00ba
                           0000BB   445 _OC0STATUS	=	0x00bb
                           0000C4   446 _OC1COMP0	=	0x00c4
                           0000C5   447 _OC1COMP1	=	0x00c5
                           00C5C4   448 _OC1COMP	=	0xc5c4
                           0000C1   449 _OC1MODE	=	0x00c1
                           0000C2   450 _OC1PIN	=	0x00c2
                           0000C3   451 _OC1STATUS	=	0x00c3
                           0000B1   452 _RADIOACC	=	0x00b1
                           0000B3   453 _RADIOADDR0	=	0x00b3
                           0000B2   454 _RADIOADDR1	=	0x00b2
                           00B2B3   455 _RADIOADDR	=	0xb2b3
                           0000B7   456 _RADIODATA0	=	0x00b7
                           0000B6   457 _RADIODATA1	=	0x00b6
                           0000B5   458 _RADIODATA2	=	0x00b5
                           0000B4   459 _RADIODATA3	=	0x00b4
                           B4B5B6B7   460 _RADIODATA	=	0xb4b5b6b7
                           0000BE   461 _RADIOSTAT0	=	0x00be
                           0000BF   462 _RADIOSTAT1	=	0x00bf
                           00BFBE   463 _RADIOSTAT	=	0xbfbe
                           0000DF   464 _SPCLKSRC	=	0x00df
                           0000DC   465 _SPMODE	=	0x00dc
                           0000DE   466 _SPSHREG	=	0x00de
                           0000DD   467 _SPSTATUS	=	0x00dd
                           00009A   468 _T0CLKSRC	=	0x009a
                           00009C   469 _T0CNT0	=	0x009c
                           00009D   470 _T0CNT1	=	0x009d
                           009D9C   471 _T0CNT	=	0x9d9c
                           000099   472 _T0MODE	=	0x0099
                           00009E   473 _T0PERIOD0	=	0x009e
                           00009F   474 _T0PERIOD1	=	0x009f
                           009F9E   475 _T0PERIOD	=	0x9f9e
                           00009B   476 _T0STATUS	=	0x009b
                           0000A2   477 _T1CLKSRC	=	0x00a2
                           0000A4   478 _T1CNT0	=	0x00a4
                           0000A5   479 _T1CNT1	=	0x00a5
                           00A5A4   480 _T1CNT	=	0xa5a4
                           0000A1   481 _T1MODE	=	0x00a1
                           0000A6   482 _T1PERIOD0	=	0x00a6
                           0000A7   483 _T1PERIOD1	=	0x00a7
                           00A7A6   484 _T1PERIOD	=	0xa7a6
                           0000A3   485 _T1STATUS	=	0x00a3
                           0000AA   486 _T2CLKSRC	=	0x00aa
                           0000AC   487 _T2CNT0	=	0x00ac
                           0000AD   488 _T2CNT1	=	0x00ad
                           00ADAC   489 _T2CNT	=	0xadac
                           0000A9   490 _T2MODE	=	0x00a9
                           0000AE   491 _T2PERIOD0	=	0x00ae
                           0000AF   492 _T2PERIOD1	=	0x00af
                           00AFAE   493 _T2PERIOD	=	0xafae
                           0000AB   494 _T2STATUS	=	0x00ab
                           0000E4   495 _U0CTRL	=	0x00e4
                           0000E7   496 _U0MODE	=	0x00e7
                           0000E6   497 _U0SHREG	=	0x00e6
                           0000E5   498 _U0STATUS	=	0x00e5
                           0000EC   499 _U1CTRL	=	0x00ec
                           0000EF   500 _U1MODE	=	0x00ef
                           0000EE   501 _U1SHREG	=	0x00ee
                           0000ED   502 _U1STATUS	=	0x00ed
                           0000DA   503 _WDTCFG	=	0x00da
                           0000DB   504 _WDTRESET	=	0x00db
                           0000F1   505 _WTCFGA	=	0x00f1
                           0000F9   506 _WTCFGB	=	0x00f9
                           0000F2   507 _WTCNTA0	=	0x00f2
                           0000F3   508 _WTCNTA1	=	0x00f3
                           00F3F2   509 _WTCNTA	=	0xf3f2
                           0000FA   510 _WTCNTB0	=	0x00fa
                           0000FB   511 _WTCNTB1	=	0x00fb
                           00FBFA   512 _WTCNTB	=	0xfbfa
                           0000EB   513 _WTCNTR1	=	0x00eb
                           0000F4   514 _WTEVTA0	=	0x00f4
                           0000F5   515 _WTEVTA1	=	0x00f5
                           00F5F4   516 _WTEVTA	=	0xf5f4
                           0000F6   517 _WTEVTB0	=	0x00f6
                           0000F7   518 _WTEVTB1	=	0x00f7
                           00F7F6   519 _WTEVTB	=	0xf7f6
                           0000FC   520 _WTEVTC0	=	0x00fc
                           0000FD   521 _WTEVTC1	=	0x00fd
                           00FDFC   522 _WTEVTC	=	0xfdfc
                           0000FE   523 _WTEVTD0	=	0x00fe
                           0000FF   524 _WTEVTD1	=	0x00ff
                           00FFFE   525 _WTEVTD	=	0xfffe
                           0000E9   526 _WTIRQEN	=	0x00e9
                           0000EA   527 _WTSTAT	=	0x00ea
                                    528 ;--------------------------------------------------------
                                    529 ; special function bits
                                    530 ;--------------------------------------------------------
                                    531 	.area RSEG    (ABS,DATA)
      000000                        532 	.org 0x0000
                           0000E0   533 _ACC_0	=	0x00e0
                           0000E1   534 _ACC_1	=	0x00e1
                           0000E2   535 _ACC_2	=	0x00e2
                           0000E3   536 _ACC_3	=	0x00e3
                           0000E4   537 _ACC_4	=	0x00e4
                           0000E5   538 _ACC_5	=	0x00e5
                           0000E6   539 _ACC_6	=	0x00e6
                           0000E7   540 _ACC_7	=	0x00e7
                           0000F0   541 _B_0	=	0x00f0
                           0000F1   542 _B_1	=	0x00f1
                           0000F2   543 _B_2	=	0x00f2
                           0000F3   544 _B_3	=	0x00f3
                           0000F4   545 _B_4	=	0x00f4
                           0000F5   546 _B_5	=	0x00f5
                           0000F6   547 _B_6	=	0x00f6
                           0000F7   548 _B_7	=	0x00f7
                           0000A0   549 _E2IE_0	=	0x00a0
                           0000A1   550 _E2IE_1	=	0x00a1
                           0000A2   551 _E2IE_2	=	0x00a2
                           0000A3   552 _E2IE_3	=	0x00a3
                           0000A4   553 _E2IE_4	=	0x00a4
                           0000A5   554 _E2IE_5	=	0x00a5
                           0000A6   555 _E2IE_6	=	0x00a6
                           0000A7   556 _E2IE_7	=	0x00a7
                           0000C0   557 _E2IP_0	=	0x00c0
                           0000C1   558 _E2IP_1	=	0x00c1
                           0000C2   559 _E2IP_2	=	0x00c2
                           0000C3   560 _E2IP_3	=	0x00c3
                           0000C4   561 _E2IP_4	=	0x00c4
                           0000C5   562 _E2IP_5	=	0x00c5
                           0000C6   563 _E2IP_6	=	0x00c6
                           0000C7   564 _E2IP_7	=	0x00c7
                           000098   565 _EIE_0	=	0x0098
                           000099   566 _EIE_1	=	0x0099
                           00009A   567 _EIE_2	=	0x009a
                           00009B   568 _EIE_3	=	0x009b
                           00009C   569 _EIE_4	=	0x009c
                           00009D   570 _EIE_5	=	0x009d
                           00009E   571 _EIE_6	=	0x009e
                           00009F   572 _EIE_7	=	0x009f
                           0000B0   573 _EIP_0	=	0x00b0
                           0000B1   574 _EIP_1	=	0x00b1
                           0000B2   575 _EIP_2	=	0x00b2
                           0000B3   576 _EIP_3	=	0x00b3
                           0000B4   577 _EIP_4	=	0x00b4
                           0000B5   578 _EIP_5	=	0x00b5
                           0000B6   579 _EIP_6	=	0x00b6
                           0000B7   580 _EIP_7	=	0x00b7
                           0000A8   581 _IE_0	=	0x00a8
                           0000A9   582 _IE_1	=	0x00a9
                           0000AA   583 _IE_2	=	0x00aa
                           0000AB   584 _IE_3	=	0x00ab
                           0000AC   585 _IE_4	=	0x00ac
                           0000AD   586 _IE_5	=	0x00ad
                           0000AE   587 _IE_6	=	0x00ae
                           0000AF   588 _IE_7	=	0x00af
                           0000AF   589 _EA	=	0x00af
                           0000B8   590 _IP_0	=	0x00b8
                           0000B9   591 _IP_1	=	0x00b9
                           0000BA   592 _IP_2	=	0x00ba
                           0000BB   593 _IP_3	=	0x00bb
                           0000BC   594 _IP_4	=	0x00bc
                           0000BD   595 _IP_5	=	0x00bd
                           0000BE   596 _IP_6	=	0x00be
                           0000BF   597 _IP_7	=	0x00bf
                           0000D0   598 _P	=	0x00d0
                           0000D1   599 _F1	=	0x00d1
                           0000D2   600 _OV	=	0x00d2
                           0000D3   601 _RS0	=	0x00d3
                           0000D4   602 _RS1	=	0x00d4
                           0000D5   603 _F0	=	0x00d5
                           0000D6   604 _AC	=	0x00d6
                           0000D7   605 _CY	=	0x00d7
                           0000C8   606 _PINA_0	=	0x00c8
                           0000C9   607 _PINA_1	=	0x00c9
                           0000CA   608 _PINA_2	=	0x00ca
                           0000CB   609 _PINA_3	=	0x00cb
                           0000CC   610 _PINA_4	=	0x00cc
                           0000CD   611 _PINA_5	=	0x00cd
                           0000CE   612 _PINA_6	=	0x00ce
                           0000CF   613 _PINA_7	=	0x00cf
                           0000E8   614 _PINB_0	=	0x00e8
                           0000E9   615 _PINB_1	=	0x00e9
                           0000EA   616 _PINB_2	=	0x00ea
                           0000EB   617 _PINB_3	=	0x00eb
                           0000EC   618 _PINB_4	=	0x00ec
                           0000ED   619 _PINB_5	=	0x00ed
                           0000EE   620 _PINB_6	=	0x00ee
                           0000EF   621 _PINB_7	=	0x00ef
                           0000F8   622 _PINC_0	=	0x00f8
                           0000F9   623 _PINC_1	=	0x00f9
                           0000FA   624 _PINC_2	=	0x00fa
                           0000FB   625 _PINC_3	=	0x00fb
                           0000FC   626 _PINC_4	=	0x00fc
                           0000FD   627 _PINC_5	=	0x00fd
                           0000FE   628 _PINC_6	=	0x00fe
                           0000FF   629 _PINC_7	=	0x00ff
                           000080   630 _PORTA_0	=	0x0080
                           000081   631 _PORTA_1	=	0x0081
                           000082   632 _PORTA_2	=	0x0082
                           000083   633 _PORTA_3	=	0x0083
                           000084   634 _PORTA_4	=	0x0084
                           000085   635 _PORTA_5	=	0x0085
                           000086   636 _PORTA_6	=	0x0086
                           000087   637 _PORTA_7	=	0x0087
                           000088   638 _PORTB_0	=	0x0088
                           000089   639 _PORTB_1	=	0x0089
                           00008A   640 _PORTB_2	=	0x008a
                           00008B   641 _PORTB_3	=	0x008b
                           00008C   642 _PORTB_4	=	0x008c
                           00008D   643 _PORTB_5	=	0x008d
                           00008E   644 _PORTB_6	=	0x008e
                           00008F   645 _PORTB_7	=	0x008f
                           000090   646 _PORTC_0	=	0x0090
                           000091   647 _PORTC_1	=	0x0091
                           000092   648 _PORTC_2	=	0x0092
                           000093   649 _PORTC_3	=	0x0093
                           000094   650 _PORTC_4	=	0x0094
                           000095   651 _PORTC_5	=	0x0095
                           000096   652 _PORTC_6	=	0x0096
                           000097   653 _PORTC_7	=	0x0097
                                    654 ;--------------------------------------------------------
                                    655 ; overlayable register banks
                                    656 ;--------------------------------------------------------
                                    657 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        658 	.ds 8
                                    659 ;--------------------------------------------------------
                                    660 ; internal ram data
                                    661 ;--------------------------------------------------------
                                    662 	.area DSEG    (DATA)
                                    663 ;--------------------------------------------------------
                                    664 ; overlayable items in internal ram 
                                    665 ;--------------------------------------------------------
                                    666 ;--------------------------------------------------------
                                    667 ; indirectly addressable internal ram data
                                    668 ;--------------------------------------------------------
                                    669 	.area ISEG    (DATA)
                                    670 ;--------------------------------------------------------
                                    671 ; absolute internal ram data
                                    672 ;--------------------------------------------------------
                                    673 	.area IABS    (ABS,DATA)
                                    674 	.area IABS    (ABS,DATA)
                                    675 ;--------------------------------------------------------
                                    676 ; bit data
                                    677 ;--------------------------------------------------------
                                    678 	.area BSEG    (BIT)
                                    679 ;--------------------------------------------------------
                                    680 ; paged external ram data
                                    681 ;--------------------------------------------------------
                                    682 	.area PSEG    (PAG,XDATA)
                                    683 ;--------------------------------------------------------
                                    684 ; external ram data
                                    685 ;--------------------------------------------------------
                                    686 	.area XSEG    (XDATA)
                           007020   687 _ADCCH0VAL0	=	0x7020
                           007021   688 _ADCCH0VAL1	=	0x7021
                           007020   689 _ADCCH0VAL	=	0x7020
                           007022   690 _ADCCH1VAL0	=	0x7022
                           007023   691 _ADCCH1VAL1	=	0x7023
                           007022   692 _ADCCH1VAL	=	0x7022
                           007024   693 _ADCCH2VAL0	=	0x7024
                           007025   694 _ADCCH2VAL1	=	0x7025
                           007024   695 _ADCCH2VAL	=	0x7024
                           007026   696 _ADCCH3VAL0	=	0x7026
                           007027   697 _ADCCH3VAL1	=	0x7027
                           007026   698 _ADCCH3VAL	=	0x7026
                           007028   699 _ADCTUNE0	=	0x7028
                           007029   700 _ADCTUNE1	=	0x7029
                           00702A   701 _ADCTUNE2	=	0x702a
                           007010   702 _DMA0ADDR0	=	0x7010
                           007011   703 _DMA0ADDR1	=	0x7011
                           007010   704 _DMA0ADDR	=	0x7010
                           007014   705 _DMA0CONFIG	=	0x7014
                           007012   706 _DMA1ADDR0	=	0x7012
                           007013   707 _DMA1ADDR1	=	0x7013
                           007012   708 _DMA1ADDR	=	0x7012
                           007015   709 _DMA1CONFIG	=	0x7015
                           007070   710 _FRCOSCCONFIG	=	0x7070
                           007071   711 _FRCOSCCTRL	=	0x7071
                           007076   712 _FRCOSCFREQ0	=	0x7076
                           007077   713 _FRCOSCFREQ1	=	0x7077
                           007076   714 _FRCOSCFREQ	=	0x7076
                           007072   715 _FRCOSCKFILT0	=	0x7072
                           007073   716 _FRCOSCKFILT1	=	0x7073
                           007072   717 _FRCOSCKFILT	=	0x7072
                           007078   718 _FRCOSCPER0	=	0x7078
                           007079   719 _FRCOSCPER1	=	0x7079
                           007078   720 _FRCOSCPER	=	0x7078
                           007074   721 _FRCOSCREF0	=	0x7074
                           007075   722 _FRCOSCREF1	=	0x7075
                           007074   723 _FRCOSCREF	=	0x7074
                           007007   724 _ANALOGA	=	0x7007
                           00700C   725 _GPIOENABLE	=	0x700c
                           007003   726 _EXTIRQ	=	0x7003
                           007000   727 _INTCHGA	=	0x7000
                           007001   728 _INTCHGB	=	0x7001
                           007002   729 _INTCHGC	=	0x7002
                           007008   730 _PALTA	=	0x7008
                           007009   731 _PALTB	=	0x7009
                           00700A   732 _PALTC	=	0x700a
                           007046   733 _PALTRADIO	=	0x7046
                           007004   734 _PINCHGA	=	0x7004
                           007005   735 _PINCHGB	=	0x7005
                           007006   736 _PINCHGC	=	0x7006
                           00700B   737 _PINSEL	=	0x700b
                           007060   738 _LPOSCCONFIG	=	0x7060
                           007066   739 _LPOSCFREQ0	=	0x7066
                           007067   740 _LPOSCFREQ1	=	0x7067
                           007066   741 _LPOSCFREQ	=	0x7066
                           007062   742 _LPOSCKFILT0	=	0x7062
                           007063   743 _LPOSCKFILT1	=	0x7063
                           007062   744 _LPOSCKFILT	=	0x7062
                           007068   745 _LPOSCPER0	=	0x7068
                           007069   746 _LPOSCPER1	=	0x7069
                           007068   747 _LPOSCPER	=	0x7068
                           007064   748 _LPOSCREF0	=	0x7064
                           007065   749 _LPOSCREF1	=	0x7065
                           007064   750 _LPOSCREF	=	0x7064
                           007054   751 _LPXOSCGM	=	0x7054
                           007F01   752 _MISCCTRL	=	0x7f01
                           007053   753 _OSCCALIB	=	0x7053
                           007050   754 _OSCFORCERUN	=	0x7050
                           007052   755 _OSCREADY	=	0x7052
                           007051   756 _OSCRUN	=	0x7051
                           007040   757 _RADIOFDATAADDR0	=	0x7040
                           007041   758 _RADIOFDATAADDR1	=	0x7041
                           007040   759 _RADIOFDATAADDR	=	0x7040
                           007042   760 _RADIOFSTATADDR0	=	0x7042
                           007043   761 _RADIOFSTATADDR1	=	0x7043
                           007042   762 _RADIOFSTATADDR	=	0x7042
                           007044   763 _RADIOMUX	=	0x7044
                           007084   764 _SCRATCH0	=	0x7084
                           007085   765 _SCRATCH1	=	0x7085
                           007086   766 _SCRATCH2	=	0x7086
                           007087   767 _SCRATCH3	=	0x7087
                           007F00   768 _SILICONREV	=	0x7f00
                           007F19   769 _XTALAMPL	=	0x7f19
                           007F18   770 _XTALOSC	=	0x7f18
                           007F1A   771 _XTALREADY	=	0x7f1a
                                    772 ;--------------------------------------------------------
                                    773 ; absolute external ram data
                                    774 ;--------------------------------------------------------
                                    775 	.area XABS    (ABS,XDATA)
                                    776 ;--------------------------------------------------------
                                    777 ; external initialized ram data
                                    778 ;--------------------------------------------------------
                                    779 	.area XISEG   (XDATA)
                                    780 	.area HOME    (CODE)
                                    781 	.area GSINIT0 (CODE)
                                    782 	.area GSINIT1 (CODE)
                                    783 	.area GSINIT2 (CODE)
                                    784 	.area GSINIT3 (CODE)
                                    785 	.area GSINIT4 (CODE)
                                    786 	.area GSINIT5 (CODE)
                                    787 	.area GSINIT  (CODE)
                                    788 	.area GSFINAL (CODE)
                                    789 	.area CSEG    (CODE)
                                    790 ;--------------------------------------------------------
                                    791 ; global & static initialisations
                                    792 ;--------------------------------------------------------
                                    793 	.area HOME    (CODE)
                                    794 	.area GSINIT  (CODE)
                                    795 	.area GSFINAL (CODE)
                                    796 	.area GSINIT  (CODE)
                                    797 ;--------------------------------------------------------
                                    798 ; Home
                                    799 ;--------------------------------------------------------
                                    800 	.area HOME    (CODE)
                                    801 	.area HOME    (CODE)
                                    802 ;--------------------------------------------------------
                                    803 ; code
                                    804 ;--------------------------------------------------------
                                    805 	.area CSEG    (CODE)
                                    806 	.area CSEG    (CODE)
                                    807 	.area CONST   (CODE)
      004D0B                        808 _remoteaddr:
      004D0B 33                     809 	.db #0x33	; 51	'3'
      004D0C 34                     810 	.db #0x34	; 52	'4'
      004D0D 00                     811 	.db #0x00	; 0
      004D0E 00                     812 	.db #0x00	; 0
      004D0F 00                     813 	.db 0x00
      004D10                        814 _localaddr:
      004D10 32                     815 	.db #0x32	; 50	'2'
      004D11 34                     816 	.db #0x34	; 52	'4'
      004D12 00                     817 	.db #0x00	; 0
      004D13 00                     818 	.db #0x00	; 0
      004D14 00                     819 	.db 0x00
      004D15 FF                     820 	.db #0xff	; 255
      004D16 FF                     821 	.db #0xff	; 255
      004D17 FF                     822 	.db #0xff	; 255
      004D18 FF                     823 	.db #0xff	; 255
      004D19 00                     824 	.db 0x00
      004D1A                        825 _framing_insert_counter:
      004D1A 01                     826 	.db #0x01	; 1
      004D1B                        827 _framing_counter_pos:
      004D1B 00                     828 	.db #0x00	; 0
      004D1C                        829 _demo_packet:
      004D1C 00                     830 	.db #0x00	; 0
      004D1D 00                     831 	.db #0x00	; 0
      004D1E 55                     832 	.db #0x55	; 85	'U'
      004D1F 66                     833 	.db #0x66	; 102	'f'
      004D20 77                     834 	.db #0x77	; 119	'w'
      004D21 88                     835 	.db #0x88	; 136
      004D22                        836 _lpxosc_settlingtime:
      004D22 B8 0B                  837 	.byte #0xb8,#0x0b	; 3000
                                    838 	.area XINIT   (CODE)
                                    839 	.area CABS    (ABS,CODE)
