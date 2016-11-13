EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:version-2.0-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "LED Controller"
Date "2016-11-12"
Rev "2.0"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L D D1
U 1 1 58270980
P 4950 1900
F 0 "D1" H 4950 1685 50  0000 C CNN
F 1 "BY550-400" H 4950 1776 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-201AD_Horizontal_RM15" H 4950 1900 50  0001 C CNN
F 3 "http://www.tme.eu/cz/Document/87b624f7fc2c535d2fa61b0c7bf239f6/by55050.pdf" H 4950 1900 50  0001 C CNN
F 4 "http://www.tme.eu/cz/details/by550_400/univerzalni-diody-tht/diotec-semiconductor/by550-400/" H 4950 1900 60  0001 C CNN "TME"
	1    4950 1900
	-1   0    0    1   
$EndComp
$Comp
L C C2
U 1 1 58270A6A
P 6550 2000
F 0 "C2" H 6435 1954 50  0000 R CNN
F 1 "100n" H 6435 2045 50  0000 R CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 6435 2091 50  0001 R CNN
F 3 "http://www.tme.eu/cz/Document/7da762c1dbaf553c64ad9c40d3603826/mlcc_samsung.pdf" H 6550 2000 50  0001 C CNN
F 4 "http://www.tme.eu/cz/details/cl31b104kbcnnnc/kondenzatory-mlcc-smd-1206/samsung/" H 6550 2000 60  0001 C CNN "TME"
	1    6550 2000
	-1   0    0    1   
$EndComp
$Comp
L +12V #PWR01
U 1 1 58270AE8
P 5100 1900
F 0 "#PWR01" H 5100 1750 50  0001 C CNN
F 1 "+12V" V 5050 2000 50  0000 L CNN
F 2 "" H 5100 1900 50  0000 C CNN
F 3 "" H 5100 1900 50  0000 C CNN
	1    5100 1900
	0    1    1    0   
$EndComp
$Comp
L GND #PWR02
U 1 1 58270B48
P 5100 2100
F 0 "#PWR02" H 5100 1850 50  0001 C CNN
F 1 "GND" H 5105 1927 50  0000 C CNN
F 2 "" H 5100 2100 50  0000 C CNN
F 3 "" H 5100 2100 50  0000 C CNN
	1    5100 2100
	0    -1   -1   0   
$EndComp
$Comp
L +12V #PWR03
U 1 1 58270BB3
P 5850 1850
F 0 "#PWR03" H 5850 1700 50  0001 C CNN
F 1 "+12V" V 5900 1900 50  0000 L CNN
F 2 "" H 5850 1850 50  0000 C CNN
F 3 "" H 5850 1850 50  0000 C CNN
	1    5850 1850
	0    -1   -1   0   
$EndComp
$Comp
L CP C1
U 1 1 58270C3E
P 6150 2000
F 0 "C1" H 6268 2046 50  0000 L CNN
F 1 "470u" H 6268 1955 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D8_L11.5_P3.5" H 6188 1850 50  0001 C CNN
F 3 "http://www.tme.eu/cz/Document/95f1702899caf3417754a5fd068c4081/e-vr.pdf" H 6150 2000 50  0001 C CNN
F 4 "http://www.tme.eu/cz/details/uvr1c471mpd/elektrolyticke-kondenzatory-tht-85c/nichicon/" H 6150 2000 60  0001 C CNN "TME"
	1    6150 2000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 58270DD5
P 5800 2150
F 0 "#PWR04" H 5800 1900 50  0001 C CNN
F 1 "GND" V 5750 2050 50  0000 R CNN
F 2 "" H 5800 2150 50  0000 C CNN
F 3 "" H 5800 2150 50  0000 C CNN
	1    5800 2150
	0    1    1    0   
