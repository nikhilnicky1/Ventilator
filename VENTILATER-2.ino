 
   
    #include <LiquidCrystal.h>
     
   // defines pins numbers
    const int stepPin = 8; 
    const int dirPin = 9; 
    int customDelay,customDelayMapped; // Defines variables
    const int homeSwitchPin = 6;//PIN NUMBER
    
      LiquidCrystal lcd(53, 51, 49, 47, 45, 43); 
    const int Contrast=50;
    const int lcdpin = 7;
    void setup() {
      // Sets the two pins as Outputs
      pinMode(stepPin,OUTPUT); 
      pinMode(dirPin,OUTPUT);
      pinMode(homeSwitchPin , INPUT);
      Serial.begin(9600);
      pinMode(lcdpin,OUTPUT);
      analogWrite(lcdpin,Contrast);
      // set up the LCD's number of columns and rows:
      lcd.begin(16, 2);
       
      }
      
    void loop() {

      // put your main code here, to run repeatedly:
       int customDelay = analogRead(A0);
       int customDelay1 = analogRead(A1);
         int BPM = map(customDelay, 0, 1023, 20, 60);
         int BPM1 = map(BPM, 20, 60, 1000, 400);
   lcd.setCursor(0, 0);
       Serial.print("BPM=");
      lcd.print("BPM=");
      lcd.print(BPM);
       Serial.print(BPM);
       Serial.print("\t");
         int VOLUME = map(customDelay1, 0, 1023, 200, 800);
         int VOLUME1 = map(VOLUME, 200, 800, 400, 1300);
       Serial.print("VOLUME=");
       Serial.print(VOLUME);
       Serial.print("\t");
   lcd.setCursor(0, 1);   
      lcd.print("VOLUME1=");
      lcd.print(VOLUME1);
       Serial.print("VOLUME1=");
       Serial.println(VOLUME1);
      
        digitalWrite(dirPin,HIGH);
           for(int x = 0; x < VOLUME1; x++) {
              digitalWrite(stepPin,HIGH); 
              delayMicroseconds(BPM1); 
              digitalWrite(stepPin,LOW); 
              delayMicroseconds(BPM1); 
               }
               delay(100);
      
         digitalWrite(dirPin,LOW);
           for(int x = 0; x < VOLUME1; x++) {
               digitalWrite(stepPin,HIGH); 
               delayMicroseconds(BPM1); 
               digitalWrite(stepPin,LOW); 
               delayMicroseconds(BPM1); 
               }
               delay(100);
   lcd.clear();            
    }
