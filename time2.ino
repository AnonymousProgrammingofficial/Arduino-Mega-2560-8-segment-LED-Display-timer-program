/* This is Code is for use on the arduino mega board.
 * Use with a 12 Pin Display.
 * This program counts down from 60 seconds (time can be changed to Long n, and count) variables
 * at the bottom of the code then pin 22 (signalOutPut) is then written to HIGH.
 * 
 * By: Anonymous Programming (JM)
 * THIS CODE CAN BE COPIED AND MODIFIED TO SUITE YOUR NEEDS.
 * Code finished YEAR: 2018
 */
#include <TimerOne.h>


//Sets up the PINS as individual integers

int aaLed = 2;
int abLed = 3;
int acLed = 4;
int adLed = 5;
int aeLed = 6;
int afLed = 7;
int agLed = 8;
int apLed = 9;

int signalOutPut  = 22;

int maindigit4 = 10;
int maindigit3 = 11;
int maindigit2 = 12;
int maindigit1 = 13;

// sets up values and varibles 
long n =6000;
int x = 100;
int del = 5;
int count;

// Declares pins as outputs
void setup() {
pinMode (maindigit1 , OUTPUT);
pinMode (maindigit2 , OUTPUT);
pinMode (maindigit3 , OUTPUT);
pinMode (maindigit4 , OUTPUT);
pinMode (aaLed , OUTPUT);
pinMode (abLed , OUTPUT);
pinMode (acLed , OUTPUT);
pinMode (adLed , OUTPUT);
pinMode (aeLed , OUTPUT);
pinMode (afLed , OUTPUT);
pinMode (agLed , OUTPUT);
pinMode (apLed , OUTPUT);
pinMode (signalOutPut, OUTPUT);

// Initializes timer functions in the library header
Timer1.initialize(10000);
Timer1.attachInterrupt(add);
}



// does the arithmatic options needed to dispay the correct timing output
void loop()
{ 
clearLEDs();
pickDigits (0);
pickNumbers(n/1000);
delay(del);

clearLEDs();
pickDigits (1);
pickNumbers((n%1000)/100);
delay(del);

clearLEDs();
pickDigits (2);
pickNumbers (n%100/10);
delay(del);

clearLEDs();
pickDigits (3);
pickNumbers (n%10);
delay(del);
}





void pickDigits(int x)
{                                  // Sets the maindigits as ON
  digitalWrite (maindigit1, HIGH);
    digitalWrite (maindigit2, HIGH);
      digitalWrite (maindigit3, HIGH);
        digitalWrite (maindigit4, HIGH);

        switch(x) // Goes through the cases to clear the LED display
        { 
          case 0:
           digitalWrite(maindigit1,LOW);
            break;
          case 1:
           digitalWrite(maindigit2, LOW);
            break;
          case 2:
           digitalWrite(maindigit3, LOW);
            break;
          default:
            digitalWrite(maindigit4, LOW);
             break;
        }
}

void pickNumbers (int x) // Picks the numbers to be displayed 1-9 digits
       {
        switch(x)
        {
        default:
         zero();
          break;
        case 1:
         one();
          break;
        case 2:
         two(); 
          break;
        case 3:
         three();
          break;
        case 4:
         four();
          break;
        case 5:
         five();
          break;
        case 6:
         six();
          break;
        case 7:
         seven();
          break;
        case 8:
         eight();
          break;
        case 9:
         nine();
         break;
        }
       }
       
void clearLEDs() //Clears the LED Display
{
   digitalWrite(aaLed, LOW);
   digitalWrite(abLed, LOW);
   digitalWrite(acLed, LOW);
   digitalWrite(adLed, LOW);
   digitalWrite(aeLed, LOW);
   digitalWrite(afLed, LOW);
   digitalWrite(agLed, LOW);
   digitalWrite(apLed, LOW);
}