$EndComp
$Comp
L LM78M05CT U1
U 1 1 58270F2F
P 7150 1900
F 0 "U1" H 7150 2217 50  0000 C CNN
F 1 "MC78M05CTG" H 7150 2126 50  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Neutral123_Vertical_LargePads" H 7150 2126 50  0001 C CIN
F 3 "http://www.tme.eu/en/Document/e6827e79e50498f3a8ba807c429dcc98/MC78M00-D.PDF" H 7150 1900 50  0001 C CNN
F 4 "http://www.tme.eu/en/details/mc78m05ctg/unregulated-voltage-regulators/on-semiconductor/" H 7150 1900 60  0001 C CNN "TME"
	1    7150 1900
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5827101A
P 7650 2000
F 0 "C3" H 7535 1954 50  0000 R CNN
F 1 "100n" H 7535 2045 50  0000 R CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 7535 2091 50  0001 R CNN
F 3 "http://www.tme.eu/cz/Document/7da762c1dbaf553c64ad9c40d3603826/mlcc_samsung.pdf" H 7650 2000 50  0001 C CNN
F 4 "http://www.tme.eu/cz/details/cl31b104kbcnnnc/kondenzatory-mlcc-smd-1206/samsung/" H 7650 2000 60  0001 C CNN "TME"
	1    7650 2000
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR05
U 1 1 582710A1
P 7900 1850
F 0 "#PWR05" H 7900 1700 50  0001 C CNN
F 1 "+5V" V 7915 1978 50  0000 L CNN
F 2 "" H 7900 1850 50  0000 C CNN
F 3 "" H 7900 1850 50  0000 C CNN
	1    7900 1850
	0    1    1    0   
$EndComp
$Comp
L Screw_Terminal_1x02 J1
U 1 1 58271362
P 4400 2000
F 0 "J1" H 4480 2342 50  0000 C CNN
F 1 "DG300-5.0" H 4480 2251 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-2pol" H 4400 1775 50  0001 C CNN
F 3 "http://www.tme.eu/en/Document/adcdc895102d44b158b752608cb08ff1/DG300-5.0.pdf" H 4375 2000 50  0001 C CNN
F 4 "http://www.tme.eu/en/details/dg300-5.0-2p12/terminal-blocks-pcb-mount/degson-electronics/dg300-50-02p-12-00ah/" H 4400 2000 60  0001 C CNN "TME"
	1    4400 2000
	1    0    0    1   
$EndComp
$Comp
L GND #PWR06
U 1 1 5827166E
P 4450 5100
F 0 "#PWR06" H 4450 4850 50  0001 C CNN
F 1 "GND" H 4600 5050 50  0000 C CNN
F 2 "" H 4450 5100 50  0000 C CNN
F 3 "" H 4450 5100 50  0000 C CNN
	1    4450 5100
	1    0    0    -1  
$EndComp
NoConn ~ 6550 3600
NoConn ~ 6550 3700
NoConn ~ 6550 3800
NoConn ~ 6550 4100
NoConn ~ 6550 4000
NoConn ~ 6550 3900
$Comp
L +5V #PWR07
U 1 1 5827180B
P 4200 2750
F 0 "#PWR07" H 4200 2600 50  0001 C CNN
F 1 "+5V" V 4300 2700 50  0000 L CNN
F 2 "" H 4200 2750 50  0000 C CNN
F 3 "" H 4200 2750 50  0000 C CNN
	1    4200 2750
	0    -1   -1   0   
$EndComp
$Comp
L C C4
U 1 1 5827192C
P 4450 3000
F 0 "C4" H 4700 2950 50  0000 R CNN
F 1 "100n" H 4750 3050 50  0000 R CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 4335 3091 50  0001 R CNN
F 3 "http://www.tme.eu/cz/Document/7da762c1dbaf553c64ad9c40d3603826/mlcc_samsung.pdf" H 4450 3000 50  0001 C CNN
F 4 "http://www.tme.eu/cz/details/cl31b104kbcnnnc/kondenzatory-mlcc-smd-1206/samsung/" H 4450 3000 60  0001 C CNN "TME"
	1    4450 3000
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X09 P2
U 1 1 5827249E
P 7750 3150
F 0 "P2" H 7827 3191 50  0000 L CNN
F 1 "IQRF BB-01" H 7827 3100 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x09" H 7827 3054 50  0001 L CNN
F 3 "" H 7750 3150 50  0000 C CNN
	1    7750 3150
	1    0    0    -1  
