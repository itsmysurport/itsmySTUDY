EESchema Schematic File Version 4
EELAYER 29 0
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
L Device:R R1
U 1 1 5CAEF6D9
P 4200 2850
F 0 "R1" H 4270 2896 50  0000 L CNN
F 1 "220" H 4270 2805 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0414_L11.9mm_D4.5mm_P20.32mm_Horizontal" V 4130 2850 50  0001 C CNN
F 3 "~" H 4200 2850 50  0001 C CNN
	1    4200 2850
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5CAEFF4D
P 4600 2500
F 0 "D1" H 4593 2716 50  0000 C CNN
F 1 "LED" H 4593 2625 50  0000 C CNN
F 2 "LED_THT:LED_Rectangular_W5.0mm_H2.0mm" H 4600 2500 50  0001 C CNN
F 3 "~" H 4600 2500 50  0001 C CNN
	1    4600 2500
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR04
U 1 1 5CAF0F92
P 5050 2300
F 0 "#PWR04" H 5050 2150 50  0001 C CNN
F 1 "+5V" H 5065 2473 50  0000 C CNN
F 2 "" H 5050 2300 50  0001 C CNN
F 3 "" H 5050 2300 50  0001 C CNN
	1    5050 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5CAF1AE2
P 4200 3250
F 0 "#PWR03" H 4200 3000 50  0001 C CNN
F 1 "GND" H 4205 3077 50  0000 C CNN
F 2 "" H 4200 3250 50  0001 C CNN
F 3 "" H 4200 3250 50  0001 C CNN
	1    4200 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 2300 5050 2500
Wire Wire Line
	5050 2500 4750 2500
Wire Wire Line
	4450 2500 4200 2500
Wire Wire Line
	4200 2500 4200 2700
Wire Wire Line
	4200 3000 4200 3250
$Comp
L Connector:Conn_01x02_Female J1
U 1 1 5CAF26C7
P 3300 2400
F 0 "J1" H 3192 2585 50  0000 C CNN
F 1 "Conn_01x02_Female" H 3192 2494 50  0000 L CNN
F 2 "Connector_Phoenix_MSTB:PhoenixContact_MSTB_2,5_2-GF_1x02_P5.00mm_Horizontal_ThreadedFlange_MountHole" H 3300 2400 50  0001 C CNN
F 3 "~" H 3300 2400 50  0001 C CNN
	1    3300 2400
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5CAF3332
P 3850 2050
F 0 "#PWR01" H 3850 1900 50  0001 C CNN
F 1 "+5V" H 3865 2223 50  0000 C CNN
F 2 "" H 3850 2050 50  0001 C CNN
F 3 "" H 3850 2050 50  0001 C CNN
	1    3850 2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5CAF3791
P 3850 2700
F 0 "#PWR02" H 3850 2450 50  0001 C CNN
F 1 "GND" H 3855 2527 50  0000 C CNN
F 2 "" H 3850 2700 50  0001 C CNN
F 3 "" H 3850 2700 50  0001 C CNN
	1    3850 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2400 3850 2400
Wire Wire Line
	3850 2400 3850 2050
Wire Wire Line
	3500 2500 3850 2500
Wire Wire Line
	3850 2500 3850 2700
$EndSCHEMATC
