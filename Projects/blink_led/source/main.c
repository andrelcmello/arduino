#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void main(void)
{
	// Configure pin PB7 as output
	DDRB |= 0x80;
	
	// Infinite loop
	while(1) {

		// Set PB7 High
		PORTB |= 0x80;

		// Wait 0.5 sec
		_delay_ms(500);	

		// Set PB7 Low
		PORTB &= ~0x80;

		// Wait 0.5 sec
		_delay_ms(500);	
	}
}
