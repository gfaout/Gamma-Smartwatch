/*
 * DESCRIPTION:
 * This class governs enabling and disabling various 
 * features of the watch, specifically related to 
 * power
 */

#ifndef GammaPower_h
#define GammaPower_h

#include <Arduino.h> //Used to access Arduino libraries

class GammaPower
{
private:


public:
  GammaPower();
  void begin();
  
  bool isCharging();
  uint16_t getBatteryVoltage();
  
};
#endif