$EndComp
$Comp
L IRLB8721PBF Q1
U 1 1 582730E3
P 7650 4100
F 0 "Q1" H 7850 4250 50  0000 L CNN
F 1 "IRLB8721PBF" H 7600 4350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Neutral123_Vertical_LargePads" H 7900 4025 50  0001 L CIN
F 3 "" H 7650 4100 50  0000 L CNN
	1    7650 4100
	1    0    0    -1  
$EndComp
$Comp
L IRLB8721PBF Q2
U 1 1 5827312F
P 7650 4650
F 0 "Q2" H 7850 4550 50  0000 L CNN
F 1 "IRLB8721PBF" H 7650 4400 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Neutral123_Vertical_LargePads" H 7900 4575 50  0001 L CIN
F 3 "" H 7650 4650 50  0000 L CNN
	1    7650 4650
	1    0    0    -1  
$EndComp
$Comp
L IRLB8721PBF Q3
U 1 1 58273179
P 7650 5200
F 0 "Q3" H 7841 5246 50  0000 L CNN
F 1 "IRLB8721PBF" H 7841 5155 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Neutral123_Vertical_LargePads" H 7900 5125 50  0001 L CIN
F 3 "" H 7650 5200 50  0000 L CNN
	1    7650 5200
	1    0    0    -1  
$EndComp
NoConn ~ 6550 5050
NoConn ~ 6550 4750
NoConn ~ 6550 4550
$Comp
L R R2
U 1 1 58273531
P 7400 4300
F 0 "R2" H 7470 4346 50  0000 L CNN
F 1 "10k" H 7470 4255 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7330 4300 50  0001 C CNN
F 3 "http://www.tme.eu/en/Document/b315665a56acbc42df513c99b390ad98/ROYALOHM-THICKFILM.pdf" H 7470 4209 50  0001 L CNN
F 4 "http://www.tme.eu/en/details/smd1206-10k-1%25/1206-smd-resistors/royal-ohm/1206s4f1002t5e/" H 7400 4300 60  0001 C CNN "TME"
	1    7400 4300
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 58273673
P 7400 4850
F 0 "R3" H 7470 4896 50  0000 L CNN
F 1 "10k" H 7470 4805 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7330 4850 50  0001 C CNN
F 3 "http://www.tme.eu/en/Document/b315665a56acbc42df513c99b390ad98/ROYALOHM-THICKFILM.pdf" H 7470 4759 50  0001 L CNN
F 4 "http://www.tme.eu/en/details/smd1206-10k-1%25/1206-smd-resistors/royal-ohm/1206s4f1002t5e/" H 7400 4850 60  0001 C CNN "TME"
	1    7400 4850
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 582736D7
P 7400 5400
F 0 "R4" H 7470 5446 50  0000 L CNN
F 1 "10k" H 7470 5355 50  0000 L CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 7330 5400 50  0001 C CNN
F 3 "http://www.tme.eu/en/Document/b315665a56acbc42df513c99b390ad98/ROYALOHM-THICKFILM.pdf" H 7470 5309 50  0001 L CNN
F 4 "http://www.tme.eu/en/details/smd1206-10k-1%25/1206-smd-resistors/royal-ohm/1206s4f1002t5e/" H 7400 5400 60  0001 C CNN "TME"
	1    7400 5400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 58273C30
