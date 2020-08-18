
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10);

int PinSensor = A0;
int PinRelais = 2;
int On = 0;

int ValeurSensor = 0;
int pourcentage = 0;

char car = NULL;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(PinRelais, OUTPUT);
}

void loop() {
  ValeurSensor = analogRead(PinSensor);
  pourcentage = ConvertEnPercent(ValeurSensor);

  car = mySerial.read();

  switch(car){
    case '1':
      On = 1;
      break;
    case '2':
      On = 0;
      break;
    default:
      car = NULL;
      break;
  }

  if (pourcentage <= 45 || On == 1) {
    digitalWrite(PinRelais, HIGH);
  }
  else if (pourcentage >= 40 || On == 0) {
    digitalWrite(PinRelais, LOW);
  }

  if (pourcentage > 100) {
    pourcentage = 100;
  }

  AfficheValeurEtPourcentage();
  delay(1000);
}

int ConvertEnPercent(int value) {
  int ValeurPorcentage = 0;
  ValeurPorcentage = map(value, 1023, 360, 0, 100);
  return ValeurPorcentage;
  
}

void AfficheValeurEtPourcentage() {
  Serial.print("Valeur: ");
  Serial.println(ValeurSensor);
  Serial.print("Pourcentage: ");
  Serial.print(pourcentage);
  Serial.println("%");
  Serial.println("-----------");
}
