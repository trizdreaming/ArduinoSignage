#include <LiquidCrystal.h>

#define BUTTON_PIN A5
#define LCD_LIGHT_PIN A4
#define LCD_LIGHT_ON_TIME 4000

unsigned int currentLcdLightOnTime = 0;
unsigned long lcdLightOn_StartMillis;
boolean isLcdLightOn;

int buttonState = 0;

int flag = 1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte sentence1_1[8] = {
        B00010,
        B11110,
        B01010,
        B01011,
        B10110,
        B00010,
        B00010,
        B00000
};

byte sentence1_2[8] = {
        B01001,
        B01001,
        B10101,
        B10101,
        B00000,
        B11111,
        B00001,
        B00001
};

byte sentence1_3[8] = {
        B00010,
        B01011,
        B10110,
        B01011,
        B00010,
        B01100,
        B10010,
        B01100
};

byte sentence1_4[8] = {
        B01001,
        B01001,
        B10101,
        B10101,
        B00000,
        B01110,
        B01010,
        B01110
};

byte sentence1_6[8] = {
        B01001,
        B10101,
        B10111,
        B01001,
        B10110,
        B11111,
        B10111,
        B11100
};

byte sentence1_7[8] = {
        B00000,
        B11111,
        B00001,
        B00001,
        B00000,
        B11111,
        B00100,
        B00100
};
byte sentence1_8[8] = {
        B00000,
        B00010,
        B10010,
        B10010,
        B10010,
        B11111,
        B00010,
        B00010
};

byte newChar[8] = {
        B00100,
        B00100,
        B00100,
        B00100,
        B11100,
        B11111,
        B11111,
        B01111
};



void setup() {
  lcd.begin(16, 2);
  
  //sentence be decided by flag point

    //first sentence
    lcd.createChar(2, sentence1_1);  
    lcd.createChar(3, sentence1_2);   
    lcd.createChar(4, sentence1_3);
    lcd.createChar(5, sentence1_4);
    lcd.createChar(7, sentence1_6); 
    lcd.createChar(8, sentence1_7);
    lcd.createChar(9, sentence1_8); 

  //for xbee
  Serial.begin(9600);
  
  //for lcd backlight
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LCD_LIGHT_PIN, OUTPUT);
  digitalWrite(LCD_LIGHT_PIN, LOW);
  isLcdLightOn = false;
}

void loop() {
  //control lcd contrast
  int sensorReading = analogRead(A0);
  int delayTime = map(sensorReading, 0, 1023, 200, 1000);
  
  //lcd backlight control
  buttonState = digitalRead(BUTTON_PIN);
  
  if( Serial.available() > 0 )
  {
    char inByte = Serial.read();
    
    if( inByte == 'A')
    {
      flag = 0;
      buttonState = HIGH;
    }
    if( inByte == 'B')
    {
      flag = 1;
      buttonState = HIGH;
    }
    if( inByte == 'C')
    {
      flag = 2;
      buttonState = HIGH;
    }
    if( inByte == 'D')
    {
      flag = 3;
      buttonState = HIGH;
    }
    if( inByte == 'E')
    {
      flag = 4;
      buttonState = HIGH;
    }
    if( inByte == 'F')
    {
      flag = 5;
      buttonState = HIGH;
    }
    
  }
  
  
  if(buttonState == HIGH)
  {
    lcdLightOn_StartMillis = millis();
    currentLcdLightOnTime = 0;
    isLcdLightOn = true;
    digitalWrite(LCD_LIGHT_PIN, HIGH);
  }
  else
  {
    if(isLcdLightOn)
    {
      if(flag == 0)
      {
        lcd.setCursor(0,0); 
        lcd.write("Hey!");
        lcd.print(" ");
        lcd.write(2);  
        lcd.write(3); 
        lcd.print(" ");
        lcd.write(4);
        lcd.write(5);
        lcd.print(" ");
        lcd.write(7);
        lcd.write(8);
        lcd.write(9);
        lcd.print("!");
        
        lcd.setCursor(0,1);
        lcd.print("Be Yield :(");
      }
      else if(flag == 1)
      {
        lcd.setCursor(0,0); 
        lcd.print("I SEE!!");
        lcd.setCursor(0,1);
        lcd.print("Follow Me :(");
      }
      else if(flag == 2)
      {
        lcd.setCursor(0,0); 
        lcd.print("Catch Me!");
        lcd.setCursor(0,1);
        lcd.print("IF you Can...");
      }
      else if(flag == 3)
      {
        lcd.setCursor(0,0); 
        lcd.print("No Respite");
        lcd.setCursor(0,1);
        lcd.print("No Forgive");
      }
      else if(flag == 4)
      {
        lcd.setCursor(0,0); 
        lcd.print("i don't know");
        lcd.setCursor(0,1);
        lcd.print("Who You Are");
      }
      else if(flag == 5)
      {
        lcd.setCursor(0,0); 
        lcd.print("But I Will");
        lcd.setCursor(0,1);
        lcd.print("Find you. FinD.");
      }
      else
      {
        lcd.setCursor(0,0); 
        lcd.print("error");
        lcd.setCursor(0,1);
        lcd.print("not have Flags!!");
      }
      
      
      currentLcdLightOnTime = millis() - lcdLightOn_StartMillis;
      
      if(currentLcdLightOnTime > LCD_LIGHT_ON_TIME)
      {
        isLcdLightOn = false;
        currentLcdLightOnTime = 0;
        digitalWrite(LCD_LIGHT_PIN, LOW);
        
        flag = 6;
        lcd.begin(16, 2);
        lcd.setCursor(0,0);
      }
    }
  }
  
  
  //Serial.println(currentLcdLightOnTime);
  
  
    
  delay(delayTime);
}
