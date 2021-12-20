#include <LiquidCrystal.h>

//declaramos la pantalla lcd y asignamos los pines de UNOR3 con los
//que vamos a comunicarnos con la pantalla. El pin 6 está conectado al 
//TILT sensor por lo que no se asigna aquí.
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//switchPin es el pin al que está conectado el tilt switch
const int switchPin = 6;
//swichtState marca el estado del sensor de movimiento tilt switch
int switchState = 0;
//prevSwitchState registra el valor previo del sensor
int prevSwitchState = 0;
//reply guarda la respuesta del programa
int reply;
int puntosJugador = 0;
int i = 0;
int j = 0;
int dificultad = 200;

void setup() {
  
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  lcd.print("Welcome to");
  lcd.setCursor(0, 1); 
  //estamos poniendo el cursor para escribir en la segunda linea
  //de la pantalla.
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
  while(puntosJugador != 1){ 

    
    
    for (i == 0; i<=15; i++) {
      switchState =digitalRead(switchPin);
      if (switchState == HIGH){
      lcd.clear();
      lcd.setCursor(15,0);
      lcd.print("X");
      lcd.setCursor(15,15);
      lcd.print("X");
      delay(dificultad);
      lcd.clear();
      }
      if (i <15){
        lcd.clear();
        lcd.setCursor(i, 0);
        lcd.print('o');
        delay(dificultad);
      }else if (i == 15){
       
        switchState =digitalRead(switchPin);
        if (switchState == HIGH){
          /*ahora la bola ha llegado al final y el boton esta pulsado por lo que debe volver en sentido contrario*/
          puntosJugador += 1;
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
              delay(dificultad);
          }
      
        }else{
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("GAME OVER!");
          lcd.setCursor(3,1);
          lcd.print("Puntos:");
          lcd.print(puntosJugador);
        }
  }
}
  }
}
