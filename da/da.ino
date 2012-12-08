
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/io.h>

#define A_PIN A0
#define D_PIN 3
#define interval 1000

int inByte = 0;
int apin_value = 0;
unsigned long prev_time = 0;

void setup()
{
	Serial.begin(9600);

	pinMode( D_PIN, OUTPUT );

	// send a byte to establish contact until receiver responds 
	establishContact();
}

void loop()
{
	unsigned long curr_time = millis();

	checkInput();

	if( curr_time - prev_time > 1000 )
	{
		prev_time = curr_time;
		apin_value = analogRead( A_PIN );
		Serial.println( apin_value );
	}
}


void checkInput()
{
	if (Serial.available() > 0)
	{
		inByte = Serial.read();

		if( inByte == 'H' )
			digitalWrite( D_PIN, HIGH );

		if( inByte == 'L' )
			digitalWrite( D_PIN, LOW );

		if( inByte == 'S' )
			putToSleep();
	}
}


void establishContact()
{
	while( Serial.available() <= 0 )
	{
		Serial.print('.');   // send a capital A
		delay(300);
	}

	Serial.println("");
}


void putToSleep()
{
	return;
}
