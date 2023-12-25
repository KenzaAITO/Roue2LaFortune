#include "mbed.h"
 
 // I2C addresses for LCD and RGB
 #define LCD_ADDRESS     (0x7c)
 #define RGB_ADDRESS     (0xc4)
 
 #define RED_REG         0x04        
 #define GREEN_REG       0x03        
 #define BLUE_REG        0x02        
 
 // commands
 #define LCD_CLEARDISPLAY 0x01
 #define LCD_DISPLAYCONTROL 0x08
 #define LCD_FUNCTIONSET 0x20
 
 // flags for display on/off control
 #define LCD_DISPLAYON 0x04
 #define LCD_DISPLAYOFF 0x00
 
 // flag for entry mode
 #define LCD_ENTRYLEFT 0x02
 
 // flags for function set
 #define LCD_8BITMODE 0x10
 #define LCD_2LINE 0x08
 #define LCD_5x10DOTS 0x04

/** Grove_LCD_RGB_Backlight Class.
 *   Used for connecting a Grove LCD RGB Backlit display
 *   to an mbed microcontroller via an I2C interface.
 */    
 class Grove_LCD_RGB_Backlight
{
 public:
     
     /** Contructor. Creates an instance of the Grove_LCD_RGB_Backlight class.
     *   @param sda SDA pin on the mbed microcontroller which will be used to communicate with the display.
     *   @param scl SCL pin on the mbed microcontroller which will be used to communicate with the display.
     */
     Grove_LCD_RGB_Backlight(PinName sda, PinName scl); 
     
 
     
    /** Set RGB color of backlight
    *   @param r Value for the red component of the RGB backlight (Between 0 and 255).
    *   @param g Value for the green component of the RGB backlight (Between 0 and 255).
    *   @param b Value for the blue component of the RGB backlight (Between 0 and 255).
    */
     void setRGB(char r, char g, char b);     
     
     
    /** Removes all of the text from the display.
    */
     void clear();
     
    /**Prints text to the LCD display.
    * @param *str Pointer to an array of characters which will be printed to the LCD screen.
    */
    void print(char *str);
     
    /**Move cursor to specified location on the LCD screen.
    * @param col Value for which column on the display the next text being printed will start at.
    * @param row Value for which row on the display the next text being printed will be printed on.
    */
     void locate(char col, char row);
 
     
 private:
     
     //Initialize device
     void init();   
     
     //Turn on display
     void displayOn();
     
     //Send command to display
     void sendCommand(char value);
     
     //Set register value
     void setReg(char addr, char val);
     
     //MBED I2C object used to transfer data to LCD
     I2C i2c;              
     
 };