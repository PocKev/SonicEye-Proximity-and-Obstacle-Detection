#include <Elapsed.h>  // see: http://www.gammon.com.au/Arduino/Elapsed.zip

// alarm frequency
#define FREQUENCY 600  // Hz
#define PERIOD 500000L / FREQUENCY  // (1 / frequency) * 1e6 / 2

#define BUZZER1 2   // D5
#define BUZZER2 3   // D6

void setup ()
{
 pinMode (BUZZER1, OUTPUT);
 pinMode (BUZZER2, OUTPUT);
}

static Elapsed t1, t2;

void loop ()
{

 if (t1.intervalUs () > PERIOD)
   {
   digitalWrite(BUZZER1, !digitalRead (BUZZER1));
   t1.reset ();
   }

if (t2.intervalUs () > PERIOD / 2)
   {
   digitalWrite(BUZZER2, !digitalRead (BUZZER2));
   t2.reset ();
   }
   
}  // end of loop
