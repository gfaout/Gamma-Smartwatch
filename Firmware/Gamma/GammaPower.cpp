#include "GammaPower.h"
const uint8_t chrgPin = 27;
const uint8_t battPin = A4;

//const uint8_t gpsPwrPin = 2;
const uint16_t VDD = 3300;
const uint16_t adcResolution = 1023;


GammaPower::GammaPower() 
{
  
}
void GammaPower::begin()
{
  pinMode(chrgPin, INPUT);
}
 
bool GammaPower::isCharging()
{
  // Returns whether or not the battery is charging
  return  !digitalRead(chrgPin); // BE SURE TO CHANGE THIS TO A CONST OR #DEFINE LATER
  //The negation is used above because the digitalRead returns low when the pin is charging.  
  
}
uint16_t GammaPower::getBatteryVoltage()
{
  uint16_t val = analogRead(battPin); // Returns value between 0(0V) and 1023 (3.3V).  
  uint16_t voltage = VDD*(val/adcResolution); // Not trying to use floating point right here.  Instead keeping as an integer.  
  return 2*voltage;
}
