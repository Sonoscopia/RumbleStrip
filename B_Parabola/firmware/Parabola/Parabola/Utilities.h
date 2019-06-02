/*
 * Utilities.h
 *
 * Created: 02-06-2019 01:50:06
 *  Author: tiago
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

uint16_t bpm2ms(float _bpm){
	return round(60000. / _bpm); 
} 

uint16_t bpmclock2ms(float _bpm, float _div){
	return round(60000. / (_bpm * _div)); 
}

uint16_t noteduration2ms(uint16_t _clockms, float _noteduration){
	return round(_clockms * _noteduration);
}

void printMaxMemUsage(){
	Serial.print("Max buffer blocks: ");
	Serial.println(AudioMemoryUsageMax());
}

void printMemUsage(){
	Serial.print("Buffer blocks currently used: ");
	Serial.println(AudioMemoryUsage());
}


#endif /* UTILITIES_H_ */