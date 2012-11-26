
#define DTEST_PIN  7
#define ATEST_PIN  0
#define LED_PIN    13

boolean current_set = false;
boolean current_lit = false;
int val = 0;

void setup()
{
	pinMode( DTEST_PIN, INPUT );
	digitalWrite( DTEST_PIN, LOW );

	pinMode( LED_PIN, OUTPUT );

	Serial.begin(9600);
}

void loop()
{
	if( digitalRead( DTEST_PIN ) == HIGH 
	 && current_set == false )
	current_set = true;

	if( digitalRead( DTEST_PIN ) == LOW
	 && current_set == true )
	current_set = false;

	if( current_set == false 
	 && current_lit == true )
	{
		digitalWrite( LED_PIN, LOW );
		current_lit = false;
	}

	if( current_set == true 
	 && current_lit == false )
	{
		digitalWrite( LED_PIN, HIGH );
		current_lit = true;
	}

	val = analogRead( ATEST_PIN );
	Serial.println( val );
}