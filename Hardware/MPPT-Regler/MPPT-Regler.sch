EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
LIBS:tl594
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L TL594 U?
U 1 1 5AD26D27
P 4650 2450
F 0 "U?" H 5050 2500 60  0000 C CNN
F 1 "TL594" H 5050 1500 60  0000 C CNN
F 2 "" H 5000 1800 60  0001 C CNN
F 3 "" H 5000 1800 60  0001 C CNN
	1    4650 2450
	1    0    0    -1  
$EndComp
$Comp
L Aruino_Nano U?
U 1 1 5AD271ED
P 4700 4050
F 0 "U?" H 5050 2400 60  0000 C CNN
F 1 "Aruino_Nano" H 5100 4000 60  0000 C CNN
F 2 "" H 5100 2900 60  0001 C CNN
F 3 "" H 5100 2900 60  0001 C CNN
	1    4700 4050
	1    0    0    -1  
$EndComp
Text GLabel 5650 4500 2    60   Input ~ 0
5V
Text GLabel 5650 4300 2    60   Input ~ 0
LGND
Text GLabel 3750 3050 0    60   Input ~ 0
PGND
Text GLabel 5650 4700 2    60   Input ~ 0
Input_Curr
Text GLabel 5650 4600 2    60   Input ~ 0
Input_Volt
Text GLabel 5650 5200 2    60   Input ~ 0
Output_Corr
Text GLabel 5650 5100 2    60   Input ~ 0
Output_Volt
Text GLabel 4500 4800 0    60   Input ~ 0
SMPS_Power
Text GLabel 4500 5300 0    60   Input ~ 0
Fan_Enable
Text GLabel 5650 4900 2    60   Input ~ 0
SDA
Text GLabel 5650 4800 2    60   Input ~ 0
SCL
Text GLabel 4500 5100 0    60   Input ~ 0
Debug_Enable
$Comp
L LM358 U?
U 1 1 5AD2772D
P 1400 2450
F 0 "U?" H 1400 2650 50  0000 L CNN
F 1 "LM358" H 1400 2250 50  0000 L CNN
F 2 "" H 1400 2450 50  0001 C CNN
F 3 "" H 1400 2450 50  0001 C CNN
	1    1400 2450
	1    0    0    -1  
$EndComp
$Comp
L LM358 U?
U 2 1 5AD2774C
P 1400 3250
F 0 "U?" H 1400 3450 50  0000 L CNN
F 1 "LM358" H 1400 3050 50  0000 L CNN
F 2 "" H 1400 3250 50  0001 C CNN
F 3 "" H 1400 3250 50  0001 C CNN
	2    1400 3250
	1    0    0    -1  
$EndComp
$Comp
L IR2111 U?
U 1 1 5AD278D9
P 7150 2500
F 0 "U?" H 7450 1950 60  0000 C CNN
F 1 "IR2111" H 7500 2450 60  0000 C CNN
F 2 "" H 7550 1900 60  0001 C CNN
F 3 "" H 7550 1900 60  0001 C CNN
	1    7150 2500
	1    0    0    -1  
$EndComp
$Comp
L INA214 U?
U 1 1 5AD27A47
P 9300 4300
F 0 "U?" H 9450 4400 60  0000 C CNN
F 1 "INA214" H 9500 4800 60  0000 C CNN
F 2 "" H 9300 4300 60  0001 C CNN
F 3 "" H 9300 4300 60  0001 C CNN
	1    9300 4300
	1    0    0    -1  
$EndComp
$Comp
L INA214 U?
U 1 1 5AD27B2C
P 9900 5200
F 0 "U?" H 10050 5300 60  0000 C CNN
F 1 "INA214" H 10100 5700 60  0000 C CNN
F 2 "" H 9900 5200 60  0001 C CNN
F 3 "" H 9900 5200 60  0001 C CNN
	1    9900 5200
	1    0    0    -1  
$EndComp
$Comp
L IRFZ44N Q?
U 1 1 5AD27C18
P 9050 2550
F 0 "Q?" H 9300 2625 50  0000 L CNN
F 1 "IRFZ44N" H 9300 2550 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 9300 2475 50  0001 L CIN
F 3 "" H 9050 2550 50  0001 L CNN
	1    9050 2550
	1    0    0    -1  
