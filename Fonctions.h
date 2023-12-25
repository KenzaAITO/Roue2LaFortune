#include "Grove_LCD_RGB_Backlight.h"
#include "CircularLED.h"
#include "mbed.h"

CircularLED circularLED1(10,9); 
const int tailleTab = 23 ; //nombre d'elemnt dans le tableau un element correspond au nombre de LEDs
void spinWheel() {
    // Exemple de code pour faire tourner la roue de la fortune

    // Définissez la séquence des LED pour la rotation
    int sequence[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

    // Répétez la séquence de rotation plusieurs fois
    int numRotations = 3;

    for (int rotation = 0; rotation < numRotations; ++rotation) {
        // Faites défiler la séquence des LED
        for (int i = 0; i < sizeof(sequence) / sizeof(sequence[0]); ++i) {
            int result = sequence[i];

            // Allumez la LED correspondant au résultat
            circularLED1.setLED(result, true);

            // Attendez un court instant pour créer l'effet de rotation
            ThisThread::sleep_for(100ms);

            // Éteignez toutes les LEDs
            circularLED1.setAllOff();

        }
    }

    // Maintenant, faites ralentir la rotation jusqu'à atteindre la valeur cible
    for (int i = 0; i < numRotations; ++i) 
    {
        //circularLED = (1 << sequence[i]);

        // Ajoutez un délai pour simuler le ralentissement
        ThisThread::sleep_for(150ms);
    }
}


void displayResult(int result) {
    //Afficher le résultat sur l'écran LCD
    int tab[tailleTab] = {1, 30, 40, 3000, 0, 50, 200, 15, -24, 67, 500, 20, 0, 1000, 5, 80, 10, -50, 36 ,0 , 700, 10000 , 9999, 2};
    if (result < tailleTab){
        int res = tab[result];
        rgbLCD.locate(0,1);
        rgbLCD.print("Vous avez gagné");

        char *empty = {};
        empty[0] = res;
        rgbLCD.print(empty);
    }
    else{
        rgbLCD.locate(0,1);
        rgbLCD.print("Une erreur est survenue");
    }
}