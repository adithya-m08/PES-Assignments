#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#include "SoftwareSerial.h"
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create a MFRC522 object.
SoftwareSerial ser(2, 3); // RX, TX6
void setup()
{
  Serial.begin(9600);   // Initiate the serial communication
  ser.begin (115200);
  SPI.begin();      // Initiate the SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("PLEASE PUT RFID TAG IN FRONT OF THE SCANNER...");
  Serial.println();
  pinMode(7,OUTPUT);
}

void loop()
{
  int pos;
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor

  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  if (content.substring(1) == "13 53 2F 13" ) //change here the UID of the card
  {
    Serial.println("Welcome Adithya");
    ser.write(1);
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    delay(3000);
  }

  if (content.substring(1) == "D3 11 18 0C" ) //change here the UID of the card
  {
    Serial.println("Welcome Pradhan");
    ser.write(2);
    digitalWrite(7,HIGH);
    delay(500);
    digitalWrite(7,LOW);
    delay(3000);
  }
}
