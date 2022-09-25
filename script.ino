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

void setup() {
  
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  lcd.print("Welcome to");
  lcd.setCursor(0, 1); 
  // setting cursos to write in the seccond line of the screen
  //MASSIVE REFACTOR NEEDED HERE! its fun to see code you wrote ages ago xD
  lcd.print("PONG-uino!");
  delay(1500);
  lcd.setCursor(0,0);
  lcd.print("PONG-uino!      ");
  lcd.setCursor(0,1);
  lcd.print("the game.");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("                ");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("               b");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("              by");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("             by ");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("            by D");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("           by Di");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("          by Die");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("         by Dieg");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("        by Diego");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("       by Diego ");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("      by Diego  ");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("     by Diego   ");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("    by Diego    ");
  delay(90);
  lcd.setCursor(0,0);
  lcd.print("   by Diego     ");
  delay(150);
  lcd.setCursor(0,0);
  lcd.print("  by Diego      ");
  delay(150);
  lcd.setCursor(0,0);
  lcd.print(" by Diego       ");
  delay(150);
  lcd.setCursor(0,0);
  lcd.print("by Diego        ");
  delay(150);
  lcd.setCursor(0,0);
  lcd.print("y Diego         ");
  delay(150);
  lcd.setCursor(0,0);
  lcd.print(" Diego          ");
  delay(150);
  lcd.setCursor(0,0);
  lcd.print("Diego           ");
  delay(150);
  lcd.setCursor(0,0);
  lcd.print("iego            ");
  delay(150);
  lcd.setCursor(0,0);
  lcd.print("ego             ");
  delay(150);
  lcd.setCursor(0,0);
  lcd.print("go              ");
  delay(150);
  lcd.setCursor(0,0);
  lcd.print("o               ");
  delay(500);

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
