#include "Grove_LCD_RGB_Backlight.h"
#include "CircularLED.h"
#include "mbed.h"

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
            circularLED.setLED(result, true);

            // Attendez un court instant pour créer l'effet de rotation
            ThisThread::sleep_for(100ms);

            // Éteignez toutes les LEDs
            circularLED.setAllOff();

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
    // Code pour afficher le résultat sur l'écran LCD RGB ici
    // Ajoutez le code nécessaire pour communiquer avec votre écran LCD RGB
    // Utilisez les broches appropriées et les commandes spécifiques à votre écran
}