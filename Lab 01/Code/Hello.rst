                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module Hello
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _isprint
                                     12 	.globl _printf
                                     13 	.globl _P7_7
                                     14 	.globl _P7_6
                                     15 	.globl _P7_5
                                     16 	.globl _P7_4
                                     17 	.globl _P7_3
                                     18 	.globl _P7_2
                                     19 	.globl _P7_1
                                     20 	.globl _P7_0
                                     21 	.globl _SPIF
                                     22 	.globl _WCOL
                                     23 	.globl _MODF
                                     24 	.globl _RXOVRN
                                     25 	.globl _NSSMD1
                                     26 	.globl _NSSMD0
                                     27 	.globl _TXBMT
                                     28 	.globl _SPIEN
                                     29 	.globl _P6_7
                                     30 	.globl _P6_6
                                     31 	.globl _P6_5
                                     32 	.globl _P6_4
                                     33 	.globl _P6_3
                                     34 	.globl _P6_2
                                     35 	.globl _P6_1
                                     36 	.globl _P6_0
                                     37 	.globl _AD2EN
                                     38 	.globl _AD2TM
                                     39 	.globl _AD2INT
                                     40 	.globl _AD2BUSY
                                     41 	.globl _AD2CM2
                                     42 	.globl _AD2CM1
                                     43 	.globl _AD2CM0
                                     44 	.globl _AD2WINT
                                     45 	.globl _AD0EN
                                     46 	.globl _AD0TM
                                     47 	.globl _AD0INT
                                     48 	.globl _AD0BUSY
                                     49 	.globl _AD0CM1
                                     50 	.globl _AD0CM0
                                     51 	.globl _AD0WINT
                                     52 	.globl _AD0LJST
                                     53 	.globl _P5_7
                                     54 	.globl _P5_6
                                     55 	.globl _P5_5
                                     56 	.globl _P5_4
                                     57 	.globl _P5_3
                                     58 	.globl _P5_2
                                     59 	.globl _P5_1
                                     60 	.globl _P5_0
                                     61 	.globl _CF
                                     62 	.globl _CR
                                     63 	.globl _CCF5
                                     64 	.globl _CCF4
                                     65 	.globl _CCF3
                                     66 	.globl _CCF2
                                     67 	.globl _CCF1
                                     68 	.globl _CCF0
                                     69 	.globl _CY
                                     70 	.globl _AC
                                     71 	.globl _F0
                                     72 	.globl _RS1
                                     73 	.globl _RS0
                                     74 	.globl _OV
                                     75 	.globl _F1
                                     76 	.globl _P
                                     77 	.globl _P4_7
                                     78 	.globl _P4_6
                                     79 	.globl _P4_5
                                     80 	.globl _P4_4
                                     81 	.globl _P4_3
                                     82 	.globl _P4_2
                                     83 	.globl _P4_1
                                     84 	.globl _P4_0
                                     85 	.globl _TF4
                                     86 	.globl _EXF4
                                     87 	.globl _EXEN4
                                     88 	.globl _TR4
                                     89 	.globl _CT4
                                     90 	.globl _CPRL4
                                     91 	.globl _TF3
                                     92 	.globl _EXF3
                                     93 	.globl _EXEN3
                                     94 	.globl _TR3
                                     95 	.globl _CT3
                                     96 	.globl _CPRL3
                                     97 	.globl _TF2
                                     98 	.globl _EXF2
                                     99 	.globl _EXEN2
                                    100 	.globl _TR2
                                    101 	.globl _CT2
                                    102 	.globl _CPRL2
                                    103 	.globl _MAC0HO
                                    104 	.globl _MAC0Z
                                    105 	.globl _MAC0SO
                                    106 	.globl _MAC0N
                                    107 	.globl _BUSY
                                    108 	.globl _ENSMB
                                    109 	.globl _STA
                                    110 	.globl _STO
                                    111 	.globl _SI
                                    112 	.globl _AA
                                    113 	.globl _SMBFTE
                                    114 	.globl _SMBTOE
                                    115 	.globl _PT2
                                    116 	.globl _PS
                                    117 	.globl _PS0
                                    118 	.globl _PT1
                                    119 	.globl _PX1
                                    120 	.globl _PT0
                                    121 	.globl _PX0
                                    122 	.globl _P3_7
                                    123 	.globl _P3_6
                                    124 	.globl _P3_5
                                    125 	.globl _P3_4
                                    126 	.globl _P3_3
                                    127 	.globl _P3_2
                                    128 	.globl _P3_1
                                    129 	.globl _P3_0
                                    130 	.globl _EA
                                    131 	.globl _ET2
                                    132 	.globl _ES
                                    133 	.globl _ES0
                                    134 	.globl _ET1
                                    135 	.globl _EX1
                                    136 	.globl _ET0
                                    137 	.globl _EX0
                                    138 	.globl _P2_7
                                    139 	.globl _P2_6
                                    140 	.globl _P2_5
                                    141 	.globl _P2_4
                                    142 	.globl _P2_3
                                    143 	.globl _P2_2
                                    144 	.globl _P2_1
                                    145 	.globl _P2_0
                                    146 	.globl _S1MODE
                                    147 	.globl _MCE1
                                    148 	.globl _REN1
                                    149 	.globl _TB81
                                    150 	.globl _RB81
                                    151 	.globl _TI1
                                    152 	.globl _RI1
                                    153 	.globl _SM00
                                    154 	.globl _SM10
                                    155 	.globl _SM20
                                    156 	.globl _REN
                                    157 	.globl _REN0
                                    158 	.globl _TB80
                                    159 	.globl _RB80
                                    160 	.globl _TI
                                    161 	.globl _TI0
                                    162 	.globl _RI
                                    163 	.globl _RI0
                                    164 	.globl _P1_7
                                    165 	.globl _P1_6
                                    166 	.globl _P1_5
                                    167 	.globl _P1_4
                                    168 	.globl _P1_3
                                    169 	.globl _P1_2
                                    170 	.globl _P1_1
                                    171 	.globl _P1_0
                                    172 	.globl _FLHBUSY
                                    173 	.globl _CP1EN
                                    174 	.globl _CP1OUT
                                    175 	.globl _CP1RIF
                                    176 	.globl _CP1FIF
                                    177 	.globl _CP1HYP1
                                    178 	.globl _CP1HYP0
                                    179 	.globl _CP1HYN1
                                    180 	.globl _CP1HYN0
                                    181 	.globl _CP0EN
                                    182 	.globl _CP0OUT
                                    183 	.globl _CP0RIF
                                    184 	.globl _CP0FIF
                                    185 	.globl _CP0HYP1
                                    186 	.globl _CP0HYP0
                                    187 	.globl _CP0HYN1
                                    188 	.globl _CP0HYN0
                                    189 	.globl _TF1
                                    190 	.globl _TR1
                                    191 	.globl _TF0
                                    192 	.globl _TR0
                                    193 	.globl _IE1
                                    194 	.globl _IT1
                                    195 	.globl _IE0
                                    196 	.globl _IT0
                                    197 	.globl _P0_7
                                    198 	.globl _P0_6
                                    199 	.globl _P0_5
                                    200 	.globl _P0_4
                                    201 	.globl _P0_3
                                    202 	.globl _P0_2
                                    203 	.globl _P0_1
                                    204 	.globl _P0_0
                                    205 	.globl _MAC0RND
                                    206 	.globl _MAC0ACC
                                    207 	.globl _MAC0A
                                    208 	.globl _RCAP4
                                    209 	.globl _TMR4
                                    210 	.globl _DAC1
                                    211 	.globl _RCAP3
                                    212 	.globl _TMR3
                                    213 	.globl _PCA0CP5
                                    214 	.globl _PCA0CP4
                                    215 	.globl _PCA0CP3
                                    216 	.globl _PCA0CP2
                                    217 	.globl _PCA0CP1
                                    218 	.globl _PCA0CP0
                                    219 	.globl _PCA0
                                    220 	.globl _DAC0
                                    221 	.globl _ADC0LT
                                    222 	.globl _ADC0GT
                                    223 	.globl _ADC0
                                    224 	.globl _RCAP2
                                    225 	.globl _TMR2
                                    226 	.globl _TMR1
                                    227 	.globl _TMR0
                                    228 	.globl _P7
                                    229 	.globl _P6
                                    230 	.globl _XBR2
                                    231 	.globl _XBR1
                                    232 	.globl _XBR0
                                    233 	.globl _P5
                                    234 	.globl _P4
                                    235 	.globl _FLACL
                                    236 	.globl _P1MDIN
                                    237 	.globl _P3MDOUT
                                    238 	.globl _P2MDOUT
                                    239 	.globl _P1MDOUT
                                    240 	.globl _P0MDOUT
                                    241 	.globl _CCH0LC
                                    242 	.globl _CCH0TN
                                    243 	.globl _CCH0CN
                                    244 	.globl _P7MDOUT
                                    245 	.globl _P6MDOUT
                                    246 	.globl _P5MDOUT
                                    247 	.globl _P4MDOUT
                                    248 	.globl _CCH0MA
                                    249 	.globl _CLKSEL
                                    250 	.globl _SFRPGCN
                                    251 	.globl _PLL0FLT
                                    252 	.globl _PLL0MUL
                                    253 	.globl _PLL0DIV
                                    254 	.globl _OSCXCN
                                    255 	.globl _OSCICL
                                    256 	.globl _OSCICN
                                    257 	.globl _PLL0CN
                                    258 	.globl _FLSTAT
                                    259 	.globl _MAC0RNDH
                                    260 	.globl _MAC0RNDL
                                    261 	.globl _MAC0CF
                                    262 	.globl _MAC0AH
                                    263 	.globl _MAC0AL
                                    264 	.globl _MAC0STA
                                    265 	.globl _MAC0OVR
                                    266 	.globl _MAC0ACC3
                                    267 	.globl _MAC0ACC2
                                    268 	.globl _MAC0ACC1
                                    269 	.globl _MAC0ACC0
                                    270 	.globl _MAC0BH
                                    271 	.globl _MAC0BL
                                    272 	.globl _ADC2CN
                                    273 	.globl _TMR4H
                                    274 	.globl _TMR4L
                                    275 	.globl _RCAP4H
                                    276 	.globl _RCAP4L
                                    277 	.globl _TMR4CF
                                    278 	.globl _TMR4CN
                                    279 	.globl _ADC2LT
                                    280 	.globl _ADC2GT
                                    281 	.globl _ADC2
                                    282 	.globl _ADC2CF
                                    283 	.globl _AMX2SL
                                    284 	.globl _AMX2CF
                                    285 	.globl _CPT1MD
                                    286 	.globl _CPT1CN
                                    287 	.globl _DAC1CN
                                    288 	.globl _DAC1H
                                    289 	.globl _DAC1L
                                    290 	.globl _TMR3H
                                    291 	.globl _TMR3L
                                    292 	.globl _RCAP3H
                                    293 	.globl _RCAP3L
                                    294 	.globl _TMR3CF
                                    295 	.globl _TMR3CN
                                    296 	.globl _SBUF1
                                    297 	.globl _SCON1
                                    298 	.globl _CPT0MD
                                    299 	.globl _CPT0CN
                                    300 	.globl _PCA0CPH1
                                    301 	.globl _PCA0CPL1
                                    302 	.globl _PCA0CPH0
                                    303 	.globl _PCA0CPL0
                                    304 	.globl _PCA0H
                                    305 	.globl _PCA0L
                                    306 	.globl _SPI0CN
                                    307 	.globl _RSTSRC
                                    308 	.globl _PCA0CPH4
                                    309 	.globl _PCA0CPL4
                                    310 	.globl _PCA0CPH3
                                    311 	.globl _PCA0CPL3
                                    312 	.globl _PCA0CPH2
                                    313 	.globl _PCA0CPL2
                                    314 	.globl _ADC0CN
                                    315 	.globl _PCA0CPH5
                                    316 	.globl _PCA0CPL5
                                    317 	.globl _PCA0CPM5
                                    318 	.globl _PCA0CPM4
                                    319 	.globl _PCA0CPM3
                                    320 	.globl _PCA0CPM2
                                    321 	.globl _PCA0CPM1
                                    322 	.globl _PCA0CPM0
                                    323 	.globl _PCA0MD
                                    324 	.globl _PCA0CN
                                    325 	.globl _DAC0CN
                                    326 	.globl _DAC0H
                                    327 	.globl _DAC0L
                                    328 	.globl _REF0CN
                                    329 	.globl _SMB0CR
                                    330 	.globl _TH2
                                    331 	.globl _TMR2H
                                    332 	.globl _TL2
                                    333 	.globl _TMR2L
                                    334 	.globl _RCAP2H
                                    335 	.globl _RCAP2L
                                    336 	.globl _TMR2CF
                                    337 	.globl _TMR2CN
                                    338 	.globl _ADC0LTH
                                    339 	.globl _ADC0LTL
                                    340 	.globl _ADC0GTH
                                    341 	.globl _ADC0GTL
                                    342 	.globl _SMB0ADR
                                    343 	.globl _SMB0DAT
                                    344 	.globl _SMB0STA
                                    345 	.globl _SMB0CN
                                    346 	.globl _ADC0H
                                    347 	.globl _ADC0L
                                    348 	.globl _ADC0CF
                                    349 	.globl _AMX0SL
                                    350 	.globl _AMX0CF
                                    351 	.globl _SADEN0
                                    352 	.globl _FLSCL
                                    353 	.globl _SADDR0
                                    354 	.globl _EMI0CF
                                    355 	.globl __XPAGE
                                    356 	.globl _EMI0CN
                                    357 	.globl _EMI0TC
                                    358 	.globl _SPI0CKR
                                    359 	.globl _SPI0DAT
                                    360 	.globl _SPI0CFG
                                    361 	.globl _SBUF
                                    362 	.globl _SBUF0
                                    363 	.globl _SCON
                                    364 	.globl _SCON0
                                    365 	.globl _SSTA0
                                    366 	.globl _PSCTL
                                    367 	.globl _CKCON
                                    368 	.globl _TH1
                                    369 	.globl _TH0
                                    370 	.globl _TL1
                                    371 	.globl _TL0
                                    372 	.globl _TMOD
                                    373 	.globl _TCON
                                    374 	.globl _WDTCN
                                    375 	.globl _EIP2
                                    376 	.globl _EIP1
                                    377 	.globl _B
                                    378 	.globl _EIE2
                                    379 	.globl _EIE1
                                    380 	.globl _ACC
                                    381 	.globl _PSW
                                    382 	.globl _IP
                                    383 	.globl _PSBANK
                                    384 	.globl _P3
                                    385 	.globl _IE
                                    386 	.globl _P2
                                    387 	.globl _P1
                                    388 	.globl _PCON
                                    389 	.globl _SFRLAST
                                    390 	.globl _SFRNEXT
                                    391 	.globl _SFRPAGE
                                    392 	.globl _DPH
                                    393 	.globl _DPL
                                    394 	.globl _SP
                                    395 	.globl _P0
                                    396 	.globl _putchar
                                    397 	.globl _getchar
                                    398 	.globl _main
                                    399 	.globl _SYSCLK_INIT
                                    400 	.globl _PORT_INIT
                                    401 	.globl _UART0_INIT
                                    402 ;--------------------------------------------------------
                                    403 ; special function registers
                                    404 ;--------------------------------------------------------
                                    405 	.area RSEG    (ABS,DATA)
      000000                        406 	.org 0x0000
                           000080   407 G$P0$0$0 == 0x0080
                           000080   408 _P0	=	0x0080
                           000081   409 G$SP$0$0 == 0x0081
                           000081   410 _SP	=	0x0081
                           000082   411 G$DPL$0$0 == 0x0082
                           000082   412 _DPL	=	0x0082
                           000083   413 G$DPH$0$0 == 0x0083
                           000083   414 _DPH	=	0x0083
                           000084   415 G$SFRPAGE$0$0 == 0x0084
                           000084   416 _SFRPAGE	=	0x0084
                           000085   417 G$SFRNEXT$0$0 == 0x0085
                           000085   418 _SFRNEXT	=	0x0085
                           000086   419 G$SFRLAST$0$0 == 0x0086
                           000086   420 _SFRLAST	=	0x0086
                           000087   421 G$PCON$0$0 == 0x0087
                           000087   422 _PCON	=	0x0087
                           000090   423 G$P1$0$0 == 0x0090
                           000090   424 _P1	=	0x0090
                           0000A0   425 G$P2$0$0 == 0x00a0
                           0000A0   426 _P2	=	0x00a0
                           0000A8   427 G$IE$0$0 == 0x00a8
                           0000A8   428 _IE	=	0x00a8
                           0000B0   429 G$P3$0$0 == 0x00b0
                           0000B0   430 _P3	=	0x00b0
                           0000B1   431 G$PSBANK$0$0 == 0x00b1
                           0000B1   432 _PSBANK	=	0x00b1
                           0000B8   433 G$IP$0$0 == 0x00b8
                           0000B8   434 _IP	=	0x00b8
                           0000D0   435 G$PSW$0$0 == 0x00d0
                           0000D0   436 _PSW	=	0x00d0
                           0000E0   437 G$ACC$0$0 == 0x00e0
                           0000E0   438 _ACC	=	0x00e0
                           0000E6   439 G$EIE1$0$0 == 0x00e6
                           0000E6   440 _EIE1	=	0x00e6
                           0000E7   441 G$EIE2$0$0 == 0x00e7
                           0000E7   442 _EIE2	=	0x00e7
                           0000F0   443 G$B$0$0 == 0x00f0
                           0000F0   444 _B	=	0x00f0
                           0000F6   445 G$EIP1$0$0 == 0x00f6
                           0000F6   446 _EIP1	=	0x00f6
                           0000F7   447 G$EIP2$0$0 == 0x00f7
                           0000F7   448 _EIP2	=	0x00f7
                           0000FF   449 G$WDTCN$0$0 == 0x00ff
                           0000FF   450 _WDTCN	=	0x00ff
                           000088   451 G$TCON$0$0 == 0x0088
                           000088   452 _TCON	=	0x0088
                           000089   453 G$TMOD$0$0 == 0x0089
                           000089   454 _TMOD	=	0x0089
                           00008A   455 G$TL0$0$0 == 0x008a
                           00008A   456 _TL0	=	0x008a
                           00008B   457 G$TL1$0$0 == 0x008b
                           00008B   458 _TL1	=	0x008b
                           00008C   459 G$TH0$0$0 == 0x008c
                           00008C   460 _TH0	=	0x008c
                           00008D   461 G$TH1$0$0 == 0x008d
                           00008D   462 _TH1	=	0x008d
                           00008E   463 G$CKCON$0$0 == 0x008e
                           00008E   464 _CKCON	=	0x008e
                           00008F   465 G$PSCTL$0$0 == 0x008f
                           00008F   466 _PSCTL	=	0x008f
                           000091   467 G$SSTA0$0$0 == 0x0091
                           000091   468 _SSTA0	=	0x0091
                           000098   469 G$SCON0$0$0 == 0x0098
                           000098   470 _SCON0	=	0x0098
                           000098   471 G$SCON$0$0 == 0x0098
                           000098   472 _SCON	=	0x0098
                           000099   473 G$SBUF0$0$0 == 0x0099
                           000099   474 _SBUF0	=	0x0099
                           000099   475 G$SBUF$0$0 == 0x0099
                           000099   476 _SBUF	=	0x0099
                           00009A   477 G$SPI0CFG$0$0 == 0x009a
                           00009A   478 _SPI0CFG	=	0x009a
                           00009B   479 G$SPI0DAT$0$0 == 0x009b
                           00009B   480 _SPI0DAT	=	0x009b
                           00009D   481 G$SPI0CKR$0$0 == 0x009d
                           00009D   482 _SPI0CKR	=	0x009d
                           0000A1   483 G$EMI0TC$0$0 == 0x00a1
                           0000A1   484 _EMI0TC	=	0x00a1
                           0000A2   485 G$EMI0CN$0$0 == 0x00a2
                           0000A2   486 _EMI0CN	=	0x00a2
                           0000A2   487 G$_XPAGE$0$0 == 0x00a2
                           0000A2   488 __XPAGE	=	0x00a2
                           0000A3   489 G$EMI0CF$0$0 == 0x00a3
                           0000A3   490 _EMI0CF	=	0x00a3
                           0000A9   491 G$SADDR0$0$0 == 0x00a9
                           0000A9   492 _SADDR0	=	0x00a9
                           0000B7   493 G$FLSCL$0$0 == 0x00b7
                           0000B7   494 _FLSCL	=	0x00b7
                           0000B9   495 G$SADEN0$0$0 == 0x00b9
                           0000B9   496 _SADEN0	=	0x00b9
                           0000BA   497 G$AMX0CF$0$0 == 0x00ba
                           0000BA   498 _AMX0CF	=	0x00ba
                           0000BB   499 G$AMX0SL$0$0 == 0x00bb
                           0000BB   500 _AMX0SL	=	0x00bb
                           0000BC   501 G$ADC0CF$0$0 == 0x00bc
                           0000BC   502 _ADC0CF	=	0x00bc
                           0000BE   503 G$ADC0L$0$0 == 0x00be
                           0000BE   504 _ADC0L	=	0x00be
                           0000BF   505 G$ADC0H$0$0 == 0x00bf
                           0000BF   506 _ADC0H	=	0x00bf
                           0000C0   507 G$SMB0CN$0$0 == 0x00c0
                           0000C0   508 _SMB0CN	=	0x00c0
                           0000C1   509 G$SMB0STA$0$0 == 0x00c1
                           0000C1   510 _SMB0STA	=	0x00c1
                           0000C2   511 G$SMB0DAT$0$0 == 0x00c2
                           0000C2   512 _SMB0DAT	=	0x00c2
                           0000C3   513 G$SMB0ADR$0$0 == 0x00c3
                           0000C3   514 _SMB0ADR	=	0x00c3
                           0000C4   515 G$ADC0GTL$0$0 == 0x00c4
                           0000C4   516 _ADC0GTL	=	0x00c4
                           0000C5   517 G$ADC0GTH$0$0 == 0x00c5
                           0000C5   518 _ADC0GTH	=	0x00c5
                           0000C6   519 G$ADC0LTL$0$0 == 0x00c6
                           0000C6   520 _ADC0LTL	=	0x00c6
                           0000C7   521 G$ADC0LTH$0$0 == 0x00c7
                           0000C7   522 _ADC0LTH	=	0x00c7
                           0000C8   523 G$TMR2CN$0$0 == 0x00c8
                           0000C8   524 _TMR2CN	=	0x00c8
                           0000C9   525 G$TMR2CF$0$0 == 0x00c9
                           0000C9   526 _TMR2CF	=	0x00c9
                           0000CA   527 G$RCAP2L$0$0 == 0x00ca
                           0000CA   528 _RCAP2L	=	0x00ca
                           0000CB   529 G$RCAP2H$0$0 == 0x00cb
                           0000CB   530 _RCAP2H	=	0x00cb
                           0000CC   531 G$TMR2L$0$0 == 0x00cc
                           0000CC   532 _TMR2L	=	0x00cc
                           0000CC   533 G$TL2$0$0 == 0x00cc
                           0000CC   534 _TL2	=	0x00cc
                           0000CD   535 G$TMR2H$0$0 == 0x00cd
                           0000CD   536 _TMR2H	=	0x00cd
                           0000CD   537 G$TH2$0$0 == 0x00cd
                           0000CD   538 _TH2	=	0x00cd
                           0000CF   539 G$SMB0CR$0$0 == 0x00cf
                           0000CF   540 _SMB0CR	=	0x00cf
                           0000D1   541 G$REF0CN$0$0 == 0x00d1
                           0000D1   542 _REF0CN	=	0x00d1
                           0000D2   543 G$DAC0L$0$0 == 0x00d2
                           0000D2   544 _DAC0L	=	0x00d2
                           0000D3   545 G$DAC0H$0$0 == 0x00d3
                           0000D3   546 _DAC0H	=	0x00d3
                           0000D4   547 G$DAC0CN$0$0 == 0x00d4
                           0000D4   548 _DAC0CN	=	0x00d4
                           0000D8   549 G$PCA0CN$0$0 == 0x00d8
                           0000D8   550 _PCA0CN	=	0x00d8
                           0000D9   551 G$PCA0MD$0$0 == 0x00d9
                           0000D9   552 _PCA0MD	=	0x00d9
                           0000DA   553 G$PCA0CPM0$0$0 == 0x00da
                           0000DA   554 _PCA0CPM0	=	0x00da
                           0000DB   555 G$PCA0CPM1$0$0 == 0x00db
                           0000DB   556 _PCA0CPM1	=	0x00db
                           0000DC   557 G$PCA0CPM2$0$0 == 0x00dc
                           0000DC   558 _PCA0CPM2	=	0x00dc
                           0000DD   559 G$PCA0CPM3$0$0 == 0x00dd
                           0000DD   560 _PCA0CPM3	=	0x00dd
                           0000DE   561 G$PCA0CPM4$0$0 == 0x00de
                           0000DE   562 _PCA0CPM4	=	0x00de
                           0000DF   563 G$PCA0CPM5$0$0 == 0x00df
                           0000DF   564 _PCA0CPM5	=	0x00df
                           0000E1   565 G$PCA0CPL5$0$0 == 0x00e1
                           0000E1   566 _PCA0CPL5	=	0x00e1
                           0000E2   567 G$PCA0CPH5$0$0 == 0x00e2
                           0000E2   568 _PCA0CPH5	=	0x00e2
                           0000E8   569 G$ADC0CN$0$0 == 0x00e8
                           0000E8   570 _ADC0CN	=	0x00e8
                           0000E9   571 G$PCA0CPL2$0$0 == 0x00e9
                           0000E9   572 _PCA0CPL2	=	0x00e9
                           0000EA   573 G$PCA0CPH2$0$0 == 0x00ea
                           0000EA   574 _PCA0CPH2	=	0x00ea
                           0000EB   575 G$PCA0CPL3$0$0 == 0x00eb
                           0000EB   576 _PCA0CPL3	=	0x00eb
                           0000EC   577 G$PCA0CPH3$0$0 == 0x00ec
                           0000EC   578 _PCA0CPH3	=	0x00ec
                           0000ED   579 G$PCA0CPL4$0$0 == 0x00ed
                           0000ED   580 _PCA0CPL4	=	0x00ed
                           0000EE   581 G$PCA0CPH4$0$0 == 0x00ee
                           0000EE   582 _PCA0CPH4	=	0x00ee
                           0000EF   583 G$RSTSRC$0$0 == 0x00ef
                           0000EF   584 _RSTSRC	=	0x00ef
                           0000F8   585 G$SPI0CN$0$0 == 0x00f8
                           0000F8   586 _SPI0CN	=	0x00f8
                           0000F9   587 G$PCA0L$0$0 == 0x00f9
                           0000F9   588 _PCA0L	=	0x00f9
                           0000FA   589 G$PCA0H$0$0 == 0x00fa
                           0000FA   590 _PCA0H	=	0x00fa
                           0000FB   591 G$PCA0CPL0$0$0 == 0x00fb
                           0000FB   592 _PCA0CPL0	=	0x00fb
                           0000FC   593 G$PCA0CPH0$0$0 == 0x00fc
                           0000FC   594 _PCA0CPH0	=	0x00fc
                           0000FD   595 G$PCA0CPL1$0$0 == 0x00fd
                           0000FD   596 _PCA0CPL1	=	0x00fd
                           0000FE   597 G$PCA0CPH1$0$0 == 0x00fe
                           0000FE   598 _PCA0CPH1	=	0x00fe
                           000088   599 G$CPT0CN$0$0 == 0x0088
                           000088   600 _CPT0CN	=	0x0088
                           000089   601 G$CPT0MD$0$0 == 0x0089
                           000089   602 _CPT0MD	=	0x0089
                           000098   603 G$SCON1$0$0 == 0x0098
                           000098   604 _SCON1	=	0x0098
                           000099   605 G$SBUF1$0$0 == 0x0099
                           000099   606 _SBUF1	=	0x0099
                           0000C8   607 G$TMR3CN$0$0 == 0x00c8
                           0000C8   608 _TMR3CN	=	0x00c8
                           0000C9   609 G$TMR3CF$0$0 == 0x00c9
                           0000C9   610 _TMR3CF	=	0x00c9
                           0000CA   611 G$RCAP3L$0$0 == 0x00ca
                           0000CA   612 _RCAP3L	=	0x00ca
                           0000CB   613 G$RCAP3H$0$0 == 0x00cb
                           0000CB   614 _RCAP3H	=	0x00cb
                           0000CC   615 G$TMR3L$0$0 == 0x00cc
                           0000CC   616 _TMR3L	=	0x00cc
                           0000CD   617 G$TMR3H$0$0 == 0x00cd
                           0000CD   618 _TMR3H	=	0x00cd
                           0000D2   619 G$DAC1L$0$0 == 0x00d2
                           0000D2   620 _DAC1L	=	0x00d2
                           0000D3   621 G$DAC1H$0$0 == 0x00d3
                           0000D3   622 _DAC1H	=	0x00d3
                           0000D4   623 G$DAC1CN$0$0 == 0x00d4
                           0000D4   624 _DAC1CN	=	0x00d4
                           000088   625 G$CPT1CN$0$0 == 0x0088
                           000088   626 _CPT1CN	=	0x0088
                           000089   627 G$CPT1MD$0$0 == 0x0089
                           000089   628 _CPT1MD	=	0x0089
                           0000BA   629 G$AMX2CF$0$0 == 0x00ba
                           0000BA   630 _AMX2CF	=	0x00ba
                           0000BB   631 G$AMX2SL$0$0 == 0x00bb
                           0000BB   632 _AMX2SL	=	0x00bb
                           0000BC   633 G$ADC2CF$0$0 == 0x00bc
                           0000BC   634 _ADC2CF	=	0x00bc
                           0000BE   635 G$ADC2$0$0 == 0x00be
                           0000BE   636 _ADC2	=	0x00be
                           0000C4   637 G$ADC2GT$0$0 == 0x00c4
                           0000C4   638 _ADC2GT	=	0x00c4
                           0000C6   639 G$ADC2LT$0$0 == 0x00c6
                           0000C6   640 _ADC2LT	=	0x00c6
                           0000C8   641 G$TMR4CN$0$0 == 0x00c8
                           0000C8   642 _TMR4CN	=	0x00c8
                           0000C9   643 G$TMR4CF$0$0 == 0x00c9
                           0000C9   644 _TMR4CF	=	0x00c9
                           0000CA   645 G$RCAP4L$0$0 == 0x00ca
                           0000CA   646 _RCAP4L	=	0x00ca
                           0000CB   647 G$RCAP4H$0$0 == 0x00cb
                           0000CB   648 _RCAP4H	=	0x00cb
                           0000CC   649 G$TMR4L$0$0 == 0x00cc
                           0000CC   650 _TMR4L	=	0x00cc
                           0000CD   651 G$TMR4H$0$0 == 0x00cd
                           0000CD   652 _TMR4H	=	0x00cd
                           0000E8   653 G$ADC2CN$0$0 == 0x00e8
                           0000E8   654 _ADC2CN	=	0x00e8
                           000091   655 G$MAC0BL$0$0 == 0x0091
                           000091   656 _MAC0BL	=	0x0091
                           000092   657 G$MAC0BH$0$0 == 0x0092
                           000092   658 _MAC0BH	=	0x0092
                           000093   659 G$MAC0ACC0$0$0 == 0x0093
                           000093   660 _MAC0ACC0	=	0x0093
                           000094   661 G$MAC0ACC1$0$0 == 0x0094
                           000094   662 _MAC0ACC1	=	0x0094
                           000095   663 G$MAC0ACC2$0$0 == 0x0095
                           000095   664 _MAC0ACC2	=	0x0095
                           000096   665 G$MAC0ACC3$0$0 == 0x0096
                           000096   666 _MAC0ACC3	=	0x0096
                           000097   667 G$MAC0OVR$0$0 == 0x0097
                           000097   668 _MAC0OVR	=	0x0097
                           0000C0   669 G$MAC0STA$0$0 == 0x00c0
                           0000C0   670 _MAC0STA	=	0x00c0
                           0000C1   671 G$MAC0AL$0$0 == 0x00c1
                           0000C1   672 _MAC0AL	=	0x00c1
                           0000C2   673 G$MAC0AH$0$0 == 0x00c2
                           0000C2   674 _MAC0AH	=	0x00c2
                           0000C3   675 G$MAC0CF$0$0 == 0x00c3
                           0000C3   676 _MAC0CF	=	0x00c3
                           0000CE   677 G$MAC0RNDL$0$0 == 0x00ce
                           0000CE   678 _MAC0RNDL	=	0x00ce
                           0000CF   679 G$MAC0RNDH$0$0 == 0x00cf
                           0000CF   680 _MAC0RNDH	=	0x00cf
                           000088   681 G$FLSTAT$0$0 == 0x0088
                           000088   682 _FLSTAT	=	0x0088
                           000089   683 G$PLL0CN$0$0 == 0x0089
                           000089   684 _PLL0CN	=	0x0089
                           00008A   685 G$OSCICN$0$0 == 0x008a
                           00008A   686 _OSCICN	=	0x008a
                           00008B   687 G$OSCICL$0$0 == 0x008b
                           00008B   688 _OSCICL	=	0x008b
                           00008C   689 G$OSCXCN$0$0 == 0x008c
                           00008C   690 _OSCXCN	=	0x008c
                           00008D   691 G$PLL0DIV$0$0 == 0x008d
                           00008D   692 _PLL0DIV	=	0x008d
                           00008E   693 G$PLL0MUL$0$0 == 0x008e
                           00008E   694 _PLL0MUL	=	0x008e
                           00008F   695 G$PLL0FLT$0$0 == 0x008f
                           00008F   696 _PLL0FLT	=	0x008f
                           000096   697 G$SFRPGCN$0$0 == 0x0096
                           000096   698 _SFRPGCN	=	0x0096
                           000097   699 G$CLKSEL$0$0 == 0x0097
                           000097   700 _CLKSEL	=	0x0097
                           00009A   701 G$CCH0MA$0$0 == 0x009a
                           00009A   702 _CCH0MA	=	0x009a
                           00009C   703 G$P4MDOUT$0$0 == 0x009c
                           00009C   704 _P4MDOUT	=	0x009c
                           00009D   705 G$P5MDOUT$0$0 == 0x009d
                           00009D   706 _P5MDOUT	=	0x009d
                           00009E   707 G$P6MDOUT$0$0 == 0x009e
                           00009E   708 _P6MDOUT	=	0x009e
                           00009F   709 G$P7MDOUT$0$0 == 0x009f
                           00009F   710 _P7MDOUT	=	0x009f
                           0000A1   711 G$CCH0CN$0$0 == 0x00a1
                           0000A1   712 _CCH0CN	=	0x00a1
                           0000A2   713 G$CCH0TN$0$0 == 0x00a2
                           0000A2   714 _CCH0TN	=	0x00a2
                           0000A3   715 G$CCH0LC$0$0 == 0x00a3
                           0000A3   716 _CCH0LC	=	0x00a3
                           0000A4   717 G$P0MDOUT$0$0 == 0x00a4
                           0000A4   718 _P0MDOUT	=	0x00a4
                           0000A5   719 G$P1MDOUT$0$0 == 0x00a5
                           0000A5   720 _P1MDOUT	=	0x00a5
                           0000A6   721 G$P2MDOUT$0$0 == 0x00a6
                           0000A6   722 _P2MDOUT	=	0x00a6
                           0000A7   723 G$P3MDOUT$0$0 == 0x00a7
                           0000A7   724 _P3MDOUT	=	0x00a7
                           0000AD   725 G$P1MDIN$0$0 == 0x00ad
                           0000AD   726 _P1MDIN	=	0x00ad
                           0000B7   727 G$FLACL$0$0 == 0x00b7
                           0000B7   728 _FLACL	=	0x00b7
                           0000C8   729 G$P4$0$0 == 0x00c8
                           0000C8   730 _P4	=	0x00c8
                           0000D8   731 G$P5$0$0 == 0x00d8
                           0000D8   732 _P5	=	0x00d8
                           0000E1   733 G$XBR0$0$0 == 0x00e1
                           0000E1   734 _XBR0	=	0x00e1
                           0000E2   735 G$XBR1$0$0 == 0x00e2
                           0000E2   736 _XBR1	=	0x00e2
                           0000E3   737 G$XBR2$0$0 == 0x00e3
                           0000E3   738 _XBR2	=	0x00e3
                           0000E8   739 G$P6$0$0 == 0x00e8
                           0000E8   740 _P6	=	0x00e8
                           0000F8   741 G$P7$0$0 == 0x00f8
                           0000F8   742 _P7	=	0x00f8
                           008C8A   743 G$TMR0$0$0 == 0x8c8a
                           008C8A   744 _TMR0	=	0x8c8a
                           008D8B   745 G$TMR1$0$0 == 0x8d8b
                           008D8B   746 _TMR1	=	0x8d8b
                           00CDCC   747 G$TMR2$0$0 == 0xcdcc
                           00CDCC   748 _TMR2	=	0xcdcc
                           00CBCA   749 G$RCAP2$0$0 == 0xcbca
                           00CBCA   750 _RCAP2	=	0xcbca
                           00BFBE   751 G$ADC0$0$0 == 0xbfbe
                           00BFBE   752 _ADC0	=	0xbfbe
                           00C5C4   753 G$ADC0GT$0$0 == 0xc5c4
                           00C5C4   754 _ADC0GT	=	0xc5c4
                           00C7C6   755 G$ADC0LT$0$0 == 0xc7c6
                           00C7C6   756 _ADC0LT	=	0xc7c6
                           00D3D2   757 G$DAC0$0$0 == 0xd3d2
                           00D3D2   758 _DAC0	=	0xd3d2
                           00FAF9   759 G$PCA0$0$0 == 0xfaf9
                           00FAF9   760 _PCA0	=	0xfaf9
                           00FCFB   761 G$PCA0CP0$0$0 == 0xfcfb
                           00FCFB   762 _PCA0CP0	=	0xfcfb
                           00FEFD   763 G$PCA0CP1$0$0 == 0xfefd
                           00FEFD   764 _PCA0CP1	=	0xfefd
                           00EAE9   765 G$PCA0CP2$0$0 == 0xeae9
                           00EAE9   766 _PCA0CP2	=	0xeae9
                           00ECEB   767 G$PCA0CP3$0$0 == 0xeceb
                           00ECEB   768 _PCA0CP3	=	0xeceb
                           00EEED   769 G$PCA0CP4$0$0 == 0xeeed
                           00EEED   770 _PCA0CP4	=	0xeeed
                           00E2E1   771 G$PCA0CP5$0$0 == 0xe2e1
                           00E2E1   772 _PCA0CP5	=	0xe2e1
                           00CDCC   773 G$TMR3$0$0 == 0xcdcc
                           00CDCC   774 _TMR3	=	0xcdcc
                           00CBCA   775 G$RCAP3$0$0 == 0xcbca
                           00CBCA   776 _RCAP3	=	0xcbca
                           00D3D2   777 G$DAC1$0$0 == 0xd3d2
                           00D3D2   778 _DAC1	=	0xd3d2
                           00CDCC   779 G$TMR4$0$0 == 0xcdcc
                           00CDCC   780 _TMR4	=	0xcdcc
                           00CBCA   781 G$RCAP4$0$0 == 0xcbca
                           00CBCA   782 _RCAP4	=	0xcbca
                           00C2C1   783 G$MAC0A$0$0 == 0xc2c1
                           00C2C1   784 _MAC0A	=	0xc2c1
                           96959493   785 G$MAC0ACC$0$0 == 0x96959493
                           96959493   786 _MAC0ACC	=	0x96959493
                           00CFCE   787 G$MAC0RND$0$0 == 0xcfce
                           00CFCE   788 _MAC0RND	=	0xcfce
                                    789 ;--------------------------------------------------------
                                    790 ; special function bits
                                    791 ;--------------------------------------------------------
                                    792 	.area RSEG    (ABS,DATA)
      000000                        793 	.org 0x0000
                           000080   794 G$P0_0$0$0 == 0x0080
                           000080   795 _P0_0	=	0x0080
                           000081   796 G$P0_1$0$0 == 0x0081
                           000081   797 _P0_1	=	0x0081
                           000082   798 G$P0_2$0$0 == 0x0082
                           000082   799 _P0_2	=	0x0082
                           000083   800 G$P0_3$0$0 == 0x0083
                           000083   801 _P0_3	=	0x0083
                           000084   802 G$P0_4$0$0 == 0x0084
                           000084   803 _P0_4	=	0x0084
                           000085   804 G$P0_5$0$0 == 0x0085
                           000085   805 _P0_5	=	0x0085
                           000086   806 G$P0_6$0$0 == 0x0086
                           000086   807 _P0_6	=	0x0086
                           000087   808 G$P0_7$0$0 == 0x0087
                           000087   809 _P0_7	=	0x0087
                           000088   810 G$IT0$0$0 == 0x0088
                           000088   811 _IT0	=	0x0088
                           000089   812 G$IE0$0$0 == 0x0089
                           000089   813 _IE0	=	0x0089
                           00008A   814 G$IT1$0$0 == 0x008a
                           00008A   815 _IT1	=	0x008a
                           00008B   816 G$IE1$0$0 == 0x008b
                           00008B   817 _IE1	=	0x008b
                           00008C   818 G$TR0$0$0 == 0x008c
                           00008C   819 _TR0	=	0x008c
                           00008D   820 G$TF0$0$0 == 0x008d
                           00008D   821 _TF0	=	0x008d
                           00008E   822 G$TR1$0$0 == 0x008e
                           00008E   823 _TR1	=	0x008e
                           00008F   824 G$TF1$0$0 == 0x008f
                           00008F   825 _TF1	=	0x008f
                           000088   826 G$CP0HYN0$0$0 == 0x0088
                           000088   827 _CP0HYN0	=	0x0088
                           000089   828 G$CP0HYN1$0$0 == 0x0089
                           000089   829 _CP0HYN1	=	0x0089
                           00008A   830 G$CP0HYP0$0$0 == 0x008a
                           00008A   831 _CP0HYP0	=	0x008a
                           00008B   832 G$CP0HYP1$0$0 == 0x008b
                           00008B   833 _CP0HYP1	=	0x008b
                           00008C   834 G$CP0FIF$0$0 == 0x008c
                           00008C   835 _CP0FIF	=	0x008c
                           00008D   836 G$CP0RIF$0$0 == 0x008d
                           00008D   837 _CP0RIF	=	0x008d
                           00008E   838 G$CP0OUT$0$0 == 0x008e
                           00008E   839 _CP0OUT	=	0x008e
                           00008F   840 G$CP0EN$0$0 == 0x008f
                           00008F   841 _CP0EN	=	0x008f
                           000088   842 G$CP1HYN0$0$0 == 0x0088
                           000088   843 _CP1HYN0	=	0x0088
                           000089   844 G$CP1HYN1$0$0 == 0x0089
                           000089   845 _CP1HYN1	=	0x0089
                           00008A   846 G$CP1HYP0$0$0 == 0x008a
                           00008A   847 _CP1HYP0	=	0x008a
                           00008B   848 G$CP1HYP1$0$0 == 0x008b
                           00008B   849 _CP1HYP1	=	0x008b
                           00008C   850 G$CP1FIF$0$0 == 0x008c
                           00008C   851 _CP1FIF	=	0x008c
                           00008D   852 G$CP1RIF$0$0 == 0x008d
                           00008D   853 _CP1RIF	=	0x008d
                           00008E   854 G$CP1OUT$0$0 == 0x008e
                           00008E   855 _CP1OUT	=	0x008e
                           00008F   856 G$CP1EN$0$0 == 0x008f
                           00008F   857 _CP1EN	=	0x008f
                           000088   858 G$FLHBUSY$0$0 == 0x0088
                           000088   859 _FLHBUSY	=	0x0088
                           000090   860 G$P1_0$0$0 == 0x0090
                           000090   861 _P1_0	=	0x0090
                           000091   862 G$P1_1$0$0 == 0x0091
                           000091   863 _P1_1	=	0x0091
                           000092   864 G$P1_2$0$0 == 0x0092
                           000092   865 _P1_2	=	0x0092
                           000093   866 G$P1_3$0$0 == 0x0093
                           000093   867 _P1_3	=	0x0093
                           000094   868 G$P1_4$0$0 == 0x0094
                           000094   869 _P1_4	=	0x0094
                           000095   870 G$P1_5$0$0 == 0x0095
                           000095   871 _P1_5	=	0x0095
                           000096   872 G$P1_6$0$0 == 0x0096
                           000096   873 _P1_6	=	0x0096
                           000097   874 G$P1_7$0$0 == 0x0097
                           000097   875 _P1_7	=	0x0097
                           000098   876 G$RI0$0$0 == 0x0098
                           000098   877 _RI0	=	0x0098
                           000098   878 G$RI$0$0 == 0x0098
                           000098   879 _RI	=	0x0098
                           000099   880 G$TI0$0$0 == 0x0099
                           000099   881 _TI0	=	0x0099
                           000099   882 G$TI$0$0 == 0x0099
                           000099   883 _TI	=	0x0099
                           00009A   884 G$RB80$0$0 == 0x009a
                           00009A   885 _RB80	=	0x009a
                           00009B   886 G$TB80$0$0 == 0x009b
                           00009B   887 _TB80	=	0x009b
                           00009C   888 G$REN0$0$0 == 0x009c
                           00009C   889 _REN0	=	0x009c
                           00009C   890 G$REN$0$0 == 0x009c
                           00009C   891 _REN	=	0x009c
                           00009D   892 G$SM20$0$0 == 0x009d
                           00009D   893 _SM20	=	0x009d
                           00009E   894 G$SM10$0$0 == 0x009e
                           00009E   895 _SM10	=	0x009e
                           00009F   896 G$SM00$0$0 == 0x009f
                           00009F   897 _SM00	=	0x009f
                           000098   898 G$RI1$0$0 == 0x0098
                           000098   899 _RI1	=	0x0098
                           000099   900 G$TI1$0$0 == 0x0099
                           000099   901 _TI1	=	0x0099
                           00009A   902 G$RB81$0$0 == 0x009a
                           00009A   903 _RB81	=	0x009a
                           00009B   904 G$TB81$0$0 == 0x009b
                           00009B   905 _TB81	=	0x009b
                           00009C   906 G$REN1$0$0 == 0x009c
                           00009C   907 _REN1	=	0x009c
                           00009D   908 G$MCE1$0$0 == 0x009d
                           00009D   909 _MCE1	=	0x009d
                           00009F   910 G$S1MODE$0$0 == 0x009f
                           00009F   911 _S1MODE	=	0x009f
                           0000A0   912 G$P2_0$0$0 == 0x00a0
                           0000A0   913 _P2_0	=	0x00a0
                           0000A1   914 G$P2_1$0$0 == 0x00a1
                           0000A1   915 _P2_1	=	0x00a1
                           0000A2   916 G$P2_2$0$0 == 0x00a2
                           0000A2   917 _P2_2	=	0x00a2
                           0000A3   918 G$P2_3$0$0 == 0x00a3
                           0000A3   919 _P2_3	=	0x00a3
                           0000A4   920 G$P2_4$0$0 == 0x00a4
                           0000A4   921 _P2_4	=	0x00a4
                           0000A5   922 G$P2_5$0$0 == 0x00a5
                           0000A5   923 _P2_5	=	0x00a5
                           0000A6   924 G$P2_6$0$0 == 0x00a6
                           0000A6   925 _P2_6	=	0x00a6
                           0000A7   926 G$P2_7$0$0 == 0x00a7
                           0000A7   927 _P2_7	=	0x00a7
                           0000A8   928 G$EX0$0$0 == 0x00a8
                           0000A8   929 _EX0	=	0x00a8
                           0000A9   930 G$ET0$0$0 == 0x00a9
                           0000A9   931 _ET0	=	0x00a9
                           0000AA   932 G$EX1$0$0 == 0x00aa
                           0000AA   933 _EX1	=	0x00aa
                           0000AB   934 G$ET1$0$0 == 0x00ab
                           0000AB   935 _ET1	=	0x00ab
                           0000AC   936 G$ES0$0$0 == 0x00ac
                           0000AC   937 _ES0	=	0x00ac
                           0000AC   938 G$ES$0$0 == 0x00ac
                           0000AC   939 _ES	=	0x00ac
                           0000AD   940 G$ET2$0$0 == 0x00ad
                           0000AD   941 _ET2	=	0x00ad
                           0000AF   942 G$EA$0$0 == 0x00af
                           0000AF   943 _EA	=	0x00af
                           0000B0   944 G$P3_0$0$0 == 0x00b0
                           0000B0   945 _P3_0	=	0x00b0
                           0000B1   946 G$P3_1$0$0 == 0x00b1
                           0000B1   947 _P3_1	=	0x00b1
                           0000B2   948 G$P3_2$0$0 == 0x00b2
                           0000B2   949 _P3_2	=	0x00b2
                           0000B3   950 G$P3_3$0$0 == 0x00b3
                           0000B3   951 _P3_3	=	0x00b3
                           0000B4   952 G$P3_4$0$0 == 0x00b4
                           0000B4   953 _P3_4	=	0x00b4
                           0000B5   954 G$P3_5$0$0 == 0x00b5
                           0000B5   955 _P3_5	=	0x00b5
                           0000B6   956 G$P3_6$0$0 == 0x00b6
                           0000B6   957 _P3_6	=	0x00b6
                           0000B7   958 G$P3_7$0$0 == 0x00b7
                           0000B7   959 _P3_7	=	0x00b7
                           0000B8   960 G$PX0$0$0 == 0x00b8
                           0000B8   961 _PX0	=	0x00b8
                           0000B9   962 G$PT0$0$0 == 0x00b9
                           0000B9   963 _PT0	=	0x00b9
                           0000BA   964 G$PX1$0$0 == 0x00ba
                           0000BA   965 _PX1	=	0x00ba
                           0000BB   966 G$PT1$0$0 == 0x00bb
                           0000BB   967 _PT1	=	0x00bb
                           0000BC   968 G$PS0$0$0 == 0x00bc
                           0000BC   969 _PS0	=	0x00bc
                           0000BC   970 G$PS$0$0 == 0x00bc
                           0000BC   971 _PS	=	0x00bc
                           0000BD   972 G$PT2$0$0 == 0x00bd
                           0000BD   973 _PT2	=	0x00bd
                           0000C0   974 G$SMBTOE$0$0 == 0x00c0
                           0000C0   975 _SMBTOE	=	0x00c0
                           0000C1   976 G$SMBFTE$0$0 == 0x00c1
                           0000C1   977 _SMBFTE	=	0x00c1
                           0000C2   978 G$AA$0$0 == 0x00c2
                           0000C2   979 _AA	=	0x00c2
                           0000C3   980 G$SI$0$0 == 0x00c3
                           0000C3   981 _SI	=	0x00c3
                           0000C4   982 G$STO$0$0 == 0x00c4
                           0000C4   983 _STO	=	0x00c4
                           0000C5   984 G$STA$0$0 == 0x00c5
                           0000C5   985 _STA	=	0x00c5
                           0000C6   986 G$ENSMB$0$0 == 0x00c6
                           0000C6   987 _ENSMB	=	0x00c6
                           0000C7   988 G$BUSY$0$0 == 0x00c7
                           0000C7   989 _BUSY	=	0x00c7
                           0000C0   990 G$MAC0N$0$0 == 0x00c0
                           0000C0   991 _MAC0N	=	0x00c0
                           0000C1   992 G$MAC0SO$0$0 == 0x00c1
                           0000C1   993 _MAC0SO	=	0x00c1
                           0000C2   994 G$MAC0Z$0$0 == 0x00c2
                           0000C2   995 _MAC0Z	=	0x00c2
                           0000C3   996 G$MAC0HO$0$0 == 0x00c3
                           0000C3   997 _MAC0HO	=	0x00c3
                           0000C8   998 G$CPRL2$0$0 == 0x00c8
                           0000C8   999 _CPRL2	=	0x00c8
                           0000C9  1000 G$CT2$0$0 == 0x00c9
                           0000C9  1001 _CT2	=	0x00c9
                           0000CA  1002 G$TR2$0$0 == 0x00ca
                           0000CA  1003 _TR2	=	0x00ca
                           0000CB  1004 G$EXEN2$0$0 == 0x00cb
                           0000CB  1005 _EXEN2	=	0x00cb
                           0000CE  1006 G$EXF2$0$0 == 0x00ce
                           0000CE  1007 _EXF2	=	0x00ce
                           0000CF  1008 G$TF2$0$0 == 0x00cf
                           0000CF  1009 _TF2	=	0x00cf
                           0000C8  1010 G$CPRL3$0$0 == 0x00c8
                           0000C8  1011 _CPRL3	=	0x00c8
                           0000C9  1012 G$CT3$0$0 == 0x00c9
                           0000C9  1013 _CT3	=	0x00c9
                           0000CA  1014 G$TR3$0$0 == 0x00ca
                           0000CA  1015 _TR3	=	0x00ca
                           0000CB  1016 G$EXEN3$0$0 == 0x00cb
                           0000CB  1017 _EXEN3	=	0x00cb
                           0000CE  1018 G$EXF3$0$0 == 0x00ce
                           0000CE  1019 _EXF3	=	0x00ce
                           0000CF  1020 G$TF3$0$0 == 0x00cf
                           0000CF  1021 _TF3	=	0x00cf
                           0000C8  1022 G$CPRL4$0$0 == 0x00c8
                           0000C8  1023 _CPRL4	=	0x00c8
                           0000C9  1024 G$CT4$0$0 == 0x00c9
                           0000C9  1025 _CT4	=	0x00c9
                           0000CA  1026 G$TR4$0$0 == 0x00ca
                           0000CA  1027 _TR4	=	0x00ca
                           0000CB  1028 G$EXEN4$0$0 == 0x00cb
                           0000CB  1029 _EXEN4	=	0x00cb
                           0000CE  1030 G$EXF4$0$0 == 0x00ce
                           0000CE  1031 _EXF4	=	0x00ce
                           0000CF  1032 G$TF4$0$0 == 0x00cf
                           0000CF  1033 _TF4	=	0x00cf
                           0000C8  1034 G$P4_0$0$0 == 0x00c8
                           0000C8  1035 _P4_0	=	0x00c8
                           0000C9  1036 G$P4_1$0$0 == 0x00c9
                           0000C9  1037 _P4_1	=	0x00c9
                           0000CA  1038 G$P4_2$0$0 == 0x00ca
                           0000CA  1039 _P4_2	=	0x00ca
                           0000CB  1040 G$P4_3$0$0 == 0x00cb
                           0000CB  1041 _P4_3	=	0x00cb
                           0000CC  1042 G$P4_4$0$0 == 0x00cc
                           0000CC  1043 _P4_4	=	0x00cc
                           0000CD  1044 G$P4_5$0$0 == 0x00cd
                           0000CD  1045 _P4_5	=	0x00cd
                           0000CE  1046 G$P4_6$0$0 == 0x00ce
                           0000CE  1047 _P4_6	=	0x00ce
                           0000CF  1048 G$P4_7$0$0 == 0x00cf
                           0000CF  1049 _P4_7	=	0x00cf
                           0000D0  1050 G$P$0$0 == 0x00d0
                           0000D0  1051 _P	=	0x00d0
                           0000D1  1052 G$F1$0$0 == 0x00d1
                           0000D1  1053 _F1	=	0x00d1
                           0000D2  1054 G$OV$0$0 == 0x00d2
                           0000D2  1055 _OV	=	0x00d2
                           0000D3  1056 G$RS0$0$0 == 0x00d3
                           0000D3  1057 _RS0	=	0x00d3
                           0000D4  1058 G$RS1$0$0 == 0x00d4
                           0000D4  1059 _RS1	=	0x00d4
                           0000D5  1060 G$F0$0$0 == 0x00d5
                           0000D5  1061 _F0	=	0x00d5
                           0000D6  1062 G$AC$0$0 == 0x00d6
                           0000D6  1063 _AC	=	0x00d6
                           0000D7  1064 G$CY$0$0 == 0x00d7
                           0000D7  1065 _CY	=	0x00d7
                           0000D8  1066 G$CCF0$0$0 == 0x00d8
                           0000D8  1067 _CCF0	=	0x00d8
                           0000D9  1068 G$CCF1$0$0 == 0x00d9
                           0000D9  1069 _CCF1	=	0x00d9
                           0000DA  1070 G$CCF2$0$0 == 0x00da
                           0000DA  1071 _CCF2	=	0x00da
                           0000DB  1072 G$CCF3$0$0 == 0x00db
                           0000DB  1073 _CCF3	=	0x00db
                           0000DC  1074 G$CCF4$0$0 == 0x00dc
                           0000DC  1075 _CCF4	=	0x00dc
                           0000DD  1076 G$CCF5$0$0 == 0x00dd
                           0000DD  1077 _CCF5	=	0x00dd
                           0000DE  1078 G$CR$0$0 == 0x00de
                           0000DE  1079 _CR	=	0x00de
                           0000DF  1080 G$CF$0$0 == 0x00df
                           0000DF  1081 _CF	=	0x00df
                           0000D8  1082 G$P5_0$0$0 == 0x00d8
                           0000D8  1083 _P5_0	=	0x00d8
                           0000D9  1084 G$P5_1$0$0 == 0x00d9
                           0000D9  1085 _P5_1	=	0x00d9
                           0000DA  1086 G$P5_2$0$0 == 0x00da
                           0000DA  1087 _P5_2	=	0x00da
                           0000DB  1088 G$P5_3$0$0 == 0x00db
                           0000DB  1089 _P5_3	=	0x00db
                           0000DC  1090 G$P5_4$0$0 == 0x00dc
                           0000DC  1091 _P5_4	=	0x00dc
                           0000DD  1092 G$P5_5$0$0 == 0x00dd
                           0000DD  1093 _P5_5	=	0x00dd
                           0000DE  1094 G$P5_6$0$0 == 0x00de
                           0000DE  1095 _P5_6	=	0x00de
                           0000DF  1096 G$P5_7$0$0 == 0x00df
                           0000DF  1097 _P5_7	=	0x00df
                           0000E8  1098 G$AD0LJST$0$0 == 0x00e8
                           0000E8  1099 _AD0LJST	=	0x00e8
                           0000E9  1100 G$AD0WINT$0$0 == 0x00e9
                           0000E9  1101 _AD0WINT	=	0x00e9
                           0000EA  1102 G$AD0CM0$0$0 == 0x00ea
                           0000EA  1103 _AD0CM0	=	0x00ea
                           0000EB  1104 G$AD0CM1$0$0 == 0x00eb
                           0000EB  1105 _AD0CM1	=	0x00eb
                           0000EC  1106 G$AD0BUSY$0$0 == 0x00ec
                           0000EC  1107 _AD0BUSY	=	0x00ec
                           0000ED  1108 G$AD0INT$0$0 == 0x00ed
                           0000ED  1109 _AD0INT	=	0x00ed
                           0000EE  1110 G$AD0TM$0$0 == 0x00ee
                           0000EE  1111 _AD0TM	=	0x00ee
                           0000EF  1112 G$AD0EN$0$0 == 0x00ef
                           0000EF  1113 _AD0EN	=	0x00ef
                           0000E8  1114 G$AD2WINT$0$0 == 0x00e8
                           0000E8  1115 _AD2WINT	=	0x00e8
                           0000E9  1116 G$AD2CM0$0$0 == 0x00e9
                           0000E9  1117 _AD2CM0	=	0x00e9
                           0000EA  1118 G$AD2CM1$0$0 == 0x00ea
                           0000EA  1119 _AD2CM1	=	0x00ea
                           0000EB  1120 G$AD2CM2$0$0 == 0x00eb
                           0000EB  1121 _AD2CM2	=	0x00eb
                           0000EC  1122 G$AD2BUSY$0$0 == 0x00ec
                           0000EC  1123 _AD2BUSY	=	0x00ec
                           0000ED  1124 G$AD2INT$0$0 == 0x00ed
                           0000ED  1125 _AD2INT	=	0x00ed
                           0000EE  1126 G$AD2TM$0$0 == 0x00ee
                           0000EE  1127 _AD2TM	=	0x00ee
                           0000EF  1128 G$AD2EN$0$0 == 0x00ef
                           0000EF  1129 _AD2EN	=	0x00ef
                           0000E8  1130 G$P6_0$0$0 == 0x00e8
                           0000E8  1131 _P6_0	=	0x00e8
                           0000E9  1132 G$P6_1$0$0 == 0x00e9
                           0000E9  1133 _P6_1	=	0x00e9
                           0000EA  1134 G$P6_2$0$0 == 0x00ea
                           0000EA  1135 _P6_2	=	0x00ea
                           0000EB  1136 G$P6_3$0$0 == 0x00eb
                           0000EB  1137 _P6_3	=	0x00eb
                           0000EC  1138 G$P6_4$0$0 == 0x00ec
                           0000EC  1139 _P6_4	=	0x00ec
                           0000ED  1140 G$P6_5$0$0 == 0x00ed
                           0000ED  1141 _P6_5	=	0x00ed
                           0000EE  1142 G$P6_6$0$0 == 0x00ee
                           0000EE  1143 _P6_6	=	0x00ee
                           0000EF  1144 G$P6_7$0$0 == 0x00ef
                           0000EF  1145 _P6_7	=	0x00ef
                           0000F8  1146 G$SPIEN$0$0 == 0x00f8
                           0000F8  1147 _SPIEN	=	0x00f8
                           0000F9  1148 G$TXBMT$0$0 == 0x00f9
                           0000F9  1149 _TXBMT	=	0x00f9
                           0000FA  1150 G$NSSMD0$0$0 == 0x00fa
                           0000FA  1151 _NSSMD0	=	0x00fa
                           0000FB  1152 G$NSSMD1$0$0 == 0x00fb
                           0000FB  1153 _NSSMD1	=	0x00fb
                           0000FC  1154 G$RXOVRN$0$0 == 0x00fc
                           0000FC  1155 _RXOVRN	=	0x00fc
                           0000FD  1156 G$MODF$0$0 == 0x00fd
                           0000FD  1157 _MODF	=	0x00fd
                           0000FE  1158 G$WCOL$0$0 == 0x00fe
                           0000FE  1159 _WCOL	=	0x00fe
                           0000FF  1160 G$SPIF$0$0 == 0x00ff
                           0000FF  1161 _SPIF	=	0x00ff
                           0000F8  1162 G$P7_0$0$0 == 0x00f8
                           0000F8  1163 _P7_0	=	0x00f8
                           0000F9  1164 G$P7_1$0$0 == 0x00f9
                           0000F9  1165 _P7_1	=	0x00f9
                           0000FA  1166 G$P7_2$0$0 == 0x00fa
                           0000FA  1167 _P7_2	=	0x00fa
                           0000FB  1168 G$P7_3$0$0 == 0x00fb
                           0000FB  1169 _P7_3	=	0x00fb
                           0000FC  1170 G$P7_4$0$0 == 0x00fc
                           0000FC  1171 _P7_4	=	0x00fc
                           0000FD  1172 G$P7_5$0$0 == 0x00fd
                           0000FD  1173 _P7_5	=	0x00fd
                           0000FE  1174 G$P7_6$0$0 == 0x00fe
                           0000FE  1175 _P7_6	=	0x00fe
                           0000FF  1176 G$P7_7$0$0 == 0x00ff
                           0000FF  1177 _P7_7	=	0x00ff
                                   1178 ;--------------------------------------------------------
                                   1179 ; overlayable register banks
                                   1180 ;--------------------------------------------------------
                                   1181 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                       1182 	.ds 8
                                   1183 ;--------------------------------------------------------
                                   1184 ; internal ram data
                                   1185 ;--------------------------------------------------------
                                   1186 	.area DSEG    (DATA)
                                   1187 ;--------------------------------------------------------
                                   1188 ; overlayable items in internal ram 
                                   1189 ;--------------------------------------------------------
                                   1190 	.area	OSEG    (OVR,DATA)
                                   1191 	.area	OSEG    (OVR,DATA)
                                   1192 	.area	OSEG    (OVR,DATA)
                                   1193 	.area	OSEG    (OVR,DATA)
                                   1194 ;--------------------------------------------------------
                                   1195 ; Stack segment in internal ram 
                                   1196 ;--------------------------------------------------------
                                   1197 	.area	SSEG
      00003C                       1198 __start__stack:
      00003C                       1199 	.ds	1
                                   1200 
                                   1201 ;--------------------------------------------------------
                                   1202 ; indirectly addressable internal ram data
                                   1203 ;--------------------------------------------------------
                                   1204 	.area ISEG    (DATA)
                                   1205 ;--------------------------------------------------------
                                   1206 ; absolute internal ram data
                                   1207 ;--------------------------------------------------------
                                   1208 	.area IABS    (ABS,DATA)
                                   1209 	.area IABS    (ABS,DATA)
                                   1210 ;--------------------------------------------------------
                                   1211 ; bit data
                                   1212 ;--------------------------------------------------------
                                   1213 	.area BSEG    (BIT)
                                   1214 ;--------------------------------------------------------
                                   1215 ; paged external ram data
                                   1216 ;--------------------------------------------------------
                                   1217 	.area PSEG    (PAG,XDATA)
                                   1218 ;--------------------------------------------------------
                                   1219 ; external ram data
                                   1220 ;--------------------------------------------------------
                                   1221 	.area XSEG    (XDATA)
                                   1222 ;--------------------------------------------------------
                                   1223 ; absolute external ram data
                                   1224 ;--------------------------------------------------------
                                   1225 	.area XABS    (ABS,XDATA)
                                   1226 ;--------------------------------------------------------
                                   1227 ; external initialized ram data
                                   1228 ;--------------------------------------------------------
                                   1229 	.area XISEG   (XDATA)
                                   1230 	.area HOME    (CODE)
                                   1231 	.area GSINIT0 (CODE)
                                   1232 	.area GSINIT1 (CODE)
                                   1233 	.area GSINIT2 (CODE)
                                   1234 	.area GSINIT3 (CODE)
                                   1235 	.area GSINIT4 (CODE)
                                   1236 	.area GSINIT5 (CODE)
                                   1237 	.area GSINIT  (CODE)
                                   1238 	.area GSFINAL (CODE)
                                   1239 	.area CSEG    (CODE)
                                   1240 ;--------------------------------------------------------
                                   1241 ; interrupt vector 
                                   1242 ;--------------------------------------------------------
                                   1243 	.area HOME    (CODE)
      000000                       1244 __interrupt_vect:
      000000 02 00 06         [24] 1245 	ljmp	__sdcc_gsinit_startup
                                   1246 ;--------------------------------------------------------
                                   1247 ; global & static initialisations
                                   1248 ;--------------------------------------------------------
                                   1249 	.area HOME    (CODE)
                                   1250 	.area GSINIT  (CODE)
                                   1251 	.area GSFINAL (CODE)
                                   1252 	.area GSINIT  (CODE)
                                   1253 	.globl __sdcc_gsinit_startup
                                   1254 	.globl __sdcc_program_startup
                                   1255 	.globl __start__stack
                                   1256 	.globl __mcs51_genXINIT
                                   1257 	.globl __mcs51_genXRAMCLEAR
                                   1258 	.globl __mcs51_genRAMCLEAR
                                   1259 	.area GSFINAL (CODE)
      00005F 02 00 03         [24] 1260 	ljmp	__sdcc_program_startup
                                   1261 ;--------------------------------------------------------
                                   1262 ; Home
                                   1263 ;--------------------------------------------------------
                                   1264 	.area HOME    (CODE)
                                   1265 	.area HOME    (CODE)
      000003                       1266 __sdcc_program_startup:
      000003 02 00 7B         [24] 1267 	ljmp	_main
                                   1268 ;	return from main will return to caller
                                   1269 ;--------------------------------------------------------
                                   1270 ; code
                                   1271 ;--------------------------------------------------------
                                   1272 	.area CSEG    (CODE)
                                   1273 ;------------------------------------------------------------
                                   1274 ;Allocation info for local variables in function 'putchar'
                                   1275 ;------------------------------------------------------------
                                   1276 ;c                         Allocated to registers r7 
                                   1277 ;------------------------------------------------------------
                           000000  1278 	G$putchar$0$0 ==.
                           000000  1279 	C$putget.h$18$0$0 ==.
                                   1280 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\/putget.h:18: void putchar(char c)
                                   1281 ;	-----------------------------------------
                                   1282 ;	 function putchar
                                   1283 ;	-----------------------------------------
      000062                       1284 _putchar:
                           000007  1285 	ar7 = 0x07
                           000006  1286 	ar6 = 0x06
                           000005  1287 	ar5 = 0x05
                           000004  1288 	ar4 = 0x04
                           000003  1289 	ar3 = 0x03
                           000002  1290 	ar2 = 0x02
                           000001  1291 	ar1 = 0x01
                           000000  1292 	ar0 = 0x00
      000062 AF 82            [24] 1293 	mov	r7,dpl
                           000002  1294 	C$putget.h$20$1$35 ==.
                                   1295 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\/putget.h:20: while(!TI0); 
      000064                       1296 00101$:
                           000002  1297 	C$putget.h$21$1$35 ==.
                                   1298 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\/putget.h:21: TI0=0;
      000064 10 99 02         [24] 1299 	jbc	_TI0,00112$
      000067 80 FB            [24] 1300 	sjmp	00101$
      000069                       1301 00112$:
                           000007  1302 	C$putget.h$22$1$35 ==.
                                   1303 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\/putget.h:22: SBUF0 = c;
      000069 8F 99            [24] 1304 	mov	_SBUF0,r7
                           000009  1305 	C$putget.h$23$1$35 ==.
                           000009  1306 	XG$putchar$0$0 ==.
      00006B 22               [24] 1307 	ret
                                   1308 ;------------------------------------------------------------
                                   1309 ;Allocation info for local variables in function 'getchar'
                                   1310 ;------------------------------------------------------------
                                   1311 ;c                         Allocated to registers 
                                   1312 ;------------------------------------------------------------
                           00000A  1313 	G$getchar$0$0 ==.
                           00000A  1314 	C$putget.h$28$1$35 ==.
                                   1315 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\/putget.h:28: char getchar(void)
                                   1316 ;	-----------------------------------------
                                   1317 ;	 function getchar
                                   1318 ;	-----------------------------------------
      00006C                       1319 _getchar:
                           00000A  1320 	C$putget.h$31$1$37 ==.
                                   1321 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\/putget.h:31: while(!RI0);
      00006C                       1322 00101$:
                           00000A  1323 	C$putget.h$32$1$37 ==.
                                   1324 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\/putget.h:32: RI0 =0;
      00006C 10 98 02         [24] 1325 	jbc	_RI0,00112$
      00006F 80 FB            [24] 1326 	sjmp	00101$
      000071                       1327 00112$:
                           00000F  1328 	C$putget.h$33$1$37 ==.
                                   1329 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\/putget.h:33: c = SBUF0;
      000071 85 99 82         [24] 1330 	mov	dpl,_SBUF0
                           000012  1331 	C$putget.h$35$1$37 ==.
                                   1332 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\/putget.h:35: putchar(c);    // echo to terminal
      000074 12 00 62         [24] 1333 	lcall	_putchar
                           000015  1334 	C$putget.h$36$1$37 ==.
                                   1335 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\/putget.h:36: return SBUF0;
      000077 85 99 82         [24] 1336 	mov	dpl,_SBUF0
                           000018  1337 	C$putget.h$37$1$37 ==.
                           000018  1338 	XG$getchar$0$0 ==.
      00007A 22               [24] 1339 	ret
                                   1340 ;------------------------------------------------------------
                                   1341 ;Allocation info for local variables in function 'main'
                                   1342 ;------------------------------------------------------------
                                   1343 ;choice                    Allocated to registers r5 
                                   1344 ;lastLineUsed              Allocated to registers r6 r7 
                                   1345 ;------------------------------------------------------------
                           000019  1346 	G$main$0$0 ==.
                           000019  1347 	C$Hello.c$45$1$37 ==.
                                   1348 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:45: void main(void)
                                   1349 ;	-----------------------------------------
                                   1350 ;	 function main
                                   1351 ;	-----------------------------------------
      00007B                       1352 _main:
                           000019  1353 	C$Hello.c$48$1$37 ==.
                                   1354 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:48: int lastLineUsed = 12;
      00007B 7E 0C            [12] 1355 	mov	r6,#0x0c
      00007D 7F 00            [12] 1356 	mov	r7,#0x00
                           00001D  1357 	C$Hello.c$50$1$43 ==.
                                   1358 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:50: WDTCN = 0xDE;                       // Disable the watchdog timer
      00007F 75 FF DE         [24] 1359 	mov	_WDTCN,#0xde
                           000020  1360 	C$Hello.c$51$1$43 ==.
                                   1361 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:51: WDTCN = 0xAD;
      000082 75 FF AD         [24] 1362 	mov	_WDTCN,#0xad
                           000023  1363 	C$Hello.c$53$1$43 ==.
                                   1364 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:53: PORT_INIT();                        // Initialize the Crossbar and GPIO
      000085 C0 07            [24] 1365 	push	ar7
      000087 C0 06            [24] 1366 	push	ar6
      000089 12 02 6E         [24] 1367 	lcall	_PORT_INIT
                           00002A  1368 	C$Hello.c$54$1$43 ==.
                                   1369 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:54: SYSCLK_INIT();                      // Initialize the oscillator
      00008C 12 02 18         [24] 1370 	lcall	_SYSCLK_INIT
                           00002D  1371 	C$Hello.c$55$1$43 ==.
                                   1372 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:55: UART0_INIT();                       // Initialize UART0
      00008F 12 02 85         [24] 1373 	lcall	_UART0_INIT
                           000030  1374 	C$Hello.c$57$1$43 ==.
                                   1375 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:57: SFRPAGE = UART0_PAGE;               // Direct output to UART0
      000092 75 84 00         [24] 1376 	mov	_SFRPAGE,#0x00
                           000033  1377 	C$Hello.c$59$1$43 ==.
                                   1378 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:59: printf("\033[2J");                  // Erase screen & move cursor to home position
      000095 74 1C            [12] 1379 	mov	a,#___str_0
      000097 C0 E0            [24] 1380 	push	acc
      000099 74 09            [12] 1381 	mov	a,#(___str_0 >> 8)
      00009B C0 E0            [24] 1382 	push	acc
      00009D 74 80            [12] 1383 	mov	a,#0x80
      00009F C0 E0            [24] 1384 	push	acc
      0000A1 12 03 01         [24] 1385 	lcall	_printf
      0000A4 15 81            [12] 1386 	dec	sp
      0000A6 15 81            [12] 1387 	dec	sp
      0000A8 15 81            [12] 1388 	dec	sp
                           000048  1389 	C$Hello.c$60$1$43 ==.
                                   1390 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:60: printf("\033[0;44;33m"); //reset attributes, set background to blue, set forground to yellow
      0000AA 74 21            [12] 1391 	mov	a,#___str_1
      0000AC C0 E0            [24] 1392 	push	acc
      0000AE 74 09            [12] 1393 	mov	a,#(___str_1 >> 8)
      0000B0 C0 E0            [24] 1394 	push	acc
      0000B2 74 80            [12] 1395 	mov	a,#0x80
      0000B4 C0 E0            [24] 1396 	push	acc
      0000B6 12 03 01         [24] 1397 	lcall	_printf
      0000B9 15 81            [12] 1398 	dec	sp
      0000BB 15 81            [12] 1399 	dec	sp
      0000BD 15 81            [12] 1400 	dec	sp
                           00005D  1401 	C$Hello.c$62$1$43 ==.
                                   1402 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:62: printf("\033[2;30HType <ESC> to end the program\n\n\n\n\r");
      0000BF 74 2C            [12] 1403 	mov	a,#___str_2
      0000C1 C0 E0            [24] 1404 	push	acc
      0000C3 74 09            [12] 1405 	mov	a,#(___str_2 >> 8)
      0000C5 C0 E0            [24] 1406 	push	acc
      0000C7 74 80            [12] 1407 	mov	a,#0x80
      0000C9 C0 E0            [24] 1408 	push	acc
      0000CB 12 03 01         [24] 1409 	lcall	_printf
      0000CE 15 81            [12] 1410 	dec	sp
      0000D0 15 81            [12] 1411 	dec	sp
      0000D2 15 81            [12] 1412 	dec	sp
                           000072  1413 	C$Hello.c$64$1$43 ==.
                                   1414 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:64: printf("The keyboard character is: ");
      0000D4 74 56            [12] 1415 	mov	a,#___str_3
      0000D6 C0 E0            [24] 1416 	push	acc
      0000D8 74 09            [12] 1417 	mov	a,#(___str_3 >> 8)
      0000DA C0 E0            [24] 1418 	push	acc
      0000DC 74 80            [12] 1419 	mov	a,#0x80
      0000DE C0 E0            [24] 1420 	push	acc
      0000E0 12 03 01         [24] 1421 	lcall	_printf
      0000E3 15 81            [12] 1422 	dec	sp
      0000E5 15 81            [12] 1423 	dec	sp
      0000E7 15 81            [12] 1424 	dec	sp
                           000087  1425 	C$Hello.c$66$1$43 ==.
                                   1426 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:66: printf("\033[12;25r"); //set scroll area
      0000E9 74 72            [12] 1427 	mov	a,#___str_4
      0000EB C0 E0            [24] 1428 	push	acc
      0000ED 74 09            [12] 1429 	mov	a,#(___str_4 >> 8)
      0000EF C0 E0            [24] 1430 	push	acc
      0000F1 74 80            [12] 1431 	mov	a,#0x80
      0000F3 C0 E0            [24] 1432 	push	acc
      0000F5 12 03 01         [24] 1433 	lcall	_printf
      0000F8 15 81            [12] 1434 	dec	sp
      0000FA 15 81            [12] 1435 	dec	sp
      0000FC 15 81            [12] 1436 	dec	sp
      0000FE D0 06            [24] 1437 	pop	ar6
      000100 D0 07            [24] 1438 	pop	ar7
                           0000A0  1439 	C$Hello.c$69$1$43 ==.
                                   1440 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:69: while(1)
      000102                       1441 00107$:
                           0000A0  1442 	C$Hello.c$71$2$44 ==.
                                   1443 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:71: printf("\033[H"); //go home, top left
      000102 C0 07            [24] 1444 	push	ar7
      000104 C0 06            [24] 1445 	push	ar6
      000106 74 7B            [12] 1446 	mov	a,#___str_5
      000108 C0 E0            [24] 1447 	push	acc
      00010A 74 09            [12] 1448 	mov	a,#(___str_5 >> 8)
      00010C C0 E0            [24] 1449 	push	acc
      00010E 74 80            [12] 1450 	mov	a,#0x80
      000110 C0 E0            [24] 1451 	push	acc
      000112 12 03 01         [24] 1452 	lcall	_printf
      000115 15 81            [12] 1453 	dec	sp
      000117 15 81            [12] 1454 	dec	sp
      000119 15 81            [12] 1455 	dec	sp
                           0000B9  1456 	C$Hello.c$74$2$44 ==.
                                   1457 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:74: choice = getchar(); //get the character input
      00011B 12 00 6C         [24] 1458 	lcall	_getchar
      00011E AD 82            [24] 1459 	mov	r5,dpl
                           0000BE  1460 	C$Hello.c$76$2$44 ==.
                                   1461 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:76: printf("\033[2k"); //erase the top left line because there was just a typed character there
      000120 C0 05            [24] 1462 	push	ar5
      000122 74 7F            [12] 1463 	mov	a,#___str_6
      000124 C0 E0            [24] 1464 	push	acc
      000126 74 09            [12] 1465 	mov	a,#(___str_6 >> 8)
      000128 C0 E0            [24] 1466 	push	acc
      00012A 74 80            [12] 1467 	mov	a,#0x80
      00012C C0 E0            [24] 1468 	push	acc
      00012E 12 03 01         [24] 1469 	lcall	_printf
      000131 15 81            [12] 1470 	dec	sp
      000133 15 81            [12] 1471 	dec	sp
      000135 15 81            [12] 1472 	dec	sp
      000137 D0 05            [24] 1473 	pop	ar5
                           0000D7  1474 	C$Hello.c$78$2$44 ==.
                                   1475 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:78: if(isprint(choice))
      000139 8D 03            [24] 1476 	mov	ar3,r5
      00013B 7C 00            [12] 1477 	mov	r4,#0x00
      00013D 8B 82            [24] 1478 	mov	dpl,r3
      00013F 8C 83            [24] 1479 	mov	dph,r4
      000141 C0 05            [24] 1480 	push	ar5
      000143 12 02 A9         [24] 1481 	lcall	_isprint
      000146 E5 82            [12] 1482 	mov	a,dpl
      000148 85 83 F0         [24] 1483 	mov	b,dph
      00014B D0 05            [24] 1484 	pop	ar5
      00014D D0 06            [24] 1485 	pop	ar6
      00014F D0 07            [24] 1486 	pop	ar7
      000151 45 F0            [12] 1487 	orl	a,b
      000153 60 72            [24] 1488 	jz	00104$
                           0000F3  1489 	C$Hello.c$81$3$45 ==.
                                   1490 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:81: printf("\033[%i;40H \n", lastLineUsed); //move cursor to the scrollable area and create a new line
      000155 C0 07            [24] 1491 	push	ar7
      000157 C0 06            [24] 1492 	push	ar6
      000159 C0 05            [24] 1493 	push	ar5
      00015B C0 06            [24] 1494 	push	ar6
      00015D C0 07            [24] 1495 	push	ar7
      00015F 74 84            [12] 1496 	mov	a,#___str_7
      000161 C0 E0            [24] 1497 	push	acc
      000163 74 09            [12] 1498 	mov	a,#(___str_7 >> 8)
      000165 C0 E0            [24] 1499 	push	acc
      000167 74 80            [12] 1500 	mov	a,#0x80
      000169 C0 E0            [24] 1501 	push	acc
      00016B 12 03 01         [24] 1502 	lcall	_printf
      00016E E5 81            [12] 1503 	mov	a,sp
      000170 24 FB            [12] 1504 	add	a,#0xfb
      000172 F5 81            [12] 1505 	mov	sp,a
      000174 D0 05            [24] 1506 	pop	ar5
      000176 D0 06            [24] 1507 	pop	ar6
      000178 D0 07            [24] 1508 	pop	ar7
                           000118  1509 	C$Hello.c$83$3$45 ==.
                                   1510 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:83: if(lastLineUsed < 25)
      00017A C3               [12] 1511 	clr	c
      00017B EE               [12] 1512 	mov	a,r6
      00017C 94 19            [12] 1513 	subb	a,#0x19
      00017E EF               [12] 1514 	mov	a,r7
      00017F 64 80            [12] 1515 	xrl	a,#0x80
      000181 94 80            [12] 1516 	subb	a,#0x80
      000183 50 05            [24] 1517 	jnc	00102$
                           000123  1518 	C$Hello.c$85$4$46 ==.
                                   1519 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:85: lastLineUsed = lastLineUsed + 1;
      000185 0E               [12] 1520 	inc	r6
      000186 BE 00 01         [24] 1521 	cjne	r6,#0x00,00122$
      000189 0F               [12] 1522 	inc	r7
      00018A                       1523 00122$:
      00018A                       1524 00102$:
                           000128  1525 	C$Hello.c$88$3$45 ==.
                                   1526 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:88: printf("The keyboard character %x is\033[4;5m not printable\033[0;44;33m", (choice & 0xff)); 
      00018A 8D 03            [24] 1527 	mov	ar3,r5
      00018C 7C 00            [12] 1528 	mov	r4,#0x00
      00018E C0 07            [24] 1529 	push	ar7
      000190 C0 06            [24] 1530 	push	ar6
      000192 C0 03            [24] 1531 	push	ar3
      000194 C0 04            [24] 1532 	push	ar4
      000196 74 8F            [12] 1533 	mov	a,#___str_8
      000198 C0 E0            [24] 1534 	push	acc
      00019A 74 09            [12] 1535 	mov	a,#(___str_8 >> 8)
      00019C C0 E0            [24] 1536 	push	acc
      00019E 74 80            [12] 1537 	mov	a,#0x80
      0001A0 C0 E0            [24] 1538 	push	acc
      0001A2 12 03 01         [24] 1539 	lcall	_printf
      0001A5 E5 81            [12] 1540 	mov	a,sp
      0001A7 24 FB            [12] 1541 	add	a,#0xfb
      0001A9 F5 81            [12] 1542 	mov	sp,a
                           000149  1543 	C$Hello.c$89$3$45 ==.
                                   1544 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:89: printf("\033[H"); //go back home
      0001AB 74 7B            [12] 1545 	mov	a,#___str_5
      0001AD C0 E0            [24] 1546 	push	acc
      0001AF 74 09            [12] 1547 	mov	a,#(___str_5 >> 8)
      0001B1 C0 E0            [24] 1548 	push	acc
      0001B3 74 80            [12] 1549 	mov	a,#0x80
      0001B5 C0 E0            [24] 1550 	push	acc
      0001B7 12 03 01         [24] 1551 	lcall	_printf
      0001BA 15 81            [12] 1552 	dec	sp
      0001BC 15 81            [12] 1553 	dec	sp
      0001BE 15 81            [12] 1554 	dec	sp
      0001C0 D0 06            [24] 1555 	pop	ar6
      0001C2 D0 07            [24] 1556 	pop	ar7
      0001C4 02 01 02         [24] 1557 	ljmp	00107$
      0001C7                       1558 00104$:
                           000165  1559 	C$Hello.c$93$3$47 ==.
                                   1560 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:93: printf("\033[6;28H"); //move cursor to the correct position
      0001C7 C0 07            [24] 1561 	push	ar7
      0001C9 C0 06            [24] 1562 	push	ar6
      0001CB C0 05            [24] 1563 	push	ar5
      0001CD 74 CA            [12] 1564 	mov	a,#___str_9
      0001CF C0 E0            [24] 1565 	push	acc
      0001D1 74 09            [12] 1566 	mov	a,#(___str_9 >> 8)
      0001D3 C0 E0            [24] 1567 	push	acc
      0001D5 74 80            [12] 1568 	mov	a,#0x80
      0001D7 C0 E0            [24] 1569 	push	acc
      0001D9 12 03 01         [24] 1570 	lcall	_printf
      0001DC 15 81            [12] 1571 	dec	sp
      0001DE 15 81            [12] 1572 	dec	sp
      0001E0 15 81            [12] 1573 	dec	sp
                           000180  1574 	C$Hello.c$94$3$47 ==.
                                   1575 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:94: printf("\033[37m%c", choice ); //print typed character, in white
      0001E2 7C 00            [12] 1576 	mov	r4,#0x00
      0001E4 C0 04            [24] 1577 	push	ar4
      0001E6 74 D2            [12] 1578 	mov	a,#___str_10
      0001E8 C0 E0            [24] 1579 	push	acc
      0001EA 74 09            [12] 1580 	mov	a,#(___str_10 >> 8)
      0001EC C0 E0            [24] 1581 	push	acc
      0001EE 74 80            [12] 1582 	mov	a,#0x80
      0001F0 C0 E0            [24] 1583 	push	acc
      0001F2 12 03 01         [24] 1584 	lcall	_printf
      0001F5 E5 81            [12] 1585 	mov	a,sp
      0001F7 24 FB            [12] 1586 	add	a,#0xfb
      0001F9 F5 81            [12] 1587 	mov	sp,a
                           000199  1588 	C$Hello.c$95$3$47 ==.
                                   1589 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:95: printf("\033[H"); //go back home
      0001FB 74 7B            [12] 1590 	mov	a,#___str_5
      0001FD C0 E0            [24] 1591 	push	acc
      0001FF 74 09            [12] 1592 	mov	a,#(___str_5 >> 8)
      000201 C0 E0            [24] 1593 	push	acc
      000203 74 80            [12] 1594 	mov	a,#0x80
      000205 C0 E0            [24] 1595 	push	acc
      000207 12 03 01         [24] 1596 	lcall	_printf
      00020A 15 81            [12] 1597 	dec	sp
      00020C 15 81            [12] 1598 	dec	sp
      00020E 15 81            [12] 1599 	dec	sp
      000210 D0 06            [24] 1600 	pop	ar6
      000212 D0 07            [24] 1601 	pop	ar7
      000214 02 01 02         [24] 1602 	ljmp	00107$
                           0001B5  1603 	C$Hello.c$122$1$43 ==.
                           0001B5  1604 	XG$main$0$0 ==.
      000217 22               [24] 1605 	ret
                                   1606 ;------------------------------------------------------------
                                   1607 ;Allocation info for local variables in function 'SYSCLK_INIT'
                                   1608 ;------------------------------------------------------------
                                   1609 ;i                         Allocated to registers r5 r6 
                                   1610 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1611 ;------------------------------------------------------------
                           0001B6  1612 	G$SYSCLK_INIT$0$0 ==.
                           0001B6  1613 	C$Hello.c$130$1$43 ==.
                                   1614 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:130: void SYSCLK_INIT(void)
                                   1615 ;	-----------------------------------------
                                   1616 ;	 function SYSCLK_INIT
                                   1617 ;	-----------------------------------------
      000218                       1618 _SYSCLK_INIT:
                           0001B6  1619 	C$Hello.c$135$1$49 ==.
                                   1620 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:135: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      000218 AF 84            [24] 1621 	mov	r7,_SFRPAGE
                           0001B8  1622 	C$Hello.c$137$1$49 ==.
                                   1623 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:137: SFRPAGE = CONFIG_PAGE;
      00021A 75 84 0F         [24] 1624 	mov	_SFRPAGE,#0x0f
                           0001BB  1625 	C$Hello.c$138$1$49 ==.
                                   1626 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:138: OSCXCN  = 0x67;                     // Start ext osc with 22.1184MHz crystal
      00021D 75 8C 67         [24] 1627 	mov	_OSCXCN,#0x67
                           0001BE  1628 	C$Hello.c$139$1$49 ==.
                                   1629 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:139: for(i=0; i < 256; i++);             // Wait for the oscillator to start up
      000220 7D 00            [12] 1630 	mov	r5,#0x00
      000222 7E 01            [12] 1631 	mov	r6,#0x01
      000224                       1632 00111$:
      000224 1D               [12] 1633 	dec	r5
      000225 BD FF 01         [24] 1634 	cjne	r5,#0xff,00141$
      000228 1E               [12] 1635 	dec	r6
      000229                       1636 00141$:
      000229 ED               [12] 1637 	mov	a,r5
      00022A 4E               [12] 1638 	orl	a,r6
      00022B 70 F7            [24] 1639 	jnz	00111$
                           0001CB  1640 	C$Hello.c$140$1$49 ==.
                                   1641 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:140: while(!(OSCXCN & 0x80));
      00022D                       1642 00102$:
      00022D E5 8C            [12] 1643 	mov	a,_OSCXCN
      00022F 30 E7 FB         [24] 1644 	jnb	acc.7,00102$
                           0001D0  1645 	C$Hello.c$141$1$49 ==.
                                   1646 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:141: CLKSEL  = 0x01;
      000232 75 97 01         [24] 1647 	mov	_CLKSEL,#0x01
                           0001D3  1648 	C$Hello.c$142$1$49 ==.
                                   1649 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:142: OSCICN  = 0x00;
      000235 75 8A 00         [24] 1650 	mov	_OSCICN,#0x00
                           0001D6  1651 	C$Hello.c$144$1$49 ==.
                                   1652 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:144: SFRPAGE = CONFIG_PAGE;
      000238 75 84 0F         [24] 1653 	mov	_SFRPAGE,#0x0f
                           0001D9  1654 	C$Hello.c$145$1$49 ==.
                                   1655 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:145: PLL0CN  = 0x04;
      00023B 75 89 04         [24] 1656 	mov	_PLL0CN,#0x04
                           0001DC  1657 	C$Hello.c$146$1$49 ==.
                                   1658 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:146: SFRPAGE = LEGACY_PAGE;
      00023E 75 84 00         [24] 1659 	mov	_SFRPAGE,#0x00
                           0001DF  1660 	C$Hello.c$147$1$49 ==.
                                   1661 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:147: FLSCL   = 0x10;
      000241 75 B7 10         [24] 1662 	mov	_FLSCL,#0x10
                           0001E2  1663 	C$Hello.c$148$1$49 ==.
                                   1664 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:148: SFRPAGE = CONFIG_PAGE;
      000244 75 84 0F         [24] 1665 	mov	_SFRPAGE,#0x0f
                           0001E5  1666 	C$Hello.c$149$1$49 ==.
                                   1667 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:149: PLL0CN |= 0x01;
      000247 43 89 01         [24] 1668 	orl	_PLL0CN,#0x01
                           0001E8  1669 	C$Hello.c$150$1$49 ==.
                                   1670 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:150: PLL0DIV = 0x04;
      00024A 75 8D 04         [24] 1671 	mov	_PLL0DIV,#0x04
                           0001EB  1672 	C$Hello.c$151$1$49 ==.
                                   1673 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:151: PLL0FLT = 0x01;
      00024D 75 8F 01         [24] 1674 	mov	_PLL0FLT,#0x01
                           0001EE  1675 	C$Hello.c$152$1$49 ==.
                                   1676 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:152: PLL0MUL = 0x09;
      000250 75 8E 09         [24] 1677 	mov	_PLL0MUL,#0x09
                           0001F1  1678 	C$Hello.c$153$1$49 ==.
                                   1679 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:153: for(i=0; i < 256; i++);
      000253 7D 00            [12] 1680 	mov	r5,#0x00
      000255 7E 01            [12] 1681 	mov	r6,#0x01
      000257                       1682 00114$:
      000257 1D               [12] 1683 	dec	r5
      000258 BD FF 01         [24] 1684 	cjne	r5,#0xff,00144$
      00025B 1E               [12] 1685 	dec	r6
      00025C                       1686 00144$:
      00025C ED               [12] 1687 	mov	a,r5
      00025D 4E               [12] 1688 	orl	a,r6
      00025E 70 F7            [24] 1689 	jnz	00114$
                           0001FE  1690 	C$Hello.c$154$1$49 ==.
                                   1691 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:154: PLL0CN |= 0x02;
      000260 43 89 02         [24] 1692 	orl	_PLL0CN,#0x02
                           000201  1693 	C$Hello.c$155$1$49 ==.
                                   1694 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:155: while(!(PLL0CN & 0x10));
      000263                       1695 00106$:
      000263 E5 89            [12] 1696 	mov	a,_PLL0CN
      000265 30 E4 FB         [24] 1697 	jnb	acc.4,00106$
                           000206  1698 	C$Hello.c$156$1$49 ==.
                                   1699 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:156: CLKSEL  = 0x02;
      000268 75 97 02         [24] 1700 	mov	_CLKSEL,#0x02
                           000209  1701 	C$Hello.c$158$1$49 ==.
                                   1702 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:158: SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
      00026B 8F 84            [24] 1703 	mov	_SFRPAGE,r7
                           00020B  1704 	C$Hello.c$159$1$49 ==.
                           00020B  1705 	XG$SYSCLK_INIT$0$0 ==.
      00026D 22               [24] 1706 	ret
                                   1707 ;------------------------------------------------------------
                                   1708 ;Allocation info for local variables in function 'PORT_INIT'
                                   1709 ;------------------------------------------------------------
                                   1710 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1711 ;------------------------------------------------------------
                           00020C  1712 	G$PORT_INIT$0$0 ==.
                           00020C  1713 	C$Hello.c$167$1$49 ==.
                                   1714 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:167: void PORT_INIT(void)
                                   1715 ;	-----------------------------------------
                                   1716 ;	 function PORT_INIT
                                   1717 ;	-----------------------------------------
      00026E                       1718 _PORT_INIT:
                           00020C  1719 	C$Hello.c$171$1$51 ==.
                                   1720 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:171: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      00026E AF 84            [24] 1721 	mov	r7,_SFRPAGE
                           00020E  1722 	C$Hello.c$173$1$51 ==.
                                   1723 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:173: SFRPAGE  = CONFIG_PAGE;
      000270 75 84 0F         [24] 1724 	mov	_SFRPAGE,#0x0f
                           000211  1725 	C$Hello.c$174$1$51 ==.
                                   1726 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:174: XBR0     = 0x04;                    // Enable UART0
      000273 75 E1 04         [24] 1727 	mov	_XBR0,#0x04
                           000214  1728 	C$Hello.c$175$1$51 ==.
                                   1729 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:175: XBR1     = 0x00;
      000276 75 E2 00         [24] 1730 	mov	_XBR1,#0x00
                           000217  1731 	C$Hello.c$176$1$51 ==.
                                   1732 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:176: XBR2     = 0x40;                    // Enable Crossbar and weak pull-up
      000279 75 E3 40         [24] 1733 	mov	_XBR2,#0x40
                           00021A  1734 	C$Hello.c$177$1$51 ==.
                                   1735 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:177: P0MDOUT |= 0x01;                    // Set TX0 on P0.0 pin to push-pull
      00027C 43 A4 01         [24] 1736 	orl	_P0MDOUT,#0x01
                           00021D  1737 	C$Hello.c$178$1$51 ==.
                                   1738 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:178: P1MDOUT |= 0x40;                    // Set green LED output P1.6 to push-pull
      00027F 43 A5 40         [24] 1739 	orl	_P1MDOUT,#0x40
                           000220  1740 	C$Hello.c$180$1$51 ==.
                                   1741 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:180: SFRPAGE  = SFRPAGE_SAVE;            // Restore SFR page
      000282 8F 84            [24] 1742 	mov	_SFRPAGE,r7
                           000222  1743 	C$Hello.c$181$1$51 ==.
                           000222  1744 	XG$PORT_INIT$0$0 ==.
      000284 22               [24] 1745 	ret
                                   1746 ;------------------------------------------------------------
                                   1747 ;Allocation info for local variables in function 'UART0_INIT'
                                   1748 ;------------------------------------------------------------
                                   1749 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1750 ;------------------------------------------------------------
                           000223  1751 	G$UART0_INIT$0$0 ==.
                           000223  1752 	C$Hello.c$189$1$51 ==.
                                   1753 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:189: void UART0_INIT(void)
                                   1754 ;	-----------------------------------------
                                   1755 ;	 function UART0_INIT
                                   1756 ;	-----------------------------------------
      000285                       1757 _UART0_INIT:
                           000223  1758 	C$Hello.c$193$1$53 ==.
                                   1759 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:193: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      000285 AF 84            [24] 1760 	mov	r7,_SFRPAGE
                           000225  1761 	C$Hello.c$195$1$53 ==.
                                   1762 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:195: SFRPAGE = TIMER01_PAGE;
      000287 75 84 00         [24] 1763 	mov	_SFRPAGE,#0x00
                           000228  1764 	C$Hello.c$196$1$53 ==.
                                   1765 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:196: TMOD   &= ~0xF0;
      00028A 53 89 0F         [24] 1766 	anl	_TMOD,#0x0f
                           00022B  1767 	C$Hello.c$197$1$53 ==.
                                   1768 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:197: TMOD   |=  0x20;                    // Timer1, Mode 2, 8-bit reload
      00028D 43 89 20         [24] 1769 	orl	_TMOD,#0x20
                           00022E  1770 	C$Hello.c$198$1$53 ==.
                                   1771 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:198: TH1     = -(SYSCLK/BAUDRATE/16);    // Set Timer1 reload baudrate value T1 Hi Byte
      000290 75 8D E5         [24] 1772 	mov	_TH1,#0xe5
                           000231  1773 	C$Hello.c$199$1$53 ==.
                                   1774 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:199: CKCON  |= 0x10;                     // Timer1 uses SYSCLK as time base
      000293 43 8E 10         [24] 1775 	orl	_CKCON,#0x10
                           000234  1776 	C$Hello.c$200$1$53 ==.
                                   1777 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:200: TL1     = TH1;
      000296 85 8D 8B         [24] 1778 	mov	_TL1,_TH1
                           000237  1779 	C$Hello.c$201$1$53 ==.
                                   1780 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:201: TR1     = 1;                        // Start Timer1
      000299 D2 8E            [12] 1781 	setb	_TR1
                           000239  1782 	C$Hello.c$203$1$53 ==.
                                   1783 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:203: SFRPAGE = UART0_PAGE;
      00029B 75 84 00         [24] 1784 	mov	_SFRPAGE,#0x00
                           00023C  1785 	C$Hello.c$204$1$53 ==.
                                   1786 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:204: SCON0   = 0x50;                     // Mode 1, 8-bit UART, enable RX
      00029E 75 98 50         [24] 1787 	mov	_SCON0,#0x50
                           00023F  1788 	C$Hello.c$205$1$53 ==.
                                   1789 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:205: SSTA0   = 0x10;                     // SMOD0 = 1
      0002A1 75 91 10         [24] 1790 	mov	_SSTA0,#0x10
                           000242  1791 	C$Hello.c$206$1$53 ==.
                                   1792 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:206: TI0     = 1;                        // Indicate TX0 ready
      0002A4 D2 99            [12] 1793 	setb	_TI0
                           000244  1794 	C$Hello.c$208$1$53 ==.
                                   1795 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Code\Hello.c:208: SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
      0002A6 8F 84            [24] 1796 	mov	_SFRPAGE,r7
                           000246  1797 	C$Hello.c$209$1$53 ==.
                           000246  1798 	XG$UART0_INIT$0$0 ==.
      0002A8 22               [24] 1799 	ret
                                   1800 	.area CSEG    (CODE)
                                   1801 	.area CONST   (CODE)
                           000000  1802 FHello$__str_0$0$0 == .
      00091C                       1803 ___str_0:
      00091C 1B                    1804 	.db 0x1b
      00091D 5B 32 4A              1805 	.ascii "[2J"
      000920 00                    1806 	.db 0x00
                           000005  1807 FHello$__str_1$0$0 == .
      000921                       1808 ___str_1:
      000921 1B                    1809 	.db 0x1b
      000922 5B 30 3B 34 34 3B 33  1810 	.ascii "[0;44;33m"
             33 6D
      00092B 00                    1811 	.db 0x00
                           000010  1812 FHello$__str_2$0$0 == .
      00092C                       1813 ___str_2:
      00092C 1B                    1814 	.db 0x1b
      00092D 5B 32 3B 33 30 48 54  1815 	.ascii "[2;30HType <ESC> to end the program"
             79 70 65 20 3C 45 53
             43 3E 20 74 6F 20 65
             6E 64 20 74 68 65 20
             70 72 6F 67 72 61 6D
      000950 0A                    1816 	.db 0x0a
      000951 0A                    1817 	.db 0x0a
      000952 0A                    1818 	.db 0x0a
      000953 0A                    1819 	.db 0x0a
      000954 0D                    1820 	.db 0x0d
      000955 00                    1821 	.db 0x00
                           00003A  1822 FHello$__str_3$0$0 == .
      000956                       1823 ___str_3:
      000956 54 68 65 20 6B 65 79  1824 	.ascii "The keyboard character is: "
             62 6F 61 72 64 20 63
             68 61 72 61 63 74 65
             72 20 69 73 3A 20
      000971 00                    1825 	.db 0x00
                           000056  1826 FHello$__str_4$0$0 == .
      000972                       1827 ___str_4:
      000972 1B                    1828 	.db 0x1b
      000973 5B 31 32 3B 32 35 72  1829 	.ascii "[12;25r"
      00097A 00                    1830 	.db 0x00
                           00005F  1831 FHello$__str_5$0$0 == .
      00097B                       1832 ___str_5:
      00097B 1B                    1833 	.db 0x1b
      00097C 5B 48                 1834 	.ascii "[H"
      00097E 00                    1835 	.db 0x00
                           000063  1836 FHello$__str_6$0$0 == .
      00097F                       1837 ___str_6:
      00097F 1B                    1838 	.db 0x1b
      000980 5B 32 6B              1839 	.ascii "[2k"
      000983 00                    1840 	.db 0x00
                           000068  1841 FHello$__str_7$0$0 == .
      000984                       1842 ___str_7:
      000984 1B                    1843 	.db 0x1b
      000985 5B 25 69 3B 34 30 48  1844 	.ascii "[%i;40H "
             20
      00098D 0A                    1845 	.db 0x0a
      00098E 00                    1846 	.db 0x00
                           000073  1847 FHello$__str_8$0$0 == .
      00098F                       1848 ___str_8:
      00098F 54 68 65 20 6B 65 79  1849 	.ascii "The keyboard character %x is"
             62 6F 61 72 64 20 63
             68 61 72 61 63 74 65
             72 20 25 78 20 69 73
      0009AB 1B                    1850 	.db 0x1b
      0009AC 5B 34 3B 35 6D 20 6E  1851 	.ascii "[4;5m not printable"
             6F 74 20 70 72 69 6E
             74 61 62 6C 65
      0009BF 1B                    1852 	.db 0x1b
      0009C0 5B 30 3B 34 34 3B 33  1853 	.ascii "[0;44;33m"
             33 6D
      0009C9 00                    1854 	.db 0x00
                           0000AE  1855 FHello$__str_9$0$0 == .
      0009CA                       1856 ___str_9:
      0009CA 1B                    1857 	.db 0x1b
      0009CB 5B 36 3B 32 38 48     1858 	.ascii "[6;28H"
      0009D1 00                    1859 	.db 0x00
                           0000B6  1860 FHello$__str_10$0$0 == .
      0009D2                       1861 ___str_10:
      0009D2 1B                    1862 	.db 0x1b
      0009D3 5B 33 37 6D 25 63     1863 	.ascii "[37m%c"
      0009D9 00                    1864 	.db 0x00
                                   1865 	.area XINIT   (CODE)
                                   1866 	.area CABS    (ABS,CODE)
