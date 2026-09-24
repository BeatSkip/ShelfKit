                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module configslave
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _lpxosc_settlingtime
                                     12 	.globl _framing_counter_pos
                                     13 	.globl _framing_insert_counter
                                     14 	.globl _localaddr
                                     15 	.globl _remoteaddr
                                     16 	.globl _PORTC_7
                                     17 	.globl _PORTC_6
                                     18 	.globl _PORTC_5
                                     19 	.globl _PORTC_4
                                     20 	.globl _PORTC_3
                                     21 	.globl _PORTC_2
                                     22 	.globl _PORTC_1
                                     23 	.globl _PORTC_0
                                     24 	.globl _PORTB_7
                                     25 	.globl _PORTB_6
                                     26 	.globl _PORTB_5
                                     27 	.globl _PORTB_4
                                     28 	.globl _PORTB_3
                                     29 	.globl _PORTB_2
                                     30 	.globl _PORTB_1
                                     31 	.globl _PORTB_0
                                     32 	.globl _PORTA_7
                                     33 	.globl _PORTA_6
                                     34 	.globl _PORTA_5
                                     35 	.globl _PORTA_4
                                     36 	.globl _PORTA_3
                                     37 	.globl _PORTA_2
                                     38 	.globl _PORTA_1
                                     39 	.globl _PORTA_0
                                     40 	.globl _PINC_7
                                     41 	.globl _PINC_6
                                     42 	.globl _PINC_5
                                     43 	.globl _PINC_4
                                     44 	.globl _PINC_3
                                     45 	.globl _PINC_2
                                     46 	.globl _PINC_1
                                     47 	.globl _PINC_0
                                     48 	.globl _PINB_7
                                     49 	.globl _PINB_6
                                     50 	.globl _PINB_5
                                     51 	.globl _PINB_4
                                     52 	.globl _PINB_3
                                     53 	.globl _PINB_2
                                     54 	.globl _PINB_1
                                     55 	.globl _PINB_0
                                     56 	.globl _PINA_7
                                     57 	.globl _PINA_6
                                     58 	.globl _PINA_5
                                     59 	.globl _PINA_4
                                     60 	.globl _PINA_3
                                     61 	.globl _PINA_2
                                     62 	.globl _PINA_1
                                     63 	.globl _PINA_0
                                     64 	.globl _CY
                                     65 	.globl _AC
                                     66 	.globl _F0
                                     67 	.globl _RS1
                                     68 	.globl _RS0
                                     69 	.globl _OV
                                     70 	.globl _F1
                                     71 	.globl _P
                                     72 	.globl _IP_7
                                     73 	.globl _IP_6
                                     74 	.globl _IP_5
                                     75 	.globl _IP_4
                                     76 	.globl _IP_3
                                     77 	.globl _IP_2
                                     78 	.globl _IP_1
                                     79 	.globl _IP_0
                                     80 	.globl _EA
                                     81 	.globl _IE_7
                                     82 	.globl _IE_6
                                     83 	.globl _IE_5
                                     84 	.globl _IE_4
                                     85 	.globl _IE_3
                                     86 	.globl _IE_2
                                     87 	.globl _IE_1
                                     88 	.globl _IE_0
                                     89 	.globl _EIP_7
                                     90 	.globl _EIP_6
                                     91 	.globl _EIP_5
                                     92 	.globl _EIP_4
                                     93 	.globl _EIP_3
                                     94 	.globl _EIP_2
                                     95 	.globl _EIP_1
                                     96 	.globl _EIP_0
                                     97 	.globl _EIE_7
                                     98 	.globl _EIE_6
                                     99 	.globl _EIE_5
                                    100 	.globl _EIE_4
                                    101 	.globl _EIE_3
                                    102 	.globl _EIE_2
                                    103 	.globl _EIE_1
                                    104 	.globl _EIE_0
                                    105 	.globl _E2IP_7
                                    106 	.globl _E2IP_6
                                    107 	.globl _E2IP_5
                                    108 	.globl _E2IP_4
                                    109 	.globl _E2IP_3
                                    110 	.globl _E2IP_2
                                    111 	.globl _E2IP_1
                                    112 	.globl _E2IP_0
                                    113 	.globl _E2IE_7
                                    114 	.globl _E2IE_6
                                    115 	.globl _E2IE_5
                                    116 	.globl _E2IE_4
                                    117 	.globl _E2IE_3
                                    118 	.globl _E2IE_2
                                    119 	.globl _E2IE_1
                                    120 	.globl _E2IE_0
                                    121 	.globl _B_7
                                    122 	.globl _B_6
                                    123 	.globl _B_5
                                    124 	.globl _B_4
                                    125 	.globl _B_3
                                    126 	.globl _B_2
                                    127 	.globl _B_1
                                    128 	.globl _B_0
                                    129 	.globl _ACC_7
                                    130 	.globl _ACC_6
                                    131 	.globl _ACC_5
                                    132 	.globl _ACC_4
                                    133 	.globl _ACC_3
                                    134 	.globl _ACC_2
                                    135 	.globl _ACC_1
                                    136 	.globl _ACC_0
                                    137 	.globl _WTSTAT
                                    138 	.globl _WTIRQEN
                                    139 	.globl _WTEVTD
                                    140 	.globl _WTEVTD1
                                    141 	.globl _WTEVTD0
                                    142 	.globl _WTEVTC
                                    143 	.globl _WTEVTC1
                                    144 	.globl _WTEVTC0
                                    145 	.globl _WTEVTB
                                    146 	.globl _WTEVTB1
                                    147 	.globl _WTEVTB0
                                    148 	.globl _WTEVTA
                                    149 	.globl _WTEVTA1
                                    150 	.globl _WTEVTA0
                                    151 	.globl _WTCNTR1
                                    152 	.globl _WTCNTB
                                    153 	.globl _WTCNTB1
                                    154 	.globl _WTCNTB0
                                    155 	.globl _WTCNTA
                                    156 	.globl _WTCNTA1
                                    157 	.globl _WTCNTA0
                                    158 	.globl _WTCFGB
                                    159 	.globl _WTCFGA
                                    160 	.globl _WDTRESET
                                    161 	.globl _WDTCFG
                                    162 	.globl _U1STATUS
                                    163 	.globl _U1SHREG
                                    164 	.globl _U1MODE
                                    165 	.globl _U1CTRL
                                    166 	.globl _U0STATUS
                                    167 	.globl _U0SHREG
                                    168 	.globl _U0MODE
                                    169 	.globl _U0CTRL
                                    170 	.globl _T2STATUS
                                    171 	.globl _T2PERIOD
                                    172 	.globl _T2PERIOD1
                                    173 	.globl _T2PERIOD0
                                    174 	.globl _T2MODE
                                    175 	.globl _T2CNT
                                    176 	.globl _T2CNT1
                                    177 	.globl _T2CNT0
                                    178 	.globl _T2CLKSRC
                                    179 	.globl _T1STATUS
                                    180 	.globl _T1PERIOD
                                    181 	.globl _T1PERIOD1
                                    182 	.globl _T1PERIOD0
                                    183 	.globl _T1MODE
                                    184 	.globl _T1CNT
                                    185 	.globl _T1CNT1
                                    186 	.globl _T1CNT0
                                    187 	.globl _T1CLKSRC
                                    188 	.globl _T0STATUS
                                    189 	.globl _T0PERIOD
                                    190 	.globl _T0PERIOD1
                                    191 	.globl _T0PERIOD0
                                    192 	.globl _T0MODE
                                    193 	.globl _T0CNT
                                    194 	.globl _T0CNT1
                                    195 	.globl _T0CNT0
                                    196 	.globl _T0CLKSRC
                                    197 	.globl _SPSTATUS
                                    198 	.globl _SPSHREG
                                    199 	.globl _SPMODE
                                    200 	.globl _SPCLKSRC
                                    201 	.globl _RADIOSTAT
                                    202 	.globl _RADIOSTAT1
                                    203 	.globl _RADIOSTAT0
                                    204 	.globl _RADIODATA
                                    205 	.globl _RADIODATA3
                                    206 	.globl _RADIODATA2
                                    207 	.globl _RADIODATA1
                                    208 	.globl _RADIODATA0
                                    209 	.globl _RADIOADDR
                                    210 	.globl _RADIOADDR1
                                    211 	.globl _RADIOADDR0
                                    212 	.globl _RADIOACC
                                    213 	.globl _OC1STATUS
                                    214 	.globl _OC1PIN
                                    215 	.globl _OC1MODE
                                    216 	.globl _OC1COMP
                                    217 	.globl _OC1COMP1
                                    218 	.globl _OC1COMP0
                                    219 	.globl _OC0STATUS
                                    220 	.globl _OC0PIN
                                    221 	.globl _OC0MODE
                                    222 	.globl _OC0COMP
                                    223 	.globl _OC0COMP1
                                    224 	.globl _OC0COMP0
                                    225 	.globl _NVSTATUS
                                    226 	.globl _NVKEY
                                    227 	.globl _NVDATA
                                    228 	.globl _NVDATA1
                                    229 	.globl _NVDATA0
                                    230 	.globl _NVADDR
                                    231 	.globl _NVADDR1
                                    232 	.globl _NVADDR0
                                    233 	.globl _IC1STATUS
                                    234 	.globl _IC1MODE
                                    235 	.globl _IC1CAPT
                                    236 	.globl _IC1CAPT1
                                    237 	.globl _IC1CAPT0
                                    238 	.globl _IC0STATUS
                                    239 	.globl _IC0MODE
                                    240 	.globl _IC0CAPT
                                    241 	.globl _IC0CAPT1
                                    242 	.globl _IC0CAPT0
                                    243 	.globl _PORTR
                                    244 	.globl _PORTC
                                    245 	.globl _PORTB
                                    246 	.globl _PORTA
                                    247 	.globl _PINR
                                    248 	.globl _PINC
                                    249 	.globl _PINB
                                    250 	.globl _PINA
                                    251 	.globl _DIRR
                                    252 	.globl _DIRC
                                    253 	.globl _DIRB
                                    254 	.globl _DIRA
                                    255 	.globl _DBGLNKSTAT
                                    256 	.globl _DBGLNKBUF
                                    257 	.globl _CODECONFIG
                                    258 	.globl _CLKSTAT
                                    259 	.globl _CLKCON
                                    260 	.globl _ANALOGCOMP
                                    261 	.globl _ADCCONV
                                    262 	.globl _ADCCLKSRC
                                    263 	.globl _ADCCH3CONFIG
                                    264 	.globl _ADCCH2CONFIG
                                    265 	.globl _ADCCH1CONFIG
                                    266 	.globl _ADCCH0CONFIG
                                    267 	.globl __XPAGE
                                    268 	.globl _XPAGE
                                    269 	.globl _SP
                                    270 	.globl _PSW
                                    271 	.globl _PCON
                                    272 	.globl _IP
                                    273 	.globl _IE
                                    274 	.globl _EIP
                                    275 	.globl _EIE
                                    276 	.globl _E2IP
                                    277 	.globl _E2IE
                                    278 	.globl _DPS
                                    279 	.globl _DPTR1
                                    280 	.globl _DPTR0
                                    281 	.globl _DPL1
                                    282 	.globl _DPL
                                    283 	.globl _DPH1
                                    284 	.globl _DPH
                                    285 	.globl _B
                                    286 	.globl _ACC
                                    287 	.globl _XTALREADY
                                    288 	.globl _XTALOSC
                                    289 	.globl _XTALAMPL
                                    290 	.globl _SILICONREV
                                    291 	.globl _SCRATCH3
                                    292 	.globl _SCRATCH2
                                    293 	.globl _SCRATCH1
                                    294 	.globl _SCRATCH0
                                    295 	.globl _RADIOMUX
                                    296 	.globl _RADIOFSTATADDR
                                    297 	.globl _RADIOFSTATADDR1
                                    298 	.globl _RADIOFSTATADDR0
                                    299 	.globl _RADIOFDATAADDR
                                    300 	.globl _RADIOFDATAADDR1
                                    301 	.globl _RADIOFDATAADDR0
                                    302 	.globl _OSCRUN
                                    303 	.globl _OSCREADY
                                    304 	.globl _OSCFORCERUN
                                    305 	.globl _OSCCALIB
                                    306 	.globl _MISCCTRL
                                    307 	.globl _LPXOSCGM
                                    308 	.globl _LPOSCREF
                                    309 	.globl _LPOSCREF1
                                    310 	.globl _LPOSCREF0
                                    311 	.globl _LPOSCPER
                                    312 	.globl _LPOSCPER1
                                    313 	.globl _LPOSCPER0
                                    314 	.globl _LPOSCKFILT
                                    315 	.globl _LPOSCKFILT1
                                    316 	.globl _LPOSCKFILT0
                                    317 	.globl _LPOSCFREQ
                                    318 	.globl _LPOSCFREQ1
                                    319 	.globl _LPOSCFREQ0
                                    320 	.globl _LPOSCCONFIG
                                    321 	.globl _PINSEL
                                    322 	.globl _PINCHGC
                                    323 	.globl _PINCHGB
                                    324 	.globl _PINCHGA
                                    325 	.globl _PALTRADIO
                                    326 	.globl _PALTC
                                    327 	.globl _PALTB
                                    328 	.globl _PALTA
                                    329 	.globl _INTCHGC
                                    330 	.globl _INTCHGB
                                    331 	.globl _INTCHGA
                                    332 	.globl _EXTIRQ
                                    333 	.globl _GPIOENABLE
                                    334 	.globl _ANALOGA
                                    335 	.globl _FRCOSCREF
                                    336 	.globl _FRCOSCREF1
                                    337 	.globl _FRCOSCREF0
                                    338 	.globl _FRCOSCPER
                                    339 	.globl _FRCOSCPER1
                                    340 	.globl _FRCOSCPER0
                                    341 	.globl _FRCOSCKFILT
                                    342 	.globl _FRCOSCKFILT1
                                    343 	.globl _FRCOSCKFILT0
                                    344 	.globl _FRCOSCFREQ
                                    345 	.globl _FRCOSCFREQ1
                                    346 	.globl _FRCOSCFREQ0
                                    347 	.globl _FRCOSCCTRL
                                    348 	.globl _FRCOSCCONFIG
                                    349 	.globl _DMA1CONFIG
                                    350 	.globl _DMA1ADDR
                                    351 	.globl _DMA1ADDR1
                                    352 	.globl _DMA1ADDR0
                                    353 	.globl _DMA0CONFIG
                                    354 	.globl _DMA0ADDR
                                    355 	.globl _DMA0ADDR1
                                    356 	.globl _DMA0ADDR0
                                    357 	.globl _ADCTUNE2
                                    358 	.globl _ADCTUNE1
                                    359 	.globl _ADCTUNE0
                                    360 	.globl _ADCCH3VAL
                                    361 	.globl _ADCCH3VAL1
                                    362 	.globl _ADCCH3VAL0
                                    363 	.globl _ADCCH2VAL
                                    364 	.globl _ADCCH2VAL1
                                    365 	.globl _ADCCH2VAL0
                                    366 	.globl _ADCCH1VAL
                                    367 	.globl _ADCCH1VAL1
                                    368 	.globl _ADCCH1VAL0
                                    369 	.globl _ADCCH0VAL
                                    370 	.globl _ADCCH0VAL1
                                    371 	.globl _ADCCH0VAL0
                                    372 ;--------------------------------------------------------
                                    373 ; special function registers
                                    374 ;--------------------------------------------------------
                                    375 	.area RSEG    (ABS,DATA)
      000000                        376 	.org 0x0000
                           0000E0   377 G$ACC$0$0 == 0x00e0
                           0000E0   378 _ACC	=	0x00e0
                           0000F0   379 G$B$0$0 == 0x00f0
                           0000F0   380 _B	=	0x00f0
                           000083   381 G$DPH$0$0 == 0x0083
                           000083   382 _DPH	=	0x0083
                           000085   383 G$DPH1$0$0 == 0x0085
                           000085   384 _DPH1	=	0x0085
                           000082   385 G$DPL$0$0 == 0x0082
                           000082   386 _DPL	=	0x0082
                           000084   387 G$DPL1$0$0 == 0x0084
                           000084   388 _DPL1	=	0x0084
                           008382   389 G$DPTR0$0$0 == 0x8382
                           008382   390 _DPTR0	=	0x8382
                           008584   391 G$DPTR1$0$0 == 0x8584
                           008584   392 _DPTR1	=	0x8584
                           000086   393 G$DPS$0$0 == 0x0086
                           000086   394 _DPS	=	0x0086
                           0000A0   395 G$E2IE$0$0 == 0x00a0
                           0000A0   396 _E2IE	=	0x00a0
                           0000C0   397 G$E2IP$0$0 == 0x00c0
                           0000C0   398 _E2IP	=	0x00c0
                           000098   399 G$EIE$0$0 == 0x0098
                           000098   400 _EIE	=	0x0098
                           0000B0   401 G$EIP$0$0 == 0x00b0
                           0000B0   402 _EIP	=	0x00b0
                           0000A8   403 G$IE$0$0 == 0x00a8
                           0000A8   404 _IE	=	0x00a8
                           0000B8   405 G$IP$0$0 == 0x00b8
                           0000B8   406 _IP	=	0x00b8
                           000087   407 G$PCON$0$0 == 0x0087
                           000087   408 _PCON	=	0x0087
                           0000D0   409 G$PSW$0$0 == 0x00d0
                           0000D0   410 _PSW	=	0x00d0
                           000081   411 G$SP$0$0 == 0x0081
                           000081   412 _SP	=	0x0081
                           0000D9   413 G$XPAGE$0$0 == 0x00d9
                           0000D9   414 _XPAGE	=	0x00d9
                           0000D9   415 G$_XPAGE$0$0 == 0x00d9
                           0000D9   416 __XPAGE	=	0x00d9
                           0000CA   417 G$ADCCH0CONFIG$0$0 == 0x00ca
                           0000CA   418 _ADCCH0CONFIG	=	0x00ca
                           0000CB   419 G$ADCCH1CONFIG$0$0 == 0x00cb
                           0000CB   420 _ADCCH1CONFIG	=	0x00cb
                           0000D2   421 G$ADCCH2CONFIG$0$0 == 0x00d2
                           0000D2   422 _ADCCH2CONFIG	=	0x00d2
                           0000D3   423 G$ADCCH3CONFIG$0$0 == 0x00d3
                           0000D3   424 _ADCCH3CONFIG	=	0x00d3
                           0000D1   425 G$ADCCLKSRC$0$0 == 0x00d1
                           0000D1   426 _ADCCLKSRC	=	0x00d1
                           0000C9   427 G$ADCCONV$0$0 == 0x00c9
                           0000C9   428 _ADCCONV	=	0x00c9
                           0000E1   429 G$ANALOGCOMP$0$0 == 0x00e1
                           0000E1   430 _ANALOGCOMP	=	0x00e1
                           0000C6   431 G$CLKCON$0$0 == 0x00c6
                           0000C6   432 _CLKCON	=	0x00c6
                           0000C7   433 G$CLKSTAT$0$0 == 0x00c7
                           0000C7   434 _CLKSTAT	=	0x00c7
                           000097   435 G$CODECONFIG$0$0 == 0x0097
                           000097   436 _CODECONFIG	=	0x0097
                           0000E3   437 G$DBGLNKBUF$0$0 == 0x00e3
                           0000E3   438 _DBGLNKBUF	=	0x00e3
                           0000E2   439 G$DBGLNKSTAT$0$0 == 0x00e2
                           0000E2   440 _DBGLNKSTAT	=	0x00e2
                           000089   441 G$DIRA$0$0 == 0x0089
                           000089   442 _DIRA	=	0x0089
                           00008A   443 G$DIRB$0$0 == 0x008a
                           00008A   444 _DIRB	=	0x008a
                           00008B   445 G$DIRC$0$0 == 0x008b
                           00008B   446 _DIRC	=	0x008b
                           00008E   447 G$DIRR$0$0 == 0x008e
                           00008E   448 _DIRR	=	0x008e
                           0000C8   449 G$PINA$0$0 == 0x00c8
                           0000C8   450 _PINA	=	0x00c8
                           0000E8   451 G$PINB$0$0 == 0x00e8
                           0000E8   452 _PINB	=	0x00e8
                           0000F8   453 G$PINC$0$0 == 0x00f8
                           0000F8   454 _PINC	=	0x00f8
                           00008D   455 G$PINR$0$0 == 0x008d
                           00008D   456 _PINR	=	0x008d
                           000080   457 G$PORTA$0$0 == 0x0080
                           000080   458 _PORTA	=	0x0080
                           000088   459 G$PORTB$0$0 == 0x0088
                           000088   460 _PORTB	=	0x0088
                           000090   461 G$PORTC$0$0 == 0x0090
                           000090   462 _PORTC	=	0x0090
                           00008C   463 G$PORTR$0$0 == 0x008c
                           00008C   464 _PORTR	=	0x008c
                           0000CE   465 G$IC0CAPT0$0$0 == 0x00ce
                           0000CE   466 _IC0CAPT0	=	0x00ce
                           0000CF   467 G$IC0CAPT1$0$0 == 0x00cf
                           0000CF   468 _IC0CAPT1	=	0x00cf
                           00CFCE   469 G$IC0CAPT$0$0 == 0xcfce
                           00CFCE   470 _IC0CAPT	=	0xcfce
                           0000CC   471 G$IC0MODE$0$0 == 0x00cc
                           0000CC   472 _IC0MODE	=	0x00cc
                           0000CD   473 G$IC0STATUS$0$0 == 0x00cd
                           0000CD   474 _IC0STATUS	=	0x00cd
                           0000D6   475 G$IC1CAPT0$0$0 == 0x00d6
                           0000D6   476 _IC1CAPT0	=	0x00d6
                           0000D7   477 G$IC1CAPT1$0$0 == 0x00d7
                           0000D7   478 _IC1CAPT1	=	0x00d7
                           00D7D6   479 G$IC1CAPT$0$0 == 0xd7d6
                           00D7D6   480 _IC1CAPT	=	0xd7d6
                           0000D4   481 G$IC1MODE$0$0 == 0x00d4
                           0000D4   482 _IC1MODE	=	0x00d4
                           0000D5   483 G$IC1STATUS$0$0 == 0x00d5
                           0000D5   484 _IC1STATUS	=	0x00d5
                           000092   485 G$NVADDR0$0$0 == 0x0092
                           000092   486 _NVADDR0	=	0x0092
                           000093   487 G$NVADDR1$0$0 == 0x0093
                           000093   488 _NVADDR1	=	0x0093
                           009392   489 G$NVADDR$0$0 == 0x9392
                           009392   490 _NVADDR	=	0x9392
                           000094   491 G$NVDATA0$0$0 == 0x0094
                           000094   492 _NVDATA0	=	0x0094
                           000095   493 G$NVDATA1$0$0 == 0x0095
                           000095   494 _NVDATA1	=	0x0095
                           009594   495 G$NVDATA$0$0 == 0x9594
                           009594   496 _NVDATA	=	0x9594
                           000096   497 G$NVKEY$0$0 == 0x0096
                           000096   498 _NVKEY	=	0x0096
                           000091   499 G$NVSTATUS$0$0 == 0x0091
                           000091   500 _NVSTATUS	=	0x0091
                           0000BC   501 G$OC0COMP0$0$0 == 0x00bc
                           0000BC   502 _OC0COMP0	=	0x00bc
                           0000BD   503 G$OC0COMP1$0$0 == 0x00bd
                           0000BD   504 _OC0COMP1	=	0x00bd
                           00BDBC   505 G$OC0COMP$0$0 == 0xbdbc
                           00BDBC   506 _OC0COMP	=	0xbdbc
                           0000B9   507 G$OC0MODE$0$0 == 0x00b9
                           0000B9   508 _OC0MODE	=	0x00b9
                           0000BA   509 G$OC0PIN$0$0 == 0x00ba
                           0000BA   510 _OC0PIN	=	0x00ba
                           0000BB   511 G$OC0STATUS$0$0 == 0x00bb
                           0000BB   512 _OC0STATUS	=	0x00bb
                           0000C4   513 G$OC1COMP0$0$0 == 0x00c4
                           0000C4   514 _OC1COMP0	=	0x00c4
                           0000C5   515 G$OC1COMP1$0$0 == 0x00c5
                           0000C5   516 _OC1COMP1	=	0x00c5
                           00C5C4   517 G$OC1COMP$0$0 == 0xc5c4
                           00C5C4   518 _OC1COMP	=	0xc5c4
                           0000C1   519 G$OC1MODE$0$0 == 0x00c1
                           0000C1   520 _OC1MODE	=	0x00c1
                           0000C2   521 G$OC1PIN$0$0 == 0x00c2
                           0000C2   522 _OC1PIN	=	0x00c2
                           0000C3   523 G$OC1STATUS$0$0 == 0x00c3
                           0000C3   524 _OC1STATUS	=	0x00c3
                           0000B1   525 G$RADIOACC$0$0 == 0x00b1
                           0000B1   526 _RADIOACC	=	0x00b1
                           0000B3   527 G$RADIOADDR0$0$0 == 0x00b3
                           0000B3   528 _RADIOADDR0	=	0x00b3
                           0000B2   529 G$RADIOADDR1$0$0 == 0x00b2
                           0000B2   530 _RADIOADDR1	=	0x00b2
                           00B2B3   531 G$RADIOADDR$0$0 == 0xb2b3
                           00B2B3   532 _RADIOADDR	=	0xb2b3
                           0000B7   533 G$RADIODATA0$0$0 == 0x00b7
                           0000B7   534 _RADIODATA0	=	0x00b7
                           0000B6   535 G$RADIODATA1$0$0 == 0x00b6
                           0000B6   536 _RADIODATA1	=	0x00b6
                           0000B5   537 G$RADIODATA2$0$0 == 0x00b5
                           0000B5   538 _RADIODATA2	=	0x00b5
                           0000B4   539 G$RADIODATA3$0$0 == 0x00b4
                           0000B4   540 _RADIODATA3	=	0x00b4
                           B4B5B6B7   541 G$RADIODATA$0$0 == 0xb4b5b6b7
                           B4B5B6B7   542 _RADIODATA	=	0xb4b5b6b7
                           0000BE   543 G$RADIOSTAT0$0$0 == 0x00be
                           0000BE   544 _RADIOSTAT0	=	0x00be
                           0000BF   545 G$RADIOSTAT1$0$0 == 0x00bf
                           0000BF   546 _RADIOSTAT1	=	0x00bf
                           00BFBE   547 G$RADIOSTAT$0$0 == 0xbfbe
                           00BFBE   548 _RADIOSTAT	=	0xbfbe
                           0000DF   549 G$SPCLKSRC$0$0 == 0x00df
                           0000DF   550 _SPCLKSRC	=	0x00df
                           0000DC   551 G$SPMODE$0$0 == 0x00dc
                           0000DC   552 _SPMODE	=	0x00dc
                           0000DE   553 G$SPSHREG$0$0 == 0x00de
                           0000DE   554 _SPSHREG	=	0x00de
                           0000DD   555 G$SPSTATUS$0$0 == 0x00dd
                           0000DD   556 _SPSTATUS	=	0x00dd
                           00009A   557 G$T0CLKSRC$0$0 == 0x009a
                           00009A   558 _T0CLKSRC	=	0x009a
                           00009C   559 G$T0CNT0$0$0 == 0x009c
                           00009C   560 _T0CNT0	=	0x009c
                           00009D   561 G$T0CNT1$0$0 == 0x009d
                           00009D   562 _T0CNT1	=	0x009d
                           009D9C   563 G$T0CNT$0$0 == 0x9d9c
                           009D9C   564 _T0CNT	=	0x9d9c
                           000099   565 G$T0MODE$0$0 == 0x0099
                           000099   566 _T0MODE	=	0x0099
                           00009E   567 G$T0PERIOD0$0$0 == 0x009e
                           00009E   568 _T0PERIOD0	=	0x009e
                           00009F   569 G$T0PERIOD1$0$0 == 0x009f
                           00009F   570 _T0PERIOD1	=	0x009f
                           009F9E   571 G$T0PERIOD$0$0 == 0x9f9e
                           009F9E   572 _T0PERIOD	=	0x9f9e
                           00009B   573 G$T0STATUS$0$0 == 0x009b
                           00009B   574 _T0STATUS	=	0x009b
                           0000A2   575 G$T1CLKSRC$0$0 == 0x00a2
                           0000A2   576 _T1CLKSRC	=	0x00a2
                           0000A4   577 G$T1CNT0$0$0 == 0x00a4
                           0000A4   578 _T1CNT0	=	0x00a4
                           0000A5   579 G$T1CNT1$0$0 == 0x00a5
                           0000A5   580 _T1CNT1	=	0x00a5
                           00A5A4   581 G$T1CNT$0$0 == 0xa5a4
                           00A5A4   582 _T1CNT	=	0xa5a4
                           0000A1   583 G$T1MODE$0$0 == 0x00a1
                           0000A1   584 _T1MODE	=	0x00a1
                           0000A6   585 G$T1PERIOD0$0$0 == 0x00a6
                           0000A6   586 _T1PERIOD0	=	0x00a6
                           0000A7   587 G$T1PERIOD1$0$0 == 0x00a7
                           0000A7   588 _T1PERIOD1	=	0x00a7
                           00A7A6   589 G$T1PERIOD$0$0 == 0xa7a6
                           00A7A6   590 _T1PERIOD	=	0xa7a6
                           0000A3   591 G$T1STATUS$0$0 == 0x00a3
                           0000A3   592 _T1STATUS	=	0x00a3
                           0000AA   593 G$T2CLKSRC$0$0 == 0x00aa
                           0000AA   594 _T2CLKSRC	=	0x00aa
                           0000AC   595 G$T2CNT0$0$0 == 0x00ac
                           0000AC   596 _T2CNT0	=	0x00ac
                           0000AD   597 G$T2CNT1$0$0 == 0x00ad
                           0000AD   598 _T2CNT1	=	0x00ad
                           00ADAC   599 G$T2CNT$0$0 == 0xadac
                           00ADAC   600 _T2CNT	=	0xadac
                           0000A9   601 G$T2MODE$0$0 == 0x00a9
                           0000A9   602 _T2MODE	=	0x00a9
                           0000AE   603 G$T2PERIOD0$0$0 == 0x00ae
                           0000AE   604 _T2PERIOD0	=	0x00ae
                           0000AF   605 G$T2PERIOD1$0$0 == 0x00af
                           0000AF   606 _T2PERIOD1	=	0x00af
                           00AFAE   607 G$T2PERIOD$0$0 == 0xafae
                           00AFAE   608 _T2PERIOD	=	0xafae
                           0000AB   609 G$T2STATUS$0$0 == 0x00ab
                           0000AB   610 _T2STATUS	=	0x00ab
                           0000E4   611 G$U0CTRL$0$0 == 0x00e4
                           0000E4   612 _U0CTRL	=	0x00e4
                           0000E7   613 G$U0MODE$0$0 == 0x00e7
                           0000E7   614 _U0MODE	=	0x00e7
                           0000E6   615 G$U0SHREG$0$0 == 0x00e6
                           0000E6   616 _U0SHREG	=	0x00e6
                           0000E5   617 G$U0STATUS$0$0 == 0x00e5
                           0000E5   618 _U0STATUS	=	0x00e5
                           0000EC   619 G$U1CTRL$0$0 == 0x00ec
                           0000EC   620 _U1CTRL	=	0x00ec
                           0000EF   621 G$U1MODE$0$0 == 0x00ef
                           0000EF   622 _U1MODE	=	0x00ef
                           0000EE   623 G$U1SHREG$0$0 == 0x00ee
                           0000EE   624 _U1SHREG	=	0x00ee
                           0000ED   625 G$U1STATUS$0$0 == 0x00ed
                           0000ED   626 _U1STATUS	=	0x00ed
                           0000DA   627 G$WDTCFG$0$0 == 0x00da
                           0000DA   628 _WDTCFG	=	0x00da
                           0000DB   629 G$WDTRESET$0$0 == 0x00db
                           0000DB   630 _WDTRESET	=	0x00db
                           0000F1   631 G$WTCFGA$0$0 == 0x00f1
                           0000F1   632 _WTCFGA	=	0x00f1
                           0000F9   633 G$WTCFGB$0$0 == 0x00f9
                           0000F9   634 _WTCFGB	=	0x00f9
                           0000F2   635 G$WTCNTA0$0$0 == 0x00f2
                           0000F2   636 _WTCNTA0	=	0x00f2
                           0000F3   637 G$WTCNTA1$0$0 == 0x00f3
                           0000F3   638 _WTCNTA1	=	0x00f3
                           00F3F2   639 G$WTCNTA$0$0 == 0xf3f2
                           00F3F2   640 _WTCNTA	=	0xf3f2
                           0000FA   641 G$WTCNTB0$0$0 == 0x00fa
                           0000FA   642 _WTCNTB0	=	0x00fa
                           0000FB   643 G$WTCNTB1$0$0 == 0x00fb
                           0000FB   644 _WTCNTB1	=	0x00fb
                           00FBFA   645 G$WTCNTB$0$0 == 0xfbfa
                           00FBFA   646 _WTCNTB	=	0xfbfa
                           0000EB   647 G$WTCNTR1$0$0 == 0x00eb
                           0000EB   648 _WTCNTR1	=	0x00eb
                           0000F4   649 G$WTEVTA0$0$0 == 0x00f4
                           0000F4   650 _WTEVTA0	=	0x00f4
                           0000F5   651 G$WTEVTA1$0$0 == 0x00f5
                           0000F5   652 _WTEVTA1	=	0x00f5
                           00F5F4   653 G$WTEVTA$0$0 == 0xf5f4
                           00F5F4   654 _WTEVTA	=	0xf5f4
                           0000F6   655 G$WTEVTB0$0$0 == 0x00f6
                           0000F6   656 _WTEVTB0	=	0x00f6
                           0000F7   657 G$WTEVTB1$0$0 == 0x00f7
                           0000F7   658 _WTEVTB1	=	0x00f7
                           00F7F6   659 G$WTEVTB$0$0 == 0xf7f6
                           00F7F6   660 _WTEVTB	=	0xf7f6
                           0000FC   661 G$WTEVTC0$0$0 == 0x00fc
                           0000FC   662 _WTEVTC0	=	0x00fc
                           0000FD   663 G$WTEVTC1$0$0 == 0x00fd
                           0000FD   664 _WTEVTC1	=	0x00fd
                           00FDFC   665 G$WTEVTC$0$0 == 0xfdfc
                           00FDFC   666 _WTEVTC	=	0xfdfc
                           0000FE   667 G$WTEVTD0$0$0 == 0x00fe
                           0000FE   668 _WTEVTD0	=	0x00fe
                           0000FF   669 G$WTEVTD1$0$0 == 0x00ff
                           0000FF   670 _WTEVTD1	=	0x00ff
                           00FFFE   671 G$WTEVTD$0$0 == 0xfffe
                           00FFFE   672 _WTEVTD	=	0xfffe
                           0000E9   673 G$WTIRQEN$0$0 == 0x00e9
                           0000E9   674 _WTIRQEN	=	0x00e9
                           0000EA   675 G$WTSTAT$0$0 == 0x00ea
                           0000EA   676 _WTSTAT	=	0x00ea
                                    677 ;--------------------------------------------------------
                                    678 ; special function bits
                                    679 ;--------------------------------------------------------
                                    680 	.area RSEG    (ABS,DATA)
      000000                        681 	.org 0x0000
                           0000E0   682 G$ACC_0$0$0 == 0x00e0
                           0000E0   683 _ACC_0	=	0x00e0
                           0000E1   684 G$ACC_1$0$0 == 0x00e1
                           0000E1   685 _ACC_1	=	0x00e1
                           0000E2   686 G$ACC_2$0$0 == 0x00e2
                           0000E2   687 _ACC_2	=	0x00e2
                           0000E3   688 G$ACC_3$0$0 == 0x00e3
                           0000E3   689 _ACC_3	=	0x00e3
                           0000E4   690 G$ACC_4$0$0 == 0x00e4
                           0000E4   691 _ACC_4	=	0x00e4
                           0000E5   692 G$ACC_5$0$0 == 0x00e5
                           0000E5   693 _ACC_5	=	0x00e5
                           0000E6   694 G$ACC_6$0$0 == 0x00e6
                           0000E6   695 _ACC_6	=	0x00e6
                           0000E7   696 G$ACC_7$0$0 == 0x00e7
                           0000E7   697 _ACC_7	=	0x00e7
                           0000F0   698 G$B_0$0$0 == 0x00f0
                           0000F0   699 _B_0	=	0x00f0
                           0000F1   700 G$B_1$0$0 == 0x00f1
                           0000F1   701 _B_1	=	0x00f1
                           0000F2   702 G$B_2$0$0 == 0x00f2
                           0000F2   703 _B_2	=	0x00f2
                           0000F3   704 G$B_3$0$0 == 0x00f3
                           0000F3   705 _B_3	=	0x00f3
                           0000F4   706 G$B_4$0$0 == 0x00f4
                           0000F4   707 _B_4	=	0x00f4
                           0000F5   708 G$B_5$0$0 == 0x00f5
                           0000F5   709 _B_5	=	0x00f5
                           0000F6   710 G$B_6$0$0 == 0x00f6
                           0000F6   711 _B_6	=	0x00f6
                           0000F7   712 G$B_7$0$0 == 0x00f7
                           0000F7   713 _B_7	=	0x00f7
                           0000A0   714 G$E2IE_0$0$0 == 0x00a0
                           0000A0   715 _E2IE_0	=	0x00a0
                           0000A1   716 G$E2IE_1$0$0 == 0x00a1
                           0000A1   717 _E2IE_1	=	0x00a1
                           0000A2   718 G$E2IE_2$0$0 == 0x00a2
                           0000A2   719 _E2IE_2	=	0x00a2
                           0000A3   720 G$E2IE_3$0$0 == 0x00a3
                           0000A3   721 _E2IE_3	=	0x00a3
                           0000A4   722 G$E2IE_4$0$0 == 0x00a4
                           0000A4   723 _E2IE_4	=	0x00a4
                           0000A5   724 G$E2IE_5$0$0 == 0x00a5
                           0000A5   725 _E2IE_5	=	0x00a5
                           0000A6   726 G$E2IE_6$0$0 == 0x00a6
                           0000A6   727 _E2IE_6	=	0x00a6
                           0000A7   728 G$E2IE_7$0$0 == 0x00a7
                           0000A7   729 _E2IE_7	=	0x00a7
                           0000C0   730 G$E2IP_0$0$0 == 0x00c0
                           0000C0   731 _E2IP_0	=	0x00c0
                           0000C1   732 G$E2IP_1$0$0 == 0x00c1
                           0000C1   733 _E2IP_1	=	0x00c1
                           0000C2   734 G$E2IP_2$0$0 == 0x00c2
                           0000C2   735 _E2IP_2	=	0x00c2
                           0000C3   736 G$E2IP_3$0$0 == 0x00c3
                           0000C3   737 _E2IP_3	=	0x00c3
                           0000C4   738 G$E2IP_4$0$0 == 0x00c4
                           0000C4   739 _E2IP_4	=	0x00c4
                           0000C5   740 G$E2IP_5$0$0 == 0x00c5
                           0000C5   741 _E2IP_5	=	0x00c5
                           0000C6   742 G$E2IP_6$0$0 == 0x00c6
                           0000C6   743 _E2IP_6	=	0x00c6
                           0000C7   744 G$E2IP_7$0$0 == 0x00c7
                           0000C7   745 _E2IP_7	=	0x00c7
                           000098   746 G$EIE_0$0$0 == 0x0098
                           000098   747 _EIE_0	=	0x0098
                           000099   748 G$EIE_1$0$0 == 0x0099
                           000099   749 _EIE_1	=	0x0099
                           00009A   750 G$EIE_2$0$0 == 0x009a
                           00009A   751 _EIE_2	=	0x009a
                           00009B   752 G$EIE_3$0$0 == 0x009b
                           00009B   753 _EIE_3	=	0x009b
                           00009C   754 G$EIE_4$0$0 == 0x009c
                           00009C   755 _EIE_4	=	0x009c
                           00009D   756 G$EIE_5$0$0 == 0x009d
                           00009D   757 _EIE_5	=	0x009d
                           00009E   758 G$EIE_6$0$0 == 0x009e
                           00009E   759 _EIE_6	=	0x009e
                           00009F   760 G$EIE_7$0$0 == 0x009f
                           00009F   761 _EIE_7	=	0x009f
                           0000B0   762 G$EIP_0$0$0 == 0x00b0
                           0000B0   763 _EIP_0	=	0x00b0
                           0000B1   764 G$EIP_1$0$0 == 0x00b1
                           0000B1   765 _EIP_1	=	0x00b1
                           0000B2   766 G$EIP_2$0$0 == 0x00b2
                           0000B2   767 _EIP_2	=	0x00b2
                           0000B3   768 G$EIP_3$0$0 == 0x00b3
                           0000B3   769 _EIP_3	=	0x00b3
                           0000B4   770 G$EIP_4$0$0 == 0x00b4
                           0000B4   771 _EIP_4	=	0x00b4
                           0000B5   772 G$EIP_5$0$0 == 0x00b5
                           0000B5   773 _EIP_5	=	0x00b5
                           0000B6   774 G$EIP_6$0$0 == 0x00b6
                           0000B6   775 _EIP_6	=	0x00b6
                           0000B7   776 G$EIP_7$0$0 == 0x00b7
                           0000B7   777 _EIP_7	=	0x00b7
                           0000A8   778 G$IE_0$0$0 == 0x00a8
                           0000A8   779 _IE_0	=	0x00a8
                           0000A9   780 G$IE_1$0$0 == 0x00a9
                           0000A9   781 _IE_1	=	0x00a9
                           0000AA   782 G$IE_2$0$0 == 0x00aa
                           0000AA   783 _IE_2	=	0x00aa
                           0000AB   784 G$IE_3$0$0 == 0x00ab
                           0000AB   785 _IE_3	=	0x00ab
                           0000AC   786 G$IE_4$0$0 == 0x00ac
                           0000AC   787 _IE_4	=	0x00ac
                           0000AD   788 G$IE_5$0$0 == 0x00ad
                           0000AD   789 _IE_5	=	0x00ad
                           0000AE   790 G$IE_6$0$0 == 0x00ae
                           0000AE   791 _IE_6	=	0x00ae
                           0000AF   792 G$IE_7$0$0 == 0x00af
                           0000AF   793 _IE_7	=	0x00af
                           0000AF   794 G$EA$0$0 == 0x00af
                           0000AF   795 _EA	=	0x00af
                           0000B8   796 G$IP_0$0$0 == 0x00b8
                           0000B8   797 _IP_0	=	0x00b8
                           0000B9   798 G$IP_1$0$0 == 0x00b9
                           0000B9   799 _IP_1	=	0x00b9
                           0000BA   800 G$IP_2$0$0 == 0x00ba
                           0000BA   801 _IP_2	=	0x00ba
                           0000BB   802 G$IP_3$0$0 == 0x00bb
                           0000BB   803 _IP_3	=	0x00bb
                           0000BC   804 G$IP_4$0$0 == 0x00bc
                           0000BC   805 _IP_4	=	0x00bc
                           0000BD   806 G$IP_5$0$0 == 0x00bd
                           0000BD   807 _IP_5	=	0x00bd
                           0000BE   808 G$IP_6$0$0 == 0x00be
                           0000BE   809 _IP_6	=	0x00be
                           0000BF   810 G$IP_7$0$0 == 0x00bf
                           0000BF   811 _IP_7	=	0x00bf
                           0000D0   812 G$P$0$0 == 0x00d0
                           0000D0   813 _P	=	0x00d0
                           0000D1   814 G$F1$0$0 == 0x00d1
                           0000D1   815 _F1	=	0x00d1
                           0000D2   816 G$OV$0$0 == 0x00d2
                           0000D2   817 _OV	=	0x00d2
                           0000D3   818 G$RS0$0$0 == 0x00d3
                           0000D3   819 _RS0	=	0x00d3
                           0000D4   820 G$RS1$0$0 == 0x00d4
                           0000D4   821 _RS1	=	0x00d4
                           0000D5   822 G$F0$0$0 == 0x00d5
                           0000D5   823 _F0	=	0x00d5
                           0000D6   824 G$AC$0$0 == 0x00d6
                           0000D6   825 _AC	=	0x00d6
                           0000D7   826 G$CY$0$0 == 0x00d7
                           0000D7   827 _CY	=	0x00d7
                           0000C8   828 G$PINA_0$0$0 == 0x00c8
                           0000C8   829 _PINA_0	=	0x00c8
                           0000C9   830 G$PINA_1$0$0 == 0x00c9
                           0000C9   831 _PINA_1	=	0x00c9
                           0000CA   832 G$PINA_2$0$0 == 0x00ca
                           0000CA   833 _PINA_2	=	0x00ca
                           0000CB   834 G$PINA_3$0$0 == 0x00cb
                           0000CB   835 _PINA_3	=	0x00cb
                           0000CC   836 G$PINA_4$0$0 == 0x00cc
                           0000CC   837 _PINA_4	=	0x00cc
                           0000CD   838 G$PINA_5$0$0 == 0x00cd
                           0000CD   839 _PINA_5	=	0x00cd
                           0000CE   840 G$PINA_6$0$0 == 0x00ce
                           0000CE   841 _PINA_6	=	0x00ce
                           0000CF   842 G$PINA_7$0$0 == 0x00cf
                           0000CF   843 _PINA_7	=	0x00cf
                           0000E8   844 G$PINB_0$0$0 == 0x00e8
                           0000E8   845 _PINB_0	=	0x00e8
                           0000E9   846 G$PINB_1$0$0 == 0x00e9
                           0000E9   847 _PINB_1	=	0x00e9
                           0000EA   848 G$PINB_2$0$0 == 0x00ea
                           0000EA   849 _PINB_2	=	0x00ea
                           0000EB   850 G$PINB_3$0$0 == 0x00eb
                           0000EB   851 _PINB_3	=	0x00eb
                           0000EC   852 G$PINB_4$0$0 == 0x00ec
                           0000EC   853 _PINB_4	=	0x00ec
                           0000ED   854 G$PINB_5$0$0 == 0x00ed
                           0000ED   855 _PINB_5	=	0x00ed
                           0000EE   856 G$PINB_6$0$0 == 0x00ee
                           0000EE   857 _PINB_6	=	0x00ee
                           0000EF   858 G$PINB_7$0$0 == 0x00ef
                           0000EF   859 _PINB_7	=	0x00ef
                           0000F8   860 G$PINC_0$0$0 == 0x00f8
                           0000F8   861 _PINC_0	=	0x00f8
                           0000F9   862 G$PINC_1$0$0 == 0x00f9
                           0000F9   863 _PINC_1	=	0x00f9
                           0000FA   864 G$PINC_2$0$0 == 0x00fa
                           0000FA   865 _PINC_2	=	0x00fa
                           0000FB   866 G$PINC_3$0$0 == 0x00fb
                           0000FB   867 _PINC_3	=	0x00fb
                           0000FC   868 G$PINC_4$0$0 == 0x00fc
                           0000FC   869 _PINC_4	=	0x00fc
                           0000FD   870 G$PINC_5$0$0 == 0x00fd
                           0000FD   871 _PINC_5	=	0x00fd
                           0000FE   872 G$PINC_6$0$0 == 0x00fe
                           0000FE   873 _PINC_6	=	0x00fe
                           0000FF   874 G$PINC_7$0$0 == 0x00ff
                           0000FF   875 _PINC_7	=	0x00ff
                           000080   876 G$PORTA_0$0$0 == 0x0080
                           000080   877 _PORTA_0	=	0x0080
                           000081   878 G$PORTA_1$0$0 == 0x0081
                           000081   879 _PORTA_1	=	0x0081
                           000082   880 G$PORTA_2$0$0 == 0x0082
                           000082   881 _PORTA_2	=	0x0082
                           000083   882 G$PORTA_3$0$0 == 0x0083
                           000083   883 _PORTA_3	=	0x0083
                           000084   884 G$PORTA_4$0$0 == 0x0084
                           000084   885 _PORTA_4	=	0x0084
                           000085   886 G$PORTA_5$0$0 == 0x0085
                           000085   887 _PORTA_5	=	0x0085
                           000086   888 G$PORTA_6$0$0 == 0x0086
                           000086   889 _PORTA_6	=	0x0086
                           000087   890 G$PORTA_7$0$0 == 0x0087
                           000087   891 _PORTA_7	=	0x0087
                           000088   892 G$PORTB_0$0$0 == 0x0088
                           000088   893 _PORTB_0	=	0x0088
                           000089   894 G$PORTB_1$0$0 == 0x0089
                           000089   895 _PORTB_1	=	0x0089
                           00008A   896 G$PORTB_2$0$0 == 0x008a
                           00008A   897 _PORTB_2	=	0x008a
                           00008B   898 G$PORTB_3$0$0 == 0x008b
                           00008B   899 _PORTB_3	=	0x008b
                           00008C   900 G$PORTB_4$0$0 == 0x008c
                           00008C   901 _PORTB_4	=	0x008c
                           00008D   902 G$PORTB_5$0$0 == 0x008d
                           00008D   903 _PORTB_5	=	0x008d
                           00008E   904 G$PORTB_6$0$0 == 0x008e
                           00008E   905 _PORTB_6	=	0x008e
                           00008F   906 G$PORTB_7$0$0 == 0x008f
                           00008F   907 _PORTB_7	=	0x008f
                           000090   908 G$PORTC_0$0$0 == 0x0090
                           000090   909 _PORTC_0	=	0x0090
                           000091   910 G$PORTC_1$0$0 == 0x0091
                           000091   911 _PORTC_1	=	0x0091
                           000092   912 G$PORTC_2$0$0 == 0x0092
                           000092   913 _PORTC_2	=	0x0092
                           000093   914 G$PORTC_3$0$0 == 0x0093
                           000093   915 _PORTC_3	=	0x0093
                           000094   916 G$PORTC_4$0$0 == 0x0094
                           000094   917 _PORTC_4	=	0x0094
                           000095   918 G$PORTC_5$0$0 == 0x0095
                           000095   919 _PORTC_5	=	0x0095
                           000096   920 G$PORTC_6$0$0 == 0x0096
                           000096   921 _PORTC_6	=	0x0096
                           000097   922 G$PORTC_7$0$0 == 0x0097
                           000097   923 _PORTC_7	=	0x0097
                                    924 ;--------------------------------------------------------
                                    925 ; overlayable register banks
                                    926 ;--------------------------------------------------------
                                    927 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        928 	.ds 8
                                    929 ;--------------------------------------------------------
                                    930 ; internal ram data
                                    931 ;--------------------------------------------------------
                                    932 	.area DSEG    (DATA)
                                    933 ;--------------------------------------------------------
                                    934 ; overlayable items in internal ram 
                                    935 ;--------------------------------------------------------
                                    936 ;--------------------------------------------------------
                                    937 ; indirectly addressable internal ram data
                                    938 ;--------------------------------------------------------
                                    939 	.area ISEG    (DATA)
                                    940 ;--------------------------------------------------------
                                    941 ; absolute internal ram data
                                    942 ;--------------------------------------------------------
                                    943 	.area IABS    (ABS,DATA)
                                    944 	.area IABS    (ABS,DATA)
                                    945 ;--------------------------------------------------------
                                    946 ; bit data
                                    947 ;--------------------------------------------------------
                                    948 	.area BSEG    (BIT)
                                    949 ;--------------------------------------------------------
                                    950 ; paged external ram data
                                    951 ;--------------------------------------------------------
                                    952 	.area PSEG    (PAG,XDATA)
                                    953 ;--------------------------------------------------------
                                    954 ; external ram data
                                    955 ;--------------------------------------------------------
                                    956 	.area XSEG    (XDATA)
                           007020   957 G$ADCCH0VAL0$0$0 == 0x7020
                           007020   958 _ADCCH0VAL0	=	0x7020
                           007021   959 G$ADCCH0VAL1$0$0 == 0x7021
                           007021   960 _ADCCH0VAL1	=	0x7021
                           007020   961 G$ADCCH0VAL$0$0 == 0x7020
                           007020   962 _ADCCH0VAL	=	0x7020
                           007022   963 G$ADCCH1VAL0$0$0 == 0x7022
                           007022   964 _ADCCH1VAL0	=	0x7022
                           007023   965 G$ADCCH1VAL1$0$0 == 0x7023
                           007023   966 _ADCCH1VAL1	=	0x7023
                           007022   967 G$ADCCH1VAL$0$0 == 0x7022
                           007022   968 _ADCCH1VAL	=	0x7022
                           007024   969 G$ADCCH2VAL0$0$0 == 0x7024
                           007024   970 _ADCCH2VAL0	=	0x7024
                           007025   971 G$ADCCH2VAL1$0$0 == 0x7025
                           007025   972 _ADCCH2VAL1	=	0x7025
                           007024   973 G$ADCCH2VAL$0$0 == 0x7024
                           007024   974 _ADCCH2VAL	=	0x7024
                           007026   975 G$ADCCH3VAL0$0$0 == 0x7026
                           007026   976 _ADCCH3VAL0	=	0x7026
                           007027   977 G$ADCCH3VAL1$0$0 == 0x7027
                           007027   978 _ADCCH3VAL1	=	0x7027
                           007026   979 G$ADCCH3VAL$0$0 == 0x7026
                           007026   980 _ADCCH3VAL	=	0x7026
                           007028   981 G$ADCTUNE0$0$0 == 0x7028
                           007028   982 _ADCTUNE0	=	0x7028
                           007029   983 G$ADCTUNE1$0$0 == 0x7029
                           007029   984 _ADCTUNE1	=	0x7029
                           00702A   985 G$ADCTUNE2$0$0 == 0x702a
                           00702A   986 _ADCTUNE2	=	0x702a
                           007010   987 G$DMA0ADDR0$0$0 == 0x7010
                           007010   988 _DMA0ADDR0	=	0x7010
                           007011   989 G$DMA0ADDR1$0$0 == 0x7011
                           007011   990 _DMA0ADDR1	=	0x7011
                           007010   991 G$DMA0ADDR$0$0 == 0x7010
                           007010   992 _DMA0ADDR	=	0x7010
                           007014   993 G$DMA0CONFIG$0$0 == 0x7014
                           007014   994 _DMA0CONFIG	=	0x7014
                           007012   995 G$DMA1ADDR0$0$0 == 0x7012
                           007012   996 _DMA1ADDR0	=	0x7012
                           007013   997 G$DMA1ADDR1$0$0 == 0x7013
                           007013   998 _DMA1ADDR1	=	0x7013
                           007012   999 G$DMA1ADDR$0$0 == 0x7012
                           007012  1000 _DMA1ADDR	=	0x7012
                           007015  1001 G$DMA1CONFIG$0$0 == 0x7015
                           007015  1002 _DMA1CONFIG	=	0x7015
                           007070  1003 G$FRCOSCCONFIG$0$0 == 0x7070
                           007070  1004 _FRCOSCCONFIG	=	0x7070
                           007071  1005 G$FRCOSCCTRL$0$0 == 0x7071
                           007071  1006 _FRCOSCCTRL	=	0x7071
                           007076  1007 G$FRCOSCFREQ0$0$0 == 0x7076
                           007076  1008 _FRCOSCFREQ0	=	0x7076
                           007077  1009 G$FRCOSCFREQ1$0$0 == 0x7077
                           007077  1010 _FRCOSCFREQ1	=	0x7077
                           007076  1011 G$FRCOSCFREQ$0$0 == 0x7076
                           007076  1012 _FRCOSCFREQ	=	0x7076
                           007072  1013 G$FRCOSCKFILT0$0$0 == 0x7072
                           007072  1014 _FRCOSCKFILT0	=	0x7072
                           007073  1015 G$FRCOSCKFILT1$0$0 == 0x7073
                           007073  1016 _FRCOSCKFILT1	=	0x7073
                           007072  1017 G$FRCOSCKFILT$0$0 == 0x7072
                           007072  1018 _FRCOSCKFILT	=	0x7072
                           007078  1019 G$FRCOSCPER0$0$0 == 0x7078
                           007078  1020 _FRCOSCPER0	=	0x7078
                           007079  1021 G$FRCOSCPER1$0$0 == 0x7079
                           007079  1022 _FRCOSCPER1	=	0x7079
                           007078  1023 G$FRCOSCPER$0$0 == 0x7078
                           007078  1024 _FRCOSCPER	=	0x7078
                           007074  1025 G$FRCOSCREF0$0$0 == 0x7074
                           007074  1026 _FRCOSCREF0	=	0x7074
                           007075  1027 G$FRCOSCREF1$0$0 == 0x7075
                           007075  1028 _FRCOSCREF1	=	0x7075
                           007074  1029 G$FRCOSCREF$0$0 == 0x7074
                           007074  1030 _FRCOSCREF	=	0x7074
                           007007  1031 G$ANALOGA$0$0 == 0x7007
                           007007  1032 _ANALOGA	=	0x7007
                           00700C  1033 G$GPIOENABLE$0$0 == 0x700c
                           00700C  1034 _GPIOENABLE	=	0x700c
                           007003  1035 G$EXTIRQ$0$0 == 0x7003
                           007003  1036 _EXTIRQ	=	0x7003
                           007000  1037 G$INTCHGA$0$0 == 0x7000
                           007000  1038 _INTCHGA	=	0x7000
                           007001  1039 G$INTCHGB$0$0 == 0x7001
                           007001  1040 _INTCHGB	=	0x7001
                           007002  1041 G$INTCHGC$0$0 == 0x7002
                           007002  1042 _INTCHGC	=	0x7002
                           007008  1043 G$PALTA$0$0 == 0x7008
                           007008  1044 _PALTA	=	0x7008
                           007009  1045 G$PALTB$0$0 == 0x7009
                           007009  1046 _PALTB	=	0x7009
                           00700A  1047 G$PALTC$0$0 == 0x700a
                           00700A  1048 _PALTC	=	0x700a
                           007046  1049 G$PALTRADIO$0$0 == 0x7046
                           007046  1050 _PALTRADIO	=	0x7046
                           007004  1051 G$PINCHGA$0$0 == 0x7004
                           007004  1052 _PINCHGA	=	0x7004
                           007005  1053 G$PINCHGB$0$0 == 0x7005
                           007005  1054 _PINCHGB	=	0x7005
                           007006  1055 G$PINCHGC$0$0 == 0x7006
                           007006  1056 _PINCHGC	=	0x7006
                           00700B  1057 G$PINSEL$0$0 == 0x700b
                           00700B  1058 _PINSEL	=	0x700b
                           007060  1059 G$LPOSCCONFIG$0$0 == 0x7060
                           007060  1060 _LPOSCCONFIG	=	0x7060
                           007066  1061 G$LPOSCFREQ0$0$0 == 0x7066
                           007066  1062 _LPOSCFREQ0	=	0x7066
                           007067  1063 G$LPOSCFREQ1$0$0 == 0x7067
                           007067  1064 _LPOSCFREQ1	=	0x7067
                           007066  1065 G$LPOSCFREQ$0$0 == 0x7066
                           007066  1066 _LPOSCFREQ	=	0x7066
                           007062  1067 G$LPOSCKFILT0$0$0 == 0x7062
                           007062  1068 _LPOSCKFILT0	=	0x7062
                           007063  1069 G$LPOSCKFILT1$0$0 == 0x7063
                           007063  1070 _LPOSCKFILT1	=	0x7063
                           007062  1071 G$LPOSCKFILT$0$0 == 0x7062
                           007062  1072 _LPOSCKFILT	=	0x7062
                           007068  1073 G$LPOSCPER0$0$0 == 0x7068
                           007068  1074 _LPOSCPER0	=	0x7068
                           007069  1075 G$LPOSCPER1$0$0 == 0x7069
                           007069  1076 _LPOSCPER1	=	0x7069
                           007068  1077 G$LPOSCPER$0$0 == 0x7068
                           007068  1078 _LPOSCPER	=	0x7068
                           007064  1079 G$LPOSCREF0$0$0 == 0x7064
                           007064  1080 _LPOSCREF0	=	0x7064
                           007065  1081 G$LPOSCREF1$0$0 == 0x7065
                           007065  1082 _LPOSCREF1	=	0x7065
                           007064  1083 G$LPOSCREF$0$0 == 0x7064
                           007064  1084 _LPOSCREF	=	0x7064
                           007054  1085 G$LPXOSCGM$0$0 == 0x7054
                           007054  1086 _LPXOSCGM	=	0x7054
                           007F01  1087 G$MISCCTRL$0$0 == 0x7f01
                           007F01  1088 _MISCCTRL	=	0x7f01
                           007053  1089 G$OSCCALIB$0$0 == 0x7053
                           007053  1090 _OSCCALIB	=	0x7053
                           007050  1091 G$OSCFORCERUN$0$0 == 0x7050
                           007050  1092 _OSCFORCERUN	=	0x7050
                           007052  1093 G$OSCREADY$0$0 == 0x7052
                           007052  1094 _OSCREADY	=	0x7052
                           007051  1095 G$OSCRUN$0$0 == 0x7051
                           007051  1096 _OSCRUN	=	0x7051
                           007040  1097 G$RADIOFDATAADDR0$0$0 == 0x7040
                           007040  1098 _RADIOFDATAADDR0	=	0x7040
                           007041  1099 G$RADIOFDATAADDR1$0$0 == 0x7041
                           007041  1100 _RADIOFDATAADDR1	=	0x7041
                           007040  1101 G$RADIOFDATAADDR$0$0 == 0x7040
                           007040  1102 _RADIOFDATAADDR	=	0x7040
                           007042  1103 G$RADIOFSTATADDR0$0$0 == 0x7042
                           007042  1104 _RADIOFSTATADDR0	=	0x7042
                           007043  1105 G$RADIOFSTATADDR1$0$0 == 0x7043
                           007043  1106 _RADIOFSTATADDR1	=	0x7043
                           007042  1107 G$RADIOFSTATADDR$0$0 == 0x7042
                           007042  1108 _RADIOFSTATADDR	=	0x7042
                           007044  1109 G$RADIOMUX$0$0 == 0x7044
                           007044  1110 _RADIOMUX	=	0x7044
                           007084  1111 G$SCRATCH0$0$0 == 0x7084
                           007084  1112 _SCRATCH0	=	0x7084
                           007085  1113 G$SCRATCH1$0$0 == 0x7085
                           007085  1114 _SCRATCH1	=	0x7085
                           007086  1115 G$SCRATCH2$0$0 == 0x7086
                           007086  1116 _SCRATCH2	=	0x7086
                           007087  1117 G$SCRATCH3$0$0 == 0x7087
                           007087  1118 _SCRATCH3	=	0x7087
                           007F00  1119 G$SILICONREV$0$0 == 0x7f00
                           007F00  1120 _SILICONREV	=	0x7f00
                           007F19  1121 G$XTALAMPL$0$0 == 0x7f19
                           007F19  1122 _XTALAMPL	=	0x7f19
                           007F18  1123 G$XTALOSC$0$0 == 0x7f18
                           007F18  1124 _XTALOSC	=	0x7f18
                           007F1A  1125 G$XTALREADY$0$0 == 0x7f1a
                           007F1A  1126 _XTALREADY	=	0x7f1a
                                   1127 ;--------------------------------------------------------
                                   1128 ; absolute external ram data
                                   1129 ;--------------------------------------------------------
                                   1130 	.area XABS    (ABS,XDATA)
                                   1131 ;--------------------------------------------------------
                                   1132 ; external initialized ram data
                                   1133 ;--------------------------------------------------------
                                   1134 	.area XISEG   (XDATA)
                                   1135 	.area HOME    (CODE)
                                   1136 	.area GSINIT0 (CODE)
                                   1137 	.area GSINIT1 (CODE)
                                   1138 	.area GSINIT2 (CODE)
                                   1139 	.area GSINIT3 (CODE)
                                   1140 	.area GSINIT4 (CODE)
                                   1141 	.area GSINIT5 (CODE)
                                   1142 	.area GSINIT  (CODE)
                                   1143 	.area GSFINAL (CODE)
                                   1144 	.area CSEG    (CODE)
                                   1145 ;--------------------------------------------------------
                                   1146 ; global & static initialisations
                                   1147 ;--------------------------------------------------------
                                   1148 	.area HOME    (CODE)
                                   1149 	.area GSINIT  (CODE)
                                   1150 	.area GSFINAL (CODE)
                                   1151 	.area GSINIT  (CODE)
                                   1152 ;--------------------------------------------------------
                                   1153 ; Home
                                   1154 ;--------------------------------------------------------
                                   1155 	.area HOME    (CODE)
                                   1156 	.area HOME    (CODE)
                                   1157 ;--------------------------------------------------------
                                   1158 ; code
                                   1159 ;--------------------------------------------------------
                                   1160 	.area CSEG    (CODE)
                                   1161 	.area CSEG    (CODE)
                                   1162 	.area CONST   (CODE)
                           000000  1163 G$remoteaddr$0$0 == .
      004E79                       1164 _remoteaddr:
      004E79 32                    1165 	.db #0x32	; 50	'2'
      004E7A 34                    1166 	.db #0x34	; 52	'4'
      004E7B 00                    1167 	.db #0x00	; 0
      004E7C 00                    1168 	.db #0x00	; 0
      004E7D 00                    1169 	.db 0x00
                           000005  1170 G$localaddr$0$0 == .
      004E7E                       1171 _localaddr:
      004E7E 33                    1172 	.db #0x33	; 51	'3'
      004E7F 34                    1173 	.db #0x34	; 52	'4'
      004E80 00                    1174 	.db #0x00	; 0
      004E81 00                    1175 	.db #0x00	; 0
      004E82 00                    1176 	.db 0x00
      004E83 FF                    1177 	.db #0xff	; 255
      004E84 FF                    1178 	.db #0xff	; 255
      004E85 FF                    1179 	.db #0xff	; 255
      004E86 FF                    1180 	.db #0xff	; 255
      004E87 00                    1181 	.db 0x00
                           00000F  1182 G$framing_insert_counter$0$0 == .
      004E88                       1183 _framing_insert_counter:
      004E88 01                    1184 	.db #0x01	; 1
                           000010  1185 G$framing_counter_pos$0$0 == .
      004E89                       1186 _framing_counter_pos:
      004E89 00                    1187 	.db #0x00	; 0
                           000011  1188 G$lpxosc_settlingtime$0$0 == .
      004E8A                       1189 _lpxosc_settlingtime:
      004E8A B8 0B                 1190 	.byte #0xb8,#0x0b	; 3000
                                   1191 	.area XINIT   (CODE)
                                   1192 	.area CABS    (ABS,CODE)
