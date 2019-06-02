/* 
	Editor: https://www.visualmicro.com/
			visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
			the contents of the _vm sub folder can be deleted prior to publishing a project
			all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
			note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Teensy 3.6, Platform=teensy3, Package=teensy
*/

#define ARDUINO 10605
#define ARDUINO_MAIN
#define printf iprintf
#define __TEENSY3__
#define __MK66FX1M0__
#define TEENSYDUINO 146
#define ARDUINO 10605
#define F_CPU 180000000
#define USB_SERIAL
#define LAYOUT_US_ENGLISH
//
//
void newPreset();

#include "arduino.h"
#include "Parabola.ino"
