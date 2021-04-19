#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
        DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
        DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as outputs, initialize to 0s
      
      	DDRC = 0xFF; PORTC = 0xFF;
      	DDRD = 0xFF; PORTD = 0x00; 

   
    unsigned char tmpA = 0x00; // Tmp
    unsigned char tmpB = 0x00; 
    unsigned char tmpC = 0x00; 
    while (1) {
        tmpA = PINA;
   	tmpC = PINC;
   	tmpB = PINB;
  
        PORTD = 0x00;

        if ( (tmpA + tmpB + tmpC) > 150) 
	{
	     	PORTD = (PORTD & 0xFE) | 0x01; // Sets PORTD to ddddddd1 (clear right most bit, then set to 1)
        }
	
       else if ( (tmpA + tmpB + tmpC) == 0x8C)
    	{
	      	PORTD = 0x22;
	}
	else if ( ((tmpA - tmpC) > 80) || ((tmpC - tmpA) > 80) )
	{
	  	PORTD = (PORTD & 0xFD) | 0x2; // Sets PORTD to dddddd1d (clear 2nd from right, then set to 1)
        PORTD = (PORTD & 0x03) | ((tmpA + tmpB + tmpC) >> 2); // Sets PORTD to 00aaaadd (clears 6 left bits, then sets them to average)
	}
    }
    return 0;
}