$EndComp
$Comp
L IRFZ44N Q?
U 1 1 5AD27CA5
P 9050 3150
F 0 "Q?" H 9300 3225 50  0000 L CNN
F 1 "IRFZ44N" H 9300 3150 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220_Vertical" H 9300 3075 50  0001 L CIN
F 3 "" H 9050 3150 50  0001 L CNN
	1    9050 3150
	1    0    0    -1  
$EndComp
$Comp
L L L?
U 1 1 5AD27D3B
P 9700 2800
F 0 "L?" H 9650 2800 50  0000 C CNN
F 1 "L" V 9775 2800 50  0000 C CNN
F 2 "" H 9700 2800 50  0001 C CNN
F 3 "" H 9700 2800 50  0001 C CNN
	1    9700 2800
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 5AD27D94
P 10250 3000
F 0 "C?" H 10275 3100 50  0000 L CNN
F 1 "C" H 10275 2900 50  0000 L CNN
F 2 "" H 10288 2850 50  0001 C CNN
F 3 "" H 10250 3000 50  0001 C CNN
	1    10250 3000
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5AD27DEF
P 8750 2250
F 0 "C?" H 8775 2350 50  0000 L CNN
F 1 "C" H 8775 2150 50  0000 L CNN
F 2 "" H 8788 2100 50  0001 C CNN
F 3 "" H 8750 2250 50  0001 C CNN
	1    8750 2250
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5AD27E36
P 8600 3150
F 0 "R?" V 8680 3150 50  0000 C CNN
F 1 "R" V 8600 3150 50  0000 C CNN
F 2 "" V 8530 3150 50  0001 C CNN
F 3 "" H 8600 3150 50  0001 C CNN
	1    8600 3150
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 5AD27ED7
P 8600 2550
F 0 "R?" V 8680 2550 50  0000 C CNN
F 1 "R" V 8600 2550 50  0000 C CNN
F 2 "" V 8530 2550 50  0001 C CNN
F 3 "" H 8600 2550 50  0001 C CNN
	1    8600 2550
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 5AD27F7C
P 5950 3500
F 0 "R?" V 6030 3500 50  0000 C CNN
F 1 "R" V 5950 3500 50  0000 C CNN
F 2 "" V 5880 3500 50  0001 C CNN
F 3 "" H 5950 3500 50  0001 C CNN
	1    5950 3500
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5AD2A343
P 4350 2350
F 0 "R?" V 4430 2350 50  0000 C CNN
F 1 "R" V 4350 2350 50  0000 C CNN
F 2 "" V 4280 2350 50  0001 C CNN
F 3 "" H 4350 2350 50  0001 C CNN
	1    4350 2350
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5AD2A3B4
P 3700 2750
F 0 "R?" V 3780 2750 50  0000 C CNN
F 1 "R" V 3700 2750 50  0000 C CNN
F 2 "" V 3630 2750 50  0001 C CNN
F 3 "" H 3700 2750 50  0001 C CNN
	1    3700 2750
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5AD2A41B
P 4150 2750
F 0 "R?" V 4230 2750 50  0000 C CNN
F 1 "R" V 4150 2750 50  0000 C CNN
F 2 "" V 4080 2750 50  0001 C CNN
F 3 "" H 4150 2750 50  0001 C CNN
	1    4150 2750
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 5AD2A7F6
P 4200 3050
F 0 "R?" V 4280 3050 50  0000 C CNN
F 1 "R" V 4200 3050 50  0000 C CNN
F 2 "" V 4130 3050 50  0001 C CNN
F 3 "" H 4200 3050 50  0001 C CNN
	1    4200 3050
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5AD2A922
P 3900 2950
F 0 "C?" H 3925 3050 50  0000 L CNN
F 1 "C" H 3925 2850 50  0000 L CNN
F 2 "" H 3938 2800 50  0001 C CNN
F 3 "" H 3900 2950 50  0001 C CNN
	1    3900 2950
	0    -1   -1   0   
$EndComp
Text GLabel 6350 2800 2    60   Input ~ 0
PGND
Text GLabel 6300 3500 2    60   Input ~ 0
PGND
Text GLabel 9150 3350 3    60   Input ~ 0
PGND
$Comp
L R R?
U 1 1 5AD2B903
P 10050 2800
F 0 "R?" V 10130 2800 50  0000 C CNN
F 1 "R" V 10050 2800 50  0000 C CNN
F 2 "" V 9980 2800 50  0001 C CNN
F 3 "" H 10050 2800 50  0001 C CNN
	1    10050 2800
	0    1    1    0   