void zero()//sets up LEDs to display number zero
{
   digitalWrite(aaLed, HIGH);
   digitalWrite(abLed, HIGH);
   digitalWrite(acLed, HIGH);
   digitalWrite(adLed, HIGH);
   digitalWrite(aeLed, HIGH);
   digitalWrite(afLed, HIGH);
   digitalWrite(agLed, LOW);
  }

void one()//sets up LEDs to display number one
{
   digitalWrite(aaLed, LOW);
   digitalWrite(abLed, HIGH);
   digitalWrite(acLed, HIGH);
   digitalWrite(adLed, LOW);
   digitalWrite(aeLed, LOW);
   digitalWrite(afLed, LOW);
   digitalWrite(agLed, LOW);
   }

void two()//sets up LEDs to display number two
{
   digitalWrite(aaLed, HIGH);
   digitalWrite(abLed, HIGH);
   digitalWrite(acLed, LOW);
   digitalWrite(adLed, HIGH);
   digitalWrite(aeLed, HIGH);
   digitalWrite(afLed, LOW);
   digitalWrite(agLed, HIGH);
   }

void three()//sets up LEDs to display number three
{
   digitalWrite(aaLed, HIGH);
   digitalWrite(abLed, HIGH);
   digitalWrite(acLed, HIGH);
   digitalWrite(adLed, HIGH);
   digitalWrite(aeLed, LOW);
   digitalWrite(afLed, LOW);
   digitalWrite(agLed, HIGH);
   }

void four()//sets up LEDs to display number four
{
   digitalWrite(aaLed, LOW);
   digitalWrite(abLed, HIGH);
   digitalWrite(acLed, HIGH);
   digitalWrite(adLed, LOW);
   digitalWrite(aeLed, LOW);
   digitalWrite(afLed, HIGH);
   digitalWrite(agLed, HIGH);
   
}

void five()//sets up LEDs to display number five
{
   digitalWrite(aaLed, HIGH);
   digitalWrite(abLed, LOW);
   digitalWrite(acLed, HIGH);
   digitalWrite(adLed, HIGH);
   digitalWrite(aeLed, LOW);
   digitalWrite(afLed, HIGH);
   digitalWrite(agLed, HIGH);
   
}

void six()//sets up LEDs to display number six
{
   digitalWrite(aaLed, HIGH);
   digitalWrite(abLed, LOW);
   digitalWrite(acLed, HIGH);
   digitalWrite(adLed, HIGH);
   digitalWrite(aeLed, HIGH);
   digitalWrite(afLed, HIGH);
   digitalWrite(agLed, HIGH);
   
}

void seven()//sets up LEDs to display number seven
{
   digitalWrite(aaLed, HIGH);
   digitalWrite(abLed, HIGH);
   digitalWrite(acLed, HIGH);
   digitalWrite(adLed, LOW);
   digitalWrite(aeLed, LOW);
   digitalWrite(afLed, LOW);
   digitalWrite(agLed, LOW);
   
}
  
void eight()//sets up LEDs to display number eight
{
   digitalWrite(aaLed, HIGH);
   digitalWrite(abLed, HIGH);
   digitalWrite(acLed, HIGH);
   digitalWrite(adLed, HIGH);
   digitalWrite(aeLed, HIGH);
   digitalWrite(afLed, HIGH);
   digitalWrite(agLed, HIGH);
   
}       

void nine() //sets up LEDs to display number nine
{
   digitalWrite(aaLed, HIGH);
   digitalWrite(abLed, HIGH);
   digitalWrite(acLed, HIGH);
   digitalWrite(adLed, HIGH);
   digitalWrite(aeLed, LOW);
   digitalWrite(afLed, HIGH);
   digitalWrite(agLed, HIGH);
   
}

 void add()  // math to count downfrom using minus minus fuctions
 {
   count --;
    
    if (count <= 6000)
{
   count = 6000;
   n--;
}

   if (n == 0) // After n reaches zero we digital write high to a specified pin 
{

 digitalWrite (signalOutPut, HIGH); // writing high to pin SignalOutPut
 
 }
 }
 
 
