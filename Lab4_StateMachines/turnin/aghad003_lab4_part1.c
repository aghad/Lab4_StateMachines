/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {start, waitState, firstPress, firstRelease, secondPress, secondRelease} state;
void tick() {
	switch(state) {
		case start:
			state = waitState;
			break;
	
		case waitState:
			if( (PINA = 0x01) == 0x01){
			state = firstPress;
			}
			else 
			state = waitState;
			break;

		case firstPress:
			if ((PINA = 0x00) == 0x01){ //First input is on
				state = firstRelease;
			}
			else {
				state = firstPress;	//
			}		
		case firstRelease: 
			if ((PINA & 0x01) == 0x01){
				state = secondPress;
			}
			else {
				state = firstRelease;
			}
		case secondPress:
			if ((PINA & 0x00) == 0x00){
				state = secondRelease;
			}
			else{ 
				state = secondPress;
			}
		case secondRelease:
			if ((PINA & 0x01) == 0x01){
				state = firstPress;
			}
			else{
				state = secondRelease;
			}
		default: 
			state = start;
			break;
	}

	switch(state){

		case start:
			PORTB = 0x01;
			break;
		case waitState:
			PORTB = 0x01;
			break;
		case firstPress:
			PORTB = 0x02;
			break;
		case firstRelease:
		//	PORTB = 0x02;
			break;
		case secondPress:
			PORTB = 0x01;
			break;
		case secondRelease:
		//	PORTB = 0x01;
			break;
		default:
			PORTB = 0x01;
			break;
		}

}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    while (1) {
	tick();
    }
    return 1;
}
