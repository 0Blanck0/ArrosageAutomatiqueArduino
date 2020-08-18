#include <avr/wdt.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10);

int PinSensor = A0;
int PinSensor2 = A1;
int PinRelais = 2;
int PinRelais2 = 3;
int BoucleAff = 0;
int On = 0;
int One = 0;
int Two = 0;

int ValeurSensor = 0;
int pourcentage = 0;

int ValeurSensor2 = 0;
int pourcentage2 = 0;

char car = NULL;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

  pinMode(PinRelais, OUTPUT);
  pinMode(PinRelais2, OUTPUT);
  pinMode(PinSensor, INPUT);
  pinMode(PinSensor2, INPUT);
}

void loop() {
  ValeurSensor = analogRead(PinSensor);
  pourcentage = ConvertEnPercent(ValeurSensor);
  
  ValeurSensor2 = analogRead(PinSensor2);
  pourcentage2 = ConvertEnPercent(ValeurSensor2);

  car = mySerial.read();

  switch (car) {
    case 'O':
      On = 1;
      break;
    case 'F':
      On = 0;
      break;
    case '0':
      One = 0;
      Two = 0;
      On = 0;
      break;
    case '1':
      if(One == 1)
        One = 0;
      else
        One = 1;
      break;
    case '2':
      if(Two == 1)
        Two = 0;
      else
        Two = 1;
        break;
    case 'R':
      Serial.println("");
      Serial.println("Reset");
      Serial.println("");
      mySerial.println("");
      mySerial.println("Reset");
      mySerial.println("");
      wdt_enable(WDTO_1S);  // reset after one second, if no "pat the dog" received

      while (1) {

      }

      break;
    default:
      car = NULL;
      break;
  }

  if (pourcentage <= 25 || On == 1 || One == 1) {
    digitalWrite(PinRelais, HIGH);
    delay(1000);
  }
  else if (pourcentage >= 40 || On == 0) {
    digitalWrite(PinRelais, LOW);
  }

  if (pourcentage2 <= 35 || On == 1 || Two == 1) {
    digitalWrite(PinRelais2, HIGH);
    delay(1000);
  }
  else if (pourcentage2 >= 60 || On == 0) {
    digitalWrite(PinRelais2, LOW);
  }

  if (pourcentage > 100) {
    pourcentage = 100;
  }

  if (pourcentage2 > 100) {
    pourcentage2 = 100;
  }

  AfficheValeurEtPourcentage(ValeurSensor, pourcentage, 1);
  AfficheValeurEtPourcentage(ValeurSensor2, pourcentage2, 2);
  delay(1000);
}

int ConvertEnPercent(int value) {
  int ValeurPorcentage = 0;
  ValeurPorcentage = map(value, 1023, 360, 0, 100);
  return ValeurPorcentage;

}

void AfficheValeurEtPourcentage(int ValSensor, int Pourcent, int nb) {
  Serial.print("Case ");
  Serial.println(nb);
  Serial.print("Valeur: ");
  Serial.println(ValSensor);
  Serial.print("Pourcentage: ");
  Serial.print(Pourcent);
  Serial.println("%");
  Serial.println("-----------");

  if (BoucleAff >= 3) {
    mySerial.print("Case ");
    mySerial.println(nb);
    mySerial.print("Valeur: ");
    mySerial.println(ValSensor);
    mySerial.print("Pourcentage: ");
    mySerial.print(Pourcent);
    mySerial.println("%");
    mySerial.println("-----------");
    BoucleAff = 0;
  }
  else
    BoucleAff++;
}

void software_Reset()
{
  asm volatile ("  jmp 0");
}
