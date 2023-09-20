#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
int ledpin = 7;
int opt1pin = 9;
int opt2pin = 10;
int buzzerpin = 8;
int sensorpin = 12;
int opt;
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  if(!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  oled.display();
  delay(1000);
  pinMode(ledpin, OUTPUT);
  pinMode(sensorpin, INPUT);
  pinMode(opt1pin, INPUT);
  pinMode(opt2pin, INPUT);

  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.println(F("1. Light switch"));
  oled.println(F("2. Motion detector"));
  oled.println(F("For 1 press BLUE"));
  oled.println(F("For 2 press RED"));
  oled.display();
  while (digitalRead(opt1pin) == LOW && digitalRead(opt2pin) == LOW);
  if (digitalRead(opt1pin) == HIGH)
  {
    opt = 1;
    oled.clearDisplay();
    oled.setCursor(55, 4);
    oled.setTextSize(3);
    oled.println(F("1"));
    oled.display();
  }
  else {
    opt = 2;
    oled.clearDisplay();
    oled.setCursor(55, 4);
    oled.setTextSize(3);
    oled.println(F("2"));
    oled.display();
  }
  delay(1000);
}

void loop() {
  int value = digitalRead(sensorpin);
  if (opt == 1) Option1(value);
  else Option2(value);
}

void Option2(int value)
{
  if (value == HIGH) detectmotion();
  else stopmotion();
}

void detectmotion()
{
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(8, 12);
  oled.println(F("Motion was detected!"));
  oled.display();
  digitalWrite(buzzerpin, HIGH);
  delay(50);
}

void stopmotion()
{
  digitalWrite(buzzerpin, LOW);
  oled.clearDisplay();
  oled.setCursor(10, 12);
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.println(F("No motion detected!"));
  oled.display();
}

void Option1(int value)
{
  if (value == HIGH)
  {
    digitalWrite(ledpin, HIGH);
    oled.clearDisplay();
    oled.setCursor(30, 12);
    oled.setTextColor(SSD1306_WHITE);
    oled.setTextSize(1);
    oled.println(F("Light is on!"));
    oled.display();
    delay(60 * 1000);
    digitalWrite(ledpin, LOW);
    oled.clearDisplay();
    oled.setCursor(30, 12);
    oled.println(F("Light is off!"));
    oled.display();
  }
  delay(100);
}