//Inclu indo bibliotecas para o programa
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal.h>
#include <DHT.h>

//Definindo pino e tipo do DHT a ser utilizado  
#define DHTPIN 8
#define DHTTYPE DHT22

//Determinando caracteristicas de alguns componentes
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12,11, 5, 4, 3, 2);
Adafruit_BMP085 bmp180;

//Determinando pino de alguns sensores e valor de outros
int lmPin = A0;
int pin_a0 = A2;
int nivel_sensor = 250;
int pino_a = A3;

void setup() 
{
  pinMode(pin_a0, INPUT);
  pinMode(pino_a, INPUT);
  pinMode(lmPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  dht.begin();
  bmp180.begin();
}

float tempC()
{
 float raw = analogRead(lmPin);
 float percent = raw/1023.0;
 float volts = percent*5;
 return 100*volts;
}

float tempF()
{return ((tempC()*9/5)+32);}

void loop() 
{ 
  Serial.print(dht.readHumidity());
  Serial.println("  % -Humidade");
  Serial.print(dht.readTemperature());
  Serial.println(" °C");
    {
     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(4, 0);
     lcd.print("Estacao");
     
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(1, 1);
     lcd.print("Meteorologica");
    }
delay(4000);


    {
     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(0, 0);
     lcd.print("Turma: C, Jose,");
     
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print("Felipe e Felipe");
    }
delay(4000);

    {
     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(0, 0);
     lcd.print("Altit.: ");
     lcd.print(bmp180.readAltitude());
     lcd.print(" m");
     
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print("Press.: ");
     lcd.print(bmp180.readPressure());  
     lcd.print(" Pa"); 
    }
    
delay(4000);

    {
     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(0, 0);
     lcd.print("Umid.: ");
     lcd.print(dht.readHumidity());
     lcd.print(" %");
   }
   
delay(4000);


   {
     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(0, 0);
     lcd.print("Gas CO");
     
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     int valor_analogico = analogRead(pin_a0);
     if (valor_analogico > nivel_sensor) {
        lcd.print("Detectado");
     }
     else {
        lcd.print("Nao Detectado");
     }
   }
   
delay(4000);



    {
     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(0, 0);
     lcd.print("Temperatura:");
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print(tempC());
     lcd.print(" C");
    }

delay(3000);


    {    
     lcd.setCursor(0, 0);
     lcd.print("                ");
     lcd.setCursor(0, 0);
     lcd.print("Temperatura:");
     lcd.setCursor(0, 1);
     lcd.print("                ");
     lcd.setCursor(0, 1);
     lcd.print(tempF());
     lcd.print(" F");
     }
delay(3000);
}
