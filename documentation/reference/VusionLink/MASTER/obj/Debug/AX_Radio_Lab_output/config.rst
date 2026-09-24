                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module config
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _axradio_fxtal
                                     12 	.globl _axradio_lposckfiltmax
                                     13 	.globl _axradio_sync_slave_rxtimeout
                                     14 	.globl _axradio_sync_slave_rxwindow
                                     15 	.globl _axradio_sync_slave_rxadvance
                                     16 	.globl _axradio_sync_slave_nrrx
                                     17 	.globl _axradio_sync_slave_resyncloss
                                     18 	.globl _axradio_sync_slave_maxperiod
                                     19 	.globl _axradio_sync_slave_syncpause
                                     20 	.globl _axradio_sync_slave_initialsyncwindow
                                     21 	.globl _axradio_sync_slave_syncwindow
                                     22 	.globl _axradio_sync_xoscstartup
                                     23 	.globl _axradio_sync_period
                                     24 	.globl _axradio_wor_period
                                     25 	.globl _axradio_framing_minpayloadlen
                                     26 	.globl _axradio_framing_ack_seqnrpos
                                     27 	.globl _axradio_framing_ack_retransmissions
                                     28 	.globl _axradio_framing_ack_delay
                                     29 	.globl _axradio_framing_ack_timeout
                                     30 	.globl _axradio_framing_enable_sfdcallback
                                     31 	.globl _axradio_framing_syncflags
                                     32 	.globl _axradio_framing_syncword
                                     33 	.globl _axradio_framing_synclen
                                     34 	.globl _axradio_framing_swcrclen
                                     35 	.globl _axradio_framing_lenmask
                                     36 	.globl _axradio_framing_lenoffs
                                     37 	.globl _axradio_framing_lenpos
                                     38 	.globl _axradio_framing_sourceaddrpos
                                     39 	.globl _axradio_framing_destaddrpos
                                     40 	.globl _axradio_framing_addrlen
                                     41 	.globl _axradio_framing_maclen
                                     42 	.globl _axradio_phy_preamble_appendpattern
                                     43 	.globl _axradio_phy_preamble_appendbits
                                     44 	.globl _axradio_phy_preamble_flags
                                     45 	.globl _axradio_phy_preamble_byte
                                     46 	.globl _axradio_phy_preamble_len
                                     47 	.globl _axradio_phy_preamble_longlen
                                     48 	.globl _axradio_phy_preamble_wor_len
                                     49 	.globl _axradio_phy_preamble_wor_longlen
                                     50 	.globl _axradio_phy_lbt_forcetx
                                     51 	.globl _axradio_phy_lbt_retries
                                     52 	.globl _axradio_phy_cs_enabled
                                     53 	.globl _axradio_phy_cs_period
                                     54 	.globl _axradio_phy_channelbusy
                                     55 	.globl _axradio_phy_rssireference
                                     56 	.globl _axradio_phy_rssioffset
                                     57 	.globl _axradio_phy_maxfreqoffset
                                     58 	.globl _axradio_phy_vcocalib
                                     59 	.globl _axradio_phy_chanvcoiinit
                                     60 	.globl _axradio_phy_chanpllrnginit
                                     61 	.globl _axradio_phy_chanfreq
                                     62 	.globl _axradio_phy_nrchannels
                                     63 	.globl _axradio_phy_pn9
                                     64 	.globl _axradio_phy_innerfreqloop
                                     65 	.globl _axradio_byteconv_buffer
                                     66 	.globl _axradio_byteconv
                                     67 	.globl _crc_crc16_msb
                                     68 	.globl _rev8
                                     69 	.globl _PORTC_7
                                     70 	.globl _PORTC_6
                                     71 	.globl _PORTC_5
                                     72 	.globl _PORTC_4
                                     73 	.globl _PORTC_3
                                     74 	.globl _PORTC_2
                                     75 	.globl _PORTC_1
                                     76 	.globl _PORTC_0
                                     77 	.globl _PORTB_7
                                     78 	.globl _PORTB_6
                                     79 	.globl _PORTB_5
                                     80 	.globl _PORTB_4
                                     81 	.globl _PORTB_3
                                     82 	.globl _PORTB_2
                                     83 	.globl _PORTB_1
                                     84 	.globl _PORTB_0
                                     85 	.globl _PORTA_7
                                     86 	.globl _PORTA_6
                                     87 	.globl _PORTA_5
                                     88 	.globl _PORTA_4
                                     89 	.globl _PORTA_3
                                     90 	.globl _PORTA_2
                                     91 	.globl _PORTA_1
                                     92 	.globl _PORTA_0
                                     93 	.globl _PINC_7
                                     94 	.globl _PINC_6
                                     95 	.globl _PINC_5
                                     96 	.globl _PINC_4
                                     97 	.globl _PINC_3
                                     98 	.globl _PINC_2
                                     99 	.globl _PINC_1
                                    100 	.globl _PINC_0
                                    101 	.globl _PINB_7
                                    102 	.globl _PINB_6
                                    103 	.globl _PINB_5
                                    104 	.globl _PINB_4
                                    105 	.globl _PINB_3
                                    106 	.globl _PINB_2
                                    107 	.globl _PINB_1
                                    108 	.globl _PINB_0
                                    109 	.globl _PINA_7
                                    110 	.globl _PINA_6
                                    111 	.globl _PINA_5
                                    112 	.globl _PINA_4
                                    113 	.globl _PINA_3
                                    114 	.globl _PINA_2
                                    115 	.globl _PINA_1
                                    116 	.globl _PINA_0
                                    117 	.globl _CY
                                    118 	.globl _AC
                                    119 	.globl _F0
                                    120 	.globl _RS1
                                    121 	.globl _RS0
                                    122 	.globl _OV
                                    123 	.globl _F1
                                    124 	.globl _P
                                    125 	.globl _IP_7
                                    126 	.globl _IP_6
                                    127 	.globl _IP_5
                                    128 	.globl _IP_4
                                    129 	.globl _IP_3
                                    130 	.globl _IP_2
                                    131 	.globl _IP_1
                                    132 	.globl _IP_0
                                    133 	.globl _EA
                                    134 	.globl _IE_7
                                    135 	.globl _IE_6
                                    136 	.globl _IE_5
                                    137 	.globl _IE_4
                                    138 	.globl _IE_3
                                    139 	.globl _IE_2
                                    140 	.globl _IE_1
                                    141 	.globl _IE_0
                                    142 	.globl _EIP_7
                                    143 	.globl _EIP_6
                                    144 	.globl _EIP_5
                                    145 	.globl _EIP_4
                                    146 	.globl _EIP_3
                                    147 	.globl _EIP_2
                                    148 	.globl _EIP_1
                                    149 	.globl _EIP_0
                                    150 	.globl _EIE_7
                                    151 	.globl _EIE_6
                                    152 	.globl _EIE_5
                                    153 	.globl _EIE_4
                                    154 	.globl _EIE_3
                                    155 	.globl _EIE_2
                                    156 	.globl _EIE_1
                                    157 	.globl _EIE_0
                                    158 	.globl _E2IP_7
                                    159 	.globl _E2IP_6
                                    160 	.globl _E2IP_5
                                    161 	.globl _E2IP_4
                                    162 	.globl _E2IP_3
                                    163 	.globl _E2IP_2
                                    164 	.globl _E2IP_1
                                    165 	.globl _E2IP_0
                                    166 	.globl _E2IE_7
                                    167 	.globl _E2IE_6
                                    168 	.globl _E2IE_5
                                    169 	.globl _E2IE_4
                                    170 	.globl _E2IE_3
                                    171 	.globl _E2IE_2
                                    172 	.globl _E2IE_1
                                    173 	.globl _E2IE_0
                                    174 	.globl _B_7
                                    175 	.globl _B_6
                                    176 	.globl _B_5
                                    177 	.globl _B_4
                                    178 	.globl _B_3
                                    179 	.globl _B_2
                                    180 	.globl _B_1
                                    181 	.globl _B_0
                                    182 	.globl _ACC_7
                                    183 	.globl _ACC_6
                                    184 	.globl _ACC_5
                                    185 	.globl _ACC_4
                                    186 	.globl _ACC_3
                                    187 	.globl _ACC_2
                                    188 	.globl _ACC_1
                                    189 	.globl _ACC_0
                                    190 	.globl _WTSTAT
                                    191 	.globl _WTIRQEN
                                    192 	.globl _WTEVTD
                                    193 	.globl _WTEVTD1
                                    194 	.globl _WTEVTD0
                                    195 	.globl _WTEVTC
                                    196 	.globl _WTEVTC1
                                    197 	.globl _WTEVTC0
                                    198 	.globl _WTEVTB
                                    199 	.globl _WTEVTB1
                                    200 	.globl _WTEVTB0
                                    201 	.globl _WTEVTA
                                    202 	.globl _WTEVTA1
                                    203 	.globl _WTEVTA0
                                    204 	.globl _WTCNTR1
                                    205 	.globl _WTCNTB
                                    206 	.globl _WTCNTB1
                                    207 	.globl _WTCNTB0
                                    208 	.globl _WTCNTA
                                    209 	.globl _WTCNTA1
                                    210 	.globl _WTCNTA0
                                    211 	.globl _WTCFGB
                                    212 	.globl _WTCFGA
                                    213 	.globl _WDTRESET
                                    214 	.globl _WDTCFG
                                    215 	.globl _U1STATUS
                                    216 	.globl _U1SHREG
                                    217 	.globl _U1MODE
                                    218 	.globl _U1CTRL
                                    219 	.globl _U0STATUS
                                    220 	.globl _U0SHREG
                                    221 	.globl _U0MODE
                                    222 	.globl _U0CTRL
                                    223 	.globl _T2STATUS
                                    224 	.globl _T2PERIOD
                                    225 	.globl _T2PERIOD1
                                    226 	.globl _T2PERIOD0
                                    227 	.globl _T2MODE
                                    228 	.globl _T2CNT
                                    229 	.globl _T2CNT1
                                    230 	.globl _T2CNT0
                                    231 	.globl _T2CLKSRC
                                    232 	.globl _T1STATUS
                                    233 	.globl _T1PERIOD
                                    234 	.globl _T1PERIOD1
                                    235 	.globl _T1PERIOD0
                                    236 	.globl _T1MODE
                                    237 	.globl _T1CNT
                                    238 	.globl _T1CNT1
                                    239 	.globl _T1CNT0
                                    240 	.globl _T1CLKSRC
                                    241 	.globl _T0STATUS
                                    242 	.globl _T0PERIOD
                                    243 	.globl _T0PERIOD1
                                    244 	.globl _T0PERIOD0
                                    245 	.globl _T0MODE
                                    246 	.globl _T0CNT
                                    247 	.globl _T0CNT1
                                    248 	.globl _T0CNT0
                                    249 	.globl _T0CLKSRC
                                    250 	.globl _SPSTATUS
                                    251 	.globl _SPSHREG
                                    252 	.globl _SPMODE
                                    253 	.globl _SPCLKSRC
                                    254 	.globl _RADIOSTAT
                                    255 	.globl _RADIOSTAT1
                                    256 	.globl _RADIOSTAT0
                                    257 	.globl _RADIODATA
                                    258 	.globl _RADIODATA3
                                    259 	.globl _RADIODATA2
                                    260 	.globl _RADIODATA1
                                    261 	.globl _RADIODATA0
                                    262 	.globl _RADIOADDR
                                    263 	.globl _RADIOADDR1
                                    264 	.globl _RADIOADDR0
                                    265 	.globl _RADIOACC
                                    266 	.globl _OC1STATUS
                                    267 	.globl _OC1PIN
                                    268 	.globl _OC1MODE
                                    269 	.globl _OC1COMP
                                    270 	.globl _OC1COMP1
                                    271 	.globl _OC1COMP0
                                    272 	.globl _OC0STATUS
                                    273 	.globl _OC0PIN
                                    274 	.globl _OC0MODE
                                    275 	.globl _OC0COMP
                                    276 	.globl _OC0COMP1
                                    277 	.globl _OC0COMP0
                                    278 	.globl _NVSTATUS
                                    279 	.globl _NVKEY
                                    280 	.globl _NVDATA
                                    281 	.globl _NVDATA1
                                    282 	.globl _NVDATA0
                                    283 	.globl _NVADDR
                                    284 	.globl _NVADDR1
                                    285 	.globl _NVADDR0
                                    286 	.globl _IC1STATUS
                                    287 	.globl _IC1MODE
                                    288 	.globl _IC1CAPT
                                    289 	.globl _IC1CAPT1
                                    290 	.globl _IC1CAPT0
                                    291 	.globl _IC0STATUS
                                    292 	.globl _IC0MODE
                                    293 	.globl _IC0CAPT
                                    294 	.globl _IC0CAPT1
                                    295 	.globl _IC0CAPT0
                                    296 	.globl _PORTR
                                    297 	.globl _PORTC
                                    298 	.globl _PORTB
                                    299 	.globl _PORTA
                                    300 	.globl _PINR
                                    301 	.globl _PINC
                                    302 	.globl _PINB
                                    303 	.globl _PINA
                                    304 	.globl _DIRR
                                    305 	.globl _DIRC
                                    306 	.globl _DIRB
                                    307 	.globl _DIRA
                                    308 	.globl _DBGLNKSTAT
                                    309 	.globl _DBGLNKBUF
                                    310 	.globl _CODECONFIG
                                    311 	.globl _CLKSTAT
                                    312 	.globl _CLKCON
                                    313 	.globl _ANALOGCOMP
                                    314 	.globl _ADCCONV
                                    315 	.globl _ADCCLKSRC
                                    316 	.globl _ADCCH3CONFIG
                                    317 	.globl _ADCCH2CONFIG
                                    318 	.globl _ADCCH1CONFIG
                                    319 	.globl _ADCCH0CONFIG
                                    320 	.globl __XPAGE
                                    321 	.globl _XPAGE
                                    322 	.globl _SP
                                    323 	.globl _PSW
                                    324 	.globl _PCON
                                    325 	.globl _IP
                                    326 	.globl _IE
                                    327 	.globl _EIP
                                    328 	.globl _EIE
                                    329 	.globl _E2IP
                                    330 	.globl _E2IE
                                    331 	.globl _DPS
                                    332 	.globl _DPTR1
                                    333 	.globl _DPTR0
                                    334 	.globl _DPL1
                                    335 	.globl _DPL
                                    336 	.globl _DPH1
                                    337 	.globl _DPH
                                    338 	.globl _B
                                    339 	.globl _ACC
                                    340 	.globl _axradio_phy_chanvcoi
                                    341 	.globl _axradio_phy_chanpllrng
                                    342 	.globl _AX5043_TIMEGAIN3NB
                                    343 	.globl _AX5043_TIMEGAIN2NB
                                    344 	.globl _AX5043_TIMEGAIN1NB
                                    345 	.globl _AX5043_TIMEGAIN0NB
                                    346 	.globl _AX5043_RXPARAMSETSNB
                                    347 	.globl _AX5043_RXPARAMCURSETNB
                                    348 	.globl _AX5043_PKTMAXLENNB
                                    349 	.globl _AX5043_PKTLENOFFSETNB
                                    350 	.globl _AX5043_PKTLENCFGNB
                                    351 	.globl _AX5043_PKTADDRMASK3NB
                                    352 	.globl _AX5043_PKTADDRMASK2NB
                                    353 	.globl _AX5043_PKTADDRMASK1NB
                                    354 	.globl _AX5043_PKTADDRMASK0NB
                                    355 	.globl _AX5043_PKTADDRCFGNB
                                    356 	.globl _AX5043_PKTADDR3NB
                                    357 	.globl _AX5043_PKTADDR2NB
                                    358 	.globl _AX5043_PKTADDR1NB
                                    359 	.globl _AX5043_PKTADDR0NB
                                    360 	.globl _AX5043_PHASEGAIN3NB
                                    361 	.globl _AX5043_PHASEGAIN2NB
                                    362 	.globl _AX5043_PHASEGAIN1NB
                                    363 	.globl _AX5043_PHASEGAIN0NB
                                    364 	.globl _AX5043_FREQUENCYLEAKNB
                                    365 	.globl _AX5043_FREQUENCYGAIND3NB
                                    366 	.globl _AX5043_FREQUENCYGAIND2NB
                                    367 	.globl _AX5043_FREQUENCYGAIND1NB
                                    368 	.globl _AX5043_FREQUENCYGAIND0NB
                                    369 	.globl _AX5043_FREQUENCYGAINC3NB
                                    370 	.globl _AX5043_FREQUENCYGAINC2NB
                                    371 	.globl _AX5043_FREQUENCYGAINC1NB
                                    372 	.globl _AX5043_FREQUENCYGAINC0NB
                                    373 	.globl _AX5043_FREQUENCYGAINB3NB
                                    374 	.globl _AX5043_FREQUENCYGAINB2NB
                                    375 	.globl _AX5043_FREQUENCYGAINB1NB
                                    376 	.globl _AX5043_FREQUENCYGAINB0NB
                                    377 	.globl _AX5043_FREQUENCYGAINA3NB
                                    378 	.globl _AX5043_FREQUENCYGAINA2NB
                                    379 	.globl _AX5043_FREQUENCYGAINA1NB
                                    380 	.globl _AX5043_FREQUENCYGAINA0NB
                                    381 	.globl _AX5043_FREQDEV13NB
                                    382 	.globl _AX5043_FREQDEV12NB
                                    383 	.globl _AX5043_FREQDEV11NB
                                    384 	.globl _AX5043_FREQDEV10NB
                                    385 	.globl _AX5043_FREQDEV03NB
                                    386 	.globl _AX5043_FREQDEV02NB
                                    387 	.globl _AX5043_FREQDEV01NB
                                    388 	.globl _AX5043_FREQDEV00NB
                                    389 	.globl _AX5043_FOURFSK3NB
                                    390 	.globl _AX5043_FOURFSK2NB
                                    391 	.globl _AX5043_FOURFSK1NB
                                    392 	.globl _AX5043_FOURFSK0NB
                                    393 	.globl _AX5043_DRGAIN3NB
                                    394 	.globl _AX5043_DRGAIN2NB
                                    395 	.globl _AX5043_DRGAIN1NB
                                    396 	.globl _AX5043_DRGAIN0NB
                                    397 	.globl _AX5043_BBOFFSRES3NB
                                    398 	.globl _AX5043_BBOFFSRES2NB
                                    399 	.globl _AX5043_BBOFFSRES1NB
                                    400 	.globl _AX5043_BBOFFSRES0NB
                                    401 	.globl _AX5043_AMPLITUDEGAIN3NB
                                    402 	.globl _AX5043_AMPLITUDEGAIN2NB
                                    403 	.globl _AX5043_AMPLITUDEGAIN1NB
                                    404 	.globl _AX5043_AMPLITUDEGAIN0NB
                                    405 	.globl _AX5043_AGCTARGET3NB
                                    406 	.globl _AX5043_AGCTARGET2NB
                                    407 	.globl _AX5043_AGCTARGET1NB
                                    408 	.globl _AX5043_AGCTARGET0NB
                                    409 	.globl _AX5043_AGCMINMAX3NB
                                    410 	.globl _AX5043_AGCMINMAX2NB
                                    411 	.globl _AX5043_AGCMINMAX1NB
                                    412 	.globl _AX5043_AGCMINMAX0NB
                                    413 	.globl _AX5043_AGCGAIN3NB
                                    414 	.globl _AX5043_AGCGAIN2NB
                                    415 	.globl _AX5043_AGCGAIN1NB
                                    416 	.globl _AX5043_AGCGAIN0NB
                                    417 	.globl _AX5043_AGCAHYST3NB
                                    418 	.globl _AX5043_AGCAHYST2NB
                                    419 	.globl _AX5043_AGCAHYST1NB
                                    420 	.globl _AX5043_AGCAHYST0NB
                                    421 	.globl _AX5043_0xF44NB
                                    422 	.globl _AX5043_0xF35NB
                                    423 	.globl _AX5043_0xF34NB
                                    424 	.globl _AX5043_0xF33NB
                                    425 	.globl _AX5043_0xF32NB
                                    426 	.globl _AX5043_0xF31NB
                                    427 	.globl _AX5043_0xF30NB
                                    428 	.globl _AX5043_0xF26NB
                                    429 	.globl _AX5043_0xF23NB
                                    430 	.globl _AX5043_0xF22NB
                                    431 	.globl _AX5043_0xF21NB
                                    432 	.globl _AX5043_0xF1CNB
                                    433 	.globl _AX5043_0xF18NB
                                    434 	.globl _AX5043_0xF0CNB
                                    435 	.globl _AX5043_0xF00NB
                                    436 	.globl _AX5043_XTALSTATUSNB
                                    437 	.globl _AX5043_XTALOSCNB
                                    438 	.globl _AX5043_XTALCAPNB
                                    439 	.globl _AX5043_XTALAMPLNB
                                    440 	.globl _AX5043_WAKEUPXOEARLYNB
                                    441 	.globl _AX5043_WAKEUPTIMER1NB
                                    442 	.globl _AX5043_WAKEUPTIMER0NB
                                    443 	.globl _AX5043_WAKEUPFREQ1NB
                                    444 	.globl _AX5043_WAKEUPFREQ0NB
                                    445 	.globl _AX5043_WAKEUP1NB
                                    446 	.globl _AX5043_WAKEUP0NB
                                    447 	.globl _AX5043_TXRATE2NB
                                    448 	.globl _AX5043_TXRATE1NB
                                    449 	.globl _AX5043_TXRATE0NB
                                    450 	.globl _AX5043_TXPWRCOEFFE1NB
                                    451 	.globl _AX5043_TXPWRCOEFFE0NB
                                    452 	.globl _AX5043_TXPWRCOEFFD1NB
                                    453 	.globl _AX5043_TXPWRCOEFFD0NB
                                    454 	.globl _AX5043_TXPWRCOEFFC1NB
                                    455 	.globl _AX5043_TXPWRCOEFFC0NB
                                    456 	.globl _AX5043_TXPWRCOEFFB1NB
                                    457 	.globl _AX5043_TXPWRCOEFFB0NB
                                    458 	.globl _AX5043_TXPWRCOEFFA1NB
                                    459 	.globl _AX5043_TXPWRCOEFFA0NB
                                    460 	.globl _AX5043_TRKRFFREQ2NB
                                    461 	.globl _AX5043_TRKRFFREQ1NB
                                    462 	.globl _AX5043_TRKRFFREQ0NB
                                    463 	.globl _AX5043_TRKPHASE1NB
                                    464 	.globl _AX5043_TRKPHASE0NB
                                    465 	.globl _AX5043_TRKFSKDEMOD1NB
                                    466 	.globl _AX5043_TRKFSKDEMOD0NB
                                    467 	.globl _AX5043_TRKFREQ1NB
                                    468 	.globl _AX5043_TRKFREQ0NB
                                    469 	.globl _AX5043_TRKDATARATE2NB
                                    470 	.globl _AX5043_TRKDATARATE1NB
                                    471 	.globl _AX5043_TRKDATARATE0NB
                                    472 	.globl _AX5043_TRKAMPLITUDE1NB
                                    473 	.globl _AX5043_TRKAMPLITUDE0NB
                                    474 	.globl _AX5043_TRKAFSKDEMOD1NB
                                    475 	.globl _AX5043_TRKAFSKDEMOD0NB
                                    476 	.globl _AX5043_TMGTXSETTLENB
                                    477 	.globl _AX5043_TMGTXBOOSTNB
                                    478 	.globl _AX5043_TMGRXSETTLENB
                                    479 	.globl _AX5043_TMGRXRSSINB
                                    480 	.globl _AX5043_TMGRXPREAMBLE3NB
                                    481 	.globl _AX5043_TMGRXPREAMBLE2NB
                                    482 	.globl _AX5043_TMGRXPREAMBLE1NB
                                    483 	.globl _AX5043_TMGRXOFFSACQNB
                                    484 	.globl _AX5043_TMGRXCOARSEAGCNB
                                    485 	.globl _AX5043_TMGRXBOOSTNB
                                    486 	.globl _AX5043_TMGRXAGCNB
                                    487 	.globl _AX5043_TIMER2NB
                                    488 	.globl _AX5043_TIMER1NB
                                    489 	.globl _AX5043_TIMER0NB
                                    490 	.globl _AX5043_SILICONREVISIONNB
                                    491 	.globl _AX5043_SCRATCHNB
                                    492 	.globl _AX5043_RXDATARATE2NB
                                    493 	.globl _AX5043_RXDATARATE1NB
                                    494 	.globl _AX5043_RXDATARATE0NB
                                    495 	.globl _AX5043_RSSIREFERENCENB
                                    496 	.globl _AX5043_RSSIABSTHRNB
                                    497 	.globl _AX5043_RSSINB
                                    498 	.globl _AX5043_REFNB
                                    499 	.globl _AX5043_RADIOSTATENB
                                    500 	.globl _AX5043_RADIOEVENTREQ1NB
                                    501 	.globl _AX5043_RADIOEVENTREQ0NB
                                    502 	.globl _AX5043_RADIOEVENTMASK1NB
                                    503 	.globl _AX5043_RADIOEVENTMASK0NB
                                    504 	.globl _AX5043_PWRMODENB
                                    505 	.globl _AX5043_PWRAMPNB
                                    506 	.globl _AX5043_POWSTICKYSTATNB
                                    507 	.globl _AX5043_POWSTATNB
                                    508 	.globl _AX5043_POWIRQMASKNB
                                    509 	.globl _AX5043_POWCTRL1NB
                                    510 	.globl _AX5043_PLLVCOIRNB
                                    511 	.globl _AX5043_PLLVCOINB
                                    512 	.globl _AX5043_PLLVCODIVNB
                                    513 	.globl _AX5043_PLLRNGCLKNB
                                    514 	.globl _AX5043_PLLRANGINGBNB
                                    515 	.globl _AX5043_PLLRANGINGANB
                                    516 	.globl _AX5043_PLLLOOPBOOSTNB
                                    517 	.globl _AX5043_PLLLOOPNB
                                    518 	.globl _AX5043_PLLLOCKDETNB
                                    519 	.globl _AX5043_PLLCPIBOOSTNB
                                    520 	.globl _AX5043_PLLCPINB
                                    521 	.globl _AX5043_PKTSTOREFLAGSNB
                                    522 	.globl _AX5043_PKTMISCFLAGSNB
                                    523 	.globl _AX5043_PKTCHUNKSIZENB
                                    524 	.globl _AX5043_PKTACCEPTFLAGSNB
                                    525 	.globl _AX5043_PINSTATENB
                                    526 	.globl _AX5043_PINFUNCSYSCLKNB
                                    527 	.globl _AX5043_PINFUNCPWRAMPNB
                                    528 	.globl _AX5043_PINFUNCIRQNB
                                    529 	.globl _AX5043_PINFUNCDCLKNB
                                    530 	.globl _AX5043_PINFUNCDATANB
                                    531 	.globl _AX5043_PINFUNCANTSELNB
                                    532 	.globl _AX5043_MODULATIONNB
                                    533 	.globl _AX5043_MODCFGPNB
                                    534 	.globl _AX5043_MODCFGFNB
                                    535 	.globl _AX5043_MODCFGANB
                                    536 	.globl _AX5043_MAXRFOFFSET2NB
                                    537 	.globl _AX5043_MAXRFOFFSET1NB
                                    538 	.globl _AX5043_MAXRFOFFSET0NB
                                    539 	.globl _AX5043_MAXDROFFSET2NB
                                    540 	.globl _AX5043_MAXDROFFSET1NB
                                    541 	.globl _AX5043_MAXDROFFSET0NB
                                    542 	.globl _AX5043_MATCH1PAT1NB
                                    543 	.globl _AX5043_MATCH1PAT0NB
                                    544 	.globl _AX5043_MATCH1MINNB
                                    545 	.globl _AX5043_MATCH1MAXNB
                                    546 	.globl _AX5043_MATCH1LENNB
                                    547 	.globl _AX5043_MATCH0PAT3NB
                                    548 	.globl _AX5043_MATCH0PAT2NB
                                    549 	.globl _AX5043_MATCH0PAT1NB
                                    550 	.globl _AX5043_MATCH0PAT0NB
                                    551 	.globl _AX5043_MATCH0MINNB
                                    552 	.globl _AX5043_MATCH0MAXNB
                                    553 	.globl _AX5043_MATCH0LENNB
                                    554 	.globl _AX5043_LPOSCSTATUSNB
                                    555 	.globl _AX5043_LPOSCREF1NB
                                    556 	.globl _AX5043_LPOSCREF0NB
                                    557 	.globl _AX5043_LPOSCPER1NB
                                    558 	.globl _AX5043_LPOSCPER0NB
                                    559 	.globl _AX5043_LPOSCKFILT1NB
                                    560 	.globl _AX5043_LPOSCKFILT0NB
                                    561 	.globl _AX5043_LPOSCFREQ1NB
                                    562 	.globl _AX5043_LPOSCFREQ0NB
                                    563 	.globl _AX5043_LPOSCCONFIGNB
                                    564 	.globl _AX5043_IRQREQUEST1NB
                                    565 	.globl _AX5043_IRQREQUEST0NB
                                    566 	.globl _AX5043_IRQMASK1NB
                                    567 	.globl _AX5043_IRQMASK0NB
                                    568 	.globl _AX5043_IRQINVERSION1NB
                                    569 	.globl _AX5043_IRQINVERSION0NB
                                    570 	.globl _AX5043_IFFREQ1NB
                                    571 	.globl _AX5043_IFFREQ0NB
                                    572 	.globl _AX5043_GPADCPERIODNB
                                    573 	.globl _AX5043_GPADCCTRLNB
                                    574 	.globl _AX5043_GPADC13VALUE1NB
                                    575 	.globl _AX5043_GPADC13VALUE0NB
                                    576 	.globl _AX5043_FSKDMIN1NB
                                    577 	.globl _AX5043_FSKDMIN0NB
                                    578 	.globl _AX5043_FSKDMAX1NB
                                    579 	.globl _AX5043_FSKDMAX0NB
                                    580 	.globl _AX5043_FSKDEV2NB
                                    581 	.globl _AX5043_FSKDEV1NB
                                    582 	.globl _AX5043_FSKDEV0NB
                                    583 	.globl _AX5043_FREQB3NB
                                    584 	.globl _AX5043_FREQB2NB
                                    585 	.globl _AX5043_FREQB1NB
                                    586 	.globl _AX5043_FREQB0NB
                                    587 	.globl _AX5043_FREQA3NB
                                    588 	.globl _AX5043_FREQA2NB
                                    589 	.globl _AX5043_FREQA1NB
                                    590 	.globl _AX5043_FREQA0NB
                                    591 	.globl _AX5043_FRAMINGNB
                                    592 	.globl _AX5043_FIFOTHRESH1NB
                                    593 	.globl _AX5043_FIFOTHRESH0NB
                                    594 	.globl _AX5043_FIFOSTATNB
                                    595 	.globl _AX5043_FIFOFREE1NB
                                    596 	.globl _AX5043_FIFOFREE0NB
                                    597 	.globl _AX5043_FIFODATANB
                                    598 	.globl _AX5043_FIFOCOUNT1NB
                                    599 	.globl _AX5043_FIFOCOUNT0NB
                                    600 	.globl _AX5043_FECSYNCNB
                                    601 	.globl _AX5043_FECSTATUSNB
                                    602 	.globl _AX5043_FECNB
                                    603 	.globl _AX5043_ENCODINGNB
                                    604 	.globl _AX5043_DIVERSITYNB
                                    605 	.globl _AX5043_DECIMATIONNB
                                    606 	.globl _AX5043_DACVALUE1NB
                                    607 	.globl _AX5043_DACVALUE0NB
                                    608 	.globl _AX5043_DACCONFIGNB
                                    609 	.globl _AX5043_CRCINIT3NB
                                    610 	.globl _AX5043_CRCINIT2NB
                                    611 	.globl _AX5043_CRCINIT1NB
                                    612 	.globl _AX5043_CRCINIT0NB
                                    613 	.globl _AX5043_BGNDRSSITHRNB
                                    614 	.globl _AX5043_BGNDRSSIGAINNB
                                    615 	.globl _AX5043_BGNDRSSINB
                                    616 	.globl _AX5043_BBTUNENB
                                    617 	.globl _AX5043_BBOFFSCAPNB
                                    618 	.globl _AX5043_AMPLFILTERNB
                                    619 	.globl _AX5043_AGCCOUNTERNB
                                    620 	.globl _AX5043_AFSKSPACE1NB
                                    621 	.globl _AX5043_AFSKSPACE0NB
                                    622 	.globl _AX5043_AFSKMARK1NB
                                    623 	.globl _AX5043_AFSKMARK0NB
                                    624 	.globl _AX5043_AFSKCTRLNB
                                    625 	.globl _AX5043_TIMEGAIN3
                                    626 	.globl _AX5043_TIMEGAIN2
                                    627 	.globl _AX5043_TIMEGAIN1
                                    628 	.globl _AX5043_TIMEGAIN0
                                    629 	.globl _AX5043_RXPARAMSETS
                                    630 	.globl _AX5043_RXPARAMCURSET
                                    631 	.globl _AX5043_PKTMAXLEN
                                    632 	.globl _AX5043_PKTLENOFFSET
                                    633 	.globl _AX5043_PKTLENCFG
                                    634 	.globl _AX5043_PKTADDRMASK3
                                    635 	.globl _AX5043_PKTADDRMASK2
                                    636 	.globl _AX5043_PKTADDRMASK1
                                    637 	.globl _AX5043_PKTADDRMASK0
                                    638 	.globl _AX5043_PKTADDRCFG
                                    639 	.globl _AX5043_PKTADDR3
                                    640 	.globl _AX5043_PKTADDR2
                                    641 	.globl _AX5043_PKTADDR1
                                    642 	.globl _AX5043_PKTADDR0
                                    643 	.globl _AX5043_PHASEGAIN3
                                    644 	.globl _AX5043_PHASEGAIN2
                                    645 	.globl _AX5043_PHASEGAIN1
                                    646 	.globl _AX5043_PHASEGAIN0
                                    647 	.globl _AX5043_FREQUENCYLEAK
                                    648 	.globl _AX5043_FREQUENCYGAIND3
                                    649 	.globl _AX5043_FREQUENCYGAIND2
                                    650 	.globl _AX5043_FREQUENCYGAIND1
                                    651 	.globl _AX5043_FREQUENCYGAIND0
                                    652 	.globl _AX5043_FREQUENCYGAINC3
                                    653 	.globl _AX5043_FREQUENCYGAINC2
                                    654 	.globl _AX5043_FREQUENCYGAINC1
                                    655 	.globl _AX5043_FREQUENCYGAINC0
                                    656 	.globl _AX5043_FREQUENCYGAINB3
                                    657 	.globl _AX5043_FREQUENCYGAINB2
                                    658 	.globl _AX5043_FREQUENCYGAINB1
                                    659 	.globl _AX5043_FREQUENCYGAINB0
                                    660 	.globl _AX5043_FREQUENCYGAINA3
                                    661 	.globl _AX5043_FREQUENCYGAINA2
                                    662 	.globl _AX5043_FREQUENCYGAINA1
                                    663 	.globl _AX5043_FREQUENCYGAINA0
                                    664 	.globl _AX5043_FREQDEV13
                                    665 	.globl _AX5043_FREQDEV12
                                    666 	.globl _AX5043_FREQDEV11
                                    667 	.globl _AX5043_FREQDEV10
                                    668 	.globl _AX5043_FREQDEV03
                                    669 	.globl _AX5043_FREQDEV02
                                    670 	.globl _AX5043_FREQDEV01
                                    671 	.globl _AX5043_FREQDEV00
                                    672 	.globl _AX5043_FOURFSK3
                                    673 	.globl _AX5043_FOURFSK2
                                    674 	.globl _AX5043_FOURFSK1
                                    675 	.globl _AX5043_FOURFSK0
                                    676 	.globl _AX5043_DRGAIN3
                                    677 	.globl _AX5043_DRGAIN2
                                    678 	.globl _AX5043_DRGAIN1
                                    679 	.globl _AX5043_DRGAIN0
                                    680 	.globl _AX5043_BBOFFSRES3
                                    681 	.globl _AX5043_BBOFFSRES2
                                    682 	.globl _AX5043_BBOFFSRES1
                                    683 	.globl _AX5043_BBOFFSRES0
                                    684 	.globl _AX5043_AMPLITUDEGAIN3
                                    685 	.globl _AX5043_AMPLITUDEGAIN2
                                    686 	.globl _AX5043_AMPLITUDEGAIN1
                                    687 	.globl _AX5043_AMPLITUDEGAIN0
                                    688 	.globl _AX5043_AGCTARGET3
                                    689 	.globl _AX5043_AGCTARGET2
                                    690 	.globl _AX5043_AGCTARGET1
                                    691 	.globl _AX5043_AGCTARGET0
                                    692 	.globl _AX5043_AGCMINMAX3
                                    693 	.globl _AX5043_AGCMINMAX2
                                    694 	.globl _AX5043_AGCMINMAX1
                                    695 	.globl _AX5043_AGCMINMAX0
                                    696 	.globl _AX5043_AGCGAIN3
                                    697 	.globl _AX5043_AGCGAIN2
                                    698 	.globl _AX5043_AGCGAIN1
                                    699 	.globl _AX5043_AGCGAIN0
                                    700 	.globl _AX5043_AGCAHYST3
                                    701 	.globl _AX5043_AGCAHYST2
                                    702 	.globl _AX5043_AGCAHYST1
                                    703 	.globl _AX5043_AGCAHYST0
                                    704 	.globl _AX5043_0xF44
                                    705 	.globl _AX5043_0xF35
                                    706 	.globl _AX5043_0xF34
                                    707 	.globl _AX5043_0xF33
                                    708 	.globl _AX5043_0xF32
                                    709 	.globl _AX5043_0xF31
                                    710 	.globl _AX5043_0xF30
                                    711 	.globl _AX5043_0xF26
                                    712 	.globl _AX5043_0xF23
                                    713 	.globl _AX5043_0xF22
                                    714 	.globl _AX5043_0xF21
                                    715 	.globl _AX5043_0xF1C
                                    716 	.globl _AX5043_0xF18
                                    717 	.globl _AX5043_0xF0C
                                    718 	.globl _AX5043_0xF00
                                    719 	.globl _AX5043_XTALSTATUS
                                    720 	.globl _AX5043_XTALOSC
                                    721 	.globl _AX5043_XTALCAP
                                    722 	.globl _AX5043_XTALAMPL
                                    723 	.globl _AX5043_WAKEUPXOEARLY
                                    724 	.globl _AX5043_WAKEUPTIMER1
                                    725 	.globl _AX5043_WAKEUPTIMER0
                                    726 	.globl _AX5043_WAKEUPFREQ1
                                    727 	.globl _AX5043_WAKEUPFREQ0
                                    728 	.globl _AX5043_WAKEUP1
                                    729 	.globl _AX5043_WAKEUP0
                                    730 	.globl _AX5043_TXRATE2
                                    731 	.globl _AX5043_TXRATE1
                                    732 	.globl _AX5043_TXRATE0
                                    733 	.globl _AX5043_TXPWRCOEFFE1
                                    734 	.globl _AX5043_TXPWRCOEFFE0
                                    735 	.globl _AX5043_TXPWRCOEFFD1
                                    736 	.globl _AX5043_TXPWRCOEFFD0
                                    737 	.globl _AX5043_TXPWRCOEFFC1
                                    738 	.globl _AX5043_TXPWRCOEFFC0
                                    739 	.globl _AX5043_TXPWRCOEFFB1
                                    740 	.globl _AX5043_TXPWRCOEFFB0
                                    741 	.globl _AX5043_TXPWRCOEFFA1
                                    742 	.globl _AX5043_TXPWRCOEFFA0
                                    743 	.globl _AX5043_TRKRFFREQ2
                                    744 	.globl _AX5043_TRKRFFREQ1
                                    745 	.globl _AX5043_TRKRFFREQ0
                                    746 	.globl _AX5043_TRKPHASE1
                                    747 	.globl _AX5043_TRKPHASE0
                                    748 	.globl _AX5043_TRKFSKDEMOD1
                                    749 	.globl _AX5043_TRKFSKDEMOD0
                                    750 	.globl _AX5043_TRKFREQ1
                                    751 	.globl _AX5043_TRKFREQ0
                                    752 	.globl _AX5043_TRKDATARATE2
                                    753 	.globl _AX5043_TRKDATARATE1
                                    754 	.globl _AX5043_TRKDATARATE0
                                    755 	.globl _AX5043_TRKAMPLITUDE1
                                    756 	.globl _AX5043_TRKAMPLITUDE0
                                    757 	.globl _AX5043_TRKAFSKDEMOD1
                                    758 	.globl _AX5043_TRKAFSKDEMOD0
                                    759 	.globl _AX5043_TMGTXSETTLE
                                    760 	.globl _AX5043_TMGTXBOOST
                                    761 	.globl _AX5043_TMGRXSETTLE
                                    762 	.globl _AX5043_TMGRXRSSI
                                    763 	.globl _AX5043_TMGRXPREAMBLE3
                                    764 	.globl _AX5043_TMGRXPREAMBLE2
                                    765 	.globl _AX5043_TMGRXPREAMBLE1
                                    766 	.globl _AX5043_TMGRXOFFSACQ
                                    767 	.globl _AX5043_TMGRXCOARSEAGC
                                    768 	.globl _AX5043_TMGRXBOOST
                                    769 	.globl _AX5043_TMGRXAGC
                                    770 	.globl _AX5043_TIMER2
                                    771 	.globl _AX5043_TIMER1
                                    772 	.globl _AX5043_TIMER0
                                    773 	.globl _AX5043_SILICONREVISION
                                    774 	.globl _AX5043_SCRATCH
                                    775 	.globl _AX5043_RXDATARATE2
                                    776 	.globl _AX5043_RXDATARATE1
                                    777 	.globl _AX5043_RXDATARATE0
                                    778 	.globl _AX5043_RSSIREFERENCE
                                    779 	.globl _AX5043_RSSIABSTHR
                                    780 	.globl _AX5043_RSSI
                                    781 	.globl _AX5043_REF
                                    782 	.globl _AX5043_RADIOSTATE
                                    783 	.globl _AX5043_RADIOEVENTREQ1
                                    784 	.globl _AX5043_RADIOEVENTREQ0
                                    785 	.globl _AX5043_RADIOEVENTMASK1
                                    786 	.globl _AX5043_RADIOEVENTMASK0
                                    787 	.globl _AX5043_PWRMODE
                                    788 	.globl _AX5043_PWRAMP
                                    789 	.globl _AX5043_POWSTICKYSTAT
                                    790 	.globl _AX5043_POWSTAT
                                    791 	.globl _AX5043_POWIRQMASK
                                    792 	.globl _AX5043_POWCTRL1
                                    793 	.globl _AX5043_PLLVCOIR
                                    794 	.globl _AX5043_PLLVCOI
                                    795 	.globl _AX5043_PLLVCODIV
                                    796 	.globl _AX5043_PLLRNGCLK
                                    797 	.globl _AX5043_PLLRANGINGB
                                    798 	.globl _AX5043_PLLRANGINGA
                                    799 	.globl _AX5043_PLLLOOPBOOST
                                    800 	.globl _AX5043_PLLLOOP
                                    801 	.globl _AX5043_PLLLOCKDET
                                    802 	.globl _AX5043_PLLCPIBOOST
                                    803 	.globl _AX5043_PLLCPI
                                    804 	.globl _AX5043_PKTSTOREFLAGS
                                    805 	.globl _AX5043_PKTMISCFLAGS
                                    806 	.globl _AX5043_PKTCHUNKSIZE
                                    807 	.globl _AX5043_PKTACCEPTFLAGS
                                    808 	.globl _AX5043_PINSTATE
                                    809 	.globl _AX5043_PINFUNCSYSCLK
                                    810 	.globl _AX5043_PINFUNCPWRAMP
                                    811 	.globl _AX5043_PINFUNCIRQ
                                    812 	.globl _AX5043_PINFUNCDCLK
                                    813 	.globl _AX5043_PINFUNCDATA
                                    814 	.globl _AX5043_PINFUNCANTSEL
                                    815 	.globl _AX5043_MODULATION
                                    816 	.globl _AX5043_MODCFGP
                                    817 	.globl _AX5043_MODCFGF
                                    818 	.globl _AX5043_MODCFGA
                                    819 	.globl _AX5043_MAXRFOFFSET2
                                    820 	.globl _AX5043_MAXRFOFFSET1
                                    821 	.globl _AX5043_MAXRFOFFSET0
                                    822 	.globl _AX5043_MAXDROFFSET2
                                    823 	.globl _AX5043_MAXDROFFSET1
                                    824 	.globl _AX5043_MAXDROFFSET0
                                    825 	.globl _AX5043_MATCH1PAT1
                                    826 	.globl _AX5043_MATCH1PAT0
                                    827 	.globl _AX5043_MATCH1MIN
                                    828 	.globl _AX5043_MATCH1MAX
                                    829 	.globl _AX5043_MATCH1LEN
                                    830 	.globl _AX5043_MATCH0PAT3
                                    831 	.globl _AX5043_MATCH0PAT2
                                    832 	.globl _AX5043_MATCH0PAT1
                                    833 	.globl _AX5043_MATCH0PAT0
                                    834 	.globl _AX5043_MATCH0MIN
                                    835 	.globl _AX5043_MATCH0MAX
                                    836 	.globl _AX5043_MATCH0LEN
                                    837 	.globl _AX5043_LPOSCSTATUS
                                    838 	.globl _AX5043_LPOSCREF1
                                    839 	.globl _AX5043_LPOSCREF0
                                    840 	.globl _AX5043_LPOSCPER1
                                    841 	.globl _AX5043_LPOSCPER0
                                    842 	.globl _AX5043_LPOSCKFILT1
                                    843 	.globl _AX5043_LPOSCKFILT0
                                    844 	.globl _AX5043_LPOSCFREQ1
                                    845 	.globl _AX5043_LPOSCFREQ0
                                    846 	.globl _AX5043_LPOSCCONFIG
                                    847 	.globl _AX5043_IRQREQUEST1
                                    848 	.globl _AX5043_IRQREQUEST0
                                    849 	.globl _AX5043_IRQMASK1
                                    850 	.globl _AX5043_IRQMASK0
                                    851 	.globl _AX5043_IRQINVERSION1
                                    852 	.globl _AX5043_IRQINVERSION0
                                    853 	.globl _AX5043_IFFREQ1
                                    854 	.globl _AX5043_IFFREQ0
                                    855 	.globl _AX5043_GPADCPERIOD
                                    856 	.globl _AX5043_GPADCCTRL
                                    857 	.globl _AX5043_GPADC13VALUE1
                                    858 	.globl _AX5043_GPADC13VALUE0
                                    859 	.globl _AX5043_FSKDMIN1
                                    860 	.globl _AX5043_FSKDMIN0
                                    861 	.globl _AX5043_FSKDMAX1
                                    862 	.globl _AX5043_FSKDMAX0
                                    863 	.globl _AX5043_FSKDEV2
                                    864 	.globl _AX5043_FSKDEV1
                                    865 	.globl _AX5043_FSKDEV0
                                    866 	.globl _AX5043_FREQB3
                                    867 	.globl _AX5043_FREQB2
                                    868 	.globl _AX5043_FREQB1
                                    869 	.globl _AX5043_FREQB0
                                    870 	.globl _AX5043_FREQA3
                                    871 	.globl _AX5043_FREQA2
                                    872 	.globl _AX5043_FREQA1
                                    873 	.globl _AX5043_FREQA0
                                    874 	.globl _AX5043_FRAMING
                                    875 	.globl _AX5043_FIFOTHRESH1
                                    876 	.globl _AX5043_FIFOTHRESH0
                                    877 	.globl _AX5043_FIFOSTAT
                                    878 	.globl _AX5043_FIFOFREE1
                                    879 	.globl _AX5043_FIFOFREE0
                                    880 	.globl _AX5043_FIFODATA
                                    881 	.globl _AX5043_FIFOCOUNT1
                                    882 	.globl _AX5043_FIFOCOUNT0
                                    883 	.globl _AX5043_FECSYNC
                                    884 	.globl _AX5043_FECSTATUS
                                    885 	.globl _AX5043_FEC
                                    886 	.globl _AX5043_ENCODING
                                    887 	.globl _AX5043_DIVERSITY
                                    888 	.globl _AX5043_DECIMATION
                                    889 	.globl _AX5043_DACVALUE1
                                    890 	.globl _AX5043_DACVALUE0
                                    891 	.globl _AX5043_DACCONFIG
                                    892 	.globl _AX5043_CRCINIT3
                                    893 	.globl _AX5043_CRCINIT2
                                    894 	.globl _AX5043_CRCINIT1
                                    895 	.globl _AX5043_CRCINIT0
                                    896 	.globl _AX5043_BGNDRSSITHR
                                    897 	.globl _AX5043_BGNDRSSIGAIN
                                    898 	.globl _AX5043_BGNDRSSI
                                    899 	.globl _AX5043_BBTUNE
                                    900 	.globl _AX5043_BBOFFSCAP
                                    901 	.globl _AX5043_AMPLFILTER
                                    902 	.globl _AX5043_AGCCOUNTER
                                    903 	.globl _AX5043_AFSKSPACE1
                                    904 	.globl _AX5043_AFSKSPACE0
                                    905 	.globl _AX5043_AFSKMARK1
                                    906 	.globl _AX5043_AFSKMARK0
                                    907 	.globl _AX5043_AFSKCTRL
                                    908 	.globl _XTALREADY
                                    909 	.globl _XTALOSC
                                    910 	.globl _XTALAMPL
                                    911 	.globl _SILICONREV
                                    912 	.globl _SCRATCH3
                                    913 	.globl _SCRATCH2
                                    914 	.globl _SCRATCH1
                                    915 	.globl _SCRATCH0
                                    916 	.globl _RADIOMUX
                                    917 	.globl _RADIOFSTATADDR
                                    918 	.globl _RADIOFSTATADDR1
                                    919 	.globl _RADIOFSTATADDR0
                                    920 	.globl _RADIOFDATAADDR
                                    921 	.globl _RADIOFDATAADDR1
                                    922 	.globl _RADIOFDATAADDR0
                                    923 	.globl _OSCRUN
                                    924 	.globl _OSCREADY
                                    925 	.globl _OSCFORCERUN
                                    926 	.globl _OSCCALIB
                                    927 	.globl _MISCCTRL
                                    928 	.globl _LPXOSCGM
                                    929 	.globl _LPOSCREF
                                    930 	.globl _LPOSCREF1
                                    931 	.globl _LPOSCREF0
                                    932 	.globl _LPOSCPER
                                    933 	.globl _LPOSCPER1
                                    934 	.globl _LPOSCPER0
                                    935 	.globl _LPOSCKFILT
                                    936 	.globl _LPOSCKFILT1
                                    937 	.globl _LPOSCKFILT0
                                    938 	.globl _LPOSCFREQ
                                    939 	.globl _LPOSCFREQ1
                                    940 	.globl _LPOSCFREQ0
                                    941 	.globl _LPOSCCONFIG
                                    942 	.globl _PINSEL
                                    943 	.globl _PINCHGC
                                    944 	.globl _PINCHGB
                                    945 	.globl _PINCHGA
                                    946 	.globl _PALTRADIO
                                    947 	.globl _PALTC
                                    948 	.globl _PALTB
                                    949 	.globl _PALTA
                                    950 	.globl _INTCHGC
                                    951 	.globl _INTCHGB
                                    952 	.globl _INTCHGA
                                    953 	.globl _EXTIRQ
                                    954 	.globl _GPIOENABLE
                                    955 	.globl _ANALOGA
                                    956 	.globl _FRCOSCREF
                                    957 	.globl _FRCOSCREF1
                                    958 	.globl _FRCOSCREF0
                                    959 	.globl _FRCOSCPER
                                    960 	.globl _FRCOSCPER1
                                    961 	.globl _FRCOSCPER0
                                    962 	.globl _FRCOSCKFILT
                                    963 	.globl _FRCOSCKFILT1
                                    964 	.globl _FRCOSCKFILT0
                                    965 	.globl _FRCOSCFREQ
                                    966 	.globl _FRCOSCFREQ1
                                    967 	.globl _FRCOSCFREQ0
                                    968 	.globl _FRCOSCCTRL
                                    969 	.globl _FRCOSCCONFIG
                                    970 	.globl _DMA1CONFIG
                                    971 	.globl _DMA1ADDR
                                    972 	.globl _DMA1ADDR1
                                    973 	.globl _DMA1ADDR0
                                    974 	.globl _DMA0CONFIG
                                    975 	.globl _DMA0ADDR
                                    976 	.globl _DMA0ADDR1
                                    977 	.globl _DMA0ADDR0
                                    978 	.globl _ADCTUNE2
                                    979 	.globl _ADCTUNE1
                                    980 	.globl _ADCTUNE0
                                    981 	.globl _ADCCH3VAL
                                    982 	.globl _ADCCH3VAL1
                                    983 	.globl _ADCCH3VAL0
                                    984 	.globl _ADCCH2VAL
                                    985 	.globl _ADCCH2VAL1
                                    986 	.globl _ADCCH2VAL0
                                    987 	.globl _ADCCH1VAL
                                    988 	.globl _ADCCH1VAL1
                                    989 	.globl _ADCCH1VAL0
                                    990 	.globl _ADCCH0VAL
                                    991 	.globl _ADCCH0VAL1
                                    992 	.globl _ADCCH0VAL0
                                    993 	.globl _ax5043_set_registers
                                    994 	.globl _ax5043_set_registers_tx
                                    995 	.globl _ax5043_set_registers_rx
                                    996 	.globl _ax5043_set_registers_rxwor
                                    997 	.globl _ax5043_set_registers_rxcont
                                    998 	.globl _ax5043_set_registers_rxcont_singleparamset
                                    999 	.globl _axradio_setup_pincfg1
                                   1000 	.globl _axradio_setup_pincfg2
                                   1001 	.globl _axradio_conv_freq_fromhz
                                   1002 	.globl _axradio_conv_freq_tohz
                                   1003 	.globl _axradio_conv_freq_fromreg
                                   1004 	.globl _axradio_conv_timeinterval_totimer0
                                   1005 	.globl _axradio_framing_check_crc
                                   1006 	.globl _axradio_framing_append_crc
                                   1007 ;--------------------------------------------------------
                                   1008 ; special function registers
                                   1009 ;--------------------------------------------------------
                                   1010 	.area RSEG    (ABS,DATA)
      000000                       1011 	.org 0x0000
                           0000E0  1012 G$ACC$0$0 == 0x00e0
                           0000E0  1013 _ACC	=	0x00e0
                           0000F0  1014 G$B$0$0 == 0x00f0
                           0000F0  1015 _B	=	0x00f0
                           000083  1016 G$DPH$0$0 == 0x0083
                           000083  1017 _DPH	=	0x0083
                           000085  1018 G$DPH1$0$0 == 0x0085
                           000085  1019 _DPH1	=	0x0085
                           000082  1020 G$DPL$0$0 == 0x0082
                           000082  1021 _DPL	=	0x0082
                           000084  1022 G$DPL1$0$0 == 0x0084
                           000084  1023 _DPL1	=	0x0084
                           008382  1024 G$DPTR0$0$0 == 0x8382
                           008382  1025 _DPTR0	=	0x8382
                           008584  1026 G$DPTR1$0$0 == 0x8584
                           008584  1027 _DPTR1	=	0x8584
                           000086  1028 G$DPS$0$0 == 0x0086
                           000086  1029 _DPS	=	0x0086
                           0000A0  1030 G$E2IE$0$0 == 0x00a0
                           0000A0  1031 _E2IE	=	0x00a0
                           0000C0  1032 G$E2IP$0$0 == 0x00c0
                           0000C0  1033 _E2IP	=	0x00c0
                           000098  1034 G$EIE$0$0 == 0x0098
                           000098  1035 _EIE	=	0x0098
                           0000B0  1036 G$EIP$0$0 == 0x00b0
                           0000B0  1037 _EIP	=	0x00b0
                           0000A8  1038 G$IE$0$0 == 0x00a8
                           0000A8  1039 _IE	=	0x00a8
                           0000B8  1040 G$IP$0$0 == 0x00b8
                           0000B8  1041 _IP	=	0x00b8
                           000087  1042 G$PCON$0$0 == 0x0087
                           000087  1043 _PCON	=	0x0087
                           0000D0  1044 G$PSW$0$0 == 0x00d0
                           0000D0  1045 _PSW	=	0x00d0
                           000081  1046 G$SP$0$0 == 0x0081
                           000081  1047 _SP	=	0x0081
                           0000D9  1048 G$XPAGE$0$0 == 0x00d9
                           0000D9  1049 _XPAGE	=	0x00d9
                           0000D9  1050 G$_XPAGE$0$0 == 0x00d9
                           0000D9  1051 __XPAGE	=	0x00d9
                           0000CA  1052 G$ADCCH0CONFIG$0$0 == 0x00ca
                           0000CA  1053 _ADCCH0CONFIG	=	0x00ca
                           0000CB  1054 G$ADCCH1CONFIG$0$0 == 0x00cb
                           0000CB  1055 _ADCCH1CONFIG	=	0x00cb
                           0000D2  1056 G$ADCCH2CONFIG$0$0 == 0x00d2
                           0000D2  1057 _ADCCH2CONFIG	=	0x00d2
                           0000D3  1058 G$ADCCH3CONFIG$0$0 == 0x00d3
                           0000D3  1059 _ADCCH3CONFIG	=	0x00d3
                           0000D1  1060 G$ADCCLKSRC$0$0 == 0x00d1
                           0000D1  1061 _ADCCLKSRC	=	0x00d1
                           0000C9  1062 G$ADCCONV$0$0 == 0x00c9
                           0000C9  1063 _ADCCONV	=	0x00c9
                           0000E1  1064 G$ANALOGCOMP$0$0 == 0x00e1
                           0000E1  1065 _ANALOGCOMP	=	0x00e1
                           0000C6  1066 G$CLKCON$0$0 == 0x00c6
                           0000C6  1067 _CLKCON	=	0x00c6
                           0000C7  1068 G$CLKSTAT$0$0 == 0x00c7
                           0000C7  1069 _CLKSTAT	=	0x00c7
                           000097  1070 G$CODECONFIG$0$0 == 0x0097
                           000097  1071 _CODECONFIG	=	0x0097
                           0000E3  1072 G$DBGLNKBUF$0$0 == 0x00e3
                           0000E3  1073 _DBGLNKBUF	=	0x00e3
                           0000E2  1074 G$DBGLNKSTAT$0$0 == 0x00e2
                           0000E2  1075 _DBGLNKSTAT	=	0x00e2
                           000089  1076 G$DIRA$0$0 == 0x0089
                           000089  1077 _DIRA	=	0x0089
                           00008A  1078 G$DIRB$0$0 == 0x008a
                           00008A  1079 _DIRB	=	0x008a
                           00008B  1080 G$DIRC$0$0 == 0x008b
                           00008B  1081 _DIRC	=	0x008b
                           00008E  1082 G$DIRR$0$0 == 0x008e
                           00008E  1083 _DIRR	=	0x008e
                           0000C8  1084 G$PINA$0$0 == 0x00c8
                           0000C8  1085 _PINA	=	0x00c8
                           0000E8  1086 G$PINB$0$0 == 0x00e8
                           0000E8  1087 _PINB	=	0x00e8
                           0000F8  1088 G$PINC$0$0 == 0x00f8
                           0000F8  1089 _PINC	=	0x00f8
                           00008D  1090 G$PINR$0$0 == 0x008d
                           00008D  1091 _PINR	=	0x008d
                           000080  1092 G$PORTA$0$0 == 0x0080
                           000080  1093 _PORTA	=	0x0080
                           000088  1094 G$PORTB$0$0 == 0x0088
                           000088  1095 _PORTB	=	0x0088
                           000090  1096 G$PORTC$0$0 == 0x0090
                           000090  1097 _PORTC	=	0x0090
                           00008C  1098 G$PORTR$0$0 == 0x008c
                           00008C  1099 _PORTR	=	0x008c
                           0000CE  1100 G$IC0CAPT0$0$0 == 0x00ce
                           0000CE  1101 _IC0CAPT0	=	0x00ce
                           0000CF  1102 G$IC0CAPT1$0$0 == 0x00cf
                           0000CF  1103 _IC0CAPT1	=	0x00cf
                           00CFCE  1104 G$IC0CAPT$0$0 == 0xcfce
                           00CFCE  1105 _IC0CAPT	=	0xcfce
                           0000CC  1106 G$IC0MODE$0$0 == 0x00cc
                           0000CC  1107 _IC0MODE	=	0x00cc
                           0000CD  1108 G$IC0STATUS$0$0 == 0x00cd
                           0000CD  1109 _IC0STATUS	=	0x00cd
                           0000D6  1110 G$IC1CAPT0$0$0 == 0x00d6
                           0000D6  1111 _IC1CAPT0	=	0x00d6
                           0000D7  1112 G$IC1CAPT1$0$0 == 0x00d7
                           0000D7  1113 _IC1CAPT1	=	0x00d7
                           00D7D6  1114 G$IC1CAPT$0$0 == 0xd7d6
                           00D7D6  1115 _IC1CAPT	=	0xd7d6
                           0000D4  1116 G$IC1MODE$0$0 == 0x00d4
                           0000D4  1117 _IC1MODE	=	0x00d4
                           0000D5  1118 G$IC1STATUS$0$0 == 0x00d5
                           0000D5  1119 _IC1STATUS	=	0x00d5
                           000092  1120 G$NVADDR0$0$0 == 0x0092
                           000092  1121 _NVADDR0	=	0x0092
                           000093  1122 G$NVADDR1$0$0 == 0x0093
                           000093  1123 _NVADDR1	=	0x0093
                           009392  1124 G$NVADDR$0$0 == 0x9392
                           009392  1125 _NVADDR	=	0x9392
                           000094  1126 G$NVDATA0$0$0 == 0x0094
                           000094  1127 _NVDATA0	=	0x0094
                           000095  1128 G$NVDATA1$0$0 == 0x0095
                           000095  1129 _NVDATA1	=	0x0095
                           009594  1130 G$NVDATA$0$0 == 0x9594
                           009594  1131 _NVDATA	=	0x9594
                           000096  1132 G$NVKEY$0$0 == 0x0096
                           000096  1133 _NVKEY	=	0x0096
                           000091  1134 G$NVSTATUS$0$0 == 0x0091
                           000091  1135 _NVSTATUS	=	0x0091
                           0000BC  1136 G$OC0COMP0$0$0 == 0x00bc
                           0000BC  1137 _OC0COMP0	=	0x00bc
                           0000BD  1138 G$OC0COMP1$0$0 == 0x00bd
                           0000BD  1139 _OC0COMP1	=	0x00bd
                           00BDBC  1140 G$OC0COMP$0$0 == 0xbdbc
                           00BDBC  1141 _OC0COMP	=	0xbdbc
                           0000B9  1142 G$OC0MODE$0$0 == 0x00b9
                           0000B9  1143 _OC0MODE	=	0x00b9
                           0000BA  1144 G$OC0PIN$0$0 == 0x00ba
                           0000BA  1145 _OC0PIN	=	0x00ba
                           0000BB  1146 G$OC0STATUS$0$0 == 0x00bb
                           0000BB  1147 _OC0STATUS	=	0x00bb
                           0000C4  1148 G$OC1COMP0$0$0 == 0x00c4
                           0000C4  1149 _OC1COMP0	=	0x00c4
                           0000C5  1150 G$OC1COMP1$0$0 == 0x00c5
                           0000C5  1151 _OC1COMP1	=	0x00c5
                           00C5C4  1152 G$OC1COMP$0$0 == 0xc5c4
                           00C5C4  1153 _OC1COMP	=	0xc5c4
                           0000C1  1154 G$OC1MODE$0$0 == 0x00c1
                           0000C1  1155 _OC1MODE	=	0x00c1
                           0000C2  1156 G$OC1PIN$0$0 == 0x00c2
                           0000C2  1157 _OC1PIN	=	0x00c2
                           0000C3  1158 G$OC1STATUS$0$0 == 0x00c3
                           0000C3  1159 _OC1STATUS	=	0x00c3
                           0000B1  1160 G$RADIOACC$0$0 == 0x00b1
                           0000B1  1161 _RADIOACC	=	0x00b1
                           0000B3  1162 G$RADIOADDR0$0$0 == 0x00b3
                           0000B3  1163 _RADIOADDR0	=	0x00b3
                           0000B2  1164 G$RADIOADDR1$0$0 == 0x00b2
                           0000B2  1165 _RADIOADDR1	=	0x00b2
                           00B2B3  1166 G$RADIOADDR$0$0 == 0xb2b3
                           00B2B3  1167 _RADIOADDR	=	0xb2b3
                           0000B7  1168 G$RADIODATA0$0$0 == 0x00b7
                           0000B7  1169 _RADIODATA0	=	0x00b7
                           0000B6  1170 G$RADIODATA1$0$0 == 0x00b6
                           0000B6  1171 _RADIODATA1	=	0x00b6
                           0000B5  1172 G$RADIODATA2$0$0 == 0x00b5
                           0000B5  1173 _RADIODATA2	=	0x00b5
                           0000B4  1174 G$RADIODATA3$0$0 == 0x00b4
                           0000B4  1175 _RADIODATA3	=	0x00b4
                           B4B5B6B7  1176 G$RADIODATA$0$0 == 0xb4b5b6b7
                           B4B5B6B7  1177 _RADIODATA	=	0xb4b5b6b7
                           0000BE  1178 G$RADIOSTAT0$0$0 == 0x00be
                           0000BE  1179 _RADIOSTAT0	=	0x00be
                           0000BF  1180 G$RADIOSTAT1$0$0 == 0x00bf
                           0000BF  1181 _RADIOSTAT1	=	0x00bf
                           00BFBE  1182 G$RADIOSTAT$0$0 == 0xbfbe
                           00BFBE  1183 _RADIOSTAT	=	0xbfbe
                           0000DF  1184 G$SPCLKSRC$0$0 == 0x00df
                           0000DF  1185 _SPCLKSRC	=	0x00df
                           0000DC  1186 G$SPMODE$0$0 == 0x00dc
                           0000DC  1187 _SPMODE	=	0x00dc
                           0000DE  1188 G$SPSHREG$0$0 == 0x00de
                           0000DE  1189 _SPSHREG	=	0x00de
                           0000DD  1190 G$SPSTATUS$0$0 == 0x00dd
                           0000DD  1191 _SPSTATUS	=	0x00dd
                           00009A  1192 G$T0CLKSRC$0$0 == 0x009a
                           00009A  1193 _T0CLKSRC	=	0x009a
                           00009C  1194 G$T0CNT0$0$0 == 0x009c
                           00009C  1195 _T0CNT0	=	0x009c
                           00009D  1196 G$T0CNT1$0$0 == 0x009d
                           00009D  1197 _T0CNT1	=	0x009d
                           009D9C  1198 G$T0CNT$0$0 == 0x9d9c
                           009D9C  1199 _T0CNT	=	0x9d9c
                           000099  1200 G$T0MODE$0$0 == 0x0099
                           000099  1201 _T0MODE	=	0x0099
                           00009E  1202 G$T0PERIOD0$0$0 == 0x009e
                           00009E  1203 _T0PERIOD0	=	0x009e
                           00009F  1204 G$T0PERIOD1$0$0 == 0x009f
                           00009F  1205 _T0PERIOD1	=	0x009f
                           009F9E  1206 G$T0PERIOD$0$0 == 0x9f9e
                           009F9E  1207 _T0PERIOD	=	0x9f9e
                           00009B  1208 G$T0STATUS$0$0 == 0x009b
                           00009B  1209 _T0STATUS	=	0x009b
                           0000A2  1210 G$T1CLKSRC$0$0 == 0x00a2
                           0000A2  1211 _T1CLKSRC	=	0x00a2
                           0000A4  1212 G$T1CNT0$0$0 == 0x00a4
                           0000A4  1213 _T1CNT0	=	0x00a4
                           0000A5  1214 G$T1CNT1$0$0 == 0x00a5
                           0000A5  1215 _T1CNT1	=	0x00a5
                           00A5A4  1216 G$T1CNT$0$0 == 0xa5a4
                           00A5A4  1217 _T1CNT	=	0xa5a4
                           0000A1  1218 G$T1MODE$0$0 == 0x00a1
                           0000A1  1219 _T1MODE	=	0x00a1
                           0000A6  1220 G$T1PERIOD0$0$0 == 0x00a6
                           0000A6  1221 _T1PERIOD0	=	0x00a6
                           0000A7  1222 G$T1PERIOD1$0$0 == 0x00a7
                           0000A7  1223 _T1PERIOD1	=	0x00a7
                           00A7A6  1224 G$T1PERIOD$0$0 == 0xa7a6
                           00A7A6  1225 _T1PERIOD	=	0xa7a6
                           0000A3  1226 G$T1STATUS$0$0 == 0x00a3
                           0000A3  1227 _T1STATUS	=	0x00a3
                           0000AA  1228 G$T2CLKSRC$0$0 == 0x00aa
                           0000AA  1229 _T2CLKSRC	=	0x00aa
                           0000AC  1230 G$T2CNT0$0$0 == 0x00ac
                           0000AC  1231 _T2CNT0	=	0x00ac
                           0000AD  1232 G$T2CNT1$0$0 == 0x00ad
                           0000AD  1233 _T2CNT1	=	0x00ad
                           00ADAC  1234 G$T2CNT$0$0 == 0xadac
                           00ADAC  1235 _T2CNT	=	0xadac
                           0000A9  1236 G$T2MODE$0$0 == 0x00a9
                           0000A9  1237 _T2MODE	=	0x00a9
                           0000AE  1238 G$T2PERIOD0$0$0 == 0x00ae
                           0000AE  1239 _T2PERIOD0	=	0x00ae
                           0000AF  1240 G$T2PERIOD1$0$0 == 0x00af
                           0000AF  1241 _T2PERIOD1	=	0x00af
                           00AFAE  1242 G$T2PERIOD$0$0 == 0xafae
                           00AFAE  1243 _T2PERIOD	=	0xafae
                           0000AB  1244 G$T2STATUS$0$0 == 0x00ab
                           0000AB  1245 _T2STATUS	=	0x00ab
                           0000E4  1246 G$U0CTRL$0$0 == 0x00e4
                           0000E4  1247 _U0CTRL	=	0x00e4
                           0000E7  1248 G$U0MODE$0$0 == 0x00e7
                           0000E7  1249 _U0MODE	=	0x00e7
                           0000E6  1250 G$U0SHREG$0$0 == 0x00e6
                           0000E6  1251 _U0SHREG	=	0x00e6
                           0000E5  1252 G$U0STATUS$0$0 == 0x00e5
                           0000E5  1253 _U0STATUS	=	0x00e5
                           0000EC  1254 G$U1CTRL$0$0 == 0x00ec
                           0000EC  1255 _U1CTRL	=	0x00ec
                           0000EF  1256 G$U1MODE$0$0 == 0x00ef
                           0000EF  1257 _U1MODE	=	0x00ef
                           0000EE  1258 G$U1SHREG$0$0 == 0x00ee
                           0000EE  1259 _U1SHREG	=	0x00ee
                           0000ED  1260 G$U1STATUS$0$0 == 0x00ed
                           0000ED  1261 _U1STATUS	=	0x00ed
                           0000DA  1262 G$WDTCFG$0$0 == 0x00da
                           0000DA  1263 _WDTCFG	=	0x00da
                           0000DB  1264 G$WDTRESET$0$0 == 0x00db
                           0000DB  1265 _WDTRESET	=	0x00db
                           0000F1  1266 G$WTCFGA$0$0 == 0x00f1
                           0000F1  1267 _WTCFGA	=	0x00f1
                           0000F9  1268 G$WTCFGB$0$0 == 0x00f9
                           0000F9  1269 _WTCFGB	=	0x00f9
                           0000F2  1270 G$WTCNTA0$0$0 == 0x00f2
                           0000F2  1271 _WTCNTA0	=	0x00f2
                           0000F3  1272 G$WTCNTA1$0$0 == 0x00f3
                           0000F3  1273 _WTCNTA1	=	0x00f3
                           00F3F2  1274 G$WTCNTA$0$0 == 0xf3f2
                           00F3F2  1275 _WTCNTA	=	0xf3f2
                           0000FA  1276 G$WTCNTB0$0$0 == 0x00fa
                           0000FA  1277 _WTCNTB0	=	0x00fa
                           0000FB  1278 G$WTCNTB1$0$0 == 0x00fb
                           0000FB  1279 _WTCNTB1	=	0x00fb
                           00FBFA  1280 G$WTCNTB$0$0 == 0xfbfa
                           00FBFA  1281 _WTCNTB	=	0xfbfa
                           0000EB  1282 G$WTCNTR1$0$0 == 0x00eb
                           0000EB  1283 _WTCNTR1	=	0x00eb
                           0000F4  1284 G$WTEVTA0$0$0 == 0x00f4
                           0000F4  1285 _WTEVTA0	=	0x00f4
                           0000F5  1286 G$WTEVTA1$0$0 == 0x00f5
                           0000F5  1287 _WTEVTA1	=	0x00f5
                           00F5F4  1288 G$WTEVTA$0$0 == 0xf5f4
                           00F5F4  1289 _WTEVTA	=	0xf5f4
                           0000F6  1290 G$WTEVTB0$0$0 == 0x00f6
                           0000F6  1291 _WTEVTB0	=	0x00f6
                           0000F7  1292 G$WTEVTB1$0$0 == 0x00f7
                           0000F7  1293 _WTEVTB1	=	0x00f7
                           00F7F6  1294 G$WTEVTB$0$0 == 0xf7f6
                           00F7F6  1295 _WTEVTB	=	0xf7f6
                           0000FC  1296 G$WTEVTC0$0$0 == 0x00fc
                           0000FC  1297 _WTEVTC0	=	0x00fc
                           0000FD  1298 G$WTEVTC1$0$0 == 0x00fd
                           0000FD  1299 _WTEVTC1	=	0x00fd
                           00FDFC  1300 G$WTEVTC$0$0 == 0xfdfc
                           00FDFC  1301 _WTEVTC	=	0xfdfc
                           0000FE  1302 G$WTEVTD0$0$0 == 0x00fe
                           0000FE  1303 _WTEVTD0	=	0x00fe
                           0000FF  1304 G$WTEVTD1$0$0 == 0x00ff
                           0000FF  1305 _WTEVTD1	=	0x00ff
                           00FFFE  1306 G$WTEVTD$0$0 == 0xfffe
                           00FFFE  1307 _WTEVTD	=	0xfffe
                           0000E9  1308 G$WTIRQEN$0$0 == 0x00e9
                           0000E9  1309 _WTIRQEN	=	0x00e9
                           0000EA  1310 G$WTSTAT$0$0 == 0x00ea
                           0000EA  1311 _WTSTAT	=	0x00ea
                                   1312 ;--------------------------------------------------------
                                   1313 ; special function bits
                                   1314 ;--------------------------------------------------------
                                   1315 	.area RSEG    (ABS,DATA)
      000000                       1316 	.org 0x0000
                           0000E0  1317 G$ACC_0$0$0 == 0x00e0
                           0000E0  1318 _ACC_0	=	0x00e0
                           0000E1  1319 G$ACC_1$0$0 == 0x00e1
                           0000E1  1320 _ACC_1	=	0x00e1
                           0000E2  1321 G$ACC_2$0$0 == 0x00e2
                           0000E2  1322 _ACC_2	=	0x00e2
                           0000E3  1323 G$ACC_3$0$0 == 0x00e3
                           0000E3  1324 _ACC_3	=	0x00e3
                           0000E4  1325 G$ACC_4$0$0 == 0x00e4
                           0000E4  1326 _ACC_4	=	0x00e4
                           0000E5  1327 G$ACC_5$0$0 == 0x00e5
                           0000E5  1328 _ACC_5	=	0x00e5
                           0000E6  1329 G$ACC_6$0$0 == 0x00e6
                           0000E6  1330 _ACC_6	=	0x00e6
                           0000E7  1331 G$ACC_7$0$0 == 0x00e7
                           0000E7  1332 _ACC_7	=	0x00e7
                           0000F0  1333 G$B_0$0$0 == 0x00f0
                           0000F0  1334 _B_0	=	0x00f0
                           0000F1  1335 G$B_1$0$0 == 0x00f1
                           0000F1  1336 _B_1	=	0x00f1
                           0000F2  1337 G$B_2$0$0 == 0x00f2
                           0000F2  1338 _B_2	=	0x00f2
                           0000F3  1339 G$B_3$0$0 == 0x00f3
                           0000F3  1340 _B_3	=	0x00f3
                           0000F4  1341 G$B_4$0$0 == 0x00f4
                           0000F4  1342 _B_4	=	0x00f4
                           0000F5  1343 G$B_5$0$0 == 0x00f5
                           0000F5  1344 _B_5	=	0x00f5
                           0000F6  1345 G$B_6$0$0 == 0x00f6
                           0000F6  1346 _B_6	=	0x00f6
                           0000F7  1347 G$B_7$0$0 == 0x00f7
                           0000F7  1348 _B_7	=	0x00f7
                           0000A0  1349 G$E2IE_0$0$0 == 0x00a0
                           0000A0  1350 _E2IE_0	=	0x00a0
                           0000A1  1351 G$E2IE_1$0$0 == 0x00a1
                           0000A1  1352 _E2IE_1	=	0x00a1
                           0000A2  1353 G$E2IE_2$0$0 == 0x00a2
                           0000A2  1354 _E2IE_2	=	0x00a2
                           0000A3  1355 G$E2IE_3$0$0 == 0x00a3
                           0000A3  1356 _E2IE_3	=	0x00a3
                           0000A4  1357 G$E2IE_4$0$0 == 0x00a4
                           0000A4  1358 _E2IE_4	=	0x00a4
                           0000A5  1359 G$E2IE_5$0$0 == 0x00a5
                           0000A5  1360 _E2IE_5	=	0x00a5
                           0000A6  1361 G$E2IE_6$0$0 == 0x00a6
                           0000A6  1362 _E2IE_6	=	0x00a6
                           0000A7  1363 G$E2IE_7$0$0 == 0x00a7
                           0000A7  1364 _E2IE_7	=	0x00a7
                           0000C0  1365 G$E2IP_0$0$0 == 0x00c0
                           0000C0  1366 _E2IP_0	=	0x00c0
                           0000C1  1367 G$E2IP_1$0$0 == 0x00c1
                           0000C1  1368 _E2IP_1	=	0x00c1
                           0000C2  1369 G$E2IP_2$0$0 == 0x00c2
                           0000C2  1370 _E2IP_2	=	0x00c2
                           0000C3  1371 G$E2IP_3$0$0 == 0x00c3
                           0000C3  1372 _E2IP_3	=	0x00c3
                           0000C4  1373 G$E2IP_4$0$0 == 0x00c4
                           0000C4  1374 _E2IP_4	=	0x00c4
                           0000C5  1375 G$E2IP_5$0$0 == 0x00c5
                           0000C5  1376 _E2IP_5	=	0x00c5
                           0000C6  1377 G$E2IP_6$0$0 == 0x00c6
                           0000C6  1378 _E2IP_6	=	0x00c6
                           0000C7  1379 G$E2IP_7$0$0 == 0x00c7
                           0000C7  1380 _E2IP_7	=	0x00c7
                           000098  1381 G$EIE_0$0$0 == 0x0098
                           000098  1382 _EIE_0	=	0x0098
                           000099  1383 G$EIE_1$0$0 == 0x0099
                           000099  1384 _EIE_1	=	0x0099
                           00009A  1385 G$EIE_2$0$0 == 0x009a
                           00009A  1386 _EIE_2	=	0x009a
                           00009B  1387 G$EIE_3$0$0 == 0x009b
                           00009B  1388 _EIE_3	=	0x009b
                           00009C  1389 G$EIE_4$0$0 == 0x009c
                           00009C  1390 _EIE_4	=	0x009c
                           00009D  1391 G$EIE_5$0$0 == 0x009d
                           00009D  1392 _EIE_5	=	0x009d
                           00009E  1393 G$EIE_6$0$0 == 0x009e
                           00009E  1394 _EIE_6	=	0x009e
                           00009F  1395 G$EIE_7$0$0 == 0x009f
                           00009F  1396 _EIE_7	=	0x009f
                           0000B0  1397 G$EIP_0$0$0 == 0x00b0
                           0000B0  1398 _EIP_0	=	0x00b0
                           0000B1  1399 G$EIP_1$0$0 == 0x00b1
                           0000B1  1400 _EIP_1	=	0x00b1
                           0000B2  1401 G$EIP_2$0$0 == 0x00b2
                           0000B2  1402 _EIP_2	=	0x00b2
                           0000B3  1403 G$EIP_3$0$0 == 0x00b3
                           0000B3  1404 _EIP_3	=	0x00b3
                           0000B4  1405 G$EIP_4$0$0 == 0x00b4
                           0000B4  1406 _EIP_4	=	0x00b4
                           0000B5  1407 G$EIP_5$0$0 == 0x00b5
                           0000B5  1408 _EIP_5	=	0x00b5
                           0000B6  1409 G$EIP_6$0$0 == 0x00b6
                           0000B6  1410 _EIP_6	=	0x00b6
                           0000B7  1411 G$EIP_7$0$0 == 0x00b7
                           0000B7  1412 _EIP_7	=	0x00b7
                           0000A8  1413 G$IE_0$0$0 == 0x00a8
                           0000A8  1414 _IE_0	=	0x00a8
                           0000A9  1415 G$IE_1$0$0 == 0x00a9
                           0000A9  1416 _IE_1	=	0x00a9
                           0000AA  1417 G$IE_2$0$0 == 0x00aa
                           0000AA  1418 _IE_2	=	0x00aa
                           0000AB  1419 G$IE_3$0$0 == 0x00ab
                           0000AB  1420 _IE_3	=	0x00ab
                           0000AC  1421 G$IE_4$0$0 == 0x00ac
                           0000AC  1422 _IE_4	=	0x00ac
                           0000AD  1423 G$IE_5$0$0 == 0x00ad
                           0000AD  1424 _IE_5	=	0x00ad
                           0000AE  1425 G$IE_6$0$0 == 0x00ae
                           0000AE  1426 _IE_6	=	0x00ae
                           0000AF  1427 G$IE_7$0$0 == 0x00af
                           0000AF  1428 _IE_7	=	0x00af
                           0000AF  1429 G$EA$0$0 == 0x00af
                           0000AF  1430 _EA	=	0x00af
                           0000B8  1431 G$IP_0$0$0 == 0x00b8
                           0000B8  1432 _IP_0	=	0x00b8
                           0000B9  1433 G$IP_1$0$0 == 0x00b9
                           0000B9  1434 _IP_1	=	0x00b9
                           0000BA  1435 G$IP_2$0$0 == 0x00ba
                           0000BA  1436 _IP_2	=	0x00ba
                           0000BB  1437 G$IP_3$0$0 == 0x00bb
                           0000BB  1438 _IP_3	=	0x00bb
                           0000BC  1439 G$IP_4$0$0 == 0x00bc
                           0000BC  1440 _IP_4	=	0x00bc
                           0000BD  1441 G$IP_5$0$0 == 0x00bd
                           0000BD  1442 _IP_5	=	0x00bd
                           0000BE  1443 G$IP_6$0$0 == 0x00be
                           0000BE  1444 _IP_6	=	0x00be
                           0000BF  1445 G$IP_7$0$0 == 0x00bf
                           0000BF  1446 _IP_7	=	0x00bf
                           0000D0  1447 G$P$0$0 == 0x00d0
                           0000D0  1448 _P	=	0x00d0
                           0000D1  1449 G$F1$0$0 == 0x00d1
                           0000D1  1450 _F1	=	0x00d1
                           0000D2  1451 G$OV$0$0 == 0x00d2
                           0000D2  1452 _OV	=	0x00d2
                           0000D3  1453 G$RS0$0$0 == 0x00d3
                           0000D3  1454 _RS0	=	0x00d3
                           0000D4  1455 G$RS1$0$0 == 0x00d4
                           0000D4  1456 _RS1	=	0x00d4
                           0000D5  1457 G$F0$0$0 == 0x00d5
                           0000D5  1458 _F0	=	0x00d5
                           0000D6  1459 G$AC$0$0 == 0x00d6
                           0000D6  1460 _AC	=	0x00d6
                           0000D7  1461 G$CY$0$0 == 0x00d7
                           0000D7  1462 _CY	=	0x00d7
                           0000C8  1463 G$PINA_0$0$0 == 0x00c8
                           0000C8  1464 _PINA_0	=	0x00c8
                           0000C9  1465 G$PINA_1$0$0 == 0x00c9
                           0000C9  1466 _PINA_1	=	0x00c9
                           0000CA  1467 G$PINA_2$0$0 == 0x00ca
                           0000CA  1468 _PINA_2	=	0x00ca
                           0000CB  1469 G$PINA_3$0$0 == 0x00cb
                           0000CB  1470 _PINA_3	=	0x00cb
                           0000CC  1471 G$PINA_4$0$0 == 0x00cc
                           0000CC  1472 _PINA_4	=	0x00cc
                           0000CD  1473 G$PINA_5$0$0 == 0x00cd
                           0000CD  1474 _PINA_5	=	0x00cd
                           0000CE  1475 G$PINA_6$0$0 == 0x00ce
                           0000CE  1476 _PINA_6	=	0x00ce
                           0000CF  1477 G$PINA_7$0$0 == 0x00cf
                           0000CF  1478 _PINA_7	=	0x00cf
                           0000E8  1479 G$PINB_0$0$0 == 0x00e8
                           0000E8  1480 _PINB_0	=	0x00e8
                           0000E9  1481 G$PINB_1$0$0 == 0x00e9
                           0000E9  1482 _PINB_1	=	0x00e9
                           0000EA  1483 G$PINB_2$0$0 == 0x00ea
                           0000EA  1484 _PINB_2	=	0x00ea
                           0000EB  1485 G$PINB_3$0$0 == 0x00eb
                           0000EB  1486 _PINB_3	=	0x00eb
                           0000EC  1487 G$PINB_4$0$0 == 0x00ec
                           0000EC  1488 _PINB_4	=	0x00ec
                           0000ED  1489 G$PINB_5$0$0 == 0x00ed
                           0000ED  1490 _PINB_5	=	0x00ed
                           0000EE  1491 G$PINB_6$0$0 == 0x00ee
                           0000EE  1492 _PINB_6	=	0x00ee
                           0000EF  1493 G$PINB_7$0$0 == 0x00ef
                           0000EF  1494 _PINB_7	=	0x00ef
                           0000F8  1495 G$PINC_0$0$0 == 0x00f8
                           0000F8  1496 _PINC_0	=	0x00f8
                           0000F9  1497 G$PINC_1$0$0 == 0x00f9
                           0000F9  1498 _PINC_1	=	0x00f9
                           0000FA  1499 G$PINC_2$0$0 == 0x00fa
                           0000FA  1500 _PINC_2	=	0x00fa
                           0000FB  1501 G$PINC_3$0$0 == 0x00fb
                           0000FB  1502 _PINC_3	=	0x00fb
                           0000FC  1503 G$PINC_4$0$0 == 0x00fc
                           0000FC  1504 _PINC_4	=	0x00fc
                           0000FD  1505 G$PINC_5$0$0 == 0x00fd
                           0000FD  1506 _PINC_5	=	0x00fd
                           0000FE  1507 G$PINC_6$0$0 == 0x00fe
                           0000FE  1508 _PINC_6	=	0x00fe
                           0000FF  1509 G$PINC_7$0$0 == 0x00ff
                           0000FF  1510 _PINC_7	=	0x00ff
                           000080  1511 G$PORTA_0$0$0 == 0x0080
                           000080  1512 _PORTA_0	=	0x0080
                           000081  1513 G$PORTA_1$0$0 == 0x0081
                           000081  1514 _PORTA_1	=	0x0081
                           000082  1515 G$PORTA_2$0$0 == 0x0082
                           000082  1516 _PORTA_2	=	0x0082
                           000083  1517 G$PORTA_3$0$0 == 0x0083
                           000083  1518 _PORTA_3	=	0x0083
                           000084  1519 G$PORTA_4$0$0 == 0x0084
                           000084  1520 _PORTA_4	=	0x0084
                           000085  1521 G$PORTA_5$0$0 == 0x0085
                           000085  1522 _PORTA_5	=	0x0085
                           000086  1523 G$PORTA_6$0$0 == 0x0086
                           000086  1524 _PORTA_6	=	0x0086
                           000087  1525 G$PORTA_7$0$0 == 0x0087
                           000087  1526 _PORTA_7	=	0x0087
                           000088  1527 G$PORTB_0$0$0 == 0x0088
                           000088  1528 _PORTB_0	=	0x0088
                           000089  1529 G$PORTB_1$0$0 == 0x0089
                           000089  1530 _PORTB_1	=	0x0089
                           00008A  1531 G$PORTB_2$0$0 == 0x008a
                           00008A  1532 _PORTB_2	=	0x008a
                           00008B  1533 G$PORTB_3$0$0 == 0x008b
                           00008B  1534 _PORTB_3	=	0x008b
                           00008C  1535 G$PORTB_4$0$0 == 0x008c
                           00008C  1536 _PORTB_4	=	0x008c
                           00008D  1537 G$PORTB_5$0$0 == 0x008d
                           00008D  1538 _PORTB_5	=	0x008d
                           00008E  1539 G$PORTB_6$0$0 == 0x008e
                           00008E  1540 _PORTB_6	=	0x008e
                           00008F  1541 G$PORTB_7$0$0 == 0x008f
                           00008F  1542 _PORTB_7	=	0x008f
                           000090  1543 G$PORTC_0$0$0 == 0x0090
                           000090  1544 _PORTC_0	=	0x0090
                           000091  1545 G$PORTC_1$0$0 == 0x0091
                           000091  1546 _PORTC_1	=	0x0091
                           000092  1547 G$PORTC_2$0$0 == 0x0092
                           000092  1548 _PORTC_2	=	0x0092
                           000093  1549 G$PORTC_3$0$0 == 0x0093
                           000093  1550 _PORTC_3	=	0x0093
                           000094  1551 G$PORTC_4$0$0 == 0x0094
                           000094  1552 _PORTC_4	=	0x0094
                           000095  1553 G$PORTC_5$0$0 == 0x0095
                           000095  1554 _PORTC_5	=	0x0095
                           000096  1555 G$PORTC_6$0$0 == 0x0096
                           000096  1556 _PORTC_6	=	0x0096
                           000097  1557 G$PORTC_7$0$0 == 0x0097
                           000097  1558 _PORTC_7	=	0x0097
                                   1559 ;--------------------------------------------------------
                                   1560 ; overlayable register banks
                                   1561 ;--------------------------------------------------------
                                   1562 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                       1563 	.ds 8
                                   1564 ;--------------------------------------------------------
                                   1565 ; internal ram data
                                   1566 ;--------------------------------------------------------
                                   1567 	.area DSEG    (DATA)
                                   1568 ;--------------------------------------------------------
                                   1569 ; overlayable items in internal ram 
                                   1570 ;--------------------------------------------------------
                                   1571 ;--------------------------------------------------------
                                   1572 ; indirectly addressable internal ram data
                                   1573 ;--------------------------------------------------------
                                   1574 	.area ISEG    (DATA)
                                   1575 ;--------------------------------------------------------
                                   1576 ; absolute internal ram data
                                   1577 ;--------------------------------------------------------
                                   1578 	.area IABS    (ABS,DATA)
                                   1579 	.area IABS    (ABS,DATA)
                                   1580 ;--------------------------------------------------------
                                   1581 ; bit data
                                   1582 ;--------------------------------------------------------
                                   1583 	.area BSEG    (BIT)
                                   1584 ;--------------------------------------------------------
                                   1585 ; paged external ram data
                                   1586 ;--------------------------------------------------------
                                   1587 	.area PSEG    (PAG,XDATA)
                                   1588 ;--------------------------------------------------------
                                   1589 ; external ram data
                                   1590 ;--------------------------------------------------------
                                   1591 	.area XSEG    (XDATA)
                           007020  1592 G$ADCCH0VAL0$0$0 == 0x7020
                           007020  1593 _ADCCH0VAL0	=	0x7020
                           007021  1594 G$ADCCH0VAL1$0$0 == 0x7021
                           007021  1595 _ADCCH0VAL1	=	0x7021
                           007020  1596 G$ADCCH0VAL$0$0 == 0x7020
                           007020  1597 _ADCCH0VAL	=	0x7020
                           007022  1598 G$ADCCH1VAL0$0$0 == 0x7022
                           007022  1599 _ADCCH1VAL0	=	0x7022
                           007023  1600 G$ADCCH1VAL1$0$0 == 0x7023
                           007023  1601 _ADCCH1VAL1	=	0x7023
                           007022  1602 G$ADCCH1VAL$0$0 == 0x7022
                           007022  1603 _ADCCH1VAL	=	0x7022
                           007024  1604 G$ADCCH2VAL0$0$0 == 0x7024
                           007024  1605 _ADCCH2VAL0	=	0x7024
                           007025  1606 G$ADCCH2VAL1$0$0 == 0x7025
                           007025  1607 _ADCCH2VAL1	=	0x7025
                           007024  1608 G$ADCCH2VAL$0$0 == 0x7024
                           007024  1609 _ADCCH2VAL	=	0x7024
                           007026  1610 G$ADCCH3VAL0$0$0 == 0x7026
                           007026  1611 _ADCCH3VAL0	=	0x7026
                           007027  1612 G$ADCCH3VAL1$0$0 == 0x7027
                           007027  1613 _ADCCH3VAL1	=	0x7027
                           007026  1614 G$ADCCH3VAL$0$0 == 0x7026
                           007026  1615 _ADCCH3VAL	=	0x7026
                           007028  1616 G$ADCTUNE0$0$0 == 0x7028
                           007028  1617 _ADCTUNE0	=	0x7028
                           007029  1618 G$ADCTUNE1$0$0 == 0x7029
                           007029  1619 _ADCTUNE1	=	0x7029
                           00702A  1620 G$ADCTUNE2$0$0 == 0x702a
                           00702A  1621 _ADCTUNE2	=	0x702a
                           007010  1622 G$DMA0ADDR0$0$0 == 0x7010
                           007010  1623 _DMA0ADDR0	=	0x7010
                           007011  1624 G$DMA0ADDR1$0$0 == 0x7011
                           007011  1625 _DMA0ADDR1	=	0x7011
                           007010  1626 G$DMA0ADDR$0$0 == 0x7010
                           007010  1627 _DMA0ADDR	=	0x7010
                           007014  1628 G$DMA0CONFIG$0$0 == 0x7014
                           007014  1629 _DMA0CONFIG	=	0x7014
                           007012  1630 G$DMA1ADDR0$0$0 == 0x7012
                           007012  1631 _DMA1ADDR0	=	0x7012
                           007013  1632 G$DMA1ADDR1$0$0 == 0x7013
                           007013  1633 _DMA1ADDR1	=	0x7013
                           007012  1634 G$DMA1ADDR$0$0 == 0x7012
                           007012  1635 _DMA1ADDR	=	0x7012
                           007015  1636 G$DMA1CONFIG$0$0 == 0x7015
                           007015  1637 _DMA1CONFIG	=	0x7015
                           007070  1638 G$FRCOSCCONFIG$0$0 == 0x7070
                           007070  1639 _FRCOSCCONFIG	=	0x7070
                           007071  1640 G$FRCOSCCTRL$0$0 == 0x7071
                           007071  1641 _FRCOSCCTRL	=	0x7071
                           007076  1642 G$FRCOSCFREQ0$0$0 == 0x7076
                           007076  1643 _FRCOSCFREQ0	=	0x7076
                           007077  1644 G$FRCOSCFREQ1$0$0 == 0x7077
                           007077  1645 _FRCOSCFREQ1	=	0x7077
                           007076  1646 G$FRCOSCFREQ$0$0 == 0x7076
                           007076  1647 _FRCOSCFREQ	=	0x7076
                           007072  1648 G$FRCOSCKFILT0$0$0 == 0x7072
                           007072  1649 _FRCOSCKFILT0	=	0x7072
                           007073  1650 G$FRCOSCKFILT1$0$0 == 0x7073
                           007073  1651 _FRCOSCKFILT1	=	0x7073
                           007072  1652 G$FRCOSCKFILT$0$0 == 0x7072
                           007072  1653 _FRCOSCKFILT	=	0x7072
                           007078  1654 G$FRCOSCPER0$0$0 == 0x7078
                           007078  1655 _FRCOSCPER0	=	0x7078
                           007079  1656 G$FRCOSCPER1$0$0 == 0x7079
                           007079  1657 _FRCOSCPER1	=	0x7079
                           007078  1658 G$FRCOSCPER$0$0 == 0x7078
                           007078  1659 _FRCOSCPER	=	0x7078
                           007074  1660 G$FRCOSCREF0$0$0 == 0x7074
                           007074  1661 _FRCOSCREF0	=	0x7074
                           007075  1662 G$FRCOSCREF1$0$0 == 0x7075
                           007075  1663 _FRCOSCREF1	=	0x7075
                           007074  1664 G$FRCOSCREF$0$0 == 0x7074
                           007074  1665 _FRCOSCREF	=	0x7074
                           007007  1666 G$ANALOGA$0$0 == 0x7007
                           007007  1667 _ANALOGA	=	0x7007
                           00700C  1668 G$GPIOENABLE$0$0 == 0x700c
                           00700C  1669 _GPIOENABLE	=	0x700c
                           007003  1670 G$EXTIRQ$0$0 == 0x7003
                           007003  1671 _EXTIRQ	=	0x7003
                           007000  1672 G$INTCHGA$0$0 == 0x7000
                           007000  1673 _INTCHGA	=	0x7000
                           007001  1674 G$INTCHGB$0$0 == 0x7001
                           007001  1675 _INTCHGB	=	0x7001
                           007002  1676 G$INTCHGC$0$0 == 0x7002
                           007002  1677 _INTCHGC	=	0x7002
                           007008  1678 G$PALTA$0$0 == 0x7008
                           007008  1679 _PALTA	=	0x7008
                           007009  1680 G$PALTB$0$0 == 0x7009
                           007009  1681 _PALTB	=	0x7009
                           00700A  1682 G$PALTC$0$0 == 0x700a
                           00700A  1683 _PALTC	=	0x700a
                           007046  1684 G$PALTRADIO$0$0 == 0x7046
                           007046  1685 _PALTRADIO	=	0x7046
                           007004  1686 G$PINCHGA$0$0 == 0x7004
                           007004  1687 _PINCHGA	=	0x7004
                           007005  1688 G$PINCHGB$0$0 == 0x7005
                           007005  1689 _PINCHGB	=	0x7005
                           007006  1690 G$PINCHGC$0$0 == 0x7006
                           007006  1691 _PINCHGC	=	0x7006
                           00700B  1692 G$PINSEL$0$0 == 0x700b
                           00700B  1693 _PINSEL	=	0x700b
                           007060  1694 G$LPOSCCONFIG$0$0 == 0x7060
                           007060  1695 _LPOSCCONFIG	=	0x7060
                           007066  1696 G$LPOSCFREQ0$0$0 == 0x7066
                           007066  1697 _LPOSCFREQ0	=	0x7066
                           007067  1698 G$LPOSCFREQ1$0$0 == 0x7067
                           007067  1699 _LPOSCFREQ1	=	0x7067
                           007066  1700 G$LPOSCFREQ$0$0 == 0x7066
                           007066  1701 _LPOSCFREQ	=	0x7066
                           007062  1702 G$LPOSCKFILT0$0$0 == 0x7062
                           007062  1703 _LPOSCKFILT0	=	0x7062
                           007063  1704 G$LPOSCKFILT1$0$0 == 0x7063
                           007063  1705 _LPOSCKFILT1	=	0x7063
                           007062  1706 G$LPOSCKFILT$0$0 == 0x7062
                           007062  1707 _LPOSCKFILT	=	0x7062
                           007068  1708 G$LPOSCPER0$0$0 == 0x7068
                           007068  1709 _LPOSCPER0	=	0x7068
                           007069  1710 G$LPOSCPER1$0$0 == 0x7069
                           007069  1711 _LPOSCPER1	=	0x7069
                           007068  1712 G$LPOSCPER$0$0 == 0x7068
                           007068  1713 _LPOSCPER	=	0x7068
                           007064  1714 G$LPOSCREF0$0$0 == 0x7064
                           007064  1715 _LPOSCREF0	=	0x7064
                           007065  1716 G$LPOSCREF1$0$0 == 0x7065
                           007065  1717 _LPOSCREF1	=	0x7065
                           007064  1718 G$LPOSCREF$0$0 == 0x7064
                           007064  1719 _LPOSCREF	=	0x7064
                           007054  1720 G$LPXOSCGM$0$0 == 0x7054
                           007054  1721 _LPXOSCGM	=	0x7054
                           007F01  1722 G$MISCCTRL$0$0 == 0x7f01
                           007F01  1723 _MISCCTRL	=	0x7f01
                           007053  1724 G$OSCCALIB$0$0 == 0x7053
                           007053  1725 _OSCCALIB	=	0x7053
                           007050  1726 G$OSCFORCERUN$0$0 == 0x7050
                           007050  1727 _OSCFORCERUN	=	0x7050
                           007052  1728 G$OSCREADY$0$0 == 0x7052
                           007052  1729 _OSCREADY	=	0x7052
                           007051  1730 G$OSCRUN$0$0 == 0x7051
                           007051  1731 _OSCRUN	=	0x7051
                           007040  1732 G$RADIOFDATAADDR0$0$0 == 0x7040
                           007040  1733 _RADIOFDATAADDR0	=	0x7040
                           007041  1734 G$RADIOFDATAADDR1$0$0 == 0x7041
                           007041  1735 _RADIOFDATAADDR1	=	0x7041
                           007040  1736 G$RADIOFDATAADDR$0$0 == 0x7040
                           007040  1737 _RADIOFDATAADDR	=	0x7040
                           007042  1738 G$RADIOFSTATADDR0$0$0 == 0x7042
                           007042  1739 _RADIOFSTATADDR0	=	0x7042
                           007043  1740 G$RADIOFSTATADDR1$0$0 == 0x7043
                           007043  1741 _RADIOFSTATADDR1	=	0x7043
                           007042  1742 G$RADIOFSTATADDR$0$0 == 0x7042
                           007042  1743 _RADIOFSTATADDR	=	0x7042
                           007044  1744 G$RADIOMUX$0$0 == 0x7044
                           007044  1745 _RADIOMUX	=	0x7044
                           007084  1746 G$SCRATCH0$0$0 == 0x7084
                           007084  1747 _SCRATCH0	=	0x7084
                           007085  1748 G$SCRATCH1$0$0 == 0x7085
                           007085  1749 _SCRATCH1	=	0x7085
                           007086  1750 G$SCRATCH2$0$0 == 0x7086
                           007086  1751 _SCRATCH2	=	0x7086
                           007087  1752 G$SCRATCH3$0$0 == 0x7087
                           007087  1753 _SCRATCH3	=	0x7087
                           007F00  1754 G$SILICONREV$0$0 == 0x7f00
                           007F00  1755 _SILICONREV	=	0x7f00
                           007F19  1756 G$XTALAMPL$0$0 == 0x7f19
                           007F19  1757 _XTALAMPL	=	0x7f19
                           007F18  1758 G$XTALOSC$0$0 == 0x7f18
                           007F18  1759 _XTALOSC	=	0x7f18
                           007F1A  1760 G$XTALREADY$0$0 == 0x7f1a
                           007F1A  1761 _XTALREADY	=	0x7f1a
                           004114  1762 G$AX5043_AFSKCTRL$0$0 == 0x4114
                           004114  1763 _AX5043_AFSKCTRL	=	0x4114
                           004113  1764 G$AX5043_AFSKMARK0$0$0 == 0x4113
                           004113  1765 _AX5043_AFSKMARK0	=	0x4113
                           004112  1766 G$AX5043_AFSKMARK1$0$0 == 0x4112
                           004112  1767 _AX5043_AFSKMARK1	=	0x4112
                           004111  1768 G$AX5043_AFSKSPACE0$0$0 == 0x4111
                           004111  1769 _AX5043_AFSKSPACE0	=	0x4111
                           004110  1770 G$AX5043_AFSKSPACE1$0$0 == 0x4110
                           004110  1771 _AX5043_AFSKSPACE1	=	0x4110
                           004043  1772 G$AX5043_AGCCOUNTER$0$0 == 0x4043
                           004043  1773 _AX5043_AGCCOUNTER	=	0x4043
                           004115  1774 G$AX5043_AMPLFILTER$0$0 == 0x4115
                           004115  1775 _AX5043_AMPLFILTER	=	0x4115
                           004189  1776 G$AX5043_BBOFFSCAP$0$0 == 0x4189
                           004189  1777 _AX5043_BBOFFSCAP	=	0x4189
                           004188  1778 G$AX5043_BBTUNE$0$0 == 0x4188
                           004188  1779 _AX5043_BBTUNE	=	0x4188
                           004041  1780 G$AX5043_BGNDRSSI$0$0 == 0x4041
                           004041  1781 _AX5043_BGNDRSSI	=	0x4041
                           00422E  1782 G$AX5043_BGNDRSSIGAIN$0$0 == 0x422e
                           00422E  1783 _AX5043_BGNDRSSIGAIN	=	0x422e
                           00422F  1784 G$AX5043_BGNDRSSITHR$0$0 == 0x422f
                           00422F  1785 _AX5043_BGNDRSSITHR	=	0x422f
                           004017  1786 G$AX5043_CRCINIT0$0$0 == 0x4017
                           004017  1787 _AX5043_CRCINIT0	=	0x4017
                           004016  1788 G$AX5043_CRCINIT1$0$0 == 0x4016
                           004016  1789 _AX5043_CRCINIT1	=	0x4016
                           004015  1790 G$AX5043_CRCINIT2$0$0 == 0x4015
                           004015  1791 _AX5043_CRCINIT2	=	0x4015
                           004014  1792 G$AX5043_CRCINIT3$0$0 == 0x4014
                           004014  1793 _AX5043_CRCINIT3	=	0x4014
                           004332  1794 G$AX5043_DACCONFIG$0$0 == 0x4332
                           004332  1795 _AX5043_DACCONFIG	=	0x4332
                           004331  1796 G$AX5043_DACVALUE0$0$0 == 0x4331
                           004331  1797 _AX5043_DACVALUE0	=	0x4331
                           004330  1798 G$AX5043_DACVALUE1$0$0 == 0x4330
                           004330  1799 _AX5043_DACVALUE1	=	0x4330
                           004102  1800 G$AX5043_DECIMATION$0$0 == 0x4102
                           004102  1801 _AX5043_DECIMATION	=	0x4102
                           004042  1802 G$AX5043_DIVERSITY$0$0 == 0x4042
                           004042  1803 _AX5043_DIVERSITY	=	0x4042
                           004011  1804 G$AX5043_ENCODING$0$0 == 0x4011
                           004011  1805 _AX5043_ENCODING	=	0x4011
                           004018  1806 G$AX5043_FEC$0$0 == 0x4018
                           004018  1807 _AX5043_FEC	=	0x4018
                           00401A  1808 G$AX5043_FECSTATUS$0$0 == 0x401a
                           00401A  1809 _AX5043_FECSTATUS	=	0x401a
                           004019  1810 G$AX5043_FECSYNC$0$0 == 0x4019
                           004019  1811 _AX5043_FECSYNC	=	0x4019
                           00402B  1812 G$AX5043_FIFOCOUNT0$0$0 == 0x402b
                           00402B  1813 _AX5043_FIFOCOUNT0	=	0x402b
                           00402A  1814 G$AX5043_FIFOCOUNT1$0$0 == 0x402a
                           00402A  1815 _AX5043_FIFOCOUNT1	=	0x402a
                           004029  1816 G$AX5043_FIFODATA$0$0 == 0x4029
                           004029  1817 _AX5043_FIFODATA	=	0x4029
                           00402D  1818 G$AX5043_FIFOFREE0$0$0 == 0x402d
                           00402D  1819 _AX5043_FIFOFREE0	=	0x402d
                           00402C  1820 G$AX5043_FIFOFREE1$0$0 == 0x402c
                           00402C  1821 _AX5043_FIFOFREE1	=	0x402c
                           004028  1822 G$AX5043_FIFOSTAT$0$0 == 0x4028
                           004028  1823 _AX5043_FIFOSTAT	=	0x4028
                           00402F  1824 G$AX5043_FIFOTHRESH0$0$0 == 0x402f
                           00402F  1825 _AX5043_FIFOTHRESH0	=	0x402f
                           00402E  1826 G$AX5043_FIFOTHRESH1$0$0 == 0x402e
                           00402E  1827 _AX5043_FIFOTHRESH1	=	0x402e
                           004012  1828 G$AX5043_FRAMING$0$0 == 0x4012
                           004012  1829 _AX5043_FRAMING	=	0x4012
                           004037  1830 G$AX5043_FREQA0$0$0 == 0x4037
                           004037  1831 _AX5043_FREQA0	=	0x4037
                           004036  1832 G$AX5043_FREQA1$0$0 == 0x4036
                           004036  1833 _AX5043_FREQA1	=	0x4036
                           004035  1834 G$AX5043_FREQA2$0$0 == 0x4035
                           004035  1835 _AX5043_FREQA2	=	0x4035
                           004034  1836 G$AX5043_FREQA3$0$0 == 0x4034
                           004034  1837 _AX5043_FREQA3	=	0x4034
                           00403F  1838 G$AX5043_FREQB0$0$0 == 0x403f
                           00403F  1839 _AX5043_FREQB0	=	0x403f
                           00403E  1840 G$AX5043_FREQB1$0$0 == 0x403e
                           00403E  1841 _AX5043_FREQB1	=	0x403e
                           00403D  1842 G$AX5043_FREQB2$0$0 == 0x403d
                           00403D  1843 _AX5043_FREQB2	=	0x403d
                           00403C  1844 G$AX5043_FREQB3$0$0 == 0x403c
                           00403C  1845 _AX5043_FREQB3	=	0x403c
                           004163  1846 G$AX5043_FSKDEV0$0$0 == 0x4163
                           004163  1847 _AX5043_FSKDEV0	=	0x4163
                           004162  1848 G$AX5043_FSKDEV1$0$0 == 0x4162
                           004162  1849 _AX5043_FSKDEV1	=	0x4162
                           004161  1850 G$AX5043_FSKDEV2$0$0 == 0x4161
                           004161  1851 _AX5043_FSKDEV2	=	0x4161
                           00410D  1852 G$AX5043_FSKDMAX0$0$0 == 0x410d
                           00410D  1853 _AX5043_FSKDMAX0	=	0x410d
                           00410C  1854 G$AX5043_FSKDMAX1$0$0 == 0x410c
                           00410C  1855 _AX5043_FSKDMAX1	=	0x410c
                           00410F  1856 G$AX5043_FSKDMIN0$0$0 == 0x410f
                           00410F  1857 _AX5043_FSKDMIN0	=	0x410f
                           00410E  1858 G$AX5043_FSKDMIN1$0$0 == 0x410e
                           00410E  1859 _AX5043_FSKDMIN1	=	0x410e
                           004309  1860 G$AX5043_GPADC13VALUE0$0$0 == 0x4309
                           004309  1861 _AX5043_GPADC13VALUE0	=	0x4309
                           004308  1862 G$AX5043_GPADC13VALUE1$0$0 == 0x4308
                           004308  1863 _AX5043_GPADC13VALUE1	=	0x4308
                           004300  1864 G$AX5043_GPADCCTRL$0$0 == 0x4300
                           004300  1865 _AX5043_GPADCCTRL	=	0x4300
                           004301  1866 G$AX5043_GPADCPERIOD$0$0 == 0x4301
                           004301  1867 _AX5043_GPADCPERIOD	=	0x4301
                           004101  1868 G$AX5043_IFFREQ0$0$0 == 0x4101
                           004101  1869 _AX5043_IFFREQ0	=	0x4101
                           004100  1870 G$AX5043_IFFREQ1$0$0 == 0x4100
                           004100  1871 _AX5043_IFFREQ1	=	0x4100
                           00400B  1872 G$AX5043_IRQINVERSION0$0$0 == 0x400b
                           00400B  1873 _AX5043_IRQINVERSION0	=	0x400b
                           00400A  1874 G$AX5043_IRQINVERSION1$0$0 == 0x400a
                           00400A  1875 _AX5043_IRQINVERSION1	=	0x400a
                           004007  1876 G$AX5043_IRQMASK0$0$0 == 0x4007
                           004007  1877 _AX5043_IRQMASK0	=	0x4007
                           004006  1878 G$AX5043_IRQMASK1$0$0 == 0x4006
                           004006  1879 _AX5043_IRQMASK1	=	0x4006
                           00400D  1880 G$AX5043_IRQREQUEST0$0$0 == 0x400d
                           00400D  1881 _AX5043_IRQREQUEST0	=	0x400d
                           00400C  1882 G$AX5043_IRQREQUEST1$0$0 == 0x400c
                           00400C  1883 _AX5043_IRQREQUEST1	=	0x400c
                           004310  1884 G$AX5043_LPOSCCONFIG$0$0 == 0x4310
                           004310  1885 _AX5043_LPOSCCONFIG	=	0x4310
                           004317  1886 G$AX5043_LPOSCFREQ0$0$0 == 0x4317
                           004317  1887 _AX5043_LPOSCFREQ0	=	0x4317
                           004316  1888 G$AX5043_LPOSCFREQ1$0$0 == 0x4316
                           004316  1889 _AX5043_LPOSCFREQ1	=	0x4316
                           004313  1890 G$AX5043_LPOSCKFILT0$0$0 == 0x4313
                           004313  1891 _AX5043_LPOSCKFILT0	=	0x4313
                           004312  1892 G$AX5043_LPOSCKFILT1$0$0 == 0x4312
                           004312  1893 _AX5043_LPOSCKFILT1	=	0x4312
                           004319  1894 G$AX5043_LPOSCPER0$0$0 == 0x4319
                           004319  1895 _AX5043_LPOSCPER0	=	0x4319
                           004318  1896 G$AX5043_LPOSCPER1$0$0 == 0x4318
                           004318  1897 _AX5043_LPOSCPER1	=	0x4318
                           004315  1898 G$AX5043_LPOSCREF0$0$0 == 0x4315
                           004315  1899 _AX5043_LPOSCREF0	=	0x4315
                           004314  1900 G$AX5043_LPOSCREF1$0$0 == 0x4314
                           004314  1901 _AX5043_LPOSCREF1	=	0x4314
                           004311  1902 G$AX5043_LPOSCSTATUS$0$0 == 0x4311
                           004311  1903 _AX5043_LPOSCSTATUS	=	0x4311
                           004214  1904 G$AX5043_MATCH0LEN$0$0 == 0x4214
                           004214  1905 _AX5043_MATCH0LEN	=	0x4214
                           004216  1906 G$AX5043_MATCH0MAX$0$0 == 0x4216
                           004216  1907 _AX5043_MATCH0MAX	=	0x4216
                           004215  1908 G$AX5043_MATCH0MIN$0$0 == 0x4215
                           004215  1909 _AX5043_MATCH0MIN	=	0x4215
                           004213  1910 G$AX5043_MATCH0PAT0$0$0 == 0x4213
                           004213  1911 _AX5043_MATCH0PAT0	=	0x4213
                           004212  1912 G$AX5043_MATCH0PAT1$0$0 == 0x4212
                           004212  1913 _AX5043_MATCH0PAT1	=	0x4212
                           004211  1914 G$AX5043_MATCH0PAT2$0$0 == 0x4211
                           004211  1915 _AX5043_MATCH0PAT2	=	0x4211
                           004210  1916 G$AX5043_MATCH0PAT3$0$0 == 0x4210
                           004210  1917 _AX5043_MATCH0PAT3	=	0x4210
                           00421C  1918 G$AX5043_MATCH1LEN$0$0 == 0x421c
                           00421C  1919 _AX5043_MATCH1LEN	=	0x421c
                           00421E  1920 G$AX5043_MATCH1MAX$0$0 == 0x421e
                           00421E  1921 _AX5043_MATCH1MAX	=	0x421e
                           00421D  1922 G$AX5043_MATCH1MIN$0$0 == 0x421d
                           00421D  1923 _AX5043_MATCH1MIN	=	0x421d
                           004219  1924 G$AX5043_MATCH1PAT0$0$0 == 0x4219
                           004219  1925 _AX5043_MATCH1PAT0	=	0x4219
                           004218  1926 G$AX5043_MATCH1PAT1$0$0 == 0x4218
                           004218  1927 _AX5043_MATCH1PAT1	=	0x4218
                           004108  1928 G$AX5043_MAXDROFFSET0$0$0 == 0x4108
                           004108  1929 _AX5043_MAXDROFFSET0	=	0x4108
                           004107  1930 G$AX5043_MAXDROFFSET1$0$0 == 0x4107
                           004107  1931 _AX5043_MAXDROFFSET1	=	0x4107
                           004106  1932 G$AX5043_MAXDROFFSET2$0$0 == 0x4106
                           004106  1933 _AX5043_MAXDROFFSET2	=	0x4106
                           00410B  1934 G$AX5043_MAXRFOFFSET0$0$0 == 0x410b
                           00410B  1935 _AX5043_MAXRFOFFSET0	=	0x410b
                           00410A  1936 G$AX5043_MAXRFOFFSET1$0$0 == 0x410a
                           00410A  1937 _AX5043_MAXRFOFFSET1	=	0x410a
                           004109  1938 G$AX5043_MAXRFOFFSET2$0$0 == 0x4109
                           004109  1939 _AX5043_MAXRFOFFSET2	=	0x4109
                           004164  1940 G$AX5043_MODCFGA$0$0 == 0x4164
                           004164  1941 _AX5043_MODCFGA	=	0x4164
                           004160  1942 G$AX5043_MODCFGF$0$0 == 0x4160
                           004160  1943 _AX5043_MODCFGF	=	0x4160
                           004F5F  1944 G$AX5043_MODCFGP$0$0 == 0x4f5f
                           004F5F  1945 _AX5043_MODCFGP	=	0x4f5f
                           004010  1946 G$AX5043_MODULATION$0$0 == 0x4010
                           004010  1947 _AX5043_MODULATION	=	0x4010
                           004025  1948 G$AX5043_PINFUNCANTSEL$0$0 == 0x4025
                           004025  1949 _AX5043_PINFUNCANTSEL	=	0x4025
                           004023  1950 G$AX5043_PINFUNCDATA$0$0 == 0x4023
                           004023  1951 _AX5043_PINFUNCDATA	=	0x4023
                           004022  1952 G$AX5043_PINFUNCDCLK$0$0 == 0x4022
                           004022  1953 _AX5043_PINFUNCDCLK	=	0x4022
                           004024  1954 G$AX5043_PINFUNCIRQ$0$0 == 0x4024
                           004024  1955 _AX5043_PINFUNCIRQ	=	0x4024
                           004026  1956 G$AX5043_PINFUNCPWRAMP$0$0 == 0x4026
                           004026  1957 _AX5043_PINFUNCPWRAMP	=	0x4026
                           004021  1958 G$AX5043_PINFUNCSYSCLK$0$0 == 0x4021
                           004021  1959 _AX5043_PINFUNCSYSCLK	=	0x4021
                           004020  1960 G$AX5043_PINSTATE$0$0 == 0x4020
                           004020  1961 _AX5043_PINSTATE	=	0x4020
                           004233  1962 G$AX5043_PKTACCEPTFLAGS$0$0 == 0x4233
                           004233  1963 _AX5043_PKTACCEPTFLAGS	=	0x4233
                           004230  1964 G$AX5043_PKTCHUNKSIZE$0$0 == 0x4230
                           004230  1965 _AX5043_PKTCHUNKSIZE	=	0x4230
                           004231  1966 G$AX5043_PKTMISCFLAGS$0$0 == 0x4231
                           004231  1967 _AX5043_PKTMISCFLAGS	=	0x4231
                           004232  1968 G$AX5043_PKTSTOREFLAGS$0$0 == 0x4232
                           004232  1969 _AX5043_PKTSTOREFLAGS	=	0x4232
                           004031  1970 G$AX5043_PLLCPI$0$0 == 0x4031
                           004031  1971 _AX5043_PLLCPI	=	0x4031
                           004039  1972 G$AX5043_PLLCPIBOOST$0$0 == 0x4039
                           004039  1973 _AX5043_PLLCPIBOOST	=	0x4039
                           004182  1974 G$AX5043_PLLLOCKDET$0$0 == 0x4182
                           004182  1975 _AX5043_PLLLOCKDET	=	0x4182
                           004030  1976 G$AX5043_PLLLOOP$0$0 == 0x4030
                           004030  1977 _AX5043_PLLLOOP	=	0x4030
                           004038  1978 G$AX5043_PLLLOOPBOOST$0$0 == 0x4038
                           004038  1979 _AX5043_PLLLOOPBOOST	=	0x4038
                           004033  1980 G$AX5043_PLLRANGINGA$0$0 == 0x4033
                           004033  1981 _AX5043_PLLRANGINGA	=	0x4033
                           00403B  1982 G$AX5043_PLLRANGINGB$0$0 == 0x403b
                           00403B  1983 _AX5043_PLLRANGINGB	=	0x403b
                           004183  1984 G$AX5043_PLLRNGCLK$0$0 == 0x4183
                           004183  1985 _AX5043_PLLRNGCLK	=	0x4183
                           004032  1986 G$AX5043_PLLVCODIV$0$0 == 0x4032
                           004032  1987 _AX5043_PLLVCODIV	=	0x4032
                           004180  1988 G$AX5043_PLLVCOI$0$0 == 0x4180
                           004180  1989 _AX5043_PLLVCOI	=	0x4180
                           004181  1990 G$AX5043_PLLVCOIR$0$0 == 0x4181
                           004181  1991 _AX5043_PLLVCOIR	=	0x4181
                           004F08  1992 G$AX5043_POWCTRL1$0$0 == 0x4f08
                           004F08  1993 _AX5043_POWCTRL1	=	0x4f08
                           004005  1994 G$AX5043_POWIRQMASK$0$0 == 0x4005
                           004005  1995 _AX5043_POWIRQMASK	=	0x4005
                           004003  1996 G$AX5043_POWSTAT$0$0 == 0x4003
                           004003  1997 _AX5043_POWSTAT	=	0x4003
                           004004  1998 G$AX5043_POWSTICKYSTAT$0$0 == 0x4004
                           004004  1999 _AX5043_POWSTICKYSTAT	=	0x4004
                           004027  2000 G$AX5043_PWRAMP$0$0 == 0x4027
                           004027  2001 _AX5043_PWRAMP	=	0x4027
                           004002  2002 G$AX5043_PWRMODE$0$0 == 0x4002
                           004002  2003 _AX5043_PWRMODE	=	0x4002
                           004009  2004 G$AX5043_RADIOEVENTMASK0$0$0 == 0x4009
                           004009  2005 _AX5043_RADIOEVENTMASK0	=	0x4009
                           004008  2006 G$AX5043_RADIOEVENTMASK1$0$0 == 0x4008
                           004008  2007 _AX5043_RADIOEVENTMASK1	=	0x4008
                           00400F  2008 G$AX5043_RADIOEVENTREQ0$0$0 == 0x400f
                           00400F  2009 _AX5043_RADIOEVENTREQ0	=	0x400f
                           00400E  2010 G$AX5043_RADIOEVENTREQ1$0$0 == 0x400e
                           00400E  2011 _AX5043_RADIOEVENTREQ1	=	0x400e
                           00401C  2012 G$AX5043_RADIOSTATE$0$0 == 0x401c
                           00401C  2013 _AX5043_RADIOSTATE	=	0x401c
                           004F0D  2014 G$AX5043_REF$0$0 == 0x4f0d
                           004F0D  2015 _AX5043_REF	=	0x4f0d
                           004040  2016 G$AX5043_RSSI$0$0 == 0x4040
                           004040  2017 _AX5043_RSSI	=	0x4040
                           00422D  2018 G$AX5043_RSSIABSTHR$0$0 == 0x422d
                           00422D  2019 _AX5043_RSSIABSTHR	=	0x422d
                           00422C  2020 G$AX5043_RSSIREFERENCE$0$0 == 0x422c
                           00422C  2021 _AX5043_RSSIREFERENCE	=	0x422c
                           004105  2022 G$AX5043_RXDATARATE0$0$0 == 0x4105
                           004105  2023 _AX5043_RXDATARATE0	=	0x4105
                           004104  2024 G$AX5043_RXDATARATE1$0$0 == 0x4104
                           004104  2025 _AX5043_RXDATARATE1	=	0x4104
                           004103  2026 G$AX5043_RXDATARATE2$0$0 == 0x4103
                           004103  2027 _AX5043_RXDATARATE2	=	0x4103
                           004001  2028 G$AX5043_SCRATCH$0$0 == 0x4001
                           004001  2029 _AX5043_SCRATCH	=	0x4001
                           004000  2030 G$AX5043_SILICONREVISION$0$0 == 0x4000
                           004000  2031 _AX5043_SILICONREVISION	=	0x4000
                           00405B  2032 G$AX5043_TIMER0$0$0 == 0x405b
                           00405B  2033 _AX5043_TIMER0	=	0x405b
                           00405A  2034 G$AX5043_TIMER1$0$0 == 0x405a
                           00405A  2035 _AX5043_TIMER1	=	0x405a
                           004059  2036 G$AX5043_TIMER2$0$0 == 0x4059
                           004059  2037 _AX5043_TIMER2	=	0x4059
                           004227  2038 G$AX5043_TMGRXAGC$0$0 == 0x4227
                           004227  2039 _AX5043_TMGRXAGC	=	0x4227
                           004223  2040 G$AX5043_TMGRXBOOST$0$0 == 0x4223
                           004223  2041 _AX5043_TMGRXBOOST	=	0x4223
                           004226  2042 G$AX5043_TMGRXCOARSEAGC$0$0 == 0x4226
                           004226  2043 _AX5043_TMGRXCOARSEAGC	=	0x4226
                           004225  2044 G$AX5043_TMGRXOFFSACQ$0$0 == 0x4225
                           004225  2045 _AX5043_TMGRXOFFSACQ	=	0x4225
                           004229  2046 G$AX5043_TMGRXPREAMBLE1$0$0 == 0x4229
                           004229  2047 _AX5043_TMGRXPREAMBLE1	=	0x4229
                           00422A  2048 G$AX5043_TMGRXPREAMBLE2$0$0 == 0x422a
                           00422A  2049 _AX5043_TMGRXPREAMBLE2	=	0x422a
                           00422B  2050 G$AX5043_TMGRXPREAMBLE3$0$0 == 0x422b
                           00422B  2051 _AX5043_TMGRXPREAMBLE3	=	0x422b
                           004228  2052 G$AX5043_TMGRXRSSI$0$0 == 0x4228
                           004228  2053 _AX5043_TMGRXRSSI	=	0x4228
                           004224  2054 G$AX5043_TMGRXSETTLE$0$0 == 0x4224
                           004224  2055 _AX5043_TMGRXSETTLE	=	0x4224
                           004220  2056 G$AX5043_TMGTXBOOST$0$0 == 0x4220
                           004220  2057 _AX5043_TMGTXBOOST	=	0x4220
                           004221  2058 G$AX5043_TMGTXSETTLE$0$0 == 0x4221
                           004221  2059 _AX5043_TMGTXSETTLE	=	0x4221
                           004055  2060 G$AX5043_TRKAFSKDEMOD0$0$0 == 0x4055
                           004055  2061 _AX5043_TRKAFSKDEMOD0	=	0x4055
                           004054  2062 G$AX5043_TRKAFSKDEMOD1$0$0 == 0x4054
                           004054  2063 _AX5043_TRKAFSKDEMOD1	=	0x4054
                           004049  2064 G$AX5043_TRKAMPLITUDE0$0$0 == 0x4049
                           004049  2065 _AX5043_TRKAMPLITUDE0	=	0x4049
                           004048  2066 G$AX5043_TRKAMPLITUDE1$0$0 == 0x4048
                           004048  2067 _AX5043_TRKAMPLITUDE1	=	0x4048
                           004047  2068 G$AX5043_TRKDATARATE0$0$0 == 0x4047
                           004047  2069 _AX5043_TRKDATARATE0	=	0x4047
                           004046  2070 G$AX5043_TRKDATARATE1$0$0 == 0x4046
                           004046  2071 _AX5043_TRKDATARATE1	=	0x4046
                           004045  2072 G$AX5043_TRKDATARATE2$0$0 == 0x4045
                           004045  2073 _AX5043_TRKDATARATE2	=	0x4045
                           004051  2074 G$AX5043_TRKFREQ0$0$0 == 0x4051
                           004051  2075 _AX5043_TRKFREQ0	=	0x4051
                           004050  2076 G$AX5043_TRKFREQ1$0$0 == 0x4050
                           004050  2077 _AX5043_TRKFREQ1	=	0x4050
                           004053  2078 G$AX5043_TRKFSKDEMOD0$0$0 == 0x4053
                           004053  2079 _AX5043_TRKFSKDEMOD0	=	0x4053
                           004052  2080 G$AX5043_TRKFSKDEMOD1$0$0 == 0x4052
                           004052  2081 _AX5043_TRKFSKDEMOD1	=	0x4052
                           00404B  2082 G$AX5043_TRKPHASE0$0$0 == 0x404b
                           00404B  2083 _AX5043_TRKPHASE0	=	0x404b
                           00404A  2084 G$AX5043_TRKPHASE1$0$0 == 0x404a
                           00404A  2085 _AX5043_TRKPHASE1	=	0x404a
                           00404F  2086 G$AX5043_TRKRFFREQ0$0$0 == 0x404f
                           00404F  2087 _AX5043_TRKRFFREQ0	=	0x404f
                           00404E  2088 G$AX5043_TRKRFFREQ1$0$0 == 0x404e
                           00404E  2089 _AX5043_TRKRFFREQ1	=	0x404e
                           00404D  2090 G$AX5043_TRKRFFREQ2$0$0 == 0x404d
                           00404D  2091 _AX5043_TRKRFFREQ2	=	0x404d
                           004169  2092 G$AX5043_TXPWRCOEFFA0$0$0 == 0x4169
                           004169  2093 _AX5043_TXPWRCOEFFA0	=	0x4169
                           004168  2094 G$AX5043_TXPWRCOEFFA1$0$0 == 0x4168
                           004168  2095 _AX5043_TXPWRCOEFFA1	=	0x4168
                           00416B  2096 G$AX5043_TXPWRCOEFFB0$0$0 == 0x416b
                           00416B  2097 _AX5043_TXPWRCOEFFB0	=	0x416b
                           00416A  2098 G$AX5043_TXPWRCOEFFB1$0$0 == 0x416a
                           00416A  2099 _AX5043_TXPWRCOEFFB1	=	0x416a
                           00416D  2100 G$AX5043_TXPWRCOEFFC0$0$0 == 0x416d
                           00416D  2101 _AX5043_TXPWRCOEFFC0	=	0x416d
                           00416C  2102 G$AX5043_TXPWRCOEFFC1$0$0 == 0x416c
                           00416C  2103 _AX5043_TXPWRCOEFFC1	=	0x416c
                           00416F  2104 G$AX5043_TXPWRCOEFFD0$0$0 == 0x416f
                           00416F  2105 _AX5043_TXPWRCOEFFD0	=	0x416f
                           00416E  2106 G$AX5043_TXPWRCOEFFD1$0$0 == 0x416e
                           00416E  2107 _AX5043_TXPWRCOEFFD1	=	0x416e
                           004171  2108 G$AX5043_TXPWRCOEFFE0$0$0 == 0x4171
                           004171  2109 _AX5043_TXPWRCOEFFE0	=	0x4171
                           004170  2110 G$AX5043_TXPWRCOEFFE1$0$0 == 0x4170
                           004170  2111 _AX5043_TXPWRCOEFFE1	=	0x4170
                           004167  2112 G$AX5043_TXRATE0$0$0 == 0x4167
                           004167  2113 _AX5043_TXRATE0	=	0x4167
                           004166  2114 G$AX5043_TXRATE1$0$0 == 0x4166
                           004166  2115 _AX5043_TXRATE1	=	0x4166
                           004165  2116 G$AX5043_TXRATE2$0$0 == 0x4165
                           004165  2117 _AX5043_TXRATE2	=	0x4165
                           00406B  2118 G$AX5043_WAKEUP0$0$0 == 0x406b
                           00406B  2119 _AX5043_WAKEUP0	=	0x406b
                           00406A  2120 G$AX5043_WAKEUP1$0$0 == 0x406a
                           00406A  2121 _AX5043_WAKEUP1	=	0x406a
                           00406D  2122 G$AX5043_WAKEUPFREQ0$0$0 == 0x406d
                           00406D  2123 _AX5043_WAKEUPFREQ0	=	0x406d
                           00406C  2124 G$AX5043_WAKEUPFREQ1$0$0 == 0x406c
                           00406C  2125 _AX5043_WAKEUPFREQ1	=	0x406c
                           004069  2126 G$AX5043_WAKEUPTIMER0$0$0 == 0x4069
                           004069  2127 _AX5043_WAKEUPTIMER0	=	0x4069
                           004068  2128 G$AX5043_WAKEUPTIMER1$0$0 == 0x4068
                           004068  2129 _AX5043_WAKEUPTIMER1	=	0x4068
                           00406E  2130 G$AX5043_WAKEUPXOEARLY$0$0 == 0x406e
                           00406E  2131 _AX5043_WAKEUPXOEARLY	=	0x406e
                           004F11  2132 G$AX5043_XTALAMPL$0$0 == 0x4f11
                           004F11  2133 _AX5043_XTALAMPL	=	0x4f11
                           004184  2134 G$AX5043_XTALCAP$0$0 == 0x4184
                           004184  2135 _AX5043_XTALCAP	=	0x4184
                           004F10  2136 G$AX5043_XTALOSC$0$0 == 0x4f10
                           004F10  2137 _AX5043_XTALOSC	=	0x4f10
                           00401D  2138 G$AX5043_XTALSTATUS$0$0 == 0x401d
                           00401D  2139 _AX5043_XTALSTATUS	=	0x401d
                           004F00  2140 G$AX5043_0xF00$0$0 == 0x4f00
                           004F00  2141 _AX5043_0xF00	=	0x4f00
                           004F0C  2142 G$AX5043_0xF0C$0$0 == 0x4f0c
                           004F0C  2143 _AX5043_0xF0C	=	0x4f0c
                           004F18  2144 G$AX5043_0xF18$0$0 == 0x4f18
                           004F18  2145 _AX5043_0xF18	=	0x4f18
                           004F1C  2146 G$AX5043_0xF1C$0$0 == 0x4f1c
                           004F1C  2147 _AX5043_0xF1C	=	0x4f1c
                           004F21  2148 G$AX5043_0xF21$0$0 == 0x4f21
                           004F21  2149 _AX5043_0xF21	=	0x4f21
                           004F22  2150 G$AX5043_0xF22$0$0 == 0x4f22
                           004F22  2151 _AX5043_0xF22	=	0x4f22
                           004F23  2152 G$AX5043_0xF23$0$0 == 0x4f23
                           004F23  2153 _AX5043_0xF23	=	0x4f23
                           004F26  2154 G$AX5043_0xF26$0$0 == 0x4f26
                           004F26  2155 _AX5043_0xF26	=	0x4f26
                           004F30  2156 G$AX5043_0xF30$0$0 == 0x4f30
                           004F30  2157 _AX5043_0xF30	=	0x4f30
                           004F31  2158 G$AX5043_0xF31$0$0 == 0x4f31
                           004F31  2159 _AX5043_0xF31	=	0x4f31
                           004F32  2160 G$AX5043_0xF32$0$0 == 0x4f32
                           004F32  2161 _AX5043_0xF32	=	0x4f32
                           004F33  2162 G$AX5043_0xF33$0$0 == 0x4f33
                           004F33  2163 _AX5043_0xF33	=	0x4f33
                           004F34  2164 G$AX5043_0xF34$0$0 == 0x4f34
                           004F34  2165 _AX5043_0xF34	=	0x4f34
                           004F35  2166 G$AX5043_0xF35$0$0 == 0x4f35
                           004F35  2167 _AX5043_0xF35	=	0x4f35
                           004F44  2168 G$AX5043_0xF44$0$0 == 0x4f44
                           004F44  2169 _AX5043_0xF44	=	0x4f44
                           004122  2170 G$AX5043_AGCAHYST0$0$0 == 0x4122
                           004122  2171 _AX5043_AGCAHYST0	=	0x4122
                           004132  2172 G$AX5043_AGCAHYST1$0$0 == 0x4132
                           004132  2173 _AX5043_AGCAHYST1	=	0x4132
                           004142  2174 G$AX5043_AGCAHYST2$0$0 == 0x4142
                           004142  2175 _AX5043_AGCAHYST2	=	0x4142
                           004152  2176 G$AX5043_AGCAHYST3$0$0 == 0x4152
                           004152  2177 _AX5043_AGCAHYST3	=	0x4152
                           004120  2178 G$AX5043_AGCGAIN0$0$0 == 0x4120
                           004120  2179 _AX5043_AGCGAIN0	=	0x4120
                           004130  2180 G$AX5043_AGCGAIN1$0$0 == 0x4130
                           004130  2181 _AX5043_AGCGAIN1	=	0x4130
                           004140  2182 G$AX5043_AGCGAIN2$0$0 == 0x4140
                           004140  2183 _AX5043_AGCGAIN2	=	0x4140
                           004150  2184 G$AX5043_AGCGAIN3$0$0 == 0x4150
                           004150  2185 _AX5043_AGCGAIN3	=	0x4150
                           004123  2186 G$AX5043_AGCMINMAX0$0$0 == 0x4123
                           004123  2187 _AX5043_AGCMINMAX0	=	0x4123
                           004133  2188 G$AX5043_AGCMINMAX1$0$0 == 0x4133
                           004133  2189 _AX5043_AGCMINMAX1	=	0x4133
                           004143  2190 G$AX5043_AGCMINMAX2$0$0 == 0x4143
                           004143  2191 _AX5043_AGCMINMAX2	=	0x4143
                           004153  2192 G$AX5043_AGCMINMAX3$0$0 == 0x4153
                           004153  2193 _AX5043_AGCMINMAX3	=	0x4153
                           004121  2194 G$AX5043_AGCTARGET0$0$0 == 0x4121
                           004121  2195 _AX5043_AGCTARGET0	=	0x4121
                           004131  2196 G$AX5043_AGCTARGET1$0$0 == 0x4131
                           004131  2197 _AX5043_AGCTARGET1	=	0x4131
                           004141  2198 G$AX5043_AGCTARGET2$0$0 == 0x4141
                           004141  2199 _AX5043_AGCTARGET2	=	0x4141
                           004151  2200 G$AX5043_AGCTARGET3$0$0 == 0x4151
                           004151  2201 _AX5043_AGCTARGET3	=	0x4151
                           00412B  2202 G$AX5043_AMPLITUDEGAIN0$0$0 == 0x412b
                           00412B  2203 _AX5043_AMPLITUDEGAIN0	=	0x412b
                           00413B  2204 G$AX5043_AMPLITUDEGAIN1$0$0 == 0x413b
                           00413B  2205 _AX5043_AMPLITUDEGAIN1	=	0x413b
                           00414B  2206 G$AX5043_AMPLITUDEGAIN2$0$0 == 0x414b
                           00414B  2207 _AX5043_AMPLITUDEGAIN2	=	0x414b
                           00415B  2208 G$AX5043_AMPLITUDEGAIN3$0$0 == 0x415b
                           00415B  2209 _AX5043_AMPLITUDEGAIN3	=	0x415b
                           00412F  2210 G$AX5043_BBOFFSRES0$0$0 == 0x412f
                           00412F  2211 _AX5043_BBOFFSRES0	=	0x412f
                           00413F  2212 G$AX5043_BBOFFSRES1$0$0 == 0x413f
                           00413F  2213 _AX5043_BBOFFSRES1	=	0x413f
                           00414F  2214 G$AX5043_BBOFFSRES2$0$0 == 0x414f
                           00414F  2215 _AX5043_BBOFFSRES2	=	0x414f
                           00415F  2216 G$AX5043_BBOFFSRES3$0$0 == 0x415f
                           00415F  2217 _AX5043_BBOFFSRES3	=	0x415f
                           004125  2218 G$AX5043_DRGAIN0$0$0 == 0x4125
                           004125  2219 _AX5043_DRGAIN0	=	0x4125
                           004135  2220 G$AX5043_DRGAIN1$0$0 == 0x4135
                           004135  2221 _AX5043_DRGAIN1	=	0x4135
                           004145  2222 G$AX5043_DRGAIN2$0$0 == 0x4145
                           004145  2223 _AX5043_DRGAIN2	=	0x4145
                           004155  2224 G$AX5043_DRGAIN3$0$0 == 0x4155
                           004155  2225 _AX5043_DRGAIN3	=	0x4155
                           00412E  2226 G$AX5043_FOURFSK0$0$0 == 0x412e
                           00412E  2227 _AX5043_FOURFSK0	=	0x412e
                           00413E  2228 G$AX5043_FOURFSK1$0$0 == 0x413e
                           00413E  2229 _AX5043_FOURFSK1	=	0x413e
                           00414E  2230 G$AX5043_FOURFSK2$0$0 == 0x414e
                           00414E  2231 _AX5043_FOURFSK2	=	0x414e
                           00415E  2232 G$AX5043_FOURFSK3$0$0 == 0x415e
                           00415E  2233 _AX5043_FOURFSK3	=	0x415e
                           00412D  2234 G$AX5043_FREQDEV00$0$0 == 0x412d
                           00412D  2235 _AX5043_FREQDEV00	=	0x412d
                           00413D  2236 G$AX5043_FREQDEV01$0$0 == 0x413d
                           00413D  2237 _AX5043_FREQDEV01	=	0x413d
                           00414D  2238 G$AX5043_FREQDEV02$0$0 == 0x414d
                           00414D  2239 _AX5043_FREQDEV02	=	0x414d
                           00415D  2240 G$AX5043_FREQDEV03$0$0 == 0x415d
                           00415D  2241 _AX5043_FREQDEV03	=	0x415d
                           00412C  2242 G$AX5043_FREQDEV10$0$0 == 0x412c
                           00412C  2243 _AX5043_FREQDEV10	=	0x412c
                           00413C  2244 G$AX5043_FREQDEV11$0$0 == 0x413c
                           00413C  2245 _AX5043_FREQDEV11	=	0x413c
                           00414C  2246 G$AX5043_FREQDEV12$0$0 == 0x414c
                           00414C  2247 _AX5043_FREQDEV12	=	0x414c
                           00415C  2248 G$AX5043_FREQDEV13$0$0 == 0x415c
                           00415C  2249 _AX5043_FREQDEV13	=	0x415c
                           004127  2250 G$AX5043_FREQUENCYGAINA0$0$0 == 0x4127
                           004127  2251 _AX5043_FREQUENCYGAINA0	=	0x4127
                           004137  2252 G$AX5043_FREQUENCYGAINA1$0$0 == 0x4137
                           004137  2253 _AX5043_FREQUENCYGAINA1	=	0x4137
                           004147  2254 G$AX5043_FREQUENCYGAINA2$0$0 == 0x4147
                           004147  2255 _AX5043_FREQUENCYGAINA2	=	0x4147
                           004157  2256 G$AX5043_FREQUENCYGAINA3$0$0 == 0x4157
                           004157  2257 _AX5043_FREQUENCYGAINA3	=	0x4157
                           004128  2258 G$AX5043_FREQUENCYGAINB0$0$0 == 0x4128
                           004128  2259 _AX5043_FREQUENCYGAINB0	=	0x4128
                           004138  2260 G$AX5043_FREQUENCYGAINB1$0$0 == 0x4138
                           004138  2261 _AX5043_FREQUENCYGAINB1	=	0x4138
                           004148  2262 G$AX5043_FREQUENCYGAINB2$0$0 == 0x4148
                           004148  2263 _AX5043_FREQUENCYGAINB2	=	0x4148
                           004158  2264 G$AX5043_FREQUENCYGAINB3$0$0 == 0x4158
                           004158  2265 _AX5043_FREQUENCYGAINB3	=	0x4158
                           004129  2266 G$AX5043_FREQUENCYGAINC0$0$0 == 0x4129
                           004129  2267 _AX5043_FREQUENCYGAINC0	=	0x4129
                           004139  2268 G$AX5043_FREQUENCYGAINC1$0$0 == 0x4139
                           004139  2269 _AX5043_FREQUENCYGAINC1	=	0x4139
                           004149  2270 G$AX5043_FREQUENCYGAINC2$0$0 == 0x4149
                           004149  2271 _AX5043_FREQUENCYGAINC2	=	0x4149
                           004159  2272 G$AX5043_FREQUENCYGAINC3$0$0 == 0x4159
                           004159  2273 _AX5043_FREQUENCYGAINC3	=	0x4159
                           00412A  2274 G$AX5043_FREQUENCYGAIND0$0$0 == 0x412a
                           00412A  2275 _AX5043_FREQUENCYGAIND0	=	0x412a
                           00413A  2276 G$AX5043_FREQUENCYGAIND1$0$0 == 0x413a
                           00413A  2277 _AX5043_FREQUENCYGAIND1	=	0x413a
                           00414A  2278 G$AX5043_FREQUENCYGAIND2$0$0 == 0x414a
                           00414A  2279 _AX5043_FREQUENCYGAIND2	=	0x414a
                           00415A  2280 G$AX5043_FREQUENCYGAIND3$0$0 == 0x415a
                           00415A  2281 _AX5043_FREQUENCYGAIND3	=	0x415a
                           004116  2282 G$AX5043_FREQUENCYLEAK$0$0 == 0x4116
                           004116  2283 _AX5043_FREQUENCYLEAK	=	0x4116
                           004126  2284 G$AX5043_PHASEGAIN0$0$0 == 0x4126
                           004126  2285 _AX5043_PHASEGAIN0	=	0x4126
                           004136  2286 G$AX5043_PHASEGAIN1$0$0 == 0x4136
                           004136  2287 _AX5043_PHASEGAIN1	=	0x4136
                           004146  2288 G$AX5043_PHASEGAIN2$0$0 == 0x4146
                           004146  2289 _AX5043_PHASEGAIN2	=	0x4146
                           004156  2290 G$AX5043_PHASEGAIN3$0$0 == 0x4156
                           004156  2291 _AX5043_PHASEGAIN3	=	0x4156
                           004207  2292 G$AX5043_PKTADDR0$0$0 == 0x4207
                           004207  2293 _AX5043_PKTADDR0	=	0x4207
                           004206  2294 G$AX5043_PKTADDR1$0$0 == 0x4206
                           004206  2295 _AX5043_PKTADDR1	=	0x4206
                           004205  2296 G$AX5043_PKTADDR2$0$0 == 0x4205
                           004205  2297 _AX5043_PKTADDR2	=	0x4205
                           004204  2298 G$AX5043_PKTADDR3$0$0 == 0x4204
                           004204  2299 _AX5043_PKTADDR3	=	0x4204
                           004200  2300 G$AX5043_PKTADDRCFG$0$0 == 0x4200
                           004200  2301 _AX5043_PKTADDRCFG	=	0x4200
                           00420B  2302 G$AX5043_PKTADDRMASK0$0$0 == 0x420b
                           00420B  2303 _AX5043_PKTADDRMASK0	=	0x420b
                           00420A  2304 G$AX5043_PKTADDRMASK1$0$0 == 0x420a
                           00420A  2305 _AX5043_PKTADDRMASK1	=	0x420a
                           004209  2306 G$AX5043_PKTADDRMASK2$0$0 == 0x4209
                           004209  2307 _AX5043_PKTADDRMASK2	=	0x4209
                           004208  2308 G$AX5043_PKTADDRMASK3$0$0 == 0x4208
                           004208  2309 _AX5043_PKTADDRMASK3	=	0x4208
                           004201  2310 G$AX5043_PKTLENCFG$0$0 == 0x4201
                           004201  2311 _AX5043_PKTLENCFG	=	0x4201
                           004202  2312 G$AX5043_PKTLENOFFSET$0$0 == 0x4202
                           004202  2313 _AX5043_PKTLENOFFSET	=	0x4202
                           004203  2314 G$AX5043_PKTMAXLEN$0$0 == 0x4203
                           004203  2315 _AX5043_PKTMAXLEN	=	0x4203
                           004118  2316 G$AX5043_RXPARAMCURSET$0$0 == 0x4118
                           004118  2317 _AX5043_RXPARAMCURSET	=	0x4118
                           004117  2318 G$AX5043_RXPARAMSETS$0$0 == 0x4117
                           004117  2319 _AX5043_RXPARAMSETS	=	0x4117
                           004124  2320 G$AX5043_TIMEGAIN0$0$0 == 0x4124
                           004124  2321 _AX5043_TIMEGAIN0	=	0x4124
                           004134  2322 G$AX5043_TIMEGAIN1$0$0 == 0x4134
                           004134  2323 _AX5043_TIMEGAIN1	=	0x4134
                           004144  2324 G$AX5043_TIMEGAIN2$0$0 == 0x4144
                           004144  2325 _AX5043_TIMEGAIN2	=	0x4144
                           004154  2326 G$AX5043_TIMEGAIN3$0$0 == 0x4154
                           004154  2327 _AX5043_TIMEGAIN3	=	0x4154
                           005114  2328 G$AX5043_AFSKCTRLNB$0$0 == 0x5114
                           005114  2329 _AX5043_AFSKCTRLNB	=	0x5114
                           005113  2330 G$AX5043_AFSKMARK0NB$0$0 == 0x5113
                           005113  2331 _AX5043_AFSKMARK0NB	=	0x5113
                           005112  2332 G$AX5043_AFSKMARK1NB$0$0 == 0x5112
                           005112  2333 _AX5043_AFSKMARK1NB	=	0x5112
                           005111  2334 G$AX5043_AFSKSPACE0NB$0$0 == 0x5111
                           005111  2335 _AX5043_AFSKSPACE0NB	=	0x5111
                           005110  2336 G$AX5043_AFSKSPACE1NB$0$0 == 0x5110
                           005110  2337 _AX5043_AFSKSPACE1NB	=	0x5110
                           005043  2338 G$AX5043_AGCCOUNTERNB$0$0 == 0x5043
                           005043  2339 _AX5043_AGCCOUNTERNB	=	0x5043
                           005115  2340 G$AX5043_AMPLFILTERNB$0$0 == 0x5115
                           005115  2341 _AX5043_AMPLFILTERNB	=	0x5115
                           005189  2342 G$AX5043_BBOFFSCAPNB$0$0 == 0x5189
                           005189  2343 _AX5043_BBOFFSCAPNB	=	0x5189
                           005188  2344 G$AX5043_BBTUNENB$0$0 == 0x5188
                           005188  2345 _AX5043_BBTUNENB	=	0x5188
                           005041  2346 G$AX5043_BGNDRSSINB$0$0 == 0x5041
                           005041  2347 _AX5043_BGNDRSSINB	=	0x5041
                           00522E  2348 G$AX5043_BGNDRSSIGAINNB$0$0 == 0x522e
                           00522E  2349 _AX5043_BGNDRSSIGAINNB	=	0x522e
                           00522F  2350 G$AX5043_BGNDRSSITHRNB$0$0 == 0x522f
                           00522F  2351 _AX5043_BGNDRSSITHRNB	=	0x522f
                           005017  2352 G$AX5043_CRCINIT0NB$0$0 == 0x5017
                           005017  2353 _AX5043_CRCINIT0NB	=	0x5017
                           005016  2354 G$AX5043_CRCINIT1NB$0$0 == 0x5016
                           005016  2355 _AX5043_CRCINIT1NB	=	0x5016
                           005015  2356 G$AX5043_CRCINIT2NB$0$0 == 0x5015
                           005015  2357 _AX5043_CRCINIT2NB	=	0x5015
                           005014  2358 G$AX5043_CRCINIT3NB$0$0 == 0x5014
                           005014  2359 _AX5043_CRCINIT3NB	=	0x5014
                           005332  2360 G$AX5043_DACCONFIGNB$0$0 == 0x5332
                           005332  2361 _AX5043_DACCONFIGNB	=	0x5332
                           005331  2362 G$AX5043_DACVALUE0NB$0$0 == 0x5331
                           005331  2363 _AX5043_DACVALUE0NB	=	0x5331
                           005330  2364 G$AX5043_DACVALUE1NB$0$0 == 0x5330
                           005330  2365 _AX5043_DACVALUE1NB	=	0x5330
                           005102  2366 G$AX5043_DECIMATIONNB$0$0 == 0x5102
                           005102  2367 _AX5043_DECIMATIONNB	=	0x5102
                           005042  2368 G$AX5043_DIVERSITYNB$0$0 == 0x5042
                           005042  2369 _AX5043_DIVERSITYNB	=	0x5042
                           005011  2370 G$AX5043_ENCODINGNB$0$0 == 0x5011
                           005011  2371 _AX5043_ENCODINGNB	=	0x5011
                           005018  2372 G$AX5043_FECNB$0$0 == 0x5018
                           005018  2373 _AX5043_FECNB	=	0x5018
                           00501A  2374 G$AX5043_FECSTATUSNB$0$0 == 0x501a
                           00501A  2375 _AX5043_FECSTATUSNB	=	0x501a
                           005019  2376 G$AX5043_FECSYNCNB$0$0 == 0x5019
                           005019  2377 _AX5043_FECSYNCNB	=	0x5019
                           00502B  2378 G$AX5043_FIFOCOUNT0NB$0$0 == 0x502b
                           00502B  2379 _AX5043_FIFOCOUNT0NB	=	0x502b
                           00502A  2380 G$AX5043_FIFOCOUNT1NB$0$0 == 0x502a
                           00502A  2381 _AX5043_FIFOCOUNT1NB	=	0x502a
                           005029  2382 G$AX5043_FIFODATANB$0$0 == 0x5029
                           005029  2383 _AX5043_FIFODATANB	=	0x5029
                           00502D  2384 G$AX5043_FIFOFREE0NB$0$0 == 0x502d
                           00502D  2385 _AX5043_FIFOFREE0NB	=	0x502d
                           00502C  2386 G$AX5043_FIFOFREE1NB$0$0 == 0x502c
                           00502C  2387 _AX5043_FIFOFREE1NB	=	0x502c
                           005028  2388 G$AX5043_FIFOSTATNB$0$0 == 0x5028
                           005028  2389 _AX5043_FIFOSTATNB	=	0x5028
                           00502F  2390 G$AX5043_FIFOTHRESH0NB$0$0 == 0x502f
                           00502F  2391 _AX5043_FIFOTHRESH0NB	=	0x502f
                           00502E  2392 G$AX5043_FIFOTHRESH1NB$0$0 == 0x502e
                           00502E  2393 _AX5043_FIFOTHRESH1NB	=	0x502e
                           005012  2394 G$AX5043_FRAMINGNB$0$0 == 0x5012
                           005012  2395 _AX5043_FRAMINGNB	=	0x5012
                           005037  2396 G$AX5043_FREQA0NB$0$0 == 0x5037
                           005037  2397 _AX5043_FREQA0NB	=	0x5037
                           005036  2398 G$AX5043_FREQA1NB$0$0 == 0x5036
                           005036  2399 _AX5043_FREQA1NB	=	0x5036
                           005035  2400 G$AX5043_FREQA2NB$0$0 == 0x5035
                           005035  2401 _AX5043_FREQA2NB	=	0x5035
                           005034  2402 G$AX5043_FREQA3NB$0$0 == 0x5034
                           005034  2403 _AX5043_FREQA3NB	=	0x5034
                           00503F  2404 G$AX5043_FREQB0NB$0$0 == 0x503f
                           00503F  2405 _AX5043_FREQB0NB	=	0x503f
                           00503E  2406 G$AX5043_FREQB1NB$0$0 == 0x503e
                           00503E  2407 _AX5043_FREQB1NB	=	0x503e
                           00503D  2408 G$AX5043_FREQB2NB$0$0 == 0x503d
                           00503D  2409 _AX5043_FREQB2NB	=	0x503d
                           00503C  2410 G$AX5043_FREQB3NB$0$0 == 0x503c
                           00503C  2411 _AX5043_FREQB3NB	=	0x503c
                           005163  2412 G$AX5043_FSKDEV0NB$0$0 == 0x5163
                           005163  2413 _AX5043_FSKDEV0NB	=	0x5163
                           005162  2414 G$AX5043_FSKDEV1NB$0$0 == 0x5162
                           005162  2415 _AX5043_FSKDEV1NB	=	0x5162
                           005161  2416 G$AX5043_FSKDEV2NB$0$0 == 0x5161
                           005161  2417 _AX5043_FSKDEV2NB	=	0x5161
                           00510D  2418 G$AX5043_FSKDMAX0NB$0$0 == 0x510d
                           00510D  2419 _AX5043_FSKDMAX0NB	=	0x510d
                           00510C  2420 G$AX5043_FSKDMAX1NB$0$0 == 0x510c
                           00510C  2421 _AX5043_FSKDMAX1NB	=	0x510c
                           00510F  2422 G$AX5043_FSKDMIN0NB$0$0 == 0x510f
                           00510F  2423 _AX5043_FSKDMIN0NB	=	0x510f
                           00510E  2424 G$AX5043_FSKDMIN1NB$0$0 == 0x510e
                           00510E  2425 _AX5043_FSKDMIN1NB	=	0x510e
                           005309  2426 G$AX5043_GPADC13VALUE0NB$0$0 == 0x5309
                           005309  2427 _AX5043_GPADC13VALUE0NB	=	0x5309
                           005308  2428 G$AX5043_GPADC13VALUE1NB$0$0 == 0x5308
                           005308  2429 _AX5043_GPADC13VALUE1NB	=	0x5308
                           005300  2430 G$AX5043_GPADCCTRLNB$0$0 == 0x5300
                           005300  2431 _AX5043_GPADCCTRLNB	=	0x5300
                           005301  2432 G$AX5043_GPADCPERIODNB$0$0 == 0x5301
                           005301  2433 _AX5043_GPADCPERIODNB	=	0x5301
                           005101  2434 G$AX5043_IFFREQ0NB$0$0 == 0x5101
                           005101  2435 _AX5043_IFFREQ0NB	=	0x5101
                           005100  2436 G$AX5043_IFFREQ1NB$0$0 == 0x5100
                           005100  2437 _AX5043_IFFREQ1NB	=	0x5100
                           00500B  2438 G$AX5043_IRQINVERSION0NB$0$0 == 0x500b
                           00500B  2439 _AX5043_IRQINVERSION0NB	=	0x500b
                           00500A  2440 G$AX5043_IRQINVERSION1NB$0$0 == 0x500a
                           00500A  2441 _AX5043_IRQINVERSION1NB	=	0x500a
                           005007  2442 G$AX5043_IRQMASK0NB$0$0 == 0x5007
                           005007  2443 _AX5043_IRQMASK0NB	=	0x5007
                           005006  2444 G$AX5043_IRQMASK1NB$0$0 == 0x5006
                           005006  2445 _AX5043_IRQMASK1NB	=	0x5006
                           00500D  2446 G$AX5043_IRQREQUEST0NB$0$0 == 0x500d
                           00500D  2447 _AX5043_IRQREQUEST0NB	=	0x500d
                           00500C  2448 G$AX5043_IRQREQUEST1NB$0$0 == 0x500c
                           00500C  2449 _AX5043_IRQREQUEST1NB	=	0x500c
                           005310  2450 G$AX5043_LPOSCCONFIGNB$0$0 == 0x5310
                           005310  2451 _AX5043_LPOSCCONFIGNB	=	0x5310
                           005317  2452 G$AX5043_LPOSCFREQ0NB$0$0 == 0x5317
                           005317  2453 _AX5043_LPOSCFREQ0NB	=	0x5317
                           005316  2454 G$AX5043_LPOSCFREQ1NB$0$0 == 0x5316
                           005316  2455 _AX5043_LPOSCFREQ1NB	=	0x5316
                           005313  2456 G$AX5043_LPOSCKFILT0NB$0$0 == 0x5313
                           005313  2457 _AX5043_LPOSCKFILT0NB	=	0x5313
                           005312  2458 G$AX5043_LPOSCKFILT1NB$0$0 == 0x5312
                           005312  2459 _AX5043_LPOSCKFILT1NB	=	0x5312
                           005319  2460 G$AX5043_LPOSCPER0NB$0$0 == 0x5319
                           005319  2461 _AX5043_LPOSCPER0NB	=	0x5319
                           005318  2462 G$AX5043_LPOSCPER1NB$0$0 == 0x5318
                           005318  2463 _AX5043_LPOSCPER1NB	=	0x5318
                           005315  2464 G$AX5043_LPOSCREF0NB$0$0 == 0x5315
                           005315  2465 _AX5043_LPOSCREF0NB	=	0x5315
                           005314  2466 G$AX5043_LPOSCREF1NB$0$0 == 0x5314
                           005314  2467 _AX5043_LPOSCREF1NB	=	0x5314
                           005311  2468 G$AX5043_LPOSCSTATUSNB$0$0 == 0x5311
                           005311  2469 _AX5043_LPOSCSTATUSNB	=	0x5311
                           005214  2470 G$AX5043_MATCH0LENNB$0$0 == 0x5214
                           005214  2471 _AX5043_MATCH0LENNB	=	0x5214
                           005216  2472 G$AX5043_MATCH0MAXNB$0$0 == 0x5216
                           005216  2473 _AX5043_MATCH0MAXNB	=	0x5216
                           005215  2474 G$AX5043_MATCH0MINNB$0$0 == 0x5215
                           005215  2475 _AX5043_MATCH0MINNB	=	0x5215
                           005213  2476 G$AX5043_MATCH0PAT0NB$0$0 == 0x5213
                           005213  2477 _AX5043_MATCH0PAT0NB	=	0x5213
                           005212  2478 G$AX5043_MATCH0PAT1NB$0$0 == 0x5212
                           005212  2479 _AX5043_MATCH0PAT1NB	=	0x5212
                           005211  2480 G$AX5043_MATCH0PAT2NB$0$0 == 0x5211
                           005211  2481 _AX5043_MATCH0PAT2NB	=	0x5211
                           005210  2482 G$AX5043_MATCH0PAT3NB$0$0 == 0x5210
                           005210  2483 _AX5043_MATCH0PAT3NB	=	0x5210
                           00521C  2484 G$AX5043_MATCH1LENNB$0$0 == 0x521c
                           00521C  2485 _AX5043_MATCH1LENNB	=	0x521c
                           00521E  2486 G$AX5043_MATCH1MAXNB$0$0 == 0x521e
                           00521E  2487 _AX5043_MATCH1MAXNB	=	0x521e
                           00521D  2488 G$AX5043_MATCH1MINNB$0$0 == 0x521d
                           00521D  2489 _AX5043_MATCH1MINNB	=	0x521d
                           005219  2490 G$AX5043_MATCH1PAT0NB$0$0 == 0x5219
                           005219  2491 _AX5043_MATCH1PAT0NB	=	0x5219
                           005218  2492 G$AX5043_MATCH1PAT1NB$0$0 == 0x5218
                           005218  2493 _AX5043_MATCH1PAT1NB	=	0x5218
                           005108  2494 G$AX5043_MAXDROFFSET0NB$0$0 == 0x5108
                           005108  2495 _AX5043_MAXDROFFSET0NB	=	0x5108
                           005107  2496 G$AX5043_MAXDROFFSET1NB$0$0 == 0x5107
                           005107  2497 _AX5043_MAXDROFFSET1NB	=	0x5107
                           005106  2498 G$AX5043_MAXDROFFSET2NB$0$0 == 0x5106
                           005106  2499 _AX5043_MAXDROFFSET2NB	=	0x5106
                           00510B  2500 G$AX5043_MAXRFOFFSET0NB$0$0 == 0x510b
                           00510B  2501 _AX5043_MAXRFOFFSET0NB	=	0x510b
                           00510A  2502 G$AX5043_MAXRFOFFSET1NB$0$0 == 0x510a
                           00510A  2503 _AX5043_MAXRFOFFSET1NB	=	0x510a
                           005109  2504 G$AX5043_MAXRFOFFSET2NB$0$0 == 0x5109
                           005109  2505 _AX5043_MAXRFOFFSET2NB	=	0x5109
                           005164  2506 G$AX5043_MODCFGANB$0$0 == 0x5164
                           005164  2507 _AX5043_MODCFGANB	=	0x5164
                           005160  2508 G$AX5043_MODCFGFNB$0$0 == 0x5160
                           005160  2509 _AX5043_MODCFGFNB	=	0x5160
                           005F5F  2510 G$AX5043_MODCFGPNB$0$0 == 0x5f5f
                           005F5F  2511 _AX5043_MODCFGPNB	=	0x5f5f
                           005010  2512 G$AX5043_MODULATIONNB$0$0 == 0x5010
                           005010  2513 _AX5043_MODULATIONNB	=	0x5010
                           005025  2514 G$AX5043_PINFUNCANTSELNB$0$0 == 0x5025
                           005025  2515 _AX5043_PINFUNCANTSELNB	=	0x5025
                           005023  2516 G$AX5043_PINFUNCDATANB$0$0 == 0x5023
                           005023  2517 _AX5043_PINFUNCDATANB	=	0x5023
                           005022  2518 G$AX5043_PINFUNCDCLKNB$0$0 == 0x5022
                           005022  2519 _AX5043_PINFUNCDCLKNB	=	0x5022
                           005024  2520 G$AX5043_PINFUNCIRQNB$0$0 == 0x5024
                           005024  2521 _AX5043_PINFUNCIRQNB	=	0x5024
                           005026  2522 G$AX5043_PINFUNCPWRAMPNB$0$0 == 0x5026
                           005026  2523 _AX5043_PINFUNCPWRAMPNB	=	0x5026
                           005021  2524 G$AX5043_PINFUNCSYSCLKNB$0$0 == 0x5021
                           005021  2525 _AX5043_PINFUNCSYSCLKNB	=	0x5021
                           005020  2526 G$AX5043_PINSTATENB$0$0 == 0x5020
                           005020  2527 _AX5043_PINSTATENB	=	0x5020
                           005233  2528 G$AX5043_PKTACCEPTFLAGSNB$0$0 == 0x5233
                           005233  2529 _AX5043_PKTACCEPTFLAGSNB	=	0x5233
                           005230  2530 G$AX5043_PKTCHUNKSIZENB$0$0 == 0x5230
                           005230  2531 _AX5043_PKTCHUNKSIZENB	=	0x5230
                           005231  2532 G$AX5043_PKTMISCFLAGSNB$0$0 == 0x5231
                           005231  2533 _AX5043_PKTMISCFLAGSNB	=	0x5231
                           005232  2534 G$AX5043_PKTSTOREFLAGSNB$0$0 == 0x5232
                           005232  2535 _AX5043_PKTSTOREFLAGSNB	=	0x5232
                           005031  2536 G$AX5043_PLLCPINB$0$0 == 0x5031
                           005031  2537 _AX5043_PLLCPINB	=	0x5031
                           005039  2538 G$AX5043_PLLCPIBOOSTNB$0$0 == 0x5039
                           005039  2539 _AX5043_PLLCPIBOOSTNB	=	0x5039
                           005182  2540 G$AX5043_PLLLOCKDETNB$0$0 == 0x5182
                           005182  2541 _AX5043_PLLLOCKDETNB	=	0x5182
                           005030  2542 G$AX5043_PLLLOOPNB$0$0 == 0x5030
                           005030  2543 _AX5043_PLLLOOPNB	=	0x5030
                           005038  2544 G$AX5043_PLLLOOPBOOSTNB$0$0 == 0x5038
                           005038  2545 _AX5043_PLLLOOPBOOSTNB	=	0x5038
                           005033  2546 G$AX5043_PLLRANGINGANB$0$0 == 0x5033
                           005033  2547 _AX5043_PLLRANGINGANB	=	0x5033
                           00503B  2548 G$AX5043_PLLRANGINGBNB$0$0 == 0x503b
                           00503B  2549 _AX5043_PLLRANGINGBNB	=	0x503b
                           005183  2550 G$AX5043_PLLRNGCLKNB$0$0 == 0x5183
                           005183  2551 _AX5043_PLLRNGCLKNB	=	0x5183
                           005032  2552 G$AX5043_PLLVCODIVNB$0$0 == 0x5032
                           005032  2553 _AX5043_PLLVCODIVNB	=	0x5032
                           005180  2554 G$AX5043_PLLVCOINB$0$0 == 0x5180
                           005180  2555 _AX5043_PLLVCOINB	=	0x5180
                           005181  2556 G$AX5043_PLLVCOIRNB$0$0 == 0x5181
                           005181  2557 _AX5043_PLLVCOIRNB	=	0x5181
                           005F08  2558 G$AX5043_POWCTRL1NB$0$0 == 0x5f08
                           005F08  2559 _AX5043_POWCTRL1NB	=	0x5f08
                           005005  2560 G$AX5043_POWIRQMASKNB$0$0 == 0x5005
                           005005  2561 _AX5043_POWIRQMASKNB	=	0x5005
                           005003  2562 G$AX5043_POWSTATNB$0$0 == 0x5003
                           005003  2563 _AX5043_POWSTATNB	=	0x5003
                           005004  2564 G$AX5043_POWSTICKYSTATNB$0$0 == 0x5004
                           005004  2565 _AX5043_POWSTICKYSTATNB	=	0x5004
                           005027  2566 G$AX5043_PWRAMPNB$0$0 == 0x5027
                           005027  2567 _AX5043_PWRAMPNB	=	0x5027
                           005002  2568 G$AX5043_PWRMODENB$0$0 == 0x5002
                           005002  2569 _AX5043_PWRMODENB	=	0x5002
                           005009  2570 G$AX5043_RADIOEVENTMASK0NB$0$0 == 0x5009
                           005009  2571 _AX5043_RADIOEVENTMASK0NB	=	0x5009
                           005008  2572 G$AX5043_RADIOEVENTMASK1NB$0$0 == 0x5008
                           005008  2573 _AX5043_RADIOEVENTMASK1NB	=	0x5008
                           00500F  2574 G$AX5043_RADIOEVENTREQ0NB$0$0 == 0x500f
                           00500F  2575 _AX5043_RADIOEVENTREQ0NB	=	0x500f
                           00500E  2576 G$AX5043_RADIOEVENTREQ1NB$0$0 == 0x500e
                           00500E  2577 _AX5043_RADIOEVENTREQ1NB	=	0x500e
                           00501C  2578 G$AX5043_RADIOSTATENB$0$0 == 0x501c
                           00501C  2579 _AX5043_RADIOSTATENB	=	0x501c
                           005F0D  2580 G$AX5043_REFNB$0$0 == 0x5f0d
                           005F0D  2581 _AX5043_REFNB	=	0x5f0d
                           005040  2582 G$AX5043_RSSINB$0$0 == 0x5040
                           005040  2583 _AX5043_RSSINB	=	0x5040
                           00522D  2584 G$AX5043_RSSIABSTHRNB$0$0 == 0x522d
                           00522D  2585 _AX5043_RSSIABSTHRNB	=	0x522d
                           00522C  2586 G$AX5043_RSSIREFERENCENB$0$0 == 0x522c
                           00522C  2587 _AX5043_RSSIREFERENCENB	=	0x522c
                           005105  2588 G$AX5043_RXDATARATE0NB$0$0 == 0x5105
                           005105  2589 _AX5043_RXDATARATE0NB	=	0x5105
                           005104  2590 G$AX5043_RXDATARATE1NB$0$0 == 0x5104
                           005104  2591 _AX5043_RXDATARATE1NB	=	0x5104
                           005103  2592 G$AX5043_RXDATARATE2NB$0$0 == 0x5103
                           005103  2593 _AX5043_RXDATARATE2NB	=	0x5103
                           005001  2594 G$AX5043_SCRATCHNB$0$0 == 0x5001
                           005001  2595 _AX5043_SCRATCHNB	=	0x5001
                           005000  2596 G$AX5043_SILICONREVISIONNB$0$0 == 0x5000
                           005000  2597 _AX5043_SILICONREVISIONNB	=	0x5000
                           00505B  2598 G$AX5043_TIMER0NB$0$0 == 0x505b
                           00505B  2599 _AX5043_TIMER0NB	=	0x505b
                           00505A  2600 G$AX5043_TIMER1NB$0$0 == 0x505a
                           00505A  2601 _AX5043_TIMER1NB	=	0x505a
                           005059  2602 G$AX5043_TIMER2NB$0$0 == 0x5059
                           005059  2603 _AX5043_TIMER2NB	=	0x5059
                           005227  2604 G$AX5043_TMGRXAGCNB$0$0 == 0x5227
                           005227  2605 _AX5043_TMGRXAGCNB	=	0x5227
                           005223  2606 G$AX5043_TMGRXBOOSTNB$0$0 == 0x5223
                           005223  2607 _AX5043_TMGRXBOOSTNB	=	0x5223
                           005226  2608 G$AX5043_TMGRXCOARSEAGCNB$0$0 == 0x5226
                           005226  2609 _AX5043_TMGRXCOARSEAGCNB	=	0x5226
                           005225  2610 G$AX5043_TMGRXOFFSACQNB$0$0 == 0x5225
                           005225  2611 _AX5043_TMGRXOFFSACQNB	=	0x5225
                           005229  2612 G$AX5043_TMGRXPREAMBLE1NB$0$0 == 0x5229
                           005229  2613 _AX5043_TMGRXPREAMBLE1NB	=	0x5229
                           00522A  2614 G$AX5043_TMGRXPREAMBLE2NB$0$0 == 0x522a
                           00522A  2615 _AX5043_TMGRXPREAMBLE2NB	=	0x522a
                           00522B  2616 G$AX5043_TMGRXPREAMBLE3NB$0$0 == 0x522b
                           00522B  2617 _AX5043_TMGRXPREAMBLE3NB	=	0x522b
                           005228  2618 G$AX5043_TMGRXRSSINB$0$0 == 0x5228
                           005228  2619 _AX5043_TMGRXRSSINB	=	0x5228
                           005224  2620 G$AX5043_TMGRXSETTLENB$0$0 == 0x5224
                           005224  2621 _AX5043_TMGRXSETTLENB	=	0x5224
                           005220  2622 G$AX5043_TMGTXBOOSTNB$0$0 == 0x5220
                           005220  2623 _AX5043_TMGTXBOOSTNB	=	0x5220
                           005221  2624 G$AX5043_TMGTXSETTLENB$0$0 == 0x5221
                           005221  2625 _AX5043_TMGTXSETTLENB	=	0x5221
                           005055  2626 G$AX5043_TRKAFSKDEMOD0NB$0$0 == 0x5055
                           005055  2627 _AX5043_TRKAFSKDEMOD0NB	=	0x5055
                           005054  2628 G$AX5043_TRKAFSKDEMOD1NB$0$0 == 0x5054
                           005054  2629 _AX5043_TRKAFSKDEMOD1NB	=	0x5054
                           005049  2630 G$AX5043_TRKAMPLITUDE0NB$0$0 == 0x5049
                           005049  2631 _AX5043_TRKAMPLITUDE0NB	=	0x5049
                           005048  2632 G$AX5043_TRKAMPLITUDE1NB$0$0 == 0x5048
                           005048  2633 _AX5043_TRKAMPLITUDE1NB	=	0x5048
                           005047  2634 G$AX5043_TRKDATARATE0NB$0$0 == 0x5047
                           005047  2635 _AX5043_TRKDATARATE0NB	=	0x5047
                           005046  2636 G$AX5043_TRKDATARATE1NB$0$0 == 0x5046
                           005046  2637 _AX5043_TRKDATARATE1NB	=	0x5046
                           005045  2638 G$AX5043_TRKDATARATE2NB$0$0 == 0x5045
                           005045  2639 _AX5043_TRKDATARATE2NB	=	0x5045
                           005051  2640 G$AX5043_TRKFREQ0NB$0$0 == 0x5051
                           005051  2641 _AX5043_TRKFREQ0NB	=	0x5051
                           005050  2642 G$AX5043_TRKFREQ1NB$0$0 == 0x5050
                           005050  2643 _AX5043_TRKFREQ1NB	=	0x5050
                           005053  2644 G$AX5043_TRKFSKDEMOD0NB$0$0 == 0x5053
                           005053  2645 _AX5043_TRKFSKDEMOD0NB	=	0x5053
                           005052  2646 G$AX5043_TRKFSKDEMOD1NB$0$0 == 0x5052
                           005052  2647 _AX5043_TRKFSKDEMOD1NB	=	0x5052
                           00504B  2648 G$AX5043_TRKPHASE0NB$0$0 == 0x504b
                           00504B  2649 _AX5043_TRKPHASE0NB	=	0x504b
                           00504A  2650 G$AX5043_TRKPHASE1NB$0$0 == 0x504a
                           00504A  2651 _AX5043_TRKPHASE1NB	=	0x504a
                           00504F  2652 G$AX5043_TRKRFFREQ0NB$0$0 == 0x504f
                           00504F  2653 _AX5043_TRKRFFREQ0NB	=	0x504f
                           00504E  2654 G$AX5043_TRKRFFREQ1NB$0$0 == 0x504e
                           00504E  2655 _AX5043_TRKRFFREQ1NB	=	0x504e
                           00504D  2656 G$AX5043_TRKRFFREQ2NB$0$0 == 0x504d
                           00504D  2657 _AX5043_TRKRFFREQ2NB	=	0x504d
                           005169  2658 G$AX5043_TXPWRCOEFFA0NB$0$0 == 0x5169
                           005169  2659 _AX5043_TXPWRCOEFFA0NB	=	0x5169
                           005168  2660 G$AX5043_TXPWRCOEFFA1NB$0$0 == 0x5168
                           005168  2661 _AX5043_TXPWRCOEFFA1NB	=	0x5168
                           00516B  2662 G$AX5043_TXPWRCOEFFB0NB$0$0 == 0x516b
                           00516B  2663 _AX5043_TXPWRCOEFFB0NB	=	0x516b
                           00516A  2664 G$AX5043_TXPWRCOEFFB1NB$0$0 == 0x516a
                           00516A  2665 _AX5043_TXPWRCOEFFB1NB	=	0x516a
                           00516D  2666 G$AX5043_TXPWRCOEFFC0NB$0$0 == 0x516d
                           00516D  2667 _AX5043_TXPWRCOEFFC0NB	=	0x516d
                           00516C  2668 G$AX5043_TXPWRCOEFFC1NB$0$0 == 0x516c
                           00516C  2669 _AX5043_TXPWRCOEFFC1NB	=	0x516c
                           00516F  2670 G$AX5043_TXPWRCOEFFD0NB$0$0 == 0x516f
                           00516F  2671 _AX5043_TXPWRCOEFFD0NB	=	0x516f
                           00516E  2672 G$AX5043_TXPWRCOEFFD1NB$0$0 == 0x516e
                           00516E  2673 _AX5043_TXPWRCOEFFD1NB	=	0x516e
                           005171  2674 G$AX5043_TXPWRCOEFFE0NB$0$0 == 0x5171
                           005171  2675 _AX5043_TXPWRCOEFFE0NB	=	0x5171
                           005170  2676 G$AX5043_TXPWRCOEFFE1NB$0$0 == 0x5170
                           005170  2677 _AX5043_TXPWRCOEFFE1NB	=	0x5170
                           005167  2678 G$AX5043_TXRATE0NB$0$0 == 0x5167
                           005167  2679 _AX5043_TXRATE0NB	=	0x5167
                           005166  2680 G$AX5043_TXRATE1NB$0$0 == 0x5166
                           005166  2681 _AX5043_TXRATE1NB	=	0x5166
                           005165  2682 G$AX5043_TXRATE2NB$0$0 == 0x5165
                           005165  2683 _AX5043_TXRATE2NB	=	0x5165
                           00506B  2684 G$AX5043_WAKEUP0NB$0$0 == 0x506b
                           00506B  2685 _AX5043_WAKEUP0NB	=	0x506b
                           00506A  2686 G$AX5043_WAKEUP1NB$0$0 == 0x506a
                           00506A  2687 _AX5043_WAKEUP1NB	=	0x506a
                           00506D  2688 G$AX5043_WAKEUPFREQ0NB$0$0 == 0x506d
                           00506D  2689 _AX5043_WAKEUPFREQ0NB	=	0x506d
                           00506C  2690 G$AX5043_WAKEUPFREQ1NB$0$0 == 0x506c
                           00506C  2691 _AX5043_WAKEUPFREQ1NB	=	0x506c
                           005069  2692 G$AX5043_WAKEUPTIMER0NB$0$0 == 0x5069
                           005069  2693 _AX5043_WAKEUPTIMER0NB	=	0x5069
                           005068  2694 G$AX5043_WAKEUPTIMER1NB$0$0 == 0x5068
                           005068  2695 _AX5043_WAKEUPTIMER1NB	=	0x5068
                           00506E  2696 G$AX5043_WAKEUPXOEARLYNB$0$0 == 0x506e
                           00506E  2697 _AX5043_WAKEUPXOEARLYNB	=	0x506e
                           005F11  2698 G$AX5043_XTALAMPLNB$0$0 == 0x5f11
                           005F11  2699 _AX5043_XTALAMPLNB	=	0x5f11
                           005184  2700 G$AX5043_XTALCAPNB$0$0 == 0x5184
                           005184  2701 _AX5043_XTALCAPNB	=	0x5184
                           005F10  2702 G$AX5043_XTALOSCNB$0$0 == 0x5f10
                           005F10  2703 _AX5043_XTALOSCNB	=	0x5f10
                           00501D  2704 G$AX5043_XTALSTATUSNB$0$0 == 0x501d
                           00501D  2705 _AX5043_XTALSTATUSNB	=	0x501d
                           005F00  2706 G$AX5043_0xF00NB$0$0 == 0x5f00
                           005F00  2707 _AX5043_0xF00NB	=	0x5f00
                           005F0C  2708 G$AX5043_0xF0CNB$0$0 == 0x5f0c
                           005F0C  2709 _AX5043_0xF0CNB	=	0x5f0c
                           005F18  2710 G$AX5043_0xF18NB$0$0 == 0x5f18
                           005F18  2711 _AX5043_0xF18NB	=	0x5f18
                           005F1C  2712 G$AX5043_0xF1CNB$0$0 == 0x5f1c
                           005F1C  2713 _AX5043_0xF1CNB	=	0x5f1c
                           005F21  2714 G$AX5043_0xF21NB$0$0 == 0x5f21
                           005F21  2715 _AX5043_0xF21NB	=	0x5f21
                           005F22  2716 G$AX5043_0xF22NB$0$0 == 0x5f22
                           005F22  2717 _AX5043_0xF22NB	=	0x5f22
                           005F23  2718 G$AX5043_0xF23NB$0$0 == 0x5f23
                           005F23  2719 _AX5043_0xF23NB	=	0x5f23
                           005F26  2720 G$AX5043_0xF26NB$0$0 == 0x5f26
                           005F26  2721 _AX5043_0xF26NB	=	0x5f26
                           005F30  2722 G$AX5043_0xF30NB$0$0 == 0x5f30
                           005F30  2723 _AX5043_0xF30NB	=	0x5f30
                           005F31  2724 G$AX5043_0xF31NB$0$0 == 0x5f31
                           005F31  2725 _AX5043_0xF31NB	=	0x5f31
                           005F32  2726 G$AX5043_0xF32NB$0$0 == 0x5f32
                           005F32  2727 _AX5043_0xF32NB	=	0x5f32
                           005F33  2728 G$AX5043_0xF33NB$0$0 == 0x5f33
                           005F33  2729 _AX5043_0xF33NB	=	0x5f33
                           005F34  2730 G$AX5043_0xF34NB$0$0 == 0x5f34
                           005F34  2731 _AX5043_0xF34NB	=	0x5f34
                           005F35  2732 G$AX5043_0xF35NB$0$0 == 0x5f35
                           005F35  2733 _AX5043_0xF35NB	=	0x5f35
                           005F44  2734 G$AX5043_0xF44NB$0$0 == 0x5f44
                           005F44  2735 _AX5043_0xF44NB	=	0x5f44
                           005122  2736 G$AX5043_AGCAHYST0NB$0$0 == 0x5122
                           005122  2737 _AX5043_AGCAHYST0NB	=	0x5122
                           005132  2738 G$AX5043_AGCAHYST1NB$0$0 == 0x5132
                           005132  2739 _AX5043_AGCAHYST1NB	=	0x5132
                           005142  2740 G$AX5043_AGCAHYST2NB$0$0 == 0x5142
                           005142  2741 _AX5043_AGCAHYST2NB	=	0x5142
                           005152  2742 G$AX5043_AGCAHYST3NB$0$0 == 0x5152
                           005152  2743 _AX5043_AGCAHYST3NB	=	0x5152
                           005120  2744 G$AX5043_AGCGAIN0NB$0$0 == 0x5120
                           005120  2745 _AX5043_AGCGAIN0NB	=	0x5120
                           005130  2746 G$AX5043_AGCGAIN1NB$0$0 == 0x5130
                           005130  2747 _AX5043_AGCGAIN1NB	=	0x5130
                           005140  2748 G$AX5043_AGCGAIN2NB$0$0 == 0x5140
                           005140  2749 _AX5043_AGCGAIN2NB	=	0x5140
                           005150  2750 G$AX5043_AGCGAIN3NB$0$0 == 0x5150
                           005150  2751 _AX5043_AGCGAIN3NB	=	0x5150
                           005123  2752 G$AX5043_AGCMINMAX0NB$0$0 == 0x5123
                           005123  2753 _AX5043_AGCMINMAX0NB	=	0x5123
                           005133  2754 G$AX5043_AGCMINMAX1NB$0$0 == 0x5133
                           005133  2755 _AX5043_AGCMINMAX1NB	=	0x5133
                           005143  2756 G$AX5043_AGCMINMAX2NB$0$0 == 0x5143
                           005143  2757 _AX5043_AGCMINMAX2NB	=	0x5143
                           005153  2758 G$AX5043_AGCMINMAX3NB$0$0 == 0x5153
                           005153  2759 _AX5043_AGCMINMAX3NB	=	0x5153
                           005121  2760 G$AX5043_AGCTARGET0NB$0$0 == 0x5121
                           005121  2761 _AX5043_AGCTARGET0NB	=	0x5121
                           005131  2762 G$AX5043_AGCTARGET1NB$0$0 == 0x5131
                           005131  2763 _AX5043_AGCTARGET1NB	=	0x5131
                           005141  2764 G$AX5043_AGCTARGET2NB$0$0 == 0x5141
                           005141  2765 _AX5043_AGCTARGET2NB	=	0x5141
                           005151  2766 G$AX5043_AGCTARGET3NB$0$0 == 0x5151
                           005151  2767 _AX5043_AGCTARGET3NB	=	0x5151
                           00512B  2768 G$AX5043_AMPLITUDEGAIN0NB$0$0 == 0x512b
                           00512B  2769 _AX5043_AMPLITUDEGAIN0NB	=	0x512b
                           00513B  2770 G$AX5043_AMPLITUDEGAIN1NB$0$0 == 0x513b
                           00513B  2771 _AX5043_AMPLITUDEGAIN1NB	=	0x513b
                           00514B  2772 G$AX5043_AMPLITUDEGAIN2NB$0$0 == 0x514b
                           00514B  2773 _AX5043_AMPLITUDEGAIN2NB	=	0x514b
                           00515B  2774 G$AX5043_AMPLITUDEGAIN3NB$0$0 == 0x515b
                           00515B  2775 _AX5043_AMPLITUDEGAIN3NB	=	0x515b
                           00512F  2776 G$AX5043_BBOFFSRES0NB$0$0 == 0x512f
                           00512F  2777 _AX5043_BBOFFSRES0NB	=	0x512f
                           00513F  2778 G$AX5043_BBOFFSRES1NB$0$0 == 0x513f
                           00513F  2779 _AX5043_BBOFFSRES1NB	=	0x513f
                           00514F  2780 G$AX5043_BBOFFSRES2NB$0$0 == 0x514f
                           00514F  2781 _AX5043_BBOFFSRES2NB	=	0x514f
                           00515F  2782 G$AX5043_BBOFFSRES3NB$0$0 == 0x515f
                           00515F  2783 _AX5043_BBOFFSRES3NB	=	0x515f
                           005125  2784 G$AX5043_DRGAIN0NB$0$0 == 0x5125
                           005125  2785 _AX5043_DRGAIN0NB	=	0x5125
                           005135  2786 G$AX5043_DRGAIN1NB$0$0 == 0x5135
                           005135  2787 _AX5043_DRGAIN1NB	=	0x5135
                           005145  2788 G$AX5043_DRGAIN2NB$0$0 == 0x5145
                           005145  2789 _AX5043_DRGAIN2NB	=	0x5145
                           005155  2790 G$AX5043_DRGAIN3NB$0$0 == 0x5155
                           005155  2791 _AX5043_DRGAIN3NB	=	0x5155
                           00512E  2792 G$AX5043_FOURFSK0NB$0$0 == 0x512e
                           00512E  2793 _AX5043_FOURFSK0NB	=	0x512e
                           00513E  2794 G$AX5043_FOURFSK1NB$0$0 == 0x513e
                           00513E  2795 _AX5043_FOURFSK1NB	=	0x513e
                           00514E  2796 G$AX5043_FOURFSK2NB$0$0 == 0x514e
                           00514E  2797 _AX5043_FOURFSK2NB	=	0x514e
                           00515E  2798 G$AX5043_FOURFSK3NB$0$0 == 0x515e
                           00515E  2799 _AX5043_FOURFSK3NB	=	0x515e
                           00512D  2800 G$AX5043_FREQDEV00NB$0$0 == 0x512d
                           00512D  2801 _AX5043_FREQDEV00NB	=	0x512d
                           00513D  2802 G$AX5043_FREQDEV01NB$0$0 == 0x513d
                           00513D  2803 _AX5043_FREQDEV01NB	=	0x513d
                           00514D  2804 G$AX5043_FREQDEV02NB$0$0 == 0x514d
                           00514D  2805 _AX5043_FREQDEV02NB	=	0x514d
                           00515D  2806 G$AX5043_FREQDEV03NB$0$0 == 0x515d
                           00515D  2807 _AX5043_FREQDEV03NB	=	0x515d
                           00512C  2808 G$AX5043_FREQDEV10NB$0$0 == 0x512c
                           00512C  2809 _AX5043_FREQDEV10NB	=	0x512c
                           00513C  2810 G$AX5043_FREQDEV11NB$0$0 == 0x513c
                           00513C  2811 _AX5043_FREQDEV11NB	=	0x513c
                           00514C  2812 G$AX5043_FREQDEV12NB$0$0 == 0x514c
                           00514C  2813 _AX5043_FREQDEV12NB	=	0x514c
                           00515C  2814 G$AX5043_FREQDEV13NB$0$0 == 0x515c
                           00515C  2815 _AX5043_FREQDEV13NB	=	0x515c
                           005127  2816 G$AX5043_FREQUENCYGAINA0NB$0$0 == 0x5127
                           005127  2817 _AX5043_FREQUENCYGAINA0NB	=	0x5127
                           005137  2818 G$AX5043_FREQUENCYGAINA1NB$0$0 == 0x5137
                           005137  2819 _AX5043_FREQUENCYGAINA1NB	=	0x5137
                           005147  2820 G$AX5043_FREQUENCYGAINA2NB$0$0 == 0x5147
                           005147  2821 _AX5043_FREQUENCYGAINA2NB	=	0x5147
                           005157  2822 G$AX5043_FREQUENCYGAINA3NB$0$0 == 0x5157
                           005157  2823 _AX5043_FREQUENCYGAINA3NB	=	0x5157
                           005128  2824 G$AX5043_FREQUENCYGAINB0NB$0$0 == 0x5128
                           005128  2825 _AX5043_FREQUENCYGAINB0NB	=	0x5128
                           005138  2826 G$AX5043_FREQUENCYGAINB1NB$0$0 == 0x5138
                           005138  2827 _AX5043_FREQUENCYGAINB1NB	=	0x5138
                           005148  2828 G$AX5043_FREQUENCYGAINB2NB$0$0 == 0x5148
                           005148  2829 _AX5043_FREQUENCYGAINB2NB	=	0x5148
                           005158  2830 G$AX5043_FREQUENCYGAINB3NB$0$0 == 0x5158
                           005158  2831 _AX5043_FREQUENCYGAINB3NB	=	0x5158
                           005129  2832 G$AX5043_FREQUENCYGAINC0NB$0$0 == 0x5129
                           005129  2833 _AX5043_FREQUENCYGAINC0NB	=	0x5129
                           005139  2834 G$AX5043_FREQUENCYGAINC1NB$0$0 == 0x5139
                           005139  2835 _AX5043_FREQUENCYGAINC1NB	=	0x5139
                           005149  2836 G$AX5043_FREQUENCYGAINC2NB$0$0 == 0x5149
                           005149  2837 _AX5043_FREQUENCYGAINC2NB	=	0x5149
                           005159  2838 G$AX5043_FREQUENCYGAINC3NB$0$0 == 0x5159
                           005159  2839 _AX5043_FREQUENCYGAINC3NB	=	0x5159
                           00512A  2840 G$AX5043_FREQUENCYGAIND0NB$0$0 == 0x512a
                           00512A  2841 _AX5043_FREQUENCYGAIND0NB	=	0x512a
                           00513A  2842 G$AX5043_FREQUENCYGAIND1NB$0$0 == 0x513a
                           00513A  2843 _AX5043_FREQUENCYGAIND1NB	=	0x513a
                           00514A  2844 G$AX5043_FREQUENCYGAIND2NB$0$0 == 0x514a
                           00514A  2845 _AX5043_FREQUENCYGAIND2NB	=	0x514a
                           00515A  2846 G$AX5043_FREQUENCYGAIND3NB$0$0 == 0x515a
                           00515A  2847 _AX5043_FREQUENCYGAIND3NB	=	0x515a
                           005116  2848 G$AX5043_FREQUENCYLEAKNB$0$0 == 0x5116
                           005116  2849 _AX5043_FREQUENCYLEAKNB	=	0x5116
                           005126  2850 G$AX5043_PHASEGAIN0NB$0$0 == 0x5126
                           005126  2851 _AX5043_PHASEGAIN0NB	=	0x5126
                           005136  2852 G$AX5043_PHASEGAIN1NB$0$0 == 0x5136
                           005136  2853 _AX5043_PHASEGAIN1NB	=	0x5136
                           005146  2854 G$AX5043_PHASEGAIN2NB$0$0 == 0x5146
                           005146  2855 _AX5043_PHASEGAIN2NB	=	0x5146
                           005156  2856 G$AX5043_PHASEGAIN3NB$0$0 == 0x5156
                           005156  2857 _AX5043_PHASEGAIN3NB	=	0x5156
                           005207  2858 G$AX5043_PKTADDR0NB$0$0 == 0x5207
                           005207  2859 _AX5043_PKTADDR0NB	=	0x5207
                           005206  2860 G$AX5043_PKTADDR1NB$0$0 == 0x5206
                           005206  2861 _AX5043_PKTADDR1NB	=	0x5206
                           005205  2862 G$AX5043_PKTADDR2NB$0$0 == 0x5205
                           005205  2863 _AX5043_PKTADDR2NB	=	0x5205
                           005204  2864 G$AX5043_PKTADDR3NB$0$0 == 0x5204
                           005204  2865 _AX5043_PKTADDR3NB	=	0x5204
                           005200  2866 G$AX5043_PKTADDRCFGNB$0$0 == 0x5200
                           005200  2867 _AX5043_PKTADDRCFGNB	=	0x5200
                           00520B  2868 G$AX5043_PKTADDRMASK0NB$0$0 == 0x520b
                           00520B  2869 _AX5043_PKTADDRMASK0NB	=	0x520b
                           00520A  2870 G$AX5043_PKTADDRMASK1NB$0$0 == 0x520a
                           00520A  2871 _AX5043_PKTADDRMASK1NB	=	0x520a
                           005209  2872 G$AX5043_PKTADDRMASK2NB$0$0 == 0x5209
                           005209  2873 _AX5043_PKTADDRMASK2NB	=	0x5209
                           005208  2874 G$AX5043_PKTADDRMASK3NB$0$0 == 0x5208
                           005208  2875 _AX5043_PKTADDRMASK3NB	=	0x5208
                           005201  2876 G$AX5043_PKTLENCFGNB$0$0 == 0x5201
                           005201  2877 _AX5043_PKTLENCFGNB	=	0x5201
                           005202  2878 G$AX5043_PKTLENOFFSETNB$0$0 == 0x5202
                           005202  2879 _AX5043_PKTLENOFFSETNB	=	0x5202
                           005203  2880 G$AX5043_PKTMAXLENNB$0$0 == 0x5203
                           005203  2881 _AX5043_PKTMAXLENNB	=	0x5203
                           005118  2882 G$AX5043_RXPARAMCURSETNB$0$0 == 0x5118
                           005118  2883 _AX5043_RXPARAMCURSETNB	=	0x5118
                           005117  2884 G$AX5043_RXPARAMSETSNB$0$0 == 0x5117
                           005117  2885 _AX5043_RXPARAMSETSNB	=	0x5117
                           005124  2886 G$AX5043_TIMEGAIN0NB$0$0 == 0x5124
                           005124  2887 _AX5043_TIMEGAIN0NB	=	0x5124
                           005134  2888 G$AX5043_TIMEGAIN1NB$0$0 == 0x5134
                           005134  2889 _AX5043_TIMEGAIN1NB	=	0x5134
                           005144  2890 G$AX5043_TIMEGAIN2NB$0$0 == 0x5144
                           005144  2891 _AX5043_TIMEGAIN2NB	=	0x5144
                           005154  2892 G$AX5043_TIMEGAIN3NB$0$0 == 0x5154
                           005154  2893 _AX5043_TIMEGAIN3NB	=	0x5154
                           000000  2894 G$axradio_phy_chanpllrng$0$0==.
      000001                       2895 _axradio_phy_chanpllrng::
      000001                       2896 	.ds 12
                           00000C  2897 G$axradio_phy_chanvcoi$0$0==.
      00000D                       2898 _axradio_phy_chanvcoi::
      00000D                       2899 	.ds 6
                                   2900 ;--------------------------------------------------------
                                   2901 ; absolute external ram data
                                   2902 ;--------------------------------------------------------
                                   2903 	.area XABS    (ABS,XDATA)
                                   2904 ;--------------------------------------------------------
                                   2905 ; external initialized ram data
                                   2906 ;--------------------------------------------------------
                                   2907 	.area XISEG   (XDATA)
                                   2908 	.area HOME    (CODE)
                                   2909 	.area GSINIT0 (CODE)
                                   2910 	.area GSINIT1 (CODE)
                                   2911 	.area GSINIT2 (CODE)
                                   2912 	.area GSINIT3 (CODE)
                                   2913 	.area GSINIT4 (CODE)
                                   2914 	.area GSINIT5 (CODE)
                                   2915 	.area GSINIT  (CODE)
                                   2916 	.area GSFINAL (CODE)
                                   2917 	.area CSEG    (CODE)
                                   2918 ;--------------------------------------------------------
                                   2919 ; global & static initialisations
                                   2920 ;--------------------------------------------------------
                                   2921 	.area HOME    (CODE)
                                   2922 	.area GSINIT  (CODE)
                                   2923 	.area GSFINAL (CODE)
                                   2924 	.area GSINIT  (CODE)
                                   2925 ;--------------------------------------------------------
                                   2926 ; Home
                                   2927 ;--------------------------------------------------------
                                   2928 	.area HOME    (CODE)
                                   2929 	.area HOME    (CODE)
                                   2930 ;--------------------------------------------------------
                                   2931 ; code
                                   2932 ;--------------------------------------------------------
                                   2933 	.area CSEG    (CODE)
                                   2934 ;------------------------------------------------------------
                                   2935 ;Allocation info for local variables in function 'ax5043_set_registers'
                                   2936 ;------------------------------------------------------------
                           000000  2937 	G$ax5043_set_registers$0$0 ==.
                           000000  2938 	C$config.c$12$0$0 ==.
                                   2939 ;	..\AX_Radio_Lab_output\config.c:12: __reentrantb void ax5043_set_registers(void) __reentrant
                                   2940 ;	-----------------------------------------
                                   2941 ;	 function ax5043_set_registers
                                   2942 ;	-----------------------------------------
      000398                       2943 _ax5043_set_registers:
                           000007  2944 	ar7 = 0x07
                           000006  2945 	ar6 = 0x06
                           000005  2946 	ar5 = 0x05
                           000004  2947 	ar4 = 0x04
                           000003  2948 	ar3 = 0x03
                           000002  2949 	ar2 = 0x02
                           000001  2950 	ar1 = 0x01
                           000000  2951 	ar0 = 0x00
                           000000  2952 	C$config.c$14$2$171 ==.
                                   2953 ;	..\AX_Radio_Lab_output\config.c:14: radio_write8(AX5043_REG_MODULATION     ,                              			0x08);
      000398 90 40 10         [24] 2954 	mov	dptr,#0x4010
      00039B 74 08            [12] 2955 	mov	a,#0x08
      00039D F0               [24] 2956 	movx	@dptr,a
                           000006  2957 	C$config.c$15$2$172 ==.
                                   2958 ;	..\AX_Radio_Lab_output\config.c:15: radio_write8(AX5043_REG_ENCODING       ,                              			0x00);
      00039E 90 40 11         [24] 2959 	mov	dptr,#0x4011
      0003A1 E4               [12] 2960 	clr	a
      0003A2 F0               [24] 2961 	movx	@dptr,a
                           00000B  2962 	C$config.c$16$2$173 ==.
                                   2963 ;	..\AX_Radio_Lab_output\config.c:16: radio_write8(AX5043_REG_FRAMING        ,                              			0x06);
      0003A3 90 40 12         [24] 2964 	mov	dptr,#0x4012
      0003A6 74 06            [12] 2965 	mov	a,#0x06
      0003A8 F0               [24] 2966 	movx	@dptr,a
                           000011  2967 	C$config.c$17$2$174 ==.
                                   2968 ;	..\AX_Radio_Lab_output\config.c:17: radio_write8(AX5043_REG_PINFUNCSYSCLK  ,                              			0x01);
      0003A9 90 40 21         [24] 2969 	mov	dptr,#0x4021
      0003AC 74 01            [12] 2970 	mov	a,#0x01
      0003AE F0               [24] 2971 	movx	@dptr,a
                           000017  2972 	C$config.c$18$2$175 ==.
                                   2973 ;	..\AX_Radio_Lab_output\config.c:18: radio_write8(AX5043_REG_PINFUNCDCLK    ,                              			0x01);
      0003AF 90 40 22         [24] 2974 	mov	dptr,#0x4022
      0003B2 F0               [24] 2975 	movx	@dptr,a
                           00001B  2976 	C$config.c$19$2$176 ==.
                                   2977 ;	..\AX_Radio_Lab_output\config.c:19: radio_write8(AX5043_REG_PINFUNCDATA    ,                              			0x01);
      0003B3 90 40 23         [24] 2978 	mov	dptr,#0x4023
      0003B6 F0               [24] 2979 	movx	@dptr,a
                           00001F  2980 	C$config.c$20$2$177 ==.
                                   2981 ;	..\AX_Radio_Lab_output\config.c:20: radio_write8(AX5043_REG_PINFUNCANTSEL  ,                              			0x82);
      0003B7 90 40 25         [24] 2982 	mov	dptr,#0x4025
      0003BA 74 82            [12] 2983 	mov	a,#0x82
      0003BC F0               [24] 2984 	movx	@dptr,a
                           000025  2985 	C$config.c$21$2$178 ==.
                                   2986 ;	..\AX_Radio_Lab_output\config.c:21: radio_write8(AX5043_REG_PINFUNCPWRAMP  ,                              			0x82);
      0003BD 90 40 26         [24] 2987 	mov	dptr,#0x4026
      0003C0 F0               [24] 2988 	movx	@dptr,a
                           000029  2989 	C$config.c$22$2$179 ==.
                                   2990 ;	..\AX_Radio_Lab_output\config.c:22: radio_write8(AX5043_REG_WAKEUPXOEARLY  ,                              			0x01);
      0003C1 90 40 6E         [24] 2991 	mov	dptr,#0x406e
      0003C4 74 01            [12] 2992 	mov	a,#0x01
      0003C6 F0               [24] 2993 	movx	@dptr,a
                           00002F  2994 	C$config.c$23$2$180 ==.
                                   2995 ;	..\AX_Radio_Lab_output\config.c:23: radio_write8(AX5043_REG_IFFREQ1        ,                              			0x01);
      0003C7 90 41 00         [24] 2996 	mov	dptr,#0x4100
      0003CA F0               [24] 2997 	movx	@dptr,a
                           000033  2998 	C$config.c$24$2$181 ==.
                                   2999 ;	..\AX_Radio_Lab_output\config.c:24: radio_write8(AX5043_REG_IFFREQ0        ,                              			0xE4);
      0003CB 90 41 01         [24] 3000 	mov	dptr,#0x4101
      0003CE 74 E4            [12] 3001 	mov	a,#0xe4
      0003D0 F0               [24] 3002 	movx	@dptr,a
                           000039  3003 	C$config.c$25$2$182 ==.
                                   3004 ;	..\AX_Radio_Lab_output\config.c:25: radio_write8(AX5043_REG_DECIMATION     ,                              			0x16);
      0003D1 90 41 02         [24] 3005 	mov	dptr,#0x4102
      0003D4 74 16            [12] 3006 	mov	a,#0x16
      0003D6 F0               [24] 3007 	movx	@dptr,a
                           00003F  3008 	C$config.c$26$2$183 ==.
                                   3009 ;	..\AX_Radio_Lab_output\config.c:26: radio_write8(AX5043_REG_RXDATARATE2    ,                              			0x00);
      0003D7 90 41 03         [24] 3010 	mov	dptr,#0x4103
      0003DA E4               [12] 3011 	clr	a
      0003DB F0               [24] 3012 	movx	@dptr,a
                           000044  3013 	C$config.c$27$2$184 ==.
                                   3014 ;	..\AX_Radio_Lab_output\config.c:27: radio_write8(AX5043_REG_RXDATARATE1    ,                              			0x3D);
      0003DC 90 41 04         [24] 3015 	mov	dptr,#0x4104
      0003DF 74 3D            [12] 3016 	mov	a,#0x3d
      0003E1 F0               [24] 3017 	movx	@dptr,a
                           00004A  3018 	C$config.c$28$2$185 ==.
                                   3019 ;	..\AX_Radio_Lab_output\config.c:28: radio_write8(AX5043_REG_RXDATARATE0    ,                              			0x8D);
      0003E2 90 41 05         [24] 3020 	mov	dptr,#0x4105
      0003E5 74 8D            [12] 3021 	mov	a,#0x8d
      0003E7 F0               [24] 3022 	movx	@dptr,a
                           000050  3023 	C$config.c$29$2$186 ==.
                                   3024 ;	..\AX_Radio_Lab_output\config.c:29: radio_write8(AX5043_REG_MAXDROFFSET2   ,                              			0x00);
      0003E8 90 41 06         [24] 3025 	mov	dptr,#0x4106
      0003EB E4               [12] 3026 	clr	a
      0003EC F0               [24] 3027 	movx	@dptr,a
                           000055  3028 	C$config.c$30$2$187 ==.
                                   3029 ;	..\AX_Radio_Lab_output\config.c:30: radio_write8(AX5043_REG_MAXDROFFSET1   ,                              			0x00);
      0003ED 90 41 07         [24] 3030 	mov	dptr,#0x4107
      0003F0 F0               [24] 3031 	movx	@dptr,a
                           000059  3032 	C$config.c$31$2$188 ==.
                                   3033 ;	..\AX_Radio_Lab_output\config.c:31: radio_write8(AX5043_REG_MAXDROFFSET0   ,                              			0x00);
      0003F1 90 41 08         [24] 3034 	mov	dptr,#0x4108
      0003F4 F0               [24] 3035 	movx	@dptr,a
                           00005D  3036 	C$config.c$32$2$189 ==.
                                   3037 ;	..\AX_Radio_Lab_output\config.c:32: radio_write8(AX5043_REG_MAXRFOFFSET2   ,                              			0x80);
      0003F5 90 41 09         [24] 3038 	mov	dptr,#0x4109
      0003F8 74 80            [12] 3039 	mov	a,#0x80
      0003FA F0               [24] 3040 	movx	@dptr,a
                           000063  3041 	C$config.c$33$2$190 ==.
                                   3042 ;	..\AX_Radio_Lab_output\config.c:33: radio_write8(AX5043_REG_MAXRFOFFSET1   ,                              			0x04);
      0003FB 90 41 0A         [24] 3043 	mov	dptr,#0x410a
      0003FE 74 04            [12] 3044 	mov	a,#0x04
      000400 F0               [24] 3045 	movx	@dptr,a
                           000069  3046 	C$config.c$34$2$191 ==.
                                   3047 ;	..\AX_Radio_Lab_output\config.c:34: radio_write8(AX5043_REG_MAXRFOFFSET0   ,                              			0x61);
      000401 90 41 0B         [24] 3048 	mov	dptr,#0x410b
      000404 74 61            [12] 3049 	mov	a,#0x61
      000406 F0               [24] 3050 	movx	@dptr,a
                           00006F  3051 	C$config.c$35$2$192 ==.
                                   3052 ;	..\AX_Radio_Lab_output\config.c:35: radio_write8(AX5043_REG_FSKDMAX1       ,                              			0x00);
      000407 90 41 0C         [24] 3053 	mov	dptr,#0x410c
      00040A E4               [12] 3054 	clr	a
      00040B F0               [24] 3055 	movx	@dptr,a
                           000074  3056 	C$config.c$36$2$193 ==.
                                   3057 ;	..\AX_Radio_Lab_output\config.c:36: radio_write8(AX5043_REG_FSKDMAX0       ,                              			0xA6);
      00040C 90 41 0D         [24] 3058 	mov	dptr,#0x410d
      00040F 74 A6            [12] 3059 	mov	a,#0xa6
      000411 F0               [24] 3060 	movx	@dptr,a
                           00007A  3061 	C$config.c$37$2$194 ==.
                                   3062 ;	..\AX_Radio_Lab_output\config.c:37: radio_write8(AX5043_REG_FSKDMIN1       ,                              			0xFF);
      000412 90 41 0E         [24] 3063 	mov	dptr,#0x410e
      000415 74 FF            [12] 3064 	mov	a,#0xff
      000417 F0               [24] 3065 	movx	@dptr,a
                           000080  3066 	C$config.c$38$2$195 ==.
                                   3067 ;	..\AX_Radio_Lab_output\config.c:38: radio_write8(AX5043_REG_FSKDMIN0       ,                              			0x5A);
      000418 90 41 0F         [24] 3068 	mov	dptr,#0x410f
      00041B 74 5A            [12] 3069 	mov	a,#0x5a
      00041D F0               [24] 3070 	movx	@dptr,a
                           000086  3071 	C$config.c$39$2$196 ==.
                                   3072 ;	..\AX_Radio_Lab_output\config.c:39: radio_write8(AX5043_REG_AMPLFILTER     ,                              			0x00);
      00041E 90 41 15         [24] 3073 	mov	dptr,#0x4115
      000421 E4               [12] 3074 	clr	a
      000422 F0               [24] 3075 	movx	@dptr,a
                           00008B  3076 	C$config.c$40$2$197 ==.
                                   3077 ;	..\AX_Radio_Lab_output\config.c:40: radio_write8(AX5043_REG_RXPARAMSETS    ,                              			0xF4);
      000423 90 41 17         [24] 3078 	mov	dptr,#0x4117
      000426 74 F4            [12] 3079 	mov	a,#0xf4
      000428 F0               [24] 3080 	movx	@dptr,a
                           000091  3081 	C$config.c$41$2$198 ==.
                                   3082 ;	..\AX_Radio_Lab_output\config.c:41: radio_write8(AX5043_REG_AGCGAIN0       ,                              			0xC5);
      000429 90 41 20         [24] 3083 	mov	dptr,#0x4120
      00042C 74 C5            [12] 3084 	mov	a,#0xc5
      00042E F0               [24] 3085 	movx	@dptr,a
                           000097  3086 	C$config.c$42$2$199 ==.
                                   3087 ;	..\AX_Radio_Lab_output\config.c:42: radio_write8(AX5043_REG_AGCTARGET0     ,                              			0x84);
      00042F 90 41 21         [24] 3088 	mov	dptr,#0x4121
      000432 74 84            [12] 3089 	mov	a,#0x84
      000434 F0               [24] 3090 	movx	@dptr,a
                           00009D  3091 	C$config.c$43$2$200 ==.
                                   3092 ;	..\AX_Radio_Lab_output\config.c:43: radio_write8(AX5043_REG_TIMEGAIN0      ,                              			0xF8);
      000435 90 41 24         [24] 3093 	mov	dptr,#0x4124
      000438 74 F8            [12] 3094 	mov	a,#0xf8
      00043A F0               [24] 3095 	movx	@dptr,a
                           0000A3  3096 	C$config.c$44$2$201 ==.
                                   3097 ;	..\AX_Radio_Lab_output\config.c:44: radio_write8(AX5043_REG_DRGAIN0        ,                              			0xF2);
      00043B 90 41 25         [24] 3098 	mov	dptr,#0x4125
      00043E 74 F2            [12] 3099 	mov	a,#0xf2
      000440 F0               [24] 3100 	movx	@dptr,a
                           0000A9  3101 	C$config.c$45$2$202 ==.
                                   3102 ;	..\AX_Radio_Lab_output\config.c:45: radio_write8(AX5043_REG_PHASEGAIN0     ,                              			0xC3);
      000441 90 41 26         [24] 3103 	mov	dptr,#0x4126
      000444 74 C3            [12] 3104 	mov	a,#0xc3
      000446 F0               [24] 3105 	movx	@dptr,a
                           0000AF  3106 	C$config.c$46$2$203 ==.
                                   3107 ;	..\AX_Radio_Lab_output\config.c:46: radio_write8(AX5043_REG_FREQUENCYGAINA0,                              			0x0F);
      000447 90 41 27         [24] 3108 	mov	dptr,#0x4127
      00044A 74 0F            [12] 3109 	mov	a,#0x0f
      00044C F0               [24] 3110 	movx	@dptr,a
                           0000B5  3111 	C$config.c$47$2$204 ==.
                                   3112 ;	..\AX_Radio_Lab_output\config.c:47: radio_write8(AX5043_REG_FREQUENCYGAINB0,                              			0x1F);
      00044D 90 41 28         [24] 3113 	mov	dptr,#0x4128
      000450 74 1F            [12] 3114 	mov	a,#0x1f
      000452 F0               [24] 3115 	movx	@dptr,a
                           0000BB  3116 	C$config.c$48$2$205 ==.
                                   3117 ;	..\AX_Radio_Lab_output\config.c:48: radio_write8(AX5043_REG_FREQUENCYGAINC0,                              			0x08);
      000453 90 41 29         [24] 3118 	mov	dptr,#0x4129
      000456 74 08            [12] 3119 	mov	a,#0x08
      000458 F0               [24] 3120 	movx	@dptr,a
                           0000C1  3121 	C$config.c$49$2$206 ==.
                                   3122 ;	..\AX_Radio_Lab_output\config.c:49: radio_write8(AX5043_REG_FREQUENCYGAIND0,                              			0x08);
      000459 90 41 2A         [24] 3123 	mov	dptr,#0x412a
      00045C F0               [24] 3124 	movx	@dptr,a
                           0000C5  3125 	C$config.c$50$2$207 ==.
                                   3126 ;	..\AX_Radio_Lab_output\config.c:50: radio_write8(AX5043_REG_AMPLITUDEGAIN0 ,                              			0x06);
      00045D 90 41 2B         [24] 3127 	mov	dptr,#0x412b
      000460 74 06            [12] 3128 	mov	a,#0x06
      000462 F0               [24] 3129 	movx	@dptr,a
                           0000CB  3130 	C$config.c$51$2$208 ==.
                                   3131 ;	..\AX_Radio_Lab_output\config.c:51: radio_write8(AX5043_REG_FREQDEV10      ,                              			0x00);
      000463 90 41 2C         [24] 3132 	mov	dptr,#0x412c
      000466 E4               [12] 3133 	clr	a
      000467 F0               [24] 3134 	movx	@dptr,a
                           0000D0  3135 	C$config.c$52$2$209 ==.
                                   3136 ;	..\AX_Radio_Lab_output\config.c:52: radio_write8(AX5043_REG_FREQDEV00      ,                              			0x00);
      000468 90 41 2D         [24] 3137 	mov	dptr,#0x412d
      00046B F0               [24] 3138 	movx	@dptr,a
                           0000D4  3139 	C$config.c$53$2$210 ==.
                                   3140 ;	..\AX_Radio_Lab_output\config.c:53: radio_write8(AX5043_REG_BBOFFSRES0     ,                              			0x00);
      00046C 90 41 2F         [24] 3141 	mov	dptr,#0x412f
      00046F F0               [24] 3142 	movx	@dptr,a
                           0000D8  3143 	C$config.c$54$2$211 ==.
                                   3144 ;	..\AX_Radio_Lab_output\config.c:54: radio_write8(AX5043_REG_AGCGAIN1       ,                              			0xC5);
      000470 90 41 30         [24] 3145 	mov	dptr,#0x4130
      000473 74 C5            [12] 3146 	mov	a,#0xc5
      000475 F0               [24] 3147 	movx	@dptr,a
                           0000DE  3148 	C$config.c$55$2$212 ==.
                                   3149 ;	..\AX_Radio_Lab_output\config.c:55: radio_write8(AX5043_REG_AGCTARGET1     ,                              			0x84);
      000476 90 41 31         [24] 3150 	mov	dptr,#0x4131
      000479 74 84            [12] 3151 	mov	a,#0x84
      00047B F0               [24] 3152 	movx	@dptr,a
                           0000E4  3153 	C$config.c$56$2$213 ==.
                                   3154 ;	..\AX_Radio_Lab_output\config.c:56: radio_write8(AX5043_REG_AGCAHYST1      ,                              			0x00);
      00047C 90 41 32         [24] 3155 	mov	dptr,#0x4132
      00047F E4               [12] 3156 	clr	a
      000480 F0               [24] 3157 	movx	@dptr,a
                           0000E9  3158 	C$config.c$57$2$214 ==.
                                   3159 ;	..\AX_Radio_Lab_output\config.c:57: radio_write8(AX5043_REG_AGCMINMAX1     ,                              			0x00);
      000481 90 41 33         [24] 3160 	mov	dptr,#0x4133
      000484 F0               [24] 3161 	movx	@dptr,a
                           0000ED  3162 	C$config.c$58$2$215 ==.
                                   3163 ;	..\AX_Radio_Lab_output\config.c:58: radio_write8(AX5043_REG_TIMEGAIN1      ,                              			0xF6);
      000485 90 41 34         [24] 3164 	mov	dptr,#0x4134
      000488 74 F6            [12] 3165 	mov	a,#0xf6
      00048A F0               [24] 3166 	movx	@dptr,a
                           0000F3  3167 	C$config.c$59$2$216 ==.
                                   3168 ;	..\AX_Radio_Lab_output\config.c:59: radio_write8(AX5043_REG_DRGAIN1        ,                              			0xF1);
      00048B 90 41 35         [24] 3169 	mov	dptr,#0x4135
      00048E 74 F1            [12] 3170 	mov	a,#0xf1
      000490 F0               [24] 3171 	movx	@dptr,a
                           0000F9  3172 	C$config.c$60$2$217 ==.
                                   3173 ;	..\AX_Radio_Lab_output\config.c:60: radio_write8(AX5043_REG_PHASEGAIN1     ,                              			0xC3);
      000491 90 41 36         [24] 3174 	mov	dptr,#0x4136
      000494 74 C3            [12] 3175 	mov	a,#0xc3
      000496 F0               [24] 3176 	movx	@dptr,a
                           0000FF  3177 	C$config.c$61$2$218 ==.
                                   3178 ;	..\AX_Radio_Lab_output\config.c:61: radio_write8(AX5043_REG_FREQUENCYGAINA1,                              			0x0F);
      000497 90 41 37         [24] 3179 	mov	dptr,#0x4137
      00049A 74 0F            [12] 3180 	mov	a,#0x0f
      00049C F0               [24] 3181 	movx	@dptr,a
                           000105  3182 	C$config.c$62$2$219 ==.
                                   3183 ;	..\AX_Radio_Lab_output\config.c:62: radio_write8(AX5043_REG_FREQUENCYGAINB1,                              			0x1F);
      00049D 90 41 38         [24] 3184 	mov	dptr,#0x4138
      0004A0 74 1F            [12] 3185 	mov	a,#0x1f
      0004A2 F0               [24] 3186 	movx	@dptr,a
                           00010B  3187 	C$config.c$63$2$220 ==.
                                   3188 ;	..\AX_Radio_Lab_output\config.c:63: radio_write8(AX5043_REG_FREQUENCYGAINC1,                              			0x08);
      0004A3 90 41 39         [24] 3189 	mov	dptr,#0x4139
      0004A6 74 08            [12] 3190 	mov	a,#0x08
      0004A8 F0               [24] 3191 	movx	@dptr,a
                           000111  3192 	C$config.c$64$2$221 ==.
                                   3193 ;	..\AX_Radio_Lab_output\config.c:64: radio_write8(AX5043_REG_FREQUENCYGAIND1,                              			0x08);
      0004A9 90 41 3A         [24] 3194 	mov	dptr,#0x413a
      0004AC F0               [24] 3195 	movx	@dptr,a
                           000115  3196 	C$config.c$65$2$222 ==.
                                   3197 ;	..\AX_Radio_Lab_output\config.c:65: radio_write8(AX5043_REG_AMPLITUDEGAIN1 ,                              			0x06);
      0004AD 90 41 3B         [24] 3198 	mov	dptr,#0x413b
      0004B0 74 06            [12] 3199 	mov	a,#0x06
      0004B2 F0               [24] 3200 	movx	@dptr,a
                           00011B  3201 	C$config.c$66$2$223 ==.
                                   3202 ;	..\AX_Radio_Lab_output\config.c:66: radio_write8(AX5043_REG_FREQDEV11      ,                              			0x00);
      0004B3 90 41 3C         [24] 3203 	mov	dptr,#0x413c
      0004B6 E4               [12] 3204 	clr	a
      0004B7 F0               [24] 3205 	movx	@dptr,a
                           000120  3206 	C$config.c$67$2$224 ==.
                                   3207 ;	..\AX_Radio_Lab_output\config.c:67: radio_write8(AX5043_REG_FREQDEV01      ,                              			0x43);
      0004B8 90 41 3D         [24] 3208 	mov	dptr,#0x413d
      0004BB 74 43            [12] 3209 	mov	a,#0x43
      0004BD F0               [24] 3210 	movx	@dptr,a
                           000126  3211 	C$config.c$68$2$225 ==.
                                   3212 ;	..\AX_Radio_Lab_output\config.c:68: radio_write8(AX5043_REG_FOURFSK1       ,                              			0x16);
      0004BE 90 41 3E         [24] 3213 	mov	dptr,#0x413e
      0004C1 74 16            [12] 3214 	mov	a,#0x16
      0004C3 F0               [24] 3215 	movx	@dptr,a
                           00012C  3216 	C$config.c$69$2$226 ==.
                                   3217 ;	..\AX_Radio_Lab_output\config.c:69: radio_write8(AX5043_REG_BBOFFSRES1     ,                              			0x00);
      0004C4 90 41 3F         [24] 3218 	mov	dptr,#0x413f
      0004C7 E4               [12] 3219 	clr	a
      0004C8 F0               [24] 3220 	movx	@dptr,a
                           000131  3221 	C$config.c$70$2$227 ==.
                                   3222 ;	..\AX_Radio_Lab_output\config.c:70: radio_write8(AX5043_REG_AGCGAIN3       ,                              			0xFF);
      0004C9 90 41 50         [24] 3223 	mov	dptr,#0x4150
      0004CC 14               [12] 3224 	dec	a
      0004CD F0               [24] 3225 	movx	@dptr,a
                           000136  3226 	C$config.c$71$2$228 ==.
                                   3227 ;	..\AX_Radio_Lab_output\config.c:71: radio_write8(AX5043_REG_AGCTARGET3     ,                              			0x84);
      0004CE 90 41 51         [24] 3228 	mov	dptr,#0x4151
      0004D1 74 84            [12] 3229 	mov	a,#0x84
      0004D3 F0               [24] 3230 	movx	@dptr,a
                           00013C  3231 	C$config.c$72$2$229 ==.
                                   3232 ;	..\AX_Radio_Lab_output\config.c:72: radio_write8(AX5043_REG_AGCAHYST3      ,                              			0x00);
      0004D4 90 41 52         [24] 3233 	mov	dptr,#0x4152
      0004D7 E4               [12] 3234 	clr	a
      0004D8 F0               [24] 3235 	movx	@dptr,a
                           000141  3236 	C$config.c$73$2$230 ==.
                                   3237 ;	..\AX_Radio_Lab_output\config.c:73: radio_write8(AX5043_REG_AGCMINMAX3     ,                              			0x00);
      0004D9 90 41 53         [24] 3238 	mov	dptr,#0x4153
      0004DC F0               [24] 3239 	movx	@dptr,a
                           000145  3240 	C$config.c$74$2$231 ==.
                                   3241 ;	..\AX_Radio_Lab_output\config.c:74: radio_write8(AX5043_REG_TIMEGAIN3      ,                              			0xF5);
      0004DD 90 41 54         [24] 3242 	mov	dptr,#0x4154
      0004E0 74 F5            [12] 3243 	mov	a,#0xf5
      0004E2 F0               [24] 3244 	movx	@dptr,a
                           00014B  3245 	C$config.c$75$2$232 ==.
                                   3246 ;	..\AX_Radio_Lab_output\config.c:75: radio_write8(AX5043_REG_DRGAIN3        ,                              			0xF0);
      0004E3 90 41 55         [24] 3247 	mov	dptr,#0x4155
      0004E6 74 F0            [12] 3248 	mov	a,#0xf0
      0004E8 F0               [24] 3249 	movx	@dptr,a
                           000151  3250 	C$config.c$76$2$233 ==.
                                   3251 ;	..\AX_Radio_Lab_output\config.c:76: radio_write8(AX5043_REG_PHASEGAIN3     ,                              			0xC3);
      0004E9 90 41 56         [24] 3252 	mov	dptr,#0x4156
      0004EC 74 C3            [12] 3253 	mov	a,#0xc3
      0004EE F0               [24] 3254 	movx	@dptr,a
                           000157  3255 	C$config.c$77$2$234 ==.
                                   3256 ;	..\AX_Radio_Lab_output\config.c:77: radio_write8(AX5043_REG_FREQUENCYGAINA3,                              			0x0F);
      0004EF 90 41 57         [24] 3257 	mov	dptr,#0x4157
      0004F2 74 0F            [12] 3258 	mov	a,#0x0f
      0004F4 F0               [24] 3259 	movx	@dptr,a
                           00015D  3260 	C$config.c$78$2$235 ==.
                                   3261 ;	..\AX_Radio_Lab_output\config.c:78: radio_write8(AX5043_REG_FREQUENCYGAINB3,                              			0x1F);
      0004F5 90 41 58         [24] 3262 	mov	dptr,#0x4158
      0004F8 74 1F            [12] 3263 	mov	a,#0x1f
      0004FA F0               [24] 3264 	movx	@dptr,a
                           000163  3265 	C$config.c$79$2$236 ==.
                                   3266 ;	..\AX_Radio_Lab_output\config.c:79: radio_write8(AX5043_REG_FREQUENCYGAINC3,                              			0x0C);
      0004FB 90 41 59         [24] 3267 	mov	dptr,#0x4159
      0004FE 74 0C            [12] 3268 	mov	a,#0x0c
      000500 F0               [24] 3269 	movx	@dptr,a
                           000169  3270 	C$config.c$80$2$237 ==.
                                   3271 ;	..\AX_Radio_Lab_output\config.c:80: radio_write8(AX5043_REG_FREQUENCYGAIND3,                              			0x0C);
      000501 90 41 5A         [24] 3272 	mov	dptr,#0x415a
      000504 F0               [24] 3273 	movx	@dptr,a
                           00016D  3274 	C$config.c$81$2$238 ==.
                                   3275 ;	..\AX_Radio_Lab_output\config.c:81: radio_write8(AX5043_REG_AMPLITUDEGAIN3 ,                              			0x06);
      000505 90 41 5B         [24] 3276 	mov	dptr,#0x415b
      000508 03               [12] 3277 	rr	a
      000509 F0               [24] 3278 	movx	@dptr,a
                           000172  3279 	C$config.c$82$2$239 ==.
                                   3280 ;	..\AX_Radio_Lab_output\config.c:82: radio_write8(AX5043_REG_FREQDEV13      ,                              			0x00);
      00050A 90 41 5C         [24] 3281 	mov	dptr,#0x415c
      00050D E4               [12] 3282 	clr	a
      00050E F0               [24] 3283 	movx	@dptr,a
                           000177  3284 	C$config.c$83$2$240 ==.
                                   3285 ;	..\AX_Radio_Lab_output\config.c:83: radio_write8(AX5043_REG_FREQDEV03      ,                              			0x43);
      00050F 90 41 5D         [24] 3286 	mov	dptr,#0x415d
      000512 74 43            [12] 3287 	mov	a,#0x43
      000514 F0               [24] 3288 	movx	@dptr,a
                           00017D  3289 	C$config.c$84$2$241 ==.
                                   3290 ;	..\AX_Radio_Lab_output\config.c:84: radio_write8(AX5043_REG_FOURFSK3       ,                              			0x16);
      000515 90 41 5E         [24] 3291 	mov	dptr,#0x415e
      000518 74 16            [12] 3292 	mov	a,#0x16
      00051A F0               [24] 3293 	movx	@dptr,a
                           000183  3294 	C$config.c$85$2$242 ==.
                                   3295 ;	..\AX_Radio_Lab_output\config.c:85: radio_write8(AX5043_REG_BBOFFSRES3     ,                              			0x00);
      00051B 90 41 5F         [24] 3296 	mov	dptr,#0x415f
      00051E E4               [12] 3297 	clr	a
      00051F F0               [24] 3298 	movx	@dptr,a
                           000188  3299 	C$config.c$86$2$243 ==.
                                   3300 ;	..\AX_Radio_Lab_output\config.c:86: radio_write8(AX5043_REG_MODCFGF        ,                              			0x03);
      000520 90 41 60         [24] 3301 	mov	dptr,#0x4160
      000523 74 03            [12] 3302 	mov	a,#0x03
      000525 F0               [24] 3303 	movx	@dptr,a
                           00018E  3304 	C$config.c$87$2$244 ==.
                                   3305 ;	..\AX_Radio_Lab_output\config.c:87: radio_write8(AX5043_REG_FSKDEV2        ,                              			0x00);
      000526 90 41 61         [24] 3306 	mov	dptr,#0x4161
      000529 E4               [12] 3307 	clr	a
      00052A F0               [24] 3308 	movx	@dptr,a
                           000193  3309 	C$config.c$88$2$245 ==.
                                   3310 ;	..\AX_Radio_Lab_output\config.c:88: radio_write8(AX5043_REG_FSKDEV1        ,                              			0x04);
      00052B 90 41 62         [24] 3311 	mov	dptr,#0x4162
      00052E 74 04            [12] 3312 	mov	a,#0x04
      000530 F0               [24] 3313 	movx	@dptr,a
                           000199  3314 	C$config.c$89$2$246 ==.
                                   3315 ;	..\AX_Radio_Lab_output\config.c:89: radio_write8(AX5043_REG_FSKDEV0        ,                              			0x08);
      000531 90 41 63         [24] 3316 	mov	dptr,#0x4163
      000534 23               [12] 3317 	rl	a
      000535 F0               [24] 3318 	movx	@dptr,a
                           00019E  3319 	C$config.c$90$2$247 ==.
                                   3320 ;	..\AX_Radio_Lab_output\config.c:90: radio_write8(AX5043_REG_MODCFGA        ,                              			0x05);
      000536 90 41 64         [24] 3321 	mov	dptr,#0x4164
      000539 74 05            [12] 3322 	mov	a,#0x05
      00053B F0               [24] 3323 	movx	@dptr,a
                           0001A4  3324 	C$config.c$91$2$248 ==.
                                   3325 ;	..\AX_Radio_Lab_output\config.c:91: radio_write8(AX5043_REG_TXRATE2        ,                              			0x00);
      00053C 90 41 65         [24] 3326 	mov	dptr,#0x4165
      00053F E4               [12] 3327 	clr	a
      000540 F0               [24] 3328 	movx	@dptr,a
                           0001A9  3329 	C$config.c$92$2$249 ==.
                                   3330 ;	..\AX_Radio_Lab_output\config.c:92: radio_write8(AX5043_REG_TXRATE1        ,                              			0x0C);
      000541 90 41 66         [24] 3331 	mov	dptr,#0x4166
      000544 74 0C            [12] 3332 	mov	a,#0x0c
      000546 F0               [24] 3333 	movx	@dptr,a
                           0001AF  3334 	C$config.c$93$2$250 ==.
                                   3335 ;	..\AX_Radio_Lab_output\config.c:93: radio_write8(AX5043_REG_TXRATE0        ,                              			0x19);
      000547 90 41 67         [24] 3336 	mov	dptr,#0x4167
      00054A 74 19            [12] 3337 	mov	a,#0x19
      00054C F0               [24] 3338 	movx	@dptr,a
                           0001B5  3339 	C$config.c$94$2$251 ==.
                                   3340 ;	..\AX_Radio_Lab_output\config.c:94: radio_write8(AX5043_REG_TXPWRCOEFFB1   ,                              			0x0F);
      00054D 90 41 6A         [24] 3341 	mov	dptr,#0x416a
      000550 74 0F            [12] 3342 	mov	a,#0x0f
      000552 F0               [24] 3343 	movx	@dptr,a
                           0001BB  3344 	C$config.c$95$2$252 ==.
                                   3345 ;	..\AX_Radio_Lab_output\config.c:95: radio_write8(AX5043_REG_TXPWRCOEFFB0   ,                              			0xFF);
      000553 90 41 6B         [24] 3346 	mov	dptr,#0x416b
      000556 74 FF            [12] 3347 	mov	a,#0xff
      000558 F0               [24] 3348 	movx	@dptr,a
                           0001C1  3349 	C$config.c$96$2$253 ==.
                                   3350 ;	..\AX_Radio_Lab_output\config.c:96: radio_write8(AX5043_REG_PLLVCOI        ,                              			0x99);
      000559 90 41 80         [24] 3351 	mov	dptr,#0x4180
      00055C 74 99            [12] 3352 	mov	a,#0x99
      00055E F0               [24] 3353 	movx	@dptr,a
                           0001C7  3354 	C$config.c$97$2$254 ==.
                                   3355 ;	..\AX_Radio_Lab_output\config.c:97: radio_write8(AX5043_REG_PLLRNGCLK      ,                              			0x04);
      00055F 90 41 83         [24] 3356 	mov	dptr,#0x4183
      000562 74 04            [12] 3357 	mov	a,#0x04
      000564 F0               [24] 3358 	movx	@dptr,a
                           0001CD  3359 	C$config.c$98$2$255 ==.
                                   3360 ;	..\AX_Radio_Lab_output\config.c:98: radio_write8(AX5043_REG_BBTUNE         ,                              			0x0F);
      000565 90 41 88         [24] 3361 	mov	dptr,#0x4188
      000568 74 0F            [12] 3362 	mov	a,#0x0f
      00056A F0               [24] 3363 	movx	@dptr,a
                           0001D3  3364 	C$config.c$99$2$256 ==.
                                   3365 ;	..\AX_Radio_Lab_output\config.c:99: radio_write8(AX5043_REG_BBOFFSCAP      ,                              			0x77);
      00056B 90 41 89         [24] 3366 	mov	dptr,#0x4189
      00056E 74 77            [12] 3367 	mov	a,#0x77
      000570 F0               [24] 3368 	movx	@dptr,a
                           0001D9  3369 	C$config.c$100$2$257 ==.
                                   3370 ;	..\AX_Radio_Lab_output\config.c:100: radio_write8(AX5043_REG_PKTADDRCFG     ,                              			0x81);
      000571 90 42 00         [24] 3371 	mov	dptr,#0x4200
      000574 74 81            [12] 3372 	mov	a,#0x81
      000576 F0               [24] 3373 	movx	@dptr,a
                           0001DF  3374 	C$config.c$101$2$258 ==.
                                   3375 ;	..\AX_Radio_Lab_output\config.c:101: radio_write8(AX5043_REG_PKTLENCFG      ,                              			0x80);
      000577 90 42 01         [24] 3376 	mov	dptr,#0x4201
      00057A 14               [12] 3377 	dec	a
      00057B F0               [24] 3378 	movx	@dptr,a
                           0001E4  3379 	C$config.c$102$2$259 ==.
                                   3380 ;	..\AX_Radio_Lab_output\config.c:102: radio_write8(AX5043_REG_PKTLENOFFSET   ,                              			0x01);
      00057C 90 42 02         [24] 3381 	mov	dptr,#0x4202
      00057F 23               [12] 3382 	rl	a
      000580 F0               [24] 3383 	movx	@dptr,a
                           0001E9  3384 	C$config.c$103$2$260 ==.
                                   3385 ;	..\AX_Radio_Lab_output\config.c:103: radio_write8(AX5043_REG_PKTMAXLEN      ,                              			0xC8);
      000581 90 42 03         [24] 3386 	mov	dptr,#0x4203
      000584 74 C8            [12] 3387 	mov	a,#0xc8
      000586 F0               [24] 3388 	movx	@dptr,a
                           0001EF  3389 	C$config.c$104$2$261 ==.
                                   3390 ;	..\AX_Radio_Lab_output\config.c:104: radio_write8(AX5043_REG_MATCH0PAT3     ,                              			0x7B);
      000587 90 42 10         [24] 3391 	mov	dptr,#0x4210
      00058A 74 7B            [12] 3392 	mov	a,#0x7b
      00058C F0               [24] 3393 	movx	@dptr,a
                           0001F5  3394 	C$config.c$105$2$262 ==.
                                   3395 ;	..\AX_Radio_Lab_output\config.c:105: radio_write8(AX5043_REG_MATCH0PAT2     ,                              			0x8A);
      00058D 90 42 11         [24] 3396 	mov	dptr,#0x4211
      000590 74 8A            [12] 3397 	mov	a,#0x8a
      000592 F0               [24] 3398 	movx	@dptr,a
                           0001FB  3399 	C$config.c$106$2$263 ==.
                                   3400 ;	..\AX_Radio_Lab_output\config.c:106: radio_write8(AX5043_REG_MATCH0PAT1     ,                              			0xD0);
      000593 90 42 12         [24] 3401 	mov	dptr,#0x4212
      000596 74 D0            [12] 3402 	mov	a,#0xd0
      000598 F0               [24] 3403 	movx	@dptr,a
                           000201  3404 	C$config.c$107$2$264 ==.
                                   3405 ;	..\AX_Radio_Lab_output\config.c:107: radio_write8(AX5043_REG_MATCH0PAT0     ,                              			0xC9);
      000599 90 42 13         [24] 3406 	mov	dptr,#0x4213
      00059C 74 C9            [12] 3407 	mov	a,#0xc9
      00059E F0               [24] 3408 	movx	@dptr,a
                           000207  3409 	C$config.c$108$2$265 ==.
                                   3410 ;	..\AX_Radio_Lab_output\config.c:108: radio_write8(AX5043_REG_MATCH0LEN      ,                              			0x9F);
      00059F 90 42 14         [24] 3411 	mov	dptr,#0x4214
      0005A2 74 9F            [12] 3412 	mov	a,#0x9f
      0005A4 F0               [24] 3413 	movx	@dptr,a
                           00020D  3414 	C$config.c$109$2$266 ==.
                                   3415 ;	..\AX_Radio_Lab_output\config.c:109: radio_write8(AX5043_REG_MATCH0MAX      ,                              			0x1F);
      0005A5 90 42 16         [24] 3416 	mov	dptr,#0x4216
      0005A8 74 1F            [12] 3417 	mov	a,#0x1f
      0005AA F0               [24] 3418 	movx	@dptr,a
                           000213  3419 	C$config.c$110$2$267 ==.
                                   3420 ;	..\AX_Radio_Lab_output\config.c:110: radio_write8(AX5043_REG_MATCH1PAT1     ,                              			0x55);
      0005AB 90 42 18         [24] 3421 	mov	dptr,#0x4218
      0005AE 74 55            [12] 3422 	mov	a,#0x55
      0005B0 F0               [24] 3423 	movx	@dptr,a
                           000219  3424 	C$config.c$111$2$268 ==.
                                   3425 ;	..\AX_Radio_Lab_output\config.c:111: radio_write8(AX5043_REG_MATCH1PAT0     ,                              			0x55);
      0005B1 90 42 19         [24] 3426 	mov	dptr,#0x4219
      0005B4 F0               [24] 3427 	movx	@dptr,a
                           00021D  3428 	C$config.c$112$2$269 ==.
                                   3429 ;	..\AX_Radio_Lab_output\config.c:112: radio_write8(AX5043_REG_MATCH1LEN      ,                              			0x8A);
      0005B5 90 42 1C         [24] 3430 	mov	dptr,#0x421c
      0005B8 74 8A            [12] 3431 	mov	a,#0x8a
      0005BA F0               [24] 3432 	movx	@dptr,a
                           000223  3433 	C$config.c$113$2$270 ==.
                                   3434 ;	..\AX_Radio_Lab_output\config.c:113: radio_write8(AX5043_REG_MATCH1MAX      ,                              			0x0A);
      0005BB 90 42 1E         [24] 3435 	mov	dptr,#0x421e
      0005BE 74 0A            [12] 3436 	mov	a,#0x0a
      0005C0 F0               [24] 3437 	movx	@dptr,a
                           000229  3438 	C$config.c$114$2$271 ==.
                                   3439 ;	..\AX_Radio_Lab_output\config.c:114: radio_write8(AX5043_REG_TMGTXBOOST     ,                              			0x3E);
      0005C1 90 42 20         [24] 3440 	mov	dptr,#0x4220
      0005C4 74 3E            [12] 3441 	mov	a,#0x3e
      0005C6 F0               [24] 3442 	movx	@dptr,a
                           00022F  3443 	C$config.c$115$2$272 ==.
                                   3444 ;	..\AX_Radio_Lab_output\config.c:115: radio_write8(AX5043_REG_TMGTXSETTLE    ,                              			0x31);
      0005C7 90 42 21         [24] 3445 	mov	dptr,#0x4221
      0005CA 74 31            [12] 3446 	mov	a,#0x31
      0005CC F0               [24] 3447 	movx	@dptr,a
                           000235  3448 	C$config.c$116$2$273 ==.
                                   3449 ;	..\AX_Radio_Lab_output\config.c:116: radio_write8(AX5043_REG_TMGRXBOOST     ,                              			0x3E);
      0005CD 90 42 23         [24] 3450 	mov	dptr,#0x4223
      0005D0 74 3E            [12] 3451 	mov	a,#0x3e
      0005D2 F0               [24] 3452 	movx	@dptr,a
                           00023B  3453 	C$config.c$117$2$274 ==.
                                   3454 ;	..\AX_Radio_Lab_output\config.c:117: radio_write8(AX5043_REG_TMGRXSETTLE    ,                              			0x31);
      0005D3 90 42 24         [24] 3455 	mov	dptr,#0x4224
      0005D6 74 31            [12] 3456 	mov	a,#0x31
      0005D8 F0               [24] 3457 	movx	@dptr,a
                           000241  3458 	C$config.c$118$2$275 ==.
                                   3459 ;	..\AX_Radio_Lab_output\config.c:118: radio_write8(AX5043_REG_TMGRXOFFSACQ   ,                              			0x00);
      0005D9 90 42 25         [24] 3460 	mov	dptr,#0x4225
      0005DC E4               [12] 3461 	clr	a
      0005DD F0               [24] 3462 	movx	@dptr,a
                           000246  3463 	C$config.c$119$2$276 ==.
                                   3464 ;	..\AX_Radio_Lab_output\config.c:119: radio_write8(AX5043_REG_TMGRXCOARSEAGC ,                              			0x7F);
      0005DE 90 42 26         [24] 3465 	mov	dptr,#0x4226
      0005E1 74 7F            [12] 3466 	mov	a,#0x7f
      0005E3 F0               [24] 3467 	movx	@dptr,a
                           00024C  3468 	C$config.c$120$2$277 ==.
                                   3469 ;	..\AX_Radio_Lab_output\config.c:120: radio_write8(AX5043_REG_TMGRXRSSI      ,                              			0x03);
      0005E4 90 42 28         [24] 3470 	mov	dptr,#0x4228
      0005E7 74 03            [12] 3471 	mov	a,#0x03
      0005E9 F0               [24] 3472 	movx	@dptr,a
                           000252  3473 	C$config.c$121$2$278 ==.
                                   3474 ;	..\AX_Radio_Lab_output\config.c:121: radio_write8(AX5043_REG_TMGRXPREAMBLE2 ,                              			0x35);
      0005EA 90 42 2A         [24] 3475 	mov	dptr,#0x422a
      0005ED 74 35            [12] 3476 	mov	a,#0x35
      0005EF F0               [24] 3477 	movx	@dptr,a
                           000258  3478 	C$config.c$122$2$279 ==.
                                   3479 ;	..\AX_Radio_Lab_output\config.c:122: radio_write8(AX5043_REG_RSSIABSTHR     ,                              			0xE0);
      0005F0 90 42 2D         [24] 3480 	mov	dptr,#0x422d
      0005F3 74 E0            [12] 3481 	mov	a,#0xe0
      0005F5 F0               [24] 3482 	movx	@dptr,a
                           00025E  3483 	C$config.c$123$2$280 ==.
                                   3484 ;	..\AX_Radio_Lab_output\config.c:123: radio_write8(AX5043_REG_BGNDRSSITHR    ,                              			0x00);
      0005F6 90 42 2F         [24] 3485 	mov	dptr,#0x422f
      0005F9 E4               [12] 3486 	clr	a
      0005FA F0               [24] 3487 	movx	@dptr,a
                           000263  3488 	C$config.c$124$2$281 ==.
                                   3489 ;	..\AX_Radio_Lab_output\config.c:124: radio_write8(AX5043_REG_PKTCHUNKSIZE   ,                              			0x0D);
      0005FB 90 42 30         [24] 3490 	mov	dptr,#0x4230
      0005FE 74 0D            [12] 3491 	mov	a,#0x0d
      000600 F0               [24] 3492 	movx	@dptr,a
                           000269  3493 	C$config.c$125$2$282 ==.
                                   3494 ;	..\AX_Radio_Lab_output\config.c:125: radio_write8(AX5043_REG_PKTACCEPTFLAGS ,                              			0x20);
      000601 90 42 33         [24] 3495 	mov	dptr,#0x4233
      000604 74 20            [12] 3496 	mov	a,#0x20
      000606 F0               [24] 3497 	movx	@dptr,a
                           00026F  3498 	C$config.c$126$2$283 ==.
                                   3499 ;	..\AX_Radio_Lab_output\config.c:126: radio_write8(AX5043_REG_DACVALUE1      ,                              			0x00);
      000607 90 43 30         [24] 3500 	mov	dptr,#0x4330
      00060A E4               [12] 3501 	clr	a
      00060B F0               [24] 3502 	movx	@dptr,a
                           000274  3503 	C$config.c$127$2$284 ==.
                                   3504 ;	..\AX_Radio_Lab_output\config.c:127: radio_write8(AX5043_REG_DACVALUE0      ,                              			0x00);
      00060C 90 43 31         [24] 3505 	mov	dptr,#0x4331
      00060F F0               [24] 3506 	movx	@dptr,a
                           000278  3507 	C$config.c$128$2$285 ==.
                                   3508 ;	..\AX_Radio_Lab_output\config.c:128: radio_write8(AX5043_REG_DACCONFIG      ,                              			0x00);
      000610 90 43 32         [24] 3509 	mov	dptr,#0x4332
      000613 F0               [24] 3510 	movx	@dptr,a
                           00027C  3511 	C$config.c$129$2$286 ==.
                                   3512 ;	..\AX_Radio_Lab_output\config.c:129: radio_write8(AX5043_REG_REF            ,                              			0x03);
      000614 90 4F 0D         [24] 3513 	mov	dptr,#0x4f0d
      000617 74 03            [12] 3514 	mov	a,#0x03
      000619 F0               [24] 3515 	movx	@dptr,a
                           000282  3516 	C$config.c$130$2$287 ==.
                                   3517 ;	..\AX_Radio_Lab_output\config.c:130: radio_write8(AX5043_REG_XTALOSC        ,                              			0x04);
      00061A 90 4F 10         [24] 3518 	mov	dptr,#0x4f10
      00061D 04               [12] 3519 	inc	a
      00061E F0               [24] 3520 	movx	@dptr,a
                           000287  3521 	C$config.c$131$2$288 ==.
                                   3522 ;	..\AX_Radio_Lab_output\config.c:131: radio_write8(AX5043_REG_XTALAMPL       ,                              			0x00);
      00061F 90 4F 11         [24] 3523 	mov	dptr,#0x4f11
      000622 E4               [12] 3524 	clr	a
      000623 F0               [24] 3525 	movx	@dptr,a
                           00028C  3526 	C$config.c$132$2$289 ==.
                                   3527 ;	..\AX_Radio_Lab_output\config.c:132: radio_write8(AX5043_REG_0xF1C          ,                              			0x07);
      000624 90 4F 1C         [24] 3528 	mov	dptr,#0x4f1c
      000627 74 07            [12] 3529 	mov	a,#0x07
      000629 F0               [24] 3530 	movx	@dptr,a
                           000292  3531 	C$config.c$133$2$290 ==.
                                   3532 ;	..\AX_Radio_Lab_output\config.c:133: radio_write8(AX5043_REG_0xF21          ,                              			0x68);
      00062A 90 4F 21         [24] 3533 	mov	dptr,#0x4f21
      00062D 74 68            [12] 3534 	mov	a,#0x68
      00062F F0               [24] 3535 	movx	@dptr,a
                           000298  3536 	C$config.c$134$2$291 ==.
                                   3537 ;	..\AX_Radio_Lab_output\config.c:134: radio_write8(AX5043_REG_0xF22          ,                              			0xFF);
      000630 90 4F 22         [24] 3538 	mov	dptr,#0x4f22
      000633 74 FF            [12] 3539 	mov	a,#0xff
      000635 F0               [24] 3540 	movx	@dptr,a
                           00029E  3541 	C$config.c$135$2$292 ==.
                                   3542 ;	..\AX_Radio_Lab_output\config.c:135: radio_write8(AX5043_REG_0xF23          ,                              			0x84);
      000636 90 4F 23         [24] 3543 	mov	dptr,#0x4f23
      000639 74 84            [12] 3544 	mov	a,#0x84
      00063B F0               [24] 3545 	movx	@dptr,a
                           0002A4  3546 	C$config.c$136$2$293 ==.
                                   3547 ;	..\AX_Radio_Lab_output\config.c:136: radio_write8(AX5043_REG_0xF26          ,                              			0x98);
      00063C 90 4F 26         [24] 3548 	mov	dptr,#0x4f26
      00063F 74 98            [12] 3549 	mov	a,#0x98
      000641 F0               [24] 3550 	movx	@dptr,a
                           0002AA  3551 	C$config.c$137$2$294 ==.
                                   3552 ;	..\AX_Radio_Lab_output\config.c:137: radio_write8(AX5043_REG_0xF34          ,                              			0x08);
      000642 90 4F 34         [24] 3553 	mov	dptr,#0x4f34
      000645 74 08            [12] 3554 	mov	a,#0x08
      000647 F0               [24] 3555 	movx	@dptr,a
                           0002B0  3556 	C$config.c$138$2$295 ==.
                                   3557 ;	..\AX_Radio_Lab_output\config.c:138: radio_write8(AX5043_REG_0xF35          ,                              			0x11);
      000648 90 4F 35         [24] 3558 	mov	dptr,#0x4f35
      00064B 74 11            [12] 3559 	mov	a,#0x11
      00064D F0               [24] 3560 	movx	@dptr,a
                           0002B6  3561 	C$config.c$139$2$296 ==.
                                   3562 ;	..\AX_Radio_Lab_output\config.c:139: radio_write8(AX5043_REG_0xF44          ,                              			0x25);
      00064E 90 4F 44         [24] 3563 	mov	dptr,#0x4f44
      000651 74 25            [12] 3564 	mov	a,#0x25
      000653 F0               [24] 3565 	movx	@dptr,a
                           0002BC  3566 	C$config.c$140$1$170 ==.
                           0002BC  3567 	XG$ax5043_set_registers$0$0 ==.
      000654 22               [24] 3568 	ret
                                   3569 ;------------------------------------------------------------
                                   3570 ;Allocation info for local variables in function 'ax5043_set_registers_tx'
                                   3571 ;------------------------------------------------------------
                           0002BD  3572 	G$ax5043_set_registers_tx$0$0 ==.
                           0002BD  3573 	C$config.c$143$1$170 ==.
                                   3574 ;	..\AX_Radio_Lab_output\config.c:143: __reentrantb void ax5043_set_registers_tx(void) __reentrant
                                   3575 ;	-----------------------------------------
                                   3576 ;	 function ax5043_set_registers_tx
                                   3577 ;	-----------------------------------------
      000655                       3578 _ax5043_set_registers_tx:
                           0002BD  3579 	C$config.c$145$2$299 ==.
                                   3580 ;	..\AX_Radio_Lab_output\config.c:145: radio_write8(AX5043_REG_PLLLOOP        ,                              			0x07);
      000655 90 40 30         [24] 3581 	mov	dptr,#0x4030
      000658 74 07            [12] 3582 	mov	a,#0x07
      00065A F0               [24] 3583 	movx	@dptr,a
                           0002C3  3584 	C$config.c$146$2$300 ==.
                                   3585 ;	..\AX_Radio_Lab_output\config.c:146: radio_write8(AX5043_REG_PLLCPI         ,                              			0x12);
      00065B 90 40 31         [24] 3586 	mov	dptr,#0x4031
      00065E 74 12            [12] 3587 	mov	a,#0x12
      000660 F0               [24] 3588 	movx	@dptr,a
                           0002C9  3589 	C$config.c$147$2$301 ==.
                                   3590 ;	..\AX_Radio_Lab_output\config.c:147: radio_write8(AX5043_REG_PLLVCODIV      ,                              			0x20);
      000661 90 40 32         [24] 3591 	mov	dptr,#0x4032
      000664 74 20            [12] 3592 	mov	a,#0x20
      000666 F0               [24] 3593 	movx	@dptr,a
                           0002CF  3594 	C$config.c$148$2$302 ==.
                                   3595 ;	..\AX_Radio_Lab_output\config.c:148: radio_write8(AX5043_REG_XTALCAP        ,                              			0x00);
      000667 90 41 84         [24] 3596 	mov	dptr,#0x4184
      00066A E4               [12] 3597 	clr	a
      00066B F0               [24] 3598 	movx	@dptr,a
                           0002D4  3599 	C$config.c$149$2$303 ==.
                                   3600 ;	..\AX_Radio_Lab_output\config.c:149: radio_write8(AX5043_REG_0xF00          ,                              			0x0F);
      00066C 90 4F 00         [24] 3601 	mov	dptr,#0x4f00
      00066F 74 0F            [12] 3602 	mov	a,#0x0f
      000671 F0               [24] 3603 	movx	@dptr,a
                           0002DA  3604 	C$config.c$150$2$304 ==.
                                   3605 ;	..\AX_Radio_Lab_output\config.c:150: radio_write8(AX5043_REG_0xF18          ,                              			0x06);
      000672 90 4F 18         [24] 3606 	mov	dptr,#0x4f18
      000675 74 06            [12] 3607 	mov	a,#0x06
      000677 F0               [24] 3608 	movx	@dptr,a
                           0002E0  3609 	C$config.c$151$1$298 ==.
                           0002E0  3610 	XG$ax5043_set_registers_tx$0$0 ==.
      000678 22               [24] 3611 	ret
                                   3612 ;------------------------------------------------------------
                                   3613 ;Allocation info for local variables in function 'ax5043_set_registers_rx'
                                   3614 ;------------------------------------------------------------
                           0002E1  3615 	G$ax5043_set_registers_rx$0$0 ==.
                           0002E1  3616 	C$config.c$154$1$298 ==.
                                   3617 ;	..\AX_Radio_Lab_output\config.c:154: __reentrantb void ax5043_set_registers_rx(void) __reentrant
                                   3618 ;	-----------------------------------------
                                   3619 ;	 function ax5043_set_registers_rx
                                   3620 ;	-----------------------------------------
      000679                       3621 _ax5043_set_registers_rx:
                           0002E1  3622 	C$config.c$156$2$307 ==.
                                   3623 ;	..\AX_Radio_Lab_output\config.c:156: radio_write8(AX5043_REG_PLLLOOP        ,                              			0x07);
      000679 90 40 30         [24] 3624 	mov	dptr,#0x4030
      00067C 74 07            [12] 3625 	mov	a,#0x07
      00067E F0               [24] 3626 	movx	@dptr,a
                           0002E7  3627 	C$config.c$157$2$308 ==.
                                   3628 ;	..\AX_Radio_Lab_output\config.c:157: radio_write8(AX5043_REG_PLLCPI         ,                              			0x08);
      00067F 90 40 31         [24] 3629 	mov	dptr,#0x4031
      000682 04               [12] 3630 	inc	a
      000683 F0               [24] 3631 	movx	@dptr,a
                           0002EC  3632 	C$config.c$158$2$309 ==.
                                   3633 ;	..\AX_Radio_Lab_output\config.c:158: radio_write8(AX5043_REG_PLLVCODIV      ,                              			0x20);
      000684 90 40 32         [24] 3634 	mov	dptr,#0x4032
      000687 74 20            [12] 3635 	mov	a,#0x20
      000689 F0               [24] 3636 	movx	@dptr,a
                           0002F2  3637 	C$config.c$159$2$310 ==.
                                   3638 ;	..\AX_Radio_Lab_output\config.c:159: radio_write8(AX5043_REG_XTALCAP        ,                              			0x00);
      00068A 90 41 84         [24] 3639 	mov	dptr,#0x4184
      00068D E4               [12] 3640 	clr	a
      00068E F0               [24] 3641 	movx	@dptr,a
                           0002F7  3642 	C$config.c$160$2$311 ==.
                                   3643 ;	..\AX_Radio_Lab_output\config.c:160: radio_write8(AX5043_REG_0xF00          ,                              			0x0F);
      00068F 90 4F 00         [24] 3644 	mov	dptr,#0x4f00
      000692 74 0F            [12] 3645 	mov	a,#0x0f
      000694 F0               [24] 3646 	movx	@dptr,a
                           0002FD  3647 	C$config.c$161$2$312 ==.
                                   3648 ;	..\AX_Radio_Lab_output\config.c:161: radio_write8(AX5043_REG_0xF18          ,                              			0x06);
      000695 90 4F 18         [24] 3649 	mov	dptr,#0x4f18
      000698 74 06            [12] 3650 	mov	a,#0x06
      00069A F0               [24] 3651 	movx	@dptr,a
                           000303  3652 	C$config.c$162$1$306 ==.
                           000303  3653 	XG$ax5043_set_registers_rx$0$0 ==.
      00069B 22               [24] 3654 	ret
                                   3655 ;------------------------------------------------------------
                                   3656 ;Allocation info for local variables in function 'ax5043_set_registers_rxwor'
                                   3657 ;------------------------------------------------------------
                           000304  3658 	G$ax5043_set_registers_rxwor$0$0 ==.
                           000304  3659 	C$config.c$165$1$306 ==.
                                   3660 ;	..\AX_Radio_Lab_output\config.c:165: __reentrantb void ax5043_set_registers_rxwor(void) __reentrant
                                   3661 ;	-----------------------------------------
                                   3662 ;	 function ax5043_set_registers_rxwor
                                   3663 ;	-----------------------------------------
      00069C                       3664 _ax5043_set_registers_rxwor:
                           000304  3665 	C$config.c$167$2$315 ==.
                                   3666 ;	..\AX_Radio_Lab_output\config.c:167: radio_write8(AX5043_REG_TMGRXAGC,                 0x0A);
      00069C 90 42 27         [24] 3667 	mov	dptr,#0x4227
      00069F 74 0A            [12] 3668 	mov	a,#0x0a
      0006A1 F0               [24] 3669 	movx	@dptr,a
                           00030A  3670 	C$config.c$168$2$316 ==.
                                   3671 ;	..\AX_Radio_Lab_output\config.c:168: radio_write8(AX5043_REG_TMGRXPREAMBLE1,           0x19);
      0006A2 90 42 29         [24] 3672 	mov	dptr,#0x4229
      0006A5 74 19            [12] 3673 	mov	a,#0x19
      0006A7 F0               [24] 3674 	movx	@dptr,a
                           000310  3675 	C$config.c$169$2$317 ==.
                                   3676 ;	..\AX_Radio_Lab_output\config.c:169: radio_write8(AX5043_REG_PKTMISCFLAGS,             0x03);
      0006A8 90 42 31         [24] 3677 	mov	dptr,#0x4231
      0006AB 74 03            [12] 3678 	mov	a,#0x03
      0006AD F0               [24] 3679 	movx	@dptr,a
                           000316  3680 	C$config.c$170$1$314 ==.
                           000316  3681 	XG$ax5043_set_registers_rxwor$0$0 ==.
      0006AE 22               [24] 3682 	ret
                                   3683 ;------------------------------------------------------------
                                   3684 ;Allocation info for local variables in function 'ax5043_set_registers_rxcont'
                                   3685 ;------------------------------------------------------------
                           000317  3686 	G$ax5043_set_registers_rxcont$0$0 ==.
                           000317  3687 	C$config.c$173$1$314 ==.
                                   3688 ;	..\AX_Radio_Lab_output\config.c:173: __reentrantb void ax5043_set_registers_rxcont(void) __reentrant
                                   3689 ;	-----------------------------------------
                                   3690 ;	 function ax5043_set_registers_rxcont
                                   3691 ;	-----------------------------------------
      0006AF                       3692 _ax5043_set_registers_rxcont:
                           000317  3693 	C$config.c$175$2$320 ==.
                                   3694 ;	..\AX_Radio_Lab_output\config.c:175: radio_write8(AX5043_REG_TMGRXAGC,                 0x00);
      0006AF 90 42 27         [24] 3695 	mov	dptr,#0x4227
      0006B2 E4               [12] 3696 	clr	a
      0006B3 F0               [24] 3697 	movx	@dptr,a
                           00031C  3698 	C$config.c$176$2$321 ==.
                                   3699 ;	..\AX_Radio_Lab_output\config.c:176: radio_write8(AX5043_REG_TMGRXPREAMBLE1,           0x00);
      0006B4 90 42 29         [24] 3700 	mov	dptr,#0x4229
      0006B7 F0               [24] 3701 	movx	@dptr,a
                           000320  3702 	C$config.c$177$2$322 ==.
                                   3703 ;	..\AX_Radio_Lab_output\config.c:177: radio_write8(AX5043_REG_PKTMISCFLAGS,             0x00);
      0006B8 90 42 31         [24] 3704 	mov	dptr,#0x4231
      0006BB F0               [24] 3705 	movx	@dptr,a
                           000324  3706 	C$config.c$178$1$319 ==.
                           000324  3707 	XG$ax5043_set_registers_rxcont$0$0 ==.
      0006BC 22               [24] 3708 	ret
                                   3709 ;------------------------------------------------------------
                                   3710 ;Allocation info for local variables in function 'ax5043_set_registers_rxcont_singleparamset'
                                   3711 ;------------------------------------------------------------
                           000325  3712 	G$ax5043_set_registers_rxcont_singleparamset$0$0 ==.
                           000325  3713 	C$config.c$181$1$319 ==.
                                   3714 ;	..\AX_Radio_Lab_output\config.c:181: __reentrantb void ax5043_set_registers_rxcont_singleparamset(void) __reentrant
                                   3715 ;	-----------------------------------------
                                   3716 ;	 function ax5043_set_registers_rxcont_singleparamset
                                   3717 ;	-----------------------------------------
      0006BD                       3718 _ax5043_set_registers_rxcont_singleparamset:
                           000325  3719 	C$config.c$183$2$325 ==.
                                   3720 ;	..\AX_Radio_Lab_output\config.c:183: radio_write8(AX5043_REG_RXPARAMSETS,              0xFF);
      0006BD 90 41 17         [24] 3721 	mov	dptr,#0x4117
      0006C0 74 FF            [12] 3722 	mov	a,#0xff
      0006C2 F0               [24] 3723 	movx	@dptr,a
                           00032B  3724 	C$config.c$184$2$326 ==.
                                   3725 ;	..\AX_Radio_Lab_output\config.c:184: radio_write8(AX5043_REG_FREQDEV13,                0x00);
      0006C3 90 41 5C         [24] 3726 	mov	dptr,#0x415c
      0006C6 E4               [12] 3727 	clr	a
      0006C7 F0               [24] 3728 	movx	@dptr,a
                           000330  3729 	C$config.c$185$2$327 ==.
                                   3730 ;	..\AX_Radio_Lab_output\config.c:185: radio_write8(AX5043_REG_FREQDEV03,                0x00);
      0006C8 90 41 5D         [24] 3731 	mov	dptr,#0x415d
      0006CB F0               [24] 3732 	movx	@dptr,a
                           000334  3733 	C$config.c$186$2$328 ==.
                                   3734 ;	..\AX_Radio_Lab_output\config.c:186: radio_write8(AX5043_REG_AGCGAIN3,                 0xE7);
      0006CC 90 41 50         [24] 3735 	mov	dptr,#0x4150
      0006CF 74 E7            [12] 3736 	mov	a,#0xe7
      0006D1 F0               [24] 3737 	movx	@dptr,a
                           00033A  3738 	C$config.c$187$1$324 ==.
                           00033A  3739 	XG$ax5043_set_registers_rxcont_singleparamset$0$0 ==.
      0006D2 22               [24] 3740 	ret
                                   3741 ;------------------------------------------------------------
                                   3742 ;Allocation info for local variables in function 'axradio_setup_pincfg1'
                                   3743 ;------------------------------------------------------------
                           00033B  3744 	G$axradio_setup_pincfg1$0$0 ==.
                           00033B  3745 	C$config.c$191$1$324 ==.
                                   3746 ;	..\AX_Radio_Lab_output\config.c:191: __reentrantb void axradio_setup_pincfg1(void) __reentrant
                                   3747 ;	-----------------------------------------
                                   3748 ;	 function axradio_setup_pincfg1
                                   3749 ;	-----------------------------------------
      0006D3                       3750 _axradio_setup_pincfg1:
                           00033B  3751 	C$config.c$196$1$330 ==.
                                   3752 ;	..\AX_Radio_Lab_output\config.c:196: PALTRADIO = 0x00; //pass through  
      0006D3 90 70 46         [24] 3753 	mov	dptr,#_PALTRADIO
      0006D6 E4               [12] 3754 	clr	a
      0006D7 F0               [24] 3755 	movx	@dptr,a
                           000340  3756 	C$config.c$199$1$330 ==.
                           000340  3757 	XG$axradio_setup_pincfg1$0$0 ==.
      0006D8 22               [24] 3758 	ret
                                   3759 ;------------------------------------------------------------
                                   3760 ;Allocation info for local variables in function 'axradio_setup_pincfg2'
                                   3761 ;------------------------------------------------------------
                           000341  3762 	G$axradio_setup_pincfg2$0$0 ==.
                           000341  3763 	C$config.c$201$1$330 ==.
                                   3764 ;	..\AX_Radio_Lab_output\config.c:201: __reentrantb void axradio_setup_pincfg2(void) __reentrant
                                   3765 ;	-----------------------------------------
                                   3766 ;	 function axradio_setup_pincfg2
                                   3767 ;	-----------------------------------------
      0006D9                       3768 _axradio_setup_pincfg2:
                           000341  3769 	C$config.c$206$1$332 ==.
                                   3770 ;	..\AX_Radio_Lab_output\config.c:206: PORTR = (PORTR & 0x3F) | 0x00; //AX8052F143 --> no pull-ups on PR6, PR7
      0006D9 53 8C 3F         [24] 3771 	anl	_PORTR,#0x3f
                           000344  3772 	C$config.c$209$1$332 ==.
                           000344  3773 	XG$axradio_setup_pincfg2$0$0 ==.
      0006DC 22               [24] 3774 	ret
                                   3775 ;------------------------------------------------------------
                                   3776 ;Allocation info for local variables in function 'axradio_conv_freq_fromhz'
                                   3777 ;------------------------------------------------------------
                                   3778 ;f                         Allocated to registers 
                                   3779 ;------------------------------------------------------------
                           000345  3780 	G$axradio_conv_freq_fromhz$0$0 ==.
                           000345  3781 	C$config.c$614$1$332 ==.
                                   3782 ;	..\AX_Radio_Lab_output\config.c:614: int32_t axradio_conv_freq_fromhz(int32_t f)
                                   3783 ;	-----------------------------------------
                                   3784 ;	 function axradio_conv_freq_fromhz
                                   3785 ;	-----------------------------------------
      0006DD                       3786 _axradio_conv_freq_fromhz:
                           000345  3787 	C$config.c$620$1$334 ==.
                                   3788 ;	..\AX_Radio_Lab_output\config.c:620: CONSTMULFIX24(0xa530e8);
      0006DD A8 82            [24] 3789 	mov r0,dpl 
      0006DF A9 83            [24] 3790 	mov r1,dph 
      0006E1 AA F0            [24] 3791 	mov r2,b 
      0006E3 FB               [12] 3792 	mov r3,a 
      0006E4 C0 E0            [24] 3793 	push acc 
      0006E6 30 E7 0D         [24] 3794 	jnb acc.7,00000$ 
      0006E9 C3               [12] 3795 	clr c 
      0006EA E4               [12] 3796 	clr a 
      0006EB 98               [12] 3797 	subb a,r0 
      0006EC F8               [12] 3798 	mov r0,a 
      0006ED E4               [12] 3799 	clr a 
      0006EE 99               [12] 3800 	subb a,r1 
      0006EF F9               [12] 3801 	mov r1,a 
      0006F0 E4               [12] 3802 	clr a 
      0006F1 9A               [12] 3803 	subb a,r2 
      0006F2 FA               [12] 3804 	mov r2,a 
      0006F3 E4               [12] 3805 	clr a 
      0006F4 9B               [12] 3806 	subb a,r3 
      0006F5 FB               [12] 3807 	mov r3,a 
      0006F6                       3808 	 00000$:
      0006F6 E4               [12] 3809 	clr a 
      0006F7 FC               [12] 3810 	mov r4,a 
      0006F8 FD               [12] 3811 	mov r5,a 
      0006F9 FE               [12] 3812 	mov r6,a 
      0006FA FF               [12] 3813 	mov r7,a 
                                   3814 ;; stage -1 
                           000001  3815 	.if (((0xa530e8)>>16)&0xff) 
      0006FB 74 A5            [12] 3816 	mov a,# (((0xa530e8)>>16)&0xff) 
      0006FD 88 F0            [24] 3817 	mov b,r0 
      0006FF A4               [48] 3818 	mul ab 
      000700 FF               [12] 3819 	mov r7,a 
      000701 AC F0            [24] 3820 	mov r4,b 
                                   3821 	.endif 
                           000001  3822 	.if (((0xa530e8)>>8)&0xff) 
      000703 74 30            [12] 3823 	mov a,# (((0xa530e8)>>8)&0xff) 
      000705 89 F0            [24] 3824 	mov b,r1 
      000707 A4               [48] 3825 	mul ab 
                           000001  3826 	.if (((0xa530e8)>>16)&0xff) 
      000708 2F               [12] 3827 	add a,r7 
      000709 FF               [12] 3828 	mov r7,a 
      00070A E5 F0            [12] 3829 	mov a,b 
      00070C 3C               [12] 3830 	addc a,r4 
      00070D FC               [12] 3831 	mov r4,a 
      00070E E4               [12] 3832 	clr a 
      00070F 3D               [12] 3833 	addc a,r5 
      000710 FD               [12] 3834 	mov r5,a 
                           000000  3835 	.else 
                                   3836 	mov r7,a 
                                   3837 	mov r4,b 
                                   3838 	.endif 
                                   3839 	.endif 
                           000001  3840 	.if ((0xa530e8)&0xff) 
      000711 74 E8            [12] 3841 	mov a,# ((0xa530e8)&0xff) 
      000713 8A F0            [24] 3842 	mov b,r2 
      000715 A4               [48] 3843 	mul ab 
                           000001  3844 	.if (((0xa530e8)>>8)&0xffff) 
      000716 2F               [12] 3845 	add a,r7 
      000717 FF               [12] 3846 	mov r7,a 
      000718 E5 F0            [12] 3847 	mov a,b 
      00071A 3C               [12] 3848 	addc a,r4 
      00071B FC               [12] 3849 	mov r4,a 
      00071C E4               [12] 3850 	clr a 
      00071D 3D               [12] 3851 	addc a,r5 
      00071E FD               [12] 3852 	mov r5,a 
                           000000  3853 	.else 
                                   3854 	mov r7,a 
                                   3855 	mov r4,b 
                                   3856 	.endif 
                                   3857 	.endif 
                                   3858 ;; clear precision extension 
      00071F E4               [12] 3859 	clr a 
      000720 FF               [12] 3860 	mov r7,a 
                                   3861 ;; stage 0 
                           000000  3862 	.if (((0xa530e8)>>24)&0xff) 
                                   3863 	mov a,# (((0xa530e8)>>24)&0xff) 
                                   3864 	mov b,r0 
                                   3865 	mul ab 
                                   3866 	add a,r4 
                                   3867 	mov r4,a 
                                   3868 	mov a,b 
                                   3869 	addc a,r5 
                                   3870 	mov r5,a 
                                   3871 	clr a 
                                   3872 	addc a,r6 
                                   3873 	mov r6,a 
                                   3874 	.endif 
                           000001  3875 	.if (((0xa530e8)>>16)&0xff) 
      000721 74 A5            [12] 3876 	mov a,# (((0xa530e8)>>16)&0xff) 
      000723 89 F0            [24] 3877 	mov b,r1 
      000725 A4               [48] 3878 	mul ab 
      000726 2C               [12] 3879 	add a,r4 
      000727 FC               [12] 3880 	mov r4,a 
      000728 E5 F0            [12] 3881 	mov a,b 
      00072A 3D               [12] 3882 	addc a,r5 
      00072B FD               [12] 3883 	mov r5,a 
      00072C E4               [12] 3884 	clr a 
      00072D 3E               [12] 3885 	addc a,r6 
      00072E FE               [12] 3886 	mov r6,a 
                                   3887 	.endif 
                           000001  3888 	.if (((0xa530e8)>>8)&0xff) 
      00072F 74 30            [12] 3889 	mov a,# (((0xa530e8)>>8)&0xff) 
      000731 8A F0            [24] 3890 	mov b,r2 
      000733 A4               [48] 3891 	mul ab 
      000734 2C               [12] 3892 	add a,r4 
      000735 FC               [12] 3893 	mov r4,a 
      000736 E5 F0            [12] 3894 	mov a,b 
      000738 3D               [12] 3895 	addc a,r5 
      000739 FD               [12] 3896 	mov r5,a 
      00073A E4               [12] 3897 	clr a 
      00073B 3E               [12] 3898 	addc a,r6 
      00073C FE               [12] 3899 	mov r6,a 
                                   3900 	.endif 
                           000001  3901 	.if ((0xa530e8)&0xff) 
      00073D 74 E8            [12] 3902 	mov a,# ((0xa530e8)&0xff) 
      00073F 8B F0            [24] 3903 	mov b,r3 
      000741 A4               [48] 3904 	mul ab 
      000742 2C               [12] 3905 	add a,r4 
      000743 FC               [12] 3906 	mov r4,a 
      000744 E5 F0            [12] 3907 	mov a,b 
      000746 3D               [12] 3908 	addc a,r5 
      000747 FD               [12] 3909 	mov r5,a 
      000748 E4               [12] 3910 	clr a 
      000749 3E               [12] 3911 	addc a,r6 
      00074A FE               [12] 3912 	mov r6,a 
                                   3913 	.endif 
                                   3914 ;; stage 1 
                           000000  3915 	.if (((0xa530e8)>>24)&0xff) 
                                   3916 	mov a,# (((0xa530e8)>>24)&0xff) 
                                   3917 	mov b,r1 
                                   3918 	mul ab 
                                   3919 	add a,r5 
                                   3920 	mov r5,a 
                                   3921 	mov a,b 
                                   3922 	addc a,r6 
                                   3923 	mov r6,a 
                                   3924 	clr a 
                                   3925 	addc a,r7 
                                   3926 	mov r7,a 
                                   3927 	.endif 
                           000001  3928 	.if (((0xa530e8)>>16)&0xff) 
      00074B 74 A5            [12] 3929 	mov a,# (((0xa530e8)>>16)&0xff) 
      00074D 8A F0            [24] 3930 	mov b,r2 
      00074F A4               [48] 3931 	mul ab 
      000750 2D               [12] 3932 	add a,r5 
      000751 FD               [12] 3933 	mov r5,a 
      000752 E5 F0            [12] 3934 	mov a,b 
      000754 3E               [12] 3935 	addc a,r6 
      000755 FE               [12] 3936 	mov r6,a 
      000756 E4               [12] 3937 	clr a 
      000757 3F               [12] 3938 	addc a,r7 
      000758 FF               [12] 3939 	mov r7,a 
                                   3940 	.endif 
                           000001  3941 	.if (((0xa530e8)>>8)&0xff) 
      000759 74 30            [12] 3942 	mov a,# (((0xa530e8)>>8)&0xff) 
      00075B 8B F0            [24] 3943 	mov b,r3 
      00075D A4               [48] 3944 	mul ab 
      00075E 2D               [12] 3945 	add a,r5 
      00075F FD               [12] 3946 	mov r5,a 
      000760 E5 F0            [12] 3947 	mov a,b 
      000762 3E               [12] 3948 	addc a,r6 
      000763 FE               [12] 3949 	mov r6,a 
      000764 E4               [12] 3950 	clr a 
      000765 3F               [12] 3951 	addc a,r7 
      000766 FF               [12] 3952 	mov r7,a 
                                   3953 	.endif 
                                   3954 ;; stage 2 
                           000000  3955 	.if (((0xa530e8)>>24)&0xff) 
                                   3956 	mov a,# (((0xa530e8)>>24)&0xff) 
                                   3957 	mov b,r2 
                                   3958 	mul ab 
                                   3959 	add a,r6 
                                   3960 	mov r6,a 
                                   3961 	mov a,b 
                                   3962 	addc a,r7 
                                   3963 	mov r7,a 
                                   3964 	.endif 
                           000001  3965 	.if (((0xa530e8)>>16)&0xff) 
      000767 74 A5            [12] 3966 	mov a,# (((0xa530e8)>>16)&0xff) 
      000769 8B F0            [24] 3967 	mov b,r3 
      00076B A4               [48] 3968 	mul ab 
      00076C 2E               [12] 3969 	add a,r6 
      00076D FE               [12] 3970 	mov r6,a 
      00076E E5 F0            [12] 3971 	mov a,b 
      000770 3F               [12] 3972 	addc a,r7 
      000771 FF               [12] 3973 	mov r7,a 
                                   3974 	.endif 
                                   3975 ;; stage 3 
                           000000  3976 	.if (((0xa530e8)>>24)&0xff) 
                                   3977 	mov a,# (((0xa530e8)>>24)&0xff) 
                                   3978 	mov b,r3 
                                   3979 	mul ab 
                                   3980 	add a,r7 
                                   3981 	mov r7,a 
                                   3982 	.endif 
      000772 D0 E0            [24] 3983 	pop acc 
      000774 30 E7 11         [24] 3984 	jnb acc.7,00001$ 
      000777 C3               [12] 3985 	clr c 
      000778 E4               [12] 3986 	clr a 
      000779 9C               [12] 3987 	subb a,r4 
      00077A F5 82            [12] 3988 	mov dpl,a 
      00077C E4               [12] 3989 	clr a 
      00077D 9D               [12] 3990 	subb a,r5 
      00077E F5 83            [12] 3991 	mov dph,a 
      000780 E4               [12] 3992 	clr a 
      000781 9E               [12] 3993 	subb a,r6 
      000782 F5 F0            [12] 3994 	mov b,a 
      000784 E4               [12] 3995 	clr a 
      000785 9F               [12] 3996 	subb a,r7 
      000786 80 07            [24] 3997 	sjmp 00002$ 
      000788                       3998 	 00001$:
      000788 8C 82            [24] 3999 	mov dpl,r4 
      00078A 8D 83            [24] 4000 	mov dph,r5 
      00078C 8E F0            [24] 4001 	mov b,r6 
      00078E EF               [12] 4002 	mov a,r7 
      00078F                       4003 	 00002$:
                           0003F7  4004 	C$config.c$621$1$334 ==.
                           0003F7  4005 	XG$axradio_conv_freq_fromhz$0$0 ==.
      00078F 22               [24] 4006 	ret
                                   4007 ;------------------------------------------------------------
                                   4008 ;Allocation info for local variables in function 'axradio_conv_freq_tohz'
                                   4009 ;------------------------------------------------------------
                                   4010 ;f                         Allocated to registers 
                                   4011 ;------------------------------------------------------------
                           0003F8  4012 	G$axradio_conv_freq_tohz$0$0 ==.
                           0003F8  4013 	C$config.c$626$1$334 ==.
                                   4014 ;	..\AX_Radio_Lab_output\config.c:626: int32_t axradio_conv_freq_tohz(int32_t f)
                                   4015 ;	-----------------------------------------
                                   4016 ;	 function axradio_conv_freq_tohz
                                   4017 ;	-----------------------------------------
      000790                       4018 _axradio_conv_freq_tohz:
                           0003F8  4019 	C$config.c$632$1$336 ==.
                                   4020 ;	..\AX_Radio_Lab_output\config.c:632: CONSTMULFIX24(0x18cba80);
      000790 A8 82            [24] 4021 	mov r0,dpl 
      000792 A9 83            [24] 4022 	mov r1,dph 
      000794 AA F0            [24] 4023 	mov r2,b 
      000796 FB               [12] 4024 	mov r3,a 
      000797 C0 E0            [24] 4025 	push acc 
      000799 30 E7 0D         [24] 4026 	jnb acc.7,00000$ 
      00079C C3               [12] 4027 	clr c 
      00079D E4               [12] 4028 	clr a 
      00079E 98               [12] 4029 	subb a,r0 
      00079F F8               [12] 4030 	mov r0,a 
      0007A0 E4               [12] 4031 	clr a 
      0007A1 99               [12] 4032 	subb a,r1 
      0007A2 F9               [12] 4033 	mov r1,a 
      0007A3 E4               [12] 4034 	clr a 
      0007A4 9A               [12] 4035 	subb a,r2 
      0007A5 FA               [12] 4036 	mov r2,a 
      0007A6 E4               [12] 4037 	clr a 
      0007A7 9B               [12] 4038 	subb a,r3 
      0007A8 FB               [12] 4039 	mov r3,a 
      0007A9                       4040 	 00000$:
      0007A9 E4               [12] 4041 	clr a 
      0007AA FC               [12] 4042 	mov r4,a 
      0007AB FD               [12] 4043 	mov r5,a 
      0007AC FE               [12] 4044 	mov r6,a 
      0007AD FF               [12] 4045 	mov r7,a 
                                   4046 ;; stage -1 
                           000001  4047 	.if (((0x18cba80)>>16)&0xff) 
      0007AE 74 8C            [12] 4048 	mov a,# (((0x18cba80)>>16)&0xff) 
      0007B0 88 F0            [24] 4049 	mov b,r0 
      0007B2 A4               [48] 4050 	mul ab 
      0007B3 FF               [12] 4051 	mov r7,a 
      0007B4 AC F0            [24] 4052 	mov r4,b 
                                   4053 	.endif 
                           000001  4054 	.if (((0x18cba80)>>8)&0xff) 
      0007B6 74 BA            [12] 4055 	mov a,# (((0x18cba80)>>8)&0xff) 
      0007B8 89 F0            [24] 4056 	mov b,r1 
      0007BA A4               [48] 4057 	mul ab 
                           000001  4058 	.if (((0x18cba80)>>16)&0xff) 
      0007BB 2F               [12] 4059 	add a,r7 
      0007BC FF               [12] 4060 	mov r7,a 
      0007BD E5 F0            [12] 4061 	mov a,b 
      0007BF 3C               [12] 4062 	addc a,r4 
      0007C0 FC               [12] 4063 	mov r4,a 
      0007C1 E4               [12] 4064 	clr a 
      0007C2 3D               [12] 4065 	addc a,r5 
      0007C3 FD               [12] 4066 	mov r5,a 
                           000000  4067 	.else 
                                   4068 	mov r7,a 
                                   4069 	mov r4,b 
                                   4070 	.endif 
                                   4071 	.endif 
                           000001  4072 	.if ((0x18cba80)&0xff) 
      0007C4 74 80            [12] 4073 	mov a,# ((0x18cba80)&0xff) 
      0007C6 8A F0            [24] 4074 	mov b,r2 
      0007C8 A4               [48] 4075 	mul ab 
                           000001  4076 	.if (((0x18cba80)>>8)&0xffff) 
      0007C9 2F               [12] 4077 	add a,r7 
      0007CA FF               [12] 4078 	mov r7,a 
      0007CB E5 F0            [12] 4079 	mov a,b 
      0007CD 3C               [12] 4080 	addc a,r4 
      0007CE FC               [12] 4081 	mov r4,a 
      0007CF E4               [12] 4082 	clr a 
      0007D0 3D               [12] 4083 	addc a,r5 
      0007D1 FD               [12] 4084 	mov r5,a 
                           000000  4085 	.else 
                                   4086 	mov r7,a 
                                   4087 	mov r4,b 
                                   4088 	.endif 
                                   4089 	.endif 
                                   4090 ;; clear precision extension 
      0007D2 E4               [12] 4091 	clr a 
      0007D3 FF               [12] 4092 	mov r7,a 
                                   4093 ;; stage 0 
                           000001  4094 	.if (((0x18cba80)>>24)&0xff) 
      0007D4 74 01            [12] 4095 	mov a,# (((0x18cba80)>>24)&0xff) 
      0007D6 88 F0            [24] 4096 	mov b,r0 
      0007D8 A4               [48] 4097 	mul ab 
      0007D9 2C               [12] 4098 	add a,r4 
      0007DA FC               [12] 4099 	mov r4,a 
      0007DB E5 F0            [12] 4100 	mov a,b 
      0007DD 3D               [12] 4101 	addc a,r5 
      0007DE FD               [12] 4102 	mov r5,a 
      0007DF E4               [12] 4103 	clr a 
      0007E0 3E               [12] 4104 	addc a,r6 
      0007E1 FE               [12] 4105 	mov r6,a 
                                   4106 	.endif 
                           000001  4107 	.if (((0x18cba80)>>16)&0xff) 
      0007E2 74 8C            [12] 4108 	mov a,# (((0x18cba80)>>16)&0xff) 
      0007E4 89 F0            [24] 4109 	mov b,r1 
      0007E6 A4               [48] 4110 	mul ab 
      0007E7 2C               [12] 4111 	add a,r4 
      0007E8 FC               [12] 4112 	mov r4,a 
      0007E9 E5 F0            [12] 4113 	mov a,b 
      0007EB 3D               [12] 4114 	addc a,r5 
      0007EC FD               [12] 4115 	mov r5,a 
      0007ED E4               [12] 4116 	clr a 
      0007EE 3E               [12] 4117 	addc a,r6 
      0007EF FE               [12] 4118 	mov r6,a 
                                   4119 	.endif 
                           000001  4120 	.if (((0x18cba80)>>8)&0xff) 
      0007F0 74 BA            [12] 4121 	mov a,# (((0x18cba80)>>8)&0xff) 
      0007F2 8A F0            [24] 4122 	mov b,r2 
      0007F4 A4               [48] 4123 	mul ab 
      0007F5 2C               [12] 4124 	add a,r4 
      0007F6 FC               [12] 4125 	mov r4,a 
      0007F7 E5 F0            [12] 4126 	mov a,b 
      0007F9 3D               [12] 4127 	addc a,r5 
      0007FA FD               [12] 4128 	mov r5,a 
      0007FB E4               [12] 4129 	clr a 
      0007FC 3E               [12] 4130 	addc a,r6 
      0007FD FE               [12] 4131 	mov r6,a 
                                   4132 	.endif 
                           000001  4133 	.if ((0x18cba80)&0xff) 
      0007FE 74 80            [12] 4134 	mov a,# ((0x18cba80)&0xff) 
      000800 8B F0            [24] 4135 	mov b,r3 
      000802 A4               [48] 4136 	mul ab 
      000803 2C               [12] 4137 	add a,r4 
      000804 FC               [12] 4138 	mov r4,a 
      000805 E5 F0            [12] 4139 	mov a,b 
      000807 3D               [12] 4140 	addc a,r5 
      000808 FD               [12] 4141 	mov r5,a 
      000809 E4               [12] 4142 	clr a 
      00080A 3E               [12] 4143 	addc a,r6 
      00080B FE               [12] 4144 	mov r6,a 
                                   4145 	.endif 
                                   4146 ;; stage 1 
                           000001  4147 	.if (((0x18cba80)>>24)&0xff) 
      00080C 74 01            [12] 4148 	mov a,# (((0x18cba80)>>24)&0xff) 
      00080E 89 F0            [24] 4149 	mov b,r1 
      000810 A4               [48] 4150 	mul ab 
      000811 2D               [12] 4151 	add a,r5 
      000812 FD               [12] 4152 	mov r5,a 
      000813 E5 F0            [12] 4153 	mov a,b 
      000815 3E               [12] 4154 	addc a,r6 
      000816 FE               [12] 4155 	mov r6,a 
      000817 E4               [12] 4156 	clr a 
      000818 3F               [12] 4157 	addc a,r7 
      000819 FF               [12] 4158 	mov r7,a 
                                   4159 	.endif 
                           000001  4160 	.if (((0x18cba80)>>16)&0xff) 
      00081A 74 8C            [12] 4161 	mov a,# (((0x18cba80)>>16)&0xff) 
      00081C 8A F0            [24] 4162 	mov b,r2 
      00081E A4               [48] 4163 	mul ab 
      00081F 2D               [12] 4164 	add a,r5 
      000820 FD               [12] 4165 	mov r5,a 
      000821 E5 F0            [12] 4166 	mov a,b 
      000823 3E               [12] 4167 	addc a,r6 
      000824 FE               [12] 4168 	mov r6,a 
      000825 E4               [12] 4169 	clr a 
      000826 3F               [12] 4170 	addc a,r7 
      000827 FF               [12] 4171 	mov r7,a 
                                   4172 	.endif 
                           000001  4173 	.if (((0x18cba80)>>8)&0xff) 
      000828 74 BA            [12] 4174 	mov a,# (((0x18cba80)>>8)&0xff) 
      00082A 8B F0            [24] 4175 	mov b,r3 
      00082C A4               [48] 4176 	mul ab 
      00082D 2D               [12] 4177 	add a,r5 
      00082E FD               [12] 4178 	mov r5,a 
      00082F E5 F0            [12] 4179 	mov a,b 
      000831 3E               [12] 4180 	addc a,r6 
      000832 FE               [12] 4181 	mov r6,a 
      000833 E4               [12] 4182 	clr a 
      000834 3F               [12] 4183 	addc a,r7 
      000835 FF               [12] 4184 	mov r7,a 
                                   4185 	.endif 
                                   4186 ;; stage 2 
                           000001  4187 	.if (((0x18cba80)>>24)&0xff) 
      000836 74 01            [12] 4188 	mov a,# (((0x18cba80)>>24)&0xff) 
      000838 8A F0            [24] 4189 	mov b,r2 
      00083A A4               [48] 4190 	mul ab 
      00083B 2E               [12] 4191 	add a,r6 
      00083C FE               [12] 4192 	mov r6,a 
      00083D E5 F0            [12] 4193 	mov a,b 
      00083F 3F               [12] 4194 	addc a,r7 
      000840 FF               [12] 4195 	mov r7,a 
                                   4196 	.endif 
                           000001  4197 	.if (((0x18cba80)>>16)&0xff) 
      000841 74 8C            [12] 4198 	mov a,# (((0x18cba80)>>16)&0xff) 
      000843 8B F0            [24] 4199 	mov b,r3 
      000845 A4               [48] 4200 	mul ab 
      000846 2E               [12] 4201 	add a,r6 
      000847 FE               [12] 4202 	mov r6,a 
      000848 E5 F0            [12] 4203 	mov a,b 
      00084A 3F               [12] 4204 	addc a,r7 
      00084B FF               [12] 4205 	mov r7,a 
                                   4206 	.endif 
                                   4207 ;; stage 3 
                           000001  4208 	.if (((0x18cba80)>>24)&0xff) 
      00084C 74 01            [12] 4209 	mov a,# (((0x18cba80)>>24)&0xff) 
      00084E 8B F0            [24] 4210 	mov b,r3 
      000850 A4               [48] 4211 	mul ab 
      000851 2F               [12] 4212 	add a,r7 
      000852 FF               [12] 4213 	mov r7,a 
                                   4214 	.endif 
      000853 D0 E0            [24] 4215 	pop acc 
      000855 30 E7 11         [24] 4216 	jnb acc.7,00001$ 
      000858 C3               [12] 4217 	clr c 
      000859 E4               [12] 4218 	clr a 
      00085A 9C               [12] 4219 	subb a,r4 
      00085B F5 82            [12] 4220 	mov dpl,a 
      00085D E4               [12] 4221 	clr a 
      00085E 9D               [12] 4222 	subb a,r5 
      00085F F5 83            [12] 4223 	mov dph,a 
      000861 E4               [12] 4224 	clr a 
      000862 9E               [12] 4225 	subb a,r6 
      000863 F5 F0            [12] 4226 	mov b,a 
      000865 E4               [12] 4227 	clr a 
      000866 9F               [12] 4228 	subb a,r7 
      000867 80 07            [24] 4229 	sjmp 00002$ 
      000869                       4230 	 00001$:
      000869 8C 82            [24] 4231 	mov dpl,r4 
      00086B 8D 83            [24] 4232 	mov dph,r5 
      00086D 8E F0            [24] 4233 	mov b,r6 
      00086F EF               [12] 4234 	mov a,r7 
      000870                       4235 	 00002$:
                           0004D8  4236 	C$config.c$633$1$336 ==.
                           0004D8  4237 	XG$axradio_conv_freq_tohz$0$0 ==.
      000870 22               [24] 4238 	ret
                                   4239 ;------------------------------------------------------------
                                   4240 ;Allocation info for local variables in function 'axradio_conv_freq_fromreg'
                                   4241 ;------------------------------------------------------------
                                   4242 ;f                         Allocated to registers 
                                   4243 ;------------------------------------------------------------
                           0004D9  4244 	G$axradio_conv_freq_fromreg$0$0 ==.
                           0004D9  4245 	C$config.c$640$1$336 ==.
                                   4246 ;	..\AX_Radio_Lab_output\config.c:640: int32_t axradio_conv_freq_fromreg(int32_t f)
                                   4247 ;	-----------------------------------------
                                   4248 ;	 function axradio_conv_freq_fromreg
                                   4249 ;	-----------------------------------------
      000871                       4250 _axradio_conv_freq_fromreg:
                           0004D9  4251 	C$config.c$646$1$338 ==.
                                   4252 ;	..\AX_Radio_Lab_output\config.c:646: CONSTMULFIX16(0x1000000);
      000871 A8 82            [24] 4253 	mov r0,dpl 
      000873 E5 83            [12] 4254 	mov a,dph 
      000875 F9               [12] 4255 	mov r1,a 
      000876 C0 E0            [24] 4256 	push acc 
      000878 30 E7 07         [24] 4257 	jnb acc.7,00000$ 
      00087B C3               [12] 4258 	clr c 
      00087C E4               [12] 4259 	clr a 
      00087D 98               [12] 4260 	subb a,r0 
      00087E F8               [12] 4261 	mov r0,a 
      00087F E4               [12] 4262 	clr a 
      000880 99               [12] 4263 	subb a,r1 
      000881 F9               [12] 4264 	mov r1,a 
      000882                       4265 	 00000$:
      000882 E4               [12] 4266 	clr a 
      000883 FC               [12] 4267 	mov r4,a 
      000884 FD               [12] 4268 	mov r5,a 
      000885 FE               [12] 4269 	mov r6,a 
      000886 FF               [12] 4270 	mov r7,a 
                                   4271 ;; stage -1 
                           000000  4272 	.if (((0x1000000)>>16)&0xff) 
                                   4273 	mov a,# (((0x1000000)>>16)&0xff) 
                                   4274 	mov b,r0 
                                   4275 	mul ab 
                                   4276 	mov r7,a 
                                   4277 	mov r4,b 
                                   4278 	.endif 
                           000000  4279 	.if (((0x1000000)>>8)&0xff) 
                                   4280 	mov a,# (((0x1000000)>>8)&0xff) 
                                   4281 	mov b,r1 
                                   4282 	mul ab 
                                   4283 	.if (((0x1000000)>>16)&0xff) 
                                   4284 	add a,r7 
                                   4285 	mov r7,a 
                                   4286 	mov a,b 
                                   4287 	addc a,r4 
                                   4288 	mov r4,a 
                                   4289 	clr a 
                                   4290 	addc a,r5 
                                   4291 	mov r5,a 
                                   4292 	.else 
                                   4293 	mov r7,a 
                                   4294 	mov r4,b 
                                   4295 	.endif 
                                   4296 	.endif 
                                   4297 ;; clear precision extension 
      000887 E4               [12] 4298 	clr a 
      000888 FF               [12] 4299 	mov r7,a 
                                   4300 ;; stage 0 
                           000001  4301 	.if (((0x1000000)>>24)&0xff) 
      000889 74 01            [12] 4302 	mov a,# (((0x1000000)>>24)&0xff) 
      00088B 88 F0            [24] 4303 	mov b,r0 
      00088D A4               [48] 4304 	mul ab 
      00088E 2C               [12] 4305 	add a,r4 
      00088F FC               [12] 4306 	mov r4,a 
      000890 E5 F0            [12] 4307 	mov a,b 
      000892 3D               [12] 4308 	addc a,r5 
      000893 FD               [12] 4309 	mov r5,a 
      000894 E4               [12] 4310 	clr a 
      000895 3E               [12] 4311 	addc a,r6 
      000896 FE               [12] 4312 	mov r6,a 
                                   4313 	.endif 
                           000000  4314 	.if (((0x1000000)>>16)&0xff) 
                                   4315 	mov a,# (((0x1000000)>>16)&0xff) 
                                   4316 	mov b,r1 
                                   4317 	mul ab 
                                   4318 	add a,r4 
                                   4319 	mov r4,a 
                                   4320 	mov a,b 
                                   4321 	addc a,r5 
                                   4322 	mov r5,a 
                                   4323 	clr a 
                                   4324 	addc a,r6 
                                   4325 	mov r6,a 
                                   4326 	.endif 
                                   4327 ;; stage 1 
                           000001  4328 	.if (((0x1000000)>>24)&0xff) 
      000897 74 01            [12] 4329 	mov a,# (((0x1000000)>>24)&0xff) 
      000899 89 F0            [24] 4330 	mov b,r1 
      00089B A4               [48] 4331 	mul ab 
      00089C 2D               [12] 4332 	add a,r5 
      00089D FD               [12] 4333 	mov r5,a 
      00089E E5 F0            [12] 4334 	mov a,b 
      0008A0 3E               [12] 4335 	addc a,r6 
      0008A1 FE               [12] 4336 	mov r6,a 
      0008A2 E4               [12] 4337 	clr a 
      0008A3 3F               [12] 4338 	addc a,r7 
      0008A4 FF               [12] 4339 	mov r7,a 
                                   4340 	.endif 
      0008A5 D0 E0            [24] 4341 	pop acc 
      0008A7 30 E7 11         [24] 4342 	jnb acc.7,00001$ 
      0008AA C3               [12] 4343 	clr c 
      0008AB E4               [12] 4344 	clr a 
      0008AC 9C               [12] 4345 	subb a,r4 
      0008AD F5 82            [12] 4346 	mov dpl,a 
      0008AF E4               [12] 4347 	clr a 
      0008B0 9D               [12] 4348 	subb a,r5 
      0008B1 F5 83            [12] 4349 	mov dph,a 
      0008B3 E4               [12] 4350 	clr a 
      0008B4 9E               [12] 4351 	subb a,r6 
      0008B5 F5 F0            [12] 4352 	mov b,a 
      0008B7 E4               [12] 4353 	clr a 
      0008B8 9F               [12] 4354 	subb a,r7 
      0008B9 80 07            [24] 4355 	sjmp 00002$ 
      0008BB                       4356 	 00001$:
      0008BB 8C 82            [24] 4357 	mov dpl,r4 
      0008BD 8D 83            [24] 4358 	mov dph,r5 
      0008BF 8E F0            [24] 4359 	mov b,r6 
      0008C1 EF               [12] 4360 	mov a,r7 
      0008C2                       4361 	 00002$:
                           00052A  4362 	C$config.c$647$1$338 ==.
                           00052A  4363 	XG$axradio_conv_freq_fromreg$0$0 ==.
      0008C2 22               [24] 4364 	ret
                                   4365 ;------------------------------------------------------------
                                   4366 ;Allocation info for local variables in function 'axradio_conv_timeinterval_totimer0'
                                   4367 ;------------------------------------------------------------
                                   4368 ;dt                        Allocated to registers r4 r5 r6 r7 
                                   4369 ;r                         Allocated to registers r0 r1 r2 r3 
                                   4370 ;------------------------------------------------------------
                           00052B  4371 	G$axradio_conv_timeinterval_totimer0$0$0 ==.
                           00052B  4372 	C$config.c$652$1$338 ==.
                                   4373 ;	..\AX_Radio_Lab_output\config.c:652: int32_t axradio_conv_timeinterval_totimer0(int32_t dt)
                                   4374 ;	-----------------------------------------
                                   4375 ;	 function axradio_conv_timeinterval_totimer0
                                   4376 ;	-----------------------------------------
      0008C3                       4377 _axradio_conv_timeinterval_totimer0:
      0008C3 AC 82            [24] 4378 	mov	r4,dpl
      0008C5 AD 83            [24] 4379 	mov	r5,dph
      0008C7 AE F0            [24] 4380 	mov	r6,b
      0008C9 FF               [12] 4381 	mov	r7,a
                           000532  4382 	C$config.c$659$1$340 ==.
                                   4383 ;	..\AX_Radio_Lab_output\config.c:659: dt >>= 6;
      0008CA ED               [12] 4384 	mov	a,r5
      0008CB A2 E7            [12] 4385 	mov	c,acc.7
      0008CD CC               [12] 4386 	xch	a,r4
      0008CE 33               [12] 4387 	rlc	a
      0008CF CC               [12] 4388 	xch	a,r4
      0008D0 33               [12] 4389 	rlc	a
      0008D1 A2 E7            [12] 4390 	mov	c,acc.7
      0008D3 CC               [12] 4391 	xch	a,r4
      0008D4 33               [12] 4392 	rlc	a
      0008D5 CC               [12] 4393 	xch	a,r4
      0008D6 33               [12] 4394 	rlc	a
      0008D7 CC               [12] 4395 	xch	a,r4
      0008D8 54 03            [12] 4396 	anl	a,#0x03
      0008DA FD               [12] 4397 	mov	r5,a
      0008DB EE               [12] 4398 	mov	a,r6
      0008DC 2E               [12] 4399 	add	a,r6
      0008DD 25 E0            [12] 4400 	add	a,acc
      0008DF 4D               [12] 4401 	orl	a,r5
      0008E0 FD               [12] 4402 	mov	r5,a
      0008E1 EF               [12] 4403 	mov	a,r7
      0008E2 A2 E7            [12] 4404 	mov	c,acc.7
      0008E4 CE               [12] 4405 	xch	a,r6
      0008E5 33               [12] 4406 	rlc	a
      0008E6 CE               [12] 4407 	xch	a,r6
      0008E7 33               [12] 4408 	rlc	a
      0008E8 A2 E7            [12] 4409 	mov	c,acc.7
      0008EA CE               [12] 4410 	xch	a,r6
      0008EB 33               [12] 4411 	rlc	a
      0008EC CE               [12] 4412 	xch	a,r6
      0008ED 33               [12] 4413 	rlc	a
      0008EE CE               [12] 4414 	xch	a,r6
      0008EF 54 03            [12] 4415 	anl	a,#0x03
      0008F1 30 E1 02         [24] 4416 	jnb	acc.1,00103$
      0008F4 44 FC            [12] 4417 	orl	a,#0xfc
      0008F6                       4418 00103$:
      0008F6 FF               [12] 4419 	mov	r7,a
                           00055F  4420 	C$config.c$660$1$340 ==.
                                   4421 ;	..\AX_Radio_Lab_output\config.c:660: r = dt;
      0008F7 8C 00            [24] 4422 	mov	ar0,r4
      0008F9 8D 01            [24] 4423 	mov	ar1,r5
      0008FB 8E 02            [24] 4424 	mov	ar2,r6
                           000565  4425 	C$config.c$661$1$340 ==.
                                   4426 ;	..\AX_Radio_Lab_output\config.c:661: dt >>= 2;
      0008FD EF               [12] 4427 	mov	a,r7
      0008FE FB               [12] 4428 	mov	r3,a
      0008FF A2 E7            [12] 4429 	mov	c,acc.7
      000901 13               [12] 4430 	rrc	a
      000902 FF               [12] 4431 	mov	r7,a
      000903 EE               [12] 4432 	mov	a,r6
      000904 13               [12] 4433 	rrc	a
      000905 FE               [12] 4434 	mov	r6,a
      000906 ED               [12] 4435 	mov	a,r5
      000907 13               [12] 4436 	rrc	a
      000908 FD               [12] 4437 	mov	r5,a
      000909 EC               [12] 4438 	mov	a,r4
      00090A 13               [12] 4439 	rrc	a
      00090B FC               [12] 4440 	mov	r4,a
      00090C EF               [12] 4441 	mov	a,r7
      00090D A2 E7            [12] 4442 	mov	c,acc.7
      00090F 13               [12] 4443 	rrc	a
      000910 FF               [12] 4444 	mov	r7,a
      000911 EE               [12] 4445 	mov	a,r6
      000912 13               [12] 4446 	rrc	a
      000913 FE               [12] 4447 	mov	r6,a
      000914 ED               [12] 4448 	mov	a,r5
      000915 13               [12] 4449 	rrc	a
      000916 FD               [12] 4450 	mov	r5,a
      000917 EC               [12] 4451 	mov	a,r4
      000918 13               [12] 4452 	rrc	a
                           000581  4453 	C$config.c$662$1$340 ==.
                                   4454 ;	..\AX_Radio_Lab_output\config.c:662: r += dt;
      000919 FC               [12] 4455 	mov	r4,a
      00091A 28               [12] 4456 	add	a,r0
      00091B F8               [12] 4457 	mov	r0,a
      00091C ED               [12] 4458 	mov	a,r5
      00091D 39               [12] 4459 	addc	a,r1
      00091E F9               [12] 4460 	mov	r1,a
      00091F EE               [12] 4461 	mov	a,r6
      000920 3A               [12] 4462 	addc	a,r2
      000921 FA               [12] 4463 	mov	r2,a
      000922 EF               [12] 4464 	mov	a,r7
      000923 3B               [12] 4465 	addc	a,r3
      000924 FB               [12] 4466 	mov	r3,a
                           00058D  4467 	C$config.c$663$1$340 ==.
                                   4468 ;	..\AX_Radio_Lab_output\config.c:663: dt >>= 3;
      000925 ED               [12] 4469 	mov	a,r5
      000926 C4               [12] 4470 	swap	a
      000927 23               [12] 4471 	rl	a
      000928 CC               [12] 4472 	xch	a,r4
      000929 C4               [12] 4473 	swap	a
      00092A 23               [12] 4474 	rl	a
      00092B 54 1F            [12] 4475 	anl	a,#0x1f
      00092D 6C               [12] 4476 	xrl	a,r4
      00092E CC               [12] 4477 	xch	a,r4
      00092F 54 1F            [12] 4478 	anl	a,#0x1f
      000931 CC               [12] 4479 	xch	a,r4
      000932 6C               [12] 4480 	xrl	a,r4
      000933 CC               [12] 4481 	xch	a,r4
      000934 FD               [12] 4482 	mov	r5,a
      000935 EE               [12] 4483 	mov	a,r6
      000936 C4               [12] 4484 	swap	a
      000937 23               [12] 4485 	rl	a
      000938 54 E0            [12] 4486 	anl	a,#0xe0
      00093A 4D               [12] 4487 	orl	a,r5
      00093B FD               [12] 4488 	mov	r5,a
      00093C EF               [12] 4489 	mov	a,r7
      00093D C4               [12] 4490 	swap	a
      00093E 23               [12] 4491 	rl	a
      00093F CE               [12] 4492 	xch	a,r6
      000940 C4               [12] 4493 	swap	a
      000941 23               [12] 4494 	rl	a
      000942 54 1F            [12] 4495 	anl	a,#0x1f
      000944 6E               [12] 4496 	xrl	a,r6
      000945 CE               [12] 4497 	xch	a,r6
      000946 54 1F            [12] 4498 	anl	a,#0x1f
      000948 CE               [12] 4499 	xch	a,r6
      000949 6E               [12] 4500 	xrl	a,r6
      00094A CE               [12] 4501 	xch	a,r6
      00094B 30 E4 02         [24] 4502 	jnb	acc.4,00104$
      00094E 44 E0            [12] 4503 	orl	a,#0xe0
      000950                       4504 00104$:
      000950 FF               [12] 4505 	mov	r7,a
                           0005B9  4506 	C$config.c$664$1$340 ==.
                                   4507 ;	..\AX_Radio_Lab_output\config.c:664: r += dt;
      000951 EC               [12] 4508 	mov	a,r4
      000952 28               [12] 4509 	add	a,r0
      000953 F8               [12] 4510 	mov	r0,a
      000954 ED               [12] 4511 	mov	a,r5
      000955 39               [12] 4512 	addc	a,r1
      000956 F9               [12] 4513 	mov	r1,a
      000957 EE               [12] 4514 	mov	a,r6
      000958 3A               [12] 4515 	addc	a,r2
      000959 FA               [12] 4516 	mov	r2,a
      00095A EF               [12] 4517 	mov	a,r7
      00095B 3B               [12] 4518 	addc	a,r3
      00095C FB               [12] 4519 	mov	r3,a
                           0005C5  4520 	C$config.c$665$1$340 ==.
                                   4521 ;	..\AX_Radio_Lab_output\config.c:665: dt >>= 2;
      00095D EF               [12] 4522 	mov	a,r7
      00095E A2 E7            [12] 4523 	mov	c,acc.7
      000960 13               [12] 4524 	rrc	a
      000961 FF               [12] 4525 	mov	r7,a
      000962 EE               [12] 4526 	mov	a,r6
      000963 13               [12] 4527 	rrc	a
      000964 FE               [12] 4528 	mov	r6,a
      000965 ED               [12] 4529 	mov	a,r5
      000966 13               [12] 4530 	rrc	a
      000967 FD               [12] 4531 	mov	r5,a
      000968 EC               [12] 4532 	mov	a,r4
      000969 13               [12] 4533 	rrc	a
      00096A FC               [12] 4534 	mov	r4,a
      00096B EF               [12] 4535 	mov	a,r7
      00096C A2 E7            [12] 4536 	mov	c,acc.7
      00096E 13               [12] 4537 	rrc	a
      00096F FF               [12] 4538 	mov	r7,a
      000970 EE               [12] 4539 	mov	a,r6
      000971 13               [12] 4540 	rrc	a
      000972 FE               [12] 4541 	mov	r6,a
      000973 ED               [12] 4542 	mov	a,r5
      000974 13               [12] 4543 	rrc	a
      000975 FD               [12] 4544 	mov	r5,a
      000976 EC               [12] 4545 	mov	a,r4
      000977 13               [12] 4546 	rrc	a
                           0005E0  4547 	C$config.c$666$1$340 ==.
                                   4548 ;	..\AX_Radio_Lab_output\config.c:666: r += dt;
      000978 28               [12] 4549 	add	a,r0
      000979 F8               [12] 4550 	mov	r0,a
      00097A ED               [12] 4551 	mov	a,r5
      00097B 39               [12] 4552 	addc	a,r1
      00097C F9               [12] 4553 	mov	r1,a
      00097D EE               [12] 4554 	mov	a,r6
      00097E 3A               [12] 4555 	addc	a,r2
      00097F FA               [12] 4556 	mov	r2,a
      000980 EF               [12] 4557 	mov	a,r7
      000981 3B               [12] 4558 	addc	a,r3
                           0005EA  4559 	C$config.c$667$1$340 ==.
                                   4560 ;	..\AX_Radio_Lab_output\config.c:667: return r;
      000982 88 82            [24] 4561 	mov	dpl,r0
      000984 89 83            [24] 4562 	mov	dph,r1
      000986 8A F0            [24] 4563 	mov	b,r2
                           0005F0  4564 	C$config.c$668$1$340 ==.
                           0005F0  4565 	XG$axradio_conv_timeinterval_totimer0$0$0 ==.
      000988 22               [24] 4566 	ret
                                   4567 ;------------------------------------------------------------
                                   4568 ;Allocation info for local variables in function 'axradio_byteconv'
                                   4569 ;------------------------------------------------------------
                                   4570 ;b                         Allocated to registers r7 
                                   4571 ;------------------------------------------------------------
                           0005F1  4572 	G$axradio_byteconv$0$0 ==.
                           0005F1  4573 	C$config.c$670$1$340 ==.
                                   4574 ;	..\AX_Radio_Lab_output\config.c:670: __reentrantb uint8_t axradio_byteconv(uint8_t b) __reentrant
                                   4575 ;	-----------------------------------------
                                   4576 ;	 function axradio_byteconv
                                   4577 ;	-----------------------------------------
      000989                       4578 _axradio_byteconv:
                           0005F1  4579 	C$config.c$672$1$342 ==.
                                   4580 ;	..\AX_Radio_Lab_output\config.c:672: return rev8(b);
      000989 12 48 7A         [24] 4581 	lcall	_rev8
                           0005F4  4582 	C$config.c$673$1$342 ==.
                           0005F4  4583 	XG$axradio_byteconv$0$0 ==.
      00098C 22               [24] 4584 	ret
                                   4585 ;------------------------------------------------------------
                                   4586 ;Allocation info for local variables in function 'axradio_byteconv_buffer'
                                   4587 ;------------------------------------------------------------
                                   4588 ;buflen                    Allocated to stack - _bp -4
                                   4589 ;buf                       Allocated to registers 
                                   4590 ;------------------------------------------------------------
                           0005F5  4591 	G$axradio_byteconv_buffer$0$0 ==.
                           0005F5  4592 	C$config.c$676$1$342 ==.
                                   4593 ;	..\AX_Radio_Lab_output\config.c:676: __reentrantb void axradio_byteconv_buffer(uint8_t __xdata *buf, uint16_t buflen) __reentrant
                                   4594 ;	-----------------------------------------
                                   4595 ;	 function axradio_byteconv_buffer
                                   4596 ;	-----------------------------------------
      00098D                       4597 _axradio_byteconv_buffer:
      00098D C0 1E            [24] 4598 	push	_bp
      00098F 85 81 1E         [24] 4599 	mov	_bp,sp
      000992 AE 82            [24] 4600 	mov	r6,dpl
      000994 AF 83            [24] 4601 	mov	r7,dph
                           0005FE  4602 	C$config.c$678$1$344 ==.
                                   4603 ;	..\AX_Radio_Lab_output\config.c:678: while (buflen) {
      000996 E5 1E            [12] 4604 	mov	a,_bp
      000998 24 FC            [12] 4605 	add	a,#0xfc
      00099A F8               [12] 4606 	mov	r0,a
      00099B 86 04            [24] 4607 	mov	ar4,@r0
      00099D 08               [12] 4608 	inc	r0
      00099E 86 05            [24] 4609 	mov	ar5,@r0
      0009A0                       4610 00101$:
      0009A0 EC               [12] 4611 	mov	a,r4
      0009A1 4D               [12] 4612 	orl	a,r5
      0009A2 60 2E            [24] 4613 	jz	00104$
                           00060C  4614 	C$config.c$679$2$345 ==.
                                   4615 ;	..\AX_Radio_Lab_output\config.c:679: *buf = rev8(*buf);
      0009A4 8E 82            [24] 4616 	mov	dpl,r6
      0009A6 8F 83            [24] 4617 	mov	dph,r7
      0009A8 E0               [24] 4618 	movx	a,@dptr
      0009A9 F5 82            [12] 4619 	mov	dpl,a
      0009AB C0 07            [24] 4620 	push	ar7
      0009AD C0 06            [24] 4621 	push	ar6
      0009AF C0 05            [24] 4622 	push	ar5
      0009B1 C0 04            [24] 4623 	push	ar4
      0009B3 12 48 7A         [24] 4624 	lcall	_rev8
      0009B6 AB 82            [24] 4625 	mov	r3,dpl
      0009B8 D0 04            [24] 4626 	pop	ar4
      0009BA D0 05            [24] 4627 	pop	ar5
      0009BC D0 06            [24] 4628 	pop	ar6
      0009BE D0 07            [24] 4629 	pop	ar7
      0009C0 8E 82            [24] 4630 	mov	dpl,r6
      0009C2 8F 83            [24] 4631 	mov	dph,r7
      0009C4 EB               [12] 4632 	mov	a,r3
      0009C5 F0               [24] 4633 	movx	@dptr,a
      0009C6 A3               [24] 4634 	inc	dptr
      0009C7 AE 82            [24] 4635 	mov	r6,dpl
      0009C9 AF 83            [24] 4636 	mov	r7,dph
                           000633  4637 	C$config.c$680$2$345 ==.
                                   4638 ;	..\AX_Radio_Lab_output\config.c:680: ++buf;
                           000633  4639 	C$config.c$681$2$345 ==.
                                   4640 ;	..\AX_Radio_Lab_output\config.c:681: --buflen;
      0009CB 1C               [12] 4641 	dec	r4
      0009CC BC FF 01         [24] 4642 	cjne	r4,#0xff,00114$
      0009CF 1D               [12] 4643 	dec	r5
      0009D0                       4644 00114$:
      0009D0 80 CE            [24] 4645 	sjmp	00101$
      0009D2                       4646 00104$:
      0009D2 D0 1E            [24] 4647 	pop	_bp
                           00063C  4648 	C$config.c$683$1$344 ==.
                           00063C  4649 	XG$axradio_byteconv_buffer$0$0 ==.
      0009D4 22               [24] 4650 	ret
                                   4651 ;------------------------------------------------------------
                                   4652 ;Allocation info for local variables in function 'axradio_framing_check_crc'
                                   4653 ;------------------------------------------------------------
                                   4654 ;cnt                       Allocated to stack - _bp -4
                                   4655 ;pkt                       Allocated to registers r6 r7 
                                   4656 ;------------------------------------------------------------
                           00063D  4657 	G$axradio_framing_check_crc$0$0 ==.
                           00063D  4658 	C$config.c$685$1$344 ==.
                                   4659 ;	..\AX_Radio_Lab_output\config.c:685: __reentrantb uint16_t axradio_framing_check_crc(uint8_t __xdata *pkt, uint16_t cnt) __reentrant
                                   4660 ;	-----------------------------------------
                                   4661 ;	 function axradio_framing_check_crc
                                   4662 ;	-----------------------------------------
      0009D5                       4663 _axradio_framing_check_crc:
      0009D5 C0 1E            [24] 4664 	push	_bp
      0009D7 85 81 1E         [24] 4665 	mov	_bp,sp
      0009DA AE 82            [24] 4666 	mov	r6,dpl
      0009DC AF 83            [24] 4667 	mov	r7,dph
                           000646  4668 	C$config.c$687$1$347 ==.
                                   4669 ;	..\AX_Radio_Lab_output\config.c:687: if (crc_crc16_msb(pkt, cnt, 0xFFFF) != 0x0000)
      0009DE 7D 00            [12] 4670 	mov	r5,#0x00
      0009E0 74 FF            [12] 4671 	mov	a,#0xff
      0009E2 C0 E0            [24] 4672 	push	acc
      0009E4 C0 E0            [24] 4673 	push	acc
      0009E6 E5 1E            [12] 4674 	mov	a,_bp
      0009E8 24 FC            [12] 4675 	add	a,#0xfc
      0009EA F8               [12] 4676 	mov	r0,a
      0009EB E6               [12] 4677 	mov	a,@r0
      0009EC C0 E0            [24] 4678 	push	acc
      0009EE 08               [12] 4679 	inc	r0
      0009EF E6               [12] 4680 	mov	a,@r0
      0009F0 C0 E0            [24] 4681 	push	acc
      0009F2 8E 82            [24] 4682 	mov	dpl,r6
      0009F4 8F 83            [24] 4683 	mov	dph,r7
      0009F6 8D F0            [24] 4684 	mov	b,r5
      0009F8 12 4A 9D         [24] 4685 	lcall	_crc_crc16_msb
      0009FB AE 82            [24] 4686 	mov	r6,dpl
      0009FD AF 83            [24] 4687 	mov	r7,dph
      0009FF E5 81            [12] 4688 	mov	a,sp
      000A01 24 FC            [12] 4689 	add	a,#0xfc
      000A03 F5 81            [12] 4690 	mov	sp,a
      000A05 EE               [12] 4691 	mov	a,r6
      000A06 4F               [12] 4692 	orl	a,r7
      000A07 60 05            [24] 4693 	jz	00102$
                           000671  4694 	C$config.c$688$1$347 ==.
                                   4695 ;	..\AX_Radio_Lab_output\config.c:688: return 0;
      000A09 90 00 00         [24] 4696 	mov	dptr,#0x0000
      000A0C 80 0A            [24] 4697 	sjmp	00103$
      000A0E                       4698 00102$:
                           000676  4699 	C$config.c$689$1$347 ==.
                                   4700 ;	..\AX_Radio_Lab_output\config.c:689: return cnt;
      000A0E E5 1E            [12] 4701 	mov	a,_bp
      000A10 24 FC            [12] 4702 	add	a,#0xfc
      000A12 F8               [12] 4703 	mov	r0,a
      000A13 86 82            [24] 4704 	mov	dpl,@r0
      000A15 08               [12] 4705 	inc	r0
      000A16 86 83            [24] 4706 	mov	dph,@r0
      000A18                       4707 00103$:
      000A18 D0 1E            [24] 4708 	pop	_bp
                           000682  4709 	C$config.c$690$1$347 ==.
                           000682  4710 	XG$axradio_framing_check_crc$0$0 ==.
      000A1A 22               [24] 4711 	ret
                                   4712 ;------------------------------------------------------------
                                   4713 ;Allocation info for local variables in function 'axradio_framing_append_crc'
                                   4714 ;------------------------------------------------------------
                                   4715 ;cnt                       Allocated to stack - _bp -4
                                   4716 ;pkt                       Allocated to registers r6 r7 
                                   4717 ;s                         Allocated to registers r4 r5 
                                   4718 ;------------------------------------------------------------
                           000683  4719 	G$axradio_framing_append_crc$0$0 ==.
                           000683  4720 	C$config.c$692$1$347 ==.
                                   4721 ;	..\AX_Radio_Lab_output\config.c:692: __reentrantb uint16_t axradio_framing_append_crc(uint8_t __xdata *pkt, uint16_t cnt) __reentrant
                                   4722 ;	-----------------------------------------
                                   4723 ;	 function axradio_framing_append_crc
                                   4724 ;	-----------------------------------------
      000A1B                       4725 _axradio_framing_append_crc:
      000A1B C0 1E            [24] 4726 	push	_bp
      000A1D 85 81 1E         [24] 4727 	mov	_bp,sp
      000A20 AE 82            [24] 4728 	mov	r6,dpl
      000A22 AF 83            [24] 4729 	mov	r7,dph
                           00068C  4730 	C$config.c$695$1$349 ==.
                                   4731 ;	..\AX_Radio_Lab_output\config.c:695: s = crc_crc16_msb(pkt, cnt, s);
      000A24 8E 03            [24] 4732 	mov	ar3,r6
      000A26 8F 04            [24] 4733 	mov	ar4,r7
      000A28 7D 00            [12] 4734 	mov	r5,#0x00
      000A2A C0 07            [24] 4735 	push	ar7
      000A2C C0 06            [24] 4736 	push	ar6
      000A2E 74 FF            [12] 4737 	mov	a,#0xff
      000A30 C0 E0            [24] 4738 	push	acc
      000A32 C0 E0            [24] 4739 	push	acc
      000A34 E5 1E            [12] 4740 	mov	a,_bp
      000A36 24 FC            [12] 4741 	add	a,#0xfc
      000A38 F8               [12] 4742 	mov	r0,a
      000A39 E6               [12] 4743 	mov	a,@r0
      000A3A C0 E0            [24] 4744 	push	acc
      000A3C 08               [12] 4745 	inc	r0
      000A3D E6               [12] 4746 	mov	a,@r0
      000A3E C0 E0            [24] 4747 	push	acc
      000A40 8B 82            [24] 4748 	mov	dpl,r3
      000A42 8C 83            [24] 4749 	mov	dph,r4
      000A44 8D F0            [24] 4750 	mov	b,r5
      000A46 12 4A 9D         [24] 4751 	lcall	_crc_crc16_msb
      000A49 AC 82            [24] 4752 	mov	r4,dpl
      000A4B AD 83            [24] 4753 	mov	r5,dph
      000A4D E5 81            [12] 4754 	mov	a,sp
      000A4F 24 FC            [12] 4755 	add	a,#0xfc
      000A51 F5 81            [12] 4756 	mov	sp,a
      000A53 D0 06            [24] 4757 	pop	ar6
      000A55 D0 07            [24] 4758 	pop	ar7
                           0006BF  4759 	C$config.c$696$1$349 ==.
                                   4760 ;	..\AX_Radio_Lab_output\config.c:696: pkt += cnt;
      000A57 E5 1E            [12] 4761 	mov	a,_bp
      000A59 24 FC            [12] 4762 	add	a,#0xfc
      000A5B F8               [12] 4763 	mov	r0,a
      000A5C E6               [12] 4764 	mov	a,@r0
      000A5D 2E               [12] 4765 	add	a,r6
      000A5E FE               [12] 4766 	mov	r6,a
      000A5F 08               [12] 4767 	inc	r0
      000A60 E6               [12] 4768 	mov	a,@r0
      000A61 3F               [12] 4769 	addc	a,r7
      000A62 FF               [12] 4770 	mov	r7,a
                           0006CB  4771 	C$config.c$697$1$349 ==.
                                   4772 ;	..\AX_Radio_Lab_output\config.c:697: *pkt++ = (uint8_t)(s >> 8);
      000A63 8D 03            [24] 4773 	mov	ar3,r5
      000A65 8E 82            [24] 4774 	mov	dpl,r6
      000A67 8F 83            [24] 4775 	mov	dph,r7
      000A69 EB               [12] 4776 	mov	a,r3
      000A6A F0               [24] 4777 	movx	@dptr,a
      000A6B A3               [24] 4778 	inc	dptr
                           0006D4  4779 	C$config.c$698$1$349 ==.
                                   4780 ;	..\AX_Radio_Lab_output\config.c:698: *pkt++ = (uint8_t)(s);
      000A6C EC               [12] 4781 	mov	a,r4
      000A6D F0               [24] 4782 	movx	@dptr,a
                           0006D6  4783 	C$config.c$699$1$349 ==.
                                   4784 ;	..\AX_Radio_Lab_output\config.c:699: return cnt + 2;
      000A6E E5 1E            [12] 4785 	mov	a,_bp
      000A70 24 FC            [12] 4786 	add	a,#0xfc
      000A72 F8               [12] 4787 	mov	r0,a
      000A73 86 82            [24] 4788 	mov	dpl,@r0
      000A75 08               [12] 4789 	inc	r0
      000A76 86 83            [24] 4790 	mov	dph,@r0
      000A78 A3               [24] 4791 	inc	dptr
      000A79 A3               [24] 4792 	inc	dptr
      000A7A D0 1E            [24] 4793 	pop	_bp
                           0006E4  4794 	C$config.c$700$1$349 ==.
                           0006E4  4795 	XG$axradio_framing_append_crc$0$0 ==.
      000A7C 22               [24] 4796 	ret
                                   4797 	.area CSEG    (CODE)
                                   4798 	.area CONST   (CODE)
                           000000  4799 G$axradio_phy_innerfreqloop$0$0 == .
      004D06                       4800 _axradio_phy_innerfreqloop:
      004D06 00                    4801 	.db #0x00	; 0
                           000001  4802 G$axradio_phy_pn9$0$0 == .
      004D07                       4803 _axradio_phy_pn9:
      004D07 00                    4804 	.db #0x00	; 0
                           000002  4805 G$axradio_phy_nrchannels$0$0 == .
      004D08                       4806 _axradio_phy_nrchannels:
      004D08 06                    4807 	.db #0x06	; 6
                           000003  4808 G$axradio_phy_chanfreq$0$0 == .
      004D09                       4809 _axradio_phy_chanfreq:
      004D09 57 6A 65 21           4810 	.byte #0x57,#0x6a,#0x65,#0x21	; 560294487
      004D0D 5B A9 65 21           4811 	.byte #0x5b,#0xa9,#0x65,#0x21	; 560310619
      004D11 5F E8 65 21           4812 	.byte #0x5f,#0xe8,#0x65,#0x21	; 560326751
      004D15 63 27 66 21           4813 	.byte #0x63,#0x27,#0x66,#0x21	; 560342883
      004D19 67 66 66 21           4814 	.byte #0x67,#0x66,#0x66,#0x21	; 560359015
      004D1D 6B A5 66 21           4815 	.byte #0x6b,#0xa5,#0x66,#0x21	; 560375147
                           00001B  4816 G$axradio_phy_chanpllrnginit$0$0 == .
      004D21                       4817 _axradio_phy_chanpllrnginit:
      004D21 0A 00                 4818 	.byte #0x0a,#0x00	; 10
      004D23 0A 00                 4819 	.byte #0x0a,#0x00	; 10
      004D25 0A 00                 4820 	.byte #0x0a,#0x00	; 10
      004D27 0A 00                 4821 	.byte #0x0a,#0x00	; 10
      004D29 0A 00                 4822 	.byte #0x0a,#0x00	; 10
      004D2B 0A 00                 4823 	.byte #0x0a,#0x00	; 10
                           000027  4824 G$axradio_phy_chanvcoiinit$0$0 == .
      004D2D                       4825 _axradio_phy_chanvcoiinit:
      004D2D 99                    4826 	.db #0x99	; 153
      004D2E 99                    4827 	.db #0x99	; 153
      004D2F 99                    4828 	.db #0x99	; 153
      004D30 99                    4829 	.db #0x99	; 153
      004D31 99                    4830 	.db #0x99	; 153
      004D32 99                    4831 	.db #0x99	; 153
                           00002D  4832 G$axradio_phy_vcocalib$0$0 == .
      004D33                       4833 _axradio_phy_vcocalib:
      004D33 01                    4834 	.db #0x01	; 1
                           00002E  4835 G$axradio_phy_maxfreqoffset$0$0 == .
      004D34                       4836 _axradio_phy_maxfreqoffset:
      004D34 22 0D 00 00           4837 	.byte #0x22,#0x0d,#0x00,#0x00	;  3362
                           000032  4838 G$axradio_phy_rssioffset$0$0 == .
      004D38                       4839 _axradio_phy_rssioffset:
      004D38 40                    4840 	.db #0x40	;  64
                           000033  4841 G$axradio_phy_rssireference$0$0 == .
      004D39                       4842 _axradio_phy_rssireference:
      004D39 3A                    4843 	.db #0x3a	;  58
                           000034  4844 G$axradio_phy_channelbusy$0$0 == .
      004D3A                       4845 _axradio_phy_channelbusy:
      004D3A E0                    4846 	.db #0xe0	; -32
                           000035  4847 G$axradio_phy_cs_period$0$0 == .
      004D3B                       4848 _axradio_phy_cs_period:
      004D3B 48 01                 4849 	.byte #0x48,#0x01	; 328
                           000037  4850 G$axradio_phy_cs_enabled$0$0 == .
      004D3D                       4851 _axradio_phy_cs_enabled:
      004D3D 00                    4852 	.db #0x00	; 0
                           000038  4853 G$axradio_phy_lbt_retries$0$0 == .
      004D3E                       4854 _axradio_phy_lbt_retries:
      004D3E 03                    4855 	.db #0x03	; 3
                           000039  4856 G$axradio_phy_lbt_forcetx$0$0 == .
      004D3F                       4857 _axradio_phy_lbt_forcetx:
      004D3F 00                    4858 	.db #0x00	; 0
                           00003A  4859 G$axradio_phy_preamble_wor_longlen$0$0 == .
      004D40                       4860 _axradio_phy_preamble_wor_longlen:
      004D40 04 00                 4861 	.byte #0x04,#0x00	; 4
                           00003C  4862 G$axradio_phy_preamble_wor_len$0$0 == .
      004D42                       4863 _axradio_phy_preamble_wor_len:
      004D42 A0 00                 4864 	.byte #0xa0,#0x00	; 160
                           00003E  4865 G$axradio_phy_preamble_longlen$0$0 == .
      004D44                       4866 _axradio_phy_preamble_longlen:
      004D44 00 00                 4867 	.byte #0x00,#0x00	; 0
                           000040  4868 G$axradio_phy_preamble_len$0$0 == .
      004D46                       4869 _axradio_phy_preamble_len:
      004D46 20 00                 4870 	.byte #0x20,#0x00	; 32
                           000042  4871 G$axradio_phy_preamble_byte$0$0 == .
      004D48                       4872 _axradio_phy_preamble_byte:
      004D48 AA                    4873 	.db #0xaa	; 170
                           000043  4874 G$axradio_phy_preamble_flags$0$0 == .
      004D49                       4875 _axradio_phy_preamble_flags:
      004D49 38                    4876 	.db #0x38	; 56	'8'
                           000044  4877 G$axradio_phy_preamble_appendbits$0$0 == .
      004D4A                       4878 _axradio_phy_preamble_appendbits:
      004D4A 00                    4879 	.db #0x00	; 0
                           000045  4880 G$axradio_phy_preamble_appendpattern$0$0 == .
      004D4B                       4881 _axradio_phy_preamble_appendpattern:
      004D4B 00                    4882 	.db #0x00	; 0
                           000046  4883 G$axradio_framing_maclen$0$0 == .
      004D4C                       4884 _axradio_framing_maclen:
      004D4C 05                    4885 	.db #0x05	; 5
                           000047  4886 G$axradio_framing_addrlen$0$0 == .
      004D4D                       4887 _axradio_framing_addrlen:
      004D4D 04                    4888 	.db #0x04	; 4
                           000048  4889 G$axradio_framing_destaddrpos$0$0 == .
      004D4E                       4890 _axradio_framing_destaddrpos:
      004D4E 01                    4891 	.db #0x01	; 1
                           000049  4892 G$axradio_framing_sourceaddrpos$0$0 == .
      004D4F                       4893 _axradio_framing_sourceaddrpos:
      004D4F FF                    4894 	.db #0xff	; 255
                           00004A  4895 G$axradio_framing_lenpos$0$0 == .
      004D50                       4896 _axradio_framing_lenpos:
      004D50 00                    4897 	.db #0x00	; 0
                           00004B  4898 G$axradio_framing_lenoffs$0$0 == .
      004D51                       4899 _axradio_framing_lenoffs:
      004D51 01                    4900 	.db #0x01	; 1
                           00004C  4901 G$axradio_framing_lenmask$0$0 == .
      004D52                       4902 _axradio_framing_lenmask:
      004D52 FF                    4903 	.db #0xff	; 255
                           00004D  4904 G$axradio_framing_swcrclen$0$0 == .
      004D53                       4905 _axradio_framing_swcrclen:
      004D53 02                    4906 	.db #0x02	; 2
                           00004E  4907 G$axradio_framing_synclen$0$0 == .
      004D54                       4908 _axradio_framing_synclen:
      004D54 20                    4909 	.db #0x20	; 32
                           00004F  4910 G$axradio_framing_syncword$0$0 == .
      004D55                       4911 _axradio_framing_syncword:
      004D55 93                    4912 	.db #0x93	; 147
      004D56 0B                    4913 	.db #0x0b	; 11
      004D57 51                    4914 	.db #0x51	; 81	'Q'
      004D58 DE                    4915 	.db #0xde	; 222
                           000053  4916 G$axradio_framing_syncflags$0$0 == .
      004D59                       4917 _axradio_framing_syncflags:
      004D59 38                    4918 	.db #0x38	; 56	'8'
                           000054  4919 G$axradio_framing_enable_sfdcallback$0$0 == .
      004D5A                       4920 _axradio_framing_enable_sfdcallback:
      004D5A 00                    4921 	.db #0x00	; 0
                           000055  4922 G$axradio_framing_ack_timeout$0$0 == .
      004D5B                       4923 _axradio_framing_ack_timeout:
      004D5B 35 05 00 00           4924 	.byte #0x35,#0x05,#0x00,#0x00	; 1333
                           000059  4925 G$axradio_framing_ack_delay$0$0 == .
      004D5F                       4926 _axradio_framing_ack_delay:
      004D5F 39 01 00 00           4927 	.byte #0x39,#0x01,#0x00,#0x00	; 313
                           00005D  4928 G$axradio_framing_ack_retransmissions$0$0 == .
      004D63                       4929 _axradio_framing_ack_retransmissions:
      004D63 03                    4930 	.db #0x03	; 3
                           00005E  4931 G$axradio_framing_ack_seqnrpos$0$0 == .
      004D64                       4932 _axradio_framing_ack_seqnrpos:
      004D64 FF                    4933 	.db #0xff	; 255
                           00005F  4934 G$axradio_framing_minpayloadlen$0$0 == .
      004D65                       4935 _axradio_framing_minpayloadlen:
      004D65 01                    4936 	.db #0x01	; 1
                           000060  4937 G$axradio_wor_period$0$0 == .
      004D66                       4938 _axradio_wor_period:
      004D66 80 00                 4939 	.byte #0x80,#0x00	; 128
                           000062  4940 G$axradio_sync_period$0$0 == .
      004D68                       4941 _axradio_sync_period:
      004D68 00 80 00 00           4942 	.byte #0x00,#0x80,#0x00,#0x00	; 32768
                           000066  4943 G$axradio_sync_xoscstartup$0$0 == .
      004D6C                       4944 _axradio_sync_xoscstartup:
      004D6C 31 00 00 00           4945 	.byte #0x31,#0x00,#0x00,#0x00	; 49
                           00006A  4946 G$axradio_sync_slave_syncwindow$0$0 == .
      004D70                       4947 _axradio_sync_slave_syncwindow:
      004D70 00 80 01 00           4948 	.byte #0x00,#0x80,#0x01,#0x00	; 98304
                           00006E  4949 G$axradio_sync_slave_initialsyncwindow$0$0 == .
      004D74                       4950 _axradio_sync_slave_initialsyncwindow:
      004D74 00 00 5A 00           4951 	.byte #0x00,#0x00,#0x5a,#0x00	; 5898240
                           000072  4952 G$axradio_sync_slave_syncpause$0$0 == .
      004D78                       4953 _axradio_sync_slave_syncpause:
      004D78 00 00 2C 01           4954 	.byte #0x00,#0x00,#0x2c,#0x01	; 19660800
                           000076  4955 G$axradio_sync_slave_maxperiod$0$0 == .
      004D7C                       4956 _axradio_sync_slave_maxperiod:
      004D7C E4 07                 4957 	.byte #0xe4,#0x07	;  2020
                           000078  4958 G$axradio_sync_slave_resyncloss$0$0 == .
      004D7E                       4959 _axradio_sync_slave_resyncloss:
      004D7E 0B                    4960 	.db #0x0b	; 11
                           000079  4961 G$axradio_sync_slave_nrrx$0$0 == .
      004D7F                       4962 _axradio_sync_slave_nrrx:
      004D7F 03                    4963 	.db #0x03	; 3
                           00007A  4964 G$axradio_sync_slave_rxadvance$0$0 == .
      004D80                       4965 _axradio_sync_slave_rxadvance:
      004D80 AE 02 00 00           4966 	.byte #0xae,#0x02,#0x00,#0x00	; 686
      004D84 89 02 00 00           4967 	.byte #0x89,#0x02,#0x00,#0x00	; 649
      004D88 D7 02 00 00           4968 	.byte #0xd7,#0x02,#0x00,#0x00	; 727
                           000086  4969 G$axradio_sync_slave_rxwindow$0$0 == .
      004D8C                       4970 _axradio_sync_slave_rxwindow:
      004D8C BC 02 00 00           4971 	.byte #0xbc,#0x02,#0x00,#0x00	; 700
      004D90 72 02 00 00           4972 	.byte #0x72,#0x02,#0x00,#0x00	; 626
      004D94 0E 03 00 00           4973 	.byte #0x0e,#0x03,#0x00,#0x00	; 782
                           000092  4974 G$axradio_sync_slave_rxtimeout$0$0 == .
      004D98                       4975 _axradio_sync_slave_rxtimeout:
      004D98 89 04 00 00           4976 	.byte #0x89,#0x04,#0x00,#0x00	; 1161
                           000096  4977 G$axradio_lposckfiltmax$0$0 == .
      004D9C                       4978 _axradio_lposckfiltmax:
      004D9C 2A 14                 4979 	.byte #0x2a,#0x14	; 5162
                           000098  4980 G$axradio_fxtal$0$0 == .
      004D9E                       4981 _axradio_fxtal:
      004D9E 80 BA 8C 01           4982 	.byte #0x80,#0xba,#0x8c,#0x01	; 26000000
                                   4983 	.area XINIT   (CODE)
                                   4984 	.area CABS    (ABS,CODE)
