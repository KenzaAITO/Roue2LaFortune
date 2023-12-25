#include "Grove_LCD_RGB_Backlight.h"
#include "PinNameAliases.h"
#include "TARGET_NUCLEO_L073RZ/PinNames.h"
#include "mbed.h"
#include "mbed_wait_api.h"
#include "LED_Bar.h"

#include <CircularLED.h>
CircularLED circularLED1(10,9);
CircularLED circularLED2(16,15);

Grove_LCD_RGB_Backlight rgbLCD(D15, D14);
LED_Bar bar(D6, D5);
unsigned int LED[24];
int k=0;

int main()
{
    int i;
   rgbLCD.setRGB(0xff, 0xff, 0xff);                 //set the color 
   rgbLCD.print("Mini Projet C++");
   rgbLCD.locate(0,1);
   rgbLCD.print("This is a test");
   wait_us(5);
   int count = 0;

   while(1)
   {
       for (int i =0;i<24;i++){
         LED[i]=0;
        }

        LED[k]= 0xff;
        k++;
        if (k==24)
        k=0;
    
  circularLED1.CircularLEDWrite(LED);
  circularLED2.CircularLEDWrite(LED);
  wait_us(400);  
     for (i=0; i<=10; i++) {
            bar.setLevel(i);
            wait_us(1000);
     }
     if (count == 0)
     {
         rgbLCD.setRGB(0xff, 0x00, 0x00);
     }   
     else if (count == 1)
     {
         rgbLCD.setRGB(0x00, 0xff, 0x00);
     }
     else if (count == 2)
     {
         rgbLCD.setRGB(0x00, 0x00, 0xff);
     }
     wait_us(1);
     count++;
     if(count == 3)
     {
         count = 0;
     }
     
   }
}