P 7450 4450
F 0 "#PWR08" H 7450 4200 50  0001 C CNN
F 1 "GND" V 7455 4322 50  0000 R CNN
F 2 "" H 7450 4450 50  0000 C CNN
F 3 "" H 7450 4450 50  0000 C CNN
	1    7450 4450
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR09
U 1 1 58273C94
P 7450 5000
F 0 "#PWR09" H 7450 4750 50  0001 C CNN
F 1 "GND" V 7455 4872 50  0000 R CNN
F 2 "" H 7450 5000 50  0000 C CNN
F 3 "" H 7450 5000 50  0000 C CNN
	1    7450 5000
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR010
U 1 1 58273D18
P 7450 5550
F 0 "#PWR010" H 7450 5300 50  0001 C CNN
F 1 "GND" V 7455 5422 50  0000 R CNN
F 2 "" H 7450 5550 50  0000 C CNN
F 3 "" H 7450 5550 50  0000 C CNN
	1    7450 5550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR011
U 1 1 5827476E
P 7800 4300
F 0 "#PWR011" H 7800 4050 50  0001 C CNN
F 1 "GND" V 7805 4172 50  0000 R CNN
F 2 "" H 7800 4300 50  0000 C CNN
F 3 "" H 7800 4300 50  0000 C CNN
	1    7800 4300
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR012
U 1 1 582749E1
P 7800 4850
F 0 "#PWR012" H 7800 4600 50  0001 C CNN
F 1 "GND" V 7805 4722 50  0000 R CNN
F 2 "" H 7800 4850 50  0000 C CNN
F 3 "" H 7800 4850 50  0000 C CNN
	1    7800 4850
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR013
U 1 1 58274A3C
P 7800 5400
F 0 "#PWR013" H 7800 5150 50  0001 C CNN
F 1 "GND" V 7805 5272 50  0000 R CNN
F 2 "" H 7800 5400 50  0000 C CNN
F 3 "" H 7800 5400 50  0000 C CNN
	1    7800 5400
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X03 P3
U 1 1 58275BB9
P 6950 4450
F 0 "P3" H 7028 4491 50  0000 L CNN
F 1 "UART" H 7050 4350 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 6950 4450 50  0001 C CNN
F 3 "" H 6950 4450 50  0000 C CNN
	1    6950 4450
	1    0    0    1   
$EndComp
$Comp
L GND #PWR014
U 1 1 58275CAE
P 6700 4550
F 0 "#PWR014" H 6700 4300 50  0001 C CNN
F 1 "GND" V 6750 4700 50  0000 R CNN
F 2 "" H 6700 4550 50  0000 C CNN
F 3 "" H 6700 4550 50  0000 C CNN
	1    6700 4550
	0    1    1    0   
$EndComp
$Comp
L Screw_Terminal_1x04 J2
U 1 1 5827668B
P 8650 4700
F 0 "J2" H 8731 5242 50  0000 C CNN
F 1 "RGB LED" H 8731 5151 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-4pol" H 8650 4275 50  0001 C CNN
F 3 "" H 8625 4900 50  0001 C CNN
	1    8650 4700
	-1   0    0    -1  
$EndComp
$Comp
L +12V #PWR015
U 1 1 58276878
P 8300 4400
F 0 "#PWR015" H 8300 4250 50  0001 C CNN
F 1 "+12V" V 8350 4300 50  0000 L CNN
F 2 "" H 8300 4400 50  0000 C CNN
F 3 "" H 8300 4400 50  0000 C CNN
	1    8300 4400
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 58276C15
P 6700 4050
F 0 "R1" V 6493 4050 50  0000 C CNN
F 1 "10k" V 6584 4050 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 6630 4050 50  0001 C CNN
F 3 "" H 6770 3959 50  0001 L CNN
	1    6700 4050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR016
U 1 1 58276E3C
P 6700 3700
F 0 "#PWR016" H 6700 3550 50  0001 C CNN
F 1 "+5V" V 6600 3750 50  0000 C CNN
F 2 "" H 6700 3700 50  0000 C CNN
F 3 "" H 6700 3700 50  0000 C CNN
	1    6700 3700
	1    0    0    -1  
