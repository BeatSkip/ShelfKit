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
                           0000E0  1012 _ACC	=	0x00e0
                           0000F0  1013 _B	=	0x00f0
                           000083  1014 _DPH	=	0x0083
                           000085  1015 _DPH1	=	0x0085
                           000082  1016 _DPL	=	0x0082
                           000084  1017 _DPL1	=	0x0084
                           008382  1018 _DPTR0	=	0x8382
                           008584  1019 _DPTR1	=	0x8584
                           000086  1020 _DPS	=	0x0086
                           0000A0  1021 _E2IE	=	0x00a0
                           0000C0  1022 _E2IP	=	0x00c0
                           000098  1023 _EIE	=	0x0098
                           0000B0  1024 _EIP	=	0x00b0
                           0000A8  1025 _IE	=	0x00a8
                           0000B8  1026 _IP	=	0x00b8
                           000087  1027 _PCON	=	0x0087
                           0000D0  1028 _PSW	=	0x00d0
                           000081  1029 _SP	=	0x0081
                           0000D9  1030 _XPAGE	=	0x00d9
                           0000D9  1031 __XPAGE	=	0x00d9
                           0000CA  1032 _ADCCH0CONFIG	=	0x00ca
                           0000CB  1033 _ADCCH1CONFIG	=	0x00cb
                           0000D2  1034 _ADCCH2CONFIG	=	0x00d2
                           0000D3  1035 _ADCCH3CONFIG	=	0x00d3
                           0000D1  1036 _ADCCLKSRC	=	0x00d1
                           0000C9  1037 _ADCCONV	=	0x00c9
                           0000E1  1038 _ANALOGCOMP	=	0x00e1
                           0000C6  1039 _CLKCON	=	0x00c6
                           0000C7  1040 _CLKSTAT	=	0x00c7
                           000097  1041 _CODECONFIG	=	0x0097
                           0000E3  1042 _DBGLNKBUF	=	0x00e3
                           0000E2  1043 _DBGLNKSTAT	=	0x00e2
                           000089  1044 _DIRA	=	0x0089
                           00008A  1045 _DIRB	=	0x008a
                           00008B  1046 _DIRC	=	0x008b
                           00008E  1047 _DIRR	=	0x008e
                           0000C8  1048 _PINA	=	0x00c8
                           0000E8  1049 _PINB	=	0x00e8
                           0000F8  1050 _PINC	=	0x00f8
                           00008D  1051 _PINR	=	0x008d
                           000080  1052 _PORTA	=	0x0080
                           000088  1053 _PORTB	=	0x0088
                           000090  1054 _PORTC	=	0x0090
                           00008C  1055 _PORTR	=	0x008c
                           0000CE  1056 _IC0CAPT0	=	0x00ce
                           0000CF  1057 _IC0CAPT1	=	0x00cf
                           00CFCE  1058 _IC0CAPT	=	0xcfce
                           0000CC  1059 _IC0MODE	=	0x00cc
                           0000CD  1060 _IC0STATUS	=	0x00cd
                           0000D6  1061 _IC1CAPT0	=	0x00d6
                           0000D7  1062 _IC1CAPT1	=	0x00d7
                           00D7D6  1063 _IC1CAPT	=	0xd7d6
                           0000D4  1064 _IC1MODE	=	0x00d4
                           0000D5  1065 _IC1STATUS	=	0x00d5
                           000092  1066 _NVADDR0	=	0x0092
                           000093  1067 _NVADDR1	=	0x0093
                           009392  1068 _NVADDR	=	0x9392
                           000094  1069 _NVDATA0	=	0x0094
                           000095  1070 _NVDATA1	=	0x0095
                           009594  1071 _NVDATA	=	0x9594
                           000096  1072 _NVKEY	=	0x0096
                           000091  1073 _NVSTATUS	=	0x0091
                           0000BC  1074 _OC0COMP0	=	0x00bc
                           0000BD  1075 _OC0COMP1	=	0x00bd
                           00BDBC  1076 _OC0COMP	=	0xbdbc
                           0000B9  1077 _OC0MODE	=	0x00b9
                           0000BA  1078 _OC0PIN	=	0x00ba
                           0000BB  1079 _OC0STATUS	=	0x00bb
                           0000C4  1080 _OC1COMP0	=	0x00c4
                           0000C5  1081 _OC1COMP1	=	0x00c5
                           00C5C4  1082 _OC1COMP	=	0xc5c4
                           0000C1  1083 _OC1MODE	=	0x00c1
                           0000C2  1084 _OC1PIN	=	0x00c2
                           0000C3  1085 _OC1STATUS	=	0x00c3
                           0000B1  1086 _RADIOACC	=	0x00b1
                           0000B3  1087 _RADIOADDR0	=	0x00b3
                           0000B2  1088 _RADIOADDR1	=	0x00b2
                           00B2B3  1089 _RADIOADDR	=	0xb2b3
                           0000B7  1090 _RADIODATA0	=	0x00b7
                           0000B6  1091 _RADIODATA1	=	0x00b6
                           0000B5  1092 _RADIODATA2	=	0x00b5
                           0000B4  1093 _RADIODATA3	=	0x00b4
                           B4B5B6B7  1094 _RADIODATA	=	0xb4b5b6b7
                           0000BE  1095 _RADIOSTAT0	=	0x00be
                           0000BF  1096 _RADIOSTAT1	=	0x00bf
                           00BFBE  1097 _RADIOSTAT	=	0xbfbe
                           0000DF  1098 _SPCLKSRC	=	0x00df
                           0000DC  1099 _SPMODE	=	0x00dc
                           0000DE  1100 _SPSHREG	=	0x00de
                           0000DD  1101 _SPSTATUS	=	0x00dd
                           00009A  1102 _T0CLKSRC	=	0x009a
                           00009C  1103 _T0CNT0	=	0x009c
                           00009D  1104 _T0CNT1	=	0x009d
                           009D9C  1105 _T0CNT	=	0x9d9c
                           000099  1106 _T0MODE	=	0x0099
                           00009E  1107 _T0PERIOD0	=	0x009e
                           00009F  1108 _T0PERIOD1	=	0x009f
                           009F9E  1109 _T0PERIOD	=	0x9f9e
                           00009B  1110 _T0STATUS	=	0x009b
                           0000A2  1111 _T1CLKSRC	=	0x00a2
                           0000A4  1112 _T1CNT0	=	0x00a4
                           0000A5  1113 _T1CNT1	=	0x00a5
                           00A5A4  1114 _T1CNT	=	0xa5a4
                           0000A1  1115 _T1MODE	=	0x00a1
                           0000A6  1116 _T1PERIOD0	=	0x00a6
                           0000A7  1117 _T1PERIOD1	=	0x00a7
                           00A7A6  1118 _T1PERIOD	=	0xa7a6
                           0000A3  1119 _T1STATUS	=	0x00a3
                           0000AA  1120 _T2CLKSRC	=	0x00aa
                           0000AC  1121 _T2CNT0	=	0x00ac
                           0000AD  1122 _T2CNT1	=	0x00ad
                           00ADAC  1123 _T2CNT	=	0xadac
                           0000A9  1124 _T2MODE	=	0x00a9
                           0000AE  1125 _T2PERIOD0	=	0x00ae
                           0000AF  1126 _T2PERIOD1	=	0x00af
                           00AFAE  1127 _T2PERIOD	=	0xafae
                           0000AB  1128 _T2STATUS	=	0x00ab
                           0000E4  1129 _U0CTRL	=	0x00e4
                           0000E7  1130 _U0MODE	=	0x00e7
                           0000E6  1131 _U0SHREG	=	0x00e6
                           0000E5  1132 _U0STATUS	=	0x00e5
                           0000EC  1133 _U1CTRL	=	0x00ec
                           0000EF  1134 _U1MODE	=	0x00ef
                           0000EE  1135 _U1SHREG	=	0x00ee
                           0000ED  1136 _U1STATUS	=	0x00ed
                           0000DA  1137 _WDTCFG	=	0x00da
                           0000DB  1138 _WDTRESET	=	0x00db
                           0000F1  1139 _WTCFGA	=	0x00f1
                           0000F9  1140 _WTCFGB	=	0x00f9
                           0000F2  1141 _WTCNTA0	=	0x00f2
                           0000F3  1142 _WTCNTA1	=	0x00f3
                           00F3F2  1143 _WTCNTA	=	0xf3f2
                           0000FA  1144 _WTCNTB0	=	0x00fa
                           0000FB  1145 _WTCNTB1	=	0x00fb
                           00FBFA  1146 _WTCNTB	=	0xfbfa
                           0000EB  1147 _WTCNTR1	=	0x00eb
                           0000F4  1148 _WTEVTA0	=	0x00f4
                           0000F5  1149 _WTEVTA1	=	0x00f5
                           00F5F4  1150 _WTEVTA	=	0xf5f4
                           0000F6  1151 _WTEVTB0	=	0x00f6
                           0000F7  1152 _WTEVTB1	=	0x00f7
                           00F7F6  1153 _WTEVTB	=	0xf7f6
                           0000FC  1154 _WTEVTC0	=	0x00fc
                           0000FD  1155 _WTEVTC1	=	0x00fd
                           00FDFC  1156 _WTEVTC	=	0xfdfc
                           0000FE  1157 _WTEVTD0	=	0x00fe
                           0000FF  1158 _WTEVTD1	=	0x00ff
                           00FFFE  1159 _WTEVTD	=	0xfffe
                           0000E9  1160 _WTIRQEN	=	0x00e9
                           0000EA  1161 _WTSTAT	=	0x00ea
                                   1162 ;--------------------------------------------------------
                                   1163 ; special function bits
                                   1164 ;--------------------------------------------------------
                                   1165 	.area RSEG    (ABS,DATA)
      000000                       1166 	.org 0x0000
                           0000E0  1167 _ACC_0	=	0x00e0
                           0000E1  1168 _ACC_1	=	0x00e1
                           0000E2  1169 _ACC_2	=	0x00e2
                           0000E3  1170 _ACC_3	=	0x00e3
                           0000E4  1171 _ACC_4	=	0x00e4
                           0000E5  1172 _ACC_5	=	0x00e5
                           0000E6  1173 _ACC_6	=	0x00e6
                           0000E7  1174 _ACC_7	=	0x00e7
                           0000F0  1175 _B_0	=	0x00f0
                           0000F1  1176 _B_1	=	0x00f1
                           0000F2  1177 _B_2	=	0x00f2
                           0000F3  1178 _B_3	=	0x00f3
                           0000F4  1179 _B_4	=	0x00f4
                           0000F5  1180 _B_5	=	0x00f5
                           0000F6  1181 _B_6	=	0x00f6
                           0000F7  1182 _B_7	=	0x00f7
                           0000A0  1183 _E2IE_0	=	0x00a0
                           0000A1  1184 _E2IE_1	=	0x00a1
                           0000A2  1185 _E2IE_2	=	0x00a2
                           0000A3  1186 _E2IE_3	=	0x00a3
                           0000A4  1187 _E2IE_4	=	0x00a4
                           0000A5  1188 _E2IE_5	=	0x00a5
                           0000A6  1189 _E2IE_6	=	0x00a6
                           0000A7  1190 _E2IE_7	=	0x00a7
                           0000C0  1191 _E2IP_0	=	0x00c0
                           0000C1  1192 _E2IP_1	=	0x00c1
                           0000C2  1193 _E2IP_2	=	0x00c2
                           0000C3  1194 _E2IP_3	=	0x00c3
                           0000C4  1195 _E2IP_4	=	0x00c4
                           0000C5  1196 _E2IP_5	=	0x00c5
                           0000C6  1197 _E2IP_6	=	0x00c6
                           0000C7  1198 _E2IP_7	=	0x00c7
                           000098  1199 _EIE_0	=	0x0098
                           000099  1200 _EIE_1	=	0x0099
                           00009A  1201 _EIE_2	=	0x009a
                           00009B  1202 _EIE_3	=	0x009b
                           00009C  1203 _EIE_4	=	0x009c
                           00009D  1204 _EIE_5	=	0x009d
                           00009E  1205 _EIE_6	=	0x009e
                           00009F  1206 _EIE_7	=	0x009f
                           0000B0  1207 _EIP_0	=	0x00b0
                           0000B1  1208 _EIP_1	=	0x00b1
                           0000B2  1209 _EIP_2	=	0x00b2
                           0000B3  1210 _EIP_3	=	0x00b3
                           0000B4  1211 _EIP_4	=	0x00b4
                           0000B5  1212 _EIP_5	=	0x00b5
                           0000B6  1213 _EIP_6	=	0x00b6
                           0000B7  1214 _EIP_7	=	0x00b7
                           0000A8  1215 _IE_0	=	0x00a8
                           0000A9  1216 _IE_1	=	0x00a9
                           0000AA  1217 _IE_2	=	0x00aa
                           0000AB  1218 _IE_3	=	0x00ab
                           0000AC  1219 _IE_4	=	0x00ac
                           0000AD  1220 _IE_5	=	0x00ad
                           0000AE  1221 _IE_6	=	0x00ae
                           0000AF  1222 _IE_7	=	0x00af
                           0000AF  1223 _EA	=	0x00af
                           0000B8  1224 _IP_0	=	0x00b8
                           0000B9  1225 _IP_1	=	0x00b9
                           0000BA  1226 _IP_2	=	0x00ba
                           0000BB  1227 _IP_3	=	0x00bb
                           0000BC  1228 _IP_4	=	0x00bc
                           0000BD  1229 _IP_5	=	0x00bd
                           0000BE  1230 _IP_6	=	0x00be
                           0000BF  1231 _IP_7	=	0x00bf
                           0000D0  1232 _P	=	0x00d0
                           0000D1  1233 _F1	=	0x00d1
                           0000D2  1234 _OV	=	0x00d2
                           0000D3  1235 _RS0	=	0x00d3
                           0000D4  1236 _RS1	=	0x00d4
                           0000D5  1237 _F0	=	0x00d5
                           0000D6  1238 _AC	=	0x00d6
                           0000D7  1239 _CY	=	0x00d7
                           0000C8  1240 _PINA_0	=	0x00c8
                           0000C9  1241 _PINA_1	=	0x00c9
                           0000CA  1242 _PINA_2	=	0x00ca
                           0000CB  1243 _PINA_3	=	0x00cb
                           0000CC  1244 _PINA_4	=	0x00cc
                           0000CD  1245 _PINA_5	=	0x00cd
                           0000CE  1246 _PINA_6	=	0x00ce
                           0000CF  1247 _PINA_7	=	0x00cf
                           0000E8  1248 _PINB_0	=	0x00e8
                           0000E9  1249 _PINB_1	=	0x00e9
                           0000EA  1250 _PINB_2	=	0x00ea
                           0000EB  1251 _PINB_3	=	0x00eb
                           0000EC  1252 _PINB_4	=	0x00ec
                           0000ED  1253 _PINB_5	=	0x00ed
                           0000EE  1254 _PINB_6	=	0x00ee
                           0000EF  1255 _PINB_7	=	0x00ef
                           0000F8  1256 _PINC_0	=	0x00f8
                           0000F9  1257 _PINC_1	=	0x00f9
                           0000FA  1258 _PINC_2	=	0x00fa
                           0000FB  1259 _PINC_3	=	0x00fb
                           0000FC  1260 _PINC_4	=	0x00fc
                           0000FD  1261 _PINC_5	=	0x00fd
                           0000FE  1262 _PINC_6	=	0x00fe
                           0000FF  1263 _PINC_7	=	0x00ff
                           000080  1264 _PORTA_0	=	0x0080
                           000081  1265 _PORTA_1	=	0x0081
                           000082  1266 _PORTA_2	=	0x0082
                           000083  1267 _PORTA_3	=	0x0083
                           000084  1268 _PORTA_4	=	0x0084
                           000085  1269 _PORTA_5	=	0x0085
                           000086  1270 _PORTA_6	=	0x0086
                           000087  1271 _PORTA_7	=	0x0087
                           000088  1272 _PORTB_0	=	0x0088
                           000089  1273 _PORTB_1	=	0x0089
                           00008A  1274 _PORTB_2	=	0x008a
                           00008B  1275 _PORTB_3	=	0x008b
                           00008C  1276 _PORTB_4	=	0x008c
                           00008D  1277 _PORTB_5	=	0x008d
                           00008E  1278 _PORTB_6	=	0x008e
                           00008F  1279 _PORTB_7	=	0x008f
                           000090  1280 _PORTC_0	=	0x0090
                           000091  1281 _PORTC_1	=	0x0091
                           000092  1282 _PORTC_2	=	0x0092
                           000093  1283 _PORTC_3	=	0x0093
                           000094  1284 _PORTC_4	=	0x0094
                           000095  1285 _PORTC_5	=	0x0095
                           000096  1286 _PORTC_6	=	0x0096
                           000097  1287 _PORTC_7	=	0x0097
                                   1288 ;--------------------------------------------------------
                                   1289 ; overlayable register banks
                                   1290 ;--------------------------------------------------------
                                   1291 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                       1292 	.ds 8
                                   1293 ;--------------------------------------------------------
                                   1294 ; internal ram data
                                   1295 ;--------------------------------------------------------
                                   1296 	.area DSEG    (DATA)
                                   1297 ;--------------------------------------------------------
                                   1298 ; overlayable items in internal ram 
                                   1299 ;--------------------------------------------------------
                                   1300 ;--------------------------------------------------------
                                   1301 ; indirectly addressable internal ram data
                                   1302 ;--------------------------------------------------------
                                   1303 	.area ISEG    (DATA)
                                   1304 ;--------------------------------------------------------
                                   1305 ; absolute internal ram data
                                   1306 ;--------------------------------------------------------
                                   1307 	.area IABS    (ABS,DATA)
                                   1308 	.area IABS    (ABS,DATA)
                                   1309 ;--------------------------------------------------------
                                   1310 ; bit data
                                   1311 ;--------------------------------------------------------
                                   1312 	.area BSEG    (BIT)
                                   1313 ;--------------------------------------------------------
                                   1314 ; paged external ram data
                                   1315 ;--------------------------------------------------------
                                   1316 	.area PSEG    (PAG,XDATA)
                                   1317 ;--------------------------------------------------------
                                   1318 ; external ram data
                                   1319 ;--------------------------------------------------------
                                   1320 	.area XSEG    (XDATA)
                           007020  1321 _ADCCH0VAL0	=	0x7020
                           007021  1322 _ADCCH0VAL1	=	0x7021
                           007020  1323 _ADCCH0VAL	=	0x7020
                           007022  1324 _ADCCH1VAL0	=	0x7022
                           007023  1325 _ADCCH1VAL1	=	0x7023
                           007022  1326 _ADCCH1VAL	=	0x7022
                           007024  1327 _ADCCH2VAL0	=	0x7024
                           007025  1328 _ADCCH2VAL1	=	0x7025
                           007024  1329 _ADCCH2VAL	=	0x7024
                           007026  1330 _ADCCH3VAL0	=	0x7026
                           007027  1331 _ADCCH3VAL1	=	0x7027
                           007026  1332 _ADCCH3VAL	=	0x7026
                           007028  1333 _ADCTUNE0	=	0x7028
                           007029  1334 _ADCTUNE1	=	0x7029
                           00702A  1335 _ADCTUNE2	=	0x702a
                           007010  1336 _DMA0ADDR0	=	0x7010
                           007011  1337 _DMA0ADDR1	=	0x7011
                           007010  1338 _DMA0ADDR	=	0x7010
                           007014  1339 _DMA0CONFIG	=	0x7014
                           007012  1340 _DMA1ADDR0	=	0x7012
                           007013  1341 _DMA1ADDR1	=	0x7013
                           007012  1342 _DMA1ADDR	=	0x7012
                           007015  1343 _DMA1CONFIG	=	0x7015
                           007070  1344 _FRCOSCCONFIG	=	0x7070
                           007071  1345 _FRCOSCCTRL	=	0x7071
                           007076  1346 _FRCOSCFREQ0	=	0x7076
                           007077  1347 _FRCOSCFREQ1	=	0x7077
                           007076  1348 _FRCOSCFREQ	=	0x7076
                           007072  1349 _FRCOSCKFILT0	=	0x7072
                           007073  1350 _FRCOSCKFILT1	=	0x7073
                           007072  1351 _FRCOSCKFILT	=	0x7072
                           007078  1352 _FRCOSCPER0	=	0x7078
                           007079  1353 _FRCOSCPER1	=	0x7079
                           007078  1354 _FRCOSCPER	=	0x7078
                           007074  1355 _FRCOSCREF0	=	0x7074
                           007075  1356 _FRCOSCREF1	=	0x7075
                           007074  1357 _FRCOSCREF	=	0x7074
                           007007  1358 _ANALOGA	=	0x7007
                           00700C  1359 _GPIOENABLE	=	0x700c
                           007003  1360 _EXTIRQ	=	0x7003
                           007000  1361 _INTCHGA	=	0x7000
                           007001  1362 _INTCHGB	=	0x7001
                           007002  1363 _INTCHGC	=	0x7002
                           007008  1364 _PALTA	=	0x7008
                           007009  1365 _PALTB	=	0x7009
                           00700A  1366 _PALTC	=	0x700a
                           007046  1367 _PALTRADIO	=	0x7046
                           007004  1368 _PINCHGA	=	0x7004
                           007005  1369 _PINCHGB	=	0x7005
                           007006  1370 _PINCHGC	=	0x7006
                           00700B  1371 _PINSEL	=	0x700b
                           007060  1372 _LPOSCCONFIG	=	0x7060
                           007066  1373 _LPOSCFREQ0	=	0x7066
                           007067  1374 _LPOSCFREQ1	=	0x7067
                           007066  1375 _LPOSCFREQ	=	0x7066
                           007062  1376 _LPOSCKFILT0	=	0x7062
                           007063  1377 _LPOSCKFILT1	=	0x7063
                           007062  1378 _LPOSCKFILT	=	0x7062
                           007068  1379 _LPOSCPER0	=	0x7068
                           007069  1380 _LPOSCPER1	=	0x7069
                           007068  1381 _LPOSCPER	=	0x7068
                           007064  1382 _LPOSCREF0	=	0x7064
                           007065  1383 _LPOSCREF1	=	0x7065
                           007064  1384 _LPOSCREF	=	0x7064
                           007054  1385 _LPXOSCGM	=	0x7054
                           007F01  1386 _MISCCTRL	=	0x7f01
                           007053  1387 _OSCCALIB	=	0x7053
                           007050  1388 _OSCFORCERUN	=	0x7050
                           007052  1389 _OSCREADY	=	0x7052
                           007051  1390 _OSCRUN	=	0x7051
                           007040  1391 _RADIOFDATAADDR0	=	0x7040
                           007041  1392 _RADIOFDATAADDR1	=	0x7041
                           007040  1393 _RADIOFDATAADDR	=	0x7040
                           007042  1394 _RADIOFSTATADDR0	=	0x7042
                           007043  1395 _RADIOFSTATADDR1	=	0x7043
                           007042  1396 _RADIOFSTATADDR	=	0x7042
                           007044  1397 _RADIOMUX	=	0x7044
                           007084  1398 _SCRATCH0	=	0x7084
                           007085  1399 _SCRATCH1	=	0x7085
                           007086  1400 _SCRATCH2	=	0x7086
                           007087  1401 _SCRATCH3	=	0x7087
                           007F00  1402 _SILICONREV	=	0x7f00
                           007F19  1403 _XTALAMPL	=	0x7f19
                           007F18  1404 _XTALOSC	=	0x7f18
                           007F1A  1405 _XTALREADY	=	0x7f1a
                           004114  1406 _AX5043_AFSKCTRL	=	0x4114
                           004113  1407 _AX5043_AFSKMARK0	=	0x4113
                           004112  1408 _AX5043_AFSKMARK1	=	0x4112
                           004111  1409 _AX5043_AFSKSPACE0	=	0x4111
                           004110  1410 _AX5043_AFSKSPACE1	=	0x4110
                           004043  1411 _AX5043_AGCCOUNTER	=	0x4043
                           004115  1412 _AX5043_AMPLFILTER	=	0x4115
                           004189  1413 _AX5043_BBOFFSCAP	=	0x4189
                           004188  1414 _AX5043_BBTUNE	=	0x4188
                           004041  1415 _AX5043_BGNDRSSI	=	0x4041
                           00422E  1416 _AX5043_BGNDRSSIGAIN	=	0x422e
                           00422F  1417 _AX5043_BGNDRSSITHR	=	0x422f
                           004017  1418 _AX5043_CRCINIT0	=	0x4017
                           004016  1419 _AX5043_CRCINIT1	=	0x4016
                           004015  1420 _AX5043_CRCINIT2	=	0x4015
                           004014  1421 _AX5043_CRCINIT3	=	0x4014
                           004332  1422 _AX5043_DACCONFIG	=	0x4332
                           004331  1423 _AX5043_DACVALUE0	=	0x4331
                           004330  1424 _AX5043_DACVALUE1	=	0x4330
                           004102  1425 _AX5043_DECIMATION	=	0x4102
                           004042  1426 _AX5043_DIVERSITY	=	0x4042
                           004011  1427 _AX5043_ENCODING	=	0x4011
                           004018  1428 _AX5043_FEC	=	0x4018
                           00401A  1429 _AX5043_FECSTATUS	=	0x401a
                           004019  1430 _AX5043_FECSYNC	=	0x4019
                           00402B  1431 _AX5043_FIFOCOUNT0	=	0x402b
                           00402A  1432 _AX5043_FIFOCOUNT1	=	0x402a
                           004029  1433 _AX5043_FIFODATA	=	0x4029
                           00402D  1434 _AX5043_FIFOFREE0	=	0x402d
                           00402C  1435 _AX5043_FIFOFREE1	=	0x402c
                           004028  1436 _AX5043_FIFOSTAT	=	0x4028
                           00402F  1437 _AX5043_FIFOTHRESH0	=	0x402f
                           00402E  1438 _AX5043_FIFOTHRESH1	=	0x402e
                           004012  1439 _AX5043_FRAMING	=	0x4012
                           004037  1440 _AX5043_FREQA0	=	0x4037
                           004036  1441 _AX5043_FREQA1	=	0x4036
                           004035  1442 _AX5043_FREQA2	=	0x4035
                           004034  1443 _AX5043_FREQA3	=	0x4034
                           00403F  1444 _AX5043_FREQB0	=	0x403f
                           00403E  1445 _AX5043_FREQB1	=	0x403e
                           00403D  1446 _AX5043_FREQB2	=	0x403d
                           00403C  1447 _AX5043_FREQB3	=	0x403c
                           004163  1448 _AX5043_FSKDEV0	=	0x4163
                           004162  1449 _AX5043_FSKDEV1	=	0x4162
                           004161  1450 _AX5043_FSKDEV2	=	0x4161
                           00410D  1451 _AX5043_FSKDMAX0	=	0x410d
                           00410C  1452 _AX5043_FSKDMAX1	=	0x410c
                           00410F  1453 _AX5043_FSKDMIN0	=	0x410f
                           00410E  1454 _AX5043_FSKDMIN1	=	0x410e
                           004309  1455 _AX5043_GPADC13VALUE0	=	0x4309
                           004308  1456 _AX5043_GPADC13VALUE1	=	0x4308
                           004300  1457 _AX5043_GPADCCTRL	=	0x4300
                           004301  1458 _AX5043_GPADCPERIOD	=	0x4301
                           004101  1459 _AX5043_IFFREQ0	=	0x4101
                           004100  1460 _AX5043_IFFREQ1	=	0x4100
                           00400B  1461 _AX5043_IRQINVERSION0	=	0x400b
                           00400A  1462 _AX5043_IRQINVERSION1	=	0x400a
                           004007  1463 _AX5043_IRQMASK0	=	0x4007
                           004006  1464 _AX5043_IRQMASK1	=	0x4006
                           00400D  1465 _AX5043_IRQREQUEST0	=	0x400d
                           00400C  1466 _AX5043_IRQREQUEST1	=	0x400c
                           004310  1467 _AX5043_LPOSCCONFIG	=	0x4310
                           004317  1468 _AX5043_LPOSCFREQ0	=	0x4317
                           004316  1469 _AX5043_LPOSCFREQ1	=	0x4316
                           004313  1470 _AX5043_LPOSCKFILT0	=	0x4313
                           004312  1471 _AX5043_LPOSCKFILT1	=	0x4312
                           004319  1472 _AX5043_LPOSCPER0	=	0x4319
                           004318  1473 _AX5043_LPOSCPER1	=	0x4318
                           004315  1474 _AX5043_LPOSCREF0	=	0x4315
                           004314  1475 _AX5043_LPOSCREF1	=	0x4314
                           004311  1476 _AX5043_LPOSCSTATUS	=	0x4311
                           004214  1477 _AX5043_MATCH0LEN	=	0x4214
                           004216  1478 _AX5043_MATCH0MAX	=	0x4216
                           004215  1479 _AX5043_MATCH0MIN	=	0x4215
                           004213  1480 _AX5043_MATCH0PAT0	=	0x4213
                           004212  1481 _AX5043_MATCH0PAT1	=	0x4212
                           004211  1482 _AX5043_MATCH0PAT2	=	0x4211
                           004210  1483 _AX5043_MATCH0PAT3	=	0x4210
                           00421C  1484 _AX5043_MATCH1LEN	=	0x421c
                           00421E  1485 _AX5043_MATCH1MAX	=	0x421e
                           00421D  1486 _AX5043_MATCH1MIN	=	0x421d
                           004219  1487 _AX5043_MATCH1PAT0	=	0x4219
                           004218  1488 _AX5043_MATCH1PAT1	=	0x4218
                           004108  1489 _AX5043_MAXDROFFSET0	=	0x4108
                           004107  1490 _AX5043_MAXDROFFSET1	=	0x4107
                           004106  1491 _AX5043_MAXDROFFSET2	=	0x4106
                           00410B  1492 _AX5043_MAXRFOFFSET0	=	0x410b
                           00410A  1493 _AX5043_MAXRFOFFSET1	=	0x410a
                           004109  1494 _AX5043_MAXRFOFFSET2	=	0x4109
                           004164  1495 _AX5043_MODCFGA	=	0x4164
                           004160  1496 _AX5043_MODCFGF	=	0x4160
                           004F5F  1497 _AX5043_MODCFGP	=	0x4f5f
                           004010  1498 _AX5043_MODULATION	=	0x4010
                           004025  1499 _AX5043_PINFUNCANTSEL	=	0x4025
                           004023  1500 _AX5043_PINFUNCDATA	=	0x4023
                           004022  1501 _AX5043_PINFUNCDCLK	=	0x4022
                           004024  1502 _AX5043_PINFUNCIRQ	=	0x4024
                           004026  1503 _AX5043_PINFUNCPWRAMP	=	0x4026
                           004021  1504 _AX5043_PINFUNCSYSCLK	=	0x4021
                           004020  1505 _AX5043_PINSTATE	=	0x4020
                           004233  1506 _AX5043_PKTACCEPTFLAGS	=	0x4233
                           004230  1507 _AX5043_PKTCHUNKSIZE	=	0x4230
                           004231  1508 _AX5043_PKTMISCFLAGS	=	0x4231
                           004232  1509 _AX5043_PKTSTOREFLAGS	=	0x4232
                           004031  1510 _AX5043_PLLCPI	=	0x4031
                           004039  1511 _AX5043_PLLCPIBOOST	=	0x4039
                           004182  1512 _AX5043_PLLLOCKDET	=	0x4182
                           004030  1513 _AX5043_PLLLOOP	=	0x4030
                           004038  1514 _AX5043_PLLLOOPBOOST	=	0x4038
                           004033  1515 _AX5043_PLLRANGINGA	=	0x4033
                           00403B  1516 _AX5043_PLLRANGINGB	=	0x403b
                           004183  1517 _AX5043_PLLRNGCLK	=	0x4183
                           004032  1518 _AX5043_PLLVCODIV	=	0x4032
                           004180  1519 _AX5043_PLLVCOI	=	0x4180
                           004181  1520 _AX5043_PLLVCOIR	=	0x4181
                           004F08  1521 _AX5043_POWCTRL1	=	0x4f08
                           004005  1522 _AX5043_POWIRQMASK	=	0x4005
                           004003  1523 _AX5043_POWSTAT	=	0x4003
                           004004  1524 _AX5043_POWSTICKYSTAT	=	0x4004
                           004027  1525 _AX5043_PWRAMP	=	0x4027
                           004002  1526 _AX5043_PWRMODE	=	0x4002
                           004009  1527 _AX5043_RADIOEVENTMASK0	=	0x4009
                           004008  1528 _AX5043_RADIOEVENTMASK1	=	0x4008
                           00400F  1529 _AX5043_RADIOEVENTREQ0	=	0x400f
                           00400E  1530 _AX5043_RADIOEVENTREQ1	=	0x400e
                           00401C  1531 _AX5043_RADIOSTATE	=	0x401c
                           004F0D  1532 _AX5043_REF	=	0x4f0d
                           004040  1533 _AX5043_RSSI	=	0x4040
                           00422D  1534 _AX5043_RSSIABSTHR	=	0x422d
                           00422C  1535 _AX5043_RSSIREFERENCE	=	0x422c
                           004105  1536 _AX5043_RXDATARATE0	=	0x4105
                           004104  1537 _AX5043_RXDATARATE1	=	0x4104
                           004103  1538 _AX5043_RXDATARATE2	=	0x4103
                           004001  1539 _AX5043_SCRATCH	=	0x4001
                           004000  1540 _AX5043_SILICONREVISION	=	0x4000
                           00405B  1541 _AX5043_TIMER0	=	0x405b
                           00405A  1542 _AX5043_TIMER1	=	0x405a
                           004059  1543 _AX5043_TIMER2	=	0x4059
                           004227  1544 _AX5043_TMGRXAGC	=	0x4227
                           004223  1545 _AX5043_TMGRXBOOST	=	0x4223
                           004226  1546 _AX5043_TMGRXCOARSEAGC	=	0x4226
                           004225  1547 _AX5043_TMGRXOFFSACQ	=	0x4225
                           004229  1548 _AX5043_TMGRXPREAMBLE1	=	0x4229
                           00422A  1549 _AX5043_TMGRXPREAMBLE2	=	0x422a
                           00422B  1550 _AX5043_TMGRXPREAMBLE3	=	0x422b
                           004228  1551 _AX5043_TMGRXRSSI	=	0x4228
                           004224  1552 _AX5043_TMGRXSETTLE	=	0x4224
                           004220  1553 _AX5043_TMGTXBOOST	=	0x4220
                           004221  1554 _AX5043_TMGTXSETTLE	=	0x4221
                           004055  1555 _AX5043_TRKAFSKDEMOD0	=	0x4055
                           004054  1556 _AX5043_TRKAFSKDEMOD1	=	0x4054
                           004049  1557 _AX5043_TRKAMPLITUDE0	=	0x4049
                           004048  1558 _AX5043_TRKAMPLITUDE1	=	0x4048
                           004047  1559 _AX5043_TRKDATARATE0	=	0x4047
                           004046  1560 _AX5043_TRKDATARATE1	=	0x4046
                           004045  1561 _AX5043_TRKDATARATE2	=	0x4045
                           004051  1562 _AX5043_TRKFREQ0	=	0x4051
                           004050  1563 _AX5043_TRKFREQ1	=	0x4050
                           004053  1564 _AX5043_TRKFSKDEMOD0	=	0x4053
                           004052  1565 _AX5043_TRKFSKDEMOD1	=	0x4052
                           00404B  1566 _AX5043_TRKPHASE0	=	0x404b
                           00404A  1567 _AX5043_TRKPHASE1	=	0x404a
                           00404F  1568 _AX5043_TRKRFFREQ0	=	0x404f
                           00404E  1569 _AX5043_TRKRFFREQ1	=	0x404e
                           00404D  1570 _AX5043_TRKRFFREQ2	=	0x404d
                           004169  1571 _AX5043_TXPWRCOEFFA0	=	0x4169
                           004168  1572 _AX5043_TXPWRCOEFFA1	=	0x4168
                           00416B  1573 _AX5043_TXPWRCOEFFB0	=	0x416b
                           00416A  1574 _AX5043_TXPWRCOEFFB1	=	0x416a
                           00416D  1575 _AX5043_TXPWRCOEFFC0	=	0x416d
                           00416C  1576 _AX5043_TXPWRCOEFFC1	=	0x416c
                           00416F  1577 _AX5043_TXPWRCOEFFD0	=	0x416f
                           00416E  1578 _AX5043_TXPWRCOEFFD1	=	0x416e
                           004171  1579 _AX5043_TXPWRCOEFFE0	=	0x4171
                           004170  1580 _AX5043_TXPWRCOEFFE1	=	0x4170
                           004167  1581 _AX5043_TXRATE0	=	0x4167
                           004166  1582 _AX5043_TXRATE1	=	0x4166
                           004165  1583 _AX5043_TXRATE2	=	0x4165
                           00406B  1584 _AX5043_WAKEUP0	=	0x406b
                           00406A  1585 _AX5043_WAKEUP1	=	0x406a
                           00406D  1586 _AX5043_WAKEUPFREQ0	=	0x406d
                           00406C  1587 _AX5043_WAKEUPFREQ1	=	0x406c
                           004069  1588 _AX5043_WAKEUPTIMER0	=	0x4069
                           004068  1589 _AX5043_WAKEUPTIMER1	=	0x4068
                           00406E  1590 _AX5043_WAKEUPXOEARLY	=	0x406e
                           004F11  1591 _AX5043_XTALAMPL	=	0x4f11
                           004184  1592 _AX5043_XTALCAP	=	0x4184
                           004F10  1593 _AX5043_XTALOSC	=	0x4f10
                           00401D  1594 _AX5043_XTALSTATUS	=	0x401d
                           004F00  1595 _AX5043_0xF00	=	0x4f00
                           004F0C  1596 _AX5043_0xF0C	=	0x4f0c
                           004F18  1597 _AX5043_0xF18	=	0x4f18
                           004F1C  1598 _AX5043_0xF1C	=	0x4f1c
                           004F21  1599 _AX5043_0xF21	=	0x4f21
                           004F22  1600 _AX5043_0xF22	=	0x4f22
                           004F23  1601 _AX5043_0xF23	=	0x4f23
                           004F26  1602 _AX5043_0xF26	=	0x4f26
                           004F30  1603 _AX5043_0xF30	=	0x4f30
                           004F31  1604 _AX5043_0xF31	=	0x4f31
                           004F32  1605 _AX5043_0xF32	=	0x4f32
                           004F33  1606 _AX5043_0xF33	=	0x4f33
                           004F34  1607 _AX5043_0xF34	=	0x4f34
                           004F35  1608 _AX5043_0xF35	=	0x4f35
                           004F44  1609 _AX5043_0xF44	=	0x4f44
                           004122  1610 _AX5043_AGCAHYST0	=	0x4122
                           004132  1611 _AX5043_AGCAHYST1	=	0x4132
                           004142  1612 _AX5043_AGCAHYST2	=	0x4142
                           004152  1613 _AX5043_AGCAHYST3	=	0x4152
                           004120  1614 _AX5043_AGCGAIN0	=	0x4120
                           004130  1615 _AX5043_AGCGAIN1	=	0x4130
                           004140  1616 _AX5043_AGCGAIN2	=	0x4140
                           004150  1617 _AX5043_AGCGAIN3	=	0x4150
                           004123  1618 _AX5043_AGCMINMAX0	=	0x4123
                           004133  1619 _AX5043_AGCMINMAX1	=	0x4133
                           004143  1620 _AX5043_AGCMINMAX2	=	0x4143
                           004153  1621 _AX5043_AGCMINMAX3	=	0x4153
                           004121  1622 _AX5043_AGCTARGET0	=	0x4121
                           004131  1623 _AX5043_AGCTARGET1	=	0x4131
                           004141  1624 _AX5043_AGCTARGET2	=	0x4141
                           004151  1625 _AX5043_AGCTARGET3	=	0x4151
                           00412B  1626 _AX5043_AMPLITUDEGAIN0	=	0x412b
                           00413B  1627 _AX5043_AMPLITUDEGAIN1	=	0x413b
                           00414B  1628 _AX5043_AMPLITUDEGAIN2	=	0x414b
                           00415B  1629 _AX5043_AMPLITUDEGAIN3	=	0x415b
                           00412F  1630 _AX5043_BBOFFSRES0	=	0x412f
                           00413F  1631 _AX5043_BBOFFSRES1	=	0x413f
                           00414F  1632 _AX5043_BBOFFSRES2	=	0x414f
                           00415F  1633 _AX5043_BBOFFSRES3	=	0x415f
                           004125  1634 _AX5043_DRGAIN0	=	0x4125
                           004135  1635 _AX5043_DRGAIN1	=	0x4135
                           004145  1636 _AX5043_DRGAIN2	=	0x4145
                           004155  1637 _AX5043_DRGAIN3	=	0x4155
                           00412E  1638 _AX5043_FOURFSK0	=	0x412e
                           00413E  1639 _AX5043_FOURFSK1	=	0x413e
                           00414E  1640 _AX5043_FOURFSK2	=	0x414e
                           00415E  1641 _AX5043_FOURFSK3	=	0x415e
                           00412D  1642 _AX5043_FREQDEV00	=	0x412d
                           00413D  1643 _AX5043_FREQDEV01	=	0x413d
                           00414D  1644 _AX5043_FREQDEV02	=	0x414d
                           00415D  1645 _AX5043_FREQDEV03	=	0x415d
                           00412C  1646 _AX5043_FREQDEV10	=	0x412c
                           00413C  1647 _AX5043_FREQDEV11	=	0x413c
                           00414C  1648 _AX5043_FREQDEV12	=	0x414c
                           00415C  1649 _AX5043_FREQDEV13	=	0x415c
                           004127  1650 _AX5043_FREQUENCYGAINA0	=	0x4127
                           004137  1651 _AX5043_FREQUENCYGAINA1	=	0x4137
                           004147  1652 _AX5043_FREQUENCYGAINA2	=	0x4147
                           004157  1653 _AX5043_FREQUENCYGAINA3	=	0x4157
                           004128  1654 _AX5043_FREQUENCYGAINB0	=	0x4128
                           004138  1655 _AX5043_FREQUENCYGAINB1	=	0x4138
                           004148  1656 _AX5043_FREQUENCYGAINB2	=	0x4148
                           004158  1657 _AX5043_FREQUENCYGAINB3	=	0x4158
                           004129  1658 _AX5043_FREQUENCYGAINC0	=	0x4129
                           004139  1659 _AX5043_FREQUENCYGAINC1	=	0x4139
                           004149  1660 _AX5043_FREQUENCYGAINC2	=	0x4149
                           004159  1661 _AX5043_FREQUENCYGAINC3	=	0x4159
                           00412A  1662 _AX5043_FREQUENCYGAIND0	=	0x412a
                           00413A  1663 _AX5043_FREQUENCYGAIND1	=	0x413a
                           00414A  1664 _AX5043_FREQUENCYGAIND2	=	0x414a
                           00415A  1665 _AX5043_FREQUENCYGAIND3	=	0x415a
                           004116  1666 _AX5043_FREQUENCYLEAK	=	0x4116
                           004126  1667 _AX5043_PHASEGAIN0	=	0x4126
                           004136  1668 _AX5043_PHASEGAIN1	=	0x4136
                           004146  1669 _AX5043_PHASEGAIN2	=	0x4146
                           004156  1670 _AX5043_PHASEGAIN3	=	0x4156
                           004207  1671 _AX5043_PKTADDR0	=	0x4207
                           004206  1672 _AX5043_PKTADDR1	=	0x4206
                           004205  1673 _AX5043_PKTADDR2	=	0x4205
                           004204  1674 _AX5043_PKTADDR3	=	0x4204
                           004200  1675 _AX5043_PKTADDRCFG	=	0x4200
                           00420B  1676 _AX5043_PKTADDRMASK0	=	0x420b
                           00420A  1677 _AX5043_PKTADDRMASK1	=	0x420a
                           004209  1678 _AX5043_PKTADDRMASK2	=	0x4209
                           004208  1679 _AX5043_PKTADDRMASK3	=	0x4208
                           004201  1680 _AX5043_PKTLENCFG	=	0x4201
                           004202  1681 _AX5043_PKTLENOFFSET	=	0x4202
                           004203  1682 _AX5043_PKTMAXLEN	=	0x4203
                           004118  1683 _AX5043_RXPARAMCURSET	=	0x4118
                           004117  1684 _AX5043_RXPARAMSETS	=	0x4117
                           004124  1685 _AX5043_TIMEGAIN0	=	0x4124
                           004134  1686 _AX5043_TIMEGAIN1	=	0x4134
                           004144  1687 _AX5043_TIMEGAIN2	=	0x4144
                           004154  1688 _AX5043_TIMEGAIN3	=	0x4154
                           005114  1689 _AX5043_AFSKCTRLNB	=	0x5114
                           005113  1690 _AX5043_AFSKMARK0NB	=	0x5113
                           005112  1691 _AX5043_AFSKMARK1NB	=	0x5112
                           005111  1692 _AX5043_AFSKSPACE0NB	=	0x5111
                           005110  1693 _AX5043_AFSKSPACE1NB	=	0x5110
                           005043  1694 _AX5043_AGCCOUNTERNB	=	0x5043
                           005115  1695 _AX5043_AMPLFILTERNB	=	0x5115
                           005189  1696 _AX5043_BBOFFSCAPNB	=	0x5189
                           005188  1697 _AX5043_BBTUNENB	=	0x5188
                           005041  1698 _AX5043_BGNDRSSINB	=	0x5041
                           00522E  1699 _AX5043_BGNDRSSIGAINNB	=	0x522e
                           00522F  1700 _AX5043_BGNDRSSITHRNB	=	0x522f
                           005017  1701 _AX5043_CRCINIT0NB	=	0x5017
                           005016  1702 _AX5043_CRCINIT1NB	=	0x5016
                           005015  1703 _AX5043_CRCINIT2NB	=	0x5015
                           005014  1704 _AX5043_CRCINIT3NB	=	0x5014
                           005332  1705 _AX5043_DACCONFIGNB	=	0x5332
                           005331  1706 _AX5043_DACVALUE0NB	=	0x5331
                           005330  1707 _AX5043_DACVALUE1NB	=	0x5330
                           005102  1708 _AX5043_DECIMATIONNB	=	0x5102
                           005042  1709 _AX5043_DIVERSITYNB	=	0x5042
                           005011  1710 _AX5043_ENCODINGNB	=	0x5011
                           005018  1711 _AX5043_FECNB	=	0x5018
                           00501A  1712 _AX5043_FECSTATUSNB	=	0x501a
                           005019  1713 _AX5043_FECSYNCNB	=	0x5019
                           00502B  1714 _AX5043_FIFOCOUNT0NB	=	0x502b
                           00502A  1715 _AX5043_FIFOCOUNT1NB	=	0x502a
                           005029  1716 _AX5043_FIFODATANB	=	0x5029
                           00502D  1717 _AX5043_FIFOFREE0NB	=	0x502d
                           00502C  1718 _AX5043_FIFOFREE1NB	=	0x502c
                           005028  1719 _AX5043_FIFOSTATNB	=	0x5028
                           00502F  1720 _AX5043_FIFOTHRESH0NB	=	0x502f
                           00502E  1721 _AX5043_FIFOTHRESH1NB	=	0x502e
                           005012  1722 _AX5043_FRAMINGNB	=	0x5012
                           005037  1723 _AX5043_FREQA0NB	=	0x5037
                           005036  1724 _AX5043_FREQA1NB	=	0x5036
                           005035  1725 _AX5043_FREQA2NB	=	0x5035
                           005034  1726 _AX5043_FREQA3NB	=	0x5034
                           00503F  1727 _AX5043_FREQB0NB	=	0x503f
                           00503E  1728 _AX5043_FREQB1NB	=	0x503e
                           00503D  1729 _AX5043_FREQB2NB	=	0x503d
                           00503C  1730 _AX5043_FREQB3NB	=	0x503c
                           005163  1731 _AX5043_FSKDEV0NB	=	0x5163
                           005162  1732 _AX5043_FSKDEV1NB	=	0x5162
                           005161  1733 _AX5043_FSKDEV2NB	=	0x5161
                           00510D  1734 _AX5043_FSKDMAX0NB	=	0x510d
                           00510C  1735 _AX5043_FSKDMAX1NB	=	0x510c
                           00510F  1736 _AX5043_FSKDMIN0NB	=	0x510f
                           00510E  1737 _AX5043_FSKDMIN1NB	=	0x510e
                           005309  1738 _AX5043_GPADC13VALUE0NB	=	0x5309
                           005308  1739 _AX5043_GPADC13VALUE1NB	=	0x5308
                           005300  1740 _AX5043_GPADCCTRLNB	=	0x5300
                           005301  1741 _AX5043_GPADCPERIODNB	=	0x5301
                           005101  1742 _AX5043_IFFREQ0NB	=	0x5101
                           005100  1743 _AX5043_IFFREQ1NB	=	0x5100
                           00500B  1744 _AX5043_IRQINVERSION0NB	=	0x500b
                           00500A  1745 _AX5043_IRQINVERSION1NB	=	0x500a
                           005007  1746 _AX5043_IRQMASK0NB	=	0x5007
                           005006  1747 _AX5043_IRQMASK1NB	=	0x5006
                           00500D  1748 _AX5043_IRQREQUEST0NB	=	0x500d
                           00500C  1749 _AX5043_IRQREQUEST1NB	=	0x500c
                           005310  1750 _AX5043_LPOSCCONFIGNB	=	0x5310
                           005317  1751 _AX5043_LPOSCFREQ0NB	=	0x5317
                           005316  1752 _AX5043_LPOSCFREQ1NB	=	0x5316
                           005313  1753 _AX5043_LPOSCKFILT0NB	=	0x5313
                           005312  1754 _AX5043_LPOSCKFILT1NB	=	0x5312
                           005319  1755 _AX5043_LPOSCPER0NB	=	0x5319
                           005318  1756 _AX5043_LPOSCPER1NB	=	0x5318
                           005315  1757 _AX5043_LPOSCREF0NB	=	0x5315
                           005314  1758 _AX5043_LPOSCREF1NB	=	0x5314
                           005311  1759 _AX5043_LPOSCSTATUSNB	=	0x5311
                           005214  1760 _AX5043_MATCH0LENNB	=	0x5214
                           005216  1761 _AX5043_MATCH0MAXNB	=	0x5216
                           005215  1762 _AX5043_MATCH0MINNB	=	0x5215
                           005213  1763 _AX5043_MATCH0PAT0NB	=	0x5213
                           005212  1764 _AX5043_MATCH0PAT1NB	=	0x5212
                           005211  1765 _AX5043_MATCH0PAT2NB	=	0x5211
                           005210  1766 _AX5043_MATCH0PAT3NB	=	0x5210
                           00521C  1767 _AX5043_MATCH1LENNB	=	0x521c
                           00521E  1768 _AX5043_MATCH1MAXNB	=	0x521e
                           00521D  1769 _AX5043_MATCH1MINNB	=	0x521d
                           005219  1770 _AX5043_MATCH1PAT0NB	=	0x5219
                           005218  1771 _AX5043_MATCH1PAT1NB	=	0x5218
                           005108  1772 _AX5043_MAXDROFFSET0NB	=	0x5108
                           005107  1773 _AX5043_MAXDROFFSET1NB	=	0x5107
                           005106  1774 _AX5043_MAXDROFFSET2NB	=	0x5106
                           00510B  1775 _AX5043_MAXRFOFFSET0NB	=	0x510b
                           00510A  1776 _AX5043_MAXRFOFFSET1NB	=	0x510a
                           005109  1777 _AX5043_MAXRFOFFSET2NB	=	0x5109
                           005164  1778 _AX5043_MODCFGANB	=	0x5164
                           005160  1779 _AX5043_MODCFGFNB	=	0x5160
                           005F5F  1780 _AX5043_MODCFGPNB	=	0x5f5f
                           005010  1781 _AX5043_MODULATIONNB	=	0x5010
                           005025  1782 _AX5043_PINFUNCANTSELNB	=	0x5025
                           005023  1783 _AX5043_PINFUNCDATANB	=	0x5023
                           005022  1784 _AX5043_PINFUNCDCLKNB	=	0x5022
                           005024  1785 _AX5043_PINFUNCIRQNB	=	0x5024
                           005026  1786 _AX5043_PINFUNCPWRAMPNB	=	0x5026
                           005021  1787 _AX5043_PINFUNCSYSCLKNB	=	0x5021
                           005020  1788 _AX5043_PINSTATENB	=	0x5020
                           005233  1789 _AX5043_PKTACCEPTFLAGSNB	=	0x5233
                           005230  1790 _AX5043_PKTCHUNKSIZENB	=	0x5230
                           005231  1791 _AX5043_PKTMISCFLAGSNB	=	0x5231
                           005232  1792 _AX5043_PKTSTOREFLAGSNB	=	0x5232
                           005031  1793 _AX5043_PLLCPINB	=	0x5031
                           005039  1794 _AX5043_PLLCPIBOOSTNB	=	0x5039
                           005182  1795 _AX5043_PLLLOCKDETNB	=	0x5182
                           005030  1796 _AX5043_PLLLOOPNB	=	0x5030
                           005038  1797 _AX5043_PLLLOOPBOOSTNB	=	0x5038
                           005033  1798 _AX5043_PLLRANGINGANB	=	0x5033
                           00503B  1799 _AX5043_PLLRANGINGBNB	=	0x503b
                           005183  1800 _AX5043_PLLRNGCLKNB	=	0x5183
                           005032  1801 _AX5043_PLLVCODIVNB	=	0x5032
                           005180  1802 _AX5043_PLLVCOINB	=	0x5180
                           005181  1803 _AX5043_PLLVCOIRNB	=	0x5181
                           005F08  1804 _AX5043_POWCTRL1NB	=	0x5f08
                           005005  1805 _AX5043_POWIRQMASKNB	=	0x5005
                           005003  1806 _AX5043_POWSTATNB	=	0x5003
                           005004  1807 _AX5043_POWSTICKYSTATNB	=	0x5004
                           005027  1808 _AX5043_PWRAMPNB	=	0x5027
                           005002  1809 _AX5043_PWRMODENB	=	0x5002
                           005009  1810 _AX5043_RADIOEVENTMASK0NB	=	0x5009
                           005008  1811 _AX5043_RADIOEVENTMASK1NB	=	0x5008
                           00500F  1812 _AX5043_RADIOEVENTREQ0NB	=	0x500f
                           00500E  1813 _AX5043_RADIOEVENTREQ1NB	=	0x500e
                           00501C  1814 _AX5043_RADIOSTATENB	=	0x501c
                           005F0D  1815 _AX5043_REFNB	=	0x5f0d
                           005040  1816 _AX5043_RSSINB	=	0x5040
                           00522D  1817 _AX5043_RSSIABSTHRNB	=	0x522d
                           00522C  1818 _AX5043_RSSIREFERENCENB	=	0x522c
                           005105  1819 _AX5043_RXDATARATE0NB	=	0x5105
                           005104  1820 _AX5043_RXDATARATE1NB	=	0x5104
                           005103  1821 _AX5043_RXDATARATE2NB	=	0x5103
                           005001  1822 _AX5043_SCRATCHNB	=	0x5001
                           005000  1823 _AX5043_SILICONREVISIONNB	=	0x5000
                           00505B  1824 _AX5043_TIMER0NB	=	0x505b
                           00505A  1825 _AX5043_TIMER1NB	=	0x505a
                           005059  1826 _AX5043_TIMER2NB	=	0x5059
                           005227  1827 _AX5043_TMGRXAGCNB	=	0x5227
                           005223  1828 _AX5043_TMGRXBOOSTNB	=	0x5223
                           005226  1829 _AX5043_TMGRXCOARSEAGCNB	=	0x5226
                           005225  1830 _AX5043_TMGRXOFFSACQNB	=	0x5225
                           005229  1831 _AX5043_TMGRXPREAMBLE1NB	=	0x5229
                           00522A  1832 _AX5043_TMGRXPREAMBLE2NB	=	0x522a
                           00522B  1833 _AX5043_TMGRXPREAMBLE3NB	=	0x522b
                           005228  1834 _AX5043_TMGRXRSSINB	=	0x5228
                           005224  1835 _AX5043_TMGRXSETTLENB	=	0x5224
                           005220  1836 _AX5043_TMGTXBOOSTNB	=	0x5220
                           005221  1837 _AX5043_TMGTXSETTLENB	=	0x5221
                           005055  1838 _AX5043_TRKAFSKDEMOD0NB	=	0x5055
                           005054  1839 _AX5043_TRKAFSKDEMOD1NB	=	0x5054
                           005049  1840 _AX5043_TRKAMPLITUDE0NB	=	0x5049
                           005048  1841 _AX5043_TRKAMPLITUDE1NB	=	0x5048
                           005047  1842 _AX5043_TRKDATARATE0NB	=	0x5047
                           005046  1843 _AX5043_TRKDATARATE1NB	=	0x5046
                           005045  1844 _AX5043_TRKDATARATE2NB	=	0x5045
                           005051  1845 _AX5043_TRKFREQ0NB	=	0x5051
                           005050  1846 _AX5043_TRKFREQ1NB	=	0x5050
                           005053  1847 _AX5043_TRKFSKDEMOD0NB	=	0x5053
                           005052  1848 _AX5043_TRKFSKDEMOD1NB	=	0x5052
                           00504B  1849 _AX5043_TRKPHASE0NB	=	0x504b
                           00504A  1850 _AX5043_TRKPHASE1NB	=	0x504a
                           00504F  1851 _AX5043_TRKRFFREQ0NB	=	0x504f
                           00504E  1852 _AX5043_TRKRFFREQ1NB	=	0x504e
                           00504D  1853 _AX5043_TRKRFFREQ2NB	=	0x504d
                           005169  1854 _AX5043_TXPWRCOEFFA0NB	=	0x5169
                           005168  1855 _AX5043_TXPWRCOEFFA1NB	=	0x5168
                           00516B  1856 _AX5043_TXPWRCOEFFB0NB	=	0x516b
                           00516A  1857 _AX5043_TXPWRCOEFFB1NB	=	0x516a
                           00516D  1858 _AX5043_TXPWRCOEFFC0NB	=	0x516d
                           00516C  1859 _AX5043_TXPWRCOEFFC1NB	=	0x516c
                           00516F  1860 _AX5043_TXPWRCOEFFD0NB	=	0x516f
                           00516E  1861 _AX5043_TXPWRCOEFFD1NB	=	0x516e
                           005171  1862 _AX5043_TXPWRCOEFFE0NB	=	0x5171
                           005170  1863 _AX5043_TXPWRCOEFFE1NB	=	0x5170
                           005167  1864 _AX5043_TXRATE0NB	=	0x5167
                           005166  1865 _AX5043_TXRATE1NB	=	0x5166
                           005165  1866 _AX5043_TXRATE2NB	=	0x5165
                           00506B  1867 _AX5043_WAKEUP0NB	=	0x506b
                           00506A  1868 _AX5043_WAKEUP1NB	=	0x506a
                           00506D  1869 _AX5043_WAKEUPFREQ0NB	=	0x506d
                           00506C  1870 _AX5043_WAKEUPFREQ1NB	=	0x506c
                           005069  1871 _AX5043_WAKEUPTIMER0NB	=	0x5069
                           005068  1872 _AX5043_WAKEUPTIMER1NB	=	0x5068
                           00506E  1873 _AX5043_WAKEUPXOEARLYNB	=	0x506e
                           005F11  1874 _AX5043_XTALAMPLNB	=	0x5f11
                           005184  1875 _AX5043_XTALCAPNB	=	0x5184
                           005F10  1876 _AX5043_XTALOSCNB	=	0x5f10
                           00501D  1877 _AX5043_XTALSTATUSNB	=	0x501d
                           005F00  1878 _AX5043_0xF00NB	=	0x5f00
                           005F0C  1879 _AX5043_0xF0CNB	=	0x5f0c
                           005F18  1880 _AX5043_0xF18NB	=	0x5f18
                           005F1C  1881 _AX5043_0xF1CNB	=	0x5f1c
                           005F21  1882 _AX5043_0xF21NB	=	0x5f21
                           005F22  1883 _AX5043_0xF22NB	=	0x5f22
                           005F23  1884 _AX5043_0xF23NB	=	0x5f23
                           005F26  1885 _AX5043_0xF26NB	=	0x5f26
                           005F30  1886 _AX5043_0xF30NB	=	0x5f30
                           005F31  1887 _AX5043_0xF31NB	=	0x5f31
                           005F32  1888 _AX5043_0xF32NB	=	0x5f32
                           005F33  1889 _AX5043_0xF33NB	=	0x5f33
                           005F34  1890 _AX5043_0xF34NB	=	0x5f34
                           005F35  1891 _AX5043_0xF35NB	=	0x5f35
                           005F44  1892 _AX5043_0xF44NB	=	0x5f44
                           005122  1893 _AX5043_AGCAHYST0NB	=	0x5122
                           005132  1894 _AX5043_AGCAHYST1NB	=	0x5132
                           005142  1895 _AX5043_AGCAHYST2NB	=	0x5142
                           005152  1896 _AX5043_AGCAHYST3NB	=	0x5152
                           005120  1897 _AX5043_AGCGAIN0NB	=	0x5120
                           005130  1898 _AX5043_AGCGAIN1NB	=	0x5130
                           005140  1899 _AX5043_AGCGAIN2NB	=	0x5140
                           005150  1900 _AX5043_AGCGAIN3NB	=	0x5150
                           005123  1901 _AX5043_AGCMINMAX0NB	=	0x5123
                           005133  1902 _AX5043_AGCMINMAX1NB	=	0x5133
                           005143  1903 _AX5043_AGCMINMAX2NB	=	0x5143
                           005153  1904 _AX5043_AGCMINMAX3NB	=	0x5153
                           005121  1905 _AX5043_AGCTARGET0NB	=	0x5121
                           005131  1906 _AX5043_AGCTARGET1NB	=	0x5131
                           005141  1907 _AX5043_AGCTARGET2NB	=	0x5141
                           005151  1908 _AX5043_AGCTARGET3NB	=	0x5151
                           00512B  1909 _AX5043_AMPLITUDEGAIN0NB	=	0x512b
                           00513B  1910 _AX5043_AMPLITUDEGAIN1NB	=	0x513b
                           00514B  1911 _AX5043_AMPLITUDEGAIN2NB	=	0x514b
                           00515B  1912 _AX5043_AMPLITUDEGAIN3NB	=	0x515b
                           00512F  1913 _AX5043_BBOFFSRES0NB	=	0x512f
                           00513F  1914 _AX5043_BBOFFSRES1NB	=	0x513f
                           00514F  1915 _AX5043_BBOFFSRES2NB	=	0x514f
                           00515F  1916 _AX5043_BBOFFSRES3NB	=	0x515f
                           005125  1917 _AX5043_DRGAIN0NB	=	0x5125
                           005135  1918 _AX5043_DRGAIN1NB	=	0x5135
                           005145  1919 _AX5043_DRGAIN2NB	=	0x5145
                           005155  1920 _AX5043_DRGAIN3NB	=	0x5155
                           00512E  1921 _AX5043_FOURFSK0NB	=	0x512e
                           00513E  1922 _AX5043_FOURFSK1NB	=	0x513e
                           00514E  1923 _AX5043_FOURFSK2NB	=	0x514e
                           00515E  1924 _AX5043_FOURFSK3NB	=	0x515e
                           00512D  1925 _AX5043_FREQDEV00NB	=	0x512d
                           00513D  1926 _AX5043_FREQDEV01NB	=	0x513d
                           00514D  1927 _AX5043_FREQDEV02NB	=	0x514d
                           00515D  1928 _AX5043_FREQDEV03NB	=	0x515d
                           00512C  1929 _AX5043_FREQDEV10NB	=	0x512c
                           00513C  1930 _AX5043_FREQDEV11NB	=	0x513c
                           00514C  1931 _AX5043_FREQDEV12NB	=	0x514c
                           00515C  1932 _AX5043_FREQDEV13NB	=	0x515c
                           005127  1933 _AX5043_FREQUENCYGAINA0NB	=	0x5127
                           005137  1934 _AX5043_FREQUENCYGAINA1NB	=	0x5137
                           005147  1935 _AX5043_FREQUENCYGAINA2NB	=	0x5147
                           005157  1936 _AX5043_FREQUENCYGAINA3NB	=	0x5157
                           005128  1937 _AX5043_FREQUENCYGAINB0NB	=	0x5128
                           005138  1938 _AX5043_FREQUENCYGAINB1NB	=	0x5138
                           005148  1939 _AX5043_FREQUENCYGAINB2NB	=	0x5148
                           005158  1940 _AX5043_FREQUENCYGAINB3NB	=	0x5158
                           005129  1941 _AX5043_FREQUENCYGAINC0NB	=	0x5129
                           005139  1942 _AX5043_FREQUENCYGAINC1NB	=	0x5139
                           005149  1943 _AX5043_FREQUENCYGAINC2NB	=	0x5149
                           005159  1944 _AX5043_FREQUENCYGAINC3NB	=	0x5159
                           00512A  1945 _AX5043_FREQUENCYGAIND0NB	=	0x512a
                           00513A  1946 _AX5043_FREQUENCYGAIND1NB	=	0x513a
                           00514A  1947 _AX5043_FREQUENCYGAIND2NB	=	0x514a
                           00515A  1948 _AX5043_FREQUENCYGAIND3NB	=	0x515a
                           005116  1949 _AX5043_FREQUENCYLEAKNB	=	0x5116
                           005126  1950 _AX5043_PHASEGAIN0NB	=	0x5126
                           005136  1951 _AX5043_PHASEGAIN1NB	=	0x5136
                           005146  1952 _AX5043_PHASEGAIN2NB	=	0x5146
                           005156  1953 _AX5043_PHASEGAIN3NB	=	0x5156
                           005207  1954 _AX5043_PKTADDR0NB	=	0x5207
                           005206  1955 _AX5043_PKTADDR1NB	=	0x5206
                           005205  1956 _AX5043_PKTADDR2NB	=	0x5205
                           005204  1957 _AX5043_PKTADDR3NB	=	0x5204
                           005200  1958 _AX5043_PKTADDRCFGNB	=	0x5200
                           00520B  1959 _AX5043_PKTADDRMASK0NB	=	0x520b
                           00520A  1960 _AX5043_PKTADDRMASK1NB	=	0x520a
                           005209  1961 _AX5043_PKTADDRMASK2NB	=	0x5209
                           005208  1962 _AX5043_PKTADDRMASK3NB	=	0x5208
                           005201  1963 _AX5043_PKTLENCFGNB	=	0x5201
                           005202  1964 _AX5043_PKTLENOFFSETNB	=	0x5202
                           005203  1965 _AX5043_PKTMAXLENNB	=	0x5203
                           005118  1966 _AX5043_RXPARAMCURSETNB	=	0x5118
                           005117  1967 _AX5043_RXPARAMSETSNB	=	0x5117
                           005124  1968 _AX5043_TIMEGAIN0NB	=	0x5124
                           005134  1969 _AX5043_TIMEGAIN1NB	=	0x5134
                           005144  1970 _AX5043_TIMEGAIN2NB	=	0x5144
                           005154  1971 _AX5043_TIMEGAIN3NB	=	0x5154
      000001                       1972 _axradio_phy_chanpllrng::
      000001                       1973 	.ds 12
      00000D                       1974 _axradio_phy_chanvcoi::
      00000D                       1975 	.ds 6
                                   1976 ;--------------------------------------------------------
                                   1977 ; absolute external ram data
                                   1978 ;--------------------------------------------------------
                                   1979 	.area XABS    (ABS,XDATA)
                                   1980 ;--------------------------------------------------------
                                   1981 ; external initialized ram data
                                   1982 ;--------------------------------------------------------
                                   1983 	.area XISEG   (XDATA)
                                   1984 	.area HOME    (CODE)
                                   1985 	.area GSINIT0 (CODE)
                                   1986 	.area GSINIT1 (CODE)
                                   1987 	.area GSINIT2 (CODE)
                                   1988 	.area GSINIT3 (CODE)
                                   1989 	.area GSINIT4 (CODE)
                                   1990 	.area GSINIT5 (CODE)
                                   1991 	.area GSINIT  (CODE)
                                   1992 	.area GSFINAL (CODE)
                                   1993 	.area CSEG    (CODE)
                                   1994 ;--------------------------------------------------------
                                   1995 ; global & static initialisations
                                   1996 ;--------------------------------------------------------
                                   1997 	.area HOME    (CODE)
                                   1998 	.area GSINIT  (CODE)
                                   1999 	.area GSFINAL (CODE)
                                   2000 	.area GSINIT  (CODE)
                                   2001 ;--------------------------------------------------------
                                   2002 ; Home
                                   2003 ;--------------------------------------------------------
                                   2004 	.area HOME    (CODE)
                                   2005 	.area HOME    (CODE)
                                   2006 ;--------------------------------------------------------
                                   2007 ; code
                                   2008 ;--------------------------------------------------------
                                   2009 	.area CSEG    (CODE)
                                   2010 ;------------------------------------------------------------
                                   2011 ;Allocation info for local variables in function 'ax5043_set_registers'
                                   2012 ;------------------------------------------------------------
                                   2013 ;	..\AX_Radio_Lab_output\config.c:12: __reentrantb void ax5043_set_registers(void) __reentrant
                                   2014 ;	-----------------------------------------
                                   2015 ;	 function ax5043_set_registers
                                   2016 ;	-----------------------------------------
      000398                       2017 _ax5043_set_registers:
                           000007  2018 	ar7 = 0x07
                           000006  2019 	ar6 = 0x06
                           000005  2020 	ar5 = 0x05
                           000004  2021 	ar4 = 0x04
                           000003  2022 	ar3 = 0x03
                           000002  2023 	ar2 = 0x02
                           000001  2024 	ar1 = 0x01
                           000000  2025 	ar0 = 0x00
                                   2026 ;	..\AX_Radio_Lab_output\config.c:14: radio_write8(AX5043_REG_MODULATION     ,                              			0x08);
      000398 90 40 10         [24] 2027 	mov	dptr,#0x4010
      00039B 74 08            [12] 2028 	mov	a,#0x08
      00039D F0               [24] 2029 	movx	@dptr,a
                                   2030 ;	..\AX_Radio_Lab_output\config.c:15: radio_write8(AX5043_REG_ENCODING       ,                              			0x00);
      00039E 90 40 11         [24] 2031 	mov	dptr,#0x4011
      0003A1 E4               [12] 2032 	clr	a
      0003A2 F0               [24] 2033 	movx	@dptr,a
                                   2034 ;	..\AX_Radio_Lab_output\config.c:16: radio_write8(AX5043_REG_FRAMING        ,                              			0x06);
      0003A3 90 40 12         [24] 2035 	mov	dptr,#0x4012
      0003A6 74 06            [12] 2036 	mov	a,#0x06
      0003A8 F0               [24] 2037 	movx	@dptr,a
                                   2038 ;	..\AX_Radio_Lab_output\config.c:17: radio_write8(AX5043_REG_PINFUNCSYSCLK  ,                              			0x01);
      0003A9 90 40 21         [24] 2039 	mov	dptr,#0x4021
      0003AC 74 01            [12] 2040 	mov	a,#0x01
      0003AE F0               [24] 2041 	movx	@dptr,a
                                   2042 ;	..\AX_Radio_Lab_output\config.c:18: radio_write8(AX5043_REG_PINFUNCDCLK    ,                              			0x01);
      0003AF 90 40 22         [24] 2043 	mov	dptr,#0x4022
      0003B2 F0               [24] 2044 	movx	@dptr,a
                                   2045 ;	..\AX_Radio_Lab_output\config.c:19: radio_write8(AX5043_REG_PINFUNCDATA    ,                              			0x01);
      0003B3 90 40 23         [24] 2046 	mov	dptr,#0x4023
      0003B6 F0               [24] 2047 	movx	@dptr,a
                                   2048 ;	..\AX_Radio_Lab_output\config.c:20: radio_write8(AX5043_REG_PINFUNCANTSEL  ,                              			0x82);
      0003B7 90 40 25         [24] 2049 	mov	dptr,#0x4025
      0003BA 74 82            [12] 2050 	mov	a,#0x82
      0003BC F0               [24] 2051 	movx	@dptr,a
                                   2052 ;	..\AX_Radio_Lab_output\config.c:21: radio_write8(AX5043_REG_PINFUNCPWRAMP  ,                              			0x82);
      0003BD 90 40 26         [24] 2053 	mov	dptr,#0x4026
      0003C0 F0               [24] 2054 	movx	@dptr,a
                                   2055 ;	..\AX_Radio_Lab_output\config.c:22: radio_write8(AX5043_REG_WAKEUPXOEARLY  ,                              			0x01);
      0003C1 90 40 6E         [24] 2056 	mov	dptr,#0x406e
      0003C4 74 01            [12] 2057 	mov	a,#0x01
      0003C6 F0               [24] 2058 	movx	@dptr,a
                                   2059 ;	..\AX_Radio_Lab_output\config.c:23: radio_write8(AX5043_REG_IFFREQ1        ,                              			0x01);
      0003C7 90 41 00         [24] 2060 	mov	dptr,#0x4100
      0003CA F0               [24] 2061 	movx	@dptr,a
                                   2062 ;	..\AX_Radio_Lab_output\config.c:24: radio_write8(AX5043_REG_IFFREQ0        ,                              			0xE4);
      0003CB 90 41 01         [24] 2063 	mov	dptr,#0x4101
      0003CE 74 E4            [12] 2064 	mov	a,#0xe4
      0003D0 F0               [24] 2065 	movx	@dptr,a
                                   2066 ;	..\AX_Radio_Lab_output\config.c:25: radio_write8(AX5043_REG_DECIMATION     ,                              			0x16);
      0003D1 90 41 02         [24] 2067 	mov	dptr,#0x4102
      0003D4 74 16            [12] 2068 	mov	a,#0x16
      0003D6 F0               [24] 2069 	movx	@dptr,a
                                   2070 ;	..\AX_Radio_Lab_output\config.c:26: radio_write8(AX5043_REG_RXDATARATE2    ,                              			0x00);
      0003D7 90 41 03         [24] 2071 	mov	dptr,#0x4103
      0003DA E4               [12] 2072 	clr	a
      0003DB F0               [24] 2073 	movx	@dptr,a
                                   2074 ;	..\AX_Radio_Lab_output\config.c:27: radio_write8(AX5043_REG_RXDATARATE1    ,                              			0x3D);
      0003DC 90 41 04         [24] 2075 	mov	dptr,#0x4104
      0003DF 74 3D            [12] 2076 	mov	a,#0x3d
      0003E1 F0               [24] 2077 	movx	@dptr,a
                                   2078 ;	..\AX_Radio_Lab_output\config.c:28: radio_write8(AX5043_REG_RXDATARATE0    ,                              			0x8D);
      0003E2 90 41 05         [24] 2079 	mov	dptr,#0x4105
      0003E5 74 8D            [12] 2080 	mov	a,#0x8d
      0003E7 F0               [24] 2081 	movx	@dptr,a
                                   2082 ;	..\AX_Radio_Lab_output\config.c:29: radio_write8(AX5043_REG_MAXDROFFSET2   ,                              			0x00);
      0003E8 90 41 06         [24] 2083 	mov	dptr,#0x4106
      0003EB E4               [12] 2084 	clr	a
      0003EC F0               [24] 2085 	movx	@dptr,a
                                   2086 ;	..\AX_Radio_Lab_output\config.c:30: radio_write8(AX5043_REG_MAXDROFFSET1   ,                              			0x00);
      0003ED 90 41 07         [24] 2087 	mov	dptr,#0x4107
      0003F0 F0               [24] 2088 	movx	@dptr,a
                                   2089 ;	..\AX_Radio_Lab_output\config.c:31: radio_write8(AX5043_REG_MAXDROFFSET0   ,                              			0x00);
      0003F1 90 41 08         [24] 2090 	mov	dptr,#0x4108
      0003F4 F0               [24] 2091 	movx	@dptr,a
                                   2092 ;	..\AX_Radio_Lab_output\config.c:32: radio_write8(AX5043_REG_MAXRFOFFSET2   ,                              			0x80);
      0003F5 90 41 09         [24] 2093 	mov	dptr,#0x4109
      0003F8 74 80            [12] 2094 	mov	a,#0x80
      0003FA F0               [24] 2095 	movx	@dptr,a
                                   2096 ;	..\AX_Radio_Lab_output\config.c:33: radio_write8(AX5043_REG_MAXRFOFFSET1   ,                              			0x04);
      0003FB 90 41 0A         [24] 2097 	mov	dptr,#0x410a
      0003FE 74 04            [12] 2098 	mov	a,#0x04
      000400 F0               [24] 2099 	movx	@dptr,a
                                   2100 ;	..\AX_Radio_Lab_output\config.c:34: radio_write8(AX5043_REG_MAXRFOFFSET0   ,                              			0x61);
      000401 90 41 0B         [24] 2101 	mov	dptr,#0x410b
      000404 74 61            [12] 2102 	mov	a,#0x61
      000406 F0               [24] 2103 	movx	@dptr,a
                                   2104 ;	..\AX_Radio_Lab_output\config.c:35: radio_write8(AX5043_REG_FSKDMAX1       ,                              			0x00);
      000407 90 41 0C         [24] 2105 	mov	dptr,#0x410c
      00040A E4               [12] 2106 	clr	a
      00040B F0               [24] 2107 	movx	@dptr,a
                                   2108 ;	..\AX_Radio_Lab_output\config.c:36: radio_write8(AX5043_REG_FSKDMAX0       ,                              			0xA6);
      00040C 90 41 0D         [24] 2109 	mov	dptr,#0x410d
      00040F 74 A6            [12] 2110 	mov	a,#0xa6
      000411 F0               [24] 2111 	movx	@dptr,a
                                   2112 ;	..\AX_Radio_Lab_output\config.c:37: radio_write8(AX5043_REG_FSKDMIN1       ,                              			0xFF);
      000412 90 41 0E         [24] 2113 	mov	dptr,#0x410e
      000415 74 FF            [12] 2114 	mov	a,#0xff
      000417 F0               [24] 2115 	movx	@dptr,a
                                   2116 ;	..\AX_Radio_Lab_output\config.c:38: radio_write8(AX5043_REG_FSKDMIN0       ,                              			0x5A);
      000418 90 41 0F         [24] 2117 	mov	dptr,#0x410f
      00041B 74 5A            [12] 2118 	mov	a,#0x5a
      00041D F0               [24] 2119 	movx	@dptr,a
                                   2120 ;	..\AX_Radio_Lab_output\config.c:39: radio_write8(AX5043_REG_AMPLFILTER     ,                              			0x00);
      00041E 90 41 15         [24] 2121 	mov	dptr,#0x4115
      000421 E4               [12] 2122 	clr	a
      000422 F0               [24] 2123 	movx	@dptr,a
                                   2124 ;	..\AX_Radio_Lab_output\config.c:40: radio_write8(AX5043_REG_RXPARAMSETS    ,                              			0xF4);
      000423 90 41 17         [24] 2125 	mov	dptr,#0x4117
      000426 74 F4            [12] 2126 	mov	a,#0xf4
      000428 F0               [24] 2127 	movx	@dptr,a
                                   2128 ;	..\AX_Radio_Lab_output\config.c:41: radio_write8(AX5043_REG_AGCGAIN0       ,                              			0xC5);
      000429 90 41 20         [24] 2129 	mov	dptr,#0x4120
      00042C 74 C5            [12] 2130 	mov	a,#0xc5
      00042E F0               [24] 2131 	movx	@dptr,a
                                   2132 ;	..\AX_Radio_Lab_output\config.c:42: radio_write8(AX5043_REG_AGCTARGET0     ,                              			0x84);
      00042F 90 41 21         [24] 2133 	mov	dptr,#0x4121
      000432 74 84            [12] 2134 	mov	a,#0x84
      000434 F0               [24] 2135 	movx	@dptr,a
                                   2136 ;	..\AX_Radio_Lab_output\config.c:43: radio_write8(AX5043_REG_TIMEGAIN0      ,                              			0xF8);
      000435 90 41 24         [24] 2137 	mov	dptr,#0x4124
      000438 74 F8            [12] 2138 	mov	a,#0xf8
      00043A F0               [24] 2139 	movx	@dptr,a
                                   2140 ;	..\AX_Radio_Lab_output\config.c:44: radio_write8(AX5043_REG_DRGAIN0        ,                              			0xF2);
      00043B 90 41 25         [24] 2141 	mov	dptr,#0x4125
      00043E 74 F2            [12] 2142 	mov	a,#0xf2
      000440 F0               [24] 2143 	movx	@dptr,a
                                   2144 ;	..\AX_Radio_Lab_output\config.c:45: radio_write8(AX5043_REG_PHASEGAIN0     ,                              			0xC3);
      000441 90 41 26         [24] 2145 	mov	dptr,#0x4126
      000444 74 C3            [12] 2146 	mov	a,#0xc3
      000446 F0               [24] 2147 	movx	@dptr,a
                                   2148 ;	..\AX_Radio_Lab_output\config.c:46: radio_write8(AX5043_REG_FREQUENCYGAINA0,                              			0x0F);
      000447 90 41 27         [24] 2149 	mov	dptr,#0x4127
      00044A 74 0F            [12] 2150 	mov	a,#0x0f
      00044C F0               [24] 2151 	movx	@dptr,a
                                   2152 ;	..\AX_Radio_Lab_output\config.c:47: radio_write8(AX5043_REG_FREQUENCYGAINB0,                              			0x1F);
      00044D 90 41 28         [24] 2153 	mov	dptr,#0x4128
      000450 74 1F            [12] 2154 	mov	a,#0x1f
      000452 F0               [24] 2155 	movx	@dptr,a
                                   2156 ;	..\AX_Radio_Lab_output\config.c:48: radio_write8(AX5043_REG_FREQUENCYGAINC0,                              			0x08);
      000453 90 41 29         [24] 2157 	mov	dptr,#0x4129
      000456 74 08            [12] 2158 	mov	a,#0x08
      000458 F0               [24] 2159 	movx	@dptr,a
                                   2160 ;	..\AX_Radio_Lab_output\config.c:49: radio_write8(AX5043_REG_FREQUENCYGAIND0,                              			0x08);
      000459 90 41 2A         [24] 2161 	mov	dptr,#0x412a
      00045C F0               [24] 2162 	movx	@dptr,a
                                   2163 ;	..\AX_Radio_Lab_output\config.c:50: radio_write8(AX5043_REG_AMPLITUDEGAIN0 ,                              			0x06);
      00045D 90 41 2B         [24] 2164 	mov	dptr,#0x412b
      000460 74 06            [12] 2165 	mov	a,#0x06
      000462 F0               [24] 2166 	movx	@dptr,a
                                   2167 ;	..\AX_Radio_Lab_output\config.c:51: radio_write8(AX5043_REG_FREQDEV10      ,                              			0x00);
      000463 90 41 2C         [24] 2168 	mov	dptr,#0x412c
      000466 E4               [12] 2169 	clr	a
      000467 F0               [24] 2170 	movx	@dptr,a
                                   2171 ;	..\AX_Radio_Lab_output\config.c:52: radio_write8(AX5043_REG_FREQDEV00      ,                              			0x00);
      000468 90 41 2D         [24] 2172 	mov	dptr,#0x412d
      00046B F0               [24] 2173 	movx	@dptr,a
                                   2174 ;	..\AX_Radio_Lab_output\config.c:53: radio_write8(AX5043_REG_BBOFFSRES0     ,                              			0x00);
      00046C 90 41 2F         [24] 2175 	mov	dptr,#0x412f
      00046F F0               [24] 2176 	movx	@dptr,a
                                   2177 ;	..\AX_Radio_Lab_output\config.c:54: radio_write8(AX5043_REG_AGCGAIN1       ,                              			0xC5);
      000470 90 41 30         [24] 2178 	mov	dptr,#0x4130
      000473 74 C5            [12] 2179 	mov	a,#0xc5
      000475 F0               [24] 2180 	movx	@dptr,a
                                   2181 ;	..\AX_Radio_Lab_output\config.c:55: radio_write8(AX5043_REG_AGCTARGET1     ,                              			0x84);
      000476 90 41 31         [24] 2182 	mov	dptr,#0x4131
      000479 74 84            [12] 2183 	mov	a,#0x84
      00047B F0               [24] 2184 	movx	@dptr,a
                                   2185 ;	..\AX_Radio_Lab_output\config.c:56: radio_write8(AX5043_REG_AGCAHYST1      ,                              			0x00);
      00047C 90 41 32         [24] 2186 	mov	dptr,#0x4132
      00047F E4               [12] 2187 	clr	a
      000480 F0               [24] 2188 	movx	@dptr,a
                                   2189 ;	..\AX_Radio_Lab_output\config.c:57: radio_write8(AX5043_REG_AGCMINMAX1     ,                              			0x00);
      000481 90 41 33         [24] 2190 	mov	dptr,#0x4133
      000484 F0               [24] 2191 	movx	@dptr,a
                                   2192 ;	..\AX_Radio_Lab_output\config.c:58: radio_write8(AX5043_REG_TIMEGAIN1      ,                              			0xF6);
      000485 90 41 34         [24] 2193 	mov	dptr,#0x4134
      000488 74 F6            [12] 2194 	mov	a,#0xf6
      00048A F0               [24] 2195 	movx	@dptr,a
                                   2196 ;	..\AX_Radio_Lab_output\config.c:59: radio_write8(AX5043_REG_DRGAIN1        ,                              			0xF1);
      00048B 90 41 35         [24] 2197 	mov	dptr,#0x4135
      00048E 74 F1            [12] 2198 	mov	a,#0xf1
      000490 F0               [24] 2199 	movx	@dptr,a
                                   2200 ;	..\AX_Radio_Lab_output\config.c:60: radio_write8(AX5043_REG_PHASEGAIN1     ,                              			0xC3);
      000491 90 41 36         [24] 2201 	mov	dptr,#0x4136
      000494 74 C3            [12] 2202 	mov	a,#0xc3
      000496 F0               [24] 2203 	movx	@dptr,a
                                   2204 ;	..\AX_Radio_Lab_output\config.c:61: radio_write8(AX5043_REG_FREQUENCYGAINA1,                              			0x0F);
      000497 90 41 37         [24] 2205 	mov	dptr,#0x4137
      00049A 74 0F            [12] 2206 	mov	a,#0x0f
      00049C F0               [24] 2207 	movx	@dptr,a
                                   2208 ;	..\AX_Radio_Lab_output\config.c:62: radio_write8(AX5043_REG_FREQUENCYGAINB1,                              			0x1F);
      00049D 90 41 38         [24] 2209 	mov	dptr,#0x4138
      0004A0 74 1F            [12] 2210 	mov	a,#0x1f
      0004A2 F0               [24] 2211 	movx	@dptr,a
                                   2212 ;	..\AX_Radio_Lab_output\config.c:63: radio_write8(AX5043_REG_FREQUENCYGAINC1,                              			0x08);
      0004A3 90 41 39         [24] 2213 	mov	dptr,#0x4139
      0004A6 74 08            [12] 2214 	mov	a,#0x08
      0004A8 F0               [24] 2215 	movx	@dptr,a
                                   2216 ;	..\AX_Radio_Lab_output\config.c:64: radio_write8(AX5043_REG_FREQUENCYGAIND1,                              			0x08);
      0004A9 90 41 3A         [24] 2217 	mov	dptr,#0x413a
      0004AC F0               [24] 2218 	movx	@dptr,a
                                   2219 ;	..\AX_Radio_Lab_output\config.c:65: radio_write8(AX5043_REG_AMPLITUDEGAIN1 ,                              			0x06);
      0004AD 90 41 3B         [24] 2220 	mov	dptr,#0x413b
      0004B0 74 06            [12] 2221 	mov	a,#0x06
      0004B2 F0               [24] 2222 	movx	@dptr,a
                                   2223 ;	..\AX_Radio_Lab_output\config.c:66: radio_write8(AX5043_REG_FREQDEV11      ,                              			0x00);
      0004B3 90 41 3C         [24] 2224 	mov	dptr,#0x413c
      0004B6 E4               [12] 2225 	clr	a
      0004B7 F0               [24] 2226 	movx	@dptr,a
                                   2227 ;	..\AX_Radio_Lab_output\config.c:67: radio_write8(AX5043_REG_FREQDEV01      ,                              			0x43);
      0004B8 90 41 3D         [24] 2228 	mov	dptr,#0x413d
      0004BB 74 43            [12] 2229 	mov	a,#0x43
      0004BD F0               [24] 2230 	movx	@dptr,a
                                   2231 ;	..\AX_Radio_Lab_output\config.c:68: radio_write8(AX5043_REG_FOURFSK1       ,                              			0x16);
      0004BE 90 41 3E         [24] 2232 	mov	dptr,#0x413e
      0004C1 74 16            [12] 2233 	mov	a,#0x16
      0004C3 F0               [24] 2234 	movx	@dptr,a
                                   2235 ;	..\AX_Radio_Lab_output\config.c:69: radio_write8(AX5043_REG_BBOFFSRES1     ,                              			0x00);
      0004C4 90 41 3F         [24] 2236 	mov	dptr,#0x413f
      0004C7 E4               [12] 2237 	clr	a
      0004C8 F0               [24] 2238 	movx	@dptr,a
                                   2239 ;	..\AX_Radio_Lab_output\config.c:70: radio_write8(AX5043_REG_AGCGAIN3       ,                              			0xFF);
      0004C9 90 41 50         [24] 2240 	mov	dptr,#0x4150
      0004CC 14               [12] 2241 	dec	a
      0004CD F0               [24] 2242 	movx	@dptr,a
                                   2243 ;	..\AX_Radio_Lab_output\config.c:71: radio_write8(AX5043_REG_AGCTARGET3     ,                              			0x84);
      0004CE 90 41 51         [24] 2244 	mov	dptr,#0x4151
      0004D1 74 84            [12] 2245 	mov	a,#0x84
      0004D3 F0               [24] 2246 	movx	@dptr,a
                                   2247 ;	..\AX_Radio_Lab_output\config.c:72: radio_write8(AX5043_REG_AGCAHYST3      ,                              			0x00);
      0004D4 90 41 52         [24] 2248 	mov	dptr,#0x4152
      0004D7 E4               [12] 2249 	clr	a
      0004D8 F0               [24] 2250 	movx	@dptr,a
                                   2251 ;	..\AX_Radio_Lab_output\config.c:73: radio_write8(AX5043_REG_AGCMINMAX3     ,                              			0x00);
      0004D9 90 41 53         [24] 2252 	mov	dptr,#0x4153
      0004DC F0               [24] 2253 	movx	@dptr,a
                                   2254 ;	..\AX_Radio_Lab_output\config.c:74: radio_write8(AX5043_REG_TIMEGAIN3      ,                              			0xF5);
      0004DD 90 41 54         [24] 2255 	mov	dptr,#0x4154
      0004E0 74 F5            [12] 2256 	mov	a,#0xf5
      0004E2 F0               [24] 2257 	movx	@dptr,a
                                   2258 ;	..\AX_Radio_Lab_output\config.c:75: radio_write8(AX5043_REG_DRGAIN3        ,                              			0xF0);
      0004E3 90 41 55         [24] 2259 	mov	dptr,#0x4155
      0004E6 74 F0            [12] 2260 	mov	a,#0xf0
      0004E8 F0               [24] 2261 	movx	@dptr,a
                                   2262 ;	..\AX_Radio_Lab_output\config.c:76: radio_write8(AX5043_REG_PHASEGAIN3     ,                              			0xC3);
      0004E9 90 41 56         [24] 2263 	mov	dptr,#0x4156
      0004EC 74 C3            [12] 2264 	mov	a,#0xc3
      0004EE F0               [24] 2265 	movx	@dptr,a
                                   2266 ;	..\AX_Radio_Lab_output\config.c:77: radio_write8(AX5043_REG_FREQUENCYGAINA3,                              			0x0F);
      0004EF 90 41 57         [24] 2267 	mov	dptr,#0x4157
      0004F2 74 0F            [12] 2268 	mov	a,#0x0f
      0004F4 F0               [24] 2269 	movx	@dptr,a
                                   2270 ;	..\AX_Radio_Lab_output\config.c:78: radio_write8(AX5043_REG_FREQUENCYGAINB3,                              			0x1F);
      0004F5 90 41 58         [24] 2271 	mov	dptr,#0x4158
      0004F8 74 1F            [12] 2272 	mov	a,#0x1f
      0004FA F0               [24] 2273 	movx	@dptr,a
                                   2274 ;	..\AX_Radio_Lab_output\config.c:79: radio_write8(AX5043_REG_FREQUENCYGAINC3,                              			0x0C);
      0004FB 90 41 59         [24] 2275 	mov	dptr,#0x4159
      0004FE 74 0C            [12] 2276 	mov	a,#0x0c
      000500 F0               [24] 2277 	movx	@dptr,a
                                   2278 ;	..\AX_Radio_Lab_output\config.c:80: radio_write8(AX5043_REG_FREQUENCYGAIND3,                              			0x0C);
      000501 90 41 5A         [24] 2279 	mov	dptr,#0x415a
      000504 F0               [24] 2280 	movx	@dptr,a
                                   2281 ;	..\AX_Radio_Lab_output\config.c:81: radio_write8(AX5043_REG_AMPLITUDEGAIN3 ,                              			0x06);
      000505 90 41 5B         [24] 2282 	mov	dptr,#0x415b
      000508 03               [12] 2283 	rr	a
      000509 F0               [24] 2284 	movx	@dptr,a
                                   2285 ;	..\AX_Radio_Lab_output\config.c:82: radio_write8(AX5043_REG_FREQDEV13      ,                              			0x00);
      00050A 90 41 5C         [24] 2286 	mov	dptr,#0x415c
      00050D E4               [12] 2287 	clr	a
      00050E F0               [24] 2288 	movx	@dptr,a
                                   2289 ;	..\AX_Radio_Lab_output\config.c:83: radio_write8(AX5043_REG_FREQDEV03      ,                              			0x43);
      00050F 90 41 5D         [24] 2290 	mov	dptr,#0x415d
      000512 74 43            [12] 2291 	mov	a,#0x43
      000514 F0               [24] 2292 	movx	@dptr,a
                                   2293 ;	..\AX_Radio_Lab_output\config.c:84: radio_write8(AX5043_REG_FOURFSK3       ,                              			0x16);
      000515 90 41 5E         [24] 2294 	mov	dptr,#0x415e
      000518 74 16            [12] 2295 	mov	a,#0x16
      00051A F0               [24] 2296 	movx	@dptr,a
                                   2297 ;	..\AX_Radio_Lab_output\config.c:85: radio_write8(AX5043_REG_BBOFFSRES3     ,                              			0x00);
      00051B 90 41 5F         [24] 2298 	mov	dptr,#0x415f
      00051E E4               [12] 2299 	clr	a
      00051F F0               [24] 2300 	movx	@dptr,a
                                   2301 ;	..\AX_Radio_Lab_output\config.c:86: radio_write8(AX5043_REG_MODCFGF        ,                              			0x03);
      000520 90 41 60         [24] 2302 	mov	dptr,#0x4160
      000523 74 03            [12] 2303 	mov	a,#0x03
      000525 F0               [24] 2304 	movx	@dptr,a
                                   2305 ;	..\AX_Radio_Lab_output\config.c:87: radio_write8(AX5043_REG_FSKDEV2        ,                              			0x00);
      000526 90 41 61         [24] 2306 	mov	dptr,#0x4161
      000529 E4               [12] 2307 	clr	a
      00052A F0               [24] 2308 	movx	@dptr,a
                                   2309 ;	..\AX_Radio_Lab_output\config.c:88: radio_write8(AX5043_REG_FSKDEV1        ,                              			0x04);
      00052B 90 41 62         [24] 2310 	mov	dptr,#0x4162
      00052E 74 04            [12] 2311 	mov	a,#0x04
      000530 F0               [24] 2312 	movx	@dptr,a
                                   2313 ;	..\AX_Radio_Lab_output\config.c:89: radio_write8(AX5043_REG_FSKDEV0        ,                              			0x08);
      000531 90 41 63         [24] 2314 	mov	dptr,#0x4163
      000534 23               [12] 2315 	rl	a
      000535 F0               [24] 2316 	movx	@dptr,a
                                   2317 ;	..\AX_Radio_Lab_output\config.c:90: radio_write8(AX5043_REG_MODCFGA        ,                              			0x05);
      000536 90 41 64         [24] 2318 	mov	dptr,#0x4164
      000539 74 05            [12] 2319 	mov	a,#0x05
      00053B F0               [24] 2320 	movx	@dptr,a
                                   2321 ;	..\AX_Radio_Lab_output\config.c:91: radio_write8(AX5043_REG_TXRATE2        ,                              			0x00);
      00053C 90 41 65         [24] 2322 	mov	dptr,#0x4165
      00053F E4               [12] 2323 	clr	a
      000540 F0               [24] 2324 	movx	@dptr,a
                                   2325 ;	..\AX_Radio_Lab_output\config.c:92: radio_write8(AX5043_REG_TXRATE1        ,                              			0x0C);
      000541 90 41 66         [24] 2326 	mov	dptr,#0x4166
      000544 74 0C            [12] 2327 	mov	a,#0x0c
      000546 F0               [24] 2328 	movx	@dptr,a
                                   2329 ;	..\AX_Radio_Lab_output\config.c:93: radio_write8(AX5043_REG_TXRATE0        ,                              			0x19);
      000547 90 41 67         [24] 2330 	mov	dptr,#0x4167
      00054A 74 19            [12] 2331 	mov	a,#0x19
      00054C F0               [24] 2332 	movx	@dptr,a
                                   2333 ;	..\AX_Radio_Lab_output\config.c:94: radio_write8(AX5043_REG_TXPWRCOEFFB1   ,                              			0x0F);
      00054D 90 41 6A         [24] 2334 	mov	dptr,#0x416a
      000550 74 0F            [12] 2335 	mov	a,#0x0f
      000552 F0               [24] 2336 	movx	@dptr,a
                                   2337 ;	..\AX_Radio_Lab_output\config.c:95: radio_write8(AX5043_REG_TXPWRCOEFFB0   ,                              			0xFF);
      000553 90 41 6B         [24] 2338 	mov	dptr,#0x416b
      000556 74 FF            [12] 2339 	mov	a,#0xff
      000558 F0               [24] 2340 	movx	@dptr,a
                                   2341 ;	..\AX_Radio_Lab_output\config.c:96: radio_write8(AX5043_REG_PLLVCOI        ,                              			0x99);
      000559 90 41 80         [24] 2342 	mov	dptr,#0x4180
      00055C 74 99            [12] 2343 	mov	a,#0x99
      00055E F0               [24] 2344 	movx	@dptr,a
                                   2345 ;	..\AX_Radio_Lab_output\config.c:97: radio_write8(AX5043_REG_PLLRNGCLK      ,                              			0x04);
      00055F 90 41 83         [24] 2346 	mov	dptr,#0x4183
      000562 74 04            [12] 2347 	mov	a,#0x04
      000564 F0               [24] 2348 	movx	@dptr,a
                                   2349 ;	..\AX_Radio_Lab_output\config.c:98: radio_write8(AX5043_REG_BBTUNE         ,                              			0x0F);
      000565 90 41 88         [24] 2350 	mov	dptr,#0x4188
      000568 74 0F            [12] 2351 	mov	a,#0x0f
      00056A F0               [24] 2352 	movx	@dptr,a
                                   2353 ;	..\AX_Radio_Lab_output\config.c:99: radio_write8(AX5043_REG_BBOFFSCAP      ,                              			0x77);
      00056B 90 41 89         [24] 2354 	mov	dptr,#0x4189
      00056E 74 77            [12] 2355 	mov	a,#0x77
      000570 F0               [24] 2356 	movx	@dptr,a
                                   2357 ;	..\AX_Radio_Lab_output\config.c:100: radio_write8(AX5043_REG_PKTADDRCFG     ,                              			0x81);
      000571 90 42 00         [24] 2358 	mov	dptr,#0x4200
      000574 74 81            [12] 2359 	mov	a,#0x81
      000576 F0               [24] 2360 	movx	@dptr,a
                                   2361 ;	..\AX_Radio_Lab_output\config.c:101: radio_write8(AX5043_REG_PKTLENCFG      ,                              			0x80);
      000577 90 42 01         [24] 2362 	mov	dptr,#0x4201
      00057A 14               [12] 2363 	dec	a
      00057B F0               [24] 2364 	movx	@dptr,a
                                   2365 ;	..\AX_Radio_Lab_output\config.c:102: radio_write8(AX5043_REG_PKTLENOFFSET   ,                              			0x01);
      00057C 90 42 02         [24] 2366 	mov	dptr,#0x4202
      00057F 23               [12] 2367 	rl	a
      000580 F0               [24] 2368 	movx	@dptr,a
                                   2369 ;	..\AX_Radio_Lab_output\config.c:103: radio_write8(AX5043_REG_PKTMAXLEN      ,                              			0xC8);
      000581 90 42 03         [24] 2370 	mov	dptr,#0x4203
      000584 74 C8            [12] 2371 	mov	a,#0xc8
      000586 F0               [24] 2372 	movx	@dptr,a
                                   2373 ;	..\AX_Radio_Lab_output\config.c:104: radio_write8(AX5043_REG_MATCH0PAT3     ,                              			0x7B);
      000587 90 42 10         [24] 2374 	mov	dptr,#0x4210
      00058A 74 7B            [12] 2375 	mov	a,#0x7b
      00058C F0               [24] 2376 	movx	@dptr,a
                                   2377 ;	..\AX_Radio_Lab_output\config.c:105: radio_write8(AX5043_REG_MATCH0PAT2     ,                              			0x8A);
      00058D 90 42 11         [24] 2378 	mov	dptr,#0x4211
      000590 74 8A            [12] 2379 	mov	a,#0x8a
      000592 F0               [24] 2380 	movx	@dptr,a
                                   2381 ;	..\AX_Radio_Lab_output\config.c:106: radio_write8(AX5043_REG_MATCH0PAT1     ,                              			0xD0);
      000593 90 42 12         [24] 2382 	mov	dptr,#0x4212
      000596 74 D0            [12] 2383 	mov	a,#0xd0
      000598 F0               [24] 2384 	movx	@dptr,a
                                   2385 ;	..\AX_Radio_Lab_output\config.c:107: radio_write8(AX5043_REG_MATCH0PAT0     ,                              			0xC9);
      000599 90 42 13         [24] 2386 	mov	dptr,#0x4213
      00059C 74 C9            [12] 2387 	mov	a,#0xc9
      00059E F0               [24] 2388 	movx	@dptr,a
                                   2389 ;	..\AX_Radio_Lab_output\config.c:108: radio_write8(AX5043_REG_MATCH0LEN      ,                              			0x9F);
      00059F 90 42 14         [24] 2390 	mov	dptr,#0x4214
      0005A2 74 9F            [12] 2391 	mov	a,#0x9f
      0005A4 F0               [24] 2392 	movx	@dptr,a
                                   2393 ;	..\AX_Radio_Lab_output\config.c:109: radio_write8(AX5043_REG_MATCH0MAX      ,                              			0x1F);
      0005A5 90 42 16         [24] 2394 	mov	dptr,#0x4216
      0005A8 74 1F            [12] 2395 	mov	a,#0x1f
      0005AA F0               [24] 2396 	movx	@dptr,a
                                   2397 ;	..\AX_Radio_Lab_output\config.c:110: radio_write8(AX5043_REG_MATCH1PAT1     ,                              			0x55);
      0005AB 90 42 18         [24] 2398 	mov	dptr,#0x4218
      0005AE 74 55            [12] 2399 	mov	a,#0x55
      0005B0 F0               [24] 2400 	movx	@dptr,a
                                   2401 ;	..\AX_Radio_Lab_output\config.c:111: radio_write8(AX5043_REG_MATCH1PAT0     ,                              			0x55);
      0005B1 90 42 19         [24] 2402 	mov	dptr,#0x4219
      0005B4 F0               [24] 2403 	movx	@dptr,a
                                   2404 ;	..\AX_Radio_Lab_output\config.c:112: radio_write8(AX5043_REG_MATCH1LEN      ,                              			0x8A);
      0005B5 90 42 1C         [24] 2405 	mov	dptr,#0x421c
      0005B8 74 8A            [12] 2406 	mov	a,#0x8a
      0005BA F0               [24] 2407 	movx	@dptr,a
                                   2408 ;	..\AX_Radio_Lab_output\config.c:113: radio_write8(AX5043_REG_MATCH1MAX      ,                              			0x0A);
      0005BB 90 42 1E         [24] 2409 	mov	dptr,#0x421e
      0005BE 74 0A            [12] 2410 	mov	a,#0x0a
      0005C0 F0               [24] 2411 	movx	@dptr,a
                                   2412 ;	..\AX_Radio_Lab_output\config.c:114: radio_write8(AX5043_REG_TMGTXBOOST     ,                              			0x3E);
      0005C1 90 42 20         [24] 2413 	mov	dptr,#0x4220
      0005C4 74 3E            [12] 2414 	mov	a,#0x3e
      0005C6 F0               [24] 2415 	movx	@dptr,a
                                   2416 ;	..\AX_Radio_Lab_output\config.c:115: radio_write8(AX5043_REG_TMGTXSETTLE    ,                              			0x31);
      0005C7 90 42 21         [24] 2417 	mov	dptr,#0x4221
      0005CA 74 31            [12] 2418 	mov	a,#0x31
      0005CC F0               [24] 2419 	movx	@dptr,a
                                   2420 ;	..\AX_Radio_Lab_output\config.c:116: radio_write8(AX5043_REG_TMGRXBOOST     ,                              			0x3E);
      0005CD 90 42 23         [24] 2421 	mov	dptr,#0x4223
      0005D0 74 3E            [12] 2422 	mov	a,#0x3e
      0005D2 F0               [24] 2423 	movx	@dptr,a
                                   2424 ;	..\AX_Radio_Lab_output\config.c:117: radio_write8(AX5043_REG_TMGRXSETTLE    ,                              			0x31);
      0005D3 90 42 24         [24] 2425 	mov	dptr,#0x4224
      0005D6 74 31            [12] 2426 	mov	a,#0x31
      0005D8 F0               [24] 2427 	movx	@dptr,a
                                   2428 ;	..\AX_Radio_Lab_output\config.c:118: radio_write8(AX5043_REG_TMGRXOFFSACQ   ,                              			0x00);
      0005D9 90 42 25         [24] 2429 	mov	dptr,#0x4225
      0005DC E4               [12] 2430 	clr	a
      0005DD F0               [24] 2431 	movx	@dptr,a
                                   2432 ;	..\AX_Radio_Lab_output\config.c:119: radio_write8(AX5043_REG_TMGRXCOARSEAGC ,                              			0x7F);
      0005DE 90 42 26         [24] 2433 	mov	dptr,#0x4226
      0005E1 74 7F            [12] 2434 	mov	a,#0x7f
      0005E3 F0               [24] 2435 	movx	@dptr,a
                                   2436 ;	..\AX_Radio_Lab_output\config.c:120: radio_write8(AX5043_REG_TMGRXRSSI      ,                              			0x03);
      0005E4 90 42 28         [24] 2437 	mov	dptr,#0x4228
      0005E7 74 03            [12] 2438 	mov	a,#0x03
      0005E9 F0               [24] 2439 	movx	@dptr,a
                                   2440 ;	..\AX_Radio_Lab_output\config.c:121: radio_write8(AX5043_REG_TMGRXPREAMBLE2 ,                              			0x35);
      0005EA 90 42 2A         [24] 2441 	mov	dptr,#0x422a
      0005ED 74 35            [12] 2442 	mov	a,#0x35
      0005EF F0               [24] 2443 	movx	@dptr,a
                                   2444 ;	..\AX_Radio_Lab_output\config.c:122: radio_write8(AX5043_REG_RSSIABSTHR     ,                              			0xE0);
      0005F0 90 42 2D         [24] 2445 	mov	dptr,#0x422d
      0005F3 74 E0            [12] 2446 	mov	a,#0xe0
      0005F5 F0               [24] 2447 	movx	@dptr,a
                                   2448 ;	..\AX_Radio_Lab_output\config.c:123: radio_write8(AX5043_REG_BGNDRSSITHR    ,                              			0x00);
      0005F6 90 42 2F         [24] 2449 	mov	dptr,#0x422f
      0005F9 E4               [12] 2450 	clr	a
      0005FA F0               [24] 2451 	movx	@dptr,a
                                   2452 ;	..\AX_Radio_Lab_output\config.c:124: radio_write8(AX5043_REG_PKTCHUNKSIZE   ,                              			0x0D);
      0005FB 90 42 30         [24] 2453 	mov	dptr,#0x4230
      0005FE 74 0D            [12] 2454 	mov	a,#0x0d
      000600 F0               [24] 2455 	movx	@dptr,a
                                   2456 ;	..\AX_Radio_Lab_output\config.c:125: radio_write8(AX5043_REG_PKTACCEPTFLAGS ,                              			0x20);
      000601 90 42 33         [24] 2457 	mov	dptr,#0x4233
      000604 74 20            [12] 2458 	mov	a,#0x20
      000606 F0               [24] 2459 	movx	@dptr,a
                                   2460 ;	..\AX_Radio_Lab_output\config.c:126: radio_write8(AX5043_REG_DACVALUE1      ,                              			0x00);
      000607 90 43 30         [24] 2461 	mov	dptr,#0x4330
      00060A E4               [12] 2462 	clr	a
      00060B F0               [24] 2463 	movx	@dptr,a
                                   2464 ;	..\AX_Radio_Lab_output\config.c:127: radio_write8(AX5043_REG_DACVALUE0      ,                              			0x00);
      00060C 90 43 31         [24] 2465 	mov	dptr,#0x4331
      00060F F0               [24] 2466 	movx	@dptr,a
                                   2467 ;	..\AX_Radio_Lab_output\config.c:128: radio_write8(AX5043_REG_DACCONFIG      ,                              			0x00);
      000610 90 43 32         [24] 2468 	mov	dptr,#0x4332
      000613 F0               [24] 2469 	movx	@dptr,a
                                   2470 ;	..\AX_Radio_Lab_output\config.c:129: radio_write8(AX5043_REG_REF            ,                              			0x03);
      000614 90 4F 0D         [24] 2471 	mov	dptr,#0x4f0d
      000617 74 03            [12] 2472 	mov	a,#0x03
      000619 F0               [24] 2473 	movx	@dptr,a
                                   2474 ;	..\AX_Radio_Lab_output\config.c:130: radio_write8(AX5043_REG_XTALOSC        ,                              			0x04);
      00061A 90 4F 10         [24] 2475 	mov	dptr,#0x4f10
      00061D 04               [12] 2476 	inc	a
      00061E F0               [24] 2477 	movx	@dptr,a
                                   2478 ;	..\AX_Radio_Lab_output\config.c:131: radio_write8(AX5043_REG_XTALAMPL       ,                              			0x00);
      00061F 90 4F 11         [24] 2479 	mov	dptr,#0x4f11
      000622 E4               [12] 2480 	clr	a
      000623 F0               [24] 2481 	movx	@dptr,a
                                   2482 ;	..\AX_Radio_Lab_output\config.c:132: radio_write8(AX5043_REG_0xF1C          ,                              			0x07);
      000624 90 4F 1C         [24] 2483 	mov	dptr,#0x4f1c
      000627 74 07            [12] 2484 	mov	a,#0x07
      000629 F0               [24] 2485 	movx	@dptr,a
                                   2486 ;	..\AX_Radio_Lab_output\config.c:133: radio_write8(AX5043_REG_0xF21          ,                              			0x68);
      00062A 90 4F 21         [24] 2487 	mov	dptr,#0x4f21
      00062D 74 68            [12] 2488 	mov	a,#0x68
      00062F F0               [24] 2489 	movx	@dptr,a
                                   2490 ;	..\AX_Radio_Lab_output\config.c:134: radio_write8(AX5043_REG_0xF22          ,                              			0xFF);
      000630 90 4F 22         [24] 2491 	mov	dptr,#0x4f22
      000633 74 FF            [12] 2492 	mov	a,#0xff
      000635 F0               [24] 2493 	movx	@dptr,a
                                   2494 ;	..\AX_Radio_Lab_output\config.c:135: radio_write8(AX5043_REG_0xF23          ,                              			0x84);
      000636 90 4F 23         [24] 2495 	mov	dptr,#0x4f23
      000639 74 84            [12] 2496 	mov	a,#0x84
      00063B F0               [24] 2497 	movx	@dptr,a
                                   2498 ;	..\AX_Radio_Lab_output\config.c:136: radio_write8(AX5043_REG_0xF26          ,                              			0x98);
      00063C 90 4F 26         [24] 2499 	mov	dptr,#0x4f26
      00063F 74 98            [12] 2500 	mov	a,#0x98
      000641 F0               [24] 2501 	movx	@dptr,a
                                   2502 ;	..\AX_Radio_Lab_output\config.c:137: radio_write8(AX5043_REG_0xF34          ,                              			0x08);
      000642 90 4F 34         [24] 2503 	mov	dptr,#0x4f34
      000645 74 08            [12] 2504 	mov	a,#0x08
      000647 F0               [24] 2505 	movx	@dptr,a
                                   2506 ;	..\AX_Radio_Lab_output\config.c:138: radio_write8(AX5043_REG_0xF35          ,                              			0x11);
      000648 90 4F 35         [24] 2507 	mov	dptr,#0x4f35
      00064B 74 11            [12] 2508 	mov	a,#0x11
      00064D F0               [24] 2509 	movx	@dptr,a
                                   2510 ;	..\AX_Radio_Lab_output\config.c:139: radio_write8(AX5043_REG_0xF44          ,                              			0x25);
      00064E 90 4F 44         [24] 2511 	mov	dptr,#0x4f44
      000651 74 25            [12] 2512 	mov	a,#0x25
      000653 F0               [24] 2513 	movx	@dptr,a
      000654 22               [24] 2514 	ret
                                   2515 ;------------------------------------------------------------
                                   2516 ;Allocation info for local variables in function 'ax5043_set_registers_tx'
                                   2517 ;------------------------------------------------------------
                                   2518 ;	..\AX_Radio_Lab_output\config.c:143: __reentrantb void ax5043_set_registers_tx(void) __reentrant
                                   2519 ;	-----------------------------------------
                                   2520 ;	 function ax5043_set_registers_tx
                                   2521 ;	-----------------------------------------
      000655                       2522 _ax5043_set_registers_tx:
                                   2523 ;	..\AX_Radio_Lab_output\config.c:145: radio_write8(AX5043_REG_PLLLOOP        ,                              			0x07);
      000655 90 40 30         [24] 2524 	mov	dptr,#0x4030
      000658 74 07            [12] 2525 	mov	a,#0x07
      00065A F0               [24] 2526 	movx	@dptr,a
                                   2527 ;	..\AX_Radio_Lab_output\config.c:146: radio_write8(AX5043_REG_PLLCPI         ,                              			0x12);
      00065B 90 40 31         [24] 2528 	mov	dptr,#0x4031
      00065E 74 12            [12] 2529 	mov	a,#0x12
      000660 F0               [24] 2530 	movx	@dptr,a
                                   2531 ;	..\AX_Radio_Lab_output\config.c:147: radio_write8(AX5043_REG_PLLVCODIV      ,                              			0x20);
      000661 90 40 32         [24] 2532 	mov	dptr,#0x4032
      000664 74 20            [12] 2533 	mov	a,#0x20
      000666 F0               [24] 2534 	movx	@dptr,a
                                   2535 ;	..\AX_Radio_Lab_output\config.c:148: radio_write8(AX5043_REG_XTALCAP        ,                              			0x00);
      000667 90 41 84         [24] 2536 	mov	dptr,#0x4184
      00066A E4               [12] 2537 	clr	a
      00066B F0               [24] 2538 	movx	@dptr,a
                                   2539 ;	..\AX_Radio_Lab_output\config.c:149: radio_write8(AX5043_REG_0xF00          ,                              			0x0F);
      00066C 90 4F 00         [24] 2540 	mov	dptr,#0x4f00
      00066F 74 0F            [12] 2541 	mov	a,#0x0f
      000671 F0               [24] 2542 	movx	@dptr,a
                                   2543 ;	..\AX_Radio_Lab_output\config.c:150: radio_write8(AX5043_REG_0xF18          ,                              			0x06);
      000672 90 4F 18         [24] 2544 	mov	dptr,#0x4f18
      000675 74 06            [12] 2545 	mov	a,#0x06
      000677 F0               [24] 2546 	movx	@dptr,a
      000678 22               [24] 2547 	ret
                                   2548 ;------------------------------------------------------------
                                   2549 ;Allocation info for local variables in function 'ax5043_set_registers_rx'
                                   2550 ;------------------------------------------------------------
                                   2551 ;	..\AX_Radio_Lab_output\config.c:154: __reentrantb void ax5043_set_registers_rx(void) __reentrant
                                   2552 ;	-----------------------------------------
                                   2553 ;	 function ax5043_set_registers_rx
                                   2554 ;	-----------------------------------------
      000679                       2555 _ax5043_set_registers_rx:
                                   2556 ;	..\AX_Radio_Lab_output\config.c:156: radio_write8(AX5043_REG_PLLLOOP        ,                              			0x07);
      000679 90 40 30         [24] 2557 	mov	dptr,#0x4030
      00067C 74 07            [12] 2558 	mov	a,#0x07
      00067E F0               [24] 2559 	movx	@dptr,a
                                   2560 ;	..\AX_Radio_Lab_output\config.c:157: radio_write8(AX5043_REG_PLLCPI         ,                              			0x08);
      00067F 90 40 31         [24] 2561 	mov	dptr,#0x4031
      000682 04               [12] 2562 	inc	a
      000683 F0               [24] 2563 	movx	@dptr,a
                                   2564 ;	..\AX_Radio_Lab_output\config.c:158: radio_write8(AX5043_REG_PLLVCODIV      ,                              			0x20);
      000684 90 40 32         [24] 2565 	mov	dptr,#0x4032
      000687 74 20            [12] 2566 	mov	a,#0x20
      000689 F0               [24] 2567 	movx	@dptr,a
                                   2568 ;	..\AX_Radio_Lab_output\config.c:159: radio_write8(AX5043_REG_XTALCAP        ,                              			0x00);
      00068A 90 41 84         [24] 2569 	mov	dptr,#0x4184
      00068D E4               [12] 2570 	clr	a
      00068E F0               [24] 2571 	movx	@dptr,a
                                   2572 ;	..\AX_Radio_Lab_output\config.c:160: radio_write8(AX5043_REG_0xF00          ,                              			0x0F);
      00068F 90 4F 00         [24] 2573 	mov	dptr,#0x4f00
      000692 74 0F            [12] 2574 	mov	a,#0x0f
      000694 F0               [24] 2575 	movx	@dptr,a
                                   2576 ;	..\AX_Radio_Lab_output\config.c:161: radio_write8(AX5043_REG_0xF18          ,                              			0x06);
      000695 90 4F 18         [24] 2577 	mov	dptr,#0x4f18
      000698 74 06            [12] 2578 	mov	a,#0x06
      00069A F0               [24] 2579 	movx	@dptr,a
      00069B 22               [24] 2580 	ret
                                   2581 ;------------------------------------------------------------
                                   2582 ;Allocation info for local variables in function 'ax5043_set_registers_rxwor'
                                   2583 ;------------------------------------------------------------
                                   2584 ;	..\AX_Radio_Lab_output\config.c:165: __reentrantb void ax5043_set_registers_rxwor(void) __reentrant
                                   2585 ;	-----------------------------------------
                                   2586 ;	 function ax5043_set_registers_rxwor
                                   2587 ;	-----------------------------------------
      00069C                       2588 _ax5043_set_registers_rxwor:
                                   2589 ;	..\AX_Radio_Lab_output\config.c:167: radio_write8(AX5043_REG_TMGRXAGC,                 0x0A);
      00069C 90 42 27         [24] 2590 	mov	dptr,#0x4227
      00069F 74 0A            [12] 2591 	mov	a,#0x0a
      0006A1 F0               [24] 2592 	movx	@dptr,a
                                   2593 ;	..\AX_Radio_Lab_output\config.c:168: radio_write8(AX5043_REG_TMGRXPREAMBLE1,           0x19);
      0006A2 90 42 29         [24] 2594 	mov	dptr,#0x4229
      0006A5 74 19            [12] 2595 	mov	a,#0x19
      0006A7 F0               [24] 2596 	movx	@dptr,a
                                   2597 ;	..\AX_Radio_Lab_output\config.c:169: radio_write8(AX5043_REG_PKTMISCFLAGS,             0x03);
      0006A8 90 42 31         [24] 2598 	mov	dptr,#0x4231
      0006AB 74 03            [12] 2599 	mov	a,#0x03
      0006AD F0               [24] 2600 	movx	@dptr,a
      0006AE 22               [24] 2601 	ret
                                   2602 ;------------------------------------------------------------
                                   2603 ;Allocation info for local variables in function 'ax5043_set_registers_rxcont'
                                   2604 ;------------------------------------------------------------
                                   2605 ;	..\AX_Radio_Lab_output\config.c:173: __reentrantb void ax5043_set_registers_rxcont(void) __reentrant
                                   2606 ;	-----------------------------------------
                                   2607 ;	 function ax5043_set_registers_rxcont
                                   2608 ;	-----------------------------------------
      0006AF                       2609 _ax5043_set_registers_rxcont:
                                   2610 ;	..\AX_Radio_Lab_output\config.c:175: radio_write8(AX5043_REG_TMGRXAGC,                 0x00);
      0006AF 90 42 27         [24] 2611 	mov	dptr,#0x4227
      0006B2 E4               [12] 2612 	clr	a
      0006B3 F0               [24] 2613 	movx	@dptr,a
                                   2614 ;	..\AX_Radio_Lab_output\config.c:176: radio_write8(AX5043_REG_TMGRXPREAMBLE1,           0x00);
      0006B4 90 42 29         [24] 2615 	mov	dptr,#0x4229
      0006B7 F0               [24] 2616 	movx	@dptr,a
                                   2617 ;	..\AX_Radio_Lab_output\config.c:177: radio_write8(AX5043_REG_PKTMISCFLAGS,             0x00);
      0006B8 90 42 31         [24] 2618 	mov	dptr,#0x4231
      0006BB F0               [24] 2619 	movx	@dptr,a
      0006BC 22               [24] 2620 	ret
                                   2621 ;------------------------------------------------------------
                                   2622 ;Allocation info for local variables in function 'ax5043_set_registers_rxcont_singleparamset'
                                   2623 ;------------------------------------------------------------
                                   2624 ;	..\AX_Radio_Lab_output\config.c:181: __reentrantb void ax5043_set_registers_rxcont_singleparamset(void) __reentrant
                                   2625 ;	-----------------------------------------
                                   2626 ;	 function ax5043_set_registers_rxcont_singleparamset
                                   2627 ;	-----------------------------------------
      0006BD                       2628 _ax5043_set_registers_rxcont_singleparamset:
                                   2629 ;	..\AX_Radio_Lab_output\config.c:183: radio_write8(AX5043_REG_RXPARAMSETS,              0xFF);
      0006BD 90 41 17         [24] 2630 	mov	dptr,#0x4117
      0006C0 74 FF            [12] 2631 	mov	a,#0xff
      0006C2 F0               [24] 2632 	movx	@dptr,a
                                   2633 ;	..\AX_Radio_Lab_output\config.c:184: radio_write8(AX5043_REG_FREQDEV13,                0x00);
      0006C3 90 41 5C         [24] 2634 	mov	dptr,#0x415c
      0006C6 E4               [12] 2635 	clr	a
      0006C7 F0               [24] 2636 	movx	@dptr,a
                                   2637 ;	..\AX_Radio_Lab_output\config.c:185: radio_write8(AX5043_REG_FREQDEV03,                0x00);
      0006C8 90 41 5D         [24] 2638 	mov	dptr,#0x415d
      0006CB F0               [24] 2639 	movx	@dptr,a
                                   2640 ;	..\AX_Radio_Lab_output\config.c:186: radio_write8(AX5043_REG_AGCGAIN3,                 0xE7);
      0006CC 90 41 50         [24] 2641 	mov	dptr,#0x4150
      0006CF 74 E7            [12] 2642 	mov	a,#0xe7
      0006D1 F0               [24] 2643 	movx	@dptr,a
      0006D2 22               [24] 2644 	ret
                                   2645 ;------------------------------------------------------------
                                   2646 ;Allocation info for local variables in function 'axradio_setup_pincfg1'
                                   2647 ;------------------------------------------------------------
                                   2648 ;	..\AX_Radio_Lab_output\config.c:191: __reentrantb void axradio_setup_pincfg1(void) __reentrant
                                   2649 ;	-----------------------------------------
                                   2650 ;	 function axradio_setup_pincfg1
                                   2651 ;	-----------------------------------------
      0006D3                       2652 _axradio_setup_pincfg1:
                                   2653 ;	..\AX_Radio_Lab_output\config.c:196: PALTRADIO = 0x00; //pass through  
      0006D3 90 70 46         [24] 2654 	mov	dptr,#_PALTRADIO
      0006D6 E4               [12] 2655 	clr	a
      0006D7 F0               [24] 2656 	movx	@dptr,a
      0006D8 22               [24] 2657 	ret
                                   2658 ;------------------------------------------------------------
                                   2659 ;Allocation info for local variables in function 'axradio_setup_pincfg2'
                                   2660 ;------------------------------------------------------------
                                   2661 ;	..\AX_Radio_Lab_output\config.c:201: __reentrantb void axradio_setup_pincfg2(void) __reentrant
                                   2662 ;	-----------------------------------------
                                   2663 ;	 function axradio_setup_pincfg2
                                   2664 ;	-----------------------------------------
      0006D9                       2665 _axradio_setup_pincfg2:
                                   2666 ;	..\AX_Radio_Lab_output\config.c:206: PORTR = (PORTR & 0x3F) | 0x00; //AX8052F143 --> no pull-ups on PR6, PR7
      0006D9 53 8C 3F         [24] 2667 	anl	_PORTR,#0x3f
      0006DC 22               [24] 2668 	ret
                                   2669 ;------------------------------------------------------------
                                   2670 ;Allocation info for local variables in function 'axradio_conv_freq_fromhz'
                                   2671 ;------------------------------------------------------------
                                   2672 ;f                         Allocated to registers 
                                   2673 ;------------------------------------------------------------
                                   2674 ;	..\AX_Radio_Lab_output\config.c:614: int32_t axradio_conv_freq_fromhz(int32_t f)
                                   2675 ;	-----------------------------------------
                                   2676 ;	 function axradio_conv_freq_fromhz
                                   2677 ;	-----------------------------------------
      0006DD                       2678 _axradio_conv_freq_fromhz:
                                   2679 ;	..\AX_Radio_Lab_output\config.c:620: CONSTMULFIX24(0xa530e8);
      0006DD A8 82            [24] 2680 	mov r0,dpl 
      0006DF A9 83            [24] 2681 	mov r1,dph 
      0006E1 AA F0            [24] 2682 	mov r2,b 
      0006E3 FB               [12] 2683 	mov r3,a 
      0006E4 C0 E0            [24] 2684 	push acc 
      0006E6 30 E7 0D         [24] 2685 	jnb acc.7,00000$ 
      0006E9 C3               [12] 2686 	clr c 
      0006EA E4               [12] 2687 	clr a 
      0006EB 98               [12] 2688 	subb a,r0 
      0006EC F8               [12] 2689 	mov r0,a 
      0006ED E4               [12] 2690 	clr a 
      0006EE 99               [12] 2691 	subb a,r1 
      0006EF F9               [12] 2692 	mov r1,a 
      0006F0 E4               [12] 2693 	clr a 
      0006F1 9A               [12] 2694 	subb a,r2 
      0006F2 FA               [12] 2695 	mov r2,a 
      0006F3 E4               [12] 2696 	clr a 
      0006F4 9B               [12] 2697 	subb a,r3 
      0006F5 FB               [12] 2698 	mov r3,a 
      0006F6                       2699 	 00000$:
      0006F6 E4               [12] 2700 	clr a 
      0006F7 FC               [12] 2701 	mov r4,a 
      0006F8 FD               [12] 2702 	mov r5,a 
      0006F9 FE               [12] 2703 	mov r6,a 
      0006FA FF               [12] 2704 	mov r7,a 
                                   2705 ;; stage -1 
                           000001  2706 	.if (((0xa530e8)>>16)&0xff) 
      0006FB 74 A5            [12] 2707 	mov a,# (((0xa530e8)>>16)&0xff) 
      0006FD 88 F0            [24] 2708 	mov b,r0 
      0006FF A4               [48] 2709 	mul ab 
      000700 FF               [12] 2710 	mov r7,a 
      000701 AC F0            [24] 2711 	mov r4,b 
                                   2712 	.endif 
                           000001  2713 	.if (((0xa530e8)>>8)&0xff) 
      000703 74 30            [12] 2714 	mov a,# (((0xa530e8)>>8)&0xff) 
      000705 89 F0            [24] 2715 	mov b,r1 
      000707 A4               [48] 2716 	mul ab 
                           000001  2717 	.if (((0xa530e8)>>16)&0xff) 
      000708 2F               [12] 2718 	add a,r7 
      000709 FF               [12] 2719 	mov r7,a 
      00070A E5 F0            [12] 2720 	mov a,b 
      00070C 3C               [12] 2721 	addc a,r4 
      00070D FC               [12] 2722 	mov r4,a 
      00070E E4               [12] 2723 	clr a 
      00070F 3D               [12] 2724 	addc a,r5 
      000710 FD               [12] 2725 	mov r5,a 
                           000000  2726 	.else 
                                   2727 	mov r7,a 
                                   2728 	mov r4,b 
                                   2729 	.endif 
                                   2730 	.endif 
                           000001  2731 	.if ((0xa530e8)&0xff) 
      000711 74 E8            [12] 2732 	mov a,# ((0xa530e8)&0xff) 
      000713 8A F0            [24] 2733 	mov b,r2 
      000715 A4               [48] 2734 	mul ab 
                           000001  2735 	.if (((0xa530e8)>>8)&0xffff) 
      000716 2F               [12] 2736 	add a,r7 
      000717 FF               [12] 2737 	mov r7,a 
      000718 E5 F0            [12] 2738 	mov a,b 
      00071A 3C               [12] 2739 	addc a,r4 
      00071B FC               [12] 2740 	mov r4,a 
      00071C E4               [12] 2741 	clr a 
      00071D 3D               [12] 2742 	addc a,r5 
      00071E FD               [12] 2743 	mov r5,a 
                           000000  2744 	.else 
                                   2745 	mov r7,a 
                                   2746 	mov r4,b 
                                   2747 	.endif 
                                   2748 	.endif 
                                   2749 ;; clear precision extension 
      00071F E4               [12] 2750 	clr a 
      000720 FF               [12] 2751 	mov r7,a 
                                   2752 ;; stage 0 
                           000000  2753 	.if (((0xa530e8)>>24)&0xff) 
                                   2754 	mov a,# (((0xa530e8)>>24)&0xff) 
                                   2755 	mov b,r0 
                                   2756 	mul ab 
                                   2757 	add a,r4 
                                   2758 	mov r4,a 
                                   2759 	mov a,b 
                                   2760 	addc a,r5 
                                   2761 	mov r5,a 
                                   2762 	clr a 
                                   2763 	addc a,r6 
                                   2764 	mov r6,a 
                                   2765 	.endif 
                           000001  2766 	.if (((0xa530e8)>>16)&0xff) 
      000721 74 A5            [12] 2767 	mov a,# (((0xa530e8)>>16)&0xff) 
      000723 89 F0            [24] 2768 	mov b,r1 
      000725 A4               [48] 2769 	mul ab 
      000726 2C               [12] 2770 	add a,r4 
      000727 FC               [12] 2771 	mov r4,a 
      000728 E5 F0            [12] 2772 	mov a,b 
      00072A 3D               [12] 2773 	addc a,r5 
      00072B FD               [12] 2774 	mov r5,a 
      00072C E4               [12] 2775 	clr a 
      00072D 3E               [12] 2776 	addc a,r6 
      00072E FE               [12] 2777 	mov r6,a 
                                   2778 	.endif 
                           000001  2779 	.if (((0xa530e8)>>8)&0xff) 
      00072F 74 30            [12] 2780 	mov a,# (((0xa530e8)>>8)&0xff) 
      000731 8A F0            [24] 2781 	mov b,r2 
      000733 A4               [48] 2782 	mul ab 
      000734 2C               [12] 2783 	add a,r4 
      000735 FC               [12] 2784 	mov r4,a 
      000736 E5 F0            [12] 2785 	mov a,b 
      000738 3D               [12] 2786 	addc a,r5 
      000739 FD               [12] 2787 	mov r5,a 
      00073A E4               [12] 2788 	clr a 
      00073B 3E               [12] 2789 	addc a,r6 
      00073C FE               [12] 2790 	mov r6,a 
                                   2791 	.endif 
                           000001  2792 	.if ((0xa530e8)&0xff) 
      00073D 74 E8            [12] 2793 	mov a,# ((0xa530e8)&0xff) 
      00073F 8B F0            [24] 2794 	mov b,r3 
      000741 A4               [48] 2795 	mul ab 
      000742 2C               [12] 2796 	add a,r4 
      000743 FC               [12] 2797 	mov r4,a 
      000744 E5 F0            [12] 2798 	mov a,b 
      000746 3D               [12] 2799 	addc a,r5 
      000747 FD               [12] 2800 	mov r5,a 
      000748 E4               [12] 2801 	clr a 
      000749 3E               [12] 2802 	addc a,r6 
      00074A FE               [12] 2803 	mov r6,a 
                                   2804 	.endif 
                                   2805 ;; stage 1 
                           000000  2806 	.if (((0xa530e8)>>24)&0xff) 
                                   2807 	mov a,# (((0xa530e8)>>24)&0xff) 
                                   2808 	mov b,r1 
                                   2809 	mul ab 
                                   2810 	add a,r5 
                                   2811 	mov r5,a 
                                   2812 	mov a,b 
                                   2813 	addc a,r6 
                                   2814 	mov r6,a 
                                   2815 	clr a 
                                   2816 	addc a,r7 
                                   2817 	mov r7,a 
                                   2818 	.endif 
                           000001  2819 	.if (((0xa530e8)>>16)&0xff) 
      00074B 74 A5            [12] 2820 	mov a,# (((0xa530e8)>>16)&0xff) 
      00074D 8A F0            [24] 2821 	mov b,r2 
      00074F A4               [48] 2822 	mul ab 
      000750 2D               [12] 2823 	add a,r5 
      000751 FD               [12] 2824 	mov r5,a 
      000752 E5 F0            [12] 2825 	mov a,b 
      000754 3E               [12] 2826 	addc a,r6 
      000755 FE               [12] 2827 	mov r6,a 
      000756 E4               [12] 2828 	clr a 
      000757 3F               [12] 2829 	addc a,r7 
      000758 FF               [12] 2830 	mov r7,a 
                                   2831 	.endif 
                           000001  2832 	.if (((0xa530e8)>>8)&0xff) 
      000759 74 30            [12] 2833 	mov a,# (((0xa530e8)>>8)&0xff) 
      00075B 8B F0            [24] 2834 	mov b,r3 
      00075D A4               [48] 2835 	mul ab 
      00075E 2D               [12] 2836 	add a,r5 
      00075F FD               [12] 2837 	mov r5,a 
      000760 E5 F0            [12] 2838 	mov a,b 
      000762 3E               [12] 2839 	addc a,r6 
      000763 FE               [12] 2840 	mov r6,a 
      000764 E4               [12] 2841 	clr a 
      000765 3F               [12] 2842 	addc a,r7 
      000766 FF               [12] 2843 	mov r7,a 
                                   2844 	.endif 
                                   2845 ;; stage 2 
                           000000  2846 	.if (((0xa530e8)>>24)&0xff) 
                                   2847 	mov a,# (((0xa530e8)>>24)&0xff) 
                                   2848 	mov b,r2 
                                   2849 	mul ab 
                                   2850 	add a,r6 
                                   2851 	mov r6,a 
                                   2852 	mov a,b 
                                   2853 	addc a,r7 
                                   2854 	mov r7,a 
                                   2855 	.endif 
                           000001  2856 	.if (((0xa530e8)>>16)&0xff) 
      000767 74 A5            [12] 2857 	mov a,# (((0xa530e8)>>16)&0xff) 
      000769 8B F0            [24] 2858 	mov b,r3 
      00076B A4               [48] 2859 	mul ab 
      00076C 2E               [12] 2860 	add a,r6 
      00076D FE               [12] 2861 	mov r6,a 
      00076E E5 F0            [12] 2862 	mov a,b 
      000770 3F               [12] 2863 	addc a,r7 
      000771 FF               [12] 2864 	mov r7,a 
                                   2865 	.endif 
                                   2866 ;; stage 3 
                           000000  2867 	.if (((0xa530e8)>>24)&0xff) 
                                   2868 	mov a,# (((0xa530e8)>>24)&0xff) 
                                   2869 	mov b,r3 
                                   2870 	mul ab 
                                   2871 	add a,r7 
                                   2872 	mov r7,a 
                                   2873 	.endif 
      000772 D0 E0            [24] 2874 	pop acc 
      000774 30 E7 11         [24] 2875 	jnb acc.7,00001$ 
      000777 C3               [12] 2876 	clr c 
      000778 E4               [12] 2877 	clr a 
      000779 9C               [12] 2878 	subb a,r4 
      00077A F5 82            [12] 2879 	mov dpl,a 
      00077C E4               [12] 2880 	clr a 
      00077D 9D               [12] 2881 	subb a,r5 
      00077E F5 83            [12] 2882 	mov dph,a 
      000780 E4               [12] 2883 	clr a 
      000781 9E               [12] 2884 	subb a,r6 
      000782 F5 F0            [12] 2885 	mov b,a 
      000784 E4               [12] 2886 	clr a 
      000785 9F               [12] 2887 	subb a,r7 
      000786 80 07            [24] 2888 	sjmp 00002$ 
      000788                       2889 	 00001$:
      000788 8C 82            [24] 2890 	mov dpl,r4 
      00078A 8D 83            [24] 2891 	mov dph,r5 
      00078C 8E F0            [24] 2892 	mov b,r6 
      00078E EF               [12] 2893 	mov a,r7 
      00078F                       2894 	 00002$:
      00078F 22               [24] 2895 	ret
                                   2896 ;------------------------------------------------------------
                                   2897 ;Allocation info for local variables in function 'axradio_conv_freq_tohz'
                                   2898 ;------------------------------------------------------------
                                   2899 ;f                         Allocated to registers 
                                   2900 ;------------------------------------------------------------
                                   2901 ;	..\AX_Radio_Lab_output\config.c:626: int32_t axradio_conv_freq_tohz(int32_t f)
                                   2902 ;	-----------------------------------------
                                   2903 ;	 function axradio_conv_freq_tohz
                                   2904 ;	-----------------------------------------
      000790                       2905 _axradio_conv_freq_tohz:
                                   2906 ;	..\AX_Radio_Lab_output\config.c:632: CONSTMULFIX24(0x18cba80);
      000790 A8 82            [24] 2907 	mov r0,dpl 
      000792 A9 83            [24] 2908 	mov r1,dph 
      000794 AA F0            [24] 2909 	mov r2,b 
      000796 FB               [12] 2910 	mov r3,a 
      000797 C0 E0            [24] 2911 	push acc 
      000799 30 E7 0D         [24] 2912 	jnb acc.7,00000$ 
      00079C C3               [12] 2913 	clr c 
      00079D E4               [12] 2914 	clr a 
      00079E 98               [12] 2915 	subb a,r0 
      00079F F8               [12] 2916 	mov r0,a 
      0007A0 E4               [12] 2917 	clr a 
      0007A1 99               [12] 2918 	subb a,r1 
      0007A2 F9               [12] 2919 	mov r1,a 
      0007A3 E4               [12] 2920 	clr a 
      0007A4 9A               [12] 2921 	subb a,r2 
      0007A5 FA               [12] 2922 	mov r2,a 
      0007A6 E4               [12] 2923 	clr a 
      0007A7 9B               [12] 2924 	subb a,r3 
      0007A8 FB               [12] 2925 	mov r3,a 
      0007A9                       2926 	 00000$:
      0007A9 E4               [12] 2927 	clr a 
      0007AA FC               [12] 2928 	mov r4,a 
      0007AB FD               [12] 2929 	mov r5,a 
      0007AC FE               [12] 2930 	mov r6,a 
      0007AD FF               [12] 2931 	mov r7,a 
                                   2932 ;; stage -1 
                           000001  2933 	.if (((0x18cba80)>>16)&0xff) 
      0007AE 74 8C            [12] 2934 	mov a,# (((0x18cba80)>>16)&0xff) 
      0007B0 88 F0            [24] 2935 	mov b,r0 
      0007B2 A4               [48] 2936 	mul ab 
      0007B3 FF               [12] 2937 	mov r7,a 
      0007B4 AC F0            [24] 2938 	mov r4,b 
                                   2939 	.endif 
                           000001  2940 	.if (((0x18cba80)>>8)&0xff) 
      0007B6 74 BA            [12] 2941 	mov a,# (((0x18cba80)>>8)&0xff) 
      0007B8 89 F0            [24] 2942 	mov b,r1 
      0007BA A4               [48] 2943 	mul ab 
                           000001  2944 	.if (((0x18cba80)>>16)&0xff) 
      0007BB 2F               [12] 2945 	add a,r7 
      0007BC FF               [12] 2946 	mov r7,a 
      0007BD E5 F0            [12] 2947 	mov a,b 
      0007BF 3C               [12] 2948 	addc a,r4 
      0007C0 FC               [12] 2949 	mov r4,a 
      0007C1 E4               [12] 2950 	clr a 
      0007C2 3D               [12] 2951 	addc a,r5 
      0007C3 FD               [12] 2952 	mov r5,a 
                           000000  2953 	.else 
                                   2954 	mov r7,a 
                                   2955 	mov r4,b 
                                   2956 	.endif 
                                   2957 	.endif 
                           000001  2958 	.if ((0x18cba80)&0xff) 
      0007C4 74 80            [12] 2959 	mov a,# ((0x18cba80)&0xff) 
      0007C6 8A F0            [24] 2960 	mov b,r2 
      0007C8 A4               [48] 2961 	mul ab 
                           000001  2962 	.if (((0x18cba80)>>8)&0xffff) 
      0007C9 2F               [12] 2963 	add a,r7 
      0007CA FF               [12] 2964 	mov r7,a 
      0007CB E5 F0            [12] 2965 	mov a,b 
      0007CD 3C               [12] 2966 	addc a,r4 
      0007CE FC               [12] 2967 	mov r4,a 
      0007CF E4               [12] 2968 	clr a 
      0007D0 3D               [12] 2969 	addc a,r5 
      0007D1 FD               [12] 2970 	mov r5,a 
                           000000  2971 	.else 
                                   2972 	mov r7,a 
                                   2973 	mov r4,b 
                                   2974 	.endif 
                                   2975 	.endif 
                                   2976 ;; clear precision extension 
      0007D2 E4               [12] 2977 	clr a 
      0007D3 FF               [12] 2978 	mov r7,a 
                                   2979 ;; stage 0 
                           000001  2980 	.if (((0x18cba80)>>24)&0xff) 
      0007D4 74 01            [12] 2981 	mov a,# (((0x18cba80)>>24)&0xff) 
      0007D6 88 F0            [24] 2982 	mov b,r0 
      0007D8 A4               [48] 2983 	mul ab 
      0007D9 2C               [12] 2984 	add a,r4 
      0007DA FC               [12] 2985 	mov r4,a 
      0007DB E5 F0            [12] 2986 	mov a,b 
      0007DD 3D               [12] 2987 	addc a,r5 
      0007DE FD               [12] 2988 	mov r5,a 
      0007DF E4               [12] 2989 	clr a 
      0007E0 3E               [12] 2990 	addc a,r6 
      0007E1 FE               [12] 2991 	mov r6,a 
                                   2992 	.endif 
                           000001  2993 	.if (((0x18cba80)>>16)&0xff) 
      0007E2 74 8C            [12] 2994 	mov a,# (((0x18cba80)>>16)&0xff) 
      0007E4 89 F0            [24] 2995 	mov b,r1 
      0007E6 A4               [48] 2996 	mul ab 
      0007E7 2C               [12] 2997 	add a,r4 
      0007E8 FC               [12] 2998 	mov r4,a 
      0007E9 E5 F0            [12] 2999 	mov a,b 
      0007EB 3D               [12] 3000 	addc a,r5 
      0007EC FD               [12] 3001 	mov r5,a 
      0007ED E4               [12] 3002 	clr a 
      0007EE 3E               [12] 3003 	addc a,r6 
      0007EF FE               [12] 3004 	mov r6,a 
                                   3005 	.endif 
                           000001  3006 	.if (((0x18cba80)>>8)&0xff) 
      0007F0 74 BA            [12] 3007 	mov a,# (((0x18cba80)>>8)&0xff) 
      0007F2 8A F0            [24] 3008 	mov b,r2 
      0007F4 A4               [48] 3009 	mul ab 
      0007F5 2C               [12] 3010 	add a,r4 
      0007F6 FC               [12] 3011 	mov r4,a 
      0007F7 E5 F0            [12] 3012 	mov a,b 
      0007F9 3D               [12] 3013 	addc a,r5 
      0007FA FD               [12] 3014 	mov r5,a 
      0007FB E4               [12] 3015 	clr a 
      0007FC 3E               [12] 3016 	addc a,r6 
      0007FD FE               [12] 3017 	mov r6,a 
                                   3018 	.endif 
                           000001  3019 	.if ((0x18cba80)&0xff) 
      0007FE 74 80            [12] 3020 	mov a,# ((0x18cba80)&0xff) 
      000800 8B F0            [24] 3021 	mov b,r3 
      000802 A4               [48] 3022 	mul ab 
      000803 2C               [12] 3023 	add a,r4 
      000804 FC               [12] 3024 	mov r4,a 
      000805 E5 F0            [12] 3025 	mov a,b 
      000807 3D               [12] 3026 	addc a,r5 
      000808 FD               [12] 3027 	mov r5,a 
      000809 E4               [12] 3028 	clr a 
      00080A 3E               [12] 3029 	addc a,r6 
      00080B FE               [12] 3030 	mov r6,a 
                                   3031 	.endif 
                                   3032 ;; stage 1 
                           000001  3033 	.if (((0x18cba80)>>24)&0xff) 
      00080C 74 01            [12] 3034 	mov a,# (((0x18cba80)>>24)&0xff) 
      00080E 89 F0            [24] 3035 	mov b,r1 
      000810 A4               [48] 3036 	mul ab 
      000811 2D               [12] 3037 	add a,r5 
      000812 FD               [12] 3038 	mov r5,a 
      000813 E5 F0            [12] 3039 	mov a,b 
      000815 3E               [12] 3040 	addc a,r6 
      000816 FE               [12] 3041 	mov r6,a 
      000817 E4               [12] 3042 	clr a 
      000818 3F               [12] 3043 	addc a,r7 
      000819 FF               [12] 3044 	mov r7,a 
                                   3045 	.endif 
                           000001  3046 	.if (((0x18cba80)>>16)&0xff) 
      00081A 74 8C            [12] 3047 	mov a,# (((0x18cba80)>>16)&0xff) 
      00081C 8A F0            [24] 3048 	mov b,r2 
      00081E A4               [48] 3049 	mul ab 
      00081F 2D               [12] 3050 	add a,r5 
      000820 FD               [12] 3051 	mov r5,a 
      000821 E5 F0            [12] 3052 	mov a,b 
      000823 3E               [12] 3053 	addc a,r6 
      000824 FE               [12] 3054 	mov r6,a 
      000825 E4               [12] 3055 	clr a 
      000826 3F               [12] 3056 	addc a,r7 
      000827 FF               [12] 3057 	mov r7,a 
                                   3058 	.endif 
                           000001  3059 	.if (((0x18cba80)>>8)&0xff) 
      000828 74 BA            [12] 3060 	mov a,# (((0x18cba80)>>8)&0xff) 
      00082A 8B F0            [24] 3061 	mov b,r3 
      00082C A4               [48] 3062 	mul ab 
      00082D 2D               [12] 3063 	add a,r5 
      00082E FD               [12] 3064 	mov r5,a 
      00082F E5 F0            [12] 3065 	mov a,b 
      000831 3E               [12] 3066 	addc a,r6 
      000832 FE               [12] 3067 	mov r6,a 
      000833 E4               [12] 3068 	clr a 
      000834 3F               [12] 3069 	addc a,r7 
      000835 FF               [12] 3070 	mov r7,a 
                                   3071 	.endif 
                                   3072 ;; stage 2 
                           000001  3073 	.if (((0x18cba80)>>24)&0xff) 
      000836 74 01            [12] 3074 	mov a,# (((0x18cba80)>>24)&0xff) 
      000838 8A F0            [24] 3075 	mov b,r2 
      00083A A4               [48] 3076 	mul ab 
      00083B 2E               [12] 3077 	add a,r6 
      00083C FE               [12] 3078 	mov r6,a 
      00083D E5 F0            [12] 3079 	mov a,b 
      00083F 3F               [12] 3080 	addc a,r7 
      000840 FF               [12] 3081 	mov r7,a 
                                   3082 	.endif 
                           000001  3083 	.if (((0x18cba80)>>16)&0xff) 
      000841 74 8C            [12] 3084 	mov a,# (((0x18cba80)>>16)&0xff) 
      000843 8B F0            [24] 3085 	mov b,r3 
      000845 A4               [48] 3086 	mul ab 
      000846 2E               [12] 3087 	add a,r6 
      000847 FE               [12] 3088 	mov r6,a 
      000848 E5 F0            [12] 3089 	mov a,b 
      00084A 3F               [12] 3090 	addc a,r7 
      00084B FF               [12] 3091 	mov r7,a 
                                   3092 	.endif 
                                   3093 ;; stage 3 
                           000001  3094 	.if (((0x18cba80)>>24)&0xff) 
      00084C 74 01            [12] 3095 	mov a,# (((0x18cba80)>>24)&0xff) 
      00084E 8B F0            [24] 3096 	mov b,r3 
      000850 A4               [48] 3097 	mul ab 
      000851 2F               [12] 3098 	add a,r7 
      000852 FF               [12] 3099 	mov r7,a 
                                   3100 	.endif 
      000853 D0 E0            [24] 3101 	pop acc 
      000855 30 E7 11         [24] 3102 	jnb acc.7,00001$ 
      000858 C3               [12] 3103 	clr c 
      000859 E4               [12] 3104 	clr a 
      00085A 9C               [12] 3105 	subb a,r4 
      00085B F5 82            [12] 3106 	mov dpl,a 
      00085D E4               [12] 3107 	clr a 
      00085E 9D               [12] 3108 	subb a,r5 
      00085F F5 83            [12] 3109 	mov dph,a 
      000861 E4               [12] 3110 	clr a 
      000862 9E               [12] 3111 	subb a,r6 
      000863 F5 F0            [12] 3112 	mov b,a 
      000865 E4               [12] 3113 	clr a 
      000866 9F               [12] 3114 	subb a,r7 
      000867 80 07            [24] 3115 	sjmp 00002$ 
      000869                       3116 	 00001$:
      000869 8C 82            [24] 3117 	mov dpl,r4 
      00086B 8D 83            [24] 3118 	mov dph,r5 
      00086D 8E F0            [24] 3119 	mov b,r6 
      00086F EF               [12] 3120 	mov a,r7 
      000870                       3121 	 00002$:
      000870 22               [24] 3122 	ret
                                   3123 ;------------------------------------------------------------
                                   3124 ;Allocation info for local variables in function 'axradio_conv_freq_fromreg'
                                   3125 ;------------------------------------------------------------
                                   3126 ;f                         Allocated to registers 
                                   3127 ;------------------------------------------------------------
                                   3128 ;	..\AX_Radio_Lab_output\config.c:640: int32_t axradio_conv_freq_fromreg(int32_t f)
                                   3129 ;	-----------------------------------------
                                   3130 ;	 function axradio_conv_freq_fromreg
                                   3131 ;	-----------------------------------------
      000871                       3132 _axradio_conv_freq_fromreg:
                                   3133 ;	..\AX_Radio_Lab_output\config.c:646: CONSTMULFIX16(0x1000000);
      000871 A8 82            [24] 3134 	mov r0,dpl 
      000873 E5 83            [12] 3135 	mov a,dph 
      000875 F9               [12] 3136 	mov r1,a 
      000876 C0 E0            [24] 3137 	push acc 
      000878 30 E7 07         [24] 3138 	jnb acc.7,00000$ 
      00087B C3               [12] 3139 	clr c 
      00087C E4               [12] 3140 	clr a 
      00087D 98               [12] 3141 	subb a,r0 
      00087E F8               [12] 3142 	mov r0,a 
      00087F E4               [12] 3143 	clr a 
      000880 99               [12] 3144 	subb a,r1 
      000881 F9               [12] 3145 	mov r1,a 
      000882                       3146 	 00000$:
      000882 E4               [12] 3147 	clr a 
      000883 FC               [12] 3148 	mov r4,a 
      000884 FD               [12] 3149 	mov r5,a 
      000885 FE               [12] 3150 	mov r6,a 
      000886 FF               [12] 3151 	mov r7,a 
                                   3152 ;; stage -1 
                           000000  3153 	.if (((0x1000000)>>16)&0xff) 
                                   3154 	mov a,# (((0x1000000)>>16)&0xff) 
                                   3155 	mov b,r0 
                                   3156 	mul ab 
                                   3157 	mov r7,a 
                                   3158 	mov r4,b 
                                   3159 	.endif 
                           000000  3160 	.if (((0x1000000)>>8)&0xff) 
                                   3161 	mov a,# (((0x1000000)>>8)&0xff) 
                                   3162 	mov b,r1 
                                   3163 	mul ab 
                                   3164 	.if (((0x1000000)>>16)&0xff) 
                                   3165 	add a,r7 
                                   3166 	mov r7,a 
                                   3167 	mov a,b 
                                   3168 	addc a,r4 
                                   3169 	mov r4,a 
                                   3170 	clr a 
                                   3171 	addc a,r5 
                                   3172 	mov r5,a 
                                   3173 	.else 
                                   3174 	mov r7,a 
                                   3175 	mov r4,b 
                                   3176 	.endif 
                                   3177 	.endif 
                                   3178 ;; clear precision extension 
      000887 E4               [12] 3179 	clr a 
      000888 FF               [12] 3180 	mov r7,a 
                                   3181 ;; stage 0 
                           000001  3182 	.if (((0x1000000)>>24)&0xff) 
      000889 74 01            [12] 3183 	mov a,# (((0x1000000)>>24)&0xff) 
      00088B 88 F0            [24] 3184 	mov b,r0 
      00088D A4               [48] 3185 	mul ab 
      00088E 2C               [12] 3186 	add a,r4 
      00088F FC               [12] 3187 	mov r4,a 
      000890 E5 F0            [12] 3188 	mov a,b 
      000892 3D               [12] 3189 	addc a,r5 
      000893 FD               [12] 3190 	mov r5,a 
      000894 E4               [12] 3191 	clr a 
      000895 3E               [12] 3192 	addc a,r6 
      000896 FE               [12] 3193 	mov r6,a 
                                   3194 	.endif 
                           000000  3195 	.if (((0x1000000)>>16)&0xff) 
                                   3196 	mov a,# (((0x1000000)>>16)&0xff) 
                                   3197 	mov b,r1 
                                   3198 	mul ab 
                                   3199 	add a,r4 
                                   3200 	mov r4,a 
                                   3201 	mov a,b 
                                   3202 	addc a,r5 
                                   3203 	mov r5,a 
                                   3204 	clr a 
                                   3205 	addc a,r6 
                                   3206 	mov r6,a 
                                   3207 	.endif 
                                   3208 ;; stage 1 
                           000001  3209 	.if (((0x1000000)>>24)&0xff) 
      000897 74 01            [12] 3210 	mov a,# (((0x1000000)>>24)&0xff) 
      000899 89 F0            [24] 3211 	mov b,r1 
      00089B A4               [48] 3212 	mul ab 
      00089C 2D               [12] 3213 	add a,r5 
      00089D FD               [12] 3214 	mov r5,a 
      00089E E5 F0            [12] 3215 	mov a,b 
      0008A0 3E               [12] 3216 	addc a,r6 
      0008A1 FE               [12] 3217 	mov r6,a 
      0008A2 E4               [12] 3218 	clr a 
      0008A3 3F               [12] 3219 	addc a,r7 
      0008A4 FF               [12] 3220 	mov r7,a 
                                   3221 	.endif 
      0008A5 D0 E0            [24] 3222 	pop acc 
      0008A7 30 E7 11         [24] 3223 	jnb acc.7,00001$ 
      0008AA C3               [12] 3224 	clr c 
      0008AB E4               [12] 3225 	clr a 
      0008AC 9C               [12] 3226 	subb a,r4 
      0008AD F5 82            [12] 3227 	mov dpl,a 
      0008AF E4               [12] 3228 	clr a 
      0008B0 9D               [12] 3229 	subb a,r5 
      0008B1 F5 83            [12] 3230 	mov dph,a 
      0008B3 E4               [12] 3231 	clr a 
      0008B4 9E               [12] 3232 	subb a,r6 
      0008B5 F5 F0            [12] 3233 	mov b,a 
      0008B7 E4               [12] 3234 	clr a 
      0008B8 9F               [12] 3235 	subb a,r7 
      0008B9 80 07            [24] 3236 	sjmp 00002$ 
      0008BB                       3237 	 00001$:
      0008BB 8C 82            [24] 3238 	mov dpl,r4 
      0008BD 8D 83            [24] 3239 	mov dph,r5 
      0008BF 8E F0            [24] 3240 	mov b,r6 
      0008C1 EF               [12] 3241 	mov a,r7 
      0008C2                       3242 	 00002$:
      0008C2 22               [24] 3243 	ret
                                   3244 ;------------------------------------------------------------
                                   3245 ;Allocation info for local variables in function 'axradio_conv_timeinterval_totimer0'
                                   3246 ;------------------------------------------------------------
                                   3247 ;dt                        Allocated to registers r4 r5 r6 r7 
                                   3248 ;r                         Allocated to registers r0 r1 r2 r3 
                                   3249 ;------------------------------------------------------------
                                   3250 ;	..\AX_Radio_Lab_output\config.c:652: int32_t axradio_conv_timeinterval_totimer0(int32_t dt)
                                   3251 ;	-----------------------------------------
                                   3252 ;	 function axradio_conv_timeinterval_totimer0
                                   3253 ;	-----------------------------------------
      0008C3                       3254 _axradio_conv_timeinterval_totimer0:
      0008C3 AC 82            [24] 3255 	mov	r4,dpl
      0008C5 AD 83            [24] 3256 	mov	r5,dph
      0008C7 AE F0            [24] 3257 	mov	r6,b
      0008C9 FF               [12] 3258 	mov	r7,a
                                   3259 ;	..\AX_Radio_Lab_output\config.c:659: dt >>= 6;
      0008CA ED               [12] 3260 	mov	a,r5
      0008CB A2 E7            [12] 3261 	mov	c,acc.7
      0008CD CC               [12] 3262 	xch	a,r4
      0008CE 33               [12] 3263 	rlc	a
      0008CF CC               [12] 3264 	xch	a,r4
      0008D0 33               [12] 3265 	rlc	a
      0008D1 A2 E7            [12] 3266 	mov	c,acc.7
      0008D3 CC               [12] 3267 	xch	a,r4
      0008D4 33               [12] 3268 	rlc	a
      0008D5 CC               [12] 3269 	xch	a,r4
      0008D6 33               [12] 3270 	rlc	a
      0008D7 CC               [12] 3271 	xch	a,r4
      0008D8 54 03            [12] 3272 	anl	a,#0x03
      0008DA FD               [12] 3273 	mov	r5,a
      0008DB EE               [12] 3274 	mov	a,r6
      0008DC 2E               [12] 3275 	add	a,r6
      0008DD 25 E0            [12] 3276 	add	a,acc
      0008DF 4D               [12] 3277 	orl	a,r5
      0008E0 FD               [12] 3278 	mov	r5,a
      0008E1 EF               [12] 3279 	mov	a,r7
      0008E2 A2 E7            [12] 3280 	mov	c,acc.7
      0008E4 CE               [12] 3281 	xch	a,r6
      0008E5 33               [12] 3282 	rlc	a
      0008E6 CE               [12] 3283 	xch	a,r6
      0008E7 33               [12] 3284 	rlc	a
      0008E8 A2 E7            [12] 3285 	mov	c,acc.7
      0008EA CE               [12] 3286 	xch	a,r6
      0008EB 33               [12] 3287 	rlc	a
      0008EC CE               [12] 3288 	xch	a,r6
      0008ED 33               [12] 3289 	rlc	a
      0008EE CE               [12] 3290 	xch	a,r6
      0008EF 54 03            [12] 3291 	anl	a,#0x03
      0008F1 30 E1 02         [24] 3292 	jnb	acc.1,00103$
      0008F4 44 FC            [12] 3293 	orl	a,#0xfc
      0008F6                       3294 00103$:
      0008F6 FF               [12] 3295 	mov	r7,a
                                   3296 ;	..\AX_Radio_Lab_output\config.c:660: r = dt;
      0008F7 8C 00            [24] 3297 	mov	ar0,r4
      0008F9 8D 01            [24] 3298 	mov	ar1,r5
      0008FB 8E 02            [24] 3299 	mov	ar2,r6
                                   3300 ;	..\AX_Radio_Lab_output\config.c:661: dt >>= 2;
      0008FD EF               [12] 3301 	mov	a,r7
      0008FE FB               [12] 3302 	mov	r3,a
      0008FF A2 E7            [12] 3303 	mov	c,acc.7
      000901 13               [12] 3304 	rrc	a
      000902 FF               [12] 3305 	mov	r7,a
      000903 EE               [12] 3306 	mov	a,r6
      000904 13               [12] 3307 	rrc	a
      000905 FE               [12] 3308 	mov	r6,a
      000906 ED               [12] 3309 	mov	a,r5
      000907 13               [12] 3310 	rrc	a
      000908 FD               [12] 3311 	mov	r5,a
      000909 EC               [12] 3312 	mov	a,r4
      00090A 13               [12] 3313 	rrc	a
      00090B FC               [12] 3314 	mov	r4,a
      00090C EF               [12] 3315 	mov	a,r7
      00090D A2 E7            [12] 3316 	mov	c,acc.7
      00090F 13               [12] 3317 	rrc	a
      000910 FF               [12] 3318 	mov	r7,a
      000911 EE               [12] 3319 	mov	a,r6
      000912 13               [12] 3320 	rrc	a
      000913 FE               [12] 3321 	mov	r6,a
      000914 ED               [12] 3322 	mov	a,r5
      000915 13               [12] 3323 	rrc	a
      000916 FD               [12] 3324 	mov	r5,a
      000917 EC               [12] 3325 	mov	a,r4
      000918 13               [12] 3326 	rrc	a
                                   3327 ;	..\AX_Radio_Lab_output\config.c:662: r += dt;
      000919 FC               [12] 3328 	mov	r4,a
      00091A 28               [12] 3329 	add	a,r0
      00091B F8               [12] 3330 	mov	r0,a
      00091C ED               [12] 3331 	mov	a,r5
      00091D 39               [12] 3332 	addc	a,r1
      00091E F9               [12] 3333 	mov	r1,a
      00091F EE               [12] 3334 	mov	a,r6
      000920 3A               [12] 3335 	addc	a,r2
      000921 FA               [12] 3336 	mov	r2,a
      000922 EF               [12] 3337 	mov	a,r7
      000923 3B               [12] 3338 	addc	a,r3
      000924 FB               [12] 3339 	mov	r3,a
                                   3340 ;	..\AX_Radio_Lab_output\config.c:663: dt >>= 3;
      000925 ED               [12] 3341 	mov	a,r5
      000926 C4               [12] 3342 	swap	a
      000927 23               [12] 3343 	rl	a
      000928 CC               [12] 3344 	xch	a,r4
      000929 C4               [12] 3345 	swap	a
      00092A 23               [12] 3346 	rl	a
      00092B 54 1F            [12] 3347 	anl	a,#0x1f
      00092D 6C               [12] 3348 	xrl	a,r4
      00092E CC               [12] 3349 	xch	a,r4
      00092F 54 1F            [12] 3350 	anl	a,#0x1f
      000931 CC               [12] 3351 	xch	a,r4
      000932 6C               [12] 3352 	xrl	a,r4
      000933 CC               [12] 3353 	xch	a,r4
      000934 FD               [12] 3354 	mov	r5,a
      000935 EE               [12] 3355 	mov	a,r6
      000936 C4               [12] 3356 	swap	a
      000937 23               [12] 3357 	rl	a
      000938 54 E0            [12] 3358 	anl	a,#0xe0
      00093A 4D               [12] 3359 	orl	a,r5
      00093B FD               [12] 3360 	mov	r5,a
      00093C EF               [12] 3361 	mov	a,r7
      00093D C4               [12] 3362 	swap	a
      00093E 23               [12] 3363 	rl	a
      00093F CE               [12] 3364 	xch	a,r6
      000940 C4               [12] 3365 	swap	a
      000941 23               [12] 3366 	rl	a
      000942 54 1F            [12] 3367 	anl	a,#0x1f
      000944 6E               [12] 3368 	xrl	a,r6
      000945 CE               [12] 3369 	xch	a,r6
      000946 54 1F            [12] 3370 	anl	a,#0x1f
      000948 CE               [12] 3371 	xch	a,r6
      000949 6E               [12] 3372 	xrl	a,r6
      00094A CE               [12] 3373 	xch	a,r6
      00094B 30 E4 02         [24] 3374 	jnb	acc.4,00104$
      00094E 44 E0            [12] 3375 	orl	a,#0xe0
      000950                       3376 00104$:
      000950 FF               [12] 3377 	mov	r7,a
                                   3378 ;	..\AX_Radio_Lab_output\config.c:664: r += dt;
      000951 EC               [12] 3379 	mov	a,r4
      000952 28               [12] 3380 	add	a,r0
      000953 F8               [12] 3381 	mov	r0,a
      000954 ED               [12] 3382 	mov	a,r5
      000955 39               [12] 3383 	addc	a,r1
      000956 F9               [12] 3384 	mov	r1,a
      000957 EE               [12] 3385 	mov	a,r6
      000958 3A               [12] 3386 	addc	a,r2
      000959 FA               [12] 3387 	mov	r2,a
      00095A EF               [12] 3388 	mov	a,r7
      00095B 3B               [12] 3389 	addc	a,r3
      00095C FB               [12] 3390 	mov	r3,a
                                   3391 ;	..\AX_Radio_Lab_output\config.c:665: dt >>= 2;
      00095D EF               [12] 3392 	mov	a,r7
      00095E A2 E7            [12] 3393 	mov	c,acc.7
      000960 13               [12] 3394 	rrc	a
      000961 FF               [12] 3395 	mov	r7,a
      000962 EE               [12] 3396 	mov	a,r6
      000963 13               [12] 3397 	rrc	a
      000964 FE               [12] 3398 	mov	r6,a
      000965 ED               [12] 3399 	mov	a,r5
      000966 13               [12] 3400 	rrc	a
      000967 FD               [12] 3401 	mov	r5,a
      000968 EC               [12] 3402 	mov	a,r4
      000969 13               [12] 3403 	rrc	a
      00096A FC               [12] 3404 	mov	r4,a
      00096B EF               [12] 3405 	mov	a,r7
      00096C A2 E7            [12] 3406 	mov	c,acc.7
      00096E 13               [12] 3407 	rrc	a
      00096F FF               [12] 3408 	mov	r7,a
      000970 EE               [12] 3409 	mov	a,r6
      000971 13               [12] 3410 	rrc	a
      000972 FE               [12] 3411 	mov	r6,a
      000973 ED               [12] 3412 	mov	a,r5
      000974 13               [12] 3413 	rrc	a
      000975 FD               [12] 3414 	mov	r5,a
      000976 EC               [12] 3415 	mov	a,r4
      000977 13               [12] 3416 	rrc	a
                                   3417 ;	..\AX_Radio_Lab_output\config.c:666: r += dt;
      000978 28               [12] 3418 	add	a,r0
      000979 F8               [12] 3419 	mov	r0,a
      00097A ED               [12] 3420 	mov	a,r5
      00097B 39               [12] 3421 	addc	a,r1
      00097C F9               [12] 3422 	mov	r1,a
      00097D EE               [12] 3423 	mov	a,r6
      00097E 3A               [12] 3424 	addc	a,r2
      00097F FA               [12] 3425 	mov	r2,a
      000980 EF               [12] 3426 	mov	a,r7
      000981 3B               [12] 3427 	addc	a,r3
                                   3428 ;	..\AX_Radio_Lab_output\config.c:667: return r;
      000982 88 82            [24] 3429 	mov	dpl,r0
      000984 89 83            [24] 3430 	mov	dph,r1
      000986 8A F0            [24] 3431 	mov	b,r2
      000988 22               [24] 3432 	ret
                                   3433 ;------------------------------------------------------------
                                   3434 ;Allocation info for local variables in function 'axradio_byteconv'
                                   3435 ;------------------------------------------------------------
                                   3436 ;b                         Allocated to registers r7 
                                   3437 ;------------------------------------------------------------
                                   3438 ;	..\AX_Radio_Lab_output\config.c:670: __reentrantb uint8_t axradio_byteconv(uint8_t b) __reentrant
                                   3439 ;	-----------------------------------------
                                   3440 ;	 function axradio_byteconv
                                   3441 ;	-----------------------------------------
      000989                       3442 _axradio_byteconv:
                                   3443 ;	..\AX_Radio_Lab_output\config.c:672: return rev8(b);
      000989 02 47 E3         [24] 3444 	ljmp	_rev8
                                   3445 ;------------------------------------------------------------
                                   3446 ;Allocation info for local variables in function 'axradio_byteconv_buffer'
                                   3447 ;------------------------------------------------------------
                                   3448 ;buflen                    Allocated to stack - _bp -4
                                   3449 ;buf                       Allocated to registers 
                                   3450 ;------------------------------------------------------------
                                   3451 ;	..\AX_Radio_Lab_output\config.c:676: __reentrantb void axradio_byteconv_buffer(uint8_t __xdata *buf, uint16_t buflen) __reentrant
                                   3452 ;	-----------------------------------------
                                   3453 ;	 function axradio_byteconv_buffer
                                   3454 ;	-----------------------------------------
      00098C                       3455 _axradio_byteconv_buffer:
      00098C C0 1E            [24] 3456 	push	_bp
      00098E 85 81 1E         [24] 3457 	mov	_bp,sp
      000991 AE 82            [24] 3458 	mov	r6,dpl
      000993 AF 83            [24] 3459 	mov	r7,dph
                                   3460 ;	..\AX_Radio_Lab_output\config.c:678: while (buflen) {
      000995 E5 1E            [12] 3461 	mov	a,_bp
      000997 24 FC            [12] 3462 	add	a,#0xfc
      000999 F8               [12] 3463 	mov	r0,a
      00099A 86 04            [24] 3464 	mov	ar4,@r0
      00099C 08               [12] 3465 	inc	r0
      00099D 86 05            [24] 3466 	mov	ar5,@r0
      00099F                       3467 00101$:
      00099F EC               [12] 3468 	mov	a,r4
      0009A0 4D               [12] 3469 	orl	a,r5
      0009A1 60 2E            [24] 3470 	jz	00104$
                                   3471 ;	..\AX_Radio_Lab_output\config.c:679: *buf = rev8(*buf);
      0009A3 8E 82            [24] 3472 	mov	dpl,r6
      0009A5 8F 83            [24] 3473 	mov	dph,r7
      0009A7 E0               [24] 3474 	movx	a,@dptr
      0009A8 F5 82            [12] 3475 	mov	dpl,a
      0009AA C0 07            [24] 3476 	push	ar7
      0009AC C0 06            [24] 3477 	push	ar6
      0009AE C0 05            [24] 3478 	push	ar5
      0009B0 C0 04            [24] 3479 	push	ar4
      0009B2 12 47 E3         [24] 3480 	lcall	_rev8
      0009B5 AB 82            [24] 3481 	mov	r3,dpl
      0009B7 D0 04            [24] 3482 	pop	ar4
      0009B9 D0 05            [24] 3483 	pop	ar5
      0009BB D0 06            [24] 3484 	pop	ar6
      0009BD D0 07            [24] 3485 	pop	ar7
      0009BF 8E 82            [24] 3486 	mov	dpl,r6
      0009C1 8F 83            [24] 3487 	mov	dph,r7
      0009C3 EB               [12] 3488 	mov	a,r3
      0009C4 F0               [24] 3489 	movx	@dptr,a
      0009C5 A3               [24] 3490 	inc	dptr
      0009C6 AE 82            [24] 3491 	mov	r6,dpl
      0009C8 AF 83            [24] 3492 	mov	r7,dph
                                   3493 ;	..\AX_Radio_Lab_output\config.c:680: ++buf;
                                   3494 ;	..\AX_Radio_Lab_output\config.c:681: --buflen;
      0009CA 1C               [12] 3495 	dec	r4
      0009CB BC FF 01         [24] 3496 	cjne	r4,#0xff,00114$
      0009CE 1D               [12] 3497 	dec	r5
      0009CF                       3498 00114$:
      0009CF 80 CE            [24] 3499 	sjmp	00101$
      0009D1                       3500 00104$:
      0009D1 D0 1E            [24] 3501 	pop	_bp
      0009D3 22               [24] 3502 	ret
                                   3503 ;------------------------------------------------------------
                                   3504 ;Allocation info for local variables in function 'axradio_framing_check_crc'
                                   3505 ;------------------------------------------------------------
                                   3506 ;cnt                       Allocated to stack - _bp -4
                                   3507 ;pkt                       Allocated to registers r6 r7 
                                   3508 ;------------------------------------------------------------
                                   3509 ;	..\AX_Radio_Lab_output\config.c:685: __reentrantb uint16_t axradio_framing_check_crc(uint8_t __xdata *pkt, uint16_t cnt) __reentrant
                                   3510 ;	-----------------------------------------
                                   3511 ;	 function axradio_framing_check_crc
                                   3512 ;	-----------------------------------------
      0009D4                       3513 _axradio_framing_check_crc:
      0009D4 C0 1E            [24] 3514 	push	_bp
      0009D6 85 81 1E         [24] 3515 	mov	_bp,sp
      0009D9 AE 82            [24] 3516 	mov	r6,dpl
      0009DB AF 83            [24] 3517 	mov	r7,dph
                                   3518 ;	..\AX_Radio_Lab_output\config.c:687: if (crc_crc16_msb(pkt, cnt, 0xFFFF) != 0x0000)
      0009DD 7D 00            [12] 3519 	mov	r5,#0x00
      0009DF 74 FF            [12] 3520 	mov	a,#0xff
      0009E1 C0 E0            [24] 3521 	push	acc
      0009E3 C0 E0            [24] 3522 	push	acc
      0009E5 E5 1E            [12] 3523 	mov	a,_bp
      0009E7 24 FC            [12] 3524 	add	a,#0xfc
      0009E9 F8               [12] 3525 	mov	r0,a
      0009EA E6               [12] 3526 	mov	a,@r0
      0009EB C0 E0            [24] 3527 	push	acc
      0009ED 08               [12] 3528 	inc	r0
      0009EE E6               [12] 3529 	mov	a,@r0
      0009EF C0 E0            [24] 3530 	push	acc
      0009F1 8E 82            [24] 3531 	mov	dpl,r6
      0009F3 8F 83            [24] 3532 	mov	dph,r7
      0009F5 8D F0            [24] 3533 	mov	b,r5
      0009F7 12 4A 06         [24] 3534 	lcall	_crc_crc16_msb
      0009FA AE 82            [24] 3535 	mov	r6,dpl
      0009FC AF 83            [24] 3536 	mov	r7,dph
      0009FE E5 81            [12] 3537 	mov	a,sp
      000A00 24 FC            [12] 3538 	add	a,#0xfc
      000A02 F5 81            [12] 3539 	mov	sp,a
      000A04 EE               [12] 3540 	mov	a,r6
      000A05 4F               [12] 3541 	orl	a,r7
      000A06 60 05            [24] 3542 	jz	00102$
                                   3543 ;	..\AX_Radio_Lab_output\config.c:688: return 0;
      000A08 90 00 00         [24] 3544 	mov	dptr,#0x0000
      000A0B 80 0A            [24] 3545 	sjmp	00103$
      000A0D                       3546 00102$:
                                   3547 ;	..\AX_Radio_Lab_output\config.c:689: return cnt;
      000A0D E5 1E            [12] 3548 	mov	a,_bp
      000A0F 24 FC            [12] 3549 	add	a,#0xfc
      000A11 F8               [12] 3550 	mov	r0,a
      000A12 86 82            [24] 3551 	mov	dpl,@r0
      000A14 08               [12] 3552 	inc	r0
      000A15 86 83            [24] 3553 	mov	dph,@r0
      000A17                       3554 00103$:
      000A17 D0 1E            [24] 3555 	pop	_bp
      000A19 22               [24] 3556 	ret
                                   3557 ;------------------------------------------------------------
                                   3558 ;Allocation info for local variables in function 'axradio_framing_append_crc'
                                   3559 ;------------------------------------------------------------
                                   3560 ;cnt                       Allocated to stack - _bp -4
                                   3561 ;pkt                       Allocated to registers r6 r7 
                                   3562 ;s                         Allocated to registers r4 r5 
                                   3563 ;------------------------------------------------------------
                                   3564 ;	..\AX_Radio_Lab_output\config.c:692: __reentrantb uint16_t axradio_framing_append_crc(uint8_t __xdata *pkt, uint16_t cnt) __reentrant
                                   3565 ;	-----------------------------------------
                                   3566 ;	 function axradio_framing_append_crc
                                   3567 ;	-----------------------------------------
      000A1A                       3568 _axradio_framing_append_crc:
      000A1A C0 1E            [24] 3569 	push	_bp
      000A1C 85 81 1E         [24] 3570 	mov	_bp,sp
      000A1F AE 82            [24] 3571 	mov	r6,dpl
      000A21 AF 83            [24] 3572 	mov	r7,dph
                                   3573 ;	..\AX_Radio_Lab_output\config.c:695: s = crc_crc16_msb(pkt, cnt, s);
      000A23 8E 03            [24] 3574 	mov	ar3,r6
      000A25 8F 04            [24] 3575 	mov	ar4,r7
      000A27 7D 00            [12] 3576 	mov	r5,#0x00
      000A29 C0 07            [24] 3577 	push	ar7
      000A2B C0 06            [24] 3578 	push	ar6
      000A2D 74 FF            [12] 3579 	mov	a,#0xff
      000A2F C0 E0            [24] 3580 	push	acc
      000A31 C0 E0            [24] 3581 	push	acc
      000A33 E5 1E            [12] 3582 	mov	a,_bp
      000A35 24 FC            [12] 3583 	add	a,#0xfc
      000A37 F8               [12] 3584 	mov	r0,a
      000A38 E6               [12] 3585 	mov	a,@r0
      000A39 C0 E0            [24] 3586 	push	acc
      000A3B 08               [12] 3587 	inc	r0
      000A3C E6               [12] 3588 	mov	a,@r0
      000A3D C0 E0            [24] 3589 	push	acc
      000A3F 8B 82            [24] 3590 	mov	dpl,r3
      000A41 8C 83            [24] 3591 	mov	dph,r4
      000A43 8D F0            [24] 3592 	mov	b,r5
      000A45 12 4A 06         [24] 3593 	lcall	_crc_crc16_msb
      000A48 AC 82            [24] 3594 	mov	r4,dpl
      000A4A AD 83            [24] 3595 	mov	r5,dph
      000A4C E5 81            [12] 3596 	mov	a,sp
      000A4E 24 FC            [12] 3597 	add	a,#0xfc
      000A50 F5 81            [12] 3598 	mov	sp,a
      000A52 D0 06            [24] 3599 	pop	ar6
      000A54 D0 07            [24] 3600 	pop	ar7
                                   3601 ;	..\AX_Radio_Lab_output\config.c:696: pkt += cnt;
      000A56 E5 1E            [12] 3602 	mov	a,_bp
      000A58 24 FC            [12] 3603 	add	a,#0xfc
      000A5A F8               [12] 3604 	mov	r0,a
      000A5B E6               [12] 3605 	mov	a,@r0
      000A5C 2E               [12] 3606 	add	a,r6
      000A5D FE               [12] 3607 	mov	r6,a
      000A5E 08               [12] 3608 	inc	r0
      000A5F E6               [12] 3609 	mov	a,@r0
      000A60 3F               [12] 3610 	addc	a,r7
      000A61 FF               [12] 3611 	mov	r7,a
                                   3612 ;	..\AX_Radio_Lab_output\config.c:697: *pkt++ = (uint8_t)(s >> 8);
      000A62 8D 03            [24] 3613 	mov	ar3,r5
      000A64 8E 82            [24] 3614 	mov	dpl,r6
      000A66 8F 83            [24] 3615 	mov	dph,r7
      000A68 EB               [12] 3616 	mov	a,r3
      000A69 F0               [24] 3617 	movx	@dptr,a
      000A6A A3               [24] 3618 	inc	dptr
                                   3619 ;	..\AX_Radio_Lab_output\config.c:698: *pkt++ = (uint8_t)(s);
      000A6B EC               [12] 3620 	mov	a,r4
      000A6C F0               [24] 3621 	movx	@dptr,a
                                   3622 ;	..\AX_Radio_Lab_output\config.c:699: return cnt + 2;
      000A6D E5 1E            [12] 3623 	mov	a,_bp
      000A6F 24 FC            [12] 3624 	add	a,#0xfc
      000A71 F8               [12] 3625 	mov	r0,a
      000A72 86 82            [24] 3626 	mov	dpl,@r0
      000A74 08               [12] 3627 	inc	r0
      000A75 86 83            [24] 3628 	mov	dph,@r0
      000A77 A3               [24] 3629 	inc	dptr
      000A78 A3               [24] 3630 	inc	dptr
      000A79 D0 1E            [24] 3631 	pop	_bp
      000A7B 22               [24] 3632 	ret
                                   3633 	.area CSEG    (CODE)
                                   3634 	.area CONST   (CODE)
      004C6F                       3635 _axradio_phy_innerfreqloop:
      004C6F 00                    3636 	.db #0x00	; 0
      004C70                       3637 _axradio_phy_pn9:
      004C70 00                    3638 	.db #0x00	; 0
      004C71                       3639 _axradio_phy_nrchannels:
      004C71 06                    3640 	.db #0x06	; 6
      004C72                       3641 _axradio_phy_chanfreq:
      004C72 57 6A 65 21           3642 	.byte #0x57,#0x6a,#0x65,#0x21	; 560294487
      004C76 5B A9 65 21           3643 	.byte #0x5b,#0xa9,#0x65,#0x21	; 560310619
      004C7A 5F E8 65 21           3644 	.byte #0x5f,#0xe8,#0x65,#0x21	; 560326751
      004C7E 63 27 66 21           3645 	.byte #0x63,#0x27,#0x66,#0x21	; 560342883
      004C82 67 66 66 21           3646 	.byte #0x67,#0x66,#0x66,#0x21	; 560359015
      004C86 6B A5 66 21           3647 	.byte #0x6b,#0xa5,#0x66,#0x21	; 560375147
      004C8A                       3648 _axradio_phy_chanpllrnginit:
      004C8A 0A 00                 3649 	.byte #0x0a,#0x00	; 10
      004C8C 0A 00                 3650 	.byte #0x0a,#0x00	; 10
      004C8E 0A 00                 3651 	.byte #0x0a,#0x00	; 10
      004C90 0A 00                 3652 	.byte #0x0a,#0x00	; 10
      004C92 0A 00                 3653 	.byte #0x0a,#0x00	; 10
      004C94 0A 00                 3654 	.byte #0x0a,#0x00	; 10
      004C96                       3655 _axradio_phy_chanvcoiinit:
      004C96 99                    3656 	.db #0x99	; 153
      004C97 99                    3657 	.db #0x99	; 153
      004C98 99                    3658 	.db #0x99	; 153
      004C99 99                    3659 	.db #0x99	; 153
      004C9A 99                    3660 	.db #0x99	; 153
      004C9B 99                    3661 	.db #0x99	; 153
      004C9C                       3662 _axradio_phy_vcocalib:
      004C9C 01                    3663 	.db #0x01	; 1
      004C9D                       3664 _axradio_phy_maxfreqoffset:
      004C9D 22 0D 00 00           3665 	.byte #0x22,#0x0d,#0x00,#0x00	;  3362
      004CA1                       3666 _axradio_phy_rssioffset:
      004CA1 40                    3667 	.db #0x40	;  64
      004CA2                       3668 _axradio_phy_rssireference:
      004CA2 3A                    3669 	.db #0x3a	;  58
      004CA3                       3670 _axradio_phy_channelbusy:
      004CA3 E0                    3671 	.db #0xe0	; -32
      004CA4                       3672 _axradio_phy_cs_period:
      004CA4 48 01                 3673 	.byte #0x48,#0x01	; 328
      004CA6                       3674 _axradio_phy_cs_enabled:
      004CA6 00                    3675 	.db #0x00	; 0
      004CA7                       3676 _axradio_phy_lbt_retries:
      004CA7 03                    3677 	.db #0x03	; 3
      004CA8                       3678 _axradio_phy_lbt_forcetx:
      004CA8 00                    3679 	.db #0x00	; 0
      004CA9                       3680 _axradio_phy_preamble_wor_longlen:
      004CA9 04 00                 3681 	.byte #0x04,#0x00	; 4
      004CAB                       3682 _axradio_phy_preamble_wor_len:
      004CAB A0 00                 3683 	.byte #0xa0,#0x00	; 160
      004CAD                       3684 _axradio_phy_preamble_longlen:
      004CAD 00 00                 3685 	.byte #0x00,#0x00	; 0
      004CAF                       3686 _axradio_phy_preamble_len:
      004CAF 20 00                 3687 	.byte #0x20,#0x00	; 32
      004CB1                       3688 _axradio_phy_preamble_byte:
      004CB1 AA                    3689 	.db #0xaa	; 170
      004CB2                       3690 _axradio_phy_preamble_flags:
      004CB2 38                    3691 	.db #0x38	; 56	'8'
      004CB3                       3692 _axradio_phy_preamble_appendbits:
      004CB3 00                    3693 	.db #0x00	; 0
      004CB4                       3694 _axradio_phy_preamble_appendpattern:
      004CB4 00                    3695 	.db #0x00	; 0
      004CB5                       3696 _axradio_framing_maclen:
      004CB5 05                    3697 	.db #0x05	; 5
      004CB6                       3698 _axradio_framing_addrlen:
      004CB6 04                    3699 	.db #0x04	; 4
      004CB7                       3700 _axradio_framing_destaddrpos:
      004CB7 01                    3701 	.db #0x01	; 1
      004CB8                       3702 _axradio_framing_sourceaddrpos:
      004CB8 FF                    3703 	.db #0xff	; 255
      004CB9                       3704 _axradio_framing_lenpos:
      004CB9 00                    3705 	.db #0x00	; 0
      004CBA                       3706 _axradio_framing_lenoffs:
      004CBA 01                    3707 	.db #0x01	; 1
      004CBB                       3708 _axradio_framing_lenmask:
      004CBB FF                    3709 	.db #0xff	; 255
      004CBC                       3710 _axradio_framing_swcrclen:
      004CBC 02                    3711 	.db #0x02	; 2
      004CBD                       3712 _axradio_framing_synclen:
      004CBD 20                    3713 	.db #0x20	; 32
      004CBE                       3714 _axradio_framing_syncword:
      004CBE 93                    3715 	.db #0x93	; 147
      004CBF 0B                    3716 	.db #0x0b	; 11
      004CC0 51                    3717 	.db #0x51	; 81	'Q'
      004CC1 DE                    3718 	.db #0xde	; 222
      004CC2                       3719 _axradio_framing_syncflags:
      004CC2 38                    3720 	.db #0x38	; 56	'8'
      004CC3                       3721 _axradio_framing_enable_sfdcallback:
      004CC3 00                    3722 	.db #0x00	; 0
      004CC4                       3723 _axradio_framing_ack_timeout:
      004CC4 35 05 00 00           3724 	.byte #0x35,#0x05,#0x00,#0x00	; 1333
      004CC8                       3725 _axradio_framing_ack_delay:
      004CC8 39 01 00 00           3726 	.byte #0x39,#0x01,#0x00,#0x00	; 313
      004CCC                       3727 _axradio_framing_ack_retransmissions:
      004CCC 03                    3728 	.db #0x03	; 3
      004CCD                       3729 _axradio_framing_ack_seqnrpos:
      004CCD FF                    3730 	.db #0xff	; 255
      004CCE                       3731 _axradio_framing_minpayloadlen:
      004CCE 01                    3732 	.db #0x01	; 1
      004CCF                       3733 _axradio_wor_period:
      004CCF 80 00                 3734 	.byte #0x80,#0x00	; 128
      004CD1                       3735 _axradio_sync_period:
      004CD1 00 80 00 00           3736 	.byte #0x00,#0x80,#0x00,#0x00	; 32768
      004CD5                       3737 _axradio_sync_xoscstartup:
      004CD5 31 00 00 00           3738 	.byte #0x31,#0x00,#0x00,#0x00	; 49
      004CD9                       3739 _axradio_sync_slave_syncwindow:
      004CD9 00 80 01 00           3740 	.byte #0x00,#0x80,#0x01,#0x00	; 98304
      004CDD                       3741 _axradio_sync_slave_initialsyncwindow:
      004CDD 00 00 5A 00           3742 	.byte #0x00,#0x00,#0x5a,#0x00	; 5898240
      004CE1                       3743 _axradio_sync_slave_syncpause:
      004CE1 00 00 2C 01           3744 	.byte #0x00,#0x00,#0x2c,#0x01	; 19660800
      004CE5                       3745 _axradio_sync_slave_maxperiod:
      004CE5 E4 07                 3746 	.byte #0xe4,#0x07	;  2020
      004CE7                       3747 _axradio_sync_slave_resyncloss:
      004CE7 0B                    3748 	.db #0x0b	; 11
      004CE8                       3749 _axradio_sync_slave_nrrx:
      004CE8 03                    3750 	.db #0x03	; 3
      004CE9                       3751 _axradio_sync_slave_rxadvance:
      004CE9 AE 02 00 00           3752 	.byte #0xae,#0x02,#0x00,#0x00	; 686
      004CED 89 02 00 00           3753 	.byte #0x89,#0x02,#0x00,#0x00	; 649
      004CF1 D7 02 00 00           3754 	.byte #0xd7,#0x02,#0x00,#0x00	; 727
      004CF5                       3755 _axradio_sync_slave_rxwindow:
      004CF5 BC 02 00 00           3756 	.byte #0xbc,#0x02,#0x00,#0x00	; 700
      004CF9 72 02 00 00           3757 	.byte #0x72,#0x02,#0x00,#0x00	; 626
      004CFD 0E 03 00 00           3758 	.byte #0x0e,#0x03,#0x00,#0x00	; 782
      004D01                       3759 _axradio_sync_slave_rxtimeout:
      004D01 89 04 00 00           3760 	.byte #0x89,#0x04,#0x00,#0x00	; 1161
      004D05                       3761 _axradio_lposckfiltmax:
      004D05 2A 14                 3762 	.byte #0x2a,#0x14	; 5162
      004D07                       3763 _axradio_fxtal:
      004D07 80 BA 8C 01           3764 	.byte #0x80,#0xba,#0x8c,#0x01	; 26000000
                                   3765 	.area XINIT   (CODE)
                                   3766 	.area CABS    (ABS,CODE)