$EndComp
Text GLabel 8750 4300 0    60   Input ~ 0
Vin
Text GLabel 6600 2550 1    60   Input ~ 0
Vin
$Comp
L C C?
U 1 1 5AD2E0E2
P 6100 3100
F 0 "C?" H 6125 3200 50  0000 L CNN
F 1 "C" H 6125 3000 50  0000 L CNN
F 2 "" H 6138 2950 50  0001 C CNN
F 3 "" H 6100 3100 50  0001 C CNN
	1    6100 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3150 5700 3250
Wire Wire Line
	4450 3250 4450 3500
Wire Wire Line
	4450 3500 5800 3500
Wire Wire Line
	5800 3500 5800 3050
Wire Wire Line
	6950 2750 6750 2750
Connection ~ 5800 3050
Wire Wire Line
	8000 2750 8300 2750
Wire Wire Line
	8300 2750 8300 2550
Wire Wire Line
	8300 2550 8450 2550
Wire Wire Line
	8750 2550 8850 2550
Wire Wire Line
	6950 2950 6950 3150
Wire Wire Line
	6950 3150 8450 3150
Wire Wire Line
	8750 3150 8850 3150
Wire Wire Line
	9150 2750 9150 2950
Wire Wire Line
	8300 2800 9550 2800
Connection ~ 9150 2800
Wire Wire Line
	10250 2800 10250 2850
Wire Wire Line
	10250 3150 10250 3350
Wire Wire Line
	10250 3350 9150 3350
Wire Wire Line
	9850 2800 9900 2800
Wire Wire Line
	10200 2800 10450 2800
Wire Wire Line
	9900 4100 10000 4100
Wire Wire Line
	10000 4100 10000 3050
Wire Wire Line
	10000 3050 9900 3050
Wire Wire Line
	9900 3050 9900 2800
Wire Wire Line
	10200 2800 10200 2950
Wire Wire Line
	10200 2950 10150 2950
Wire Wire Line
	10150 2950 10150 4000
Wire Wire Line
	10150 4000 9900 4000
Wire Wire Line
	6600 2950 5700 2950
Connection ~ 6100 2950
Wire Wire Line
	6100 3250 6100 3500
Wire Wire Line
	6100 3500 6300 3500
Wire Wire Line
	5700 3200 5950 3200
Wire Wire Line
	5950 3200 5950 2950
Connection ~ 5950 2950
Connection ~ 5700 3200
Wire Wire Line
	4450 2950 4050 2950
Wire Wire Line
	4450 3050 4350 3050
Wire Wire Line
	4050 3050 3750 3050
Wire Wire Line
	3750 2950 3750 3150
Wire Wire Line
	3750 3150 4450 3150
Connection ~ 3750 3050
Wire Wire Line
	4300 2750 4450 2750
Text GLabel 4350 2200 1    60   Input ~ 0
OUT_DAC
Wire Wire Line
	4350 2550 4450 2550
Wire Wire Line
	3750 2950 3700 2950
Wire Wire Line
	3700 2950 3700 2900
Wire Wire Line
	3700 2600 4000 2600
Wire Wire Line
	4000 2600 4000 2750
Wire Wire Line
	4000 2650 4450 2650
Connection ~ 4000 2650
$Comp
L R R?
U 1 1 5AD2F119
P 3850 2250
F 0 "R?" V 3930 2250 50  0000 C CNN
F 1 "R" V 3850 2250 50  0000 C CNN
F 2 "" V 3780 2250 50  0001 C CNN
F 3 "" H 3850 2250 50  0001 C CNN
	1    3850 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 2600 3850 2400
Connection ~ 3850 2600
Text GLabel 3850 2100 1    60   Input ~ 0
Vin
$Comp
L C C?
U 1 1 5AD2F227
P 4000 2450
F 0 "C?" H 4025 2550 50  0000 L CNN
F 1 "C" H 4025 2350 50  0000 L CNN
F 2 "" H 4038 2300 50  0001 C CNN
F 3 "" H 4000 2450 50  0001 C CNN
	1    4000 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4350 2550 4350 2500
Wire Wire Line
	4150 2450 4300 2450
Wire Wire Line
	4300 2450 4300 2750
Connection ~ 4300 2750
$Comp
L C C?
U 1 1 5AD316C2
P 6150 2700
F 0 "C?" H 6175 2800 50  0000 L CNN
F 1 "C" H 6175 2600 50  0000 L CNN
F 2 "" H 6188 2550 50  0001 C CNN
F 3 "" H 6150 2700 50  0001 C CNN
	1    6150 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 2850 5700 2850