$EndComp
NoConn ~ 7550 2750
NoConn ~ 7550 2850
$Comp
L +5V #PWR017
U 1 1 58277297
P 7500 3550
F 0 "#PWR017" H 7500 3400 50  0001 C CNN
F 1 "+5V" V 7515 3678 50  0000 L CNN
F 2 "" H 7500 3550 50  0000 C CNN
F 3 "" H 7500 3550 50  0000 C CNN
	1    7500 3550
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR018
U 1 1 5827730A
P 7500 3450
F 0 "#PWR018" H 7500 3200 50  0001 C CNN
F 1 "GND" V 7505 3322 50  0000 R CNN
F 2 "" H 7500 3450 50  0000 C CNN
F 3 "" H 7500 3450 50  0000 C CNN
	1    7500 3450
	0    1    1    0   
$EndComp
NoConn ~ 6550 2750
$Comp
L CRYSTAL Y1
U 1 1 58278335
P 7000 3600
F 0 "Y1" H 7000 3332 50  0000 C CNN
F 1 "CRYSTAL" H 7000 3423 50  0000 C CNN
F 2 "Crystals:Crystal_HC49-U_Vertical" H 7000 3600 50  0001 C CNN
F 3 "http://www.tme.eu/cz/Document/6c671fc2d1c29550257ca2d207d0534f/HC49US_Series.pdf" H 7000 3600 50  0001 C CNN
	1    7000 3600
	-1   0    0    1   
$EndComp
$Comp
L C C5
U 1 1 582789E4
P 6850 3800
F 0 "C5" H 6650 3850 50  0000 L CNN
F 1 "18p" H 6600 3750 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 6888 3650 50  0001 C CNN
F 3 "http://www.tme.eu/cz/Document/7da762c1dbaf553c64ad9c40d3603826/mlcc_samsung.pdf" H 6965 3709 50  0001 L CNN
F 4 "http://www.tme.eu/cz/details/cl31c180jbcnnnc/kondenzatory-mlcc-smd-1206/samsung/" H 6850 3800 60  0001 C CNN "TME"
	1    6850 3800
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 58278B6F
P 7150 3800
F 0 "C6" H 7265 3846 50  0000 L CNN
F 1 "18p" H 7265 3755 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 7188 3650 50  0001 C CNN
F 3 "http://www.tme.eu/cz/Document/7da762c1dbaf553c64ad9c40d3603826/mlcc_samsung.pdf" H 7265 3709 50  0001 L CNN
F 4 "http://www.tme.eu/cz/details/cl31c180jbcnnnc/kondenzatory-mlcc-smd-1206/samsung/" H 7150 3800 60  0001 C CNN "TME"
	1    7150 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR019
U 1 1 58278E8C
P 7000 3950
F 0 "#PWR019" H 7000 3700 50  0001 C CNN
F 1 "GND" H 7005 3777 50  0000 C CNN
F 2 "" H 7000 3950 50  0000 C CNN
F 3 "" H 7000 3950 50  0000 C CNN
	1    7000 3950
	-1   0    0    1   
$EndComp
Text Label 6850 3250 0    60   ~ 0
SCK
Text Label 6850 3150 0    60   ~ 0
MISO
Text Label 6850 3050 0    60   ~ 0
MOSI
Text Label 6850 2950 0    60   ~ 0
SS
Text Label 6850 2850 0    60   ~ 0
TR_RESET
Text Label 6600 4350 0    60   ~ 0
RX
Text Label 6600 4450 0    60   ~ 0
TX
$Comp
L ATMEGA328P-P IC1
U 1 1 58279CDA
P 5550 3850
F 0 "IC1" H 5600 5217 50  0000 C CNN
F 1 "ATMEGA328P-P" H 5600 5126 50  0000 C CNN
F 2 "Housings_DIP:DIP-28_W7.62mm_LongPads" H 5600 5125 50  0001 C CIN
F 3 "" H 5550 3850 50  0000 C CNN
	1    5550 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P1
