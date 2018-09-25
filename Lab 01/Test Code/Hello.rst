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
                                     11 	.globl _printf
                                     12 	.globl _LED3
                                     13 	.globl _LED2
                                     14 	.globl _LED1
                                     15 	.globl _LED0
                                     16 	.globl _Pot3
                                     17 	.globl _Pot2
                                     18 	.globl _Pot1
                                     19 	.globl _Pot0
                                     20 	.globl _P7_7
                                     21 	.globl _P7_6
                                     22 	.globl _P7_5
                                     23 	.globl _P7_4
                                     24 	.globl _P7_3
                                     25 	.globl _P7_2
                                     26 	.globl _P7_1
                                     27 	.globl _P7_0
                                     28 	.globl _SPIF
                                     29 	.globl _WCOL
                                     30 	.globl _MODF
                                     31 	.globl _RXOVRN
                                     32 	.globl _NSSMD1
                                     33 	.globl _NSSMD0
                                     34 	.globl _TXBMT
                                     35 	.globl _SPIEN
                                     36 	.globl _P6_7
                                     37 	.globl _P6_6
                                     38 	.globl _P6_5
                                     39 	.globl _P6_4
                                     40 	.globl _P6_3
                                     41 	.globl _P6_2
                                     42 	.globl _P6_1
                                     43 	.globl _P6_0
                                     44 	.globl _AD2EN
                                     45 	.globl _AD2TM
                                     46 	.globl _AD2INT
                                     47 	.globl _AD2BUSY
                                     48 	.globl _AD2CM2
                                     49 	.globl _AD2CM1
                                     50 	.globl _AD2CM0
                                     51 	.globl _AD2WINT
                                     52 	.globl _AD0EN
                                     53 	.globl _AD0TM
                                     54 	.globl _AD0INT
                                     55 	.globl _AD0BUSY
                                     56 	.globl _AD0CM1
                                     57 	.globl _AD0CM0
                                     58 	.globl _AD0WINT
                                     59 	.globl _AD0LJST
                                     60 	.globl _P5_7
                                     61 	.globl _P5_6
                                     62 	.globl _P5_5
                                     63 	.globl _P5_4
                                     64 	.globl _P5_3
                                     65 	.globl _P5_2
                                     66 	.globl _P5_1
                                     67 	.globl _P5_0
                                     68 	.globl _CF
                                     69 	.globl _CR
                                     70 	.globl _CCF5
                                     71 	.globl _CCF4
                                     72 	.globl _CCF3
                                     73 	.globl _CCF2
                                     74 	.globl _CCF1
                                     75 	.globl _CCF0
                                     76 	.globl _CY
                                     77 	.globl _AC
                                     78 	.globl _F0
                                     79 	.globl _RS1
                                     80 	.globl _RS0
                                     81 	.globl _OV
                                     82 	.globl _F1
                                     83 	.globl _P
                                     84 	.globl _P4_7
                                     85 	.globl _P4_6
                                     86 	.globl _P4_5
                                     87 	.globl _P4_4
                                     88 	.globl _P4_3
                                     89 	.globl _P4_2
                                     90 	.globl _P4_1
                                     91 	.globl _P4_0
                                     92 	.globl _TF4
                                     93 	.globl _EXF4
                                     94 	.globl _EXEN4
                                     95 	.globl _TR4
                                     96 	.globl _CT4
                                     97 	.globl _CPRL4
                                     98 	.globl _TF3
                                     99 	.globl _EXF3
                                    100 	.globl _EXEN3
                                    101 	.globl _TR3
                                    102 	.globl _CT3
                                    103 	.globl _CPRL3
                                    104 	.globl _TF2
                                    105 	.globl _EXF2
                                    106 	.globl _EXEN2
                                    107 	.globl _TR2
                                    108 	.globl _CT2
                                    109 	.globl _CPRL2
                                    110 	.globl _MAC0HO
                                    111 	.globl _MAC0Z
                                    112 	.globl _MAC0SO
                                    113 	.globl _MAC0N
                                    114 	.globl _BUSY
                                    115 	.globl _ENSMB
                                    116 	.globl _STA
                                    117 	.globl _STO
                                    118 	.globl _SI
                                    119 	.globl _AA
                                    120 	.globl _SMBFTE
                                    121 	.globl _SMBTOE
                                    122 	.globl _PT2
                                    123 	.globl _PS
                                    124 	.globl _PS0
                                    125 	.globl _PT1
                                    126 	.globl _PX1
                                    127 	.globl _PT0
                                    128 	.globl _PX0
                                    129 	.globl _P3_7
                                    130 	.globl _P3_6
                                    131 	.globl _P3_5
                                    132 	.globl _P3_4
                                    133 	.globl _P3_3
                                    134 	.globl _P3_2
                                    135 	.globl _P3_1
                                    136 	.globl _P3_0
                                    137 	.globl _EA
                                    138 	.globl _ET2
                                    139 	.globl _ES
                                    140 	.globl _ES0
                                    141 	.globl _ET1
                                    142 	.globl _EX1
                                    143 	.globl _ET0
                                    144 	.globl _EX0
                                    145 	.globl _P2_7
                                    146 	.globl _P2_6
                                    147 	.globl _P2_5
                                    148 	.globl _P2_4
                                    149 	.globl _P2_3
                                    150 	.globl _P2_2
                                    151 	.globl _P2_1
                                    152 	.globl _P2_0
                                    153 	.globl _S1MODE
                                    154 	.globl _MCE1
                                    155 	.globl _REN1
                                    156 	.globl _TB81
                                    157 	.globl _RB81
                                    158 	.globl _TI1
                                    159 	.globl _RI1
                                    160 	.globl _SM00
                                    161 	.globl _SM10
                                    162 	.globl _SM20
                                    163 	.globl _REN
                                    164 	.globl _REN0
                                    165 	.globl _TB80
                                    166 	.globl _RB80
                                    167 	.globl _TI
                                    168 	.globl _TI0
                                    169 	.globl _RI
                                    170 	.globl _RI0
                                    171 	.globl _P1_7
                                    172 	.globl _P1_6
                                    173 	.globl _P1_5
                                    174 	.globl _P1_4
                                    175 	.globl _P1_3
                                    176 	.globl _P1_2
                                    177 	.globl _P1_1
                                    178 	.globl _P1_0
                                    179 	.globl _FLHBUSY
                                    180 	.globl _CP1EN
                                    181 	.globl _CP1OUT
                                    182 	.globl _CP1RIF
                                    183 	.globl _CP1FIF
                                    184 	.globl _CP1HYP1
                                    185 	.globl _CP1HYP0
                                    186 	.globl _CP1HYN1
                                    187 	.globl _CP1HYN0
                                    188 	.globl _CP0EN
                                    189 	.globl _CP0OUT
                                    190 	.globl _CP0RIF
                                    191 	.globl _CP0FIF
                                    192 	.globl _CP0HYP1
                                    193 	.globl _CP0HYP0
                                    194 	.globl _CP0HYN1
                                    195 	.globl _CP0HYN0
                                    196 	.globl _TF1
                                    197 	.globl _TR1
                                    198 	.globl _TF0
                                    199 	.globl _TR0
                                    200 	.globl _IE1
                                    201 	.globl _IT1
                                    202 	.globl _IE0
                                    203 	.globl _IT0
                                    204 	.globl _P0_7
                                    205 	.globl _P0_6
                                    206 	.globl _P0_5
                                    207 	.globl _P0_4
                                    208 	.globl _P0_3
                                    209 	.globl _P0_2
                                    210 	.globl _P0_1
                                    211 	.globl _P0_0
                                    212 	.globl _MAC0RND
                                    213 	.globl _MAC0ACC
                                    214 	.globl _MAC0A
                                    215 	.globl _RCAP4
                                    216 	.globl _TMR4
                                    217 	.globl _DAC1
                                    218 	.globl _RCAP3
                                    219 	.globl _TMR3
                                    220 	.globl _PCA0CP5
                                    221 	.globl _PCA0CP4
                                    222 	.globl _PCA0CP3
                                    223 	.globl _PCA0CP2
                                    224 	.globl _PCA0CP1
                                    225 	.globl _PCA0CP0
                                    226 	.globl _PCA0
                                    227 	.globl _DAC0
                                    228 	.globl _ADC0LT
                                    229 	.globl _ADC0GT
                                    230 	.globl _ADC0
                                    231 	.globl _RCAP2
                                    232 	.globl _TMR2
                                    233 	.globl _TMR1
                                    234 	.globl _TMR0
                                    235 	.globl _P7
                                    236 	.globl _P6
                                    237 	.globl _XBR2
                                    238 	.globl _XBR1
                                    239 	.globl _XBR0
                                    240 	.globl _P5
                                    241 	.globl _P4
                                    242 	.globl _FLACL
                                    243 	.globl _P1MDIN
                                    244 	.globl _P3MDOUT
                                    245 	.globl _P2MDOUT
                                    246 	.globl _P1MDOUT
                                    247 	.globl _P0MDOUT
                                    248 	.globl _CCH0LC
                                    249 	.globl _CCH0TN
                                    250 	.globl _CCH0CN
                                    251 	.globl _P7MDOUT
                                    252 	.globl _P6MDOUT
                                    253 	.globl _P5MDOUT
                                    254 	.globl _P4MDOUT
                                    255 	.globl _CCH0MA
                                    256 	.globl _CLKSEL
                                    257 	.globl _SFRPGCN
                                    258 	.globl _PLL0FLT
                                    259 	.globl _PLL0MUL
                                    260 	.globl _PLL0DIV
                                    261 	.globl _OSCXCN
                                    262 	.globl _OSCICL
                                    263 	.globl _OSCICN
                                    264 	.globl _PLL0CN
                                    265 	.globl _FLSTAT
                                    266 	.globl _MAC0RNDH
                                    267 	.globl _MAC0RNDL
                                    268 	.globl _MAC0CF
                                    269 	.globl _MAC0AH
                                    270 	.globl _MAC0AL
                                    271 	.globl _MAC0STA
                                    272 	.globl _MAC0OVR
                                    273 	.globl _MAC0ACC3
                                    274 	.globl _MAC0ACC2
                                    275 	.globl _MAC0ACC1
                                    276 	.globl _MAC0ACC0
                                    277 	.globl _MAC0BH
                                    278 	.globl _MAC0BL
                                    279 	.globl _ADC2CN
                                    280 	.globl _TMR4H
                                    281 	.globl _TMR4L
                                    282 	.globl _RCAP4H
                                    283 	.globl _RCAP4L
                                    284 	.globl _TMR4CF
                                    285 	.globl _TMR4CN
                                    286 	.globl _ADC2LT
                                    287 	.globl _ADC2GT
                                    288 	.globl _ADC2
                                    289 	.globl _ADC2CF
                                    290 	.globl _AMX2SL
                                    291 	.globl _AMX2CF
                                    292 	.globl _CPT1MD
                                    293 	.globl _CPT1CN
                                    294 	.globl _DAC1CN
                                    295 	.globl _DAC1H
                                    296 	.globl _DAC1L
                                    297 	.globl _TMR3H
                                    298 	.globl _TMR3L
                                    299 	.globl _RCAP3H
                                    300 	.globl _RCAP3L
                                    301 	.globl _TMR3CF
                                    302 	.globl _TMR3CN
                                    303 	.globl _SBUF1
                                    304 	.globl _SCON1
                                    305 	.globl _CPT0MD
                                    306 	.globl _CPT0CN
                                    307 	.globl _PCA0CPH1
                                    308 	.globl _PCA0CPL1
                                    309 	.globl _PCA0CPH0
                                    310 	.globl _PCA0CPL0
                                    311 	.globl _PCA0H
                                    312 	.globl _PCA0L
                                    313 	.globl _SPI0CN
                                    314 	.globl _RSTSRC
                                    315 	.globl _PCA0CPH4
                                    316 	.globl _PCA0CPL4
                                    317 	.globl _PCA0CPH3
                                    318 	.globl _PCA0CPL3
                                    319 	.globl _PCA0CPH2
                                    320 	.globl _PCA0CPL2
                                    321 	.globl _ADC0CN
                                    322 	.globl _PCA0CPH5
                                    323 	.globl _PCA0CPL5
                                    324 	.globl _PCA0CPM5
                                    325 	.globl _PCA0CPM4
                                    326 	.globl _PCA0CPM3
                                    327 	.globl _PCA0CPM2
                                    328 	.globl _PCA0CPM1
                                    329 	.globl _PCA0CPM0
                                    330 	.globl _PCA0MD
                                    331 	.globl _PCA0CN
                                    332 	.globl _DAC0CN
                                    333 	.globl _DAC0H
                                    334 	.globl _DAC0L
                                    335 	.globl _REF0CN
                                    336 	.globl _SMB0CR
                                    337 	.globl _TH2
                                    338 	.globl _TMR2H
                                    339 	.globl _TL2
                                    340 	.globl _TMR2L
                                    341 	.globl _RCAP2H
                                    342 	.globl _RCAP2L
                                    343 	.globl _TMR2CF
                                    344 	.globl _TMR2CN
                                    345 	.globl _ADC0LTH
                                    346 	.globl _ADC0LTL
                                    347 	.globl _ADC0GTH
                                    348 	.globl _ADC0GTL
                                    349 	.globl _SMB0ADR
                                    350 	.globl _SMB0DAT
                                    351 	.globl _SMB0STA
                                    352 	.globl _SMB0CN
                                    353 	.globl _ADC0H
                                    354 	.globl _ADC0L
                                    355 	.globl _ADC0CF
                                    356 	.globl _AMX0SL
                                    357 	.globl _AMX0CF
                                    358 	.globl _SADEN0
                                    359 	.globl _FLSCL
                                    360 	.globl _SADDR0
                                    361 	.globl _EMI0CF
                                    362 	.globl __XPAGE
                                    363 	.globl _EMI0CN
                                    364 	.globl _EMI0TC
                                    365 	.globl _SPI0CKR
                                    366 	.globl _SPI0DAT
                                    367 	.globl _SPI0CFG
                                    368 	.globl _SBUF
                                    369 	.globl _SBUF0
                                    370 	.globl _SCON
                                    371 	.globl _SCON0
                                    372 	.globl _SSTA0
                                    373 	.globl _PSCTL
                                    374 	.globl _CKCON
                                    375 	.globl _TH1
                                    376 	.globl _TH0
                                    377 	.globl _TL1
                                    378 	.globl _TL0
                                    379 	.globl _TMOD
                                    380 	.globl _TCON
                                    381 	.globl _WDTCN
                                    382 	.globl _EIP2
                                    383 	.globl _EIP1
                                    384 	.globl _B
                                    385 	.globl _EIE2
                                    386 	.globl _EIE1
                                    387 	.globl _ACC
                                    388 	.globl _PSW
                                    389 	.globl _IP
                                    390 	.globl _PSBANK
                                    391 	.globl _P3
                                    392 	.globl _IE
                                    393 	.globl _P2
                                    394 	.globl _P1
                                    395 	.globl _PCON
                                    396 	.globl _SFRLAST
                                    397 	.globl _SFRNEXT
                                    398 	.globl _SFRPAGE
                                    399 	.globl _DPH
                                    400 	.globl _DPL
                                    401 	.globl _SP
                                    402 	.globl _P0
                                    403 	.globl _putchar
                                    404 	.globl _getchar
                                    405 	.globl _main
                                    406 	.globl _SYSCLK_INIT
                                    407 	.globl _PORT_INIT
                                    408 	.globl _UART0_INIT
                                    409 ;--------------------------------------------------------
                                    410 ; special function registers
                                    411 ;--------------------------------------------------------
                                    412 	.area RSEG    (ABS,DATA)
      000000                        413 	.org 0x0000
                           000080   414 G$P0$0$0 == 0x0080
                           000080   415 _P0	=	0x0080
                           000081   416 G$SP$0$0 == 0x0081
                           000081   417 _SP	=	0x0081
                           000082   418 G$DPL$0$0 == 0x0082
                           000082   419 _DPL	=	0x0082
                           000083   420 G$DPH$0$0 == 0x0083
                           000083   421 _DPH	=	0x0083
                           000084   422 G$SFRPAGE$0$0 == 0x0084
                           000084   423 _SFRPAGE	=	0x0084
                           000085   424 G$SFRNEXT$0$0 == 0x0085
                           000085   425 _SFRNEXT	=	0x0085
                           000086   426 G$SFRLAST$0$0 == 0x0086
                           000086   427 _SFRLAST	=	0x0086
                           000087   428 G$PCON$0$0 == 0x0087
                           000087   429 _PCON	=	0x0087
                           000090   430 G$P1$0$0 == 0x0090
                           000090   431 _P1	=	0x0090
                           0000A0   432 G$P2$0$0 == 0x00a0
                           0000A0   433 _P2	=	0x00a0
                           0000A8   434 G$IE$0$0 == 0x00a8
                           0000A8   435 _IE	=	0x00a8
                           0000B0   436 G$P3$0$0 == 0x00b0
                           0000B0   437 _P3	=	0x00b0
                           0000B1   438 G$PSBANK$0$0 == 0x00b1
                           0000B1   439 _PSBANK	=	0x00b1
                           0000B8   440 G$IP$0$0 == 0x00b8
                           0000B8   441 _IP	=	0x00b8
                           0000D0   442 G$PSW$0$0 == 0x00d0
                           0000D0   443 _PSW	=	0x00d0
                           0000E0   444 G$ACC$0$0 == 0x00e0
                           0000E0   445 _ACC	=	0x00e0
                           0000E6   446 G$EIE1$0$0 == 0x00e6
                           0000E6   447 _EIE1	=	0x00e6
                           0000E7   448 G$EIE2$0$0 == 0x00e7
                           0000E7   449 _EIE2	=	0x00e7
                           0000F0   450 G$B$0$0 == 0x00f0
                           0000F0   451 _B	=	0x00f0
                           0000F6   452 G$EIP1$0$0 == 0x00f6
                           0000F6   453 _EIP1	=	0x00f6
                           0000F7   454 G$EIP2$0$0 == 0x00f7
                           0000F7   455 _EIP2	=	0x00f7
                           0000FF   456 G$WDTCN$0$0 == 0x00ff
                           0000FF   457 _WDTCN	=	0x00ff
                           000088   458 G$TCON$0$0 == 0x0088
                           000088   459 _TCON	=	0x0088
                           000089   460 G$TMOD$0$0 == 0x0089
                           000089   461 _TMOD	=	0x0089
                           00008A   462 G$TL0$0$0 == 0x008a
                           00008A   463 _TL0	=	0x008a
                           00008B   464 G$TL1$0$0 == 0x008b
                           00008B   465 _TL1	=	0x008b
                           00008C   466 G$TH0$0$0 == 0x008c
                           00008C   467 _TH0	=	0x008c
                           00008D   468 G$TH1$0$0 == 0x008d
                           00008D   469 _TH1	=	0x008d
                           00008E   470 G$CKCON$0$0 == 0x008e
                           00008E   471 _CKCON	=	0x008e
                           00008F   472 G$PSCTL$0$0 == 0x008f
                           00008F   473 _PSCTL	=	0x008f
                           000091   474 G$SSTA0$0$0 == 0x0091
                           000091   475 _SSTA0	=	0x0091
                           000098   476 G$SCON0$0$0 == 0x0098
                           000098   477 _SCON0	=	0x0098
                           000098   478 G$SCON$0$0 == 0x0098
                           000098   479 _SCON	=	0x0098
                           000099   480 G$SBUF0$0$0 == 0x0099
                           000099   481 _SBUF0	=	0x0099
                           000099   482 G$SBUF$0$0 == 0x0099
                           000099   483 _SBUF	=	0x0099
                           00009A   484 G$SPI0CFG$0$0 == 0x009a
                           00009A   485 _SPI0CFG	=	0x009a
                           00009B   486 G$SPI0DAT$0$0 == 0x009b
                           00009B   487 _SPI0DAT	=	0x009b
                           00009D   488 G$SPI0CKR$0$0 == 0x009d
                           00009D   489 _SPI0CKR	=	0x009d
                           0000A1   490 G$EMI0TC$0$0 == 0x00a1
                           0000A1   491 _EMI0TC	=	0x00a1
                           0000A2   492 G$EMI0CN$0$0 == 0x00a2
                           0000A2   493 _EMI0CN	=	0x00a2
                           0000A2   494 G$_XPAGE$0$0 == 0x00a2
                           0000A2   495 __XPAGE	=	0x00a2
                           0000A3   496 G$EMI0CF$0$0 == 0x00a3
                           0000A3   497 _EMI0CF	=	0x00a3
                           0000A9   498 G$SADDR0$0$0 == 0x00a9
                           0000A9   499 _SADDR0	=	0x00a9
                           0000B7   500 G$FLSCL$0$0 == 0x00b7
                           0000B7   501 _FLSCL	=	0x00b7
                           0000B9   502 G$SADEN0$0$0 == 0x00b9
                           0000B9   503 _SADEN0	=	0x00b9
                           0000BA   504 G$AMX0CF$0$0 == 0x00ba
                           0000BA   505 _AMX0CF	=	0x00ba
                           0000BB   506 G$AMX0SL$0$0 == 0x00bb
                           0000BB   507 _AMX0SL	=	0x00bb
                           0000BC   508 G$ADC0CF$0$0 == 0x00bc
                           0000BC   509 _ADC0CF	=	0x00bc
                           0000BE   510 G$ADC0L$0$0 == 0x00be
                           0000BE   511 _ADC0L	=	0x00be
                           0000BF   512 G$ADC0H$0$0 == 0x00bf
                           0000BF   513 _ADC0H	=	0x00bf
                           0000C0   514 G$SMB0CN$0$0 == 0x00c0
                           0000C0   515 _SMB0CN	=	0x00c0
                           0000C1   516 G$SMB0STA$0$0 == 0x00c1
                           0000C1   517 _SMB0STA	=	0x00c1
                           0000C2   518 G$SMB0DAT$0$0 == 0x00c2
                           0000C2   519 _SMB0DAT	=	0x00c2
                           0000C3   520 G$SMB0ADR$0$0 == 0x00c3
                           0000C3   521 _SMB0ADR	=	0x00c3
                           0000C4   522 G$ADC0GTL$0$0 == 0x00c4
                           0000C4   523 _ADC0GTL	=	0x00c4
                           0000C5   524 G$ADC0GTH$0$0 == 0x00c5
                           0000C5   525 _ADC0GTH	=	0x00c5
                           0000C6   526 G$ADC0LTL$0$0 == 0x00c6
                           0000C6   527 _ADC0LTL	=	0x00c6
                           0000C7   528 G$ADC0LTH$0$0 == 0x00c7
                           0000C7   529 _ADC0LTH	=	0x00c7
                           0000C8   530 G$TMR2CN$0$0 == 0x00c8
                           0000C8   531 _TMR2CN	=	0x00c8
                           0000C9   532 G$TMR2CF$0$0 == 0x00c9
                           0000C9   533 _TMR2CF	=	0x00c9
                           0000CA   534 G$RCAP2L$0$0 == 0x00ca
                           0000CA   535 _RCAP2L	=	0x00ca
                           0000CB   536 G$RCAP2H$0$0 == 0x00cb
                           0000CB   537 _RCAP2H	=	0x00cb
                           0000CC   538 G$TMR2L$0$0 == 0x00cc
                           0000CC   539 _TMR2L	=	0x00cc
                           0000CC   540 G$TL2$0$0 == 0x00cc
                           0000CC   541 _TL2	=	0x00cc
                           0000CD   542 G$TMR2H$0$0 == 0x00cd
                           0000CD   543 _TMR2H	=	0x00cd
                           0000CD   544 G$TH2$0$0 == 0x00cd
                           0000CD   545 _TH2	=	0x00cd
                           0000CF   546 G$SMB0CR$0$0 == 0x00cf
                           0000CF   547 _SMB0CR	=	0x00cf
                           0000D1   548 G$REF0CN$0$0 == 0x00d1
                           0000D1   549 _REF0CN	=	0x00d1
                           0000D2   550 G$DAC0L$0$0 == 0x00d2
                           0000D2   551 _DAC0L	=	0x00d2
                           0000D3   552 G$DAC0H$0$0 == 0x00d3
                           0000D3   553 _DAC0H	=	0x00d3
                           0000D4   554 G$DAC0CN$0$0 == 0x00d4
                           0000D4   555 _DAC0CN	=	0x00d4
                           0000D8   556 G$PCA0CN$0$0 == 0x00d8
                           0000D8   557 _PCA0CN	=	0x00d8
                           0000D9   558 G$PCA0MD$0$0 == 0x00d9
                           0000D9   559 _PCA0MD	=	0x00d9
                           0000DA   560 G$PCA0CPM0$0$0 == 0x00da
                           0000DA   561 _PCA0CPM0	=	0x00da
                           0000DB   562 G$PCA0CPM1$0$0 == 0x00db
                           0000DB   563 _PCA0CPM1	=	0x00db
                           0000DC   564 G$PCA0CPM2$0$0 == 0x00dc
                           0000DC   565 _PCA0CPM2	=	0x00dc
                           0000DD   566 G$PCA0CPM3$0$0 == 0x00dd
                           0000DD   567 _PCA0CPM3	=	0x00dd
                           0000DE   568 G$PCA0CPM4$0$0 == 0x00de
                           0000DE   569 _PCA0CPM4	=	0x00de
                           0000DF   570 G$PCA0CPM5$0$0 == 0x00df
                           0000DF   571 _PCA0CPM5	=	0x00df
                           0000E1   572 G$PCA0CPL5$0$0 == 0x00e1
                           0000E1   573 _PCA0CPL5	=	0x00e1
                           0000E2   574 G$PCA0CPH5$0$0 == 0x00e2
                           0000E2   575 _PCA0CPH5	=	0x00e2
                           0000E8   576 G$ADC0CN$0$0 == 0x00e8
                           0000E8   577 _ADC0CN	=	0x00e8
                           0000E9   578 G$PCA0CPL2$0$0 == 0x00e9
                           0000E9   579 _PCA0CPL2	=	0x00e9
                           0000EA   580 G$PCA0CPH2$0$0 == 0x00ea
                           0000EA   581 _PCA0CPH2	=	0x00ea
                           0000EB   582 G$PCA0CPL3$0$0 == 0x00eb
                           0000EB   583 _PCA0CPL3	=	0x00eb
                           0000EC   584 G$PCA0CPH3$0$0 == 0x00ec
                           0000EC   585 _PCA0CPH3	=	0x00ec
                           0000ED   586 G$PCA0CPL4$0$0 == 0x00ed
                           0000ED   587 _PCA0CPL4	=	0x00ed
                           0000EE   588 G$PCA0CPH4$0$0 == 0x00ee
                           0000EE   589 _PCA0CPH4	=	0x00ee
                           0000EF   590 G$RSTSRC$0$0 == 0x00ef
                           0000EF   591 _RSTSRC	=	0x00ef
                           0000F8   592 G$SPI0CN$0$0 == 0x00f8
                           0000F8   593 _SPI0CN	=	0x00f8
                           0000F9   594 G$PCA0L$0$0 == 0x00f9
                           0000F9   595 _PCA0L	=	0x00f9
                           0000FA   596 G$PCA0H$0$0 == 0x00fa
                           0000FA   597 _PCA0H	=	0x00fa
                           0000FB   598 G$PCA0CPL0$0$0 == 0x00fb
                           0000FB   599 _PCA0CPL0	=	0x00fb
                           0000FC   600 G$PCA0CPH0$0$0 == 0x00fc
                           0000FC   601 _PCA0CPH0	=	0x00fc
                           0000FD   602 G$PCA0CPL1$0$0 == 0x00fd
                           0000FD   603 _PCA0CPL1	=	0x00fd
                           0000FE   604 G$PCA0CPH1$0$0 == 0x00fe
                           0000FE   605 _PCA0CPH1	=	0x00fe
                           000088   606 G$CPT0CN$0$0 == 0x0088
                           000088   607 _CPT0CN	=	0x0088
                           000089   608 G$CPT0MD$0$0 == 0x0089
                           000089   609 _CPT0MD	=	0x0089
                           000098   610 G$SCON1$0$0 == 0x0098
                           000098   611 _SCON1	=	0x0098
                           000099   612 G$SBUF1$0$0 == 0x0099
                           000099   613 _SBUF1	=	0x0099
                           0000C8   614 G$TMR3CN$0$0 == 0x00c8
                           0000C8   615 _TMR3CN	=	0x00c8
                           0000C9   616 G$TMR3CF$0$0 == 0x00c9
                           0000C9   617 _TMR3CF	=	0x00c9
                           0000CA   618 G$RCAP3L$0$0 == 0x00ca
                           0000CA   619 _RCAP3L	=	0x00ca
                           0000CB   620 G$RCAP3H$0$0 == 0x00cb
                           0000CB   621 _RCAP3H	=	0x00cb
                           0000CC   622 G$TMR3L$0$0 == 0x00cc
                           0000CC   623 _TMR3L	=	0x00cc
                           0000CD   624 G$TMR3H$0$0 == 0x00cd
                           0000CD   625 _TMR3H	=	0x00cd
                           0000D2   626 G$DAC1L$0$0 == 0x00d2
                           0000D2   627 _DAC1L	=	0x00d2
                           0000D3   628 G$DAC1H$0$0 == 0x00d3
                           0000D3   629 _DAC1H	=	0x00d3
                           0000D4   630 G$DAC1CN$0$0 == 0x00d4
                           0000D4   631 _DAC1CN	=	0x00d4
                           000088   632 G$CPT1CN$0$0 == 0x0088
                           000088   633 _CPT1CN	=	0x0088
                           000089   634 G$CPT1MD$0$0 == 0x0089
                           000089   635 _CPT1MD	=	0x0089
                           0000BA   636 G$AMX2CF$0$0 == 0x00ba
                           0000BA   637 _AMX2CF	=	0x00ba
                           0000BB   638 G$AMX2SL$0$0 == 0x00bb
                           0000BB   639 _AMX2SL	=	0x00bb
                           0000BC   640 G$ADC2CF$0$0 == 0x00bc
                           0000BC   641 _ADC2CF	=	0x00bc
                           0000BE   642 G$ADC2$0$0 == 0x00be
                           0000BE   643 _ADC2	=	0x00be
                           0000C4   644 G$ADC2GT$0$0 == 0x00c4
                           0000C4   645 _ADC2GT	=	0x00c4
                           0000C6   646 G$ADC2LT$0$0 == 0x00c6
                           0000C6   647 _ADC2LT	=	0x00c6
                           0000C8   648 G$TMR4CN$0$0 == 0x00c8
                           0000C8   649 _TMR4CN	=	0x00c8
                           0000C9   650 G$TMR4CF$0$0 == 0x00c9
                           0000C9   651 _TMR4CF	=	0x00c9
                           0000CA   652 G$RCAP4L$0$0 == 0x00ca
                           0000CA   653 _RCAP4L	=	0x00ca
                           0000CB   654 G$RCAP4H$0$0 == 0x00cb
                           0000CB   655 _RCAP4H	=	0x00cb
                           0000CC   656 G$TMR4L$0$0 == 0x00cc
                           0000CC   657 _TMR4L	=	0x00cc
                           0000CD   658 G$TMR4H$0$0 == 0x00cd
                           0000CD   659 _TMR4H	=	0x00cd
                           0000E8   660 G$ADC2CN$0$0 == 0x00e8
                           0000E8   661 _ADC2CN	=	0x00e8
                           000091   662 G$MAC0BL$0$0 == 0x0091
                           000091   663 _MAC0BL	=	0x0091
                           000092   664 G$MAC0BH$0$0 == 0x0092
                           000092   665 _MAC0BH	=	0x0092
                           000093   666 G$MAC0ACC0$0$0 == 0x0093
                           000093   667 _MAC0ACC0	=	0x0093
                           000094   668 G$MAC0ACC1$0$0 == 0x0094
                           000094   669 _MAC0ACC1	=	0x0094
                           000095   670 G$MAC0ACC2$0$0 == 0x0095
                           000095   671 _MAC0ACC2	=	0x0095
                           000096   672 G$MAC0ACC3$0$0 == 0x0096
                           000096   673 _MAC0ACC3	=	0x0096
                           000097   674 G$MAC0OVR$0$0 == 0x0097
                           000097   675 _MAC0OVR	=	0x0097
                           0000C0   676 G$MAC0STA$0$0 == 0x00c0
                           0000C0   677 _MAC0STA	=	0x00c0
                           0000C1   678 G$MAC0AL$0$0 == 0x00c1
                           0000C1   679 _MAC0AL	=	0x00c1
                           0000C2   680 G$MAC0AH$0$0 == 0x00c2
                           0000C2   681 _MAC0AH	=	0x00c2
                           0000C3   682 G$MAC0CF$0$0 == 0x00c3
                           0000C3   683 _MAC0CF	=	0x00c3
                           0000CE   684 G$MAC0RNDL$0$0 == 0x00ce
                           0000CE   685 _MAC0RNDL	=	0x00ce
                           0000CF   686 G$MAC0RNDH$0$0 == 0x00cf
                           0000CF   687 _MAC0RNDH	=	0x00cf
                           000088   688 G$FLSTAT$0$0 == 0x0088
                           000088   689 _FLSTAT	=	0x0088
                           000089   690 G$PLL0CN$0$0 == 0x0089
                           000089   691 _PLL0CN	=	0x0089
                           00008A   692 G$OSCICN$0$0 == 0x008a
                           00008A   693 _OSCICN	=	0x008a
                           00008B   694 G$OSCICL$0$0 == 0x008b
                           00008B   695 _OSCICL	=	0x008b
                           00008C   696 G$OSCXCN$0$0 == 0x008c
                           00008C   697 _OSCXCN	=	0x008c
                           00008D   698 G$PLL0DIV$0$0 == 0x008d
                           00008D   699 _PLL0DIV	=	0x008d
                           00008E   700 G$PLL0MUL$0$0 == 0x008e
                           00008E   701 _PLL0MUL	=	0x008e
                           00008F   702 G$PLL0FLT$0$0 == 0x008f
                           00008F   703 _PLL0FLT	=	0x008f
                           000096   704 G$SFRPGCN$0$0 == 0x0096
                           000096   705 _SFRPGCN	=	0x0096
                           000097   706 G$CLKSEL$0$0 == 0x0097
                           000097   707 _CLKSEL	=	0x0097
                           00009A   708 G$CCH0MA$0$0 == 0x009a
                           00009A   709 _CCH0MA	=	0x009a
                           00009C   710 G$P4MDOUT$0$0 == 0x009c
                           00009C   711 _P4MDOUT	=	0x009c
                           00009D   712 G$P5MDOUT$0$0 == 0x009d
                           00009D   713 _P5MDOUT	=	0x009d
                           00009E   714 G$P6MDOUT$0$0 == 0x009e
                           00009E   715 _P6MDOUT	=	0x009e
                           00009F   716 G$P7MDOUT$0$0 == 0x009f
                           00009F   717 _P7MDOUT	=	0x009f
                           0000A1   718 G$CCH0CN$0$0 == 0x00a1
                           0000A1   719 _CCH0CN	=	0x00a1
                           0000A2   720 G$CCH0TN$0$0 == 0x00a2
                           0000A2   721 _CCH0TN	=	0x00a2
                           0000A3   722 G$CCH0LC$0$0 == 0x00a3
                           0000A3   723 _CCH0LC	=	0x00a3
                           0000A4   724 G$P0MDOUT$0$0 == 0x00a4
                           0000A4   725 _P0MDOUT	=	0x00a4
                           0000A5   726 G$P1MDOUT$0$0 == 0x00a5
                           0000A5   727 _P1MDOUT	=	0x00a5
                           0000A6   728 G$P2MDOUT$0$0 == 0x00a6
                           0000A6   729 _P2MDOUT	=	0x00a6
                           0000A7   730 G$P3MDOUT$0$0 == 0x00a7
                           0000A7   731 _P3MDOUT	=	0x00a7
                           0000AD   732 G$P1MDIN$0$0 == 0x00ad
                           0000AD   733 _P1MDIN	=	0x00ad
                           0000B7   734 G$FLACL$0$0 == 0x00b7
                           0000B7   735 _FLACL	=	0x00b7
                           0000C8   736 G$P4$0$0 == 0x00c8
                           0000C8   737 _P4	=	0x00c8
                           0000D8   738 G$P5$0$0 == 0x00d8
                           0000D8   739 _P5	=	0x00d8
                           0000E1   740 G$XBR0$0$0 == 0x00e1
                           0000E1   741 _XBR0	=	0x00e1
                           0000E2   742 G$XBR1$0$0 == 0x00e2
                           0000E2   743 _XBR1	=	0x00e2
                           0000E3   744 G$XBR2$0$0 == 0x00e3
                           0000E3   745 _XBR2	=	0x00e3
                           0000E8   746 G$P6$0$0 == 0x00e8
                           0000E8   747 _P6	=	0x00e8
                           0000F8   748 G$P7$0$0 == 0x00f8
                           0000F8   749 _P7	=	0x00f8
                           008C8A   750 G$TMR0$0$0 == 0x8c8a
                           008C8A   751 _TMR0	=	0x8c8a
                           008D8B   752 G$TMR1$0$0 == 0x8d8b
                           008D8B   753 _TMR1	=	0x8d8b
                           00CDCC   754 G$TMR2$0$0 == 0xcdcc
                           00CDCC   755 _TMR2	=	0xcdcc
                           00CBCA   756 G$RCAP2$0$0 == 0xcbca
                           00CBCA   757 _RCAP2	=	0xcbca
                           00BFBE   758 G$ADC0$0$0 == 0xbfbe
                           00BFBE   759 _ADC0	=	0xbfbe
                           00C5C4   760 G$ADC0GT$0$0 == 0xc5c4
                           00C5C4   761 _ADC0GT	=	0xc5c4
                           00C7C6   762 G$ADC0LT$0$0 == 0xc7c6
                           00C7C6   763 _ADC0LT	=	0xc7c6
                           00D3D2   764 G$DAC0$0$0 == 0xd3d2
                           00D3D2   765 _DAC0	=	0xd3d2
                           00FAF9   766 G$PCA0$0$0 == 0xfaf9
                           00FAF9   767 _PCA0	=	0xfaf9
                           00FCFB   768 G$PCA0CP0$0$0 == 0xfcfb
                           00FCFB   769 _PCA0CP0	=	0xfcfb
                           00FEFD   770 G$PCA0CP1$0$0 == 0xfefd
                           00FEFD   771 _PCA0CP1	=	0xfefd
                           00EAE9   772 G$PCA0CP2$0$0 == 0xeae9
                           00EAE9   773 _PCA0CP2	=	0xeae9
                           00ECEB   774 G$PCA0CP3$0$0 == 0xeceb
                           00ECEB   775 _PCA0CP3	=	0xeceb
                           00EEED   776 G$PCA0CP4$0$0 == 0xeeed
                           00EEED   777 _PCA0CP4	=	0xeeed
                           00E2E1   778 G$PCA0CP5$0$0 == 0xe2e1
                           00E2E1   779 _PCA0CP5	=	0xe2e1
                           00CDCC   780 G$TMR3$0$0 == 0xcdcc
                           00CDCC   781 _TMR3	=	0xcdcc
                           00CBCA   782 G$RCAP3$0$0 == 0xcbca
                           00CBCA   783 _RCAP3	=	0xcbca
                           00D3D2   784 G$DAC1$0$0 == 0xd3d2
                           00D3D2   785 _DAC1	=	0xd3d2
                           00CDCC   786 G$TMR4$0$0 == 0xcdcc
                           00CDCC   787 _TMR4	=	0xcdcc
                           00CBCA   788 G$RCAP4$0$0 == 0xcbca
                           00CBCA   789 _RCAP4	=	0xcbca
                           00C2C1   790 G$MAC0A$0$0 == 0xc2c1
                           00C2C1   791 _MAC0A	=	0xc2c1
                           96959493   792 G$MAC0ACC$0$0 == 0x96959493
                           96959493   793 _MAC0ACC	=	0x96959493
                           00CFCE   794 G$MAC0RND$0$0 == 0xcfce
                           00CFCE   795 _MAC0RND	=	0xcfce
                                    796 ;--------------------------------------------------------
                                    797 ; special function bits
                                    798 ;--------------------------------------------------------
                                    799 	.area RSEG    (ABS,DATA)
      000000                        800 	.org 0x0000
                           000080   801 G$P0_0$0$0 == 0x0080
                           000080   802 _P0_0	=	0x0080
                           000081   803 G$P0_1$0$0 == 0x0081
                           000081   804 _P0_1	=	0x0081
                           000082   805 G$P0_2$0$0 == 0x0082
                           000082   806 _P0_2	=	0x0082
                           000083   807 G$P0_3$0$0 == 0x0083
                           000083   808 _P0_3	=	0x0083
                           000084   809 G$P0_4$0$0 == 0x0084
                           000084   810 _P0_4	=	0x0084
                           000085   811 G$P0_5$0$0 == 0x0085
                           000085   812 _P0_5	=	0x0085
                           000086   813 G$P0_6$0$0 == 0x0086
                           000086   814 _P0_6	=	0x0086
                           000087   815 G$P0_7$0$0 == 0x0087
                           000087   816 _P0_7	=	0x0087
                           000088   817 G$IT0$0$0 == 0x0088
                           000088   818 _IT0	=	0x0088
                           000089   819 G$IE0$0$0 == 0x0089
                           000089   820 _IE0	=	0x0089
                           00008A   821 G$IT1$0$0 == 0x008a
                           00008A   822 _IT1	=	0x008a
                           00008B   823 G$IE1$0$0 == 0x008b
                           00008B   824 _IE1	=	0x008b
                           00008C   825 G$TR0$0$0 == 0x008c
                           00008C   826 _TR0	=	0x008c
                           00008D   827 G$TF0$0$0 == 0x008d
                           00008D   828 _TF0	=	0x008d
                           00008E   829 G$TR1$0$0 == 0x008e
                           00008E   830 _TR1	=	0x008e
                           00008F   831 G$TF1$0$0 == 0x008f
                           00008F   832 _TF1	=	0x008f
                           000088   833 G$CP0HYN0$0$0 == 0x0088
                           000088   834 _CP0HYN0	=	0x0088
                           000089   835 G$CP0HYN1$0$0 == 0x0089
                           000089   836 _CP0HYN1	=	0x0089
                           00008A   837 G$CP0HYP0$0$0 == 0x008a
                           00008A   838 _CP0HYP0	=	0x008a
                           00008B   839 G$CP0HYP1$0$0 == 0x008b
                           00008B   840 _CP0HYP1	=	0x008b
                           00008C   841 G$CP0FIF$0$0 == 0x008c
                           00008C   842 _CP0FIF	=	0x008c
                           00008D   843 G$CP0RIF$0$0 == 0x008d
                           00008D   844 _CP0RIF	=	0x008d
                           00008E   845 G$CP0OUT$0$0 == 0x008e
                           00008E   846 _CP0OUT	=	0x008e
                           00008F   847 G$CP0EN$0$0 == 0x008f
                           00008F   848 _CP0EN	=	0x008f
                           000088   849 G$CP1HYN0$0$0 == 0x0088
                           000088   850 _CP1HYN0	=	0x0088
                           000089   851 G$CP1HYN1$0$0 == 0x0089
                           000089   852 _CP1HYN1	=	0x0089
                           00008A   853 G$CP1HYP0$0$0 == 0x008a
                           00008A   854 _CP1HYP0	=	0x008a
                           00008B   855 G$CP1HYP1$0$0 == 0x008b
                           00008B   856 _CP1HYP1	=	0x008b
                           00008C   857 G$CP1FIF$0$0 == 0x008c
                           00008C   858 _CP1FIF	=	0x008c
                           00008D   859 G$CP1RIF$0$0 == 0x008d
                           00008D   860 _CP1RIF	=	0x008d
                           00008E   861 G$CP1OUT$0$0 == 0x008e
                           00008E   862 _CP1OUT	=	0x008e
                           00008F   863 G$CP1EN$0$0 == 0x008f
                           00008F   864 _CP1EN	=	0x008f
                           000088   865 G$FLHBUSY$0$0 == 0x0088
                           000088   866 _FLHBUSY	=	0x0088
                           000090   867 G$P1_0$0$0 == 0x0090
                           000090   868 _P1_0	=	0x0090
                           000091   869 G$P1_1$0$0 == 0x0091
                           000091   870 _P1_1	=	0x0091
                           000092   871 G$P1_2$0$0 == 0x0092
                           000092   872 _P1_2	=	0x0092
                           000093   873 G$P1_3$0$0 == 0x0093
                           000093   874 _P1_3	=	0x0093
                           000094   875 G$P1_4$0$0 == 0x0094
                           000094   876 _P1_4	=	0x0094
                           000095   877 G$P1_5$0$0 == 0x0095
                           000095   878 _P1_5	=	0x0095
                           000096   879 G$P1_6$0$0 == 0x0096
                           000096   880 _P1_6	=	0x0096
                           000097   881 G$P1_7$0$0 == 0x0097
                           000097   882 _P1_7	=	0x0097
                           000098   883 G$RI0$0$0 == 0x0098
                           000098   884 _RI0	=	0x0098
                           000098   885 G$RI$0$0 == 0x0098
                           000098   886 _RI	=	0x0098
                           000099   887 G$TI0$0$0 == 0x0099
                           000099   888 _TI0	=	0x0099
                           000099   889 G$TI$0$0 == 0x0099
                           000099   890 _TI	=	0x0099
                           00009A   891 G$RB80$0$0 == 0x009a
                           00009A   892 _RB80	=	0x009a
                           00009B   893 G$TB80$0$0 == 0x009b
                           00009B   894 _TB80	=	0x009b
                           00009C   895 G$REN0$0$0 == 0x009c
                           00009C   896 _REN0	=	0x009c
                           00009C   897 G$REN$0$0 == 0x009c
                           00009C   898 _REN	=	0x009c
                           00009D   899 G$SM20$0$0 == 0x009d
                           00009D   900 _SM20	=	0x009d
                           00009E   901 G$SM10$0$0 == 0x009e
                           00009E   902 _SM10	=	0x009e
                           00009F   903 G$SM00$0$0 == 0x009f
                           00009F   904 _SM00	=	0x009f
                           000098   905 G$RI1$0$0 == 0x0098
                           000098   906 _RI1	=	0x0098
                           000099   907 G$TI1$0$0 == 0x0099
                           000099   908 _TI1	=	0x0099
                           00009A   909 G$RB81$0$0 == 0x009a
                           00009A   910 _RB81	=	0x009a
                           00009B   911 G$TB81$0$0 == 0x009b
                           00009B   912 _TB81	=	0x009b
                           00009C   913 G$REN1$0$0 == 0x009c
                           00009C   914 _REN1	=	0x009c
                           00009D   915 G$MCE1$0$0 == 0x009d
                           00009D   916 _MCE1	=	0x009d
                           00009F   917 G$S1MODE$0$0 == 0x009f
                           00009F   918 _S1MODE	=	0x009f
                           0000A0   919 G$P2_0$0$0 == 0x00a0
                           0000A0   920 _P2_0	=	0x00a0
                           0000A1   921 G$P2_1$0$0 == 0x00a1
                           0000A1   922 _P2_1	=	0x00a1
                           0000A2   923 G$P2_2$0$0 == 0x00a2
                           0000A2   924 _P2_2	=	0x00a2
                           0000A3   925 G$P2_3$0$0 == 0x00a3
                           0000A3   926 _P2_3	=	0x00a3
                           0000A4   927 G$P2_4$0$0 == 0x00a4
                           0000A4   928 _P2_4	=	0x00a4
                           0000A5   929 G$P2_5$0$0 == 0x00a5
                           0000A5   930 _P2_5	=	0x00a5
                           0000A6   931 G$P2_6$0$0 == 0x00a6
                           0000A6   932 _P2_6	=	0x00a6
                           0000A7   933 G$P2_7$0$0 == 0x00a7
                           0000A7   934 _P2_7	=	0x00a7
                           0000A8   935 G$EX0$0$0 == 0x00a8
                           0000A8   936 _EX0	=	0x00a8
                           0000A9   937 G$ET0$0$0 == 0x00a9
                           0000A9   938 _ET0	=	0x00a9
                           0000AA   939 G$EX1$0$0 == 0x00aa
                           0000AA   940 _EX1	=	0x00aa
                           0000AB   941 G$ET1$0$0 == 0x00ab
                           0000AB   942 _ET1	=	0x00ab
                           0000AC   943 G$ES0$0$0 == 0x00ac
                           0000AC   944 _ES0	=	0x00ac
                           0000AC   945 G$ES$0$0 == 0x00ac
                           0000AC   946 _ES	=	0x00ac
                           0000AD   947 G$ET2$0$0 == 0x00ad
                           0000AD   948 _ET2	=	0x00ad
                           0000AF   949 G$EA$0$0 == 0x00af
                           0000AF   950 _EA	=	0x00af
                           0000B0   951 G$P3_0$0$0 == 0x00b0
                           0000B0   952 _P3_0	=	0x00b0
                           0000B1   953 G$P3_1$0$0 == 0x00b1
                           0000B1   954 _P3_1	=	0x00b1
                           0000B2   955 G$P3_2$0$0 == 0x00b2
                           0000B2   956 _P3_2	=	0x00b2
                           0000B3   957 G$P3_3$0$0 == 0x00b3
                           0000B3   958 _P3_3	=	0x00b3
                           0000B4   959 G$P3_4$0$0 == 0x00b4
                           0000B4   960 _P3_4	=	0x00b4
                           0000B5   961 G$P3_5$0$0 == 0x00b5
                           0000B5   962 _P3_5	=	0x00b5
                           0000B6   963 G$P3_6$0$0 == 0x00b6
                           0000B6   964 _P3_6	=	0x00b6
                           0000B7   965 G$P3_7$0$0 == 0x00b7
                           0000B7   966 _P3_7	=	0x00b7
                           0000B8   967 G$PX0$0$0 == 0x00b8
                           0000B8   968 _PX0	=	0x00b8
                           0000B9   969 G$PT0$0$0 == 0x00b9
                           0000B9   970 _PT0	=	0x00b9
                           0000BA   971 G$PX1$0$0 == 0x00ba
                           0000BA   972 _PX1	=	0x00ba
                           0000BB   973 G$PT1$0$0 == 0x00bb
                           0000BB   974 _PT1	=	0x00bb
                           0000BC   975 G$PS0$0$0 == 0x00bc
                           0000BC   976 _PS0	=	0x00bc
                           0000BC   977 G$PS$0$0 == 0x00bc
                           0000BC   978 _PS	=	0x00bc
                           0000BD   979 G$PT2$0$0 == 0x00bd
                           0000BD   980 _PT2	=	0x00bd
                           0000C0   981 G$SMBTOE$0$0 == 0x00c0
                           0000C0   982 _SMBTOE	=	0x00c0
                           0000C1   983 G$SMBFTE$0$0 == 0x00c1
                           0000C1   984 _SMBFTE	=	0x00c1
                           0000C2   985 G$AA$0$0 == 0x00c2
                           0000C2   986 _AA	=	0x00c2
                           0000C3   987 G$SI$0$0 == 0x00c3
                           0000C3   988 _SI	=	0x00c3
                           0000C4   989 G$STO$0$0 == 0x00c4
                           0000C4   990 _STO	=	0x00c4
                           0000C5   991 G$STA$0$0 == 0x00c5
                           0000C5   992 _STA	=	0x00c5
                           0000C6   993 G$ENSMB$0$0 == 0x00c6
                           0000C6   994 _ENSMB	=	0x00c6
                           0000C7   995 G$BUSY$0$0 == 0x00c7
                           0000C7   996 _BUSY	=	0x00c7
                           0000C0   997 G$MAC0N$0$0 == 0x00c0
                           0000C0   998 _MAC0N	=	0x00c0
                           0000C1   999 G$MAC0SO$0$0 == 0x00c1
                           0000C1  1000 _MAC0SO	=	0x00c1
                           0000C2  1001 G$MAC0Z$0$0 == 0x00c2
                           0000C2  1002 _MAC0Z	=	0x00c2
                           0000C3  1003 G$MAC0HO$0$0 == 0x00c3
                           0000C3  1004 _MAC0HO	=	0x00c3
                           0000C8  1005 G$CPRL2$0$0 == 0x00c8
                           0000C8  1006 _CPRL2	=	0x00c8
                           0000C9  1007 G$CT2$0$0 == 0x00c9
                           0000C9  1008 _CT2	=	0x00c9
                           0000CA  1009 G$TR2$0$0 == 0x00ca
                           0000CA  1010 _TR2	=	0x00ca
                           0000CB  1011 G$EXEN2$0$0 == 0x00cb
                           0000CB  1012 _EXEN2	=	0x00cb
                           0000CE  1013 G$EXF2$0$0 == 0x00ce
                           0000CE  1014 _EXF2	=	0x00ce
                           0000CF  1015 G$TF2$0$0 == 0x00cf
                           0000CF  1016 _TF2	=	0x00cf
                           0000C8  1017 G$CPRL3$0$0 == 0x00c8
                           0000C8  1018 _CPRL3	=	0x00c8
                           0000C9  1019 G$CT3$0$0 == 0x00c9
                           0000C9  1020 _CT3	=	0x00c9
                           0000CA  1021 G$TR3$0$0 == 0x00ca
                           0000CA  1022 _TR3	=	0x00ca
                           0000CB  1023 G$EXEN3$0$0 == 0x00cb
                           0000CB  1024 _EXEN3	=	0x00cb
                           0000CE  1025 G$EXF3$0$0 == 0x00ce
                           0000CE  1026 _EXF3	=	0x00ce
                           0000CF  1027 G$TF3$0$0 == 0x00cf
                           0000CF  1028 _TF3	=	0x00cf
                           0000C8  1029 G$CPRL4$0$0 == 0x00c8
                           0000C8  1030 _CPRL4	=	0x00c8
                           0000C9  1031 G$CT4$0$0 == 0x00c9
                           0000C9  1032 _CT4	=	0x00c9
                           0000CA  1033 G$TR4$0$0 == 0x00ca
                           0000CA  1034 _TR4	=	0x00ca
                           0000CB  1035 G$EXEN4$0$0 == 0x00cb
                           0000CB  1036 _EXEN4	=	0x00cb
                           0000CE  1037 G$EXF4$0$0 == 0x00ce
                           0000CE  1038 _EXF4	=	0x00ce
                           0000CF  1039 G$TF4$0$0 == 0x00cf
                           0000CF  1040 _TF4	=	0x00cf
                           0000C8  1041 G$P4_0$0$0 == 0x00c8
                           0000C8  1042 _P4_0	=	0x00c8
                           0000C9  1043 G$P4_1$0$0 == 0x00c9
                           0000C9  1044 _P4_1	=	0x00c9
                           0000CA  1045 G$P4_2$0$0 == 0x00ca
                           0000CA  1046 _P4_2	=	0x00ca
                           0000CB  1047 G$P4_3$0$0 == 0x00cb
                           0000CB  1048 _P4_3	=	0x00cb
                           0000CC  1049 G$P4_4$0$0 == 0x00cc
                           0000CC  1050 _P4_4	=	0x00cc
                           0000CD  1051 G$P4_5$0$0 == 0x00cd
                           0000CD  1052 _P4_5	=	0x00cd
                           0000CE  1053 G$P4_6$0$0 == 0x00ce
                           0000CE  1054 _P4_6	=	0x00ce
                           0000CF  1055 G$P4_7$0$0 == 0x00cf
                           0000CF  1056 _P4_7	=	0x00cf
                           0000D0  1057 G$P$0$0 == 0x00d0
                           0000D0  1058 _P	=	0x00d0
                           0000D1  1059 G$F1$0$0 == 0x00d1
                           0000D1  1060 _F1	=	0x00d1
                           0000D2  1061 G$OV$0$0 == 0x00d2
                           0000D2  1062 _OV	=	0x00d2
                           0000D3  1063 G$RS0$0$0 == 0x00d3
                           0000D3  1064 _RS0	=	0x00d3
                           0000D4  1065 G$RS1$0$0 == 0x00d4
                           0000D4  1066 _RS1	=	0x00d4
                           0000D5  1067 G$F0$0$0 == 0x00d5
                           0000D5  1068 _F0	=	0x00d5
                           0000D6  1069 G$AC$0$0 == 0x00d6
                           0000D6  1070 _AC	=	0x00d6
                           0000D7  1071 G$CY$0$0 == 0x00d7
                           0000D7  1072 _CY	=	0x00d7
                           0000D8  1073 G$CCF0$0$0 == 0x00d8
                           0000D8  1074 _CCF0	=	0x00d8
                           0000D9  1075 G$CCF1$0$0 == 0x00d9
                           0000D9  1076 _CCF1	=	0x00d9
                           0000DA  1077 G$CCF2$0$0 == 0x00da
                           0000DA  1078 _CCF2	=	0x00da
                           0000DB  1079 G$CCF3$0$0 == 0x00db
                           0000DB  1080 _CCF3	=	0x00db
                           0000DC  1081 G$CCF4$0$0 == 0x00dc
                           0000DC  1082 _CCF4	=	0x00dc
                           0000DD  1083 G$CCF5$0$0 == 0x00dd
                           0000DD  1084 _CCF5	=	0x00dd
                           0000DE  1085 G$CR$0$0 == 0x00de
                           0000DE  1086 _CR	=	0x00de
                           0000DF  1087 G$CF$0$0 == 0x00df
                           0000DF  1088 _CF	=	0x00df
                           0000D8  1089 G$P5_0$0$0 == 0x00d8
                           0000D8  1090 _P5_0	=	0x00d8
                           0000D9  1091 G$P5_1$0$0 == 0x00d9
                           0000D9  1092 _P5_1	=	0x00d9
                           0000DA  1093 G$P5_2$0$0 == 0x00da
                           0000DA  1094 _P5_2	=	0x00da
                           0000DB  1095 G$P5_3$0$0 == 0x00db
                           0000DB  1096 _P5_3	=	0x00db
                           0000DC  1097 G$P5_4$0$0 == 0x00dc
                           0000DC  1098 _P5_4	=	0x00dc
                           0000DD  1099 G$P5_5$0$0 == 0x00dd
                           0000DD  1100 _P5_5	=	0x00dd
                           0000DE  1101 G$P5_6$0$0 == 0x00de
                           0000DE  1102 _P5_6	=	0x00de
                           0000DF  1103 G$P5_7$0$0 == 0x00df
                           0000DF  1104 _P5_7	=	0x00df
                           0000E8  1105 G$AD0LJST$0$0 == 0x00e8
                           0000E8  1106 _AD0LJST	=	0x00e8
                           0000E9  1107 G$AD0WINT$0$0 == 0x00e9
                           0000E9  1108 _AD0WINT	=	0x00e9
                           0000EA  1109 G$AD0CM0$0$0 == 0x00ea
                           0000EA  1110 _AD0CM0	=	0x00ea
                           0000EB  1111 G$AD0CM1$0$0 == 0x00eb
                           0000EB  1112 _AD0CM1	=	0x00eb
                           0000EC  1113 G$AD0BUSY$0$0 == 0x00ec
                           0000EC  1114 _AD0BUSY	=	0x00ec
                           0000ED  1115 G$AD0INT$0$0 == 0x00ed
                           0000ED  1116 _AD0INT	=	0x00ed
                           0000EE  1117 G$AD0TM$0$0 == 0x00ee
                           0000EE  1118 _AD0TM	=	0x00ee
                           0000EF  1119 G$AD0EN$0$0 == 0x00ef
                           0000EF  1120 _AD0EN	=	0x00ef
                           0000E8  1121 G$AD2WINT$0$0 == 0x00e8
                           0000E8  1122 _AD2WINT	=	0x00e8
                           0000E9  1123 G$AD2CM0$0$0 == 0x00e9
                           0000E9  1124 _AD2CM0	=	0x00e9
                           0000EA  1125 G$AD2CM1$0$0 == 0x00ea
                           0000EA  1126 _AD2CM1	=	0x00ea
                           0000EB  1127 G$AD2CM2$0$0 == 0x00eb
                           0000EB  1128 _AD2CM2	=	0x00eb
                           0000EC  1129 G$AD2BUSY$0$0 == 0x00ec
                           0000EC  1130 _AD2BUSY	=	0x00ec
                           0000ED  1131 G$AD2INT$0$0 == 0x00ed
                           0000ED  1132 _AD2INT	=	0x00ed
                           0000EE  1133 G$AD2TM$0$0 == 0x00ee
                           0000EE  1134 _AD2TM	=	0x00ee
                           0000EF  1135 G$AD2EN$0$0 == 0x00ef
                           0000EF  1136 _AD2EN	=	0x00ef
                           0000E8  1137 G$P6_0$0$0 == 0x00e8
                           0000E8  1138 _P6_0	=	0x00e8
                           0000E9  1139 G$P6_1$0$0 == 0x00e9
                           0000E9  1140 _P6_1	=	0x00e9
                           0000EA  1141 G$P6_2$0$0 == 0x00ea
                           0000EA  1142 _P6_2	=	0x00ea
                           0000EB  1143 G$P6_3$0$0 == 0x00eb
                           0000EB  1144 _P6_3	=	0x00eb
                           0000EC  1145 G$P6_4$0$0 == 0x00ec
                           0000EC  1146 _P6_4	=	0x00ec
                           0000ED  1147 G$P6_5$0$0 == 0x00ed
                           0000ED  1148 _P6_5	=	0x00ed
                           0000EE  1149 G$P6_6$0$0 == 0x00ee
                           0000EE  1150 _P6_6	=	0x00ee
                           0000EF  1151 G$P6_7$0$0 == 0x00ef
                           0000EF  1152 _P6_7	=	0x00ef
                           0000F8  1153 G$SPIEN$0$0 == 0x00f8
                           0000F8  1154 _SPIEN	=	0x00f8
                           0000F9  1155 G$TXBMT$0$0 == 0x00f9
                           0000F9  1156 _TXBMT	=	0x00f9
                           0000FA  1157 G$NSSMD0$0$0 == 0x00fa
                           0000FA  1158 _NSSMD0	=	0x00fa
                           0000FB  1159 G$NSSMD1$0$0 == 0x00fb
                           0000FB  1160 _NSSMD1	=	0x00fb
                           0000FC  1161 G$RXOVRN$0$0 == 0x00fc
                           0000FC  1162 _RXOVRN	=	0x00fc
                           0000FD  1163 G$MODF$0$0 == 0x00fd
                           0000FD  1164 _MODF	=	0x00fd
                           0000FE  1165 G$WCOL$0$0 == 0x00fe
                           0000FE  1166 _WCOL	=	0x00fe
                           0000FF  1167 G$SPIF$0$0 == 0x00ff
                           0000FF  1168 _SPIF	=	0x00ff
                           0000F8  1169 G$P7_0$0$0 == 0x00f8
                           0000F8  1170 _P7_0	=	0x00f8
                           0000F9  1171 G$P7_1$0$0 == 0x00f9
                           0000F9  1172 _P7_1	=	0x00f9
                           0000FA  1173 G$P7_2$0$0 == 0x00fa
                           0000FA  1174 _P7_2	=	0x00fa
                           0000FB  1175 G$P7_3$0$0 == 0x00fb
                           0000FB  1176 _P7_3	=	0x00fb
                           0000FC  1177 G$P7_4$0$0 == 0x00fc
                           0000FC  1178 _P7_4	=	0x00fc
                           0000FD  1179 G$P7_5$0$0 == 0x00fd
                           0000FD  1180 _P7_5	=	0x00fd
                           0000FE  1181 G$P7_6$0$0 == 0x00fe
                           0000FE  1182 _P7_6	=	0x00fe
                           0000FF  1183 G$P7_7$0$0 == 0x00ff
                           0000FF  1184 _P7_7	=	0x00ff
                           000090  1185 G$Pot0$0$0 == 0x0090
                           000090  1186 _Pot0	=	0x0090
                           000091  1187 G$Pot1$0$0 == 0x0091
                           000091  1188 _Pot1	=	0x0091
                           000092  1189 G$Pot2$0$0 == 0x0092
                           000092  1190 _Pot2	=	0x0092
                           000093  1191 G$Pot3$0$0 == 0x0093
                           000093  1192 _Pot3	=	0x0093
                           0000A0  1193 G$LED0$0$0 == 0x00a0
                           0000A0  1194 _LED0	=	0x00a0
                           0000A1  1195 G$LED1$0$0 == 0x00a1
                           0000A1  1196 _LED1	=	0x00a1
                           0000A2  1197 G$LED2$0$0 == 0x00a2
                           0000A2  1198 _LED2	=	0x00a2
                           0000A3  1199 G$LED3$0$0 == 0x00a3
                           0000A3  1200 _LED3	=	0x00a3
                                   1201 ;--------------------------------------------------------
                                   1202 ; overlayable register banks
                                   1203 ;--------------------------------------------------------
                                   1204 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                       1205 	.ds 8
                                   1206 ;--------------------------------------------------------
                                   1207 ; internal ram data
                                   1208 ;--------------------------------------------------------
                                   1209 	.area DSEG    (DATA)
                                   1210 ;--------------------------------------------------------
                                   1211 ; overlayable items in internal ram 
                                   1212 ;--------------------------------------------------------
                                   1213 	.area	OSEG    (OVR,DATA)
                                   1214 	.area	OSEG    (OVR,DATA)
                                   1215 	.area	OSEG    (OVR,DATA)
                                   1216 	.area	OSEG    (OVR,DATA)
                                   1217 ;--------------------------------------------------------
                                   1218 ; Stack segment in internal ram 
                                   1219 ;--------------------------------------------------------
                                   1220 	.area	SSEG
      00003C                       1221 __start__stack:
      00003C                       1222 	.ds	1
                                   1223 
                                   1224 ;--------------------------------------------------------
                                   1225 ; indirectly addressable internal ram data
                                   1226 ;--------------------------------------------------------
                                   1227 	.area ISEG    (DATA)
                                   1228 ;--------------------------------------------------------
                                   1229 ; absolute internal ram data
                                   1230 ;--------------------------------------------------------
                                   1231 	.area IABS    (ABS,DATA)
                                   1232 	.area IABS    (ABS,DATA)
                                   1233 ;--------------------------------------------------------
                                   1234 ; bit data
                                   1235 ;--------------------------------------------------------
                                   1236 	.area BSEG    (BIT)
                                   1237 ;--------------------------------------------------------
                                   1238 ; paged external ram data
                                   1239 ;--------------------------------------------------------
                                   1240 	.area PSEG    (PAG,XDATA)
                                   1241 ;--------------------------------------------------------
                                   1242 ; external ram data
                                   1243 ;--------------------------------------------------------
                                   1244 	.area XSEG    (XDATA)
                                   1245 ;--------------------------------------------------------
                                   1246 ; absolute external ram data
                                   1247 ;--------------------------------------------------------
                                   1248 	.area XABS    (ABS,XDATA)
                                   1249 ;--------------------------------------------------------
                                   1250 ; external initialized ram data
                                   1251 ;--------------------------------------------------------
                                   1252 	.area XISEG   (XDATA)
                                   1253 	.area HOME    (CODE)
                                   1254 	.area GSINIT0 (CODE)
                                   1255 	.area GSINIT1 (CODE)
                                   1256 	.area GSINIT2 (CODE)
                                   1257 	.area GSINIT3 (CODE)
                                   1258 	.area GSINIT4 (CODE)
                                   1259 	.area GSINIT5 (CODE)
                                   1260 	.area GSINIT  (CODE)
                                   1261 	.area GSFINAL (CODE)
                                   1262 	.area CSEG    (CODE)
                                   1263 ;--------------------------------------------------------
                                   1264 ; interrupt vector 
                                   1265 ;--------------------------------------------------------
                                   1266 	.area HOME    (CODE)
      000000                       1267 __interrupt_vect:
      000000 02 00 06         [24] 1268 	ljmp	__sdcc_gsinit_startup
                                   1269 ;--------------------------------------------------------
                                   1270 ; global & static initialisations
                                   1271 ;--------------------------------------------------------
                                   1272 	.area HOME    (CODE)
                                   1273 	.area GSINIT  (CODE)
                                   1274 	.area GSFINAL (CODE)
                                   1275 	.area GSINIT  (CODE)
                                   1276 	.globl __sdcc_gsinit_startup
                                   1277 	.globl __sdcc_program_startup
                                   1278 	.globl __start__stack
                                   1279 	.globl __mcs51_genXINIT
                                   1280 	.globl __mcs51_genXRAMCLEAR
                                   1281 	.globl __mcs51_genRAMCLEAR
                                   1282 	.area GSFINAL (CODE)
      00005F 02 00 03         [24] 1283 	ljmp	__sdcc_program_startup
                                   1284 ;--------------------------------------------------------
                                   1285 ; Home
                                   1286 ;--------------------------------------------------------
                                   1287 	.area HOME    (CODE)
                                   1288 	.area HOME    (CODE)
      000003                       1289 __sdcc_program_startup:
      000003 02 00 7B         [24] 1290 	ljmp	_main
                                   1291 ;	return from main will return to caller
                                   1292 ;--------------------------------------------------------
                                   1293 ; code
                                   1294 ;--------------------------------------------------------
                                   1295 	.area CSEG    (CODE)
                                   1296 ;------------------------------------------------------------
                                   1297 ;Allocation info for local variables in function 'putchar'
                                   1298 ;------------------------------------------------------------
                                   1299 ;c                         Allocated to registers r7 
                                   1300 ;------------------------------------------------------------
                           000000  1301 	G$putchar$0$0 ==.
                           000000  1302 	C$putget.h$18$0$0 ==.
                                   1303 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\/putget.h:18: void putchar(char c)
                                   1304 ;	-----------------------------------------
                                   1305 ;	 function putchar
                                   1306 ;	-----------------------------------------
      000062                       1307 _putchar:
                           000007  1308 	ar7 = 0x07
                           000006  1309 	ar6 = 0x06
                           000005  1310 	ar5 = 0x05
                           000004  1311 	ar4 = 0x04
                           000003  1312 	ar3 = 0x03
                           000002  1313 	ar2 = 0x02
                           000001  1314 	ar1 = 0x01
                           000000  1315 	ar0 = 0x00
      000062 AF 82            [24] 1316 	mov	r7,dpl
                           000002  1317 	C$putget.h$20$1$35 ==.
                                   1318 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\/putget.h:20: while(!TI0); 
      000064                       1319 00101$:
                           000002  1320 	C$putget.h$21$1$35 ==.
                                   1321 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\/putget.h:21: TI0=0;
      000064 10 99 02         [24] 1322 	jbc	_TI0,00112$
      000067 80 FB            [24] 1323 	sjmp	00101$
      000069                       1324 00112$:
                           000007  1325 	C$putget.h$22$1$35 ==.
                                   1326 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\/putget.h:22: SBUF0 = c;
      000069 8F 99            [24] 1327 	mov	_SBUF0,r7
                           000009  1328 	C$putget.h$23$1$35 ==.
                           000009  1329 	XG$putchar$0$0 ==.
      00006B 22               [24] 1330 	ret
                                   1331 ;------------------------------------------------------------
                                   1332 ;Allocation info for local variables in function 'getchar'
                                   1333 ;------------------------------------------------------------
                                   1334 ;c                         Allocated to registers 
                                   1335 ;------------------------------------------------------------
                           00000A  1336 	G$getchar$0$0 ==.
                           00000A  1337 	C$putget.h$28$1$35 ==.
                                   1338 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\/putget.h:28: char getchar(void)
                                   1339 ;	-----------------------------------------
                                   1340 ;	 function getchar
                                   1341 ;	-----------------------------------------
      00006C                       1342 _getchar:
                           00000A  1343 	C$putget.h$31$1$37 ==.
                                   1344 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\/putget.h:31: while(!RI0);
      00006C                       1345 00101$:
                           00000A  1346 	C$putget.h$32$1$37 ==.
                                   1347 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\/putget.h:32: RI0 =0;
      00006C 10 98 02         [24] 1348 	jbc	_RI0,00112$
      00006F 80 FB            [24] 1349 	sjmp	00101$
      000071                       1350 00112$:
                           00000F  1351 	C$putget.h$33$1$37 ==.
                                   1352 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\/putget.h:33: c = SBUF0;
      000071 85 99 82         [24] 1353 	mov	dpl,_SBUF0
                           000012  1354 	C$putget.h$35$1$37 ==.
                                   1355 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\/putget.h:35: putchar(c);    // echo to terminal
      000074 12 00 62         [24] 1356 	lcall	_putchar
                           000015  1357 	C$putget.h$36$1$37 ==.
                                   1358 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\/putget.h:36: return SBUF0;
      000077 85 99 82         [24] 1359 	mov	dpl,_SBUF0
                           000018  1360 	C$putget.h$37$1$37 ==.
                           000018  1361 	XG$getchar$0$0 ==.
      00007A 22               [24] 1362 	ret
                                   1363 ;------------------------------------------------------------
                                   1364 ;Allocation info for local variables in function 'main'
                                   1365 ;------------------------------------------------------------
                                   1366 ;Mem0                      Allocated to registers r7 
                                   1367 ;Mem1                      Allocated to registers r6 
                                   1368 ;Mem2                      Allocated to registers r5 
                                   1369 ;Mem3                      Allocated to registers r4 
                                   1370 ;------------------------------------------------------------
                           000019  1371 	G$main$0$0 ==.
                           000019  1372 	C$Hello.c$58$1$37 ==.
                                   1373 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:58: void main(void)
                                   1374 ;	-----------------------------------------
                                   1375 ;	 function main
                                   1376 ;	-----------------------------------------
      00007B                       1377 _main:
                           000019  1378 	C$Hello.c$65$1$43 ==.
                                   1379 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:65: WDTCN = 0xDE;                       // Disable the watchdog timer
      00007B 75 FF DE         [24] 1380 	mov	_WDTCN,#0xde
                           00001C  1381 	C$Hello.c$66$1$43 ==.
                                   1382 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:66: WDTCN = 0xAD;
      00007E 75 FF AD         [24] 1383 	mov	_WDTCN,#0xad
                           00001F  1384 	C$Hello.c$68$1$43 ==.
                                   1385 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:68: PORT_INIT();                        // Initialize the Crossbar and GPIO
      000081 12 02 EC         [24] 1386 	lcall	_PORT_INIT
                           000022  1387 	C$Hello.c$69$1$43 ==.
                                   1388 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:69: SYSCLK_INIT();                      // Initialize the oscillator
      000084 12 02 96         [24] 1389 	lcall	_SYSCLK_INIT
                           000025  1390 	C$Hello.c$70$1$43 ==.
                                   1391 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:70: UART0_INIT();                       // Initialize UART0
      000087 12 03 09         [24] 1392 	lcall	_UART0_INIT
                           000028  1393 	C$Hello.c$72$1$43 ==.
                                   1394 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:72: SFRPAGE = UART0_PAGE;               // Direct output to UART0
      00008A 75 84 00         [24] 1395 	mov	_SFRPAGE,#0x00
                           00002B  1396 	C$Hello.c$74$1$43 ==.
                                   1397 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:74: Mem0 = Pot0;
      00008D A2 90            [12] 1398 	mov	c,_Pot0
      00008F E4               [12] 1399 	clr	a
      000090 33               [12] 1400 	rlc	a
      000091 FF               [12] 1401 	mov	r7,a
                           000030  1402 	C$Hello.c$75$1$43 ==.
                                   1403 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:75: Mem1 = Pot1;
      000092 A2 91            [12] 1404 	mov	c,_Pot1
      000094 E4               [12] 1405 	clr	a
      000095 33               [12] 1406 	rlc	a
      000096 FE               [12] 1407 	mov	r6,a
                           000035  1408 	C$Hello.c$76$1$43 ==.
                                   1409 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:76: Mem2 = Pot2;
      000097 A2 92            [12] 1410 	mov	c,_Pot2
      000099 E4               [12] 1411 	clr	a
      00009A 33               [12] 1412 	rlc	a
      00009B FD               [12] 1413 	mov	r5,a
                           00003A  1414 	C$Hello.c$77$1$43 ==.
                                   1415 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:77: Mem3 = Pot3;
      00009C A2 93            [12] 1416 	mov	c,_Pot3
      00009E E4               [12] 1417 	clr	a
      00009F 33               [12] 1418 	rlc	a
      0000A0 FC               [12] 1419 	mov	r4,a
                           00003F  1420 	C$Hello.c$78$1$43 ==.
                                   1421 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:78: while(1)
      0000A1                       1422 00119$:
                           00003F  1423 	C$Hello.c$80$2$44 ==.
                                   1424 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:80: printf("\033[H"); //go home, top left
      0000A1 C0 07            [24] 1425 	push	ar7
      0000A3 C0 06            [24] 1426 	push	ar6
      0000A5 C0 05            [24] 1427 	push	ar5
      0000A7 C0 04            [24] 1428 	push	ar4
      0000A9 74 6C            [12] 1429 	mov	a,#___str_0
      0000AB C0 E0            [24] 1430 	push	acc
      0000AD 74 09            [12] 1431 	mov	a,#(___str_0 >> 8)
      0000AF C0 E0            [24] 1432 	push	acc
      0000B1 74 80            [12] 1433 	mov	a,#0x80
      0000B3 C0 E0            [24] 1434 	push	acc
      0000B5 12 03 51         [24] 1435 	lcall	_printf
      0000B8 15 81            [12] 1436 	dec	sp
      0000BA 15 81            [12] 1437 	dec	sp
      0000BC 15 81            [12] 1438 	dec	sp
      0000BE D0 04            [24] 1439 	pop	ar4
      0000C0 D0 05            [24] 1440 	pop	ar5
      0000C2 D0 06            [24] 1441 	pop	ar6
      0000C4 D0 07            [24] 1442 	pop	ar7
                           000064  1443 	C$Hello.c$82$2$44 ==.
                                   1444 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:82: if(Pot0 != Mem0 || Pot1 != Mem1 || Pot2 != Mem2 || Pot3 != Mem3)
      0000C6 A2 90            [12] 1445 	mov	c,_Pot0
      0000C8 E4               [12] 1446 	clr	a
      0000C9 33               [12] 1447 	rlc	a
      0000CA FB               [12] 1448 	mov	r3,a
      0000CB 8F 02            [24] 1449 	mov	ar2,r7
      0000CD B5 02 21         [24] 1450 	cjne	a,ar2,00113$
      0000D0 A2 91            [12] 1451 	mov	c,_Pot1
      0000D2 E4               [12] 1452 	clr	a
      0000D3 33               [12] 1453 	rlc	a
      0000D4 FB               [12] 1454 	mov	r3,a
      0000D5 8E 02            [24] 1455 	mov	ar2,r6
      0000D7 B5 02 17         [24] 1456 	cjne	a,ar2,00113$
      0000DA A2 92            [12] 1457 	mov	c,_Pot2
      0000DC E4               [12] 1458 	clr	a
      0000DD 33               [12] 1459 	rlc	a
      0000DE FB               [12] 1460 	mov	r3,a
      0000DF 8D 02            [24] 1461 	mov	ar2,r5
      0000E1 B5 02 0D         [24] 1462 	cjne	a,ar2,00113$
      0000E4 A2 93            [12] 1463 	mov	c,_Pot3
      0000E6 E4               [12] 1464 	clr	a
      0000E7 33               [12] 1465 	rlc	a
      0000E8 FB               [12] 1466 	mov	r3,a
      0000E9 8C 02            [24] 1467 	mov	ar2,r4
      0000EB B5 02 03         [24] 1468 	cjne	a,ar2,00153$
      0000EE 02 02 6D         [24] 1469 	ljmp	00114$
      0000F1                       1470 00153$:
      0000F1                       1471 00113$:
                           00008F  1472 	C$Hello.c$84$3$45 ==.
                                   1473 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:84: printf("\033[2J"); //erase screen
      0000F1 74 70            [12] 1474 	mov	a,#___str_1
      0000F3 C0 E0            [24] 1475 	push	acc
      0000F5 74 09            [12] 1476 	mov	a,#(___str_1 >> 8)
      0000F7 C0 E0            [24] 1477 	push	acc
      0000F9 74 80            [12] 1478 	mov	a,#0x80
      0000FB C0 E0            [24] 1479 	push	acc
      0000FD 12 03 51         [24] 1480 	lcall	_printf
      000100 15 81            [12] 1481 	dec	sp
      000102 15 81            [12] 1482 	dec	sp
      000104 15 81            [12] 1483 	dec	sp
                           0000A4  1484 	C$Hello.c$86$3$45 ==.
                                   1485 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:86: if(Pot0 == 1)
      000106 30 90 19         [24] 1486 	jnb	_Pot0,00102$
                           0000A7  1487 	C$Hello.c$88$4$46 ==.
                                   1488 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:88: LED0 = 1;
      000109 D2 A0            [12] 1489 	setb	_LED0
                           0000A9  1490 	C$Hello.c$89$4$46 ==.
                                   1491 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:89: printf("LED0 is HIGH");
      00010B 74 75            [12] 1492 	mov	a,#___str_2
      00010D C0 E0            [24] 1493 	push	acc
      00010F 74 09            [12] 1494 	mov	a,#(___str_2 >> 8)
      000111 C0 E0            [24] 1495 	push	acc
      000113 74 80            [12] 1496 	mov	a,#0x80
      000115 C0 E0            [24] 1497 	push	acc
      000117 12 03 51         [24] 1498 	lcall	_printf
      00011A 15 81            [12] 1499 	dec	sp
      00011C 15 81            [12] 1500 	dec	sp
      00011E 15 81            [12] 1501 	dec	sp
      000120 80 17            [24] 1502 	sjmp	00103$
      000122                       1503 00102$:
                           0000C0  1504 	C$Hello.c$93$4$47 ==.
                                   1505 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:93: LED0 = 0;
      000122 C2 A0            [12] 1506 	clr	_LED0
                           0000C2  1507 	C$Hello.c$94$4$47 ==.
                                   1508 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:94: printf("LED0 is LOW");
      000124 74 82            [12] 1509 	mov	a,#___str_3
      000126 C0 E0            [24] 1510 	push	acc
      000128 74 09            [12] 1511 	mov	a,#(___str_3 >> 8)
      00012A C0 E0            [24] 1512 	push	acc
      00012C 74 80            [12] 1513 	mov	a,#0x80
      00012E C0 E0            [24] 1514 	push	acc
      000130 12 03 51         [24] 1515 	lcall	_printf
      000133 15 81            [12] 1516 	dec	sp
      000135 15 81            [12] 1517 	dec	sp
      000137 15 81            [12] 1518 	dec	sp
      000139                       1519 00103$:
                           0000D7  1520 	C$Hello.c$96$3$45 ==.
                                   1521 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:96: Mem0 = Pot0;
      000139 A2 90            [12] 1522 	mov	c,_Pot0
      00013B E4               [12] 1523 	clr	a
      00013C 33               [12] 1524 	rlc	a
      00013D FF               [12] 1525 	mov	r7,a
                           0000DC  1526 	C$Hello.c$98$3$45 ==.
                                   1527 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:98: printf("\n\r");
      00013E C0 07            [24] 1528 	push	ar7
      000140 74 8E            [12] 1529 	mov	a,#___str_4
      000142 C0 E0            [24] 1530 	push	acc
      000144 74 09            [12] 1531 	mov	a,#(___str_4 >> 8)
      000146 C0 E0            [24] 1532 	push	acc
      000148 74 80            [12] 1533 	mov	a,#0x80
      00014A C0 E0            [24] 1534 	push	acc
      00014C 12 03 51         [24] 1535 	lcall	_printf
      00014F 15 81            [12] 1536 	dec	sp
      000151 15 81            [12] 1537 	dec	sp
      000153 15 81            [12] 1538 	dec	sp
      000155 D0 07            [24] 1539 	pop	ar7
                           0000F5  1540 	C$Hello.c$100$3$45 ==.
                                   1541 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:100: if(Pot1 == 1)
      000157 30 91 1D         [24] 1542 	jnb	_Pot1,00105$
                           0000F8  1543 	C$Hello.c$102$4$48 ==.
                                   1544 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:102: LED1 = 1;
      00015A D2 A1            [12] 1545 	setb	_LED1
                           0000FA  1546 	C$Hello.c$103$4$48 ==.
                                   1547 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:103: printf("LED1 is HIGH");
      00015C C0 07            [24] 1548 	push	ar7
      00015E 74 91            [12] 1549 	mov	a,#___str_5
      000160 C0 E0            [24] 1550 	push	acc
      000162 74 09            [12] 1551 	mov	a,#(___str_5 >> 8)
      000164 C0 E0            [24] 1552 	push	acc
      000166 74 80            [12] 1553 	mov	a,#0x80
      000168 C0 E0            [24] 1554 	push	acc
      00016A 12 03 51         [24] 1555 	lcall	_printf
      00016D 15 81            [12] 1556 	dec	sp
      00016F 15 81            [12] 1557 	dec	sp
      000171 15 81            [12] 1558 	dec	sp
      000173 D0 07            [24] 1559 	pop	ar7
      000175 80 1B            [24] 1560 	sjmp	00106$
      000177                       1561 00105$:
                           000115  1562 	C$Hello.c$107$4$49 ==.
                                   1563 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:107: LED1 = 0;
      000177 C2 A1            [12] 1564 	clr	_LED1
                           000117  1565 	C$Hello.c$108$4$49 ==.
                                   1566 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:108: printf("LED1 is LOW");
      000179 C0 07            [24] 1567 	push	ar7
      00017B 74 9E            [12] 1568 	mov	a,#___str_6
      00017D C0 E0            [24] 1569 	push	acc
      00017F 74 09            [12] 1570 	mov	a,#(___str_6 >> 8)
      000181 C0 E0            [24] 1571 	push	acc
      000183 74 80            [12] 1572 	mov	a,#0x80
      000185 C0 E0            [24] 1573 	push	acc
      000187 12 03 51         [24] 1574 	lcall	_printf
      00018A 15 81            [12] 1575 	dec	sp
      00018C 15 81            [12] 1576 	dec	sp
      00018E 15 81            [12] 1577 	dec	sp
      000190 D0 07            [24] 1578 	pop	ar7
      000192                       1579 00106$:
                           000130  1580 	C$Hello.c$110$3$45 ==.
                                   1581 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:110: Mem1 = Pot1;
      000192 A2 91            [12] 1582 	mov	c,_Pot1
      000194 E4               [12] 1583 	clr	a
      000195 33               [12] 1584 	rlc	a
      000196 FE               [12] 1585 	mov	r6,a
                           000135  1586 	C$Hello.c$112$3$45 ==.
                                   1587 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:112: printf("\n\r");
      000197 C0 07            [24] 1588 	push	ar7
      000199 C0 06            [24] 1589 	push	ar6
      00019B 74 8E            [12] 1590 	mov	a,#___str_4
      00019D C0 E0            [24] 1591 	push	acc
      00019F 74 09            [12] 1592 	mov	a,#(___str_4 >> 8)
      0001A1 C0 E0            [24] 1593 	push	acc
      0001A3 74 80            [12] 1594 	mov	a,#0x80
      0001A5 C0 E0            [24] 1595 	push	acc
      0001A7 12 03 51         [24] 1596 	lcall	_printf
      0001AA 15 81            [12] 1597 	dec	sp
      0001AC 15 81            [12] 1598 	dec	sp
      0001AE 15 81            [12] 1599 	dec	sp
      0001B0 D0 06            [24] 1600 	pop	ar6
      0001B2 D0 07            [24] 1601 	pop	ar7
                           000152  1602 	C$Hello.c$114$3$45 ==.
                                   1603 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:114: if(Pot2 == 1)
      0001B4 30 92 21         [24] 1604 	jnb	_Pot2,00108$
                           000155  1605 	C$Hello.c$116$4$50 ==.
                                   1606 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:116: LED2 = 1;
      0001B7 D2 A2            [12] 1607 	setb	_LED2
                           000157  1608 	C$Hello.c$117$4$50 ==.
                                   1609 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:117: printf("LED2 is HIGH");
      0001B9 C0 07            [24] 1610 	push	ar7
      0001BB C0 06            [24] 1611 	push	ar6
      0001BD 74 AA            [12] 1612 	mov	a,#___str_7
      0001BF C0 E0            [24] 1613 	push	acc
      0001C1 74 09            [12] 1614 	mov	a,#(___str_7 >> 8)
      0001C3 C0 E0            [24] 1615 	push	acc
      0001C5 74 80            [12] 1616 	mov	a,#0x80
      0001C7 C0 E0            [24] 1617 	push	acc
      0001C9 12 03 51         [24] 1618 	lcall	_printf
      0001CC 15 81            [12] 1619 	dec	sp
      0001CE 15 81            [12] 1620 	dec	sp
      0001D0 15 81            [12] 1621 	dec	sp
      0001D2 D0 06            [24] 1622 	pop	ar6
      0001D4 D0 07            [24] 1623 	pop	ar7
      0001D6 80 1F            [24] 1624 	sjmp	00109$
      0001D8                       1625 00108$:
                           000176  1626 	C$Hello.c$121$4$51 ==.
                                   1627 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:121: LED2 = 0;
      0001D8 C2 A2            [12] 1628 	clr	_LED2
                           000178  1629 	C$Hello.c$122$4$51 ==.
                                   1630 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:122: printf("LED2 is LOW");
      0001DA C0 07            [24] 1631 	push	ar7
      0001DC C0 06            [24] 1632 	push	ar6
      0001DE 74 B7            [12] 1633 	mov	a,#___str_8
      0001E0 C0 E0            [24] 1634 	push	acc
      0001E2 74 09            [12] 1635 	mov	a,#(___str_8 >> 8)
      0001E4 C0 E0            [24] 1636 	push	acc
      0001E6 74 80            [12] 1637 	mov	a,#0x80
      0001E8 C0 E0            [24] 1638 	push	acc
      0001EA 12 03 51         [24] 1639 	lcall	_printf
      0001ED 15 81            [12] 1640 	dec	sp
      0001EF 15 81            [12] 1641 	dec	sp
      0001F1 15 81            [12] 1642 	dec	sp
      0001F3 D0 06            [24] 1643 	pop	ar6
      0001F5 D0 07            [24] 1644 	pop	ar7
      0001F7                       1645 00109$:
                           000195  1646 	C$Hello.c$124$3$45 ==.
                                   1647 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:124: Mem2 = Pot2;
      0001F7 A2 92            [12] 1648 	mov	c,_Pot2
      0001F9 E4               [12] 1649 	clr	a
      0001FA 33               [12] 1650 	rlc	a
      0001FB FD               [12] 1651 	mov	r5,a
                           00019A  1652 	C$Hello.c$126$3$45 ==.
                                   1653 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:126: printf("\n\r");
      0001FC C0 07            [24] 1654 	push	ar7
      0001FE C0 06            [24] 1655 	push	ar6
      000200 C0 05            [24] 1656 	push	ar5
      000202 74 8E            [12] 1657 	mov	a,#___str_4
      000204 C0 E0            [24] 1658 	push	acc
      000206 74 09            [12] 1659 	mov	a,#(___str_4 >> 8)
      000208 C0 E0            [24] 1660 	push	acc
      00020A 74 80            [12] 1661 	mov	a,#0x80
      00020C C0 E0            [24] 1662 	push	acc
      00020E 12 03 51         [24] 1663 	lcall	_printf
      000211 15 81            [12] 1664 	dec	sp
      000213 15 81            [12] 1665 	dec	sp
      000215 15 81            [12] 1666 	dec	sp
      000217 D0 05            [24] 1667 	pop	ar5
      000219 D0 06            [24] 1668 	pop	ar6
      00021B D0 07            [24] 1669 	pop	ar7
                           0001BB  1670 	C$Hello.c$128$3$45 ==.
                                   1671 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:128: if(Pot3 == 1)
      00021D 30 93 25         [24] 1672 	jnb	_Pot3,00111$
                           0001BE  1673 	C$Hello.c$130$4$52 ==.
                                   1674 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:130: LED3 = 1;
      000220 D2 A3            [12] 1675 	setb	_LED3
                           0001C0  1676 	C$Hello.c$131$4$52 ==.
                                   1677 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:131: printf("LED3 is HIGH");
      000222 C0 07            [24] 1678 	push	ar7
      000224 C0 06            [24] 1679 	push	ar6
      000226 C0 05            [24] 1680 	push	ar5
      000228 74 C3            [12] 1681 	mov	a,#___str_9
      00022A C0 E0            [24] 1682 	push	acc
      00022C 74 09            [12] 1683 	mov	a,#(___str_9 >> 8)
      00022E C0 E0            [24] 1684 	push	acc
      000230 74 80            [12] 1685 	mov	a,#0x80
      000232 C0 E0            [24] 1686 	push	acc
      000234 12 03 51         [24] 1687 	lcall	_printf
      000237 15 81            [12] 1688 	dec	sp
      000239 15 81            [12] 1689 	dec	sp
      00023B 15 81            [12] 1690 	dec	sp
      00023D D0 05            [24] 1691 	pop	ar5
      00023F D0 06            [24] 1692 	pop	ar6
      000241 D0 07            [24] 1693 	pop	ar7
      000243 80 23            [24] 1694 	sjmp	00112$
      000245                       1695 00111$:
                           0001E3  1696 	C$Hello.c$135$4$53 ==.
                                   1697 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:135: LED3 = 0;
      000245 C2 A3            [12] 1698 	clr	_LED3
                           0001E5  1699 	C$Hello.c$136$4$53 ==.
                                   1700 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:136: printf("LED3 is LOW");
      000247 C0 07            [24] 1701 	push	ar7
      000249 C0 06            [24] 1702 	push	ar6
      00024B C0 05            [24] 1703 	push	ar5
      00024D 74 D0            [12] 1704 	mov	a,#___str_10
      00024F C0 E0            [24] 1705 	push	acc
      000251 74 09            [12] 1706 	mov	a,#(___str_10 >> 8)
      000253 C0 E0            [24] 1707 	push	acc
      000255 74 80            [12] 1708 	mov	a,#0x80
      000257 C0 E0            [24] 1709 	push	acc
      000259 12 03 51         [24] 1710 	lcall	_printf
      00025C 15 81            [12] 1711 	dec	sp
      00025E 15 81            [12] 1712 	dec	sp
      000260 15 81            [12] 1713 	dec	sp
      000262 D0 05            [24] 1714 	pop	ar5
      000264 D0 06            [24] 1715 	pop	ar6
      000266 D0 07            [24] 1716 	pop	ar7
      000268                       1717 00112$:
                           000206  1718 	C$Hello.c$138$3$45 ==.
                                   1719 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:138: Mem3 = Pot3;
      000268 A2 93            [12] 1720 	mov	c,_Pot3
      00026A E4               [12] 1721 	clr	a
      00026B 33               [12] 1722 	rlc	a
      00026C FC               [12] 1723 	mov	r4,a
      00026D                       1724 00114$:
                           00020B  1725 	C$Hello.c$141$2$44 ==.
                                   1726 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:141: printf("\033[H"); //go home, top left
      00026D C0 07            [24] 1727 	push	ar7
      00026F C0 06            [24] 1728 	push	ar6
      000271 C0 05            [24] 1729 	push	ar5
      000273 C0 04            [24] 1730 	push	ar4
      000275 74 6C            [12] 1731 	mov	a,#___str_0
      000277 C0 E0            [24] 1732 	push	acc
      000279 74 09            [12] 1733 	mov	a,#(___str_0 >> 8)
      00027B C0 E0            [24] 1734 	push	acc
      00027D 74 80            [12] 1735 	mov	a,#0x80
      00027F C0 E0            [24] 1736 	push	acc
      000281 12 03 51         [24] 1737 	lcall	_printf
      000284 15 81            [12] 1738 	dec	sp
      000286 15 81            [12] 1739 	dec	sp
      000288 15 81            [12] 1740 	dec	sp
      00028A D0 04            [24] 1741 	pop	ar4
      00028C D0 05            [24] 1742 	pop	ar5
      00028E D0 06            [24] 1743 	pop	ar6
      000290 D0 07            [24] 1744 	pop	ar7
      000292 02 00 A1         [24] 1745 	ljmp	00119$
                           000233  1746 	C$Hello.c$143$1$43 ==.
                           000233  1747 	XG$main$0$0 ==.
      000295 22               [24] 1748 	ret
                                   1749 ;------------------------------------------------------------
                                   1750 ;Allocation info for local variables in function 'SYSCLK_INIT'
                                   1751 ;------------------------------------------------------------
                                   1752 ;i                         Allocated to registers r5 r6 
                                   1753 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1754 ;------------------------------------------------------------
                           000234  1755 	G$SYSCLK_INIT$0$0 ==.
                           000234  1756 	C$Hello.c$151$1$43 ==.
                                   1757 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:151: void SYSCLK_INIT(void)
                                   1758 ;	-----------------------------------------
                                   1759 ;	 function SYSCLK_INIT
                                   1760 ;	-----------------------------------------
      000296                       1761 _SYSCLK_INIT:
                           000234  1762 	C$Hello.c$156$1$55 ==.
                                   1763 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:156: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      000296 AF 84            [24] 1764 	mov	r7,_SFRPAGE
                           000236  1765 	C$Hello.c$158$1$55 ==.
                                   1766 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:158: SFRPAGE = CONFIG_PAGE;
      000298 75 84 0F         [24] 1767 	mov	_SFRPAGE,#0x0f
                           000239  1768 	C$Hello.c$159$1$55 ==.
                                   1769 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:159: OSCXCN  = 0x67;                     // Start ext osc with 22.1184MHz crystal
      00029B 75 8C 67         [24] 1770 	mov	_OSCXCN,#0x67
                           00023C  1771 	C$Hello.c$160$1$55 ==.
                                   1772 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:160: for(i=0; i < 256; i++);             // Wait for the oscillator to start up
      00029E 7D 00            [12] 1773 	mov	r5,#0x00
      0002A0 7E 01            [12] 1774 	mov	r6,#0x01
      0002A2                       1775 00111$:
      0002A2 1D               [12] 1776 	dec	r5
      0002A3 BD FF 01         [24] 1777 	cjne	r5,#0xff,00141$
      0002A6 1E               [12] 1778 	dec	r6
      0002A7                       1779 00141$:
      0002A7 ED               [12] 1780 	mov	a,r5
      0002A8 4E               [12] 1781 	orl	a,r6
      0002A9 70 F7            [24] 1782 	jnz	00111$
                           000249  1783 	C$Hello.c$161$1$55 ==.
                                   1784 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:161: while(!(OSCXCN & 0x80));
      0002AB                       1785 00102$:
      0002AB E5 8C            [12] 1786 	mov	a,_OSCXCN
      0002AD 30 E7 FB         [24] 1787 	jnb	acc.7,00102$
                           00024E  1788 	C$Hello.c$162$1$55 ==.
                                   1789 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:162: CLKSEL  = 0x01;
      0002B0 75 97 01         [24] 1790 	mov	_CLKSEL,#0x01
                           000251  1791 	C$Hello.c$163$1$55 ==.
                                   1792 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:163: OSCICN  = 0x00;
      0002B3 75 8A 00         [24] 1793 	mov	_OSCICN,#0x00
                           000254  1794 	C$Hello.c$165$1$55 ==.
                                   1795 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:165: SFRPAGE = CONFIG_PAGE;
      0002B6 75 84 0F         [24] 1796 	mov	_SFRPAGE,#0x0f
                           000257  1797 	C$Hello.c$166$1$55 ==.
                                   1798 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:166: PLL0CN  = 0x04;
      0002B9 75 89 04         [24] 1799 	mov	_PLL0CN,#0x04
                           00025A  1800 	C$Hello.c$167$1$55 ==.
                                   1801 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:167: SFRPAGE = LEGACY_PAGE;
      0002BC 75 84 00         [24] 1802 	mov	_SFRPAGE,#0x00
                           00025D  1803 	C$Hello.c$168$1$55 ==.
                                   1804 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:168: FLSCL   = 0x10;
      0002BF 75 B7 10         [24] 1805 	mov	_FLSCL,#0x10
                           000260  1806 	C$Hello.c$169$1$55 ==.
                                   1807 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:169: SFRPAGE = CONFIG_PAGE;
      0002C2 75 84 0F         [24] 1808 	mov	_SFRPAGE,#0x0f
                           000263  1809 	C$Hello.c$170$1$55 ==.
                                   1810 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:170: PLL0CN |= 0x01;
      0002C5 43 89 01         [24] 1811 	orl	_PLL0CN,#0x01
                           000266  1812 	C$Hello.c$171$1$55 ==.
                                   1813 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:171: PLL0DIV = 0x04;
      0002C8 75 8D 04         [24] 1814 	mov	_PLL0DIV,#0x04
                           000269  1815 	C$Hello.c$172$1$55 ==.
                                   1816 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:172: PLL0FLT = 0x01;
      0002CB 75 8F 01         [24] 1817 	mov	_PLL0FLT,#0x01
                           00026C  1818 	C$Hello.c$173$1$55 ==.
                                   1819 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:173: PLL0MUL = 0x09;
      0002CE 75 8E 09         [24] 1820 	mov	_PLL0MUL,#0x09
                           00026F  1821 	C$Hello.c$174$1$55 ==.
                                   1822 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:174: for(i=0; i < 256; i++);
      0002D1 7D 00            [12] 1823 	mov	r5,#0x00
      0002D3 7E 01            [12] 1824 	mov	r6,#0x01
      0002D5                       1825 00114$:
      0002D5 1D               [12] 1826 	dec	r5
      0002D6 BD FF 01         [24] 1827 	cjne	r5,#0xff,00144$
      0002D9 1E               [12] 1828 	dec	r6
      0002DA                       1829 00144$:
      0002DA ED               [12] 1830 	mov	a,r5
      0002DB 4E               [12] 1831 	orl	a,r6
      0002DC 70 F7            [24] 1832 	jnz	00114$
                           00027C  1833 	C$Hello.c$175$1$55 ==.
                                   1834 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:175: PLL0CN |= 0x02;
      0002DE 43 89 02         [24] 1835 	orl	_PLL0CN,#0x02
                           00027F  1836 	C$Hello.c$176$1$55 ==.
                                   1837 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:176: while(!(PLL0CN & 0x10));
      0002E1                       1838 00106$:
      0002E1 E5 89            [12] 1839 	mov	a,_PLL0CN
      0002E3 30 E4 FB         [24] 1840 	jnb	acc.4,00106$
                           000284  1841 	C$Hello.c$177$1$55 ==.
                                   1842 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:177: CLKSEL  = 0x02;
      0002E6 75 97 02         [24] 1843 	mov	_CLKSEL,#0x02
                           000287  1844 	C$Hello.c$179$1$55 ==.
                                   1845 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:179: SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
      0002E9 8F 84            [24] 1846 	mov	_SFRPAGE,r7
                           000289  1847 	C$Hello.c$180$1$55 ==.
                           000289  1848 	XG$SYSCLK_INIT$0$0 ==.
      0002EB 22               [24] 1849 	ret
                                   1850 ;------------------------------------------------------------
                                   1851 ;Allocation info for local variables in function 'PORT_INIT'
                                   1852 ;------------------------------------------------------------
                                   1853 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1854 ;------------------------------------------------------------
                           00028A  1855 	G$PORT_INIT$0$0 ==.
                           00028A  1856 	C$Hello.c$188$1$55 ==.
                                   1857 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:188: void PORT_INIT(void)
                                   1858 ;	-----------------------------------------
                                   1859 ;	 function PORT_INIT
                                   1860 ;	-----------------------------------------
      0002EC                       1861 _PORT_INIT:
                           00028A  1862 	C$Hello.c$192$1$57 ==.
                                   1863 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:192: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      0002EC AF 84            [24] 1864 	mov	r7,_SFRPAGE
                           00028C  1865 	C$Hello.c$194$1$57 ==.
                                   1866 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:194: SFRPAGE  = CONFIG_PAGE;
      0002EE 75 84 0F         [24] 1867 	mov	_SFRPAGE,#0x0f
                           00028F  1868 	C$Hello.c$195$1$57 ==.
                                   1869 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:195: XBR0     = 0x04;                    // Enable UART0
      0002F1 75 E1 04         [24] 1870 	mov	_XBR0,#0x04
                           000292  1871 	C$Hello.c$196$1$57 ==.
                                   1872 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:196: XBR1     = 0x00;
      0002F4 75 E2 00         [24] 1873 	mov	_XBR1,#0x00
                           000295  1874 	C$Hello.c$197$1$57 ==.
                                   1875 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:197: XBR2     = 0x40;                    // Enable Crossbar and weak pull-up
      0002F7 75 E3 40         [24] 1876 	mov	_XBR2,#0x40
                           000298  1877 	C$Hello.c$199$1$57 ==.
                                   1878 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:199: P0MDOUT |= 0x01;                    // Set TX0 on P0.0 pin to push-pull
      0002FA 43 A4 01         [24] 1879 	orl	_P0MDOUT,#0x01
                           00029B  1880 	C$Hello.c$202$1$57 ==.
                                   1881 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:202: P1MDOUT &= 0xF0; //Sets input pins 0-3 using F0: 1111 0000
      0002FD 53 A5 F0         [24] 1882 	anl	_P1MDOUT,#0xf0
                           00029E  1883 	C$Hello.c$203$1$57 ==.
                                   1884 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:203: P1 |= 0x0F; //Pules input pins 0-3 with 0000 1111
      000300 43 90 0F         [24] 1885 	orl	_P1,#0x0f
                           0002A1  1886 	C$Hello.c$206$1$57 ==.
                                   1887 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:206: P2MDOUT |= 0x0F; //set output pins (port 1) to pushpull using 0000 1111
      000303 43 A6 0F         [24] 1888 	orl	_P2MDOUT,#0x0f
                           0002A4  1889 	C$Hello.c$208$1$57 ==.
                                   1890 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:208: SFRPAGE = SFRPAGE_SAVE;            // Restore SFR page
      000306 8F 84            [24] 1891 	mov	_SFRPAGE,r7
                           0002A6  1892 	C$Hello.c$209$1$57 ==.
                           0002A6  1893 	XG$PORT_INIT$0$0 ==.
      000308 22               [24] 1894 	ret
                                   1895 ;------------------------------------------------------------
                                   1896 ;Allocation info for local variables in function 'UART0_INIT'
                                   1897 ;------------------------------------------------------------
                                   1898 ;SFRPAGE_SAVE              Allocated to registers r7 
                                   1899 ;------------------------------------------------------------
                           0002A7  1900 	G$UART0_INIT$0$0 ==.
                           0002A7  1901 	C$Hello.c$218$1$57 ==.
                                   1902 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:218: void UART0_INIT(void)
                                   1903 ;	-----------------------------------------
                                   1904 ;	 function UART0_INIT
                                   1905 ;	-----------------------------------------
      000309                       1906 _UART0_INIT:
                           0002A7  1907 	C$Hello.c$222$1$59 ==.
                                   1908 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:222: SFRPAGE_SAVE = SFRPAGE;             // Save Current SFR page
      000309 AF 84            [24] 1909 	mov	r7,_SFRPAGE
                           0002A9  1910 	C$Hello.c$224$1$59 ==.
                                   1911 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:224: SFRPAGE = TIMER01_PAGE;
      00030B 75 84 00         [24] 1912 	mov	_SFRPAGE,#0x00
                           0002AC  1913 	C$Hello.c$225$1$59 ==.
                                   1914 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:225: TMOD   &= ~0xF0;
      00030E 53 89 0F         [24] 1915 	anl	_TMOD,#0x0f
                           0002AF  1916 	C$Hello.c$226$1$59 ==.
                                   1917 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:226: TMOD   |=  0x20;                    // Timer1, Mode 2, 8-bit reload
      000311 43 89 20         [24] 1918 	orl	_TMOD,#0x20
                           0002B2  1919 	C$Hello.c$227$1$59 ==.
                                   1920 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:227: TH1     = -(SYSCLK/BAUDRATE/16);    // Set Timer1 reload baudrate value T1 Hi Byte
      000314 75 8D E5         [24] 1921 	mov	_TH1,#0xe5
                           0002B5  1922 	C$Hello.c$228$1$59 ==.
                                   1923 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:228: CKCON  |= 0x10;                     // Timer1 uses SYSCLK as time base
      000317 43 8E 10         [24] 1924 	orl	_CKCON,#0x10
                           0002B8  1925 	C$Hello.c$229$1$59 ==.
                                   1926 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:229: TL1     = TH1;
      00031A 85 8D 8B         [24] 1927 	mov	_TL1,_TH1
                           0002BB  1928 	C$Hello.c$230$1$59 ==.
                                   1929 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:230: TR1     = 1;                        // Start Timer1
      00031D D2 8E            [12] 1930 	setb	_TR1
                           0002BD  1931 	C$Hello.c$232$1$59 ==.
                                   1932 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:232: SFRPAGE = UART0_PAGE;
      00031F 75 84 00         [24] 1933 	mov	_SFRPAGE,#0x00
                           0002C0  1934 	C$Hello.c$233$1$59 ==.
                                   1935 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:233: SCON0   = 0x50;                     // Mode 1, 8-bit UART, enable RX
      000322 75 98 50         [24] 1936 	mov	_SCON0,#0x50
                           0002C3  1937 	C$Hello.c$234$1$59 ==.
                                   1938 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:234: SSTA0   = 0x10;                     // SMOD0 = 1
      000325 75 91 10         [24] 1939 	mov	_SSTA0,#0x10
                           0002C6  1940 	C$Hello.c$235$1$59 ==.
                                   1941 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:235: TI0     = 1;                        // Indicate TX0 ready
      000328 D2 99            [12] 1942 	setb	_TI0
                           0002C8  1943 	C$Hello.c$237$1$59 ==.
                                   1944 ;	C:\Users\cwpyb\Google Drive\Microprocessor Systems\Lab 01\Test Code\Hello.c:237: SFRPAGE = SFRPAGE_SAVE;             // Restore SFR page
      00032A 8F 84            [24] 1945 	mov	_SFRPAGE,r7
                           0002CA  1946 	C$Hello.c$238$1$59 ==.
                           0002CA  1947 	XG$UART0_INIT$0$0 ==.
      00032C 22               [24] 1948 	ret
                                   1949 	.area CSEG    (CODE)
                                   1950 	.area CONST   (CODE)
                           000000  1951 FHello$__str_0$0$0 == .
      00096C                       1952 ___str_0:
      00096C 1B                    1953 	.db 0x1b
      00096D 5B 48                 1954 	.ascii "[H"
      00096F 00                    1955 	.db 0x00
                           000004  1956 FHello$__str_1$0$0 == .
      000970                       1957 ___str_1:
      000970 1B                    1958 	.db 0x1b
      000971 5B 32 4A              1959 	.ascii "[2J"
      000974 00                    1960 	.db 0x00
                           000009  1961 FHello$__str_2$0$0 == .
      000975                       1962 ___str_2:
      000975 4C 45 44 30 20 69 73  1963 	.ascii "LED0 is HIGH"
             20 48 49 47 48
      000981 00                    1964 	.db 0x00
                           000016  1965 FHello$__str_3$0$0 == .
      000982                       1966 ___str_3:
      000982 4C 45 44 30 20 69 73  1967 	.ascii "LED0 is LOW"
             20 4C 4F 57
      00098D 00                    1968 	.db 0x00
                           000022  1969 FHello$__str_4$0$0 == .
      00098E                       1970 ___str_4:
      00098E 0A                    1971 	.db 0x0a
      00098F 0D                    1972 	.db 0x0d
      000990 00                    1973 	.db 0x00
                           000025  1974 FHello$__str_5$0$0 == .
      000991                       1975 ___str_5:
      000991 4C 45 44 31 20 69 73  1976 	.ascii "LED1 is HIGH"
             20 48 49 47 48
      00099D 00                    1977 	.db 0x00
                           000032  1978 FHello$__str_6$0$0 == .
      00099E                       1979 ___str_6:
      00099E 4C 45 44 31 20 69 73  1980 	.ascii "LED1 is LOW"
             20 4C 4F 57
      0009A9 00                    1981 	.db 0x00
                           00003E  1982 FHello$__str_7$0$0 == .
      0009AA                       1983 ___str_7:
      0009AA 4C 45 44 32 20 69 73  1984 	.ascii "LED2 is HIGH"
             20 48 49 47 48
      0009B6 00                    1985 	.db 0x00
                           00004B  1986 FHello$__str_8$0$0 == .
      0009B7                       1987 ___str_8:
      0009B7 4C 45 44 32 20 69 73  1988 	.ascii "LED2 is LOW"
             20 4C 4F 57
      0009C2 00                    1989 	.db 0x00
                           000057  1990 FHello$__str_9$0$0 == .
      0009C3                       1991 ___str_9:
      0009C3 4C 45 44 33 20 69 73  1992 	.ascii "LED3 is HIGH"
             20 48 49 47 48
      0009CF 00                    1993 	.db 0x00
                           000064  1994 FHello$__str_10$0$0 == .
      0009D0                       1995 ___str_10:
      0009D0 4C 45 44 33 20 69 73  1996 	.ascii "LED3 is LOW"
             20 4C 4F 57
      0009DB 00                    1997 	.db 0x00
                                   1998 	.area XINIT   (CODE)
                                   1999 	.area CABS    (ABS,CODE)
