
#define LED 13
#define INTERVAL 15

long int timer = 0;
int inverse = 1;

void setup()
{
    pinMode( LED, OUTPUT );
}

void loop()
{
    if( timer > 300 )
        inverse = -1;

    if( timer < 0 )
    {
        timer = 0;
        inverse = 1;
    }

    digitalWrite( LED, HIGH );

    delay( 100 );
    digitalWrite( LED, LOW );
    
    delay( timer );    
    timer = timer + ( INTERVAL * inverse );
}
