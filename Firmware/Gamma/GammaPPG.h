/*
 FILENAME:  GammaPPG.h
 AUTHOR:  Orlando Hoilett
 EMAIL:     ohoilett@purdue.edu / orlandohoilett@gmail.com
 
 
 Please see .cpp file for extended descriptions, instructions, and version updates
 
 
 */


#ifndef GammaPPG_h
#define GammaPPG_h


//Standard Arduino Libraries
#include <Arduino.h>

//Custom External Libraries
#include "AD524X.h"


class GammaPPG
{
  
private:
  
  //potentiometer to control gain of TIA and bandpass filters
  AD524X ad5242;
  
  //Gain settings for digital potentiometers
  uint8_t R_ledCurrent;
  uint8_t R_tiaGain;
  uint8_t R_ppgGain;
  
  //true = ON, false = OFF
  bool ledState;
  
  
public:
  
  GammaPPG(); //must be called before setup in .ino code
  void begin(); //must be called in setup in .ino code
  
  
  //Control LED
  void turnLEDOn();
  void turnLEDOff();
  bool getLEDStatus() const;
  void setLEDCurrent(uint8_t val);
  uint8_t getLEDCurrent() const;
  void balanceLEDCurrent();
  
  
  //Amplifier gain control for TIA
  void setTIAGain(uint8_t gain);
  uint8_t getTIAGain() const;
  void balanceTIAGain();
  
  
  //Amplifier gain control for Bandpass filter
  void setPPGGain(uint8_t gain);
  uint8_t getPPGGain() const;
  
  
  //Read voltage of PPG circuit
  uint16_t getTIA() const;
  uint16_t getPPG() const; //bandpass filters
  
  
};



#endif /* GammaPPG_h */
