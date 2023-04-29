#include <LiquidCrystal.h>

// declare lcd screen and assign UNOR3 pins that we will use to communicate with the screen.
// Pin 6 is connected to the TILT sensor so its not assigned here
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//switchPin connected to tilt switch
const int switchPin = 6;
//swichtState sets the state of tilt switch sensor
int switchState = 0;
//prevSwitchState registers sensor previous state
int prevSwitchState = 0;
//reply saves program output
int reply;
int playerPoints = 0;
int i = 0;
int j = 0;
int ballSpeed = 200;

void printWithDelay(int col, int row, const char* text, int waitTime) {
  lcd.setCursor(col, row);
  lcd.print(text);
  delay(waitTime);
}

void setup() {
  
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  printWithDelay(0, 0, "Welcome to", 0);
  printWithDelay(0, 1, "PONG-uino!", 1500);
  printWithDelay(0, 0, "PONG-uino!      ", 0);
  printWithDelay(0, 1, "the game.", 1500);
  
  lcd.clear();
  const char* animationText = "                b              by             by             by D           by Di          by Die         by Dieg        by Diego       by Diego       by Diego      by Diego     by Diego      by Diego   by Diego    by Diego     ";
  int animationTextLength = strlen(animationText);
  
  for (int i = 0; i < animationTextLength - 15; i++) {
    int delayTime = (i < animationTextLength - 31) ? 90 : 150;
    String frame = animationText.substring(i, i + 16);
    printWithDelay(0, 0, frame.c_str(), delayTime);
  }
  
  printWithDelay(0, 0, "o               ", 500);

}

void loop() {

  switchState =digitalRead(switchPin);
  while(playerPoints != 1){ 

    
    
    for (i == 0; i<=15; i++) {
      switchState =digitalRead(switchPin);
      if (switchState == HIGH){
      lcd.clear();
      lcd.setCursor(15,0);
      lcd.print("X");
      lcd.setCursor(15,15);
      lcd.print("X");
      delay(ballSpeed);
      lcd.clear();
      }
      if (i <15){
        lcd.clear();
        lcd.setCursor(i, 0);
        lcd.print('o');
        delay(ballSpeed);
      }else if (i == 15){
       
        switchState =digitalRead(switchPin);
        if (switchState == HIGH){
          // now the ball has reached screen end and btn is pressed so it should go back
          playerPoints += 1;
          for (i == 14; i>=0; i--) {
              switchState =digitalRead(switchPin);
              if (switchState == HIGH){
                lcd.clear();
                lcd.setCursor(15,0);
                lcd.print("X");
                lcd.setCursor(15,15);
                lcd.print("X");
                delay(1);
                lcd.clear();
              }
              lcd.clear();
              lcd.setCursor(i, 0);
              lcd.print('o');
              delay(ballSpeed);
          }
      
        }else{
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("GAME OVER!");
          lcd.setCursor(3,1);
          lcd.print("Puntos:");
          lcd.print(playerPoints);
        }
  }
}
  }
}
