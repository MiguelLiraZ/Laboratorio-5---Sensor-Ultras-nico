#include <LiquidCrystal_I2C.h>

const int Trigger = 2;
const int Eco = 3;
int x = 0; 

int Rojo = 9;
int Ama = 8;
int Verde = 7;

int a = 0;
int dir = 5;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{

  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  Serial.begin(9600);
  
  pinMode(Trigger, OUTPUT);
  pinMode(Eco, INPUT);

  pinMode(Rojo, OUTPUT);
  pinMode(Ama, OUTPUT);
  pinMode(Verde, OUTPUT);

  digitalWrite(Rojo, LOW);
  digitalWrite(Ama, LOW);
  digitalWrite(Verde, LOW);
  
  digitalWrite(Trigger,LOW);
  
}

void loop()
{
  
  long t;
  long d;
  
  digitalWrite(Trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger,LOW);
  
  t = pulseIn(Eco,HIGH);
  d = t / 59;

  Serial.print(d);
  Serial.print(",");
  Serial.println(a);

  a+=dir;

  if(a==0){
  dir = 5;
  }
  
  if(a==180){
  dir = -5;
  }
  
   if(d>11 && d<20){ //Rojo
    digitalWrite(Rojo, HIGH);
    digitalWrite(Ama, LOW);
    digitalWrite(Verde, LOW);

    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(d);
    lcd.setCursor(4,0);
    lcd.print("Centimetros");

    lcd.setCursor(1,1);
    lcd.print("Cerca");
  }
  
  if(d>21 && d<50){ //Amarillo
    digitalWrite(Rojo, LOW);
    digitalWrite(Ama, HIGH);
    digitalWrite(Verde, LOW);

    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(d);
    lcd.setCursor(4,0);
    lcd.print("Centimetros");

    lcd.setCursor(1,1);
    lcd.print("Intermedio");
    
  }
  
  if(d>51 && d<150){ //Verde
    digitalWrite(Rojo, LOW);
    digitalWrite(Ama, LOW);
    digitalWrite(Verde, HIGH);

    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(d);
    lcd.setCursor(4,0);
    lcd.print("Centimetros");

    lcd.setCursor(1,1);
    lcd.print("Lejos");
    
  }
  
  if(d>0 && d<10){ //Rojo - Parpadea
    digitalWrite(Rojo, HIGH);
    digitalWrite(Ama, LOW);
    digitalWrite(Verde, LOW);
    delay(500);
    digitalWrite(Rojo, LOW);
    delay(500);

    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(d);
    lcd.setCursor(4,0);
    lcd.print("Centimetros");

    lcd.setCursor(1,1);
    lcd.print("Muy Cerca");

    
    
  delay(100);
  
 }
}
  
