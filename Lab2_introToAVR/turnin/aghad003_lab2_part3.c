#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
        DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
        DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
        DDRC = 0xFF; PORTC = 0x00;
	
	// unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
        unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
while(1) {
                //Read input
        tmpA = PINA; 
	if (tmpA == 0x00){
		PORTC = 0x04;//Empty (in Binary this means 4) 
 	}
	else if ((tmpA == 0x01) || (tmpA == 0x02) || (tmpA == 0x04) || (tmpA == 0x08)){
		PORTC = 0x03; //3 available 
	}
	else if ((tmpA == 0x03) || (tmpA == 0x06) || (tmpA == 0x05) || (tmpA == 0x0A) || (tmpA == 0x0C))
	{
		PORTC = 0x02; //2 Avaible 
	}
	else if ((tmpA == 0x0D) || (tmpA == 0x0E) || (tmpA == 0x0B) || (tmpA == 0x07))
	{ 
		PORTC = 0x01; //1 availble
	}
	else 
		PORTC = 0x80; //Everything is full 
	}	


        return 0;
}

