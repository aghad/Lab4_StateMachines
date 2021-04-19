#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
        DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
        DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
        unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
        unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
while(1) {
                // 1) Read input
                tmpA = PINA & 0x03;
                //A7A6A5A4 A3A211
                if (tmpA == 0x01)
                {
                        tmpB = 0x01;
                }

                else {
                        tmpB  = 0x00;
                }
        PORTB = tmpB;
        }
        return 0;
}