Wire Wire Line
	6350 2650 6350 2850
Connection ~ 6150 2850
Wire Wire Line
	6150 2550 6000 2550
Wire Wire Line
	6000 2550 6000 2750
Wire Wire Line
	6000 2750 5700 2750
$Comp
L R R?
U 1 1 5AD318A1
P 6350 2500
F 0 "R?" V 6430 2500 50  0000 C CNN
F 1 "R" V 6350 2500 50  0000 C CNN
F 2 "" V 6280 2500 50  0001 C CNN
F 3 "" H 6350 2500 50  0001 C CNN
	1    6350 2500
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5AD31943
P 6350 2050
F 0 "R?" V 6430 2050 50  0000 C CNN
F 1 "R" V 6350 2050 50  0000 C CNN
F 2 "" V 6280 2050 50  0001 C CNN
F 3 "" H 6350 2050 50  0001 C CNN
	1    6350 2050
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5AD319BA
P 5950 2450
F 0 "R?" V 6030 2450 50  0000 C CNN
F 1 "R" V 5950 2450 50  0000 C CNN
F 2 "" V 5880 2450 50  0001 C CNN
F 3 "" H 5950 2450 50  0001 C CNN
	1    5950 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6150 2550 6150 2450
Wire Wire Line
	6150 2450 6100 2450
Wire Wire Line
	5800 2450 5800 2650
Wire Wire Line
	5800 2650 5700 2650
Wire Wire Line
	6350 2350 6350 2200
Wire Wire Line
	6350 2250 5700 2250
Wire Wire Line
	5700 2250 5700 2550
Connection ~ 6350 2250
Text GLabel 6350 1900 1    60   Input ~ 0
Vout
$Comp
L C C?
U 1 1 5AD33BF2
P 8000 2500
F 0 "C?" H 8025 2600 50  0000 L CNN
F 1 "C" H 8025 2400 50  0000 L CNN
F 2 "" H 8038 2350 50  0001 C CNN
F 3 "" H 8000 2500 50  0001 C CNN
	1    8000 2500
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5AD33CA7
P 6800 3100
F 0 "C?" H 6825 3200 50  0000 L CNN
F 1 "C" H 6825 3000 50  0000 L CNN
F 2 "" H 6838 2950 50  0001 C CNN
F 3 "" H 6800 3100 50  0001 C CNN
	1    6800 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 2250 6800 2950
Wire Wire Line
	6600 2650 6950 2650
Wire Wire Line
	6950 2850 6900 2850
Wire Wire Line
	6900 2850 6900 3250
Wire Wire Line
	6900 3250 6200 3250
Wire Wire Line
	6200 3250 6200 3500
Connection ~ 6200 3500
Connection ~ 6800 3250
Wire Wire Line
	6600 2550 6600 2950
Connection ~ 6800 2650
Connection ~ 6600 2650
Wire Wire Line
	5700 3050 6350 3050
Wire Wire Line
	6350 3050 6350 3000
Wire Wire Line
	6350 3000 6750 3000
Wire Wire Line
	6750 3000 6750 2750
Wire Wire Line
	7600 2250 8000 2250
Wire Wire Line
	8000 2250 8000 2350
Wire Wire Line
	7300 2250 6800 2250
$Comp
L D_Schottky D?
U 1 1 5AD35ED0
P 7450 2250
F 0 "D?" H 7450 2350 50  0000 C CNN
F 1 "D_Schottky" H 7450 2150 50  0000 C CNN
F 2 "" H 7450 2250 50  0001 C CNN
F 3 "" H 7450 2250 50  0001 C CNN
	1    7450 2250
	-1   0    0    1   
$EndComp
$Comp
L D_Schottky D?
U 1 1 5AD36DD8
P 9450 3100
F 0 "D?" H 9450 3200 50  0000 C CNN
F 1 "D_Schottky" H 9450 3000 50  0000 C CNN
F 2 "" H 9450 3100 50  0001 C CNN
F 3 "" H 9450 3100 50  0001 C CNN
	1    9450 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	9450 3250 9450 3350
Connection ~ 9450 3350
Wire Wire Line
	9450 2950 9450 2800
Connection ~ 9450 2800
Wire Wire Line
	8000 2850 8300 2850
Wire Wire Line
	8300 2850 8300 2800
