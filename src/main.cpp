#include <Arduino.h>
// #include <IRremote.h>
//#include <SoftwareSerial.h>

#define Motor1Maju 6
#define Motor1Mundur 7
#define Motor2Maju 9
#define Motor2Mundur 8
#define Motor3Maju 10
#define Motor3Mundur 11
#define Motor4Maju 13
#define Motor4Mundur 12
//#define IRPin 2

unsigned long kodeTombolTerakhir;
unsigned long terakhirDitekan;
bool ditekan = false;
String commandBT;
//SoftwareSerial BTSerial(22, 24); // RX, TX


// put function declarations here:
void berhenti();
void maju();
void mundur();
void kanan();
void kiri();
void bacaIR();
void gerakan();
void bacaBT();
void gerakanBT();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // IrReceiver.begin(IRPin, false);
  Serial1.begin(9600);
  pinMode(Motor1Maju, OUTPUT);
  pinMode(Motor1Mundur, OUTPUT);
  pinMode(Motor2Maju, OUTPUT);
  pinMode(Motor2Mundur, OUTPUT);
  pinMode(Motor3Maju, OUTPUT);
  pinMode(Motor3Mundur, OUTPUT);
  pinMode(Motor4Maju, OUTPUT);
  pinMode(Motor4Mundur, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //berhenti(2000);
  
  // maju(2000);
  // // berhenti(1000);
  // mundur(2000);
  // // berhenti(1000);
  // kanan();
  // // berhenti(1000);
  // kiri(2000);
  // // berhenti(1000);
  // bacaIR();
  //Serial.println(kodeIR);
  bacaBT();
}

void berhenti(){
  // Serial.println("Berhenti");
  digitalWrite(Motor1Maju, LOW);
  digitalWrite(Motor1Mundur, LOW);
  digitalWrite(Motor2Maju, LOW);
  digitalWrite(Motor2Mundur, LOW);
  digitalWrite(Motor3Maju, LOW);
  digitalWrite(Motor3Mundur, LOW);
  digitalWrite(Motor4Maju, LOW);
  digitalWrite(Motor4Mundur, LOW);
}

void maju(){
  // Serial.println("Maju");
  digitalWrite(Motor1Maju, HIGH);
  digitalWrite(Motor1Mundur, LOW);
  digitalWrite(Motor2Maju, HIGH);
  digitalWrite(Motor2Mundur, LOW);
  digitalWrite(Motor3Maju, HIGH);
  digitalWrite(Motor3Mundur, LOW);
  digitalWrite(Motor4Maju, HIGH);
  digitalWrite(Motor4Mundur, LOW);
}

void mundur(){
  // Serial.println("Mundur");
  digitalWrite(Motor1Maju, LOW);
  digitalWrite(Motor1Mundur, HIGH);
  digitalWrite(Motor2Maju, LOW);
  digitalWrite(Motor2Mundur, HIGH);
  digitalWrite(Motor3Maju, LOW);
  digitalWrite(Motor3Mundur, HIGH);
  digitalWrite(Motor4Maju, LOW);
  digitalWrite(Motor4Mundur, HIGH);
}

void kanan(){
  // Serial.println("Kanan");
  digitalWrite(Motor1Maju, HIGH);
  digitalWrite(Motor1Mundur, LOW);
  digitalWrite(Motor2Maju, LOW);
  digitalWrite(Motor2Mundur, HIGH);
  digitalWrite(Motor3Maju, HIGH);
  digitalWrite(Motor3Mundur, LOW);
  digitalWrite(Motor4Maju, LOW);
  digitalWrite(Motor4Mundur, HIGH);
}


void kiri() {
  // Serial.println("Kiri");
  digitalWrite(Motor1Maju, LOW);
  digitalWrite(Motor1Mundur, HIGH);
  digitalWrite(Motor2Maju, HIGH);
  digitalWrite(Motor2Mundur, LOW);
  digitalWrite(Motor3Maju, LOW);
  digitalWrite(Motor3Mundur, HIGH);
  digitalWrite(Motor4Maju, HIGH);
}

// void bacaIR(){
//   if (IrReceiver.decode()) {
//     if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
//       Serial.println("ditekan");
//       ditekan = true;
//     } else {
//       kodeTombolTerakhir = IrReceiver.decodedIRData.command;
//       gerakan();
//       Serial.print("Kode Tombol: ");
//       Serial.println(kodeTombolTerakhir);
//       ditekan = false;
//     }
//     terakhirDitekan = millis();
//     IrReceiver.resume();
//   }

//   if (ditekan && millis() - terakhirDitekan > 200) {
//     berhenti();
//     Serial.println("Tombol Dilepas");
//     ditekan = false;
//   }
// }

// void gerakan() {
//   switch (kodeTombolTerakhir) {
//     case 24:
//       maju();
//       break;
//     case 82:
//       mundur();
//       break;
//     case 90:
//       kanan();
//       break;
//     case 8:
//       kiri();
//       break;
//     default:
//       berhenti();
//       break;
//   }
// }

void bacaBT() {
  // Serial.print("Baca BT ");
  // Serial.println(BTSerial.available());
  // if (BTSerial.available()) {
  //   commandBT = Serial.readStringUntil('\n');
  //   Serial.print("Command: ");
  //   Serial.println(commandBT);
  //   gerakanBT();
  // }



  // if (BTSerial.available()) {
  //   commandBT = BTSerial.readStringUntil('\n');
  //   Serial.print("Command: ");
  //   Serial.println(commandBT);
  //   gerakanBT();
  // }

  if (Serial1.available()) {
    commandBT = Serial1.readStringUntil('\n');
    commandBT.trim();
    gerakanBT();
  }
  delay(100);
}

void gerakanBT() {
  if (commandBT == "F") {
    maju();
  } else if (commandBT == "B") {
    mundur();
  } else if (commandBT == "R") {
    kanan();
  } else if (commandBT == "L") {
    kiri();
  } else {
    berhenti();
  }
}