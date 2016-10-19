/*
This Program will recieve data from the computer over serial
and process it as different commands depending on the leading byte
 */
#define REDPIN 9
#define GREENPIN 11
#define BLUEPIN 13
#define ORANGEPIN 12
#define WHITEPIN 10

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int state;
 
// the setup routine runs once when you press reset:
void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(ORANGEPIN, OUTPUT);
  pinMode(WHITEPIN, OUTPUT);
  
  Serial.begin(9600);
}
 
// the loop routine runs over and over again forever:
void loop() {  
  if (Serial.available() > 0) {
   if(Serial.peek() == 'b' || Serial.peek() == 'o' || Serial.peek() == 'g' || Serial.peek() == 'w' || Serial.peek() == 'r' || Serial.peek() == 'c' || Serial.peek() == 'f'){
      int choice = Serial.read();
      state = Serial.parseInt();
      
      if (choice == 'b') { //check for the character that signifies that this will be a command
        if(digitalRead(BLUEPIN)==HIGH)
          digitalWrite(BLUEPIN, LOW);
        else
          digitalWrite(BLUEPIN, HIGH);
      }
      else if (choice == 'o') { //check for the character that signifies that this will be a command
        if(digitalRead(ORANGEPIN)==HIGH)
          digitalWrite(ORANGEPIN, LOW);
        else
          digitalWrite(ORANGEPIN, HIGH);
      }
      else if (choice == 'g') { //check for the character that signifies that this will be a command
        if(digitalRead(GREENPIN)==HIGH)
          digitalWrite(GREENPIN, LOW);
        else
          digitalWrite(GREENPIN, HIGH);
      }
      else if (choice == 'w') { //check for the character that signifies that this will be a command
        if(digitalRead(WHITEPIN)==HIGH)
          digitalWrite(WHITEPIN, LOW);
        else
          digitalWrite(WHITEPIN, HIGH);
      }
      else if (choice == 'r') { //check for the character that signifies that this will be a command
         if(digitalRead(REDPIN)==HIGH)
          digitalWrite(REDPIN, LOW);
         else
          digitalWrite(REDPIN, HIGH);
      }
      else if(choice == 'c'){
        digitalWrite(BLUEPIN, LOW);
        digitalWrite(ORANGEPIN, LOW);
        digitalWrite(GREENPIN, LOW);
        digitalWrite(WHITEPIN, LOW);
        digitalWrite(REDPIN, LOW);
      }
      else if(choice == 'f'){
        digitalWrite(BLUEPIN, HIGH);
        digitalWrite(ORANGEPIN, HIGH);
        digitalWrite(GREENPIN, HIGH);
        digitalWrite(WHITEPIN, HIGH);
        digitalWrite(REDPIN, HIGH);
      }
    while ((Serial.available() > 0) && !(Serial.peek() == 'b' || Serial.peek() == 'o' || Serial.peek() == 'g' || Serial.peek() == 'w' || Serial.peek() == 'r' || Serial.peek() == 'c' || Serial.peek() == 'f')){ //Discard everything that we didn't expect
      Serial.read();
    }
   }
  }
}