NoConn ~ 8000 2950
Text GLabel 9050 3900 0    60   Input ~ 0
Ref_2V5
Text GLabel 9900 3900 2    60   Input ~ 0
Output_Curr
Text GLabel 8700 4000 0    60   Input ~ 0
LGND
Text GLabel 8550 2400 0    60   Input ~ 0
PGND
Wire Wire Line
	8550 2400 8750 2400
Wire Wire Line
	8750 2100 9150 2100
Wire Wire Line
	9150 2000 9150 2350
Text GLabel 9150 2000 1    60   Input ~ 0
Vin
Connection ~ 9150 2100
$Comp
L R R?
U 1 1 5AD3E5B5
P 7100 4350
F 0 "R?" V 7180 4350 50  0000 C CNN
F 1 "R" V 7100 4350 50  0000 C CNN
F 2 "" V 7030 4350 50  0001 C CNN
F 3 "" H 7100 4350 50  0001 C CNN
	1    7100 4350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5AD3E655
P 7100 4850
F 0 "R?" V 7180 4850 50  0000 C CNN
F 1 "R" V 7100 4850 50  0000 C CNN
F 2 "" V 7030 4850 50  0001 C CNN
F 3 "" H 7100 4850 50  0001 C CNN
	1    7100 4850
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5AD3E6F8
P 7450 4350
F 0 "R?" V 7530 4350 50  0000 C CNN
F 1 "R" V 7450 4350 50  0000 C CNN
F 2 "" V 7380 4350 50  0001 C CNN
F 3 "" H 7450 4350 50  0001 C CNN
	1    7450 4350
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5AD3E77B
P 7450 4850
F 0 "R?" V 7530 4850 50  0000 C CNN
F 1 "R" V 7450 4850 50  0000 C CNN
F 2 "" V 7380 4850 50  0001 C CNN
F 3 "" H 7450 4850 50  0001 C CNN
	1    7450 4850
	1    0    0    -1  
$EndComp
Text GLabel 7100 4150 1    60   Input ~ 0
Vin
Text GLabel 10450 2800 2    60   Input ~ 0
Vout
Connection ~ 10250 2800
Text GLabel 7450 4150 1    60   Input ~ 0
Vout
Text GLabel 7250 5300 3    60   Input ~ 0
LGND
Wire Wire Line
	7100 5000 7100 5300
Wire Wire Line
	6850 5300 7650 5300
Wire Wire Line
	7450 5300 7450 5000
Wire Wire Line
	7100 4500 7100 4700
Wire Wire Line
	7450 4500 7450 4700
Wire Wire Line
	7450 4150 7450 4200
Wire Wire Line
	7100 4150 7100 4200
Text GLabel 7600 4650 2    60   Input ~ 0
Output_Volt
Text GLabel 7000 4600 0    60   Input ~ 0
Input_Volt
Wire Wire Line
	7000 4600 7100 4600
Connection ~ 7100 4600
Wire Wire Line
	7450 4650 7600 4650
Connection ~ 7450 4650
$Comp
L C C?
U 1 1 5AD42DDA
P 6850 4850
F 0 "C?" H 6875 4950 50  0000 L CNN
F 1 "C" H 6875 4750 50  0000 L CNN
F 2 "" H 6888 4700 50  0001 C CNN
F 3 "" H 6850 4850 50  0001 C CNN
	1    6850 4850
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 5AD42EBC
P 7650 4900
F 0 "C?" H 7675 5000 50  0000 L CNN
F 1 "C" H 7675 4800 50  0000 L CNN
F 2 "" H 7688 4750 50  0001 C CNN
F 3 "" H 7650 4900 50  0001 C CNN
	1    7650 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 5300 7650 5050
Connection ~ 7450 5300
Wire Wire Line
	6850 5300 6850 5000
Connection ~ 7100 5300
Wire Wire Line
	7100 4700 6850 4700
Wire Wire Line
	7650 4750 7550 4750
Wire Wire Line
	7550 4750 7550 4650
Connection ~ 7550 4650
$Comp
L C C?
U 1 1 5AD432B0
P 8850 4150
F 0 "C?" H 8875 4250 50  0000 L CNN
F 1 "C" H 8875 4050 50  0000 L CNN
F 2 "" H 8888 4000 50  0001 C CNN
F 3 "" H 8850 4150 50  0001 C CNN
	1    8850 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 4300 9000 4300
Wire Wire Line
	9000 4300 9000 4100
Wire Wire Line
	9000 4100 9050 4100
Connection ~ 8850 4300
Wire Wire Line
	8700 4000 9050 4000
Connection ~ 8850 4000
$EndSCHEMATC