U 1 1 582847B5
P 7100 4150
F 0 "P1" H 7178 4191 50  0000 L CNN
F 1 "CONN_01X02" H 7178 4100 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 7177 4054 50  0001 L CNN
F 3 "" H 7100 4150 50  0000 C CNN
	1    7100 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 1900 5100 1900
Wire Wire Line
	5850 1850 6750 1850
Connection ~ 6150 1850
Wire Wire Line
	5800 2150 7650 2150
Connection ~ 6150 2150
Connection ~ 6550 1850
Connection ~ 6550 2150
Connection ~ 7150 2150
Wire Wire Line
	4600 2100 5100 2100
Wire Wire Line
	4800 1900 4600 1900
Wire Wire Line
	4450 5050 4650 5050
Wire Wire Line
	4450 3150 4450 5100
Wire Wire Line
	4650 4950 4450 4950
Connection ~ 4450 5050
Connection ~ 4450 4950
Wire Wire Line
	4200 2750 4650 2750
Wire Wire Line
	4600 2750 4600 3350
Connection ~ 4600 2750
Wire Wire Line
	4600 3050 4650 3050
Wire Wire Line
	4600 3350 4650 3350
Connection ~ 4600 3050
Wire Wire Line
	7300 5250 7450 5250
Wire Wire Line
	7300 4700 7450 4700
Wire Wire Line
	7300 4150 7450 4150
Wire Wire Line
	7300 4150 7300 4650
Connection ~ 7400 4150
Wire Wire Line
	7300 4700 7300 4850
Connection ~ 7400 4700
Wire Wire Line
	7300 4950 7300 5250
Connection ~ 7400 5250
Wire Wire Line
	7400 5000 7450 5000
Wire Wire Line
	7400 5550 7450 5550
Wire Wire Line
	4450 2750 4450 2850
Connection ~ 4450 2750
Wire Wire Line
	7550 1850 7900 1850
Connection ~ 7650 1850
Wire Wire Line
	7750 4300 7800 4300
Wire Wire Line
	7750 4850 7800 4850
Wire Wire Line
	7750 5400 7800 5400
Wire Wire Line
	7450 4450 7400 4450
Wire Wire Line
	7300 4650 6550 4650
Wire Wire Line
	7300 4850 6550 4850
Wire Wire Line
	7300 4950 6550 4950
Wire Wire Line
	7750 5000 8450 5000
Wire Wire Line
	7750 4450 8100 4450
Wire Wire Line
	8100 4450 8100 4800
Wire Wire Line
	8100 4800 8450 4800
Wire Wire Line
	7750 3900 8150 3900
Wire Wire Line
	8150 3900 8150 4600
Wire Wire Line
	8150 4600 8450 4600
Wire Wire Line
	7500 3450 7550 3450
Wire Wire Line
	7550 3550 7500 3550
Wire Wire Line
	7550 3350 7500 3350
Wire Wire Line
	7500 3350 7500 2850
Wire Wire Line
	7500 2850 6550 2850
Wire Wire Line
	6550 2950 7550 2950
Wire Wire Line
	6550 3050 7550 3050
Wire Wire Line
	6550 3150 7550 3150
Wire Wire Line
	6550 3250 7550 3250
Wire Wire Line
	6550 4450 6750 4450
Wire Wire Line
	6550 4350 6750 4350
Wire Wire Line
	6700 4550 6750 4550
Wire Wire Line
	6550 3350 7150 3350
Wire Wire Line
	7150 3350 7150 3650
Wire Wire Line
	6550 3450 6850 3450
Wire Wire Line
	6850 3450 6850 3650
Connection ~ 6850 3600
Connection ~ 7150 3600
Wire Wire Line
	6850 3950 7150 3950
Connection ~ 7000 3950
Wire Wire Line
	8300 4400 8450 4400
Wire Wire Line
	6700 3700 6700 3900
Wire Wire Line
	6550 4200 6900 4200
Connection ~ 6700 4200
Wire Wire Line
	6900 3950 6900 4100
Connection ~ 6900 3950
$EndSCHEMATC
