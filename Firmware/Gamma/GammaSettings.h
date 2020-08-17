
/*
 * DESCRIPTION:
 * This class governs the loading of settings from a 
 * JSON file, the manipulation of those settings during
 * run-time, and the saving of those features to the JSON file
 */

#ifndef GammaSettings_h
#define GammaSettings_h

#include <Arduino.h> //Used to access Arduino libraries

class GammaSettings
{
private:


public:
  GammaSettings();
  void begin();
  
  void loadFromFile(char* filename);
  void saveToFile(char* filename);
    
};
#endif
