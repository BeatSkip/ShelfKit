                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module display_com0
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
                                    367 ;--------------------------------------------------------
                                    368 ; special function registers
                                    369 ;--------------------------------------------------------
                                    370 	.area RSEG    (ABS,DATA)
      000000                        371 	.org 0x0000
                           0000E0   372 _ACC	=	0x00e0
                           0000F0   373 _B	=	0x00f0
                           000083   374 _DPH	=	0x0083
                           000085   375 _DPH1	=	0x0085
                           000082   376 _DPL	=	0x0082
                           000084   377 _DPL1	=	0x0084
                           008382   378 _DPTR0	=	0x8382
                           008584   379 _DPTR1	=	0x8584
                           000086   380 _DPS	=	0x0086
                           0000A0   381 _E2IE	=	0x00a0
                           0000C0   382 _E2IP	=	0x00c0
                           000098   383 _EIE	=	0x0098
                           0000B0   384 _EIP	=	0x00b0
                           0000A8   385 _IE	=	0x00a8
                           0000B8   386 _IP	=	0x00b8
                           000087   387 _PCON	=	0x0087
                           0000D0   388 _PSW	=	0x00d0
                           000081   389 _SP	=	0x0081
                           0000D9   390 _XPAGE	=	0x00d9
                           0000D9   391 __XPAGE	=	0x00d9
                           0000CA   392 _ADCCH0CONFIG	=	0x00ca
                           0000CB   393 _ADCCH1CONFIG	=	0x00cb
                           0000D2   394 _ADCCH2CONFIG	=	0x00d2
                           0000D3   395 _ADCCH3CONFIG	=	0x00d3
                           0000D1   396 _ADCCLKSRC	=	0x00d1
                           0000C9   397 _ADCCONV	=	0x00c9
                           0000E1   398 _ANALOGCOMP	=	0x00e1
                           0000C6   399 _CLKCON	=	0x00c6
                           0000C7   400 _CLKSTAT	=	0x00c7
                           000097   401 _CODECONFIG	=	0x0097
                           0000E3   402 _DBGLNKBUF	=	0x00e3
                           0000E2   403 _DBGLNKSTAT	=	0x00e2
                           000089   404 _DIRA	=	0x0089
                           00008A   405 _DIRB	=	0x008a
                           00008B   406 _DIRC	=	0x008b
                           00008E   407 _DIRR	=	0x008e
                           0000C8   408 _PINA	=	0x00c8
                           0000E8   409 _PINB	=	0x00e8
                           0000F8   410 _PINC	=	0x00f8
                           00008D   411 _PINR	=	0x008d
                           000080   412 _PORTA	=	0x0080
                           000088   413 _PORTB	=	0x0088
                           000090   414 _PORTC	=	0x0090
                           00008C   415 _PORTR	=	0x008c
                           0000CE   416 _IC0CAPT0	=	0x00ce
                           0000CF   417 _IC0CAPT1	=	0x00cf
                           00CFCE   418 _IC0CAPT	=	0xcfce
                           0000CC   419 _IC0MODE	=	0x00cc
                           0000CD   420 _IC0STATUS	=	0x00cd
                           0000D6   421 _IC1CAPT0	=	0x00d6
                           0000D7   422 _IC1CAPT1	=	0x00d7
                           00D7D6   423 _IC1CAPT	=	0xd7d6
                           0000D4   424 _IC1MODE	=	0x00d4
                           0000D5   425 _IC1STATUS	=	0x00d5
                           000092   426 _NVADDR0	=	0x0092
                           000093   427 _NVADDR1	=	0x0093
                           009392   428 _NVADDR	=	0x9392
                           000094   429 _NVDATA0	=	0x0094
                           000095   430 _NVDATA1	=	0x0095
                           009594   431 _NVDATA	=	0x9594
                           000096   432 _NVKEY	=	0x0096
                           000091   433 _NVSTATUS	=	0x0091
                           0000BC   434 _OC0COMP0	=	0x00bc
                           0000BD   435 _OC0COMP1	=	0x00bd
                           00BDBC   436 _OC0COMP	=	0xbdbc
                           0000B9   437 _OC0MODE	=	0x00b9
                           0000BA   438 _OC0PIN	=	0x00ba
                           0000BB   439 _OC0STATUS	=	0x00bb
                           0000C4   440 _OC1COMP0	=	0x00c4
                           0000C5   441 _OC1COMP1	=	0x00c5
                           00C5C4   442 _OC1COMP	=	0xc5c4
                           0000C1   443 _OC1MODE	=	0x00c1
                           0000C2   444 _OC1PIN	=	0x00c2
                           0000C3   445 _OC1STATUS	=	0x00c3
                           0000B1   446 _RADIOACC	=	0x00b1
                           0000B3   447 _RADIOADDR0	=	0x00b3
                           0000B2   448 _RADIOADDR1	=	0x00b2
                           00B2B3   449 _RADIOADDR	=	0xb2b3
                           0000B7   450 _RADIODATA0	=	0x00b7
                           0000B6   451 _RADIODATA1	=	0x00b6
                           0000B5   452 _RADIODATA2	=	0x00b5
                           0000B4   453 _RADIODATA3	=	0x00b4
                           B4B5B6B7   454 _RADIODATA	=	0xb4b5b6b7
                           0000BE   455 _RADIOSTAT0	=	0x00be
                           0000BF   456 _RADIOSTAT1	=	0x00bf
                           00BFBE   457 _RADIOSTAT	=	0xbfbe
                           0000DF   458 _SPCLKSRC	=	0x00df
                           0000DC   459 _SPMODE	=	0x00dc
                           0000DE   460 _SPSHREG	=	0x00de
                           0000DD   461 _SPSTATUS	=	0x00dd
                           00009A   462 _T0CLKSRC	=	0x009a
                           00009C   463 _T0CNT0	=	0x009c
                           00009D   464 _T0CNT1	=	0x009d
                           009D9C   465 _T0CNT	=	0x9d9c
                           000099   466 _T0MODE	=	0x0099
                           00009E   467 _T0PERIOD0	=	0x009e
                           00009F   468 _T0PERIOD1	=	0x009f
                           009F9E   469 _T0PERIOD	=	0x9f9e
                           00009B   470 _T0STATUS	=	0x009b
                           0000A2   471 _T1CLKSRC	=	0x00a2
                           0000A4   472 _T1CNT0	=	0x00a4
                           0000A5   473 _T1CNT1	=	0x00a5
                           00A5A4   474 _T1CNT	=	0xa5a4
                           0000A1   475 _T1MODE	=	0x00a1
                           0000A6   476 _T1PERIOD0	=	0x00a6
                           0000A7   477 _T1PERIOD1	=	0x00a7
                           00A7A6   478 _T1PERIOD	=	0xa7a6
                           0000A3   479 _T1STATUS	=	0x00a3
                           0000AA   480 _T2CLKSRC	=	0x00aa
                           0000AC   481 _T2CNT0	=	0x00ac
                           0000AD   482 _T2CNT1	=	0x00ad
                           00ADAC   483 _T2CNT	=	0xadac
                           0000A9   484 _T2MODE	=	0x00a9
                           0000AE   485 _T2PERIOD0	=	0x00ae
                           0000AF   486 _T2PERIOD1	=	0x00af
                           00AFAE   487 _T2PERIOD	=	0xafae
                           0000AB   488 _T2STATUS	=	0x00ab
                           0000E4   489 _U0CTRL	=	0x00e4
                           0000E7   490 _U0MODE	=	0x00e7
                           0000E6   491 _U0SHREG	=	0x00e6
                           0000E5   492 _U0STATUS	=	0x00e5
                           0000EC   493 _U1CTRL	=	0x00ec
                           0000EF   494 _U1MODE	=	0x00ef
                           0000EE   495 _U1SHREG	=	0x00ee
                           0000ED   496 _U1STATUS	=	0x00ed
                           0000DA   497 _WDTCFG	=	0x00da
                           0000DB   498 _WDTRESET	=	0x00db
                           0000F1   499 _WTCFGA	=	0x00f1
                           0000F9   500 _WTCFGB	=	0x00f9
                           0000F2   501 _WTCNTA0	=	0x00f2
                           0000F3   502 _WTCNTA1	=	0x00f3
                           00F3F2   503 _WTCNTA	=	0xf3f2
                           0000FA   504 _WTCNTB0	=	0x00fa
                           0000FB   505 _WTCNTB1	=	0x00fb
                           00FBFA   506 _WTCNTB	=	0xfbfa
                           0000EB   507 _WTCNTR1	=	0x00eb
                           0000F4   508 _WTEVTA0	=	0x00f4
                           0000F5   509 _WTEVTA1	=	0x00f5
                           00F5F4   510 _WTEVTA	=	0xf5f4
                           0000F6   511 _WTEVTB0	=	0x00f6
                           0000F7   512 _WTEVTB1	=	0x00f7
                           00F7F6   513 _WTEVTB	=	0xf7f6
                           0000FC   514 _WTEVTC0	=	0x00fc
                           0000FD   515 _WTEVTC1	=	0x00fd
                           00FDFC   516 _WTEVTC	=	0xfdfc
                           0000FE   517 _WTEVTD0	=	0x00fe
                           0000FF   518 _WTEVTD1	=	0x00ff
                           00FFFE   519 _WTEVTD	=	0xfffe
                           0000E9   520 _WTIRQEN	=	0x00e9
                           0000EA   521 _WTSTAT	=	0x00ea
                                    522 ;--------------------------------------------------------
                                    523 ; special function bits
                                    524 ;--------------------------------------------------------
                                    525 	.area RSEG    (ABS,DATA)
      000000                        526 	.org 0x0000
                           0000E0   527 _ACC_0	=	0x00e0
                           0000E1   528 _ACC_1	=	0x00e1
                           0000E2   529 _ACC_2	=	0x00e2
                           0000E3   530 _ACC_3	=	0x00e3
                           0000E4   531 _ACC_4	=	0x00e4
                           0000E5   532 _ACC_5	=	0x00e5
                           0000E6   533 _ACC_6	=	0x00e6
                           0000E7   534 _ACC_7	=	0x00e7
                           0000F0   535 _B_0	=	0x00f0
                           0000F1   536 _B_1	=	0x00f1
                           0000F2   537 _B_2	=	0x00f2
                           0000F3   538 _B_3	=	0x00f3
                           0000F4   539 _B_4	=	0x00f4
                           0000F5   540 _B_5	=	0x00f5
                           0000F6   541 _B_6	=	0x00f6
                           0000F7   542 _B_7	=	0x00f7
                           0000A0   543 _E2IE_0	=	0x00a0
                           0000A1   544 _E2IE_1	=	0x00a1
                           0000A2   545 _E2IE_2	=	0x00a2
                           0000A3   546 _E2IE_3	=	0x00a3
                           0000A4   547 _E2IE_4	=	0x00a4
                           0000A5   548 _E2IE_5	=	0x00a5
                           0000A6   549 _E2IE_6	=	0x00a6
                           0000A7   550 _E2IE_7	=	0x00a7
                           0000C0   551 _E2IP_0	=	0x00c0
                           0000C1   552 _E2IP_1	=	0x00c1
                           0000C2   553 _E2IP_2	=	0x00c2
                           0000C3   554 _E2IP_3	=	0x00c3
                           0000C4   555 _E2IP_4	=	0x00c4
                           0000C5   556 _E2IP_5	=	0x00c5
                           0000C6   557 _E2IP_6	=	0x00c6
                           0000C7   558 _E2IP_7	=	0x00c7
                           000098   559 _EIE_0	=	0x0098
                           000099   560 _EIE_1	=	0x0099
                           00009A   561 _EIE_2	=	0x009a
                           00009B   562 _EIE_3	=	0x009b
                           00009C   563 _EIE_4	=	0x009c
                           00009D   564 _EIE_5	=	0x009d
                           00009E   565 _EIE_6	=	0x009e
                           00009F   566 _EIE_7	=	0x009f
                           0000B0   567 _EIP_0	=	0x00b0
                           0000B1   568 _EIP_1	=	0x00b1
                           0000B2   569 _EIP_2	=	0x00b2
                           0000B3   570 _EIP_3	=	0x00b3
                           0000B4   571 _EIP_4	=	0x00b4
                           0000B5   572 _EIP_5	=	0x00b5
                           0000B6   573 _EIP_6	=	0x00b6
                           0000B7   574 _EIP_7	=	0x00b7
                           0000A8   575 _IE_0	=	0x00a8
                           0000A9   576 _IE_1	=	0x00a9
                           0000AA   577 _IE_2	=	0x00aa
                           0000AB   578 _IE_3	=	0x00ab
                           0000AC   579 _IE_4	=	0x00ac
                           0000AD   580 _IE_5	=	0x00ad
                           0000AE   581 _IE_6	=	0x00ae
                           0000AF   582 _IE_7	=	0x00af
                           0000AF   583 _EA	=	0x00af
                           0000B8   584 _IP_0	=	0x00b8
                           0000B9   585 _IP_1	=	0x00b9
                           0000BA   586 _IP_2	=	0x00ba
                           0000BB   587 _IP_3	=	0x00bb
                           0000BC   588 _IP_4	=	0x00bc
                           0000BD   589 _IP_5	=	0x00bd
                           0000BE   590 _IP_6	=	0x00be
                           0000BF   591 _IP_7	=	0x00bf
                           0000D0   592 _P	=	0x00d0
                           0000D1   593 _F1	=	0x00d1
                           0000D2   594 _OV	=	0x00d2
                           0000D3   595 _RS0	=	0x00d3
                           0000D4   596 _RS1	=	0x00d4
                           0000D5   597 _F0	=	0x00d5
                           0000D6   598 _AC	=	0x00d6
                           0000D7   599 _CY	=	0x00d7
                           0000C8   600 _PINA_0	=	0x00c8
                           0000C9   601 _PINA_1	=	0x00c9
                           0000CA   602 _PINA_2	=	0x00ca
                           0000CB   603 _PINA_3	=	0x00cb
                           0000CC   604 _PINA_4	=	0x00cc
                           0000CD   605 _PINA_5	=	0x00cd
                           0000CE   606 _PINA_6	=	0x00ce
                           0000CF   607 _PINA_7	=	0x00cf
                           0000E8   608 _PINB_0	=	0x00e8
                           0000E9   609 _PINB_1	=	0x00e9
                           0000EA   610 _PINB_2	=	0x00ea
                           0000EB   611 _PINB_3	=	0x00eb
                           0000EC   612 _PINB_4	=	0x00ec
                           0000ED   613 _PINB_5	=	0x00ed
                           0000EE   614 _PINB_6	=	0x00ee
                           0000EF   615 _PINB_7	=	0x00ef
                           0000F8   616 _PINC_0	=	0x00f8
                           0000F9   617 _PINC_1	=	0x00f9
                           0000FA   618 _PINC_2	=	0x00fa
                           0000FB   619 _PINC_3	=	0x00fb
                           0000FC   620 _PINC_4	=	0x00fc
                           0000FD   621 _PINC_5	=	0x00fd
                           0000FE   622 _PINC_6	=	0x00fe
                           0000FF   623 _PINC_7	=	0x00ff
                           000080   624 _PORTA_0	=	0x0080
                           000081   625 _PORTA_1	=	0x0081
                           000082   626 _PORTA_2	=	0x0082
                           000083   627 _PORTA_3	=	0x0083
                           000084   628 _PORTA_4	=	0x0084
                           000085   629 _PORTA_5	=	0x0085
                           000086   630 _PORTA_6	=	0x0086
                           000087   631 _PORTA_7	=	0x0087
                           000088   632 _PORTB_0	=	0x0088
                           000089   633 _PORTB_1	=	0x0089
                           00008A   634 _PORTB_2	=	0x008a
                           00008B   635 _PORTB_3	=	0x008b
                           00008C   636 _PORTB_4	=	0x008c
                           00008D   637 _PORTB_5	=	0x008d
                           00008E   638 _PORTB_6	=	0x008e
                           00008F   639 _PORTB_7	=	0x008f
                           000090   640 _PORTC_0	=	0x0090
                           000091   641 _PORTC_1	=	0x0091
                           000092   642 _PORTC_2	=	0x0092
                           000093   643 _PORTC_3	=	0x0093
                           000094   644 _PORTC_4	=	0x0094
                           000095   645 _PORTC_5	=	0x0095
                           000096   646 _PORTC_6	=	0x0096
                           000097   647 _PORTC_7	=	0x0097
                                    648 ;--------------------------------------------------------
                                    649 ; overlayable register banks
                                    650 ;--------------------------------------------------------
                                    651 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        652 	.ds 8
                                    653 ;--------------------------------------------------------
                                    654 ; internal ram data
                                    655 ;--------------------------------------------------------
                                    656 	.area DSEG    (DATA)
                                    657 ;--------------------------------------------------------
                                    658 ; overlayable items in internal ram 
                                    659 ;--------------------------------------------------------
                                    660 ;--------------------------------------------------------
                                    661 ; indirectly addressable internal ram data
                                    662 ;--------------------------------------------------------
                                    663 	.area ISEG    (DATA)
                                    664 ;--------------------------------------------------------
                                    665 ; absolute internal ram data
                                    666 ;--------------------------------------------------------
                                    667 	.area IABS    (ABS,DATA)
                                    668 	.area IABS    (ABS,DATA)
                                    669 ;--------------------------------------------------------
                                    670 ; bit data
                                    671 ;--------------------------------------------------------
                                    672 	.area BSEG    (BIT)
                                    673 ;--------------------------------------------------------
                                    674 ; paged external ram data
                                    675 ;--------------------------------------------------------
                                    676 	.area PSEG    (PAG,XDATA)
                                    677 ;--------------------------------------------------------
                                    678 ; external ram data
                                    679 ;--------------------------------------------------------
                                    680 	.area XSEG    (XDATA)
                           007020   681 _ADCCH0VAL0	=	0x7020
                           007021   682 _ADCCH0VAL1	=	0x7021
                           007020   683 _ADCCH0VAL	=	0x7020
                           007022   684 _ADCCH1VAL0	=	0x7022
                           007023   685 _ADCCH1VAL1	=	0x7023
                           007022   686 _ADCCH1VAL	=	0x7022
                           007024   687 _ADCCH2VAL0	=	0x7024
                           007025   688 _ADCCH2VAL1	=	0x7025
                           007024   689 _ADCCH2VAL	=	0x7024
                           007026   690 _ADCCH3VAL0	=	0x7026
                           007027   691 _ADCCH3VAL1	=	0x7027
                           007026   692 _ADCCH3VAL	=	0x7026
                           007028   693 _ADCTUNE0	=	0x7028
                           007029   694 _ADCTUNE1	=	0x7029
                           00702A   695 _ADCTUNE2	=	0x702a
                           007010   696 _DMA0ADDR0	=	0x7010
                           007011   697 _DMA0ADDR1	=	0x7011
                           007010   698 _DMA0ADDR	=	0x7010
                           007014   699 _DMA0CONFIG	=	0x7014
                           007012   700 _DMA1ADDR0	=	0x7012
                           007013   701 _DMA1ADDR1	=	0x7013
                           007012   702 _DMA1ADDR	=	0x7012
                           007015   703 _DMA1CONFIG	=	0x7015
                           007070   704 _FRCOSCCONFIG	=	0x7070
                           007071   705 _FRCOSCCTRL	=	0x7071
                           007076   706 _FRCOSCFREQ0	=	0x7076
                           007077   707 _FRCOSCFREQ1	=	0x7077
                           007076   708 _FRCOSCFREQ	=	0x7076
                           007072   709 _FRCOSCKFILT0	=	0x7072
                           007073   710 _FRCOSCKFILT1	=	0x7073
                           007072   711 _FRCOSCKFILT	=	0x7072
                           007078   712 _FRCOSCPER0	=	0x7078
                           007079   713 _FRCOSCPER1	=	0x7079
                           007078   714 _FRCOSCPER	=	0x7078
                           007074   715 _FRCOSCREF0	=	0x7074
                           007075   716 _FRCOSCREF1	=	0x7075
                           007074   717 _FRCOSCREF	=	0x7074
                           007007   718 _ANALOGA	=	0x7007
                           00700C   719 _GPIOENABLE	=	0x700c
                           007003   720 _EXTIRQ	=	0x7003
                           007000   721 _INTCHGA	=	0x7000
                           007001   722 _INTCHGB	=	0x7001
                           007002   723 _INTCHGC	=	0x7002
                           007008   724 _PALTA	=	0x7008
                           007009   725 _PALTB	=	0x7009
                           00700A   726 _PALTC	=	0x700a
                           007046   727 _PALTRADIO	=	0x7046
                           007004   728 _PINCHGA	=	0x7004
                           007005   729 _PINCHGB	=	0x7005
                           007006   730 _PINCHGC	=	0x7006
                           00700B   731 _PINSEL	=	0x700b
                           007060   732 _LPOSCCONFIG	=	0x7060
                           007066   733 _LPOSCFREQ0	=	0x7066
                           007067   734 _LPOSCFREQ1	=	0x7067
                           007066   735 _LPOSCFREQ	=	0x7066
                           007062   736 _LPOSCKFILT0	=	0x7062
                           007063   737 _LPOSCKFILT1	=	0x7063
                           007062   738 _LPOSCKFILT	=	0x7062
                           007068   739 _LPOSCPER0	=	0x7068
                           007069   740 _LPOSCPER1	=	0x7069
                           007068   741 _LPOSCPER	=	0x7068
                           007064   742 _LPOSCREF0	=	0x7064
                           007065   743 _LPOSCREF1	=	0x7065
                           007064   744 _LPOSCREF	=	0x7064
                           007054   745 _LPXOSCGM	=	0x7054
                           007F01   746 _MISCCTRL	=	0x7f01
                           007053   747 _OSCCALIB	=	0x7053
                           007050   748 _OSCFORCERUN	=	0x7050
                           007052   749 _OSCREADY	=	0x7052
                           007051   750 _OSCRUN	=	0x7051
                           007040   751 _RADIOFDATAADDR0	=	0x7040
                           007041   752 _RADIOFDATAADDR1	=	0x7041
                           007040   753 _RADIOFDATAADDR	=	0x7040
                           007042   754 _RADIOFSTATADDR0	=	0x7042
                           007043   755 _RADIOFSTATADDR1	=	0x7043
                           007042   756 _RADIOFSTATADDR	=	0x7042
                           007044   757 _RADIOMUX	=	0x7044
                           007084   758 _SCRATCH0	=	0x7084
                           007085   759 _SCRATCH1	=	0x7085
                           007086   760 _SCRATCH2	=	0x7086
                           007087   761 _SCRATCH3	=	0x7087
                           007F00   762 _SILICONREV	=	0x7f00
                           007F19   763 _XTALAMPL	=	0x7f19
                           007F18   764 _XTALOSC	=	0x7f18
                           007F1A   765 _XTALREADY	=	0x7f1a
                           00FC06   766 _flash_deviceid	=	0xfc06
                           00FC00   767 _flash_calsector	=	0xfc00
                                    768 ;--------------------------------------------------------
                                    769 ; absolute external ram data
                                    770 ;--------------------------------------------------------
                                    771 	.area XABS    (ABS,XDATA)
                                    772 ;--------------------------------------------------------
                                    773 ; external initialized ram data
                                    774 ;--------------------------------------------------------
                                    775 	.area XISEG   (XDATA)
                                    776 	.area HOME    (CODE)
                                    777 	.area GSINIT0 (CODE)
                                    778 	.area GSINIT1 (CODE)
                                    779 	.area GSINIT2 (CODE)
                                    780 	.area GSINIT3 (CODE)
                                    781 	.area GSINIT4 (CODE)
                                    782 	.area GSINIT5 (CODE)
                                    783 	.area GSINIT  (CODE)
                                    784 	.area GSFINAL (CODE)
                                    785 	.area CSEG    (CODE)
                                    786 ;--------------------------------------------------------
                                    787 ; global & static initialisations
                                    788 ;--------------------------------------------------------
                                    789 	.area HOME    (CODE)
                                    790 	.area GSINIT  (CODE)
                                    791 	.area GSFINAL (CODE)
                                    792 	.area GSINIT  (CODE)
                                    793 ;--------------------------------------------------------
                                    794 ; Home
                                    795 ;--------------------------------------------------------
                                    796 	.area HOME    (CODE)
                                    797 	.area HOME    (CODE)
                                    798 ;--------------------------------------------------------
                                    799 ; code
                                    800 ;--------------------------------------------------------
                                    801 	.area CSEG    (CODE)
                                    802 	.area CSEG    (CODE)
                                    803 	.area CONST   (CODE)
                                    804 	.area XINIT   (CODE)
                                    805 	.area CABS    (ABS,CODE)
