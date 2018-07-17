/*
 * Ekran için gerekli kütüphane
 * The screen's library:
 * https://github.com/jandelgado/arduino/wiki/SSD1306-based-OLED-connected-to-Arduino
 * 
 */


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

#define OLED_MOSI  11   //D1
#define OLED_CLK   12   //D0
#define OLED_DC    9
#define OLED_CS    8    //my screen does not have cs pin. I did not use it. 
#define OLED_RESET 10

//the screen implement
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

String readFromAndroid;   

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

  //diğer oled de yazma için gerekli olanlar.
  //the screen skill setup
  display.begin(SSD1306_SWITCHCAPVCC);            //start screen
  display.display();
  delay(500);
  display.clearDisplay();
  display.setTextSize(1);                         //text size. you can chance if you want.
  display.setTextColor(WHITE);                    //my screen only has White.
}

void loop() {
  display.display();                
  display.clearDisplay();
  display.setCursor(0,0);
  
  display.println("The Text On Screen :");                    //write to screen
  Serial.println("Enter Text :");                             //write to Serial Port Screen

  //there is nothing differences between "readStringUntil()" and "readString()".
  readFromAndroid = mySerial.readStringUntil('\n');           //bluetooth dan text al     //input from bluetooth
  //readFromAndroid = Serial.readString();                    //serial porttan text al    //input from Serial Port

  delay(500);
  //Serial.println(readFromAndroid);    //serial de basma       //write to Serial Port
  display.println(readFromAndroid);     //oledde basma          //write to Screen
  delay(500);
  
}
