                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module easyax5043
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _axradio_wait_n_lposccycles
                                     12 	.globl _ax5043_init_registers_rx
                                     13 	.globl _ax5043_init_registers_tx
                                     14 	.globl _memset
                                     15 	.globl _memcpy
                                     16 	.globl _wtimer_remove_callback
                                     17 	.globl _wtimer_add_callback
                                     18 	.globl _wtimer_remove
                                     19 	.globl _wtimer1_addrelative
                                     20 	.globl _wtimer0_addrelative
                                     21 	.globl _wtimer0_addabsolute
                                     22 	.globl _wtimer0_curtime
                                     23 	.globl _wtimer_runcallbacks
                                     24 	.globl _wtimer_idle
                                     25 	.globl _ax5043_writefifo
                                     26 	.globl _ax5043_readfifo
                                     27 	.globl _ax5043_wakeup_deepsleep
                                     28 	.globl _ax5043_enter_deepsleep
                                     29 	.globl _ax5043_reset
                                     30 	.globl _ax5043_commsleepexit
                                     31 	.globl _radio_read24
                                     32 	.globl _radio_read16
                                     33 	.globl _pn9_buffer
                                     34 	.globl _pn9_advance_byte
                                     35 	.globl _pn9_advance_bits
                                     36 	.globl _disable_radio_interrupt_in_mcu_pin
                                     37 	.globl _enable_radio_interrupt_in_mcu_pin
                                     38 	.globl _axradio_framing_append_crc
                                     39 	.globl _axradio_framing_check_crc
                                     40 	.globl _ax5043_set_registers_rxcont_singleparamset
                                     41 	.globl _ax5043_set_registers_rxcont
                                     42 	.globl _ax5043_set_registers_rxwor
                                     43 	.globl _ax5043_set_registers_rx
                                     44 	.globl _ax5043_set_registers_tx
                                     45 	.globl _ax5043_set_registers
                                     46 	.globl _axradio_conv_freq_fromreg
                                     47 	.globl _axradio_statuschange
                                     48 	.globl _axradio_conv_timeinterval_totimer0
                                     49 	.globl _enter_standby
                                     50 	.globl _checksignedlimit32
                                     51 	.globl _checksignedlimit16
                                     52 	.globl _signedlimit16
                                     53 	.globl _signextend24
                                     54 	.globl _signextend20
                                     55 	.globl _signextend16
                                     56 	.globl _PORTC_7
                                     57 	.globl _PORTC_6
                                     58 	.globl _PORTC_5
                                     59 	.globl _PORTC_4
                                     60 	.globl _PORTC_3
                                     61 	.globl _PORTC_2
                                     62 	.globl _PORTC_1
                                     63 	.globl _PORTC_0
                                     64 	.globl _PORTB_7
                                     65 	.globl _PORTB_6
                                     66 	.globl _PORTB_5
                                     67 	.globl _PORTB_4
                                     68 	.globl _PORTB_3
                                     69 	.globl _PORTB_2
                                     70 	.globl _PORTB_1
                                     71 	.globl _PORTB_0
                                     72 	.globl _PORTA_7
                                     73 	.globl _PORTA_6
                                     74 	.globl _PORTA_5
                                     75 	.globl _PORTA_4
                                     76 	.globl _PORTA_3
                                     77 	.globl _PORTA_2
                                     78 	.globl _PORTA_1
                                     79 	.globl _PORTA_0
                                     80 	.globl _PINC_7
                                     81 	.globl _PINC_6
                                     82 	.globl _PINC_5
                                     83 	.globl _PINC_4
                                     84 	.globl _PINC_3
                                     85 	.globl _PINC_2
                                     86 	.globl _PINC_1
                                     87 	.globl _PINC_0
                                     88 	.globl _PINB_7
                                     89 	.globl _PINB_6
                                     90 	.globl _PINB_5
                                     91 	.globl _PINB_4
                                     92 	.globl _PINB_3
                                     93 	.globl _PINB_2
                                     94 	.globl _PINB_1
                                     95 	.globl _PINB_0
                                     96 	.globl _PINA_7
                                     97 	.globl _PINA_6
                                     98 	.globl _PINA_5
                                     99 	.globl _PINA_4
                                    100 	.globl _PINA_3
                                    101 	.globl _PINA_2
                                    102 	.globl _PINA_1
                                    103 	.globl _PINA_0
                                    104 	.globl _CY
                                    105 	.globl _AC
                                    106 	.globl _F0
                                    107 	.globl _RS1
                                    108 	.globl _RS0
                                    109 	.globl _OV
                                    110 	.globl _F1
                                    111 	.globl _P
                                    112 	.globl _IP_7
                                    113 	.globl _IP_6
                                    114 	.globl _IP_5
                                    115 	.globl _IP_4
                                    116 	.globl _IP_3
                                    117 	.globl _IP_2
                                    118 	.globl _IP_1
                                    119 	.globl _IP_0
                                    120 	.globl _EA
                                    121 	.globl _IE_7
                                    122 	.globl _IE_6
                                    123 	.globl _IE_5
                                    124 	.globl _IE_4
                                    125 	.globl _IE_3
                                    126 	.globl _IE_2
                                    127 	.globl _IE_1
                                    128 	.globl _IE_0
                                    129 	.globl _EIP_7
                                    130 	.globl _EIP_6
                                    131 	.globl _EIP_5
                                    132 	.globl _EIP_4
                                    133 	.globl _EIP_3
                                    134 	.globl _EIP_2
                                    135 	.globl _EIP_1
                                    136 	.globl _EIP_0
                                    137 	.globl _EIE_7
                                    138 	.globl _EIE_6
                                    139 	.globl _EIE_5
                                    140 	.globl _EIE_4
                                    141 	.globl _EIE_3
                                    142 	.globl _EIE_2
                                    143 	.globl _EIE_1
                                    144 	.globl _EIE_0
                                    145 	.globl _E2IP_7
                                    146 	.globl _E2IP_6
                                    147 	.globl _E2IP_5
                                    148 	.globl _E2IP_4
                                    149 	.globl _E2IP_3
                                    150 	.globl _E2IP_2
                                    151 	.globl _E2IP_1
                                    152 	.globl _E2IP_0
                                    153 	.globl _E2IE_7
                                    154 	.globl _E2IE_6
                                    155 	.globl _E2IE_5
                                    156 	.globl _E2IE_4
                                    157 	.globl _E2IE_3
                                    158 	.globl _E2IE_2
                                    159 	.globl _E2IE_1
                                    160 	.globl _E2IE_0
                                    161 	.globl _B_7
                                    162 	.globl _B_6
                                    163 	.globl _B_5
                                    164 	.globl _B_4
                                    165 	.globl _B_3
                                    166 	.globl _B_2
                                    167 	.globl _B_1
                                    168 	.globl _B_0
                                    169 	.globl _ACC_7
                                    170 	.globl _ACC_6
                                    171 	.globl _ACC_5
                                    172 	.globl _ACC_4
                                    173 	.globl _ACC_3
                                    174 	.globl _ACC_2
                                    175 	.globl _ACC_1
                                    176 	.globl _ACC_0
                                    177 	.globl _WTSTAT
                                    178 	.globl _WTIRQEN
                                    179 	.globl _WTEVTD
                                    180 	.globl _WTEVTD1
                                    181 	.globl _WTEVTD0
                                    182 	.globl _WTEVTC
                                    183 	.globl _WTEVTC1
                                    184 	.globl _WTEVTC0
                                    185 	.globl _WTEVTB
                                    186 	.globl _WTEVTB1
                                    187 	.globl _WTEVTB0
                                    188 	.globl _WTEVTA
                                    189 	.globl _WTEVTA1
                                    190 	.globl _WTEVTA0
                                    191 	.globl _WTCNTR1
                                    192 	.globl _WTCNTB
                                    193 	.globl _WTCNTB1
                                    194 	.globl _WTCNTB0
                                    195 	.globl _WTCNTA
                                    196 	.globl _WTCNTA1
                                    197 	.globl _WTCNTA0
                                    198 	.globl _WTCFGB
                                    199 	.globl _WTCFGA
                                    200 	.globl _WDTRESET
                                    201 	.globl _WDTCFG
                                    202 	.globl _U1STATUS
                                    203 	.globl _U1SHREG
                                    204 	.globl _U1MODE
                                    205 	.globl _U1CTRL
                                    206 	.globl _U0STATUS
                                    207 	.globl _U0SHREG
                                    208 	.globl _U0MODE
                                    209 	.globl _U0CTRL
                                    210 	.globl _T2STATUS
                                    211 	.globl _T2PERIOD
                                    212 	.globl _T2PERIOD1
                                    213 	.globl _T2PERIOD0
                                    214 	.globl _T2MODE
                                    215 	.globl _T2CNT
                                    216 	.globl _T2CNT1
                                    217 	.globl _T2CNT0
                                    218 	.globl _T2CLKSRC
                                    219 	.globl _T1STATUS
                                    220 	.globl _T1PERIOD
                                    221 	.globl _T1PERIOD1
                                    222 	.globl _T1PERIOD0
                                    223 	.globl _T1MODE
                                    224 	.globl _T1CNT
                                    225 	.globl _T1CNT1
                                    226 	.globl _T1CNT0
                                    227 	.globl _T1CLKSRC
                                    228 	.globl _T0STATUS
                                    229 	.globl _T0PERIOD
                                    230 	.globl _T0PERIOD1
                                    231 	.globl _T0PERIOD0
                                    232 	.globl _T0MODE
                                    233 	.globl _T0CNT
                                    234 	.globl _T0CNT1
                                    235 	.globl _T0CNT0
                                    236 	.globl _T0CLKSRC
                                    237 	.globl _SPSTATUS
                                    238 	.globl _SPSHREG
                                    239 	.globl _SPMODE
                                    240 	.globl _SPCLKSRC
                                    241 	.globl _RADIOSTAT
                                    242 	.globl _RADIOSTAT1
                                    243 	.globl _RADIOSTAT0
                                    244 	.globl _RADIODATA
                                    245 	.globl _RADIODATA3
                                    246 	.globl _RADIODATA2
                                    247 	.globl _RADIODATA1
                                    248 	.globl _RADIODATA0
                                    249 	.globl _RADIOADDR
                                    250 	.globl _RADIOADDR1
                                    251 	.globl _RADIOADDR0
                                    252 	.globl _RADIOACC
                                    253 	.globl _OC1STATUS
                                    254 	.globl _OC1PIN
                                    255 	.globl _OC1MODE
                                    256 	.globl _OC1COMP
                                    257 	.globl _OC1COMP1
                                    258 	.globl _OC1COMP0
                                    259 	.globl _OC0STATUS
                                    260 	.globl _OC0PIN
                                    261 	.globl _OC0MODE
                                    262 	.globl _OC0COMP
                                    263 	.globl _OC0COMP1
                                    264 	.globl _OC0COMP0
                                    265 	.globl _NVSTATUS
                                    266 	.globl _NVKEY
                                    267 	.globl _NVDATA
                                    268 	.globl _NVDATA1
                                    269 	.globl _NVDATA0
                                    270 	.globl _NVADDR
                                    271 	.globl _NVADDR1
                                    272 	.globl _NVADDR0
                                    273 	.globl _IC1STATUS
                                    274 	.globl _IC1MODE
                                    275 	.globl _IC1CAPT
                                    276 	.globl _IC1CAPT1
                                    277 	.globl _IC1CAPT0
                                    278 	.globl _IC0STATUS
                                    279 	.globl _IC0MODE
                                    280 	.globl _IC0CAPT
                                    281 	.globl _IC0CAPT1
                                    282 	.globl _IC0CAPT0
                                    283 	.globl _PORTR
                                    284 	.globl _PORTC
                                    285 	.globl _PORTB
                                    286 	.globl _PORTA
                                    287 	.globl _PINR
                                    288 	.globl _PINC
                                    289 	.globl _PINB
                                    290 	.globl _PINA
                                    291 	.globl _DIRR
                                    292 	.globl _DIRC
                                    293 	.globl _DIRB
                                    294 	.globl _DIRA
                                    295 	.globl _DBGLNKSTAT
                                    296 	.globl _DBGLNKBUF
                                    297 	.globl _CODECONFIG
                                    298 	.globl _CLKSTAT
                                    299 	.globl _CLKCON
                                    300 	.globl _ANALOGCOMP
                                    301 	.globl _ADCCONV
                                    302 	.globl _ADCCLKSRC
                                    303 	.globl _ADCCH3CONFIG
                                    304 	.globl _ADCCH2CONFIG
                                    305 	.globl _ADCCH1CONFIG
                                    306 	.globl _ADCCH0CONFIG
                                    307 	.globl __XPAGE
                                    308 	.globl _XPAGE
                                    309 	.globl _SP
                                    310 	.globl _PSW
                                    311 	.globl _PCON
                                    312 	.globl _IP
                                    313 	.globl _IE
                                    314 	.globl _EIP
                                    315 	.globl _EIE
                                    316 	.globl _E2IP
                                    317 	.globl _E2IE
                                    318 	.globl _DPS
                                    319 	.globl _DPTR1
                                    320 	.globl _DPTR0
                                    321 	.globl _DPL1
                                    322 	.globl _DPL
                                    323 	.globl _DPH1
                                    324 	.globl _DPH
                                    325 	.globl _B
                                    326 	.globl _ACC
                                    327 	.globl _radio_not_found_lcd_display
                                    328 	.globl _radio_lcd_display
                                    329 	.globl _f33_saved
                                    330 	.globl _f32_saved
                                    331 	.globl _f31_saved
                                    332 	.globl _f30_saved
                                    333 	.globl _axradio_timer
                                    334 	.globl _axradio_cb_transmitdata
                                    335 	.globl _axradio_cb_transmitend
                                    336 	.globl _axradio_cb_transmitstart
                                    337 	.globl _axradio_cb_channelstate
                                    338 	.globl _axradio_cb_receivesfd
                                    339 	.globl _axradio_cb_receive
                                    340 	.globl _axradio_rxbuffer
                                    341 	.globl _axradio_txbuffer
                                    342 	.globl _axradio_default_remoteaddr
                                    343 	.globl _axradio_localaddr
                                    344 	.globl _axradio_timeanchor
                                    345 	.globl _axradio_sync_periodcorr
                                    346 	.globl _axradio_sync_time
                                    347 	.globl _axradio_ack_seqnr
                                    348 	.globl _axradio_ack_count
                                    349 	.globl _axradio_curfreqoffset
                                    350 	.globl _axradio_curchannel
                                    351 	.globl _axradio_txbuffer_cnt
                                    352 	.globl _axradio_txbuffer_len
                                    353 	.globl _axradio_syncstate
                                    354 	.globl _AX5043_TIMEGAIN3NB
                                    355 	.globl _AX5043_TIMEGAIN2NB
                                    356 	.globl _AX5043_TIMEGAIN1NB
                                    357 	.globl _AX5043_TIMEGAIN0NB
                                    358 	.globl _AX5043_RXPARAMSETSNB
                                    359 	.globl _AX5043_RXPARAMCURSETNB
                                    360 	.globl _AX5043_PKTMAXLENNB
                                    361 	.globl _AX5043_PKTLENOFFSETNB
                                    362 	.globl _AX5043_PKTLENCFGNB
                                    363 	.globl _AX5043_PKTADDRMASK3NB
                                    364 	.globl _AX5043_PKTADDRMASK2NB
                                    365 	.globl _AX5043_PKTADDRMASK1NB
                                    366 	.globl _AX5043_PKTADDRMASK0NB
                                    367 	.globl _AX5043_PKTADDRCFGNB
                                    368 	.globl _AX5043_PKTADDR3NB
                                    369 	.globl _AX5043_PKTADDR2NB
                                    370 	.globl _AX5043_PKTADDR1NB
                                    371 	.globl _AX5043_PKTADDR0NB
                                    372 	.globl _AX5043_PHASEGAIN3NB
                                    373 	.globl _AX5043_PHASEGAIN2NB
                                    374 	.globl _AX5043_PHASEGAIN1NB
                                    375 	.globl _AX5043_PHASEGAIN0NB
                                    376 	.globl _AX5043_FREQUENCYLEAKNB
                                    377 	.globl _AX5043_FREQUENCYGAIND3NB
                                    378 	.globl _AX5043_FREQUENCYGAIND2NB
                                    379 	.globl _AX5043_FREQUENCYGAIND1NB
                                    380 	.globl _AX5043_FREQUENCYGAIND0NB
                                    381 	.globl _AX5043_FREQUENCYGAINC3NB
                                    382 	.globl _AX5043_FREQUENCYGAINC2NB
                                    383 	.globl _AX5043_FREQUENCYGAINC1NB
                                    384 	.globl _AX5043_FREQUENCYGAINC0NB
                                    385 	.globl _AX5043_FREQUENCYGAINB3NB
                                    386 	.globl _AX5043_FREQUENCYGAINB2NB
                                    387 	.globl _AX5043_FREQUENCYGAINB1NB
                                    388 	.globl _AX5043_FREQUENCYGAINB0NB
                                    389 	.globl _AX5043_FREQUENCYGAINA3NB
                                    390 	.globl _AX5043_FREQUENCYGAINA2NB
                                    391 	.globl _AX5043_FREQUENCYGAINA1NB
                                    392 	.globl _AX5043_FREQUENCYGAINA0NB
                                    393 	.globl _AX5043_FREQDEV13NB
                                    394 	.globl _AX5043_FREQDEV12NB
                                    395 	.globl _AX5043_FREQDEV11NB
                                    396 	.globl _AX5043_FREQDEV10NB
                                    397 	.globl _AX5043_FREQDEV03NB
                                    398 	.globl _AX5043_FREQDEV02NB
                                    399 	.globl _AX5043_FREQDEV01NB
                                    400 	.globl _AX5043_FREQDEV00NB
                                    401 	.globl _AX5043_FOURFSK3NB
                                    402 	.globl _AX5043_FOURFSK2NB
                                    403 	.globl _AX5043_FOURFSK1NB
                                    404 	.globl _AX5043_FOURFSK0NB
                                    405 	.globl _AX5043_DRGAIN3NB
                                    406 	.globl _AX5043_DRGAIN2NB
                                    407 	.globl _AX5043_DRGAIN1NB
                                    408 	.globl _AX5043_DRGAIN0NB
                                    409 	.globl _AX5043_BBOFFSRES3NB
                                    410 	.globl _AX5043_BBOFFSRES2NB
                                    411 	.globl _AX5043_BBOFFSRES1NB
                                    412 	.globl _AX5043_BBOFFSRES0NB
                                    413 	.globl _AX5043_AMPLITUDEGAIN3NB
                                    414 	.globl _AX5043_AMPLITUDEGAIN2NB
                                    415 	.globl _AX5043_AMPLITUDEGAIN1NB
                                    416 	.globl _AX5043_AMPLITUDEGAIN0NB
                                    417 	.globl _AX5043_AGCTARGET3NB
                                    418 	.globl _AX5043_AGCTARGET2NB
                                    419 	.globl _AX5043_AGCTARGET1NB
                                    420 	.globl _AX5043_AGCTARGET0NB
                                    421 	.globl _AX5043_AGCMINMAX3NB
                                    422 	.globl _AX5043_AGCMINMAX2NB
                                    423 	.globl _AX5043_AGCMINMAX1NB
                                    424 	.globl _AX5043_AGCMINMAX0NB
                                    425 	.globl _AX5043_AGCGAIN3NB
                                    426 	.globl _AX5043_AGCGAIN2NB
                                    427 	.globl _AX5043_AGCGAIN1NB
                                    428 	.globl _AX5043_AGCGAIN0NB
                                    429 	.globl _AX5043_AGCAHYST3NB
                                    430 	.globl _AX5043_AGCAHYST2NB
                                    431 	.globl _AX5043_AGCAHYST1NB
                                    432 	.globl _AX5043_AGCAHYST0NB
                                    433 	.globl _AX5043_0xF44NB
                                    434 	.globl _AX5043_0xF35NB
                                    435 	.globl _AX5043_0xF34NB
                                    436 	.globl _AX5043_0xF33NB
                                    437 	.globl _AX5043_0xF32NB
                                    438 	.globl _AX5043_0xF31NB
                                    439 	.globl _AX5043_0xF30NB
                                    440 	.globl _AX5043_0xF26NB
                                    441 	.globl _AX5043_0xF23NB
                                    442 	.globl _AX5043_0xF22NB
                                    443 	.globl _AX5043_0xF21NB
                                    444 	.globl _AX5043_0xF1CNB
                                    445 	.globl _AX5043_0xF18NB
                                    446 	.globl _AX5043_0xF0CNB
                                    447 	.globl _AX5043_0xF00NB
                                    448 	.globl _AX5043_XTALSTATUSNB
                                    449 	.globl _AX5043_XTALOSCNB
                                    450 	.globl _AX5043_XTALCAPNB
                                    451 	.globl _AX5043_XTALAMPLNB
                                    452 	.globl _AX5043_WAKEUPXOEARLYNB
                                    453 	.globl _AX5043_WAKEUPTIMER1NB
                                    454 	.globl _AX5043_WAKEUPTIMER0NB
                                    455 	.globl _AX5043_WAKEUPFREQ1NB
                                    456 	.globl _AX5043_WAKEUPFREQ0NB
                                    457 	.globl _AX5043_WAKEUP1NB
                                    458 	.globl _AX5043_WAKEUP0NB
                                    459 	.globl _AX5043_TXRATE2NB
                                    460 	.globl _AX5043_TXRATE1NB
                                    461 	.globl _AX5043_TXRATE0NB
                                    462 	.globl _AX5043_TXPWRCOEFFE1NB
                                    463 	.globl _AX5043_TXPWRCOEFFE0NB
                                    464 	.globl _AX5043_TXPWRCOEFFD1NB
                                    465 	.globl _AX5043_TXPWRCOEFFD0NB
                                    466 	.globl _AX5043_TXPWRCOEFFC1NB
                                    467 	.globl _AX5043_TXPWRCOEFFC0NB
                                    468 	.globl _AX5043_TXPWRCOEFFB1NB
                                    469 	.globl _AX5043_TXPWRCOEFFB0NB
                                    470 	.globl _AX5043_TXPWRCOEFFA1NB
                                    471 	.globl _AX5043_TXPWRCOEFFA0NB
                                    472 	.globl _AX5043_TRKRFFREQ2NB
                                    473 	.globl _AX5043_TRKRFFREQ1NB
                                    474 	.globl _AX5043_TRKRFFREQ0NB
                                    475 	.globl _AX5043_TRKPHASE1NB
                                    476 	.globl _AX5043_TRKPHASE0NB
                                    477 	.globl _AX5043_TRKFSKDEMOD1NB
                                    478 	.globl _AX5043_TRKFSKDEMOD0NB
                                    479 	.globl _AX5043_TRKFREQ1NB
                                    480 	.globl _AX5043_TRKFREQ0NB
                                    481 	.globl _AX5043_TRKDATARATE2NB
                                    482 	.globl _AX5043_TRKDATARATE1NB
                                    483 	.globl _AX5043_TRKDATARATE0NB
                                    484 	.globl _AX5043_TRKAMPLITUDE1NB
                                    485 	.globl _AX5043_TRKAMPLITUDE0NB
                                    486 	.globl _AX5043_TRKAFSKDEMOD1NB
                                    487 	.globl _AX5043_TRKAFSKDEMOD0NB
                                    488 	.globl _AX5043_TMGTXSETTLENB
                                    489 	.globl _AX5043_TMGTXBOOSTNB
                                    490 	.globl _AX5043_TMGRXSETTLENB
                                    491 	.globl _AX5043_TMGRXRSSINB
                                    492 	.globl _AX5043_TMGRXPREAMBLE3NB
                                    493 	.globl _AX5043_TMGRXPREAMBLE2NB
                                    494 	.globl _AX5043_TMGRXPREAMBLE1NB
                                    495 	.globl _AX5043_TMGRXOFFSACQNB
                                    496 	.globl _AX5043_TMGRXCOARSEAGCNB
                                    497 	.globl _AX5043_TMGRXBOOSTNB
                                    498 	.globl _AX5043_TMGRXAGCNB
                                    499 	.globl _AX5043_TIMER2NB
                                    500 	.globl _AX5043_TIMER1NB
                                    501 	.globl _AX5043_TIMER0NB
                                    502 	.globl _AX5043_SILICONREVISIONNB
                                    503 	.globl _AX5043_SCRATCHNB
                                    504 	.globl _AX5043_RXDATARATE2NB
                                    505 	.globl _AX5043_RXDATARATE1NB
                                    506 	.globl _AX5043_RXDATARATE0NB
                                    507 	.globl _AX5043_RSSIREFERENCENB
                                    508 	.globl _AX5043_RSSIABSTHRNB
                                    509 	.globl _AX5043_RSSINB
                                    510 	.globl _AX5043_REFNB
                                    511 	.globl _AX5043_RADIOSTATENB
                                    512 	.globl _AX5043_RADIOEVENTREQ1NB
                                    513 	.globl _AX5043_RADIOEVENTREQ0NB
                                    514 	.globl _AX5043_RADIOEVENTMASK1NB
                                    515 	.globl _AX5043_RADIOEVENTMASK0NB
                                    516 	.globl _AX5043_PWRMODENB
                                    517 	.globl _AX5043_PWRAMPNB
                                    518 	.globl _AX5043_POWSTICKYSTATNB
                                    519 	.globl _AX5043_POWSTATNB
                                    520 	.globl _AX5043_POWIRQMASKNB
                                    521 	.globl _AX5043_POWCTRL1NB
                                    522 	.globl _AX5043_PLLVCOIRNB
                                    523 	.globl _AX5043_PLLVCOINB
                                    524 	.globl _AX5043_PLLVCODIVNB
                                    525 	.globl _AX5043_PLLRNGCLKNB
                                    526 	.globl _AX5043_PLLRANGINGBNB
                                    527 	.globl _AX5043_PLLRANGINGANB
                                    528 	.globl _AX5043_PLLLOOPBOOSTNB
                                    529 	.globl _AX5043_PLLLOOPNB
                                    530 	.globl _AX5043_PLLLOCKDETNB
                                    531 	.globl _AX5043_PLLCPIBOOSTNB
                                    532 	.globl _AX5043_PLLCPINB
                                    533 	.globl _AX5043_PKTSTOREFLAGSNB
                                    534 	.globl _AX5043_PKTMISCFLAGSNB
                                    535 	.globl _AX5043_PKTCHUNKSIZENB
                                    536 	.globl _AX5043_PKTACCEPTFLAGSNB
                                    537 	.globl _AX5043_PINSTATENB
                                    538 	.globl _AX5043_PINFUNCSYSCLKNB
                                    539 	.globl _AX5043_PINFUNCPWRAMPNB
                                    540 	.globl _AX5043_PINFUNCIRQNB
                                    541 	.globl _AX5043_PINFUNCDCLKNB
                                    542 	.globl _AX5043_PINFUNCDATANB
                                    543 	.globl _AX5043_PINFUNCANTSELNB
                                    544 	.globl _AX5043_MODULATIONNB
                                    545 	.globl _AX5043_MODCFGPNB
                                    546 	.globl _AX5043_MODCFGFNB
                                    547 	.globl _AX5043_MODCFGANB
                                    548 	.globl _AX5043_MAXRFOFFSET2NB
                                    549 	.globl _AX5043_MAXRFOFFSET1NB
                                    550 	.globl _AX5043_MAXRFOFFSET0NB
                                    551 	.globl _AX5043_MAXDROFFSET2NB
                                    552 	.globl _AX5043_MAXDROFFSET1NB
                                    553 	.globl _AX5043_MAXDROFFSET0NB
                                    554 	.globl _AX5043_MATCH1PAT1NB
                                    555 	.globl _AX5043_MATCH1PAT0NB
                                    556 	.globl _AX5043_MATCH1MINNB
                                    557 	.globl _AX5043_MATCH1MAXNB
                                    558 	.globl _AX5043_MATCH1LENNB
                                    559 	.globl _AX5043_MATCH0PAT3NB
                                    560 	.globl _AX5043_MATCH0PAT2NB
                                    561 	.globl _AX5043_MATCH0PAT1NB
                                    562 	.globl _AX5043_MATCH0PAT0NB
                                    563 	.globl _AX5043_MATCH0MINNB
                                    564 	.globl _AX5043_MATCH0MAXNB
                                    565 	.globl _AX5043_MATCH0LENNB
                                    566 	.globl _AX5043_LPOSCSTATUSNB
                                    567 	.globl _AX5043_LPOSCREF1NB
                                    568 	.globl _AX5043_LPOSCREF0NB
                                    569 	.globl _AX5043_LPOSCPER1NB
                                    570 	.globl _AX5043_LPOSCPER0NB
                                    571 	.globl _AX5043_LPOSCKFILT1NB
                                    572 	.globl _AX5043_LPOSCKFILT0NB
                                    573 	.globl _AX5043_LPOSCFREQ1NB
                                    574 	.globl _AX5043_LPOSCFREQ0NB
                                    575 	.globl _AX5043_LPOSCCONFIGNB
                                    576 	.globl _AX5043_IRQREQUEST1NB
                                    577 	.globl _AX5043_IRQREQUEST0NB
                                    578 	.globl _AX5043_IRQMASK1NB
                                    579 	.globl _AX5043_IRQMASK0NB
                                    580 	.globl _AX5043_IRQINVERSION1NB
                                    581 	.globl _AX5043_IRQINVERSION0NB
                                    582 	.globl _AX5043_IFFREQ1NB
                                    583 	.globl _AX5043_IFFREQ0NB
                                    584 	.globl _AX5043_GPADCPERIODNB
                                    585 	.globl _AX5043_GPADCCTRLNB
                                    586 	.globl _AX5043_GPADC13VALUE1NB
                                    587 	.globl _AX5043_GPADC13VALUE0NB
                                    588 	.globl _AX5043_FSKDMIN1NB
                                    589 	.globl _AX5043_FSKDMIN0NB
                                    590 	.globl _AX5043_FSKDMAX1NB
                                    591 	.globl _AX5043_FSKDMAX0NB
                                    592 	.globl _AX5043_FSKDEV2NB
                                    593 	.globl _AX5043_FSKDEV1NB
                                    594 	.globl _AX5043_FSKDEV0NB
                                    595 	.globl _AX5043_FREQB3NB
                                    596 	.globl _AX5043_FREQB2NB
                                    597 	.globl _AX5043_FREQB1NB
                                    598 	.globl _AX5043_FREQB0NB
                                    599 	.globl _AX5043_FREQA3NB
                                    600 	.globl _AX5043_FREQA2NB
                                    601 	.globl _AX5043_FREQA1NB
                                    602 	.globl _AX5043_FREQA0NB
                                    603 	.globl _AX5043_FRAMINGNB
                                    604 	.globl _AX5043_FIFOTHRESH1NB
                                    605 	.globl _AX5043_FIFOTHRESH0NB
                                    606 	.globl _AX5043_FIFOSTATNB
                                    607 	.globl _AX5043_FIFOFREE1NB
                                    608 	.globl _AX5043_FIFOFREE0NB
                                    609 	.globl _AX5043_FIFODATANB
                                    610 	.globl _AX5043_FIFOCOUNT1NB
                                    611 	.globl _AX5043_FIFOCOUNT0NB
                                    612 	.globl _AX5043_FECSYNCNB
                                    613 	.globl _AX5043_FECSTATUSNB
                                    614 	.globl _AX5043_FECNB
                                    615 	.globl _AX5043_ENCODINGNB
                                    616 	.globl _AX5043_DIVERSITYNB
                                    617 	.globl _AX5043_DECIMATIONNB
                                    618 	.globl _AX5043_DACVALUE1NB
                                    619 	.globl _AX5043_DACVALUE0NB
                                    620 	.globl _AX5043_DACCONFIGNB
                                    621 	.globl _AX5043_CRCINIT3NB
                                    622 	.globl _AX5043_CRCINIT2NB
                                    623 	.globl _AX5043_CRCINIT1NB
                                    624 	.globl _AX5043_CRCINIT0NB
                                    625 	.globl _AX5043_BGNDRSSITHRNB
                                    626 	.globl _AX5043_BGNDRSSIGAINNB
                                    627 	.globl _AX5043_BGNDRSSINB
                                    628 	.globl _AX5043_BBTUNENB
                                    629 	.globl _AX5043_BBOFFSCAPNB
                                    630 	.globl _AX5043_AMPLFILTERNB
                                    631 	.globl _AX5043_AGCCOUNTERNB
                                    632 	.globl _AX5043_AFSKSPACE1NB
                                    633 	.globl _AX5043_AFSKSPACE0NB
                                    634 	.globl _AX5043_AFSKMARK1NB
                                    635 	.globl _AX5043_AFSKMARK0NB
                                    636 	.globl _AX5043_AFSKCTRLNB
                                    637 	.globl _AX5043_TIMEGAIN3
                                    638 	.globl _AX5043_TIMEGAIN2
                                    639 	.globl _AX5043_TIMEGAIN1
                                    640 	.globl _AX5043_TIMEGAIN0
                                    641 	.globl _AX5043_RXPARAMSETS
                                    642 	.globl _AX5043_RXPARAMCURSET
                                    643 	.globl _AX5043_PKTMAXLEN
                                    644 	.globl _AX5043_PKTLENOFFSET
                                    645 	.globl _AX5043_PKTLENCFG
                                    646 	.globl _AX5043_PKTADDRMASK3
                                    647 	.globl _AX5043_PKTADDRMASK2
                                    648 	.globl _AX5043_PKTADDRMASK1
                                    649 	.globl _AX5043_PKTADDRMASK0
                                    650 	.globl _AX5043_PKTADDRCFG
                                    651 	.globl _AX5043_PKTADDR3
                                    652 	.globl _AX5043_PKTADDR2
                                    653 	.globl _AX5043_PKTADDR1
                                    654 	.globl _AX5043_PKTADDR0
                                    655 	.globl _AX5043_PHASEGAIN3
                                    656 	.globl _AX5043_PHASEGAIN2
                                    657 	.globl _AX5043_PHASEGAIN1
                                    658 	.globl _AX5043_PHASEGAIN0
                                    659 	.globl _AX5043_FREQUENCYLEAK
                                    660 	.globl _AX5043_FREQUENCYGAIND3
                                    661 	.globl _AX5043_FREQUENCYGAIND2
                                    662 	.globl _AX5043_FREQUENCYGAIND1
                                    663 	.globl _AX5043_FREQUENCYGAIND0
                                    664 	.globl _AX5043_FREQUENCYGAINC3
                                    665 	.globl _AX5043_FREQUENCYGAINC2
                                    666 	.globl _AX5043_FREQUENCYGAINC1
                                    667 	.globl _AX5043_FREQUENCYGAINC0
                                    668 	.globl _AX5043_FREQUENCYGAINB3
                                    669 	.globl _AX5043_FREQUENCYGAINB2
                                    670 	.globl _AX5043_FREQUENCYGAINB1
                                    671 	.globl _AX5043_FREQUENCYGAINB0
                                    672 	.globl _AX5043_FREQUENCYGAINA3
                                    673 	.globl _AX5043_FREQUENCYGAINA2
                                    674 	.globl _AX5043_FREQUENCYGAINA1
                                    675 	.globl _AX5043_FREQUENCYGAINA0
                                    676 	.globl _AX5043_FREQDEV13
                                    677 	.globl _AX5043_FREQDEV12
                                    678 	.globl _AX5043_FREQDEV11
                                    679 	.globl _AX5043_FREQDEV10
                                    680 	.globl _AX5043_FREQDEV03
                                    681 	.globl _AX5043_FREQDEV02
                                    682 	.globl _AX5043_FREQDEV01
                                    683 	.globl _AX5043_FREQDEV00
                                    684 	.globl _AX5043_FOURFSK3
                                    685 	.globl _AX5043_FOURFSK2
                                    686 	.globl _AX5043_FOURFSK1
                                    687 	.globl _AX5043_FOURFSK0
                                    688 	.globl _AX5043_DRGAIN3
                                    689 	.globl _AX5043_DRGAIN2
                                    690 	.globl _AX5043_DRGAIN1
                                    691 	.globl _AX5043_DRGAIN0
                                    692 	.globl _AX5043_BBOFFSRES3
                                    693 	.globl _AX5043_BBOFFSRES2
                                    694 	.globl _AX5043_BBOFFSRES1
                                    695 	.globl _AX5043_BBOFFSRES0
                                    696 	.globl _AX5043_AMPLITUDEGAIN3
                                    697 	.globl _AX5043_AMPLITUDEGAIN2
                                    698 	.globl _AX5043_AMPLITUDEGAIN1
                                    699 	.globl _AX5043_AMPLITUDEGAIN0
                                    700 	.globl _AX5043_AGCTARGET3
                                    701 	.globl _AX5043_AGCTARGET2
                                    702 	.globl _AX5043_AGCTARGET1
                                    703 	.globl _AX5043_AGCTARGET0
                                    704 	.globl _AX5043_AGCMINMAX3
                                    705 	.globl _AX5043_AGCMINMAX2
                                    706 	.globl _AX5043_AGCMINMAX1
                                    707 	.globl _AX5043_AGCMINMAX0
                                    708 	.globl _AX5043_AGCGAIN3
                                    709 	.globl _AX5043_AGCGAIN2
                                    710 	.globl _AX5043_AGCGAIN1
                                    711 	.globl _AX5043_AGCGAIN0
                                    712 	.globl _AX5043_AGCAHYST3
                                    713 	.globl _AX5043_AGCAHYST2
                                    714 	.globl _AX5043_AGCAHYST1
                                    715 	.globl _AX5043_AGCAHYST0
                                    716 	.globl _AX5043_0xF44
                                    717 	.globl _AX5043_0xF35
                                    718 	.globl _AX5043_0xF34
                                    719 	.globl _AX5043_0xF33
                                    720 	.globl _AX5043_0xF32
                                    721 	.globl _AX5043_0xF31
                                    722 	.globl _AX5043_0xF30
                                    723 	.globl _AX5043_0xF26
                                    724 	.globl _AX5043_0xF23
                                    725 	.globl _AX5043_0xF22
                                    726 	.globl _AX5043_0xF21
                                    727 	.globl _AX5043_0xF1C
                                    728 	.globl _AX5043_0xF18
                                    729 	.globl _AX5043_0xF0C
                                    730 	.globl _AX5043_0xF00
                                    731 	.globl _AX5043_XTALSTATUS
                                    732 	.globl _AX5043_XTALOSC
                                    733 	.globl _AX5043_XTALCAP
                                    734 	.globl _AX5043_XTALAMPL
                                    735 	.globl _AX5043_WAKEUPXOEARLY
                                    736 	.globl _AX5043_WAKEUPTIMER1
                                    737 	.globl _AX5043_WAKEUPTIMER0
                                    738 	.globl _AX5043_WAKEUPFREQ1
                                    739 	.globl _AX5043_WAKEUPFREQ0
                                    740 	.globl _AX5043_WAKEUP1
                                    741 	.globl _AX5043_WAKEUP0
                                    742 	.globl _AX5043_TXRATE2
                                    743 	.globl _AX5043_TXRATE1
                                    744 	.globl _AX5043_TXRATE0
                                    745 	.globl _AX5043_TXPWRCOEFFE1
                                    746 	.globl _AX5043_TXPWRCOEFFE0
                                    747 	.globl _AX5043_TXPWRCOEFFD1
                                    748 	.globl _AX5043_TXPWRCOEFFD0
                                    749 	.globl _AX5043_TXPWRCOEFFC1
                                    750 	.globl _AX5043_TXPWRCOEFFC0
                                    751 	.globl _AX5043_TXPWRCOEFFB1
                                    752 	.globl _AX5043_TXPWRCOEFFB0
                                    753 	.globl _AX5043_TXPWRCOEFFA1
                                    754 	.globl _AX5043_TXPWRCOEFFA0
                                    755 	.globl _AX5043_TRKRFFREQ2
                                    756 	.globl _AX5043_TRKRFFREQ1
                                    757 	.globl _AX5043_TRKRFFREQ0
                                    758 	.globl _AX5043_TRKPHASE1
                                    759 	.globl _AX5043_TRKPHASE0
                                    760 	.globl _AX5043_TRKFSKDEMOD1
                                    761 	.globl _AX5043_TRKFSKDEMOD0
                                    762 	.globl _AX5043_TRKFREQ1
                                    763 	.globl _AX5043_TRKFREQ0
                                    764 	.globl _AX5043_TRKDATARATE2
                                    765 	.globl _AX5043_TRKDATARATE1
                                    766 	.globl _AX5043_TRKDATARATE0
                                    767 	.globl _AX5043_TRKAMPLITUDE1
                                    768 	.globl _AX5043_TRKAMPLITUDE0
                                    769 	.globl _AX5043_TRKAFSKDEMOD1
                                    770 	.globl _AX5043_TRKAFSKDEMOD0
                                    771 	.globl _AX5043_TMGTXSETTLE
                                    772 	.globl _AX5043_TMGTXBOOST
                                    773 	.globl _AX5043_TMGRXSETTLE
                                    774 	.globl _AX5043_TMGRXRSSI
                                    775 	.globl _AX5043_TMGRXPREAMBLE3
                                    776 	.globl _AX5043_TMGRXPREAMBLE2
                                    777 	.globl _AX5043_TMGRXPREAMBLE1
                                    778 	.globl _AX5043_TMGRXOFFSACQ
                                    779 	.globl _AX5043_TMGRXCOARSEAGC
                                    780 	.globl _AX5043_TMGRXBOOST
                                    781 	.globl _AX5043_TMGRXAGC
                                    782 	.globl _AX5043_TIMER2
                                    783 	.globl _AX5043_TIMER1
                                    784 	.globl _AX5043_TIMER0
                                    785 	.globl _AX5043_SILICONREVISION
                                    786 	.globl _AX5043_SCRATCH
                                    787 	.globl _AX5043_RXDATARATE2
                                    788 	.globl _AX5043_RXDATARATE1
                                    789 	.globl _AX5043_RXDATARATE0
                                    790 	.globl _AX5043_RSSIREFERENCE
                                    791 	.globl _AX5043_RSSIABSTHR
                                    792 	.globl _AX5043_RSSI
                                    793 	.globl _AX5043_REF
                                    794 	.globl _AX5043_RADIOSTATE
                                    795 	.globl _AX5043_RADIOEVENTREQ1
                                    796 	.globl _AX5043_RADIOEVENTREQ0
                                    797 	.globl _AX5043_RADIOEVENTMASK1
                                    798 	.globl _AX5043_RADIOEVENTMASK0
                                    799 	.globl _AX5043_PWRMODE
                                    800 	.globl _AX5043_PWRAMP
                                    801 	.globl _AX5043_POWSTICKYSTAT
                                    802 	.globl _AX5043_POWSTAT
                                    803 	.globl _AX5043_POWIRQMASK
                                    804 	.globl _AX5043_POWCTRL1
                                    805 	.globl _AX5043_PLLVCOIR
                                    806 	.globl _AX5043_PLLVCOI
                                    807 	.globl _AX5043_PLLVCODIV
                                    808 	.globl _AX5043_PLLRNGCLK
                                    809 	.globl _AX5043_PLLRANGINGB
                                    810 	.globl _AX5043_PLLRANGINGA
                                    811 	.globl _AX5043_PLLLOOPBOOST
                                    812 	.globl _AX5043_PLLLOOP
                                    813 	.globl _AX5043_PLLLOCKDET
                                    814 	.globl _AX5043_PLLCPIBOOST
                                    815 	.globl _AX5043_PLLCPI
                                    816 	.globl _AX5043_PKTSTOREFLAGS
                                    817 	.globl _AX5043_PKTMISCFLAGS
                                    818 	.globl _AX5043_PKTCHUNKSIZE
                                    819 	.globl _AX5043_PKTACCEPTFLAGS
                                    820 	.globl _AX5043_PINSTATE
                                    821 	.globl _AX5043_PINFUNCSYSCLK
                                    822 	.globl _AX5043_PINFUNCPWRAMP
                                    823 	.globl _AX5043_PINFUNCIRQ
                                    824 	.globl _AX5043_PINFUNCDCLK
                                    825 	.globl _AX5043_PINFUNCDATA
                                    826 	.globl _AX5043_PINFUNCANTSEL
                                    827 	.globl _AX5043_MODULATION
                                    828 	.globl _AX5043_MODCFGP
                                    829 	.globl _AX5043_MODCFGF
                                    830 	.globl _AX5043_MODCFGA
                                    831 	.globl _AX5043_MAXRFOFFSET2
                                    832 	.globl _AX5043_MAXRFOFFSET1
                                    833 	.globl _AX5043_MAXRFOFFSET0
                                    834 	.globl _AX5043_MAXDROFFSET2
                                    835 	.globl _AX5043_MAXDROFFSET1
                                    836 	.globl _AX5043_MAXDROFFSET0
                                    837 	.globl _AX5043_MATCH1PAT1
                                    838 	.globl _AX5043_MATCH1PAT0
                                    839 	.globl _AX5043_MATCH1MIN
                                    840 	.globl _AX5043_MATCH1MAX
                                    841 	.globl _AX5043_MATCH1LEN
                                    842 	.globl _AX5043_MATCH0PAT3
                                    843 	.globl _AX5043_MATCH0PAT2
                                    844 	.globl _AX5043_MATCH0PAT1
                                    845 	.globl _AX5043_MATCH0PAT0
                                    846 	.globl _AX5043_MATCH0MIN
                                    847 	.globl _AX5043_MATCH0MAX
                                    848 	.globl _AX5043_MATCH0LEN
                                    849 	.globl _AX5043_LPOSCSTATUS
                                    850 	.globl _AX5043_LPOSCREF1
                                    851 	.globl _AX5043_LPOSCREF0
                                    852 	.globl _AX5043_LPOSCPER1
                                    853 	.globl _AX5043_LPOSCPER0
                                    854 	.globl _AX5043_LPOSCKFILT1
                                    855 	.globl _AX5043_LPOSCKFILT0
                                    856 	.globl _AX5043_LPOSCFREQ1
                                    857 	.globl _AX5043_LPOSCFREQ0
                                    858 	.globl _AX5043_LPOSCCONFIG
                                    859 	.globl _AX5043_IRQREQUEST1
                                    860 	.globl _AX5043_IRQREQUEST0
                                    861 	.globl _AX5043_IRQMASK1
                                    862 	.globl _AX5043_IRQMASK0
                                    863 	.globl _AX5043_IRQINVERSION1
                                    864 	.globl _AX5043_IRQINVERSION0
                                    865 	.globl _AX5043_IFFREQ1
                                    866 	.globl _AX5043_IFFREQ0
                                    867 	.globl _AX5043_GPADCPERIOD
                                    868 	.globl _AX5043_GPADCCTRL
                                    869 	.globl _AX5043_GPADC13VALUE1
                                    870 	.globl _AX5043_GPADC13VALUE0
                                    871 	.globl _AX5043_FSKDMIN1
                                    872 	.globl _AX5043_FSKDMIN0
                                    873 	.globl _AX5043_FSKDMAX1
                                    874 	.globl _AX5043_FSKDMAX0
                                    875 	.globl _AX5043_FSKDEV2
                                    876 	.globl _AX5043_FSKDEV1
                                    877 	.globl _AX5043_FSKDEV0
                                    878 	.globl _AX5043_FREQB3
                                    879 	.globl _AX5043_FREQB2
                                    880 	.globl _AX5043_FREQB1
                                    881 	.globl _AX5043_FREQB0
                                    882 	.globl _AX5043_FREQA3
                                    883 	.globl _AX5043_FREQA2
                                    884 	.globl _AX5043_FREQA1
                                    885 	.globl _AX5043_FREQA0
                                    886 	.globl _AX5043_FRAMING
                                    887 	.globl _AX5043_FIFOTHRESH1
                                    888 	.globl _AX5043_FIFOTHRESH0
                                    889 	.globl _AX5043_FIFOSTAT
                                    890 	.globl _AX5043_FIFOFREE1
                                    891 	.globl _AX5043_FIFOFREE0
                                    892 	.globl _AX5043_FIFODATA
                                    893 	.globl _AX5043_FIFOCOUNT1
                                    894 	.globl _AX5043_FIFOCOUNT0
                                    895 	.globl _AX5043_FECSYNC
                                    896 	.globl _AX5043_FECSTATUS
                                    897 	.globl _AX5043_FEC
                                    898 	.globl _AX5043_ENCODING
                                    899 	.globl _AX5043_DIVERSITY
                                    900 	.globl _AX5043_DECIMATION
                                    901 	.globl _AX5043_DACVALUE1
                                    902 	.globl _AX5043_DACVALUE0
                                    903 	.globl _AX5043_DACCONFIG
                                    904 	.globl _AX5043_CRCINIT3
                                    905 	.globl _AX5043_CRCINIT2
                                    906 	.globl _AX5043_CRCINIT1
                                    907 	.globl _AX5043_CRCINIT0
                                    908 	.globl _AX5043_BGNDRSSITHR
                                    909 	.globl _AX5043_BGNDRSSIGAIN
                                    910 	.globl _AX5043_BGNDRSSI
                                    911 	.globl _AX5043_BBTUNE
                                    912 	.globl _AX5043_BBOFFSCAP
                                    913 	.globl _AX5043_AMPLFILTER
                                    914 	.globl _AX5043_AGCCOUNTER
                                    915 	.globl _AX5043_AFSKSPACE1
                                    916 	.globl _AX5043_AFSKSPACE0
                                    917 	.globl _AX5043_AFSKMARK1
                                    918 	.globl _AX5043_AFSKMARK0
                                    919 	.globl _AX5043_AFSKCTRL
                                    920 	.globl _XTALREADY
                                    921 	.globl _XTALOSC
                                    922 	.globl _XTALAMPL
                                    923 	.globl _SILICONREV
                                    924 	.globl _SCRATCH3
                                    925 	.globl _SCRATCH2
                                    926 	.globl _SCRATCH1
                                    927 	.globl _SCRATCH0
                                    928 	.globl _RADIOMUX
                                    929 	.globl _RADIOFSTATADDR
                                    930 	.globl _RADIOFSTATADDR1
                                    931 	.globl _RADIOFSTATADDR0
                                    932 	.globl _RADIOFDATAADDR
                                    933 	.globl _RADIOFDATAADDR1
                                    934 	.globl _RADIOFDATAADDR0
                                    935 	.globl _OSCRUN
                                    936 	.globl _OSCREADY
                                    937 	.globl _OSCFORCERUN
                                    938 	.globl _OSCCALIB
                                    939 	.globl _MISCCTRL
                                    940 	.globl _LPXOSCGM
                                    941 	.globl _LPOSCREF
                                    942 	.globl _LPOSCREF1
                                    943 	.globl _LPOSCREF0
                                    944 	.globl _LPOSCPER
                                    945 	.globl _LPOSCPER1
                                    946 	.globl _LPOSCPER0
                                    947 	.globl _LPOSCKFILT
                                    948 	.globl _LPOSCKFILT1
                                    949 	.globl _LPOSCKFILT0
                                    950 	.globl _LPOSCFREQ
                                    951 	.globl _LPOSCFREQ1
                                    952 	.globl _LPOSCFREQ0
                                    953 	.globl _LPOSCCONFIG
                                    954 	.globl _PINSEL
                                    955 	.globl _PINCHGC
                                    956 	.globl _PINCHGB
                                    957 	.globl _PINCHGA
                                    958 	.globl _PALTRADIO
                                    959 	.globl _PALTC
                                    960 	.globl _PALTB
                                    961 	.globl _PALTA
                                    962 	.globl _INTCHGC
                                    963 	.globl _INTCHGB
                                    964 	.globl _INTCHGA
                                    965 	.globl _EXTIRQ
                                    966 	.globl _GPIOENABLE
                                    967 	.globl _ANALOGA
                                    968 	.globl _FRCOSCREF
                                    969 	.globl _FRCOSCREF1
                                    970 	.globl _FRCOSCREF0
                                    971 	.globl _FRCOSCPER
                                    972 	.globl _FRCOSCPER1
                                    973 	.globl _FRCOSCPER0
                                    974 	.globl _FRCOSCKFILT
                                    975 	.globl _FRCOSCKFILT1
                                    976 	.globl _FRCOSCKFILT0
                                    977 	.globl _FRCOSCFREQ
                                    978 	.globl _FRCOSCFREQ1
                                    979 	.globl _FRCOSCFREQ0
                                    980 	.globl _FRCOSCCTRL
                                    981 	.globl _FRCOSCCONFIG
                                    982 	.globl _DMA1CONFIG
                                    983 	.globl _DMA1ADDR
                                    984 	.globl _DMA1ADDR1
                                    985 	.globl _DMA1ADDR0
                                    986 	.globl _DMA0CONFIG
                                    987 	.globl _DMA0ADDR
                                    988 	.globl _DMA0ADDR1
                                    989 	.globl _DMA0ADDR0
                                    990 	.globl _ADCTUNE2
                                    991 	.globl _ADCTUNE1
                                    992 	.globl _ADCTUNE0
                                    993 	.globl _ADCCH3VAL
                                    994 	.globl _ADCCH3VAL1
                                    995 	.globl _ADCCH3VAL0
                                    996 	.globl _ADCCH2VAL
                                    997 	.globl _ADCCH2VAL1
                                    998 	.globl _ADCCH2VAL0
                                    999 	.globl _ADCCH1VAL
                                   1000 	.globl _ADCCH1VAL1
                                   1001 	.globl _ADCCH1VAL0
                                   1002 	.globl _ADCCH0VAL
                                   1003 	.globl _ADCCH0VAL1
                                   1004 	.globl _ADCCH0VAL0
                                   1005 	.globl _axradio_transmit_PARM_3
                                   1006 	.globl _axradio_transmit_PARM_2
                                   1007 	.globl _aligned_alloc_PARM_2
                                   1008 	.globl _axradio_trxstate
                                   1009 	.globl _axradio_mode
                                   1010 	.globl _axradio_conv_time_totimer0
                                   1011 	.globl _axradio_isr
                                   1012 	.globl _ax5043_receiver_on_continuous
                                   1013 	.globl _ax5043_receiver_on_wor
                                   1014 	.globl _ax5043_prepare_tx
                                   1015 	.globl _ax5043_off
                                   1016 	.globl _ax5043_off_xtal
                                   1017 	.globl _axradio_wait_for_xtal
                                   1018 	.globl _axradio_init
                                   1019 	.globl _axradio_cansleep
                                   1020 	.globl _axradio_set_mode
                                   1021 	.globl _axradio_get_mode
                                   1022 	.globl _axradio_set_channel
                                   1023 	.globl _axradio_get_channel
                                   1024 	.globl _axradio_get_pllrange
                                   1025 	.globl _axradio_get_pllvcoi
                                   1026 	.globl _axradio_set_freqoffset
                                   1027 	.globl _axradio_get_freqoffset
                                   1028 	.globl _axradio_set_local_address
                                   1029 	.globl _axradio_get_local_address
                                   1030 	.globl _axradio_set_default_remote_address
                                   1031 	.globl _axradio_get_default_remote_address
                                   1032 	.globl _axradio_transmit
                                   1033 	.globl _axradio_agc_freeze
                                   1034 	.globl _axradio_agc_thaw
                                   1035 	.globl _axradio_calibrate_lposc
                                   1036 	.globl _axradio_commsleepexit
                                   1037 	.globl _axradio_check_fourfsk_modulation
                                   1038 	.globl _axradio_get_transmitter_pa_type
                                   1039 ;--------------------------------------------------------
                                   1040 ; special function registers
                                   1041 ;--------------------------------------------------------
                                   1042 	.area RSEG    (ABS,DATA)
      000000                       1043 	.org 0x0000
                           0000E0  1044 _ACC	=	0x00e0
                           0000F0  1045 _B	=	0x00f0
                           000083  1046 _DPH	=	0x0083
                           000085  1047 _DPH1	=	0x0085
                           000082  1048 _DPL	=	0x0082
                           000084  1049 _DPL1	=	0x0084
                           008382  1050 _DPTR0	=	0x8382
                           008584  1051 _DPTR1	=	0x8584
                           000086  1052 _DPS	=	0x0086
                           0000A0  1053 _E2IE	=	0x00a0
                           0000C0  1054 _E2IP	=	0x00c0
                           000098  1055 _EIE	=	0x0098
                           0000B0  1056 _EIP	=	0x00b0
                           0000A8  1057 _IE	=	0x00a8
                           0000B8  1058 _IP	=	0x00b8
                           000087  1059 _PCON	=	0x0087
                           0000D0  1060 _PSW	=	0x00d0
                           000081  1061 _SP	=	0x0081
                           0000D9  1062 _XPAGE	=	0x00d9
                           0000D9  1063 __XPAGE	=	0x00d9
                           0000CA  1064 _ADCCH0CONFIG	=	0x00ca
                           0000CB  1065 _ADCCH1CONFIG	=	0x00cb
                           0000D2  1066 _ADCCH2CONFIG	=	0x00d2
                           0000D3  1067 _ADCCH3CONFIG	=	0x00d3
                           0000D1  1068 _ADCCLKSRC	=	0x00d1
                           0000C9  1069 _ADCCONV	=	0x00c9
                           0000E1  1070 _ANALOGCOMP	=	0x00e1
                           0000C6  1071 _CLKCON	=	0x00c6
                           0000C7  1072 _CLKSTAT	=	0x00c7
                           000097  1073 _CODECONFIG	=	0x0097
                           0000E3  1074 _DBGLNKBUF	=	0x00e3
                           0000E2  1075 _DBGLNKSTAT	=	0x00e2
                           000089  1076 _DIRA	=	0x0089
                           00008A  1077 _DIRB	=	0x008a
                           00008B  1078 _DIRC	=	0x008b
                           00008E  1079 _DIRR	=	0x008e
                           0000C8  1080 _PINA	=	0x00c8
                           0000E8  1081 _PINB	=	0x00e8
                           0000F8  1082 _PINC	=	0x00f8
                           00008D  1083 _PINR	=	0x008d
                           000080  1084 _PORTA	=	0x0080
                           000088  1085 _PORTB	=	0x0088
                           000090  1086 _PORTC	=	0x0090
                           00008C  1087 _PORTR	=	0x008c
                           0000CE  1088 _IC0CAPT0	=	0x00ce
                           0000CF  1089 _IC0CAPT1	=	0x00cf
                           00CFCE  1090 _IC0CAPT	=	0xcfce
                           0000CC  1091 _IC0MODE	=	0x00cc
                           0000CD  1092 _IC0STATUS	=	0x00cd
                           0000D6  1093 _IC1CAPT0	=	0x00d6
                           0000D7  1094 _IC1CAPT1	=	0x00d7
                           00D7D6  1095 _IC1CAPT	=	0xd7d6
                           0000D4  1096 _IC1MODE	=	0x00d4
                           0000D5  1097 _IC1STATUS	=	0x00d5
                           000092  1098 _NVADDR0	=	0x0092
                           000093  1099 _NVADDR1	=	0x0093
                           009392  1100 _NVADDR	=	0x9392
                           000094  1101 _NVDATA0	=	0x0094
                           000095  1102 _NVDATA1	=	0x0095
                           009594  1103 _NVDATA	=	0x9594
                           000096  1104 _NVKEY	=	0x0096
                           000091  1105 _NVSTATUS	=	0x0091
                           0000BC  1106 _OC0COMP0	=	0x00bc
                           0000BD  1107 _OC0COMP1	=	0x00bd
                           00BDBC  1108 _OC0COMP	=	0xbdbc
                           0000B9  1109 _OC0MODE	=	0x00b9
                           0000BA  1110 _OC0PIN	=	0x00ba
                           0000BB  1111 _OC0STATUS	=	0x00bb
                           0000C4  1112 _OC1COMP0	=	0x00c4
                           0000C5  1113 _OC1COMP1	=	0x00c5
                           00C5C4  1114 _OC1COMP	=	0xc5c4
                           0000C1  1115 _OC1MODE	=	0x00c1
                           0000C2  1116 _OC1PIN	=	0x00c2
                           0000C3  1117 _OC1STATUS	=	0x00c3
                           0000B1  1118 _RADIOACC	=	0x00b1
                           0000B3  1119 _RADIOADDR0	=	0x00b3
                           0000B2  1120 _RADIOADDR1	=	0x00b2
                           00B2B3  1121 _RADIOADDR	=	0xb2b3
                           0000B7  1122 _RADIODATA0	=	0x00b7
                           0000B6  1123 _RADIODATA1	=	0x00b6
                           0000B5  1124 _RADIODATA2	=	0x00b5
                           0000B4  1125 _RADIODATA3	=	0x00b4
                           B4B5B6B7  1126 _RADIODATA	=	0xb4b5b6b7
                           0000BE  1127 _RADIOSTAT0	=	0x00be
                           0000BF  1128 _RADIOSTAT1	=	0x00bf
                           00BFBE  1129 _RADIOSTAT	=	0xbfbe
                           0000DF  1130 _SPCLKSRC	=	0x00df
                           0000DC  1131 _SPMODE	=	0x00dc
                           0000DE  1132 _SPSHREG	=	0x00de
                           0000DD  1133 _SPSTATUS	=	0x00dd
                           00009A  1134 _T0CLKSRC	=	0x009a
                           00009C  1135 _T0CNT0	=	0x009c
                           00009D  1136 _T0CNT1	=	0x009d
                           009D9C  1137 _T0CNT	=	0x9d9c
                           000099  1138 _T0MODE	=	0x0099
                           00009E  1139 _T0PERIOD0	=	0x009e
                           00009F  1140 _T0PERIOD1	=	0x009f
                           009F9E  1141 _T0PERIOD	=	0x9f9e
                           00009B  1142 _T0STATUS	=	0x009b
                           0000A2  1143 _T1CLKSRC	=	0x00a2
                           0000A4  1144 _T1CNT0	=	0x00a4
                           0000A5  1145 _T1CNT1	=	0x00a5
                           00A5A4  1146 _T1CNT	=	0xa5a4
                           0000A1  1147 _T1MODE	=	0x00a1
                           0000A6  1148 _T1PERIOD0	=	0x00a6
                           0000A7  1149 _T1PERIOD1	=	0x00a7
                           00A7A6  1150 _T1PERIOD	=	0xa7a6
                           0000A3  1151 _T1STATUS	=	0x00a3
                           0000AA  1152 _T2CLKSRC	=	0x00aa
                           0000AC  1153 _T2CNT0	=	0x00ac
                           0000AD  1154 _T2CNT1	=	0x00ad
                           00ADAC  1155 _T2CNT	=	0xadac
                           0000A9  1156 _T2MODE	=	0x00a9
                           0000AE  1157 _T2PERIOD0	=	0x00ae
                           0000AF  1158 _T2PERIOD1	=	0x00af
                           00AFAE  1159 _T2PERIOD	=	0xafae
                           0000AB  1160 _T2STATUS	=	0x00ab
                           0000E4  1161 _U0CTRL	=	0x00e4
                           0000E7  1162 _U0MODE	=	0x00e7
                           0000E6  1163 _U0SHREG	=	0x00e6
                           0000E5  1164 _U0STATUS	=	0x00e5
                           0000EC  1165 _U1CTRL	=	0x00ec
                           0000EF  1166 _U1MODE	=	0x00ef
                           0000EE  1167 _U1SHREG	=	0x00ee
                           0000ED  1168 _U1STATUS	=	0x00ed
                           0000DA  1169 _WDTCFG	=	0x00da
                           0000DB  1170 _WDTRESET	=	0x00db
                           0000F1  1171 _WTCFGA	=	0x00f1
                           0000F9  1172 _WTCFGB	=	0x00f9
                           0000F2  1173 _WTCNTA0	=	0x00f2
                           0000F3  1174 _WTCNTA1	=	0x00f3
                           00F3F2  1175 _WTCNTA	=	0xf3f2
                           0000FA  1176 _WTCNTB0	=	0x00fa
                           0000FB  1177 _WTCNTB1	=	0x00fb
                           00FBFA  1178 _WTCNTB	=	0xfbfa
                           0000EB  1179 _WTCNTR1	=	0x00eb
                           0000F4  1180 _WTEVTA0	=	0x00f4
                           0000F5  1181 _WTEVTA1	=	0x00f5
                           00F5F4  1182 _WTEVTA	=	0xf5f4
                           0000F6  1183 _WTEVTB0	=	0x00f6
                           0000F7  1184 _WTEVTB1	=	0x00f7
                           00F7F6  1185 _WTEVTB	=	0xf7f6
                           0000FC  1186 _WTEVTC0	=	0x00fc
                           0000FD  1187 _WTEVTC1	=	0x00fd
                           00FDFC  1188 _WTEVTC	=	0xfdfc
                           0000FE  1189 _WTEVTD0	=	0x00fe
                           0000FF  1190 _WTEVTD1	=	0x00ff
                           00FFFE  1191 _WTEVTD	=	0xfffe
                           0000E9  1192 _WTIRQEN	=	0x00e9
                           0000EA  1193 _WTSTAT	=	0x00ea
                                   1194 ;--------------------------------------------------------
                                   1195 ; special function bits
                                   1196 ;--------------------------------------------------------
                                   1197 	.area RSEG    (ABS,DATA)
      000000                       1198 	.org 0x0000
                           0000E0  1199 _ACC_0	=	0x00e0
                           0000E1  1200 _ACC_1	=	0x00e1
                           0000E2  1201 _ACC_2	=	0x00e2
                           0000E3  1202 _ACC_3	=	0x00e3
                           0000E4  1203 _ACC_4	=	0x00e4
                           0000E5  1204 _ACC_5	=	0x00e5
                           0000E6  1205 _ACC_6	=	0x00e6
                           0000E7  1206 _ACC_7	=	0x00e7
                           0000F0  1207 _B_0	=	0x00f0
                           0000F1  1208 _B_1	=	0x00f1
                           0000F2  1209 _B_2	=	0x00f2
                           0000F3  1210 _B_3	=	0x00f3
                           0000F4  1211 _B_4	=	0x00f4
                           0000F5  1212 _B_5	=	0x00f5
                           0000F6  1213 _B_6	=	0x00f6
                           0000F7  1214 _B_7	=	0x00f7
                           0000A0  1215 _E2IE_0	=	0x00a0
                           0000A1  1216 _E2IE_1	=	0x00a1
                           0000A2  1217 _E2IE_2	=	0x00a2
                           0000A3  1218 _E2IE_3	=	0x00a3
                           0000A4  1219 _E2IE_4	=	0x00a4
                           0000A5  1220 _E2IE_5	=	0x00a5
                           0000A6  1221 _E2IE_6	=	0x00a6
                           0000A7  1222 _E2IE_7	=	0x00a7
                           0000C0  1223 _E2IP_0	=	0x00c0
                           0000C1  1224 _E2IP_1	=	0x00c1
                           0000C2  1225 _E2IP_2	=	0x00c2
                           0000C3  1226 _E2IP_3	=	0x00c3
                           0000C4  1227 _E2IP_4	=	0x00c4
                           0000C5  1228 _E2IP_5	=	0x00c5
                           0000C6  1229 _E2IP_6	=	0x00c6
                           0000C7  1230 _E2IP_7	=	0x00c7
                           000098  1231 _EIE_0	=	0x0098
                           000099  1232 _EIE_1	=	0x0099
                           00009A  1233 _EIE_2	=	0x009a
                           00009B  1234 _EIE_3	=	0x009b
                           00009C  1235 _EIE_4	=	0x009c
                           00009D  1236 _EIE_5	=	0x009d
                           00009E  1237 _EIE_6	=	0x009e
                           00009F  1238 _EIE_7	=	0x009f
                           0000B0  1239 _EIP_0	=	0x00b0
                           0000B1  1240 _EIP_1	=	0x00b1
                           0000B2  1241 _EIP_2	=	0x00b2
                           0000B3  1242 _EIP_3	=	0x00b3
                           0000B4  1243 _EIP_4	=	0x00b4
                           0000B5  1244 _EIP_5	=	0x00b5
                           0000B6  1245 _EIP_6	=	0x00b6
                           0000B7  1246 _EIP_7	=	0x00b7
                           0000A8  1247 _IE_0	=	0x00a8
                           0000A9  1248 _IE_1	=	0x00a9
                           0000AA  1249 _IE_2	=	0x00aa
                           0000AB  1250 _IE_3	=	0x00ab
                           0000AC  1251 _IE_4	=	0x00ac
                           0000AD  1252 _IE_5	=	0x00ad
                           0000AE  1253 _IE_6	=	0x00ae
                           0000AF  1254 _IE_7	=	0x00af
                           0000AF  1255 _EA	=	0x00af
                           0000B8  1256 _IP_0	=	0x00b8
                           0000B9  1257 _IP_1	=	0x00b9
                           0000BA  1258 _IP_2	=	0x00ba
                           0000BB  1259 _IP_3	=	0x00bb
                           0000BC  1260 _IP_4	=	0x00bc
                           0000BD  1261 _IP_5	=	0x00bd
                           0000BE  1262 _IP_6	=	0x00be
                           0000BF  1263 _IP_7	=	0x00bf
                           0000D0  1264 _P	=	0x00d0
                           0000D1  1265 _F1	=	0x00d1
                           0000D2  1266 _OV	=	0x00d2
                           0000D3  1267 _RS0	=	0x00d3
                           0000D4  1268 _RS1	=	0x00d4
                           0000D5  1269 _F0	=	0x00d5
                           0000D6  1270 _AC	=	0x00d6
                           0000D7  1271 _CY	=	0x00d7
                           0000C8  1272 _PINA_0	=	0x00c8
                           0000C9  1273 _PINA_1	=	0x00c9
                           0000CA  1274 _PINA_2	=	0x00ca
                           0000CB  1275 _PINA_3	=	0x00cb
                           0000CC  1276 _PINA_4	=	0x00cc
                           0000CD  1277 _PINA_5	=	0x00cd
                           0000CE  1278 _PINA_6	=	0x00ce
                           0000CF  1279 _PINA_7	=	0x00cf
                           0000E8  1280 _PINB_0	=	0x00e8
                           0000E9  1281 _PINB_1	=	0x00e9
                           0000EA  1282 _PINB_2	=	0x00ea
                           0000EB  1283 _PINB_3	=	0x00eb
                           0000EC  1284 _PINB_4	=	0x00ec
                           0000ED  1285 _PINB_5	=	0x00ed
                           0000EE  1286 _PINB_6	=	0x00ee
                           0000EF  1287 _PINB_7	=	0x00ef
                           0000F8  1288 _PINC_0	=	0x00f8
                           0000F9  1289 _PINC_1	=	0x00f9
                           0000FA  1290 _PINC_2	=	0x00fa
                           0000FB  1291 _PINC_3	=	0x00fb
                           0000FC  1292 _PINC_4	=	0x00fc
                           0000FD  1293 _PINC_5	=	0x00fd
                           0000FE  1294 _PINC_6	=	0x00fe
                           0000FF  1295 _PINC_7	=	0x00ff
                           000080  1296 _PORTA_0	=	0x0080
                           000081  1297 _PORTA_1	=	0x0081
                           000082  1298 _PORTA_2	=	0x0082
                           000083  1299 _PORTA_3	=	0x0083
                           000084  1300 _PORTA_4	=	0x0084
                           000085  1301 _PORTA_5	=	0x0085
                           000086  1302 _PORTA_6	=	0x0086
                           000087  1303 _PORTA_7	=	0x0087
                           000088  1304 _PORTB_0	=	0x0088
                           000089  1305 _PORTB_1	=	0x0089
                           00008A  1306 _PORTB_2	=	0x008a
                           00008B  1307 _PORTB_3	=	0x008b
                           00008C  1308 _PORTB_4	=	0x008c
                           00008D  1309 _PORTB_5	=	0x008d
                           00008E  1310 _PORTB_6	=	0x008e
                           00008F  1311 _PORTB_7	=	0x008f
                           000090  1312 _PORTC_0	=	0x0090
                           000091  1313 _PORTC_1	=	0x0091
                           000092  1314 _PORTC_2	=	0x0092
                           000093  1315 _PORTC_3	=	0x0093
                           000094  1316 _PORTC_4	=	0x0094
                           000095  1317 _PORTC_5	=	0x0095
                           000096  1318 _PORTC_6	=	0x0096
                           000097  1319 _PORTC_7	=	0x0097
                                   1320 ;--------------------------------------------------------
                                   1321 ; overlayable register banks
                                   1322 ;--------------------------------------------------------
                                   1323 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                       1324 	.ds 8
                                   1325 ;--------------------------------------------------------
                                   1326 ; overlayable bit register bank
                                   1327 ;--------------------------------------------------------
                                   1328 	.area BIT_BANK	(REL,OVR,DATA)
      000021                       1329 bits:
      000021                       1330 	.ds 1
                           008000  1331 	b0 = bits[0]
                           008100  1332 	b1 = bits[1]
                           008200  1333 	b2 = bits[2]
                           008300  1334 	b3 = bits[3]
                           008400  1335 	b4 = bits[4]
                           008500  1336 	b5 = bits[5]
                           008600  1337 	b6 = bits[6]
                           008700  1338 	b7 = bits[7]
                                   1339 ;--------------------------------------------------------
                                   1340 ; internal ram data
                                   1341 ;--------------------------------------------------------
                                   1342 	.area DSEG    (DATA)
      000008                       1343 _axradio_mode::
      000008                       1344 	.ds 1
      000009                       1345 _axradio_trxstate::
      000009                       1346 	.ds 1
      00000A                       1347 _aligned_alloc_PARM_2:
      00000A                       1348 	.ds 2
      00000C                       1349 _axradio_init_i_1_657:
      00000C                       1350 	.ds 1
      00000D                       1351 _axradio_init_vcoisave_3_687:
      00000D                       1352 	.ds 1
      00000E                       1353 _axradio_init_j_3_687:
      00000E                       1354 	.ds 1
      00000F                       1355 _axradio_init_f_5_690:
      00000F                       1356 	.ds 4
      000013                       1357 _axradio_init_sloc0_1_0:
      000013                       1358 	.ds 2
      000015                       1359 _axradio_transmit_PARM_2:
      000015                       1360 	.ds 3
      000018                       1361 _axradio_transmit_PARM_3:
      000018                       1362 	.ds 2
                                   1363 ;--------------------------------------------------------
                                   1364 ; overlayable items in internal ram 
                                   1365 ;--------------------------------------------------------
                                   1366 	.area	OSEG    (OVR,DATA)
                                   1367 	.area	OSEG    (OVR,DATA)
      00002E                       1368 _axradio_set_channel_rng_1_766:
      00002E                       1369 	.ds 1
                                   1370 	.area	OSEG    (OVR,DATA)
                                   1371 	.area	OSEG    (OVR,DATA)
                                   1372 ;--------------------------------------------------------
                                   1373 ; indirectly addressable internal ram data
                                   1374 ;--------------------------------------------------------
                                   1375 	.area ISEG    (DATA)
                                   1376 ;--------------------------------------------------------
                                   1377 ; absolute internal ram data
                                   1378 ;--------------------------------------------------------
                                   1379 	.area IABS    (ABS,DATA)
                                   1380 	.area IABS    (ABS,DATA)
                                   1381 ;--------------------------------------------------------
                                   1382 ; bit data
                                   1383 ;--------------------------------------------------------
                                   1384 	.area BSEG    (BIT)
      000000                       1385 _axradio_timer_callback_sloc0_1_0:
      000000                       1386 	.ds 1
                                   1387 ;--------------------------------------------------------
                                   1388 ; paged external ram data
                                   1389 ;--------------------------------------------------------
                                   1390 	.area PSEG    (PAG,XDATA)
                                   1391 ;--------------------------------------------------------
                                   1392 ; external ram data
                                   1393 ;--------------------------------------------------------
                                   1394 	.area XSEG    (XDATA)
                           007020  1395 _ADCCH0VAL0	=	0x7020
                           007021  1396 _ADCCH0VAL1	=	0x7021
                           007020  1397 _ADCCH0VAL	=	0x7020
                           007022  1398 _ADCCH1VAL0	=	0x7022
                           007023  1399 _ADCCH1VAL1	=	0x7023
                           007022  1400 _ADCCH1VAL	=	0x7022
                           007024  1401 _ADCCH2VAL0	=	0x7024
                           007025  1402 _ADCCH2VAL1	=	0x7025
                           007024  1403 _ADCCH2VAL	=	0x7024
                           007026  1404 _ADCCH3VAL0	=	0x7026
                           007027  1405 _ADCCH3VAL1	=	0x7027
                           007026  1406 _ADCCH3VAL	=	0x7026
                           007028  1407 _ADCTUNE0	=	0x7028
                           007029  1408 _ADCTUNE1	=	0x7029
                           00702A  1409 _ADCTUNE2	=	0x702a
                           007010  1410 _DMA0ADDR0	=	0x7010
                           007011  1411 _DMA0ADDR1	=	0x7011
                           007010  1412 _DMA0ADDR	=	0x7010
                           007014  1413 _DMA0CONFIG	=	0x7014
                           007012  1414 _DMA1ADDR0	=	0x7012
                           007013  1415 _DMA1ADDR1	=	0x7013
                           007012  1416 _DMA1ADDR	=	0x7012
                           007015  1417 _DMA1CONFIG	=	0x7015
                           007070  1418 _FRCOSCCONFIG	=	0x7070
                           007071  1419 _FRCOSCCTRL	=	0x7071
                           007076  1420 _FRCOSCFREQ0	=	0x7076
                           007077  1421 _FRCOSCFREQ1	=	0x7077
                           007076  1422 _FRCOSCFREQ	=	0x7076
                           007072  1423 _FRCOSCKFILT0	=	0x7072
                           007073  1424 _FRCOSCKFILT1	=	0x7073
                           007072  1425 _FRCOSCKFILT	=	0x7072
                           007078  1426 _FRCOSCPER0	=	0x7078
                           007079  1427 _FRCOSCPER1	=	0x7079
                           007078  1428 _FRCOSCPER	=	0x7078
                           007074  1429 _FRCOSCREF0	=	0x7074
                           007075  1430 _FRCOSCREF1	=	0x7075
                           007074  1431 _FRCOSCREF	=	0x7074
                           007007  1432 _ANALOGA	=	0x7007
                           00700C  1433 _GPIOENABLE	=	0x700c
                           007003  1434 _EXTIRQ	=	0x7003
                           007000  1435 _INTCHGA	=	0x7000
                           007001  1436 _INTCHGB	=	0x7001
                           007002  1437 _INTCHGC	=	0x7002
                           007008  1438 _PALTA	=	0x7008
                           007009  1439 _PALTB	=	0x7009
                           00700A  1440 _PALTC	=	0x700a
                           007046  1441 _PALTRADIO	=	0x7046
                           007004  1442 _PINCHGA	=	0x7004
                           007005  1443 _PINCHGB	=	0x7005
                           007006  1444 _PINCHGC	=	0x7006
                           00700B  1445 _PINSEL	=	0x700b
                           007060  1446 _LPOSCCONFIG	=	0x7060
                           007066  1447 _LPOSCFREQ0	=	0x7066
                           007067  1448 _LPOSCFREQ1	=	0x7067
                           007066  1449 _LPOSCFREQ	=	0x7066
                           007062  1450 _LPOSCKFILT0	=	0x7062
                           007063  1451 _LPOSCKFILT1	=	0x7063
                           007062  1452 _LPOSCKFILT	=	0x7062
                           007068  1453 _LPOSCPER0	=	0x7068
                           007069  1454 _LPOSCPER1	=	0x7069
                           007068  1455 _LPOSCPER	=	0x7068
                           007064  1456 _LPOSCREF0	=	0x7064
                           007065  1457 _LPOSCREF1	=	0x7065
                           007064  1458 _LPOSCREF	=	0x7064
                           007054  1459 _LPXOSCGM	=	0x7054
                           007F01  1460 _MISCCTRL	=	0x7f01
                           007053  1461 _OSCCALIB	=	0x7053
                           007050  1462 _OSCFORCERUN	=	0x7050
                           007052  1463 _OSCREADY	=	0x7052
                           007051  1464 _OSCRUN	=	0x7051
                           007040  1465 _RADIOFDATAADDR0	=	0x7040
                           007041  1466 _RADIOFDATAADDR1	=	0x7041
                           007040  1467 _RADIOFDATAADDR	=	0x7040
                           007042  1468 _RADIOFSTATADDR0	=	0x7042
                           007043  1469 _RADIOFSTATADDR1	=	0x7043
                           007042  1470 _RADIOFSTATADDR	=	0x7042
                           007044  1471 _RADIOMUX	=	0x7044
                           007084  1472 _SCRATCH0	=	0x7084
                           007085  1473 _SCRATCH1	=	0x7085
                           007086  1474 _SCRATCH2	=	0x7086
                           007087  1475 _SCRATCH3	=	0x7087
                           007F00  1476 _SILICONREV	=	0x7f00
                           007F19  1477 _XTALAMPL	=	0x7f19
                           007F18  1478 _XTALOSC	=	0x7f18
                           007F1A  1479 _XTALREADY	=	0x7f1a
                           004114  1480 _AX5043_AFSKCTRL	=	0x4114
                           004113  1481 _AX5043_AFSKMARK0	=	0x4113
                           004112  1482 _AX5043_AFSKMARK1	=	0x4112
                           004111  1483 _AX5043_AFSKSPACE0	=	0x4111
                           004110  1484 _AX5043_AFSKSPACE1	=	0x4110
                           004043  1485 _AX5043_AGCCOUNTER	=	0x4043
                           004115  1486 _AX5043_AMPLFILTER	=	0x4115
                           004189  1487 _AX5043_BBOFFSCAP	=	0x4189
                           004188  1488 _AX5043_BBTUNE	=	0x4188
                           004041  1489 _AX5043_BGNDRSSI	=	0x4041
                           00422E  1490 _AX5043_BGNDRSSIGAIN	=	0x422e
                           00422F  1491 _AX5043_BGNDRSSITHR	=	0x422f
                           004017  1492 _AX5043_CRCINIT0	=	0x4017
                           004016  1493 _AX5043_CRCINIT1	=	0x4016
                           004015  1494 _AX5043_CRCINIT2	=	0x4015
                           004014  1495 _AX5043_CRCINIT3	=	0x4014
                           004332  1496 _AX5043_DACCONFIG	=	0x4332
                           004331  1497 _AX5043_DACVALUE0	=	0x4331
                           004330  1498 _AX5043_DACVALUE1	=	0x4330
                           004102  1499 _AX5043_DECIMATION	=	0x4102
                           004042  1500 _AX5043_DIVERSITY	=	0x4042
                           004011  1501 _AX5043_ENCODING	=	0x4011
                           004018  1502 _AX5043_FEC	=	0x4018
                           00401A  1503 _AX5043_FECSTATUS	=	0x401a
                           004019  1504 _AX5043_FECSYNC	=	0x4019
                           00402B  1505 _AX5043_FIFOCOUNT0	=	0x402b
                           00402A  1506 _AX5043_FIFOCOUNT1	=	0x402a
                           004029  1507 _AX5043_FIFODATA	=	0x4029
                           00402D  1508 _AX5043_FIFOFREE0	=	0x402d
                           00402C  1509 _AX5043_FIFOFREE1	=	0x402c
                           004028  1510 _AX5043_FIFOSTAT	=	0x4028
                           00402F  1511 _AX5043_FIFOTHRESH0	=	0x402f
                           00402E  1512 _AX5043_FIFOTHRESH1	=	0x402e
                           004012  1513 _AX5043_FRAMING	=	0x4012
                           004037  1514 _AX5043_FREQA0	=	0x4037
                           004036  1515 _AX5043_FREQA1	=	0x4036
                           004035  1516 _AX5043_FREQA2	=	0x4035
                           004034  1517 _AX5043_FREQA3	=	0x4034
                           00403F  1518 _AX5043_FREQB0	=	0x403f
                           00403E  1519 _AX5043_FREQB1	=	0x403e
                           00403D  1520 _AX5043_FREQB2	=	0x403d
                           00403C  1521 _AX5043_FREQB3	=	0x403c
                           004163  1522 _AX5043_FSKDEV0	=	0x4163
                           004162  1523 _AX5043_FSKDEV1	=	0x4162
                           004161  1524 _AX5043_FSKDEV2	=	0x4161
                           00410D  1525 _AX5043_FSKDMAX0	=	0x410d
                           00410C  1526 _AX5043_FSKDMAX1	=	0x410c
                           00410F  1527 _AX5043_FSKDMIN0	=	0x410f
                           00410E  1528 _AX5043_FSKDMIN1	=	0x410e
                           004309  1529 _AX5043_GPADC13VALUE0	=	0x4309
                           004308  1530 _AX5043_GPADC13VALUE1	=	0x4308
                           004300  1531 _AX5043_GPADCCTRL	=	0x4300
                           004301  1532 _AX5043_GPADCPERIOD	=	0x4301
                           004101  1533 _AX5043_IFFREQ0	=	0x4101
                           004100  1534 _AX5043_IFFREQ1	=	0x4100
                           00400B  1535 _AX5043_IRQINVERSION0	=	0x400b
                           00400A  1536 _AX5043_IRQINVERSION1	=	0x400a
                           004007  1537 _AX5043_IRQMASK0	=	0x4007
                           004006  1538 _AX5043_IRQMASK1	=	0x4006
                           00400D  1539 _AX5043_IRQREQUEST0	=	0x400d
                           00400C  1540 _AX5043_IRQREQUEST1	=	0x400c
                           004310  1541 _AX5043_LPOSCCONFIG	=	0x4310
                           004317  1542 _AX5043_LPOSCFREQ0	=	0x4317
                           004316  1543 _AX5043_LPOSCFREQ1	=	0x4316
                           004313  1544 _AX5043_LPOSCKFILT0	=	0x4313
                           004312  1545 _AX5043_LPOSCKFILT1	=	0x4312
                           004319  1546 _AX5043_LPOSCPER0	=	0x4319
                           004318  1547 _AX5043_LPOSCPER1	=	0x4318
                           004315  1548 _AX5043_LPOSCREF0	=	0x4315
                           004314  1549 _AX5043_LPOSCREF1	=	0x4314
                           004311  1550 _AX5043_LPOSCSTATUS	=	0x4311
                           004214  1551 _AX5043_MATCH0LEN	=	0x4214
                           004216  1552 _AX5043_MATCH0MAX	=	0x4216
                           004215  1553 _AX5043_MATCH0MIN	=	0x4215
                           004213  1554 _AX5043_MATCH0PAT0	=	0x4213
                           004212  1555 _AX5043_MATCH0PAT1	=	0x4212
                           004211  1556 _AX5043_MATCH0PAT2	=	0x4211
                           004210  1557 _AX5043_MATCH0PAT3	=	0x4210
                           00421C  1558 _AX5043_MATCH1LEN	=	0x421c
                           00421E  1559 _AX5043_MATCH1MAX	=	0x421e
                           00421D  1560 _AX5043_MATCH1MIN	=	0x421d
                           004219  1561 _AX5043_MATCH1PAT0	=	0x4219
                           004218  1562 _AX5043_MATCH1PAT1	=	0x4218
                           004108  1563 _AX5043_MAXDROFFSET0	=	0x4108
                           004107  1564 _AX5043_MAXDROFFSET1	=	0x4107
                           004106  1565 _AX5043_MAXDROFFSET2	=	0x4106
                           00410B  1566 _AX5043_MAXRFOFFSET0	=	0x410b
                           00410A  1567 _AX5043_MAXRFOFFSET1	=	0x410a
                           004109  1568 _AX5043_MAXRFOFFSET2	=	0x4109
                           004164  1569 _AX5043_MODCFGA	=	0x4164
                           004160  1570 _AX5043_MODCFGF	=	0x4160
                           004F5F  1571 _AX5043_MODCFGP	=	0x4f5f
                           004010  1572 _AX5043_MODULATION	=	0x4010
                           004025  1573 _AX5043_PINFUNCANTSEL	=	0x4025
                           004023  1574 _AX5043_PINFUNCDATA	=	0x4023
                           004022  1575 _AX5043_PINFUNCDCLK	=	0x4022
                           004024  1576 _AX5043_PINFUNCIRQ	=	0x4024
                           004026  1577 _AX5043_PINFUNCPWRAMP	=	0x4026
                           004021  1578 _AX5043_PINFUNCSYSCLK	=	0x4021
                           004020  1579 _AX5043_PINSTATE	=	0x4020
                           004233  1580 _AX5043_PKTACCEPTFLAGS	=	0x4233
                           004230  1581 _AX5043_PKTCHUNKSIZE	=	0x4230
                           004231  1582 _AX5043_PKTMISCFLAGS	=	0x4231
                           004232  1583 _AX5043_PKTSTOREFLAGS	=	0x4232
                           004031  1584 _AX5043_PLLCPI	=	0x4031
                           004039  1585 _AX5043_PLLCPIBOOST	=	0x4039
                           004182  1586 _AX5043_PLLLOCKDET	=	0x4182
                           004030  1587 _AX5043_PLLLOOP	=	0x4030
                           004038  1588 _AX5043_PLLLOOPBOOST	=	0x4038
                           004033  1589 _AX5043_PLLRANGINGA	=	0x4033
                           00403B  1590 _AX5043_PLLRANGINGB	=	0x403b
                           004183  1591 _AX5043_PLLRNGCLK	=	0x4183
                           004032  1592 _AX5043_PLLVCODIV	=	0x4032
                           004180  1593 _AX5043_PLLVCOI	=	0x4180
                           004181  1594 _AX5043_PLLVCOIR	=	0x4181
                           004F08  1595 _AX5043_POWCTRL1	=	0x4f08
                           004005  1596 _AX5043_POWIRQMASK	=	0x4005
                           004003  1597 _AX5043_POWSTAT	=	0x4003
                           004004  1598 _AX5043_POWSTICKYSTAT	=	0x4004
                           004027  1599 _AX5043_PWRAMP	=	0x4027
                           004002  1600 _AX5043_PWRMODE	=	0x4002
                           004009  1601 _AX5043_RADIOEVENTMASK0	=	0x4009
                           004008  1602 _AX5043_RADIOEVENTMASK1	=	0x4008
                           00400F  1603 _AX5043_RADIOEVENTREQ0	=	0x400f
                           00400E  1604 _AX5043_RADIOEVENTREQ1	=	0x400e
                           00401C  1605 _AX5043_RADIOSTATE	=	0x401c
                           004F0D  1606 _AX5043_REF	=	0x4f0d
                           004040  1607 _AX5043_RSSI	=	0x4040
                           00422D  1608 _AX5043_RSSIABSTHR	=	0x422d
                           00422C  1609 _AX5043_RSSIREFERENCE	=	0x422c
                           004105  1610 _AX5043_RXDATARATE0	=	0x4105
                           004104  1611 _AX5043_RXDATARATE1	=	0x4104
                           004103  1612 _AX5043_RXDATARATE2	=	0x4103
                           004001  1613 _AX5043_SCRATCH	=	0x4001
                           004000  1614 _AX5043_SILICONREVISION	=	0x4000
                           00405B  1615 _AX5043_TIMER0	=	0x405b
                           00405A  1616 _AX5043_TIMER1	=	0x405a
                           004059  1617 _AX5043_TIMER2	=	0x4059
                           004227  1618 _AX5043_TMGRXAGC	=	0x4227
                           004223  1619 _AX5043_TMGRXBOOST	=	0x4223
                           004226  1620 _AX5043_TMGRXCOARSEAGC	=	0x4226
                           004225  1621 _AX5043_TMGRXOFFSACQ	=	0x4225
                           004229  1622 _AX5043_TMGRXPREAMBLE1	=	0x4229
                           00422A  1623 _AX5043_TMGRXPREAMBLE2	=	0x422a
                           00422B  1624 _AX5043_TMGRXPREAMBLE3	=	0x422b
                           004228  1625 _AX5043_TMGRXRSSI	=	0x4228
                           004224  1626 _AX5043_TMGRXSETTLE	=	0x4224
                           004220  1627 _AX5043_TMGTXBOOST	=	0x4220
                           004221  1628 _AX5043_TMGTXSETTLE	=	0x4221
                           004055  1629 _AX5043_TRKAFSKDEMOD0	=	0x4055
                           004054  1630 _AX5043_TRKAFSKDEMOD1	=	0x4054
                           004049  1631 _AX5043_TRKAMPLITUDE0	=	0x4049
                           004048  1632 _AX5043_TRKAMPLITUDE1	=	0x4048
                           004047  1633 _AX5043_TRKDATARATE0	=	0x4047
                           004046  1634 _AX5043_TRKDATARATE1	=	0x4046
                           004045  1635 _AX5043_TRKDATARATE2	=	0x4045
                           004051  1636 _AX5043_TRKFREQ0	=	0x4051
                           004050  1637 _AX5043_TRKFREQ1	=	0x4050
                           004053  1638 _AX5043_TRKFSKDEMOD0	=	0x4053
                           004052  1639 _AX5043_TRKFSKDEMOD1	=	0x4052
                           00404B  1640 _AX5043_TRKPHASE0	=	0x404b
                           00404A  1641 _AX5043_TRKPHASE1	=	0x404a
                           00404F  1642 _AX5043_TRKRFFREQ0	=	0x404f
                           00404E  1643 _AX5043_TRKRFFREQ1	=	0x404e
                           00404D  1644 _AX5043_TRKRFFREQ2	=	0x404d
                           004169  1645 _AX5043_TXPWRCOEFFA0	=	0x4169
                           004168  1646 _AX5043_TXPWRCOEFFA1	=	0x4168
                           00416B  1647 _AX5043_TXPWRCOEFFB0	=	0x416b
                           00416A  1648 _AX5043_TXPWRCOEFFB1	=	0x416a
                           00416D  1649 _AX5043_TXPWRCOEFFC0	=	0x416d
                           00416C  1650 _AX5043_TXPWRCOEFFC1	=	0x416c
                           00416F  1651 _AX5043_TXPWRCOEFFD0	=	0x416f
                           00416E  1652 _AX5043_TXPWRCOEFFD1	=	0x416e
                           004171  1653 _AX5043_TXPWRCOEFFE0	=	0x4171
                           004170  1654 _AX5043_TXPWRCOEFFE1	=	0x4170
                           004167  1655 _AX5043_TXRATE0	=	0x4167
                           004166  1656 _AX5043_TXRATE1	=	0x4166
                           004165  1657 _AX5043_TXRATE2	=	0x4165
                           00406B  1658 _AX5043_WAKEUP0	=	0x406b
                           00406A  1659 _AX5043_WAKEUP1	=	0x406a
                           00406D  1660 _AX5043_WAKEUPFREQ0	=	0x406d
                           00406C  1661 _AX5043_WAKEUPFREQ1	=	0x406c
                           004069  1662 _AX5043_WAKEUPTIMER0	=	0x4069
                           004068  1663 _AX5043_WAKEUPTIMER1	=	0x4068
                           00406E  1664 _AX5043_WAKEUPXOEARLY	=	0x406e
                           004F11  1665 _AX5043_XTALAMPL	=	0x4f11
                           004184  1666 _AX5043_XTALCAP	=	0x4184
                           004F10  1667 _AX5043_XTALOSC	=	0x4f10
                           00401D  1668 _AX5043_XTALSTATUS	=	0x401d
                           004F00  1669 _AX5043_0xF00	=	0x4f00
                           004F0C  1670 _AX5043_0xF0C	=	0x4f0c
                           004F18  1671 _AX5043_0xF18	=	0x4f18
                           004F1C  1672 _AX5043_0xF1C	=	0x4f1c
                           004F21  1673 _AX5043_0xF21	=	0x4f21
                           004F22  1674 _AX5043_0xF22	=	0x4f22
                           004F23  1675 _AX5043_0xF23	=	0x4f23
                           004F26  1676 _AX5043_0xF26	=	0x4f26
                           004F30  1677 _AX5043_0xF30	=	0x4f30
                           004F31  1678 _AX5043_0xF31	=	0x4f31
                           004F32  1679 _AX5043_0xF32	=	0x4f32
                           004F33  1680 _AX5043_0xF33	=	0x4f33
                           004F34  1681 _AX5043_0xF34	=	0x4f34
                           004F35  1682 _AX5043_0xF35	=	0x4f35
                           004F44  1683 _AX5043_0xF44	=	0x4f44
                           004122  1684 _AX5043_AGCAHYST0	=	0x4122
                           004132  1685 _AX5043_AGCAHYST1	=	0x4132
                           004142  1686 _AX5043_AGCAHYST2	=	0x4142
                           004152  1687 _AX5043_AGCAHYST3	=	0x4152
                           004120  1688 _AX5043_AGCGAIN0	=	0x4120
                           004130  1689 _AX5043_AGCGAIN1	=	0x4130
                           004140  1690 _AX5043_AGCGAIN2	=	0x4140
                           004150  1691 _AX5043_AGCGAIN3	=	0x4150
                           004123  1692 _AX5043_AGCMINMAX0	=	0x4123
                           004133  1693 _AX5043_AGCMINMAX1	=	0x4133
                           004143  1694 _AX5043_AGCMINMAX2	=	0x4143
                           004153  1695 _AX5043_AGCMINMAX3	=	0x4153
                           004121  1696 _AX5043_AGCTARGET0	=	0x4121
                           004131  1697 _AX5043_AGCTARGET1	=	0x4131
                           004141  1698 _AX5043_AGCTARGET2	=	0x4141
                           004151  1699 _AX5043_AGCTARGET3	=	0x4151
                           00412B  1700 _AX5043_AMPLITUDEGAIN0	=	0x412b
                           00413B  1701 _AX5043_AMPLITUDEGAIN1	=	0x413b
                           00414B  1702 _AX5043_AMPLITUDEGAIN2	=	0x414b
                           00415B  1703 _AX5043_AMPLITUDEGAIN3	=	0x415b
                           00412F  1704 _AX5043_BBOFFSRES0	=	0x412f
                           00413F  1705 _AX5043_BBOFFSRES1	=	0x413f
                           00414F  1706 _AX5043_BBOFFSRES2	=	0x414f
                           00415F  1707 _AX5043_BBOFFSRES3	=	0x415f
                           004125  1708 _AX5043_DRGAIN0	=	0x4125
                           004135  1709 _AX5043_DRGAIN1	=	0x4135
                           004145  1710 _AX5043_DRGAIN2	=	0x4145
                           004155  1711 _AX5043_DRGAIN3	=	0x4155
                           00412E  1712 _AX5043_FOURFSK0	=	0x412e
                           00413E  1713 _AX5043_FOURFSK1	=	0x413e
                           00414E  1714 _AX5043_FOURFSK2	=	0x414e
                           00415E  1715 _AX5043_FOURFSK3	=	0x415e
                           00412D  1716 _AX5043_FREQDEV00	=	0x412d
                           00413D  1717 _AX5043_FREQDEV01	=	0x413d
                           00414D  1718 _AX5043_FREQDEV02	=	0x414d
                           00415D  1719 _AX5043_FREQDEV03	=	0x415d
                           00412C  1720 _AX5043_FREQDEV10	=	0x412c
                           00413C  1721 _AX5043_FREQDEV11	=	0x413c
                           00414C  1722 _AX5043_FREQDEV12	=	0x414c
                           00415C  1723 _AX5043_FREQDEV13	=	0x415c
                           004127  1724 _AX5043_FREQUENCYGAINA0	=	0x4127
                           004137  1725 _AX5043_FREQUENCYGAINA1	=	0x4137
                           004147  1726 _AX5043_FREQUENCYGAINA2	=	0x4147
                           004157  1727 _AX5043_FREQUENCYGAINA3	=	0x4157
                           004128  1728 _AX5043_FREQUENCYGAINB0	=	0x4128
                           004138  1729 _AX5043_FREQUENCYGAINB1	=	0x4138
                           004148  1730 _AX5043_FREQUENCYGAINB2	=	0x4148
                           004158  1731 _AX5043_FREQUENCYGAINB3	=	0x4158
                           004129  1732 _AX5043_FREQUENCYGAINC0	=	0x4129
                           004139  1733 _AX5043_FREQUENCYGAINC1	=	0x4139
                           004149  1734 _AX5043_FREQUENCYGAINC2	=	0x4149
                           004159  1735 _AX5043_FREQUENCYGAINC3	=	0x4159
                           00412A  1736 _AX5043_FREQUENCYGAIND0	=	0x412a
                           00413A  1737 _AX5043_FREQUENCYGAIND1	=	0x413a
                           00414A  1738 _AX5043_FREQUENCYGAIND2	=	0x414a
                           00415A  1739 _AX5043_FREQUENCYGAIND3	=	0x415a
                           004116  1740 _AX5043_FREQUENCYLEAK	=	0x4116
                           004126  1741 _AX5043_PHASEGAIN0	=	0x4126
                           004136  1742 _AX5043_PHASEGAIN1	=	0x4136
                           004146  1743 _AX5043_PHASEGAIN2	=	0x4146
                           004156  1744 _AX5043_PHASEGAIN3	=	0x4156
                           004207  1745 _AX5043_PKTADDR0	=	0x4207
                           004206  1746 _AX5043_PKTADDR1	=	0x4206
                           004205  1747 _AX5043_PKTADDR2	=	0x4205
                           004204  1748 _AX5043_PKTADDR3	=	0x4204
                           004200  1749 _AX5043_PKTADDRCFG	=	0x4200
                           00420B  1750 _AX5043_PKTADDRMASK0	=	0x420b
                           00420A  1751 _AX5043_PKTADDRMASK1	=	0x420a
                           004209  1752 _AX5043_PKTADDRMASK2	=	0x4209
                           004208  1753 _AX5043_PKTADDRMASK3	=	0x4208
                           004201  1754 _AX5043_PKTLENCFG	=	0x4201
                           004202  1755 _AX5043_PKTLENOFFSET	=	0x4202
                           004203  1756 _AX5043_PKTMAXLEN	=	0x4203
                           004118  1757 _AX5043_RXPARAMCURSET	=	0x4118
                           004117  1758 _AX5043_RXPARAMSETS	=	0x4117
                           004124  1759 _AX5043_TIMEGAIN0	=	0x4124
                           004134  1760 _AX5043_TIMEGAIN1	=	0x4134
                           004144  1761 _AX5043_TIMEGAIN2	=	0x4144
                           004154  1762 _AX5043_TIMEGAIN3	=	0x4154
                           005114  1763 _AX5043_AFSKCTRLNB	=	0x5114
                           005113  1764 _AX5043_AFSKMARK0NB	=	0x5113
                           005112  1765 _AX5043_AFSKMARK1NB	=	0x5112
                           005111  1766 _AX5043_AFSKSPACE0NB	=	0x5111
                           005110  1767 _AX5043_AFSKSPACE1NB	=	0x5110
                           005043  1768 _AX5043_AGCCOUNTERNB	=	0x5043
                           005115  1769 _AX5043_AMPLFILTERNB	=	0x5115
                           005189  1770 _AX5043_BBOFFSCAPNB	=	0x5189
                           005188  1771 _AX5043_BBTUNENB	=	0x5188
                           005041  1772 _AX5043_BGNDRSSINB	=	0x5041
                           00522E  1773 _AX5043_BGNDRSSIGAINNB	=	0x522e
                           00522F  1774 _AX5043_BGNDRSSITHRNB	=	0x522f
                           005017  1775 _AX5043_CRCINIT0NB	=	0x5017
                           005016  1776 _AX5043_CRCINIT1NB	=	0x5016
                           005015  1777 _AX5043_CRCINIT2NB	=	0x5015
                           005014  1778 _AX5043_CRCINIT3NB	=	0x5014
                           005332  1779 _AX5043_DACCONFIGNB	=	0x5332
                           005331  1780 _AX5043_DACVALUE0NB	=	0x5331
                           005330  1781 _AX5043_DACVALUE1NB	=	0x5330
                           005102  1782 _AX5043_DECIMATIONNB	=	0x5102
                           005042  1783 _AX5043_DIVERSITYNB	=	0x5042
                           005011  1784 _AX5043_ENCODINGNB	=	0x5011
                           005018  1785 _AX5043_FECNB	=	0x5018
                           00501A  1786 _AX5043_FECSTATUSNB	=	0x501a
                           005019  1787 _AX5043_FECSYNCNB	=	0x5019
                           00502B  1788 _AX5043_FIFOCOUNT0NB	=	0x502b
                           00502A  1789 _AX5043_FIFOCOUNT1NB	=	0x502a
                           005029  1790 _AX5043_FIFODATANB	=	0x5029
                           00502D  1791 _AX5043_FIFOFREE0NB	=	0x502d
                           00502C  1792 _AX5043_FIFOFREE1NB	=	0x502c
                           005028  1793 _AX5043_FIFOSTATNB	=	0x5028
                           00502F  1794 _AX5043_FIFOTHRESH0NB	=	0x502f
                           00502E  1795 _AX5043_FIFOTHRESH1NB	=	0x502e
                           005012  1796 _AX5043_FRAMINGNB	=	0x5012
                           005037  1797 _AX5043_FREQA0NB	=	0x5037
                           005036  1798 _AX5043_FREQA1NB	=	0x5036
                           005035  1799 _AX5043_FREQA2NB	=	0x5035
                           005034  1800 _AX5043_FREQA3NB	=	0x5034
                           00503F  1801 _AX5043_FREQB0NB	=	0x503f
                           00503E  1802 _AX5043_FREQB1NB	=	0x503e
                           00503D  1803 _AX5043_FREQB2NB	=	0x503d
                           00503C  1804 _AX5043_FREQB3NB	=	0x503c
                           005163  1805 _AX5043_FSKDEV0NB	=	0x5163
                           005162  1806 _AX5043_FSKDEV1NB	=	0x5162
                           005161  1807 _AX5043_FSKDEV2NB	=	0x5161
                           00510D  1808 _AX5043_FSKDMAX0NB	=	0x510d
                           00510C  1809 _AX5043_FSKDMAX1NB	=	0x510c
                           00510F  1810 _AX5043_FSKDMIN0NB	=	0x510f
                           00510E  1811 _AX5043_FSKDMIN1NB	=	0x510e
                           005309  1812 _AX5043_GPADC13VALUE0NB	=	0x5309
                           005308  1813 _AX5043_GPADC13VALUE1NB	=	0x5308
                           005300  1814 _AX5043_GPADCCTRLNB	=	0x5300
                           005301  1815 _AX5043_GPADCPERIODNB	=	0x5301
                           005101  1816 _AX5043_IFFREQ0NB	=	0x5101
                           005100  1817 _AX5043_IFFREQ1NB	=	0x5100
                           00500B  1818 _AX5043_IRQINVERSION0NB	=	0x500b
                           00500A  1819 _AX5043_IRQINVERSION1NB	=	0x500a
                           005007  1820 _AX5043_IRQMASK0NB	=	0x5007
                           005006  1821 _AX5043_IRQMASK1NB	=	0x5006
                           00500D  1822 _AX5043_IRQREQUEST0NB	=	0x500d
                           00500C  1823 _AX5043_IRQREQUEST1NB	=	0x500c
                           005310  1824 _AX5043_LPOSCCONFIGNB	=	0x5310
                           005317  1825 _AX5043_LPOSCFREQ0NB	=	0x5317
                           005316  1826 _AX5043_LPOSCFREQ1NB	=	0x5316
                           005313  1827 _AX5043_LPOSCKFILT0NB	=	0x5313
                           005312  1828 _AX5043_LPOSCKFILT1NB	=	0x5312
                           005319  1829 _AX5043_LPOSCPER0NB	=	0x5319
                           005318  1830 _AX5043_LPOSCPER1NB	=	0x5318
                           005315  1831 _AX5043_LPOSCREF0NB	=	0x5315
                           005314  1832 _AX5043_LPOSCREF1NB	=	0x5314
                           005311  1833 _AX5043_LPOSCSTATUSNB	=	0x5311
                           005214  1834 _AX5043_MATCH0LENNB	=	0x5214
                           005216  1835 _AX5043_MATCH0MAXNB	=	0x5216
                           005215  1836 _AX5043_MATCH0MINNB	=	0x5215
                           005213  1837 _AX5043_MATCH0PAT0NB	=	0x5213
                           005212  1838 _AX5043_MATCH0PAT1NB	=	0x5212
                           005211  1839 _AX5043_MATCH0PAT2NB	=	0x5211
                           005210  1840 _AX5043_MATCH0PAT3NB	=	0x5210
                           00521C  1841 _AX5043_MATCH1LENNB	=	0x521c
                           00521E  1842 _AX5043_MATCH1MAXNB	=	0x521e
                           00521D  1843 _AX5043_MATCH1MINNB	=	0x521d
                           005219  1844 _AX5043_MATCH1PAT0NB	=	0x5219
                           005218  1845 _AX5043_MATCH1PAT1NB	=	0x5218
                           005108  1846 _AX5043_MAXDROFFSET0NB	=	0x5108
                           005107  1847 _AX5043_MAXDROFFSET1NB	=	0x5107
                           005106  1848 _AX5043_MAXDROFFSET2NB	=	0x5106
                           00510B  1849 _AX5043_MAXRFOFFSET0NB	=	0x510b
                           00510A  1850 _AX5043_MAXRFOFFSET1NB	=	0x510a
                           005109  1851 _AX5043_MAXRFOFFSET2NB	=	0x5109
                           005164  1852 _AX5043_MODCFGANB	=	0x5164
                           005160  1853 _AX5043_MODCFGFNB	=	0x5160
                           005F5F  1854 _AX5043_MODCFGPNB	=	0x5f5f
                           005010  1855 _AX5043_MODULATIONNB	=	0x5010
                           005025  1856 _AX5043_PINFUNCANTSELNB	=	0x5025
                           005023  1857 _AX5043_PINFUNCDATANB	=	0x5023
                           005022  1858 _AX5043_PINFUNCDCLKNB	=	0x5022
                           005024  1859 _AX5043_PINFUNCIRQNB	=	0x5024
                           005026  1860 _AX5043_PINFUNCPWRAMPNB	=	0x5026
                           005021  1861 _AX5043_PINFUNCSYSCLKNB	=	0x5021
                           005020  1862 _AX5043_PINSTATENB	=	0x5020
                           005233  1863 _AX5043_PKTACCEPTFLAGSNB	=	0x5233
                           005230  1864 _AX5043_PKTCHUNKSIZENB	=	0x5230
                           005231  1865 _AX5043_PKTMISCFLAGSNB	=	0x5231
                           005232  1866 _AX5043_PKTSTOREFLAGSNB	=	0x5232
                           005031  1867 _AX5043_PLLCPINB	=	0x5031
                           005039  1868 _AX5043_PLLCPIBOOSTNB	=	0x5039
                           005182  1869 _AX5043_PLLLOCKDETNB	=	0x5182
                           005030  1870 _AX5043_PLLLOOPNB	=	0x5030
                           005038  1871 _AX5043_PLLLOOPBOOSTNB	=	0x5038
                           005033  1872 _AX5043_PLLRANGINGANB	=	0x5033
                           00503B  1873 _AX5043_PLLRANGINGBNB	=	0x503b
                           005183  1874 _AX5043_PLLRNGCLKNB	=	0x5183
                           005032  1875 _AX5043_PLLVCODIVNB	=	0x5032
                           005180  1876 _AX5043_PLLVCOINB	=	0x5180
                           005181  1877 _AX5043_PLLVCOIRNB	=	0x5181
                           005F08  1878 _AX5043_POWCTRL1NB	=	0x5f08
                           005005  1879 _AX5043_POWIRQMASKNB	=	0x5005
                           005003  1880 _AX5043_POWSTATNB	=	0x5003
                           005004  1881 _AX5043_POWSTICKYSTATNB	=	0x5004
                           005027  1882 _AX5043_PWRAMPNB	=	0x5027
                           005002  1883 _AX5043_PWRMODENB	=	0x5002
                           005009  1884 _AX5043_RADIOEVENTMASK0NB	=	0x5009
                           005008  1885 _AX5043_RADIOEVENTMASK1NB	=	0x5008
                           00500F  1886 _AX5043_RADIOEVENTREQ0NB	=	0x500f
                           00500E  1887 _AX5043_RADIOEVENTREQ1NB	=	0x500e
                           00501C  1888 _AX5043_RADIOSTATENB	=	0x501c
                           005F0D  1889 _AX5043_REFNB	=	0x5f0d
                           005040  1890 _AX5043_RSSINB	=	0x5040
                           00522D  1891 _AX5043_RSSIABSTHRNB	=	0x522d
                           00522C  1892 _AX5043_RSSIREFERENCENB	=	0x522c
                           005105  1893 _AX5043_RXDATARATE0NB	=	0x5105
                           005104  1894 _AX5043_RXDATARATE1NB	=	0x5104
                           005103  1895 _AX5043_RXDATARATE2NB	=	0x5103
                           005001  1896 _AX5043_SCRATCHNB	=	0x5001
                           005000  1897 _AX5043_SILICONREVISIONNB	=	0x5000
                           00505B  1898 _AX5043_TIMER0NB	=	0x505b
                           00505A  1899 _AX5043_TIMER1NB	=	0x505a
                           005059  1900 _AX5043_TIMER2NB	=	0x5059
                           005227  1901 _AX5043_TMGRXAGCNB	=	0x5227
                           005223  1902 _AX5043_TMGRXBOOSTNB	=	0x5223
                           005226  1903 _AX5043_TMGRXCOARSEAGCNB	=	0x5226
                           005225  1904 _AX5043_TMGRXOFFSACQNB	=	0x5225
                           005229  1905 _AX5043_TMGRXPREAMBLE1NB	=	0x5229
                           00522A  1906 _AX5043_TMGRXPREAMBLE2NB	=	0x522a
                           00522B  1907 _AX5043_TMGRXPREAMBLE3NB	=	0x522b
                           005228  1908 _AX5043_TMGRXRSSINB	=	0x5228
                           005224  1909 _AX5043_TMGRXSETTLENB	=	0x5224
                           005220  1910 _AX5043_TMGTXBOOSTNB	=	0x5220
                           005221  1911 _AX5043_TMGTXSETTLENB	=	0x5221
                           005055  1912 _AX5043_TRKAFSKDEMOD0NB	=	0x5055
                           005054  1913 _AX5043_TRKAFSKDEMOD1NB	=	0x5054
                           005049  1914 _AX5043_TRKAMPLITUDE0NB	=	0x5049
                           005048  1915 _AX5043_TRKAMPLITUDE1NB	=	0x5048
                           005047  1916 _AX5043_TRKDATARATE0NB	=	0x5047
                           005046  1917 _AX5043_TRKDATARATE1NB	=	0x5046
                           005045  1918 _AX5043_TRKDATARATE2NB	=	0x5045
                           005051  1919 _AX5043_TRKFREQ0NB	=	0x5051
                           005050  1920 _AX5043_TRKFREQ1NB	=	0x5050
                           005053  1921 _AX5043_TRKFSKDEMOD0NB	=	0x5053
                           005052  1922 _AX5043_TRKFSKDEMOD1NB	=	0x5052
                           00504B  1923 _AX5043_TRKPHASE0NB	=	0x504b
                           00504A  1924 _AX5043_TRKPHASE1NB	=	0x504a
                           00504F  1925 _AX5043_TRKRFFREQ0NB	=	0x504f
                           00504E  1926 _AX5043_TRKRFFREQ1NB	=	0x504e
                           00504D  1927 _AX5043_TRKRFFREQ2NB	=	0x504d
                           005169  1928 _AX5043_TXPWRCOEFFA0NB	=	0x5169
                           005168  1929 _AX5043_TXPWRCOEFFA1NB	=	0x5168
                           00516B  1930 _AX5043_TXPWRCOEFFB0NB	=	0x516b
                           00516A  1931 _AX5043_TXPWRCOEFFB1NB	=	0x516a
                           00516D  1932 _AX5043_TXPWRCOEFFC0NB	=	0x516d
                           00516C  1933 _AX5043_TXPWRCOEFFC1NB	=	0x516c
                           00516F  1934 _AX5043_TXPWRCOEFFD0NB	=	0x516f
                           00516E  1935 _AX5043_TXPWRCOEFFD1NB	=	0x516e
                           005171  1936 _AX5043_TXPWRCOEFFE0NB	=	0x5171
                           005170  1937 _AX5043_TXPWRCOEFFE1NB	=	0x5170
                           005167  1938 _AX5043_TXRATE0NB	=	0x5167
                           005166  1939 _AX5043_TXRATE1NB	=	0x5166
                           005165  1940 _AX5043_TXRATE2NB	=	0x5165
                           00506B  1941 _AX5043_WAKEUP0NB	=	0x506b
                           00506A  1942 _AX5043_WAKEUP1NB	=	0x506a
                           00506D  1943 _AX5043_WAKEUPFREQ0NB	=	0x506d
                           00506C  1944 _AX5043_WAKEUPFREQ1NB	=	0x506c
                           005069  1945 _AX5043_WAKEUPTIMER0NB	=	0x5069
                           005068  1946 _AX5043_WAKEUPTIMER1NB	=	0x5068
                           00506E  1947 _AX5043_WAKEUPXOEARLYNB	=	0x506e
                           005F11  1948 _AX5043_XTALAMPLNB	=	0x5f11
                           005184  1949 _AX5043_XTALCAPNB	=	0x5184
                           005F10  1950 _AX5043_XTALOSCNB	=	0x5f10
                           00501D  1951 _AX5043_XTALSTATUSNB	=	0x501d
                           005F00  1952 _AX5043_0xF00NB	=	0x5f00
                           005F0C  1953 _AX5043_0xF0CNB	=	0x5f0c
                           005F18  1954 _AX5043_0xF18NB	=	0x5f18
                           005F1C  1955 _AX5043_0xF1CNB	=	0x5f1c
                           005F21  1956 _AX5043_0xF21NB	=	0x5f21
                           005F22  1957 _AX5043_0xF22NB	=	0x5f22
                           005F23  1958 _AX5043_0xF23NB	=	0x5f23
                           005F26  1959 _AX5043_0xF26NB	=	0x5f26
                           005F30  1960 _AX5043_0xF30NB	=	0x5f30
                           005F31  1961 _AX5043_0xF31NB	=	0x5f31
                           005F32  1962 _AX5043_0xF32NB	=	0x5f32
                           005F33  1963 _AX5043_0xF33NB	=	0x5f33
                           005F34  1964 _AX5043_0xF34NB	=	0x5f34
                           005F35  1965 _AX5043_0xF35NB	=	0x5f35
                           005F44  1966 _AX5043_0xF44NB	=	0x5f44
                           005122  1967 _AX5043_AGCAHYST0NB	=	0x5122
                           005132  1968 _AX5043_AGCAHYST1NB	=	0x5132
                           005142  1969 _AX5043_AGCAHYST2NB	=	0x5142
                           005152  1970 _AX5043_AGCAHYST3NB	=	0x5152
                           005120  1971 _AX5043_AGCGAIN0NB	=	0x5120
                           005130  1972 _AX5043_AGCGAIN1NB	=	0x5130
                           005140  1973 _AX5043_AGCGAIN2NB	=	0x5140
                           005150  1974 _AX5043_AGCGAIN3NB	=	0x5150
                           005123  1975 _AX5043_AGCMINMAX0NB	=	0x5123
                           005133  1976 _AX5043_AGCMINMAX1NB	=	0x5133
                           005143  1977 _AX5043_AGCMINMAX2NB	=	0x5143
                           005153  1978 _AX5043_AGCMINMAX3NB	=	0x5153
                           005121  1979 _AX5043_AGCTARGET0NB	=	0x5121
                           005131  1980 _AX5043_AGCTARGET1NB	=	0x5131
                           005141  1981 _AX5043_AGCTARGET2NB	=	0x5141
                           005151  1982 _AX5043_AGCTARGET3NB	=	0x5151
                           00512B  1983 _AX5043_AMPLITUDEGAIN0NB	=	0x512b
                           00513B  1984 _AX5043_AMPLITUDEGAIN1NB	=	0x513b
                           00514B  1985 _AX5043_AMPLITUDEGAIN2NB	=	0x514b
                           00515B  1986 _AX5043_AMPLITUDEGAIN3NB	=	0x515b
                           00512F  1987 _AX5043_BBOFFSRES0NB	=	0x512f
                           00513F  1988 _AX5043_BBOFFSRES1NB	=	0x513f
                           00514F  1989 _AX5043_BBOFFSRES2NB	=	0x514f
                           00515F  1990 _AX5043_BBOFFSRES3NB	=	0x515f
                           005125  1991 _AX5043_DRGAIN0NB	=	0x5125
                           005135  1992 _AX5043_DRGAIN1NB	=	0x5135
                           005145  1993 _AX5043_DRGAIN2NB	=	0x5145
                           005155  1994 _AX5043_DRGAIN3NB	=	0x5155
                           00512E  1995 _AX5043_FOURFSK0NB	=	0x512e
                           00513E  1996 _AX5043_FOURFSK1NB	=	0x513e
                           00514E  1997 _AX5043_FOURFSK2NB	=	0x514e
                           00515E  1998 _AX5043_FOURFSK3NB	=	0x515e
                           00512D  1999 _AX5043_FREQDEV00NB	=	0x512d
                           00513D  2000 _AX5043_FREQDEV01NB	=	0x513d
                           00514D  2001 _AX5043_FREQDEV02NB	=	0x514d
                           00515D  2002 _AX5043_FREQDEV03NB	=	0x515d
                           00512C  2003 _AX5043_FREQDEV10NB	=	0x512c
                           00513C  2004 _AX5043_FREQDEV11NB	=	0x513c
                           00514C  2005 _AX5043_FREQDEV12NB	=	0x514c
                           00515C  2006 _AX5043_FREQDEV13NB	=	0x515c
                           005127  2007 _AX5043_FREQUENCYGAINA0NB	=	0x5127
                           005137  2008 _AX5043_FREQUENCYGAINA1NB	=	0x5137
                           005147  2009 _AX5043_FREQUENCYGAINA2NB	=	0x5147
                           005157  2010 _AX5043_FREQUENCYGAINA3NB	=	0x5157
                           005128  2011 _AX5043_FREQUENCYGAINB0NB	=	0x5128
                           005138  2012 _AX5043_FREQUENCYGAINB1NB	=	0x5138
                           005148  2013 _AX5043_FREQUENCYGAINB2NB	=	0x5148
                           005158  2014 _AX5043_FREQUENCYGAINB3NB	=	0x5158
                           005129  2015 _AX5043_FREQUENCYGAINC0NB	=	0x5129
                           005139  2016 _AX5043_FREQUENCYGAINC1NB	=	0x5139
                           005149  2017 _AX5043_FREQUENCYGAINC2NB	=	0x5149
                           005159  2018 _AX5043_FREQUENCYGAINC3NB	=	0x5159
                           00512A  2019 _AX5043_FREQUENCYGAIND0NB	=	0x512a
                           00513A  2020 _AX5043_FREQUENCYGAIND1NB	=	0x513a
                           00514A  2021 _AX5043_FREQUENCYGAIND2NB	=	0x514a
                           00515A  2022 _AX5043_FREQUENCYGAIND3NB	=	0x515a
                           005116  2023 _AX5043_FREQUENCYLEAKNB	=	0x5116
                           005126  2024 _AX5043_PHASEGAIN0NB	=	0x5126
                           005136  2025 _AX5043_PHASEGAIN1NB	=	0x5136
                           005146  2026 _AX5043_PHASEGAIN2NB	=	0x5146
                           005156  2027 _AX5043_PHASEGAIN3NB	=	0x5156
                           005207  2028 _AX5043_PKTADDR0NB	=	0x5207
                           005206  2029 _AX5043_PKTADDR1NB	=	0x5206
                           005205  2030 _AX5043_PKTADDR2NB	=	0x5205
                           005204  2031 _AX5043_PKTADDR3NB	=	0x5204
                           005200  2032 _AX5043_PKTADDRCFGNB	=	0x5200
                           00520B  2033 _AX5043_PKTADDRMASK0NB	=	0x520b
                           00520A  2034 _AX5043_PKTADDRMASK1NB	=	0x520a
                           005209  2035 _AX5043_PKTADDRMASK2NB	=	0x5209
                           005208  2036 _AX5043_PKTADDRMASK3NB	=	0x5208
                           005201  2037 _AX5043_PKTLENCFGNB	=	0x5201
                           005202  2038 _AX5043_PKTLENOFFSETNB	=	0x5202
                           005203  2039 _AX5043_PKTMAXLENNB	=	0x5203
                           005118  2040 _AX5043_RXPARAMCURSETNB	=	0x5118
                           005117  2041 _AX5043_RXPARAMSETSNB	=	0x5117
                           005124  2042 _AX5043_TIMEGAIN0NB	=	0x5124
                           005134  2043 _AX5043_TIMEGAIN1NB	=	0x5134
                           005144  2044 _AX5043_TIMEGAIN2NB	=	0x5144
                           005154  2045 _AX5043_TIMEGAIN3NB	=	0x5154
      000013                       2046 _axradio_syncstate::
      000013                       2047 	.ds 1
      000014                       2048 _axradio_txbuffer_len::
      000014                       2049 	.ds 2
      000016                       2050 _axradio_txbuffer_cnt::
      000016                       2051 	.ds 2
      000018                       2052 _axradio_curchannel::
      000018                       2053 	.ds 1
      000019                       2054 _axradio_curfreqoffset::
      000019                       2055 	.ds 4
      00001D                       2056 _axradio_ack_count::
      00001D                       2057 	.ds 1
      00001E                       2058 _axradio_ack_seqnr::
      00001E                       2059 	.ds 1
      00001F                       2060 _axradio_sync_time::
      00001F                       2061 	.ds 4
      000023                       2062 _axradio_sync_periodcorr::
      000023                       2063 	.ds 2
      000025                       2064 _axradio_timeanchor::
      000025                       2065 	.ds 8
      00002D                       2066 _axradio_localaddr::
      00002D                       2067 	.ds 10
      000037                       2068 _axradio_default_remoteaddr::
      000037                       2069 	.ds 5
      00003C                       2070 _axradio_txbuffer::
      00003C                       2071 	.ds 260
      000140                       2072 _axradio_rxbuffer::
      000140                       2073 	.ds 260
      000244                       2074 _axradio_cb_receive::
      000244                       2075 	.ds 36
      000268                       2076 _axradio_cb_receivesfd::
      000268                       2077 	.ds 10
      000272                       2078 _axradio_cb_channelstate::
      000272                       2079 	.ds 13
      00027F                       2080 _axradio_cb_transmitstart::
      00027F                       2081 	.ds 10
      000289                       2082 _axradio_cb_transmitend::
      000289                       2083 	.ds 10
      000293                       2084 _axradio_cb_transmitdata::
      000293                       2085 	.ds 10
      00029D                       2086 _axradio_timer::
      00029D                       2087 	.ds 8
                                   2088 ;--------------------------------------------------------
                                   2089 ; absolute external ram data
                                   2090 ;--------------------------------------------------------
                                   2091 	.area XABS    (ABS,XDATA)
                                   2092 ;--------------------------------------------------------
                                   2093 ; external initialized ram data
                                   2094 ;--------------------------------------------------------
                                   2095 	.area XISEG   (XDATA)
      00044D                       2096 _f30_saved::
      00044D                       2097 	.ds 1
      00044E                       2098 _f31_saved::
      00044E                       2099 	.ds 1
      00044F                       2100 _f32_saved::
      00044F                       2101 	.ds 1
      000450                       2102 _f33_saved::
      000450                       2103 	.ds 1
      000451                       2104 _radio_lcd_display::
      000451                       2105 	.ds 14
      00045F                       2106 _radio_not_found_lcd_display::
      00045F                       2107 	.ds 20
                                   2108 	.area HOME    (CODE)
                                   2109 	.area GSINIT0 (CODE)
                                   2110 	.area GSINIT1 (CODE)
                                   2111 	.area GSINIT2 (CODE)
                                   2112 	.area GSINIT3 (CODE)
                                   2113 	.area GSINIT4 (CODE)
                                   2114 	.area GSINIT5 (CODE)
                                   2115 	.area GSINIT  (CODE)
                                   2116 	.area GSFINAL (CODE)
                                   2117 	.area CSEG    (CODE)
                                   2118 ;--------------------------------------------------------
                                   2119 ; global & static initialisations
                                   2120 ;--------------------------------------------------------
                                   2121 	.area HOME    (CODE)
                                   2122 	.area GSINIT  (CODE)
                                   2123 	.area GSFINAL (CODE)
                                   2124 	.area GSINIT  (CODE)
                                   2125 ;	..\COMMON\easyax5043.c:74: volatile uint8_t __data axradio_mode = AXRADIO_MODE_UNINIT;
      000384 75 08 00         [24] 2126 	mov	_axradio_mode,#0x00
                                   2127 ;	..\COMMON\easyax5043.c:75: volatile axradio_trxstate_t __data axradio_trxstate = trxstate_off;
      000387 75 09 00         [24] 2128 	mov	_axradio_trxstate,#0x00
                                   2129 ;--------------------------------------------------------
                                   2130 ; Home
                                   2131 ;--------------------------------------------------------
                                   2132 	.area HOME    (CODE)
                                   2133 	.area HOME    (CODE)
                                   2134 ;--------------------------------------------------------
                                   2135 ; code
                                   2136 ;--------------------------------------------------------
                                   2137 	.area CSEG    (CODE)
                                   2138 ;------------------------------------------------------------
                                   2139 ;Allocation info for local variables in function 'update_timeanchor'
                                   2140 ;------------------------------------------------------------
                                   2141 ;__00010012                Allocated to registers 
                                   2142 ;crit                      Allocated to registers 
                                   2143 ;crit                      Allocated to registers r7 
                                   2144 ;__00020014                Allocated to registers 
                                   2145 ;crit                      Allocated to registers 
                                   2146 ;------------------------------------------------------------
                                   2147 ;	..\COMMON\easyax5043.c:276: static __reentrantb void update_timeanchor(void) __reentrant
                                   2148 ;	-----------------------------------------
                                   2149 ;	 function update_timeanchor
                                   2150 ;	-----------------------------------------
      000A7C                       2151 _update_timeanchor:
                           000007  2152 	ar7 = 0x07
                           000006  2153 	ar6 = 0x06
                           000005  2154 	ar5 = 0x05
                           000004  2155 	ar4 = 0x04
                           000003  2156 	ar3 = 0x03
                           000002  2157 	ar2 = 0x02
                           000001  2158 	ar1 = 0x01
                           000000  2159 	ar0 = 0x00
                                   2160 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:351: criticalsection_t crit = IE & 0x80;
      000A7C 74 80            [12] 2161 	mov	a,#0x80
      000A7E 55 A8            [12] 2162 	anl	a,_IE
      000A80 FF               [12] 2163 	mov	r7,a
                                   2164 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:352: EA = 0;
      000A81 C2 AF            [12] 2165 	clr	_EA
                                   2166 ;	..\COMMON\easyax5043.c:280: axradio_timeanchor.timer0 = wtimer0_curtime();
      000A83 C0 07            [24] 2167 	push	ar7
      000A85 12 4C 16         [24] 2168 	lcall	_wtimer0_curtime
      000A88 AB 82            [24] 2169 	mov	r3,dpl
      000A8A AC 83            [24] 2170 	mov	r4,dph
      000A8C AD F0            [24] 2171 	mov	r5,b
      000A8E FE               [12] 2172 	mov	r6,a
      000A8F D0 07            [24] 2173 	pop	ar7
      000A91 90 00 25         [24] 2174 	mov	dptr,#_axradio_timeanchor
      000A94 EB               [12] 2175 	mov	a,r3
      000A95 F0               [24] 2176 	movx	@dptr,a
      000A96 EC               [12] 2177 	mov	a,r4
      000A97 A3               [24] 2178 	inc	dptr
      000A98 F0               [24] 2179 	movx	@dptr,a
      000A99 ED               [12] 2180 	mov	a,r5
      000A9A A3               [24] 2181 	inc	dptr
      000A9B F0               [24] 2182 	movx	@dptr,a
      000A9C EE               [12] 2183 	mov	a,r6
      000A9D A3               [24] 2184 	inc	dptr
      000A9E F0               [24] 2185 	movx	@dptr,a
                                   2186 ;	..\COMMON\easyax5043.c:281: axradio_timeanchor.radiotimer = radio_read24(AX5043_REG_TIMER2);
      000A9F 90 00 59         [24] 2187 	mov	dptr,#0x0059
      000AA2 12 43 98         [24] 2188 	lcall	_radio_read24
      000AA5 AB 82            [24] 2189 	mov	r3,dpl
      000AA7 AC 83            [24] 2190 	mov	r4,dph
      000AA9 AD F0            [24] 2191 	mov	r5,b
      000AAB FE               [12] 2192 	mov	r6,a
      000AAC 90 00 29         [24] 2193 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      000AAF EB               [12] 2194 	mov	a,r3
      000AB0 F0               [24] 2195 	movx	@dptr,a
      000AB1 EC               [12] 2196 	mov	a,r4
      000AB2 A3               [24] 2197 	inc	dptr
      000AB3 F0               [24] 2198 	movx	@dptr,a
      000AB4 ED               [12] 2199 	mov	a,r5
      000AB5 A3               [24] 2200 	inc	dptr
      000AB6 F0               [24] 2201 	movx	@dptr,a
      000AB7 EE               [12] 2202 	mov	a,r6
      000AB8 A3               [24] 2203 	inc	dptr
      000AB9 F0               [24] 2204 	movx	@dptr,a
                                   2205 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:358: IE |= crit;
      000ABA EF               [12] 2206 	mov	a,r7
      000ABB 42 A8            [12] 2207 	orl	_IE,a
                                   2208 ;	..\COMMON\easyax5043.c:282: exit_critical(crit);
      000ABD 22               [24] 2209 	ret
                                   2210 ;------------------------------------------------------------
                                   2211 ;Allocation info for local variables in function 'axradio_conv_time_totimer0'
                                   2212 ;------------------------------------------------------------
                                   2213 ;dt                        Allocated to registers r4 r5 r6 r7 
                                   2214 ;------------------------------------------------------------
                                   2215 ;	..\COMMON\easyax5043.c:285: __reentrantb uint32_t axradio_conv_time_totimer0(uint32_t dt) __reentrant
                                   2216 ;	-----------------------------------------
                                   2217 ;	 function axradio_conv_time_totimer0
                                   2218 ;	-----------------------------------------
      000ABE                       2219 _axradio_conv_time_totimer0:
      000ABE AC 82            [24] 2220 	mov	r4,dpl
      000AC0 AD 83            [24] 2221 	mov	r5,dph
      000AC2 AE F0            [24] 2222 	mov	r6,b
      000AC4 FF               [12] 2223 	mov	r7,a
                                   2224 ;	..\COMMON\easyax5043.c:287: dt -= axradio_timeanchor.radiotimer;
      000AC5 90 00 29         [24] 2225 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      000AC8 E0               [24] 2226 	movx	a,@dptr
      000AC9 F8               [12] 2227 	mov	r0,a
      000ACA A3               [24] 2228 	inc	dptr
      000ACB E0               [24] 2229 	movx	a,@dptr
      000ACC F9               [12] 2230 	mov	r1,a
      000ACD A3               [24] 2231 	inc	dptr
      000ACE E0               [24] 2232 	movx	a,@dptr
      000ACF FA               [12] 2233 	mov	r2,a
      000AD0 A3               [24] 2234 	inc	dptr
      000AD1 E0               [24] 2235 	movx	a,@dptr
      000AD2 FB               [12] 2236 	mov	r3,a
      000AD3 EC               [12] 2237 	mov	a,r4
      000AD4 C3               [12] 2238 	clr	c
      000AD5 98               [12] 2239 	subb	a,r0
      000AD6 FC               [12] 2240 	mov	r4,a
      000AD7 ED               [12] 2241 	mov	a,r5
      000AD8 99               [12] 2242 	subb	a,r1
      000AD9 FD               [12] 2243 	mov	r5,a
      000ADA EE               [12] 2244 	mov	a,r6
      000ADB 9A               [12] 2245 	subb	a,r2
      000ADC FE               [12] 2246 	mov	r6,a
      000ADD EF               [12] 2247 	mov	a,r7
      000ADE 9B               [12] 2248 	subb	a,r3
                                   2249 ;	..\COMMON\easyax5043.c:288: dt = axradio_conv_timeinterval_totimer0(signextend24(dt));
      000ADF 8C 82            [24] 2250 	mov	dpl,r4
      000AE1 8D 83            [24] 2251 	mov	dph,r5
      000AE3 8E F0            [24] 2252 	mov	b,r6
      000AE5 12 4C 10         [24] 2253 	lcall	_signextend24
      000AE8 12 08 C3         [24] 2254 	lcall	_axradio_conv_timeinterval_totimer0
      000AEB AC 82            [24] 2255 	mov	r4,dpl
      000AED AD 83            [24] 2256 	mov	r5,dph
      000AEF AE F0            [24] 2257 	mov	r6,b
      000AF1 FF               [12] 2258 	mov	r7,a
                                   2259 ;	..\COMMON\easyax5043.c:289: dt += axradio_timeanchor.timer0;
      000AF2 90 00 25         [24] 2260 	mov	dptr,#_axradio_timeanchor
      000AF5 E0               [24] 2261 	movx	a,@dptr
      000AF6 F8               [12] 2262 	mov	r0,a
      000AF7 A3               [24] 2263 	inc	dptr
      000AF8 E0               [24] 2264 	movx	a,@dptr
      000AF9 F9               [12] 2265 	mov	r1,a
      000AFA A3               [24] 2266 	inc	dptr
      000AFB E0               [24] 2267 	movx	a,@dptr
      000AFC FA               [12] 2268 	mov	r2,a
      000AFD A3               [24] 2269 	inc	dptr
      000AFE E0               [24] 2270 	movx	a,@dptr
      000AFF FB               [12] 2271 	mov	r3,a
      000B00 E8               [12] 2272 	mov	a,r0
      000B01 2C               [12] 2273 	add	a,r4
      000B02 FC               [12] 2274 	mov	r4,a
      000B03 E9               [12] 2275 	mov	a,r1
      000B04 3D               [12] 2276 	addc	a,r5
      000B05 FD               [12] 2277 	mov	r5,a
      000B06 EA               [12] 2278 	mov	a,r2
      000B07 3E               [12] 2279 	addc	a,r6
      000B08 FE               [12] 2280 	mov	r6,a
      000B09 EB               [12] 2281 	mov	a,r3
      000B0A 3F               [12] 2282 	addc	a,r7
                                   2283 ;	..\COMMON\easyax5043.c:290: return dt;
      000B0B 8C 82            [24] 2284 	mov	dpl,r4
      000B0D 8D 83            [24] 2285 	mov	dph,r5
      000B0F 8E F0            [24] 2286 	mov	b,r6
      000B11 22               [24] 2287 	ret
                                   2288 ;------------------------------------------------------------
                                   2289 ;Allocation info for local variables in function 'ax5043_init_registers_common'
                                   2290 ;------------------------------------------------------------
                                   2291 ;rng                       Allocated to registers r6 
                                   2292 ;------------------------------------------------------------
                                   2293 ;	..\COMMON\easyax5043.c:293: static __reentrantb uint8_t ax5043_init_registers_common(void) __reentrant
                                   2294 ;	-----------------------------------------
                                   2295 ;	 function ax5043_init_registers_common
                                   2296 ;	-----------------------------------------
      000B12                       2297 _ax5043_init_registers_common:
                                   2298 ;	..\COMMON\easyax5043.c:295: uint8_t rng = axradio_phy_chanpllrng[axradio_curchannel];
      000B12 90 00 18         [24] 2299 	mov	dptr,#_axradio_curchannel
      000B15 E0               [24] 2300 	movx	a,@dptr
      000B16 75 F0 02         [24] 2301 	mov	b,#0x02
      000B19 A4               [48] 2302 	mul	ab
      000B1A 24 01            [12] 2303 	add	a,#_axradio_phy_chanpllrng
      000B1C F5 82            [12] 2304 	mov	dpl,a
      000B1E 74 00            [12] 2305 	mov	a,#(_axradio_phy_chanpllrng >> 8)
      000B20 35 F0            [12] 2306 	addc	a,b
      000B22 F5 83            [12] 2307 	mov	dph,a
      000B24 E0               [24] 2308 	movx	a,@dptr
      000B25 FE               [12] 2309 	mov	r6,a
      000B26 A3               [24] 2310 	inc	dptr
      000B27 E0               [24] 2311 	movx	a,@dptr
      000B28 FF               [12] 2312 	mov	r7,a
                                   2313 ;	..\COMMON\easyax5043.c:296: if (rng & 0x20)
      000B29 EE               [12] 2314 	mov	a,r6
      000B2A 30 E5 04         [24] 2315 	jnb	acc.5,00102$
                                   2316 ;	..\COMMON\easyax5043.c:297: return AXRADIO_ERR_RANGING;
      000B2D 75 82 06         [24] 2317 	mov	dpl,#0x06
      000B30 22               [24] 2318 	ret
      000B31                       2319 00102$:
                                   2320 ;	..\COMMON\easyax5043.c:298: if (radio_read8(AX5043_REG_PLLLOOP) & 0x80)
      000B31 90 40 30         [24] 2321 	mov	dptr,#0x4030
      000B34 E0               [24] 2322 	movx	a,@dptr
      000B35 FF               [12] 2323 	mov	r7,a
      000B36 30 E7 0A         [24] 2324 	jnb	acc.7,00106$
                                   2325 ;	..\COMMON\easyax5043.c:299: radio_write8(AX5043_REG_PLLRANGINGB, (rng & 0x0F));
      000B39 74 0F            [12] 2326 	mov	a,#0x0f
      000B3B 5E               [12] 2327 	anl	a,r6
      000B3C FF               [12] 2328 	mov	r7,a
      000B3D 90 40 3B         [24] 2329 	mov	dptr,#0x403b
      000B40 F0               [24] 2330 	movx	@dptr,a
                                   2331 ;	..\COMMON\easyax5043.c:301: radio_write8(AX5043_REG_PLLRANGINGA, (rng & 0x0F));
      000B41 80 08            [24] 2332 	sjmp	00111$
      000B43                       2333 00106$:
      000B43 74 0F            [12] 2334 	mov	a,#0x0f
      000B45 5E               [12] 2335 	anl	a,r6
      000B46 FF               [12] 2336 	mov	r7,a
      000B47 90 40 33         [24] 2337 	mov	dptr,#0x4033
      000B4A F0               [24] 2338 	movx	@dptr,a
      000B4B                       2339 00111$:
                                   2340 ;	..\COMMON\easyax5043.c:302: rng = axradio_get_pllvcoi();
      000B4B 12 33 DB         [24] 2341 	lcall	_axradio_get_pllvcoi
      000B4E AF 82            [24] 2342 	mov	r7,dpl
      000B50 8F 06            [24] 2343 	mov	ar6,r7
                                   2344 ;	..\COMMON\easyax5043.c:303: if (rng & 0x80)
      000B52 EE               [12] 2345 	mov	a,r6
      000B53 30 E7 05         [24] 2346 	jnb	acc.7,00116$
                                   2347 ;	..\COMMON\easyax5043.c:304: radio_write8(AX5043_REG_PLLVCOI, rng);
      000B56 90 41 80         [24] 2348 	mov	dptr,#0x4180
      000B59 EE               [12] 2349 	mov	a,r6
      000B5A F0               [24] 2350 	movx	@dptr,a
      000B5B                       2351 00116$:
                                   2352 ;	..\COMMON\easyax5043.c:305: return AXRADIO_ERR_NOERROR;
      000B5B 75 82 00         [24] 2353 	mov	dpl,#0x00
      000B5E 22               [24] 2354 	ret
                                   2355 ;------------------------------------------------------------
                                   2356 ;Allocation info for local variables in function 'ax5043_init_registers_tx'
                                   2357 ;------------------------------------------------------------
                                   2358 ;	..\COMMON\easyax5043.c:308: __reentrantb uint8_t ax5043_init_registers_tx(void) __reentrant
                                   2359 ;	-----------------------------------------
                                   2360 ;	 function ax5043_init_registers_tx
                                   2361 ;	-----------------------------------------
      000B5F                       2362 _ax5043_init_registers_tx:
                                   2363 ;	..\COMMON\easyax5043.c:310: ax5043_set_registers_tx();
      000B5F 12 06 55         [24] 2364 	lcall	_ax5043_set_registers_tx
                                   2365 ;	..\COMMON\easyax5043.c:311: return ax5043_init_registers_common();
      000B62 02 0B 12         [24] 2366 	ljmp	_ax5043_init_registers_common
                                   2367 ;------------------------------------------------------------
                                   2368 ;Allocation info for local variables in function 'ax5043_init_registers_rx'
                                   2369 ;------------------------------------------------------------
                                   2370 ;	..\COMMON\easyax5043.c:314: __reentrantb uint8_t ax5043_init_registers_rx(void) __reentrant
                                   2371 ;	-----------------------------------------
                                   2372 ;	 function ax5043_init_registers_rx
                                   2373 ;	-----------------------------------------
      000B65                       2374 _ax5043_init_registers_rx:
                                   2375 ;	..\COMMON\easyax5043.c:316: ax5043_set_registers_rx();
      000B65 12 06 79         [24] 2376 	lcall	_ax5043_set_registers_rx
                                   2377 ;	..\COMMON\easyax5043.c:317: return ax5043_init_registers_common();
      000B68 02 0B 12         [24] 2378 	ljmp	_ax5043_init_registers_common
                                   2379 ;------------------------------------------------------------
                                   2380 ;Allocation info for local variables in function 'receive_isr'
                                   2381 ;------------------------------------------------------------
                                   2382 ;fifo_cmd                  Allocated to registers r6 
                                   2383 ;flags                     Allocated to registers 
                                   2384 ;i                         Allocated to registers r6 
                                   2385 ;len                       Allocated to registers r7 
                                   2386 ;radioStateTemp            Allocated to registers r6 
                                   2387 ;r                         Allocated to registers r6 
                                   2388 ;r                         Allocated to registers r6 
                                   2389 ;r                         Allocated to registers r6 
                                   2390 ;------------------------------------------------------------
                                   2391 ;	..\COMMON\easyax5043.c:320: static __reentrantb void receive_isr(void) __reentrant
                                   2392 ;	-----------------------------------------
                                   2393 ;	 function receive_isr
                                   2394 ;	-----------------------------------------
      000B6B                       2395 _receive_isr:
                                   2396 ;	..\COMMON\easyax5043.c:324: uint8_t len = radio_read8(AX5043_REG_RADIOEVENTREQ0); // clear request so interrupt does not fire again. sync_rx enables interrupt on radio state changed in order to wake up on SDF detected
      000B6B 90 40 0F         [24] 2397 	mov	dptr,#0x400f
      000B6E E0               [24] 2398 	movx	a,@dptr
      000B6F FF               [12] 2399 	mov	r7,a
                                   2400 ;	..\COMMON\easyax5043.c:326: uint8_t radioStateTemp = radio_read8(AX5043_REG_RADIOSTATE);
      000B70 90 40 1C         [24] 2401 	mov	dptr,#0x401c
      000B73 E0               [24] 2402 	movx	a,@dptr
      000B74 FE               [12] 2403 	mov	r6,a
                                   2404 ;	..\COMMON\easyax5043.c:327: if ((len & 0x04) && radioStateTemp == 0x0F) {
      000B75 EF               [12] 2405 	mov	a,r7
      000B76 30 E2 3A         [24] 2406 	jnb	acc.2,00175$
      000B79 BE 0F 37         [24] 2407 	cjne	r6,#0x0f,00175$
                                   2408 ;	..\COMMON\easyax5043.c:329: update_timeanchor();
      000B7C 12 0A 7C         [24] 2409 	lcall	_update_timeanchor
                                   2410 ;	..\COMMON\easyax5043.c:330: if(axradio_framing_enable_sfdcallback) {
      000B7F 90 4C C3         [24] 2411 	mov	dptr,#_axradio_framing_enable_sfdcallback
      000B82 E4               [12] 2412 	clr	a
      000B83 93               [24] 2413 	movc	a,@a+dptr
      000B84 60 2D            [24] 2414 	jz	00175$
                                   2415 ;	..\COMMON\easyax5043.c:331: wtimer_remove_callback(&axradio_cb_receivesfd.cb);
      000B86 90 02 68         [24] 2416 	mov	dptr,#_axradio_cb_receivesfd
      000B89 12 48 82         [24] 2417 	lcall	_wtimer_remove_callback
                                   2418 ;	..\COMMON\easyax5043.c:332: axradio_cb_receivesfd.st.error = AXRADIO_ERR_NOERROR;
      000B8C 90 02 6D         [24] 2419 	mov	dptr,#(_axradio_cb_receivesfd + 0x0005)
      000B8F E4               [12] 2420 	clr	a
      000B90 F0               [24] 2421 	movx	@dptr,a
                                   2422 ;	..\COMMON\easyax5043.c:333: axradio_cb_receivesfd.st.time.t = axradio_timeanchor.radiotimer;
      000B91 90 00 29         [24] 2423 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      000B94 E0               [24] 2424 	movx	a,@dptr
      000B95 FB               [12] 2425 	mov	r3,a
      000B96 A3               [24] 2426 	inc	dptr
      000B97 E0               [24] 2427 	movx	a,@dptr
      000B98 FC               [12] 2428 	mov	r4,a
      000B99 A3               [24] 2429 	inc	dptr
      000B9A E0               [24] 2430 	movx	a,@dptr
      000B9B FD               [12] 2431 	mov	r5,a
      000B9C A3               [24] 2432 	inc	dptr
      000B9D E0               [24] 2433 	movx	a,@dptr
      000B9E FE               [12] 2434 	mov	r6,a
      000B9F 90 02 6E         [24] 2435 	mov	dptr,#(_axradio_cb_receivesfd + 0x0006)
      000BA2 EB               [12] 2436 	mov	a,r3
      000BA3 F0               [24] 2437 	movx	@dptr,a
      000BA4 EC               [12] 2438 	mov	a,r4
      000BA5 A3               [24] 2439 	inc	dptr
      000BA6 F0               [24] 2440 	movx	@dptr,a
      000BA7 ED               [12] 2441 	mov	a,r5
      000BA8 A3               [24] 2442 	inc	dptr
      000BA9 F0               [24] 2443 	movx	@dptr,a
      000BAA EE               [12] 2444 	mov	a,r6
      000BAB A3               [24] 2445 	inc	dptr
      000BAC F0               [24] 2446 	movx	@dptr,a
                                   2447 ;	..\COMMON\easyax5043.c:334: wtimer_add_callback(&axradio_cb_receivesfd.cb);
      000BAD 90 02 68         [24] 2448 	mov	dptr,#_axradio_cb_receivesfd
      000BB0 12 42 C4         [24] 2449 	lcall	_wtimer_add_callback
                                   2450 ;	..\COMMON\easyax5043.c:346: while (radio_read8(AX5043_REG_IRQREQUEST0) & 0x01) {    // while fifo not empty
      000BB3                       2451 00175$:
      000BB3                       2452 00159$:
      000BB3 90 40 0D         [24] 2453 	mov	dptr,#0x400d
      000BB6 E0               [24] 2454 	movx	a,@dptr
      000BB7 FE               [12] 2455 	mov	r6,a
      000BB8 20 E0 01         [24] 2456 	jb	acc.0,00256$
      000BBB 22               [24] 2457 	ret
      000BBC                       2458 00256$:
                                   2459 ;	..\COMMON\easyax5043.c:347: fifo_cmd = radio_read8(AX5043_REG_FIFODATA); // read command
      000BBC 90 40 29         [24] 2460 	mov	dptr,#0x4029
      000BBF E0               [24] 2461 	movx	a,@dptr
      000BC0 FE               [12] 2462 	mov	r6,a
                                   2463 ;	..\COMMON\easyax5043.c:348: len = (fifo_cmd & 0xE0) >> 5; // top 3 bits encode payload len
      000BC1 74 E0            [12] 2464 	mov	a,#0xe0
      000BC3 5E               [12] 2465 	anl	a,r6
      000BC4 FD               [12] 2466 	mov	r5,a
      000BC5 C4               [12] 2467 	swap	a
      000BC6 03               [12] 2468 	rr	a
      000BC7 54 07            [12] 2469 	anl	a,#0x07
      000BC9 FF               [12] 2470 	mov	r7,a
                                   2471 ;	..\COMMON\easyax5043.c:349: if (len == 7)
      000BCA BF 07 05         [24] 2472 	cjne	r7,#0x07,00107$
                                   2473 ;	..\COMMON\easyax5043.c:350: len = radio_read8(AX5043_REG_FIFODATA); // 7 means variable length, -> get length byte
      000BCD 90 40 29         [24] 2474 	mov	dptr,#0x4029
      000BD0 E0               [24] 2475 	movx	a,@dptr
      000BD1 FF               [12] 2476 	mov	r7,a
      000BD2                       2477 00107$:
                                   2478 ;	..\COMMON\easyax5043.c:351: fifo_cmd &= 0x1F;
      000BD2 53 06 1F         [24] 2479 	anl	ar6,#0x1f
                                   2480 ;	..\COMMON\easyax5043.c:352: switch (fifo_cmd) {
      000BD5 BE 01 02         [24] 2481 	cjne	r6,#0x01,00259$
      000BD8 80 21            [24] 2482 	sjmp	00108$
      000BDA                       2483 00259$:
      000BDA BE 10 03         [24] 2484 	cjne	r6,#0x10,00260$
      000BDD 02 0E 1E         [24] 2485 	ljmp	00145$
      000BE0                       2486 00260$:
      000BE0 BE 11 03         [24] 2487 	cjne	r6,#0x11,00261$
      000BE3 02 0D F1         [24] 2488 	ljmp	00142$
      000BE6                       2489 00261$:
      000BE6 BE 12 03         [24] 2490 	cjne	r6,#0x12,00262$
      000BE9 02 0D A1         [24] 2491 	ljmp	00138$
      000BEC                       2492 00262$:
      000BEC BE 13 03         [24] 2493 	cjne	r6,#0x13,00263$
      000BEF 02 0D 5A         [24] 2494 	ljmp	00134$
      000BF2                       2495 00263$:
      000BF2 BE 15 03         [24] 2496 	cjne	r6,#0x15,00264$
      000BF5 02 0E 47         [24] 2497 	ljmp	00148$
      000BF8                       2498 00264$:
      000BF8 02 0E BF         [24] 2499 	ljmp	00152$
                                   2500 ;	..\COMMON\easyax5043.c:353: case AX5043_FIFOCMD_DATA:
      000BFB                       2501 00108$:
                                   2502 ;	..\COMMON\easyax5043.c:354: if (!len)
      000BFB EF               [12] 2503 	mov	a,r7
      000BFC 60 B5            [24] 2504 	jz	00159$
                                   2505 ;	..\COMMON\easyax5043.c:357: flags = radio_read8(AX5043_REG_FIFODATA);
      000BFE 90 40 29         [24] 2506 	mov	dptr,#0x4029
      000C01 E0               [24] 2507 	movx	a,@dptr
                                   2508 ;	..\COMMON\easyax5043.c:358: --len;
      000C02 1F               [12] 2509 	dec	r7
                                   2510 ;	..\COMMON\easyax5043.c:359: ax5043_readfifo(axradio_rxbuffer, len);
      000C03 C0 07            [24] 2511 	push	ar7
      000C05 C0 07            [24] 2512 	push	ar7
      000C07 90 01 40         [24] 2513 	mov	dptr,#_axradio_rxbuffer
      000C0A 75 F0 00         [24] 2514 	mov	b,#0x00
      000C0D 12 47 39         [24] 2515 	lcall	_ax5043_readfifo
      000C10 15 81            [12] 2516 	dec	sp
      000C12 D0 07            [24] 2517 	pop	ar7
                                   2518 ;	..\COMMON\easyax5043.c:360: if(axradio_mode == AXRADIO_MODE_WOR_RECEIVE || axradio_mode == AXRADIO_MODE_WOR_ACK_RECEIVE) {
      000C14 74 21            [12] 2519 	mov	a,#0x21
      000C16 B5 08 02         [24] 2520 	cjne	a,_axradio_mode,00266$
      000C19 80 05            [24] 2521 	sjmp	00111$
      000C1B                       2522 00266$:
      000C1B 74 23            [12] 2523 	mov	a,#0x23
      000C1D B5 08 21         [24] 2524 	cjne	a,_axradio_mode,00112$
      000C20                       2525 00111$:
                                   2526 ;	..\COMMON\easyax5043.c:361: f30_saved = radio_read8(AX5043_REG_0xF30);
      000C20 90 4F 30         [24] 2527 	mov	dptr,#0x4f30
      000C23 E0               [24] 2528 	movx	a,@dptr
      000C24 90 04 4D         [24] 2529 	mov	dptr,#_f30_saved
      000C27 F0               [24] 2530 	movx	@dptr,a
                                   2531 ;	..\COMMON\easyax5043.c:362: f31_saved = radio_read8(AX5043_REG_0xF31);
      000C28 90 4F 31         [24] 2532 	mov	dptr,#0x4f31
      000C2B E0               [24] 2533 	movx	a,@dptr
      000C2C 90 04 4E         [24] 2534 	mov	dptr,#_f31_saved
      000C2F F0               [24] 2535 	movx	@dptr,a
                                   2536 ;	..\COMMON\easyax5043.c:363: f32_saved = radio_read8(AX5043_REG_0xF32);
      000C30 90 4F 32         [24] 2537 	mov	dptr,#0x4f32
      000C33 E0               [24] 2538 	movx	a,@dptr
      000C34 90 04 4F         [24] 2539 	mov	dptr,#_f32_saved
      000C37 F0               [24] 2540 	movx	@dptr,a
                                   2541 ;	..\COMMON\easyax5043.c:364: f33_saved = radio_read8(AX5043_REG_0xF33);
      000C38 90 4F 33         [24] 2542 	mov	dptr,#0x4f33
      000C3B E0               [24] 2543 	movx	a,@dptr
      000C3C FE               [12] 2544 	mov	r6,a
      000C3D 90 04 50         [24] 2545 	mov	dptr,#_f33_saved
      000C40 F0               [24] 2546 	movx	@dptr,a
      000C41                       2547 00112$:
                                   2548 ;	..\COMMON\easyax5043.c:366: if (axradio_mode == AXRADIO_MODE_WOR_RECEIVE ||
      000C41 74 21            [12] 2549 	mov	a,#0x21
      000C43 B5 08 02         [24] 2550 	cjne	a,_axradio_mode,00269$
      000C46 80 05            [24] 2551 	sjmp	00114$
      000C48                       2552 00269$:
                                   2553 ;	..\COMMON\easyax5043.c:367: axradio_mode == AXRADIO_MODE_SYNC_SLAVE)
      000C48 74 32            [12] 2554 	mov	a,#0x32
      000C4A B5 08 05         [24] 2555 	cjne	a,_axradio_mode,00120$
                                   2556 ;	..\COMMON\easyax5043.c:368: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_POWERDOWN);
      000C4D                       2557 00114$:
      000C4D 90 40 02         [24] 2558 	mov	dptr,#0x4002
      000C50 E4               [12] 2559 	clr	a
      000C51 F0               [24] 2560 	movx	@dptr,a
                                   2561 ;	..\COMMON\easyax5043.c:369: radio_write8(AX5043_REG_IRQMASK0, (radio_read8(AX5043_REG_IRQMASK0) & (uint8_t)~0x01)); // disable FIFO not empty irq
      000C52                       2562 00120$:
      000C52 90 40 07         [24] 2563 	mov	dptr,#0x4007
      000C55 E0               [24] 2564 	movx	a,@dptr
      000C56 54 FE            [12] 2565 	anl	a,#0xfe
      000C58 F0               [24] 2566 	movx	@dptr,a
                                   2567 ;	..\COMMON\easyax5043.c:370: wtimer_remove_callback(&axradio_cb_receive.cb);
      000C59 90 02 44         [24] 2568 	mov	dptr,#_axradio_cb_receive
      000C5C C0 07            [24] 2569 	push	ar7
      000C5E 12 48 82         [24] 2570 	lcall	_wtimer_remove_callback
      000C61 D0 07            [24] 2571 	pop	ar7
                                   2572 ;	..\COMMON\easyax5043.c:371: axradio_cb_receive.st.error = AXRADIO_ERR_NOERROR;
      000C63 90 02 49         [24] 2573 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      000C66 E4               [12] 2574 	clr	a
      000C67 F0               [24] 2575 	movx	@dptr,a
                                   2576 ;	..\COMMON\easyax5043.c:372: axradio_cb_receive.st.rx.mac.raw = axradio_rxbuffer;
      000C68 90 02 62         [24] 2577 	mov	dptr,#(_axradio_cb_receive + 0x001e)
      000C6B 74 40            [12] 2578 	mov	a,#_axradio_rxbuffer
      000C6D F0               [24] 2579 	movx	@dptr,a
      000C6E 74 01            [12] 2580 	mov	a,#(_axradio_rxbuffer >> 8)
      000C70 A3               [24] 2581 	inc	dptr
      000C71 F0               [24] 2582 	movx	@dptr,a
                                   2583 ;	..\COMMON\easyax5043.c:373: if (AXRADIO_MODE_IS_STREAM_RECEIVE(axradio_mode)) {
      000C72 74 F8            [12] 2584 	mov	a,#0xf8
      000C74 55 08            [12] 2585 	anl	a,_axradio_mode
      000C76 FE               [12] 2586 	mov	r6,a
      000C77 BE 28 02         [24] 2587 	cjne	r6,#0x28,00272$
      000C7A 80 03            [24] 2588 	sjmp	00273$
      000C7C                       2589 00272$:
      000C7C 02 0D 08         [24] 2590 	ljmp	00127$
      000C7F                       2591 00273$:
                                   2592 ;	..\COMMON\easyax5043.c:374: axradio_cb_receive.st.rx.pktdata = axradio_rxbuffer;
      000C7F 90 02 64         [24] 2593 	mov	dptr,#(_axradio_cb_receive + 0x0020)
      000C82 74 40            [12] 2594 	mov	a,#_axradio_rxbuffer
      000C84 F0               [24] 2595 	movx	@dptr,a
      000C85 74 01            [12] 2596 	mov	a,#(_axradio_rxbuffer >> 8)
      000C87 A3               [24] 2597 	inc	dptr
      000C88 F0               [24] 2598 	movx	@dptr,a
                                   2599 ;	..\COMMON\easyax5043.c:375: axradio_cb_receive.st.rx.pktlen = len;
      000C89 8F 05            [24] 2600 	mov	ar5,r7
      000C8B 7E 00            [12] 2601 	mov	r6,#0x00
      000C8D 90 02 66         [24] 2602 	mov	dptr,#(_axradio_cb_receive + 0x0022)
      000C90 ED               [12] 2603 	mov	a,r5
      000C91 F0               [24] 2604 	movx	@dptr,a
      000C92 EE               [12] 2605 	mov	a,r6
      000C93 A3               [24] 2606 	inc	dptr
      000C94 F0               [24] 2607 	movx	@dptr,a
                                   2608 ;	..\COMMON\easyax5043.c:377: int8_t r = radio_read8(AX5043_REG_RSSI);
      000C95 90 40 40         [24] 2609 	mov	dptr,#0x4040
      000C98 E0               [24] 2610 	movx	a,@dptr
                                   2611 ;	..\COMMON\easyax5043.c:378: axradio_cb_receive.st.rx.phy.rssi = r - (int16_t)axradio_phy_rssioffset;
      000C99 FE               [12] 2612 	mov	r6,a
      000C9A 33               [12] 2613 	rlc	a
      000C9B 95 E0            [12] 2614 	subb	a,acc
      000C9D FD               [12] 2615 	mov	r5,a
      000C9E 90 4C A1         [24] 2616 	mov	dptr,#_axradio_phy_rssioffset
      000CA1 E4               [12] 2617 	clr	a
      000CA2 93               [24] 2618 	movc	a,@a+dptr
      000CA3 FC               [12] 2619 	mov	r4,a
      000CA4 33               [12] 2620 	rlc	a
      000CA5 95 E0            [12] 2621 	subb	a,acc
      000CA7 FB               [12] 2622 	mov	r3,a
      000CA8 EE               [12] 2623 	mov	a,r6
      000CA9 C3               [12] 2624 	clr	c
      000CAA 9C               [12] 2625 	subb	a,r4
      000CAB FE               [12] 2626 	mov	r6,a
      000CAC ED               [12] 2627 	mov	a,r5
      000CAD 9B               [12] 2628 	subb	a,r3
      000CAE FD               [12] 2629 	mov	r5,a
      000CAF 90 02 4E         [24] 2630 	mov	dptr,#(_axradio_cb_receive + 0x000a)
      000CB2 EE               [12] 2631 	mov	a,r6
      000CB3 F0               [24] 2632 	movx	@dptr,a
      000CB4 ED               [12] 2633 	mov	a,r5
      000CB5 A3               [24] 2634 	inc	dptr
      000CB6 F0               [24] 2635 	movx	@dptr,a
                                   2636 ;	..\COMMON\easyax5043.c:380: if (axradio_phy_innerfreqloop) {
      000CB7 90 4C 6F         [24] 2637 	mov	dptr,#_axradio_phy_innerfreqloop
      000CBA E4               [12] 2638 	clr	a
      000CBB 93               [24] 2639 	movc	a,@a+dptr
      000CBC 60 23            [24] 2640 	jz	00124$
                                   2641 ;	..\COMMON\easyax5043.c:381: axradio_cb_receive.st.rx.phy.offset.o = axradio_conv_freq_fromreg(signextend16(radio_read16(AX5043_REG_TRKFREQ1)));
      000CBE 90 00 50         [24] 2642 	mov	dptr,#0x0050
      000CC1 12 44 D1         [24] 2643 	lcall	_radio_read16
      000CC4 12 4C 3D         [24] 2644 	lcall	_signextend16
      000CC7 12 08 71         [24] 2645 	lcall	_axradio_conv_freq_fromreg
      000CCA AB 82            [24] 2646 	mov	r3,dpl
      000CCC AC 83            [24] 2647 	mov	r4,dph
      000CCE AD F0            [24] 2648 	mov	r5,b
      000CD0 FE               [12] 2649 	mov	r6,a
      000CD1 90 02 50         [24] 2650 	mov	dptr,#(_axradio_cb_receive + 0x000c)
      000CD4 EB               [12] 2651 	mov	a,r3
      000CD5 F0               [24] 2652 	movx	@dptr,a
      000CD6 EC               [12] 2653 	mov	a,r4
      000CD7 A3               [24] 2654 	inc	dptr
      000CD8 F0               [24] 2655 	movx	@dptr,a
      000CD9 ED               [12] 2656 	mov	a,r5
      000CDA A3               [24] 2657 	inc	dptr
      000CDB F0               [24] 2658 	movx	@dptr,a
      000CDC EE               [12] 2659 	mov	a,r6
      000CDD A3               [24] 2660 	inc	dptr
      000CDE F0               [24] 2661 	movx	@dptr,a
      000CDF 80 1E            [24] 2662 	sjmp	00125$
      000CE1                       2663 00124$:
                                   2664 ;	..\COMMON\easyax5043.c:383: axradio_cb_receive.st.rx.phy.offset.o = signextend20(radio_read24(AX5043_REG_TRKRFFREQ2));
      000CE1 90 00 4D         [24] 2665 	mov	dptr,#0x004d
      000CE4 12 43 98         [24] 2666 	lcall	_radio_read24
      000CE7 12 4B E2         [24] 2667 	lcall	_signextend20
      000CEA AB 82            [24] 2668 	mov	r3,dpl
      000CEC AC 83            [24] 2669 	mov	r4,dph
      000CEE AD F0            [24] 2670 	mov	r5,b
      000CF0 FE               [12] 2671 	mov	r6,a
      000CF1 90 02 50         [24] 2672 	mov	dptr,#(_axradio_cb_receive + 0x000c)
      000CF4 EB               [12] 2673 	mov	a,r3
      000CF5 F0               [24] 2674 	movx	@dptr,a
      000CF6 EC               [12] 2675 	mov	a,r4
      000CF7 A3               [24] 2676 	inc	dptr
      000CF8 F0               [24] 2677 	movx	@dptr,a
      000CF9 ED               [12] 2678 	mov	a,r5
      000CFA A3               [24] 2679 	inc	dptr
      000CFB F0               [24] 2680 	movx	@dptr,a
      000CFC EE               [12] 2681 	mov	a,r6
      000CFD A3               [24] 2682 	inc	dptr
      000CFE F0               [24] 2683 	movx	@dptr,a
      000CFF                       2684 00125$:
                                   2685 ;	..\COMMON\easyax5043.c:385: wtimer_add_callback(&axradio_cb_receive.cb);
      000CFF 90 02 44         [24] 2686 	mov	dptr,#_axradio_cb_receive
      000D02 12 42 C4         [24] 2687 	lcall	_wtimer_add_callback
                                   2688 ;	..\COMMON\easyax5043.c:386: break;
      000D05 02 0B B3         [24] 2689 	ljmp	00159$
      000D08                       2690 00127$:
                                   2691 ;	..\COMMON\easyax5043.c:388: axradio_cb_receive.st.rx.pktdata = &axradio_rxbuffer[axradio_framing_maclen];
      000D08 90 4C B5         [24] 2692 	mov	dptr,#_axradio_framing_maclen
      000D0B E4               [12] 2693 	clr	a
      000D0C 93               [24] 2694 	movc	a,@a+dptr
      000D0D FE               [12] 2695 	mov	r6,a
      000D0E 24 40            [12] 2696 	add	a,#_axradio_rxbuffer
      000D10 FC               [12] 2697 	mov	r4,a
      000D11 E4               [12] 2698 	clr	a
      000D12 34 01            [12] 2699 	addc	a,#(_axradio_rxbuffer >> 8)
      000D14 FD               [12] 2700 	mov	r5,a
      000D15 90 02 64         [24] 2701 	mov	dptr,#(_axradio_cb_receive + 0x0020)
      000D18 EC               [12] 2702 	mov	a,r4
      000D19 F0               [24] 2703 	movx	@dptr,a
      000D1A ED               [12] 2704 	mov	a,r5
      000D1B A3               [24] 2705 	inc	dptr
      000D1C F0               [24] 2706 	movx	@dptr,a
                                   2707 ;	..\COMMON\easyax5043.c:389: if (len < axradio_framing_maclen) {
      000D1D C3               [12] 2708 	clr	c
      000D1E EF               [12] 2709 	mov	a,r7
      000D1F 9E               [12] 2710 	subb	a,r6
      000D20 50 0A            [24] 2711 	jnc	00132$
                                   2712 ;	..\COMMON\easyax5043.c:391: axradio_cb_receive.st.rx.pktlen = 0;
      000D22 90 02 66         [24] 2713 	mov	dptr,#(_axradio_cb_receive + 0x0022)
      000D25 E4               [12] 2714 	clr	a
      000D26 F0               [24] 2715 	movx	@dptr,a
      000D27 A3               [24] 2716 	inc	dptr
      000D28 F0               [24] 2717 	movx	@dptr,a
      000D29 02 0B B3         [24] 2718 	ljmp	00159$
      000D2C                       2719 00132$:
                                   2720 ;	..\COMMON\easyax5043.c:393: len -= axradio_framing_maclen;
      000D2C EF               [12] 2721 	mov	a,r7
      000D2D C3               [12] 2722 	clr	c
      000D2E 9E               [12] 2723 	subb	a,r6
                                   2724 ;	..\COMMON\easyax5043.c:394: axradio_cb_receive.st.rx.pktlen = len;
      000D2F FD               [12] 2725 	mov	r5,a
      000D30 7E 00            [12] 2726 	mov	r6,#0x00
      000D32 90 02 66         [24] 2727 	mov	dptr,#(_axradio_cb_receive + 0x0022)
      000D35 ED               [12] 2728 	mov	a,r5
      000D36 F0               [24] 2729 	movx	@dptr,a
      000D37 EE               [12] 2730 	mov	a,r6
      000D38 A3               [24] 2731 	inc	dptr
      000D39 F0               [24] 2732 	movx	@dptr,a
                                   2733 ;	..\COMMON\easyax5043.c:395: wtimer_add_callback(&axradio_cb_receive.cb);
      000D3A 90 02 44         [24] 2734 	mov	dptr,#_axradio_cb_receive
      000D3D 12 42 C4         [24] 2735 	lcall	_wtimer_add_callback
                                   2736 ;	..\COMMON\easyax5043.c:396: if (axradio_mode == AXRADIO_MODE_SYNC_SLAVE ||
      000D40 74 32            [12] 2737 	mov	a,#0x32
      000D42 B5 08 02         [24] 2738 	cjne	a,_axradio_mode,00276$
      000D45 80 0A            [24] 2739 	sjmp	00128$
      000D47                       2740 00276$:
                                   2741 ;	..\COMMON\easyax5043.c:397: axradio_mode == AXRADIO_MODE_SYNC_ACK_SLAVE)
      000D47 74 33            [12] 2742 	mov	a,#0x33
      000D49 B5 08 02         [24] 2743 	cjne	a,_axradio_mode,00277$
      000D4C 80 03            [24] 2744 	sjmp	00278$
      000D4E                       2745 00277$:
      000D4E 02 0B B3         [24] 2746 	ljmp	00159$
      000D51                       2747 00278$:
      000D51                       2748 00128$:
                                   2749 ;	..\COMMON\easyax5043.c:398: wtimer_remove(&axradio_timer);
      000D51 90 02 9D         [24] 2750 	mov	dptr,#_axradio_timer
      000D54 12 47 8D         [24] 2751 	lcall	_wtimer_remove
                                   2752 ;	..\COMMON\easyax5043.c:400: break;
      000D57 02 0B B3         [24] 2753 	ljmp	00159$
                                   2754 ;	..\COMMON\easyax5043.c:402: case AX5043_FIFOCMD_RFFREQOFFS:
      000D5A                       2755 00134$:
                                   2756 ;	..\COMMON\easyax5043.c:403: if (axradio_phy_innerfreqloop || len != 3)
      000D5A 90 4C 6F         [24] 2757 	mov	dptr,#_axradio_phy_innerfreqloop
      000D5D E4               [12] 2758 	clr	a
      000D5E 93               [24] 2759 	movc	a,@a+dptr
      000D5F 60 03            [24] 2760 	jz	00279$
      000D61 02 0E BF         [24] 2761 	ljmp	00152$
      000D64                       2762 00279$:
      000D64 BF 03 02         [24] 2763 	cjne	r7,#0x03,00280$
      000D67 80 03            [24] 2764 	sjmp	00281$
      000D69                       2765 00280$:
      000D69 02 0E BF         [24] 2766 	ljmp	00152$
      000D6C                       2767 00281$:
                                   2768 ;	..\COMMON\easyax5043.c:405: i = radio_read8(AX5043_REG_FIFODATA);
      000D6C 90 40 29         [24] 2769 	mov	dptr,#0x4029
      000D6F E0               [24] 2770 	movx	a,@dptr
      000D70 FE               [12] 2771 	mov	r6,a
                                   2772 ;	..\COMMON\easyax5043.c:406: i &= 0x0F;
      000D71 53 06 0F         [24] 2773 	anl	ar6,#0x0f
                                   2774 ;	..\COMMON\easyax5043.c:407: i |= 1 + (uint8_t)~(i & 0x08);
      000D74 74 08            [12] 2775 	mov	a,#0x08
      000D76 5E               [12] 2776 	anl	a,r6
      000D77 F4               [12] 2777 	cpl	a
      000D78 FD               [12] 2778 	mov	r5,a
      000D79 0D               [12] 2779 	inc	r5
      000D7A ED               [12] 2780 	mov	a,r5
      000D7B 42 06            [12] 2781 	orl	ar6,a
                                   2782 ;	..\COMMON\easyax5043.c:408: axradio_cb_receive.st.rx.phy.offset.b.b3 = ((int8_t)i) >> 8;
      000D7D 8E 05            [24] 2783 	mov	ar5,r6
      000D7F ED               [12] 2784 	mov	a,r5
      000D80 33               [12] 2785 	rlc	a
      000D81 95 E0            [12] 2786 	subb	a,acc
      000D83 FD               [12] 2787 	mov	r5,a
      000D84 90 02 53         [24] 2788 	mov	dptr,#(_axradio_cb_receive + 0x000f)
      000D87 F0               [24] 2789 	movx	@dptr,a
                                   2790 ;	..\COMMON\easyax5043.c:409: axradio_cb_receive.st.rx.phy.offset.b.b2 = i;
      000D88 90 02 52         [24] 2791 	mov	dptr,#(_axradio_cb_receive + 0x000e)
      000D8B EE               [12] 2792 	mov	a,r6
      000D8C F0               [24] 2793 	movx	@dptr,a
                                   2794 ;	..\COMMON\easyax5043.c:410: axradio_cb_receive.st.rx.phy.offset.b.b1 = radio_read8(AX5043_REG_FIFODATA);
      000D8D 90 40 29         [24] 2795 	mov	dptr,#0x4029
      000D90 E0               [24] 2796 	movx	a,@dptr
      000D91 90 02 51         [24] 2797 	mov	dptr,#(_axradio_cb_receive + 0x000d)
      000D94 F0               [24] 2798 	movx	@dptr,a
                                   2799 ;	..\COMMON\easyax5043.c:411: axradio_cb_receive.st.rx.phy.offset.b.b0 = radio_read8(AX5043_REG_FIFODATA);
      000D95 90 40 29         [24] 2800 	mov	dptr,#0x4029
      000D98 E0               [24] 2801 	movx	a,@dptr
      000D99 FE               [12] 2802 	mov	r6,a
      000D9A 90 02 50         [24] 2803 	mov	dptr,#(_axradio_cb_receive + 0x000c)
      000D9D F0               [24] 2804 	movx	@dptr,a
                                   2805 ;	..\COMMON\easyax5043.c:412: break;
      000D9E 02 0B B3         [24] 2806 	ljmp	00159$
                                   2807 ;	..\COMMON\easyax5043.c:414: case AX5043_FIFOCMD_FREQOFFS:
      000DA1                       2808 00138$:
                                   2809 ;	..\COMMON\easyax5043.c:415: if (!axradio_phy_innerfreqloop || len != 2)
      000DA1 90 4C 6F         [24] 2810 	mov	dptr,#_axradio_phy_innerfreqloop
      000DA4 E4               [12] 2811 	clr	a
      000DA5 93               [24] 2812 	movc	a,@a+dptr
      000DA6 70 03            [24] 2813 	jnz	00282$
      000DA8 02 0E BF         [24] 2814 	ljmp	00152$
      000DAB                       2815 00282$:
      000DAB BF 02 02         [24] 2816 	cjne	r7,#0x02,00283$
      000DAE 80 03            [24] 2817 	sjmp	00284$
      000DB0                       2818 00283$:
      000DB0 02 0E BF         [24] 2819 	ljmp	00152$
      000DB3                       2820 00284$:
                                   2821 ;	..\COMMON\easyax5043.c:417: axradio_cb_receive.st.rx.phy.offset.b.b1 = radio_read8(AX5043_REG_FIFODATA);
      000DB3 90 40 29         [24] 2822 	mov	dptr,#0x4029
      000DB6 E0               [24] 2823 	movx	a,@dptr
      000DB7 90 02 51         [24] 2824 	mov	dptr,#(_axradio_cb_receive + 0x000d)
      000DBA F0               [24] 2825 	movx	@dptr,a
                                   2826 ;	..\COMMON\easyax5043.c:418: axradio_cb_receive.st.rx.phy.offset.b.b0 = radio_read8(AX5043_REG_FIFODATA);
      000DBB 90 40 29         [24] 2827 	mov	dptr,#0x4029
      000DBE E0               [24] 2828 	movx	a,@dptr
      000DBF 90 02 50         [24] 2829 	mov	dptr,#(_axradio_cb_receive + 0x000c)
      000DC2 F0               [24] 2830 	movx	@dptr,a
                                   2831 ;	..\COMMON\easyax5043.c:419: axradio_cb_receive.st.rx.phy.offset.o = axradio_conv_freq_fromreg(signextend16(axradio_cb_receive.st.rx.phy.offset.o));
      000DC3 90 02 50         [24] 2832 	mov	dptr,#(_axradio_cb_receive + 0x000c)
      000DC6 E0               [24] 2833 	movx	a,@dptr
      000DC7 FB               [12] 2834 	mov	r3,a
      000DC8 A3               [24] 2835 	inc	dptr
      000DC9 E0               [24] 2836 	movx	a,@dptr
      000DCA FC               [12] 2837 	mov	r4,a
      000DCB A3               [24] 2838 	inc	dptr
      000DCC E0               [24] 2839 	movx	a,@dptr
      000DCD A3               [24] 2840 	inc	dptr
      000DCE E0               [24] 2841 	movx	a,@dptr
      000DCF 8B 82            [24] 2842 	mov	dpl,r3
      000DD1 8C 83            [24] 2843 	mov	dph,r4
      000DD3 12 4C 3D         [24] 2844 	lcall	_signextend16
      000DD6 12 08 71         [24] 2845 	lcall	_axradio_conv_freq_fromreg
      000DD9 AB 82            [24] 2846 	mov	r3,dpl
      000DDB AC 83            [24] 2847 	mov	r4,dph
      000DDD AD F0            [24] 2848 	mov	r5,b
      000DDF FE               [12] 2849 	mov	r6,a
      000DE0 90 02 50         [24] 2850 	mov	dptr,#(_axradio_cb_receive + 0x000c)
      000DE3 EB               [12] 2851 	mov	a,r3
      000DE4 F0               [24] 2852 	movx	@dptr,a
      000DE5 EC               [12] 2853 	mov	a,r4
      000DE6 A3               [24] 2854 	inc	dptr
      000DE7 F0               [24] 2855 	movx	@dptr,a
      000DE8 ED               [12] 2856 	mov	a,r5
      000DE9 A3               [24] 2857 	inc	dptr
      000DEA F0               [24] 2858 	movx	@dptr,a
      000DEB EE               [12] 2859 	mov	a,r6
      000DEC A3               [24] 2860 	inc	dptr
      000DED F0               [24] 2861 	movx	@dptr,a
                                   2862 ;	..\COMMON\easyax5043.c:420: break;
      000DEE 02 0B B3         [24] 2863 	ljmp	00159$
                                   2864 ;	..\COMMON\easyax5043.c:422: case AX5043_FIFOCMD_RSSI:
      000DF1                       2865 00142$:
                                   2866 ;	..\COMMON\easyax5043.c:423: if (len != 1)
      000DF1 BF 01 02         [24] 2867 	cjne	r7,#0x01,00285$
      000DF4 80 03            [24] 2868 	sjmp	00286$
      000DF6                       2869 00285$:
      000DF6 02 0E BF         [24] 2870 	ljmp	00152$
      000DF9                       2871 00286$:
                                   2872 ;	..\COMMON\easyax5043.c:426: int8_t r = radio_read8(AX5043_REG_FIFODATA);
      000DF9 90 40 29         [24] 2873 	mov	dptr,#0x4029
      000DFC E0               [24] 2874 	movx	a,@dptr
                                   2875 ;	..\COMMON\easyax5043.c:427: axradio_cb_receive.st.rx.phy.rssi = r - (int16_t)axradio_phy_rssioffset;
      000DFD FE               [12] 2876 	mov	r6,a
      000DFE 33               [12] 2877 	rlc	a
      000DFF 95 E0            [12] 2878 	subb	a,acc
      000E01 FD               [12] 2879 	mov	r5,a
      000E02 90 4C A1         [24] 2880 	mov	dptr,#_axradio_phy_rssioffset
      000E05 E4               [12] 2881 	clr	a
      000E06 93               [24] 2882 	movc	a,@a+dptr
      000E07 FC               [12] 2883 	mov	r4,a
      000E08 33               [12] 2884 	rlc	a
      000E09 95 E0            [12] 2885 	subb	a,acc
      000E0B FB               [12] 2886 	mov	r3,a
      000E0C EE               [12] 2887 	mov	a,r6
      000E0D C3               [12] 2888 	clr	c
      000E0E 9C               [12] 2889 	subb	a,r4
      000E0F FE               [12] 2890 	mov	r6,a
      000E10 ED               [12] 2891 	mov	a,r5
      000E11 9B               [12] 2892 	subb	a,r3
      000E12 FD               [12] 2893 	mov	r5,a
      000E13 90 02 4E         [24] 2894 	mov	dptr,#(_axradio_cb_receive + 0x000a)
      000E16 EE               [12] 2895 	mov	a,r6
      000E17 F0               [24] 2896 	movx	@dptr,a
      000E18 ED               [12] 2897 	mov	a,r5
      000E19 A3               [24] 2898 	inc	dptr
      000E1A F0               [24] 2899 	movx	@dptr,a
                                   2900 ;	..\COMMON\easyax5043.c:429: break;
      000E1B 02 0B B3         [24] 2901 	ljmp	00159$
                                   2902 ;	..\COMMON\easyax5043.c:431: case AX5043_FIFOCMD_TIMER:
      000E1E                       2903 00145$:
                                   2904 ;	..\COMMON\easyax5043.c:432: if (len != 3)
      000E1E BF 03 02         [24] 2905 	cjne	r7,#0x03,00287$
      000E21 80 03            [24] 2906 	sjmp	00288$
      000E23                       2907 00287$:
      000E23 02 0E BF         [24] 2908 	ljmp	00152$
      000E26                       2909 00288$:
                                   2910 ;	..\COMMON\easyax5043.c:436: axradio_cb_receive.st.time.b.b3 = 0;
      000E26 90 02 4D         [24] 2911 	mov	dptr,#(_axradio_cb_receive + 0x0009)
      000E29 E4               [12] 2912 	clr	a
      000E2A F0               [24] 2913 	movx	@dptr,a
                                   2914 ;	..\COMMON\easyax5043.c:437: axradio_cb_receive.st.time.b.b2 = radio_read8(AX5043_REG_FIFODATA);
      000E2B 90 40 29         [24] 2915 	mov	dptr,#0x4029
      000E2E E0               [24] 2916 	movx	a,@dptr
      000E2F 90 02 4C         [24] 2917 	mov	dptr,#(_axradio_cb_receive + 0x0008)
      000E32 F0               [24] 2918 	movx	@dptr,a
                                   2919 ;	..\COMMON\easyax5043.c:438: axradio_cb_receive.st.time.b.b1 = radio_read8(AX5043_REG_FIFODATA);
      000E33 90 40 29         [24] 2920 	mov	dptr,#0x4029
      000E36 E0               [24] 2921 	movx	a,@dptr
      000E37 90 02 4B         [24] 2922 	mov	dptr,#(_axradio_cb_receive + 0x0007)
      000E3A F0               [24] 2923 	movx	@dptr,a
                                   2924 ;	..\COMMON\easyax5043.c:439: axradio_cb_receive.st.time.b.b0 = radio_read8(AX5043_REG_FIFODATA);
      000E3B 90 40 29         [24] 2925 	mov	dptr,#0x4029
      000E3E E0               [24] 2926 	movx	a,@dptr
      000E3F FE               [12] 2927 	mov	r6,a
      000E40 90 02 4A         [24] 2928 	mov	dptr,#(_axradio_cb_receive + 0x0006)
      000E43 F0               [24] 2929 	movx	@dptr,a
                                   2930 ;	..\COMMON\easyax5043.c:440: break;
      000E44 02 0B B3         [24] 2931 	ljmp	00159$
                                   2932 ;	..\COMMON\easyax5043.c:442: case AX5043_FIFOCMD_ANTRSSI:
      000E47                       2933 00148$:
                                   2934 ;	..\COMMON\easyax5043.c:443: if (!len)
      000E47 EF               [12] 2935 	mov	a,r7
      000E48 70 03            [24] 2936 	jnz	00289$
      000E4A 02 0B B3         [24] 2937 	ljmp	00159$
      000E4D                       2938 00289$:
                                   2939 ;	..\COMMON\easyax5043.c:445: update_timeanchor();
      000E4D C0 07            [24] 2940 	push	ar7
      000E4F 12 0A 7C         [24] 2941 	lcall	_update_timeanchor
                                   2942 ;	..\COMMON\easyax5043.c:446: wtimer_remove_callback(&axradio_cb_channelstate.cb);
      000E52 90 02 72         [24] 2943 	mov	dptr,#_axradio_cb_channelstate
      000E55 12 48 82         [24] 2944 	lcall	_wtimer_remove_callback
                                   2945 ;	..\COMMON\easyax5043.c:447: axradio_cb_channelstate.st.error = AXRADIO_ERR_NOERROR;
      000E58 90 02 77         [24] 2946 	mov	dptr,#(_axradio_cb_channelstate + 0x0005)
      000E5B E4               [12] 2947 	clr	a
      000E5C F0               [24] 2948 	movx	@dptr,a
                                   2949 ;	..\COMMON\easyax5043.c:449: int8_t r = radio_read8(AX5043_REG_FIFODATA);
      000E5D 90 40 29         [24] 2950 	mov	dptr,#0x4029
      000E60 E0               [24] 2951 	movx	a,@dptr
                                   2952 ;	..\COMMON\easyax5043.c:450: axradio_cb_channelstate.st.cs.rssi = r - (int16_t)axradio_phy_rssioffset;
      000E61 FE               [12] 2953 	mov	r6,a
      000E62 FC               [12] 2954 	mov	r4,a
      000E63 33               [12] 2955 	rlc	a
      000E64 95 E0            [12] 2956 	subb	a,acc
      000E66 FD               [12] 2957 	mov	r5,a
      000E67 90 4C A1         [24] 2958 	mov	dptr,#_axradio_phy_rssioffset
      000E6A E4               [12] 2959 	clr	a
      000E6B 93               [24] 2960 	movc	a,@a+dptr
      000E6C FB               [12] 2961 	mov	r3,a
      000E6D 33               [12] 2962 	rlc	a
      000E6E 95 E0            [12] 2963 	subb	a,acc
      000E70 FA               [12] 2964 	mov	r2,a
      000E71 EC               [12] 2965 	mov	a,r4
      000E72 C3               [12] 2966 	clr	c
      000E73 9B               [12] 2967 	subb	a,r3
      000E74 FC               [12] 2968 	mov	r4,a
      000E75 ED               [12] 2969 	mov	a,r5
      000E76 9A               [12] 2970 	subb	a,r2
      000E77 FD               [12] 2971 	mov	r5,a
      000E78 90 02 7C         [24] 2972 	mov	dptr,#(_axradio_cb_channelstate + 0x000a)
      000E7B EC               [12] 2973 	mov	a,r4
      000E7C F0               [24] 2974 	movx	@dptr,a
      000E7D ED               [12] 2975 	mov	a,r5
      000E7E A3               [24] 2976 	inc	dptr
      000E7F F0               [24] 2977 	movx	@dptr,a
                                   2978 ;	..\COMMON\easyax5043.c:451: axradio_cb_channelstate.st.cs.busy = r >= axradio_phy_channelbusy;
      000E80 90 4C A3         [24] 2979 	mov	dptr,#_axradio_phy_channelbusy
      000E83 E4               [12] 2980 	clr	a
      000E84 93               [24] 2981 	movc	a,@a+dptr
      000E85 FD               [12] 2982 	mov	r5,a
      000E86 C3               [12] 2983 	clr	c
      000E87 EE               [12] 2984 	mov	a,r6
      000E88 64 80            [12] 2985 	xrl	a,#0x80
      000E8A 8D F0            [24] 2986 	mov	b,r5
      000E8C 63 F0 80         [24] 2987 	xrl	b,#0x80
      000E8F 95 F0            [12] 2988 	subb	a,b
      000E91 B3               [12] 2989 	cpl	c
      000E92 92 08            [24] 2990 	mov	b0,c
      000E94 E4               [12] 2991 	clr	a
      000E95 33               [12] 2992 	rlc	a
      000E96 90 02 7E         [24] 2993 	mov	dptr,#(_axradio_cb_channelstate + 0x000c)
      000E99 F0               [24] 2994 	movx	@dptr,a
                                   2995 ;	..\COMMON\easyax5043.c:453: axradio_cb_channelstate.st.time.t = axradio_timeanchor.radiotimer;
      000E9A 90 00 29         [24] 2996 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      000E9D E0               [24] 2997 	movx	a,@dptr
      000E9E FB               [12] 2998 	mov	r3,a
      000E9F A3               [24] 2999 	inc	dptr
      000EA0 E0               [24] 3000 	movx	a,@dptr
      000EA1 FC               [12] 3001 	mov	r4,a
      000EA2 A3               [24] 3002 	inc	dptr
      000EA3 E0               [24] 3003 	movx	a,@dptr
      000EA4 FD               [12] 3004 	mov	r5,a
      000EA5 A3               [24] 3005 	inc	dptr
      000EA6 E0               [24] 3006 	movx	a,@dptr
      000EA7 FE               [12] 3007 	mov	r6,a
      000EA8 90 02 78         [24] 3008 	mov	dptr,#(_axradio_cb_channelstate + 0x0006)
      000EAB EB               [12] 3009 	mov	a,r3
      000EAC F0               [24] 3010 	movx	@dptr,a
      000EAD EC               [12] 3011 	mov	a,r4
      000EAE A3               [24] 3012 	inc	dptr
      000EAF F0               [24] 3013 	movx	@dptr,a
      000EB0 ED               [12] 3014 	mov	a,r5
      000EB1 A3               [24] 3015 	inc	dptr
      000EB2 F0               [24] 3016 	movx	@dptr,a
      000EB3 EE               [12] 3017 	mov	a,r6
      000EB4 A3               [24] 3018 	inc	dptr
      000EB5 F0               [24] 3019 	movx	@dptr,a
                                   3020 ;	..\COMMON\easyax5043.c:454: wtimer_add_callback(&axradio_cb_channelstate.cb);
      000EB6 90 02 72         [24] 3021 	mov	dptr,#_axradio_cb_channelstate
      000EB9 12 42 C4         [24] 3022 	lcall	_wtimer_add_callback
      000EBC D0 07            [24] 3023 	pop	ar7
                                   3024 ;	..\COMMON\easyax5043.c:455: --len;
      000EBE 1F               [12] 3025 	dec	r7
                                   3026 ;	..\COMMON\easyax5043.c:460: dropchunk:
      000EBF                       3027 00152$:
                                   3028 ;	..\COMMON\easyax5043.c:461: if (!len)
      000EBF EF               [12] 3029 	mov	a,r7
      000EC0 70 03            [24] 3030 	jnz	00290$
      000EC2 02 0B B3         [24] 3031 	ljmp	00159$
      000EC5                       3032 00290$:
                                   3033 ;	..\COMMON\easyax5043.c:464: do {
      000EC5                       3034 00155$:
                                   3035 ;	..\COMMON\easyax5043.c:465: radio_read8(AX5043_REG_FIFODATA);	// purge FIFO
      000EC5 90 40 29         [24] 3036 	mov	dptr,#0x4029
      000EC8 E0               [24] 3037 	movx	a,@dptr
                                   3038 ;	..\COMMON\easyax5043.c:467: while (--i);
      000EC9 DF FA            [24] 3039 	djnz	r7,00155$
                                   3040 ;	..\COMMON\easyax5043.c:469: } // end switch(fifo_cmd)
      000ECB 02 0B B3         [24] 3041 	ljmp	00159$
                                   3042 ;------------------------------------------------------------
                                   3043 ;Allocation info for local variables in function 'transmit_isr'
                                   3044 ;------------------------------------------------------------
                                   3045 ;cnt                       Allocated to registers r7 
                                   3046 ;byte                      Allocated to registers r7 
                                   3047 ;len_byte                  Allocated to registers r4 
                                   3048 ;i                         Allocated to registers r3 
                                   3049 ;byte                      Allocated to registers r6 
                                   3050 ;flags                     Allocated to registers r6 
                                   3051 ;len                       Allocated to registers r4 r5 
                                   3052 ;------------------------------------------------------------
                                   3053 ;	..\COMMON\easyax5043.c:473: static __reentrantb void transmit_isr(void) __reentrant
                                   3054 ;	-----------------------------------------
                                   3055 ;	 function transmit_isr
                                   3056 ;	-----------------------------------------
      000ECE                       3057 _transmit_isr:
                                   3058 ;	..\COMMON\easyax5043.c:612: axradio_trxstate = trxstate_tx_waitdone;
      000ECE                       3059 00226$:
                                   3060 ;	..\COMMON\easyax5043.c:476: uint8_t cnt = radio_read8(AX5043_REG_FIFOFREE0);
      000ECE 90 40 2D         [24] 3061 	mov	dptr,#0x402d
      000ED1 E0               [24] 3062 	movx	a,@dptr
      000ED2 FF               [12] 3063 	mov	r7,a
                                   3064 ;	..\COMMON\easyax5043.c:477: if (radio_read8(AX5043_REG_FIFOFREE1))
      000ED3 90 40 2C         [24] 3065 	mov	dptr,#0x402c
      000ED6 E0               [24] 3066 	movx	a,@dptr
      000ED7 60 02            [24] 3067 	jz	00102$
                                   3068 ;	..\COMMON\easyax5043.c:478: cnt = 0xff;
      000ED9 7F FF            [12] 3069 	mov	r7,#0xff
      000EDB                       3070 00102$:
                                   3071 ;	..\COMMON\easyax5043.c:479: switch (axradio_trxstate) {
      000EDB AE 09            [24] 3072 	mov	r6,_axradio_trxstate
      000EDD BE 0A 02         [24] 3073 	cjne	r6,#0x0a,00315$
      000EE0 80 0D            [24] 3074 	sjmp	00103$
      000EE2                       3075 00315$:
      000EE2 BE 0B 03         [24] 3076 	cjne	r6,#0x0b,00316$
      000EE5 02 0F 84         [24] 3077 	ljmp	00127$
      000EE8                       3078 00316$:
      000EE8 BE 0C 03         [24] 3079 	cjne	r6,#0x0c,00317$
      000EEB 02 11 5A         [24] 3080 	ljmp	00189$
      000EEE                       3081 00317$:
      000EEE 22               [24] 3082 	ret
                                   3083 ;	..\COMMON\easyax5043.c:480: case trxstate_tx_longpreamble:
      000EEF                       3084 00103$:
                                   3085 ;	..\COMMON\easyax5043.c:481: if (!axradio_txbuffer_cnt) {
      000EEF 90 00 16         [24] 3086 	mov	dptr,#_axradio_txbuffer_cnt
      000EF2 E0               [24] 3087 	movx	a,@dptr
      000EF3 FD               [12] 3088 	mov	r5,a
      000EF4 A3               [24] 3089 	inc	dptr
      000EF5 E0               [24] 3090 	movx	a,@dptr
      000EF6 FE               [12] 3091 	mov	r6,a
      000EF7 4D               [12] 3092 	orl	a,r5
      000EF8 70 37            [24] 3093 	jnz	00109$
                                   3094 ;	..\COMMON\easyax5043.c:482: axradio_trxstate = trxstate_tx_shortpreamble;
      000EFA 75 09 0B         [24] 3095 	mov	_axradio_trxstate,#0x0b
                                   3096 ;	..\COMMON\easyax5043.c:483: if( axradio_mode == AXRADIO_MODE_WOR_TRANSMIT || axradio_mode == AXRADIO_MODE_WOR_ACK_TRANSMIT )
      000EFD 74 11            [12] 3097 	mov	a,#0x11
      000EFF B5 08 02         [24] 3098 	cjne	a,_axradio_mode,00319$
      000F02 80 05            [24] 3099 	sjmp	00104$
      000F04                       3100 00319$:
      000F04 74 13            [12] 3101 	mov	a,#0x13
      000F06 B5 08 14         [24] 3102 	cjne	a,_axradio_mode,00105$
      000F09                       3103 00104$:
                                   3104 ;	..\COMMON\easyax5043.c:484: axradio_txbuffer_cnt = axradio_phy_preamble_wor_len;
      000F09 90 4C AB         [24] 3105 	mov	dptr,#_axradio_phy_preamble_wor_len
      000F0C E4               [12] 3106 	clr	a
      000F0D 93               [24] 3107 	movc	a,@a+dptr
      000F0E FB               [12] 3108 	mov	r3,a
      000F0F 74 01            [12] 3109 	mov	a,#0x01
      000F11 93               [24] 3110 	movc	a,@a+dptr
      000F12 FC               [12] 3111 	mov	r4,a
      000F13 90 00 16         [24] 3112 	mov	dptr,#_axradio_txbuffer_cnt
      000F16 EB               [12] 3113 	mov	a,r3
      000F17 F0               [24] 3114 	movx	@dptr,a
      000F18 EC               [12] 3115 	mov	a,r4
      000F19 A3               [24] 3116 	inc	dptr
      000F1A F0               [24] 3117 	movx	@dptr,a
      000F1B 80 67            [24] 3118 	sjmp	00127$
      000F1D                       3119 00105$:
                                   3120 ;	..\COMMON\easyax5043.c:486: axradio_txbuffer_cnt = axradio_phy_preamble_len;
      000F1D 90 4C AF         [24] 3121 	mov	dptr,#_axradio_phy_preamble_len
      000F20 E4               [12] 3122 	clr	a
      000F21 93               [24] 3123 	movc	a,@a+dptr
      000F22 FB               [12] 3124 	mov	r3,a
      000F23 74 01            [12] 3125 	mov	a,#0x01
      000F25 93               [24] 3126 	movc	a,@a+dptr
      000F26 FC               [12] 3127 	mov	r4,a
      000F27 90 00 16         [24] 3128 	mov	dptr,#_axradio_txbuffer_cnt
      000F2A EB               [12] 3129 	mov	a,r3
      000F2B F0               [24] 3130 	movx	@dptr,a
      000F2C EC               [12] 3131 	mov	a,r4
      000F2D A3               [24] 3132 	inc	dptr
      000F2E F0               [24] 3133 	movx	@dptr,a
                                   3134 ;	..\COMMON\easyax5043.c:487: goto shortpreamble;
      000F2F 80 53            [24] 3135 	sjmp	00127$
      000F31                       3136 00109$:
                                   3137 ;	..\COMMON\easyax5043.c:489: if (cnt < 4)
      000F31 BF 04 00         [24] 3138 	cjne	r7,#0x04,00322$
      000F34                       3139 00322$:
      000F34 50 03            [24] 3140 	jnc	00323$
      000F36 02 12 01         [24] 3141 	ljmp	00220$
      000F39                       3142 00323$:
                                   3143 ;	..\COMMON\easyax5043.c:491: cnt = 7;
      000F39 7F 07            [12] 3144 	mov	r7,#0x07
                                   3145 ;	..\COMMON\easyax5043.c:492: if (axradio_txbuffer_cnt < 7)
      000F3B C3               [12] 3146 	clr	c
      000F3C ED               [12] 3147 	mov	a,r5
      000F3D 94 07            [12] 3148 	subb	a,#0x07
      000F3F EE               [12] 3149 	mov	a,r6
      000F40 94 00            [12] 3150 	subb	a,#0x00
      000F42 50 02            [24] 3151 	jnc	00113$
                                   3152 ;	..\COMMON\easyax5043.c:493: cnt = axradio_txbuffer_cnt;
      000F44 8D 07            [24] 3153 	mov	ar7,r5
      000F46                       3154 00113$:
                                   3155 ;	..\COMMON\easyax5043.c:494: axradio_txbuffer_cnt -= cnt;
      000F46 8F 05            [24] 3156 	mov	ar5,r7
      000F48 7E 00            [12] 3157 	mov	r6,#0x00
      000F4A 90 00 16         [24] 3158 	mov	dptr,#_axradio_txbuffer_cnt
      000F4D E0               [24] 3159 	movx	a,@dptr
      000F4E FB               [12] 3160 	mov	r3,a
      000F4F A3               [24] 3161 	inc	dptr
      000F50 E0               [24] 3162 	movx	a,@dptr
      000F51 FC               [12] 3163 	mov	r4,a
      000F52 90 00 16         [24] 3164 	mov	dptr,#_axradio_txbuffer_cnt
      000F55 EB               [12] 3165 	mov	a,r3
      000F56 C3               [12] 3166 	clr	c
      000F57 9D               [12] 3167 	subb	a,r5
      000F58 F0               [24] 3168 	movx	@dptr,a
      000F59 EC               [12] 3169 	mov	a,r4
      000F5A 9E               [12] 3170 	subb	a,r6
      000F5B A3               [24] 3171 	inc	dptr
      000F5C F0               [24] 3172 	movx	@dptr,a
                                   3173 ;	..\COMMON\easyax5043.c:495: cnt <<= 5;
      000F5D EF               [12] 3174 	mov	a,r7
      000F5E C4               [12] 3175 	swap	a
      000F5F 23               [12] 3176 	rl	a
      000F60 54 E0            [12] 3177 	anl	a,#0xe0
      000F62 FF               [12] 3178 	mov	r7,a
                                   3179 ;	..\COMMON\easyax5043.c:496: radio_write8(AX5043_REG_FIFODATA, (AX5043_FIFOCMD_REPEATDATA | (3 << 5)));
      000F63 90 40 29         [24] 3180 	mov	dptr,#0x4029
      000F66 74 62            [12] 3181 	mov	a,#0x62
      000F68 F0               [24] 3182 	movx	@dptr,a
                                   3183 ;	..\COMMON\easyax5043.c:497: radio_write8(AX5043_REG_FIFODATA, axradio_phy_preamble_flags);
      000F69 90 4C B2         [24] 3184 	mov	dptr,#_axradio_phy_preamble_flags
      000F6C E4               [12] 3185 	clr	a
      000F6D 93               [24] 3186 	movc	a,@a+dptr
      000F6E 90 40 29         [24] 3187 	mov	dptr,#0x4029
      000F71 F0               [24] 3188 	movx	@dptr,a
                                   3189 ;	..\COMMON\easyax5043.c:498: radio_write8(AX5043_REG_FIFODATA, cnt);
      000F72 90 40 29         [24] 3190 	mov	dptr,#0x4029
      000F75 EF               [12] 3191 	mov	a,r7
      000F76 F0               [24] 3192 	movx	@dptr,a
                                   3193 ;	..\COMMON\easyax5043.c:499: radio_write8(AX5043_REG_FIFODATA, axradio_phy_preamble_byte);
      000F77 90 4C B1         [24] 3194 	mov	dptr,#_axradio_phy_preamble_byte
      000F7A E4               [12] 3195 	clr	a
      000F7B 93               [24] 3196 	movc	a,@a+dptr
      000F7C FE               [12] 3197 	mov	r6,a
      000F7D 90 40 29         [24] 3198 	mov	dptr,#0x4029
      000F80 F0               [24] 3199 	movx	@dptr,a
                                   3200 ;	..\COMMON\easyax5043.c:500: break;
      000F81 02 0E CE         [24] 3201 	ljmp	00226$
                                   3202 ;	..\COMMON\easyax5043.c:503: shortpreamble:
      000F84                       3203 00127$:
                                   3204 ;	..\COMMON\easyax5043.c:504: if (!axradio_txbuffer_cnt) {
      000F84 90 00 16         [24] 3205 	mov	dptr,#_axradio_txbuffer_cnt
      000F87 E0               [24] 3206 	movx	a,@dptr
      000F88 FD               [12] 3207 	mov	r5,a
      000F89 A3               [24] 3208 	inc	dptr
      000F8A E0               [24] 3209 	movx	a,@dptr
      000F8B FE               [12] 3210 	mov	r6,a
      000F8C 4D               [12] 3211 	orl	a,r5
      000F8D 60 03            [24] 3212 	jz	00325$
      000F8F 02 10 6B         [24] 3213 	ljmp	00158$
      000F92                       3214 00325$:
                                   3215 ;	..\COMMON\easyax5043.c:505: if (cnt < 15)
      000F92 BF 0F 00         [24] 3216 	cjne	r7,#0x0f,00326$
      000F95                       3217 00326$:
      000F95 50 03            [24] 3218 	jnc	00327$
      000F97 02 12 01         [24] 3219 	ljmp	00220$
      000F9A                       3220 00327$:
                                   3221 ;	..\COMMON\easyax5043.c:507: if (axradio_phy_preamble_appendbits) {
      000F9A 90 4C B3         [24] 3222 	mov	dptr,#_axradio_phy_preamble_appendbits
      000F9D E4               [12] 3223 	clr	a
      000F9E 93               [24] 3224 	movc	a,@a+dptr
      000F9F FC               [12] 3225 	mov	r4,a
      000FA0 60 6F            [24] 3226 	jz	00143$
                                   3227 ;	..\COMMON\easyax5043.c:509: radio_write8(AX5043_REG_FIFODATA, (AX5043_FIFOCMD_DATA | (2 << 5)));
                                   3228 ;	..\COMMON\easyax5043.c:510: radio_write8(AX5043_REG_FIFODATA, 0x1C);
      000FA2 90 40 29         [24] 3229 	mov	dptr,#0x4029
      000FA5 74 41            [12] 3230 	mov	a,#0x41
      000FA7 F0               [24] 3231 	movx	@dptr,a
      000FA8 74 1C            [12] 3232 	mov	a,#0x1c
      000FAA F0               [24] 3233 	movx	@dptr,a
                                   3234 ;	..\COMMON\easyax5043.c:511: byte = axradio_phy_preamble_appendpattern;
      000FAB 90 4C B4         [24] 3235 	mov	dptr,#_axradio_phy_preamble_appendpattern
      000FAE E4               [12] 3236 	clr	a
      000FAF 93               [24] 3237 	movc	a,@a+dptr
      000FB0 FB               [12] 3238 	mov	r3,a
      000FB1 FF               [12] 3239 	mov	r7,a
                                   3240 ;	..\COMMON\easyax5043.c:512: if (radio_read8(AX5043_REG_PKTADDRCFG) & 0x80) {
      000FB2 90 42 00         [24] 3241 	mov	dptr,#0x4200
      000FB5 E0               [24] 3242 	movx	a,@dptr
      000FB6 FA               [12] 3243 	mov	r2,a
      000FB7 30 E7 26         [24] 3244 	jnb	acc.7,00137$
                                   3245 ;	..\COMMON\easyax5043.c:514: byte &= 0xFF << (8-axradio_phy_preamble_appendbits);
      000FBA 74 08            [12] 3246 	mov	a,#0x08
      000FBC C3               [12] 3247 	clr	c
      000FBD 9C               [12] 3248 	subb	a,r4
      000FBE F5 F0            [12] 3249 	mov	b,a
      000FC0 05 F0            [12] 3250 	inc	b
      000FC2 74 FF            [12] 3251 	mov	a,#0xff
      000FC4 80 02            [24] 3252 	sjmp	00332$
      000FC6                       3253 00330$:
      000FC6 25 E0            [12] 3254 	add	a,acc
      000FC8                       3255 00332$:
      000FC8 D5 F0 FB         [24] 3256 	djnz	b,00330$
      000FCB FA               [12] 3257 	mov	r2,a
      000FCC 52 07            [12] 3258 	anl	ar7,a
                                   3259 ;	..\COMMON\easyax5043.c:515: byte |= 0x80 >> axradio_phy_preamble_appendbits;
      000FCE 8C F0            [24] 3260 	mov	b,r4
      000FD0 05 F0            [12] 3261 	inc	b
      000FD2 74 80            [12] 3262 	mov	a,#0x80
      000FD4 80 02            [24] 3263 	sjmp	00334$
      000FD6                       3264 00333$:
      000FD6 C3               [12] 3265 	clr	c
      000FD7 13               [12] 3266 	rrc	a
      000FD8                       3267 00334$:
      000FD8 D5 F0 FB         [24] 3268 	djnz	b,00333$
      000FDB FA               [12] 3269 	mov	r2,a
      000FDC 42 07            [12] 3270 	orl	ar7,a
      000FDE 80 2C            [24] 3271 	sjmp	00139$
      000FE0                       3272 00137$:
                                   3273 ;	..\COMMON\easyax5043.c:518: byte &= 0xFF >> (8-axradio_phy_preamble_appendbits);
      000FE0 8C 02            [24] 3274 	mov	ar2,r4
      000FE2 7B 00            [12] 3275 	mov	r3,#0x00
      000FE4 74 08            [12] 3276 	mov	a,#0x08
      000FE6 C3               [12] 3277 	clr	c
      000FE7 9A               [12] 3278 	subb	a,r2
      000FE8 FA               [12] 3279 	mov	r2,a
      000FE9 E4               [12] 3280 	clr	a
      000FEA 9B               [12] 3281 	subb	a,r3
      000FEB FB               [12] 3282 	mov	r3,a
      000FEC 8A F0            [24] 3283 	mov	b,r2
      000FEE 05 F0            [12] 3284 	inc	b
      000FF0 74 FF            [12] 3285 	mov	a,#0xff
      000FF2 80 02            [24] 3286 	sjmp	00336$
      000FF4                       3287 00335$:
      000FF4 C3               [12] 3288 	clr	c
      000FF5 13               [12] 3289 	rrc	a
      000FF6                       3290 00336$:
      000FF6 D5 F0 FB         [24] 3291 	djnz	b,00335$
      000FF9 FA               [12] 3292 	mov	r2,a
      000FFA 52 07            [12] 3293 	anl	ar7,a
                                   3294 ;	..\COMMON\easyax5043.c:519: byte |= 0x01 << axradio_phy_preamble_appendbits;
      000FFC 8C F0            [24] 3295 	mov	b,r4
      000FFE 05 F0            [12] 3296 	inc	b
      001000 74 01            [12] 3297 	mov	a,#0x01
      001002 80 02            [24] 3298 	sjmp	00339$
      001004                       3299 00337$:
      001004 25 E0            [12] 3300 	add	a,acc
      001006                       3301 00339$:
      001006 D5 F0 FB         [24] 3302 	djnz	b,00337$
      001009 FC               [12] 3303 	mov	r4,a
      00100A 42 07            [12] 3304 	orl	ar7,a
                                   3305 ;	..\COMMON\easyax5043.c:521: radio_write8(AX5043_REG_FIFODATA, byte);
      00100C                       3306 00139$:
      00100C 90 40 29         [24] 3307 	mov	dptr,#0x4029
      00100F EF               [12] 3308 	mov	a,r7
      001010 F0               [24] 3309 	movx	@dptr,a
      001011                       3310 00143$:
                                   3311 ;	..\COMMON\easyax5043.c:527: if ((radio_read8(AX5043_REG_FRAMING) & 0x0E) == 0x06 && axradio_framing_synclen) {
      001011 90 40 12         [24] 3312 	mov	dptr,#0x4012
      001014 E0               [24] 3313 	movx	a,@dptr
      001015 FC               [12] 3314 	mov	r4,a
      001016 53 04 0E         [24] 3315 	anl	ar4,#0x0e
      001019 BC 06 49         [24] 3316 	cjne	r4,#0x06,00155$
      00101C 90 4C BD         [24] 3317 	mov	dptr,#_axradio_framing_synclen
      00101F E4               [12] 3318 	clr	a
      001020 93               [24] 3319 	movc	a,@a+dptr
      001021 FC               [12] 3320 	mov	r4,a
      001022 E4               [12] 3321 	clr	a
      001023 93               [24] 3322 	movc	a,@a+dptr
      001024 60 3F            [24] 3323 	jz	00155$
                                   3324 ;	..\COMMON\easyax5043.c:529: uint8_t len_byte = axradio_framing_synclen;
                                   3325 ;	..\COMMON\easyax5043.c:530: uint8_t i = (len_byte & 0x07) ? 0x04 : 0;
      001026 EC               [12] 3326 	mov	a,r4
      001027 54 07            [12] 3327 	anl	a,#0x07
      001029 60 02            [24] 3328 	jz	00230$
      00102B 74 04            [12] 3329 	mov	a,#0x04
      00102D                       3330 00230$:
      00102D FB               [12] 3331 	mov	r3,a
                                   3332 ;	..\COMMON\easyax5043.c:532: len_byte += 7;
      00102E 74 07            [12] 3333 	mov	a,#0x07
      001030 2C               [12] 3334 	add	a,r4
                                   3335 ;	..\COMMON\easyax5043.c:533: len_byte >>= 3;
      001031 C4               [12] 3336 	swap	a
      001032 23               [12] 3337 	rl	a
      001033 54 1F            [12] 3338 	anl	a,#0x1f
                                   3339 ;	..\COMMON\easyax5043.c:534: radio_write8(AX5043_REG_FIFODATA, (AX5043_FIFOCMD_DATA | ((len_byte + 1) << 5)));
      001035 FC               [12] 3340 	mov	r4,a
      001036 04               [12] 3341 	inc	a
      001037 C4               [12] 3342 	swap	a
      001038 23               [12] 3343 	rl	a
      001039 54 E0            [12] 3344 	anl	a,#0xe0
      00103B FA               [12] 3345 	mov	r2,a
      00103C 43 02 01         [24] 3346 	orl	ar2,#0x01
      00103F 90 40 29         [24] 3347 	mov	dptr,#0x4029
      001042 EA               [12] 3348 	mov	a,r2
      001043 F0               [24] 3349 	movx	@dptr,a
                                   3350 ;	..\COMMON\easyax5043.c:535: radio_write8(AX5043_REG_FIFODATA, axradio_framing_syncflags | i);
      001044 90 4C C2         [24] 3351 	mov	dptr,#_axradio_framing_syncflags
      001047 E4               [12] 3352 	clr	a
      001048 93               [24] 3353 	movc	a,@a+dptr
      001049 FA               [12] 3354 	mov	r2,a
      00104A 42 03            [12] 3355 	orl	ar3,a
      00104C 90 40 29         [24] 3356 	mov	dptr,#0x4029
      00104F EB               [12] 3357 	mov	a,r3
      001050 F0               [24] 3358 	movx	@dptr,a
                                   3359 ;	..\COMMON\easyax5043.c:536: for (i = 0; i < len_byte; ++i) {
      001051 7B 00            [12] 3360 	mov	r3,#0x00
      001053                       3361 00224$:
      001053 C3               [12] 3362 	clr	c
      001054 EB               [12] 3363 	mov	a,r3
      001055 9C               [12] 3364 	subb	a,r4
      001056 50 0D            [24] 3365 	jnc	00155$
                                   3366 ;	..\COMMON\easyax5043.c:538: radio_write8(AX5043_REG_FIFODATA, axradio_framing_syncword[i]);
      001058 EB               [12] 3367 	mov	a,r3
      001059 90 4C BE         [24] 3368 	mov	dptr,#_axradio_framing_syncword
      00105C 93               [24] 3369 	movc	a,@a+dptr
      00105D FA               [12] 3370 	mov	r2,a
      00105E 90 40 29         [24] 3371 	mov	dptr,#0x4029
      001061 F0               [24] 3372 	movx	@dptr,a
                                   3373 ;	..\COMMON\easyax5043.c:536: for (i = 0; i < len_byte; ++i) {
      001062 0B               [12] 3374 	inc	r3
      001063 80 EE            [24] 3375 	sjmp	00224$
      001065                       3376 00155$:
                                   3377 ;	..\COMMON\easyax5043.c:545: axradio_trxstate = trxstate_tx_packet;
      001065 75 09 0C         [24] 3378 	mov	_axradio_trxstate,#0x0c
                                   3379 ;	..\COMMON\easyax5043.c:546: break;
      001068 02 0E CE         [24] 3380 	ljmp	00226$
      00106B                       3381 00158$:
                                   3382 ;	..\COMMON\easyax5043.c:548: if (cnt < 4)
      00106B BF 04 00         [24] 3383 	cjne	r7,#0x04,00345$
      00106E                       3384 00345$:
      00106E 50 03            [24] 3385 	jnc	00346$
      001070 02 12 01         [24] 3386 	ljmp	00220$
      001073                       3387 00346$:
                                   3388 ;	..\COMMON\easyax5043.c:550: cnt = 255;
      001073 7F FF            [12] 3389 	mov	r7,#0xff
                                   3390 ;	..\COMMON\easyax5043.c:551: if (axradio_txbuffer_cnt < 255*8)
      001075 C3               [12] 3391 	clr	c
      001076 ED               [12] 3392 	mov	a,r5
      001077 94 F8            [12] 3393 	subb	a,#0xf8
      001079 EE               [12] 3394 	mov	a,r6
      00107A 94 07            [12] 3395 	subb	a,#0x07
      00107C 50 12            [24] 3396 	jnc	00162$
                                   3397 ;	..\COMMON\easyax5043.c:552: cnt = axradio_txbuffer_cnt >> 3;
      00107E EE               [12] 3398 	mov	a,r6
      00107F C4               [12] 3399 	swap	a
      001080 23               [12] 3400 	rl	a
      001081 CD               [12] 3401 	xch	a,r5
      001082 C4               [12] 3402 	swap	a
      001083 23               [12] 3403 	rl	a
      001084 54 1F            [12] 3404 	anl	a,#0x1f
      001086 6D               [12] 3405 	xrl	a,r5
      001087 CD               [12] 3406 	xch	a,r5
      001088 54 1F            [12] 3407 	anl	a,#0x1f
      00108A CD               [12] 3408 	xch	a,r5
      00108B 6D               [12] 3409 	xrl	a,r5
      00108C CD               [12] 3410 	xch	a,r5
      00108D FE               [12] 3411 	mov	r6,a
      00108E 8D 07            [24] 3412 	mov	ar7,r5
      001090                       3413 00162$:
                                   3414 ;	..\COMMON\easyax5043.c:553: if (cnt) {
      001090 EF               [12] 3415 	mov	a,r7
      001091 60 45            [24] 3416 	jz	00176$
                                   3417 ;	..\COMMON\easyax5043.c:554: axradio_txbuffer_cnt -= ((uint16_t)cnt) << 3;
      001093 8F 05            [24] 3418 	mov	ar5,r7
      001095 E4               [12] 3419 	clr	a
      001096 03               [12] 3420 	rr	a
      001097 54 F8            [12] 3421 	anl	a,#0xf8
      001099 CD               [12] 3422 	xch	a,r5
      00109A C4               [12] 3423 	swap	a
      00109B 03               [12] 3424 	rr	a
      00109C CD               [12] 3425 	xch	a,r5
      00109D 6D               [12] 3426 	xrl	a,r5
      00109E CD               [12] 3427 	xch	a,r5
      00109F 54 F8            [12] 3428 	anl	a,#0xf8
      0010A1 CD               [12] 3429 	xch	a,r5
      0010A2 6D               [12] 3430 	xrl	a,r5
      0010A3 FE               [12] 3431 	mov	r6,a
      0010A4 90 00 16         [24] 3432 	mov	dptr,#_axradio_txbuffer_cnt
      0010A7 E0               [24] 3433 	movx	a,@dptr
      0010A8 FB               [12] 3434 	mov	r3,a
      0010A9 A3               [24] 3435 	inc	dptr
      0010AA E0               [24] 3436 	movx	a,@dptr
      0010AB FC               [12] 3437 	mov	r4,a
      0010AC 90 00 16         [24] 3438 	mov	dptr,#_axradio_txbuffer_cnt
      0010AF EB               [12] 3439 	mov	a,r3
      0010B0 C3               [12] 3440 	clr	c
      0010B1 9D               [12] 3441 	subb	a,r5
      0010B2 F0               [24] 3442 	movx	@dptr,a
      0010B3 EC               [12] 3443 	mov	a,r4
      0010B4 9E               [12] 3444 	subb	a,r6
      0010B5 A3               [24] 3445 	inc	dptr
      0010B6 F0               [24] 3446 	movx	@dptr,a
                                   3447 ;	..\COMMON\easyax5043.c:555: radio_write8(AX5043_REG_FIFODATA, (AX5043_FIFOCMD_REPEATDATA | (3 << 5)));
      0010B7 90 40 29         [24] 3448 	mov	dptr,#0x4029
      0010BA 74 62            [12] 3449 	mov	a,#0x62
      0010BC F0               [24] 3450 	movx	@dptr,a
                                   3451 ;	..\COMMON\easyax5043.c:556: radio_write8(AX5043_REG_FIFODATA, axradio_phy_preamble_flags);
      0010BD 90 4C B2         [24] 3452 	mov	dptr,#_axradio_phy_preamble_flags
      0010C0 E4               [12] 3453 	clr	a
      0010C1 93               [24] 3454 	movc	a,@a+dptr
      0010C2 90 40 29         [24] 3455 	mov	dptr,#0x4029
      0010C5 F0               [24] 3456 	movx	@dptr,a
                                   3457 ;	..\COMMON\easyax5043.c:557: radio_write8(AX5043_REG_FIFODATA, cnt);
      0010C6 90 40 29         [24] 3458 	mov	dptr,#0x4029
      0010C9 EF               [12] 3459 	mov	a,r7
      0010CA F0               [24] 3460 	movx	@dptr,a
                                   3461 ;	..\COMMON\easyax5043.c:558: radio_write8(AX5043_REG_FIFODATA, axradio_phy_preamble_byte);
      0010CB 90 4C B1         [24] 3462 	mov	dptr,#_axradio_phy_preamble_byte
      0010CE E4               [12] 3463 	clr	a
      0010CF 93               [24] 3464 	movc	a,@a+dptr
      0010D0 FE               [12] 3465 	mov	r6,a
      0010D1 90 40 29         [24] 3466 	mov	dptr,#0x4029
      0010D4 F0               [24] 3467 	movx	@dptr,a
                                   3468 ;	..\COMMON\easyax5043.c:559: break;
      0010D5 02 0E CE         [24] 3469 	ljmp	00226$
      0010D8                       3470 00176$:
                                   3471 ;	..\COMMON\easyax5043.c:562: uint8_t byte = axradio_phy_preamble_byte;
      0010D8 90 4C B1         [24] 3472 	mov	dptr,#_axradio_phy_preamble_byte
      0010DB E4               [12] 3473 	clr	a
      0010DC 93               [24] 3474 	movc	a,@a+dptr
      0010DD FE               [12] 3475 	mov	r6,a
                                   3476 ;	..\COMMON\easyax5043.c:563: cnt = axradio_txbuffer_cnt;
      0010DE 90 00 16         [24] 3477 	mov	dptr,#_axradio_txbuffer_cnt
      0010E1 E0               [24] 3478 	movx	a,@dptr
      0010E2 FC               [12] 3479 	mov	r4,a
      0010E3 A3               [24] 3480 	inc	dptr
      0010E4 E0               [24] 3481 	movx	a,@dptr
      0010E5 8C 07            [24] 3482 	mov	ar7,r4
                                   3483 ;	..\COMMON\easyax5043.c:564: axradio_txbuffer_cnt = 0;
      0010E7 90 00 16         [24] 3484 	mov	dptr,#_axradio_txbuffer_cnt
      0010EA E4               [12] 3485 	clr	a
      0010EB F0               [24] 3486 	movx	@dptr,a
      0010EC A3               [24] 3487 	inc	dptr
      0010ED F0               [24] 3488 	movx	@dptr,a
                                   3489 ;	..\COMMON\easyax5043.c:565: radio_write8(AX5043_REG_FIFODATA, (AX5043_FIFOCMD_DATA | (2 << 5)));
                                   3490 ;	..\COMMON\easyax5043.c:566: radio_write8(AX5043_REG_FIFODATA, 0x1C);
      0010EE 90 40 29         [24] 3491 	mov	dptr,#0x4029
      0010F1 74 41            [12] 3492 	mov	a,#0x41
      0010F3 F0               [24] 3493 	movx	@dptr,a
      0010F4 74 1C            [12] 3494 	mov	a,#0x1c
      0010F6 F0               [24] 3495 	movx	@dptr,a
                                   3496 ;	..\COMMON\easyax5043.c:567: if (radio_read8(AX5043_REG_PKTADDRCFG) & 0x80) {
      0010F7 90 42 00         [24] 3497 	mov	dptr,#0x4200
      0010FA E0               [24] 3498 	movx	a,@dptr
      0010FB FD               [12] 3499 	mov	r5,a
      0010FC 30 E7 27         [24] 3500 	jnb	acc.7,00184$
                                   3501 ;	..\COMMON\easyax5043.c:569: byte &= 0xFF << (8-cnt);
      0010FF 74 08            [12] 3502 	mov	a,#0x08
      001101 C3               [12] 3503 	clr	c
      001102 9F               [12] 3504 	subb	a,r7
      001103 FD               [12] 3505 	mov	r5,a
      001104 8D F0            [24] 3506 	mov	b,r5
      001106 05 F0            [12] 3507 	inc	b
      001108 74 FF            [12] 3508 	mov	a,#0xff
      00110A 80 02            [24] 3509 	sjmp	00352$
      00110C                       3510 00350$:
      00110C 25 E0            [12] 3511 	add	a,acc
      00110E                       3512 00352$:
      00110E D5 F0 FB         [24] 3513 	djnz	b,00350$
      001111 FD               [12] 3514 	mov	r5,a
      001112 52 06            [12] 3515 	anl	ar6,a
                                   3516 ;	..\COMMON\easyax5043.c:570: byte |= 0x80 >> cnt;
      001114 8F F0            [24] 3517 	mov	b,r7
      001116 05 F0            [12] 3518 	inc	b
      001118 74 80            [12] 3519 	mov	a,#0x80
      00111A 80 02            [24] 3520 	sjmp	00354$
      00111C                       3521 00353$:
      00111C C3               [12] 3522 	clr	c
      00111D 13               [12] 3523 	rrc	a
      00111E                       3524 00354$:
      00111E D5 F0 FB         [24] 3525 	djnz	b,00353$
      001121 FD               [12] 3526 	mov	r5,a
      001122 42 06            [12] 3527 	orl	ar6,a
      001124 80 2C            [24] 3528 	sjmp	00186$
      001126                       3529 00184$:
                                   3530 ;	..\COMMON\easyax5043.c:573: byte &= 0xFF >> (8-cnt);
      001126 8F 04            [24] 3531 	mov	ar4,r7
      001128 7D 00            [12] 3532 	mov	r5,#0x00
      00112A 74 08            [12] 3533 	mov	a,#0x08
      00112C C3               [12] 3534 	clr	c
      00112D 9C               [12] 3535 	subb	a,r4
      00112E FC               [12] 3536 	mov	r4,a
      00112F E4               [12] 3537 	clr	a
      001130 9D               [12] 3538 	subb	a,r5
      001131 FD               [12] 3539 	mov	r5,a
      001132 8C F0            [24] 3540 	mov	b,r4
      001134 05 F0            [12] 3541 	inc	b
      001136 74 FF            [12] 3542 	mov	a,#0xff
      001138 80 02            [24] 3543 	sjmp	00356$
      00113A                       3544 00355$:
      00113A C3               [12] 3545 	clr	c
      00113B 13               [12] 3546 	rrc	a
      00113C                       3547 00356$:
      00113C D5 F0 FB         [24] 3548 	djnz	b,00355$
      00113F FC               [12] 3549 	mov	r4,a
      001140 52 06            [12] 3550 	anl	ar6,a
                                   3551 ;	..\COMMON\easyax5043.c:574: byte |= 0x01 << cnt;
      001142 8F F0            [24] 3552 	mov	b,r7
      001144 05 F0            [12] 3553 	inc	b
      001146 74 01            [12] 3554 	mov	a,#0x01
      001148 80 02            [24] 3555 	sjmp	00359$
      00114A                       3556 00357$:
      00114A 25 E0            [12] 3557 	add	a,acc
      00114C                       3558 00359$:
      00114C D5 F0 FB         [24] 3559 	djnz	b,00357$
      00114F FD               [12] 3560 	mov	r5,a
      001150 42 06            [12] 3561 	orl	ar6,a
                                   3562 ;	..\COMMON\easyax5043.c:576: radio_write8(AX5043_REG_FIFODATA, byte);
      001152                       3563 00186$:
      001152 90 40 29         [24] 3564 	mov	dptr,#0x4029
      001155 EE               [12] 3565 	mov	a,r6
      001156 F0               [24] 3566 	movx	@dptr,a
                                   3567 ;	..\COMMON\easyax5043.c:578: break;
      001157 02 0E CE         [24] 3568 	ljmp	00226$
                                   3569 ;	..\COMMON\easyax5043.c:580: case trxstate_tx_packet:
      00115A                       3570 00189$:
                                   3571 ;	..\COMMON\easyax5043.c:581: if (cnt < 11)
      00115A BF 0B 00         [24] 3572 	cjne	r7,#0x0b,00360$
      00115D                       3573 00360$:
      00115D 50 03            [24] 3574 	jnc	00361$
      00115F 02 12 01         [24] 3575 	ljmp	00220$
      001162                       3576 00361$:
                                   3577 ;	..\COMMON\easyax5043.c:584: uint8_t flags = 0;
      001162 7E 00            [12] 3578 	mov	r6,#0x00
                                   3579 ;	..\COMMON\easyax5043.c:585: if (!axradio_txbuffer_cnt)
      001164 90 00 16         [24] 3580 	mov	dptr,#_axradio_txbuffer_cnt
      001167 E0               [24] 3581 	movx	a,@dptr
      001168 F5 F0            [12] 3582 	mov	b,a
      00116A A3               [24] 3583 	inc	dptr
      00116B E0               [24] 3584 	movx	a,@dptr
      00116C 45 F0            [12] 3585 	orl	a,b
      00116E 70 02            [24] 3586 	jnz	00193$
                                   3587 ;	..\COMMON\easyax5043.c:586: flags |= 0x01; // flag byte: pkt_start
      001170 7E 01            [12] 3588 	mov	r6,#0x01
      001172                       3589 00193$:
                                   3590 ;	..\COMMON\easyax5043.c:588: uint16_t len = axradio_txbuffer_len - axradio_txbuffer_cnt;
      001172 90 00 16         [24] 3591 	mov	dptr,#_axradio_txbuffer_cnt
      001175 E0               [24] 3592 	movx	a,@dptr
      001176 FC               [12] 3593 	mov	r4,a
      001177 A3               [24] 3594 	inc	dptr
      001178 E0               [24] 3595 	movx	a,@dptr
      001179 FD               [12] 3596 	mov	r5,a
      00117A 90 00 14         [24] 3597 	mov	dptr,#_axradio_txbuffer_len
      00117D E0               [24] 3598 	movx	a,@dptr
      00117E FA               [12] 3599 	mov	r2,a
      00117F A3               [24] 3600 	inc	dptr
      001180 E0               [24] 3601 	movx	a,@dptr
      001181 FB               [12] 3602 	mov	r3,a
      001182 EA               [12] 3603 	mov	a,r2
      001183 C3               [12] 3604 	clr	c
      001184 9C               [12] 3605 	subb	a,r4
      001185 FC               [12] 3606 	mov	r4,a
      001186 EB               [12] 3607 	mov	a,r3
      001187 9D               [12] 3608 	subb	a,r5
      001188 FD               [12] 3609 	mov	r5,a
                                   3610 ;	..\COMMON\easyax5043.c:589: cnt -= 3;
      001189 1F               [12] 3611 	dec	r7
      00118A 1F               [12] 3612 	dec	r7
      00118B 1F               [12] 3613 	dec	r7
                                   3614 ;	..\COMMON\easyax5043.c:590: if (cnt >= len) {
      00118C 8F 02            [24] 3615 	mov	ar2,r7
      00118E 7B 00            [12] 3616 	mov	r3,#0x00
      001190 C3               [12] 3617 	clr	c
      001191 EA               [12] 3618 	mov	a,r2
      001192 9C               [12] 3619 	subb	a,r4
      001193 EB               [12] 3620 	mov	a,r3
      001194 9D               [12] 3621 	subb	a,r5
      001195 40 05            [24] 3622 	jc	00195$
                                   3623 ;	..\COMMON\easyax5043.c:591: cnt = len;
      001197 8C 07            [24] 3624 	mov	ar7,r4
                                   3625 ;	..\COMMON\easyax5043.c:592: flags |= 0x02; // flag byte: pkt_end
      001199 43 06 02         [24] 3626 	orl	ar6,#0x02
      00119C                       3627 00195$:
                                   3628 ;	..\COMMON\easyax5043.c:595: if (!cnt)
      00119C EF               [12] 3629 	mov	a,r7
      00119D 60 53            [24] 3630 	jz	00212$
                                   3631 ;	..\COMMON\easyax5043.c:597: radio_write8(AX5043_REG_FIFODATA, AX5043_FIFOCMD_DATA | (7 << 5));
      00119F 90 40 29         [24] 3632 	mov	dptr,#0x4029
      0011A2 74 E1            [12] 3633 	mov	a,#0xe1
      0011A4 F0               [24] 3634 	movx	@dptr,a
                                   3635 ;	..\COMMON\easyax5043.c:598: radio_write8(AX5043_REG_FIFODATA, (cnt + 1)); // write FIFO chunk length byte (length includes the flag byte, thus the +1)
      0011A5 EF               [12] 3636 	mov	a,r7
      0011A6 04               [12] 3637 	inc	a
      0011A7 90 40 29         [24] 3638 	mov	dptr,#0x4029
      0011AA F0               [24] 3639 	movx	@dptr,a
                                   3640 ;	..\COMMON\easyax5043.c:599: radio_write8(AX5043_REG_FIFODATA, flags);
      0011AB 90 40 29         [24] 3641 	mov	dptr,#0x4029
      0011AE EE               [12] 3642 	mov	a,r6
      0011AF F0               [24] 3643 	movx	@dptr,a
                                   3644 ;	..\COMMON\easyax5043.c:600: ax5043_writefifo(&axradio_txbuffer[axradio_txbuffer_cnt], cnt);
      0011B0 90 00 16         [24] 3645 	mov	dptr,#_axradio_txbuffer_cnt
      0011B3 E0               [24] 3646 	movx	a,@dptr
      0011B4 FC               [12] 3647 	mov	r4,a
      0011B5 A3               [24] 3648 	inc	dptr
      0011B6 E0               [24] 3649 	movx	a,@dptr
      0011B7 FD               [12] 3650 	mov	r5,a
      0011B8 EC               [12] 3651 	mov	a,r4
      0011B9 24 3C            [12] 3652 	add	a,#_axradio_txbuffer
      0011BB FC               [12] 3653 	mov	r4,a
      0011BC ED               [12] 3654 	mov	a,r5
      0011BD 34 00            [12] 3655 	addc	a,#(_axradio_txbuffer >> 8)
      0011BF FD               [12] 3656 	mov	r5,a
      0011C0 7B 00            [12] 3657 	mov	r3,#0x00
      0011C2 C0 07            [24] 3658 	push	ar7
      0011C4 C0 06            [24] 3659 	push	ar6
      0011C6 C0 07            [24] 3660 	push	ar7
      0011C8 8C 82            [24] 3661 	mov	dpl,r4
      0011CA 8D 83            [24] 3662 	mov	dph,r5
      0011CC 8B F0            [24] 3663 	mov	b,r3
      0011CE 12 48 F1         [24] 3664 	lcall	_ax5043_writefifo
      0011D1 15 81            [12] 3665 	dec	sp
      0011D3 D0 06            [24] 3666 	pop	ar6
      0011D5 D0 07            [24] 3667 	pop	ar7
                                   3668 ;	..\COMMON\easyax5043.c:601: axradio_txbuffer_cnt += cnt;
      0011D7 7D 00            [12] 3669 	mov	r5,#0x00
      0011D9 90 00 16         [24] 3670 	mov	dptr,#_axradio_txbuffer_cnt
      0011DC E0               [24] 3671 	movx	a,@dptr
      0011DD FB               [12] 3672 	mov	r3,a
      0011DE A3               [24] 3673 	inc	dptr
      0011DF E0               [24] 3674 	movx	a,@dptr
      0011E0 FC               [12] 3675 	mov	r4,a
      0011E1 90 00 16         [24] 3676 	mov	dptr,#_axradio_txbuffer_cnt
      0011E4 EF               [12] 3677 	mov	a,r7
      0011E5 2B               [12] 3678 	add	a,r3
      0011E6 F0               [24] 3679 	movx	@dptr,a
      0011E7 ED               [12] 3680 	mov	a,r5
      0011E8 3C               [12] 3681 	addc	a,r4
      0011E9 A3               [24] 3682 	inc	dptr
      0011EA F0               [24] 3683 	movx	@dptr,a
                                   3684 ;	..\COMMON\easyax5043.c:602: if (flags & 0x02)
      0011EB EE               [12] 3685 	mov	a,r6
      0011EC 20 E1 03         [24] 3686 	jb	acc.1,00212$
                                   3687 ;	..\COMMON\easyax5043.c:603: goto pktend;
                                   3688 ;	..\COMMON\easyax5043.c:607: default:
                                   3689 ;	..\COMMON\easyax5043.c:608: return;
                                   3690 ;	..\COMMON\easyax5043.c:611: pktend:
      0011EF 02 0E CE         [24] 3691 	ljmp	00226$
      0011F2                       3692 00212$:
                                   3693 ;	..\COMMON\easyax5043.c:612: axradio_trxstate = trxstate_tx_waitdone;
      0011F2 75 09 0D         [24] 3694 	mov	_axradio_trxstate,#0x0d
                                   3695 ;	..\COMMON\easyax5043.c:613: radio_write8(AX5043_REG_RADIOEVENTMASK0, 0x01); // enable REVRDONE event
      0011F5 90 40 09         [24] 3696 	mov	dptr,#0x4009
      0011F8 74 01            [12] 3697 	mov	a,#0x01
      0011FA F0               [24] 3698 	movx	@dptr,a
                                   3699 ;	..\COMMON\easyax5043.c:614: radio_write8(AX5043_REG_IRQMASK0, 0x40); // enable radio controller irq
      0011FB 90 40 07         [24] 3700 	mov	dptr,#0x4007
      0011FE 74 40            [12] 3701 	mov	a,#0x40
      001200 F0               [24] 3702 	movx	@dptr,a
                                   3703 ;	..\COMMON\easyax5043.c:616: radio_write8(AX5043_REG_FIFOSTAT, 4); // commit
      001201                       3704 00220$:
      001201 90 40 28         [24] 3705 	mov	dptr,#0x4028
      001204 74 04            [12] 3706 	mov	a,#0x04
      001206 F0               [24] 3707 	movx	@dptr,a
      001207 22               [24] 3708 	ret
                                   3709 ;------------------------------------------------------------
                                   3710 ;Allocation info for local variables in function 'axradio_isr'
                                   3711 ;------------------------------------------------------------
                                   3712 ;radioStateTemp            Allocated to registers 
                                   3713 ;evt                       Allocated to registers r7 
                                   3714 ;------------------------------------------------------------
                                   3715 ;	..\COMMON\easyax5043.c:620: void axradio_isr(void) __interrupt INT_RADIO
                                   3716 ;	-----------------------------------------
                                   3717 ;	 function axradio_isr
                                   3718 ;	-----------------------------------------
      001208                       3719 _axradio_isr:
      001208 C0 21            [24] 3720 	push	bits
      00120A C0 E0            [24] 3721 	push	acc
      00120C C0 F0            [24] 3722 	push	b
      00120E C0 82            [24] 3723 	push	dpl
      001210 C0 83            [24] 3724 	push	dph
      001212 C0 07            [24] 3725 	push	(0+7)
      001214 C0 06            [24] 3726 	push	(0+6)
      001216 C0 05            [24] 3727 	push	(0+5)
      001218 C0 04            [24] 3728 	push	(0+4)
      00121A C0 03            [24] 3729 	push	(0+3)
      00121C C0 02            [24] 3730 	push	(0+2)
      00121E C0 01            [24] 3731 	push	(0+1)
      001220 C0 00            [24] 3732 	push	(0+0)
      001222 C0 D0            [24] 3733 	push	psw
      001224 75 D0 00         [24] 3734 	mov	psw,#0x00
                                   3735 ;	..\COMMON\easyax5043.c:633: switch (axradio_trxstate) {
      001227 E5 09            [12] 3736 	mov	a,_axradio_trxstate
      001229 FF               [12] 3737 	mov	r7,a
      00122A 24 EF            [12] 3738 	add	a,#0xff - 0x10
      00122C 50 03            [24] 3739 	jnc	00349$
      00122E 02 12 64         [24] 3740 	ljmp	00102$
      001231                       3741 00349$:
      001231 EF               [12] 3742 	mov	a,r7
      001232 F5 F0            [12] 3743 	mov	b,a
      001234 24 0B            [12] 3744 	add	a,#(00350$-3-.)
      001236 83               [24] 3745 	movc	a,@a+pc
      001237 F5 82            [12] 3746 	mov	dpl,a
      001239 E5 F0            [12] 3747 	mov	a,b
      00123B 24 15            [12] 3748 	add	a,#(00351$-3-.)
      00123D 83               [24] 3749 	movc	a,@a+pc
      00123E F5 83            [12] 3750 	mov	dph,a
      001240 E4               [12] 3751 	clr	a
      001241 73               [24] 3752 	jmp	@a+dptr
      001242                       3753 00350$:
      001242 64                    3754 	.db	00101$
      001243 1B                    3755 	.db	00258$
      001244 C7                    3756 	.db	00227$
      001245 70                    3757 	.db	00108$
      001246 64                    3758 	.db	00101$
      001247 7B                    3759 	.db	00112$
      001248 64                    3760 	.db	00101$
      001249 86                    3761 	.db	00116$
      00124A 64                    3762 	.db	00101$
      00124B 91                    3763 	.db	00120$
      00124C 24                    3764 	.db	00153$
      00124D 24                    3765 	.db	00154$
      00124E 24                    3766 	.db	00155$
      00124F 2A                    3767 	.db	00156$
      001250 5E                    3768 	.db	00186$
      001251 A3                    3769 	.db	00196$
      001252 CB                    3770 	.db	00211$
      001253                       3771 00351$:
      001253 12                    3772 	.db	00101$>>8
      001254 16                    3773 	.db	00258$>>8
      001255 15                    3774 	.db	00227$>>8
      001256 12                    3775 	.db	00108$>>8
      001257 12                    3776 	.db	00101$>>8
      001258 12                    3777 	.db	00112$>>8
      001259 12                    3778 	.db	00101$>>8
      00125A 12                    3779 	.db	00116$>>8
      00125B 12                    3780 	.db	00101$>>8
      00125C 12                    3781 	.db	00120$>>8
      00125D 13                    3782 	.db	00153$>>8
      00125E 13                    3783 	.db	00154$>>8
      00125F 13                    3784 	.db	00155$>>8
      001260 13                    3785 	.db	00156$>>8
      001261 14                    3786 	.db	00186$>>8
      001262 14                    3787 	.db	00196$>>8
      001263 14                    3788 	.db	00211$>>8
                                   3789 ;	..\COMMON\easyax5043.c:634: default:
      001264                       3790 00101$:
                                   3791 ;	..\COMMON\easyax5043.c:635: radio_write8(AX5043_REG_IRQMASK1, 0x00);
      001264                       3792 00102$:
      001264 90 40 06         [24] 3793 	mov	dptr,#0x4006
      001267 E4               [12] 3794 	clr	a
      001268 F0               [24] 3795 	movx	@dptr,a
                                   3796 ;	..\COMMON\easyax5043.c:636: radio_write8(AX5043_REG_IRQMASK0, 0x00);
      001269 90 40 07         [24] 3797 	mov	dptr,#0x4007
      00126C F0               [24] 3798 	movx	@dptr,a
                                   3799 ;	..\COMMON\easyax5043.c:637: break;
      00126D 02 16 1E         [24] 3800 	ljmp	00260$
                                   3801 ;	..\COMMON\easyax5043.c:639: case trxstate_wait_xtal:
      001270                       3802 00108$:
                                   3803 ;	..\COMMON\easyax5043.c:640: radio_write8(AX5043_REG_IRQMASK1, 0x00); // otherwise crystal ready will fire all over again
      001270 90 40 06         [24] 3804 	mov	dptr,#0x4006
      001273 E4               [12] 3805 	clr	a
      001274 F0               [24] 3806 	movx	@dptr,a
                                   3807 ;	..\COMMON\easyax5043.c:641: axradio_trxstate = trxstate_xtal_ready;
      001275 75 09 04         [24] 3808 	mov	_axradio_trxstate,#0x04
                                   3809 ;	..\COMMON\easyax5043.c:642: break;
      001278 02 16 1E         [24] 3810 	ljmp	00260$
                                   3811 ;	..\COMMON\easyax5043.c:644: case trxstate_pll_ranging:
      00127B                       3812 00112$:
                                   3813 ;	..\COMMON\easyax5043.c:645: radio_write8(AX5043_REG_IRQMASK1, 0x00); // otherwise autoranging done will fire all over again
      00127B 90 40 06         [24] 3814 	mov	dptr,#0x4006
      00127E E4               [12] 3815 	clr	a
      00127F F0               [24] 3816 	movx	@dptr,a
                                   3817 ;	..\COMMON\easyax5043.c:646: axradio_trxstate = trxstate_pll_ranging_done;
      001280 75 09 06         [24] 3818 	mov	_axradio_trxstate,#0x06
                                   3819 ;	..\COMMON\easyax5043.c:647: break;
      001283 02 16 1E         [24] 3820 	ljmp	00260$
                                   3821 ;	..\COMMON\easyax5043.c:649: case trxstate_pll_settling:
      001286                       3822 00116$:
                                   3823 ;	..\COMMON\easyax5043.c:650: radio_write8(AX5043_REG_RADIOEVENTMASK0, 0x00);
      001286 90 40 09         [24] 3824 	mov	dptr,#0x4009
      001289 E4               [12] 3825 	clr	a
      00128A F0               [24] 3826 	movx	@dptr,a
                                   3827 ;	..\COMMON\easyax5043.c:651: axradio_trxstate = trxstate_pll_settled;
      00128B 75 09 08         [24] 3828 	mov	_axradio_trxstate,#0x08
                                   3829 ;	..\COMMON\easyax5043.c:652: break;
      00128E 02 16 1E         [24] 3830 	ljmp	00260$
                                   3831 ;	..\COMMON\easyax5043.c:654: case trxstate_tx_xtalwait:
      001291                       3832 00120$:
                                   3833 ;	..\COMMON\easyax5043.c:655: radio_read8(AX5043_REG_RADIOEVENTREQ0); // make sure REVRDONE bit is cleared, so it is a reliable indicator that the packet is out
      001291 90 40 0F         [24] 3834 	mov	dptr,#0x400f
      001294 E0               [24] 3835 	movx	a,@dptr
                                   3836 ;	..\COMMON\easyax5043.c:656: radio_write8(AX5043_REG_FIFOSTAT, 3); // clear FIFO data & flags (prevent transmitting anything left over in the FIFO, this has no effect if the FIFO is not powerered, in this case it is reset any way)
      001295 90 40 28         [24] 3837 	mov	dptr,#0x4028
      001298 74 03            [12] 3838 	mov	a,#0x03
      00129A F0               [24] 3839 	movx	@dptr,a
                                   3840 ;	..\COMMON\easyax5043.c:657: radio_write8(AX5043_REG_IRQMASK1, 0x00);
      00129B 90 40 06         [24] 3841 	mov	dptr,#0x4006
      00129E E4               [12] 3842 	clr	a
      00129F F0               [24] 3843 	movx	@dptr,a
                                   3844 ;	..\COMMON\easyax5043.c:658: radio_write8(AX5043_REG_IRQMASK0, 0x08); // enable fifo free threshold
      0012A0 90 40 07         [24] 3845 	mov	dptr,#0x4007
      0012A3 74 08            [12] 3846 	mov	a,#0x08
      0012A5 F0               [24] 3847 	movx	@dptr,a
                                   3848 ;	..\COMMON\easyax5043.c:659: axradio_trxstate = trxstate_tx_longpreamble;
      0012A6 75 09 0A         [24] 3849 	mov	_axradio_trxstate,#0x0a
                                   3850 ;	..\COMMON\easyax5043.c:661: if ((radio_read8(AX5043_REG_MODULATION) & 0x0F) == 9) { // 4-FSK
      0012A9 90 40 10         [24] 3851 	mov	dptr,#0x4010
      0012AC E0               [24] 3852 	movx	a,@dptr
      0012AD FF               [12] 3853 	mov	r7,a
      0012AE 53 07 0F         [24] 3854 	anl	ar7,#0x0f
      0012B1 BF 09 11         [24] 3855 	cjne	r7,#0x09,00143$
                                   3856 ;	..\COMMON\easyax5043.c:662: radio_write8(AX5043_REG_FIFODATA, (AX5043_FIFOCMD_DATA | (7 << 5)));
                                   3857 ;	..\COMMON\easyax5043.c:663: radio_write8(AX5043_REG_FIFODATA, 2);  // length (including flags)
                                   3858 ;	..\COMMON\easyax5043.c:664: radio_write8(AX5043_REG_FIFODATA, 0x01);  // flag PKTSTART -> dibit sync
      0012B4 90 40 29         [24] 3859 	mov	dptr,#0x4029
      0012B7 74 E1            [12] 3860 	mov	a,#0xe1
      0012B9 F0               [24] 3861 	movx	@dptr,a
      0012BA 74 02            [12] 3862 	mov	a,#0x02
      0012BC F0               [24] 3863 	movx	@dptr,a
      0012BD 14               [12] 3864 	dec	a
      0012BE F0               [24] 3865 	movx	@dptr,a
                                   3866 ;	..\COMMON\easyax5043.c:665: radio_write8(AX5043_REG_FIFODATA, 0x11); // dummy byte for forcing dibit sync
      0012BF 90 40 29         [24] 3867 	mov	dptr,#0x4029
      0012C2 74 11            [12] 3868 	mov	a,#0x11
      0012C4 F0               [24] 3869 	movx	@dptr,a
      0012C5                       3870 00143$:
                                   3871 ;	..\COMMON\easyax5043.c:672: transmit_isr();
      0012C5 12 0E CE         [24] 3872 	lcall	_transmit_isr
                                   3873 ;	..\COMMON\easyax5043.c:673: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_FULL_TX);
      0012C8 90 40 02         [24] 3874 	mov	dptr,#0x4002
      0012CB 74 0D            [12] 3875 	mov	a,#0x0d
      0012CD F0               [24] 3876 	movx	@dptr,a
                                   3877 ;	..\COMMON\easyax5043.c:674: update_timeanchor();
      0012CE 12 0A 7C         [24] 3878 	lcall	_update_timeanchor
                                   3879 ;	..\COMMON\easyax5043.c:675: wtimer_remove_callback(&axradio_cb_transmitstart.cb);
      0012D1 90 02 7F         [24] 3880 	mov	dptr,#_axradio_cb_transmitstart
      0012D4 12 48 82         [24] 3881 	lcall	_wtimer_remove_callback
                                   3882 ;	..\COMMON\easyax5043.c:676: switch (axradio_mode) {
      0012D7 AF 08            [24] 3883 	mov	r7,_axradio_mode
      0012D9 BF 12 02         [24] 3884 	cjne	r7,#0x12,00354$
      0012DC 80 03            [24] 3885 	sjmp	00148$
      0012DE                       3886 00354$:
      0012DE BF 13 19         [24] 3887 	cjne	r7,#0x13,00151$
                                   3888 ;	..\COMMON\easyax5043.c:678: case AXRADIO_MODE_WOR_ACK_TRANSMIT:
      0012E1                       3889 00148$:
                                   3890 ;	..\COMMON\easyax5043.c:679: if (axradio_ack_count != axradio_framing_ack_retransmissions) {
      0012E1 90 00 1D         [24] 3891 	mov	dptr,#_axradio_ack_count
      0012E4 E0               [24] 3892 	movx	a,@dptr
      0012E5 FF               [12] 3893 	mov	r7,a
      0012E6 90 4C CC         [24] 3894 	mov	dptr,#_axradio_framing_ack_retransmissions
      0012E9 E4               [12] 3895 	clr	a
      0012EA 93               [24] 3896 	movc	a,@a+dptr
      0012EB FE               [12] 3897 	mov	r6,a
      0012EC EF               [12] 3898 	mov	a,r7
      0012ED B5 06 02         [24] 3899 	cjne	a,ar6,00357$
      0012F0 80 08            [24] 3900 	sjmp	00151$
      0012F2                       3901 00357$:
                                   3902 ;	..\COMMON\easyax5043.c:680: axradio_cb_transmitstart.st.error = AXRADIO_ERR_RETRANSMISSION;
      0012F2 90 02 84         [24] 3903 	mov	dptr,#(_axradio_cb_transmitstart + 0x0005)
      0012F5 74 08            [12] 3904 	mov	a,#0x08
      0012F7 F0               [24] 3905 	movx	@dptr,a
                                   3906 ;	..\COMMON\easyax5043.c:681: break;
                                   3907 ;	..\COMMON\easyax5043.c:684: default:
      0012F8 80 05            [24] 3908 	sjmp	00152$
      0012FA                       3909 00151$:
                                   3910 ;	..\COMMON\easyax5043.c:685: axradio_cb_transmitstart.st.error = AXRADIO_ERR_NOERROR;
      0012FA 90 02 84         [24] 3911 	mov	dptr,#(_axradio_cb_transmitstart + 0x0005)
      0012FD E4               [12] 3912 	clr	a
      0012FE F0               [24] 3913 	movx	@dptr,a
                                   3914 ;	..\COMMON\easyax5043.c:687: }
      0012FF                       3915 00152$:
                                   3916 ;	..\COMMON\easyax5043.c:688: axradio_cb_transmitstart.st.time.t = axradio_timeanchor.radiotimer;
      0012FF 90 00 29         [24] 3917 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      001302 E0               [24] 3918 	movx	a,@dptr
      001303 FC               [12] 3919 	mov	r4,a
      001304 A3               [24] 3920 	inc	dptr
      001305 E0               [24] 3921 	movx	a,@dptr
      001306 FD               [12] 3922 	mov	r5,a
      001307 A3               [24] 3923 	inc	dptr
      001308 E0               [24] 3924 	movx	a,@dptr
      001309 FE               [12] 3925 	mov	r6,a
      00130A A3               [24] 3926 	inc	dptr
      00130B E0               [24] 3927 	movx	a,@dptr
      00130C FF               [12] 3928 	mov	r7,a
      00130D 90 02 85         [24] 3929 	mov	dptr,#(_axradio_cb_transmitstart + 0x0006)
      001310 EC               [12] 3930 	mov	a,r4
      001311 F0               [24] 3931 	movx	@dptr,a
      001312 ED               [12] 3932 	mov	a,r5
      001313 A3               [24] 3933 	inc	dptr
      001314 F0               [24] 3934 	movx	@dptr,a
      001315 EE               [12] 3935 	mov	a,r6
      001316 A3               [24] 3936 	inc	dptr
      001317 F0               [24] 3937 	movx	@dptr,a
      001318 EF               [12] 3938 	mov	a,r7
      001319 A3               [24] 3939 	inc	dptr
      00131A F0               [24] 3940 	movx	@dptr,a
                                   3941 ;	..\COMMON\easyax5043.c:689: wtimer_add_callback(&axradio_cb_transmitstart.cb);
      00131B 90 02 7F         [24] 3942 	mov	dptr,#_axradio_cb_transmitstart
      00131E 12 42 C4         [24] 3943 	lcall	_wtimer_add_callback
                                   3944 ;	..\COMMON\easyax5043.c:690: break;
      001321 02 16 1E         [24] 3945 	ljmp	00260$
                                   3946 ;	..\COMMON\easyax5043.c:692: case trxstate_tx_longpreamble:
      001324                       3947 00153$:
                                   3948 ;	..\COMMON\easyax5043.c:693: case trxstate_tx_shortpreamble:
      001324                       3949 00154$:
                                   3950 ;	..\COMMON\easyax5043.c:694: case trxstate_tx_packet:
      001324                       3951 00155$:
                                   3952 ;	..\COMMON\easyax5043.c:695: transmit_isr();
      001324 12 0E CE         [24] 3953 	lcall	_transmit_isr
                                   3954 ;	..\COMMON\easyax5043.c:696: break;
      001327 02 16 1E         [24] 3955 	ljmp	00260$
                                   3956 ;	..\COMMON\easyax5043.c:698: case trxstate_tx_waitdone:
      00132A                       3957 00156$:
                                   3958 ;	..\COMMON\easyax5043.c:699: radio_read8(AX5043_REG_RADIOEVENTREQ0);
      00132A 90 40 0F         [24] 3959 	mov	dptr,#0x400f
      00132D E0               [24] 3960 	movx	a,@dptr
                                   3961 ;	..\COMMON\easyax5043.c:700: radioStateTemp = radio_read8(AX5043_REG_RADIOSTATE);
      00132E 90 40 1C         [24] 3962 	mov	dptr,#0x401c
      001331 E0               [24] 3963 	movx	a,@dptr
      001332 60 03            [24] 3964 	jz	00358$
      001334 02 16 1E         [24] 3965 	ljmp	00260$
      001337                       3966 00358$:
                                   3967 ;	..\COMMON\easyax5043.c:701: if (radioStateTemp != 0)
                                   3968 ;	..\COMMON\easyax5043.c:703: radio_write8(AX5043_REG_RADIOEVENTMASK0, 0x00);
      001337 90 40 09         [24] 3969 	mov	dptr,#0x4009
      00133A E4               [12] 3970 	clr	a
      00133B F0               [24] 3971 	movx	@dptr,a
                                   3972 ;	..\COMMON\easyax5043.c:704: switch (axradio_mode) {
      00133C AF 08            [24] 3973 	mov	r7,_axradio_mode
      00133E BF 12 02         [24] 3974 	cjne	r7,#0x12,00359$
      001341 80 6A            [24] 3975 	sjmp	00173$
      001343                       3976 00359$:
      001343 BF 13 02         [24] 3977 	cjne	r7,#0x13,00360$
      001346 80 65            [24] 3978 	sjmp	00173$
      001348                       3979 00360$:
      001348 BF 20 02         [24] 3980 	cjne	r7,#0x20,00361$
      00134B 80 1D            [24] 3981 	sjmp	00162$
      00134D                       3982 00361$:
      00134D BF 21 02         [24] 3983 	cjne	r7,#0x21,00362$
      001350 80 36            [24] 3984 	sjmp	00167$
      001352                       3985 00362$:
      001352 BF 22 02         [24] 3986 	cjne	r7,#0x22,00363$
      001355 80 1C            [24] 3987 	sjmp	00163$
      001357                       3988 00363$:
      001357 BF 23 02         [24] 3989 	cjne	r7,#0x23,00364$
      00135A 80 3C            [24] 3990 	sjmp	00170$
      00135C                       3991 00364$:
      00135C BF 30 03         [24] 3992 	cjne	r7,#0x30,00365$
      00135F 02 13 E1         [24] 3993 	ljmp	00174$
      001362                       3994 00365$:
      001362 BF 31 02         [24] 3995 	cjne	r7,#0x31,00366$
      001365 80 39            [24] 3996 	sjmp	00171$
      001367                       3997 00366$:
      001367 02 13 EE         [24] 3998 	ljmp	00175$
                                   3999 ;	..\COMMON\easyax5043.c:705: case AXRADIO_MODE_ASYNC_RECEIVE:
      00136A                       4000 00162$:
                                   4001 ;	..\COMMON\easyax5043.c:706: ax5043_init_registers_rx();
      00136A 12 0B 65         [24] 4002 	lcall	_ax5043_init_registers_rx
                                   4003 ;	..\COMMON\easyax5043.c:707: ax5043_receiver_on_continuous();
      00136D 12 16 3B         [24] 4004 	lcall	_ax5043_receiver_on_continuous
                                   4005 ;	..\COMMON\easyax5043.c:708: break;
      001370 02 13 F1         [24] 4006 	ljmp	00176$
                                   4007 ;	..\COMMON\easyax5043.c:710: case AXRADIO_MODE_ACK_RECEIVE:
      001373                       4008 00163$:
                                   4009 ;	..\COMMON\easyax5043.c:711: if (axradio_cb_receive.st.error == AXRADIO_ERR_PACKETDONE) {
      001373 90 02 49         [24] 4010 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      001376 E0               [24] 4011 	movx	a,@dptr
      001377 FF               [12] 4012 	mov	r7,a
      001378 BF F0 08         [24] 4013 	cjne	r7,#0xf0,00166$
                                   4014 ;	..\COMMON\easyax5043.c:712: ax5043_init_registers_rx();
      00137B 12 0B 65         [24] 4015 	lcall	_ax5043_init_registers_rx
                                   4016 ;	..\COMMON\easyax5043.c:713: ax5043_receiver_on_continuous();
      00137E 12 16 3B         [24] 4017 	lcall	_ax5043_receiver_on_continuous
                                   4018 ;	..\COMMON\easyax5043.c:714: break;
                                   4019 ;	..\COMMON\easyax5043.c:716: offxtal:
      001381 80 6E            [24] 4020 	sjmp	00176$
      001383                       4021 00166$:
                                   4022 ;	..\COMMON\easyax5043.c:717: ax5043_off_xtal();
      001383 12 17 93         [24] 4023 	lcall	_ax5043_off_xtal
                                   4024 ;	..\COMMON\easyax5043.c:718: break;
                                   4025 ;	..\COMMON\easyax5043.c:720: case AXRADIO_MODE_WOR_RECEIVE:
      001386 80 69            [24] 4026 	sjmp	00176$
      001388                       4027 00167$:
                                   4028 ;	..\COMMON\easyax5043.c:721: if (axradio_cb_receive.st.error == AXRADIO_ERR_PACKETDONE) {
      001388 90 02 49         [24] 4029 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      00138B E0               [24] 4030 	movx	a,@dptr
      00138C FF               [12] 4031 	mov	r7,a
      00138D BF F0 F3         [24] 4032 	cjne	r7,#0xf0,00166$
                                   4033 ;	..\COMMON\easyax5043.c:722: ax5043_init_registers_rx();
      001390 12 0B 65         [24] 4034 	lcall	_ax5043_init_registers_rx
                                   4035 ;	..\COMMON\easyax5043.c:723: ax5043_receiver_on_wor();
      001393 12 16 A2         [24] 4036 	lcall	_ax5043_receiver_on_wor
                                   4037 ;	..\COMMON\easyax5043.c:724: break;
                                   4038 ;	..\COMMON\easyax5043.c:728: case AXRADIO_MODE_WOR_ACK_RECEIVE:
      001396 80 59            [24] 4039 	sjmp	00176$
      001398                       4040 00170$:
                                   4041 ;	..\COMMON\easyax5043.c:729: ax5043_init_registers_rx();
      001398 12 0B 65         [24] 4042 	lcall	_ax5043_init_registers_rx
                                   4043 ;	..\COMMON\easyax5043.c:730: ax5043_receiver_on_wor();
      00139B 12 16 A2         [24] 4044 	lcall	_ax5043_receiver_on_wor
                                   4045 ;	..\COMMON\easyax5043.c:731: break;
                                   4046 ;	..\COMMON\easyax5043.c:733: case AXRADIO_MODE_SYNC_ACK_MASTER:
      00139E 80 51            [24] 4047 	sjmp	00176$
      0013A0                       4048 00171$:
                                   4049 ;	..\COMMON\easyax5043.c:734: axradio_txbuffer_len = axradio_framing_minpayloadlen;
      0013A0 90 4C CE         [24] 4050 	mov	dptr,#_axradio_framing_minpayloadlen
      0013A3 E4               [12] 4051 	clr	a
      0013A4 93               [24] 4052 	movc	a,@a+dptr
      0013A5 FF               [12] 4053 	mov	r7,a
      0013A6 90 00 14         [24] 4054 	mov	dptr,#_axradio_txbuffer_len
      0013A9 F0               [24] 4055 	movx	@dptr,a
      0013AA E4               [12] 4056 	clr	a
      0013AB A3               [24] 4057 	inc	dptr
      0013AC F0               [24] 4058 	movx	@dptr,a
                                   4059 ;	..\COMMON\easyax5043.c:738: case AXRADIO_MODE_WOR_ACK_TRANSMIT:
      0013AD                       4060 00173$:
                                   4061 ;	..\COMMON\easyax5043.c:739: ax5043_init_registers_rx();
      0013AD 12 0B 65         [24] 4062 	lcall	_ax5043_init_registers_rx
                                   4063 ;	..\COMMON\easyax5043.c:740: ax5043_receiver_on_continuous();
      0013B0 12 16 3B         [24] 4064 	lcall	_ax5043_receiver_on_continuous
                                   4065 ;	..\COMMON\easyax5043.c:741: wtimer_remove(&axradio_timer);
      0013B3 90 02 9D         [24] 4066 	mov	dptr,#_axradio_timer
      0013B6 12 47 8D         [24] 4067 	lcall	_wtimer_remove
                                   4068 ;	..\COMMON\easyax5043.c:742: axradio_timer.time = axradio_framing_ack_timeout;
      0013B9 90 4C C4         [24] 4069 	mov	dptr,#_axradio_framing_ack_timeout
      0013BC E4               [12] 4070 	clr	a
      0013BD 93               [24] 4071 	movc	a,@a+dptr
      0013BE FC               [12] 4072 	mov	r4,a
      0013BF 74 01            [12] 4073 	mov	a,#0x01
      0013C1 93               [24] 4074 	movc	a,@a+dptr
      0013C2 FD               [12] 4075 	mov	r5,a
      0013C3 74 02            [12] 4076 	mov	a,#0x02
      0013C5 93               [24] 4077 	movc	a,@a+dptr
      0013C6 FE               [12] 4078 	mov	r6,a
      0013C7 74 03            [12] 4079 	mov	a,#0x03
      0013C9 93               [24] 4080 	movc	a,@a+dptr
      0013CA FF               [12] 4081 	mov	r7,a
      0013CB 90 02 A1         [24] 4082 	mov	dptr,#(_axradio_timer + 0x0004)
      0013CE EC               [12] 4083 	mov	a,r4
      0013CF F0               [24] 4084 	movx	@dptr,a
      0013D0 ED               [12] 4085 	mov	a,r5
      0013D1 A3               [24] 4086 	inc	dptr
      0013D2 F0               [24] 4087 	movx	@dptr,a
      0013D3 EE               [12] 4088 	mov	a,r6
      0013D4 A3               [24] 4089 	inc	dptr
      0013D5 F0               [24] 4090 	movx	@dptr,a
      0013D6 EF               [12] 4091 	mov	a,r7
      0013D7 A3               [24] 4092 	inc	dptr
      0013D8 F0               [24] 4093 	movx	@dptr,a
                                   4094 ;	..\COMMON\easyax5043.c:743: wtimer0_addrelative(&axradio_timer);
      0013D9 90 02 9D         [24] 4095 	mov	dptr,#_axradio_timer
      0013DC 12 42 DE         [24] 4096 	lcall	_wtimer0_addrelative
                                   4097 ;	..\COMMON\easyax5043.c:744: break;
                                   4098 ;	..\COMMON\easyax5043.c:746: case AXRADIO_MODE_SYNC_MASTER:
      0013DF 80 10            [24] 4099 	sjmp	00176$
      0013E1                       4100 00174$:
                                   4101 ;	..\COMMON\easyax5043.c:747: axradio_txbuffer_len = axradio_framing_minpayloadlen;
      0013E1 90 4C CE         [24] 4102 	mov	dptr,#_axradio_framing_minpayloadlen
      0013E4 E4               [12] 4103 	clr	a
      0013E5 93               [24] 4104 	movc	a,@a+dptr
      0013E6 FF               [12] 4105 	mov	r7,a
      0013E7 90 00 14         [24] 4106 	mov	dptr,#_axradio_txbuffer_len
      0013EA F0               [24] 4107 	movx	@dptr,a
      0013EB E4               [12] 4108 	clr	a
      0013EC A3               [24] 4109 	inc	dptr
      0013ED F0               [24] 4110 	movx	@dptr,a
                                   4111 ;	..\COMMON\easyax5043.c:750: default:
      0013EE                       4112 00175$:
                                   4113 ;	..\COMMON\easyax5043.c:751: ax5043_off();
      0013EE 12 17 8A         [24] 4114 	lcall	_ax5043_off
                                   4115 ;	..\COMMON\easyax5043.c:753: }
      0013F1                       4116 00176$:
                                   4117 ;	..\COMMON\easyax5043.c:754: if (axradio_mode != AXRADIO_MODE_SYNC_MASTER &&
      0013F1 74 30            [12] 4118 	mov	a,#0x30
      0013F3 B5 08 02         [24] 4119 	cjne	a,_axradio_mode,00371$
      0013F6 80 1A            [24] 4120 	sjmp	00178$
      0013F8                       4121 00371$:
                                   4122 ;	..\COMMON\easyax5043.c:755: axradio_mode != AXRADIO_MODE_SYNC_ACK_MASTER &&
      0013F8 74 31            [12] 4123 	mov	a,#0x31
      0013FA B5 08 02         [24] 4124 	cjne	a,_axradio_mode,00372$
      0013FD 80 13            [24] 4125 	sjmp	00178$
      0013FF                       4126 00372$:
                                   4127 ;	..\COMMON\easyax5043.c:756: axradio_mode != AXRADIO_MODE_SYNC_SLAVE &&
      0013FF 74 32            [12] 4128 	mov	a,#0x32
      001401 B5 08 02         [24] 4129 	cjne	a,_axradio_mode,00373$
      001404 80 0C            [24] 4130 	sjmp	00178$
      001406                       4131 00373$:
                                   4132 ;	..\COMMON\easyax5043.c:757: axradio_mode != AXRADIO_MODE_SYNC_ACK_SLAVE)
      001406 74 33            [12] 4133 	mov	a,#0x33
      001408 B5 08 02         [24] 4134 	cjne	a,_axradio_mode,00374$
      00140B 80 05            [24] 4135 	sjmp	00178$
      00140D                       4136 00374$:
                                   4137 ;	..\COMMON\easyax5043.c:758: axradio_syncstate = syncstate_off;
      00140D 90 00 13         [24] 4138 	mov	dptr,#_axradio_syncstate
      001410 E4               [12] 4139 	clr	a
      001411 F0               [24] 4140 	movx	@dptr,a
      001412                       4141 00178$:
                                   4142 ;	..\COMMON\easyax5043.c:759: update_timeanchor();
      001412 12 0A 7C         [24] 4143 	lcall	_update_timeanchor
                                   4144 ;	..\COMMON\easyax5043.c:760: wtimer_remove_callback(&axradio_cb_transmitend.cb);
      001415 90 02 89         [24] 4145 	mov	dptr,#_axradio_cb_transmitend
      001418 12 48 82         [24] 4146 	lcall	_wtimer_remove_callback
                                   4147 ;	..\COMMON\easyax5043.c:761: axradio_cb_transmitend.st.error = AXRADIO_ERR_NOERROR;
      00141B 90 02 8E         [24] 4148 	mov	dptr,#(_axradio_cb_transmitend + 0x0005)
      00141E E4               [12] 4149 	clr	a
      00141F F0               [24] 4150 	movx	@dptr,a
                                   4151 ;	..\COMMON\easyax5043.c:762: if (axradio_mode == AXRADIO_MODE_ACK_TRANSMIT ||
      001420 74 12            [12] 4152 	mov	a,#0x12
      001422 B5 08 02         [24] 4153 	cjne	a,_axradio_mode,00375$
      001425 80 0C            [24] 4154 	sjmp	00182$
      001427                       4155 00375$:
                                   4156 ;	..\COMMON\easyax5043.c:763: axradio_mode == AXRADIO_MODE_WOR_ACK_TRANSMIT ||
      001427 74 13            [12] 4157 	mov	a,#0x13
      001429 B5 08 02         [24] 4158 	cjne	a,_axradio_mode,00376$
      00142C 80 05            [24] 4159 	sjmp	00182$
      00142E                       4160 00376$:
                                   4161 ;	..\COMMON\easyax5043.c:764: axradio_mode == AXRADIO_MODE_SYNC_ACK_MASTER)
      00142E 74 31            [12] 4162 	mov	a,#0x31
      001430 B5 08 06         [24] 4163 	cjne	a,_axradio_mode,00183$
      001433                       4164 00182$:
                                   4165 ;	..\COMMON\easyax5043.c:765: axradio_cb_transmitend.st.error = AXRADIO_ERR_BUSY;
      001433 90 02 8E         [24] 4166 	mov	dptr,#(_axradio_cb_transmitend + 0x0005)
      001436 74 02            [12] 4167 	mov	a,#0x02
      001438 F0               [24] 4168 	movx	@dptr,a
      001439                       4169 00183$:
                                   4170 ;	..\COMMON\easyax5043.c:766: axradio_cb_transmitend.st.time.t = axradio_timeanchor.radiotimer;
      001439 90 00 29         [24] 4171 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      00143C E0               [24] 4172 	movx	a,@dptr
      00143D FC               [12] 4173 	mov	r4,a
      00143E A3               [24] 4174 	inc	dptr
      00143F E0               [24] 4175 	movx	a,@dptr
      001440 FD               [12] 4176 	mov	r5,a
      001441 A3               [24] 4177 	inc	dptr
      001442 E0               [24] 4178 	movx	a,@dptr
      001443 FE               [12] 4179 	mov	r6,a
      001444 A3               [24] 4180 	inc	dptr
      001445 E0               [24] 4181 	movx	a,@dptr
      001446 FF               [12] 4182 	mov	r7,a
      001447 90 02 8F         [24] 4183 	mov	dptr,#(_axradio_cb_transmitend + 0x0006)
      00144A EC               [12] 4184 	mov	a,r4
      00144B F0               [24] 4185 	movx	@dptr,a
      00144C ED               [12] 4186 	mov	a,r5
      00144D A3               [24] 4187 	inc	dptr
      00144E F0               [24] 4188 	movx	@dptr,a
      00144F EE               [12] 4189 	mov	a,r6
      001450 A3               [24] 4190 	inc	dptr
      001451 F0               [24] 4191 	movx	@dptr,a
      001452 EF               [12] 4192 	mov	a,r7
      001453 A3               [24] 4193 	inc	dptr
      001454 F0               [24] 4194 	movx	@dptr,a
                                   4195 ;	..\COMMON\easyax5043.c:767: wtimer_add_callback(&axradio_cb_transmitend.cb);
      001455 90 02 89         [24] 4196 	mov	dptr,#_axradio_cb_transmitend
      001458 12 42 C4         [24] 4197 	lcall	_wtimer_add_callback
                                   4198 ;	..\COMMON\easyax5043.c:768: break;
      00145B 02 16 1E         [24] 4199 	ljmp	00260$
                                   4200 ;	..\COMMON\easyax5043.c:771: case trxstate_txcw_xtalwait:
      00145E                       4201 00186$:
                                   4202 ;	..\COMMON\easyax5043.c:772: radio_write8(AX5043_REG_IRQMASK1, 0x00);
      00145E 90 40 06         [24] 4203 	mov	dptr,#0x4006
      001461 E4               [12] 4204 	clr	a
      001462 F0               [24] 4205 	movx	@dptr,a
                                   4206 ;	..\COMMON\easyax5043.c:773: radio_write8(AX5043_REG_IRQMASK0, 0x00);
      001463 90 40 07         [24] 4207 	mov	dptr,#0x4007
      001466 F0               [24] 4208 	movx	@dptr,a
                                   4209 ;	..\COMMON\easyax5043.c:774: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_FULL_TX);
      001467 90 40 02         [24] 4210 	mov	dptr,#0x4002
      00146A 74 0D            [12] 4211 	mov	a,#0x0d
      00146C F0               [24] 4212 	movx	@dptr,a
                                   4213 ;	..\COMMON\easyax5043.c:775: axradio_trxstate = trxstate_off;
      00146D 75 09 00         [24] 4214 	mov	_axradio_trxstate,#0x00
                                   4215 ;	..\COMMON\easyax5043.c:776: update_timeanchor();
      001470 12 0A 7C         [24] 4216 	lcall	_update_timeanchor
                                   4217 ;	..\COMMON\easyax5043.c:777: wtimer_remove_callback(&axradio_cb_transmitstart.cb);
      001473 90 02 7F         [24] 4218 	mov	dptr,#_axradio_cb_transmitstart
      001476 12 48 82         [24] 4219 	lcall	_wtimer_remove_callback
                                   4220 ;	..\COMMON\easyax5043.c:778: axradio_cb_transmitstart.st.error = AXRADIO_ERR_NOERROR;
      001479 90 02 84         [24] 4221 	mov	dptr,#(_axradio_cb_transmitstart + 0x0005)
      00147C E4               [12] 4222 	clr	a
      00147D F0               [24] 4223 	movx	@dptr,a
                                   4224 ;	..\COMMON\easyax5043.c:779: axradio_cb_transmitstart.st.time.t = axradio_timeanchor.radiotimer;
      00147E 90 00 29         [24] 4225 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      001481 E0               [24] 4226 	movx	a,@dptr
      001482 FC               [12] 4227 	mov	r4,a
      001483 A3               [24] 4228 	inc	dptr
      001484 E0               [24] 4229 	movx	a,@dptr
      001485 FD               [12] 4230 	mov	r5,a
      001486 A3               [24] 4231 	inc	dptr
      001487 E0               [24] 4232 	movx	a,@dptr
      001488 FE               [12] 4233 	mov	r6,a
      001489 A3               [24] 4234 	inc	dptr
      00148A E0               [24] 4235 	movx	a,@dptr
      00148B FF               [12] 4236 	mov	r7,a
      00148C 90 02 85         [24] 4237 	mov	dptr,#(_axradio_cb_transmitstart + 0x0006)
      00148F EC               [12] 4238 	mov	a,r4
      001490 F0               [24] 4239 	movx	@dptr,a
      001491 ED               [12] 4240 	mov	a,r5
      001492 A3               [24] 4241 	inc	dptr
      001493 F0               [24] 4242 	movx	@dptr,a
      001494 EE               [12] 4243 	mov	a,r6
      001495 A3               [24] 4244 	inc	dptr
      001496 F0               [24] 4245 	movx	@dptr,a
      001497 EF               [12] 4246 	mov	a,r7
      001498 A3               [24] 4247 	inc	dptr
      001499 F0               [24] 4248 	movx	@dptr,a
                                   4249 ;	..\COMMON\easyax5043.c:780: wtimer_add_callback(&axradio_cb_transmitstart.cb);
      00149A 90 02 7F         [24] 4250 	mov	dptr,#_axradio_cb_transmitstart
      00149D 12 42 C4         [24] 4251 	lcall	_wtimer_add_callback
                                   4252 ;	..\COMMON\easyax5043.c:781: break;
      0014A0 02 16 1E         [24] 4253 	ljmp	00260$
                                   4254 ;	..\COMMON\easyax5043.c:783: case trxstate_txstream_xtalwait:
      0014A3                       4255 00196$:
                                   4256 ;	..\COMMON\easyax5043.c:784: if (radio_read8(AX5043_REG_IRQREQUEST1) & 0x01) {
      0014A3 90 40 0C         [24] 4257 	mov	dptr,#0x400c
      0014A6 E0               [24] 4258 	movx	a,@dptr
      0014A7 FF               [12] 4259 	mov	r7,a
      0014A8 20 E0 03         [24] 4260 	jb	acc.0,00379$
      0014AB 02 15 7D         [24] 4261 	ljmp	00221$
      0014AE                       4262 00379$:
                                   4263 ;	..\COMMON\easyax5043.c:785: radio_write8(AX5043_REG_RADIOEVENTMASK0, 0x03); // enable PLL settled and done event
      0014AE 90 40 09         [24] 4264 	mov	dptr,#0x4009
      0014B1 74 03            [12] 4265 	mov	a,#0x03
      0014B3 F0               [24] 4266 	movx	@dptr,a
                                   4267 ;	..\COMMON\easyax5043.c:786: radio_write8(AX5043_REG_IRQMASK1, 0x00);
      0014B4 90 40 06         [24] 4268 	mov	dptr,#0x4006
      0014B7 E4               [12] 4269 	clr	a
      0014B8 F0               [24] 4270 	movx	@dptr,a
                                   4271 ;	..\COMMON\easyax5043.c:787: radio_write8(AX5043_REG_IRQMASK0, 0x40); // enable radio controller irq
      0014B9 90 40 07         [24] 4272 	mov	dptr,#0x4007
      0014BC 74 40            [12] 4273 	mov	a,#0x40
      0014BE F0               [24] 4274 	movx	@dptr,a
                                   4275 ;	..\COMMON\easyax5043.c:788: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_FULL_TX);
      0014BF 90 40 02         [24] 4276 	mov	dptr,#0x4002
      0014C2 74 0D            [12] 4277 	mov	a,#0x0d
      0014C4 F0               [24] 4278 	movx	@dptr,a
                                   4279 ;	..\COMMON\easyax5043.c:789: axradio_trxstate = trxstate_txstream;
      0014C5 75 09 10         [24] 4280 	mov	_axradio_trxstate,#0x10
                                   4281 ;	..\COMMON\easyax5043.c:791: goto txstreamdatacb;
      0014C8 02 15 7D         [24] 4282 	ljmp	00221$
                                   4283 ;	..\COMMON\easyax5043.c:793: case trxstate_txstream:
      0014CB                       4284 00211$:
                                   4285 ;	..\COMMON\easyax5043.c:795: uint8_t __autodata evt = radio_read8(AX5043_REG_RADIOEVENTREQ0);
      0014CB 90 40 0F         [24] 4286 	mov	dptr,#0x400f
      0014CE E0               [24] 4287 	movx	a,@dptr
      0014CF FF               [12] 4288 	mov	r7,a
                                   4289 ;	..\COMMON\easyax5043.c:796: radio_write8(AX5043_REG_RADIOEVENTMASK0, 0x00);
      0014D0 90 40 09         [24] 4290 	mov	dptr,#0x4009
      0014D3 E4               [12] 4291 	clr	a
      0014D4 F0               [24] 4292 	movx	@dptr,a
                                   4293 ;	..\COMMON\easyax5043.c:797: if (evt & 0x03)
      0014D5 EF               [12] 4294 	mov	a,r7
      0014D6 54 03            [12] 4295 	anl	a,#0x03
      0014D8 60 07            [24] 4296 	jz	00216$
                                   4297 ;	..\COMMON\easyax5043.c:798: update_timeanchor();
      0014DA C0 07            [24] 4298 	push	ar7
      0014DC 12 0A 7C         [24] 4299 	lcall	_update_timeanchor
      0014DF D0 07            [24] 4300 	pop	ar7
      0014E1                       4301 00216$:
                                   4302 ;	..\COMMON\easyax5043.c:799: if (evt & 0x01) {
      0014E1 EF               [12] 4303 	mov	a,r7
      0014E2 30 E0 34         [24] 4304 	jnb	acc.0,00218$
                                   4305 ;	..\COMMON\easyax5043.c:800: update_timeanchor();
      0014E5 C0 07            [24] 4306 	push	ar7
      0014E7 12 0A 7C         [24] 4307 	lcall	_update_timeanchor
                                   4308 ;	..\COMMON\easyax5043.c:801: wtimer_remove_callback(&axradio_cb_transmitend.cb);
      0014EA 90 02 89         [24] 4309 	mov	dptr,#_axradio_cb_transmitend
      0014ED 12 48 82         [24] 4310 	lcall	_wtimer_remove_callback
                                   4311 ;	..\COMMON\easyax5043.c:802: axradio_cb_transmitend.st.error = AXRADIO_ERR_NOERROR;
      0014F0 90 02 8E         [24] 4312 	mov	dptr,#(_axradio_cb_transmitend + 0x0005)
      0014F3 E4               [12] 4313 	clr	a
      0014F4 F0               [24] 4314 	movx	@dptr,a
                                   4315 ;	..\COMMON\easyax5043.c:803: axradio_cb_transmitend.st.time.t = axradio_timeanchor.radiotimer;
      0014F5 90 00 29         [24] 4316 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      0014F8 E0               [24] 4317 	movx	a,@dptr
      0014F9 FB               [12] 4318 	mov	r3,a
      0014FA A3               [24] 4319 	inc	dptr
      0014FB E0               [24] 4320 	movx	a,@dptr
      0014FC FC               [12] 4321 	mov	r4,a
      0014FD A3               [24] 4322 	inc	dptr
      0014FE E0               [24] 4323 	movx	a,@dptr
      0014FF FD               [12] 4324 	mov	r5,a
      001500 A3               [24] 4325 	inc	dptr
      001501 E0               [24] 4326 	movx	a,@dptr
      001502 FE               [12] 4327 	mov	r6,a
      001503 90 02 8F         [24] 4328 	mov	dptr,#(_axradio_cb_transmitend + 0x0006)
      001506 EB               [12] 4329 	mov	a,r3
      001507 F0               [24] 4330 	movx	@dptr,a
      001508 EC               [12] 4331 	mov	a,r4
      001509 A3               [24] 4332 	inc	dptr
      00150A F0               [24] 4333 	movx	@dptr,a
      00150B ED               [12] 4334 	mov	a,r5
      00150C A3               [24] 4335 	inc	dptr
      00150D F0               [24] 4336 	movx	@dptr,a
      00150E EE               [12] 4337 	mov	a,r6
      00150F A3               [24] 4338 	inc	dptr
      001510 F0               [24] 4339 	movx	@dptr,a
                                   4340 ;	..\COMMON\easyax5043.c:804: wtimer_add_callback(&axradio_cb_transmitend.cb);
      001511 90 02 89         [24] 4341 	mov	dptr,#_axradio_cb_transmitend
      001514 12 42 C4         [24] 4342 	lcall	_wtimer_add_callback
      001517 D0 07            [24] 4343 	pop	ar7
      001519                       4344 00218$:
                                   4345 ;	..\COMMON\easyax5043.c:806: if (evt & 0x02) {
      001519 EF               [12] 4346 	mov	a,r7
      00151A 30 E1 60         [24] 4347 	jnb	acc.1,00221$
                                   4348 ;	..\COMMON\easyax5043.c:807: update_timeanchor();
      00151D 12 0A 7C         [24] 4349 	lcall	_update_timeanchor
                                   4350 ;	..\COMMON\easyax5043.c:808: wtimer_remove_callback(&axradio_cb_transmitstart.cb);
      001520 90 02 7F         [24] 4351 	mov	dptr,#_axradio_cb_transmitstart
      001523 12 48 82         [24] 4352 	lcall	_wtimer_remove_callback
                                   4353 ;	..\COMMON\easyax5043.c:809: axradio_cb_transmitstart.st.error = AXRADIO_ERR_NOERROR;
      001526 90 02 84         [24] 4354 	mov	dptr,#(_axradio_cb_transmitstart + 0x0005)
      001529 E4               [12] 4355 	clr	a
      00152A F0               [24] 4356 	movx	@dptr,a
                                   4357 ;	..\COMMON\easyax5043.c:810: axradio_cb_transmitstart.st.time.t = axradio_timeanchor.radiotimer;
      00152B 90 00 29         [24] 4358 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      00152E E0               [24] 4359 	movx	a,@dptr
      00152F FC               [12] 4360 	mov	r4,a
      001530 A3               [24] 4361 	inc	dptr
      001531 E0               [24] 4362 	movx	a,@dptr
      001532 FD               [12] 4363 	mov	r5,a
      001533 A3               [24] 4364 	inc	dptr
      001534 E0               [24] 4365 	movx	a,@dptr
      001535 FE               [12] 4366 	mov	r6,a
      001536 A3               [24] 4367 	inc	dptr
      001537 E0               [24] 4368 	movx	a,@dptr
      001538 FF               [12] 4369 	mov	r7,a
      001539 90 02 85         [24] 4370 	mov	dptr,#(_axradio_cb_transmitstart + 0x0006)
      00153C EC               [12] 4371 	mov	a,r4
      00153D F0               [24] 4372 	movx	@dptr,a
      00153E ED               [12] 4373 	mov	a,r5
      00153F A3               [24] 4374 	inc	dptr
      001540 F0               [24] 4375 	movx	@dptr,a
      001541 EE               [12] 4376 	mov	a,r6
      001542 A3               [24] 4377 	inc	dptr
      001543 F0               [24] 4378 	movx	@dptr,a
      001544 EF               [12] 4379 	mov	a,r7
      001545 A3               [24] 4380 	inc	dptr
      001546 F0               [24] 4381 	movx	@dptr,a
                                   4382 ;	..\COMMON\easyax5043.c:811: wtimer_add_callback(&axradio_cb_transmitstart.cb);
      001547 90 02 7F         [24] 4383 	mov	dptr,#_axradio_cb_transmitstart
      00154A 12 42 C4         [24] 4384 	lcall	_wtimer_add_callback
                                   4385 ;	..\COMMON\easyax5043.c:813: update_timeanchor();
      00154D 12 0A 7C         [24] 4386 	lcall	_update_timeanchor
                                   4387 ;	..\COMMON\easyax5043.c:814: wtimer_remove_callback(&axradio_cb_transmitdata.cb);
      001550 90 02 93         [24] 4388 	mov	dptr,#_axradio_cb_transmitdata
      001553 12 48 82         [24] 4389 	lcall	_wtimer_remove_callback
                                   4390 ;	..\COMMON\easyax5043.c:815: axradio_cb_transmitdata.st.error = AXRADIO_ERR_NOERROR;
      001556 90 02 98         [24] 4391 	mov	dptr,#(_axradio_cb_transmitdata + 0x0005)
      001559 E4               [12] 4392 	clr	a
      00155A F0               [24] 4393 	movx	@dptr,a
                                   4394 ;	..\COMMON\easyax5043.c:816: axradio_cb_transmitdata.st.time.t = axradio_timeanchor.radiotimer;
      00155B 90 00 29         [24] 4395 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      00155E E0               [24] 4396 	movx	a,@dptr
      00155F FC               [12] 4397 	mov	r4,a
      001560 A3               [24] 4398 	inc	dptr
      001561 E0               [24] 4399 	movx	a,@dptr
      001562 FD               [12] 4400 	mov	r5,a
      001563 A3               [24] 4401 	inc	dptr
      001564 E0               [24] 4402 	movx	a,@dptr
      001565 FE               [12] 4403 	mov	r6,a
      001566 A3               [24] 4404 	inc	dptr
      001567 E0               [24] 4405 	movx	a,@dptr
      001568 FF               [12] 4406 	mov	r7,a
      001569 90 02 99         [24] 4407 	mov	dptr,#(_axradio_cb_transmitdata + 0x0006)
      00156C EC               [12] 4408 	mov	a,r4
      00156D F0               [24] 4409 	movx	@dptr,a
      00156E ED               [12] 4410 	mov	a,r5
      00156F A3               [24] 4411 	inc	dptr
      001570 F0               [24] 4412 	movx	@dptr,a
      001571 EE               [12] 4413 	mov	a,r6
      001572 A3               [24] 4414 	inc	dptr
      001573 F0               [24] 4415 	movx	@dptr,a
      001574 EF               [12] 4416 	mov	a,r7
      001575 A3               [24] 4417 	inc	dptr
      001576 F0               [24] 4418 	movx	@dptr,a
                                   4419 ;	..\COMMON\easyax5043.c:817: wtimer_add_callback(&axradio_cb_transmitdata.cb);
      001577 90 02 93         [24] 4420 	mov	dptr,#_axradio_cb_transmitdata
      00157A 12 42 C4         [24] 4421 	lcall	_wtimer_add_callback
                                   4422 ;	..\COMMON\easyax5043.c:820: txstreamdatacb:
      00157D                       4423 00221$:
                                   4424 ;	..\COMMON\easyax5043.c:821: if (radio_read8(AX5043_REG_IRQREQUEST0) & radio_read8(AX5043_REG_IRQMASK0) & 0x08) {
      00157D 90 40 0D         [24] 4425 	mov	dptr,#0x400d
      001580 E0               [24] 4426 	movx	a,@dptr
      001581 FF               [12] 4427 	mov	r7,a
      001582 90 40 07         [24] 4428 	mov	dptr,#0x4007
      001585 E0               [24] 4429 	movx	a,@dptr
      001586 FE               [12] 4430 	mov	r6,a
      001587 5F               [12] 4431 	anl	a,r7
      001588 20 E3 03         [24] 4432 	jb	acc.3,00383$
      00158B 02 16 1E         [24] 4433 	ljmp	00260$
      00158E                       4434 00383$:
                                   4435 ;	..\COMMON\easyax5043.c:822: radio_write8(AX5043_REG_IRQMASK0, (radio_read8(AX5043_REG_IRQMASK0) & (uint8_t)~0x08));
      00158E 90 40 07         [24] 4436 	mov	dptr,#0x4007
      001591 E0               [24] 4437 	movx	a,@dptr
      001592 54 F7            [12] 4438 	anl	a,#0xf7
      001594 F0               [24] 4439 	movx	@dptr,a
                                   4440 ;	..\COMMON\easyax5043.c:823: update_timeanchor();
      001595 12 0A 7C         [24] 4441 	lcall	_update_timeanchor
                                   4442 ;	..\COMMON\easyax5043.c:824: wtimer_remove_callback(&axradio_cb_transmitdata.cb);
      001598 90 02 93         [24] 4443 	mov	dptr,#_axradio_cb_transmitdata
      00159B 12 48 82         [24] 4444 	lcall	_wtimer_remove_callback
                                   4445 ;	..\COMMON\easyax5043.c:825: axradio_cb_transmitdata.st.error = AXRADIO_ERR_NOERROR;
      00159E 90 02 98         [24] 4446 	mov	dptr,#(_axradio_cb_transmitdata + 0x0005)
      0015A1 E4               [12] 4447 	clr	a
      0015A2 F0               [24] 4448 	movx	@dptr,a
                                   4449 ;	..\COMMON\easyax5043.c:826: axradio_cb_transmitdata.st.time.t = axradio_timeanchor.radiotimer;
      0015A3 90 00 29         [24] 4450 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      0015A6 E0               [24] 4451 	movx	a,@dptr
      0015A7 FC               [12] 4452 	mov	r4,a
      0015A8 A3               [24] 4453 	inc	dptr
      0015A9 E0               [24] 4454 	movx	a,@dptr
      0015AA FD               [12] 4455 	mov	r5,a
      0015AB A3               [24] 4456 	inc	dptr
      0015AC E0               [24] 4457 	movx	a,@dptr
      0015AD FE               [12] 4458 	mov	r6,a
      0015AE A3               [24] 4459 	inc	dptr
      0015AF E0               [24] 4460 	movx	a,@dptr
      0015B0 FF               [12] 4461 	mov	r7,a
      0015B1 90 02 99         [24] 4462 	mov	dptr,#(_axradio_cb_transmitdata + 0x0006)
      0015B4 EC               [12] 4463 	mov	a,r4
      0015B5 F0               [24] 4464 	movx	@dptr,a
      0015B6 ED               [12] 4465 	mov	a,r5
      0015B7 A3               [24] 4466 	inc	dptr
      0015B8 F0               [24] 4467 	movx	@dptr,a
      0015B9 EE               [12] 4468 	mov	a,r6
      0015BA A3               [24] 4469 	inc	dptr
      0015BB F0               [24] 4470 	movx	@dptr,a
      0015BC EF               [12] 4471 	mov	a,r7
      0015BD A3               [24] 4472 	inc	dptr
      0015BE F0               [24] 4473 	movx	@dptr,a
                                   4474 ;	..\COMMON\easyax5043.c:827: wtimer_add_callback(&axradio_cb_transmitdata.cb);
      0015BF 90 02 93         [24] 4475 	mov	dptr,#_axradio_cb_transmitdata
      0015C2 12 42 C4         [24] 4476 	lcall	_wtimer_add_callback
                                   4477 ;	..\COMMON\easyax5043.c:829: break;
                                   4478 ;	..\COMMON\easyax5043.c:831: case trxstate_rxwor:
      0015C5 80 57            [24] 4479 	sjmp	00260$
      0015C7                       4480 00227$:
                                   4481 ;	..\COMMON\easyax5043.c:837: if (radio_read8(AX5043_REG_IRQREQUEST0) & 0x80) { // vdda ready (note irqinversion does not act upon AX5043_REG_IRQREQUEST0)
      0015C7 90 40 0D         [24] 4482 	mov	dptr,#0x400d
      0015CA E0               [24] 4483 	movx	a,@dptr
      0015CB FF               [12] 4484 	mov	r7,a
      0015CC 30 E7 0A         [24] 4485 	jnb	acc.7,00231$
                                   4486 ;	..\COMMON\easyax5043.c:838: radio_write8(AX5043_REG_IRQINVERSION0, (radio_read8(AX5043_REG_IRQINVERSION0) | 0x80)); // invert pwr irq, so it does not fire continuously
      0015CF 90 40 0B         [24] 4487 	mov	dptr,#0x400b
      0015D2 E0               [24] 4488 	movx	a,@dptr
      0015D3 44 80            [12] 4489 	orl	a,#0x80
      0015D5 FF               [12] 4490 	mov	r7,a
      0015D6 F0               [24] 4491 	movx	@dptr,a
                                   4492 ;	..\COMMON\easyax5043.c:840: radio_write8(AX5043_REG_IRQINVERSION0, (radio_read8(AX5043_REG_IRQINVERSION0) & (uint8_t)~0x80)); // drop pwr irq inversion --> armed again
      0015D7 80 08            [24] 4493 	sjmp	00236$
      0015D9                       4494 00231$:
      0015D9 90 40 0B         [24] 4495 	mov	dptr,#0x400b
      0015DC E0               [24] 4496 	movx	a,@dptr
      0015DD 54 7F            [12] 4497 	anl	a,#0x7f
      0015DF FF               [12] 4498 	mov	r7,a
      0015E0 F0               [24] 4499 	movx	@dptr,a
      0015E1                       4500 00236$:
                                   4501 ;	..\COMMON\easyax5043.c:843: if (radio_read8(AX5043_REG_IRQREQUEST1) & 0x01) { // XTAL ready
      0015E1 90 40 0C         [24] 4502 	mov	dptr,#0x400c
      0015E4 E0               [24] 4503 	movx	a,@dptr
      0015E5 FF               [12] 4504 	mov	r7,a
      0015E6 30 E0 0A         [24] 4505 	jnb	acc.0,00240$
                                   4506 ;	..\COMMON\easyax5043.c:844: radio_write8(AX5043_REG_IRQINVERSION1, (radio_read8(AX5043_REG_IRQINVERSION1) | 0x01)); // invert the xtal ready irq so it does not fire continuously
      0015E9 90 40 0A         [24] 4507 	mov	dptr,#0x400a
      0015EC E0               [24] 4508 	movx	a,@dptr
      0015ED 44 01            [12] 4509 	orl	a,#0x01
      0015EF FF               [12] 4510 	mov	r7,a
      0015F0 F0               [24] 4511 	movx	@dptr,a
                                   4512 ;	..\COMMON\easyax5043.c:847: radio_write8(AX5043_REG_IRQINVERSION1, (radio_read8(AX5043_REG_IRQINVERSION1) & (uint8_t)~0x01)); // drop xtal ready irq inversion --> armed again for next wake-up
      0015F1 80 28            [24] 4513 	sjmp	00258$
      0015F3                       4514 00240$:
      0015F3 90 40 0A         [24] 4515 	mov	dptr,#0x400a
      0015F6 E0               [24] 4516 	movx	a,@dptr
      0015F7 54 FE            [12] 4517 	anl	a,#0xfe
      0015F9 F0               [24] 4518 	movx	@dptr,a
                                   4519 ;	..\COMMON\easyax5043.c:848: radio_write8(AX5043_REG_0xF30, f30_saved);
      0015FA 90 04 4D         [24] 4520 	mov	dptr,#_f30_saved
      0015FD E0               [24] 4521 	movx	a,@dptr
      0015FE 90 4F 30         [24] 4522 	mov	dptr,#0x4f30
      001601 F0               [24] 4523 	movx	@dptr,a
                                   4524 ;	..\COMMON\easyax5043.c:849: radio_write8(AX5043_REG_0xF31, f31_saved);
      001602 90 04 4E         [24] 4525 	mov	dptr,#_f31_saved
      001605 E0               [24] 4526 	movx	a,@dptr
      001606 90 4F 31         [24] 4527 	mov	dptr,#0x4f31
      001609 F0               [24] 4528 	movx	@dptr,a
                                   4529 ;	..\COMMON\easyax5043.c:850: radio_write8(AX5043_REG_0xF32, f32_saved);
      00160A 90 04 4F         [24] 4530 	mov	dptr,#_f32_saved
      00160D E0               [24] 4531 	movx	a,@dptr
      00160E 90 4F 32         [24] 4532 	mov	dptr,#0x4f32
      001611 F0               [24] 4533 	movx	@dptr,a
                                   4534 ;	..\COMMON\easyax5043.c:851: radio_write8(AX5043_REG_0xF33, f33_saved);
      001612 90 04 50         [24] 4535 	mov	dptr,#_f33_saved
      001615 E0               [24] 4536 	movx	a,@dptr
      001616 FF               [12] 4537 	mov	r7,a
      001617 90 4F 33         [24] 4538 	mov	dptr,#0x4f33
      00161A F0               [24] 4539 	movx	@dptr,a
                                   4540 ;	..\COMMON\easyax5043.c:855: case trxstate_rx:
      00161B                       4541 00258$:
                                   4542 ;	..\COMMON\easyax5043.c:856: receive_isr();
      00161B 12 0B 6B         [24] 4543 	lcall	_receive_isr
                                   4544 ;	..\COMMON\easyax5043.c:859: } // end switch(axradio_trxstate)
      00161E                       4545 00260$:
      00161E D0 D0            [24] 4546 	pop	psw
      001620 D0 00            [24] 4547 	pop	(0+0)
      001622 D0 01            [24] 4548 	pop	(0+1)
      001624 D0 02            [24] 4549 	pop	(0+2)
      001626 D0 03            [24] 4550 	pop	(0+3)
      001628 D0 04            [24] 4551 	pop	(0+4)
      00162A D0 05            [24] 4552 	pop	(0+5)
      00162C D0 06            [24] 4553 	pop	(0+6)
      00162E D0 07            [24] 4554 	pop	(0+7)
      001630 D0 83            [24] 4555 	pop	dph
      001632 D0 82            [24] 4556 	pop	dpl
      001634 D0 F0            [24] 4557 	pop	b
      001636 D0 E0            [24] 4558 	pop	acc
      001638 D0 21            [24] 4559 	pop	bits
      00163A 32               [24] 4560 	reti
                                   4561 ;------------------------------------------------------------
                                   4562 ;Allocation info for local variables in function 'ax5043_receiver_on_continuous'
                                   4563 ;------------------------------------------------------------
                                   4564 ;rschanged_int             Allocated to registers r6 
                                   4565 ;------------------------------------------------------------
                                   4566 ;	..\COMMON\easyax5043.c:863: __reentrantb void ax5043_receiver_on_continuous(void) __reentrant
                                   4567 ;	-----------------------------------------
                                   4568 ;	 function ax5043_receiver_on_continuous
                                   4569 ;	-----------------------------------------
      00163B                       4570 _ax5043_receiver_on_continuous:
                                   4571 ;	..\COMMON\easyax5043.c:865: uint8_t rschanged_int = (axradio_framing_enable_sfdcallback | (axradio_mode == AXRADIO_MODE_SYNC_ACK_SLAVE) | (axradio_mode == AXRADIO_MODE_SYNC_SLAVE) );
      00163B 74 33            [12] 4572 	mov	a,#0x33
      00163D B5 08 04         [24] 4573 	cjne	a,_axradio_mode,00138$
      001640 74 01            [12] 4574 	mov	a,#0x01
      001642 80 01            [24] 4575 	sjmp	00139$
      001644                       4576 00138$:
      001644 E4               [12] 4577 	clr	a
      001645                       4578 00139$:
      001645 FF               [12] 4579 	mov	r7,a
      001646 90 4C C3         [24] 4580 	mov	dptr,#_axradio_framing_enable_sfdcallback
      001649 E4               [12] 4581 	clr	a
      00164A 93               [24] 4582 	movc	a,@a+dptr
      00164B FE               [12] 4583 	mov	r6,a
      00164C 42 07            [12] 4584 	orl	ar7,a
      00164E 74 32            [12] 4585 	mov	a,#0x32
      001650 B5 08 04         [24] 4586 	cjne	a,_axradio_mode,00140$
      001653 74 01            [12] 4587 	mov	a,#0x01
      001655 80 01            [24] 4588 	sjmp	00141$
      001657                       4589 00140$:
      001657 E4               [12] 4590 	clr	a
      001658                       4591 00141$:
      001658 42 07            [12] 4592 	orl	ar7,a
                                   4593 ;	..\COMMON\easyax5043.c:866: if (rschanged_int)
      00165A EF               [12] 4594 	mov	a,r7
      00165B FE               [12] 4595 	mov	r6,a
      00165C 60 06            [24] 4596 	jz	00106$
                                   4597 ;	..\COMMON\easyax5043.c:867: radio_write8(AX5043_REG_RADIOEVENTMASK0, 0x04);
      00165E 90 40 09         [24] 4598 	mov	dptr,#0x4009
      001661 74 04            [12] 4599 	mov	a,#0x04
      001663 F0               [24] 4600 	movx	@dptr,a
                                   4601 ;	..\COMMON\easyax5043.c:868: radio_write8(AX5043_REG_RSSIREFERENCE, axradio_phy_rssireference);
      001664                       4602 00106$:
      001664 90 4C A2         [24] 4603 	mov	dptr,#_axradio_phy_rssireference
      001667 E4               [12] 4604 	clr	a
      001668 93               [24] 4605 	movc	a,@a+dptr
      001669 90 42 2C         [24] 4606 	mov	dptr,#0x422c
      00166C F0               [24] 4607 	movx	@dptr,a
                                   4608 ;	..\COMMON\easyax5043.c:869: ax5043_set_registers_rxcont();
      00166D C0 06            [24] 4609 	push	ar6
      00166F 12 06 AF         [24] 4610 	lcall	_ax5043_set_registers_rxcont
      001672 D0 06            [24] 4611 	pop	ar6
                                   4612 ;	..\COMMON\easyax5043.c:882: radio_write8(AX5043_REG_PKTSTOREFLAGS, radio_read8(AX5043_REG_PKTSTOREFLAGS) & (uint8_t)~0x40);
      001674 90 42 32         [24] 4613 	mov	dptr,#0x4232
      001677 E0               [24] 4614 	movx	a,@dptr
      001678 54 BF            [12] 4615 	anl	a,#0xbf
      00167A FF               [12] 4616 	mov	r7,a
      00167B F0               [24] 4617 	movx	@dptr,a
                                   4618 ;	..\COMMON\easyax5043.c:885: radio_write8(AX5043_REG_FIFOSTAT, 3); // clear FIFO data & flags
      00167C 90 40 28         [24] 4619 	mov	dptr,#0x4028
      00167F 74 03            [12] 4620 	mov	a,#0x03
      001681 F0               [24] 4621 	movx	@dptr,a
                                   4622 ;	..\COMMON\easyax5043.c:886: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_FULL_RX);
      001682 90 40 02         [24] 4623 	mov	dptr,#0x4002
      001685 74 09            [12] 4624 	mov	a,#0x09
      001687 F0               [24] 4625 	movx	@dptr,a
                                   4626 ;	..\COMMON\easyax5043.c:887: axradio_trxstate = trxstate_rx;
      001688 75 09 01         [24] 4627 	mov	_axradio_trxstate,#0x01
                                   4628 ;	..\COMMON\easyax5043.c:888: if (rschanged_int)
      00168B EE               [12] 4629 	mov	a,r6
      00168C 60 08            [24] 4630 	jz	00121$
                                   4631 ;	..\COMMON\easyax5043.c:889: radio_write8(AX5043_REG_IRQMASK0, 0x41); //  enable FIFO not empty / radio controller irq
      00168E 90 40 07         [24] 4632 	mov	dptr,#0x4007
      001691 74 41            [12] 4633 	mov	a,#0x41
      001693 F0               [24] 4634 	movx	@dptr,a
                                   4635 ;	..\COMMON\easyax5043.c:891: radio_write8(AX5043_REG_IRQMASK0, 0x01); //  enable FIFO not empty
      001694 80 06            [24] 4636 	sjmp	00127$
      001696                       4637 00121$:
      001696 90 40 07         [24] 4638 	mov	dptr,#0x4007
      001699 74 01            [12] 4639 	mov	a,#0x01
      00169B F0               [24] 4640 	movx	@dptr,a
                                   4641 ;	..\COMMON\easyax5043.c:892: radio_write8(AX5043_REG_IRQMASK1, 0x00);
      00169C                       4642 00127$:
      00169C 90 40 06         [24] 4643 	mov	dptr,#0x4006
      00169F E4               [12] 4644 	clr	a
      0016A0 F0               [24] 4645 	movx	@dptr,a
      0016A1 22               [24] 4646 	ret
                                   4647 ;------------------------------------------------------------
                                   4648 ;Allocation info for local variables in function 'ax5043_receiver_on_wor'
                                   4649 ;------------------------------------------------------------
                                   4650 ;wp                        Allocated to registers r6 r7 
                                   4651 ;------------------------------------------------------------
                                   4652 ;	..\COMMON\easyax5043.c:895: __reentrantb void ax5043_receiver_on_wor(void) __reentrant
                                   4653 ;	-----------------------------------------
                                   4654 ;	 function ax5043_receiver_on_wor
                                   4655 ;	-----------------------------------------
      0016A2                       4656 _ax5043_receiver_on_wor:
                                   4657 ;	..\COMMON\easyax5043.c:897: radio_write8(AX5043_REG_BGNDRSSIGAIN, 0x02);
      0016A2 90 42 2E         [24] 4658 	mov	dptr,#0x422e
      0016A5 74 02            [12] 4659 	mov	a,#0x02
      0016A7 F0               [24] 4660 	movx	@dptr,a
                                   4661 ;	..\COMMON\easyax5043.c:898: if(axradio_framing_enable_sfdcallback)
      0016A8 90 4C C3         [24] 4662 	mov	dptr,#_axradio_framing_enable_sfdcallback
      0016AB E4               [12] 4663 	clr	a
      0016AC 93               [24] 4664 	movc	a,@a+dptr
      0016AD 60 06            [24] 4665 	jz	00109$
                                   4666 ;	..\COMMON\easyax5043.c:899: radio_write8(AX5043_REG_RADIOEVENTMASK0, 0x04);
      0016AF 90 40 09         [24] 4667 	mov	dptr,#0x4009
      0016B2 74 04            [12] 4668 	mov	a,#0x04
      0016B4 F0               [24] 4669 	movx	@dptr,a
                                   4670 ;	..\COMMON\easyax5043.c:900: radio_write8(AX5043_REG_FIFOSTAT, 3); // clear FIFO data & flags
      0016B5                       4671 00109$:
      0016B5 90 40 28         [24] 4672 	mov	dptr,#0x4028
      0016B8 74 03            [12] 4673 	mov	a,#0x03
      0016BA F0               [24] 4674 	movx	@dptr,a
                                   4675 ;	..\COMMON\easyax5043.c:901: radio_write8(AX5043_REG_LPOSCCONFIG, 0x01); // start LPOSC, slow mode
      0016BB 90 43 10         [24] 4676 	mov	dptr,#0x4310
      0016BE 74 01            [12] 4677 	mov	a,#0x01
      0016C0 F0               [24] 4678 	movx	@dptr,a
                                   4679 ;	..\COMMON\easyax5043.c:902: radio_write8(AX5043_REG_RSSIREFERENCE, axradio_phy_rssireference);
      0016C1 90 4C A2         [24] 4680 	mov	dptr,#_axradio_phy_rssireference
      0016C4 E4               [12] 4681 	clr	a
      0016C5 93               [24] 4682 	movc	a,@a+dptr
      0016C6 90 42 2C         [24] 4683 	mov	dptr,#0x422c
      0016C9 F0               [24] 4684 	movx	@dptr,a
                                   4685 ;	..\COMMON\easyax5043.c:903: ax5043_set_registers_rxwor();
      0016CA 12 06 9C         [24] 4686 	lcall	_ax5043_set_registers_rxwor
                                   4687 ;	..\COMMON\easyax5043.c:904: radio_write8(AX5043_REG_PKTSTOREFLAGS, (radio_read8(AX5043_REG_PKTSTOREFLAGS) & (uint8_t)~0x40));
      0016CD 90 42 32         [24] 4688 	mov	dptr,#0x4232
      0016D0 E0               [24] 4689 	movx	a,@dptr
      0016D1 54 BF            [12] 4690 	anl	a,#0xbf
      0016D3 FF               [12] 4691 	mov	r7,a
      0016D4 F0               [24] 4692 	movx	@dptr,a
                                   4693 ;	..\COMMON\easyax5043.c:906: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_WOR_RX);
      0016D5 90 40 02         [24] 4694 	mov	dptr,#0x4002
      0016D8 74 0B            [12] 4695 	mov	a,#0x0b
      0016DA F0               [24] 4696 	movx	@dptr,a
                                   4697 ;	..\COMMON\easyax5043.c:907: axradio_trxstate = trxstate_rxwor;
      0016DB 75 09 02         [24] 4698 	mov	_axradio_trxstate,#0x02
                                   4699 ;	..\COMMON\easyax5043.c:908: if(axradio_framing_enable_sfdcallback)
      0016DE 90 4C C3         [24] 4700 	mov	dptr,#_axradio_framing_enable_sfdcallback
      0016E1 E4               [12] 4701 	clr	a
      0016E2 93               [24] 4702 	movc	a,@a+dptr
      0016E3 60 08            [24] 4703 	jz	00127$
                                   4704 ;	..\COMMON\easyax5043.c:909: radio_write8(AX5043_REG_IRQMASK0, 0x41); //  enable FIFO not empty / radio controller irq
      0016E5 90 40 07         [24] 4705 	mov	dptr,#0x4007
      0016E8 74 41            [12] 4706 	mov	a,#0x41
      0016EA F0               [24] 4707 	movx	@dptr,a
                                   4708 ;	..\COMMON\easyax5043.c:911: radio_write8(AX5043_REG_IRQMASK0, 0x01); //  enable FIFO not empty
      0016EB 80 06            [24] 4709 	sjmp	00132$
      0016ED                       4710 00127$:
      0016ED 90 40 07         [24] 4711 	mov	dptr,#0x4007
      0016F0 74 01            [12] 4712 	mov	a,#0x01
      0016F2 F0               [24] 4713 	movx	@dptr,a
      0016F3                       4714 00132$:
                                   4715 ;	..\COMMON\easyax5043.c:915: if (((PALTRADIO & 0x40) && ((radio_read8(AX5043_REG_PINFUNCPWRAMP) & 0x0F) == 0x07)) || ((PALTRADIO & 0x80) && ((radio_read8(AX5043_REG_PINFUNCANTSEL) & 0x07) == 0x04))) // pass through of TCXO_EN
      0016F3 90 70 46         [24] 4716 	mov	dptr,#_PALTRADIO
      0016F6 E0               [24] 4717 	movx	a,@dptr
      0016F7 FF               [12] 4718 	mov	r7,a
      0016F8 30 E6 0D         [24] 4719 	jnb	acc.6,00143$
      0016FB 90 40 26         [24] 4720 	mov	dptr,#0x4026
      0016FE E0               [24] 4721 	movx	a,@dptr
      0016FF FF               [12] 4722 	mov	r7,a
      001700 53 07 0F         [24] 4723 	anl	ar7,#0x0f
      001703 BF 07 02         [24] 4724 	cjne	r7,#0x07,00176$
      001706 80 13            [24] 4725 	sjmp	00133$
      001708                       4726 00176$:
      001708                       4727 00143$:
      001708 90 70 46         [24] 4728 	mov	dptr,#_PALTRADIO
      00170B E0               [24] 4729 	movx	a,@dptr
      00170C FF               [12] 4730 	mov	r7,a
      00170D 30 E7 19         [24] 4731 	jnb	acc.7,00144$
      001710 90 40 25         [24] 4732 	mov	dptr,#0x4025
      001713 E0               [24] 4733 	movx	a,@dptr
      001714 FF               [12] 4734 	mov	r7,a
      001715 53 07 07         [24] 4735 	anl	ar7,#0x07
      001718 BF 04 0E         [24] 4736 	cjne	r7,#0x04,00144$
                                   4737 ;	..\COMMON\easyax5043.c:918: radio_write8(AX5043_REG_IRQMASK0, radio_read8(AX5043_REG_IRQMASK0) | 0x80); // power irq (AX8052F143 WOR with TCXO)
      00171B                       4738 00133$:
      00171B 90 40 07         [24] 4739 	mov	dptr,#0x4007
      00171E E0               [24] 4740 	movx	a,@dptr
      00171F 44 80            [12] 4741 	orl	a,#0x80
      001721 FF               [12] 4742 	mov	r7,a
      001722 F0               [24] 4743 	movx	@dptr,a
                                   4744 ;	..\COMMON\easyax5043.c:919: radio_write8(AX5043_REG_POWIRQMASK, 0x90); // interrupt when vddana ready (AX8052F143 WOR with TCXO)
      001723 90 40 05         [24] 4745 	mov	dptr,#0x4005
      001726 74 90            [12] 4746 	mov	a,#0x90
      001728 F0               [24] 4747 	movx	@dptr,a
                                   4748 ;	..\COMMON\easyax5043.c:922: radio_write8(AX5043_REG_IRQMASK1, 0x01); // xtal ready
      001729                       4749 00144$:
      001729 90 40 06         [24] 4750 	mov	dptr,#0x4006
      00172C 74 01            [12] 4751 	mov	a,#0x01
      00172E F0               [24] 4752 	movx	@dptr,a
                                   4753 ;	..\COMMON\easyax5043.c:924: uint16_t wp = axradio_wor_period;
      00172F 90 4C CF         [24] 4754 	mov	dptr,#_axradio_wor_period
      001732 E4               [12] 4755 	clr	a
      001733 93               [24] 4756 	movc	a,@a+dptr
      001734 FE               [12] 4757 	mov	r6,a
      001735 74 01            [12] 4758 	mov	a,#0x01
      001737 93               [24] 4759 	movc	a,@a+dptr
                                   4760 ;	..\COMMON\easyax5043.c:925: radio_write8(AX5043_REG_WAKEUPFREQ1, ((wp >> 8) & 0xFF));
      001738 FF               [12] 4761 	mov	r7,a
      001739 FD               [12] 4762 	mov	r5,a
      00173A 90 40 6C         [24] 4763 	mov	dptr,#0x406c
      00173D ED               [12] 4764 	mov	a,r5
      00173E F0               [24] 4765 	movx	@dptr,a
                                   4766 ;	..\COMMON\easyax5043.c:926: radio_write8(AX5043_REG_WAKEUPFREQ0, ((wp >> 0) & 0xFF)); // actually wakeup period measured in LP OSC cycles
      00173F 8E 05            [24] 4767 	mov	ar5,r6
      001741 90 40 6D         [24] 4768 	mov	dptr,#0x406d
      001744 ED               [12] 4769 	mov	a,r5
      001745 F0               [24] 4770 	movx	@dptr,a
                                   4771 ;	..\COMMON\easyax5043.c:927: wp += radio_read16(AX5043_REG_WAKEUPTIMER1);
      001746 90 00 68         [24] 4772 	mov	dptr,#0x0068
      001749 12 44 D1         [24] 4773 	lcall	_radio_read16
      00174C AC 82            [24] 4774 	mov	r4,dpl
      00174E AD 83            [24] 4775 	mov	r5,dph
      001750 EC               [12] 4776 	mov	a,r4
      001751 2E               [12] 4777 	add	a,r6
      001752 FE               [12] 4778 	mov	r6,a
      001753 ED               [12] 4779 	mov	a,r5
      001754 3F               [12] 4780 	addc	a,r7
                                   4781 ;	..\COMMON\easyax5043.c:928: radio_write8(AX5043_REG_WAKEUP1, ((wp >> 8) & 0xFF));
      001755 FD               [12] 4782 	mov	r5,a
      001756 90 40 6A         [24] 4783 	mov	dptr,#0x406a
      001759 ED               [12] 4784 	mov	a,r5
      00175A F0               [24] 4785 	movx	@dptr,a
                                   4786 ;	..\COMMON\easyax5043.c:929: radio_write8(AX5043_REG_WAKEUP0, ((wp >> 0) & 0xFF));
      00175B 90 40 6B         [24] 4787 	mov	dptr,#0x406b
      00175E EE               [12] 4788 	mov	a,r6
      00175F F0               [24] 4789 	movx	@dptr,a
      001760 22               [24] 4790 	ret
                                   4791 ;------------------------------------------------------------
                                   4792 ;Allocation info for local variables in function 'ax5043_prepare_tx'
                                   4793 ;------------------------------------------------------------
                                   4794 ;	..\COMMON\easyax5043.c:933: __reentrantb void ax5043_prepare_tx(void) __reentrant
                                   4795 ;	-----------------------------------------
                                   4796 ;	 function ax5043_prepare_tx
                                   4797 ;	-----------------------------------------
      001761                       4798 _ax5043_prepare_tx:
                                   4799 ;	..\COMMON\easyax5043.c:935: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_XTAL_ON);
                                   4800 ;	..\COMMON\easyax5043.c:936: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_FIFO_ON);
      001761 90 40 02         [24] 4801 	mov	dptr,#0x4002
      001764 74 05            [12] 4802 	mov	a,#0x05
      001766 F0               [24] 4803 	movx	@dptr,a
      001767 74 07            [12] 4804 	mov	a,#0x07
      001769 F0               [24] 4805 	movx	@dptr,a
                                   4806 ;	..\COMMON\easyax5043.c:937: ax5043_init_registers_tx();
      00176A 12 0B 5F         [24] 4807 	lcall	_ax5043_init_registers_tx
                                   4808 ;	..\COMMON\easyax5043.c:938: radio_write8(AX5043_REG_FIFOTHRESH1, 0);
      00176D 90 40 2E         [24] 4809 	mov	dptr,#0x402e
      001770 E4               [12] 4810 	clr	a
      001771 F0               [24] 4811 	movx	@dptr,a
                                   4812 ;	..\COMMON\easyax5043.c:939: radio_write8(AX5043_REG_FIFOTHRESH0, 0x80);
      001772 90 40 2F         [24] 4813 	mov	dptr,#0x402f
      001775 74 80            [12] 4814 	mov	a,#0x80
      001777 F0               [24] 4815 	movx	@dptr,a
                                   4816 ;	..\COMMON\easyax5043.c:940: axradio_trxstate = trxstate_tx_xtalwait;
      001778 75 09 09         [24] 4817 	mov	_axradio_trxstate,#0x09
                                   4818 ;	..\COMMON\easyax5043.c:941: radio_write8(AX5043_REG_IRQMASK0, 0x00);
      00177B 90 40 07         [24] 4819 	mov	dptr,#0x4007
      00177E E4               [12] 4820 	clr	a
      00177F F0               [24] 4821 	movx	@dptr,a
                                   4822 ;	..\COMMON\easyax5043.c:942: radio_write8(AX5043_REG_IRQMASK1, 0x01); // enable xtal ready interrupt
      001780 90 40 06         [24] 4823 	mov	dptr,#0x4006
      001783 04               [12] 4824 	inc	a
      001784 F0               [24] 4825 	movx	@dptr,a
                                   4826 ;	..\COMMON\easyax5043.c:943: radio_read8(AX5043_REG_POWSTICKYSTAT); // clear pwr management sticky status --> brownout gate works
      001785 90 40 04         [24] 4827 	mov	dptr,#0x4004
      001788 E0               [24] 4828 	movx	a,@dptr
      001789 22               [24] 4829 	ret
                                   4830 ;------------------------------------------------------------
                                   4831 ;Allocation info for local variables in function 'ax5043_off'
                                   4832 ;------------------------------------------------------------
                                   4833 ;	..\COMMON\easyax5043.c:946: __reentrantb void ax5043_off(void) __reentrant
                                   4834 ;	-----------------------------------------
                                   4835 ;	 function ax5043_off
                                   4836 ;	-----------------------------------------
      00178A                       4837 _ax5043_off:
                                   4838 ;	..\COMMON\easyax5043.c:948: ax5043_off_xtal();
      00178A 12 17 93         [24] 4839 	lcall	_ax5043_off_xtal
                                   4840 ;	..\COMMON\easyax5043.c:949: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_POWERDOWN);
      00178D 90 40 02         [24] 4841 	mov	dptr,#0x4002
      001790 E4               [12] 4842 	clr	a
      001791 F0               [24] 4843 	movx	@dptr,a
      001792 22               [24] 4844 	ret
                                   4845 ;------------------------------------------------------------
                                   4846 ;Allocation info for local variables in function 'ax5043_off_xtal'
                                   4847 ;------------------------------------------------------------
                                   4848 ;	..\COMMON\easyax5043.c:952: __reentrantb void ax5043_off_xtal(void) __reentrant
                                   4849 ;	-----------------------------------------
                                   4850 ;	 function ax5043_off_xtal
                                   4851 ;	-----------------------------------------
      001793                       4852 _ax5043_off_xtal:
                                   4853 ;	..\COMMON\easyax5043.c:954: radio_write8(AX5043_REG_IRQMASK0, 0x00); // IRQ off
      001793 90 40 07         [24] 4854 	mov	dptr,#0x4007
      001796 E4               [12] 4855 	clr	a
      001797 F0               [24] 4856 	movx	@dptr,a
                                   4857 ;	..\COMMON\easyax5043.c:955: radio_write8(AX5043_REG_IRQMASK1, 0x00);
      001798 90 40 06         [24] 4858 	mov	dptr,#0x4006
      00179B F0               [24] 4859 	movx	@dptr,a
                                   4860 ;	..\COMMON\easyax5043.c:956: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_XTAL_ON);
      00179C 90 40 02         [24] 4861 	mov	dptr,#0x4002
      00179F 74 05            [12] 4862 	mov	a,#0x05
      0017A1 F0               [24] 4863 	movx	@dptr,a
                                   4864 ;	..\COMMON\easyax5043.c:957: radio_write8(AX5043_REG_LPOSCCONFIG, 0x00); // LPOSC off
      0017A2 90 43 10         [24] 4865 	mov	dptr,#0x4310
      0017A5 E4               [12] 4866 	clr	a
      0017A6 F0               [24] 4867 	movx	@dptr,a
                                   4868 ;	..\COMMON\easyax5043.c:958: axradio_trxstate = trxstate_off;
                                   4869 ;	1-genFromRTrack replaced	mov	_axradio_trxstate,#0x00
      0017A7 F5 09            [12] 4870 	mov	_axradio_trxstate,a
      0017A9 22               [24] 4871 	ret
                                   4872 ;------------------------------------------------------------
                                   4873 ;Allocation info for local variables in function 'axradio_wait_for_xtal'
                                   4874 ;------------------------------------------------------------
                                   4875 ;__00010016                Allocated to registers 
                                   4876 ;crit                      Allocated to registers r7 
                                   4877 ;crit                      Allocated to registers r7 
                                   4878 ;__00030019                Allocated to registers 
                                   4879 ;crit                      Allocated to registers 
                                   4880 ;__00020021                Allocated to registers 
                                   4881 ;crit                      Allocated to registers 
                                   4882 ;------------------------------------------------------------
                                   4883 ;	..\COMMON\easyax5043.c:961: void axradio_wait_for_xtal(void)
                                   4884 ;	-----------------------------------------
                                   4885 ;	 function axradio_wait_for_xtal
                                   4886 ;	-----------------------------------------
      0017AA                       4887 _axradio_wait_for_xtal:
                                   4888 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:351: criticalsection_t crit = IE & 0x80;
      0017AA 74 80            [12] 4889 	mov	a,#0x80
      0017AC 55 A8            [12] 4890 	anl	a,_IE
      0017AE FF               [12] 4891 	mov	r7,a
                                   4892 ;	..\COMMON\easyax5043.c:963: criticalsection_t crit = enter_critical();
      0017AF C2 AF            [12] 4893 	clr	_EA
                                   4894 ;	..\COMMON\easyax5043.c:964: axradio_trxstate = trxstate_wait_xtal;
      0017B1 75 09 03         [24] 4895 	mov	_axradio_trxstate,#0x03
                                   4896 ;	..\COMMON\easyax5043.c:965: radio_write8(AX5043_REG_IRQMASK1, (radio_read8(AX5043_REG_IRQMASK1) | 0x01)); // enable xtal ready interrupt
      0017B4 90 40 06         [24] 4897 	mov	dptr,#0x4006
      0017B7 E0               [24] 4898 	movx	a,@dptr
      0017B8 44 01            [12] 4899 	orl	a,#0x01
      0017BA FE               [12] 4900 	mov	r6,a
      0017BB F0               [24] 4901 	movx	@dptr,a
      0017BC                       4902 00111$:
                                   4903 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:373: EA = 0;
      0017BC C2 AF            [12] 4904 	clr	_EA
                                   4905 ;	..\COMMON\easyax5043.c:968: if (axradio_trxstate == trxstate_xtal_ready)
      0017BE 74 04            [12] 4906 	mov	a,#0x04
      0017C0 B5 09 02         [24] 4907 	cjne	a,_axradio_trxstate,00121$
      0017C3 80 16            [24] 4908 	sjmp	00106$
      0017C5                       4909 00121$:
                                   4910 ;	..\COMMON\easyax5043.c:970: wtimer_idle(WTFLAG_CANSTANDBY);
      0017C5 75 82 02         [24] 4911 	mov	dpl,#0x02
      0017C8 C0 07            [24] 4912 	push	ar7
      0017CA 12 41 4B         [24] 4913 	lcall	_wtimer_idle
      0017CD D0 07            [24] 4914 	pop	ar7
                                   4915 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:358: IE |= crit;
      0017CF EF               [12] 4916 	mov	a,r7
      0017D0 42 A8            [12] 4917 	orl	_IE,a
                                   4918 ;	..\COMMON\easyax5043.c:972: wtimer_runcallbacks();
      0017D2 C0 07            [24] 4919 	push	ar7
      0017D4 12 41 CF         [24] 4920 	lcall	_wtimer_runcallbacks
      0017D7 D0 07            [24] 4921 	pop	ar7
      0017D9 80 E1            [24] 4922 	sjmp	00111$
      0017DB                       4923 00106$:
                                   4924 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:358: IE |= crit;
      0017DB EF               [12] 4925 	mov	a,r7
      0017DC 42 A8            [12] 4926 	orl	_IE,a
                                   4927 ;	..\COMMON\easyax5043.c:974: exit_critical(crit);     //  Restore all Interrupts
      0017DE 22               [24] 4928 	ret
                                   4929 ;------------------------------------------------------------
                                   4930 ;Allocation info for local variables in function 'axradio_setaddrregs'
                                   4931 ;------------------------------------------------------------
                                   4932 ;pn                        Allocated to registers r6 r7 
                                   4933 ;inv                       Allocated to registers r5 
                                   4934 ;------------------------------------------------------------
                                   4935 ;	..\COMMON\easyax5043.c:977: static void axradio_setaddrregs(void)
                                   4936 ;	-----------------------------------------
                                   4937 ;	 function axradio_setaddrregs
                                   4938 ;	-----------------------------------------
      0017DF                       4939 _axradio_setaddrregs:
                                   4940 ;	..\COMMON\easyax5043.c:979: radio_write8(AX5043_REG_PKTADDR0, axradio_localaddr.addr[0]);
      0017DF 90 00 2D         [24] 4941 	mov	dptr,#_axradio_localaddr
      0017E2 E0               [24] 4942 	movx	a,@dptr
      0017E3 90 42 07         [24] 4943 	mov	dptr,#0x4207
      0017E6 F0               [24] 4944 	movx	@dptr,a
                                   4945 ;	..\COMMON\easyax5043.c:980: radio_write8(AX5043_REG_PKTADDR1, axradio_localaddr.addr[1]);
      0017E7 90 00 2E         [24] 4946 	mov	dptr,#(_axradio_localaddr + 0x0001)
      0017EA E0               [24] 4947 	movx	a,@dptr
      0017EB 90 42 06         [24] 4948 	mov	dptr,#0x4206
      0017EE F0               [24] 4949 	movx	@dptr,a
                                   4950 ;	..\COMMON\easyax5043.c:981: radio_write8(AX5043_REG_PKTADDR2, axradio_localaddr.addr[2]);
      0017EF 90 00 2F         [24] 4951 	mov	dptr,#(_axradio_localaddr + 0x0002)
      0017F2 E0               [24] 4952 	movx	a,@dptr
      0017F3 90 42 05         [24] 4953 	mov	dptr,#0x4205
      0017F6 F0               [24] 4954 	movx	@dptr,a
                                   4955 ;	..\COMMON\easyax5043.c:982: radio_write8(AX5043_REG_PKTADDR3, axradio_localaddr.addr[3]);
      0017F7 90 00 30         [24] 4956 	mov	dptr,#(_axradio_localaddr + 0x0003)
      0017FA E0               [24] 4957 	movx	a,@dptr
      0017FB 90 42 04         [24] 4958 	mov	dptr,#0x4204
      0017FE F0               [24] 4959 	movx	@dptr,a
                                   4960 ;	..\COMMON\easyax5043.c:984: radio_write8(AX5043_REG_PKTADDRMASK0, axradio_localaddr.mask[0]);
      0017FF 90 00 32         [24] 4961 	mov	dptr,#(_axradio_localaddr + 0x0005)
      001802 E0               [24] 4962 	movx	a,@dptr
      001803 90 42 0B         [24] 4963 	mov	dptr,#0x420b
      001806 F0               [24] 4964 	movx	@dptr,a
                                   4965 ;	..\COMMON\easyax5043.c:985: radio_write8(AX5043_REG_PKTADDRMASK1, axradio_localaddr.mask[1]);
      001807 90 00 33         [24] 4966 	mov	dptr,#(_axradio_localaddr + 0x0006)
      00180A E0               [24] 4967 	movx	a,@dptr
      00180B 90 42 0A         [24] 4968 	mov	dptr,#0x420a
      00180E F0               [24] 4969 	movx	@dptr,a
                                   4970 ;	..\COMMON\easyax5043.c:986: radio_write8(AX5043_REG_PKTADDRMASK2, axradio_localaddr.mask[2]);
      00180F 90 00 34         [24] 4971 	mov	dptr,#(_axradio_localaddr + 0x0007)
      001812 E0               [24] 4972 	movx	a,@dptr
      001813 90 42 09         [24] 4973 	mov	dptr,#0x4209
      001816 F0               [24] 4974 	movx	@dptr,a
                                   4975 ;	..\COMMON\easyax5043.c:987: radio_write8(AX5043_REG_PKTADDRMASK3, axradio_localaddr.mask[3]);
      001817 90 00 35         [24] 4976 	mov	dptr,#(_axradio_localaddr + 0x0008)
      00181A E0               [24] 4977 	movx	a,@dptr
      00181B FF               [12] 4978 	mov	r7,a
      00181C 90 42 08         [24] 4979 	mov	dptr,#0x4208
      00181F F0               [24] 4980 	movx	@dptr,a
                                   4981 ;	..\COMMON\easyax5043.c:989: if (axradio_phy_pn9 && axradio_framing_addrlen) {
      001820 90 4C 70         [24] 4982 	mov	dptr,#_axradio_phy_pn9
      001823 E4               [12] 4983 	clr	a
      001824 93               [24] 4984 	movc	a,@a+dptr
      001825 70 01            [24] 4985 	jnz	00153$
      001827 22               [24] 4986 	ret
      001828                       4987 00153$:
      001828 90 4C B6         [24] 4988 	mov	dptr,#_axradio_framing_addrlen
      00182B E4               [12] 4989 	clr	a
      00182C 93               [24] 4990 	movc	a,@a+dptr
      00182D 70 01            [24] 4991 	jnz	00154$
      00182F 22               [24] 4992 	ret
      001830                       4993 00154$:
                                   4994 ;	..\COMMON\easyax5043.c:990: uint16_t __autodata pn = 0x1ff;
      001830 7E FF            [12] 4995 	mov	r6,#0xff
      001832 7F 01            [12] 4996 	mov	r7,#0x01
                                   4997 ;	..\COMMON\easyax5043.c:991: uint8_t __autodata inv = -(radio_read8(AX5043_REG_ENCODING) & 0x01);
      001834 90 40 11         [24] 4998 	mov	dptr,#0x4011
      001837 E0               [24] 4999 	movx	a,@dptr
      001838 FD               [12] 5000 	mov	r5,a
      001839 53 05 01         [24] 5001 	anl	ar5,#0x01
      00183C C3               [12] 5002 	clr	c
      00183D E4               [12] 5003 	clr	a
      00183E 9D               [12] 5004 	subb	a,r5
      00183F FD               [12] 5005 	mov	r5,a
                                   5006 ;	..\COMMON\easyax5043.c:992: if (axradio_framing_destaddrpos != 0xff)
      001840 90 4C B7         [24] 5007 	mov	dptr,#_axradio_framing_destaddrpos
      001843 E4               [12] 5008 	clr	a
      001844 93               [24] 5009 	movc	a,@a+dptr
      001845 FC               [12] 5010 	mov	r4,a
      001846 BC FF 02         [24] 5011 	cjne	r4,#0xff,00155$
      001849 80 26            [24] 5012 	sjmp	00127$
      00184B                       5013 00155$:
                                   5014 ;	..\COMMON\easyax5043.c:993: pn = pn9_advance_bits(pn, axradio_framing_destaddrpos << 3);
      00184B E4               [12] 5015 	clr	a
      00184C C4               [12] 5016 	swap	a
      00184D 03               [12] 5017 	rr	a
      00184E 54 F8            [12] 5018 	anl	a,#0xf8
      001850 CC               [12] 5019 	xch	a,r4
      001851 C4               [12] 5020 	swap	a
      001852 03               [12] 5021 	rr	a
      001853 CC               [12] 5022 	xch	a,r4
      001854 6C               [12] 5023 	xrl	a,r4
      001855 CC               [12] 5024 	xch	a,r4
      001856 54 F8            [12] 5025 	anl	a,#0xf8
      001858 CC               [12] 5026 	xch	a,r4
      001859 6C               [12] 5027 	xrl	a,r4
      00185A FB               [12] 5028 	mov	r3,a
      00185B C0 05            [24] 5029 	push	ar5
      00185D C0 04            [24] 5030 	push	ar4
      00185F C0 03            [24] 5031 	push	ar3
      001861 90 01 FF         [24] 5032 	mov	dptr,#0x01ff
      001864 12 4B 88         [24] 5033 	lcall	_pn9_advance_bits
      001867 AE 82            [24] 5034 	mov	r6,dpl
      001869 AF 83            [24] 5035 	mov	r7,dph
      00186B 15 81            [12] 5036 	dec	sp
      00186D 15 81            [12] 5037 	dec	sp
      00186F D0 05            [24] 5038 	pop	ar5
                                   5039 ;	..\COMMON\easyax5043.c:994: radio_write8(AX5043_REG_PKTADDR0, (radio_read8(AX5043_REG_PKTADDR0) ^ (pn ^ inv)));
      001871                       5040 00127$:
      001871 90 42 07         [24] 5041 	mov	dptr,#0x4207
      001874 E0               [24] 5042 	movx	a,@dptr
      001875 FC               [12] 5043 	mov	r4,a
      001876 7B 00            [12] 5044 	mov	r3,#0x00
      001878 ED               [12] 5045 	mov	a,r5
      001879 6E               [12] 5046 	xrl	a,r6
      00187A F9               [12] 5047 	mov	r1,a
      00187B EB               [12] 5048 	mov	a,r3
      00187C 6F               [12] 5049 	xrl	a,r7
      00187D FA               [12] 5050 	mov	r2,a
      00187E 8C 00            [24] 5051 	mov	ar0,r4
      001880 7C 00            [12] 5052 	mov	r4,#0x00
      001882 E8               [12] 5053 	mov	a,r0
      001883 62 01            [12] 5054 	xrl	ar1,a
      001885 EC               [12] 5055 	mov	a,r4
      001886 62 02            [12] 5056 	xrl	ar2,a
      001888 90 42 07         [24] 5057 	mov	dptr,#0x4207
      00188B E9               [12] 5058 	mov	a,r1
      00188C F0               [24] 5059 	movx	@dptr,a
                                   5060 ;	..\COMMON\easyax5043.c:995: pn = pn9_advance_byte(pn);
      00188D 8E 82            [24] 5061 	mov	dpl,r6
      00188F 8F 83            [24] 5062 	mov	dph,r7
      001891 C0 05            [24] 5063 	push	ar5
      001893 C0 03            [24] 5064 	push	ar3
      001895 12 4B AE         [24] 5065 	lcall	_pn9_advance_byte
      001898 AE 82            [24] 5066 	mov	r6,dpl
      00189A AF 83            [24] 5067 	mov	r7,dph
      00189C D0 03            [24] 5068 	pop	ar3
      00189E D0 05            [24] 5069 	pop	ar5
                                   5070 ;	..\COMMON\easyax5043.c:996: radio_write8(AX5043_REG_PKTADDR1, (radio_read8(AX5043_REG_PKTADDR1) ^ (pn ^ inv)));
      0018A0 90 42 06         [24] 5071 	mov	dptr,#0x4206
      0018A3 E0               [24] 5072 	movx	a,@dptr
      0018A4 FC               [12] 5073 	mov	r4,a
      0018A5 ED               [12] 5074 	mov	a,r5
      0018A6 6E               [12] 5075 	xrl	a,r6
      0018A7 F9               [12] 5076 	mov	r1,a
      0018A8 EB               [12] 5077 	mov	a,r3
      0018A9 6F               [12] 5078 	xrl	a,r7
      0018AA FA               [12] 5079 	mov	r2,a
      0018AB 8C 00            [24] 5080 	mov	ar0,r4
      0018AD 7C 00            [12] 5081 	mov	r4,#0x00
      0018AF E8               [12] 5082 	mov	a,r0
      0018B0 62 01            [12] 5083 	xrl	ar1,a
      0018B2 EC               [12] 5084 	mov	a,r4
      0018B3 62 02            [12] 5085 	xrl	ar2,a
      0018B5 90 42 06         [24] 5086 	mov	dptr,#0x4206
      0018B8 E9               [12] 5087 	mov	a,r1
      0018B9 F0               [24] 5088 	movx	@dptr,a
                                   5089 ;	..\COMMON\easyax5043.c:997: pn = pn9_advance_byte(pn);
      0018BA 8E 82            [24] 5090 	mov	dpl,r6
      0018BC 8F 83            [24] 5091 	mov	dph,r7
      0018BE C0 05            [24] 5092 	push	ar5
      0018C0 C0 03            [24] 5093 	push	ar3
      0018C2 12 4B AE         [24] 5094 	lcall	_pn9_advance_byte
      0018C5 AE 82            [24] 5095 	mov	r6,dpl
      0018C7 AF 83            [24] 5096 	mov	r7,dph
      0018C9 D0 03            [24] 5097 	pop	ar3
      0018CB D0 05            [24] 5098 	pop	ar5
                                   5099 ;	..\COMMON\easyax5043.c:998: radio_write8(AX5043_REG_PKTADDR2, (radio_read8(AX5043_REG_PKTADDR2) ^ (pn ^ inv)));
      0018CD 90 42 05         [24] 5100 	mov	dptr,#0x4205
      0018D0 E0               [24] 5101 	movx	a,@dptr
      0018D1 FC               [12] 5102 	mov	r4,a
      0018D2 ED               [12] 5103 	mov	a,r5
      0018D3 6E               [12] 5104 	xrl	a,r6
      0018D4 F9               [12] 5105 	mov	r1,a
      0018D5 EB               [12] 5106 	mov	a,r3
      0018D6 6F               [12] 5107 	xrl	a,r7
      0018D7 FA               [12] 5108 	mov	r2,a
      0018D8 8C 00            [24] 5109 	mov	ar0,r4
      0018DA 7C 00            [12] 5110 	mov	r4,#0x00
      0018DC E8               [12] 5111 	mov	a,r0
      0018DD 62 01            [12] 5112 	xrl	ar1,a
      0018DF EC               [12] 5113 	mov	a,r4
      0018E0 62 02            [12] 5114 	xrl	ar2,a
      0018E2 90 42 05         [24] 5115 	mov	dptr,#0x4205
      0018E5 E9               [12] 5116 	mov	a,r1
      0018E6 F0               [24] 5117 	movx	@dptr,a
                                   5118 ;	..\COMMON\easyax5043.c:999: pn = pn9_advance_byte(pn);
      0018E7 8E 82            [24] 5119 	mov	dpl,r6
      0018E9 8F 83            [24] 5120 	mov	dph,r7
      0018EB C0 05            [24] 5121 	push	ar5
      0018ED C0 03            [24] 5122 	push	ar3
      0018EF 12 4B AE         [24] 5123 	lcall	_pn9_advance_byte
      0018F2 AE 82            [24] 5124 	mov	r6,dpl
      0018F4 AF 83            [24] 5125 	mov	r7,dph
      0018F6 D0 03            [24] 5126 	pop	ar3
      0018F8 D0 05            [24] 5127 	pop	ar5
                                   5128 ;	..\COMMON\easyax5043.c:1000: radio_write8(AX5043_REG_PKTADDR3, (radio_read8(AX5043_REG_PKTADDR3) ^ (pn ^ inv)));
      0018FA 90 42 04         [24] 5129 	mov	dptr,#0x4204
      0018FD E0               [24] 5130 	movx	a,@dptr
      0018FE FC               [12] 5131 	mov	r4,a
      0018FF ED               [12] 5132 	mov	a,r5
      001900 62 06            [12] 5133 	xrl	ar6,a
      001902 EB               [12] 5134 	mov	a,r3
      001903 62 07            [12] 5135 	xrl	ar7,a
      001905 7D 00            [12] 5136 	mov	r5,#0x00
      001907 EC               [12] 5137 	mov	a,r4
      001908 62 06            [12] 5138 	xrl	ar6,a
      00190A ED               [12] 5139 	mov	a,r5
      00190B 62 07            [12] 5140 	xrl	ar7,a
      00190D 90 42 04         [24] 5141 	mov	dptr,#0x4204
      001910 EE               [12] 5142 	mov	a,r6
      001911 F0               [24] 5143 	movx	@dptr,a
      001912 22               [24] 5144 	ret
                                   5145 ;------------------------------------------------------------
                                   5146 ;Allocation info for local variables in function 'ax5043_init_registers'
                                   5147 ;------------------------------------------------------------
                                   5148 ;	..\COMMON\easyax5043.c:1004: static void ax5043_init_registers(void)
                                   5149 ;	-----------------------------------------
                                   5150 ;	 function ax5043_init_registers
                                   5151 ;	-----------------------------------------
      001913                       5152 _ax5043_init_registers:
                                   5153 ;	..\COMMON\easyax5043.c:1006: ax5043_set_registers();
      001913 12 03 98         [24] 5154 	lcall	_ax5043_set_registers
                                   5155 ;	..\COMMON\easyax5043.c:1011: radio_write8(AX5043_REG_PKTLENOFFSET, (radio_read8(AX5043_REG_PKTLENOFFSET) + axradio_framing_swcrclen)); // add len offs for software CRC16 (used for both, fixed and variable length packets
      001916 90 42 02         [24] 5156 	mov	dptr,#0x4202
      001919 E0               [24] 5157 	movx	a,@dptr
      00191A FF               [12] 5158 	mov	r7,a
      00191B 90 4C BC         [24] 5159 	mov	dptr,#_axradio_framing_swcrclen
      00191E E4               [12] 5160 	clr	a
      00191F 93               [24] 5161 	movc	a,@a+dptr
      001920 FE               [12] 5162 	mov	r6,a
      001921 2F               [12] 5163 	add	a,r7
      001922 90 42 02         [24] 5164 	mov	dptr,#0x4202
      001925 F0               [24] 5165 	movx	@dptr,a
                                   5166 ;	..\COMMON\easyax5043.c:1012: radio_write8(AX5043_REG_PINFUNCIRQ, 0x03); // use as IRQ pin
      001926 90 40 24         [24] 5167 	mov	dptr,#0x4024
      001929 74 03            [12] 5168 	mov	a,#0x03
      00192B F0               [24] 5169 	movx	@dptr,a
                                   5170 ;	..\COMMON\easyax5043.c:1013: radio_write8(AX5043_REG_PKTSTOREFLAGS, (axradio_phy_innerfreqloop ? 0x13 : 0x15)); // store RF offset, RSSI and delimiter timing
      00192C 90 4C 6F         [24] 5171 	mov	dptr,#_axradio_phy_innerfreqloop
      00192F E4               [12] 5172 	clr	a
      001930 93               [24] 5173 	movc	a,@a+dptr
      001931 FF               [12] 5174 	mov	r7,a
      001932 60 04            [24] 5175 	jz	00112$
      001934 7F 13            [12] 5176 	mov	r7,#0x13
      001936 80 02            [24] 5177 	sjmp	00113$
      001938                       5178 00112$:
      001938 7F 15            [12] 5179 	mov	r7,#0x15
      00193A                       5180 00113$:
      00193A 90 42 32         [24] 5181 	mov	dptr,#0x4232
      00193D EF               [12] 5182 	mov	a,r7
      00193E F0               [24] 5183 	movx	@dptr,a
                                   5184 ;	..\COMMON\easyax5043.c:1014: axradio_setaddrregs();
      00193F 02 17 DF         [24] 5185 	ljmp	_axradio_setaddrregs
                                   5186 ;------------------------------------------------------------
                                   5187 ;Allocation info for local variables in function 'axradio_sync_addtime'
                                   5188 ;------------------------------------------------------------
                                   5189 ;dt                        Allocated to registers r4 r5 r6 r7 
                                   5190 ;------------------------------------------------------------
                                   5191 ;	..\COMMON\easyax5043.c:1021: static __reentrantb void axradio_sync_addtime(uint32_t dt) __reentrant
                                   5192 ;	-----------------------------------------
                                   5193 ;	 function axradio_sync_addtime
                                   5194 ;	-----------------------------------------
      001942                       5195 _axradio_sync_addtime:
      001942 AC 82            [24] 5196 	mov	r4,dpl
      001944 AD 83            [24] 5197 	mov	r5,dph
      001946 AE F0            [24] 5198 	mov	r6,b
      001948 FF               [12] 5199 	mov	r7,a
                                   5200 ;	..\COMMON\easyax5043.c:1023: axradio_sync_time += dt;
      001949 90 00 1F         [24] 5201 	mov	dptr,#_axradio_sync_time
      00194C E0               [24] 5202 	movx	a,@dptr
      00194D F8               [12] 5203 	mov	r0,a
      00194E A3               [24] 5204 	inc	dptr
      00194F E0               [24] 5205 	movx	a,@dptr
      001950 F9               [12] 5206 	mov	r1,a
      001951 A3               [24] 5207 	inc	dptr
      001952 E0               [24] 5208 	movx	a,@dptr
      001953 FA               [12] 5209 	mov	r2,a
      001954 A3               [24] 5210 	inc	dptr
      001955 E0               [24] 5211 	movx	a,@dptr
      001956 FB               [12] 5212 	mov	r3,a
      001957 90 00 1F         [24] 5213 	mov	dptr,#_axradio_sync_time
      00195A EC               [12] 5214 	mov	a,r4
      00195B 28               [12] 5215 	add	a,r0
      00195C F0               [24] 5216 	movx	@dptr,a
      00195D ED               [12] 5217 	mov	a,r5
      00195E 39               [12] 5218 	addc	a,r1
      00195F A3               [24] 5219 	inc	dptr
      001960 F0               [24] 5220 	movx	@dptr,a
      001961 EE               [12] 5221 	mov	a,r6
      001962 3A               [12] 5222 	addc	a,r2
      001963 A3               [24] 5223 	inc	dptr
      001964 F0               [24] 5224 	movx	@dptr,a
      001965 EF               [12] 5225 	mov	a,r7
      001966 3B               [12] 5226 	addc	a,r3
      001967 A3               [24] 5227 	inc	dptr
      001968 F0               [24] 5228 	movx	@dptr,a
      001969 22               [24] 5229 	ret
                                   5230 ;------------------------------------------------------------
                                   5231 ;Allocation info for local variables in function 'axradio_sync_subtime'
                                   5232 ;------------------------------------------------------------
                                   5233 ;dt                        Allocated to registers r4 r5 r6 r7 
                                   5234 ;------------------------------------------------------------
                                   5235 ;	..\COMMON\easyax5043.c:1026: static __reentrantb void axradio_sync_subtime(uint32_t dt) __reentrant
                                   5236 ;	-----------------------------------------
                                   5237 ;	 function axradio_sync_subtime
                                   5238 ;	-----------------------------------------
      00196A                       5239 _axradio_sync_subtime:
      00196A AC 82            [24] 5240 	mov	r4,dpl
      00196C AD 83            [24] 5241 	mov	r5,dph
      00196E AE F0            [24] 5242 	mov	r6,b
      001970 FF               [12] 5243 	mov	r7,a
                                   5244 ;	..\COMMON\easyax5043.c:1028: axradio_sync_time -= dt;
      001971 90 00 1F         [24] 5245 	mov	dptr,#_axradio_sync_time
      001974 E0               [24] 5246 	movx	a,@dptr
      001975 F8               [12] 5247 	mov	r0,a
      001976 A3               [24] 5248 	inc	dptr
      001977 E0               [24] 5249 	movx	a,@dptr
      001978 F9               [12] 5250 	mov	r1,a
      001979 A3               [24] 5251 	inc	dptr
      00197A E0               [24] 5252 	movx	a,@dptr
      00197B FA               [12] 5253 	mov	r2,a
      00197C A3               [24] 5254 	inc	dptr
      00197D E0               [24] 5255 	movx	a,@dptr
      00197E FB               [12] 5256 	mov	r3,a
      00197F 90 00 1F         [24] 5257 	mov	dptr,#_axradio_sync_time
      001982 E8               [12] 5258 	mov	a,r0
      001983 C3               [12] 5259 	clr	c
      001984 9C               [12] 5260 	subb	a,r4
      001985 F0               [24] 5261 	movx	@dptr,a
      001986 E9               [12] 5262 	mov	a,r1
      001987 9D               [12] 5263 	subb	a,r5
      001988 A3               [24] 5264 	inc	dptr
      001989 F0               [24] 5265 	movx	@dptr,a
      00198A EA               [12] 5266 	mov	a,r2
      00198B 9E               [12] 5267 	subb	a,r6
      00198C A3               [24] 5268 	inc	dptr
      00198D F0               [24] 5269 	movx	@dptr,a
      00198E EB               [12] 5270 	mov	a,r3
      00198F 9F               [12] 5271 	subb	a,r7
      001990 A3               [24] 5272 	inc	dptr
      001991 F0               [24] 5273 	movx	@dptr,a
      001992 22               [24] 5274 	ret
                                   5275 ;------------------------------------------------------------
                                   5276 ;Allocation info for local variables in function 'axradio_sync_settimeradv'
                                   5277 ;------------------------------------------------------------
                                   5278 ;dt                        Allocated to registers r4 r5 r6 r7 
                                   5279 ;------------------------------------------------------------
                                   5280 ;	..\COMMON\easyax5043.c:1031: static __reentrantb void axradio_sync_settimeradv(uint32_t dt) __reentrant
                                   5281 ;	-----------------------------------------
                                   5282 ;	 function axradio_sync_settimeradv
                                   5283 ;	-----------------------------------------
      001993                       5284 _axradio_sync_settimeradv:
      001993 AC 82            [24] 5285 	mov	r4,dpl
      001995 AD 83            [24] 5286 	mov	r5,dph
      001997 AE F0            [24] 5287 	mov	r6,b
      001999 FF               [12] 5288 	mov	r7,a
                                   5289 ;	..\COMMON\easyax5043.c:1033: axradio_timer.time = axradio_sync_time;
      00199A 90 00 1F         [24] 5290 	mov	dptr,#_axradio_sync_time
      00199D E0               [24] 5291 	movx	a,@dptr
      00199E F8               [12] 5292 	mov	r0,a
      00199F A3               [24] 5293 	inc	dptr
      0019A0 E0               [24] 5294 	movx	a,@dptr
      0019A1 F9               [12] 5295 	mov	r1,a
      0019A2 A3               [24] 5296 	inc	dptr
      0019A3 E0               [24] 5297 	movx	a,@dptr
      0019A4 FA               [12] 5298 	mov	r2,a
      0019A5 A3               [24] 5299 	inc	dptr
      0019A6 E0               [24] 5300 	movx	a,@dptr
      0019A7 FB               [12] 5301 	mov	r3,a
      0019A8 90 02 A1         [24] 5302 	mov	dptr,#(_axradio_timer + 0x0004)
      0019AB E8               [12] 5303 	mov	a,r0
      0019AC F0               [24] 5304 	movx	@dptr,a
      0019AD E9               [12] 5305 	mov	a,r1
      0019AE A3               [24] 5306 	inc	dptr
      0019AF F0               [24] 5307 	movx	@dptr,a
      0019B0 EA               [12] 5308 	mov	a,r2
      0019B1 A3               [24] 5309 	inc	dptr
      0019B2 F0               [24] 5310 	movx	@dptr,a
      0019B3 EB               [12] 5311 	mov	a,r3
      0019B4 A3               [24] 5312 	inc	dptr
      0019B5 F0               [24] 5313 	movx	@dptr,a
                                   5314 ;	..\COMMON\easyax5043.c:1034: axradio_timer.time -= dt;
      0019B6 E8               [12] 5315 	mov	a,r0
      0019B7 C3               [12] 5316 	clr	c
      0019B8 9C               [12] 5317 	subb	a,r4
      0019B9 FC               [12] 5318 	mov	r4,a
      0019BA E9               [12] 5319 	mov	a,r1
      0019BB 9D               [12] 5320 	subb	a,r5
      0019BC FD               [12] 5321 	mov	r5,a
      0019BD EA               [12] 5322 	mov	a,r2
      0019BE 9E               [12] 5323 	subb	a,r6
      0019BF FE               [12] 5324 	mov	r6,a
      0019C0 EB               [12] 5325 	mov	a,r3
      0019C1 9F               [12] 5326 	subb	a,r7
      0019C2 FF               [12] 5327 	mov	r7,a
      0019C3 90 02 A1         [24] 5328 	mov	dptr,#(_axradio_timer + 0x0004)
      0019C6 EC               [12] 5329 	mov	a,r4
      0019C7 F0               [24] 5330 	movx	@dptr,a
      0019C8 ED               [12] 5331 	mov	a,r5
      0019C9 A3               [24] 5332 	inc	dptr
      0019CA F0               [24] 5333 	movx	@dptr,a
      0019CB EE               [12] 5334 	mov	a,r6
      0019CC A3               [24] 5335 	inc	dptr
      0019CD F0               [24] 5336 	movx	@dptr,a
      0019CE EF               [12] 5337 	mov	a,r7
      0019CF A3               [24] 5338 	inc	dptr
      0019D0 F0               [24] 5339 	movx	@dptr,a
      0019D1 22               [24] 5340 	ret
                                   5341 ;------------------------------------------------------------
                                   5342 ;Allocation info for local variables in function 'axradio_sync_adjustperiodcorr'
                                   5343 ;------------------------------------------------------------
                                   5344 ;dt                        Allocated to registers r4 r5 r6 r7 
                                   5345 ;------------------------------------------------------------
                                   5346 ;	..\COMMON\easyax5043.c:1037: static void axradio_sync_adjustperiodcorr(void)
                                   5347 ;	-----------------------------------------
                                   5348 ;	 function axradio_sync_adjustperiodcorr
                                   5349 ;	-----------------------------------------
      0019D2                       5350 _axradio_sync_adjustperiodcorr:
                                   5351 ;	..\COMMON\easyax5043.c:1039: int32_t __autodata dt = axradio_conv_time_totimer0(axradio_cb_receive.st.time.t) - axradio_sync_time;
      0019D2 90 02 4A         [24] 5352 	mov	dptr,#(_axradio_cb_receive + 0x0006)
      0019D5 E0               [24] 5353 	movx	a,@dptr
      0019D6 FC               [12] 5354 	mov	r4,a
      0019D7 A3               [24] 5355 	inc	dptr
      0019D8 E0               [24] 5356 	movx	a,@dptr
      0019D9 FD               [12] 5357 	mov	r5,a
      0019DA A3               [24] 5358 	inc	dptr
      0019DB E0               [24] 5359 	movx	a,@dptr
      0019DC FE               [12] 5360 	mov	r6,a
      0019DD A3               [24] 5361 	inc	dptr
      0019DE E0               [24] 5362 	movx	a,@dptr
      0019DF 8C 82            [24] 5363 	mov	dpl,r4
      0019E1 8D 83            [24] 5364 	mov	dph,r5
      0019E3 8E F0            [24] 5365 	mov	b,r6
      0019E5 12 0A BE         [24] 5366 	lcall	_axradio_conv_time_totimer0
      0019E8 AC 82            [24] 5367 	mov	r4,dpl
      0019EA AD 83            [24] 5368 	mov	r5,dph
      0019EC AE F0            [24] 5369 	mov	r6,b
      0019EE FF               [12] 5370 	mov	r7,a
      0019EF 90 00 1F         [24] 5371 	mov	dptr,#_axradio_sync_time
      0019F2 E0               [24] 5372 	movx	a,@dptr
      0019F3 F8               [12] 5373 	mov	r0,a
      0019F4 A3               [24] 5374 	inc	dptr
      0019F5 E0               [24] 5375 	movx	a,@dptr
      0019F6 F9               [12] 5376 	mov	r1,a
      0019F7 A3               [24] 5377 	inc	dptr
      0019F8 E0               [24] 5378 	movx	a,@dptr
      0019F9 FA               [12] 5379 	mov	r2,a
      0019FA A3               [24] 5380 	inc	dptr
      0019FB E0               [24] 5381 	movx	a,@dptr
      0019FC FB               [12] 5382 	mov	r3,a
      0019FD EC               [12] 5383 	mov	a,r4
      0019FE C3               [12] 5384 	clr	c
      0019FF 98               [12] 5385 	subb	a,r0
      001A00 FC               [12] 5386 	mov	r4,a
      001A01 ED               [12] 5387 	mov	a,r5
      001A02 99               [12] 5388 	subb	a,r1
      001A03 FD               [12] 5389 	mov	r5,a
      001A04 EE               [12] 5390 	mov	a,r6
      001A05 9A               [12] 5391 	subb	a,r2
      001A06 FE               [12] 5392 	mov	r6,a
      001A07 EF               [12] 5393 	mov	a,r7
      001A08 9B               [12] 5394 	subb	a,r3
      001A09 FF               [12] 5395 	mov	r7,a
                                   5396 ;	..\COMMON\easyax5043.c:1040: axradio_cb_receive.st.rx.phy.timeoffset = dt;
      001A0A 8C 02            [24] 5397 	mov	ar2,r4
      001A0C 8D 03            [24] 5398 	mov	ar3,r5
      001A0E 90 02 54         [24] 5399 	mov	dptr,#(_axradio_cb_receive + 0x0010)
      001A11 EA               [12] 5400 	mov	a,r2
      001A12 F0               [24] 5401 	movx	@dptr,a
      001A13 EB               [12] 5402 	mov	a,r3
      001A14 A3               [24] 5403 	inc	dptr
      001A15 F0               [24] 5404 	movx	@dptr,a
                                   5405 ;	..\COMMON\easyax5043.c:1041: if (!checksignedlimit16(axradio_sync_periodcorr, axradio_sync_slave_maxperiod)) {
      001A16 90 00 23         [24] 5406 	mov	dptr,#_axradio_sync_periodcorr
      001A19 E0               [24] 5407 	movx	a,@dptr
      001A1A FA               [12] 5408 	mov	r2,a
      001A1B A3               [24] 5409 	inc	dptr
      001A1C E0               [24] 5410 	movx	a,@dptr
      001A1D FB               [12] 5411 	mov	r3,a
      001A1E 90 4C E5         [24] 5412 	mov	dptr,#_axradio_sync_slave_maxperiod
      001A21 E4               [12] 5413 	clr	a
      001A22 93               [24] 5414 	movc	a,@a+dptr
      001A23 C0 E0            [24] 5415 	push	acc
      001A25 74 01            [12] 5416 	mov	a,#0x01
      001A27 93               [24] 5417 	movc	a,@a+dptr
      001A28 C0 E0            [24] 5418 	push	acc
      001A2A 8A 82            [24] 5419 	mov	dpl,r2
      001A2C 8B 83            [24] 5420 	mov	dph,r3
      001A2E 12 46 B3         [24] 5421 	lcall	_checksignedlimit16
      001A31 AB 82            [24] 5422 	mov	r3,dpl
      001A33 15 81            [12] 5423 	dec	sp
      001A35 15 81            [12] 5424 	dec	sp
      001A37 EB               [12] 5425 	mov	a,r3
      001A38 70 4B            [24] 5426 	jnz	00102$
                                   5427 ;	..\COMMON\easyax5043.c:1042: axradio_sync_addtime(dt);
      001A3A 8C 82            [24] 5428 	mov	dpl,r4
      001A3C 8D 83            [24] 5429 	mov	dph,r5
      001A3E 8E F0            [24] 5430 	mov	b,r6
      001A40 EF               [12] 5431 	mov	a,r7
      001A41 C0 07            [24] 5432 	push	ar7
      001A43 C0 06            [24] 5433 	push	ar6
      001A45 C0 05            [24] 5434 	push	ar5
      001A47 C0 04            [24] 5435 	push	ar4
      001A49 12 19 42         [24] 5436 	lcall	_axradio_sync_addtime
      001A4C D0 04            [24] 5437 	pop	ar4
      001A4E D0 05            [24] 5438 	pop	ar5
      001A50 D0 06            [24] 5439 	pop	ar6
      001A52 D0 07            [24] 5440 	pop	ar7
                                   5441 ;	..\COMMON\easyax5043.c:1043: dt <<= SYNC_K1;
      001A54 EF               [12] 5442 	mov	a,r7
      001A55 C4               [12] 5443 	swap	a
      001A56 23               [12] 5444 	rl	a
      001A57 54 E0            [12] 5445 	anl	a,#0xe0
      001A59 CE               [12] 5446 	xch	a,r6
      001A5A C4               [12] 5447 	swap	a
      001A5B 23               [12] 5448 	rl	a
      001A5C CE               [12] 5449 	xch	a,r6
      001A5D 6E               [12] 5450 	xrl	a,r6
      001A5E CE               [12] 5451 	xch	a,r6
      001A5F 54 E0            [12] 5452 	anl	a,#0xe0
      001A61 CE               [12] 5453 	xch	a,r6
      001A62 6E               [12] 5454 	xrl	a,r6
      001A63 FF               [12] 5455 	mov	r7,a
      001A64 ED               [12] 5456 	mov	a,r5
      001A65 C4               [12] 5457 	swap	a
      001A66 23               [12] 5458 	rl	a
      001A67 54 1F            [12] 5459 	anl	a,#0x1f
      001A69 4E               [12] 5460 	orl	a,r6
      001A6A FE               [12] 5461 	mov	r6,a
      001A6B ED               [12] 5462 	mov	a,r5
      001A6C C4               [12] 5463 	swap	a
      001A6D 23               [12] 5464 	rl	a
      001A6E 54 E0            [12] 5465 	anl	a,#0xe0
      001A70 CC               [12] 5466 	xch	a,r4
      001A71 C4               [12] 5467 	swap	a
      001A72 23               [12] 5468 	rl	a
      001A73 CC               [12] 5469 	xch	a,r4
      001A74 6C               [12] 5470 	xrl	a,r4
      001A75 CC               [12] 5471 	xch	a,r4
      001A76 54 E0            [12] 5472 	anl	a,#0xe0
      001A78 CC               [12] 5473 	xch	a,r4
      001A79 6C               [12] 5474 	xrl	a,r4
      001A7A FD               [12] 5475 	mov	r5,a
                                   5476 ;	..\COMMON\easyax5043.c:1044: axradio_sync_periodcorr = dt;
      001A7B 90 00 23         [24] 5477 	mov	dptr,#_axradio_sync_periodcorr
      001A7E EC               [12] 5478 	mov	a,r4
      001A7F F0               [24] 5479 	movx	@dptr,a
      001A80 ED               [12] 5480 	mov	a,r5
      001A81 A3               [24] 5481 	inc	dptr
      001A82 F0               [24] 5482 	movx	@dptr,a
      001A83 80 48            [24] 5483 	sjmp	00103$
      001A85                       5484 00102$:
                                   5485 ;	..\COMMON\easyax5043.c:1046: axradio_sync_periodcorr += dt;
      001A85 90 00 23         [24] 5486 	mov	dptr,#_axradio_sync_periodcorr
      001A88 E0               [24] 5487 	movx	a,@dptr
      001A89 FA               [12] 5488 	mov	r2,a
      001A8A A3               [24] 5489 	inc	dptr
      001A8B E0               [24] 5490 	movx	a,@dptr
      001A8C FB               [12] 5491 	mov	r3,a
      001A8D 8A 00            [24] 5492 	mov	ar0,r2
      001A8F EB               [12] 5493 	mov	a,r3
      001A90 F9               [12] 5494 	mov	r1,a
      001A91 33               [12] 5495 	rlc	a
      001A92 95 E0            [12] 5496 	subb	a,acc
      001A94 FA               [12] 5497 	mov	r2,a
      001A95 FB               [12] 5498 	mov	r3,a
      001A96 EC               [12] 5499 	mov	a,r4
      001A97 28               [12] 5500 	add	a,r0
      001A98 F8               [12] 5501 	mov	r0,a
      001A99 ED               [12] 5502 	mov	a,r5
      001A9A 39               [12] 5503 	addc	a,r1
      001A9B F9               [12] 5504 	mov	r1,a
      001A9C EE               [12] 5505 	mov	a,r6
      001A9D 3A               [12] 5506 	addc	a,r2
      001A9E EF               [12] 5507 	mov	a,r7
      001A9F 3B               [12] 5508 	addc	a,r3
      001AA0 90 00 23         [24] 5509 	mov	dptr,#_axradio_sync_periodcorr
      001AA3 E8               [12] 5510 	mov	a,r0
      001AA4 F0               [24] 5511 	movx	@dptr,a
      001AA5 E9               [12] 5512 	mov	a,r1
      001AA6 A3               [24] 5513 	inc	dptr
      001AA7 F0               [24] 5514 	movx	@dptr,a
                                   5515 ;	..\COMMON\easyax5043.c:1047: dt >>= SYNC_K0;
      001AA8 EF               [12] 5516 	mov	a,r7
      001AA9 A2 E7            [12] 5517 	mov	c,acc.7
      001AAB 13               [12] 5518 	rrc	a
      001AAC FF               [12] 5519 	mov	r7,a
      001AAD EE               [12] 5520 	mov	a,r6
      001AAE 13               [12] 5521 	rrc	a
      001AAF FE               [12] 5522 	mov	r6,a
      001AB0 ED               [12] 5523 	mov	a,r5
      001AB1 13               [12] 5524 	rrc	a
      001AB2 FD               [12] 5525 	mov	r5,a
      001AB3 EC               [12] 5526 	mov	a,r4
      001AB4 13               [12] 5527 	rrc	a
      001AB5 FC               [12] 5528 	mov	r4,a
      001AB6 EF               [12] 5529 	mov	a,r7
      001AB7 A2 E7            [12] 5530 	mov	c,acc.7
      001AB9 13               [12] 5531 	rrc	a
      001ABA FF               [12] 5532 	mov	r7,a
      001ABB EE               [12] 5533 	mov	a,r6
      001ABC 13               [12] 5534 	rrc	a
      001ABD FE               [12] 5535 	mov	r6,a
      001ABE ED               [12] 5536 	mov	a,r5
      001ABF 13               [12] 5537 	rrc	a
      001AC0 FD               [12] 5538 	mov	r5,a
      001AC1 EC               [12] 5539 	mov	a,r4
      001AC2 13               [12] 5540 	rrc	a
                                   5541 ;	..\COMMON\easyax5043.c:1048: axradio_sync_addtime(dt);
      001AC3 F5 82            [12] 5542 	mov	dpl,a
      001AC5 8D 83            [24] 5543 	mov	dph,r5
      001AC7 8E F0            [24] 5544 	mov	b,r6
      001AC9 EF               [12] 5545 	mov	a,r7
      001ACA 12 19 42         [24] 5546 	lcall	_axradio_sync_addtime
      001ACD                       5547 00103$:
                                   5548 ;	..\COMMON\easyax5043.c:1050: axradio_sync_periodcorr = signedlimit16(axradio_sync_periodcorr, axradio_sync_slave_maxperiod);
      001ACD 90 00 23         [24] 5549 	mov	dptr,#_axradio_sync_periodcorr
      001AD0 E0               [24] 5550 	movx	a,@dptr
      001AD1 FE               [12] 5551 	mov	r6,a
      001AD2 A3               [24] 5552 	inc	dptr
      001AD3 E0               [24] 5553 	movx	a,@dptr
      001AD4 FF               [12] 5554 	mov	r7,a
      001AD5 90 4C E5         [24] 5555 	mov	dptr,#_axradio_sync_slave_maxperiod
      001AD8 E4               [12] 5556 	clr	a
      001AD9 93               [24] 5557 	movc	a,@a+dptr
      001ADA C0 E0            [24] 5558 	push	acc
      001ADC 74 01            [12] 5559 	mov	a,#0x01
      001ADE 93               [24] 5560 	movc	a,@a+dptr
      001ADF C0 E0            [24] 5561 	push	acc
      001AE1 8E 82            [24] 5562 	mov	dpl,r6
      001AE3 8F 83            [24] 5563 	mov	dph,r7
      001AE5 12 46 DA         [24] 5564 	lcall	_signedlimit16
      001AE8 AE 82            [24] 5565 	mov	r6,dpl
      001AEA AF 83            [24] 5566 	mov	r7,dph
      001AEC 15 81            [12] 5567 	dec	sp
      001AEE 15 81            [12] 5568 	dec	sp
      001AF0 90 00 23         [24] 5569 	mov	dptr,#_axradio_sync_periodcorr
      001AF3 EE               [12] 5570 	mov	a,r6
      001AF4 F0               [24] 5571 	movx	@dptr,a
      001AF5 EF               [12] 5572 	mov	a,r7
      001AF6 A3               [24] 5573 	inc	dptr
      001AF7 F0               [24] 5574 	movx	@dptr,a
      001AF8 22               [24] 5575 	ret
                                   5576 ;------------------------------------------------------------
                                   5577 ;Allocation info for local variables in function 'axradio_sync_slave_nextperiod'
                                   5578 ;------------------------------------------------------------
                                   5579 ;c                         Allocated to registers r6 r7 
                                   5580 ;------------------------------------------------------------
                                   5581 ;	..\COMMON\easyax5043.c:1053: static void axradio_sync_slave_nextperiod()
                                   5582 ;	-----------------------------------------
                                   5583 ;	 function axradio_sync_slave_nextperiod
                                   5584 ;	-----------------------------------------
      001AF9                       5585 _axradio_sync_slave_nextperiod:
                                   5586 ;	..\COMMON\easyax5043.c:1055: axradio_sync_addtime(axradio_sync_period);
      001AF9 90 4C D1         [24] 5587 	mov	dptr,#_axradio_sync_period
      001AFC E4               [12] 5588 	clr	a
      001AFD 93               [24] 5589 	movc	a,@a+dptr
      001AFE FC               [12] 5590 	mov	r4,a
      001AFF 74 01            [12] 5591 	mov	a,#0x01
      001B01 93               [24] 5592 	movc	a,@a+dptr
      001B02 FD               [12] 5593 	mov	r5,a
      001B03 74 02            [12] 5594 	mov	a,#0x02
      001B05 93               [24] 5595 	movc	a,@a+dptr
      001B06 FE               [12] 5596 	mov	r6,a
      001B07 74 03            [12] 5597 	mov	a,#0x03
      001B09 93               [24] 5598 	movc	a,@a+dptr
      001B0A 8C 82            [24] 5599 	mov	dpl,r4
      001B0C 8D 83            [24] 5600 	mov	dph,r5
      001B0E 8E F0            [24] 5601 	mov	b,r6
      001B10 12 19 42         [24] 5602 	lcall	_axradio_sync_addtime
                                   5603 ;	..\COMMON\easyax5043.c:1056: if (!checksignedlimit16(axradio_sync_periodcorr, axradio_sync_slave_maxperiod))
      001B13 90 00 23         [24] 5604 	mov	dptr,#_axradio_sync_periodcorr
      001B16 E0               [24] 5605 	movx	a,@dptr
      001B17 FE               [12] 5606 	mov	r6,a
      001B18 A3               [24] 5607 	inc	dptr
      001B19 E0               [24] 5608 	movx	a,@dptr
      001B1A FF               [12] 5609 	mov	r7,a
      001B1B 90 4C E5         [24] 5610 	mov	dptr,#_axradio_sync_slave_maxperiod
      001B1E E4               [12] 5611 	clr	a
      001B1F 93               [24] 5612 	movc	a,@a+dptr
      001B20 C0 E0            [24] 5613 	push	acc
      001B22 74 01            [12] 5614 	mov	a,#0x01
      001B24 93               [24] 5615 	movc	a,@a+dptr
      001B25 C0 E0            [24] 5616 	push	acc
      001B27 8E 82            [24] 5617 	mov	dpl,r6
      001B29 8F 83            [24] 5618 	mov	dph,r7
      001B2B 12 46 B3         [24] 5619 	lcall	_checksignedlimit16
      001B2E AF 82            [24] 5620 	mov	r7,dpl
      001B30 15 81            [12] 5621 	dec	sp
      001B32 15 81            [12] 5622 	dec	sp
      001B34 EF               [12] 5623 	mov	a,r7
      001B35 70 01            [24] 5624 	jnz	00102$
                                   5625 ;	..\COMMON\easyax5043.c:1057: return;
      001B37 22               [24] 5626 	ret
      001B38                       5627 00102$:
                                   5628 ;	..\COMMON\easyax5043.c:1059: int16_t __autodata c = axradio_sync_periodcorr;
      001B38 90 00 23         [24] 5629 	mov	dptr,#_axradio_sync_periodcorr
      001B3B E0               [24] 5630 	movx	a,@dptr
      001B3C FE               [12] 5631 	mov	r6,a
      001B3D A3               [24] 5632 	inc	dptr
      001B3E E0               [24] 5633 	movx	a,@dptr
                                   5634 ;	..\COMMON\easyax5043.c:1060: axradio_sync_addtime(c >> SYNC_K1);
      001B3F FF               [12] 5635 	mov	r7,a
      001B40 C4               [12] 5636 	swap	a
      001B41 03               [12] 5637 	rr	a
      001B42 CE               [12] 5638 	xch	a,r6
      001B43 C4               [12] 5639 	swap	a
      001B44 03               [12] 5640 	rr	a
      001B45 54 07            [12] 5641 	anl	a,#0x07
      001B47 6E               [12] 5642 	xrl	a,r6
      001B48 CE               [12] 5643 	xch	a,r6
      001B49 54 07            [12] 5644 	anl	a,#0x07
      001B4B CE               [12] 5645 	xch	a,r6
      001B4C 6E               [12] 5646 	xrl	a,r6
      001B4D CE               [12] 5647 	xch	a,r6
      001B4E 30 E2 02         [24] 5648 	jnb	acc.2,00109$
      001B51 44 F8            [12] 5649 	orl	a,#0xf8
      001B53                       5650 00109$:
      001B53 FF               [12] 5651 	mov	r7,a
      001B54 33               [12] 5652 	rlc	a
      001B55 95 E0            [12] 5653 	subb	a,acc
      001B57 FD               [12] 5654 	mov	r5,a
      001B58 8E 82            [24] 5655 	mov	dpl,r6
      001B5A 8F 83            [24] 5656 	mov	dph,r7
      001B5C 8D F0            [24] 5657 	mov	b,r5
      001B5E 02 19 42         [24] 5658 	ljmp	_axradio_sync_addtime
                                   5659 ;------------------------------------------------------------
                                   5660 ;Allocation info for local variables in function 'axradio_timer_callback'
                                   5661 ;------------------------------------------------------------
                                   5662 ;desc                      Allocated to registers 
                                   5663 ;r                         Allocated to registers r7 
                                   5664 ;idx                       Allocated to registers r7 
                                   5665 ;rs                        Allocated to registers r6 
                                   5666 ;idx                       Allocated to registers r7 
                                   5667 ;------------------------------------------------------------
                                   5668 ;	..\COMMON\easyax5043.c:1066: static void axradio_timer_callback(struct wtimer_desc __xdata *desc)
                                   5669 ;	-----------------------------------------
                                   5670 ;	 function axradio_timer_callback
                                   5671 ;	-----------------------------------------
      001B61                       5672 _axradio_timer_callback:
                                   5673 ;	..\COMMON\easyax5043.c:1069: switch (axradio_mode) {
      001B61 AF 08            [24] 5674 	mov	r7,_axradio_mode
      001B63 BF 10 00         [24] 5675 	cjne	r7,#0x10,00326$
      001B66                       5676 00326$:
      001B66 50 01            [24] 5677 	jnc	00327$
      001B68 22               [24] 5678 	ret
      001B69                       5679 00327$:
      001B69 EF               [12] 5680 	mov	a,r7
      001B6A 24 CC            [12] 5681 	add	a,#0xff - 0x33
      001B6C 50 01            [24] 5682 	jnc	00328$
      001B6E 22               [24] 5683 	ret
      001B6F                       5684 00328$:
      001B6F EF               [12] 5685 	mov	a,r7
      001B70 24 F0            [12] 5686 	add	a,#0xf0
      001B72 FF               [12] 5687 	mov	r7,a
      001B73 24 0A            [12] 5688 	add	a,#(00329$-3-.)
      001B75 83               [24] 5689 	movc	a,@a+pc
      001B76 F5 82            [12] 5690 	mov	dpl,a
      001B78 EF               [12] 5691 	mov	a,r7
      001B79 24 28            [12] 5692 	add	a,#(00330$-3-.)
      001B7B 83               [24] 5693 	movc	a,@a+pc
      001B7C F5 83            [12] 5694 	mov	dph,a
      001B7E E4               [12] 5695 	clr	a
      001B7F 73               [24] 5696 	jmp	@a+dptr
      001B80                       5697 00329$:
      001B80 68                    5698 	.db	00112$
      001B81 68                    5699 	.db	00113$
      001B82 FE                    5700 	.db	00123$
      001B83 FE                    5701 	.db	00124$
      001B84 8B                    5702 	.db	00235$
      001B85 8B                    5703 	.db	00235$
      001B86 8B                    5704 	.db	00235$
      001B87 8B                    5705 	.db	00235$
      001B88 8B                    5706 	.db	00235$
      001B89 8B                    5707 	.db	00235$
      001B8A 8B                    5708 	.db	00235$
      001B8B 8B                    5709 	.db	00235$
      001B8C 8B                    5710 	.db	00235$
      001B8D 8B                    5711 	.db	00235$
      001B8E 8B                    5712 	.db	00235$
      001B8F 8B                    5713 	.db	00235$
      001B90 C8                    5714 	.db	00106$
      001B91 C8                    5715 	.db	00107$
      001B92 60                    5716 	.db	00129$
      001B93 60                    5717 	.db	00130$
      001B94 8B                    5718 	.db	00235$
      001B95 8B                    5719 	.db	00235$
      001B96 8B                    5720 	.db	00235$
      001B97 8B                    5721 	.db	00235$
      001B98 C8                    5722 	.db	00102$
      001B99 C8                    5723 	.db	00103$
      001B9A C8                    5724 	.db	00104$
      001B9B C8                    5725 	.db	00105$
      001B9C C8                    5726 	.db	00101$
      001B9D 8B                    5727 	.db	00235$
      001B9E 8B                    5728 	.db	00235$
      001B9F 8B                    5729 	.db	00235$
      001BA0 F8                    5730 	.db	00166$
      001BA1 F8                    5731 	.db	00167$
      001BA2 97                    5732 	.db	00209$
      001BA3 97                    5733 	.db	00210$
      001BA4                       5734 00330$:
      001BA4 1C                    5735 	.db	00112$>>8
      001BA5 1C                    5736 	.db	00113$>>8
      001BA6 1C                    5737 	.db	00123$>>8
      001BA7 1C                    5738 	.db	00124$>>8
      001BA8 23                    5739 	.db	00235$>>8
      001BA9 23                    5740 	.db	00235$>>8
      001BAA 23                    5741 	.db	00235$>>8
      001BAB 23                    5742 	.db	00235$>>8
      001BAC 23                    5743 	.db	00235$>>8
      001BAD 23                    5744 	.db	00235$>>8
      001BAE 23                    5745 	.db	00235$>>8
      001BAF 23                    5746 	.db	00235$>>8
      001BB0 23                    5747 	.db	00235$>>8
      001BB1 23                    5748 	.db	00235$>>8
      001BB2 23                    5749 	.db	00235$>>8
      001BB3 23                    5750 	.db	00235$>>8
      001BB4 1B                    5751 	.db	00106$>>8
      001BB5 1B                    5752 	.db	00107$>>8
      001BB6 1D                    5753 	.db	00129$>>8
      001BB7 1D                    5754 	.db	00130$>>8
      001BB8 23                    5755 	.db	00235$>>8
      001BB9 23                    5756 	.db	00235$>>8
      001BBA 23                    5757 	.db	00235$>>8
      001BBB 23                    5758 	.db	00235$>>8
      001BBC 1B                    5759 	.db	00102$>>8
      001BBD 1B                    5760 	.db	00103$>>8
      001BBE 1B                    5761 	.db	00104$>>8
      001BBF 1B                    5762 	.db	00105$>>8
      001BC0 1B                    5763 	.db	00101$>>8
      001BC1 23                    5764 	.db	00235$>>8
      001BC2 23                    5765 	.db	00235$>>8
      001BC3 23                    5766 	.db	00235$>>8
      001BC4 1D                    5767 	.db	00166$>>8
      001BC5 1D                    5768 	.db	00167$>>8
      001BC6 1F                    5769 	.db	00209$>>8
      001BC7 1F                    5770 	.db	00210$>>8
                                   5771 ;	..\COMMON\easyax5043.c:1070: case AXRADIO_MODE_STREAM_RECEIVE:
      001BC8                       5772 00101$:
                                   5773 ;	..\COMMON\easyax5043.c:1071: case AXRADIO_MODE_STREAM_RECEIVE_UNENC:
      001BC8                       5774 00102$:
                                   5775 ;	..\COMMON\easyax5043.c:1072: case AXRADIO_MODE_STREAM_RECEIVE_SCRAM:
      001BC8                       5776 00103$:
                                   5777 ;	..\COMMON\easyax5043.c:1073: case AXRADIO_MODE_STREAM_RECEIVE_UNENC_LSB:
      001BC8                       5778 00104$:
                                   5779 ;	..\COMMON\easyax5043.c:1074: case AXRADIO_MODE_STREAM_RECEIVE_SCRAM_LSB:
      001BC8                       5780 00105$:
                                   5781 ;	..\COMMON\easyax5043.c:1075: case AXRADIO_MODE_ASYNC_RECEIVE:
      001BC8                       5782 00106$:
                                   5783 ;	..\COMMON\easyax5043.c:1076: case AXRADIO_MODE_WOR_RECEIVE:
      001BC8                       5784 00107$:
                                   5785 ;	..\COMMON\easyax5043.c:1077: if (axradio_syncstate == syncstate_asynctx)
      001BC8 90 00 13         [24] 5786 	mov	dptr,#_axradio_syncstate
      001BCB E0               [24] 5787 	movx	a,@dptr
      001BCC FF               [12] 5788 	mov	r7,a
      001BCD BF 02 03         [24] 5789 	cjne	r7,#0x02,00331$
      001BD0 02 1C 68         [24] 5790 	ljmp	00114$
      001BD3                       5791 00331$:
                                   5792 ;	..\COMMON\easyax5043.c:1079: wtimer_remove(&axradio_timer);
      001BD3 90 02 9D         [24] 5793 	mov	dptr,#_axradio_timer
      001BD6 12 47 8D         [24] 5794 	lcall	_wtimer_remove
                                   5795 ;	..\COMMON\easyax5043.c:1080: rearmcstimer:
      001BD9                       5796 00110$:
                                   5797 ;	..\COMMON\easyax5043.c:1081: axradio_timer.time = axradio_phy_cs_period;
      001BD9 90 4C A4         [24] 5798 	mov	dptr,#_axradio_phy_cs_period
      001BDC E4               [12] 5799 	clr	a
      001BDD 93               [24] 5800 	movc	a,@a+dptr
      001BDE FE               [12] 5801 	mov	r6,a
      001BDF 74 01            [12] 5802 	mov	a,#0x01
      001BE1 93               [24] 5803 	movc	a,@a+dptr
      001BE2 FF               [12] 5804 	mov	r7,a
      001BE3 7D 00            [12] 5805 	mov	r5,#0x00
      001BE5 7C 00            [12] 5806 	mov	r4,#0x00
      001BE7 90 02 A1         [24] 5807 	mov	dptr,#(_axradio_timer + 0x0004)
      001BEA EE               [12] 5808 	mov	a,r6
      001BEB F0               [24] 5809 	movx	@dptr,a
      001BEC EF               [12] 5810 	mov	a,r7
      001BED A3               [24] 5811 	inc	dptr
      001BEE F0               [24] 5812 	movx	@dptr,a
      001BEF ED               [12] 5813 	mov	a,r5
      001BF0 A3               [24] 5814 	inc	dptr
      001BF1 F0               [24] 5815 	movx	@dptr,a
      001BF2 EC               [12] 5816 	mov	a,r4
      001BF3 A3               [24] 5817 	inc	dptr
      001BF4 F0               [24] 5818 	movx	@dptr,a
                                   5819 ;	..\COMMON\easyax5043.c:1082: wtimer0_addrelative(&axradio_timer);
      001BF5 90 02 9D         [24] 5820 	mov	dptr,#_axradio_timer
      001BF8 12 42 DE         [24] 5821 	lcall	_wtimer0_addrelative
                                   5822 ;	..\COMMON\easyax5043.c:1083: chanstatecb:
      001BFB                       5823 00111$:
                                   5824 ;	..\COMMON\easyax5043.c:1084: update_timeanchor();
      001BFB 12 0A 7C         [24] 5825 	lcall	_update_timeanchor
                                   5826 ;	..\COMMON\easyax5043.c:1085: wtimer_remove_callback(&axradio_cb_channelstate.cb);
      001BFE 90 02 72         [24] 5827 	mov	dptr,#_axradio_cb_channelstate
      001C01 12 48 82         [24] 5828 	lcall	_wtimer_remove_callback
                                   5829 ;	..\COMMON\easyax5043.c:1086: axradio_cb_channelstate.st.error = AXRADIO_ERR_NOERROR;
      001C04 90 02 77         [24] 5830 	mov	dptr,#(_axradio_cb_channelstate + 0x0005)
      001C07 E4               [12] 5831 	clr	a
      001C08 F0               [24] 5832 	movx	@dptr,a
                                   5833 ;	..\COMMON\easyax5043.c:1088: int8_t __autodata r = radio_read8(AX5043_REG_RSSI);
      001C09 90 40 40         [24] 5834 	mov	dptr,#0x4040
      001C0C E0               [24] 5835 	movx	a,@dptr
                                   5836 ;	..\COMMON\easyax5043.c:1089: axradio_cb_channelstate.st.cs.rssi = r - (int16_t)axradio_phy_rssioffset;
      001C0D FF               [12] 5837 	mov	r7,a
      001C0E FD               [12] 5838 	mov	r5,a
      001C0F 33               [12] 5839 	rlc	a
      001C10 95 E0            [12] 5840 	subb	a,acc
      001C12 FE               [12] 5841 	mov	r6,a
      001C13 90 4C A1         [24] 5842 	mov	dptr,#_axradio_phy_rssioffset
      001C16 E4               [12] 5843 	clr	a
      001C17 93               [24] 5844 	movc	a,@a+dptr
      001C18 FC               [12] 5845 	mov	r4,a
      001C19 33               [12] 5846 	rlc	a
      001C1A 95 E0            [12] 5847 	subb	a,acc
      001C1C FB               [12] 5848 	mov	r3,a
      001C1D ED               [12] 5849 	mov	a,r5
      001C1E C3               [12] 5850 	clr	c
      001C1F 9C               [12] 5851 	subb	a,r4
      001C20 FD               [12] 5852 	mov	r5,a
      001C21 EE               [12] 5853 	mov	a,r6
      001C22 9B               [12] 5854 	subb	a,r3
      001C23 FE               [12] 5855 	mov	r6,a
      001C24 90 02 7C         [24] 5856 	mov	dptr,#(_axradio_cb_channelstate + 0x000a)
      001C27 ED               [12] 5857 	mov	a,r5
      001C28 F0               [24] 5858 	movx	@dptr,a
      001C29 EE               [12] 5859 	mov	a,r6
      001C2A A3               [24] 5860 	inc	dptr
      001C2B F0               [24] 5861 	movx	@dptr,a
                                   5862 ;	..\COMMON\easyax5043.c:1090: axradio_cb_channelstate.st.cs.busy = r >= axradio_phy_channelbusy;
      001C2C 90 4C A3         [24] 5863 	mov	dptr,#_axradio_phy_channelbusy
      001C2F E4               [12] 5864 	clr	a
      001C30 93               [24] 5865 	movc	a,@a+dptr
      001C31 FE               [12] 5866 	mov	r6,a
      001C32 C3               [12] 5867 	clr	c
      001C33 EF               [12] 5868 	mov	a,r7
      001C34 64 80            [12] 5869 	xrl	a,#0x80
      001C36 8E F0            [24] 5870 	mov	b,r6
      001C38 63 F0 80         [24] 5871 	xrl	b,#0x80
      001C3B 95 F0            [12] 5872 	subb	a,b
      001C3D B3               [12] 5873 	cpl	c
      001C3E 92 00            [24] 5874 	mov	_axradio_timer_callback_sloc0_1_0,c
      001C40 E4               [12] 5875 	clr	a
      001C41 33               [12] 5876 	rlc	a
      001C42 90 02 7E         [24] 5877 	mov	dptr,#(_axradio_cb_channelstate + 0x000c)
      001C45 F0               [24] 5878 	movx	@dptr,a
                                   5879 ;	..\COMMON\easyax5043.c:1092: axradio_cb_channelstate.st.time.t = axradio_timeanchor.radiotimer;
      001C46 90 00 29         [24] 5880 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      001C49 E0               [24] 5881 	movx	a,@dptr
      001C4A FC               [12] 5882 	mov	r4,a
      001C4B A3               [24] 5883 	inc	dptr
      001C4C E0               [24] 5884 	movx	a,@dptr
      001C4D FD               [12] 5885 	mov	r5,a
      001C4E A3               [24] 5886 	inc	dptr
      001C4F E0               [24] 5887 	movx	a,@dptr
      001C50 FE               [12] 5888 	mov	r6,a
      001C51 A3               [24] 5889 	inc	dptr
      001C52 E0               [24] 5890 	movx	a,@dptr
      001C53 FF               [12] 5891 	mov	r7,a
      001C54 90 02 78         [24] 5892 	mov	dptr,#(_axradio_cb_channelstate + 0x0006)
      001C57 EC               [12] 5893 	mov	a,r4
      001C58 F0               [24] 5894 	movx	@dptr,a
      001C59 ED               [12] 5895 	mov	a,r5
      001C5A A3               [24] 5896 	inc	dptr
      001C5B F0               [24] 5897 	movx	@dptr,a
      001C5C EE               [12] 5898 	mov	a,r6
      001C5D A3               [24] 5899 	inc	dptr
      001C5E F0               [24] 5900 	movx	@dptr,a
      001C5F EF               [12] 5901 	mov	a,r7
      001C60 A3               [24] 5902 	inc	dptr
      001C61 F0               [24] 5903 	movx	@dptr,a
                                   5904 ;	..\COMMON\easyax5043.c:1093: wtimer_add_callback(&axradio_cb_channelstate.cb);
      001C62 90 02 72         [24] 5905 	mov	dptr,#_axradio_cb_channelstate
                                   5906 ;	..\COMMON\easyax5043.c:1094: break;
      001C65 02 42 C4         [24] 5907 	ljmp	_wtimer_add_callback
                                   5908 ;	..\COMMON\easyax5043.c:1096: case AXRADIO_MODE_ASYNC_TRANSMIT:
      001C68                       5909 00112$:
                                   5910 ;	..\COMMON\easyax5043.c:1097: case AXRADIO_MODE_WOR_TRANSMIT:
      001C68                       5911 00113$:
                                   5912 ;	..\COMMON\easyax5043.c:1098: transmitcs:
      001C68                       5913 00114$:
                                   5914 ;	..\COMMON\easyax5043.c:1099: if (axradio_ack_count)
      001C68 90 00 1D         [24] 5915 	mov	dptr,#_axradio_ack_count
      001C6B E0               [24] 5916 	movx	a,@dptr
      001C6C FF               [12] 5917 	mov	r7,a
      001C6D E0               [24] 5918 	movx	a,@dptr
      001C6E 60 06            [24] 5919 	jz	00116$
                                   5920 ;	..\COMMON\easyax5043.c:1100: --axradio_ack_count;
      001C70 EF               [12] 5921 	mov	a,r7
      001C71 14               [12] 5922 	dec	a
      001C72 90 00 1D         [24] 5923 	mov	dptr,#_axradio_ack_count
      001C75 F0               [24] 5924 	movx	@dptr,a
      001C76                       5925 00116$:
                                   5926 ;	..\COMMON\easyax5043.c:1101: wtimer_remove(&axradio_timer);
      001C76 90 02 9D         [24] 5927 	mov	dptr,#_axradio_timer
      001C79 12 47 8D         [24] 5928 	lcall	_wtimer_remove
                                   5929 ;	..\COMMON\easyax5043.c:1102: if ((int8_t)radio_read8(AX5043_REG_RSSI) < axradio_phy_channelbusy ||
      001C7C 90 40 40         [24] 5930 	mov	dptr,#0x4040
      001C7F E0               [24] 5931 	movx	a,@dptr
      001C80 FF               [12] 5932 	mov	r7,a
      001C81 90 4C A3         [24] 5933 	mov	dptr,#_axradio_phy_channelbusy
      001C84 E4               [12] 5934 	clr	a
      001C85 93               [24] 5935 	movc	a,@a+dptr
      001C86 FE               [12] 5936 	mov	r6,a
      001C87 C3               [12] 5937 	clr	c
      001C88 EF               [12] 5938 	mov	a,r7
      001C89 64 80            [12] 5939 	xrl	a,#0x80
      001C8B 8E F0            [24] 5940 	mov	b,r6
      001C8D 63 F0 80         [24] 5941 	xrl	b,#0x80
      001C90 95 F0            [12] 5942 	subb	a,b
      001C92 40 0F            [24] 5943 	jc	00117$
                                   5944 ;	..\COMMON\easyax5043.c:1103: (!axradio_ack_count && axradio_phy_lbt_forcetx)) {
      001C94 90 00 1D         [24] 5945 	mov	dptr,#_axradio_ack_count
      001C97 E0               [24] 5946 	movx	a,@dptr
      001C98 FF               [12] 5947 	mov	r7,a
      001C99 E0               [24] 5948 	movx	a,@dptr
      001C9A 70 23            [24] 5949 	jnz	00118$
      001C9C 90 4C A8         [24] 5950 	mov	dptr,#_axradio_phy_lbt_forcetx
      001C9F E4               [12] 5951 	clr	a
      001CA0 93               [24] 5952 	movc	a,@a+dptr
      001CA1 60 1C            [24] 5953 	jz	00118$
      001CA3                       5954 00117$:
                                   5955 ;	..\COMMON\easyax5043.c:1104: axradio_syncstate = syncstate_off;
      001CA3 90 00 13         [24] 5956 	mov	dptr,#_axradio_syncstate
      001CA6 E4               [12] 5957 	clr	a
      001CA7 F0               [24] 5958 	movx	@dptr,a
                                   5959 ;	..\COMMON\easyax5043.c:1105: axradio_txbuffer_cnt = axradio_phy_preamble_longlen;
      001CA8 90 4C AD         [24] 5960 	mov	dptr,#_axradio_phy_preamble_longlen
                                   5961 ;	genFromRTrack removed	clr	a
      001CAB 93               [24] 5962 	movc	a,@a+dptr
      001CAC FD               [12] 5963 	mov	r5,a
      001CAD 74 01            [12] 5964 	mov	a,#0x01
      001CAF 93               [24] 5965 	movc	a,@a+dptr
      001CB0 FE               [12] 5966 	mov	r6,a
      001CB1 90 00 16         [24] 5967 	mov	dptr,#_axradio_txbuffer_cnt
      001CB4 ED               [12] 5968 	mov	a,r5
      001CB5 F0               [24] 5969 	movx	@dptr,a
      001CB6 EE               [12] 5970 	mov	a,r6
      001CB7 A3               [24] 5971 	inc	dptr
      001CB8 F0               [24] 5972 	movx	@dptr,a
                                   5973 ;	..\COMMON\easyax5043.c:1106: ax5043_prepare_tx();
      001CB9 12 17 61         [24] 5974 	lcall	_ax5043_prepare_tx
                                   5975 ;	..\COMMON\easyax5043.c:1107: goto chanstatecb;
      001CBC 02 1B FB         [24] 5976 	ljmp	00111$
      001CBF                       5977 00118$:
                                   5978 ;	..\COMMON\easyax5043.c:1109: if (axradio_ack_count)
      001CBF EF               [12] 5979 	mov	a,r7
      001CC0 60 03            [24] 5980 	jz	00336$
      001CC2 02 1B D9         [24] 5981 	ljmp	00110$
      001CC5                       5982 00336$:
                                   5983 ;	..\COMMON\easyax5043.c:1111: update_timeanchor();
      001CC5 12 0A 7C         [24] 5984 	lcall	_update_timeanchor
                                   5985 ;	..\COMMON\easyax5043.c:1112: axradio_syncstate = syncstate_off;
      001CC8 90 00 13         [24] 5986 	mov	dptr,#_axradio_syncstate
      001CCB E4               [12] 5987 	clr	a
      001CCC F0               [24] 5988 	movx	@dptr,a
                                   5989 ;	..\COMMON\easyax5043.c:1113: ax5043_off();
      001CCD 12 17 8A         [24] 5990 	lcall	_ax5043_off
                                   5991 ;	..\COMMON\easyax5043.c:1114: wtimer_remove_callback(&axradio_cb_transmitstart.cb);
      001CD0 90 02 7F         [24] 5992 	mov	dptr,#_axradio_cb_transmitstart
      001CD3 12 48 82         [24] 5993 	lcall	_wtimer_remove_callback
                                   5994 ;	..\COMMON\easyax5043.c:1115: axradio_cb_transmitstart.st.error = AXRADIO_ERR_TIMEOUT;
      001CD6 90 02 84         [24] 5995 	mov	dptr,#(_axradio_cb_transmitstart + 0x0005)
      001CD9 74 03            [12] 5996 	mov	a,#0x03
      001CDB F0               [24] 5997 	movx	@dptr,a
                                   5998 ;	..\COMMON\easyax5043.c:1116: axradio_cb_transmitstart.st.time.t = axradio_timeanchor.radiotimer;
      001CDC 90 00 29         [24] 5999 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      001CDF E0               [24] 6000 	movx	a,@dptr
      001CE0 FC               [12] 6001 	mov	r4,a
      001CE1 A3               [24] 6002 	inc	dptr
      001CE2 E0               [24] 6003 	movx	a,@dptr
      001CE3 FD               [12] 6004 	mov	r5,a
      001CE4 A3               [24] 6005 	inc	dptr
      001CE5 E0               [24] 6006 	movx	a,@dptr
      001CE6 FE               [12] 6007 	mov	r6,a
      001CE7 A3               [24] 6008 	inc	dptr
      001CE8 E0               [24] 6009 	movx	a,@dptr
      001CE9 FF               [12] 6010 	mov	r7,a
      001CEA 90 02 85         [24] 6011 	mov	dptr,#(_axradio_cb_transmitstart + 0x0006)
      001CED EC               [12] 6012 	mov	a,r4
      001CEE F0               [24] 6013 	movx	@dptr,a
      001CEF ED               [12] 6014 	mov	a,r5
      001CF0 A3               [24] 6015 	inc	dptr
      001CF1 F0               [24] 6016 	movx	@dptr,a
      001CF2 EE               [12] 6017 	mov	a,r6
      001CF3 A3               [24] 6018 	inc	dptr
      001CF4 F0               [24] 6019 	movx	@dptr,a
      001CF5 EF               [12] 6020 	mov	a,r7
      001CF6 A3               [24] 6021 	inc	dptr
      001CF7 F0               [24] 6022 	movx	@dptr,a
                                   6023 ;	..\COMMON\easyax5043.c:1117: wtimer_add_callback(&axradio_cb_transmitstart.cb);
      001CF8 90 02 7F         [24] 6024 	mov	dptr,#_axradio_cb_transmitstart
                                   6025 ;	..\COMMON\easyax5043.c:1118: break;
      001CFB 02 42 C4         [24] 6026 	ljmp	_wtimer_add_callback
                                   6027 ;	..\COMMON\easyax5043.c:1120: case AXRADIO_MODE_ACK_TRANSMIT:
      001CFE                       6028 00123$:
                                   6029 ;	..\COMMON\easyax5043.c:1121: case AXRADIO_MODE_WOR_ACK_TRANSMIT:
      001CFE                       6030 00124$:
                                   6031 ;	..\COMMON\easyax5043.c:1122: if (axradio_syncstate == syncstate_lbt)
      001CFE 90 00 13         [24] 6032 	mov	dptr,#_axradio_syncstate
      001D01 E0               [24] 6033 	movx	a,@dptr
      001D02 FF               [12] 6034 	mov	r7,a
      001D03 BF 01 03         [24] 6035 	cjne	r7,#0x01,00337$
      001D06 02 1C 68         [24] 6036 	ljmp	00114$
      001D09                       6037 00337$:
                                   6038 ;	..\COMMON\easyax5043.c:1124: ax5043_off();
      001D09 12 17 8A         [24] 6039 	lcall	_ax5043_off
                                   6040 ;	..\COMMON\easyax5043.c:1125: if (!axradio_ack_count) {
      001D0C 90 00 1D         [24] 6041 	mov	dptr,#_axradio_ack_count
      001D0F E0               [24] 6042 	movx	a,@dptr
      001D10 FF               [12] 6043 	mov	r7,a
      001D11 E0               [24] 6044 	movx	a,@dptr
      001D12 70 31            [24] 6045 	jnz	00128$
                                   6046 ;	..\COMMON\easyax5043.c:1126: update_timeanchor();
      001D14 12 0A 7C         [24] 6047 	lcall	_update_timeanchor
                                   6048 ;	..\COMMON\easyax5043.c:1127: wtimer_remove_callback(&axradio_cb_transmitend.cb);
      001D17 90 02 89         [24] 6049 	mov	dptr,#_axradio_cb_transmitend
      001D1A 12 48 82         [24] 6050 	lcall	_wtimer_remove_callback
                                   6051 ;	..\COMMON\easyax5043.c:1128: axradio_cb_transmitend.st.error = AXRADIO_ERR_TIMEOUT;
      001D1D 90 02 8E         [24] 6052 	mov	dptr,#(_axradio_cb_transmitend + 0x0005)
      001D20 74 03            [12] 6053 	mov	a,#0x03
      001D22 F0               [24] 6054 	movx	@dptr,a
                                   6055 ;	..\COMMON\easyax5043.c:1129: axradio_cb_transmitend.st.time.t = axradio_timeanchor.radiotimer;
      001D23 90 00 29         [24] 6056 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      001D26 E0               [24] 6057 	movx	a,@dptr
      001D27 FB               [12] 6058 	mov	r3,a
      001D28 A3               [24] 6059 	inc	dptr
      001D29 E0               [24] 6060 	movx	a,@dptr
      001D2A FC               [12] 6061 	mov	r4,a
      001D2B A3               [24] 6062 	inc	dptr
      001D2C E0               [24] 6063 	movx	a,@dptr
      001D2D FD               [12] 6064 	mov	r5,a
      001D2E A3               [24] 6065 	inc	dptr
      001D2F E0               [24] 6066 	movx	a,@dptr
      001D30 FE               [12] 6067 	mov	r6,a
      001D31 90 02 8F         [24] 6068 	mov	dptr,#(_axradio_cb_transmitend + 0x0006)
      001D34 EB               [12] 6069 	mov	a,r3
      001D35 F0               [24] 6070 	movx	@dptr,a
      001D36 EC               [12] 6071 	mov	a,r4
      001D37 A3               [24] 6072 	inc	dptr
      001D38 F0               [24] 6073 	movx	@dptr,a
      001D39 ED               [12] 6074 	mov	a,r5
      001D3A A3               [24] 6075 	inc	dptr
      001D3B F0               [24] 6076 	movx	@dptr,a
      001D3C EE               [12] 6077 	mov	a,r6
      001D3D A3               [24] 6078 	inc	dptr
      001D3E F0               [24] 6079 	movx	@dptr,a
                                   6080 ;	..\COMMON\easyax5043.c:1130: wtimer_add_callback(&axradio_cb_transmitend.cb);
      001D3F 90 02 89         [24] 6081 	mov	dptr,#_axradio_cb_transmitend
                                   6082 ;	..\COMMON\easyax5043.c:1131: break;
      001D42 02 42 C4         [24] 6083 	ljmp	_wtimer_add_callback
      001D45                       6084 00128$:
                                   6085 ;	..\COMMON\easyax5043.c:1133: --axradio_ack_count;
      001D45 EF               [12] 6086 	mov	a,r7
      001D46 14               [12] 6087 	dec	a
      001D47 90 00 1D         [24] 6088 	mov	dptr,#_axradio_ack_count
      001D4A F0               [24] 6089 	movx	@dptr,a
                                   6090 ;	..\COMMON\easyax5043.c:1134: axradio_txbuffer_cnt = axradio_phy_preamble_longlen;
      001D4B 90 4C AD         [24] 6091 	mov	dptr,#_axradio_phy_preamble_longlen
      001D4E E4               [12] 6092 	clr	a
      001D4F 93               [24] 6093 	movc	a,@a+dptr
      001D50 FE               [12] 6094 	mov	r6,a
      001D51 74 01            [12] 6095 	mov	a,#0x01
      001D53 93               [24] 6096 	movc	a,@a+dptr
      001D54 FF               [12] 6097 	mov	r7,a
      001D55 90 00 16         [24] 6098 	mov	dptr,#_axradio_txbuffer_cnt
      001D58 EE               [12] 6099 	mov	a,r6
      001D59 F0               [24] 6100 	movx	@dptr,a
      001D5A EF               [12] 6101 	mov	a,r7
      001D5B A3               [24] 6102 	inc	dptr
      001D5C F0               [24] 6103 	movx	@dptr,a
                                   6104 ;	..\COMMON\easyax5043.c:1135: ax5043_prepare_tx();
                                   6105 ;	..\COMMON\easyax5043.c:1136: break;
      001D5D 02 17 61         [24] 6106 	ljmp	_ax5043_prepare_tx
                                   6107 ;	..\COMMON\easyax5043.c:1138: case AXRADIO_MODE_ACK_RECEIVE:
      001D60                       6108 00129$:
                                   6109 ;	..\COMMON\easyax5043.c:1139: case AXRADIO_MODE_WOR_ACK_RECEIVE:
      001D60                       6110 00130$:
                                   6111 ;	..\COMMON\easyax5043.c:1140: if (axradio_syncstate == syncstate_lbt)
      001D60 90 00 13         [24] 6112 	mov	dptr,#_axradio_syncstate
      001D63 E0               [24] 6113 	movx	a,@dptr
      001D64 FF               [12] 6114 	mov	r7,a
      001D65 BF 01 03         [24] 6115 	cjne	r7,#0x01,00339$
      001D68 02 1C 68         [24] 6116 	ljmp	00114$
      001D6B                       6117 00339$:
                                   6118 ;	..\COMMON\easyax5043.c:1143: radio_write8(AX5043_REG_FIFOSTAT, 3);
      001D6B                       6119 00134$:
      001D6B 90 40 28         [24] 6120 	mov	dptr,#0x4028
      001D6E 74 03            [12] 6121 	mov	a,#0x03
      001D70 F0               [24] 6122 	movx	@dptr,a
                                   6123 ;	..\COMMON\easyax5043.c:1144: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_FULL_TX);
      001D71 90 40 02         [24] 6124 	mov	dptr,#0x4002
      001D74 74 0D            [12] 6125 	mov	a,#0x0d
      001D76 F0               [24] 6126 	movx	@dptr,a
                                   6127 ;	..\COMMON\easyax5043.c:1145: while (!(radio_read8(AX5043_REG_POWSTAT) & 0x08)); // wait for modem vdd so writing the FIFO is safe
      001D77                       6128 00140$:
      001D77 90 40 03         [24] 6129 	mov	dptr,#0x4003
      001D7A E0               [24] 6130 	movx	a,@dptr
      001D7B FF               [12] 6131 	mov	r7,a
      001D7C 30 E3 F8         [24] 6132 	jnb	acc.3,00140$
                                   6133 ;	..\COMMON\easyax5043.c:1146: ax5043_init_registers_tx();
      001D7F 12 0B 5F         [24] 6134 	lcall	_ax5043_init_registers_tx
                                   6135 ;	..\COMMON\easyax5043.c:1147: radio_read8(AX5043_REG_RADIOEVENTREQ0); // make sure REVRDONE bit is cleared, so it is a reliable indicator that the packet is out
      001D82 90 40 0F         [24] 6136 	mov	dptr,#0x400f
      001D85 E0               [24] 6137 	movx	a,@dptr
                                   6138 ;	..\COMMON\easyax5043.c:1148: radio_write8(AX5043_REG_FIFOTHRESH1, 0);
      001D86 90 40 2E         [24] 6139 	mov	dptr,#0x402e
      001D89 E4               [12] 6140 	clr	a
      001D8A F0               [24] 6141 	movx	@dptr,a
                                   6142 ;	..\COMMON\easyax5043.c:1149: radio_write8(AX5043_REG_FIFOTHRESH0, 0x80);
      001D8B 90 40 2F         [24] 6143 	mov	dptr,#0x402f
      001D8E 74 80            [12] 6144 	mov	a,#0x80
      001D90 F0               [24] 6145 	movx	@dptr,a
                                   6146 ;	..\COMMON\easyax5043.c:1150: axradio_trxstate = trxstate_tx_longpreamble;
      001D91 75 09 0A         [24] 6147 	mov	_axradio_trxstate,#0x0a
                                   6148 ;	..\COMMON\easyax5043.c:1151: axradio_txbuffer_cnt = axradio_phy_preamble_longlen;
      001D94 90 4C AD         [24] 6149 	mov	dptr,#_axradio_phy_preamble_longlen
      001D97 E4               [12] 6150 	clr	a
      001D98 93               [24] 6151 	movc	a,@a+dptr
      001D99 FE               [12] 6152 	mov	r6,a
      001D9A 74 01            [12] 6153 	mov	a,#0x01
      001D9C 93               [24] 6154 	movc	a,@a+dptr
      001D9D FF               [12] 6155 	mov	r7,a
      001D9E 90 00 16         [24] 6156 	mov	dptr,#_axradio_txbuffer_cnt
      001DA1 EE               [12] 6157 	mov	a,r6
      001DA2 F0               [24] 6158 	movx	@dptr,a
      001DA3 EF               [12] 6159 	mov	a,r7
      001DA4 A3               [24] 6160 	inc	dptr
      001DA5 F0               [24] 6161 	movx	@dptr,a
                                   6162 ;	..\COMMON\easyax5043.c:1153: if ((radio_read8(AX5043_REG_MODULATION) & 0x0F) == 9) { // 4-FSK
      001DA6 90 40 10         [24] 6163 	mov	dptr,#0x4010
      001DA9 E0               [24] 6164 	movx	a,@dptr
      001DAA FF               [12] 6165 	mov	r7,a
      001DAB 53 07 0F         [24] 6166 	anl	ar7,#0x0f
      001DAE BF 09 11         [24] 6167 	cjne	r7,#0x09,00163$
                                   6168 ;	..\COMMON\easyax5043.c:1154: radio_write8(AX5043_REG_FIFODATA, AX5043_FIFOCMD_DATA | (7 << 5));
                                   6169 ;	..\COMMON\easyax5043.c:1155: radio_write8(AX5043_REG_FIFODATA, 2);  // length (including flags)
                                   6170 ;	..\COMMON\easyax5043.c:1156: radio_write8(AX5043_REG_FIFODATA, 0x01);  // flag PKTSTART -> dibit sync
      001DB1 90 40 29         [24] 6171 	mov	dptr,#0x4029
      001DB4 74 E1            [12] 6172 	mov	a,#0xe1
      001DB6 F0               [24] 6173 	movx	@dptr,a
      001DB7 74 02            [12] 6174 	mov	a,#0x02
      001DB9 F0               [24] 6175 	movx	@dptr,a
      001DBA 14               [12] 6176 	dec	a
      001DBB F0               [24] 6177 	movx	@dptr,a
                                   6178 ;	..\COMMON\easyax5043.c:1157: radio_write8(AX5043_REG_FIFODATA, 0x11); // dummy byte for forcing dibit sync
      001DBC 90 40 29         [24] 6179 	mov	dptr,#0x4029
      001DBF 74 11            [12] 6180 	mov	a,#0x11
      001DC1 F0               [24] 6181 	movx	@dptr,a
                                   6182 ;	..\COMMON\easyax5043.c:1164: radio_write8(AX5043_REG_IRQMASK0, 0x08); // enable fifo free threshold
      001DC2                       6183 00163$:
      001DC2 90 40 07         [24] 6184 	mov	dptr,#0x4007
      001DC5 74 08            [12] 6185 	mov	a,#0x08
      001DC7 F0               [24] 6186 	movx	@dptr,a
                                   6187 ;	..\COMMON\easyax5043.c:1165: update_timeanchor();
      001DC8 12 0A 7C         [24] 6188 	lcall	_update_timeanchor
                                   6189 ;	..\COMMON\easyax5043.c:1166: wtimer_remove_callback(&axradio_cb_transmitstart.cb);
      001DCB 90 02 7F         [24] 6190 	mov	dptr,#_axradio_cb_transmitstart
      001DCE 12 48 82         [24] 6191 	lcall	_wtimer_remove_callback
                                   6192 ;	..\COMMON\easyax5043.c:1167: axradio_cb_transmitstart.st.error = AXRADIO_ERR_NOERROR;
      001DD1 90 02 84         [24] 6193 	mov	dptr,#(_axradio_cb_transmitstart + 0x0005)
      001DD4 E4               [12] 6194 	clr	a
      001DD5 F0               [24] 6195 	movx	@dptr,a
                                   6196 ;	..\COMMON\easyax5043.c:1168: axradio_cb_transmitstart.st.time.t = axradio_timeanchor.radiotimer;
      001DD6 90 00 29         [24] 6197 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      001DD9 E0               [24] 6198 	movx	a,@dptr
      001DDA FC               [12] 6199 	mov	r4,a
      001DDB A3               [24] 6200 	inc	dptr
      001DDC E0               [24] 6201 	movx	a,@dptr
      001DDD FD               [12] 6202 	mov	r5,a
      001DDE A3               [24] 6203 	inc	dptr
      001DDF E0               [24] 6204 	movx	a,@dptr
      001DE0 FE               [12] 6205 	mov	r6,a
      001DE1 A3               [24] 6206 	inc	dptr
      001DE2 E0               [24] 6207 	movx	a,@dptr
      001DE3 FF               [12] 6208 	mov	r7,a
      001DE4 90 02 85         [24] 6209 	mov	dptr,#(_axradio_cb_transmitstart + 0x0006)
      001DE7 EC               [12] 6210 	mov	a,r4
      001DE8 F0               [24] 6211 	movx	@dptr,a
      001DE9 ED               [12] 6212 	mov	a,r5
      001DEA A3               [24] 6213 	inc	dptr
      001DEB F0               [24] 6214 	movx	@dptr,a
      001DEC EE               [12] 6215 	mov	a,r6
      001DED A3               [24] 6216 	inc	dptr
      001DEE F0               [24] 6217 	movx	@dptr,a
      001DEF EF               [12] 6218 	mov	a,r7
      001DF0 A3               [24] 6219 	inc	dptr
      001DF1 F0               [24] 6220 	movx	@dptr,a
                                   6221 ;	..\COMMON\easyax5043.c:1169: wtimer_add_callback(&axradio_cb_transmitstart.cb);
      001DF2 90 02 7F         [24] 6222 	mov	dptr,#_axradio_cb_transmitstart
                                   6223 ;	..\COMMON\easyax5043.c:1170: break;
      001DF5 02 42 C4         [24] 6224 	ljmp	_wtimer_add_callback
                                   6225 ;	..\COMMON\easyax5043.c:1172: case AXRADIO_MODE_SYNC_MASTER:
      001DF8                       6226 00166$:
                                   6227 ;	..\COMMON\easyax5043.c:1173: case AXRADIO_MODE_SYNC_ACK_MASTER:
      001DF8                       6228 00167$:
                                   6229 ;	..\COMMON\easyax5043.c:1174: switch (axradio_syncstate) {
      001DF8 90 00 13         [24] 6230 	mov	dptr,#_axradio_syncstate
      001DFB E0               [24] 6231 	movx	a,@dptr
      001DFC FF               [12] 6232 	mov	r7,a
      001DFD BF 04 02         [24] 6233 	cjne	r7,#0x04,00343$
      001E00 80 58            [24] 6234 	sjmp	00173$
      001E02                       6235 00343$:
      001E02 BF 05 03         [24] 6236 	cjne	r7,#0x05,00344$
      001E05 02 1F 37         [24] 6237 	ljmp	00207$
      001E08                       6238 00344$:
                                   6239 ;	..\COMMON\easyax5043.c:1176: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_XTAL_ON);
      001E08 90 40 02         [24] 6240 	mov	dptr,#0x4002
      001E0B 74 05            [12] 6241 	mov	a,#0x05
      001E0D F0               [24] 6242 	movx	@dptr,a
                                   6243 ;	..\COMMON\easyax5043.c:1177: ax5043_init_registers_tx();
      001E0E 12 0B 5F         [24] 6244 	lcall	_ax5043_init_registers_tx
                                   6245 ;	..\COMMON\easyax5043.c:1178: axradio_syncstate = syncstate_master_xostartup;
      001E11 90 00 13         [24] 6246 	mov	dptr,#_axradio_syncstate
      001E14 74 04            [12] 6247 	mov	a,#0x04
      001E16 F0               [24] 6248 	movx	@dptr,a
                                   6249 ;	..\COMMON\easyax5043.c:1179: wtimer_remove_callback(&axradio_cb_transmitdata.cb);
      001E17 90 02 93         [24] 6250 	mov	dptr,#_axradio_cb_transmitdata
      001E1A 12 48 82         [24] 6251 	lcall	_wtimer_remove_callback
                                   6252 ;	..\COMMON\easyax5043.c:1180: axradio_cb_transmitdata.st.error = AXRADIO_ERR_NOERROR;
      001E1D 90 02 98         [24] 6253 	mov	dptr,#(_axradio_cb_transmitdata + 0x0005)
      001E20 E4               [12] 6254 	clr	a
      001E21 F0               [24] 6255 	movx	@dptr,a
                                   6256 ;	..\COMMON\easyax5043.c:1181: axradio_cb_transmitdata.st.time.t = 0;
      001E22 90 02 99         [24] 6257 	mov	dptr,#(_axradio_cb_transmitdata + 0x0006)
      001E25 F0               [24] 6258 	movx	@dptr,a
      001E26 A3               [24] 6259 	inc	dptr
      001E27 F0               [24] 6260 	movx	@dptr,a
      001E28 A3               [24] 6261 	inc	dptr
      001E29 F0               [24] 6262 	movx	@dptr,a
      001E2A A3               [24] 6263 	inc	dptr
      001E2B F0               [24] 6264 	movx	@dptr,a
                                   6265 ;	..\COMMON\easyax5043.c:1182: wtimer_add_callback(&axradio_cb_transmitdata.cb);
      001E2C 90 02 93         [24] 6266 	mov	dptr,#_axradio_cb_transmitdata
      001E2F 12 42 C4         [24] 6267 	lcall	_wtimer_add_callback
                                   6268 ;	..\COMMON\easyax5043.c:1183: wtimer_remove(&axradio_timer);
      001E32 90 02 9D         [24] 6269 	mov	dptr,#_axradio_timer
      001E35 12 47 8D         [24] 6270 	lcall	_wtimer_remove
                                   6271 ;	..\COMMON\easyax5043.c:1184: axradio_timer.time = axradio_sync_time;
      001E38 90 00 1F         [24] 6272 	mov	dptr,#_axradio_sync_time
      001E3B E0               [24] 6273 	movx	a,@dptr
      001E3C FC               [12] 6274 	mov	r4,a
      001E3D A3               [24] 6275 	inc	dptr
      001E3E E0               [24] 6276 	movx	a,@dptr
      001E3F FD               [12] 6277 	mov	r5,a
      001E40 A3               [24] 6278 	inc	dptr
      001E41 E0               [24] 6279 	movx	a,@dptr
      001E42 FE               [12] 6280 	mov	r6,a
      001E43 A3               [24] 6281 	inc	dptr
      001E44 E0               [24] 6282 	movx	a,@dptr
      001E45 FF               [12] 6283 	mov	r7,a
      001E46 90 02 A1         [24] 6284 	mov	dptr,#(_axradio_timer + 0x0004)
      001E49 EC               [12] 6285 	mov	a,r4
      001E4A F0               [24] 6286 	movx	@dptr,a
      001E4B ED               [12] 6287 	mov	a,r5
      001E4C A3               [24] 6288 	inc	dptr
      001E4D F0               [24] 6289 	movx	@dptr,a
      001E4E EE               [12] 6290 	mov	a,r6
      001E4F A3               [24] 6291 	inc	dptr
      001E50 F0               [24] 6292 	movx	@dptr,a
      001E51 EF               [12] 6293 	mov	a,r7
      001E52 A3               [24] 6294 	inc	dptr
      001E53 F0               [24] 6295 	movx	@dptr,a
                                   6296 ;	..\COMMON\easyax5043.c:1185: wtimer0_addabsolute(&axradio_timer);
      001E54 90 02 9D         [24] 6297 	mov	dptr,#_axradio_timer
                                   6298 ;	..\COMMON\easyax5043.c:1186: break;
      001E57 02 43 6C         [24] 6299 	ljmp	_wtimer0_addabsolute
                                   6300 ;	..\COMMON\easyax5043.c:1189: radio_write8(AX5043_REG_FIFOSTAT, 3);
      001E5A                       6301 00173$:
      001E5A 90 40 28         [24] 6302 	mov	dptr,#0x4028
      001E5D 74 03            [12] 6303 	mov	a,#0x03
      001E5F F0               [24] 6304 	movx	@dptr,a
                                   6305 ;	..\COMMON\easyax5043.c:1190: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_FULL_TX);
      001E60 90 40 02         [24] 6306 	mov	dptr,#0x4002
      001E63 74 0D            [12] 6307 	mov	a,#0x0d
      001E65 F0               [24] 6308 	movx	@dptr,a
                                   6309 ;	..\COMMON\easyax5043.c:1191: while (!(radio_read8(AX5043_REG_POWSTAT) & 0x08)); // wait for modem vdd so writing the FIFO is safe
      001E66                       6310 00179$:
      001E66 90 40 03         [24] 6311 	mov	dptr,#0x4003
      001E69 E0               [24] 6312 	movx	a,@dptr
      001E6A FF               [12] 6313 	mov	r7,a
      001E6B 30 E3 F8         [24] 6314 	jnb	acc.3,00179$
                                   6315 ;	..\COMMON\easyax5043.c:1192: radio_read8(AX5043_REG_RADIOEVENTREQ0); // make sure REVRDONE bit is cleared, so it is a reliable indicator that the packet is out
      001E6E 90 40 0F         [24] 6316 	mov	dptr,#0x400f
      001E71 E0               [24] 6317 	movx	a,@dptr
                                   6318 ;	..\COMMON\easyax5043.c:1193: radio_write8(AX5043_REG_FIFOTHRESH1, 0);
      001E72 90 40 2E         [24] 6319 	mov	dptr,#0x402e
      001E75 E4               [12] 6320 	clr	a
      001E76 F0               [24] 6321 	movx	@dptr,a
                                   6322 ;	..\COMMON\easyax5043.c:1194: radio_write8(AX5043_REG_FIFOTHRESH0, 0x80);
      001E77 90 40 2F         [24] 6323 	mov	dptr,#0x402f
      001E7A 74 80            [12] 6324 	mov	a,#0x80
      001E7C F0               [24] 6325 	movx	@dptr,a
                                   6326 ;	..\COMMON\easyax5043.c:1195: axradio_trxstate = trxstate_tx_longpreamble;
      001E7D 75 09 0A         [24] 6327 	mov	_axradio_trxstate,#0x0a
                                   6328 ;	..\COMMON\easyax5043.c:1196: axradio_txbuffer_cnt = axradio_phy_preamble_longlen;
      001E80 90 4C AD         [24] 6329 	mov	dptr,#_axradio_phy_preamble_longlen
      001E83 E4               [12] 6330 	clr	a
      001E84 93               [24] 6331 	movc	a,@a+dptr
      001E85 FE               [12] 6332 	mov	r6,a
      001E86 74 01            [12] 6333 	mov	a,#0x01
      001E88 93               [24] 6334 	movc	a,@a+dptr
      001E89 FF               [12] 6335 	mov	r7,a
      001E8A 90 00 16         [24] 6336 	mov	dptr,#_axradio_txbuffer_cnt
      001E8D EE               [12] 6337 	mov	a,r6
      001E8E F0               [24] 6338 	movx	@dptr,a
      001E8F EF               [12] 6339 	mov	a,r7
      001E90 A3               [24] 6340 	inc	dptr
      001E91 F0               [24] 6341 	movx	@dptr,a
                                   6342 ;	..\COMMON\easyax5043.c:1198: if ((radio_read8(AX5043_REG_MODULATION) & 0x0F) == 9) { // 4-FSK
      001E92 90 40 10         [24] 6343 	mov	dptr,#0x4010
      001E95 E0               [24] 6344 	movx	a,@dptr
      001E96 FF               [12] 6345 	mov	r7,a
      001E97 53 07 0F         [24] 6346 	anl	ar7,#0x0f
      001E9A BF 09 11         [24] 6347 	cjne	r7,#0x09,00201$
                                   6348 ;	..\COMMON\easyax5043.c:1199: radio_write8(AX5043_REG_FIFODATA, (AX5043_FIFOCMD_DATA | (7 << 5)));
                                   6349 ;	..\COMMON\easyax5043.c:1200: radio_write8(AX5043_REG_FIFODATA, 2);  // length (including flags)
                                   6350 ;	..\COMMON\easyax5043.c:1201: radio_write8(AX5043_REG_FIFODATA, 0x01);  // flag PKTSTART -> dibit sync
      001E9D 90 40 29         [24] 6351 	mov	dptr,#0x4029
      001EA0 74 E1            [12] 6352 	mov	a,#0xe1
      001EA2 F0               [24] 6353 	movx	@dptr,a
      001EA3 74 02            [12] 6354 	mov	a,#0x02
      001EA5 F0               [24] 6355 	movx	@dptr,a
      001EA6 14               [12] 6356 	dec	a
      001EA7 F0               [24] 6357 	movx	@dptr,a
                                   6358 ;	..\COMMON\easyax5043.c:1202: radio_write8(AX5043_REG_FIFODATA, 0x11); // dummy byte for forcing dibit sync
      001EA8 90 40 29         [24] 6359 	mov	dptr,#0x4029
      001EAB 74 11            [12] 6360 	mov	a,#0x11
      001EAD F0               [24] 6361 	movx	@dptr,a
      001EAE                       6362 00201$:
                                   6363 ;	..\COMMON\easyax5043.c:1209: wtimer_remove(&axradio_timer);
      001EAE 90 02 9D         [24] 6364 	mov	dptr,#_axradio_timer
      001EB1 12 47 8D         [24] 6365 	lcall	_wtimer_remove
                                   6366 ;	..\COMMON\easyax5043.c:1210: update_timeanchor();
      001EB4 12 0A 7C         [24] 6367 	lcall	_update_timeanchor
                                   6368 ;	..\COMMON\easyax5043.c:1211: radio_write8(AX5043_REG_IRQMASK0, 0x08); // enable fifo free threshold
      001EB7 90 40 07         [24] 6369 	mov	dptr,#0x4007
      001EBA 74 08            [12] 6370 	mov	a,#0x08
      001EBC F0               [24] 6371 	movx	@dptr,a
                                   6372 ;	..\COMMON\easyax5043.c:1212: axradio_sync_addtime(axradio_sync_period);
      001EBD 90 4C D1         [24] 6373 	mov	dptr,#_axradio_sync_period
      001EC0 E4               [12] 6374 	clr	a
      001EC1 93               [24] 6375 	movc	a,@a+dptr
      001EC2 FC               [12] 6376 	mov	r4,a
      001EC3 74 01            [12] 6377 	mov	a,#0x01
      001EC5 93               [24] 6378 	movc	a,@a+dptr
      001EC6 FD               [12] 6379 	mov	r5,a
      001EC7 74 02            [12] 6380 	mov	a,#0x02
      001EC9 93               [24] 6381 	movc	a,@a+dptr
      001ECA FE               [12] 6382 	mov	r6,a
      001ECB 74 03            [12] 6383 	mov	a,#0x03
      001ECD 93               [24] 6384 	movc	a,@a+dptr
      001ECE 8C 82            [24] 6385 	mov	dpl,r4
      001ED0 8D 83            [24] 6386 	mov	dph,r5
      001ED2 8E F0            [24] 6387 	mov	b,r6
      001ED4 12 19 42         [24] 6388 	lcall	_axradio_sync_addtime
                                   6389 ;	..\COMMON\easyax5043.c:1213: axradio_syncstate = syncstate_master_waitack;
      001ED7 90 00 13         [24] 6390 	mov	dptr,#_axradio_syncstate
      001EDA 74 05            [12] 6391 	mov	a,#0x05
      001EDC F0               [24] 6392 	movx	@dptr,a
                                   6393 ;	..\COMMON\easyax5043.c:1214: if (axradio_mode != AXRADIO_MODE_SYNC_ACK_MASTER) {
      001EDD 74 31            [12] 6394 	mov	a,#0x31
      001EDF B5 08 02         [24] 6395 	cjne	a,_axradio_mode,00348$
      001EE2 80 26            [24] 6396 	sjmp	00206$
      001EE4                       6397 00348$:
                                   6398 ;	..\COMMON\easyax5043.c:1215: axradio_syncstate = syncstate_master_normal;
      001EE4 90 00 13         [24] 6399 	mov	dptr,#_axradio_syncstate
      001EE7 74 03            [12] 6400 	mov	a,#0x03
      001EE9 F0               [24] 6401 	movx	@dptr,a
                                   6402 ;	..\COMMON\easyax5043.c:1216: axradio_sync_settimeradv(axradio_sync_xoscstartup);
      001EEA 90 4C D5         [24] 6403 	mov	dptr,#_axradio_sync_xoscstartup
      001EED E4               [12] 6404 	clr	a
      001EEE 93               [24] 6405 	movc	a,@a+dptr
      001EEF FC               [12] 6406 	mov	r4,a
      001EF0 74 01            [12] 6407 	mov	a,#0x01
      001EF2 93               [24] 6408 	movc	a,@a+dptr
      001EF3 FD               [12] 6409 	mov	r5,a
      001EF4 74 02            [12] 6410 	mov	a,#0x02
      001EF6 93               [24] 6411 	movc	a,@a+dptr
      001EF7 FE               [12] 6412 	mov	r6,a
      001EF8 74 03            [12] 6413 	mov	a,#0x03
      001EFA 93               [24] 6414 	movc	a,@a+dptr
      001EFB 8C 82            [24] 6415 	mov	dpl,r4
      001EFD 8D 83            [24] 6416 	mov	dph,r5
      001EFF 8E F0            [24] 6417 	mov	b,r6
      001F01 12 19 93         [24] 6418 	lcall	_axradio_sync_settimeradv
                                   6419 ;	..\COMMON\easyax5043.c:1217: wtimer0_addabsolute(&axradio_timer);
      001F04 90 02 9D         [24] 6420 	mov	dptr,#_axradio_timer
      001F07 12 43 6C         [24] 6421 	lcall	_wtimer0_addabsolute
      001F0A                       6422 00206$:
                                   6423 ;	..\COMMON\easyax5043.c:1219: wtimer_remove_callback(&axradio_cb_transmitstart.cb);
      001F0A 90 02 7F         [24] 6424 	mov	dptr,#_axradio_cb_transmitstart
      001F0D 12 48 82         [24] 6425 	lcall	_wtimer_remove_callback
                                   6426 ;	..\COMMON\easyax5043.c:1220: axradio_cb_transmitstart.st.error = AXRADIO_ERR_NOERROR;
      001F10 90 02 84         [24] 6427 	mov	dptr,#(_axradio_cb_transmitstart + 0x0005)
      001F13 E4               [12] 6428 	clr	a
      001F14 F0               [24] 6429 	movx	@dptr,a
                                   6430 ;	..\COMMON\easyax5043.c:1221: axradio_cb_transmitstart.st.time.t = axradio_timeanchor.radiotimer;
      001F15 90 00 29         [24] 6431 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      001F18 E0               [24] 6432 	movx	a,@dptr
      001F19 FC               [12] 6433 	mov	r4,a
      001F1A A3               [24] 6434 	inc	dptr
      001F1B E0               [24] 6435 	movx	a,@dptr
      001F1C FD               [12] 6436 	mov	r5,a
      001F1D A3               [24] 6437 	inc	dptr
      001F1E E0               [24] 6438 	movx	a,@dptr
      001F1F FE               [12] 6439 	mov	r6,a
      001F20 A3               [24] 6440 	inc	dptr
      001F21 E0               [24] 6441 	movx	a,@dptr
      001F22 FF               [12] 6442 	mov	r7,a
      001F23 90 02 85         [24] 6443 	mov	dptr,#(_axradio_cb_transmitstart + 0x0006)
      001F26 EC               [12] 6444 	mov	a,r4
      001F27 F0               [24] 6445 	movx	@dptr,a
      001F28 ED               [12] 6446 	mov	a,r5
      001F29 A3               [24] 6447 	inc	dptr
      001F2A F0               [24] 6448 	movx	@dptr,a
      001F2B EE               [12] 6449 	mov	a,r6
      001F2C A3               [24] 6450 	inc	dptr
      001F2D F0               [24] 6451 	movx	@dptr,a
      001F2E EF               [12] 6452 	mov	a,r7
      001F2F A3               [24] 6453 	inc	dptr
      001F30 F0               [24] 6454 	movx	@dptr,a
                                   6455 ;	..\COMMON\easyax5043.c:1222: wtimer_add_callback(&axradio_cb_transmitstart.cb);
      001F31 90 02 7F         [24] 6456 	mov	dptr,#_axradio_cb_transmitstart
                                   6457 ;	..\COMMON\easyax5043.c:1223: break;
      001F34 02 42 C4         [24] 6458 	ljmp	_wtimer_add_callback
                                   6459 ;	..\COMMON\easyax5043.c:1225: case syncstate_master_waitack:
      001F37                       6460 00207$:
                                   6461 ;	..\COMMON\easyax5043.c:1226: ax5043_off();
      001F37 12 17 8A         [24] 6462 	lcall	_ax5043_off
                                   6463 ;	..\COMMON\easyax5043.c:1227: axradio_syncstate = syncstate_master_normal;
      001F3A 90 00 13         [24] 6464 	mov	dptr,#_axradio_syncstate
      001F3D 74 03            [12] 6465 	mov	a,#0x03
      001F3F F0               [24] 6466 	movx	@dptr,a
                                   6467 ;	..\COMMON\easyax5043.c:1228: wtimer_remove(&axradio_timer);
      001F40 90 02 9D         [24] 6468 	mov	dptr,#_axradio_timer
      001F43 12 47 8D         [24] 6469 	lcall	_wtimer_remove
                                   6470 ;	..\COMMON\easyax5043.c:1229: axradio_sync_settimeradv(axradio_sync_xoscstartup);
      001F46 90 4C D5         [24] 6471 	mov	dptr,#_axradio_sync_xoscstartup
      001F49 E4               [12] 6472 	clr	a
      001F4A 93               [24] 6473 	movc	a,@a+dptr
      001F4B FC               [12] 6474 	mov	r4,a
      001F4C 74 01            [12] 6475 	mov	a,#0x01
      001F4E 93               [24] 6476 	movc	a,@a+dptr
      001F4F FD               [12] 6477 	mov	r5,a
      001F50 74 02            [12] 6478 	mov	a,#0x02
      001F52 93               [24] 6479 	movc	a,@a+dptr
      001F53 FE               [12] 6480 	mov	r6,a
      001F54 74 03            [12] 6481 	mov	a,#0x03
      001F56 93               [24] 6482 	movc	a,@a+dptr
      001F57 8C 82            [24] 6483 	mov	dpl,r4
      001F59 8D 83            [24] 6484 	mov	dph,r5
      001F5B 8E F0            [24] 6485 	mov	b,r6
      001F5D 12 19 93         [24] 6486 	lcall	_axradio_sync_settimeradv
                                   6487 ;	..\COMMON\easyax5043.c:1230: wtimer0_addabsolute(&axradio_timer);
      001F60 90 02 9D         [24] 6488 	mov	dptr,#_axradio_timer
      001F63 12 43 6C         [24] 6489 	lcall	_wtimer0_addabsolute
                                   6490 ;	..\COMMON\easyax5043.c:1231: update_timeanchor();
      001F66 12 0A 7C         [24] 6491 	lcall	_update_timeanchor
                                   6492 ;	..\COMMON\easyax5043.c:1232: wtimer_remove_callback(&axradio_cb_transmitend.cb);
      001F69 90 02 89         [24] 6493 	mov	dptr,#_axradio_cb_transmitend
      001F6C 12 48 82         [24] 6494 	lcall	_wtimer_remove_callback
                                   6495 ;	..\COMMON\easyax5043.c:1233: axradio_cb_transmitend.st.error = AXRADIO_ERR_TIMEOUT;
      001F6F 90 02 8E         [24] 6496 	mov	dptr,#(_axradio_cb_transmitend + 0x0005)
      001F72 74 03            [12] 6497 	mov	a,#0x03
      001F74 F0               [24] 6498 	movx	@dptr,a
                                   6499 ;	..\COMMON\easyax5043.c:1234: axradio_cb_transmitend.st.time.t = axradio_timeanchor.radiotimer;
      001F75 90 00 29         [24] 6500 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      001F78 E0               [24] 6501 	movx	a,@dptr
      001F79 FC               [12] 6502 	mov	r4,a
      001F7A A3               [24] 6503 	inc	dptr
      001F7B E0               [24] 6504 	movx	a,@dptr
      001F7C FD               [12] 6505 	mov	r5,a
      001F7D A3               [24] 6506 	inc	dptr
      001F7E E0               [24] 6507 	movx	a,@dptr
      001F7F FE               [12] 6508 	mov	r6,a
      001F80 A3               [24] 6509 	inc	dptr
      001F81 E0               [24] 6510 	movx	a,@dptr
      001F82 FF               [12] 6511 	mov	r7,a
      001F83 90 02 8F         [24] 6512 	mov	dptr,#(_axradio_cb_transmitend + 0x0006)
      001F86 EC               [12] 6513 	mov	a,r4
      001F87 F0               [24] 6514 	movx	@dptr,a
      001F88 ED               [12] 6515 	mov	a,r5
      001F89 A3               [24] 6516 	inc	dptr
      001F8A F0               [24] 6517 	movx	@dptr,a
      001F8B EE               [12] 6518 	mov	a,r6
      001F8C A3               [24] 6519 	inc	dptr
      001F8D F0               [24] 6520 	movx	@dptr,a
      001F8E EF               [12] 6521 	mov	a,r7
      001F8F A3               [24] 6522 	inc	dptr
      001F90 F0               [24] 6523 	movx	@dptr,a
                                   6524 ;	..\COMMON\easyax5043.c:1235: wtimer_add_callback(&axradio_cb_transmitend.cb);
      001F91 90 02 89         [24] 6525 	mov	dptr,#_axradio_cb_transmitend
                                   6526 ;	..\COMMON\easyax5043.c:1238: break;
      001F94 02 42 C4         [24] 6527 	ljmp	_wtimer_add_callback
                                   6528 ;	..\COMMON\easyax5043.c:1240: case AXRADIO_MODE_SYNC_SLAVE:
      001F97                       6529 00209$:
                                   6530 ;	..\COMMON\easyax5043.c:1241: case AXRADIO_MODE_SYNC_ACK_SLAVE:
      001F97                       6531 00210$:
                                   6532 ;	..\COMMON\easyax5043.c:1242: switch (axradio_syncstate) {
      001F97 90 00 13         [24] 6533 	mov	dptr,#_axradio_syncstate
      001F9A E0               [24] 6534 	movx	a,@dptr
      001F9B FF               [12] 6535 	mov  r7,a
      001F9C 24 F3            [12] 6536 	add	a,#0xff - 0x0c
      001F9E 50 03            [24] 6537 	jnc	00349$
      001FA0 02 1F CE         [24] 6538 	ljmp	00212$
      001FA3                       6539 00349$:
      001FA3 EF               [12] 6540 	mov	a,r7
      001FA4 F5 F0            [12] 6541 	mov	b,a
      001FA6 24 0B            [12] 6542 	add	a,#(00350$-3-.)
      001FA8 83               [24] 6543 	movc	a,@a+pc
      001FA9 F5 82            [12] 6544 	mov	dpl,a
      001FAB E5 F0            [12] 6545 	mov	a,b
      001FAD 24 11            [12] 6546 	add	a,#(00351$-3-.)
      001FAF 83               [24] 6547 	movc	a,@a+pc
      001FB0 F5 83            [12] 6548 	mov	dph,a
      001FB2 E4               [12] 6549 	clr	a
      001FB3 73               [24] 6550 	jmp	@a+dptr
      001FB4                       6551 00350$:
      001FB4 CE                    6552 	.db	00211$
      001FB5 CE                    6553 	.db	00211$
      001FB6 CE                    6554 	.db	00211$
      001FB7 CE                    6555 	.db	00211$
      001FB8 CE                    6556 	.db	00211$
      001FB9 CE                    6557 	.db	00211$
      001FBA CE                    6558 	.db	00212$
      001FBB 59                    6559 	.db	00213$
      001FBC E7                    6560 	.db	00214$
      001FBD 39                    6561 	.db	00218$
      001FBE EA                    6562 	.db	00221$
      001FBF 48                    6563 	.db	00226$
      001FC0 5C                    6564 	.db	00233$
      001FC1                       6565 00351$:
      001FC1 1F                    6566 	.db	00211$>>8
      001FC2 1F                    6567 	.db	00211$>>8
      001FC3 1F                    6568 	.db	00211$>>8
      001FC4 1F                    6569 	.db	00211$>>8
      001FC5 1F                    6570 	.db	00211$>>8
      001FC6 1F                    6571 	.db	00211$>>8
      001FC7 1F                    6572 	.db	00212$>>8
      001FC8 20                    6573 	.db	00213$>>8
      001FC9 20                    6574 	.db	00214$>>8
      001FCA 21                    6575 	.db	00218$>>8
      001FCB 21                    6576 	.db	00221$>>8
      001FCC 22                    6577 	.db	00226$>>8
      001FCD 23                    6578 	.db	00233$>>8
                                   6579 ;	..\COMMON\easyax5043.c:1243: default:
      001FCE                       6580 00211$:
                                   6581 ;	..\COMMON\easyax5043.c:1244: case syncstate_slave_synchunt:
      001FCE                       6582 00212$:
                                   6583 ;	..\COMMON\easyax5043.c:1245: ax5043_off();
      001FCE 12 17 8A         [24] 6584 	lcall	_ax5043_off
                                   6585 ;	..\COMMON\easyax5043.c:1246: axradio_syncstate = syncstate_slave_syncpause;
      001FD1 90 00 13         [24] 6586 	mov	dptr,#_axradio_syncstate
      001FD4 74 07            [12] 6587 	mov	a,#0x07
      001FD6 F0               [24] 6588 	movx	@dptr,a
                                   6589 ;	..\COMMON\easyax5043.c:1247: axradio_sync_addtime(axradio_sync_slave_syncpause);
      001FD7 90 4C E1         [24] 6590 	mov	dptr,#_axradio_sync_slave_syncpause
      001FDA E4               [12] 6591 	clr	a
      001FDB 93               [24] 6592 	movc	a,@a+dptr
      001FDC FC               [12] 6593 	mov	r4,a
      001FDD 74 01            [12] 6594 	mov	a,#0x01
      001FDF 93               [24] 6595 	movc	a,@a+dptr
      001FE0 FD               [12] 6596 	mov	r5,a
      001FE1 74 02            [12] 6597 	mov	a,#0x02
      001FE3 93               [24] 6598 	movc	a,@a+dptr
      001FE4 FE               [12] 6599 	mov	r6,a
      001FE5 74 03            [12] 6600 	mov	a,#0x03
      001FE7 93               [24] 6601 	movc	a,@a+dptr
      001FE8 8C 82            [24] 6602 	mov	dpl,r4
      001FEA 8D 83            [24] 6603 	mov	dph,r5
      001FEC 8E F0            [24] 6604 	mov	b,r6
      001FEE 12 19 42         [24] 6605 	lcall	_axradio_sync_addtime
                                   6606 ;	..\COMMON\easyax5043.c:1248: wtimer_remove(&axradio_timer);
      001FF1 90 02 9D         [24] 6607 	mov	dptr,#_axradio_timer
      001FF4 12 47 8D         [24] 6608 	lcall	_wtimer_remove
                                   6609 ;	..\COMMON\easyax5043.c:1249: axradio_timer.time = axradio_sync_time;
      001FF7 90 00 1F         [24] 6610 	mov	dptr,#_axradio_sync_time
      001FFA E0               [24] 6611 	movx	a,@dptr
      001FFB FC               [12] 6612 	mov	r4,a
      001FFC A3               [24] 6613 	inc	dptr
      001FFD E0               [24] 6614 	movx	a,@dptr
      001FFE FD               [12] 6615 	mov	r5,a
      001FFF A3               [24] 6616 	inc	dptr
      002000 E0               [24] 6617 	movx	a,@dptr
      002001 FE               [12] 6618 	mov	r6,a
      002002 A3               [24] 6619 	inc	dptr
      002003 E0               [24] 6620 	movx	a,@dptr
      002004 FF               [12] 6621 	mov	r7,a
      002005 90 02 A1         [24] 6622 	mov	dptr,#(_axradio_timer + 0x0004)
      002008 EC               [12] 6623 	mov	a,r4
      002009 F0               [24] 6624 	movx	@dptr,a
      00200A ED               [12] 6625 	mov	a,r5
      00200B A3               [24] 6626 	inc	dptr
      00200C F0               [24] 6627 	movx	@dptr,a
      00200D EE               [12] 6628 	mov	a,r6
      00200E A3               [24] 6629 	inc	dptr
      00200F F0               [24] 6630 	movx	@dptr,a
      002010 EF               [12] 6631 	mov	a,r7
      002011 A3               [24] 6632 	inc	dptr
      002012 F0               [24] 6633 	movx	@dptr,a
                                   6634 ;	..\COMMON\easyax5043.c:1250: wtimer0_addabsolute(&axradio_timer);
      002013 90 02 9D         [24] 6635 	mov	dptr,#_axradio_timer
      002016 12 43 6C         [24] 6636 	lcall	_wtimer0_addabsolute
                                   6637 ;	..\COMMON\easyax5043.c:1251: wtimer_remove_callback(&axradio_cb_receive.cb);
      002019 90 02 44         [24] 6638 	mov	dptr,#_axradio_cb_receive
      00201C 12 48 82         [24] 6639 	lcall	_wtimer_remove_callback
                                   6640 ;	..\COMMON\easyax5043.c:1252: memset_xdata(&axradio_cb_receive.st, 0, sizeof(axradio_cb_receive.st));
      00201F 75 2E 00         [24] 6641 	mov	_memset_PARM_2,#0x00
      002022 75 2F 20         [24] 6642 	mov	_memset_PARM_3,#0x20
      002025 75 30 00         [24] 6643 	mov	(_memset_PARM_3 + 1),#0x00
      002028 90 02 48         [24] 6644 	mov	dptr,#(_axradio_cb_receive + 0x0004)
      00202B 75 F0 00         [24] 6645 	mov	b,#0x00
      00202E 12 42 50         [24] 6646 	lcall	_memset
                                   6647 ;	..\COMMON\easyax5043.c:1253: axradio_cb_receive.st.time.t = axradio_timeanchor.radiotimer;
      002031 90 00 29         [24] 6648 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      002034 E0               [24] 6649 	movx	a,@dptr
      002035 FC               [12] 6650 	mov	r4,a
      002036 A3               [24] 6651 	inc	dptr
      002037 E0               [24] 6652 	movx	a,@dptr
      002038 FD               [12] 6653 	mov	r5,a
      002039 A3               [24] 6654 	inc	dptr
      00203A E0               [24] 6655 	movx	a,@dptr
      00203B FE               [12] 6656 	mov	r6,a
      00203C A3               [24] 6657 	inc	dptr
      00203D E0               [24] 6658 	movx	a,@dptr
      00203E FF               [12] 6659 	mov	r7,a
      00203F 90 02 4A         [24] 6660 	mov	dptr,#(_axradio_cb_receive + 0x0006)
      002042 EC               [12] 6661 	mov	a,r4
      002043 F0               [24] 6662 	movx	@dptr,a
      002044 ED               [12] 6663 	mov	a,r5
      002045 A3               [24] 6664 	inc	dptr
      002046 F0               [24] 6665 	movx	@dptr,a
      002047 EE               [12] 6666 	mov	a,r6
      002048 A3               [24] 6667 	inc	dptr
      002049 F0               [24] 6668 	movx	@dptr,a
      00204A EF               [12] 6669 	mov	a,r7
      00204B A3               [24] 6670 	inc	dptr
      00204C F0               [24] 6671 	movx	@dptr,a
                                   6672 ;	..\COMMON\easyax5043.c:1254: axradio_cb_receive.st.error = AXRADIO_ERR_RESYNCTIMEOUT;
      00204D 90 02 49         [24] 6673 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      002050 74 0A            [12] 6674 	mov	a,#0x0a
      002052 F0               [24] 6675 	movx	@dptr,a
                                   6676 ;	..\COMMON\easyax5043.c:1255: wtimer_add_callback(&axradio_cb_receive.cb);
      002053 90 02 44         [24] 6677 	mov	dptr,#_axradio_cb_receive
                                   6678 ;	..\COMMON\easyax5043.c:1256: break;
      002056 02 42 C4         [24] 6679 	ljmp	_wtimer_add_callback
                                   6680 ;	..\COMMON\easyax5043.c:1258: case syncstate_slave_syncpause:
      002059                       6681 00213$:
                                   6682 ;	..\COMMON\easyax5043.c:1259: ax5043_receiver_on_continuous();
      002059 12 16 3B         [24] 6683 	lcall	_ax5043_receiver_on_continuous
                                   6684 ;	..\COMMON\easyax5043.c:1260: axradio_syncstate = syncstate_slave_synchunt;
      00205C 90 00 13         [24] 6685 	mov	dptr,#_axradio_syncstate
      00205F 74 06            [12] 6686 	mov	a,#0x06
      002061 F0               [24] 6687 	movx	@dptr,a
                                   6688 ;	..\COMMON\easyax5043.c:1261: axradio_sync_addtime(axradio_sync_slave_syncwindow);
      002062 90 4C D9         [24] 6689 	mov	dptr,#_axradio_sync_slave_syncwindow
      002065 E4               [12] 6690 	clr	a
      002066 93               [24] 6691 	movc	a,@a+dptr
      002067 FC               [12] 6692 	mov	r4,a
      002068 74 01            [12] 6693 	mov	a,#0x01
      00206A 93               [24] 6694 	movc	a,@a+dptr
      00206B FD               [12] 6695 	mov	r5,a
      00206C 74 02            [12] 6696 	mov	a,#0x02
      00206E 93               [24] 6697 	movc	a,@a+dptr
      00206F FE               [12] 6698 	mov	r6,a
      002070 74 03            [12] 6699 	mov	a,#0x03
      002072 93               [24] 6700 	movc	a,@a+dptr
      002073 8C 82            [24] 6701 	mov	dpl,r4
      002075 8D 83            [24] 6702 	mov	dph,r5
      002077 8E F0            [24] 6703 	mov	b,r6
      002079 12 19 42         [24] 6704 	lcall	_axradio_sync_addtime
                                   6705 ;	..\COMMON\easyax5043.c:1262: wtimer_remove(&axradio_timer);
      00207C 90 02 9D         [24] 6706 	mov	dptr,#_axradio_timer
      00207F 12 47 8D         [24] 6707 	lcall	_wtimer_remove
                                   6708 ;	..\COMMON\easyax5043.c:1263: axradio_timer.time = axradio_sync_time;
      002082 90 00 1F         [24] 6709 	mov	dptr,#_axradio_sync_time
      002085 E0               [24] 6710 	movx	a,@dptr
      002086 FC               [12] 6711 	mov	r4,a
      002087 A3               [24] 6712 	inc	dptr
      002088 E0               [24] 6713 	movx	a,@dptr
      002089 FD               [12] 6714 	mov	r5,a
      00208A A3               [24] 6715 	inc	dptr
      00208B E0               [24] 6716 	movx	a,@dptr
      00208C FE               [12] 6717 	mov	r6,a
      00208D A3               [24] 6718 	inc	dptr
      00208E E0               [24] 6719 	movx	a,@dptr
      00208F FF               [12] 6720 	mov	r7,a
      002090 90 02 A1         [24] 6721 	mov	dptr,#(_axradio_timer + 0x0004)
      002093 EC               [12] 6722 	mov	a,r4
      002094 F0               [24] 6723 	movx	@dptr,a
      002095 ED               [12] 6724 	mov	a,r5
      002096 A3               [24] 6725 	inc	dptr
      002097 F0               [24] 6726 	movx	@dptr,a
      002098 EE               [12] 6727 	mov	a,r6
      002099 A3               [24] 6728 	inc	dptr
      00209A F0               [24] 6729 	movx	@dptr,a
      00209B EF               [12] 6730 	mov	a,r7
      00209C A3               [24] 6731 	inc	dptr
      00209D F0               [24] 6732 	movx	@dptr,a
                                   6733 ;	..\COMMON\easyax5043.c:1264: wtimer0_addabsolute(&axradio_timer);
      00209E 90 02 9D         [24] 6734 	mov	dptr,#_axradio_timer
      0020A1 12 43 6C         [24] 6735 	lcall	_wtimer0_addabsolute
                                   6736 ;	..\COMMON\easyax5043.c:1265: update_timeanchor();
      0020A4 12 0A 7C         [24] 6737 	lcall	_update_timeanchor
                                   6738 ;	..\COMMON\easyax5043.c:1266: wtimer_remove_callback(&axradio_cb_receive.cb);
      0020A7 90 02 44         [24] 6739 	mov	dptr,#_axradio_cb_receive
      0020AA 12 48 82         [24] 6740 	lcall	_wtimer_remove_callback
                                   6741 ;	..\COMMON\easyax5043.c:1267: memset_xdata(&axradio_cb_receive.st, 0, sizeof(axradio_cb_receive.st));
      0020AD 75 2E 00         [24] 6742 	mov	_memset_PARM_2,#0x00
      0020B0 75 2F 20         [24] 6743 	mov	_memset_PARM_3,#0x20
      0020B3 75 30 00         [24] 6744 	mov	(_memset_PARM_3 + 1),#0x00
      0020B6 90 02 48         [24] 6745 	mov	dptr,#(_axradio_cb_receive + 0x0004)
      0020B9 75 F0 00         [24] 6746 	mov	b,#0x00
      0020BC 12 42 50         [24] 6747 	lcall	_memset
                                   6748 ;	..\COMMON\easyax5043.c:1268: axradio_cb_receive.st.time.t = axradio_timeanchor.radiotimer;
      0020BF 90 00 29         [24] 6749 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      0020C2 E0               [24] 6750 	movx	a,@dptr
      0020C3 FC               [12] 6751 	mov	r4,a
      0020C4 A3               [24] 6752 	inc	dptr
      0020C5 E0               [24] 6753 	movx	a,@dptr
      0020C6 FD               [12] 6754 	mov	r5,a
      0020C7 A3               [24] 6755 	inc	dptr
      0020C8 E0               [24] 6756 	movx	a,@dptr
      0020C9 FE               [12] 6757 	mov	r6,a
      0020CA A3               [24] 6758 	inc	dptr
      0020CB E0               [24] 6759 	movx	a,@dptr
      0020CC FF               [12] 6760 	mov	r7,a
      0020CD 90 02 4A         [24] 6761 	mov	dptr,#(_axradio_cb_receive + 0x0006)
      0020D0 EC               [12] 6762 	mov	a,r4
      0020D1 F0               [24] 6763 	movx	@dptr,a
      0020D2 ED               [12] 6764 	mov	a,r5
      0020D3 A3               [24] 6765 	inc	dptr
      0020D4 F0               [24] 6766 	movx	@dptr,a
      0020D5 EE               [12] 6767 	mov	a,r6
      0020D6 A3               [24] 6768 	inc	dptr
      0020D7 F0               [24] 6769 	movx	@dptr,a
      0020D8 EF               [12] 6770 	mov	a,r7
      0020D9 A3               [24] 6771 	inc	dptr
      0020DA F0               [24] 6772 	movx	@dptr,a
                                   6773 ;	..\COMMON\easyax5043.c:1269: axradio_cb_receive.st.error = AXRADIO_ERR_RESYNC;
      0020DB 90 02 49         [24] 6774 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      0020DE 74 09            [12] 6775 	mov	a,#0x09
      0020E0 F0               [24] 6776 	movx	@dptr,a
                                   6777 ;	..\COMMON\easyax5043.c:1270: wtimer_add_callback(&axradio_cb_receive.cb);
      0020E1 90 02 44         [24] 6778 	mov	dptr,#_axradio_cb_receive
                                   6779 ;	..\COMMON\easyax5043.c:1271: break;
      0020E4 02 42 C4         [24] 6780 	ljmp	_wtimer_add_callback
                                   6781 ;	..\COMMON\easyax5043.c:1273: case syncstate_slave_rxidle:
      0020E7                       6782 00214$:
                                   6783 ;	..\COMMON\easyax5043.c:1274: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_XTAL_ON);
      0020E7 90 40 02         [24] 6784 	mov	dptr,#0x4002
      0020EA 74 05            [12] 6785 	mov	a,#0x05
      0020EC F0               [24] 6786 	movx	@dptr,a
                                   6787 ;	..\COMMON\easyax5043.c:1275: axradio_syncstate = syncstate_slave_rxxosc;
      0020ED 90 00 13         [24] 6788 	mov	dptr,#_axradio_syncstate
      0020F0 74 09            [12] 6789 	mov	a,#0x09
      0020F2 F0               [24] 6790 	movx	@dptr,a
                                   6791 ;	..\COMMON\easyax5043.c:1276: wtimer_remove(&axradio_timer);
      0020F3 90 02 9D         [24] 6792 	mov	dptr,#_axradio_timer
      0020F6 12 47 8D         [24] 6793 	lcall	_wtimer_remove
                                   6794 ;	..\COMMON\easyax5043.c:1277: axradio_timer.time += axradio_sync_xoscstartup;
      0020F9 90 02 A1         [24] 6795 	mov	dptr,#(_axradio_timer + 0x0004)
      0020FC E0               [24] 6796 	movx	a,@dptr
      0020FD FC               [12] 6797 	mov	r4,a
      0020FE A3               [24] 6798 	inc	dptr
      0020FF E0               [24] 6799 	movx	a,@dptr
      002100 FD               [12] 6800 	mov	r5,a
      002101 A3               [24] 6801 	inc	dptr
      002102 E0               [24] 6802 	movx	a,@dptr
      002103 FE               [12] 6803 	mov	r6,a
      002104 A3               [24] 6804 	inc	dptr
      002105 E0               [24] 6805 	movx	a,@dptr
      002106 FF               [12] 6806 	mov	r7,a
      002107 90 4C D5         [24] 6807 	mov	dptr,#_axradio_sync_xoscstartup
      00210A E4               [12] 6808 	clr	a
      00210B 93               [24] 6809 	movc	a,@a+dptr
      00210C F8               [12] 6810 	mov	r0,a
      00210D 74 01            [12] 6811 	mov	a,#0x01
      00210F 93               [24] 6812 	movc	a,@a+dptr
      002110 F9               [12] 6813 	mov	r1,a
      002111 74 02            [12] 6814 	mov	a,#0x02
      002113 93               [24] 6815 	movc	a,@a+dptr
      002114 FA               [12] 6816 	mov	r2,a
      002115 74 03            [12] 6817 	mov	a,#0x03
      002117 93               [24] 6818 	movc	a,@a+dptr
      002118 FB               [12] 6819 	mov	r3,a
      002119 E8               [12] 6820 	mov	a,r0
      00211A 2C               [12] 6821 	add	a,r4
      00211B FC               [12] 6822 	mov	r4,a
      00211C E9               [12] 6823 	mov	a,r1
      00211D 3D               [12] 6824 	addc	a,r5
      00211E FD               [12] 6825 	mov	r5,a
      00211F EA               [12] 6826 	mov	a,r2
      002120 3E               [12] 6827 	addc	a,r6
      002121 FE               [12] 6828 	mov	r6,a
      002122 EB               [12] 6829 	mov	a,r3
      002123 3F               [12] 6830 	addc	a,r7
      002124 FF               [12] 6831 	mov	r7,a
      002125 90 02 A1         [24] 6832 	mov	dptr,#(_axradio_timer + 0x0004)
      002128 EC               [12] 6833 	mov	a,r4
      002129 F0               [24] 6834 	movx	@dptr,a
      00212A ED               [12] 6835 	mov	a,r5
      00212B A3               [24] 6836 	inc	dptr
      00212C F0               [24] 6837 	movx	@dptr,a
      00212D EE               [12] 6838 	mov	a,r6
      00212E A3               [24] 6839 	inc	dptr
      00212F F0               [24] 6840 	movx	@dptr,a
      002130 EF               [12] 6841 	mov	a,r7
      002131 A3               [24] 6842 	inc	dptr
      002132 F0               [24] 6843 	movx	@dptr,a
                                   6844 ;	..\COMMON\easyax5043.c:1278: wtimer0_addabsolute(&axradio_timer);
      002133 90 02 9D         [24] 6845 	mov	dptr,#_axradio_timer
                                   6846 ;	..\COMMON\easyax5043.c:1279: break;
      002136 02 43 6C         [24] 6847 	ljmp	_wtimer0_addabsolute
                                   6848 ;	..\COMMON\easyax5043.c:1281: case syncstate_slave_rxxosc:
      002139                       6849 00218$:
                                   6850 ;	..\COMMON\easyax5043.c:1282: ax5043_receiver_on_continuous();
      002139 12 16 3B         [24] 6851 	lcall	_ax5043_receiver_on_continuous
                                   6852 ;	..\COMMON\easyax5043.c:1283: axradio_syncstate = syncstate_slave_rxsfdwindow;
      00213C 90 00 13         [24] 6853 	mov	dptr,#_axradio_syncstate
      00213F 74 0A            [12] 6854 	mov	a,#0x0a
      002141 F0               [24] 6855 	movx	@dptr,a
                                   6856 ;	..\COMMON\easyax5043.c:1284: update_timeanchor();
      002142 12 0A 7C         [24] 6857 	lcall	_update_timeanchor
                                   6858 ;	..\COMMON\easyax5043.c:1285: wtimer_remove_callback(&axradio_cb_receive.cb);
      002145 90 02 44         [24] 6859 	mov	dptr,#_axradio_cb_receive
      002148 12 48 82         [24] 6860 	lcall	_wtimer_remove_callback
                                   6861 ;	..\COMMON\easyax5043.c:1286: memset_xdata(&axradio_cb_receive.st, 0, sizeof(axradio_cb_receive.st));
      00214B 75 2E 00         [24] 6862 	mov	_memset_PARM_2,#0x00
      00214E 75 2F 20         [24] 6863 	mov	_memset_PARM_3,#0x20
      002151 75 30 00         [24] 6864 	mov	(_memset_PARM_3 + 1),#0x00
      002154 90 02 48         [24] 6865 	mov	dptr,#(_axradio_cb_receive + 0x0004)
      002157 75 F0 00         [24] 6866 	mov	b,#0x00
      00215A 12 42 50         [24] 6867 	lcall	_memset
                                   6868 ;	..\COMMON\easyax5043.c:1287: axradio_cb_receive.st.time.t = axradio_timeanchor.radiotimer;
      00215D 90 00 29         [24] 6869 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      002160 E0               [24] 6870 	movx	a,@dptr
      002161 FC               [12] 6871 	mov	r4,a
      002162 A3               [24] 6872 	inc	dptr
      002163 E0               [24] 6873 	movx	a,@dptr
      002164 FD               [12] 6874 	mov	r5,a
      002165 A3               [24] 6875 	inc	dptr
      002166 E0               [24] 6876 	movx	a,@dptr
      002167 FE               [12] 6877 	mov	r6,a
      002168 A3               [24] 6878 	inc	dptr
      002169 E0               [24] 6879 	movx	a,@dptr
      00216A FF               [12] 6880 	mov	r7,a
      00216B 90 02 4A         [24] 6881 	mov	dptr,#(_axradio_cb_receive + 0x0006)
      00216E EC               [12] 6882 	mov	a,r4
      00216F F0               [24] 6883 	movx	@dptr,a
      002170 ED               [12] 6884 	mov	a,r5
      002171 A3               [24] 6885 	inc	dptr
      002172 F0               [24] 6886 	movx	@dptr,a
      002173 EE               [12] 6887 	mov	a,r6
      002174 A3               [24] 6888 	inc	dptr
      002175 F0               [24] 6889 	movx	@dptr,a
      002176 EF               [12] 6890 	mov	a,r7
      002177 A3               [24] 6891 	inc	dptr
      002178 F0               [24] 6892 	movx	@dptr,a
                                   6893 ;	..\COMMON\easyax5043.c:1288: axradio_cb_receive.st.error = AXRADIO_ERR_RECEIVESTART;
      002179 90 02 49         [24] 6894 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      00217C 74 0B            [12] 6895 	mov	a,#0x0b
      00217E F0               [24] 6896 	movx	@dptr,a
                                   6897 ;	..\COMMON\easyax5043.c:1289: wtimer_add_callback(&axradio_cb_receive.cb);
      00217F 90 02 44         [24] 6898 	mov	dptr,#_axradio_cb_receive
      002182 12 42 C4         [24] 6899 	lcall	_wtimer_add_callback
                                   6900 ;	..\COMMON\easyax5043.c:1290: wtimer_remove(&axradio_timer);
      002185 90 02 9D         [24] 6901 	mov	dptr,#_axradio_timer
      002188 12 47 8D         [24] 6902 	lcall	_wtimer_remove
                                   6903 ;	..\COMMON\easyax5043.c:1292: uint8_t __autodata idx = axradio_sync_seqnr;
      00218B 90 00 1E         [24] 6904 	mov	dptr,#_axradio_ack_seqnr
      00218E E0               [24] 6905 	movx	a,@dptr
      00218F FF               [12] 6906 	mov	r7,a
                                   6907 ;	..\COMMON\easyax5043.c:1293: if (idx >= axradio_sync_slave_nrrx)
      002190 90 4C E8         [24] 6908 	mov	dptr,#_axradio_sync_slave_nrrx
      002193 E4               [12] 6909 	clr	a
      002194 93               [24] 6910 	movc	a,@a+dptr
      002195 FE               [12] 6911 	mov	r6,a
      002196 C3               [12] 6912 	clr	c
      002197 EF               [12] 6913 	mov	a,r7
      002198 9E               [12] 6914 	subb	a,r6
      002199 40 03            [24] 6915 	jc	00220$
                                   6916 ;	..\COMMON\easyax5043.c:1294: idx = axradio_sync_slave_nrrx - 1;
      00219B EE               [12] 6917 	mov	a,r6
      00219C 14               [12] 6918 	dec	a
      00219D FF               [12] 6919 	mov	r7,a
      00219E                       6920 00220$:
                                   6921 ;	..\COMMON\easyax5043.c:1295: axradio_timer.time += axradio_sync_slave_rxwindow[idx];
      00219E 90 02 A1         [24] 6922 	mov	dptr,#(_axradio_timer + 0x0004)
      0021A1 E0               [24] 6923 	movx	a,@dptr
      0021A2 FB               [12] 6924 	mov	r3,a
      0021A3 A3               [24] 6925 	inc	dptr
      0021A4 E0               [24] 6926 	movx	a,@dptr
      0021A5 FC               [12] 6927 	mov	r4,a
      0021A6 A3               [24] 6928 	inc	dptr
      0021A7 E0               [24] 6929 	movx	a,@dptr
      0021A8 FD               [12] 6930 	mov	r5,a
      0021A9 A3               [24] 6931 	inc	dptr
      0021AA E0               [24] 6932 	movx	a,@dptr
      0021AB FE               [12] 6933 	mov	r6,a
      0021AC EF               [12] 6934 	mov	a,r7
      0021AD 75 F0 04         [24] 6935 	mov	b,#0x04
      0021B0 A4               [48] 6936 	mul	ab
      0021B1 24 F5            [12] 6937 	add	a,#_axradio_sync_slave_rxwindow
      0021B3 F5 82            [12] 6938 	mov	dpl,a
      0021B5 74 4C            [12] 6939 	mov	a,#(_axradio_sync_slave_rxwindow >> 8)
      0021B7 35 F0            [12] 6940 	addc	a,b
      0021B9 F5 83            [12] 6941 	mov	dph,a
      0021BB E4               [12] 6942 	clr	a
      0021BC 93               [24] 6943 	movc	a,@a+dptr
      0021BD F8               [12] 6944 	mov	r0,a
      0021BE A3               [24] 6945 	inc	dptr
      0021BF E4               [12] 6946 	clr	a
      0021C0 93               [24] 6947 	movc	a,@a+dptr
      0021C1 F9               [12] 6948 	mov	r1,a
      0021C2 A3               [24] 6949 	inc	dptr
      0021C3 E4               [12] 6950 	clr	a
      0021C4 93               [24] 6951 	movc	a,@a+dptr
      0021C5 FA               [12] 6952 	mov	r2,a
      0021C6 A3               [24] 6953 	inc	dptr
      0021C7 E4               [12] 6954 	clr	a
      0021C8 93               [24] 6955 	movc	a,@a+dptr
      0021C9 FF               [12] 6956 	mov	r7,a
      0021CA E8               [12] 6957 	mov	a,r0
      0021CB 2B               [12] 6958 	add	a,r3
      0021CC FB               [12] 6959 	mov	r3,a
      0021CD E9               [12] 6960 	mov	a,r1
      0021CE 3C               [12] 6961 	addc	a,r4
      0021CF FC               [12] 6962 	mov	r4,a
      0021D0 EA               [12] 6963 	mov	a,r2
      0021D1 3D               [12] 6964 	addc	a,r5
      0021D2 FD               [12] 6965 	mov	r5,a
      0021D3 EF               [12] 6966 	mov	a,r7
      0021D4 3E               [12] 6967 	addc	a,r6
      0021D5 FE               [12] 6968 	mov	r6,a
      0021D6 90 02 A1         [24] 6969 	mov	dptr,#(_axradio_timer + 0x0004)
      0021D9 EB               [12] 6970 	mov	a,r3
      0021DA F0               [24] 6971 	movx	@dptr,a
      0021DB EC               [12] 6972 	mov	a,r4
      0021DC A3               [24] 6973 	inc	dptr
      0021DD F0               [24] 6974 	movx	@dptr,a
      0021DE ED               [12] 6975 	mov	a,r5
      0021DF A3               [24] 6976 	inc	dptr
      0021E0 F0               [24] 6977 	movx	@dptr,a
      0021E1 EE               [12] 6978 	mov	a,r6
      0021E2 A3               [24] 6979 	inc	dptr
      0021E3 F0               [24] 6980 	movx	@dptr,a
                                   6981 ;	..\COMMON\easyax5043.c:1297: wtimer0_addabsolute(&axradio_timer);
      0021E4 90 02 9D         [24] 6982 	mov	dptr,#_axradio_timer
                                   6983 ;	..\COMMON\easyax5043.c:1298: break;
      0021E7 02 43 6C         [24] 6984 	ljmp	_wtimer0_addabsolute
                                   6985 ;	..\COMMON\easyax5043.c:1300: case syncstate_slave_rxsfdwindow:
      0021EA                       6986 00221$:
                                   6987 ;	..\COMMON\easyax5043.c:1302: uint8_t __autodata rs = radio_read8(AX5043_REG_RADIOSTATE);
      0021EA 90 40 1C         [24] 6988 	mov	dptr,#0x401c
      0021ED E0               [24] 6989 	movx	a,@dptr
                                   6990 ;	..\COMMON\easyax5043.c:1303: if (!rs)
      0021EE FF               [12] 6991 	mov	r7,a
      0021EF FE               [12] 6992 	mov	r6,a
      0021F0 70 01            [24] 6993 	jnz	00353$
      0021F2 22               [24] 6994 	ret
      0021F3                       6995 00353$:
                                   6996 ;	..\COMMON\easyax5043.c:1306: if (!(0x0F & (uint8_t)~rs)) {
      0021F3 EE               [12] 6997 	mov	a,r6
      0021F4 F4               [12] 6998 	cpl	a
      0021F5 FE               [12] 6999 	mov	r6,a
      0021F6 54 0F            [12] 7000 	anl	a,#0x0f
      0021F8 60 02            [24] 7001 	jz	00355$
      0021FA 80 4C            [24] 7002 	sjmp	00226$
      0021FC                       7003 00355$:
                                   7004 ;	..\COMMON\easyax5043.c:1307: axradio_syncstate = syncstate_slave_rxpacket;
      0021FC 90 00 13         [24] 7005 	mov	dptr,#_axradio_syncstate
      0021FF 74 0B            [12] 7006 	mov	a,#0x0b
      002201 F0               [24] 7007 	movx	@dptr,a
                                   7008 ;	..\COMMON\easyax5043.c:1308: wtimer_remove(&axradio_timer);
      002202 90 02 9D         [24] 7009 	mov	dptr,#_axradio_timer
      002205 12 47 8D         [24] 7010 	lcall	_wtimer_remove
                                   7011 ;	..\COMMON\easyax5043.c:1309: axradio_timer.time += axradio_sync_slave_rxtimeout;
      002208 90 02 A1         [24] 7012 	mov	dptr,#(_axradio_timer + 0x0004)
      00220B E0               [24] 7013 	movx	a,@dptr
      00220C FC               [12] 7014 	mov	r4,a
      00220D A3               [24] 7015 	inc	dptr
      00220E E0               [24] 7016 	movx	a,@dptr
      00220F FD               [12] 7017 	mov	r5,a
      002210 A3               [24] 7018 	inc	dptr
      002211 E0               [24] 7019 	movx	a,@dptr
      002212 FE               [12] 7020 	mov	r6,a
      002213 A3               [24] 7021 	inc	dptr
      002214 E0               [24] 7022 	movx	a,@dptr
      002215 FF               [12] 7023 	mov	r7,a
      002216 90 4D 01         [24] 7024 	mov	dptr,#_axradio_sync_slave_rxtimeout
      002219 E4               [12] 7025 	clr	a
      00221A 93               [24] 7026 	movc	a,@a+dptr
      00221B F8               [12] 7027 	mov	r0,a
      00221C 74 01            [12] 7028 	mov	a,#0x01
      00221E 93               [24] 7029 	movc	a,@a+dptr
      00221F F9               [12] 7030 	mov	r1,a
      002220 74 02            [12] 7031 	mov	a,#0x02
      002222 93               [24] 7032 	movc	a,@a+dptr
      002223 FA               [12] 7033 	mov	r2,a
      002224 74 03            [12] 7034 	mov	a,#0x03
      002226 93               [24] 7035 	movc	a,@a+dptr
      002227 FB               [12] 7036 	mov	r3,a
      002228 E8               [12] 7037 	mov	a,r0
      002229 2C               [12] 7038 	add	a,r4
      00222A FC               [12] 7039 	mov	r4,a
      00222B E9               [12] 7040 	mov	a,r1
      00222C 3D               [12] 7041 	addc	a,r5
      00222D FD               [12] 7042 	mov	r5,a
      00222E EA               [12] 7043 	mov	a,r2
      00222F 3E               [12] 7044 	addc	a,r6
      002230 FE               [12] 7045 	mov	r6,a
      002231 EB               [12] 7046 	mov	a,r3
      002232 3F               [12] 7047 	addc	a,r7
      002233 FF               [12] 7048 	mov	r7,a
      002234 90 02 A1         [24] 7049 	mov	dptr,#(_axradio_timer + 0x0004)
      002237 EC               [12] 7050 	mov	a,r4
      002238 F0               [24] 7051 	movx	@dptr,a
      002239 ED               [12] 7052 	mov	a,r5
      00223A A3               [24] 7053 	inc	dptr
      00223B F0               [24] 7054 	movx	@dptr,a
      00223C EE               [12] 7055 	mov	a,r6
      00223D A3               [24] 7056 	inc	dptr
      00223E F0               [24] 7057 	movx	@dptr,a
      00223F EF               [12] 7058 	mov	a,r7
      002240 A3               [24] 7059 	inc	dptr
      002241 F0               [24] 7060 	movx	@dptr,a
                                   7061 ;	..\COMMON\easyax5043.c:1310: wtimer0_addabsolute(&axradio_timer);
      002242 90 02 9D         [24] 7062 	mov	dptr,#_axradio_timer
                                   7063 ;	..\COMMON\easyax5043.c:1311: break;
      002245 02 43 6C         [24] 7064 	ljmp	_wtimer0_addabsolute
                                   7065 ;	..\COMMON\easyax5043.c:1316: case syncstate_slave_rxpacket:
      002248                       7066 00226$:
                                   7067 ;	..\COMMON\easyax5043.c:1317: ax5043_off();
      002248 12 17 8A         [24] 7068 	lcall	_ax5043_off
                                   7069 ;	..\COMMON\easyax5043.c:1318: if (!axradio_sync_seqnr)
      00224B 90 00 1E         [24] 7070 	mov	dptr,#_axradio_ack_seqnr
      00224E E0               [24] 7071 	movx	a,@dptr
      00224F 70 06            [24] 7072 	jnz	00228$
                                   7073 ;	..\COMMON\easyax5043.c:1319: axradio_sync_seqnr = 1;
      002251 90 00 1E         [24] 7074 	mov	dptr,#_axradio_ack_seqnr
      002254 74 01            [12] 7075 	mov	a,#0x01
      002256 F0               [24] 7076 	movx	@dptr,a
      002257                       7077 00228$:
                                   7078 ;	..\COMMON\easyax5043.c:1320: ++axradio_sync_seqnr;
      002257 90 00 1E         [24] 7079 	mov	dptr,#_axradio_ack_seqnr
      00225A E0               [24] 7080 	movx	a,@dptr
      00225B 24 01            [12] 7081 	add	a,#0x01
      00225D F0               [24] 7082 	movx	@dptr,a
                                   7083 ;	..\COMMON\easyax5043.c:1321: update_timeanchor();
      00225E 12 0A 7C         [24] 7084 	lcall	_update_timeanchor
                                   7085 ;	..\COMMON\easyax5043.c:1322: wtimer_remove_callback(&axradio_cb_receive.cb);
      002261 90 02 44         [24] 7086 	mov	dptr,#_axradio_cb_receive
      002264 12 48 82         [24] 7087 	lcall	_wtimer_remove_callback
                                   7088 ;	..\COMMON\easyax5043.c:1323: memset_xdata(&axradio_cb_receive.st, 0, sizeof(axradio_cb_receive.st));
      002267 75 2E 00         [24] 7089 	mov	_memset_PARM_2,#0x00
      00226A 75 2F 20         [24] 7090 	mov	_memset_PARM_3,#0x20
      00226D 75 30 00         [24] 7091 	mov	(_memset_PARM_3 + 1),#0x00
      002270 90 02 48         [24] 7092 	mov	dptr,#(_axradio_cb_receive + 0x0004)
      002273 75 F0 00         [24] 7093 	mov	b,#0x00
      002276 12 42 50         [24] 7094 	lcall	_memset
                                   7095 ;	..\COMMON\easyax5043.c:1324: axradio_cb_receive.st.time.t = axradio_timeanchor.radiotimer;
      002279 90 00 29         [24] 7096 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      00227C E0               [24] 7097 	movx	a,@dptr
      00227D FC               [12] 7098 	mov	r4,a
      00227E A3               [24] 7099 	inc	dptr
      00227F E0               [24] 7100 	movx	a,@dptr
      002280 FD               [12] 7101 	mov	r5,a
      002281 A3               [24] 7102 	inc	dptr
      002282 E0               [24] 7103 	movx	a,@dptr
      002283 FE               [12] 7104 	mov	r6,a
      002284 A3               [24] 7105 	inc	dptr
      002285 E0               [24] 7106 	movx	a,@dptr
      002286 FF               [12] 7107 	mov	r7,a
      002287 90 02 4A         [24] 7108 	mov	dptr,#(_axradio_cb_receive + 0x0006)
      00228A EC               [12] 7109 	mov	a,r4
      00228B F0               [24] 7110 	movx	@dptr,a
      00228C ED               [12] 7111 	mov	a,r5
      00228D A3               [24] 7112 	inc	dptr
      00228E F0               [24] 7113 	movx	@dptr,a
      00228F EE               [12] 7114 	mov	a,r6
      002290 A3               [24] 7115 	inc	dptr
      002291 F0               [24] 7116 	movx	@dptr,a
      002292 EF               [12] 7117 	mov	a,r7
      002293 A3               [24] 7118 	inc	dptr
      002294 F0               [24] 7119 	movx	@dptr,a
                                   7120 ;	..\COMMON\easyax5043.c:1325: axradio_cb_receive.st.error = AXRADIO_ERR_TIMEOUT;
      002295 90 02 49         [24] 7121 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      002298 74 03            [12] 7122 	mov	a,#0x03
      00229A F0               [24] 7123 	movx	@dptr,a
                                   7124 ;	..\COMMON\easyax5043.c:1326: if (axradio_sync_seqnr <= axradio_sync_slave_resyncloss) {
      00229B 90 00 1E         [24] 7125 	mov	dptr,#_axradio_ack_seqnr
      00229E E0               [24] 7126 	movx	a,@dptr
      00229F FF               [12] 7127 	mov	r7,a
      0022A0 90 4C E7         [24] 7128 	mov	dptr,#_axradio_sync_slave_resyncloss
      0022A3 E4               [12] 7129 	clr	a
      0022A4 93               [24] 7130 	movc	a,@a+dptr
      0022A5 FE               [12] 7131 	mov	r6,a
      0022A6 C3               [12] 7132 	clr	c
      0022A7 9F               [12] 7133 	subb	a,r7
      0022A8 40 54            [24] 7134 	jc	00232$
                                   7135 ;	..\COMMON\easyax5043.c:1327: wtimer_add_callback(&axradio_cb_receive.cb);
      0022AA 90 02 44         [24] 7136 	mov	dptr,#_axradio_cb_receive
      0022AD 12 42 C4         [24] 7137 	lcall	_wtimer_add_callback
                                   7138 ;	..\COMMON\easyax5043.c:1328: axradio_sync_slave_nextperiod();
      0022B0 12 1A F9         [24] 7139 	lcall	_axradio_sync_slave_nextperiod
                                   7140 ;	..\COMMON\easyax5043.c:1329: axradio_syncstate = syncstate_slave_rxidle;
      0022B3 90 00 13         [24] 7141 	mov	dptr,#_axradio_syncstate
      0022B6 74 08            [12] 7142 	mov	a,#0x08
      0022B8 F0               [24] 7143 	movx	@dptr,a
                                   7144 ;	..\COMMON\easyax5043.c:1330: wtimer_remove(&axradio_timer);
      0022B9 90 02 9D         [24] 7145 	mov	dptr,#_axradio_timer
      0022BC 12 47 8D         [24] 7146 	lcall	_wtimer_remove
                                   7147 ;	..\COMMON\easyax5043.c:1332: uint8_t __autodata idx = axradio_sync_seqnr;
      0022BF 90 00 1E         [24] 7148 	mov	dptr,#_axradio_ack_seqnr
      0022C2 E0               [24] 7149 	movx	a,@dptr
      0022C3 FF               [12] 7150 	mov	r7,a
                                   7151 ;	..\COMMON\easyax5043.c:1333: if (idx >= axradio_sync_slave_nrrx)
      0022C4 90 4C E8         [24] 7152 	mov	dptr,#_axradio_sync_slave_nrrx
      0022C7 E4               [12] 7153 	clr	a
      0022C8 93               [24] 7154 	movc	a,@a+dptr
      0022C9 FE               [12] 7155 	mov	r6,a
      0022CA C3               [12] 7156 	clr	c
      0022CB EF               [12] 7157 	mov	a,r7
      0022CC 9E               [12] 7158 	subb	a,r6
      0022CD 40 03            [24] 7159 	jc	00230$
                                   7160 ;	..\COMMON\easyax5043.c:1334: idx = axradio_sync_slave_nrrx - 1;
      0022CF EE               [12] 7161 	mov	a,r6
      0022D0 14               [12] 7162 	dec	a
      0022D1 FF               [12] 7163 	mov	r7,a
      0022D2                       7164 00230$:
                                   7165 ;	..\COMMON\easyax5043.c:1335: axradio_sync_settimeradv(axradio_sync_slave_rxadvance[idx]);
      0022D2 EF               [12] 7166 	mov	a,r7
      0022D3 75 F0 04         [24] 7167 	mov	b,#0x04
      0022D6 A4               [48] 7168 	mul	ab
      0022D7 24 E9            [12] 7169 	add	a,#_axradio_sync_slave_rxadvance
      0022D9 F5 82            [12] 7170 	mov	dpl,a
      0022DB 74 4C            [12] 7171 	mov	a,#(_axradio_sync_slave_rxadvance >> 8)
      0022DD 35 F0            [12] 7172 	addc	a,b
      0022DF F5 83            [12] 7173 	mov	dph,a
      0022E1 E4               [12] 7174 	clr	a
      0022E2 93               [24] 7175 	movc	a,@a+dptr
      0022E3 FC               [12] 7176 	mov	r4,a
      0022E4 A3               [24] 7177 	inc	dptr
      0022E5 E4               [12] 7178 	clr	a
      0022E6 93               [24] 7179 	movc	a,@a+dptr
      0022E7 FD               [12] 7180 	mov	r5,a
      0022E8 A3               [24] 7181 	inc	dptr
      0022E9 E4               [12] 7182 	clr	a
      0022EA 93               [24] 7183 	movc	a,@a+dptr
      0022EB FE               [12] 7184 	mov	r6,a
      0022EC A3               [24] 7185 	inc	dptr
      0022ED E4               [12] 7186 	clr	a
      0022EE 93               [24] 7187 	movc	a,@a+dptr
      0022EF 8C 82            [24] 7188 	mov	dpl,r4
      0022F1 8D 83            [24] 7189 	mov	dph,r5
      0022F3 8E F0            [24] 7190 	mov	b,r6
      0022F5 12 19 93         [24] 7191 	lcall	_axradio_sync_settimeradv
                                   7192 ;	..\COMMON\easyax5043.c:1337: wtimer0_addabsolute(&axradio_timer);
      0022F8 90 02 9D         [24] 7193 	mov	dptr,#_axradio_timer
                                   7194 ;	..\COMMON\easyax5043.c:1338: break;
      0022FB 02 43 6C         [24] 7195 	ljmp	_wtimer0_addabsolute
      0022FE                       7196 00232$:
                                   7197 ;	..\COMMON\easyax5043.c:1340: axradio_cb_receive.st.error = AXRADIO_ERR_RESYNC;
      0022FE 90 02 49         [24] 7198 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      002301 74 09            [12] 7199 	mov	a,#0x09
      002303 F0               [24] 7200 	movx	@dptr,a
                                   7201 ;	..\COMMON\easyax5043.c:1341: wtimer_add_callback(&axradio_cb_receive.cb);
      002304 90 02 44         [24] 7202 	mov	dptr,#_axradio_cb_receive
      002307 12 42 C4         [24] 7203 	lcall	_wtimer_add_callback
                                   7204 ;	..\COMMON\easyax5043.c:1342: ax5043_receiver_on_continuous();
      00230A 12 16 3B         [24] 7205 	lcall	_ax5043_receiver_on_continuous
                                   7206 ;	..\COMMON\easyax5043.c:1343: axradio_syncstate = syncstate_slave_synchunt;
      00230D 90 00 13         [24] 7207 	mov	dptr,#_axradio_syncstate
      002310 74 06            [12] 7208 	mov	a,#0x06
      002312 F0               [24] 7209 	movx	@dptr,a
                                   7210 ;	..\COMMON\easyax5043.c:1344: wtimer_remove(&axradio_timer);
      002313 90 02 9D         [24] 7211 	mov	dptr,#_axradio_timer
      002316 12 47 8D         [24] 7212 	lcall	_wtimer_remove
                                   7213 ;	..\COMMON\easyax5043.c:1345: axradio_timer.time = axradio_sync_slave_syncwindow;
      002319 90 4C D9         [24] 7214 	mov	dptr,#_axradio_sync_slave_syncwindow
      00231C E4               [12] 7215 	clr	a
      00231D 93               [24] 7216 	movc	a,@a+dptr
      00231E FC               [12] 7217 	mov	r4,a
      00231F 74 01            [12] 7218 	mov	a,#0x01
      002321 93               [24] 7219 	movc	a,@a+dptr
      002322 FD               [12] 7220 	mov	r5,a
      002323 74 02            [12] 7221 	mov	a,#0x02
      002325 93               [24] 7222 	movc	a,@a+dptr
      002326 FE               [12] 7223 	mov	r6,a
      002327 74 03            [12] 7224 	mov	a,#0x03
      002329 93               [24] 7225 	movc	a,@a+dptr
      00232A FF               [12] 7226 	mov	r7,a
      00232B 90 02 A1         [24] 7227 	mov	dptr,#(_axradio_timer + 0x0004)
      00232E EC               [12] 7228 	mov	a,r4
      00232F F0               [24] 7229 	movx	@dptr,a
      002330 ED               [12] 7230 	mov	a,r5
      002331 A3               [24] 7231 	inc	dptr
      002332 F0               [24] 7232 	movx	@dptr,a
      002333 EE               [12] 7233 	mov	a,r6
      002334 A3               [24] 7234 	inc	dptr
      002335 F0               [24] 7235 	movx	@dptr,a
      002336 EF               [12] 7236 	mov	a,r7
      002337 A3               [24] 7237 	inc	dptr
      002338 F0               [24] 7238 	movx	@dptr,a
                                   7239 ;	..\COMMON\easyax5043.c:1346: wtimer0_addrelative(&axradio_timer);
      002339 90 02 9D         [24] 7240 	mov	dptr,#_axradio_timer
      00233C 12 42 DE         [24] 7241 	lcall	_wtimer0_addrelative
                                   7242 ;	..\COMMON\easyax5043.c:1347: axradio_sync_time = axradio_timer.time;
      00233F 90 02 A1         [24] 7243 	mov	dptr,#(_axradio_timer + 0x0004)
      002342 E0               [24] 7244 	movx	a,@dptr
      002343 FC               [12] 7245 	mov	r4,a
      002344 A3               [24] 7246 	inc	dptr
      002345 E0               [24] 7247 	movx	a,@dptr
      002346 FD               [12] 7248 	mov	r5,a
      002347 A3               [24] 7249 	inc	dptr
      002348 E0               [24] 7250 	movx	a,@dptr
      002349 FE               [12] 7251 	mov	r6,a
      00234A A3               [24] 7252 	inc	dptr
      00234B E0               [24] 7253 	movx	a,@dptr
      00234C FF               [12] 7254 	mov	r7,a
      00234D 90 00 1F         [24] 7255 	mov	dptr,#_axradio_sync_time
      002350 EC               [12] 7256 	mov	a,r4
      002351 F0               [24] 7257 	movx	@dptr,a
      002352 ED               [12] 7258 	mov	a,r5
      002353 A3               [24] 7259 	inc	dptr
      002354 F0               [24] 7260 	movx	@dptr,a
      002355 EE               [12] 7261 	mov	a,r6
      002356 A3               [24] 7262 	inc	dptr
      002357 F0               [24] 7263 	movx	@dptr,a
      002358 EF               [12] 7264 	mov	a,r7
      002359 A3               [24] 7265 	inc	dptr
      00235A F0               [24] 7266 	movx	@dptr,a
                                   7267 ;	..\COMMON\easyax5043.c:1348: break;
                                   7268 ;	..\COMMON\easyax5043.c:1350: case syncstate_slave_rxack:
      00235B 22               [24] 7269 	ret
      00235C                       7270 00233$:
                                   7271 ;	..\COMMON\easyax5043.c:1351: axradio_syncstate = syncstate_slave_rxidle;
      00235C 90 00 13         [24] 7272 	mov	dptr,#_axradio_syncstate
      00235F 74 08            [12] 7273 	mov	a,#0x08
      002361 F0               [24] 7274 	movx	@dptr,a
                                   7275 ;	..\COMMON\easyax5043.c:1352: wtimer_remove(&axradio_timer);
      002362 90 02 9D         [24] 7276 	mov	dptr,#_axradio_timer
      002365 12 47 8D         [24] 7277 	lcall	_wtimer_remove
                                   7278 ;	..\COMMON\easyax5043.c:1353: axradio_sync_settimeradv(axradio_sync_slave_rxadvance[1]);
      002368 90 4C ED         [24] 7279 	mov	dptr,#(_axradio_sync_slave_rxadvance + 0x0004)
      00236B E4               [12] 7280 	clr	a
      00236C 93               [24] 7281 	movc	a,@a+dptr
      00236D FC               [12] 7282 	mov	r4,a
      00236E A3               [24] 7283 	inc	dptr
      00236F E4               [12] 7284 	clr	a
      002370 93               [24] 7285 	movc	a,@a+dptr
      002371 FD               [12] 7286 	mov	r5,a
      002372 A3               [24] 7287 	inc	dptr
      002373 E4               [12] 7288 	clr	a
      002374 93               [24] 7289 	movc	a,@a+dptr
      002375 FE               [12] 7290 	mov	r6,a
      002376 A3               [24] 7291 	inc	dptr
      002377 E4               [12] 7292 	clr	a
      002378 93               [24] 7293 	movc	a,@a+dptr
      002379 8C 82            [24] 7294 	mov	dpl,r4
      00237B 8D 83            [24] 7295 	mov	dph,r5
      00237D 8E F0            [24] 7296 	mov	b,r6
      00237F 12 19 93         [24] 7297 	lcall	_axradio_sync_settimeradv
                                   7298 ;	..\COMMON\easyax5043.c:1354: wtimer0_addabsolute(&axradio_timer);
      002382 90 02 9D         [24] 7299 	mov	dptr,#_axradio_timer
      002385 12 43 6C         [24] 7300 	lcall	_wtimer0_addabsolute
                                   7301 ;	..\COMMON\easyax5043.c:1355: goto transmitack;
      002388 02 1D 6B         [24] 7302 	ljmp	00134$
                                   7303 ;	..\COMMON\easyax5043.c:1359: default:
      00238B                       7304 00235$:
                                   7305 ;	..\COMMON\easyax5043.c:1361: }
      00238B 22               [24] 7306 	ret
                                   7307 ;------------------------------------------------------------
                                   7308 ;Allocation info for local variables in function 'axradio_callback_fwd'
                                   7309 ;------------------------------------------------------------
                                   7310 ;desc                      Allocated to registers r6 r7 
                                   7311 ;------------------------------------------------------------
                                   7312 ;	..\COMMON\easyax5043.c:1364: static __reentrantb void axradio_callback_fwd(struct wtimer_callback __xdata *desc) __reentrant
                                   7313 ;	-----------------------------------------
                                   7314 ;	 function axradio_callback_fwd
                                   7315 ;	-----------------------------------------
      00238C                       7316 _axradio_callback_fwd:
      00238C AE 82            [24] 7317 	mov	r6,dpl
      00238E AF 83            [24] 7318 	mov	r7,dph
                                   7319 ;	..\COMMON\easyax5043.c:1366: axradio_statuschange((struct axradio_status __xdata *)(desc + 1));
      002390 74 04            [12] 7320 	mov	a,#0x04
      002392 2E               [12] 7321 	add	a,r6
      002393 FE               [12] 7322 	mov	r6,a
      002394 E4               [12] 7323 	clr	a
      002395 3F               [12] 7324 	addc	a,r7
      002396 FF               [12] 7325 	mov	r7,a
      002397 8E 82            [24] 7326 	mov	dpl,r6
      002399 8F 83            [24] 7327 	mov	dph,r7
      00239B 02 3C 6F         [24] 7328 	ljmp	_axradio_statuschange
                                   7329 ;------------------------------------------------------------
                                   7330 ;Allocation info for local variables in function 'axradio_receive_callback_fwd'
                                   7331 ;------------------------------------------------------------
                                   7332 ;desc                      Allocated to registers 
                                   7333 ;len                       Allocated to registers r6 r7 
                                   7334 ;len                       Allocated to registers r6 r7 
                                   7335 ;seqnr                     Allocated to registers r6 
                                   7336 ;len_byte                  Allocated to registers r6 
                                   7337 ;trxst                     Allocated to registers r6 
                                   7338 ;__00030023                Allocated to registers 
                                   7339 ;crit                      Allocated to registers 
                                   7340 ;crit                      Allocated to registers r7 
                                   7341 ;__00040025                Allocated to registers 
                                   7342 ;crit                      Allocated to registers 
                                   7343 ;------------------------------------------------------------
                                   7344 ;	..\COMMON\easyax5043.c:1369: static void axradio_receive_callback_fwd(struct wtimer_callback __xdata *desc)
                                   7345 ;	-----------------------------------------
                                   7346 ;	 function axradio_receive_callback_fwd
                                   7347 ;	-----------------------------------------
      00239E                       7348 _axradio_receive_callback_fwd:
                                   7349 ;	..\COMMON\easyax5043.c:1373: if (axradio_cb_receive.st.error != AXRADIO_ERR_NOERROR) {
      00239E 90 02 49         [24] 7350 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      0023A1 E0               [24] 7351 	movx	a,@dptr
      0023A2 60 06            [24] 7352 	jz	00102$
                                   7353 ;	..\COMMON\easyax5043.c:1374: axradio_statuschange((struct axradio_status __xdata *)&axradio_cb_receive.st);
      0023A4 90 02 48         [24] 7354 	mov	dptr,#(_axradio_cb_receive + 0x0004)
                                   7355 ;	..\COMMON\easyax5043.c:1375: return;
      0023A7 02 3C 6F         [24] 7356 	ljmp	_axradio_statuschange
      0023AA                       7357 00102$:
                                   7358 ;	..\COMMON\easyax5043.c:1377: if (axradio_phy_pn9 && !AXRADIO_MODE_IS_STREAM_RECEIVE(axradio_mode)) {
      0023AA 90 4C 70         [24] 7359 	mov	dptr,#_axradio_phy_pn9
      0023AD E4               [12] 7360 	clr	a
      0023AE 93               [24] 7361 	movc	a,@a+dptr
      0023AF 60 51            [24] 7362 	jz	00104$
      0023B1 74 F8            [12] 7363 	mov	a,#0xf8
      0023B3 55 08            [12] 7364 	anl	a,_axradio_mode
      0023B5 FF               [12] 7365 	mov	r7,a
      0023B6 BF 28 02         [24] 7366 	cjne	r7,#0x28,00299$
      0023B9 80 47            [24] 7367 	sjmp	00104$
      0023BB                       7368 00299$:
                                   7369 ;	..\COMMON\easyax5043.c:1378: uint16_t __autodata len = axradio_cb_receive.st.rx.pktlen;
      0023BB 90 02 66         [24] 7370 	mov	dptr,#(_axradio_cb_receive + 0x0022)
      0023BE E0               [24] 7371 	movx	a,@dptr
      0023BF FE               [12] 7372 	mov	r6,a
      0023C0 A3               [24] 7373 	inc	dptr
      0023C1 E0               [24] 7374 	movx	a,@dptr
      0023C2 FF               [12] 7375 	mov	r7,a
                                   7376 ;	..\COMMON\easyax5043.c:1379: len += axradio_framing_maclen;
      0023C3 90 4C B5         [24] 7377 	mov	dptr,#_axradio_framing_maclen
      0023C6 E4               [12] 7378 	clr	a
      0023C7 93               [24] 7379 	movc	a,@a+dptr
      0023C8 7C 00            [12] 7380 	mov	r4,#0x00
      0023CA 2E               [12] 7381 	add	a,r6
      0023CB FE               [12] 7382 	mov	r6,a
      0023CC EC               [12] 7383 	mov	a,r4
      0023CD 3F               [12] 7384 	addc	a,r7
      0023CE FF               [12] 7385 	mov	r7,a
                                   7386 ;	..\COMMON\easyax5043.c:1380: pn9_buffer((__xdata uint8_t *)axradio_cb_receive.st.rx.mac.raw, len, 0x1ff, -(radio_read8(AX5043_REG_ENCODING) & 0x01));
      0023CF 90 40 11         [24] 7387 	mov	dptr,#0x4011
      0023D2 E0               [24] 7388 	movx	a,@dptr
      0023D3 FD               [12] 7389 	mov	r5,a
      0023D4 53 05 01         [24] 7390 	anl	ar5,#0x01
      0023D7 C3               [12] 7391 	clr	c
      0023D8 E4               [12] 7392 	clr	a
      0023D9 9D               [12] 7393 	subb	a,r5
      0023DA FD               [12] 7394 	mov	r5,a
      0023DB 90 02 62         [24] 7395 	mov	dptr,#(_axradio_cb_receive + 0x001e)
      0023DE E0               [24] 7396 	movx	a,@dptr
      0023DF FB               [12] 7397 	mov	r3,a
      0023E0 A3               [24] 7398 	inc	dptr
      0023E1 E0               [24] 7399 	movx	a,@dptr
      0023E2 FC               [12] 7400 	mov	r4,a
      0023E3 7A 00            [12] 7401 	mov	r2,#0x00
      0023E5 C0 05            [24] 7402 	push	ar5
      0023E7 74 FF            [12] 7403 	mov	a,#0xff
      0023E9 C0 E0            [24] 7404 	push	acc
      0023EB 74 01            [12] 7405 	mov	a,#0x01
      0023ED C0 E0            [24] 7406 	push	acc
      0023EF C0 06            [24] 7407 	push	ar6
      0023F1 C0 07            [24] 7408 	push	ar7
      0023F3 8B 82            [24] 7409 	mov	dpl,r3
      0023F5 8C 83            [24] 7410 	mov	dph,r4
      0023F7 8A F0            [24] 7411 	mov	b,r2
      0023F9 12 43 BF         [24] 7412 	lcall	_pn9_buffer
      0023FC E5 81            [12] 7413 	mov	a,sp
      0023FE 24 FB            [12] 7414 	add	a,#0xfb
      002400 F5 81            [12] 7415 	mov	sp,a
      002402                       7416 00104$:
                                   7417 ;	..\COMMON\easyax5043.c:1382: if (axradio_framing_swcrclen && !AXRADIO_MODE_IS_STREAM_RECEIVE(axradio_mode)) {
      002402 90 4C BC         [24] 7418 	mov	dptr,#_axradio_framing_swcrclen
      002405 E4               [12] 7419 	clr	a
      002406 93               [24] 7420 	movc	a,@a+dptr
      002407 60 66            [24] 7421 	jz	00109$
      002409 74 F8            [12] 7422 	mov	a,#0xf8
      00240B 55 08            [12] 7423 	anl	a,_axradio_mode
      00240D FF               [12] 7424 	mov	r7,a
      00240E BF 28 02         [24] 7425 	cjne	r7,#0x28,00301$
      002411 80 5C            [24] 7426 	sjmp	00109$
      002413                       7427 00301$:
                                   7428 ;	..\COMMON\easyax5043.c:1383: uint16_t __autodata len = axradio_cb_receive.st.rx.pktlen;
      002413 90 02 66         [24] 7429 	mov	dptr,#(_axradio_cb_receive + 0x0022)
      002416 E0               [24] 7430 	movx	a,@dptr
      002417 FE               [12] 7431 	mov	r6,a
      002418 A3               [24] 7432 	inc	dptr
      002419 E0               [24] 7433 	movx	a,@dptr
      00241A FF               [12] 7434 	mov	r7,a
                                   7435 ;	..\COMMON\easyax5043.c:1384: len += axradio_framing_maclen;
      00241B 90 4C B5         [24] 7436 	mov	dptr,#_axradio_framing_maclen
      00241E E4               [12] 7437 	clr	a
      00241F 93               [24] 7438 	movc	a,@a+dptr
      002420 7C 00            [12] 7439 	mov	r4,#0x00
      002422 2E               [12] 7440 	add	a,r6
      002423 FE               [12] 7441 	mov	r6,a
      002424 EC               [12] 7442 	mov	a,r4
      002425 3F               [12] 7443 	addc	a,r7
      002426 FF               [12] 7444 	mov	r7,a
                                   7445 ;	..\COMMON\easyax5043.c:1385: len = axradio_framing_check_crc((uint8_t __xdata *)axradio_cb_receive.st.rx.mac.raw, len);
      002427 90 02 62         [24] 7446 	mov	dptr,#(_axradio_cb_receive + 0x001e)
      00242A E0               [24] 7447 	movx	a,@dptr
      00242B FC               [12] 7448 	mov	r4,a
      00242C A3               [24] 7449 	inc	dptr
      00242D E0               [24] 7450 	movx	a,@dptr
      00242E FD               [12] 7451 	mov	r5,a
      00242F C0 06            [24] 7452 	push	ar6
      002431 C0 07            [24] 7453 	push	ar7
      002433 8C 82            [24] 7454 	mov	dpl,r4
      002435 8D 83            [24] 7455 	mov	dph,r5
      002437 12 09 D4         [24] 7456 	lcall	_axradio_framing_check_crc
      00243A AE 82            [24] 7457 	mov	r6,dpl
      00243C AF 83            [24] 7458 	mov	r7,dph
      00243E 15 81            [12] 7459 	dec	sp
      002440 15 81            [12] 7460 	dec	sp
                                   7461 ;	..\COMMON\easyax5043.c:1386: if (!len)
      002442 EE               [12] 7462 	mov	a,r6
      002443 4F               [12] 7463 	orl	a,r7
      002444 70 03            [24] 7464 	jnz	00302$
      002446 02 28 3A         [24] 7465 	ljmp	00171$
      002449                       7466 00302$:
                                   7467 ;	..\COMMON\easyax5043.c:1389: len -= axradio_framing_maclen;
      002449 90 4C B5         [24] 7468 	mov	dptr,#_axradio_framing_maclen
      00244C E4               [12] 7469 	clr	a
      00244D 93               [24] 7470 	movc	a,@a+dptr
      00244E FD               [12] 7471 	mov	r5,a
      00244F 7C 00            [12] 7472 	mov	r4,#0x00
      002451 EE               [12] 7473 	mov	a,r6
      002452 C3               [12] 7474 	clr	c
      002453 9D               [12] 7475 	subb	a,r5
      002454 FE               [12] 7476 	mov	r6,a
      002455 EF               [12] 7477 	mov	a,r7
      002456 9C               [12] 7478 	subb	a,r4
      002457 FF               [12] 7479 	mov	r7,a
                                   7480 ;	..\COMMON\easyax5043.c:1390: len -= axradio_framing_swcrclen; // drop crc
      002458 90 4C BC         [24] 7481 	mov	dptr,#_axradio_framing_swcrclen
      00245B E4               [12] 7482 	clr	a
      00245C 93               [24] 7483 	movc	a,@a+dptr
      00245D FD               [12] 7484 	mov	r5,a
      00245E 7C 00            [12] 7485 	mov	r4,#0x00
      002460 EE               [12] 7486 	mov	a,r6
      002461 C3               [12] 7487 	clr	c
      002462 9D               [12] 7488 	subb	a,r5
      002463 FE               [12] 7489 	mov	r6,a
      002464 EF               [12] 7490 	mov	a,r7
      002465 9C               [12] 7491 	subb	a,r4
      002466 FF               [12] 7492 	mov	r7,a
                                   7493 ;	..\COMMON\easyax5043.c:1391: axradio_cb_receive.st.rx.pktlen = len;
      002467 90 02 66         [24] 7494 	mov	dptr,#(_axradio_cb_receive + 0x0022)
      00246A EE               [12] 7495 	mov	a,r6
      00246B F0               [24] 7496 	movx	@dptr,a
      00246C EF               [12] 7497 	mov	a,r7
      00246D A3               [24] 7498 	inc	dptr
      00246E F0               [24] 7499 	movx	@dptr,a
      00246F                       7500 00109$:
                                   7501 ;	..\COMMON\easyax5043.c:1395: axradio_cb_receive.st.rx.phy.timeoffset = 0;
      00246F 90 02 54         [24] 7502 	mov	dptr,#(_axradio_cb_receive + 0x0010)
      002472 E4               [12] 7503 	clr	a
      002473 F0               [24] 7504 	movx	@dptr,a
      002474 A3               [24] 7505 	inc	dptr
      002475 F0               [24] 7506 	movx	@dptr,a
                                   7507 ;	..\COMMON\easyax5043.c:1396: axradio_cb_receive.st.rx.phy.period = 0;
      002476 90 02 56         [24] 7508 	mov	dptr,#(_axradio_cb_receive + 0x0012)
      002479 F0               [24] 7509 	movx	@dptr,a
      00247A A3               [24] 7510 	inc	dptr
      00247B F0               [24] 7511 	movx	@dptr,a
                                   7512 ;	..\COMMON\easyax5043.c:1397: if (axradio_mode == AXRADIO_MODE_ACK_TRANSMIT ||
      00247C 74 12            [12] 7513 	mov	a,#0x12
      00247E B5 08 02         [24] 7514 	cjne	a,_axradio_mode,00303$
      002481 80 0C            [24] 7515 	sjmp	00113$
      002483                       7516 00303$:
                                   7517 ;	..\COMMON\easyax5043.c:1398: axradio_mode == AXRADIO_MODE_WOR_ACK_TRANSMIT ||
      002483 74 13            [12] 7518 	mov	a,#0x13
      002485 B5 08 02         [24] 7519 	cjne	a,_axradio_mode,00304$
      002488 80 05            [24] 7520 	sjmp	00113$
      00248A                       7521 00304$:
                                   7522 ;	..\COMMON\easyax5043.c:1399: axradio_mode == AXRADIO_MODE_SYNC_ACK_MASTER) {
      00248A 74 31            [12] 7523 	mov	a,#0x31
      00248C B5 08 60         [24] 7524 	cjne	a,_axradio_mode,00114$
      00248F                       7525 00113$:
                                   7526 ;	..\COMMON\easyax5043.c:1400: ax5043_off();
      00248F 12 17 8A         [24] 7527 	lcall	_ax5043_off
                                   7528 ;	..\COMMON\easyax5043.c:1401: wtimer_remove(&axradio_timer);
      002492 90 02 9D         [24] 7529 	mov	dptr,#_axradio_timer
      002495 12 47 8D         [24] 7530 	lcall	_wtimer_remove
                                   7531 ;	..\COMMON\easyax5043.c:1402: if (axradio_mode == AXRADIO_MODE_SYNC_ACK_MASTER) {
      002498 74 31            [12] 7532 	mov	a,#0x31
      00249A B5 08 26         [24] 7533 	cjne	a,_axradio_mode,00112$
                                   7534 ;	..\COMMON\easyax5043.c:1403: axradio_syncstate = syncstate_master_normal;
      00249D 90 00 13         [24] 7535 	mov	dptr,#_axradio_syncstate
      0024A0 74 03            [12] 7536 	mov	a,#0x03
      0024A2 F0               [24] 7537 	movx	@dptr,a
                                   7538 ;	..\COMMON\easyax5043.c:1404: axradio_sync_settimeradv(axradio_sync_xoscstartup);
      0024A3 90 4C D5         [24] 7539 	mov	dptr,#_axradio_sync_xoscstartup
      0024A6 E4               [12] 7540 	clr	a
      0024A7 93               [24] 7541 	movc	a,@a+dptr
      0024A8 FC               [12] 7542 	mov	r4,a
      0024A9 74 01            [12] 7543 	mov	a,#0x01
      0024AB 93               [24] 7544 	movc	a,@a+dptr
      0024AC FD               [12] 7545 	mov	r5,a
      0024AD 74 02            [12] 7546 	mov	a,#0x02
      0024AF 93               [24] 7547 	movc	a,@a+dptr
      0024B0 FE               [12] 7548 	mov	r6,a
      0024B1 74 03            [12] 7549 	mov	a,#0x03
      0024B3 93               [24] 7550 	movc	a,@a+dptr
      0024B4 8C 82            [24] 7551 	mov	dpl,r4
      0024B6 8D 83            [24] 7552 	mov	dph,r5
      0024B8 8E F0            [24] 7553 	mov	b,r6
      0024BA 12 19 93         [24] 7554 	lcall	_axradio_sync_settimeradv
                                   7555 ;	..\COMMON\easyax5043.c:1405: wtimer0_addabsolute(&axradio_timer);
      0024BD 90 02 9D         [24] 7556 	mov	dptr,#_axradio_timer
      0024C0 12 43 6C         [24] 7557 	lcall	_wtimer0_addabsolute
      0024C3                       7558 00112$:
                                   7559 ;	..\COMMON\easyax5043.c:1407: wtimer_remove_callback(&axradio_cb_transmitend.cb);
      0024C3 90 02 89         [24] 7560 	mov	dptr,#_axradio_cb_transmitend
      0024C6 12 48 82         [24] 7561 	lcall	_wtimer_remove_callback
                                   7562 ;	..\COMMON\easyax5043.c:1408: axradio_cb_transmitend.st.error = AXRADIO_ERR_NOERROR;
      0024C9 90 02 8E         [24] 7563 	mov	dptr,#(_axradio_cb_transmitend + 0x0005)
      0024CC E4               [12] 7564 	clr	a
      0024CD F0               [24] 7565 	movx	@dptr,a
                                   7566 ;	..\COMMON\easyax5043.c:1409: axradio_cb_transmitend.st.time.t = radio_read24(AX5043_REG_TIMER2);
      0024CE 90 00 59         [24] 7567 	mov	dptr,#0x0059
      0024D1 12 43 98         [24] 7568 	lcall	_radio_read24
      0024D4 AC 82            [24] 7569 	mov	r4,dpl
      0024D6 AD 83            [24] 7570 	mov	r5,dph
      0024D8 AE F0            [24] 7571 	mov	r6,b
      0024DA FF               [12] 7572 	mov	r7,a
      0024DB 90 02 8F         [24] 7573 	mov	dptr,#(_axradio_cb_transmitend + 0x0006)
      0024DE EC               [12] 7574 	mov	a,r4
      0024DF F0               [24] 7575 	movx	@dptr,a
      0024E0 ED               [12] 7576 	mov	a,r5
      0024E1 A3               [24] 7577 	inc	dptr
      0024E2 F0               [24] 7578 	movx	@dptr,a
      0024E3 EE               [12] 7579 	mov	a,r6
      0024E4 A3               [24] 7580 	inc	dptr
      0024E5 F0               [24] 7581 	movx	@dptr,a
      0024E6 EF               [12] 7582 	mov	a,r7
      0024E7 A3               [24] 7583 	inc	dptr
      0024E8 F0               [24] 7584 	movx	@dptr,a
                                   7585 ;	..\COMMON\easyax5043.c:1410: wtimer_add_callback(&axradio_cb_transmitend.cb);
      0024E9 90 02 89         [24] 7586 	mov	dptr,#_axradio_cb_transmitend
      0024EC 12 42 C4         [24] 7587 	lcall	_wtimer_add_callback
      0024EF                       7588 00114$:
                                   7589 ;	..\COMMON\easyax5043.c:1412: if (axradio_framing_destaddrpos != 0xff)
      0024EF 90 4C B7         [24] 7590 	mov	dptr,#_axradio_framing_destaddrpos
      0024F2 E4               [12] 7591 	clr	a
      0024F3 93               [24] 7592 	movc	a,@a+dptr
      0024F4 FF               [12] 7593 	mov	r7,a
      0024F5 BF FF 02         [24] 7594 	cjne	r7,#0xff,00309$
      0024F8 80 29            [24] 7595 	sjmp	00118$
      0024FA                       7596 00309$:
                                   7597 ;	..\COMMON\easyax5043.c:1413: memcpy_xdata(&axradio_cb_receive.st.rx.mac.localaddr, &axradio_cb_receive.st.rx.mac.raw[axradio_framing_destaddrpos], axradio_framing_addrlen);
      0024FA 90 02 62         [24] 7598 	mov	dptr,#(_axradio_cb_receive + 0x001e)
      0024FD E0               [24] 7599 	movx	a,@dptr
      0024FE FD               [12] 7600 	mov	r5,a
      0024FF A3               [24] 7601 	inc	dptr
      002500 E0               [24] 7602 	movx	a,@dptr
      002501 FE               [12] 7603 	mov	r6,a
      002502 EF               [12] 7604 	mov	a,r7
      002503 2D               [12] 7605 	add	a,r5
      002504 FF               [12] 7606 	mov	r7,a
      002505 E4               [12] 7607 	clr	a
      002506 3E               [12] 7608 	addc	a,r6
      002507 FC               [12] 7609 	mov	r4,a
      002508 8F 2E            [24] 7610 	mov	_memcpy_PARM_2,r7
      00250A 8C 2F            [24] 7611 	mov	(_memcpy_PARM_2 + 1),r4
      00250C 75 30 00         [24] 7612 	mov	(_memcpy_PARM_2 + 2),#0x00
      00250F 90 4C B6         [24] 7613 	mov	dptr,#_axradio_framing_addrlen
      002512 E4               [12] 7614 	clr	a
      002513 93               [24] 7615 	movc	a,@a+dptr
      002514 FF               [12] 7616 	mov	r7,a
      002515 8F 31            [24] 7617 	mov	_memcpy_PARM_3,r7
      002517 75 32 00         [24] 7618 	mov	(_memcpy_PARM_3 + 1),#0x00
      00251A 90 02 5D         [24] 7619 	mov	dptr,#(_axradio_cb_receive + 0x0019)
      00251D 75 F0 00         [24] 7620 	mov	b,#0x00
      002520 12 42 6F         [24] 7621 	lcall	_memcpy
      002523                       7622 00118$:
                                   7623 ;	..\COMMON\easyax5043.c:1414: if (axradio_framing_sourceaddrpos != 0xff)
      002523 90 4C B8         [24] 7624 	mov	dptr,#_axradio_framing_sourceaddrpos
      002526 E4               [12] 7625 	clr	a
      002527 93               [24] 7626 	movc	a,@a+dptr
      002528 FF               [12] 7627 	mov	r7,a
      002529 BF FF 02         [24] 7628 	cjne	r7,#0xff,00310$
      00252C 80 29            [24] 7629 	sjmp	00120$
      00252E                       7630 00310$:
                                   7631 ;	..\COMMON\easyax5043.c:1415: memcpy_xdata(&axradio_cb_receive.st.rx.mac.remoteaddr, &axradio_cb_receive.st.rx.mac.raw[axradio_framing_sourceaddrpos], axradio_framing_addrlen);
      00252E 90 02 62         [24] 7632 	mov	dptr,#(_axradio_cb_receive + 0x001e)
      002531 E0               [24] 7633 	movx	a,@dptr
      002532 FD               [12] 7634 	mov	r5,a
      002533 A3               [24] 7635 	inc	dptr
      002534 E0               [24] 7636 	movx	a,@dptr
      002535 FE               [12] 7637 	mov	r6,a
      002536 EF               [12] 7638 	mov	a,r7
      002537 2D               [12] 7639 	add	a,r5
      002538 FF               [12] 7640 	mov	r7,a
      002539 E4               [12] 7641 	clr	a
      00253A 3E               [12] 7642 	addc	a,r6
      00253B FC               [12] 7643 	mov	r4,a
      00253C 8F 2E            [24] 7644 	mov	_memcpy_PARM_2,r7
      00253E 8C 2F            [24] 7645 	mov	(_memcpy_PARM_2 + 1),r4
      002540 75 30 00         [24] 7646 	mov	(_memcpy_PARM_2 + 2),#0x00
      002543 90 4C B6         [24] 7647 	mov	dptr,#_axradio_framing_addrlen
      002546 E4               [12] 7648 	clr	a
      002547 93               [24] 7649 	movc	a,@a+dptr
      002548 FF               [12] 7650 	mov	r7,a
      002549 8F 31            [24] 7651 	mov	_memcpy_PARM_3,r7
      00254B 75 32 00         [24] 7652 	mov	(_memcpy_PARM_3 + 1),#0x00
      00254E 90 02 58         [24] 7653 	mov	dptr,#(_axradio_cb_receive + 0x0014)
      002551 75 F0 00         [24] 7654 	mov	b,#0x00
      002554 12 42 6F         [24] 7655 	lcall	_memcpy
      002557                       7656 00120$:
                                   7657 ;	..\COMMON\easyax5043.c:1416: if (axradio_mode == AXRADIO_MODE_ACK_RECEIVE ||
      002557 74 22            [12] 7658 	mov	a,#0x22
      002559 B5 08 02         [24] 7659 	cjne	a,_axradio_mode,00311$
      00255C 80 11            [24] 7660 	sjmp	00154$
      00255E                       7661 00311$:
                                   7662 ;	..\COMMON\easyax5043.c:1417: axradio_mode == AXRADIO_MODE_WOR_ACK_RECEIVE ||
      00255E 74 23            [12] 7663 	mov	a,#0x23
      002560 B5 08 02         [24] 7664 	cjne	a,_axradio_mode,00312$
      002563 80 0A            [24] 7665 	sjmp	00154$
      002565                       7666 00312$:
                                   7667 ;	..\COMMON\easyax5043.c:1418: axradio_mode == AXRADIO_MODE_SYNC_ACK_SLAVE) {
      002565 74 33            [12] 7668 	mov	a,#0x33
      002567 B5 08 02         [24] 7669 	cjne	a,_axradio_mode,00313$
      00256A 80 03            [24] 7670 	sjmp	00314$
      00256C                       7671 00313$:
      00256C 02 27 50         [24] 7672 	ljmp	00155$
      00256F                       7673 00314$:
      00256F                       7674 00154$:
                                   7675 ;	..\COMMON\easyax5043.c:1419: axradio_ack_count = 0;
      00256F 90 00 1D         [24] 7676 	mov	dptr,#_axradio_ack_count
      002572 E4               [12] 7677 	clr	a
      002573 F0               [24] 7678 	movx	@dptr,a
                                   7679 ;	..\COMMON\easyax5043.c:1420: axradio_txbuffer_len = axradio_framing_maclen + axradio_framing_minpayloadlen;
      002574 90 4C B5         [24] 7680 	mov	dptr,#_axradio_framing_maclen
                                   7681 ;	genFromRTrack removed	clr	a
      002577 93               [24] 7682 	movc	a,@a+dptr
      002578 FF               [12] 7683 	mov	r7,a
      002579 FD               [12] 7684 	mov	r5,a
      00257A 7E 00            [12] 7685 	mov	r6,#0x00
      00257C 90 4C CE         [24] 7686 	mov	dptr,#_axradio_framing_minpayloadlen
      00257F E4               [12] 7687 	clr	a
      002580 93               [24] 7688 	movc	a,@a+dptr
      002581 FC               [12] 7689 	mov	r4,a
      002582 7B 00            [12] 7690 	mov	r3,#0x00
      002584 90 00 14         [24] 7691 	mov	dptr,#_axradio_txbuffer_len
      002587 EC               [12] 7692 	mov	a,r4
      002588 2D               [12] 7693 	add	a,r5
      002589 F0               [24] 7694 	movx	@dptr,a
      00258A EB               [12] 7695 	mov	a,r3
      00258B 3E               [12] 7696 	addc	a,r6
      00258C A3               [24] 7697 	inc	dptr
      00258D F0               [24] 7698 	movx	@dptr,a
                                   7699 ;	..\COMMON\easyax5043.c:1421: memset_xdata(axradio_txbuffer, 0, axradio_framing_maclen);
      00258E 8F 2F            [24] 7700 	mov	_memset_PARM_3,r7
                                   7701 ;	1-genFromRTrack replaced	mov	(_memset_PARM_3 + 1),#0x00
      002590 8E 30            [24] 7702 	mov	(_memset_PARM_3 + 1),r6
                                   7703 ;	1-genFromRTrack replaced	mov	_memset_PARM_2,#0x00
      002592 8E 2E            [24] 7704 	mov	_memset_PARM_2,r6
      002594 90 00 3C         [24] 7705 	mov	dptr,#_axradio_txbuffer
      002597 75 F0 00         [24] 7706 	mov	b,#0x00
      00259A 12 42 50         [24] 7707 	lcall	_memset
                                   7708 ;	..\COMMON\easyax5043.c:1422: if (axradio_framing_ack_seqnrpos != 0xff) {
      00259D 90 4C CD         [24] 7709 	mov	dptr,#_axradio_framing_ack_seqnrpos
      0025A0 E4               [12] 7710 	clr	a
      0025A1 93               [24] 7711 	movc	a,@a+dptr
      0025A2 FF               [12] 7712 	mov	r7,a
      0025A3 BF FF 02         [24] 7713 	cjne	r7,#0xff,00315$
      0025A6 80 35            [24] 7714 	sjmp	00125$
      0025A8                       7715 00315$:
                                   7716 ;	..\COMMON\easyax5043.c:1423: uint8_t seqnr = axradio_cb_receive.st.rx.mac.raw[axradio_framing_ack_seqnrpos];
      0025A8 90 02 62         [24] 7717 	mov	dptr,#(_axradio_cb_receive + 0x001e)
      0025AB E0               [24] 7718 	movx	a,@dptr
      0025AC FD               [12] 7719 	mov	r5,a
      0025AD A3               [24] 7720 	inc	dptr
      0025AE E0               [24] 7721 	movx	a,@dptr
      0025AF FE               [12] 7722 	mov	r6,a
      0025B0 EF               [12] 7723 	mov	a,r7
      0025B1 2D               [12] 7724 	add	a,r5
      0025B2 F5 82            [12] 7725 	mov	dpl,a
      0025B4 E4               [12] 7726 	clr	a
      0025B5 3E               [12] 7727 	addc	a,r6
      0025B6 F5 83            [12] 7728 	mov	dph,a
      0025B8 E0               [24] 7729 	movx	a,@dptr
      0025B9 FE               [12] 7730 	mov	r6,a
                                   7731 ;	..\COMMON\easyax5043.c:1424: axradio_txbuffer[axradio_framing_ack_seqnrpos] = seqnr;
      0025BA EF               [12] 7732 	mov	a,r7
      0025BB 24 3C            [12] 7733 	add	a,#_axradio_txbuffer
      0025BD F5 82            [12] 7734 	mov	dpl,a
      0025BF E4               [12] 7735 	clr	a
      0025C0 34 00            [12] 7736 	addc	a,#(_axradio_txbuffer >> 8)
      0025C2 F5 83            [12] 7737 	mov	dph,a
      0025C4 EE               [12] 7738 	mov	a,r6
      0025C5 F0               [24] 7739 	movx	@dptr,a
                                   7740 ;	..\COMMON\easyax5043.c:1425: if (axradio_ack_seqnr != seqnr)
      0025C6 90 00 1E         [24] 7741 	mov	dptr,#_axradio_ack_seqnr
      0025C9 E0               [24] 7742 	movx	a,@dptr
      0025CA FF               [12] 7743 	mov	r7,a
      0025CB B5 06 02         [24] 7744 	cjne	a,ar6,00316$
      0025CE 80 07            [24] 7745 	sjmp	00122$
      0025D0                       7746 00316$:
                                   7747 ;	..\COMMON\easyax5043.c:1426: axradio_ack_seqnr = seqnr;
      0025D0 90 00 1E         [24] 7748 	mov	dptr,#_axradio_ack_seqnr
      0025D3 EE               [12] 7749 	mov	a,r6
      0025D4 F0               [24] 7750 	movx	@dptr,a
      0025D5 80 06            [24] 7751 	sjmp	00125$
      0025D7                       7752 00122$:
                                   7753 ;	..\COMMON\easyax5043.c:1428: axradio_cb_receive.st.error = AXRADIO_ERR_RETRANSMISSION;
      0025D7 90 02 49         [24] 7754 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      0025DA 74 08            [12] 7755 	mov	a,#0x08
      0025DC F0               [24] 7756 	movx	@dptr,a
      0025DD                       7757 00125$:
                                   7758 ;	..\COMMON\easyax5043.c:1430: if (axradio_framing_destaddrpos != 0xff) {
      0025DD 90 4C B7         [24] 7759 	mov	dptr,#_axradio_framing_destaddrpos
      0025E0 E4               [12] 7760 	clr	a
      0025E1 93               [24] 7761 	movc	a,@a+dptr
      0025E2 FF               [12] 7762 	mov	r7,a
      0025E3 BF FF 02         [24] 7763 	cjne	r7,#0xff,00317$
      0025E6 80 57            [24] 7764 	sjmp	00130$
      0025E8                       7765 00317$:
                                   7766 ;	..\COMMON\easyax5043.c:1431: if (axradio_framing_sourceaddrpos != 0xff)
      0025E8 90 4C B8         [24] 7767 	mov	dptr,#_axradio_framing_sourceaddrpos
      0025EB E4               [12] 7768 	clr	a
      0025EC 93               [24] 7769 	movc	a,@a+dptr
      0025ED FE               [12] 7770 	mov	r6,a
      0025EE BE FF 02         [24] 7771 	cjne	r6,#0xff,00318$
      0025F1 80 27            [24] 7772 	sjmp	00127$
      0025F3                       7773 00318$:
                                   7774 ;	..\COMMON\easyax5043.c:1432: memcpy_xdata(&axradio_txbuffer[axradio_framing_destaddrpos], &axradio_cb_receive.st.rx.mac.remoteaddr, axradio_framing_addrlen);
      0025F3 EF               [12] 7775 	mov	a,r7
      0025F4 24 3C            [12] 7776 	add	a,#_axradio_txbuffer
      0025F6 FD               [12] 7777 	mov	r5,a
      0025F7 E4               [12] 7778 	clr	a
      0025F8 34 00            [12] 7779 	addc	a,#(_axradio_txbuffer >> 8)
      0025FA FE               [12] 7780 	mov	r6,a
      0025FB 7C 00            [12] 7781 	mov	r4,#0x00
      0025FD 75 2E 58         [24] 7782 	mov	_memcpy_PARM_2,#(_axradio_cb_receive + 0x0014)
      002600 75 2F 02         [24] 7783 	mov	(_memcpy_PARM_2 + 1),#((_axradio_cb_receive + 0x0014) >> 8)
                                   7784 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_2 + 2),#0x00
      002603 8C 30            [24] 7785 	mov	(_memcpy_PARM_2 + 2),r4
      002605 90 4C B6         [24] 7786 	mov	dptr,#_axradio_framing_addrlen
      002608 E4               [12] 7787 	clr	a
      002609 93               [24] 7788 	movc	a,@a+dptr
      00260A FB               [12] 7789 	mov	r3,a
      00260B 8B 31            [24] 7790 	mov	_memcpy_PARM_3,r3
                                   7791 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_3 + 1),#0x00
      00260D 8C 32            [24] 7792 	mov	(_memcpy_PARM_3 + 1),r4
      00260F 8D 82            [24] 7793 	mov	dpl,r5
      002611 8E 83            [24] 7794 	mov	dph,r6
      002613 8C F0            [24] 7795 	mov	b,r4
      002615 12 42 6F         [24] 7796 	lcall	_memcpy
      002618 80 25            [24] 7797 	sjmp	00130$
      00261A                       7798 00127$:
                                   7799 ;	..\COMMON\easyax5043.c:1434: memcpy_xdata(&axradio_txbuffer[axradio_framing_destaddrpos], &axradio_default_remoteaddr, axradio_framing_addrlen);
      00261A EF               [12] 7800 	mov	a,r7
      00261B 24 3C            [12] 7801 	add	a,#_axradio_txbuffer
      00261D FF               [12] 7802 	mov	r7,a
      00261E E4               [12] 7803 	clr	a
      00261F 34 00            [12] 7804 	addc	a,#(_axradio_txbuffer >> 8)
      002621 FE               [12] 7805 	mov	r6,a
      002622 7D 00            [12] 7806 	mov	r5,#0x00
      002624 75 2E 37         [24] 7807 	mov	_memcpy_PARM_2,#_axradio_default_remoteaddr
      002627 75 2F 00         [24] 7808 	mov	(_memcpy_PARM_2 + 1),#(_axradio_default_remoteaddr >> 8)
                                   7809 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_2 + 2),#0x00
      00262A 8D 30            [24] 7810 	mov	(_memcpy_PARM_2 + 2),r5
      00262C 90 4C B6         [24] 7811 	mov	dptr,#_axradio_framing_addrlen
      00262F E4               [12] 7812 	clr	a
      002630 93               [24] 7813 	movc	a,@a+dptr
      002631 FC               [12] 7814 	mov	r4,a
      002632 8C 31            [24] 7815 	mov	_memcpy_PARM_3,r4
                                   7816 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_3 + 1),#0x00
      002634 8D 32            [24] 7817 	mov	(_memcpy_PARM_3 + 1),r5
      002636 8F 82            [24] 7818 	mov	dpl,r7
      002638 8E 83            [24] 7819 	mov	dph,r6
      00263A 8D F0            [24] 7820 	mov	b,r5
      00263C 12 42 6F         [24] 7821 	lcall	_memcpy
      00263F                       7822 00130$:
                                   7823 ;	..\COMMON\easyax5043.c:1436: if (axradio_framing_sourceaddrpos != 0xff)
      00263F 90 4C B8         [24] 7824 	mov	dptr,#_axradio_framing_sourceaddrpos
      002642 E4               [12] 7825 	clr	a
      002643 93               [24] 7826 	movc	a,@a+dptr
      002644 FF               [12] 7827 	mov	r7,a
      002645 BF FF 02         [24] 7828 	cjne	r7,#0xff,00319$
      002648 80 25            [24] 7829 	sjmp	00132$
      00264A                       7830 00319$:
                                   7831 ;	..\COMMON\easyax5043.c:1437: memcpy_xdata(&axradio_txbuffer[axradio_framing_sourceaddrpos], &axradio_localaddr.addr, axradio_framing_addrlen);
      00264A EF               [12] 7832 	mov	a,r7
      00264B 24 3C            [12] 7833 	add	a,#_axradio_txbuffer
      00264D FF               [12] 7834 	mov	r7,a
      00264E E4               [12] 7835 	clr	a
      00264F 34 00            [12] 7836 	addc	a,#(_axradio_txbuffer >> 8)
      002651 FE               [12] 7837 	mov	r6,a
      002652 7D 00            [12] 7838 	mov	r5,#0x00
      002654 75 2E 2D         [24] 7839 	mov	_memcpy_PARM_2,#_axradio_localaddr
      002657 75 2F 00         [24] 7840 	mov	(_memcpy_PARM_2 + 1),#(_axradio_localaddr >> 8)
                                   7841 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_2 + 2),#0x00
      00265A 8D 30            [24] 7842 	mov	(_memcpy_PARM_2 + 2),r5
      00265C 90 4C B6         [24] 7843 	mov	dptr,#_axradio_framing_addrlen
      00265F E4               [12] 7844 	clr	a
      002660 93               [24] 7845 	movc	a,@a+dptr
      002661 FC               [12] 7846 	mov	r4,a
      002662 8C 31            [24] 7847 	mov	_memcpy_PARM_3,r4
                                   7848 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_3 + 1),#0x00
      002664 8D 32            [24] 7849 	mov	(_memcpy_PARM_3 + 1),r5
      002666 8F 82            [24] 7850 	mov	dpl,r7
      002668 8E 83            [24] 7851 	mov	dph,r6
      00266A 8D F0            [24] 7852 	mov	b,r5
      00266C 12 42 6F         [24] 7853 	lcall	_memcpy
      00266F                       7854 00132$:
                                   7855 ;	..\COMMON\easyax5043.c:1438: if (axradio_framing_lenmask) {
      00266F 90 4C BB         [24] 7856 	mov	dptr,#_axradio_framing_lenmask
      002672 E4               [12] 7857 	clr	a
      002673 93               [24] 7858 	movc	a,@a+dptr
      002674 FF               [12] 7859 	mov	r7,a
      002675 60 30            [24] 7860 	jz	00134$
                                   7861 ;	..\COMMON\easyax5043.c:1439: uint8_t len_byte = (uint8_t)(axradio_txbuffer_len - axradio_framing_lenoffs) & axradio_framing_lenmask; // if you prefer not counting the len byte itself, set LENOFFS = 1
      002677 90 00 14         [24] 7862 	mov	dptr,#_axradio_txbuffer_len
      00267A E0               [24] 7863 	movx	a,@dptr
      00267B FD               [12] 7864 	mov	r5,a
      00267C A3               [24] 7865 	inc	dptr
      00267D E0               [24] 7866 	movx	a,@dptr
      00267E 90 4C BA         [24] 7867 	mov	dptr,#_axradio_framing_lenoffs
      002681 E4               [12] 7868 	clr	a
      002682 93               [24] 7869 	movc	a,@a+dptr
      002683 FE               [12] 7870 	mov	r6,a
      002684 ED               [12] 7871 	mov	a,r5
      002685 C3               [12] 7872 	clr	c
      002686 9E               [12] 7873 	subb	a,r6
      002687 5F               [12] 7874 	anl	a,r7
      002688 FE               [12] 7875 	mov	r6,a
                                   7876 ;	..\COMMON\easyax5043.c:1440: axradio_txbuffer[axradio_framing_lenpos] = (axradio_txbuffer[axradio_framing_lenpos] & (uint8_t)~axradio_framing_lenmask) | len_byte;
      002689 90 4C B9         [24] 7877 	mov	dptr,#_axradio_framing_lenpos
      00268C E4               [12] 7878 	clr	a
      00268D 93               [24] 7879 	movc	a,@a+dptr
      00268E 24 3C            [12] 7880 	add	a,#_axradio_txbuffer
      002690 FD               [12] 7881 	mov	r5,a
      002691 E4               [12] 7882 	clr	a
      002692 34 00            [12] 7883 	addc	a,#(_axradio_txbuffer >> 8)
      002694 FC               [12] 7884 	mov	r4,a
      002695 8D 82            [24] 7885 	mov	dpl,r5
      002697 8C 83            [24] 7886 	mov	dph,r4
      002699 E0               [24] 7887 	movx	a,@dptr
      00269A FB               [12] 7888 	mov	r3,a
      00269B EF               [12] 7889 	mov	a,r7
      00269C F4               [12] 7890 	cpl	a
      00269D FF               [12] 7891 	mov	r7,a
      00269E 5B               [12] 7892 	anl	a,r3
      00269F 42 06            [12] 7893 	orl	ar6,a
      0026A1 8D 82            [24] 7894 	mov	dpl,r5
      0026A3 8C 83            [24] 7895 	mov	dph,r4
      0026A5 EE               [12] 7896 	mov	a,r6
      0026A6 F0               [24] 7897 	movx	@dptr,a
      0026A7                       7898 00134$:
                                   7899 ;	..\COMMON\easyax5043.c:1442: if (axradio_framing_swcrclen)
      0026A7 90 4C BC         [24] 7900 	mov	dptr,#_axradio_framing_swcrclen
      0026AA E4               [12] 7901 	clr	a
      0026AB 93               [24] 7902 	movc	a,@a+dptr
      0026AC 60 20            [24] 7903 	jz	00136$
                                   7904 ;	..\COMMON\easyax5043.c:1443: axradio_txbuffer_len = axradio_framing_append_crc(axradio_txbuffer, axradio_txbuffer_len);
      0026AE 90 00 14         [24] 7905 	mov	dptr,#_axradio_txbuffer_len
      0026B1 E0               [24] 7906 	movx	a,@dptr
      0026B2 C0 E0            [24] 7907 	push	acc
      0026B4 A3               [24] 7908 	inc	dptr
      0026B5 E0               [24] 7909 	movx	a,@dptr
      0026B6 C0 E0            [24] 7910 	push	acc
      0026B8 90 00 3C         [24] 7911 	mov	dptr,#_axradio_txbuffer
      0026BB 12 0A 1A         [24] 7912 	lcall	_axradio_framing_append_crc
      0026BE AE 82            [24] 7913 	mov	r6,dpl
      0026C0 AF 83            [24] 7914 	mov	r7,dph
      0026C2 15 81            [12] 7915 	dec	sp
      0026C4 15 81            [12] 7916 	dec	sp
      0026C6 90 00 14         [24] 7917 	mov	dptr,#_axradio_txbuffer_len
      0026C9 EE               [12] 7918 	mov	a,r6
      0026CA F0               [24] 7919 	movx	@dptr,a
      0026CB EF               [12] 7920 	mov	a,r7
      0026CC A3               [24] 7921 	inc	dptr
      0026CD F0               [24] 7922 	movx	@dptr,a
      0026CE                       7923 00136$:
                                   7924 ;	..\COMMON\easyax5043.c:1444: if (axradio_phy_pn9) {
      0026CE 90 4C 70         [24] 7925 	mov	dptr,#_axradio_phy_pn9
      0026D1 E4               [12] 7926 	clr	a
      0026D2 93               [24] 7927 	movc	a,@a+dptr
      0026D3 60 2F            [24] 7928 	jz	00139$
                                   7929 ;	..\COMMON\easyax5043.c:1445: pn9_buffer(axradio_txbuffer, axradio_txbuffer_len, 0x1ff, -(radio_read8(AX5043_REG_ENCODING) & 0x01));
      0026D5 90 40 11         [24] 7930 	mov	dptr,#0x4011
      0026D8 E0               [24] 7931 	movx	a,@dptr
      0026D9 FF               [12] 7932 	mov	r7,a
      0026DA 53 07 01         [24] 7933 	anl	ar7,#0x01
      0026DD C3               [12] 7934 	clr	c
      0026DE E4               [12] 7935 	clr	a
      0026DF 9F               [12] 7936 	subb	a,r7
      0026E0 FF               [12] 7937 	mov	r7,a
      0026E1 C0 07            [24] 7938 	push	ar7
      0026E3 74 FF            [12] 7939 	mov	a,#0xff
      0026E5 C0 E0            [24] 7940 	push	acc
      0026E7 74 01            [12] 7941 	mov	a,#0x01
      0026E9 C0 E0            [24] 7942 	push	acc
      0026EB 90 00 14         [24] 7943 	mov	dptr,#_axradio_txbuffer_len
      0026EE E0               [24] 7944 	movx	a,@dptr
      0026EF C0 E0            [24] 7945 	push	acc
      0026F1 A3               [24] 7946 	inc	dptr
      0026F2 E0               [24] 7947 	movx	a,@dptr
      0026F3 C0 E0            [24] 7948 	push	acc
      0026F5 90 00 3C         [24] 7949 	mov	dptr,#_axradio_txbuffer
      0026F8 75 F0 00         [24] 7950 	mov	b,#0x00
      0026FB 12 43 BF         [24] 7951 	lcall	_pn9_buffer
      0026FE E5 81            [12] 7952 	mov	a,sp
      002700 24 FB            [12] 7953 	add	a,#0xfb
      002702 F5 81            [12] 7954 	mov	sp,a
                                   7955 ;	..\COMMON\easyax5043.c:1447: radio_write8(AX5043_REG_IRQMASK1, 0x00);
      002704                       7956 00139$:
      002704 90 40 06         [24] 7957 	mov	dptr,#0x4006
      002707 E4               [12] 7958 	clr	a
      002708 F0               [24] 7959 	movx	@dptr,a
                                   7960 ;	..\COMMON\easyax5043.c:1448: radio_write8(AX5043_REG_IRQMASK0, 0x00);
      002709 90 40 07         [24] 7961 	mov	dptr,#0x4007
      00270C F0               [24] 7962 	movx	@dptr,a
                                   7963 ;	..\COMMON\easyax5043.c:1449: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_XTAL_ON);
      00270D 90 40 02         [24] 7964 	mov	dptr,#0x4002
      002710 74 05            [12] 7965 	mov	a,#0x05
      002712 F0               [24] 7966 	movx	@dptr,a
                                   7967 ;	..\COMMON\easyax5043.c:1450: radio_write8(AX5043_REG_FIFOSTAT, 3);
      002713 90 40 28         [24] 7968 	mov	dptr,#0x4028
      002716 74 03            [12] 7969 	mov	a,#0x03
      002718 F0               [24] 7970 	movx	@dptr,a
                                   7971 ;	..\COMMON\easyax5043.c:1451: axradio_trxstate = trxstate_tx_longpreamble; // ensure that trxstate != off, otherwise we would prematurely enable the receiver, see below
      002719 75 09 0A         [24] 7972 	mov	_axradio_trxstate,#0x0a
                                   7973 ;	..\COMMON\easyax5043.c:1452: while (radio_read8(AX5043_REG_POWSTAT) & 0x08);
      00271C                       7974 00151$:
      00271C 90 40 03         [24] 7975 	mov	dptr,#0x4003
      00271F E0               [24] 7976 	movx	a,@dptr
      002720 FF               [12] 7977 	mov	r7,a
      002721 20 E3 F8         [24] 7978 	jb	acc.3,00151$
                                   7979 ;	..\COMMON\easyax5043.c:1453: wtimer_remove(&axradio_timer);
      002724 90 02 9D         [24] 7980 	mov	dptr,#_axradio_timer
      002727 12 47 8D         [24] 7981 	lcall	_wtimer_remove
                                   7982 ;	..\COMMON\easyax5043.c:1454: axradio_timer.time = axradio_framing_ack_delay;
      00272A 90 4C C8         [24] 7983 	mov	dptr,#_axradio_framing_ack_delay
      00272D E4               [12] 7984 	clr	a
      00272E 93               [24] 7985 	movc	a,@a+dptr
      00272F FC               [12] 7986 	mov	r4,a
      002730 74 01            [12] 7987 	mov	a,#0x01
      002732 93               [24] 7988 	movc	a,@a+dptr
      002733 FD               [12] 7989 	mov	r5,a
      002734 74 02            [12] 7990 	mov	a,#0x02
      002736 93               [24] 7991 	movc	a,@a+dptr
      002737 FE               [12] 7992 	mov	r6,a
      002738 74 03            [12] 7993 	mov	a,#0x03
      00273A 93               [24] 7994 	movc	a,@a+dptr
      00273B FF               [12] 7995 	mov	r7,a
      00273C 90 02 A1         [24] 7996 	mov	dptr,#(_axradio_timer + 0x0004)
      00273F EC               [12] 7997 	mov	a,r4
      002740 F0               [24] 7998 	movx	@dptr,a
      002741 ED               [12] 7999 	mov	a,r5
      002742 A3               [24] 8000 	inc	dptr
      002743 F0               [24] 8001 	movx	@dptr,a
      002744 EE               [12] 8002 	mov	a,r6
      002745 A3               [24] 8003 	inc	dptr
      002746 F0               [24] 8004 	movx	@dptr,a
      002747 EF               [12] 8005 	mov	a,r7
      002748 A3               [24] 8006 	inc	dptr
      002749 F0               [24] 8007 	movx	@dptr,a
                                   8008 ;	..\COMMON\easyax5043.c:1455: wtimer1_addrelative(&axradio_timer);
      00274A 90 02 9D         [24] 8009 	mov	dptr,#_axradio_timer
      00274D 12 43 25         [24] 8010 	lcall	_wtimer1_addrelative
      002750                       8011 00155$:
                                   8012 ;	..\COMMON\easyax5043.c:1457: if (axradio_mode == AXRADIO_MODE_SYNC_SLAVE ||
      002750 74 32            [12] 8013 	mov	a,#0x32
      002752 B5 08 02         [24] 8014 	cjne	a,_axradio_mode,00324$
      002755 80 0A            [24] 8015 	sjmp	00168$
      002757                       8016 00324$:
                                   8017 ;	..\COMMON\easyax5043.c:1458: axradio_mode == AXRADIO_MODE_SYNC_ACK_SLAVE) {
      002757 74 33            [12] 8018 	mov	a,#0x33
      002759 B5 08 02         [24] 8019 	cjne	a,_axradio_mode,00325$
      00275C 80 03            [24] 8020 	sjmp	00326$
      00275E                       8021 00325$:
      00275E 02 28 34         [24] 8022 	ljmp	00169$
      002761                       8023 00326$:
      002761                       8024 00168$:
                                   8025 ;	..\COMMON\easyax5043.c:1459: if (axradio_mode != AXRADIO_MODE_SYNC_ACK_SLAVE)
      002761 74 33            [12] 8026 	mov	a,#0x33
      002763 B5 08 02         [24] 8027 	cjne	a,_axradio_mode,00327$
      002766 80 03            [24] 8028 	sjmp	00159$
      002768                       8029 00327$:
                                   8030 ;	..\COMMON\easyax5043.c:1460: ax5043_off();
      002768 12 17 8A         [24] 8031 	lcall	_ax5043_off
      00276B                       8032 00159$:
                                   8033 ;	..\COMMON\easyax5043.c:1461: switch (axradio_syncstate) {
      00276B 90 00 13         [24] 8034 	mov	dptr,#_axradio_syncstate
      00276E E0               [24] 8035 	movx	a,@dptr
      00276F FF               [12] 8036 	mov	r7,a
      002770 BF 08 02         [24] 8037 	cjne	r7,#0x08,00328$
      002773 80 45            [24] 8038 	sjmp	00163$
      002775                       8039 00328$:
      002775 BF 0A 02         [24] 8040 	cjne	r7,#0x0a,00329$
      002778 80 40            [24] 8041 	sjmp	00163$
      00277A                       8042 00329$:
      00277A BF 0B 02         [24] 8043 	cjne	r7,#0x0b,00330$
      00277D 80 3B            [24] 8044 	sjmp	00163$
      00277F                       8045 00330$:
                                   8046 ;	..\COMMON\easyax5043.c:1465: axradio_sync_time = axradio_conv_time_totimer0(axradio_cb_receive.st.time.t);
      00277F 90 02 4A         [24] 8047 	mov	dptr,#(_axradio_cb_receive + 0x0006)
      002782 E0               [24] 8048 	movx	a,@dptr
      002783 FC               [12] 8049 	mov	r4,a
      002784 A3               [24] 8050 	inc	dptr
      002785 E0               [24] 8051 	movx	a,@dptr
      002786 FD               [12] 8052 	mov	r5,a
      002787 A3               [24] 8053 	inc	dptr
      002788 E0               [24] 8054 	movx	a,@dptr
      002789 FE               [12] 8055 	mov	r6,a
      00278A A3               [24] 8056 	inc	dptr
      00278B E0               [24] 8057 	movx	a,@dptr
      00278C 8C 82            [24] 8058 	mov	dpl,r4
      00278E 8D 83            [24] 8059 	mov	dph,r5
      002790 8E F0            [24] 8060 	mov	b,r6
      002792 12 0A BE         [24] 8061 	lcall	_axradio_conv_time_totimer0
      002795 AC 82            [24] 8062 	mov	r4,dpl
      002797 AD 83            [24] 8063 	mov	r5,dph
      002799 AE F0            [24] 8064 	mov	r6,b
      00279B FF               [12] 8065 	mov	r7,a
      00279C 90 00 1F         [24] 8066 	mov	dptr,#_axradio_sync_time
      00279F EC               [12] 8067 	mov	a,r4
      0027A0 F0               [24] 8068 	movx	@dptr,a
      0027A1 ED               [12] 8069 	mov	a,r5
      0027A2 A3               [24] 8070 	inc	dptr
      0027A3 F0               [24] 8071 	movx	@dptr,a
      0027A4 EE               [12] 8072 	mov	a,r6
      0027A5 A3               [24] 8073 	inc	dptr
      0027A6 F0               [24] 8074 	movx	@dptr,a
      0027A7 EF               [12] 8075 	mov	a,r7
      0027A8 A3               [24] 8076 	inc	dptr
      0027A9 F0               [24] 8077 	movx	@dptr,a
                                   8078 ;	..\COMMON\easyax5043.c:1466: axradio_sync_periodcorr = -32768;
      0027AA 90 00 23         [24] 8079 	mov	dptr,#_axradio_sync_periodcorr
      0027AD E4               [12] 8080 	clr	a
      0027AE F0               [24] 8081 	movx	@dptr,a
      0027AF 74 80            [12] 8082 	mov	a,#0x80
      0027B1 A3               [24] 8083 	inc	dptr
      0027B2 F0               [24] 8084 	movx	@dptr,a
                                   8085 ;	..\COMMON\easyax5043.c:1467: axradio_sync_seqnr = 0;
      0027B3 90 00 1E         [24] 8086 	mov	dptr,#_axradio_ack_seqnr
      0027B6 E4               [12] 8087 	clr	a
      0027B7 F0               [24] 8088 	movx	@dptr,a
                                   8089 ;	..\COMMON\easyax5043.c:1468: break;
                                   8090 ;	..\COMMON\easyax5043.c:1472: case syncstate_slave_rxpacket:
      0027B8 80 2D            [24] 8091 	sjmp	00164$
      0027BA                       8092 00163$:
                                   8093 ;	..\COMMON\easyax5043.c:1473: axradio_sync_adjustperiodcorr();
      0027BA 12 19 D2         [24] 8094 	lcall	_axradio_sync_adjustperiodcorr
                                   8095 ;	..\COMMON\easyax5043.c:1474: axradio_cb_receive.st.rx.phy.period = axradio_sync_periodcorr >> SYNC_K1;
      0027BD 90 00 23         [24] 8096 	mov	dptr,#_axradio_sync_periodcorr
      0027C0 E0               [24] 8097 	movx	a,@dptr
      0027C1 FE               [12] 8098 	mov	r6,a
      0027C2 A3               [24] 8099 	inc	dptr
      0027C3 E0               [24] 8100 	movx	a,@dptr
      0027C4 FF               [12] 8101 	mov	r7,a
      0027C5 C4               [12] 8102 	swap	a
      0027C6 03               [12] 8103 	rr	a
      0027C7 CE               [12] 8104 	xch	a,r6
      0027C8 C4               [12] 8105 	swap	a
      0027C9 03               [12] 8106 	rr	a
      0027CA 54 07            [12] 8107 	anl	a,#0x07
      0027CC 6E               [12] 8108 	xrl	a,r6
      0027CD CE               [12] 8109 	xch	a,r6
      0027CE 54 07            [12] 8110 	anl	a,#0x07
      0027D0 CE               [12] 8111 	xch	a,r6
      0027D1 6E               [12] 8112 	xrl	a,r6
      0027D2 CE               [12] 8113 	xch	a,r6
      0027D3 30 E2 02         [24] 8114 	jnb	acc.2,00331$
      0027D6 44 F8            [12] 8115 	orl	a,#0xf8
      0027D8                       8116 00331$:
      0027D8 FF               [12] 8117 	mov	r7,a
      0027D9 90 02 56         [24] 8118 	mov	dptr,#(_axradio_cb_receive + 0x0012)
      0027DC EE               [12] 8119 	mov	a,r6
      0027DD F0               [24] 8120 	movx	@dptr,a
      0027DE EF               [12] 8121 	mov	a,r7
      0027DF A3               [24] 8122 	inc	dptr
      0027E0 F0               [24] 8123 	movx	@dptr,a
                                   8124 ;	..\COMMON\easyax5043.c:1475: axradio_sync_seqnr = 1;
      0027E1 90 00 1E         [24] 8125 	mov	dptr,#_axradio_ack_seqnr
      0027E4 74 01            [12] 8126 	mov	a,#0x01
      0027E6 F0               [24] 8127 	movx	@dptr,a
                                   8128 ;	..\COMMON\easyax5043.c:1477: };
      0027E7                       8129 00164$:
                                   8130 ;	..\COMMON\easyax5043.c:1478: axradio_sync_slave_nextperiod();
      0027E7 12 1A F9         [24] 8131 	lcall	_axradio_sync_slave_nextperiod
                                   8132 ;	..\COMMON\easyax5043.c:1479: if (axradio_mode != AXRADIO_MODE_SYNC_ACK_SLAVE) {
      0027EA 74 33            [12] 8133 	mov	a,#0x33
      0027EC B5 08 02         [24] 8134 	cjne	a,_axradio_mode,00332$
      0027EF 80 3D            [24] 8135 	sjmp	00166$
      0027F1                       8136 00332$:
                                   8137 ;	..\COMMON\easyax5043.c:1480: axradio_syncstate = syncstate_slave_rxidle;
      0027F1 90 00 13         [24] 8138 	mov	dptr,#_axradio_syncstate
      0027F4 74 08            [12] 8139 	mov	a,#0x08
      0027F6 F0               [24] 8140 	movx	@dptr,a
                                   8141 ;	..\COMMON\easyax5043.c:1481: wtimer_remove(&axradio_timer);
      0027F7 90 02 9D         [24] 8142 	mov	dptr,#_axradio_timer
      0027FA 12 47 8D         [24] 8143 	lcall	_wtimer_remove
                                   8144 ;	..\COMMON\easyax5043.c:1482: axradio_sync_settimeradv(axradio_sync_slave_rxadvance[axradio_sync_seqnr]);
      0027FD 90 00 1E         [24] 8145 	mov	dptr,#_axradio_ack_seqnr
      002800 E0               [24] 8146 	movx	a,@dptr
      002801 75 F0 04         [24] 8147 	mov	b,#0x04
      002804 A4               [48] 8148 	mul	ab
      002805 24 E9            [12] 8149 	add	a,#_axradio_sync_slave_rxadvance
      002807 F5 82            [12] 8150 	mov	dpl,a
      002809 74 4C            [12] 8151 	mov	a,#(_axradio_sync_slave_rxadvance >> 8)
      00280B 35 F0            [12] 8152 	addc	a,b
      00280D F5 83            [12] 8153 	mov	dph,a
      00280F E4               [12] 8154 	clr	a
      002810 93               [24] 8155 	movc	a,@a+dptr
      002811 FC               [12] 8156 	mov	r4,a
      002812 A3               [24] 8157 	inc	dptr
      002813 E4               [12] 8158 	clr	a
      002814 93               [24] 8159 	movc	a,@a+dptr
      002815 FD               [12] 8160 	mov	r5,a
      002816 A3               [24] 8161 	inc	dptr
      002817 E4               [12] 8162 	clr	a
      002818 93               [24] 8163 	movc	a,@a+dptr
      002819 FE               [12] 8164 	mov	r6,a
      00281A A3               [24] 8165 	inc	dptr
      00281B E4               [12] 8166 	clr	a
      00281C 93               [24] 8167 	movc	a,@a+dptr
      00281D 8C 82            [24] 8168 	mov	dpl,r4
      00281F 8D 83            [24] 8169 	mov	dph,r5
      002821 8E F0            [24] 8170 	mov	b,r6
      002823 12 19 93         [24] 8171 	lcall	_axradio_sync_settimeradv
                                   8172 ;	..\COMMON\easyax5043.c:1483: wtimer0_addabsolute(&axradio_timer);
      002826 90 02 9D         [24] 8173 	mov	dptr,#_axradio_timer
      002829 12 43 6C         [24] 8174 	lcall	_wtimer0_addabsolute
      00282C 80 06            [24] 8175 	sjmp	00169$
      00282E                       8176 00166$:
                                   8177 ;	..\COMMON\easyax5043.c:1485: axradio_syncstate = syncstate_slave_rxack;
      00282E 90 00 13         [24] 8178 	mov	dptr,#_axradio_syncstate
      002831 74 0C            [12] 8179 	mov	a,#0x0c
      002833 F0               [24] 8180 	movx	@dptr,a
      002834                       8181 00169$:
                                   8182 ;	..\COMMON\easyax5043.c:1488: axradio_statuschange((struct axradio_status __xdata *)&axradio_cb_receive.st);
      002834 90 02 48         [24] 8183 	mov	dptr,#(_axradio_cb_receive + 0x0004)
      002837 12 3C 6F         [24] 8184 	lcall	_axradio_statuschange
                                   8185 ;	..\COMMON\easyax5043.c:1489: endcb:
      00283A                       8186 00171$:
                                   8187 ;	..\COMMON\easyax5043.c:1490: if (axradio_mode == AXRADIO_MODE_WOR_RECEIVE) {
      00283A 74 21            [12] 8188 	mov	a,#0x21
      00283C B5 08 03         [24] 8189 	cjne	a,_axradio_mode,00189$
                                   8190 ;	..\COMMON\easyax5043.c:1491: ax5043_receiver_on_wor();
      00283F 02 16 A2         [24] 8191 	ljmp	_ax5043_receiver_on_wor
      002842                       8192 00189$:
                                   8193 ;	..\COMMON\easyax5043.c:1492: } else if (axradio_mode == AXRADIO_MODE_ACK_RECEIVE ||
      002842 74 22            [12] 8194 	mov	a,#0x22
      002844 B5 08 02         [24] 8195 	cjne	a,_axradio_mode,00335$
      002847 80 05            [24] 8196 	sjmp	00184$
      002849                       8197 00335$:
                                   8198 ;	..\COMMON\easyax5043.c:1493: axradio_mode == AXRADIO_MODE_WOR_ACK_RECEIVE) {
      002849 74 23            [12] 8199 	mov	a,#0x23
      00284B B5 08 20         [24] 8200 	cjne	a,_axradio_mode,00185$
      00284E                       8201 00184$:
                                   8202 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:351: criticalsection_t crit = IE & 0x80;
      00284E 74 80            [12] 8203 	mov	a,#0x80
      002850 55 A8            [12] 8204 	anl	a,_IE
      002852 FF               [12] 8205 	mov	r7,a
                                   8206 ;	..\COMMON\easyax5043.c:1496: criticalsection_t crit = enter_critical();
      002853 C2 AF            [12] 8207 	clr	_EA
                                   8208 ;	..\COMMON\easyax5043.c:1497: trxst = axradio_trxstate;
      002855 AE 09            [24] 8209 	mov	r6,_axradio_trxstate
                                   8210 ;	..\COMMON\easyax5043.c:1498: axradio_cb_receive.st.error = AXRADIO_ERR_PACKETDONE;
      002857 90 02 49         [24] 8211 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      00285A 74 F0            [12] 8212 	mov	a,#0xf0
      00285C F0               [24] 8213 	movx	@dptr,a
                                   8214 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:358: IE |= crit;
      00285D EF               [12] 8215 	mov	a,r7
      00285E 42 A8            [12] 8216 	orl	_IE,a
                                   8217 ;	..\COMMON\easyax5043.c:1501: if (trxst == trxstate_off) {
      002860 EE               [12] 8218 	mov	a,r6
      002861 70 1D            [24] 8219 	jnz	00193$
                                   8220 ;	..\COMMON\easyax5043.c:1502: if (axradio_mode == AXRADIO_MODE_WOR_ACK_RECEIVE)
      002863 74 23            [12] 8221 	mov	a,#0x23
      002865 B5 08 03         [24] 8222 	cjne	a,_axradio_mode,00173$
                                   8223 ;	..\COMMON\easyax5043.c:1503: ax5043_receiver_on_wor();
      002868 02 16 A2         [24] 8224 	ljmp	_ax5043_receiver_on_wor
      00286B                       8225 00173$:
                                   8226 ;	..\COMMON\easyax5043.c:1505: ax5043_receiver_on_continuous();
      00286B 02 16 3B         [24] 8227 	ljmp	_ax5043_receiver_on_continuous
      00286E                       8228 00185$:
                                   8229 ;	..\COMMON\easyax5043.c:1508: switch (axradio_trxstate) {
      00286E AF 09            [24] 8230 	mov	r7,_axradio_trxstate
      002870 BF 01 02         [24] 8231 	cjne	r7,#0x01,00341$
      002873 80 03            [24] 8232 	sjmp	00179$
      002875                       8233 00341$:
      002875 BF 02 08         [24] 8234 	cjne	r7,#0x02,00193$
                                   8235 ;	..\COMMON\easyax5043.c:1511: radio_write8(AX5043_REG_IRQMASK0, (radio_read8(AX5043_REG_IRQMASK0) | 0x01)); // re-enable FIFO not empty irq
      002878                       8236 00179$:
      002878 90 40 07         [24] 8237 	mov	dptr,#0x4007
      00287B E0               [24] 8238 	movx	a,@dptr
      00287C 44 01            [12] 8239 	orl	a,#0x01
      00287E FF               [12] 8240 	mov	r7,a
      00287F F0               [24] 8241 	movx	@dptr,a
                                   8242 ;	..\COMMON\easyax5043.c:1516: }
      002880                       8243 00193$:
      002880 22               [24] 8244 	ret
                                   8245 ;------------------------------------------------------------
                                   8246 ;Allocation info for local variables in function 'axradio_killallcb'
                                   8247 ;------------------------------------------------------------
                                   8248 ;	..\COMMON\easyax5043.c:1520: static void axradio_killallcb(void)
                                   8249 ;	-----------------------------------------
                                   8250 ;	 function axradio_killallcb
                                   8251 ;	-----------------------------------------
      002881                       8252 _axradio_killallcb:
                                   8253 ;	..\COMMON\easyax5043.c:1522: wtimer_remove_callback(&axradio_cb_receive.cb);
      002881 90 02 44         [24] 8254 	mov	dptr,#_axradio_cb_receive
      002884 12 48 82         [24] 8255 	lcall	_wtimer_remove_callback
                                   8256 ;	..\COMMON\easyax5043.c:1523: wtimer_remove_callback(&axradio_cb_receivesfd.cb);
      002887 90 02 68         [24] 8257 	mov	dptr,#_axradio_cb_receivesfd
      00288A 12 48 82         [24] 8258 	lcall	_wtimer_remove_callback
                                   8259 ;	..\COMMON\easyax5043.c:1524: wtimer_remove_callback(&axradio_cb_channelstate.cb);
      00288D 90 02 72         [24] 8260 	mov	dptr,#_axradio_cb_channelstate
      002890 12 48 82         [24] 8261 	lcall	_wtimer_remove_callback
                                   8262 ;	..\COMMON\easyax5043.c:1525: wtimer_remove_callback(&axradio_cb_transmitstart.cb);
      002893 90 02 7F         [24] 8263 	mov	dptr,#_axradio_cb_transmitstart
      002896 12 48 82         [24] 8264 	lcall	_wtimer_remove_callback
                                   8265 ;	..\COMMON\easyax5043.c:1526: wtimer_remove_callback(&axradio_cb_transmitend.cb);
      002899 90 02 89         [24] 8266 	mov	dptr,#_axradio_cb_transmitend
      00289C 12 48 82         [24] 8267 	lcall	_wtimer_remove_callback
                                   8268 ;	..\COMMON\easyax5043.c:1527: wtimer_remove_callback(&axradio_cb_transmitdata.cb);
      00289F 90 02 93         [24] 8269 	mov	dptr,#_axradio_cb_transmitdata
      0028A2 12 48 82         [24] 8270 	lcall	_wtimer_remove_callback
                                   8271 ;	..\COMMON\easyax5043.c:1528: wtimer_remove(&axradio_timer);
      0028A5 90 02 9D         [24] 8272 	mov	dptr,#_axradio_timer
      0028A8 02 47 8D         [24] 8273 	ljmp	_wtimer_remove
                                   8274 ;------------------------------------------------------------
                                   8275 ;Allocation info for local variables in function 'axradio_tunevoltage'
                                   8276 ;------------------------------------------------------------
                                   8277 ;r                         Allocated to registers r6 r7 
                                   8278 ;cnt                       Allocated to registers r5 
                                   8279 ;x                         Allocated to registers r4 r3 
                                   8280 ;------------------------------------------------------------
                                   8281 ;	..\COMMON\easyax5043.c:1555: static int16_t axradio_tunevoltage(void)
                                   8282 ;	-----------------------------------------
                                   8283 ;	 function axradio_tunevoltage
                                   8284 ;	-----------------------------------------
      0028AB                       8285 _axradio_tunevoltage:
                                   8286 ;	..\COMMON\easyax5043.c:1557: int16_t __autodata r = 0;
      0028AB 7E 00            [12] 8287 	mov	r6,#0x00
      0028AD 7F 00            [12] 8288 	mov	r7,#0x00
                                   8289 ;	..\COMMON\easyax5043.c:1560: radio_write8(AX5043_REG_GPADCCTRL, 0x84);
      0028AF 7D 40            [12] 8290 	mov	r5,#0x40
      0028B1                       8291 00101$:
      0028B1 90 43 00         [24] 8292 	mov	dptr,#0x4300
      0028B4 74 84            [12] 8293 	mov	a,#0x84
      0028B6 F0               [24] 8294 	movx	@dptr,a
                                   8295 ;	..\COMMON\easyax5043.c:1561: do {} while (radio_read8(AX5043_REG_GPADCCTRL) & 0x80);
      0028B7                       8296 00104$:
      0028B7 90 43 00         [24] 8297 	mov	dptr,#0x4300
      0028BA E0               [24] 8298 	movx	a,@dptr
      0028BB FC               [12] 8299 	mov	r4,a
      0028BC 20 E7 F8         [24] 8300 	jb	acc.7,00104$
                                   8301 ;	..\COMMON\easyax5043.c:1562: } while (--cnt);
      0028BF DD F0            [24] 8302 	djnz	r5,00101$
                                   8303 ;	..\COMMON\easyax5043.c:1565: radio_write8(AX5043_REG_GPADCCTRL, 0x84);
      0028C1 7D 20            [12] 8304 	mov	r5,#0x20
      0028C3                       8305 00109$:
      0028C3 90 43 00         [24] 8306 	mov	dptr,#0x4300
      0028C6 74 84            [12] 8307 	mov	a,#0x84
      0028C8 F0               [24] 8308 	movx	@dptr,a
                                   8309 ;	..\COMMON\easyax5043.c:1566: do {} while (radio_read8(AX5043_REG_GPADCCTRL) & 0x80);
      0028C9                       8310 00112$:
      0028C9 90 43 00         [24] 8311 	mov	dptr,#0x4300
      0028CC E0               [24] 8312 	movx	a,@dptr
      0028CD FC               [12] 8313 	mov	r4,a
      0028CE 20 E7 F8         [24] 8314 	jb	acc.7,00112$
                                   8315 ;	..\COMMON\easyax5043.c:1568: int16_t x = radio_read8(AX5043_REG_GPADC13VALUE1) & 0x03;
      0028D1 90 43 08         [24] 8316 	mov	dptr,#0x4308
      0028D4 E0               [24] 8317 	movx	a,@dptr
      0028D5 FC               [12] 8318 	mov	r4,a
      0028D6 53 04 03         [24] 8319 	anl	ar4,#0x03
                                   8320 ;	..\COMMON\easyax5043.c:1569: x <<= 8;
      0028D9 8C 03            [24] 8321 	mov	ar3,r4
      0028DB 7C 00            [12] 8322 	mov	r4,#0x00
                                   8323 ;	..\COMMON\easyax5043.c:1570: x |= radio_read8(AX5043_REG_GPADC13VALUE0);
      0028DD 90 43 09         [24] 8324 	mov	dptr,#0x4309
      0028E0 E0               [24] 8325 	movx	a,@dptr
      0028E1 F9               [12] 8326 	mov	r1,a
      0028E2 7A 00            [12] 8327 	mov	r2,#0x00
      0028E4 E9               [12] 8328 	mov	a,r1
      0028E5 42 04            [12] 8329 	orl	ar4,a
      0028E7 EA               [12] 8330 	mov	a,r2
      0028E8 42 03            [12] 8331 	orl	ar3,a
                                   8332 ;	..\COMMON\easyax5043.c:1571: r += x;
      0028EA EC               [12] 8333 	mov	a,r4
      0028EB 2E               [12] 8334 	add	a,r6
      0028EC FE               [12] 8335 	mov	r6,a
      0028ED EB               [12] 8336 	mov	a,r3
      0028EE 3F               [12] 8337 	addc	a,r7
      0028EF FF               [12] 8338 	mov	r7,a
                                   8339 ;	..\COMMON\easyax5043.c:1573: } while (--cnt);
      0028F0 DD D1            [24] 8340 	djnz	r5,00109$
                                   8341 ;	..\COMMON\easyax5043.c:1574: return r;
      0028F2 8E 82            [24] 8342 	mov	dpl,r6
      0028F4 8F 83            [24] 8343 	mov	dph,r7
      0028F6 22               [24] 8344 	ret
                                   8345 ;------------------------------------------------------------
                                   8346 ;Allocation info for local variables in function 'axradio_adjustvcoi'
                                   8347 ;------------------------------------------------------------
                                   8348 ;rng                       Allocated to registers r7 
                                   8349 ;offs                      Allocated to registers r3 
                                   8350 ;bestrng                   Allocated to registers r4 
                                   8351 ;bestval                   Allocated to registers r5 r6 
                                   8352 ;val                       Allocated to stack - _bp +1
                                   8353 ;------------------------------------------------------------
                                   8354 ;	..\COMMON\easyax5043.c:1579: static __reentrantb uint8_t axradio_adjustvcoi(uint8_t rng) __reentrant
                                   8355 ;	-----------------------------------------
                                   8356 ;	 function axradio_adjustvcoi
                                   8357 ;	-----------------------------------------
      0028F7                       8358 _axradio_adjustvcoi:
      0028F7 C0 1E            [24] 8359 	push	_bp
      0028F9 85 81 1E         [24] 8360 	mov	_bp,sp
      0028FC 05 81            [12] 8361 	inc	sp
      0028FE 05 81            [12] 8362 	inc	sp
      002900 AF 82            [24] 8363 	mov	r7,dpl
                                   8364 ;	..\COMMON\easyax5043.c:1583: uint16_t bestval = (uint16_t)~0;
      002902 7D FF            [12] 8365 	mov	r5,#0xff
      002904 7E FF            [12] 8366 	mov	r6,#0xff
                                   8367 ;	..\COMMON\easyax5043.c:1584: rng &= 0x7F;
      002906 53 07 7F         [24] 8368 	anl	ar7,#0x7f
                                   8369 ;	..\COMMON\easyax5043.c:1585: bestrng = rng;
      002909 8F 04            [24] 8370 	mov	ar4,r7
                                   8371 ;	..\COMMON\easyax5043.c:1586: for (offs = 0; offs != 16; ++offs) {
      00290B 7B 00            [12] 8372 	mov	r3,#0x00
      00290D                       8373 00121$:
                                   8374 ;	..\COMMON\easyax5043.c:1588: if (!((uint8_t)(rng + offs) & 0xC0)) {
      00290D EB               [12] 8375 	mov	a,r3
      00290E 2F               [12] 8376 	add	a,r7
      00290F 54 C0            [12] 8377 	anl	a,#0xc0
      002911 60 02            [24] 8378 	jz	00150$
      002913 80 42            [24] 8379 	sjmp	00107$
      002915                       8380 00150$:
                                   8381 ;	..\COMMON\easyax5043.c:1589: radio_write8(AX5043_REG_PLLVCOI, (0x80 | (rng + offs)));
      002915 C0 04            [24] 8382 	push	ar4
      002917 EB               [12] 8383 	mov	a,r3
      002918 2F               [12] 8384 	add	a,r7
      002919 44 80            [12] 8385 	orl	a,#0x80
      00291B 90 41 80         [24] 8386 	mov	dptr,#0x4180
      00291E F0               [24] 8387 	movx	@dptr,a
                                   8388 ;	..\COMMON\easyax5043.c:1590: val = axradio_tunevoltage();
      00291F C0 07            [24] 8389 	push	ar7
      002921 C0 06            [24] 8390 	push	ar6
      002923 C0 05            [24] 8391 	push	ar5
      002925 C0 03            [24] 8392 	push	ar3
      002927 12 28 AB         [24] 8393 	lcall	_axradio_tunevoltage
      00292A AA 82            [24] 8394 	mov	r2,dpl
      00292C AC 83            [24] 8395 	mov	r4,dph
      00292E D0 03            [24] 8396 	pop	ar3
      002930 D0 05            [24] 8397 	pop	ar5
      002932 D0 06            [24] 8398 	pop	ar6
      002934 D0 07            [24] 8399 	pop	ar7
      002936 A8 1E            [24] 8400 	mov	r0,_bp
      002938 08               [12] 8401 	inc	r0
      002939 A6 02            [24] 8402 	mov	@r0,ar2
      00293B 08               [12] 8403 	inc	r0
      00293C A6 04            [24] 8404 	mov	@r0,ar4
                                   8405 ;	..\COMMON\easyax5043.c:1591: if (val < bestval) {
      00293E A8 1E            [24] 8406 	mov	r0,_bp
      002940 08               [12] 8407 	inc	r0
      002941 C3               [12] 8408 	clr	c
      002942 E6               [12] 8409 	mov	a,@r0
      002943 9D               [12] 8410 	subb	a,r5
      002944 08               [12] 8411 	inc	r0
      002945 E6               [12] 8412 	mov	a,@r0
      002946 9E               [12] 8413 	subb	a,r6
      002947 D0 04            [24] 8414 	pop	ar4
      002949 50 0C            [24] 8415 	jnc	00107$
                                   8416 ;	..\COMMON\easyax5043.c:1592: bestval = val;
      00294B A8 1E            [24] 8417 	mov	r0,_bp
      00294D 08               [12] 8418 	inc	r0
      00294E 86 05            [24] 8419 	mov	ar5,@r0
      002950 08               [12] 8420 	inc	r0
      002951 86 06            [24] 8421 	mov	ar6,@r0
                                   8422 ;	..\COMMON\easyax5043.c:1593: bestrng = rng + offs;
      002953 EB               [12] 8423 	mov	a,r3
      002954 2F               [12] 8424 	add	a,r7
      002955 FA               [12] 8425 	mov	r2,a
      002956 FC               [12] 8426 	mov	r4,a
      002957                       8427 00107$:
                                   8428 ;	..\COMMON\easyax5043.c:1596: if (!offs)
      002957 EB               [12] 8429 	mov	a,r3
      002958 60 4D            [24] 8430 	jz	00117$
                                   8431 ;	..\COMMON\easyax5043.c:1598: if (!((uint8_t)(rng - offs) & 0xC0)) {
      00295A EF               [12] 8432 	mov	a,r7
      00295B C3               [12] 8433 	clr	c
      00295C 9B               [12] 8434 	subb	a,r3
      00295D 54 C0            [12] 8435 	anl	a,#0xc0
      00295F 60 02            [24] 8436 	jz	00154$
      002961 80 44            [24] 8437 	sjmp	00117$
      002963                       8438 00154$:
                                   8439 ;	..\COMMON\easyax5043.c:1599: radio_write8(AX5043_REG_PLLVCOI, (0x80 | (rng - offs)));
      002963 C0 04            [24] 8440 	push	ar4
      002965 EF               [12] 8441 	mov	a,r7
      002966 C3               [12] 8442 	clr	c
      002967 9B               [12] 8443 	subb	a,r3
      002968 44 80            [12] 8444 	orl	a,#0x80
      00296A 90 41 80         [24] 8445 	mov	dptr,#0x4180
      00296D F0               [24] 8446 	movx	@dptr,a
                                   8447 ;	..\COMMON\easyax5043.c:1600: val = axradio_tunevoltage();
      00296E C0 07            [24] 8448 	push	ar7
      002970 C0 06            [24] 8449 	push	ar6
      002972 C0 05            [24] 8450 	push	ar5
      002974 C0 03            [24] 8451 	push	ar3
      002976 12 28 AB         [24] 8452 	lcall	_axradio_tunevoltage
      002979 AA 82            [24] 8453 	mov	r2,dpl
      00297B AC 83            [24] 8454 	mov	r4,dph
      00297D D0 03            [24] 8455 	pop	ar3
      00297F D0 05            [24] 8456 	pop	ar5
      002981 D0 06            [24] 8457 	pop	ar6
      002983 D0 07            [24] 8458 	pop	ar7
      002985 A8 1E            [24] 8459 	mov	r0,_bp
      002987 08               [12] 8460 	inc	r0
      002988 A6 02            [24] 8461 	mov	@r0,ar2
      00298A 08               [12] 8462 	inc	r0
      00298B A6 04            [24] 8463 	mov	@r0,ar4
                                   8464 ;	..\COMMON\easyax5043.c:1601: if (val < bestval) {
      00298D A8 1E            [24] 8465 	mov	r0,_bp
      00298F 08               [12] 8466 	inc	r0
      002990 C3               [12] 8467 	clr	c
      002991 E6               [12] 8468 	mov	a,@r0
      002992 9D               [12] 8469 	subb	a,r5
      002993 08               [12] 8470 	inc	r0
      002994 E6               [12] 8471 	mov	a,@r0
      002995 9E               [12] 8472 	subb	a,r6
      002996 D0 04            [24] 8473 	pop	ar4
      002998 50 0D            [24] 8474 	jnc	00117$
                                   8475 ;	..\COMMON\easyax5043.c:1602: bestval = val;
      00299A A8 1E            [24] 8476 	mov	r0,_bp
      00299C 08               [12] 8477 	inc	r0
      00299D 86 05            [24] 8478 	mov	ar5,@r0
      00299F 08               [12] 8479 	inc	r0
      0029A0 86 06            [24] 8480 	mov	ar6,@r0
                                   8481 ;	..\COMMON\easyax5043.c:1603: bestrng = rng - offs;
      0029A2 EF               [12] 8482 	mov	a,r7
      0029A3 C3               [12] 8483 	clr	c
      0029A4 9B               [12] 8484 	subb	a,r3
      0029A5 FA               [12] 8485 	mov	r2,a
      0029A6 FC               [12] 8486 	mov	r4,a
      0029A7                       8487 00117$:
                                   8488 ;	..\COMMON\easyax5043.c:1586: for (offs = 0; offs != 16; ++offs) {
      0029A7 0B               [12] 8489 	inc	r3
      0029A8 BB 10 02         [24] 8490 	cjne	r3,#0x10,00156$
      0029AB 80 03            [24] 8491 	sjmp	00157$
      0029AD                       8492 00156$:
      0029AD 02 29 0D         [24] 8493 	ljmp	00121$
      0029B0                       8494 00157$:
                                   8495 ;	..\COMMON\easyax5043.c:1608: if (bestval <= 0x0010)
      0029B0 C3               [12] 8496 	clr	c
      0029B1 74 10            [12] 8497 	mov	a,#0x10
      0029B3 9D               [12] 8498 	subb	a,r5
      0029B4 E4               [12] 8499 	clr	a
      0029B5 9E               [12] 8500 	subb	a,r6
      0029B6 40 07            [24] 8501 	jc	00120$
                                   8502 ;	..\COMMON\easyax5043.c:1609: return rng | 0x80;
      0029B8 74 80            [12] 8503 	mov	a,#0x80
      0029BA 4F               [12] 8504 	orl	a,r7
      0029BB F5 82            [12] 8505 	mov	dpl,a
      0029BD 80 05            [24] 8506 	sjmp	00122$
      0029BF                       8507 00120$:
                                   8508 ;	..\COMMON\easyax5043.c:1610: return bestrng | 0x80;
      0029BF 74 80            [12] 8509 	mov	a,#0x80
      0029C1 4C               [12] 8510 	orl	a,r4
      0029C2 F5 82            [12] 8511 	mov	dpl,a
      0029C4                       8512 00122$:
      0029C4 85 1E 81         [24] 8513 	mov	sp,_bp
      0029C7 D0 1E            [24] 8514 	pop	_bp
      0029C9 22               [24] 8515 	ret
                                   8516 ;------------------------------------------------------------
                                   8517 ;Allocation info for local variables in function 'axradio_calvcoi'
                                   8518 ;------------------------------------------------------------
                                   8519 ;i                         Allocated to registers r2 
                                   8520 ;r                         Allocated to registers r7 
                                   8521 ;vmin                      Allocated to registers r5 r6 
                                   8522 ;vmax                      Allocated to registers r3 r4 
                                   8523 ;curtune                   Allocated to stack - _bp +1
                                   8524 ;------------------------------------------------------------
                                   8525 ;	..\COMMON\easyax5043.c:1613: static __reentrantb uint8_t axradio_calvcoi(void) __reentrant
                                   8526 ;	-----------------------------------------
                                   8527 ;	 function axradio_calvcoi
                                   8528 ;	-----------------------------------------
      0029CA                       8529 _axradio_calvcoi:
      0029CA C0 1E            [24] 8530 	push	_bp
      0029CC 85 81 1E         [24] 8531 	mov	_bp,sp
      0029CF 05 81            [12] 8532 	inc	sp
      0029D1 05 81            [12] 8533 	inc	sp
                                   8534 ;	..\COMMON\easyax5043.c:1616: uint8_t r = 0;
      0029D3 7F 00            [12] 8535 	mov	r7,#0x00
                                   8536 ;	..\COMMON\easyax5043.c:1617: uint16_t vmin = 0xffff;
      0029D5 7D FF            [12] 8537 	mov	r5,#0xff
      0029D7 7E FF            [12] 8538 	mov	r6,#0xff
                                   8539 ;	..\COMMON\easyax5043.c:1618: uint16_t vmax = 0x0000;
      0029D9 7B 00            [12] 8540 	mov	r3,#0x00
      0029DB 7C 00            [12] 8541 	mov	r4,#0x00
                                   8542 ;	..\COMMON\easyax5043.c:1619: for (i = 0x40; i != 0;) {
      0029DD 7A 40            [12] 8543 	mov	r2,#0x40
      0029DF                       8544 00116$:
                                   8545 ;	..\COMMON\easyax5043.c:1621: --i;
      0029DF C0 07            [24] 8546 	push	ar7
      0029E1 1A               [12] 8547 	dec	r2
                                   8548 ;	..\COMMON\easyax5043.c:1622: radio_write8(AX5043_REG_PLLVCOI, (0x80 | i));
      0029E2 74 80            [12] 8549 	mov	a,#0x80
      0029E4 4A               [12] 8550 	orl	a,r2
      0029E5 FF               [12] 8551 	mov	r7,a
      0029E6 90 41 80         [24] 8552 	mov	dptr,#0x4180
      0029E9 F0               [24] 8553 	movx	@dptr,a
                                   8554 ;	..\COMMON\easyax5043.c:1623: radio_read8(AX5043_REG_PLLRANGINGA); // clear PLL lock loss
      0029EA 90 40 33         [24] 8555 	mov	dptr,#0x4033
      0029ED E0               [24] 8556 	movx	a,@dptr
                                   8557 ;	..\COMMON\easyax5043.c:1624: curtune = axradio_tunevoltage();
      0029EE C0 07            [24] 8558 	push	ar7
      0029F0 C0 06            [24] 8559 	push	ar6
      0029F2 C0 05            [24] 8560 	push	ar5
      0029F4 C0 04            [24] 8561 	push	ar4
      0029F6 C0 03            [24] 8562 	push	ar3
      0029F8 C0 02            [24] 8563 	push	ar2
      0029FA 12 28 AB         [24] 8564 	lcall	_axradio_tunevoltage
      0029FD A8 1E            [24] 8565 	mov	r0,_bp
      0029FF 08               [12] 8566 	inc	r0
      002A00 A6 82            [24] 8567 	mov	@r0,dpl
      002A02 08               [12] 8568 	inc	r0
      002A03 A6 83            [24] 8569 	mov	@r0,dph
      002A05 D0 02            [24] 8570 	pop	ar2
      002A07 D0 03            [24] 8571 	pop	ar3
      002A09 D0 04            [24] 8572 	pop	ar4
      002A0B D0 05            [24] 8573 	pop	ar5
      002A0D D0 06            [24] 8574 	pop	ar6
      002A0F D0 07            [24] 8575 	pop	ar7
      002A11 A8 1E            [24] 8576 	mov	r0,_bp
      002A13 08               [12] 8577 	inc	r0
                                   8578 ;	..\COMMON\easyax5043.c:1625: radio_read8(AX5043_REG_PLLRANGINGA); // clear PLL lock loss
      002A14 90 40 33         [24] 8579 	mov	dptr,#0x4033
      002A17 E0               [24] 8580 	movx	a,@dptr
                                   8581 ;	..\COMMON\easyax5043.c:1626: ((uint16_t __xdata *)axradio_rxbuffer)[i] = curtune;
      002A18 EA               [12] 8582 	mov	a,r2
      002A19 75 F0 02         [24] 8583 	mov	b,#0x02
      002A1C A4               [48] 8584 	mul	ab
      002A1D 24 40            [12] 8585 	add	a,#_axradio_rxbuffer
      002A1F F5 82            [12] 8586 	mov	dpl,a
      002A21 74 01            [12] 8587 	mov	a,#(_axradio_rxbuffer >> 8)
      002A23 35 F0            [12] 8588 	addc	a,b
      002A25 F5 83            [12] 8589 	mov	dph,a
      002A27 A8 1E            [24] 8590 	mov	r0,_bp
      002A29 08               [12] 8591 	inc	r0
      002A2A E6               [12] 8592 	mov	a,@r0
      002A2B F0               [24] 8593 	movx	@dptr,a
      002A2C 08               [12] 8594 	inc	r0
      002A2D E6               [12] 8595 	mov	a,@r0
      002A2E A3               [24] 8596 	inc	dptr
      002A2F F0               [24] 8597 	movx	@dptr,a
                                   8598 ;	..\COMMON\easyax5043.c:1627: if (curtune > vmax)
      002A30 A8 1E            [24] 8599 	mov	r0,_bp
      002A32 08               [12] 8600 	inc	r0
      002A33 C3               [12] 8601 	clr	c
      002A34 EB               [12] 8602 	mov	a,r3
      002A35 96               [12] 8603 	subb	a,@r0
      002A36 EC               [12] 8604 	mov	a,r4
      002A37 08               [12] 8605 	inc	r0
      002A38 96               [12] 8606 	subb	a,@r0
      002A39 D0 07            [24] 8607 	pop	ar7
      002A3B 50 08            [24] 8608 	jnc	00105$
                                   8609 ;	..\COMMON\easyax5043.c:1628: vmax = curtune;
      002A3D A8 1E            [24] 8610 	mov	r0,_bp
      002A3F 08               [12] 8611 	inc	r0
      002A40 86 03            [24] 8612 	mov	ar3,@r0
      002A42 08               [12] 8613 	inc	r0
      002A43 86 04            [24] 8614 	mov	ar4,@r0
      002A45                       8615 00105$:
                                   8616 ;	..\COMMON\easyax5043.c:1629: if (curtune < vmin) {
      002A45 A8 1E            [24] 8617 	mov	r0,_bp
      002A47 08               [12] 8618 	inc	r0
      002A48 C3               [12] 8619 	clr	c
      002A49 E6               [12] 8620 	mov	a,@r0
      002A4A 9D               [12] 8621 	subb	a,r5
      002A4B 08               [12] 8622 	inc	r0
      002A4C E6               [12] 8623 	mov	a,@r0
      002A4D 9E               [12] 8624 	subb	a,r6
      002A4E 50 1E            [24] 8625 	jnc	00117$
                                   8626 ;	..\COMMON\easyax5043.c:1630: vmin = curtune;
      002A50 C0 07            [24] 8627 	push	ar7
      002A52 A8 1E            [24] 8628 	mov	r0,_bp
      002A54 08               [12] 8629 	inc	r0
      002A55 86 05            [24] 8630 	mov	ar5,@r0
      002A57 08               [12] 8631 	inc	r0
      002A58 86 06            [24] 8632 	mov	ar6,@r0
                                   8633 ;	..\COMMON\easyax5043.c:1632: if (!(0xC0 & (uint8_t)~(radio_read8(AX5043_REG_PLLRANGINGA))))
      002A5A 90 40 33         [24] 8634 	mov	dptr,#0x4033
      002A5D E0               [24] 8635 	movx	a,@dptr
      002A5E F4               [12] 8636 	cpl	a
      002A5F FF               [12] 8637 	mov	r7,a
      002A60 54 C0            [12] 8638 	anl	a,#0xc0
      002A62 60 04            [24] 8639 	jz	00150$
      002A64 D0 07            [24] 8640 	pop	ar7
      002A66 80 06            [24] 8641 	sjmp	00117$
      002A68                       8642 00150$:
      002A68 D0 07            [24] 8643 	pop	ar7
                                   8644 ;	..\COMMON\easyax5043.c:1633: r = i | 0x80;
      002A6A 74 80            [12] 8645 	mov	a,#0x80
      002A6C 4A               [12] 8646 	orl	a,r2
      002A6D FF               [12] 8647 	mov	r7,a
      002A6E                       8648 00117$:
                                   8649 ;	..\COMMON\easyax5043.c:1619: for (i = 0x40; i != 0;) {
      002A6E EA               [12] 8650 	mov	a,r2
      002A6F 60 03            [24] 8651 	jz	00151$
      002A71 02 29 DF         [24] 8652 	ljmp	00116$
      002A74                       8653 00151$:
                                   8654 ;	..\COMMON\easyax5043.c:1636: if (!(r & 0x80) || vmax >= 0xFF00 || vmin < 0x0100 || vmax - vmin < 0x4000)
      002A74 EF               [12] 8655 	mov	a,r7
      002A75 30 E7 16         [24] 8656 	jnb	acc.7,00111$
      002A78 74 01            [12] 8657 	mov	a,#0x100 - 0xff
      002A7A 2C               [12] 8658 	add	a,r4
      002A7B 40 11            [24] 8659 	jc	00111$
      002A7D 74 FF            [12] 8660 	mov	a,#0x100 - 0x01
      002A7F 2E               [12] 8661 	add	a,r6
      002A80 50 0C            [24] 8662 	jnc	00111$
      002A82 EB               [12] 8663 	mov	a,r3
      002A83 C3               [12] 8664 	clr	c
      002A84 9D               [12] 8665 	subb	a,r5
      002A85 FD               [12] 8666 	mov	r5,a
      002A86 EC               [12] 8667 	mov	a,r4
      002A87 9E               [12] 8668 	subb	a,r6
      002A88 FE               [12] 8669 	mov	r6,a
      002A89 C3               [12] 8670 	clr	c
      002A8A 94 40            [12] 8671 	subb	a,#0x40
      002A8C 50 05            [24] 8672 	jnc	00112$
      002A8E                       8673 00111$:
                                   8674 ;	..\COMMON\easyax5043.c:1637: return 0;
      002A8E 75 82 00         [24] 8675 	mov	dpl,#0x00
      002A91 80 02            [24] 8676 	sjmp	00118$
      002A93                       8677 00112$:
                                   8678 ;	..\COMMON\easyax5043.c:1638: return r;
      002A93 8F 82            [24] 8679 	mov	dpl,r7
      002A95                       8680 00118$:
      002A95 85 1E 81         [24] 8681 	mov	sp,_bp
      002A98 D0 1E            [24] 8682 	pop	_bp
      002A9A 22               [24] 8683 	ret
                                   8684 ;------------------------------------------------------------
                                   8685 ;Allocation info for local variables in function 'axradio_init'
                                   8686 ;------------------------------------------------------------
                                   8687 ;i                         Allocated with name '_axradio_init_i_1_657'
                                   8688 ;crit                      Allocated to registers r6 
                                   8689 ;__00020027                Allocated to registers 
                                   8690 ;f                         Allocated to registers r3 r4 r5 r6 
                                   8691 ;crit                      Allocated to registers r6 
                                   8692 ;r                         Allocated to registers r4 
                                   8693 ;__00040030                Allocated to registers 
                                   8694 ;crit                      Allocated to registers 
                                   8695 ;__00030032                Allocated to registers 
                                   8696 ;crit                      Allocated to registers 
                                   8697 ;x                         Allocated to registers r7 
                                   8698 ;vcoisave                  Allocated with name '_axradio_init_vcoisave_3_687'
                                   8699 ;j                         Allocated with name '_axradio_init_j_3_687'
                                   8700 ;f                         Allocated with name '_axradio_init_f_5_690'
                                   8701 ;x                         Allocated to registers r7 
                                   8702 ;f                         Allocated to registers r4 r5 r6 r7 
                                   8703 ;sloc0                     Allocated with name '_axradio_init_sloc0_1_0'
                                   8704 ;------------------------------------------------------------
                                   8705 ;	..\COMMON\easyax5043.c:1645: uint8_t axradio_init(void)
                                   8706 ;	-----------------------------------------
                                   8707 ;	 function axradio_init
                                   8708 ;	-----------------------------------------
      002A9B                       8709 _axradio_init:
                                   8710 ;	..\COMMON\easyax5043.c:1649: axradio_mode = AXRADIO_MODE_UNINIT;
      002A9B 75 08 00         [24] 8711 	mov	_axradio_mode,#0x00
                                   8712 ;	..\COMMON\easyax5043.c:1650: axradio_killallcb();
      002A9E 12 28 81         [24] 8713 	lcall	_axradio_killallcb
                                   8714 ;	..\COMMON\easyax5043.c:1651: axradio_cb_receive.cb.handler = axradio_receive_callback_fwd;
      002AA1 90 02 46         [24] 8715 	mov	dptr,#(_axradio_cb_receive + 0x0002)
      002AA4 74 9E            [12] 8716 	mov	a,#_axradio_receive_callback_fwd
      002AA6 F0               [24] 8717 	movx	@dptr,a
      002AA7 74 23            [12] 8718 	mov	a,#(_axradio_receive_callback_fwd >> 8)
      002AA9 A3               [24] 8719 	inc	dptr
      002AAA F0               [24] 8720 	movx	@dptr,a
                                   8721 ;	..\COMMON\easyax5043.c:1652: axradio_cb_receive.st.status = AXRADIO_STAT_RECEIVE;
      002AAB 90 02 48         [24] 8722 	mov	dptr,#(_axradio_cb_receive + 0x0004)
      002AAE E4               [12] 8723 	clr	a
      002AAF F0               [24] 8724 	movx	@dptr,a
                                   8725 ;	..\COMMON\easyax5043.c:1653: memset_xdata(axradio_cb_receive.st.rx.mac.remoteaddr, 0, sizeof(axradio_cb_receive.st.rx.mac.remoteaddr));
                                   8726 ;	1-genFromRTrack replaced	mov	_memset_PARM_2,#0x00
      002AB0 F5 2E            [12] 8727 	mov	_memset_PARM_2,a
      002AB2 75 2F 05         [24] 8728 	mov	_memset_PARM_3,#0x05
                                   8729 ;	1-genFromRTrack replaced	mov	(_memset_PARM_3 + 1),#0x00
      002AB5 F5 30            [12] 8730 	mov	(_memset_PARM_3 + 1),a
      002AB7 90 02 58         [24] 8731 	mov	dptr,#(_axradio_cb_receive + 0x0014)
      002ABA 75 F0 00         [24] 8732 	mov	b,#0x00
      002ABD 12 42 50         [24] 8733 	lcall	_memset
                                   8734 ;	..\COMMON\easyax5043.c:1654: memset_xdata(axradio_cb_receive.st.rx.mac.localaddr, 0, sizeof(axradio_cb_receive.st.rx.mac.localaddr));
      002AC0 75 2E 00         [24] 8735 	mov	_memset_PARM_2,#0x00
      002AC3 75 2F 05         [24] 8736 	mov	_memset_PARM_3,#0x05
      002AC6 75 30 00         [24] 8737 	mov	(_memset_PARM_3 + 1),#0x00
      002AC9 90 02 5D         [24] 8738 	mov	dptr,#(_axradio_cb_receive + 0x0019)
      002ACC 75 F0 00         [24] 8739 	mov	b,#0x00
      002ACF 12 42 50         [24] 8740 	lcall	_memset
                                   8741 ;	..\COMMON\easyax5043.c:1655: axradio_cb_receivesfd.cb.handler = axradio_callback_fwd;
      002AD2 90 02 6A         [24] 8742 	mov	dptr,#(_axradio_cb_receivesfd + 0x0002)
      002AD5 74 8C            [12] 8743 	mov	a,#_axradio_callback_fwd
      002AD7 F0               [24] 8744 	movx	@dptr,a
      002AD8 74 23            [12] 8745 	mov	a,#(_axradio_callback_fwd >> 8)
      002ADA A3               [24] 8746 	inc	dptr
      002ADB F0               [24] 8747 	movx	@dptr,a
                                   8748 ;	..\COMMON\easyax5043.c:1656: axradio_cb_receivesfd.st.status = AXRADIO_STAT_RECEIVESFD;
      002ADC 90 02 6C         [24] 8749 	mov	dptr,#(_axradio_cb_receivesfd + 0x0004)
      002ADF 74 01            [12] 8750 	mov	a,#0x01
      002AE1 F0               [24] 8751 	movx	@dptr,a
                                   8752 ;	..\COMMON\easyax5043.c:1657: axradio_cb_channelstate.cb.handler = axradio_callback_fwd;
      002AE2 90 02 74         [24] 8753 	mov	dptr,#(_axradio_cb_channelstate + 0x0002)
      002AE5 74 8C            [12] 8754 	mov	a,#_axradio_callback_fwd
      002AE7 F0               [24] 8755 	movx	@dptr,a
      002AE8 74 23            [12] 8756 	mov	a,#(_axradio_callback_fwd >> 8)
      002AEA A3               [24] 8757 	inc	dptr
      002AEB F0               [24] 8758 	movx	@dptr,a
                                   8759 ;	..\COMMON\easyax5043.c:1658: axradio_cb_channelstate.st.status = AXRADIO_STAT_CHANNELSTATE;
      002AEC 90 02 76         [24] 8760 	mov	dptr,#(_axradio_cb_channelstate + 0x0004)
      002AEF 74 02            [12] 8761 	mov	a,#0x02
      002AF1 F0               [24] 8762 	movx	@dptr,a
                                   8763 ;	..\COMMON\easyax5043.c:1659: axradio_cb_transmitstart.cb.handler = axradio_callback_fwd;
      002AF2 90 02 81         [24] 8764 	mov	dptr,#(_axradio_cb_transmitstart + 0x0002)
      002AF5 74 8C            [12] 8765 	mov	a,#_axradio_callback_fwd
      002AF7 F0               [24] 8766 	movx	@dptr,a
      002AF8 74 23            [12] 8767 	mov	a,#(_axradio_callback_fwd >> 8)
      002AFA A3               [24] 8768 	inc	dptr
      002AFB F0               [24] 8769 	movx	@dptr,a
                                   8770 ;	..\COMMON\easyax5043.c:1660: axradio_cb_transmitstart.st.status = AXRADIO_STAT_TRANSMITSTART;
      002AFC 90 02 83         [24] 8771 	mov	dptr,#(_axradio_cb_transmitstart + 0x0004)
      002AFF 74 03            [12] 8772 	mov	a,#0x03
      002B01 F0               [24] 8773 	movx	@dptr,a
                                   8774 ;	..\COMMON\easyax5043.c:1661: axradio_cb_transmitend.cb.handler = axradio_callback_fwd;
      002B02 90 02 8B         [24] 8775 	mov	dptr,#(_axradio_cb_transmitend + 0x0002)
      002B05 74 8C            [12] 8776 	mov	a,#_axradio_callback_fwd
      002B07 F0               [24] 8777 	movx	@dptr,a
      002B08 74 23            [12] 8778 	mov	a,#(_axradio_callback_fwd >> 8)
      002B0A A3               [24] 8779 	inc	dptr
      002B0B F0               [24] 8780 	movx	@dptr,a
                                   8781 ;	..\COMMON\easyax5043.c:1662: axradio_cb_transmitend.st.status = AXRADIO_STAT_TRANSMITEND;
      002B0C 90 02 8D         [24] 8782 	mov	dptr,#(_axradio_cb_transmitend + 0x0004)
      002B0F 74 04            [12] 8783 	mov	a,#0x04
      002B11 F0               [24] 8784 	movx	@dptr,a
                                   8785 ;	..\COMMON\easyax5043.c:1663: axradio_cb_transmitdata.cb.handler = axradio_callback_fwd;
      002B12 90 02 95         [24] 8786 	mov	dptr,#(_axradio_cb_transmitdata + 0x0002)
      002B15 74 8C            [12] 8787 	mov	a,#_axradio_callback_fwd
      002B17 F0               [24] 8788 	movx	@dptr,a
      002B18 74 23            [12] 8789 	mov	a,#(_axradio_callback_fwd >> 8)
      002B1A A3               [24] 8790 	inc	dptr
      002B1B F0               [24] 8791 	movx	@dptr,a
                                   8792 ;	..\COMMON\easyax5043.c:1664: axradio_cb_transmitdata.st.status = AXRADIO_STAT_TRANSMITDATA;
      002B1C 90 02 97         [24] 8793 	mov	dptr,#(_axradio_cb_transmitdata + 0x0004)
      002B1F 74 05            [12] 8794 	mov	a,#0x05
      002B21 F0               [24] 8795 	movx	@dptr,a
                                   8796 ;	..\COMMON\easyax5043.c:1665: axradio_timer.handler = axradio_timer_callback;
      002B22 90 02 9F         [24] 8797 	mov	dptr,#(_axradio_timer + 0x0002)
      002B25 74 61            [12] 8798 	mov	a,#_axradio_timer_callback
      002B27 F0               [24] 8799 	movx	@dptr,a
      002B28 74 1B            [12] 8800 	mov	a,#(_axradio_timer_callback >> 8)
      002B2A A3               [24] 8801 	inc	dptr
      002B2B F0               [24] 8802 	movx	@dptr,a
                                   8803 ;	..\COMMON\easyax5043.c:1666: axradio_curchannel = 0;
      002B2C 90 00 18         [24] 8804 	mov	dptr,#_axradio_curchannel
      002B2F E4               [12] 8805 	clr	a
      002B30 F0               [24] 8806 	movx	@dptr,a
                                   8807 ;	..\COMMON\easyax5043.c:1667: axradio_curfreqoffset = 0;
      002B31 90 00 19         [24] 8808 	mov	dptr,#_axradio_curfreqoffset
      002B34 F0               [24] 8809 	movx	@dptr,a
      002B35 A3               [24] 8810 	inc	dptr
      002B36 F0               [24] 8811 	movx	@dptr,a
      002B37 A3               [24] 8812 	inc	dptr
      002B38 F0               [24] 8813 	movx	@dptr,a
      002B39 A3               [24] 8814 	inc	dptr
      002B3A F0               [24] 8815 	movx	@dptr,a
                                   8816 ;	..\COMMON\easyax5043.c:1668: disable_radio_interrupt_in_mcu_pin();
      002B3B 12 3C A6         [24] 8817 	lcall	_disable_radio_interrupt_in_mcu_pin
                                   8818 ;	..\COMMON\easyax5043.c:1669: axradio_trxstate = trxstate_off;
      002B3E 75 09 00         [24] 8819 	mov	_axradio_trxstate,#0x00
                                   8820 ;	..\COMMON\easyax5043.c:1670: if (ax5043_reset())
      002B41 12 3E 05         [24] 8821 	lcall	_ax5043_reset
      002B44 E5 82            [12] 8822 	mov	a,dpl
      002B46 60 04            [24] 8823 	jz	00102$
                                   8824 ;	..\COMMON\easyax5043.c:1671: return AXRADIO_ERR_NOCHIP;
      002B48 75 82 05         [24] 8825 	mov	dpl,#0x05
      002B4B 22               [24] 8826 	ret
      002B4C                       8827 00102$:
                                   8828 ;	..\COMMON\easyax5043.c:1672: ax5043_init_registers();
      002B4C 12 19 13         [24] 8829 	lcall	_ax5043_init_registers
                                   8830 ;	..\COMMON\easyax5043.c:1673: ax5043_set_registers_tx();
      002B4F 12 06 55         [24] 8831 	lcall	_ax5043_set_registers_tx
                                   8832 ;	..\COMMON\easyax5043.c:1674: radio_write8(AX5043_REG_PLLLOOP, 0x09); // default 100kHz loop BW for ranging
      002B52 90 40 30         [24] 8833 	mov	dptr,#0x4030
      002B55 74 09            [12] 8834 	mov	a,#0x09
      002B57 F0               [24] 8835 	movx	@dptr,a
                                   8836 ;	..\COMMON\easyax5043.c:1675: radio_write8(AX5043_REG_PLLCPI, 0x08);
      002B58 90 40 31         [24] 8837 	mov	dptr,#0x4031
      002B5B 14               [12] 8838 	dec	a
      002B5C F0               [24] 8839 	movx	@dptr,a
                                   8840 ;	..\COMMON\easyax5043.c:1676: enable_radio_interrupt_in_mcu_pin();
      002B5D 12 3C A3         [24] 8841 	lcall	_enable_radio_interrupt_in_mcu_pin
                                   8842 ;	..\COMMON\easyax5043.c:1678: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_XTAL_ON);
      002B60 90 40 02         [24] 8843 	mov	dptr,#0x4002
      002B63 74 05            [12] 8844 	mov	a,#0x05
      002B65 F0               [24] 8845 	movx	@dptr,a
                                   8846 ;	..\COMMON\easyax5043.c:1679: radio_write8(AX5043_REG_MODULATION, 0x08);
      002B66 90 40 10         [24] 8847 	mov	dptr,#0x4010
      002B69 74 08            [12] 8848 	mov	a,#0x08
      002B6B F0               [24] 8849 	movx	@dptr,a
                                   8850 ;	..\COMMON\easyax5043.c:1680: radio_write8(AX5043_REG_FSKDEV2, 0x00);
      002B6C 90 41 61         [24] 8851 	mov	dptr,#0x4161
      002B6F E4               [12] 8852 	clr	a
      002B70 F0               [24] 8853 	movx	@dptr,a
                                   8854 ;	..\COMMON\easyax5043.c:1681: radio_write8(AX5043_REG_FSKDEV1, 0x00);
      002B71 90 41 62         [24] 8855 	mov	dptr,#0x4162
      002B74 F0               [24] 8856 	movx	@dptr,a
                                   8857 ;	..\COMMON\easyax5043.c:1682: radio_write8(AX5043_REG_FSKDEV0, 0x00);
      002B75 90 41 63         [24] 8858 	mov	dptr,#0x4163
      002B78 F0               [24] 8859 	movx	@dptr,a
                                   8860 ;	..\COMMON\easyax5043.c:1683: axradio_wait_for_xtal();
      002B79 12 17 AA         [24] 8861 	lcall	_axradio_wait_for_xtal
                                   8862 ;	..\COMMON\easyax5043.c:1684: for (i = 0; i < axradio_phy_nrchannels; ++i) {
      002B7C 7F 00            [12] 8863 	mov	r7,#0x00
      002B7E                       8864 00239$:
      002B7E 90 4C 71         [24] 8865 	mov	dptr,#_axradio_phy_nrchannels
      002B81 E4               [12] 8866 	clr	a
      002B82 93               [24] 8867 	movc	a,@a+dptr
      002B83 FE               [12] 8868 	mov	r6,a
      002B84 C3               [12] 8869 	clr	c
      002B85 EF               [12] 8870 	mov	a,r7
      002B86 9E               [12] 8871 	subb	a,r6
      002B87 40 03            [24] 8872 	jc	00311$
      002B89 02 2C 86         [24] 8873 	ljmp	00155$
      002B8C                       8874 00311$:
                                   8875 ;	..\COMMON\easyax5043.c:1685: uint32_t __autodata f = axradio_phy_chanfreq[i];
      002B8C EF               [12] 8876 	mov	a,r7
      002B8D 75 F0 04         [24] 8877 	mov	b,#0x04
      002B90 A4               [48] 8878 	mul	ab
      002B91 24 72            [12] 8879 	add	a,#_axradio_phy_chanfreq
      002B93 F5 82            [12] 8880 	mov	dpl,a
      002B95 74 4C            [12] 8881 	mov	a,#(_axradio_phy_chanfreq >> 8)
      002B97 35 F0            [12] 8882 	addc	a,b
      002B99 F5 83            [12] 8883 	mov	dph,a
      002B9B E4               [12] 8884 	clr	a
      002B9C 93               [24] 8885 	movc	a,@a+dptr
      002B9D FB               [12] 8886 	mov	r3,a
      002B9E A3               [24] 8887 	inc	dptr
      002B9F E4               [12] 8888 	clr	a
      002BA0 93               [24] 8889 	movc	a,@a+dptr
      002BA1 FC               [12] 8890 	mov	r4,a
      002BA2 A3               [24] 8891 	inc	dptr
      002BA3 E4               [12] 8892 	clr	a
      002BA4 93               [24] 8893 	movc	a,@a+dptr
      002BA5 FD               [12] 8894 	mov	r5,a
      002BA6 A3               [24] 8895 	inc	dptr
      002BA7 E4               [12] 8896 	clr	a
      002BA8 93               [24] 8897 	movc	a,@a+dptr
      002BA9 FE               [12] 8898 	mov	r6,a
                                   8899 ;	..\COMMON\easyax5043.c:1686: radio_write8(AX5043_REG_FREQA0, f);
      002BAA 8B 02            [24] 8900 	mov	ar2,r3
      002BAC 90 40 37         [24] 8901 	mov	dptr,#0x4037
      002BAF EA               [12] 8902 	mov	a,r2
      002BB0 F0               [24] 8903 	movx	@dptr,a
                                   8904 ;	..\COMMON\easyax5043.c:1687: radio_write8(AX5043_REG_FREQA1, (f >> 8));
      002BB1 8C 02            [24] 8905 	mov	ar2,r4
      002BB3 90 40 36         [24] 8906 	mov	dptr,#0x4036
      002BB6 EA               [12] 8907 	mov	a,r2
      002BB7 F0               [24] 8908 	movx	@dptr,a
                                   8909 ;	..\COMMON\easyax5043.c:1688: radio_write8(AX5043_REG_FREQA2, (f >> 16));
      002BB8 8D 02            [24] 8910 	mov	ar2,r5
      002BBA 90 40 35         [24] 8911 	mov	dptr,#0x4035
      002BBD EA               [12] 8912 	mov	a,r2
      002BBE F0               [24] 8913 	movx	@dptr,a
                                   8914 ;	..\COMMON\easyax5043.c:1689: radio_write8(AX5043_REG_FREQA3, (f >> 24));
      002BBF 8E 03            [24] 8915 	mov	ar3,r6
      002BC1 90 40 34         [24] 8916 	mov	dptr,#0x4034
      002BC4 EB               [12] 8917 	mov	a,r3
      002BC5 F0               [24] 8918 	movx	@dptr,a
                                   8919 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:351: criticalsection_t crit = IE & 0x80;
      002BC6 74 80            [12] 8920 	mov	a,#0x80
      002BC8 55 A8            [12] 8921 	anl	a,_IE
      002BCA FE               [12] 8922 	mov	r6,a
                                   8923 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:352: EA = 0;
      002BCB C2 AF            [12] 8924 	clr	_EA
                                   8925 ;	..\COMMON\easyax5043.c:1690: crit = enter_critical();
                                   8926 ;	..\COMMON\easyax5043.c:1691: axradio_trxstate = trxstate_pll_ranging;
      002BCD 75 09 05         [24] 8927 	mov	_axradio_trxstate,#0x05
                                   8928 ;	..\COMMON\easyax5043.c:1692: radio_write8(AX5043_REG_IRQMASK1, 0x10); // enable pll autoranging done interrupt
      002BD0 90 40 06         [24] 8929 	mov	dptr,#0x4006
      002BD3 74 10            [12] 8930 	mov	a,#0x10
      002BD5 F0               [24] 8931 	movx	@dptr,a
                                   8932 ;	..\COMMON\easyax5043.c:1695: if (!(axradio_phy_chanpllrnginit[0] & 0xF0)) {
      002BD6 90 4C 8A         [24] 8933 	mov	dptr,#_axradio_phy_chanpllrnginit
      002BD9 E4               [12] 8934 	clr	a
      002BDA 93               [24] 8935 	movc	a,@a+dptr
      002BDB FC               [12] 8936 	mov	r4,a
      002BDC A3               [24] 8937 	inc	dptr
      002BDD E4               [12] 8938 	clr	a
      002BDE 93               [24] 8939 	movc	a,@a+dptr
      002BDF FD               [12] 8940 	mov	r5,a
      002BE0 EC               [12] 8941 	mov	a,r4
      002BE1 54 F0            [12] 8942 	anl	a,#0xf0
      002BE3 70 1B            [24] 8943 	jnz	00144$
                                   8944 ;	..\COMMON\easyax5043.c:1697: r = axradio_phy_chanpllrnginit[i] | 0x10;
      002BE5 EF               [12] 8945 	mov	a,r7
      002BE6 75 F0 02         [24] 8946 	mov	b,#0x02
      002BE9 A4               [48] 8947 	mul	ab
      002BEA 24 8A            [12] 8948 	add	a,#_axradio_phy_chanpllrnginit
      002BEC F5 82            [12] 8949 	mov	dpl,a
      002BEE 74 4C            [12] 8950 	mov	a,#(_axradio_phy_chanpllrnginit >> 8)
      002BF0 35 F0            [12] 8951 	addc	a,b
      002BF2 F5 83            [12] 8952 	mov	dph,a
      002BF4 E4               [12] 8953 	clr	a
      002BF5 93               [24] 8954 	movc	a,@a+dptr
      002BF6 FC               [12] 8955 	mov	r4,a
      002BF7 A3               [24] 8956 	inc	dptr
      002BF8 E4               [12] 8957 	clr	a
      002BF9 93               [24] 8958 	movc	a,@a+dptr
      002BFA FD               [12] 8959 	mov	r5,a
      002BFB 43 04 10         [24] 8960 	orl	ar4,#0x10
      002BFE 80 32            [24] 8961 	sjmp	00146$
      002C00                       8962 00144$:
                                   8963 ;	..\COMMON\easyax5043.c:1699: r = 0x18;
      002C00 7C 18            [12] 8964 	mov	r4,#0x18
                                   8965 ;	..\COMMON\easyax5043.c:1700: if (i) {
      002C02 EF               [12] 8966 	mov	a,r7
      002C03 60 2D            [24] 8967 	jz	00146$
                                   8968 ;	..\COMMON\easyax5043.c:1701: r = axradio_phy_chanpllrng[i - 1];
      002C05 8F 03            [24] 8969 	mov	ar3,r7
      002C07 7D 00            [12] 8970 	mov	r5,#0x00
      002C09 1B               [12] 8971 	dec	r3
      002C0A BB FF 01         [24] 8972 	cjne	r3,#0xff,00315$
      002C0D 1D               [12] 8973 	dec	r5
      002C0E                       8974 00315$:
      002C0E ED               [12] 8975 	mov	a,r5
      002C0F CB               [12] 8976 	xch	a,r3
      002C10 25 E0            [12] 8977 	add	a,acc
      002C12 CB               [12] 8978 	xch	a,r3
      002C13 33               [12] 8979 	rlc	a
      002C14 FD               [12] 8980 	mov	r5,a
      002C15 EB               [12] 8981 	mov	a,r3
      002C16 24 01            [12] 8982 	add	a,#_axradio_phy_chanpllrng
      002C18 F5 82            [12] 8983 	mov	dpl,a
      002C1A ED               [12] 8984 	mov	a,r5
      002C1B 34 00            [12] 8985 	addc	a,#(_axradio_phy_chanpllrng >> 8)
      002C1D F5 83            [12] 8986 	mov	dph,a
      002C1F E0               [24] 8987 	movx	a,@dptr
      002C20 FB               [12] 8988 	mov	r3,a
      002C21 A3               [24] 8989 	inc	dptr
      002C22 E0               [24] 8990 	movx	a,@dptr
      002C23 FD               [12] 8991 	mov	r5,a
      002C24 8B 04            [24] 8992 	mov	ar4,r3
                                   8993 ;	..\COMMON\easyax5043.c:1702: if (r & 0x20)
      002C26 EC               [12] 8994 	mov	a,r4
      002C27 30 E5 02         [24] 8995 	jnb	acc.5,00140$
                                   8996 ;	..\COMMON\easyax5043.c:1703: r = 0x08;
      002C2A 7C 08            [12] 8997 	mov	r4,#0x08
      002C2C                       8998 00140$:
                                   8999 ;	..\COMMON\easyax5043.c:1704: r &= 0x0F;
      002C2C 53 04 0F         [24] 9000 	anl	ar4,#0x0f
                                   9001 ;	..\COMMON\easyax5043.c:1705: r |= 0x10;
      002C2F 43 04 10         [24] 9002 	orl	ar4,#0x10
                                   9003 ;	..\COMMON\easyax5043.c:1708: radio_write8(AX5043_REG_PLLRANGINGA, r); // init ranging process starting from "range"
      002C32                       9004 00146$:
      002C32 90 40 33         [24] 9005 	mov	dptr,#0x4033
      002C35 EC               [12] 9006 	mov	a,r4
      002C36 F0               [24] 9007 	movx	@dptr,a
      002C37                       9008 00236$:
                                   9009 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:363: EA = 0;
      002C37 C2 AF            [12] 9010 	clr	_EA
                                   9011 ;	..\COMMON\easyax5043.c:1712: if (axradio_trxstate == trxstate_pll_ranging_done)
      002C39 74 06            [12] 9012 	mov	a,#0x06
      002C3B B5 09 02         [24] 9013 	cjne	a,_axradio_trxstate,00317$
      002C3E 80 1A            [24] 9014 	sjmp	00151$
      002C40                       9015 00317$:
                                   9016 ;	..\COMMON\easyax5043.c:1714: wtimer_idle(WTFLAG_CANSTANDBY);
      002C40 75 82 02         [24] 9017 	mov	dpl,#0x02
      002C43 C0 07            [24] 9018 	push	ar7
      002C45 C0 06            [24] 9019 	push	ar6
      002C47 12 41 4B         [24] 9020 	lcall	_wtimer_idle
      002C4A D0 06            [24] 9021 	pop	ar6
                                   9022 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:358: IE |= crit;
      002C4C EE               [12] 9023 	mov	a,r6
      002C4D 42 A8            [12] 9024 	orl	_IE,a
                                   9025 ;	..\COMMON\easyax5043.c:1716: wtimer_runcallbacks();
      002C4F C0 06            [24] 9026 	push	ar6
      002C51 12 41 CF         [24] 9027 	lcall	_wtimer_runcallbacks
      002C54 D0 06            [24] 9028 	pop	ar6
      002C56 D0 07            [24] 9029 	pop	ar7
      002C58 80 DD            [24] 9030 	sjmp	00236$
      002C5A                       9031 00151$:
                                   9032 ;	..\COMMON\easyax5043.c:1718: axradio_trxstate = trxstate_off;
      002C5A 75 09 00         [24] 9033 	mov	_axradio_trxstate,#0x00
                                   9034 ;	..\COMMON\easyax5043.c:1719: radio_write8(AX5043_REG_IRQMASK1, 0x00);
      002C5D 90 40 06         [24] 9035 	mov	dptr,#0x4006
      002C60 E4               [12] 9036 	clr	a
      002C61 F0               [24] 9037 	movx	@dptr,a
                                   9038 ;	..\COMMON\easyax5043.c:1720: axradio_phy_chanpllrng[i] = (uint8_t)radio_read8(AX5043_REG_PLLRANGINGA);
      002C62 EF               [12] 9039 	mov	a,r7
      002C63 75 F0 02         [24] 9040 	mov	b,#0x02
      002C66 A4               [48] 9041 	mul	ab
      002C67 24 01            [12] 9042 	add	a,#_axradio_phy_chanpllrng
      002C69 FC               [12] 9043 	mov	r4,a
      002C6A 74 00            [12] 9044 	mov	a,#(_axradio_phy_chanpllrng >> 8)
      002C6C 35 F0            [12] 9045 	addc	a,b
      002C6E FD               [12] 9046 	mov	r5,a
      002C6F 90 40 33         [24] 9047 	mov	dptr,#0x4033
      002C72 E0               [24] 9048 	movx	a,@dptr
      002C73 FB               [12] 9049 	mov	r3,a
      002C74 7A 00            [12] 9050 	mov	r2,#0x00
      002C76 8C 82            [24] 9051 	mov	dpl,r4
      002C78 8D 83            [24] 9052 	mov	dph,r5
      002C7A EB               [12] 9053 	mov	a,r3
      002C7B F0               [24] 9054 	movx	@dptr,a
      002C7C EA               [12] 9055 	mov	a,r2
      002C7D A3               [24] 9056 	inc	dptr
      002C7E F0               [24] 9057 	movx	@dptr,a
                                   9058 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:358: IE |= crit;
      002C7F EE               [12] 9059 	mov	a,r6
      002C80 42 A8            [12] 9060 	orl	_IE,a
                                   9061 ;	..\COMMON\easyax5043.c:1684: for (i = 0; i < axradio_phy_nrchannels; ++i) {
      002C82 0F               [12] 9062 	inc	r7
      002C83 02 2B 7E         [24] 9063 	ljmp	00239$
      002C86                       9064 00155$:
                                   9065 ;	..\COMMON\easyax5043.c:1724: if (axradio_phy_vcocalib) {
      002C86 90 4C 9C         [24] 9066 	mov	dptr,#_axradio_phy_vcocalib
      002C89 E4               [12] 9067 	clr	a
      002C8A 93               [24] 9068 	movc	a,@a+dptr
      002C8B 70 03            [24] 9069 	jnz	00318$
      002C8D 02 2E 0F         [24] 9070 	ljmp	00211$
      002C90                       9071 00318$:
                                   9072 ;	..\COMMON\easyax5043.c:1725: ax5043_set_registers_tx();
      002C90 12 06 55         [24] 9073 	lcall	_ax5043_set_registers_tx
                                   9074 ;	..\COMMON\easyax5043.c:1726: radio_write8(AX5043_REG_MODULATION, 0x08);
      002C93 90 40 10         [24] 9075 	mov	dptr,#0x4010
      002C96 74 08            [12] 9076 	mov	a,#0x08
      002C98 F0               [24] 9077 	movx	@dptr,a
                                   9078 ;	..\COMMON\easyax5043.c:1727: radio_write8(AX5043_REG_FSKDEV2, 0x00);
      002C99 90 41 61         [24] 9079 	mov	dptr,#0x4161
      002C9C E4               [12] 9080 	clr	a
      002C9D F0               [24] 9081 	movx	@dptr,a
                                   9082 ;	..\COMMON\easyax5043.c:1728: radio_write8(AX5043_REG_FSKDEV1, 0x00);
      002C9E 90 41 62         [24] 9083 	mov	dptr,#0x4162
      002CA1 F0               [24] 9084 	movx	@dptr,a
                                   9085 ;	..\COMMON\easyax5043.c:1729: radio_write8(AX5043_REG_FSKDEV0, 0x00);
      002CA2 90 41 63         [24] 9086 	mov	dptr,#0x4163
      002CA5 F0               [24] 9087 	movx	@dptr,a
                                   9088 ;	..\COMMON\easyax5043.c:1730: radio_write8(AX5043_REG_PLLLOOP, (radio_read8(AX5043_REG_PLLLOOP) | 0x04));
      002CA6 90 40 30         [24] 9089 	mov	dptr,#0x4030
      002CA9 E0               [24] 9090 	movx	a,@dptr
      002CAA 44 04            [12] 9091 	orl	a,#0x04
      002CAC F0               [24] 9092 	movx	@dptr,a
                                   9093 ;	..\COMMON\easyax5043.c:1732: uint8_t x = radio_read8(AX5043_REG_0xF35);
      002CAD 90 4F 35         [24] 9094 	mov	dptr,#0x4f35
      002CB0 E0               [24] 9095 	movx	a,@dptr
                                   9096 ;	..\COMMON\easyax5043.c:1733: x |= 0x80;
                                   9097 ;	..\COMMON\easyax5043.c:1734: if (2 & (uint8_t)~x)
      002CB1 44 80            [12] 9098 	orl	a,#0x80
      002CB3 FF               [12] 9099 	mov	r7,a
      002CB4 F4               [12] 9100 	cpl	a
      002CB5 FE               [12] 9101 	mov	r6,a
      002CB6 30 E1 01         [24] 9102 	jnb	acc.1,00173$
                                   9103 ;	..\COMMON\easyax5043.c:1735: ++x;
      002CB9 0F               [12] 9104 	inc	r7
                                   9105 ;	..\COMMON\easyax5043.c:1736: radio_write8(AX5043_REG_0xF35, x);
      002CBA                       9106 00173$:
      002CBA 90 4F 35         [24] 9107 	mov	dptr,#0x4f35
      002CBD EF               [12] 9108 	mov	a,r7
      002CBE F0               [24] 9109 	movx	@dptr,a
                                   9110 ;	..\COMMON\easyax5043.c:1738: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_SYNTH_TX);
      002CBF 90 40 02         [24] 9111 	mov	dptr,#0x4002
      002CC2 74 0C            [12] 9112 	mov	a,#0x0c
      002CC4 F0               [24] 9113 	movx	@dptr,a
                                   9114 ;	..\COMMON\easyax5043.c:1740: uint8_t __autodata vcoisave = radio_read8(AX5043_REG_PLLVCOI);
      002CC5 90 41 80         [24] 9115 	mov	dptr,#0x4180
      002CC8 E0               [24] 9116 	movx	a,@dptr
      002CC9 F5 0D            [12] 9117 	mov	_axradio_init_vcoisave_3_687,a
                                   9118 ;	..\COMMON\easyax5043.c:1741: uint8_t j = 2;
      002CCB 75 0E 02         [24] 9119 	mov	_axradio_init_j_3_687,#0x02
                                   9120 ;	..\COMMON\easyax5043.c:1742: for (i = 0; i < axradio_phy_nrchannels; ++i) {
      002CCE 75 0C 00         [24] 9121 	mov	_axradio_init_i_1_657,#0x00
      002CD1                       9122 00242$:
      002CD1 90 4C 71         [24] 9123 	mov	dptr,#_axradio_phy_nrchannels
      002CD4 E4               [12] 9124 	clr	a
      002CD5 93               [24] 9125 	movc	a,@a+dptr
      002CD6 FC               [12] 9126 	mov	r4,a
      002CD7 C3               [12] 9127 	clr	c
      002CD8 E5 0C            [12] 9128 	mov	a,_axradio_init_i_1_657
      002CDA 9C               [12] 9129 	subb	a,r4
      002CDB 40 03            [24] 9130 	jc	00320$
      002CDD 02 2E 09         [24] 9131 	ljmp	00206$
      002CE0                       9132 00320$:
                                   9133 ;	..\COMMON\easyax5043.c:1743: axradio_phy_chanvcoi[i] = 0;
      002CE0 E5 0C            [12] 9134 	mov	a,_axradio_init_i_1_657
      002CE2 24 0D            [12] 9135 	add	a,#_axradio_phy_chanvcoi
      002CE4 F5 82            [12] 9136 	mov	dpl,a
      002CE6 E4               [12] 9137 	clr	a
      002CE7 34 00            [12] 9138 	addc	a,#(_axradio_phy_chanvcoi >> 8)
      002CE9 F5 83            [12] 9139 	mov	dph,a
      002CEB E4               [12] 9140 	clr	a
      002CEC F0               [24] 9141 	movx	@dptr,a
                                   9142 ;	..\COMMON\easyax5043.c:1744: if (axradio_phy_chanpllrng[i] & 0x20)
      002CED E5 0C            [12] 9143 	mov	a,_axradio_init_i_1_657
      002CEF 75 F0 02         [24] 9144 	mov	b,#0x02
      002CF2 A4               [48] 9145 	mul	ab
      002CF3 FB               [12] 9146 	mov	r3,a
      002CF4 AC F0            [24] 9147 	mov	r4,b
      002CF6 24 01            [12] 9148 	add	a,#_axradio_phy_chanpllrng
      002CF8 F9               [12] 9149 	mov	r1,a
      002CF9 EC               [12] 9150 	mov	a,r4
      002CFA 34 00            [12] 9151 	addc	a,#(_axradio_phy_chanpllrng >> 8)
      002CFC FA               [12] 9152 	mov	r2,a
      002CFD 89 82            [24] 9153 	mov	dpl,r1
      002CFF 8A 83            [24] 9154 	mov	dph,r2
      002D01 E0               [24] 9155 	movx	a,@dptr
      002D02 F5 13            [12] 9156 	mov	_axradio_init_sloc0_1_0,a
      002D04 A3               [24] 9157 	inc	dptr
      002D05 E0               [24] 9158 	movx	a,@dptr
      002D06 F5 14            [12] 9159 	mov	(_axradio_init_sloc0_1_0 + 1),a
      002D08 E5 13            [12] 9160 	mov	a,_axradio_init_sloc0_1_0
      002D0A 30 E5 03         [24] 9161 	jnb	acc.5,00321$
      002D0D 02 2E 04         [24] 9162 	ljmp	00204$
      002D10                       9163 00321$:
                                   9164 ;	..\COMMON\easyax5043.c:1746: radio_write8(AX5043_REG_PLLRANGINGA, (axradio_phy_chanpllrng[i] & 0x0F));
      002D10 74 0F            [12] 9165 	mov	a,#0x0f
      002D12 55 13            [12] 9166 	anl	a,_axradio_init_sloc0_1_0
      002D14 F8               [12] 9167 	mov	r0,a
      002D15 90 40 33         [24] 9168 	mov	dptr,#0x4033
      002D18 F0               [24] 9169 	movx	@dptr,a
                                   9170 ;	..\COMMON\easyax5043.c:1748: uint32_t __autodata f = axradio_phy_chanfreq[i];
      002D19 E5 0C            [12] 9171 	mov	a,_axradio_init_i_1_657
      002D1B 75 F0 04         [24] 9172 	mov	b,#0x04
      002D1E A4               [48] 9173 	mul	ab
      002D1F 24 72            [12] 9174 	add	a,#_axradio_phy_chanfreq
      002D21 F5 82            [12] 9175 	mov	dpl,a
      002D23 74 4C            [12] 9176 	mov	a,#(_axradio_phy_chanfreq >> 8)
      002D25 35 F0            [12] 9177 	addc	a,b
      002D27 F5 83            [12] 9178 	mov	dph,a
      002D29 E4               [12] 9179 	clr	a
      002D2A 93               [24] 9180 	movc	a,@a+dptr
      002D2B F5 0F            [12] 9181 	mov	_axradio_init_f_5_690,a
      002D2D A3               [24] 9182 	inc	dptr
      002D2E E4               [12] 9183 	clr	a
      002D2F 93               [24] 9184 	movc	a,@a+dptr
      002D30 F5 10            [12] 9185 	mov	(_axradio_init_f_5_690 + 1),a
      002D32 A3               [24] 9186 	inc	dptr
      002D33 E4               [12] 9187 	clr	a
      002D34 93               [24] 9188 	movc	a,@a+dptr
      002D35 F5 11            [12] 9189 	mov	(_axradio_init_f_5_690 + 2),a
      002D37 A3               [24] 9190 	inc	dptr
      002D38 E4               [12] 9191 	clr	a
      002D39 93               [24] 9192 	movc	a,@a+dptr
      002D3A F5 12            [12] 9193 	mov	(_axradio_init_f_5_690 + 3),a
                                   9194 ;	..\COMMON\easyax5043.c:1749: radio_write8(AX5043_REG_FREQA0, f);
      002D3C AF 0F            [24] 9195 	mov	r7,_axradio_init_f_5_690
      002D3E 90 40 37         [24] 9196 	mov	dptr,#0x4037
      002D41 EF               [12] 9197 	mov	a,r7
      002D42 F0               [24] 9198 	movx	@dptr,a
                                   9199 ;	..\COMMON\easyax5043.c:1750: radio_write8(AX5043_REG_FREQA1, (f >> 8));
      002D43 AF 10            [24] 9200 	mov	r7,(_axradio_init_f_5_690 + 1)
      002D45 90 40 36         [24] 9201 	mov	dptr,#0x4036
      002D48 EF               [12] 9202 	mov	a,r7
      002D49 F0               [24] 9203 	movx	@dptr,a
                                   9204 ;	..\COMMON\easyax5043.c:1751: radio_write8(AX5043_REG_FREQA2, (f >> 16));
      002D4A AF 11            [24] 9205 	mov	r7,(_axradio_init_f_5_690 + 2)
      002D4C 90 40 35         [24] 9206 	mov	dptr,#0x4035
      002D4F EF               [12] 9207 	mov	a,r7
      002D50 F0               [24] 9208 	movx	@dptr,a
                                   9209 ;	..\COMMON\easyax5043.c:1752: radio_write8(AX5043_REG_FREQA3, (f >> 24));
      002D51 AF 12            [24] 9210 	mov	r7,(_axradio_init_f_5_690 + 3)
      002D53 90 40 34         [24] 9211 	mov	dptr,#0x4034
      002D56 EF               [12] 9212 	mov	a,r7
      002D57 F0               [24] 9213 	movx	@dptr,a
                                   9214 ;	..\COMMON\easyax5043.c:1754: do {
      002D58                       9215 00201$:
                                   9216 ;	..\COMMON\easyax5043.c:1755: if (axradio_phy_chanvcoiinit[0]) {
      002D58 90 4C 96         [24] 9217 	mov	dptr,#_axradio_phy_chanvcoiinit
      002D5B E4               [12] 9218 	clr	a
      002D5C 93               [24] 9219 	movc	a,@a+dptr
      002D5D 60 6B            [24] 9220 	jz	00199$
                                   9221 ;	..\COMMON\easyax5043.c:1756: uint8_t x = axradio_phy_chanvcoiinit[i];
      002D5F E5 0C            [12] 9222 	mov	a,_axradio_init_i_1_657
      002D61 90 4C 96         [24] 9223 	mov	dptr,#_axradio_phy_chanvcoiinit
      002D64 93               [24] 9224 	movc	a,@a+dptr
      002D65 FF               [12] 9225 	mov	r7,a
                                   9226 ;	..\COMMON\easyax5043.c:1757: if (!(axradio_phy_chanpllrnginit[0] & 0xF0))
      002D66 90 4C 8A         [24] 9227 	mov	dptr,#_axradio_phy_chanpllrnginit
      002D69 E4               [12] 9228 	clr	a
      002D6A 93               [24] 9229 	movc	a,@a+dptr
      002D6B FD               [12] 9230 	mov	r5,a
      002D6C A3               [24] 9231 	inc	dptr
      002D6D E4               [12] 9232 	clr	a
      002D6E 93               [24] 9233 	movc	a,@a+dptr
      002D6F FE               [12] 9234 	mov	r6,a
      002D70 ED               [12] 9235 	mov	a,r5
      002D71 54 F0            [12] 9236 	anl	a,#0xf0
      002D73 70 25            [24] 9237 	jnz	00197$
                                   9238 ;	..\COMMON\easyax5043.c:1758: x += (axradio_phy_chanpllrng[i] & 0x0F) - (axradio_phy_chanpllrnginit[i] & 0x0F);
      002D75 89 82            [24] 9239 	mov	dpl,r1
      002D77 8A 83            [24] 9240 	mov	dph,r2
      002D79 E0               [24] 9241 	movx	a,@dptr
      002D7A FD               [12] 9242 	mov	r5,a
      002D7B A3               [24] 9243 	inc	dptr
      002D7C E0               [24] 9244 	movx	a,@dptr
      002D7D 53 05 0F         [24] 9245 	anl	ar5,#0x0f
      002D80 EB               [12] 9246 	mov	a,r3
      002D81 24 8A            [12] 9247 	add	a,#_axradio_phy_chanpllrnginit
      002D83 F5 82            [12] 9248 	mov	dpl,a
      002D85 EC               [12] 9249 	mov	a,r4
      002D86 34 4C            [12] 9250 	addc	a,#(_axradio_phy_chanpllrnginit >> 8)
      002D88 F5 83            [12] 9251 	mov	dph,a
      002D8A E4               [12] 9252 	clr	a
      002D8B 93               [24] 9253 	movc	a,@a+dptr
      002D8C F8               [12] 9254 	mov	r0,a
      002D8D A3               [24] 9255 	inc	dptr
      002D8E E4               [12] 9256 	clr	a
      002D8F 93               [24] 9257 	movc	a,@a+dptr
      002D90 53 00 0F         [24] 9258 	anl	ar0,#0x0f
      002D93 7E 00            [12] 9259 	mov	r6,#0x00
      002D95 ED               [12] 9260 	mov	a,r5
      002D96 C3               [12] 9261 	clr	c
      002D97 98               [12] 9262 	subb	a,r0
      002D98 2F               [12] 9263 	add	a,r7
      002D99 FF               [12] 9264 	mov	r7,a
      002D9A                       9265 00197$:
                                   9266 ;	..\COMMON\easyax5043.c:1759: axradio_phy_chanvcoi[i] = axradio_adjustvcoi(x);
      002D9A E5 0C            [12] 9267 	mov	a,_axradio_init_i_1_657
      002D9C 24 0D            [12] 9268 	add	a,#_axradio_phy_chanvcoi
      002D9E FD               [12] 9269 	mov	r5,a
      002D9F E4               [12] 9270 	clr	a
      002DA0 34 00            [12] 9271 	addc	a,#(_axradio_phy_chanvcoi >> 8)
      002DA2 FE               [12] 9272 	mov	r6,a
      002DA3 8F 82            [24] 9273 	mov	dpl,r7
      002DA5 C0 06            [24] 9274 	push	ar6
      002DA7 C0 05            [24] 9275 	push	ar5
      002DA9 C0 04            [24] 9276 	push	ar4
      002DAB C0 03            [24] 9277 	push	ar3
      002DAD C0 02            [24] 9278 	push	ar2
      002DAF C0 01            [24] 9279 	push	ar1
      002DB1 12 28 F7         [24] 9280 	lcall	_axradio_adjustvcoi
      002DB4 AF 82            [24] 9281 	mov	r7,dpl
      002DB6 D0 01            [24] 9282 	pop	ar1
      002DB8 D0 02            [24] 9283 	pop	ar2
      002DBA D0 03            [24] 9284 	pop	ar3
      002DBC D0 04            [24] 9285 	pop	ar4
      002DBE D0 05            [24] 9286 	pop	ar5
      002DC0 D0 06            [24] 9287 	pop	ar6
      002DC2 8D 82            [24] 9288 	mov	dpl,r5
      002DC4 8E 83            [24] 9289 	mov	dph,r6
      002DC6 EF               [12] 9290 	mov	a,r7
      002DC7 F0               [24] 9291 	movx	@dptr,a
      002DC8 80 2C            [24] 9292 	sjmp	00202$
      002DCA                       9293 00199$:
                                   9294 ;	..\COMMON\easyax5043.c:1761: axradio_phy_chanvcoi[i] = axradio_calvcoi();
      002DCA E5 0C            [12] 9295 	mov	a,_axradio_init_i_1_657
      002DCC 24 0D            [12] 9296 	add	a,#_axradio_phy_chanvcoi
      002DCE FE               [12] 9297 	mov	r6,a
      002DCF E4               [12] 9298 	clr	a
      002DD0 34 00            [12] 9299 	addc	a,#(_axradio_phy_chanvcoi >> 8)
      002DD2 FF               [12] 9300 	mov	r7,a
      002DD3 C0 07            [24] 9301 	push	ar7
      002DD5 C0 06            [24] 9302 	push	ar6
      002DD7 C0 04            [24] 9303 	push	ar4
      002DD9 C0 03            [24] 9304 	push	ar3
      002DDB C0 02            [24] 9305 	push	ar2
      002DDD C0 01            [24] 9306 	push	ar1
      002DDF 12 29 CA         [24] 9307 	lcall	_axradio_calvcoi
      002DE2 AD 82            [24] 9308 	mov	r5,dpl
      002DE4 D0 01            [24] 9309 	pop	ar1
      002DE6 D0 02            [24] 9310 	pop	ar2
      002DE8 D0 03            [24] 9311 	pop	ar3
      002DEA D0 04            [24] 9312 	pop	ar4
      002DEC D0 06            [24] 9313 	pop	ar6
      002DEE D0 07            [24] 9314 	pop	ar7
      002DF0 8E 82            [24] 9315 	mov	dpl,r6
      002DF2 8F 83            [24] 9316 	mov	dph,r7
      002DF4 ED               [12] 9317 	mov	a,r5
      002DF5 F0               [24] 9318 	movx	@dptr,a
      002DF6                       9319 00202$:
                                   9320 ;	..\COMMON\easyax5043.c:1763: } while (--j);
      002DF6 E5 0E            [12] 9321 	mov	a,_axradio_init_j_3_687
      002DF8 14               [12] 9322 	dec	a
      002DF9 FF               [12] 9323 	mov	r7,a
      002DFA 8F 0E            [24] 9324 	mov	_axradio_init_j_3_687,r7
      002DFC 60 03            [24] 9325 	jz	00325$
      002DFE 02 2D 58         [24] 9326 	ljmp	00201$
      002E01                       9327 00325$:
                                   9328 ;	..\COMMON\easyax5043.c:1764: j = 1;
      002E01 75 0E 01         [24] 9329 	mov	_axradio_init_j_3_687,#0x01
      002E04                       9330 00204$:
                                   9331 ;	..\COMMON\easyax5043.c:1742: for (i = 0; i < axradio_phy_nrchannels; ++i) {
      002E04 05 0C            [12] 9332 	inc	_axradio_init_i_1_657
      002E06 02 2C D1         [24] 9333 	ljmp	00242$
                                   9334 ;	..\COMMON\easyax5043.c:1784: radio_write8(AX5043_REG_PLLVCOI, vcoisave);
      002E09                       9335 00206$:
      002E09 90 41 80         [24] 9336 	mov	dptr,#0x4180
      002E0C E5 0D            [12] 9337 	mov	a,_axradio_init_vcoisave_3_687
      002E0E F0               [24] 9338 	movx	@dptr,a
                                   9339 ;	..\COMMON\easyax5043.c:1817: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_POWERDOWN);
      002E0F                       9340 00211$:
      002E0F 90 40 02         [24] 9341 	mov	dptr,#0x4002
      002E12 E4               [12] 9342 	clr	a
      002E13 F0               [24] 9343 	movx	@dptr,a
                                   9344 ;	..\COMMON\easyax5043.c:1818: ax5043_init_registers();
      002E14 12 19 13         [24] 9345 	lcall	_ax5043_init_registers
                                   9346 ;	..\COMMON\easyax5043.c:1819: ax5043_set_registers_rx();
      002E17 12 06 79         [24] 9347 	lcall	_ax5043_set_registers_rx
                                   9348 ;	..\COMMON\easyax5043.c:1820: radio_write8(AX5043_REG_PLLRANGINGA, (axradio_phy_chanpllrng[0] & 0x0F));
      002E1A 90 00 01         [24] 9349 	mov	dptr,#_axradio_phy_chanpllrng
      002E1D E0               [24] 9350 	movx	a,@dptr
      002E1E FE               [12] 9351 	mov	r6,a
      002E1F A3               [24] 9352 	inc	dptr
      002E20 E0               [24] 9353 	movx	a,@dptr
      002E21 53 06 0F         [24] 9354 	anl	ar6,#0x0f
      002E24 90 40 33         [24] 9355 	mov	dptr,#0x4033
      002E27 EE               [12] 9356 	mov	a,r6
      002E28 F0               [24] 9357 	movx	@dptr,a
                                   9358 ;	..\COMMON\easyax5043.c:1822: uint32_t __autodata f = axradio_phy_chanfreq[0];
      002E29 90 4C 72         [24] 9359 	mov	dptr,#_axradio_phy_chanfreq
      002E2C E4               [12] 9360 	clr	a
      002E2D 93               [24] 9361 	movc	a,@a+dptr
      002E2E FC               [12] 9362 	mov	r4,a
      002E2F A3               [24] 9363 	inc	dptr
      002E30 E4               [12] 9364 	clr	a
      002E31 93               [24] 9365 	movc	a,@a+dptr
      002E32 FD               [12] 9366 	mov	r5,a
      002E33 A3               [24] 9367 	inc	dptr
      002E34 E4               [12] 9368 	clr	a
      002E35 93               [24] 9369 	movc	a,@a+dptr
      002E36 FE               [12] 9370 	mov	r6,a
      002E37 A3               [24] 9371 	inc	dptr
      002E38 E4               [12] 9372 	clr	a
      002E39 93               [24] 9373 	movc	a,@a+dptr
      002E3A FF               [12] 9374 	mov	r7,a
                                   9375 ;	..\COMMON\easyax5043.c:1823: radio_write8(AX5043_REG_FREQA0, f);
      002E3B 8C 03            [24] 9376 	mov	ar3,r4
      002E3D 90 40 37         [24] 9377 	mov	dptr,#0x4037
      002E40 EB               [12] 9378 	mov	a,r3
      002E41 F0               [24] 9379 	movx	@dptr,a
                                   9380 ;	..\COMMON\easyax5043.c:1824: radio_write8(AX5043_REG_FREQA1, (f >> 8));
      002E42 8D 03            [24] 9381 	mov	ar3,r5
      002E44 90 40 36         [24] 9382 	mov	dptr,#0x4036
      002E47 EB               [12] 9383 	mov	a,r3
      002E48 F0               [24] 9384 	movx	@dptr,a
                                   9385 ;	..\COMMON\easyax5043.c:1825: radio_write8(AX5043_REG_FREQA2, (f >> 16));
      002E49 8E 03            [24] 9386 	mov	ar3,r6
      002E4B 90 40 35         [24] 9387 	mov	dptr,#0x4035
      002E4E EB               [12] 9388 	mov	a,r3
      002E4F F0               [24] 9389 	movx	@dptr,a
                                   9390 ;	..\COMMON\easyax5043.c:1826: radio_write8(AX5043_REG_FREQA3, (f >> 24));
      002E50 8F 04            [24] 9391 	mov	ar4,r7
      002E52 90 40 34         [24] 9392 	mov	dptr,#0x4034
      002E55 EC               [12] 9393 	mov	a,r4
      002E56 F0               [24] 9394 	movx	@dptr,a
                                   9395 ;	..\COMMON\easyax5043.c:1829: axradio_mode = AXRADIO_MODE_OFF;
      002E57 75 08 01         [24] 9396 	mov	_axradio_mode,#0x01
                                   9397 ;	..\COMMON\easyax5043.c:1830: for (i = 0; i < axradio_phy_nrchannels; ++i)
      002E5A 7F 00            [12] 9398 	mov	r7,#0x00
      002E5C                       9399 00244$:
      002E5C 90 4C 71         [24] 9400 	mov	dptr,#_axradio_phy_nrchannels
      002E5F E4               [12] 9401 	clr	a
      002E60 93               [24] 9402 	movc	a,@a+dptr
      002E61 FE               [12] 9403 	mov	r6,a
      002E62 C3               [12] 9404 	clr	c
      002E63 EF               [12] 9405 	mov	a,r7
      002E64 9E               [12] 9406 	subb	a,r6
      002E65 50 1F            [24] 9407 	jnc	00231$
                                   9408 ;	..\COMMON\easyax5043.c:1831: if (axradio_phy_chanpllrng[i] & 0x20)
      002E67 EF               [12] 9409 	mov	a,r7
      002E68 75 F0 02         [24] 9410 	mov	b,#0x02
      002E6B A4               [48] 9411 	mul	ab
      002E6C 24 01            [12] 9412 	add	a,#_axradio_phy_chanpllrng
      002E6E F5 82            [12] 9413 	mov	dpl,a
      002E70 74 00            [12] 9414 	mov	a,#(_axradio_phy_chanpllrng >> 8)
      002E72 35 F0            [12] 9415 	addc	a,b
      002E74 F5 83            [12] 9416 	mov	dph,a
      002E76 E0               [24] 9417 	movx	a,@dptr
      002E77 FD               [12] 9418 	mov	r5,a
      002E78 A3               [24] 9419 	inc	dptr
      002E79 E0               [24] 9420 	movx	a,@dptr
      002E7A FE               [12] 9421 	mov	r6,a
      002E7B ED               [12] 9422 	mov	a,r5
      002E7C 30 E5 04         [24] 9423 	jnb	acc.5,00245$
                                   9424 ;	..\COMMON\easyax5043.c:1832: return AXRADIO_ERR_RANGING;
      002E7F 75 82 06         [24] 9425 	mov	dpl,#0x06
      002E82 22               [24] 9426 	ret
      002E83                       9427 00245$:
                                   9428 ;	..\COMMON\easyax5043.c:1830: for (i = 0; i < axradio_phy_nrchannels; ++i)
      002E83 0F               [12] 9429 	inc	r7
      002E84 80 D6            [24] 9430 	sjmp	00244$
      002E86                       9431 00231$:
                                   9432 ;	..\COMMON\easyax5043.c:1833: return AXRADIO_ERR_NOERROR;
      002E86 75 82 00         [24] 9433 	mov	dpl,#0x00
      002E89 22               [24] 9434 	ret
                                   9435 ;------------------------------------------------------------
                                   9436 ;Allocation info for local variables in function 'axradio_cansleep'
                                   9437 ;------------------------------------------------------------
                                   9438 ;	..\COMMON\easyax5043.c:1836: __reentrantb uint8_t axradio_cansleep(void) __reentrant
                                   9439 ;	-----------------------------------------
                                   9440 ;	 function axradio_cansleep
                                   9441 ;	-----------------------------------------
      002E8A                       9442 _axradio_cansleep:
                                   9443 ;	..\COMMON\easyax5043.c:1838: if (axradio_trxstate == trxstate_off || axradio_trxstate == trxstate_rxwor)
      002E8A E5 09            [12] 9444 	mov	a,_axradio_trxstate
      002E8C 60 05            [24] 9445 	jz	00101$
      002E8E 74 02            [12] 9446 	mov	a,#0x02
      002E90 B5 09 04         [24] 9447 	cjne	a,_axradio_trxstate,00102$
      002E93                       9448 00101$:
                                   9449 ;	..\COMMON\easyax5043.c:1839: return 1;
      002E93 75 82 01         [24] 9450 	mov	dpl,#0x01
      002E96 22               [24] 9451 	ret
      002E97                       9452 00102$:
                                   9453 ;	..\COMMON\easyax5043.c:1840: return 0;
      002E97 75 82 00         [24] 9454 	mov	dpl,#0x00
      002E9A 22               [24] 9455 	ret
                                   9456 ;------------------------------------------------------------
                                   9457 ;Allocation info for local variables in function 'wtimer_cansleep_dummy'
                                   9458 ;------------------------------------------------------------
                                   9459 ;	..\COMMON\easyax5043.c:1844: static void wtimer_cansleep_dummy(void) __naked
                                   9460 ;	-----------------------------------------
                                   9461 ;	 function wtimer_cansleep_dummy
                                   9462 ;	-----------------------------------------
      002E9B                       9463 _wtimer_cansleep_dummy:
                                   9464 ;	naked function: no prologue.
                                   9465 ;	..\COMMON\easyax5043.c:1858: __endasm;
                                   9466 	.area	WTCANSLP0 (CODE)
                                   9467 	.area	WTCANSLP1 (CODE)
                                   9468 	.area	WTCANSLP2 (CODE)
                                   9469 	.area	WTCANSLP1 (CODE)
      0050CA 12 2E 8A         [24] 9470 	lcall	_axradio_cansleep
      0050CD E5 82            [12] 9471 	mov	a,dpl
      0050CF 70 01            [24] 9472 	jnz	00000$
      0050D1 22               [24] 9473 	ret
      0050D2                       9474 	00000$:
                                   9475 	.area	CSEG (CODE)
                                   9476 ;	naked function: no epilogue.
                                   9477 ;------------------------------------------------------------
                                   9478 ;Allocation info for local variables in function 'axradio_set_mode'
                                   9479 ;------------------------------------------------------------
                                   9480 ;mode                      Allocated to registers r7 
                                   9481 ;r                         Allocated to registers r5 
                                   9482 ;r                         Allocated to registers r6 
                                   9483 ;__00030034                Allocated to registers 
                                   9484 ;crit                      Allocated to registers r6 
                                   9485 ;crit                      Allocated to registers r6 
                                   9486 ;__00040036                Allocated to registers 
                                   9487 ;crit                      Allocated to registers 
                                   9488 ;------------------------------------------------------------
                                   9489 ;	..\COMMON\easyax5043.c:1862: uint8_t axradio_set_mode(uint8_t mode)
                                   9490 ;	-----------------------------------------
                                   9491 ;	 function axradio_set_mode
                                   9492 ;	-----------------------------------------
      002E9B                       9493 _axradio_set_mode:
                                   9494 ;	..\COMMON\easyax5043.c:1864: if (mode == axradio_mode)
      002E9B E5 82            [12] 9495 	mov	a,dpl
      002E9D FF               [12] 9496 	mov	r7,a
      002E9E B5 08 04         [24] 9497 	cjne	a,_axradio_mode,00102$
                                   9498 ;	..\COMMON\easyax5043.c:1865: return AXRADIO_ERR_NOERROR;
      002EA1 75 82 00         [24] 9499 	mov	dpl,#0x00
      002EA4 22               [24] 9500 	ret
      002EA5                       9501 00102$:
                                   9502 ;	..\COMMON\easyax5043.c:1866: switch (axradio_mode) {
      002EA5 AE 08            [24] 9503 	mov	r6,_axradio_mode
      002EA7 BE 00 02         [24] 9504 	cjne	r6,#0x00,00357$
      002EAA 80 4C            [24] 9505 	sjmp	00103$
      002EAC                       9506 00357$:
      002EAC BE 02 02         [24] 9507 	cjne	r6,#0x02,00358$
      002EAF 80 5A            [24] 9508 	sjmp	00106$
      002EB1                       9509 00358$:
      002EB1 BE 03 03         [24] 9510 	cjne	r6,#0x03,00359$
      002EB4 02 2F 3B         [24] 9511 	ljmp	00116$
      002EB7                       9512 00359$:
      002EB7 BE 18 03         [24] 9513 	cjne	r6,#0x18,00360$
      002EBA 02 2F 3B         [24] 9514 	ljmp	00116$
      002EBD                       9515 00360$:
      002EBD BE 19 02         [24] 9516 	cjne	r6,#0x19,00361$
      002EC0 80 79            [24] 9517 	sjmp	00116$
      002EC2                       9518 00361$:
      002EC2 BE 1A 02         [24] 9519 	cjne	r6,#0x1a,00362$
      002EC5 80 74            [24] 9520 	sjmp	00116$
      002EC7                       9521 00362$:
      002EC7 BE 1B 02         [24] 9522 	cjne	r6,#0x1b,00363$
      002ECA 80 6F            [24] 9523 	sjmp	00116$
      002ECC                       9524 00363$:
      002ECC BE 1C 02         [24] 9525 	cjne	r6,#0x1c,00364$
      002ECF 80 6A            [24] 9526 	sjmp	00116$
      002ED1                       9527 00364$:
      002ED1 BE 28 03         [24] 9528 	cjne	r6,#0x28,00365$
      002ED4 02 2F 94         [24] 9529 	ljmp	00124$
      002ED7                       9530 00365$:
      002ED7 BE 29 03         [24] 9531 	cjne	r6,#0x29,00366$
      002EDA 02 2F 94         [24] 9532 	ljmp	00124$
      002EDD                       9533 00366$:
      002EDD BE 2A 03         [24] 9534 	cjne	r6,#0x2a,00367$
      002EE0 02 2F 94         [24] 9535 	ljmp	00124$
      002EE3                       9536 00367$:
      002EE3 BE 2B 03         [24] 9537 	cjne	r6,#0x2b,00368$
      002EE6 02 2F 94         [24] 9538 	ljmp	00124$
      002EE9                       9539 00368$:
      002EE9 BE 2C 03         [24] 9540 	cjne	r6,#0x2c,00369$
      002EEC 02 2F 94         [24] 9541 	ljmp	00124$
      002EEF                       9542 00369$:
      002EEF BE 2D 03         [24] 9543 	cjne	r6,#0x2d,00370$
      002EF2 02 2F 94         [24] 9544 	ljmp	00124$
      002EF5                       9545 00370$:
      002EF5 02 2F A1         [24] 9546 	ljmp	00125$
                                   9547 ;	..\COMMON\easyax5043.c:1867: case AXRADIO_MODE_UNINIT:
      002EF8                       9548 00103$:
                                   9549 ;	..\COMMON\easyax5043.c:1869: uint8_t __autodata r = axradio_init();
      002EF8 C0 07            [24] 9550 	push	ar7
      002EFA 12 2A 9B         [24] 9551 	lcall	_axradio_init
      002EFD AE 82            [24] 9552 	mov	r6,dpl
      002EFF D0 07            [24] 9553 	pop	ar7
                                   9554 ;	..\COMMON\easyax5043.c:1870: if (r != AXRADIO_ERR_NOERROR)
      002F01 EE               [12] 9555 	mov	a,r6
      002F02 FD               [12] 9556 	mov	r5,a
      002F03 70 03            [24] 9557 	jnz	00371$
      002F05 02 2F AB         [24] 9558 	ljmp	00126$
      002F08                       9559 00371$:
                                   9560 ;	..\COMMON\easyax5043.c:1871: return r;
      002F08 8D 82            [24] 9561 	mov	dpl,r5
      002F0A 22               [24] 9562 	ret
                                   9563 ;	..\COMMON\easyax5043.c:1875: case AXRADIO_MODE_DEEPSLEEP:
      002F0B                       9564 00106$:
                                   9565 ;	..\COMMON\easyax5043.c:1877: uint8_t __autodata r = ax5043_wakeup_deepsleep();
      002F0B C0 07            [24] 9566 	push	ar7
      002F0D 12 3D C2         [24] 9567 	lcall	_ax5043_wakeup_deepsleep
      002F10 AE 82            [24] 9568 	mov	r6,dpl
      002F12 D0 07            [24] 9569 	pop	ar7
                                   9570 ;	..\COMMON\easyax5043.c:1878: if (r)
      002F14 EE               [12] 9571 	mov	a,r6
      002F15 60 04            [24] 9572 	jz	00108$
                                   9573 ;	..\COMMON\easyax5043.c:1879: return AXRADIO_ERR_NOCHIP;
      002F17 75 82 05         [24] 9574 	mov	dpl,#0x05
      002F1A 22               [24] 9575 	ret
      002F1B                       9576 00108$:
                                   9577 ;	..\COMMON\easyax5043.c:1880: ax5043_init_registers();
      002F1B C0 07            [24] 9578 	push	ar7
      002F1D 12 19 13         [24] 9579 	lcall	_ax5043_init_registers
                                   9580 ;	..\COMMON\easyax5043.c:1881: r = axradio_set_channel(axradio_curchannel);
      002F20 90 00 18         [24] 9581 	mov	dptr,#_axradio_curchannel
      002F23 E0               [24] 9582 	movx	a,@dptr
      002F24 F5 82            [12] 9583 	mov	dpl,a
      002F26 12 32 EC         [24] 9584 	lcall	_axradio_set_channel
      002F29 AE 82            [24] 9585 	mov	r6,dpl
      002F2B D0 07            [24] 9586 	pop	ar7
                                   9587 ;	..\COMMON\easyax5043.c:1882: if (r != AXRADIO_ERR_NOERROR)
      002F2D EE               [12] 9588 	mov	a,r6
      002F2E 60 03            [24] 9589 	jz	00110$
                                   9590 ;	..\COMMON\easyax5043.c:1883: return r;
      002F30 8E 82            [24] 9591 	mov	dpl,r6
      002F32 22               [24] 9592 	ret
      002F33                       9593 00110$:
                                   9594 ;	..\COMMON\easyax5043.c:1884: axradio_trxstate = trxstate_off;
      002F33 75 09 00         [24] 9595 	mov	_axradio_trxstate,#0x00
                                   9596 ;	..\COMMON\easyax5043.c:1885: axradio_mode = AXRADIO_MODE_OFF;
      002F36 75 08 01         [24] 9597 	mov	_axradio_mode,#0x01
                                   9598 ;	..\COMMON\easyax5043.c:1886: break;
                                   9599 ;	..\COMMON\easyax5043.c:1894: case AXRADIO_MODE_CW_TRANSMIT:
      002F39 80 70            [24] 9600 	sjmp	00126$
      002F3B                       9601 00116$:
                                   9602 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:351: criticalsection_t crit = IE & 0x80;
      002F3B 74 80            [12] 9603 	mov	a,#0x80
      002F3D 55 A8            [12] 9604 	anl	a,_IE
      002F3F FE               [12] 9605 	mov	r6,a
                                   9606 ;	..\COMMON\easyax5043.c:1896: criticalsection_t crit = enter_critical();
      002F40 C2 AF            [12] 9607 	clr	_EA
                                   9608 ;	..\COMMON\easyax5043.c:1897: if (axradio_trxstate == trxstate_off) {
      002F42 E5 09            [12] 9609 	mov	a,_axradio_trxstate
      002F44 70 38            [24] 9610 	jnz	00118$
                                   9611 ;	..\COMMON\easyax5043.c:1898: update_timeanchor();
      002F46 C0 07            [24] 9612 	push	ar7
      002F48 C0 06            [24] 9613 	push	ar6
      002F4A 12 0A 7C         [24] 9614 	lcall	_update_timeanchor
                                   9615 ;	..\COMMON\easyax5043.c:1899: wtimer_remove_callback(&axradio_cb_transmitend.cb);
      002F4D 90 02 89         [24] 9616 	mov	dptr,#_axradio_cb_transmitend
      002F50 12 48 82         [24] 9617 	lcall	_wtimer_remove_callback
                                   9618 ;	..\COMMON\easyax5043.c:1900: axradio_cb_transmitend.st.error = AXRADIO_ERR_NOERROR;
      002F53 90 02 8E         [24] 9619 	mov	dptr,#(_axradio_cb_transmitend + 0x0005)
      002F56 E4               [12] 9620 	clr	a
      002F57 F0               [24] 9621 	movx	@dptr,a
                                   9622 ;	..\COMMON\easyax5043.c:1901: axradio_cb_transmitend.st.time.t = axradio_timeanchor.radiotimer;
      002F58 90 00 29         [24] 9623 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      002F5B E0               [24] 9624 	movx	a,@dptr
      002F5C FA               [12] 9625 	mov	r2,a
      002F5D A3               [24] 9626 	inc	dptr
      002F5E E0               [24] 9627 	movx	a,@dptr
      002F5F FB               [12] 9628 	mov	r3,a
      002F60 A3               [24] 9629 	inc	dptr
      002F61 E0               [24] 9630 	movx	a,@dptr
      002F62 FC               [12] 9631 	mov	r4,a
      002F63 A3               [24] 9632 	inc	dptr
      002F64 E0               [24] 9633 	movx	a,@dptr
      002F65 FD               [12] 9634 	mov	r5,a
      002F66 90 02 8F         [24] 9635 	mov	dptr,#(_axradio_cb_transmitend + 0x0006)
      002F69 EA               [12] 9636 	mov	a,r2
      002F6A F0               [24] 9637 	movx	@dptr,a
      002F6B EB               [12] 9638 	mov	a,r3
      002F6C A3               [24] 9639 	inc	dptr
      002F6D F0               [24] 9640 	movx	@dptr,a
      002F6E EC               [12] 9641 	mov	a,r4
      002F6F A3               [24] 9642 	inc	dptr
      002F70 F0               [24] 9643 	movx	@dptr,a
      002F71 ED               [12] 9644 	mov	a,r5
      002F72 A3               [24] 9645 	inc	dptr
      002F73 F0               [24] 9646 	movx	@dptr,a
                                   9647 ;	..\COMMON\easyax5043.c:1902: wtimer_add_callback(&axradio_cb_transmitend.cb);
      002F74 90 02 89         [24] 9648 	mov	dptr,#_axradio_cb_transmitend
      002F77 12 42 C4         [24] 9649 	lcall	_wtimer_add_callback
      002F7A D0 06            [24] 9650 	pop	ar6
      002F7C D0 07            [24] 9651 	pop	ar7
      002F7E                       9652 00118$:
                                   9653 ;	..\COMMON\easyax5043.c:1904: ax5043_off();
      002F7E C0 07            [24] 9654 	push	ar7
      002F80 C0 06            [24] 9655 	push	ar6
      002F82 12 17 8A         [24] 9656 	lcall	_ax5043_off
      002F85 D0 06            [24] 9657 	pop	ar6
                                   9658 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:358: IE |= crit;
      002F87 EE               [12] 9659 	mov	a,r6
      002F88 42 A8            [12] 9660 	orl	_IE,a
                                   9661 ;	..\COMMON\easyax5043.c:1907: ax5043_init_registers();
      002F8A 12 19 13         [24] 9662 	lcall	_ax5043_init_registers
      002F8D D0 07            [24] 9663 	pop	ar7
                                   9664 ;	..\COMMON\easyax5043.c:1908: axradio_mode = AXRADIO_MODE_OFF;
      002F8F 75 08 01         [24] 9665 	mov	_axradio_mode,#0x01
                                   9666 ;	..\COMMON\easyax5043.c:1909: break;
                                   9667 ;	..\COMMON\easyax5043.c:1917: case AXRADIO_MODE_STREAM_RECEIVE_DATAPIN:
      002F92 80 17            [24] 9668 	sjmp	00126$
      002F94                       9669 00124$:
                                   9670 ;	..\COMMON\easyax5043.c:1918: ax5043_off();
      002F94 C0 07            [24] 9671 	push	ar7
      002F96 12 17 8A         [24] 9672 	lcall	_ax5043_off
                                   9673 ;	..\COMMON\easyax5043.c:1919: ax5043_init_registers();
      002F99 12 19 13         [24] 9674 	lcall	_ax5043_init_registers
      002F9C D0 07            [24] 9675 	pop	ar7
                                   9676 ;	..\COMMON\easyax5043.c:1920: axradio_mode = AXRADIO_MODE_OFF;
      002F9E 75 08 01         [24] 9677 	mov	_axradio_mode,#0x01
                                   9678 ;	..\COMMON\easyax5043.c:1922: default:
      002FA1                       9679 00125$:
                                   9680 ;	..\COMMON\easyax5043.c:1923: ax5043_off();
      002FA1 C0 07            [24] 9681 	push	ar7
      002FA3 12 17 8A         [24] 9682 	lcall	_ax5043_off
      002FA6 D0 07            [24] 9683 	pop	ar7
                                   9684 ;	..\COMMON\easyax5043.c:1924: axradio_mode = AXRADIO_MODE_OFF;
      002FA8 75 08 01         [24] 9685 	mov	_axradio_mode,#0x01
                                   9686 ;	..\COMMON\easyax5043.c:1926: }
      002FAB                       9687 00126$:
                                   9688 ;	..\COMMON\easyax5043.c:1927: axradio_killallcb();
      002FAB C0 07            [24] 9689 	push	ar7
      002FAD 12 28 81         [24] 9690 	lcall	_axradio_killallcb
      002FB0 D0 07            [24] 9691 	pop	ar7
                                   9692 ;	..\COMMON\easyax5043.c:1928: if (mode == AXRADIO_MODE_UNINIT)
      002FB2 EF               [12] 9693 	mov	a,r7
      002FB3 70 04            [24] 9694 	jnz	00128$
                                   9695 ;	..\COMMON\easyax5043.c:1929: return AXRADIO_ERR_NOTSUPPORTED;
      002FB5 75 82 01         [24] 9696 	mov	dpl,#0x01
      002FB8 22               [24] 9697 	ret
      002FB9                       9698 00128$:
                                   9699 ;	..\COMMON\easyax5043.c:1930: axradio_syncstate = syncstate_off;
      002FB9 90 00 13         [24] 9700 	mov	dptr,#_axradio_syncstate
      002FBC E4               [12] 9701 	clr	a
      002FBD F0               [24] 9702 	movx	@dptr,a
                                   9703 ;	..\COMMON\easyax5043.c:1931: switch (mode) {
      002FBE EF               [12] 9704 	mov	a,r7
      002FBF 24 CC            [12] 9705 	add	a,#0xff - 0x33
      002FC1 50 03            [24] 9706 	jnc	00376$
      002FC3 02 32 E4         [24] 9707 	ljmp	00253$
      002FC6                       9708 00376$:
      002FC6 EF               [12] 9709 	mov	a,r7
      002FC7 24 0A            [12] 9710 	add	a,#(00377$-3-.)
      002FC9 83               [24] 9711 	movc	a,@a+pc
      002FCA F5 82            [12] 9712 	mov	dpl,a
      002FCC EF               [12] 9713 	mov	a,r7
      002FCD 24 38            [12] 9714 	add	a,#(00378$-3-.)
      002FCF 83               [24] 9715 	movc	a,@a+pc
      002FD0 F5 83            [12] 9716 	mov	dph,a
      002FD2 E4               [12] 9717 	clr	a
      002FD3 73               [24] 9718 	jmp	@a+dptr
      002FD4                       9719 00377$:
      002FD4 E4                    9720 	.db	00253$
      002FD5 3C                    9721 	.db	00129$
      002FD6 40                    9722 	.db	00130$
      002FD7 AC                    9723 	.db	00215$
      002FD8 E4                    9724 	.db	00253$
      002FD9 E4                    9725 	.db	00253$
      002FDA E4                    9726 	.db	00253$
      002FDB E4                    9727 	.db	00253$
      002FDC E4                    9728 	.db	00253$
      002FDD E4                    9729 	.db	00253$
      002FDE E4                    9730 	.db	00253$
      002FDF E4                    9731 	.db	00253$
      002FE0 E4                    9732 	.db	00253$
      002FE1 E4                    9733 	.db	00253$
      002FE2 E4                    9734 	.db	00253$
      002FE3 E4                    9735 	.db	00253$
      002FE4 4A                    9736 	.db	00131$
      002FE5 59                    9737 	.db	00133$
      002FE6 4A                    9738 	.db	00132$
      002FE7 59                    9739 	.db	00134$
      002FE8 E4                    9740 	.db	00253$
      002FE9 E4                    9741 	.db	00253$
      002FEA E4                    9742 	.db	00253$
      002FEB E4                    9743 	.db	00253$
      002FEC BB                    9744 	.db	00143$
      002FED BB                    9745 	.db	00144$
      002FEE BB                    9746 	.db	00145$
      002FEF BB                    9747 	.db	00146$
      002FF0 BB                    9748 	.db	00142$
      002FF1 E4                    9749 	.db	00253$
      002FF2 E4                    9750 	.db	00253$
      002FF3 E4                    9751 	.db	00253$
      002FF4 68                    9752 	.db	00135$
      002FF5 A9                    9753 	.db	00140$
      002FF6 68                    9754 	.db	00136$
      002FF7 A9                    9755 	.db	00141$
      002FF8 E4                    9756 	.db	00253$
      002FF9 E4                    9757 	.db	00253$
      002FFA E4                    9758 	.db	00253$
      002FFB E4                    9759 	.db	00253$
      002FFC 48                    9760 	.db	00175$
      002FFD 48                    9761 	.db	00176$
      002FFE 48                    9762 	.db	00177$
      002FFF 48                    9763 	.db	00178$
      003000 48                    9764 	.db	00174$
      003001 48                    9765 	.db	00179$
      003002 E4                    9766 	.db	00253$
      003003 E4                    9767 	.db	00253$
      003004 EF                    9768 	.db	00249$
      003005 EF                    9769 	.db	00250$
      003006 4A                    9770 	.db	00251$
      003007 4A                    9771 	.db	00252$
      003008                       9772 00378$:
      003008 32                    9773 	.db	00253$>>8
      003009 30                    9774 	.db	00129$>>8
      00300A 30                    9775 	.db	00130$>>8
      00300B 31                    9776 	.db	00215$>>8
      00300C 32                    9777 	.db	00253$>>8
      00300D 32                    9778 	.db	00253$>>8
      00300E 32                    9779 	.db	00253$>>8
      00300F 32                    9780 	.db	00253$>>8
      003010 32                    9781 	.db	00253$>>8
      003011 32                    9782 	.db	00253$>>8
      003012 32                    9783 	.db	00253$>>8
      003013 32                    9784 	.db	00253$>>8
      003014 32                    9785 	.db	00253$>>8
      003015 32                    9786 	.db	00253$>>8
      003016 32                    9787 	.db	00253$>>8
      003017 32                    9788 	.db	00253$>>8
      003018 30                    9789 	.db	00131$>>8
      003019 30                    9790 	.db	00133$>>8
      00301A 30                    9791 	.db	00132$>>8
      00301B 30                    9792 	.db	00134$>>8
      00301C 32                    9793 	.db	00253$>>8
      00301D 32                    9794 	.db	00253$>>8
      00301E 32                    9795 	.db	00253$>>8
      00301F 32                    9796 	.db	00253$>>8
      003020 30                    9797 	.db	00143$>>8
      003021 30                    9798 	.db	00144$>>8
      003022 30                    9799 	.db	00145$>>8
      003023 30                    9800 	.db	00146$>>8
      003024 30                    9801 	.db	00142$>>8
      003025 32                    9802 	.db	00253$>>8
      003026 32                    9803 	.db	00253$>>8
      003027 32                    9804 	.db	00253$>>8
      003028 30                    9805 	.db	00135$>>8
      003029 30                    9806 	.db	00140$>>8
      00302A 30                    9807 	.db	00136$>>8
      00302B 30                    9808 	.db	00141$>>8
      00302C 32                    9809 	.db	00253$>>8
      00302D 32                    9810 	.db	00253$>>8
      00302E 32                    9811 	.db	00253$>>8
      00302F 32                    9812 	.db	00253$>>8
      003030 31                    9813 	.db	00175$>>8
      003031 31                    9814 	.db	00176$>>8
      003032 31                    9815 	.db	00177$>>8
      003033 31                    9816 	.db	00178$>>8
      003034 31                    9817 	.db	00174$>>8
      003035 31                    9818 	.db	00179$>>8
      003036 32                    9819 	.db	00253$>>8
      003037 32                    9820 	.db	00253$>>8
      003038 31                    9821 	.db	00249$>>8
      003039 31                    9822 	.db	00250$>>8
      00303A 32                    9823 	.db	00251$>>8
      00303B 32                    9824 	.db	00252$>>8
                                   9825 ;	..\COMMON\easyax5043.c:1932: case AXRADIO_MODE_OFF:
      00303C                       9826 00129$:
                                   9827 ;	..\COMMON\easyax5043.c:1933: return AXRADIO_ERR_NOERROR;
      00303C 75 82 00         [24] 9828 	mov	dpl,#0x00
      00303F 22               [24] 9829 	ret
                                   9830 ;	..\COMMON\easyax5043.c:1935: case AXRADIO_MODE_DEEPSLEEP:
      003040                       9831 00130$:
                                   9832 ;	..\COMMON\easyax5043.c:1936: ax5043_enter_deepsleep();
      003040 12 3D A2         [24] 9833 	lcall	_ax5043_enter_deepsleep
                                   9834 ;	..\COMMON\easyax5043.c:1937: axradio_mode = AXRADIO_MODE_DEEPSLEEP;
      003043 75 08 02         [24] 9835 	mov	_axradio_mode,#0x02
                                   9836 ;	..\COMMON\easyax5043.c:1938: return AXRADIO_ERR_NOERROR;
      003046 75 82 00         [24] 9837 	mov	dpl,#0x00
      003049 22               [24] 9838 	ret
                                   9839 ;	..\COMMON\easyax5043.c:1940: case AXRADIO_MODE_ASYNC_TRANSMIT:
      00304A                       9840 00131$:
                                   9841 ;	..\COMMON\easyax5043.c:1941: case AXRADIO_MODE_ACK_TRANSMIT:
      00304A                       9842 00132$:
                                   9843 ;	..\COMMON\easyax5043.c:1942: axradio_mode = mode;
      00304A 8F 08            [24] 9844 	mov	_axradio_mode,r7
                                   9845 ;	..\COMMON\easyax5043.c:1943: axradio_ack_seqnr = 0xff;
      00304C 90 00 1E         [24] 9846 	mov	dptr,#_axradio_ack_seqnr
      00304F 74 FF            [12] 9847 	mov	a,#0xff
      003051 F0               [24] 9848 	movx	@dptr,a
                                   9849 ;	..\COMMON\easyax5043.c:1944: ax5043_init_registers_tx();
      003052 12 0B 5F         [24] 9850 	lcall	_ax5043_init_registers_tx
                                   9851 ;	..\COMMON\easyax5043.c:1945: return AXRADIO_ERR_NOERROR;
      003055 75 82 00         [24] 9852 	mov	dpl,#0x00
      003058 22               [24] 9853 	ret
                                   9854 ;	..\COMMON\easyax5043.c:1947: case AXRADIO_MODE_WOR_TRANSMIT:
      003059                       9855 00133$:
                                   9856 ;	..\COMMON\easyax5043.c:1948: case AXRADIO_MODE_WOR_ACK_TRANSMIT:
      003059                       9857 00134$:
                                   9858 ;	..\COMMON\easyax5043.c:1949: axradio_mode = mode;
      003059 8F 08            [24] 9859 	mov	_axradio_mode,r7
                                   9860 ;	..\COMMON\easyax5043.c:1950: axradio_ack_seqnr = 0xff;
      00305B 90 00 1E         [24] 9861 	mov	dptr,#_axradio_ack_seqnr
      00305E 74 FF            [12] 9862 	mov	a,#0xff
      003060 F0               [24] 9863 	movx	@dptr,a
                                   9864 ;	..\COMMON\easyax5043.c:1951: ax5043_init_registers_tx();
      003061 12 0B 5F         [24] 9865 	lcall	_ax5043_init_registers_tx
                                   9866 ;	..\COMMON\easyax5043.c:1952: return AXRADIO_ERR_NOERROR;
      003064 75 82 00         [24] 9867 	mov	dpl,#0x00
      003067 22               [24] 9868 	ret
                                   9869 ;	..\COMMON\easyax5043.c:1954: case AXRADIO_MODE_ASYNC_RECEIVE:
      003068                       9870 00135$:
                                   9871 ;	..\COMMON\easyax5043.c:1955: case AXRADIO_MODE_ACK_RECEIVE:
      003068                       9872 00136$:
                                   9873 ;	..\COMMON\easyax5043.c:1956: axradio_mode = mode;
      003068 8F 08            [24] 9874 	mov	_axradio_mode,r7
                                   9875 ;	..\COMMON\easyax5043.c:1957: axradio_ack_seqnr = 0xff;
      00306A 90 00 1E         [24] 9876 	mov	dptr,#_axradio_ack_seqnr
      00306D 74 FF            [12] 9877 	mov	a,#0xff
      00306F F0               [24] 9878 	movx	@dptr,a
                                   9879 ;	..\COMMON\easyax5043.c:1958: ax5043_init_registers_rx();
      003070 12 0B 65         [24] 9880 	lcall	_ax5043_init_registers_rx
                                   9881 ;	..\COMMON\easyax5043.c:1959: ax5043_receiver_on_continuous();
      003073 12 16 3B         [24] 9882 	lcall	_ax5043_receiver_on_continuous
                                   9883 ;	..\COMMON\easyax5043.c:1960: enablecs:
      003076                       9884 00137$:
                                   9885 ;	..\COMMON\easyax5043.c:1961: if (axradio_phy_cs_enabled) {
      003076 90 4C A6         [24] 9886 	mov	dptr,#_axradio_phy_cs_enabled
      003079 E4               [12] 9887 	clr	a
      00307A 93               [24] 9888 	movc	a,@a+dptr
      00307B 60 28            [24] 9889 	jz	00139$
                                   9890 ;	..\COMMON\easyax5043.c:1962: wtimer_remove(&axradio_timer);
      00307D 90 02 9D         [24] 9891 	mov	dptr,#_axradio_timer
      003080 12 47 8D         [24] 9892 	lcall	_wtimer_remove
                                   9893 ;	..\COMMON\easyax5043.c:1963: axradio_timer.time = axradio_phy_cs_period;
      003083 90 4C A4         [24] 9894 	mov	dptr,#_axradio_phy_cs_period
      003086 E4               [12] 9895 	clr	a
      003087 93               [24] 9896 	movc	a,@a+dptr
      003088 FD               [12] 9897 	mov	r5,a
      003089 74 01            [12] 9898 	mov	a,#0x01
      00308B 93               [24] 9899 	movc	a,@a+dptr
      00308C FE               [12] 9900 	mov	r6,a
      00308D 7C 00            [12] 9901 	mov	r4,#0x00
      00308F 7B 00            [12] 9902 	mov	r3,#0x00
      003091 90 02 A1         [24] 9903 	mov	dptr,#(_axradio_timer + 0x0004)
      003094 ED               [12] 9904 	mov	a,r5
      003095 F0               [24] 9905 	movx	@dptr,a
      003096 EE               [12] 9906 	mov	a,r6
      003097 A3               [24] 9907 	inc	dptr
      003098 F0               [24] 9908 	movx	@dptr,a
      003099 EC               [12] 9909 	mov	a,r4
      00309A A3               [24] 9910 	inc	dptr
      00309B F0               [24] 9911 	movx	@dptr,a
      00309C EB               [12] 9912 	mov	a,r3
      00309D A3               [24] 9913 	inc	dptr
      00309E F0               [24] 9914 	movx	@dptr,a
                                   9915 ;	..\COMMON\easyax5043.c:1964: wtimer0_addrelative(&axradio_timer);
      00309F 90 02 9D         [24] 9916 	mov	dptr,#_axradio_timer
      0030A2 12 42 DE         [24] 9917 	lcall	_wtimer0_addrelative
      0030A5                       9918 00139$:
                                   9919 ;	..\COMMON\easyax5043.c:1966: return AXRADIO_ERR_NOERROR;
      0030A5 75 82 00         [24] 9920 	mov	dpl,#0x00
      0030A8 22               [24] 9921 	ret
                                   9922 ;	..\COMMON\easyax5043.c:1968: case AXRADIO_MODE_WOR_RECEIVE:
      0030A9                       9923 00140$:
                                   9924 ;	..\COMMON\easyax5043.c:1969: case AXRADIO_MODE_WOR_ACK_RECEIVE:
      0030A9                       9925 00141$:
                                   9926 ;	..\COMMON\easyax5043.c:1970: axradio_ack_seqnr = 0xff;
      0030A9 90 00 1E         [24] 9927 	mov	dptr,#_axradio_ack_seqnr
      0030AC 74 FF            [12] 9928 	mov	a,#0xff
      0030AE F0               [24] 9929 	movx	@dptr,a
                                   9930 ;	..\COMMON\easyax5043.c:1971: axradio_mode = mode;
      0030AF 8F 08            [24] 9931 	mov	_axradio_mode,r7
                                   9932 ;	..\COMMON\easyax5043.c:1972: ax5043_init_registers_rx();
      0030B1 12 0B 65         [24] 9933 	lcall	_ax5043_init_registers_rx
                                   9934 ;	..\COMMON\easyax5043.c:1973: ax5043_receiver_on_wor();
      0030B4 12 16 A2         [24] 9935 	lcall	_ax5043_receiver_on_wor
                                   9936 ;	..\COMMON\easyax5043.c:1974: return AXRADIO_ERR_NOERROR;
      0030B7 75 82 00         [24] 9937 	mov	dpl,#0x00
      0030BA 22               [24] 9938 	ret
                                   9939 ;	..\COMMON\easyax5043.c:1976: case AXRADIO_MODE_STREAM_TRANSMIT:
      0030BB                       9940 00142$:
                                   9941 ;	..\COMMON\easyax5043.c:1977: case AXRADIO_MODE_STREAM_TRANSMIT_UNENC:
      0030BB                       9942 00143$:
                                   9943 ;	..\COMMON\easyax5043.c:1978: case AXRADIO_MODE_STREAM_TRANSMIT_SCRAM:
      0030BB                       9944 00144$:
                                   9945 ;	..\COMMON\easyax5043.c:1979: case AXRADIO_MODE_STREAM_TRANSMIT_UNENC_LSB:
      0030BB                       9946 00145$:
                                   9947 ;	..\COMMON\easyax5043.c:1980: case AXRADIO_MODE_STREAM_TRANSMIT_SCRAM_LSB:
      0030BB                       9948 00146$:
                                   9949 ;	..\COMMON\easyax5043.c:1981: axradio_mode = mode;
      0030BB 8F 08            [24] 9950 	mov	_axradio_mode,r7
                                   9951 ;	..\COMMON\easyax5043.c:1982: if (axradio_mode == AXRADIO_MODE_STREAM_TRANSMIT_UNENC ||
      0030BD 74 18            [12] 9952 	mov	a,#0x18
      0030BF B5 08 02         [24] 9953 	cjne	a,_axradio_mode,00380$
      0030C2 80 05            [24] 9954 	sjmp	00147$
      0030C4                       9955 00380$:
                                   9956 ;	..\COMMON\easyax5043.c:1983: axradio_mode == AXRADIO_MODE_STREAM_TRANSMIT_UNENC_LSB)
      0030C4 74 1A            [12] 9957 	mov	a,#0x1a
      0030C6 B5 08 05         [24] 9958 	cjne	a,_axradio_mode,00151$
                                   9959 ;	..\COMMON\easyax5043.c:1984: radio_write8(AX5043_REG_ENCODING, 0);
      0030C9                       9960 00147$:
      0030C9 90 40 11         [24] 9961 	mov	dptr,#0x4011
      0030CC E4               [12] 9962 	clr	a
      0030CD F0               [24] 9963 	movx	@dptr,a
      0030CE                       9964 00151$:
                                   9965 ;	..\COMMON\easyax5043.c:1985: if (axradio_mode == AXRADIO_MODE_STREAM_TRANSMIT_SCRAM ||
      0030CE 74 19            [12] 9966 	mov	a,#0x19
      0030D0 B5 08 02         [24] 9967 	cjne	a,_axradio_mode,00383$
      0030D3 80 05            [24] 9968 	sjmp	00153$
      0030D5                       9969 00383$:
                                   9970 ;	..\COMMON\easyax5043.c:1986: axradio_mode == AXRADIO_MODE_STREAM_TRANSMIT_SCRAM_LSB)
      0030D5 74 1B            [12] 9971 	mov	a,#0x1b
      0030D7 B5 08 06         [24] 9972 	cjne	a,_axradio_mode,00157$
                                   9973 ;	..\COMMON\easyax5043.c:1987: radio_write8(AX5043_REG_ENCODING, 4);
      0030DA                       9974 00153$:
      0030DA 90 40 11         [24] 9975 	mov	dptr,#0x4011
      0030DD 74 04            [12] 9976 	mov	a,#0x04
      0030DF F0               [24] 9977 	movx	@dptr,a
      0030E0                       9978 00157$:
                                   9979 ;	..\COMMON\easyax5043.c:1988: if (axradio_mode == AXRADIO_MODE_STREAM_TRANSMIT_UNENC_LSB ||
      0030E0 74 1A            [12] 9980 	mov	a,#0x1a
      0030E2 B5 08 02         [24] 9981 	cjne	a,_axradio_mode,00386$
      0030E5 80 05            [24] 9982 	sjmp	00159$
      0030E7                       9983 00386$:
                                   9984 ;	..\COMMON\easyax5043.c:1989: axradio_mode == AXRADIO_MODE_STREAM_TRANSMIT_SCRAM_LSB)
      0030E7 74 1B            [12] 9985 	mov	a,#0x1b
      0030E9 B5 08 08         [24] 9986 	cjne	a,_axradio_mode,00163$
                                   9987 ;	..\COMMON\easyax5043.c:1990: radio_write8(AX5043_REG_PKTADDRCFG, (radio_read8(AX5043_REG_PKTADDRCFG) & 0x7F));
      0030EC                       9988 00159$:
      0030EC 90 42 00         [24] 9989 	mov	dptr,#0x4200
      0030EF E0               [24] 9990 	movx	a,@dptr
      0030F0 54 7F            [12] 9991 	anl	a,#0x7f
      0030F2 FE               [12] 9992 	mov	r6,a
      0030F3 F0               [24] 9993 	movx	@dptr,a
      0030F4                       9994 00163$:
                                   9995 ;	..\COMMON\easyax5043.c:1991: ax5043_init_registers_tx();
      0030F4 12 0B 5F         [24] 9996 	lcall	_ax5043_init_registers_tx
                                   9997 ;	..\COMMON\easyax5043.c:1992: radio_write8(AX5043_REG_FRAMING, 0);
      0030F7 90 40 12         [24] 9998 	mov	dptr,#0x4012
      0030FA E4               [12] 9999 	clr	a
      0030FB F0               [24]10000 	movx	@dptr,a
                                  10001 ;	..\COMMON\easyax5043.c:1993: ax5043_prepare_tx();
      0030FC 12 17 61         [24]10002 	lcall	_ax5043_prepare_tx
                                  10003 ;	..\COMMON\easyax5043.c:1994: axradio_trxstate = trxstate_txstream_xtalwait;
      0030FF 75 09 0F         [24]10004 	mov	_axradio_trxstate,#0x0f
                                  10005 ;	..\COMMON\easyax5043.c:1995: while (!(radio_read8(AX5043_REG_POWSTAT) & 0x08)) {}; // wait for modem vdd so writing the FIFO is safe
      003102                      10006 00168$:
      003102 90 40 03         [24]10007 	mov	dptr,#0x4003
      003105 E0               [24]10008 	movx	a,@dptr
      003106 FE               [12]10009 	mov	r6,a
      003107 30 E3 F8         [24]10010 	jnb	acc.3,00168$
                                  10011 ;	..\COMMON\easyax5043.c:1996: radio_write8(AX5043_REG_FIFOSTAT, 3); // clear FIFO data & flags (prevent transmitting anything left over in the FIFO, this has no effect if the FIFO is not powerered, in this case it is reset any way)
      00310A 90 40 28         [24]10012 	mov	dptr,#0x4028
      00310D 74 03            [12]10013 	mov	a,#0x03
      00310F F0               [24]10014 	movx	@dptr,a
                                  10015 ;	..\COMMON\easyax5043.c:1997: radio_read8(AX5043_REG_RADIOEVENTREQ0); // make sure REVRDONE bit is cleared, so it is a reliable indicator that the packet is out
      003110 90 40 0F         [24]10016 	mov	dptr,#0x400f
      003113 E0               [24]10017 	movx	a,@dptr
                                  10018 ;	..\COMMON\easyax5043.c:1998: update_timeanchor();
      003114 12 0A 7C         [24]10019 	lcall	_update_timeanchor
                                  10020 ;	..\COMMON\easyax5043.c:1999: wtimer_remove_callback(&axradio_cb_transmitdata.cb);
      003117 90 02 93         [24]10021 	mov	dptr,#_axradio_cb_transmitdata
      00311A 12 48 82         [24]10022 	lcall	_wtimer_remove_callback
                                  10023 ;	..\COMMON\easyax5043.c:2000: axradio_cb_transmitdata.st.error = AXRADIO_ERR_NOERROR;
      00311D 90 02 98         [24]10024 	mov	dptr,#(_axradio_cb_transmitdata + 0x0005)
      003120 E4               [12]10025 	clr	a
      003121 F0               [24]10026 	movx	@dptr,a
                                  10027 ;	..\COMMON\easyax5043.c:2001: axradio_cb_transmitdata.st.time.t = axradio_timeanchor.radiotimer;
      003122 90 00 29         [24]10028 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      003125 E0               [24]10029 	movx	a,@dptr
      003126 FB               [12]10030 	mov	r3,a
      003127 A3               [24]10031 	inc	dptr
      003128 E0               [24]10032 	movx	a,@dptr
      003129 FC               [12]10033 	mov	r4,a
      00312A A3               [24]10034 	inc	dptr
      00312B E0               [24]10035 	movx	a,@dptr
      00312C FD               [12]10036 	mov	r5,a
      00312D A3               [24]10037 	inc	dptr
      00312E E0               [24]10038 	movx	a,@dptr
      00312F FE               [12]10039 	mov	r6,a
      003130 90 02 99         [24]10040 	mov	dptr,#(_axradio_cb_transmitdata + 0x0006)
      003133 EB               [12]10041 	mov	a,r3
      003134 F0               [24]10042 	movx	@dptr,a
      003135 EC               [12]10043 	mov	a,r4
      003136 A3               [24]10044 	inc	dptr
      003137 F0               [24]10045 	movx	@dptr,a
      003138 ED               [12]10046 	mov	a,r5
      003139 A3               [24]10047 	inc	dptr
      00313A F0               [24]10048 	movx	@dptr,a
      00313B EE               [12]10049 	mov	a,r6
      00313C A3               [24]10050 	inc	dptr
      00313D F0               [24]10051 	movx	@dptr,a
                                  10052 ;	..\COMMON\easyax5043.c:2002: wtimer_add_callback(&axradio_cb_transmitdata.cb);
      00313E 90 02 93         [24]10053 	mov	dptr,#_axradio_cb_transmitdata
      003141 12 42 C4         [24]10054 	lcall	_wtimer_add_callback
                                  10055 ;	..\COMMON\easyax5043.c:2003: return AXRADIO_ERR_NOERROR;
      003144 75 82 00         [24]10056 	mov	dpl,#0x00
      003147 22               [24]10057 	ret
                                  10058 ;	..\COMMON\easyax5043.c:2005: case AXRADIO_MODE_STREAM_RECEIVE:
      003148                      10059 00174$:
                                  10060 ;	..\COMMON\easyax5043.c:2006: case AXRADIO_MODE_STREAM_RECEIVE_UNENC:
      003148                      10061 00175$:
                                  10062 ;	..\COMMON\easyax5043.c:2007: case AXRADIO_MODE_STREAM_RECEIVE_SCRAM:
      003148                      10063 00176$:
                                  10064 ;	..\COMMON\easyax5043.c:2008: case AXRADIO_MODE_STREAM_RECEIVE_UNENC_LSB:
      003148                      10065 00177$:
                                  10066 ;	..\COMMON\easyax5043.c:2009: case AXRADIO_MODE_STREAM_RECEIVE_SCRAM_LSB:
      003148                      10067 00178$:
                                  10068 ;	..\COMMON\easyax5043.c:2010: case AXRADIO_MODE_STREAM_RECEIVE_DATAPIN:
      003148                      10069 00179$:
                                  10070 ;	..\COMMON\easyax5043.c:2011: axradio_mode = mode;
      003148 8F 08            [24]10071 	mov	_axradio_mode,r7
                                  10072 ;	..\COMMON\easyax5043.c:2012: ax5043_init_registers_rx();
      00314A 12 0B 65         [24]10073 	lcall	_ax5043_init_registers_rx
                                  10074 ;	..\COMMON\easyax5043.c:2013: if (axradio_mode == AXRADIO_MODE_STREAM_RECEIVE_UNENC ||
      00314D 74 28            [12]10075 	mov	a,#0x28
      00314F B5 08 02         [24]10076 	cjne	a,_axradio_mode,00390$
      003152 80 05            [24]10077 	sjmp	00180$
      003154                      10078 00390$:
                                  10079 ;	..\COMMON\easyax5043.c:2014: axradio_mode == AXRADIO_MODE_STREAM_RECEIVE_UNENC_LSB)
      003154 74 2A            [12]10080 	mov	a,#0x2a
      003156 B5 08 05         [24]10081 	cjne	a,_axradio_mode,00184$
                                  10082 ;	..\COMMON\easyax5043.c:2015: radio_write8(AX5043_REG_ENCODING, 0);
      003159                      10083 00180$:
      003159 90 40 11         [24]10084 	mov	dptr,#0x4011
      00315C E4               [12]10085 	clr	a
      00315D F0               [24]10086 	movx	@dptr,a
      00315E                      10087 00184$:
                                  10088 ;	..\COMMON\easyax5043.c:2016: if (axradio_mode == AXRADIO_MODE_STREAM_RECEIVE_SCRAM ||
      00315E 74 29            [12]10089 	mov	a,#0x29
      003160 B5 08 02         [24]10090 	cjne	a,_axradio_mode,00393$
      003163 80 05            [24]10091 	sjmp	00186$
      003165                      10092 00393$:
                                  10093 ;	..\COMMON\easyax5043.c:2017: axradio_mode == AXRADIO_MODE_STREAM_RECEIVE_SCRAM_LSB)
      003165 74 2B            [12]10094 	mov	a,#0x2b
      003167 B5 08 06         [24]10095 	cjne	a,_axradio_mode,00190$
                                  10096 ;	..\COMMON\easyax5043.c:2018: radio_write8(AX5043_REG_ENCODING, 4);
      00316A                      10097 00186$:
      00316A 90 40 11         [24]10098 	mov	dptr,#0x4011
      00316D 74 04            [12]10099 	mov	a,#0x04
      00316F F0               [24]10100 	movx	@dptr,a
      003170                      10101 00190$:
                                  10102 ;	..\COMMON\easyax5043.c:2019: if (axradio_mode == AXRADIO_MODE_STREAM_RECEIVE_UNENC_LSB ||
      003170 74 2A            [12]10103 	mov	a,#0x2a
      003172 B5 08 02         [24]10104 	cjne	a,_axradio_mode,00396$
      003175 80 05            [24]10105 	sjmp	00192$
      003177                      10106 00396$:
                                  10107 ;	..\COMMON\easyax5043.c:2020: axradio_mode == AXRADIO_MODE_STREAM_RECEIVE_SCRAM_LSB)
      003177 74 2B            [12]10108 	mov	a,#0x2b
      003179 B5 08 08         [24]10109 	cjne	a,_axradio_mode,00198$
                                  10110 ;	..\COMMON\easyax5043.c:2021: radio_write8(AX5043_REG_PKTADDRCFG, (radio_read8(AX5043_REG_PKTADDRCFG) & 0x7F));
      00317C                      10111 00192$:
      00317C 90 42 00         [24]10112 	mov	dptr,#0x4200
      00317F E0               [24]10113 	movx	a,@dptr
      003180 54 7F            [12]10114 	anl	a,#0x7f
      003182 FE               [12]10115 	mov	r6,a
      003183 F0               [24]10116 	movx	@dptr,a
                                  10117 ;	..\COMMON\easyax5043.c:2022: radio_write8(AX5043_REG_FRAMING, 0);
      003184                      10118 00198$:
      003184 90 40 12         [24]10119 	mov	dptr,#0x4012
      003187 E4               [12]10120 	clr	a
      003188 F0               [24]10121 	movx	@dptr,a
                                  10122 ;	..\COMMON\easyax5043.c:2023: radio_write8(AX5043_REG_PKTCHUNKSIZE, 8); // 64 byte
      003189 90 42 30         [24]10123 	mov	dptr,#0x4230
      00318C 74 08            [12]10124 	mov	a,#0x08
      00318E F0               [24]10125 	movx	@dptr,a
                                  10126 ;	..\COMMON\easyax5043.c:2024: radio_write8(AX5043_REG_RXPARAMSETS, 0x00);
      00318F 90 41 17         [24]10127 	mov	dptr,#0x4117
      003192 E4               [12]10128 	clr	a
      003193 F0               [24]10129 	movx	@dptr,a
                                  10130 ;	..\COMMON\easyax5043.c:2025: if (axradio_mode == AXRADIO_MODE_STREAM_RECEIVE_DATAPIN) {
      003194 74 2D            [12]10131 	mov	a,#0x2d
      003196 B5 08 0D         [24]10132 	cjne	a,_axradio_mode,00214$
                                  10133 ;	..\COMMON\easyax5043.c:2026: ax5043_set_registers_rxcont_singleparamset();
      003199 12 06 BD         [24]10134 	lcall	_ax5043_set_registers_rxcont_singleparamset
                                  10135 ;	..\COMMON\easyax5043.c:2027: radio_write8(AX5043_REG_PINFUNCDATA, 0x04);
      00319C 90 40 23         [24]10136 	mov	dptr,#0x4023
      00319F 74 04            [12]10137 	mov	a,#0x04
      0031A1 F0               [24]10138 	movx	@dptr,a
                                  10139 ;	..\COMMON\easyax5043.c:2028: radio_write8(AX5043_REG_PINFUNCDCLK, 0x04);
      0031A2 90 40 22         [24]10140 	mov	dptr,#0x4022
      0031A5 F0               [24]10141 	movx	@dptr,a
      0031A6                      10142 00214$:
                                  10143 ;	..\COMMON\easyax5043.c:2030: ax5043_receiver_on_continuous();
      0031A6 12 16 3B         [24]10144 	lcall	_ax5043_receiver_on_continuous
                                  10145 ;	..\COMMON\easyax5043.c:2031: goto enablecs;
      0031A9 02 30 76         [24]10146 	ljmp	00137$
                                  10147 ;	..\COMMON\easyax5043.c:2033: case AXRADIO_MODE_CW_TRANSMIT:
      0031AC                      10148 00215$:
                                  10149 ;	..\COMMON\easyax5043.c:2034: axradio_mode = AXRADIO_MODE_CW_TRANSMIT;
      0031AC 75 08 03         [24]10150 	mov	_axradio_mode,#0x03
                                  10151 ;	..\COMMON\easyax5043.c:2035: ax5043_init_registers_tx();
      0031AF 12 0B 5F         [24]10152 	lcall	_ax5043_init_registers_tx
                                  10153 ;	..\COMMON\easyax5043.c:2036: radio_write8(AX5043_REG_MODULATION, 8);   // Set an FSK mode
      0031B2 90 40 10         [24]10154 	mov	dptr,#0x4010
      0031B5 74 08            [12]10155 	mov	a,#0x08
      0031B7 F0               [24]10156 	movx	@dptr,a
                                  10157 ;	..\COMMON\easyax5043.c:2037: radio_write8(AX5043_REG_FSKDEV2, 0x00);
      0031B8 90 41 61         [24]10158 	mov	dptr,#0x4161
      0031BB E4               [12]10159 	clr	a
      0031BC F0               [24]10160 	movx	@dptr,a
                                  10161 ;	..\COMMON\easyax5043.c:2038: radio_write8(AX5043_REG_FSKDEV1, 0x00);
      0031BD 90 41 62         [24]10162 	mov	dptr,#0x4162
      0031C0 F0               [24]10163 	movx	@dptr,a
                                  10164 ;	..\COMMON\easyax5043.c:2039: radio_write8(AX5043_REG_FSKDEV0, 0x00);
      0031C1 90 41 63         [24]10165 	mov	dptr,#0x4163
      0031C4 F0               [24]10166 	movx	@dptr,a
                                  10167 ;	..\COMMON\easyax5043.c:2040: radio_write8(AX5043_REG_TXRATE2, 0x00);
      0031C5 90 41 65         [24]10168 	mov	dptr,#0x4165
      0031C8 F0               [24]10169 	movx	@dptr,a
                                  10170 ;	..\COMMON\easyax5043.c:2041: radio_write8(AX5043_REG_TXRATE1, 0x00);
      0031C9 90 41 66         [24]10171 	mov	dptr,#0x4166
      0031CC F0               [24]10172 	movx	@dptr,a
                                  10173 ;	..\COMMON\easyax5043.c:2042: radio_write8(AX5043_REG_TXRATE0, 0x01);
      0031CD 90 41 67         [24]10174 	mov	dptr,#0x4167
      0031D0 04               [12]10175 	inc	a
      0031D1 F0               [24]10176 	movx	@dptr,a
                                  10177 ;	..\COMMON\easyax5043.c:2043: radio_write8(AX5043_REG_PINFUNCDATA, 0x04);
      0031D2 90 40 23         [24]10178 	mov	dptr,#0x4023
      0031D5 74 04            [12]10179 	mov	a,#0x04
      0031D7 F0               [24]10180 	movx	@dptr,a
                                  10181 ;	..\COMMON\easyax5043.c:2044: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_FIFO_ON);
      0031D8 90 40 02         [24]10182 	mov	dptr,#0x4002
      0031DB 74 07            [12]10183 	mov	a,#0x07
      0031DD F0               [24]10184 	movx	@dptr,a
                                  10185 ;	..\COMMON\easyax5043.c:2045: axradio_trxstate = trxstate_txcw_xtalwait;
      0031DE 75 09 0E         [24]10186 	mov	_axradio_trxstate,#0x0e
                                  10187 ;	..\COMMON\easyax5043.c:2046: radio_write8(AX5043_REG_IRQMASK0, 0x00);
      0031E1 90 40 07         [24]10188 	mov	dptr,#0x4007
      0031E4 E4               [12]10189 	clr	a
      0031E5 F0               [24]10190 	movx	@dptr,a
                                  10191 ;	..\COMMON\easyax5043.c:2047: radio_write8(AX5043_REG_IRQMASK1, 0x01); // enable xtal ready interrupt
      0031E6 90 40 06         [24]10192 	mov	dptr,#0x4006
      0031E9 04               [12]10193 	inc	a
      0031EA F0               [24]10194 	movx	@dptr,a
                                  10195 ;	..\COMMON\easyax5043.c:2048: return AXRADIO_ERR_NOERROR;
      0031EB 75 82 00         [24]10196 	mov	dpl,#0x00
      0031EE 22               [24]10197 	ret
                                  10198 ;	..\COMMON\easyax5043.c:2050: case AXRADIO_MODE_SYNC_MASTER:
      0031EF                      10199 00249$:
                                  10200 ;	..\COMMON\easyax5043.c:2051: case AXRADIO_MODE_SYNC_ACK_MASTER:
      0031EF                      10201 00250$:
                                  10202 ;	..\COMMON\easyax5043.c:2052: axradio_mode = mode;
      0031EF 8F 08            [24]10203 	mov	_axradio_mode,r7
                                  10204 ;	..\COMMON\easyax5043.c:2053: axradio_syncstate = syncstate_master_normal;
      0031F1 90 00 13         [24]10205 	mov	dptr,#_axradio_syncstate
      0031F4 74 03            [12]10206 	mov	a,#0x03
      0031F6 F0               [24]10207 	movx	@dptr,a
                                  10208 ;	..\COMMON\easyax5043.c:2055: wtimer_remove(&axradio_timer);
      0031F7 90 02 9D         [24]10209 	mov	dptr,#_axradio_timer
      0031FA 12 47 8D         [24]10210 	lcall	_wtimer_remove
                                  10211 ;	..\COMMON\easyax5043.c:2056: axradio_timer.time = 2;
      0031FD 90 02 A1         [24]10212 	mov	dptr,#(_axradio_timer + 0x0004)
      003200 74 02            [12]10213 	mov	a,#0x02
      003202 F0               [24]10214 	movx	@dptr,a
      003203 E4               [12]10215 	clr	a
      003204 A3               [24]10216 	inc	dptr
      003205 F0               [24]10217 	movx	@dptr,a
      003206 A3               [24]10218 	inc	dptr
      003207 F0               [24]10219 	movx	@dptr,a
      003208 A3               [24]10220 	inc	dptr
      003209 F0               [24]10221 	movx	@dptr,a
                                  10222 ;	..\COMMON\easyax5043.c:2057: wtimer0_addrelative(&axradio_timer);
      00320A 90 02 9D         [24]10223 	mov	dptr,#_axradio_timer
      00320D 12 42 DE         [24]10224 	lcall	_wtimer0_addrelative
                                  10225 ;	..\COMMON\easyax5043.c:2058: axradio_sync_time = axradio_timer.time;
      003210 90 02 A1         [24]10226 	mov	dptr,#(_axradio_timer + 0x0004)
      003213 E0               [24]10227 	movx	a,@dptr
      003214 FB               [12]10228 	mov	r3,a
      003215 A3               [24]10229 	inc	dptr
      003216 E0               [24]10230 	movx	a,@dptr
      003217 FC               [12]10231 	mov	r4,a
      003218 A3               [24]10232 	inc	dptr
      003219 E0               [24]10233 	movx	a,@dptr
      00321A FD               [12]10234 	mov	r5,a
      00321B A3               [24]10235 	inc	dptr
      00321C E0               [24]10236 	movx	a,@dptr
      00321D FE               [12]10237 	mov	r6,a
      00321E 90 00 1F         [24]10238 	mov	dptr,#_axradio_sync_time
      003221 EB               [12]10239 	mov	a,r3
      003222 F0               [24]10240 	movx	@dptr,a
      003223 EC               [12]10241 	mov	a,r4
      003224 A3               [24]10242 	inc	dptr
      003225 F0               [24]10243 	movx	@dptr,a
      003226 ED               [12]10244 	mov	a,r5
      003227 A3               [24]10245 	inc	dptr
      003228 F0               [24]10246 	movx	@dptr,a
      003229 EE               [12]10247 	mov	a,r6
      00322A A3               [24]10248 	inc	dptr
      00322B F0               [24]10249 	movx	@dptr,a
                                  10250 ;	..\COMMON\easyax5043.c:2059: axradio_sync_addtime(axradio_sync_xoscstartup);
      00322C 90 4C D5         [24]10251 	mov	dptr,#_axradio_sync_xoscstartup
      00322F E4               [12]10252 	clr	a
      003230 93               [24]10253 	movc	a,@a+dptr
      003231 FB               [12]10254 	mov	r3,a
      003232 74 01            [12]10255 	mov	a,#0x01
      003234 93               [24]10256 	movc	a,@a+dptr
      003235 FC               [12]10257 	mov	r4,a
      003236 74 02            [12]10258 	mov	a,#0x02
      003238 93               [24]10259 	movc	a,@a+dptr
      003239 FD               [12]10260 	mov	r5,a
      00323A 74 03            [12]10261 	mov	a,#0x03
      00323C 93               [24]10262 	movc	a,@a+dptr
      00323D 8B 82            [24]10263 	mov	dpl,r3
      00323F 8C 83            [24]10264 	mov	dph,r4
      003241 8D F0            [24]10265 	mov	b,r5
      003243 12 19 42         [24]10266 	lcall	_axradio_sync_addtime
                                  10267 ;	..\COMMON\easyax5043.c:2060: return AXRADIO_ERR_NOERROR;
      003246 75 82 00         [24]10268 	mov	dpl,#0x00
      003249 22               [24]10269 	ret
                                  10270 ;	..\COMMON\easyax5043.c:2062: case AXRADIO_MODE_SYNC_SLAVE:
      00324A                      10271 00251$:
                                  10272 ;	..\COMMON\easyax5043.c:2063: case AXRADIO_MODE_SYNC_ACK_SLAVE:
      00324A                      10273 00252$:
                                  10274 ;	..\COMMON\easyax5043.c:2064: axradio_mode = mode;
      00324A 8F 08            [24]10275 	mov	_axradio_mode,r7
                                  10276 ;	..\COMMON\easyax5043.c:2065: ax5043_init_registers_rx();
      00324C 12 0B 65         [24]10277 	lcall	_ax5043_init_registers_rx
                                  10278 ;	..\COMMON\easyax5043.c:2066: ax5043_receiver_on_continuous();
      00324F 12 16 3B         [24]10279 	lcall	_ax5043_receiver_on_continuous
                                  10280 ;	..\COMMON\easyax5043.c:2067: axradio_syncstate = syncstate_slave_synchunt;
      003252 90 00 13         [24]10281 	mov	dptr,#_axradio_syncstate
      003255 74 06            [12]10282 	mov	a,#0x06
      003257 F0               [24]10283 	movx	@dptr,a
                                  10284 ;	..\COMMON\easyax5043.c:2068: wtimer_remove(&axradio_timer);
      003258 90 02 9D         [24]10285 	mov	dptr,#_axradio_timer
      00325B 12 47 8D         [24]10286 	lcall	_wtimer_remove
                                  10287 ;	..\COMMON\easyax5043.c:2069: axradio_timer.time = axradio_sync_slave_initialsyncwindow;
      00325E 90 4C DD         [24]10288 	mov	dptr,#_axradio_sync_slave_initialsyncwindow
      003261 E4               [12]10289 	clr	a
      003262 93               [24]10290 	movc	a,@a+dptr
      003263 FC               [12]10291 	mov	r4,a
      003264 74 01            [12]10292 	mov	a,#0x01
      003266 93               [24]10293 	movc	a,@a+dptr
      003267 FD               [12]10294 	mov	r5,a
      003268 74 02            [12]10295 	mov	a,#0x02
      00326A 93               [24]10296 	movc	a,@a+dptr
      00326B FE               [12]10297 	mov	r6,a
      00326C 74 03            [12]10298 	mov	a,#0x03
      00326E 93               [24]10299 	movc	a,@a+dptr
      00326F FF               [12]10300 	mov	r7,a
      003270 90 02 A1         [24]10301 	mov	dptr,#(_axradio_timer + 0x0004)
      003273 EC               [12]10302 	mov	a,r4
      003274 F0               [24]10303 	movx	@dptr,a
      003275 ED               [12]10304 	mov	a,r5
      003276 A3               [24]10305 	inc	dptr
      003277 F0               [24]10306 	movx	@dptr,a
      003278 EE               [12]10307 	mov	a,r6
      003279 A3               [24]10308 	inc	dptr
      00327A F0               [24]10309 	movx	@dptr,a
      00327B EF               [12]10310 	mov	a,r7
      00327C A3               [24]10311 	inc	dptr
      00327D F0               [24]10312 	movx	@dptr,a
                                  10313 ;	..\COMMON\easyax5043.c:2070: wtimer0_addrelative(&axradio_timer);
      00327E 90 02 9D         [24]10314 	mov	dptr,#_axradio_timer
      003281 12 42 DE         [24]10315 	lcall	_wtimer0_addrelative
                                  10316 ;	..\COMMON\easyax5043.c:2071: axradio_sync_time = axradio_timer.time;
      003284 90 02 A1         [24]10317 	mov	dptr,#(_axradio_timer + 0x0004)
      003287 E0               [24]10318 	movx	a,@dptr
      003288 FC               [12]10319 	mov	r4,a
      003289 A3               [24]10320 	inc	dptr
      00328A E0               [24]10321 	movx	a,@dptr
      00328B FD               [12]10322 	mov	r5,a
      00328C A3               [24]10323 	inc	dptr
      00328D E0               [24]10324 	movx	a,@dptr
      00328E FE               [12]10325 	mov	r6,a
      00328F A3               [24]10326 	inc	dptr
      003290 E0               [24]10327 	movx	a,@dptr
      003291 FF               [12]10328 	mov	r7,a
      003292 90 00 1F         [24]10329 	mov	dptr,#_axradio_sync_time
      003295 EC               [12]10330 	mov	a,r4
      003296 F0               [24]10331 	movx	@dptr,a
      003297 ED               [12]10332 	mov	a,r5
      003298 A3               [24]10333 	inc	dptr
      003299 F0               [24]10334 	movx	@dptr,a
      00329A EE               [12]10335 	mov	a,r6
      00329B A3               [24]10336 	inc	dptr
      00329C F0               [24]10337 	movx	@dptr,a
      00329D EF               [12]10338 	mov	a,r7
      00329E A3               [24]10339 	inc	dptr
      00329F F0               [24]10340 	movx	@dptr,a
                                  10341 ;	..\COMMON\easyax5043.c:2072: wtimer_remove_callback(&axradio_cb_receive.cb);
      0032A0 90 02 44         [24]10342 	mov	dptr,#_axradio_cb_receive
      0032A3 12 48 82         [24]10343 	lcall	_wtimer_remove_callback
                                  10344 ;	..\COMMON\easyax5043.c:2073: memset_xdata(&axradio_cb_receive.st, 0, sizeof(axradio_cb_receive.st));
      0032A6 75 2E 00         [24]10345 	mov	_memset_PARM_2,#0x00
      0032A9 75 2F 20         [24]10346 	mov	_memset_PARM_3,#0x20
      0032AC 75 30 00         [24]10347 	mov	(_memset_PARM_3 + 1),#0x00
      0032AF 90 02 48         [24]10348 	mov	dptr,#(_axradio_cb_receive + 0x0004)
      0032B2 75 F0 00         [24]10349 	mov	b,#0x00
      0032B5 12 42 50         [24]10350 	lcall	_memset
                                  10351 ;	..\COMMON\easyax5043.c:2074: axradio_cb_receive.st.time.t = axradio_timeanchor.radiotimer;
      0032B8 90 00 29         [24]10352 	mov	dptr,#(_axradio_timeanchor + 0x0004)
      0032BB E0               [24]10353 	movx	a,@dptr
      0032BC FC               [12]10354 	mov	r4,a
      0032BD A3               [24]10355 	inc	dptr
      0032BE E0               [24]10356 	movx	a,@dptr
      0032BF FD               [12]10357 	mov	r5,a
      0032C0 A3               [24]10358 	inc	dptr
      0032C1 E0               [24]10359 	movx	a,@dptr
      0032C2 FE               [12]10360 	mov	r6,a
      0032C3 A3               [24]10361 	inc	dptr
      0032C4 E0               [24]10362 	movx	a,@dptr
      0032C5 FF               [12]10363 	mov	r7,a
      0032C6 90 02 4A         [24]10364 	mov	dptr,#(_axradio_cb_receive + 0x0006)
      0032C9 EC               [12]10365 	mov	a,r4
      0032CA F0               [24]10366 	movx	@dptr,a
      0032CB ED               [12]10367 	mov	a,r5
      0032CC A3               [24]10368 	inc	dptr
      0032CD F0               [24]10369 	movx	@dptr,a
      0032CE EE               [12]10370 	mov	a,r6
      0032CF A3               [24]10371 	inc	dptr
      0032D0 F0               [24]10372 	movx	@dptr,a
      0032D1 EF               [12]10373 	mov	a,r7
      0032D2 A3               [24]10374 	inc	dptr
      0032D3 F0               [24]10375 	movx	@dptr,a
                                  10376 ;	..\COMMON\easyax5043.c:2075: axradio_cb_receive.st.error = AXRADIO_ERR_RESYNC;
      0032D4 90 02 49         [24]10377 	mov	dptr,#(_axradio_cb_receive + 0x0005)
      0032D7 74 09            [12]10378 	mov	a,#0x09
      0032D9 F0               [24]10379 	movx	@dptr,a
                                  10380 ;	..\COMMON\easyax5043.c:2076: wtimer_add_callback(&axradio_cb_receive.cb);
      0032DA 90 02 44         [24]10381 	mov	dptr,#_axradio_cb_receive
      0032DD 12 42 C4         [24]10382 	lcall	_wtimer_add_callback
                                  10383 ;	..\COMMON\easyax5043.c:2077: return AXRADIO_ERR_NOERROR;
      0032E0 75 82 00         [24]10384 	mov	dpl,#0x00
                                  10385 ;	..\COMMON\easyax5043.c:2079: default:
      0032E3 22               [24]10386 	ret
      0032E4                      10387 00253$:
                                  10388 ;	..\COMMON\easyax5043.c:2080: return AXRADIO_ERR_NOTSUPPORTED;
      0032E4 75 82 01         [24]10389 	mov	dpl,#0x01
                                  10390 ;	..\COMMON\easyax5043.c:2081: }
      0032E7 22               [24]10391 	ret
                                  10392 ;------------------------------------------------------------
                                  10393 ;Allocation info for local variables in function 'axradio_get_mode'
                                  10394 ;------------------------------------------------------------
                                  10395 ;	..\COMMON\easyax5043.c:2084: uint8_t axradio_get_mode(void)
                                  10396 ;	-----------------------------------------
                                  10397 ;	 function axradio_get_mode
                                  10398 ;	-----------------------------------------
      0032E8                      10399 _axradio_get_mode:
                                  10400 ;	..\COMMON\easyax5043.c:2086: return axradio_mode;
      0032E8 85 08 82         [24]10401 	mov	dpl,_axradio_mode
      0032EB 22               [24]10402 	ret
                                  10403 ;------------------------------------------------------------
                                  10404 ;Allocation info for local variables in function 'axradio_set_channel'
                                  10405 ;------------------------------------------------------------
                                  10406 ;chnum                     Allocated to registers r7 
                                  10407 ;rng                       Allocated with name '_axradio_set_channel_rng_1_766'
                                  10408 ;f                         Allocated to registers r3 r4 r6 r7 
                                  10409 ;------------------------------------------------------------
                                  10410 ;	..\COMMON\easyax5043.c:2089: uint8_t axradio_set_channel(uint8_t chnum)
                                  10411 ;	-----------------------------------------
                                  10412 ;	 function axradio_set_channel
                                  10413 ;	-----------------------------------------
      0032EC                      10414 _axradio_set_channel:
      0032EC AF 82            [24]10415 	mov	r7,dpl
                                  10416 ;	..\COMMON\easyax5043.c:2092: if (chnum >= axradio_phy_nrchannels)
      0032EE 90 4C 71         [24]10417 	mov	dptr,#_axradio_phy_nrchannels
      0032F1 E4               [12]10418 	clr	a
      0032F2 93               [24]10419 	movc	a,@a+dptr
      0032F3 FE               [12]10420 	mov	r6,a
      0032F4 C3               [12]10421 	clr	c
      0032F5 EF               [12]10422 	mov	a,r7
      0032F6 9E               [12]10423 	subb	a,r6
      0032F7 40 04            [24]10424 	jc	00102$
                                  10425 ;	..\COMMON\easyax5043.c:2093: return AXRADIO_ERR_INVALID;
      0032F9 75 82 04         [24]10426 	mov	dpl,#0x04
      0032FC 22               [24]10427 	ret
      0032FD                      10428 00102$:
                                  10429 ;	..\COMMON\easyax5043.c:2094: axradio_curchannel = chnum;
      0032FD 90 00 18         [24]10430 	mov	dptr,#_axradio_curchannel
      003300 EF               [12]10431 	mov	a,r7
      003301 F0               [24]10432 	movx	@dptr,a
                                  10433 ;	..\COMMON\easyax5043.c:2095: rng = axradio_phy_chanpllrng[chnum];
      003302 EF               [12]10434 	mov	a,r7
      003303 75 F0 02         [24]10435 	mov	b,#0x02
      003306 A4               [48]10436 	mul	ab
      003307 24 01            [12]10437 	add	a,#_axradio_phy_chanpllrng
      003309 F5 82            [12]10438 	mov	dpl,a
      00330B 74 00            [12]10439 	mov	a,#(_axradio_phy_chanpllrng >> 8)
      00330D 35 F0            [12]10440 	addc	a,b
      00330F F5 83            [12]10441 	mov	dph,a
      003311 E0               [24]10442 	movx	a,@dptr
      003312 FD               [12]10443 	mov	r5,a
      003313 A3               [24]10444 	inc	dptr
      003314 E0               [24]10445 	movx	a,@dptr
      003315 FE               [12]10446 	mov	r6,a
                                  10447 ;	..\COMMON\easyax5043.c:2096: if (rng & 0x20)
      003316 ED               [12]10448 	mov	a,r5
      003317 F5 2E            [12]10449 	mov	_axradio_set_channel_rng_1_766,a
      003319 30 E5 04         [24]10450 	jnb	acc.5,00104$
                                  10451 ;	..\COMMON\easyax5043.c:2097: return AXRADIO_ERR_RANGING;
      00331C 75 82 06         [24]10452 	mov	dpl,#0x06
      00331F 22               [24]10453 	ret
      003320                      10454 00104$:
                                  10455 ;	..\COMMON\easyax5043.c:2099: uint32_t __autodata f = axradio_phy_chanfreq[chnum];
      003320 EF               [12]10456 	mov	a,r7
      003321 75 F0 04         [24]10457 	mov	b,#0x04
      003324 A4               [48]10458 	mul	ab
      003325 24 72            [12]10459 	add	a,#_axradio_phy_chanfreq
      003327 F5 82            [12]10460 	mov	dpl,a
      003329 74 4C            [12]10461 	mov	a,#(_axradio_phy_chanfreq >> 8)
      00332B 35 F0            [12]10462 	addc	a,b
      00332D F5 83            [12]10463 	mov	dph,a
      00332F E4               [12]10464 	clr	a
      003330 93               [24]10465 	movc	a,@a+dptr
      003331 FB               [12]10466 	mov	r3,a
      003332 A3               [24]10467 	inc	dptr
      003333 E4               [12]10468 	clr	a
      003334 93               [24]10469 	movc	a,@a+dptr
      003335 FC               [12]10470 	mov	r4,a
      003336 A3               [24]10471 	inc	dptr
      003337 E4               [12]10472 	clr	a
      003338 93               [24]10473 	movc	a,@a+dptr
      003339 FE               [12]10474 	mov	r6,a
      00333A A3               [24]10475 	inc	dptr
      00333B E4               [12]10476 	clr	a
      00333C 93               [24]10477 	movc	a,@a+dptr
      00333D FF               [12]10478 	mov	r7,a
                                  10479 ;	..\COMMON\easyax5043.c:2100: f += axradio_curfreqoffset;
      00333E 90 00 19         [24]10480 	mov	dptr,#_axradio_curfreqoffset
      003341 E0               [24]10481 	movx	a,@dptr
      003342 F8               [12]10482 	mov	r0,a
      003343 A3               [24]10483 	inc	dptr
      003344 E0               [24]10484 	movx	a,@dptr
      003345 F9               [12]10485 	mov	r1,a
      003346 A3               [24]10486 	inc	dptr
      003347 E0               [24]10487 	movx	a,@dptr
      003348 FA               [12]10488 	mov	r2,a
      003349 A3               [24]10489 	inc	dptr
      00334A E0               [24]10490 	movx	a,@dptr
      00334B FD               [12]10491 	mov	r5,a
      00334C E8               [12]10492 	mov	a,r0
      00334D 2B               [12]10493 	add	a,r3
      00334E FB               [12]10494 	mov	r3,a
      00334F E9               [12]10495 	mov	a,r1
      003350 3C               [12]10496 	addc	a,r4
      003351 FC               [12]10497 	mov	r4,a
      003352 EA               [12]10498 	mov	a,r2
      003353 3E               [12]10499 	addc	a,r6
      003354 FE               [12]10500 	mov	r6,a
      003355 ED               [12]10501 	mov	a,r5
      003356 3F               [12]10502 	addc	a,r7
      003357 FF               [12]10503 	mov	r7,a
                                  10504 ;	..\COMMON\easyax5043.c:2101: if (radio_read8(AX5043_REG_PLLLOOP) & 0x80) {
      003358 90 40 30         [24]10505 	mov	dptr,#0x4030
      00335B E0               [24]10506 	movx	a,@dptr
      00335C FD               [12]10507 	mov	r5,a
      00335D 30 E7 26         [24]10508 	jnb	acc.7,00120$
                                  10509 ;	..\COMMON\easyax5043.c:2102: radio_write8(AX5043_REG_PLLRANGINGA, (rng & 0x0F));
      003360 74 0F            [12]10510 	mov	a,#0x0f
      003362 55 2E            [12]10511 	anl	a,_axradio_set_channel_rng_1_766
      003364 90 40 33         [24]10512 	mov	dptr,#0x4033
      003367 F0               [24]10513 	movx	@dptr,a
                                  10514 ;	..\COMMON\easyax5043.c:2103: radio_write8(AX5043_REG_FREQA0, f);
      003368 8B 05            [24]10515 	mov	ar5,r3
      00336A 90 40 37         [24]10516 	mov	dptr,#0x4037
      00336D ED               [12]10517 	mov	a,r5
      00336E F0               [24]10518 	movx	@dptr,a
                                  10519 ;	..\COMMON\easyax5043.c:2104: radio_write8(AX5043_REG_FREQA1, f >> 8);
      00336F 8C 05            [24]10520 	mov	ar5,r4
      003371 90 40 36         [24]10521 	mov	dptr,#0x4036
      003374 ED               [12]10522 	mov	a,r5
      003375 F0               [24]10523 	movx	@dptr,a
                                  10524 ;	..\COMMON\easyax5043.c:2105: radio_write8(AX5043_REG_FREQA2, f >> 16);
      003376 8E 05            [24]10525 	mov	ar5,r6
      003378 90 40 35         [24]10526 	mov	dptr,#0x4035
      00337B ED               [12]10527 	mov	a,r5
      00337C F0               [24]10528 	movx	@dptr,a
                                  10529 ;	..\COMMON\easyax5043.c:2106: radio_write8(AX5043_REG_FREQA3, f >> 24);
      00337D 8F 05            [24]10530 	mov	ar5,r7
      00337F 90 40 34         [24]10531 	mov	dptr,#0x4034
      003382 ED               [12]10532 	mov	a,r5
      003383 F0               [24]10533 	movx	@dptr,a
                                  10534 ;	..\COMMON\easyax5043.c:2108: radio_write8(AX5043_REG_PLLRANGINGB, rng & 0x0F);
      003384 80 24            [24]10535 	sjmp	00138$
      003386                      10536 00120$:
      003386 74 0F            [12]10537 	mov	a,#0x0f
      003388 55 2E            [12]10538 	anl	a,_axradio_set_channel_rng_1_766
      00338A 90 40 3B         [24]10539 	mov	dptr,#0x403b
      00338D F0               [24]10540 	movx	@dptr,a
                                  10541 ;	..\COMMON\easyax5043.c:2109: radio_write8(AX5043_REG_FREQB0, f);
      00338E 8B 05            [24]10542 	mov	ar5,r3
      003390 90 40 3F         [24]10543 	mov	dptr,#0x403f
      003393 ED               [12]10544 	mov	a,r5
      003394 F0               [24]10545 	movx	@dptr,a
                                  10546 ;	..\COMMON\easyax5043.c:2110: radio_write8(AX5043_REG_FREQB1, f >> 8);
      003395 8C 05            [24]10547 	mov	ar5,r4
      003397 90 40 3E         [24]10548 	mov	dptr,#0x403e
      00339A ED               [12]10549 	mov	a,r5
      00339B F0               [24]10550 	movx	@dptr,a
                                  10551 ;	..\COMMON\easyax5043.c:2111: radio_write8(AX5043_REG_FREQB2, f >> 16);
      00339C 8E 05            [24]10552 	mov	ar5,r6
      00339E 90 40 3D         [24]10553 	mov	dptr,#0x403d
      0033A1 ED               [12]10554 	mov	a,r5
      0033A2 F0               [24]10555 	movx	@dptr,a
                                  10556 ;	..\COMMON\easyax5043.c:2112: radio_write8(AX5043_REG_FREQB3, f >> 24);
      0033A3 8F 03            [24]10557 	mov	ar3,r7
      0033A5 90 40 3C         [24]10558 	mov	dptr,#0x403c
      0033A8 EB               [12]10559 	mov	a,r3
      0033A9 F0               [24]10560 	movx	@dptr,a
                                  10561 ;	..\COMMON\easyax5043.c:2115: radio_write8(AX5043_REG_PLLLOOP, radio_read8(AX5043_REG_PLLLOOP) ^ 0x80);
      0033AA                      10562 00138$:
      0033AA 90 40 30         [24]10563 	mov	dptr,#0x4030
      0033AD E0               [24]10564 	movx	a,@dptr
      0033AE 64 80            [12]10565 	xrl	a,#0x80
      0033B0 F0               [24]10566 	movx	@dptr,a
                                  10567 ;	..\COMMON\easyax5043.c:2116: return AXRADIO_ERR_NOERROR;
      0033B1 75 82 00         [24]10568 	mov	dpl,#0x00
      0033B4 22               [24]10569 	ret
                                  10570 ;------------------------------------------------------------
                                  10571 ;Allocation info for local variables in function 'axradio_get_channel'
                                  10572 ;------------------------------------------------------------
                                  10573 ;	..\COMMON\easyax5043.c:2119: uint8_t axradio_get_channel(void)
                                  10574 ;	-----------------------------------------
                                  10575 ;	 function axradio_get_channel
                                  10576 ;	-----------------------------------------
      0033B5                      10577 _axradio_get_channel:
                                  10578 ;	..\COMMON\easyax5043.c:2121: return axradio_curchannel;
      0033B5 90 00 18         [24]10579 	mov	dptr,#_axradio_curchannel
      0033B8 E0               [24]10580 	movx	a,@dptr
      0033B9 F5 82            [12]10581 	mov	dpl,a
      0033BB 22               [24]10582 	ret
                                  10583 ;------------------------------------------------------------
                                  10584 ;Allocation info for local variables in function 'axradio_get_pllrange'
                                  10585 ;------------------------------------------------------------
                                  10586 ;	..\COMMON\easyax5043.c:2124: uint16_t axradio_get_pllrange(void)
                                  10587 ;	-----------------------------------------
                                  10588 ;	 function axradio_get_pllrange
                                  10589 ;	-----------------------------------------
      0033BC                      10590 _axradio_get_pllrange:
                                  10591 ;	..\COMMON\easyax5043.c:2126: return axradio_phy_chanpllrng[axradio_curchannel] & 0x000F;
      0033BC 90 00 18         [24]10592 	mov	dptr,#_axradio_curchannel
      0033BF E0               [24]10593 	movx	a,@dptr
      0033C0 75 F0 02         [24]10594 	mov	b,#0x02
      0033C3 A4               [48]10595 	mul	ab
      0033C4 24 01            [12]10596 	add	a,#_axradio_phy_chanpllrng
      0033C6 F5 82            [12]10597 	mov	dpl,a
      0033C8 74 00            [12]10598 	mov	a,#(_axradio_phy_chanpllrng >> 8)
      0033CA 35 F0            [12]10599 	addc	a,b
      0033CC F5 83            [12]10600 	mov	dph,a
      0033CE E0               [24]10601 	movx	a,@dptr
      0033CF FE               [12]10602 	mov	r6,a
      0033D0 A3               [24]10603 	inc	dptr
      0033D1 E0               [24]10604 	movx	a,@dptr
      0033D2 74 0F            [12]10605 	mov	a,#0x0f
      0033D4 5E               [12]10606 	anl	a,r6
      0033D5 F5 82            [12]10607 	mov	dpl,a
      0033D7 75 83 00         [24]10608 	mov	dph,#0x00
      0033DA 22               [24]10609 	ret
                                  10610 ;------------------------------------------------------------
                                  10611 ;Allocation info for local variables in function 'axradio_get_pllvcoi'
                                  10612 ;------------------------------------------------------------
                                  10613 ;x                         Allocated to registers r7 
                                  10614 ;x                         Allocated to registers r6 
                                  10615 ;------------------------------------------------------------
                                  10616 ;	..\COMMON\easyax5043.c:2129: uint8_t axradio_get_pllvcoi(void)
                                  10617 ;	-----------------------------------------
                                  10618 ;	 function axradio_get_pllvcoi
                                  10619 ;	-----------------------------------------
      0033DB                      10620 _axradio_get_pllvcoi:
                                  10621 ;	..\COMMON\easyax5043.c:2131: if (axradio_phy_vcocalib) {
      0033DB 90 4C 9C         [24]10622 	mov	dptr,#_axradio_phy_vcocalib
      0033DE E4               [12]10623 	clr	a
      0033DF 93               [24]10624 	movc	a,@a+dptr
      0033E0 60 15            [24]10625 	jz	00104$
                                  10626 ;	..\COMMON\easyax5043.c:2132: uint8_t x = axradio_phy_chanvcoi[axradio_curchannel];
      0033E2 90 00 18         [24]10627 	mov	dptr,#_axradio_curchannel
      0033E5 E0               [24]10628 	movx	a,@dptr
      0033E6 24 0D            [12]10629 	add	a,#_axradio_phy_chanvcoi
      0033E8 F5 82            [12]10630 	mov	dpl,a
      0033EA E4               [12]10631 	clr	a
      0033EB 34 00            [12]10632 	addc	a,#(_axradio_phy_chanvcoi >> 8)
      0033ED F5 83            [12]10633 	mov	dph,a
      0033EF E0               [24]10634 	movx	a,@dptr
                                  10635 ;	..\COMMON\easyax5043.c:2133: if (x & 0x80)
      0033F0 FF               [12]10636 	mov	r7,a
      0033F1 30 E7 03         [24]10637 	jnb	acc.7,00104$
                                  10638 ;	..\COMMON\easyax5043.c:2134: return x;
      0033F4 8F 82            [24]10639 	mov	dpl,r7
      0033F6 22               [24]10640 	ret
      0033F7                      10641 00104$:
                                  10642 ;	..\COMMON\easyax5043.c:2137: uint8_t x = axradio_phy_chanvcoiinit[axradio_curchannel];
      0033F7 90 00 18         [24]10643 	mov	dptr,#_axradio_curchannel
      0033FA E0               [24]10644 	movx	a,@dptr
      0033FB FF               [12]10645 	mov	r7,a
      0033FC 90 4C 96         [24]10646 	mov	dptr,#_axradio_phy_chanvcoiinit
      0033FF 93               [24]10647 	movc	a,@a+dptr
                                  10648 ;	..\COMMON\easyax5043.c:2138: if (x & 0x80) {
      003400 FE               [12]10649 	mov	r6,a
      003401 30 E7 4C         [24]10650 	jnb	acc.7,00108$
                                  10651 ;	..\COMMON\easyax5043.c:2139: if (!(axradio_phy_chanpllrnginit[0] & 0xF0)) {
      003404 90 4C 8A         [24]10652 	mov	dptr,#_axradio_phy_chanpllrnginit
      003407 E4               [12]10653 	clr	a
      003408 93               [24]10654 	movc	a,@a+dptr
      003409 FC               [12]10655 	mov	r4,a
      00340A A3               [24]10656 	inc	dptr
      00340B E4               [12]10657 	clr	a
      00340C 93               [24]10658 	movc	a,@a+dptr
      00340D FD               [12]10659 	mov	r5,a
      00340E EC               [12]10660 	mov	a,r4
      00340F 54 F0            [12]10661 	anl	a,#0xf0
      003411 70 3A            [24]10662 	jnz	00106$
                                  10663 ;	..\COMMON\easyax5043.c:2140: x += (axradio_phy_chanpllrng[axradio_curchannel] & 0x0F) - (axradio_phy_chanpllrnginit[axradio_curchannel] & 0x0F);
      003413 EF               [12]10664 	mov	a,r7
      003414 75 F0 02         [24]10665 	mov	b,#0x02
      003417 A4               [48]10666 	mul	ab
      003418 FF               [12]10667 	mov	r7,a
      003419 AD F0            [24]10668 	mov	r5,b
      00341B 24 01            [12]10669 	add	a,#_axradio_phy_chanpllrng
      00341D F5 82            [12]10670 	mov	dpl,a
      00341F ED               [12]10671 	mov	a,r5
      003420 34 00            [12]10672 	addc	a,#(_axradio_phy_chanpllrng >> 8)
      003422 F5 83            [12]10673 	mov	dph,a
      003424 E0               [24]10674 	movx	a,@dptr
      003425 FB               [12]10675 	mov	r3,a
      003426 A3               [24]10676 	inc	dptr
      003427 E0               [24]10677 	movx	a,@dptr
      003428 53 03 0F         [24]10678 	anl	ar3,#0x0f
      00342B 7C 00            [12]10679 	mov	r4,#0x00
      00342D EF               [12]10680 	mov	a,r7
      00342E 24 8A            [12]10681 	add	a,#_axradio_phy_chanpllrnginit
      003430 F5 82            [12]10682 	mov	dpl,a
      003432 ED               [12]10683 	mov	a,r5
      003433 34 4C            [12]10684 	addc	a,#(_axradio_phy_chanpllrnginit >> 8)
      003435 F5 83            [12]10685 	mov	dph,a
      003437 E4               [12]10686 	clr	a
      003438 93               [24]10687 	movc	a,@a+dptr
      003439 FD               [12]10688 	mov	r5,a
      00343A A3               [24]10689 	inc	dptr
      00343B E4               [12]10690 	clr	a
      00343C 93               [24]10691 	movc	a,@a+dptr
      00343D 53 05 0F         [24]10692 	anl	ar5,#0x0f
      003440 7F 00            [12]10693 	mov	r7,#0x00
      003442 EB               [12]10694 	mov	a,r3
      003443 C3               [12]10695 	clr	c
      003444 9D               [12]10696 	subb	a,r5
      003445 2E               [12]10697 	add	a,r6
      003446 FE               [12]10698 	mov	r6,a
                                  10699 ;	..\COMMON\easyax5043.c:2141: x &= 0x3f;
      003447 53 06 3F         [24]10700 	anl	ar6,#0x3f
                                  10701 ;	..\COMMON\easyax5043.c:2142: x |= 0x80;
      00344A 43 06 80         [24]10702 	orl	ar6,#0x80
      00344D                      10703 00106$:
                                  10704 ;	..\COMMON\easyax5043.c:2144: return x;
      00344D 8E 82            [24]10705 	mov	dpl,r6
      00344F 22               [24]10706 	ret
      003450                      10707 00108$:
                                  10708 ;	..\COMMON\easyax5043.c:2147: return radio_read8(AX5043_REG_PLLVCOI);
      003450 90 41 80         [24]10709 	mov	dptr,#0x4180
      003453 E0               [24]10710 	movx	a,@dptr
      003454 F5 82            [12]10711 	mov	dpl,a
      003456 22               [24]10712 	ret
                                  10713 ;------------------------------------------------------------
                                  10714 ;Allocation info for local variables in function 'axradio_set_curfreqoffset'
                                  10715 ;------------------------------------------------------------
                                  10716 ;offs                      Allocated to registers r4 r5 r6 r7 
                                  10717 ;------------------------------------------------------------
                                  10718 ;	..\COMMON\easyax5043.c:2150: static uint8_t axradio_set_curfreqoffset(int32_t offs)
                                  10719 ;	-----------------------------------------
                                  10720 ;	 function axradio_set_curfreqoffset
                                  10721 ;	-----------------------------------------
      003457                      10722 _axradio_set_curfreqoffset:
      003457 AC 82            [24]10723 	mov	r4,dpl
      003459 AD 83            [24]10724 	mov	r5,dph
      00345B AE F0            [24]10725 	mov	r6,b
      00345D FF               [12]10726 	mov	r7,a
                                  10727 ;	..\COMMON\easyax5043.c:2152: axradio_curfreqoffset = offs;
      00345E 90 00 19         [24]10728 	mov	dptr,#_axradio_curfreqoffset
      003461 EC               [12]10729 	mov	a,r4
      003462 F0               [24]10730 	movx	@dptr,a
      003463 ED               [12]10731 	mov	a,r5
      003464 A3               [24]10732 	inc	dptr
      003465 F0               [24]10733 	movx	@dptr,a
      003466 EE               [12]10734 	mov	a,r6
      003467 A3               [24]10735 	inc	dptr
      003468 F0               [24]10736 	movx	@dptr,a
      003469 EF               [12]10737 	mov	a,r7
      00346A A3               [24]10738 	inc	dptr
      00346B F0               [24]10739 	movx	@dptr,a
                                  10740 ;	..\COMMON\easyax5043.c:2153: if (checksignedlimit32(offs, axradio_phy_maxfreqoffset))
      00346C 90 4C 9D         [24]10741 	mov	dptr,#_axradio_phy_maxfreqoffset
      00346F E4               [12]10742 	clr	a
      003470 93               [24]10743 	movc	a,@a+dptr
      003471 C0 E0            [24]10744 	push	acc
      003473 74 01            [12]10745 	mov	a,#0x01
      003475 93               [24]10746 	movc	a,@a+dptr
      003476 C0 E0            [24]10747 	push	acc
      003478 74 02            [12]10748 	mov	a,#0x02
      00347A 93               [24]10749 	movc	a,@a+dptr
      00347B C0 E0            [24]10750 	push	acc
      00347D 74 03            [12]10751 	mov	a,#0x03
      00347F 93               [24]10752 	movc	a,@a+dptr
      003480 C0 E0            [24]10753 	push	acc
      003482 8C 82            [24]10754 	mov	dpl,r4
      003484 8D 83            [24]10755 	mov	dph,r5
      003486 8E F0            [24]10756 	mov	b,r6
      003488 EF               [12]10757 	mov	a,r7
      003489 12 46 7A         [24]10758 	lcall	_checksignedlimit32
      00348C AF 82            [24]10759 	mov	r7,dpl
      00348E E5 81            [12]10760 	mov	a,sp
      003490 24 FC            [12]10761 	add	a,#0xfc
      003492 F5 81            [12]10762 	mov	sp,a
      003494 EF               [12]10763 	mov	a,r7
      003495 60 04            [24]10764 	jz	00102$
                                  10765 ;	..\COMMON\easyax5043.c:2154: return AXRADIO_ERR_NOERROR;
      003497 75 82 00         [24]10766 	mov	dpl,#0x00
      00349A 22               [24]10767 	ret
      00349B                      10768 00102$:
                                  10769 ;	..\COMMON\easyax5043.c:2155: if (axradio_curfreqoffset < 0)
      00349B 90 00 19         [24]10770 	mov	dptr,#_axradio_curfreqoffset
      00349E E0               [24]10771 	movx	a,@dptr
      00349F FC               [12]10772 	mov	r4,a
      0034A0 A3               [24]10773 	inc	dptr
      0034A1 E0               [24]10774 	movx	a,@dptr
      0034A2 FD               [12]10775 	mov	r5,a
      0034A3 A3               [24]10776 	inc	dptr
      0034A4 E0               [24]10777 	movx	a,@dptr
      0034A5 FE               [12]10778 	mov	r6,a
      0034A6 A3               [24]10779 	inc	dptr
      0034A7 E0               [24]10780 	movx	a,@dptr
      0034A8 FF               [12]10781 	mov	r7,a
      0034A9 30 E7 27         [24]10782 	jnb	acc.7,00104$
                                  10783 ;	..\COMMON\easyax5043.c:2156: axradio_curfreqoffset = -axradio_phy_maxfreqoffset;
      0034AC 90 4C 9D         [24]10784 	mov	dptr,#_axradio_phy_maxfreqoffset
      0034AF E4               [12]10785 	clr	a
      0034B0 93               [24]10786 	movc	a,@a+dptr
      0034B1 FC               [12]10787 	mov	r4,a
      0034B2 74 01            [12]10788 	mov	a,#0x01
      0034B4 93               [24]10789 	movc	a,@a+dptr
      0034B5 FD               [12]10790 	mov	r5,a
      0034B6 74 02            [12]10791 	mov	a,#0x02
      0034B8 93               [24]10792 	movc	a,@a+dptr
      0034B9 FE               [12]10793 	mov	r6,a
      0034BA 74 03            [12]10794 	mov	a,#0x03
      0034BC 93               [24]10795 	movc	a,@a+dptr
      0034BD FF               [12]10796 	mov	r7,a
      0034BE 90 00 19         [24]10797 	mov	dptr,#_axradio_curfreqoffset
      0034C1 C3               [12]10798 	clr	c
      0034C2 E4               [12]10799 	clr	a
      0034C3 9C               [12]10800 	subb	a,r4
      0034C4 F0               [24]10801 	movx	@dptr,a
      0034C5 E4               [12]10802 	clr	a
      0034C6 9D               [12]10803 	subb	a,r5
      0034C7 A3               [24]10804 	inc	dptr
      0034C8 F0               [24]10805 	movx	@dptr,a
      0034C9 E4               [12]10806 	clr	a
      0034CA 9E               [12]10807 	subb	a,r6
      0034CB A3               [24]10808 	inc	dptr
      0034CC F0               [24]10809 	movx	@dptr,a
      0034CD E4               [12]10810 	clr	a
      0034CE 9F               [12]10811 	subb	a,r7
      0034CF A3               [24]10812 	inc	dptr
      0034D0 F0               [24]10813 	movx	@dptr,a
      0034D1 80 20            [24]10814 	sjmp	00105$
      0034D3                      10815 00104$:
                                  10816 ;	..\COMMON\easyax5043.c:2158: axradio_curfreqoffset = axradio_phy_maxfreqoffset;
      0034D3 90 4C 9D         [24]10817 	mov	dptr,#_axradio_phy_maxfreqoffset
      0034D6 E4               [12]10818 	clr	a
      0034D7 93               [24]10819 	movc	a,@a+dptr
      0034D8 FC               [12]10820 	mov	r4,a
      0034D9 74 01            [12]10821 	mov	a,#0x01
      0034DB 93               [24]10822 	movc	a,@a+dptr
      0034DC FD               [12]10823 	mov	r5,a
      0034DD 74 02            [12]10824 	mov	a,#0x02
      0034DF 93               [24]10825 	movc	a,@a+dptr
      0034E0 FE               [12]10826 	mov	r6,a
      0034E1 74 03            [12]10827 	mov	a,#0x03
      0034E3 93               [24]10828 	movc	a,@a+dptr
      0034E4 FF               [12]10829 	mov	r7,a
      0034E5 90 00 19         [24]10830 	mov	dptr,#_axradio_curfreqoffset
      0034E8 EC               [12]10831 	mov	a,r4
      0034E9 F0               [24]10832 	movx	@dptr,a
      0034EA ED               [12]10833 	mov	a,r5
      0034EB A3               [24]10834 	inc	dptr
      0034EC F0               [24]10835 	movx	@dptr,a
      0034ED EE               [12]10836 	mov	a,r6
      0034EE A3               [24]10837 	inc	dptr
      0034EF F0               [24]10838 	movx	@dptr,a
      0034F0 EF               [12]10839 	mov	a,r7
      0034F1 A3               [24]10840 	inc	dptr
      0034F2 F0               [24]10841 	movx	@dptr,a
      0034F3                      10842 00105$:
                                  10843 ;	..\COMMON\easyax5043.c:2159: return AXRADIO_ERR_INVALID;
      0034F3 75 82 04         [24]10844 	mov	dpl,#0x04
      0034F6 22               [24]10845 	ret
                                  10846 ;------------------------------------------------------------
                                  10847 ;Allocation info for local variables in function 'axradio_set_freqoffset'
                                  10848 ;------------------------------------------------------------
                                  10849 ;offs                      Allocated to registers r4 r5 r6 r7 
                                  10850 ;ret                       Allocated to registers r7 
                                  10851 ;ret2                      Allocated to registers r6 
                                  10852 ;------------------------------------------------------------
                                  10853 ;	..\COMMON\easyax5043.c:2162: uint8_t axradio_set_freqoffset(int32_t offs)
                                  10854 ;	-----------------------------------------
                                  10855 ;	 function axradio_set_freqoffset
                                  10856 ;	-----------------------------------------
      0034F7                      10857 _axradio_set_freqoffset:
                                  10858 ;	..\COMMON\easyax5043.c:2164: uint8_t __autodata ret = axradio_set_curfreqoffset(offs);
      0034F7 12 34 57         [24]10859 	lcall	_axradio_set_curfreqoffset
      0034FA AF 82            [24]10860 	mov	r7,dpl
                                  10861 ;	..\COMMON\easyax5043.c:2166: uint8_t __autodata ret2 = axradio_set_channel(axradio_curchannel);
      0034FC 90 00 18         [24]10862 	mov	dptr,#_axradio_curchannel
      0034FF E0               [24]10863 	movx	a,@dptr
      003500 F5 82            [12]10864 	mov	dpl,a
      003502 C0 07            [24]10865 	push	ar7
      003504 12 32 EC         [24]10866 	lcall	_axradio_set_channel
      003507 AE 82            [24]10867 	mov	r6,dpl
      003509 D0 07            [24]10868 	pop	ar7
                                  10869 ;	..\COMMON\easyax5043.c:2167: if (ret == AXRADIO_ERR_NOERROR)
      00350B EF               [12]10870 	mov	a,r7
      00350C 70 02            [24]10871 	jnz	00102$
                                  10872 ;	..\COMMON\easyax5043.c:2168: ret = ret2;
      00350E 8E 07            [24]10873 	mov	ar7,r6
      003510                      10874 00102$:
                                  10875 ;	..\COMMON\easyax5043.c:2170: return ret;
      003510 8F 82            [24]10876 	mov	dpl,r7
      003512 22               [24]10877 	ret
                                  10878 ;------------------------------------------------------------
                                  10879 ;Allocation info for local variables in function 'axradio_get_freqoffset'
                                  10880 ;------------------------------------------------------------
                                  10881 ;	..\COMMON\easyax5043.c:2173: int32_t axradio_get_freqoffset(void)
                                  10882 ;	-----------------------------------------
                                  10883 ;	 function axradio_get_freqoffset
                                  10884 ;	-----------------------------------------
      003513                      10885 _axradio_get_freqoffset:
                                  10886 ;	..\COMMON\easyax5043.c:2175: return axradio_curfreqoffset;
      003513 90 00 19         [24]10887 	mov	dptr,#_axradio_curfreqoffset
      003516 E0               [24]10888 	movx	a,@dptr
      003517 FC               [12]10889 	mov	r4,a
      003518 A3               [24]10890 	inc	dptr
      003519 E0               [24]10891 	movx	a,@dptr
      00351A FD               [12]10892 	mov	r5,a
      00351B A3               [24]10893 	inc	dptr
      00351C E0               [24]10894 	movx	a,@dptr
      00351D FE               [12]10895 	mov	r6,a
      00351E A3               [24]10896 	inc	dptr
      00351F E0               [24]10897 	movx	a,@dptr
      003520 8C 82            [24]10898 	mov	dpl,r4
      003522 8D 83            [24]10899 	mov	dph,r5
      003524 8E F0            [24]10900 	mov	b,r6
      003526 22               [24]10901 	ret
                                  10902 ;------------------------------------------------------------
                                  10903 ;Allocation info for local variables in function 'axradio_set_local_address'
                                  10904 ;------------------------------------------------------------
                                  10905 ;addr                      Allocated to registers r5 r6 r7 
                                  10906 ;------------------------------------------------------------
                                  10907 ;	..\COMMON\easyax5043.c:2178: void axradio_set_local_address(const struct axradio_address_mask __genericaddr *addr)
                                  10908 ;	-----------------------------------------
                                  10909 ;	 function axradio_set_local_address
                                  10910 ;	-----------------------------------------
      003527                      10911 _axradio_set_local_address:
      003527 AD 82            [24]10912 	mov	r5,dpl
      003529 AE 83            [24]10913 	mov	r6,dph
      00352B AF F0            [24]10914 	mov	r7,b
                                  10915 ;	..\COMMON\easyax5043.c:2180: memcpy_xdatageneric(&axradio_localaddr, addr, sizeof(axradio_localaddr));
      00352D 8D 2E            [24]10916 	mov	_memcpy_PARM_2,r5
      00352F 8E 2F            [24]10917 	mov	(_memcpy_PARM_2 + 1),r6
      003531 8F 30            [24]10918 	mov	(_memcpy_PARM_2 + 2),r7
      003533 75 31 0A         [24]10919 	mov	_memcpy_PARM_3,#0x0a
      003536 75 32 00         [24]10920 	mov	(_memcpy_PARM_3 + 1),#0x00
      003539 90 00 2D         [24]10921 	mov	dptr,#_axradio_localaddr
      00353C 75 F0 00         [24]10922 	mov	b,#0x00
      00353F 12 42 6F         [24]10923 	lcall	_memcpy
                                  10924 ;	..\COMMON\easyax5043.c:2181: axradio_setaddrregs();
      003542 02 17 DF         [24]10925 	ljmp	_axradio_setaddrregs
                                  10926 ;------------------------------------------------------------
                                  10927 ;Allocation info for local variables in function 'axradio_get_local_address'
                                  10928 ;------------------------------------------------------------
                                  10929 ;addr                      Allocated to registers r5 r6 r7 
                                  10930 ;------------------------------------------------------------
                                  10931 ;	..\COMMON\easyax5043.c:2184: void axradio_get_local_address(struct axradio_address_mask __genericaddr *addr)
                                  10932 ;	-----------------------------------------
                                  10933 ;	 function axradio_get_local_address
                                  10934 ;	-----------------------------------------
      003545                      10935 _axradio_get_local_address:
      003545 AD 82            [24]10936 	mov	r5,dpl
      003547 AE 83            [24]10937 	mov	r6,dph
      003549 AF F0            [24]10938 	mov	r7,b
                                  10939 ;	..\COMMON\easyax5043.c:2186: memcpy_genericxdata(addr, &axradio_localaddr, sizeof(axradio_localaddr));
      00354B 75 2E 2D         [24]10940 	mov	_memcpy_PARM_2,#_axradio_localaddr
      00354E 75 2F 00         [24]10941 	mov	(_memcpy_PARM_2 + 1),#(_axradio_localaddr >> 8)
      003551 75 30 00         [24]10942 	mov	(_memcpy_PARM_2 + 2),#0x00
      003554 75 31 0A         [24]10943 	mov	_memcpy_PARM_3,#0x0a
      003557 75 32 00         [24]10944 	mov	(_memcpy_PARM_3 + 1),#0x00
      00355A 8D 82            [24]10945 	mov	dpl,r5
      00355C 8E 83            [24]10946 	mov	dph,r6
      00355E 8F F0            [24]10947 	mov	b,r7
      003560 02 42 6F         [24]10948 	ljmp	_memcpy
                                  10949 ;------------------------------------------------------------
                                  10950 ;Allocation info for local variables in function 'axradio_set_default_remote_address'
                                  10951 ;------------------------------------------------------------
                                  10952 ;addr                      Allocated to registers r5 r6 r7 
                                  10953 ;------------------------------------------------------------
                                  10954 ;	..\COMMON\easyax5043.c:2189: void axradio_set_default_remote_address(const struct axradio_address __genericaddr *addr)
                                  10955 ;	-----------------------------------------
                                  10956 ;	 function axradio_set_default_remote_address
                                  10957 ;	-----------------------------------------
      003563                      10958 _axradio_set_default_remote_address:
      003563 AD 82            [24]10959 	mov	r5,dpl
      003565 AE 83            [24]10960 	mov	r6,dph
      003567 AF F0            [24]10961 	mov	r7,b
                                  10962 ;	..\COMMON\easyax5043.c:2191: memcpy_xdatageneric(&axradio_default_remoteaddr, addr, sizeof(axradio_default_remoteaddr));
      003569 8D 2E            [24]10963 	mov	_memcpy_PARM_2,r5
      00356B 8E 2F            [24]10964 	mov	(_memcpy_PARM_2 + 1),r6
      00356D 8F 30            [24]10965 	mov	(_memcpy_PARM_2 + 2),r7
      00356F 75 31 05         [24]10966 	mov	_memcpy_PARM_3,#0x05
      003572 75 32 00         [24]10967 	mov	(_memcpy_PARM_3 + 1),#0x00
      003575 90 00 37         [24]10968 	mov	dptr,#_axradio_default_remoteaddr
      003578 75 F0 00         [24]10969 	mov	b,#0x00
      00357B 02 42 6F         [24]10970 	ljmp	_memcpy
                                  10971 ;------------------------------------------------------------
                                  10972 ;Allocation info for local variables in function 'axradio_get_default_remote_address'
                                  10973 ;------------------------------------------------------------
                                  10974 ;addr                      Allocated to registers r5 r6 r7 
                                  10975 ;------------------------------------------------------------
                                  10976 ;	..\COMMON\easyax5043.c:2194: void axradio_get_default_remote_address(struct axradio_address __genericaddr *addr)
                                  10977 ;	-----------------------------------------
                                  10978 ;	 function axradio_get_default_remote_address
                                  10979 ;	-----------------------------------------
      00357E                      10980 _axradio_get_default_remote_address:
      00357E AD 82            [24]10981 	mov	r5,dpl
      003580 AE 83            [24]10982 	mov	r6,dph
      003582 AF F0            [24]10983 	mov	r7,b
                                  10984 ;	..\COMMON\easyax5043.c:2196: memcpy_genericxdata(addr, &axradio_default_remoteaddr, sizeof(axradio_default_remoteaddr));
      003584 75 2E 37         [24]10985 	mov	_memcpy_PARM_2,#_axradio_default_remoteaddr
      003587 75 2F 00         [24]10986 	mov	(_memcpy_PARM_2 + 1),#(_axradio_default_remoteaddr >> 8)
      00358A 75 30 00         [24]10987 	mov	(_memcpy_PARM_2 + 2),#0x00
      00358D 75 31 05         [24]10988 	mov	_memcpy_PARM_3,#0x05
      003590 75 32 00         [24]10989 	mov	(_memcpy_PARM_3 + 1),#0x00
      003593 8D 82            [24]10990 	mov	dpl,r5
      003595 8E 83            [24]10991 	mov	dph,r6
      003597 8F F0            [24]10992 	mov	b,r7
      003599 02 42 6F         [24]10993 	ljmp	_memcpy
                                  10994 ;------------------------------------------------------------
                                  10995 ;Allocation info for local variables in function 'axradio_transmit'
                                  10996 ;------------------------------------------------------------
                                  10997 ;pkt                       Allocated with name '_axradio_transmit_PARM_2'
                                  10998 ;pktlen                    Allocated with name '_axradio_transmit_PARM_3'
                                  10999 ;addr                      Allocated to registers r5 r6 r7 
                                  11000 ;fifofree                  Allocated to registers r3 r4 
                                  11001 ;i                         Allocated to registers r4 
                                  11002 ;__00030038                Allocated to registers 
                                  11003 ;crit                      Allocated to registers 
                                  11004 ;crit                      Allocated to registers r4 
                                  11005 ;__00040040                Allocated to registers 
                                  11006 ;crit                      Allocated to registers 
                                  11007 ;len_byte                  Allocated to registers r6 
                                  11008 ;------------------------------------------------------------
                                  11009 ;	..\COMMON\easyax5043.c:2199: uint8_t axradio_transmit(const struct axradio_address __genericaddr *addr, const uint8_t __genericaddr *pkt, uint16_t pktlen)
                                  11010 ;	-----------------------------------------
                                  11011 ;	 function axradio_transmit
                                  11012 ;	-----------------------------------------
      00359C                      11013 _axradio_transmit:
      00359C AD 82            [24]11014 	mov	r5,dpl
      00359E AE 83            [24]11015 	mov	r6,dph
      0035A0 AF F0            [24]11016 	mov	r7,b
                                  11017 ;	..\COMMON\easyax5043.c:2201: switch (axradio_mode) {
      0035A2 AC 08            [24]11018 	mov	r4,_axradio_mode
      0035A4 BC 10 03         [24]11019 	cjne	r4,#0x10,00316$
      0035A7 02 36 A0         [24]11020 	ljmp	00155$
      0035AA                      11021 00316$:
      0035AA BC 11 03         [24]11022 	cjne	r4,#0x11,00317$
      0035AD 02 36 A0         [24]11023 	ljmp	00155$
      0035B0                      11024 00317$:
      0035B0 BC 12 03         [24]11025 	cjne	r4,#0x12,00318$
      0035B3 02 36 A0         [24]11026 	ljmp	00155$
      0035B6                      11027 00318$:
      0035B6 BC 13 03         [24]11028 	cjne	r4,#0x13,00319$
      0035B9 02 36 A0         [24]11029 	ljmp	00155$
      0035BC                      11030 00319$:
      0035BC BC 18 02         [24]11031 	cjne	r4,#0x18,00320$
      0035BF 80 2F            [24]11032 	sjmp	00105$
      0035C1                      11033 00320$:
      0035C1 BC 19 02         [24]11034 	cjne	r4,#0x19,00321$
      0035C4 80 2A            [24]11035 	sjmp	00105$
      0035C6                      11036 00321$:
      0035C6 BC 1A 02         [24]11037 	cjne	r4,#0x1a,00322$
      0035C9 80 25            [24]11038 	sjmp	00105$
      0035CB                      11039 00322$:
      0035CB BC 1B 02         [24]11040 	cjne	r4,#0x1b,00323$
      0035CE 80 20            [24]11041 	sjmp	00105$
      0035D0                      11042 00323$:
      0035D0 BC 1C 02         [24]11043 	cjne	r4,#0x1c,00324$
      0035D3 80 1B            [24]11044 	sjmp	00105$
      0035D5                      11045 00324$:
      0035D5 BC 20 03         [24]11046 	cjne	r4,#0x20,00325$
      0035D8 02 36 67         [24]11047 	ljmp	00134$
      0035DB                      11048 00325$:
      0035DB BC 21 03         [24]11049 	cjne	r4,#0x21,00326$
      0035DE 02 36 67         [24]11050 	ljmp	00134$
      0035E1                      11051 00326$:
      0035E1 BC 30 03         [24]11052 	cjne	r4,#0x30,00327$
      0035E4 02 36 AB         [24]11053 	ljmp	00158$
      0035E7                      11054 00327$:
      0035E7 BC 31 03         [24]11055 	cjne	r4,#0x31,00328$
      0035EA 02 36 AB         [24]11056 	ljmp	00158$
      0035ED                      11057 00328$:
      0035ED 02 39 00         [24]11058 	ljmp	00198$
                                  11059 ;	..\COMMON\easyax5043.c:2206: case AXRADIO_MODE_STREAM_TRANSMIT_SCRAM_LSB:
      0035F0                      11060 00105$:
                                  11061 ;	..\COMMON\easyax5043.c:2208: uint16_t __autodata fifofree = radio_read16(AX5043_REG_FIFOFREE1); ///
      0035F0 90 00 2C         [24]11062 	mov	dptr,#0x002c
      0035F3 12 44 D1         [24]11063 	lcall	_radio_read16
      0035F6 AB 82            [24]11064 	mov	r3,dpl
      0035F8 AC 83            [24]11065 	mov	r4,dph
                                  11066 ;	..\COMMON\easyax5043.c:2210: if (fifofree < pktlen + 3)
      0035FA 74 03            [12]11067 	mov	a,#0x03
      0035FC 25 18            [12]11068 	add	a,_axradio_transmit_PARM_3
      0035FE F9               [12]11069 	mov	r1,a
      0035FF E4               [12]11070 	clr	a
      003600 35 19            [12]11071 	addc	a,(_axradio_transmit_PARM_3 + 1)
      003602 FA               [12]11072 	mov	r2,a
      003603 C3               [12]11073 	clr	c
      003604 EB               [12]11074 	mov	a,r3
      003605 99               [12]11075 	subb	a,r1
      003606 EC               [12]11076 	mov	a,r4
      003607 9A               [12]11077 	subb	a,r2
      003608 50 04            [24]11078 	jnc	00107$
                                  11079 ;	..\COMMON\easyax5043.c:2211: return AXRADIO_ERR_INVALID;
      00360A 75 82 04         [24]11080 	mov	dpl,#0x04
      00360D 22               [24]11081 	ret
      00360E                      11082 00107$:
                                  11083 ;	..\COMMON\easyax5043.c:2213: if (pktlen) {
      00360E E5 18            [12]11084 	mov	a,_axradio_transmit_PARM_3
      003610 45 19            [12]11085 	orl	a,(_axradio_transmit_PARM_3 + 1)
      003612 60 30            [24]11086 	jz	00124$
                                  11087 ;	..\COMMON\easyax5043.c:2214: uint8_t __autodata i = pktlen;
      003614 AC 18            [24]11088 	mov	r4,_axradio_transmit_PARM_3
                                  11089 ;	..\COMMON\easyax5043.c:2215: radio_write8(AX5043_REG_FIFODATA, AX5043_FIFOCMD_DATA | (7 << 5));
      003616 90 40 29         [24]11090 	mov	dptr,#0x4029
      003619 74 E1            [12]11091 	mov	a,#0xe1
      00361B F0               [24]11092 	movx	@dptr,a
                                  11093 ;	..\COMMON\easyax5043.c:2216: radio_write8(AX5043_REG_FIFODATA, i + 1);
      00361C EC               [12]11094 	mov	a,r4
      00361D 04               [12]11095 	inc	a
      00361E 90 40 29         [24]11096 	mov	dptr,#0x4029
      003621 F0               [24]11097 	movx	@dptr,a
                                  11098 ;	..\COMMON\easyax5043.c:2217: radio_write8(AX5043_REG_FIFODATA, 0x08);
      003622 90 40 29         [24]11099 	mov	dptr,#0x4029
      003625 74 08            [12]11100 	mov	a,#0x08
      003627 F0               [24]11101 	movx	@dptr,a
                                  11102 ;	..\COMMON\easyax5043.c:2219: radio_write8(AX5043_REG_FIFODATA, *pkt++);
      003628 A9 15            [24]11103 	mov	r1,_axradio_transmit_PARM_2
      00362A AA 16            [24]11104 	mov	r2,(_axradio_transmit_PARM_2 + 1)
      00362C AB 17            [24]11105 	mov	r3,(_axradio_transmit_PARM_2 + 2)
      00362E                      11106 00117$:
      00362E 89 82            [24]11107 	mov	dpl,r1
      003630 8A 83            [24]11108 	mov	dph,r2
      003632 8B F0            [24]11109 	mov	b,r3
      003634 12 4B F4         [24]11110 	lcall	__gptrget
      003637 F8               [12]11111 	mov	r0,a
      003638 A3               [24]11112 	inc	dptr
      003639 A9 82            [24]11113 	mov	r1,dpl
      00363B AA 83            [24]11114 	mov	r2,dph
      00363D 90 40 29         [24]11115 	mov	dptr,#0x4029
      003640 E8               [12]11116 	mov	a,r0
      003641 F0               [24]11117 	movx	@dptr,a
                                  11118 ;	..\COMMON\easyax5043.c:2220: } while (--i);
      003642 DC EA            [24]11119 	djnz	r4,00117$
      003644                      11120 00124$:
                                  11121 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:351: criticalsection_t crit = IE & 0x80;
      003644 74 80            [12]11122 	mov	a,#0x80
      003646 55 A8            [12]11123 	anl	a,_IE
      003648 FC               [12]11124 	mov	r4,a
                                  11125 ;	..\COMMON\easyax5043.c:2223: criticalsection_t crit = enter_critical();
      003649 C2 AF            [12]11126 	clr	_EA
                                  11127 ;	..\COMMON\easyax5043.c:2224: radio_read8(AX5043_REG_RADIOEVENTREQ0);
      00364B 90 40 0F         [24]11128 	mov	dptr,#0x400f
      00364E E0               [24]11129 	movx	a,@dptr
                                  11130 ;	..\COMMON\easyax5043.c:2225: radio_read8(AX5043_REG_IRQREQUEST0);
      00364F 90 40 0D         [24]11131 	mov	dptr,#0x400d
      003652 E0               [24]11132 	movx	a,@dptr
                                  11133 ;	..\COMMON\easyax5043.c:2226: radio_write8(AX5043_REG_IRQMASK0, radio_read8(AX5043_REG_IRQMASK0) | 0x08);
      003653 90 40 07         [24]11134 	mov	dptr,#0x4007
      003656 E0               [24]11135 	movx	a,@dptr
      003657 44 08            [12]11136 	orl	a,#0x08
      003659 F0               [24]11137 	movx	@dptr,a
                                  11138 ;	..\COMMON\easyax5043.c:2227: radio_write8(AX5043_REG_FIFOSTAT,  4); // FIFO commit
      00365A 90 40 28         [24]11139 	mov	dptr,#0x4028
      00365D 74 04            [12]11140 	mov	a,#0x04
      00365F F0               [24]11141 	movx	@dptr,a
                                  11142 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:358: IE |= crit;
      003660 EC               [12]11143 	mov	a,r4
      003661 42 A8            [12]11144 	orl	_IE,a
                                  11145 ;	..\COMMON\easyax5043.c:2230: return AXRADIO_ERR_NOERROR;
      003663 75 82 00         [24]11146 	mov	dpl,#0x00
      003666 22               [24]11147 	ret
                                  11148 ;	..\COMMON\easyax5043.c:2237: case AXRADIO_MODE_WOR_RECEIVE:
      003667                      11149 00134$:
                                  11150 ;	..\COMMON\easyax5043.c:2238: if (axradio_syncstate != syncstate_off)
      003667 90 00 13         [24]11151 	mov	dptr,#_axradio_syncstate
      00366A E0               [24]11152 	movx	a,@dptr
      00366B E0               [24]11153 	movx	a,@dptr
      00366C 60 04            [24]11154 	jz	00137$
                                  11155 ;	..\COMMON\easyax5043.c:2239: return AXRADIO_ERR_BUSY;
      00366E 75 82 02         [24]11156 	mov	dpl,#0x02
      003671 22               [24]11157 	ret
                                  11158 ;	..\COMMON\easyax5043.c:2240: radio_write8(AX5043_REG_IRQMASK1, 0x00);
      003672                      11159 00137$:
      003672 90 40 06         [24]11160 	mov	dptr,#0x4006
      003675 E4               [12]11161 	clr	a
      003676 F0               [24]11162 	movx	@dptr,a
                                  11163 ;	..\COMMON\easyax5043.c:2241: radio_write8(AX5043_REG_IRQMASK0, 0x00);
      003677 90 40 07         [24]11164 	mov	dptr,#0x4007
      00367A F0               [24]11165 	movx	@dptr,a
                                  11166 ;	..\COMMON\easyax5043.c:2242: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_XTAL_ON);
      00367B 90 40 02         [24]11167 	mov	dptr,#0x4002
      00367E 74 05            [12]11168 	mov	a,#0x05
      003680 F0               [24]11169 	movx	@dptr,a
                                  11170 ;	..\COMMON\easyax5043.c:2243: radio_write8(AX5043_REG_FIFOSTAT, 3);
      003681 90 40 28         [24]11171 	mov	dptr,#0x4028
      003684 74 03            [12]11172 	mov	a,#0x03
      003686 F0               [24]11173 	movx	@dptr,a
                                  11174 ;	..\COMMON\easyax5043.c:2244: while (radio_read8(AX5043_REG_POWSTAT) & 0x08);
      003687                      11175 00149$:
      003687 90 40 03         [24]11176 	mov	dptr,#0x4003
      00368A E0               [24]11177 	movx	a,@dptr
      00368B FC               [12]11178 	mov	r4,a
      00368C 20 E3 F8         [24]11179 	jb	acc.3,00149$
                                  11180 ;	..\COMMON\easyax5043.c:2245: ax5043_init_registers_tx();
      00368F C0 07            [24]11181 	push	ar7
      003691 C0 06            [24]11182 	push	ar6
      003693 C0 05            [24]11183 	push	ar5
      003695 12 0B 5F         [24]11184 	lcall	_ax5043_init_registers_tx
      003698 D0 05            [24]11185 	pop	ar5
      00369A D0 06            [24]11186 	pop	ar6
      00369C D0 07            [24]11187 	pop	ar7
                                  11188 ;	..\COMMON\easyax5043.c:2246: goto dotx;
                                  11189 ;	..\COMMON\easyax5043.c:2251: case AXRADIO_MODE_WOR_ACK_TRANSMIT:
      00369E 80 0B            [24]11190 	sjmp	00158$
      0036A0                      11191 00155$:
                                  11192 ;	..\COMMON\easyax5043.c:2252: if (axradio_syncstate != syncstate_off)
      0036A0 90 00 13         [24]11193 	mov	dptr,#_axradio_syncstate
      0036A3 E0               [24]11194 	movx	a,@dptr
      0036A4 E0               [24]11195 	movx	a,@dptr
      0036A5 60 04            [24]11196 	jz	00158$
                                  11197 ;	..\COMMON\easyax5043.c:2253: return AXRADIO_ERR_BUSY;
      0036A7 75 82 02         [24]11198 	mov	dpl,#0x02
      0036AA 22               [24]11199 	ret
                                  11200 ;	..\COMMON\easyax5043.c:2254: dotx:
      0036AB                      11201 00158$:
                                  11202 ;	..\COMMON\easyax5043.c:2255: axradio_ack_count = axradio_framing_ack_retransmissions;
      0036AB 90 4C CC         [24]11203 	mov	dptr,#_axradio_framing_ack_retransmissions
      0036AE E4               [12]11204 	clr	a
      0036AF 93               [24]11205 	movc	a,@a+dptr
      0036B0 90 00 1D         [24]11206 	mov	dptr,#_axradio_ack_count
      0036B3 F0               [24]11207 	movx	@dptr,a
                                  11208 ;	..\COMMON\easyax5043.c:2256: ++axradio_ack_seqnr;
      0036B4 90 00 1E         [24]11209 	mov	dptr,#_axradio_ack_seqnr
      0036B7 E0               [24]11210 	movx	a,@dptr
      0036B8 24 01            [12]11211 	add	a,#0x01
      0036BA F0               [24]11212 	movx	@dptr,a
                                  11213 ;	..\COMMON\easyax5043.c:2257: axradio_txbuffer_len = pktlen + axradio_framing_maclen;
      0036BB 90 4C B5         [24]11214 	mov	dptr,#_axradio_framing_maclen
      0036BE E4               [12]11215 	clr	a
      0036BF 93               [24]11216 	movc	a,@a+dptr
      0036C0 FC               [12]11217 	mov	r4,a
      0036C1 7B 00            [12]11218 	mov	r3,#0x00
      0036C3 25 18            [12]11219 	add	a,_axradio_transmit_PARM_3
      0036C5 FA               [12]11220 	mov	r2,a
      0036C6 EB               [12]11221 	mov	a,r3
      0036C7 35 19            [12]11222 	addc	a,(_axradio_transmit_PARM_3 + 1)
      0036C9 FB               [12]11223 	mov	r3,a
      0036CA 90 00 14         [24]11224 	mov	dptr,#_axradio_txbuffer_len
      0036CD EA               [12]11225 	mov	a,r2
      0036CE F0               [24]11226 	movx	@dptr,a
      0036CF EB               [12]11227 	mov	a,r3
      0036D0 A3               [24]11228 	inc	dptr
      0036D1 F0               [24]11229 	movx	@dptr,a
                                  11230 ;	..\COMMON\easyax5043.c:2258: if (axradio_txbuffer_len > sizeof(axradio_txbuffer))
      0036D2 C3               [12]11231 	clr	c
      0036D3 74 04            [12]11232 	mov	a,#0x04
      0036D5 9A               [12]11233 	subb	a,r2
      0036D6 74 01            [12]11234 	mov	a,#0x01
      0036D8 9B               [12]11235 	subb	a,r3
      0036D9 50 04            [24]11236 	jnc	00160$
                                  11237 ;	..\COMMON\easyax5043.c:2259: return AXRADIO_ERR_INVALID;
      0036DB 75 82 04         [24]11238 	mov	dpl,#0x04
      0036DE 22               [24]11239 	ret
      0036DF                      11240 00160$:
                                  11241 ;	..\COMMON\easyax5043.c:2260: memset_xdata(axradio_txbuffer, 0, axradio_framing_maclen);
      0036DF 8C 2F            [24]11242 	mov	_memset_PARM_3,r4
      0036E1 75 30 00         [24]11243 	mov	(_memset_PARM_3 + 1),#0x00
      0036E4 75 2E 00         [24]11244 	mov	_memset_PARM_2,#0x00
      0036E7 90 00 3C         [24]11245 	mov	dptr,#_axradio_txbuffer
      0036EA 75 F0 00         [24]11246 	mov	b,#0x00
      0036ED C0 07            [24]11247 	push	ar7
      0036EF C0 06            [24]11248 	push	ar6
      0036F1 C0 05            [24]11249 	push	ar5
      0036F3 12 42 50         [24]11250 	lcall	_memset
                                  11251 ;	..\COMMON\easyax5043.c:2261: memcpy_xdatageneric(&axradio_txbuffer[axradio_framing_maclen], pkt, pktlen);
      0036F6 90 4C B5         [24]11252 	mov	dptr,#_axradio_framing_maclen
      0036F9 E4               [12]11253 	clr	a
      0036FA 93               [24]11254 	movc	a,@a+dptr
      0036FB 24 3C            [12]11255 	add	a,#_axradio_txbuffer
      0036FD FC               [12]11256 	mov	r4,a
      0036FE E4               [12]11257 	clr	a
      0036FF 34 00            [12]11258 	addc	a,#(_axradio_txbuffer >> 8)
      003701 FB               [12]11259 	mov	r3,a
      003702 7A 00            [12]11260 	mov	r2,#0x00
      003704 85 15 2E         [24]11261 	mov	_memcpy_PARM_2,_axradio_transmit_PARM_2
      003707 85 16 2F         [24]11262 	mov	(_memcpy_PARM_2 + 1),(_axradio_transmit_PARM_2 + 1)
      00370A 85 17 30         [24]11263 	mov	(_memcpy_PARM_2 + 2),(_axradio_transmit_PARM_2 + 2)
      00370D 85 18 31         [24]11264 	mov	_memcpy_PARM_3,_axradio_transmit_PARM_3
      003710 85 19 32         [24]11265 	mov	(_memcpy_PARM_3 + 1),(_axradio_transmit_PARM_3 + 1)
      003713 8C 82            [24]11266 	mov	dpl,r4
      003715 8B 83            [24]11267 	mov	dph,r3
      003717 8A F0            [24]11268 	mov	b,r2
      003719 12 42 6F         [24]11269 	lcall	_memcpy
      00371C D0 05            [24]11270 	pop	ar5
      00371E D0 06            [24]11271 	pop	ar6
      003720 D0 07            [24]11272 	pop	ar7
                                  11273 ;	..\COMMON\easyax5043.c:2262: if (axradio_framing_ack_seqnrpos != 0xff)
      003722 90 4C CD         [24]11274 	mov	dptr,#_axradio_framing_ack_seqnrpos
      003725 E4               [12]11275 	clr	a
      003726 93               [24]11276 	movc	a,@a+dptr
      003727 FC               [12]11277 	mov	r4,a
      003728 BC FF 02         [24]11278 	cjne	r4,#0xff,00337$
      00372B 80 12            [24]11279 	sjmp	00162$
      00372D                      11280 00337$:
                                  11281 ;	..\COMMON\easyax5043.c:2263: axradio_txbuffer[axradio_framing_ack_seqnrpos] = axradio_ack_seqnr;
      00372D EC               [12]11282 	mov	a,r4
      00372E 24 3C            [12]11283 	add	a,#_axradio_txbuffer
      003730 FC               [12]11284 	mov	r4,a
      003731 E4               [12]11285 	clr	a
      003732 34 00            [12]11286 	addc	a,#(_axradio_txbuffer >> 8)
      003734 FB               [12]11287 	mov	r3,a
      003735 90 00 1E         [24]11288 	mov	dptr,#_axradio_ack_seqnr
      003738 E0               [24]11289 	movx	a,@dptr
      003739 FA               [12]11290 	mov	r2,a
      00373A 8C 82            [24]11291 	mov	dpl,r4
      00373C 8B 83            [24]11292 	mov	dph,r3
      00373E F0               [24]11293 	movx	@dptr,a
      00373F                      11294 00162$:
                                  11295 ;	..\COMMON\easyax5043.c:2264: if (axradio_framing_destaddrpos != 0xff)
      00373F 90 4C B7         [24]11296 	mov	dptr,#_axradio_framing_destaddrpos
      003742 E4               [12]11297 	clr	a
      003743 93               [24]11298 	movc	a,@a+dptr
      003744 FC               [12]11299 	mov	r4,a
      003745 BC FF 02         [24]11300 	cjne	r4,#0xff,00338$
      003748 80 23            [24]11301 	sjmp	00164$
      00374A                      11302 00338$:
                                  11303 ;	..\COMMON\easyax5043.c:2265: memcpy_xdatageneric(&axradio_txbuffer[axradio_framing_destaddrpos], &addr->addr, axradio_framing_addrlen);
      00374A EC               [12]11304 	mov	a,r4
      00374B 24 3C            [12]11305 	add	a,#_axradio_txbuffer
      00374D FC               [12]11306 	mov	r4,a
      00374E E4               [12]11307 	clr	a
      00374F 34 00            [12]11308 	addc	a,#(_axradio_txbuffer >> 8)
      003751 FB               [12]11309 	mov	r3,a
      003752 7A 00            [12]11310 	mov	r2,#0x00
      003754 8D 2E            [24]11311 	mov	_memcpy_PARM_2,r5
      003756 8E 2F            [24]11312 	mov	(_memcpy_PARM_2 + 1),r6
      003758 8F 30            [24]11313 	mov	(_memcpy_PARM_2 + 2),r7
      00375A 90 4C B6         [24]11314 	mov	dptr,#_axradio_framing_addrlen
      00375D E4               [12]11315 	clr	a
      00375E 93               [24]11316 	movc	a,@a+dptr
      00375F FF               [12]11317 	mov	r7,a
      003760 8F 31            [24]11318 	mov	_memcpy_PARM_3,r7
                                  11319 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_3 + 1),#0x00
      003762 8A 32            [24]11320 	mov	(_memcpy_PARM_3 + 1),r2
      003764 8C 82            [24]11321 	mov	dpl,r4
      003766 8B 83            [24]11322 	mov	dph,r3
      003768 8A F0            [24]11323 	mov	b,r2
      00376A 12 42 6F         [24]11324 	lcall	_memcpy
      00376D                      11325 00164$:
                                  11326 ;	..\COMMON\easyax5043.c:2266: if (axradio_framing_sourceaddrpos != 0xff)
      00376D 90 4C B8         [24]11327 	mov	dptr,#_axradio_framing_sourceaddrpos
      003770 E4               [12]11328 	clr	a
      003771 93               [24]11329 	movc	a,@a+dptr
      003772 FF               [12]11330 	mov	r7,a
      003773 BF FF 02         [24]11331 	cjne	r7,#0xff,00339$
      003776 80 25            [24]11332 	sjmp	00166$
      003778                      11333 00339$:
                                  11334 ;	..\COMMON\easyax5043.c:2267: memcpy_xdata(&axradio_txbuffer[axradio_framing_sourceaddrpos], &axradio_localaddr.addr, axradio_framing_addrlen);
      003778 EF               [12]11335 	mov	a,r7
      003779 24 3C            [12]11336 	add	a,#_axradio_txbuffer
      00377B FF               [12]11337 	mov	r7,a
      00377C E4               [12]11338 	clr	a
      00377D 34 00            [12]11339 	addc	a,#(_axradio_txbuffer >> 8)
      00377F FE               [12]11340 	mov	r6,a
      003780 7D 00            [12]11341 	mov	r5,#0x00
      003782 75 2E 2D         [24]11342 	mov	_memcpy_PARM_2,#_axradio_localaddr
      003785 75 2F 00         [24]11343 	mov	(_memcpy_PARM_2 + 1),#(_axradio_localaddr >> 8)
                                  11344 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_2 + 2),#0x00
      003788 8D 30            [24]11345 	mov	(_memcpy_PARM_2 + 2),r5
      00378A 90 4C B6         [24]11346 	mov	dptr,#_axradio_framing_addrlen
      00378D E4               [12]11347 	clr	a
      00378E 93               [24]11348 	movc	a,@a+dptr
      00378F FC               [12]11349 	mov	r4,a
      003790 8C 31            [24]11350 	mov	_memcpy_PARM_3,r4
                                  11351 ;	1-genFromRTrack replaced	mov	(_memcpy_PARM_3 + 1),#0x00
      003792 8D 32            [24]11352 	mov	(_memcpy_PARM_3 + 1),r5
      003794 8F 82            [24]11353 	mov	dpl,r7
      003796 8E 83            [24]11354 	mov	dph,r6
      003798 8D F0            [24]11355 	mov	b,r5
      00379A 12 42 6F         [24]11356 	lcall	_memcpy
      00379D                      11357 00166$:
                                  11358 ;	..\COMMON\easyax5043.c:2268: if (axradio_framing_lenmask) {
      00379D 90 4C BB         [24]11359 	mov	dptr,#_axradio_framing_lenmask
      0037A0 E4               [12]11360 	clr	a
      0037A1 93               [24]11361 	movc	a,@a+dptr
      0037A2 FF               [12]11362 	mov	r7,a
      0037A3 60 30            [24]11363 	jz	00168$
                                  11364 ;	..\COMMON\easyax5043.c:2269: uint8_t __autodata len_byte = (uint8_t)(axradio_txbuffer_len - axradio_framing_lenoffs) & axradio_framing_lenmask; // if you prefer not counting the len byte itself, set LENOFFS = 1
      0037A5 90 00 14         [24]11365 	mov	dptr,#_axradio_txbuffer_len
      0037A8 E0               [24]11366 	movx	a,@dptr
      0037A9 FD               [12]11367 	mov	r5,a
      0037AA A3               [24]11368 	inc	dptr
      0037AB E0               [24]11369 	movx	a,@dptr
      0037AC 90 4C BA         [24]11370 	mov	dptr,#_axradio_framing_lenoffs
      0037AF E4               [12]11371 	clr	a
      0037B0 93               [24]11372 	movc	a,@a+dptr
      0037B1 FE               [12]11373 	mov	r6,a
      0037B2 ED               [12]11374 	mov	a,r5
      0037B3 C3               [12]11375 	clr	c
      0037B4 9E               [12]11376 	subb	a,r6
      0037B5 5F               [12]11377 	anl	a,r7
      0037B6 FE               [12]11378 	mov	r6,a
                                  11379 ;	..\COMMON\easyax5043.c:2270: axradio_txbuffer[axradio_framing_lenpos] = (axradio_txbuffer[axradio_framing_lenpos] & (uint8_t)~axradio_framing_lenmask) | len_byte;
      0037B7 90 4C B9         [24]11380 	mov	dptr,#_axradio_framing_lenpos
      0037BA E4               [12]11381 	clr	a
      0037BB 93               [24]11382 	movc	a,@a+dptr
      0037BC 24 3C            [12]11383 	add	a,#_axradio_txbuffer
      0037BE FD               [12]11384 	mov	r5,a
      0037BF E4               [12]11385 	clr	a
      0037C0 34 00            [12]11386 	addc	a,#(_axradio_txbuffer >> 8)
      0037C2 FC               [12]11387 	mov	r4,a
      0037C3 8D 82            [24]11388 	mov	dpl,r5
      0037C5 8C 83            [24]11389 	mov	dph,r4
      0037C7 E0               [24]11390 	movx	a,@dptr
      0037C8 FB               [12]11391 	mov	r3,a
      0037C9 EF               [12]11392 	mov	a,r7
      0037CA F4               [12]11393 	cpl	a
      0037CB FF               [12]11394 	mov	r7,a
      0037CC 5B               [12]11395 	anl	a,r3
      0037CD 42 06            [12]11396 	orl	ar6,a
      0037CF 8D 82            [24]11397 	mov	dpl,r5
      0037D1 8C 83            [24]11398 	mov	dph,r4
      0037D3 EE               [12]11399 	mov	a,r6
      0037D4 F0               [24]11400 	movx	@dptr,a
      0037D5                      11401 00168$:
                                  11402 ;	..\COMMON\easyax5043.c:2272: if (axradio_framing_swcrclen)
      0037D5 90 4C BC         [24]11403 	mov	dptr,#_axradio_framing_swcrclen
      0037D8 E4               [12]11404 	clr	a
      0037D9 93               [24]11405 	movc	a,@a+dptr
      0037DA 60 20            [24]11406 	jz	00170$
                                  11407 ;	..\COMMON\easyax5043.c:2273: axradio_txbuffer_len = axradio_framing_append_crc(axradio_txbuffer, axradio_txbuffer_len);
      0037DC 90 00 14         [24]11408 	mov	dptr,#_axradio_txbuffer_len
      0037DF E0               [24]11409 	movx	a,@dptr
      0037E0 C0 E0            [24]11410 	push	acc
      0037E2 A3               [24]11411 	inc	dptr
      0037E3 E0               [24]11412 	movx	a,@dptr
      0037E4 C0 E0            [24]11413 	push	acc
      0037E6 90 00 3C         [24]11414 	mov	dptr,#_axradio_txbuffer
      0037E9 12 0A 1A         [24]11415 	lcall	_axradio_framing_append_crc
      0037EC AE 82            [24]11416 	mov	r6,dpl
      0037EE AF 83            [24]11417 	mov	r7,dph
      0037F0 15 81            [12]11418 	dec	sp
      0037F2 15 81            [12]11419 	dec	sp
      0037F4 90 00 14         [24]11420 	mov	dptr,#_axradio_txbuffer_len
      0037F7 EE               [12]11421 	mov	a,r6
      0037F8 F0               [24]11422 	movx	@dptr,a
      0037F9 EF               [12]11423 	mov	a,r7
      0037FA A3               [24]11424 	inc	dptr
      0037FB F0               [24]11425 	movx	@dptr,a
      0037FC                      11426 00170$:
                                  11427 ;	..\COMMON\easyax5043.c:2274: if (axradio_phy_pn9)
      0037FC 90 4C 70         [24]11428 	mov	dptr,#_axradio_phy_pn9
      0037FF E4               [12]11429 	clr	a
      003800 93               [24]11430 	movc	a,@a+dptr
      003801 60 2F            [24]11431 	jz	00172$
                                  11432 ;	..\COMMON\easyax5043.c:2275: pn9_buffer(axradio_txbuffer, axradio_txbuffer_len, 0x1ff, -((radio_read8(AX5043_REG_ENCODING) & 0x01)));
      003803 90 40 11         [24]11433 	mov	dptr,#0x4011
      003806 E0               [24]11434 	movx	a,@dptr
      003807 FF               [12]11435 	mov	r7,a
      003808 53 07 01         [24]11436 	anl	ar7,#0x01
      00380B C3               [12]11437 	clr	c
      00380C E4               [12]11438 	clr	a
      00380D 9F               [12]11439 	subb	a,r7
      00380E FF               [12]11440 	mov	r7,a
      00380F C0 07            [24]11441 	push	ar7
      003811 74 FF            [12]11442 	mov	a,#0xff
      003813 C0 E0            [24]11443 	push	acc
      003815 74 01            [12]11444 	mov	a,#0x01
      003817 C0 E0            [24]11445 	push	acc
      003819 90 00 14         [24]11446 	mov	dptr,#_axradio_txbuffer_len
      00381C E0               [24]11447 	movx	a,@dptr
      00381D C0 E0            [24]11448 	push	acc
      00381F A3               [24]11449 	inc	dptr
      003820 E0               [24]11450 	movx	a,@dptr
      003821 C0 E0            [24]11451 	push	acc
      003823 90 00 3C         [24]11452 	mov	dptr,#_axradio_txbuffer
      003826 75 F0 00         [24]11453 	mov	b,#0x00
      003829 12 43 BF         [24]11454 	lcall	_pn9_buffer
      00382C E5 81            [12]11455 	mov	a,sp
      00382E 24 FB            [12]11456 	add	a,#0xfb
      003830 F5 81            [12]11457 	mov	sp,a
      003832                      11458 00172$:
                                  11459 ;	..\COMMON\easyax5043.c:2276: if (axradio_mode == AXRADIO_MODE_SYNC_MASTER ||
      003832 74 30            [12]11460 	mov	a,#0x30
      003834 B5 08 02         [24]11461 	cjne	a,_axradio_mode,00343$
      003837 80 05            [24]11462 	sjmp	00173$
      003839                      11463 00343$:
                                  11464 ;	..\COMMON\easyax5043.c:2277: axradio_mode == AXRADIO_MODE_SYNC_ACK_MASTER)
      003839 74 31            [12]11465 	mov	a,#0x31
      00383B B5 08 04         [24]11466 	cjne	a,_axradio_mode,00174$
      00383E                      11467 00173$:
                                  11468 ;	..\COMMON\easyax5043.c:2278: return AXRADIO_ERR_NOERROR;
      00383E 75 82 00         [24]11469 	mov	dpl,#0x00
      003841 22               [24]11470 	ret
      003842                      11471 00174$:
                                  11472 ;	..\COMMON\easyax5043.c:2279: if (axradio_mode == AXRADIO_MODE_WOR_TRANSMIT ||
      003842 74 11            [12]11473 	mov	a,#0x11
      003844 B5 08 02         [24]11474 	cjne	a,_axradio_mode,00346$
      003847 80 05            [24]11475 	sjmp	00176$
      003849                      11476 00346$:
                                  11477 ;	..\COMMON\easyax5043.c:2280: axradio_mode == AXRADIO_MODE_WOR_ACK_TRANSMIT)
      003849 74 13            [12]11478 	mov	a,#0x13
      00384B B5 08 14         [24]11479 	cjne	a,_axradio_mode,00177$
      00384E                      11480 00176$:
                                  11481 ;	..\COMMON\easyax5043.c:2281: axradio_txbuffer_cnt = axradio_phy_preamble_wor_longlen;
      00384E 90 4C A9         [24]11482 	mov	dptr,#_axradio_phy_preamble_wor_longlen
      003851 E4               [12]11483 	clr	a
      003852 93               [24]11484 	movc	a,@a+dptr
      003853 FE               [12]11485 	mov	r6,a
      003854 74 01            [12]11486 	mov	a,#0x01
      003856 93               [24]11487 	movc	a,@a+dptr
      003857 FF               [12]11488 	mov	r7,a
      003858 90 00 16         [24]11489 	mov	dptr,#_axradio_txbuffer_cnt
      00385B EE               [12]11490 	mov	a,r6
      00385C F0               [24]11491 	movx	@dptr,a
      00385D EF               [12]11492 	mov	a,r7
      00385E A3               [24]11493 	inc	dptr
      00385F F0               [24]11494 	movx	@dptr,a
      003860 80 12            [24]11495 	sjmp	00178$
      003862                      11496 00177$:
                                  11497 ;	..\COMMON\easyax5043.c:2283: axradio_txbuffer_cnt = axradio_phy_preamble_longlen;
      003862 90 4C AD         [24]11498 	mov	dptr,#_axradio_phy_preamble_longlen
      003865 E4               [12]11499 	clr	a
      003866 93               [24]11500 	movc	a,@a+dptr
      003867 FE               [12]11501 	mov	r6,a
      003868 74 01            [12]11502 	mov	a,#0x01
      00386A 93               [24]11503 	movc	a,@a+dptr
      00386B FF               [12]11504 	mov	r7,a
      00386C 90 00 16         [24]11505 	mov	dptr,#_axradio_txbuffer_cnt
      00386F EE               [12]11506 	mov	a,r6
      003870 F0               [24]11507 	movx	@dptr,a
      003871 EF               [12]11508 	mov	a,r7
      003872 A3               [24]11509 	inc	dptr
      003873 F0               [24]11510 	movx	@dptr,a
      003874                      11511 00178$:
                                  11512 ;	..\COMMON\easyax5043.c:2284: if (axradio_phy_lbt_retries) {
      003874 90 4C A7         [24]11513 	mov	dptr,#_axradio_phy_lbt_retries
      003877 E4               [12]11514 	clr	a
      003878 93               [24]11515 	movc	a,@a+dptr
      003879 60 78            [24]11516 	jz	00197$
                                  11517 ;	..\COMMON\easyax5043.c:2285: switch (axradio_mode) {
      00387B AF 08            [24]11518 	mov	r7,_axradio_mode
      00387D BF 10 02         [24]11519 	cjne	r7,#0x10,00350$
      003880 80 21            [24]11520 	sjmp	00187$
      003882                      11521 00350$:
      003882 BF 11 02         [24]11522 	cjne	r7,#0x11,00351$
      003885 80 1C            [24]11523 	sjmp	00187$
      003887                      11524 00351$:
      003887 BF 12 02         [24]11525 	cjne	r7,#0x12,00352$
      00388A 80 17            [24]11526 	sjmp	00187$
      00388C                      11527 00352$:
      00388C BF 13 02         [24]11528 	cjne	r7,#0x13,00353$
      00388F 80 12            [24]11529 	sjmp	00187$
      003891                      11530 00353$:
      003891 BF 20 02         [24]11531 	cjne	r7,#0x20,00354$
      003894 80 0D            [24]11532 	sjmp	00187$
      003896                      11533 00354$:
      003896 BF 21 02         [24]11534 	cjne	r7,#0x21,00355$
      003899 80 08            [24]11535 	sjmp	00187$
      00389B                      11536 00355$:
      00389B BF 22 02         [24]11537 	cjne	r7,#0x22,00356$
      00389E 80 03            [24]11538 	sjmp	00187$
      0038A0                      11539 00356$:
      0038A0 BF 23 50         [24]11540 	cjne	r7,#0x23,00197$
                                  11541 ;	..\COMMON\easyax5043.c:2293: case AXRADIO_MODE_ACK_RECEIVE:
      0038A3                      11542 00187$:
                                  11543 ;	..\COMMON\easyax5043.c:2294: ax5043_off_xtal();
      0038A3 12 17 93         [24]11544 	lcall	_ax5043_off_xtal
                                  11545 ;	..\COMMON\easyax5043.c:2295: ax5043_init_registers_rx();
      0038A6 12 0B 65         [24]11546 	lcall	_ax5043_init_registers_rx
                                  11547 ;	..\COMMON\easyax5043.c:2296: radio_write8(AX5043_REG_RSSIREFERENCE, axradio_phy_rssireference);
      0038A9 90 4C A2         [24]11548 	mov	dptr,#_axradio_phy_rssireference
      0038AC E4               [12]11549 	clr	a
      0038AD 93               [24]11550 	movc	a,@a+dptr
      0038AE 90 42 2C         [24]11551 	mov	dptr,#0x422c
      0038B1 F0               [24]11552 	movx	@dptr,a
                                  11553 ;	..\COMMON\easyax5043.c:2297: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_FULL_RX);
      0038B2 90 40 02         [24]11554 	mov	dptr,#0x4002
      0038B5 74 09            [12]11555 	mov	a,#0x09
      0038B7 F0               [24]11556 	movx	@dptr,a
                                  11557 ;	..\COMMON\easyax5043.c:2298: axradio_ack_count = axradio_phy_lbt_retries;
      0038B8 90 4C A7         [24]11558 	mov	dptr,#_axradio_phy_lbt_retries
      0038BB E4               [12]11559 	clr	a
      0038BC 93               [24]11560 	movc	a,@a+dptr
      0038BD 90 00 1D         [24]11561 	mov	dptr,#_axradio_ack_count
      0038C0 F0               [24]11562 	movx	@dptr,a
                                  11563 ;	..\COMMON\easyax5043.c:2299: axradio_syncstate = syncstate_lbt;
      0038C1 90 00 13         [24]11564 	mov	dptr,#_axradio_syncstate
      0038C4 74 01            [12]11565 	mov	a,#0x01
      0038C6 F0               [24]11566 	movx	@dptr,a
                                  11567 ;	..\COMMON\easyax5043.c:2300: wtimer_remove(&axradio_timer);
      0038C7 90 02 9D         [24]11568 	mov	dptr,#_axradio_timer
      0038CA 12 47 8D         [24]11569 	lcall	_wtimer_remove
                                  11570 ;	..\COMMON\easyax5043.c:2301: axradio_timer.time = axradio_phy_cs_period;
      0038CD 90 4C A4         [24]11571 	mov	dptr,#_axradio_phy_cs_period
      0038D0 E4               [12]11572 	clr	a
      0038D1 93               [24]11573 	movc	a,@a+dptr
      0038D2 FE               [12]11574 	mov	r6,a
      0038D3 74 01            [12]11575 	mov	a,#0x01
      0038D5 93               [24]11576 	movc	a,@a+dptr
      0038D6 FF               [12]11577 	mov	r7,a
      0038D7 7D 00            [12]11578 	mov	r5,#0x00
      0038D9 7C 00            [12]11579 	mov	r4,#0x00
      0038DB 90 02 A1         [24]11580 	mov	dptr,#(_axradio_timer + 0x0004)
      0038DE EE               [12]11581 	mov	a,r6
      0038DF F0               [24]11582 	movx	@dptr,a
      0038E0 EF               [12]11583 	mov	a,r7
      0038E1 A3               [24]11584 	inc	dptr
      0038E2 F0               [24]11585 	movx	@dptr,a
      0038E3 ED               [12]11586 	mov	a,r5
      0038E4 A3               [24]11587 	inc	dptr
      0038E5 F0               [24]11588 	movx	@dptr,a
      0038E6 EC               [12]11589 	mov	a,r4
      0038E7 A3               [24]11590 	inc	dptr
      0038E8 F0               [24]11591 	movx	@dptr,a
                                  11592 ;	..\COMMON\easyax5043.c:2302: wtimer0_addrelative(&axradio_timer);
      0038E9 90 02 9D         [24]11593 	mov	dptr,#_axradio_timer
      0038EC 12 42 DE         [24]11594 	lcall	_wtimer0_addrelative
                                  11595 ;	..\COMMON\easyax5043.c:2303: return AXRADIO_ERR_NOERROR;
      0038EF 75 82 00         [24]11596 	mov	dpl,#0x00
                                  11597 ;	..\COMMON\easyax5043.c:2307: }
      0038F2 22               [24]11598 	ret
      0038F3                      11599 00197$:
                                  11600 ;	..\COMMON\easyax5043.c:2309: axradio_syncstate = syncstate_asynctx;
      0038F3 90 00 13         [24]11601 	mov	dptr,#_axradio_syncstate
      0038F6 74 02            [12]11602 	mov	a,#0x02
      0038F8 F0               [24]11603 	movx	@dptr,a
                                  11604 ;	..\COMMON\easyax5043.c:2310: ax5043_prepare_tx();
      0038F9 12 17 61         [24]11605 	lcall	_ax5043_prepare_tx
                                  11606 ;	..\COMMON\easyax5043.c:2311: return AXRADIO_ERR_NOERROR;
      0038FC 75 82 00         [24]11607 	mov	dpl,#0x00
                                  11608 ;	..\COMMON\easyax5043.c:2313: default:
      0038FF 22               [24]11609 	ret
      003900                      11610 00198$:
                                  11611 ;	..\COMMON\easyax5043.c:2314: return AXRADIO_ERR_NOTSUPPORTED;
      003900 75 82 01         [24]11612 	mov	dpl,#0x01
                                  11613 ;	..\COMMON\easyax5043.c:2315: }
      003903 22               [24]11614 	ret
                                  11615 ;------------------------------------------------------------
                                  11616 ;Allocation info for local variables in function 'axradio_set_paramsets'
                                  11617 ;------------------------------------------------------------
                                  11618 ;val                       Allocated to registers r7 
                                  11619 ;------------------------------------------------------------
                                  11620 ;	..\COMMON\easyax5043.c:2318: static __reentrantb uint8_t axradio_set_paramsets(uint8_t val) __reentrant
                                  11621 ;	-----------------------------------------
                                  11622 ;	 function axradio_set_paramsets
                                  11623 ;	-----------------------------------------
      003904                      11624 _axradio_set_paramsets:
      003904 AF 82            [24]11625 	mov	r7,dpl
                                  11626 ;	..\COMMON\easyax5043.c:2320: if (!AXRADIO_MODE_IS_STREAM_RECEIVE(axradio_mode))
      003906 74 F8            [12]11627 	mov	a,#0xf8
      003908 55 08            [12]11628 	anl	a,_axradio_mode
      00390A FE               [12]11629 	mov	r6,a
      00390B BE 28 02         [24]11630 	cjne	r6,#0x28,00111$
      00390E 80 04            [24]11631 	sjmp	00103$
      003910                      11632 00111$:
                                  11633 ;	..\COMMON\easyax5043.c:2321: return AXRADIO_ERR_NOTSUPPORTED;
      003910 75 82 01         [24]11634 	mov	dpl,#0x01
                                  11635 ;	..\COMMON\easyax5043.c:2322: radio_write8(AX5043_REG_RXPARAMSETS, val);
      003913 22               [24]11636 	ret
      003914                      11637 00103$:
      003914 90 41 17         [24]11638 	mov	dptr,#0x4117
      003917 EF               [12]11639 	mov	a,r7
      003918 F0               [24]11640 	movx	@dptr,a
                                  11641 ;	..\COMMON\easyax5043.c:2323: return AXRADIO_ERR_NOERROR;
      003919 75 82 00         [24]11642 	mov	dpl,#0x00
      00391C 22               [24]11643 	ret
                                  11644 ;------------------------------------------------------------
                                  11645 ;Allocation info for local variables in function 'axradio_agc_freeze'
                                  11646 ;------------------------------------------------------------
                                  11647 ;	..\COMMON\easyax5043.c:2326: uint8_t axradio_agc_freeze(void)
                                  11648 ;	-----------------------------------------
                                  11649 ;	 function axradio_agc_freeze
                                  11650 ;	-----------------------------------------
      00391D                      11651 _axradio_agc_freeze:
                                  11652 ;	..\COMMON\easyax5043.c:2328: return axradio_set_paramsets(0xff);
      00391D 75 82 FF         [24]11653 	mov	dpl,#0xff
      003920 02 39 04         [24]11654 	ljmp	_axradio_set_paramsets
                                  11655 ;------------------------------------------------------------
                                  11656 ;Allocation info for local variables in function 'axradio_agc_thaw'
                                  11657 ;------------------------------------------------------------
                                  11658 ;	..\COMMON\easyax5043.c:2331: uint8_t axradio_agc_thaw(void)
                                  11659 ;	-----------------------------------------
                                  11660 ;	 function axradio_agc_thaw
                                  11661 ;	-----------------------------------------
      003923                      11662 _axradio_agc_thaw:
                                  11663 ;	..\COMMON\easyax5043.c:2333: return axradio_set_paramsets(0x00);
      003923 75 82 00         [24]11664 	mov	dpl,#0x00
      003926 02 39 04         [24]11665 	ljmp	_axradio_set_paramsets
                                  11666 ;------------------------------------------------------------
                                  11667 ;Allocation info for local variables in function 'axradio_wait_n_lposccycles'
                                  11668 ;------------------------------------------------------------
                                  11669 ;n                         Allocated to registers r7 
                                  11670 ;cnt                       Allocated to registers r6 
                                  11671 ;------------------------------------------------------------
                                  11672 ;	..\COMMON\easyax5043.c:2336: void axradio_wait_n_lposccycles(uint8_t n)
                                  11673 ;	-----------------------------------------
                                  11674 ;	 function axradio_wait_n_lposccycles
                                  11675 ;	-----------------------------------------
      003929                      11676 _axradio_wait_n_lposccycles:
      003929 AF 82            [24]11677 	mov	r7,dpl
                                  11678 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:373: EA = 0;
      00392B C2 AF            [12]11679 	clr	_EA
                                  11680 ;	..\COMMON\easyax5043.c:2340: radio_write8(AX5043_REG_IRQMASK1, radio_read8(AX5043_REG_IRQMASK1) | 0x04); // LPOSC irq
      00392D 90 40 06         [24]11681 	mov	dptr,#0x4006
      003930 E0               [24]11682 	movx	a,@dptr
      003931 44 04            [12]11683 	orl	a,#0x04
      003933 F0               [24]11684 	movx	@dptr,a
      003934 7E 00            [12]11685 	mov	r6,#0x00
      003936                      11686 00114$:
                                  11687 ;	..\COMMON\easyax5043.c:2343: if( radio_read8(AX5043_REG_IRQREQUEST1) & 0x04 )
      003936 90 40 0C         [24]11688 	mov	dptr,#0x400c
      003939 E0               [24]11689 	movx	a,@dptr
      00393A FD               [12]11690 	mov	r5,a
      00393B 30 E2 05         [24]11691 	jnb	acc.2,00105$
                                  11692 ;	..\COMMON\easyax5043.c:2345: cnt++;
      00393E 0E               [12]11693 	inc	r6
                                  11694 ;	..\COMMON\easyax5043.c:2346: radio_read8(AX5043_REG_LPOSCSTATUS); // clear irq request
      00393F 90 43 11         [24]11695 	mov	dptr,#0x4311
      003942 E0               [24]11696 	movx	a,@dptr
      003943                      11697 00105$:
                                  11698 ;	..\COMMON\easyax5043.c:2349: if(cnt > n)
      003943 C3               [12]11699 	clr	c
      003944 EF               [12]11700 	mov	a,r7
      003945 9E               [12]11701 	subb	a,r6
      003946 40 05            [24]11702 	jc	00109$
                                  11703 ;	..\COMMON\easyax5043.c:2351: enter_standby();
      003948 12 44 F4         [24]11704 	lcall	_enter_standby
                                  11705 ;	..\COMMON\easyax5043.c:2354: radio_write8(AX5043_REG_IRQMASK1, (radio_read8(AX5043_REG_IRQMASK1) & ~0x04)); // disable LPOSC irq
      00394B 80 E9            [24]11706 	sjmp	00114$
      00394D                      11707 00109$:
      00394D 90 40 06         [24]11708 	mov	dptr,#0x4006
      003950 E0               [24]11709 	movx	a,@dptr
      003951 54 FB            [12]11710 	anl	a,#0xfb
      003953 F0               [24]11711 	movx	@dptr,a
                                  11712 ;	C:/Program Files (x86)/ON Semiconductor/AXSDB/libmf/include/libmftypes.h:368: EA = 1;
      003954 D2 AF            [12]11713 	setb	_EA
                                  11714 ;	..\COMMON\easyax5043.c:2355: __enable_irq();
      003956 22               [24]11715 	ret
                                  11716 ;------------------------------------------------------------
                                  11717 ;Allocation info for local variables in function 'axradio_calibrate_lposc'
                                  11718 ;------------------------------------------------------------
                                  11719 ;x                         Allocated to registers r7 
                                  11720 ;------------------------------------------------------------
                                  11721 ;	..\COMMON\easyax5043.c:2358: void axradio_calibrate_lposc(void)
                                  11722 ;	-----------------------------------------
                                  11723 ;	 function axradio_calibrate_lposc
                                  11724 ;	-----------------------------------------
      003957                      11725 _axradio_calibrate_lposc:
                                  11726 ;	..\COMMON\easyax5043.c:2360: radio_write8(AX5043_REG_LPOSCFREQ1, 0x00);
      003957 90 43 16         [24]11727 	mov	dptr,#0x4316
      00395A E4               [12]11728 	clr	a
      00395B F0               [24]11729 	movx	@dptr,a
                                  11730 ;	..\COMMON\easyax5043.c:2361: radio_write8(AX5043_REG_LPOSCFREQ0, 0x00);
      00395C 90 43 17         [24]11731 	mov	dptr,#0x4317
      00395F F0               [24]11732 	movx	@dptr,a
                                  11733 ;	..\COMMON\easyax5043.c:2363: radio_write8(AX5043_REG_LPOSCREF1, (((axradio_fxtal/640)>>8) & 0xFF));
      003960 90 4D 07         [24]11734 	mov	dptr,#_axradio_fxtal
                                  11735 ;	genFromRTrack removed	clr	a
      003963 93               [24]11736 	movc	a,@a+dptr
      003964 FC               [12]11737 	mov	r4,a
      003965 74 01            [12]11738 	mov	a,#0x01
      003967 93               [24]11739 	movc	a,@a+dptr
      003968 FD               [12]11740 	mov	r5,a
      003969 74 02            [12]11741 	mov	a,#0x02
      00396B 93               [24]11742 	movc	a,@a+dptr
      00396C FE               [12]11743 	mov	r6,a
      00396D 74 03            [12]11744 	mov	a,#0x03
      00396F 93               [24]11745 	movc	a,@a+dptr
      003970 FF               [12]11746 	mov	r7,a
      003971 75 2E 80         [24]11747 	mov	__divulong_PARM_2,#0x80
      003974 75 2F 02         [24]11748 	mov	(__divulong_PARM_2 + 1),#0x02
      003977 E4               [12]11749 	clr	a
      003978 F5 30            [12]11750 	mov	(__divulong_PARM_2 + 2),a
      00397A F5 31            [12]11751 	mov	(__divulong_PARM_2 + 3),a
      00397C 8C 82            [24]11752 	mov	dpl,r4
      00397E 8D 83            [24]11753 	mov	dph,r5
      003980 8E F0            [24]11754 	mov	b,r6
      003982 EF               [12]11755 	mov	a,r7
      003983 12 3E E9         [24]11756 	lcall	__divulong
      003986 AC 82            [24]11757 	mov	r4,dpl
      003988 AD 83            [24]11758 	mov	r5,dph
      00398A 8D 03            [24]11759 	mov	ar3,r5
      00398C 90 43 14         [24]11760 	mov	dptr,#0x4314
      00398F EB               [12]11761 	mov	a,r3
      003990 F0               [24]11762 	movx	@dptr,a
                                  11763 ;	..\COMMON\easyax5043.c:2364: radio_write8(AX5043_REG_LPOSCREF0, (((axradio_fxtal/640)>>0) & 0xFF));
      003991 90 43 15         [24]11764 	mov	dptr,#0x4315
      003994 EC               [12]11765 	mov	a,r4
      003995 F0               [24]11766 	movx	@dptr,a
                                  11767 ;	..\COMMON\easyax5043.c:2365: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_SYNTH_RX);
      003996 90 40 02         [24]11768 	mov	dptr,#0x4002
      003999 74 08            [12]11769 	mov	a,#0x08
      00399B F0               [24]11770 	movx	@dptr,a
                                  11771 ;	..\COMMON\easyax5043.c:2366: radio_write8(AX5043_REG_LPOSCKFILT1, ((axradio_lposckfiltmax >> (8 + 1)) & 0xFF)); // kfiltmax >> 1
      00399C 90 4D 05         [24]11772 	mov	dptr,#_axradio_lposckfiltmax
      00399F E4               [12]11773 	clr	a
      0039A0 93               [24]11774 	movc	a,@a+dptr
      0039A1 FE               [12]11775 	mov	r6,a
      0039A2 74 01            [12]11776 	mov	a,#0x01
      0039A4 93               [24]11777 	movc	a,@a+dptr
      0039A5 FF               [12]11778 	mov	r7,a
      0039A6 C3               [12]11779 	clr	c
      0039A7 13               [12]11780 	rrc	a
      0039A8 FC               [12]11781 	mov	r4,a
      0039A9 90 43 12         [24]11782 	mov	dptr,#0x4312
      0039AC EC               [12]11783 	mov	a,r4
      0039AD F0               [24]11784 	movx	@dptr,a
                                  11785 ;	..\COMMON\easyax5043.c:2367: radio_write8(AX5043_REG_LPOSCKFILT0, ((axradio_lposckfiltmax >> 1) & 0xFF));
      0039AE EF               [12]11786 	mov	a,r7
      0039AF C3               [12]11787 	clr	c
      0039B0 13               [12]11788 	rrc	a
      0039B1 CE               [12]11789 	xch	a,r6
      0039B2 13               [12]11790 	rrc	a
      0039B3 CE               [12]11791 	xch	a,r6
      0039B4 90 43 13         [24]11792 	mov	dptr,#0x4313
      0039B7 EE               [12]11793 	mov	a,r6
      0039B8 F0               [24]11794 	movx	@dptr,a
                                  11795 ;	..\COMMON\easyax5043.c:2368: axradio_wait_for_xtal();
      0039B9 12 17 AA         [24]11796 	lcall	_axradio_wait_for_xtal
                                  11797 ;	..\COMMON\easyax5043.c:2370: radio_write8(AX5043_REG_LPOSCCONFIG, 0x25); // LPOSC ENA, slow mode; calibrate on rising edge, irq on rising edge
      0039BC 90 43 10         [24]11798 	mov	dptr,#0x4310
      0039BF 74 25            [12]11799 	mov	a,#0x25
      0039C1 F0               [24]11800 	movx	@dptr,a
                                  11801 ;	..\COMMON\easyax5043.c:2371: axradio_wait_n_lposccycles(6);
      0039C2 75 82 06         [24]11802 	mov	dpl,#0x06
      0039C5 12 39 29         [24]11803 	lcall	_axradio_wait_n_lposccycles
                                  11804 ;	..\COMMON\easyax5043.c:2388: radio_write8(AX5043_REG_LPOSCKFILT1, ((axradio_lposckfiltmax >> (8 + 2)) & 0xFF)); // kfiltmax >> 2
      0039C8 90 4D 05         [24]11805 	mov	dptr,#_axradio_lposckfiltmax
      0039CB E4               [12]11806 	clr	a
      0039CC 93               [24]11807 	movc	a,@a+dptr
      0039CD FE               [12]11808 	mov	r6,a
      0039CE 74 01            [12]11809 	mov	a,#0x01
      0039D0 93               [24]11810 	movc	a,@a+dptr
      0039D1 FF               [12]11811 	mov	r7,a
      0039D2 03               [12]11812 	rr	a
      0039D3 03               [12]11813 	rr	a
      0039D4 54 3F            [12]11814 	anl	a,#0x3f
      0039D6 FC               [12]11815 	mov	r4,a
      0039D7 90 43 12         [24]11816 	mov	dptr,#0x4312
      0039DA EC               [12]11817 	mov	a,r4
      0039DB F0               [24]11818 	movx	@dptr,a
                                  11819 ;	..\COMMON\easyax5043.c:2389: radio_write8(AX5043_REG_LPOSCKFILT0, ((axradio_lposckfiltmax >> 2) & 0xFF));
      0039DC EF               [12]11820 	mov	a,r7
      0039DD C3               [12]11821 	clr	c
      0039DE 13               [12]11822 	rrc	a
      0039DF CE               [12]11823 	xch	a,r6
      0039E0 13               [12]11824 	rrc	a
      0039E1 CE               [12]11825 	xch	a,r6
      0039E2 C3               [12]11826 	clr	c
      0039E3 13               [12]11827 	rrc	a
      0039E4 CE               [12]11828 	xch	a,r6
      0039E5 13               [12]11829 	rrc	a
      0039E6 CE               [12]11830 	xch	a,r6
      0039E7 90 43 13         [24]11831 	mov	dptr,#0x4313
      0039EA EE               [12]11832 	mov	a,r6
      0039EB F0               [24]11833 	movx	@dptr,a
                                  11834 ;	..\COMMON\easyax5043.c:2390: axradio_wait_n_lposccycles(5);
      0039EC 75 82 05         [24]11835 	mov	dpl,#0x05
      0039EF 12 39 29         [24]11836 	lcall	_axradio_wait_n_lposccycles
                                  11837 ;	..\COMMON\easyax5043.c:2392: radio_write8(AX5043_REG_LPOSCCONFIG, 0x00);
      0039F2 90 43 10         [24]11838 	mov	dptr,#0x4310
      0039F5 E4               [12]11839 	clr	a
      0039F6 F0               [24]11840 	movx	@dptr,a
                                  11841 ;	..\COMMON\easyax5043.c:2393: radio_write8(AX5043_REG_PWRMODE, AX5043_PWRSTATE_POWERDOWN);
      0039F7 90 40 02         [24]11842 	mov	dptr,#0x4002
      0039FA F0               [24]11843 	movx	@dptr,a
                                  11844 ;	..\COMMON\easyax5043.c:2396: uint8_t x = radio_read8(AX5043_REG_LPOSCFREQ1);
      0039FB 90 43 16         [24]11845 	mov	dptr,#0x4316
      0039FE E0               [24]11846 	movx	a,@dptr
      0039FF FF               [12]11847 	mov	r7,a
                                  11848 ;	..\COMMON\easyax5043.c:2397: if( x == 0x7f || x == 0x80 )
      003A00 BF 7F 02         [24]11849 	cjne	r7,#0x7f,00151$
      003A03 80 03            [24]11850 	sjmp	00137$
      003A05                      11851 00151$:
      003A05 BF 80 09         [24]11852 	cjne	r7,#0x80,00146$
                                  11853 ;	..\COMMON\easyax5043.c:2399: radio_write8(AX5043_REG_LPOSCFREQ1, 0);
      003A08                      11854 00137$:
      003A08 90 43 16         [24]11855 	mov	dptr,#0x4316
      003A0B E4               [12]11856 	clr	a
      003A0C F0               [24]11857 	movx	@dptr,a
                                  11858 ;	..\COMMON\easyax5043.c:2400: radio_write8(AX5043_REG_LPOSCFREQ0, 0);
      003A0D 90 43 17         [24]11859 	mov	dptr,#0x4317
      003A10 F0               [24]11860 	movx	@dptr,a
      003A11                      11861 00146$:
      003A11 22               [24]11862 	ret
                                  11863 ;------------------------------------------------------------
                                  11864 ;Allocation info for local variables in function 'axradio_commsleepexit'
                                  11865 ;------------------------------------------------------------
                                  11866 ;	..\COMMON\easyax5043.c:2408: __reentrantb void axradio_commsleepexit(void) __reentrant
                                  11867 ;	-----------------------------------------
                                  11868 ;	 function axradio_commsleepexit
                                  11869 ;	-----------------------------------------
      003A12                      11870 _axradio_commsleepexit:
                                  11871 ;	..\COMMON\easyax5043.c:2410: ax5043_commsleepexit();
      003A12 02 47 11         [24]11872 	ljmp	_ax5043_commsleepexit
                                  11873 ;------------------------------------------------------------
                                  11874 ;Allocation info for local variables in function 'axradio_check_fourfsk_modulation'
                                  11875 ;------------------------------------------------------------
                                  11876 ;modulation                Allocated to registers r7 
                                  11877 ;------------------------------------------------------------
                                  11878 ;	..\COMMON\easyax5043.c:2422: uint8_t axradio_check_fourfsk_modulation(void)
                                  11879 ;	-----------------------------------------
                                  11880 ;	 function axradio_check_fourfsk_modulation
                                  11881 ;	-----------------------------------------
      003A15                      11882 _axradio_check_fourfsk_modulation:
                                  11883 ;	..\COMMON\easyax5043.c:2424: uint8_t modulation = radio_read8(AX5043_REG_MODULATION);
      003A15 90 40 10         [24]11884 	mov	dptr,#0x4010
      003A18 E0               [24]11885 	movx	a,@dptr
      003A19 FF               [12]11886 	mov	r7,a
                                  11887 ;	..\COMMON\easyax5043.c:2425: if((modulation & 0x0F) == 9)
      003A1A 53 07 0F         [24]11888 	anl	ar7,#0x0f
      003A1D BF 09 04         [24]11889 	cjne	r7,#0x09,00102$
                                  11890 ;	..\COMMON\easyax5043.c:2426: return 1;
      003A20 75 82 01         [24]11891 	mov	dpl,#0x01
      003A23 22               [24]11892 	ret
      003A24                      11893 00102$:
                                  11894 ;	..\COMMON\easyax5043.c:2428: return 0;
      003A24 75 82 00         [24]11895 	mov	dpl,#0x00
      003A27 22               [24]11896 	ret
                                  11897 ;------------------------------------------------------------
                                  11898 ;Allocation info for local variables in function 'axradio_get_transmitter_pa_type'
                                  11899 ;------------------------------------------------------------
                                  11900 ;	..\COMMON\easyax5043.c:2431: uint8_t axradio_get_transmitter_pa_type(void)
                                  11901 ;	-----------------------------------------
                                  11902 ;	 function axradio_get_transmitter_pa_type
                                  11903 ;	-----------------------------------------
      003A28                      11904 _axradio_get_transmitter_pa_type:
                                  11905 ;	..\COMMON\easyax5043.c:2433: return (radio_read8(AX5043_REG_MODCFGA) & 0x03);
      003A28 90 41 64         [24]11906 	mov	dptr,#0x4164
      003A2B E0               [24]11907 	movx	a,@dptr
      003A2C FF               [12]11908 	mov	r7,a
      003A2D 74 03            [12]11909 	mov	a,#0x03
      003A2F 5F               [12]11910 	anl	a,r7
      003A30 F5 82            [12]11911 	mov	dpl,a
      003A32 22               [24]11912 	ret
                                  11913 	.area CSEG    (CODE)
                                  11914 	.area CONST   (CODE)
                                  11915 	.area XINIT   (CODE)
      005094                      11916 __xinit__f30_saved:
      005094 3F                   11917 	.db #0x3f	; 63
      005095                      11918 __xinit__f31_saved:
      005095 F0                   11919 	.db #0xf0	; 240
      005096                      11920 __xinit__f32_saved:
      005096 3F                   11921 	.db #0x3f	; 63
      005097                      11922 __xinit__f33_saved:
      005097 F0                   11923 	.db #0xf0	; 240
      005098                      11924 __xinit__radio_lcd_display:
      005098 66 6F 75 6E 64 20 41 11925 	.ascii "found AX5043"
             58 35 30 34 33
      0050A4 0A                   11926 	.db 0x0a
      0050A5 00                   11927 	.db 0x00
      0050A6                      11928 __xinit__radio_not_found_lcd_display:
      0050A6 4E 6F 20 52 61 64 69 11929 	.ascii "No Radio"
             6F
      0050AE 0A                   11930 	.db 0x0a
      0050AF 63 68 69 70 20 66 6F 11931 	.ascii "chip found"
             75 6E 64
      0050B9 00                   11932 	.db 0x00
                                  11933 	.area CABS    (ABS,CODE)
