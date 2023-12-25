#include "Grove_LCD_RGB_Backlight.h"
#include "PinNameAliases.h"
#include "TARGET_NUCLEO_L073RZ/PinNames.h"
#include "mbed.h"
#include "mbed_wait_api.h"
#include <CircularLED.h>
#include "Fonctions.h"

#define  USER_BUTTON PC_13

CircularLED circularLED1(10,9); 
Grove_LCD_RGB_Backlight rgbLCD(D14, D15); //D14 et D15 sont les ports SCL et SDA connecté à l'ecran
DigitalIn button(USER_BUTTON);

unsigned int LED[24];
int k=0;

int main()
{
   int i;
   rgbLCD.setRGB(0xff, 0xff, 0xff);//set couleur 
   rgbLCD.print("Mini Projet C++");
   rgbLCD.locate(0,1);
   rgbLCD.print("Appuyez sur le Bouton pour commencer");

   wait_us(5);

   while(1)
   {
       for (int i =0;i<24;i++){
         LED[i]=0;
        }

        LED[k]= 0xff;
        k++;
        if (k==24){
            k=0;
        }
    
        circularLED1.CircularLEDWrite(LED);
        //circularLED2.CircularLEDWrite(LED);
        wait_us(40);  
        while (1) {
        // Attendez que le bouton soit enfoncé
        while (!button);

        // Effectuez la rotation de la roue de la fortune
        spinWheel();

        // Obtenez un résultat aléatoire (par exemple, de 1 à 24)
        int result = rand() % 24 + 1;

        // Affichez le résultat sur l'écran LCD RGB
        displayResult(result);

        // Attendez que le bouton soit relâché
        while (!button);
        }
    }
}

