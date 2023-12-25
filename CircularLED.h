#ifndef CircularLED_h
#define CircularLED_h
//#include "mbed.h"
#include <cstdint>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define defaultDDR_Data     DDRC
#define defaultDDR_Clk      DDRC
#define defaultPORT_Data    PORTC
#define defaultintPORT_Clk  PORTC

constexpr int defaultBIT_Data  = 0x10;
constexpr int defaultBIT_Clk   = 0x20;
constexpr int defaultIntensity = 128; //intensité LEDs de 0 à 255
constexpr int defaultIndex = 128;
constexpr bool defaultOn = true;
class CircularLED
{
  public:
  volatile uint8_t *PORT_Data;
  volatile uint8_t *PORT_Clk;
  CircularLED(int data, int clk, int intensity);
  CircularLED(int data, int clk);
  void ClearDisplay(void);
  void CircularLEDWrite(unsigned int data[24]);
  void setAllOff();
  void setLED(int index, bool on);
  private:
  void Sent16bit(unsigned int data);
  void Latch(void);
  
  uint8_t _intensity{defaultIntensity}; 
  uint8_t _data;
  uint8_t _clk;
  uint8_t BIT_Data{defaultBIT_Data};
  uint8_t BIT_Clk{defaultBIT_Clk};
  int index{defaultIndex};
  bool On{defaultOn};
};
//extern CircularLED circularLED;

#endif