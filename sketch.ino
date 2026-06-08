#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "HX711.h"

// OLED configuration
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// HX711 pins
const int LOADCELL_DOUT_PIN = 4;
const int LOADCELL_SCK_PIN = 2;
HX711 scale;

void setup() {
  Serial.begin(115200);
  
  // Initialize I2C with custom pins for ESP32-CAM layout
  Wire.begin(15, 14); 
  
  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("OLED allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Harvest AI Status:");
  display.println("Initializing scale...");
  display.display();

  // Initialize Scale
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.println("--- HARVEST AI ---");
  
  if (scale.is_ready()) {
    long reading = scale.read();
    display.setCursor(0, 25);
    display.setTextSize(2);
    display.print("Raw: ");
    display.print(reading / 1000); // Simple downscale for testing display
    
    Serial.print("Raw Scale Reading: ");
    Serial.println(reading);
  } else {
    display.setCursor(0, 25);
    display.println("Scale error!");
  }
  
  display.display();
  delay(500);
}
