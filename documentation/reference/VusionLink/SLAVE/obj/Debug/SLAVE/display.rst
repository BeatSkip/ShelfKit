                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module display
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _PORTC_7
                                     12 	.globl _PORTC_6
                                     13 	.globl _PORTC_5
                                     14 	.globl _PORTC_4
                                     15 	.globl _PORTC_3
                                     16 	.globl _PORTC_2
                                     17 	.globl _PORTC_1
                                     18 	.globl _PORTC_0
                                     19 	.globl _PORTB_7
                                     20 	.globl _PORTB_6
                                     21 	.globl _PORTB_5
                                     22 	.globl _PORTB_4
                                     23 	.globl _PORTB_3
                                     24 	.globl _PORTB_2
                                     25 	.globl _PORTB_1
                                     26 	.globl _PORTB_0
                                     27 	.globl _PORTA_7
                                     28 	.globl _PORTA_6
                                     29 	.globl _PORTA_5
                                     30 	.globl _PORTA_4
                                     31 	.globl _PORTA_3
                                     32 	.globl _PORTA_2
                                     33 	.globl _PORTA_1
                                     34 	.globl _PORTA_0
                                     35 	.globl _PINC_7
                                     36 	.globl _PINC_6
                                     37 	.globl _PINC_5
                                     38 	.globl _PINC_4
                                     39 	.globl _PINC_3
                                     40 	.globl _PINC_2
                                     41 	.globl _PINC_1
                                     42 	.globl _PINC_0
                                     43 	.globl _PINB_7
                                     44 	.globl _PINB_6
                                     45 	.globl _PINB_5
                                     46 	.globl _PINB_4
                                     47 	.globl _PINB_3
                                     48 	.globl _PINB_2
                                     49 	.globl _PINB_1
                                     50 	.globl _PINB_0
                                     51 	.globl _PINA_7
                                     52 	.globl _PINA_6
                                     53 	.globl _PINA_5
                                     54 	.globl _PINA_4
                                     55 	.globl _PINA_3
                                     56 	.globl _PINA_2
                                     57 	.globl _PINA_1
                                     58 	.globl _PINA_0
                                     59 	.globl _CY
                                     60 	.globl _AC
                                     61 	.globl _F0
                                     62 	.globl _RS1
                                     63 	.globl _RS0
                                     64 	.globl _OV
                                     65 	.globl _F1
                                     66 	.globl _P
                                     67 	.globl _IP_7
                                     68 	.globl _IP_6
                                     69 	.globl _IP_5
                                     70 	.globl _IP_4
                                     71 	.globl _IP_3
                                     72 	.globl _IP_2
                                     73 	.globl _IP_1
                                     74 	.globl _IP_0
                                     75 	.globl _EA
                                     76 	.globl _IE_7
                                     77 	.globl _IE_6
                                     78 	.globl _IE_5
                                     79 	.globl _IE_4
                                     80 	.globl _IE_3
                                     81 	.globl _IE_2
                                     82 	.globl _IE_1
                                     83 	.globl _IE_0
                                     84 	.globl _EIP_7
                                     85 	.globl _EIP_6
                                     86 	.globl _EIP_5
                                     87 	.globl _EIP_4
                                     88 	.globl _EIP_3
                                     89 	.globl _EIP_2
                                     90 	.globl _EIP_1
                                     91 	.globl _EIP_0
                                     92 	.globl _EIE_7
                                     93 	.globl _EIE_6
                                     94 	.globl _EIE_5
                                     95 	.globl _EIE_4
                                     96 	.globl _EIE_3
                                     97 	.globl _EIE_2
                                     98 	.globl _EIE_1
                                     99 	.globl _EIE_0
                                    100 	.globl _E2IP_7
                                    101 	.globl _E2IP_6
                                    102 	.globl _E2IP_5
                                    103 	.globl _E2IP_4
                                    104 	.globl _E2IP_3
                                    105 	.globl _E2IP_2
                                    106 	.globl _E2IP_1
                                    107 	.globl _E2IP_0
                                    108 	.globl _E2IE_7
                                    109 	.globl _E2IE_6
                                    110 	.globl _E2IE_5
                                    111 	.globl _E2IE_4
                                    112 	.globl _E2IE_3
                                    113 	.globl _E2IE_2
                                    114 	.globl _E2IE_1
                                    115 	.globl _E2IE_0
                                    116 	.globl _B_7
                                    117 	.globl _B_6
                                    118 	.globl _B_5
                                    119 	.globl _B_4
                                    120 	.globl _B_3
                                    121 	.globl _B_2
                                    122 	.globl _B_1
                                    123 	.globl _B_0
                                    124 	.globl _ACC_7
                                    125 	.globl _ACC_6
                                    126 	.globl _ACC_5
                                    127 	.globl _ACC_4
                                    128 	.globl _ACC_3
                                    129 	.globl _ACC_2
                                    130 	.globl _ACC_1
                                    131 	.globl _ACC_0
                                    132 	.globl _WTSTAT
                                    133 	.globl _WTIRQEN
                                    134 	.globl _WTEVTD
                                    135 	.globl _WTEVTD1
                                    136 	.globl _WTEVTD0
                                    137 	.globl _WTEVTC
                                    138 	.globl _WTEVTC1
                                    139 	.globl _WTEVTC0
                                    140 	.globl _WTEVTB
                                    141 	.globl _WTEVTB1
                                    142 	.globl _WTEVTB0
                                    143 	.globl _WTEVTA
                                    144 	.globl _WTEVTA1
                                    145 	.globl _WTEVTA0
                                    146 	.globl _WTCNTR1
                                    147 	.globl _WTCNTB
                                    148 	.globl _WTCNTB1
                                    149 	.globl _WTCNTB0
                                    150 	.globl _WTCNTA
                                    151 	.globl _WTCNTA1
                                    152 	.globl _WTCNTA0
                                    153 	.globl _WTCFGB
                                    154 	.globl _WTCFGA
                                    155 	.globl _WDTRESET
                                    156 	.globl _WDTCFG
                                    157 	.globl _U1STATUS
                                    158 	.globl _U1SHREG
                                    159 	.globl _U1MODE
                                    160 	.globl _U1CTRL
                                    161 	.globl _U0STATUS
                                    162 	.globl _U0SHREG
                                    163 	.globl _U0MODE
                                    164 	.globl _U0CTRL
                                    165 	.globl _T2STATUS
                                    166 	.globl _T2PERIOD
                                    167 	.globl _T2PERIOD1
                                    168 	.globl _T2PERIOD0
                                    169 	.globl _T2MODE
                                    170 	.globl _T2CNT
                                    171 	.globl _T2CNT1
                                    172 	.globl _T2CNT0
                                    173 	.globl _T2CLKSRC
                                    174 	.globl _T1STATUS
                                    175 	.globl _T1PERIOD
                                    176 	.globl _T1PERIOD1
                                    177 	.globl _T1PERIOD0
                                    178 	.globl _T1MODE
                                    179 	.globl _T1CNT
                                    180 	.globl _T1CNT1
                                    181 	.globl _T1CNT0
                                    182 	.globl _T1CLKSRC
                                    183 	.globl _T0STATUS
                                    184 	.globl _T0PERIOD
                                    185 	.globl _T0PERIOD1
                                    186 	.globl _T0PERIOD0
                                    187 	.globl _T0MODE
                                    188 	.globl _T0CNT
                                    189 	.globl _T0CNT1
                                    190 	.globl _T0CNT0
                                    191 	.globl _T0CLKSRC
                                    192 	.globl _SPSTATUS
                                    193 	.globl _SPSHREG
                                    194 	.globl _SPMODE
                                    195 	.globl _SPCLKSRC
                                    196 	.globl _RADIOSTAT
                                    197 	.globl _RADIOSTAT1
                                    198 	.globl _RADIOSTAT0
                                    199 	.globl _RADIODATA
                                    200 	.globl _RADIODATA3
                                    201 	.globl _RADIODATA2
                                    202 	.globl _RADIODATA1
                                    203 	.globl _RADIODATA0
                                    204 	.globl _RADIOADDR
                                    205 	.globl _RADIOADDR1
                                    206 	.globl _RADIOADDR0
                                    207 	.globl _RADIOACC
                                    208 	.globl _OC1STATUS
                                    209 	.globl _OC1PIN
                                    210 	.globl _OC1MODE
                                    211 	.globl _OC1COMP
                                    212 	.globl _OC1COMP1
                                    213 	.globl _OC1COMP0
                                    214 	.globl _OC0STATUS
                                    215 	.globl _OC0PIN
                                    216 	.globl _OC0MODE
                                    217 	.globl _OC0COMP
                                    218 	.globl _OC0COMP1
                                    219 	.globl _OC0COMP0
                                    220 	.globl _NVSTATUS
                                    221 	.globl _NVKEY
                                    222 	.globl _NVDATA
                                    223 	.globl _NVDATA1
                                    224 	.globl _NVDATA0
                                    225 	.globl _NVADDR
                                    226 	.globl _NVADDR1
                                    227 	.globl _NVADDR0
                                    228 	.globl _IC1STATUS
                                    229 	.globl _IC1MODE
                                    230 	.globl _IC1CAPT
                                    231 	.globl _IC1CAPT1
                                    232 	.globl _IC1CAPT0
                                    233 	.globl _IC0STATUS
                                    234 	.globl _IC0MODE
                                    235 	.globl _IC0CAPT
                                    236 	.globl _IC0CAPT1
                                    237 	.globl _IC0CAPT0
                                    238 	.globl _PORTR
                                    239 	.globl _PORTC
                                    240 	.globl _PORTB
                                    241 	.globl _PORTA
                                    242 	.globl _PINR
                                    243 	.globl _PINC
                                    244 	.globl _PINB
                                    245 	.globl _PINA
                                    246 	.globl _DIRR
                                    247 	.globl _DIRC
                                    248 	.globl _DIRB
                                    249 	.globl _DIRA
                                    250 	.globl _DBGLNKSTAT
                                    251 	.globl _DBGLNKBUF
                                    252 	.globl _CODECONFIG
                                    253 	.globl _CLKSTAT
                                    254 	.globl _CLKCON
                                    255 	.globl _ANALOGCOMP
                                    256 	.globl _ADCCONV
                                    257 	.globl _ADCCLKSRC
                                    258 	.globl _ADCCH3CONFIG
                                    259 	.globl _ADCCH2CONFIG
                                    260 	.globl _ADCCH1CONFIG
                                    261 	.globl _ADCCH0CONFIG
                                    262 	.globl __XPAGE
                                    263 	.globl _XPAGE
                                    264 	.globl _SP
                                    265 	.globl _PSW
                                    266 	.globl _PCON
                                    267 	.globl _IP
                                    268 	.globl _IE
                                    269 	.globl _EIP
                                    270 	.globl _EIE
                                    271 	.globl _E2IP
                                    272 	.globl _E2IE
                                    273 	.globl _DPS
                                    274 	.globl _DPTR1
                                    275 	.globl _DPTR0
                                    276 	.globl _DPL1
                                    277 	.globl _DPL
                                    278 	.globl _DPH1
                                    279 	.globl _DPH
                                    280 	.globl _B
                                    281 	.globl _ACC
                                    282 	.globl _XTALREADY
                                    283 	.globl _XTALOSC
                                    284 	.globl _XTALAMPL
                                    285 	.globl _SILICONREV
                                    286 	.globl _SCRATCH3
                                    287 	.globl _SCRATCH2
                                    288 	.globl _SCRATCH1
                                    289 	.globl _SCRATCH0
                                    290 	.globl _RADIOMUX
                                    291 	.globl _RADIOFSTATADDR
                                    292 	.globl _RADIOFSTATADDR1
                                    293 	.globl _RADIOFSTATADDR0
                                    294 	.globl _RADIOFDATAADDR
                                    295 	.globl _RADIOFDATAADDR1
                                    296 	.globl _RADIOFDATAADDR0
                                    297 	.globl _OSCRUN
                                    298 	.globl _OSCREADY
                                    299 	.globl _OSCFORCERUN
                                    300 	.globl _OSCCALIB
                                    301 	.globl _MISCCTRL
                                    302 	.globl _LPXOSCGM
                                    303 	.globl _LPOSCREF
                                    304 	.globl _LPOSCREF1
                                    305 	.globl _LPOSCREF0
                                    306 	.globl _LPOSCPER
                                    307 	.globl _LPOSCPER1
                                    308 	.globl _LPOSCPER0
                                    309 	.globl _LPOSCKFILT
                                    310 	.globl _LPOSCKFILT1
                                    311 	.globl _LPOSCKFILT0
                                    312 	.globl _LPOSCFREQ
                                    313 	.globl _LPOSCFREQ1
                                    314 	.globl _LPOSCFREQ0
                                    315 	.globl _LPOSCCONFIG
                                    316 	.globl _PINSEL
                                    317 	.globl _PINCHGC
                                    318 	.globl _PINCHGB
                                    319 	.globl _PINCHGA
                                    320 	.globl _PALTRADIO
                                    321 	.globl _PALTC
                                    322 	.globl _PALTB
                                    323 	.globl _PALTA
                                    324 	.globl _INTCHGC
                                    325 	.globl _INTCHGB
                                    326 	.globl _INTCHGA
                                    327 	.globl _EXTIRQ
                                    328 	.globl _GPIOENABLE
                                    329 	.globl _ANALOGA
                                    330 	.globl _FRCOSCREF
                                    331 	.globl _FRCOSCREF1
                                    332 	.globl _FRCOSCREF0
                                    333 	.globl _FRCOSCPER
                                    334 	.globl _FRCOSCPER1
                                    335 	.globl _FRCOSCPER0
                                    336 	.globl _FRCOSCKFILT
                                    337 	.globl _FRCOSCKFILT1
                                    338 	.globl _FRCOSCKFILT0
                                    339 	.globl _FRCOSCFREQ
                                    340 	.globl _FRCOSCFREQ1
                                    341 	.globl _FRCOSCFREQ0
                                    342 	.globl _FRCOSCCTRL
                                    343 	.globl _FRCOSCCONFIG
                                    344 	.globl _DMA1CONFIG
                                    345 	.globl _DMA1ADDR
                                    346 	.globl _DMA1ADDR1
                                    347 	.globl _DMA1ADDR0
                                    348 	.globl _DMA0CONFIG
                                    349 	.globl _DMA0ADDR
                                    350 	.globl _DMA0ADDR1
                                    351 	.globl _DMA0ADDR0
                                    352 	.globl _ADCTUNE2
                                    353 	.globl _ADCTUNE1
                                    354 	.globl _ADCTUNE0
                                    355 	.globl _ADCCH3VAL
                                    356 	.globl _ADCCH3VAL1
                                    357 	.globl _ADCCH3VAL0
                                    358 	.globl _ADCCH2VAL
                                    359 	.globl _ADCCH2VAL1
                                    360 	.globl _ADCCH2VAL0
                                    361 	.globl _ADCCH1VAL
                                    362 	.globl _ADCCH1VAL1
                                    363 	.globl _ADCCH1VAL0
                                    364 	.globl _ADCCH0VAL
                                    365 	.globl _ADCCH0VAL1
                                    366 	.globl _ADCCH0VAL0
                                    367 	.globl _display_timing
                                    368 	.globl _per_test_counter_previous
                                    369 	.globl _per_test_counter
                                    370 	.globl _display_received_packet
                                    371 	.globl _dbglink_received_packet
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
                           000000   933 G$per_test_counter$0$0==.
      00001A                        934 _per_test_counter::
      00001A                        935 	.ds 2
                           000002   936 G$per_test_counter_previous$0$0==.
      00001C                        937 _per_test_counter_previous::
      00001C                        938 	.ds 2
                           000004   939 G$display_timing$0$0==.
      00001E                        940 _display_timing::
      00001E                        941 	.ds 1
                                    942 ;--------------------------------------------------------
                                    943 ; overlayable items in internal ram 
                                    944 ;--------------------------------------------------------
                                    945 	.area	OSEG    (OVR,DATA)
                                    946 	.area	OSEG    (OVR,DATA)
                                    947 ;--------------------------------------------------------
                                    948 ; indirectly addressable internal ram data
                                    949 ;--------------------------------------------------------
                                    950 	.area ISEG    (DATA)
                                    951 ;--------------------------------------------------------
                                    952 ; absolute internal ram data
                                    953 ;--------------------------------------------------------
                                    954 	.area IABS    (ABS,DATA)
                                    955 	.area IABS    (ABS,DATA)
                                    956 ;--------------------------------------------------------
                                    957 ; bit data
                                    958 ;--------------------------------------------------------
                                    959 	.area BSEG    (BIT)
                           000000   960 Ldisplay.display_received_packet$sloc0$1$0==.
      000001                        961 _display_received_packet_sloc0_1_0:
      000001                        962 	.ds 1
                                    963 ;--------------------------------------------------------
                                    964 ; paged external ram data
                                    965 ;--------------------------------------------------------
                                    966 	.area PSEG    (PAG,XDATA)
                                    967 ;--------------------------------------------------------
                                    968 ; external ram data
                                    969 ;--------------------------------------------------------
                                    970 	.area XSEG    (XDATA)
                           007020   971 G$ADCCH0VAL0$0$0 == 0x7020
                           007020   972 _ADCCH0VAL0	=	0x7020
                           007021   973 G$ADCCH0VAL1$0$0 == 0x7021
                           007021   974 _ADCCH0VAL1	=	0x7021
                           007020   975 G$ADCCH0VAL$0$0 == 0x7020
                           007020   976 _ADCCH0VAL	=	0x7020
                           007022   977 G$ADCCH1VAL0$0$0 == 0x7022
                           007022   978 _ADCCH1VAL0	=	0x7022
                           007023   979 G$ADCCH1VAL1$0$0 == 0x7023
                           007023   980 _ADCCH1VAL1	=	0x7023
                           007022   981 G$ADCCH1VAL$0$0 == 0x7022
                           007022   982 _ADCCH1VAL	=	0x7022
                           007024   983 G$ADCCH2VAL0$0$0 == 0x7024
                           007024   984 _ADCCH2VAL0	=	0x7024
                           007025   985 G$ADCCH2VAL1$0$0 == 0x7025
                           007025   986 _ADCCH2VAL1	=	0x7025
                           007024   987 G$ADCCH2VAL$0$0 == 0x7024
                           007024   988 _ADCCH2VAL	=	0x7024
                           007026   989 G$ADCCH3VAL0$0$0 == 0x7026
                           007026   990 _ADCCH3VAL0	=	0x7026
                           007027   991 G$ADCCH3VAL1$0$0 == 0x7027
                           007027   992 _ADCCH3VAL1	=	0x7027
                           007026   993 G$ADCCH3VAL$0$0 == 0x7026
                           007026   994 _ADCCH3VAL	=	0x7026
                           007028   995 G$ADCTUNE0$0$0 == 0x7028
                           007028   996 _ADCTUNE0	=	0x7028
                           007029   997 G$ADCTUNE1$0$0 == 0x7029
                           007029   998 _ADCTUNE1	=	0x7029
                           00702A   999 G$ADCTUNE2$0$0 == 0x702a
                           00702A  1000 _ADCTUNE2	=	0x702a
                           007010  1001 G$DMA0ADDR0$0$0 == 0x7010
                           007010  1002 _DMA0ADDR0	=	0x7010
                           007011  1003 G$DMA0ADDR1$0$0 == 0x7011
                           007011  1004 _DMA0ADDR1	=	0x7011
                           007010  1005 G$DMA0ADDR$0$0 == 0x7010
                           007010  1006 _DMA0ADDR	=	0x7010
                           007014  1007 G$DMA0CONFIG$0$0 == 0x7014
                           007014  1008 _DMA0CONFIG	=	0x7014
                           007012  1009 G$DMA1ADDR0$0$0 == 0x7012
                           007012  1010 _DMA1ADDR0	=	0x7012
                           007013  1011 G$DMA1ADDR1$0$0 == 0x7013
                           007013  1012 _DMA1ADDR1	=	0x7013
                           007012  1013 G$DMA1ADDR$0$0 == 0x7012
                           007012  1014 _DMA1ADDR	=	0x7012
                           007015  1015 G$DMA1CONFIG$0$0 == 0x7015
                           007015  1016 _DMA1CONFIG	=	0x7015
                           007070  1017 G$FRCOSCCONFIG$0$0 == 0x7070
                           007070  1018 _FRCOSCCONFIG	=	0x7070
                           007071  1019 G$FRCOSCCTRL$0$0 == 0x7071
                           007071  1020 _FRCOSCCTRL	=	0x7071
                           007076  1021 G$FRCOSCFREQ0$0$0 == 0x7076
                           007076  1022 _FRCOSCFREQ0	=	0x7076
                           007077  1023 G$FRCOSCFREQ1$0$0 == 0x7077
                           007077  1024 _FRCOSCFREQ1	=	0x7077
                           007076  1025 G$FRCOSCFREQ$0$0 == 0x7076
                           007076  1026 _FRCOSCFREQ	=	0x7076
                           007072  1027 G$FRCOSCKFILT0$0$0 == 0x7072
                           007072  1028 _FRCOSCKFILT0	=	0x7072
                           007073  1029 G$FRCOSCKFILT1$0$0 == 0x7073
                           007073  1030 _FRCOSCKFILT1	=	0x7073
                           007072  1031 G$FRCOSCKFILT$0$0 == 0x7072
                           007072  1032 _FRCOSCKFILT	=	0x7072
                           007078  1033 G$FRCOSCPER0$0$0 == 0x7078
                           007078  1034 _FRCOSCPER0	=	0x7078
                           007079  1035 G$FRCOSCPER1$0$0 == 0x7079
                           007079  1036 _FRCOSCPER1	=	0x7079
                           007078  1037 G$FRCOSCPER$0$0 == 0x7078
                           007078  1038 _FRCOSCPER	=	0x7078
                           007074  1039 G$FRCOSCREF0$0$0 == 0x7074
                           007074  1040 _FRCOSCREF0	=	0x7074
                           007075  1041 G$FRCOSCREF1$0$0 == 0x7075
                           007075  1042 _FRCOSCREF1	=	0x7075
                           007074  1043 G$FRCOSCREF$0$0 == 0x7074
                           007074  1044 _FRCOSCREF	=	0x7074
                           007007  1045 G$ANALOGA$0$0 == 0x7007
                           007007  1046 _ANALOGA	=	0x7007
                           00700C  1047 G$GPIOENABLE$0$0 == 0x700c
                           00700C  1048 _GPIOENABLE	=	0x700c
                           007003  1049 G$EXTIRQ$0$0 == 0x7003
                           007003  1050 _EXTIRQ	=	0x7003
                           007000  1051 G$INTCHGA$0$0 == 0x7000
                           007000  1052 _INTCHGA	=	0x7000
                           007001  1053 G$INTCHGB$0$0 == 0x7001
                           007001  1054 _INTCHGB	=	0x7001
                           007002  1055 G$INTCHGC$0$0 == 0x7002
                           007002  1056 _INTCHGC	=	0x7002
                           007008  1057 G$PALTA$0$0 == 0x7008
                           007008  1058 _PALTA	=	0x7008
                           007009  1059 G$PALTB$0$0 == 0x7009
                           007009  1060 _PALTB	=	0x7009
                           00700A  1061 G$PALTC$0$0 == 0x700a
                           00700A  1062 _PALTC	=	0x700a
                           007046  1063 G$PALTRADIO$0$0 == 0x7046
                           007046  1064 _PALTRADIO	=	0x7046
                           007004  1065 G$PINCHGA$0$0 == 0x7004
                           007004  1066 _PINCHGA	=	0x7004
                           007005  1067 G$PINCHGB$0$0 == 0x7005
                           007005  1068 _PINCHGB	=	0x7005
                           007006  1069 G$PINCHGC$0$0 == 0x7006
                           007006  1070 _PINCHGC	=	0x7006
                           00700B  1071 G$PINSEL$0$0 == 0x700b
                           00700B  1072 _PINSEL	=	0x700b
                           007060  1073 G$LPOSCCONFIG$0$0 == 0x7060
                           007060  1074 _LPOSCCONFIG	=	0x7060
                           007066  1075 G$LPOSCFREQ0$0$0 == 0x7066
                           007066  1076 _LPOSCFREQ0	=	0x7066
                           007067  1077 G$LPOSCFREQ1$0$0 == 0x7067
                           007067  1078 _LPOSCFREQ1	=	0x7067
                           007066  1079 G$LPOSCFREQ$0$0 == 0x7066
                           007066  1080 _LPOSCFREQ	=	0x7066
                           007062  1081 G$LPOSCKFILT0$0$0 == 0x7062
                           007062  1082 _LPOSCKFILT0	=	0x7062
                           007063  1083 G$LPOSCKFILT1$0$0 == 0x7063
                           007063  1084 _LPOSCKFILT1	=	0x7063
                           007062  1085 G$LPOSCKFILT$0$0 == 0x7062
                           007062  1086 _LPOSCKFILT	=	0x7062
                           007068  1087 G$LPOSCPER0$0$0 == 0x7068
                           007068  1088 _LPOSCPER0	=	0x7068
                           007069  1089 G$LPOSCPER1$0$0 == 0x7069
                           007069  1090 _LPOSCPER1	=	0x7069
                           007068  1091 G$LPOSCPER$0$0 == 0x7068
                           007068  1092 _LPOSCPER	=	0x7068
                           007064  1093 G$LPOSCREF0$0$0 == 0x7064
                           007064  1094 _LPOSCREF0	=	0x7064
                           007065  1095 G$LPOSCREF1$0$0 == 0x7065
                           007065  1096 _LPOSCREF1	=	0x7065
                           007064  1097 G$LPOSCREF$0$0 == 0x7064
                           007064  1098 _LPOSCREF	=	0x7064
                           007054  1099 G$LPXOSCGM$0$0 == 0x7054
                           007054  1100 _LPXOSCGM	=	0x7054
                           007F01  1101 G$MISCCTRL$0$0 == 0x7f01
                           007F01  1102 _MISCCTRL	=	0x7f01
                           007053  1103 G$OSCCALIB$0$0 == 0x7053
                           007053  1104 _OSCCALIB	=	0x7053
                           007050  1105 G$OSCFORCERUN$0$0 == 0x7050
                           007050  1106 _OSCFORCERUN	=	0x7050
                           007052  1107 G$OSCREADY$0$0 == 0x7052
                           007052  1108 _OSCREADY	=	0x7052
                           007051  1109 G$OSCRUN$0$0 == 0x7051
                           007051  1110 _OSCRUN	=	0x7051
                           007040  1111 G$RADIOFDATAADDR0$0$0 == 0x7040
                           007040  1112 _RADIOFDATAADDR0	=	0x7040
                           007041  1113 G$RADIOFDATAADDR1$0$0 == 0x7041
                           007041  1114 _RADIOFDATAADDR1	=	0x7041
                           007040  1115 G$RADIOFDATAADDR$0$0 == 0x7040
                           007040  1116 _RADIOFDATAADDR	=	0x7040
                           007042  1117 G$RADIOFSTATADDR0$0$0 == 0x7042
                           007042  1118 _RADIOFSTATADDR0	=	0x7042
                           007043  1119 G$RADIOFSTATADDR1$0$0 == 0x7043
                           007043  1120 _RADIOFSTATADDR1	=	0x7043
                           007042  1121 G$RADIOFSTATADDR$0$0 == 0x7042
                           007042  1122 _RADIOFSTATADDR	=	0x7042
                           007044  1123 G$RADIOMUX$0$0 == 0x7044
                           007044  1124 _RADIOMUX	=	0x7044
                           007084  1125 G$SCRATCH0$0$0 == 0x7084
                           007084  1126 _SCRATCH0	=	0x7084
                           007085  1127 G$SCRATCH1$0$0 == 0x7085
                           007085  1128 _SCRATCH1	=	0x7085
                           007086  1129 G$SCRATCH2$0$0 == 0x7086
                           007086  1130 _SCRATCH2	=	0x7086
                           007087  1131 G$SCRATCH3$0$0 == 0x7087
                           007087  1132 _SCRATCH3	=	0x7087
                           007F00  1133 G$SILICONREV$0$0 == 0x7f00
                           007F00  1134 _SILICONREV	=	0x7f00
                           007F19  1135 G$XTALAMPL$0$0 == 0x7f19
                           007F19  1136 _XTALAMPL	=	0x7f19
                           007F18  1137 G$XTALOSC$0$0 == 0x7f18
                           007F18  1138 _XTALOSC	=	0x7f18
                           007F1A  1139 G$XTALREADY$0$0 == 0x7f1a
                           007F1A  1140 _XTALREADY	=	0x7f1a
                           00FC06  1141 Fdisplay$flash_deviceid$0$0 == 0xfc06
                           00FC06  1142 _flash_deviceid	=	0xfc06
                           00FC00  1143 Fdisplay$flash_calsector$0$0 == 0xfc00
                           00FC00  1144 _flash_calsector	=	0xfc00
                                   1145 ;--------------------------------------------------------
                                   1146 ; absolute external ram data
                                   1147 ;--------------------------------------------------------
                                   1148 	.area XABS    (ABS,XDATA)
                                   1149 ;--------------------------------------------------------
                                   1150 ; external initialized ram data
                                   1151 ;--------------------------------------------------------
                                   1152 	.area XISEG   (XDATA)
                                   1153 	.area HOME    (CODE)
                                   1154 	.area GSINIT0 (CODE)
                                   1155 	.area GSINIT1 (CODE)
                                   1156 	.area GSINIT2 (CODE)
                                   1157 	.area GSINIT3 (CODE)
                                   1158 	.area GSINIT4 (CODE)
                                   1159 	.area GSINIT5 (CODE)
                                   1160 	.area GSINIT  (CODE)
                                   1161 	.area GSFINAL (CODE)
                                   1162 	.area CSEG    (CODE)
                                   1163 ;--------------------------------------------------------
                                   1164 ; global & static initialisations
                                   1165 ;--------------------------------------------------------
                                   1166 	.area HOME    (CODE)
                                   1167 	.area GSINIT  (CODE)
                                   1168 	.area GSFINAL (CODE)
                                   1169 	.area GSINIT  (CODE)
                           000000  1170 	C$display.c$78$1$337 ==.
                                   1171 ;	display.c:78: uint16_t __data per_test_counter = 0, per_test_counter_previous = 0;
      00038A E4               [12] 1172 	clr	a
      00038B F5 1A            [12] 1173 	mov	_per_test_counter,a
      00038D F5 1B            [12] 1174 	mov	(_per_test_counter + 1),a
                           000005  1175 	C$display.c$78$1$337 ==.
                                   1176 ;	display.c:78: extern uint16_t __data pkts_received, pkts_missing;
      00038F F5 1C            [12] 1177 	mov	_per_test_counter_previous,a
      000391 F5 1D            [12] 1178 	mov	(_per_test_counter_previous + 1),a
                           000009  1179 	C$display.c$80$1$337 ==.
                                   1180 ;	display.c:80: uint8_t __data display_timing = 2;
      000393 75 1E 02         [24] 1181 	mov	_display_timing,#0x02
                                   1182 ;--------------------------------------------------------
                                   1183 ; Home
                                   1184 ;--------------------------------------------------------
                                   1185 	.area HOME    (CODE)
                                   1186 	.area HOME    (CODE)
                                   1187 ;--------------------------------------------------------
                                   1188 ; code
                                   1189 ;--------------------------------------------------------
                                   1190 	.area CSEG    (CODE)
                                   1191 ;------------------------------------------------------------
                                   1192 ;Allocation info for local variables in function 'display_received_packet'
                                   1193 ;------------------------------------------------------------
                                   1194 ;st                        Allocated to registers r6 r7 
                                   1195 ;retran                    Allocated to registers r5 
                                   1196 ;------------------------------------------------------------
                           000000  1197 	G$display_received_packet$0$0 ==.
                           000000  1198 	C$display.c$82$0$0 ==.
                                   1199 ;	display.c:82: uint8_t display_received_packet(struct axradio_status __xdata *st)
                                   1200 ;	-----------------------------------------
                                   1201 ;	 function display_received_packet
                                   1202 ;	-----------------------------------------
      003C78                       1203 _display_received_packet:
                           000007  1204 	ar7 = 0x07
                           000006  1205 	ar6 = 0x06
                           000005  1206 	ar5 = 0x05
                           000004  1207 	ar4 = 0x04
                           000003  1208 	ar3 = 0x03
                           000002  1209 	ar2 = 0x02
                           000001  1210 	ar1 = 0x01
                           000000  1211 	ar0 = 0x00
      003C78 AE 82            [24] 1212 	mov	r6,dpl
      003C7A AF 83            [24] 1213 	mov	r7,dph
                           000004  1214 	C$display.c$84$1$0 ==.
                                   1215 ;	display.c:84: uint8_t retran = 0;
      003C7C 7D 00            [12] 1216 	mov	r5,#0x00
                           000006  1217 	C$display.c$90$1$337 ==.
                                   1218 ;	display.c:90: if (!PINB_2)
      003C7E 20 EA 0F         [24] 1219 	jb	_PINB_2,00102$
                           000009  1220 	C$display.c$91$1$337 ==.
                                   1221 ;	display.c:91: display_timing = (!display_timing) | 0x02;
      003C81 E5 1E            [12] 1222 	mov	a,_display_timing
      003C83 B4 01 00         [24] 1223 	cjne	a,#0x01,00169$
      003C86                       1224 00169$:
      003C86 92 01            [24] 1225 	mov  _display_received_packet_sloc0_1_0,c
      003C88 E4               [12] 1226 	clr	a
      003C89 33               [12] 1227 	rlc	a
      003C8A FC               [12] 1228 	mov	r4,a
      003C8B 74 02            [12] 1229 	mov	a,#0x02
      003C8D 4C               [12] 1230 	orl	a,r4
      003C8E F5 1E            [12] 1231 	mov	_display_timing,a
      003C90                       1232 00102$:
                           000018  1233 	C$display.c$96$1$337 ==.
                                   1234 ;	display.c:96: if (display_timing & 0x02)
      003C90 E5 1E            [12] 1235 	mov	a,_display_timing
      003C92 30 E1 03         [24] 1236 	jnb	acc.1,00123$
                           00001D  1237 	C$display.c$99$2$338 ==.
                                   1238 ;	display.c:99: display_timing &= 0x01;
      003C95 53 1E 01         [24] 1239 	anl	_display_timing,#0x01
                           000020  1240 	C$display.c$116$1$337 ==.
                                   1241 ;	display.c:116: display_writenum16(axradio_conv_freq_tohz(st->u.rx.phy.offset), 6, WRNUM_SIGNED);
      003C98                       1242 00123$:
                           000020  1243 	C$display.c$133$1$337 ==.
                                   1244 ;	display.c:133: if (framing_insert_counter)
      003C98 90 4E 88         [24] 1245 	mov	dptr,#_framing_insert_counter
      003C9B E4               [12] 1246 	clr	a
      003C9C 93               [24] 1247 	movc	a,@a+dptr
      003C9D 60 7B            [24] 1248 	jz	00150$
                           000027  1249 	C$display.c$135$2$355 ==.
                                   1250 ;	display.c:135: per_test_counter_previous = per_test_counter;
      003C9F 85 1A 1C         [24] 1251 	mov	_per_test_counter_previous,_per_test_counter
      003CA2 85 1B 1D         [24] 1252 	mov	(_per_test_counter_previous + 1),(_per_test_counter + 1)
                           00002D  1253 	C$display.c$136$2$355 ==.
                                   1254 ;	display.c:136: per_test_counter = ((st->u.rx.pktdata[framing_counter_pos+1])<<8) | st->u.rx.pktdata[framing_counter_pos];
      003CA5 74 06            [12] 1255 	mov	a,#0x06
      003CA7 2E               [12] 1256 	add	a,r6
      003CA8 FE               [12] 1257 	mov	r6,a
      003CA9 E4               [12] 1258 	clr	a
      003CAA 3F               [12] 1259 	addc	a,r7
      003CAB FF               [12] 1260 	mov	r7,a
      003CAC 74 16            [12] 1261 	mov	a,#0x16
      003CAE 2E               [12] 1262 	add	a,r6
      003CAF F5 82            [12] 1263 	mov	dpl,a
      003CB1 E4               [12] 1264 	clr	a
      003CB2 3F               [12] 1265 	addc	a,r7
      003CB3 F5 83            [12] 1266 	mov	dph,a
      003CB5 E0               [24] 1267 	movx	a,@dptr
      003CB6 FE               [12] 1268 	mov	r6,a
      003CB7 A3               [24] 1269 	inc	dptr
      003CB8 E0               [24] 1270 	movx	a,@dptr
      003CB9 FF               [12] 1271 	mov	r7,a
      003CBA 90 4E 89         [24] 1272 	mov	dptr,#_framing_counter_pos
      003CBD E4               [12] 1273 	clr	a
      003CBE 93               [24] 1274 	movc	a,@a+dptr
      003CBF FC               [12] 1275 	mov	r4,a
      003CC0 FA               [12] 1276 	mov	r2,a
      003CC1 7B 00            [12] 1277 	mov	r3,#0x00
      003CC3 0A               [12] 1278 	inc	r2
      003CC4 BA 00 01         [24] 1279 	cjne	r2,#0x00,00172$
      003CC7 0B               [12] 1280 	inc	r3
      003CC8                       1281 00172$:
      003CC8 EA               [12] 1282 	mov	a,r2
      003CC9 2E               [12] 1283 	add	a,r6
      003CCA F5 82            [12] 1284 	mov	dpl,a
      003CCC EB               [12] 1285 	mov	a,r3
      003CCD 3F               [12] 1286 	addc	a,r7
      003CCE F5 83            [12] 1287 	mov	dph,a
      003CD0 E0               [24] 1288 	movx	a,@dptr
      003CD1 FA               [12] 1289 	mov	r2,a
      003CD2 7B 00            [12] 1290 	mov	r3,#0x00
      003CD4 EC               [12] 1291 	mov	a,r4
      003CD5 2E               [12] 1292 	add	a,r6
      003CD6 F5 82            [12] 1293 	mov	dpl,a
      003CD8 E4               [12] 1294 	clr	a
      003CD9 3F               [12] 1295 	addc	a,r7
      003CDA F5 83            [12] 1296 	mov	dph,a
      003CDC E0               [24] 1297 	movx	a,@dptr
      003CDD FF               [12] 1298 	mov	r7,a
      003CDE 7E 00            [12] 1299 	mov	r6,#0x00
      003CE0 4B               [12] 1300 	orl	a,r3
      003CE1 F5 1A            [12] 1301 	mov	_per_test_counter,a
      003CE3 EE               [12] 1302 	mov	a,r6
      003CE4 4A               [12] 1303 	orl	a,r2
      003CE5 F5 1B            [12] 1304 	mov	(_per_test_counter + 1),a
                           00006F  1305 	C$display.c$137$2$355 ==.
                                   1306 ;	display.c:137: if (pkts_received != 1)
      003CE7 74 01            [12] 1307 	mov	a,#0x01
      003CE9 B5 23 06         [24] 1308 	cjne	a,_pkts_received,00173$
      003CEC 14               [12] 1309 	dec	a
      003CED B5 24 02         [24] 1310 	cjne	a,(_pkts_received + 1),00173$
      003CF0 80 28            [24] 1311 	sjmp	00150$
      003CF2                       1312 00173$:
                           00007A  1313 	C$display.c$139$3$356 ==.
                                   1314 ;	display.c:139: if (per_test_counter == per_test_counter_previous)
      003CF2 E5 1C            [12] 1315 	mov	a,_per_test_counter_previous
      003CF4 B5 1A 09         [24] 1316 	cjne	a,_per_test_counter,00136$
      003CF7 E5 1D            [12] 1317 	mov	a,(_per_test_counter_previous + 1)
      003CF9 B5 1B 04         [24] 1318 	cjne	a,(_per_test_counter + 1),00136$
                           000084  1319 	C$display.c$140$3$356 ==.
                                   1320 ;	display.c:140: retran = 1;
      003CFC 7D 01            [12] 1321 	mov	r5,#0x01
      003CFE 80 1A            [24] 1322 	sjmp	00150$
      003D00                       1323 00136$:
                           000088  1324 	C$display.c$142$3$356 ==.
                                   1325 ;	display.c:142: pkts_missing += per_test_counter - per_test_counter_previous - 1;
      003D00 E5 1A            [12] 1326 	mov	a,_per_test_counter
      003D02 C3               [12] 1327 	clr	c
      003D03 95 1C            [12] 1328 	subb	a,_per_test_counter_previous
      003D05 FE               [12] 1329 	mov	r6,a
      003D06 E5 1B            [12] 1330 	mov	a,(_per_test_counter + 1)
      003D08 95 1D            [12] 1331 	subb	a,(_per_test_counter_previous + 1)
      003D0A FF               [12] 1332 	mov	r7,a
      003D0B 1E               [12] 1333 	dec	r6
      003D0C BE FF 01         [24] 1334 	cjne	r6,#0xff,00176$
      003D0F 1F               [12] 1335 	dec	r7
      003D10                       1336 00176$:
      003D10 EE               [12] 1337 	mov	a,r6
      003D11 25 25            [12] 1338 	add	a,_pkts_missing
      003D13 F5 25            [12] 1339 	mov	_pkts_missing,a
      003D15 EF               [12] 1340 	mov	a,r7
      003D16 35 26            [12] 1341 	addc	a,(_pkts_missing + 1)
      003D18 F5 26            [12] 1342 	mov	(_pkts_missing + 1),a
                           0000A2  1343 	C$display.c$152$1$337 ==.
                                   1344 ;	display.c:152: display_writestr("?");
      003D1A                       1345 00150$:
                           0000A2  1346 	C$display.c$154$1$337 ==.
                                   1347 ;	display.c:154: return retran;
      003D1A 8D 82            [24] 1348 	mov	dpl,r5
                           0000A4  1349 	C$display.c$155$1$337 ==.
                           0000A4  1350 	XG$display_received_packet$0$0 ==.
      003D1C 22               [24] 1351 	ret
                                   1352 ;------------------------------------------------------------
                                   1353 ;Allocation info for local variables in function 'dbglink_received_packet'
                                   1354 ;------------------------------------------------------------
                                   1355 ;st                        Allocated to registers 
                                   1356 ;------------------------------------------------------------
                           0000A5  1357 	G$dbglink_received_packet$0$0 ==.
                           0000A5  1358 	C$display.c$171$1$337 ==.
                                   1359 ;	display.c:171: void dbglink_received_packet(struct axradio_status __xdata *st)
                                   1360 ;	-----------------------------------------
                                   1361 ;	 function dbglink_received_packet
                                   1362 ;	-----------------------------------------
      003D1D                       1363 _dbglink_received_packet:
                           0000A5  1364 	C$display.c$226$1$337 ==.
                                   1365 ;	display.c:226: }
                           0000A5  1366 	C$display.c$226$1$337 ==.
                           0000A5  1367 	XG$dbglink_received_packet$0$0 ==.
      003D1D 22               [24] 1368 	ret
                                   1369 	.area CSEG    (CODE)
                                   1370 	.area CONST   (CODE)
                                   1371 	.area XINIT   (CODE)
                                   1372 	.area CABS    (ABS,CODE)
