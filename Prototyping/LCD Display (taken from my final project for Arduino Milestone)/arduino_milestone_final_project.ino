#include <IRremote.h>  //including infrared remote header file     
#include <LiquidCrystal.h>
int RECV_PIN = 7; // the pin where you connect the output pin of IR sensor     
IRrecv irrecv(RECV_PIN);     
decode_results results;     
int on_state = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


char thank_you[11] = "Thank you ";
char very_much[11] = "very much ";
char for_teaching[14] = "for teaching ";
char this_course[13] = "this course.";

char* words[4] = {thank_you, very_much, for_teaching, this_course};
int word_idx = 0;
void setup()     
{     
Serial.begin(9600);     
irrecv.enableIRIn();
lcd.begin(16,2);     
on_state = 1;
word_idx = -1;
lcd.display();
}
void loop()     
{     
if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.     
{     
 int value = results.value;// Results of decoding are stored in result.value     
 if (value == -28561) {
    word_idx++;
    lcd.setCursor(0,1);
    lcd.print(words[word_idx]);
 }
 else if (value == -8161) {
  word_idx--;
  lcd.setCursor(0,1);
  lcd.print(words[word_idx]);
 }
 else if (value == -23971) {
    if (on_state == 1) {
      lcd.noDisplay();
      on_state--;
    }
    else {
      lcd.display();
      on_state = 1;
    }
 }

 delay(250);
 irrecv.resume(); // Restart the ISR state machine and Receive the next value     
}
}     
