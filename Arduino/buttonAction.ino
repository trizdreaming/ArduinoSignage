const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buttonPin5 = 6;
const int buttonPin6 = 7;

int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;
int button5State = 0;
int button6State = 0;

void setup()
{
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  
  Serial.begin(9600);
}


void loop()
{
  button1State = digitalRead(buttonPin1);
  button2State = digitalRead(buttonPin2);
  button3State = digitalRead(buttonPin3);
  button4State = digitalRead(buttonPin4);
  button5State = digitalRead(buttonPin5);
  button6State = digitalRead(buttonPin6);
  
  if(button1State == HIGH)
  {
    Serial.print('A');
    delay(600);
  }
  else if(button2State == HIGH)
  {
    Serial.print('B');
    delay(600);
  }
  else if(button3State == HIGH)
  {
    Serial.print('C');
    delay(600);
  }
  else if(button4State == HIGH)
  {
    Serial.print('D');
    delay(600);
  }
  else if(button5State == HIGH)
  {
    Serial.print('E');
    delay(600);
  }
  else if(button6State == HIGH)
  {
    Serial.print('F');
    delay(600);
  }
}
