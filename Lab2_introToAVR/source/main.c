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
    unsigned char tmpB = 0x00; //tmp
    unsigned char tmpC = 0x00; //tmp
    unsigned char tmpE = 0x00;
    while (1) {
        tmpA = PINA;
   	tmpC = PINC;
   	tmpB = PINB;
  	PORTD = 0x00;
	tmpE = tmpA + tmpB + tmpC;

        if (((tmpE > 150)))
	{
	     	PORTD = ((PORTD & 0xFE) | 0x01); //Exceeds 140KG  
	}
	
	if (((tmpA - tmpC) > 80) || ((tmpC - tmpA) > 80)) //If Values have difference of 80KG
	{
	  	PORTD = (PORTD & 0xFD) | 0x2;//PORTD to 00aaaadd 
      		PORTD = ((PORTD & 0x03) | (tmpE >> 2)); 
	} 

        if ((tmpA + tmpB + tmpC) == 0x8C) //Does set PORTD to 00aaaadd
	{
	      	PORTD = 0x22; //If values have difference of 140KG
	}	
   }	 
    return 0;
}
