#include <WiFi.h>
#include <HTTPClient.h>
#include "esp_camera.h"
#include "HX711.h"

const char* wifi_name = "YOUR_WIFI_NAME";
const char* wifi_pass = "YOUR_WIFI_PASSWORD";
const char* upload_url = "http://YOUR_LAPTOP_LOCAL_IP:8080/upload-frame";

const int SCALE_DOUT_PIN = 13;
const int SCALE_CLK_PIN = 14;
HX711 scale;
float scale_calibration_factor = -405.0;

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

void setup() {
  Serial.begin(115200);
  
  scale.begin(SCALE_DOUT_PIN, SCALE_CLK_PIN);
  scale.set_scale(scale_calibration_factor);
  scale.tare();
  
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_QVGA;
  config.jpeg_quality = 12;
  config.fb_count = 1;
  
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.println("init error");
    return;
  }

  WiFi.begin(wifi_name, wifi_pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("connected");
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    return;
  }
    
  float w = scale.get_units(5);
  if (w < 0) { 
    w = 0.0; 
  }
    
  camera_fb_t * fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("fb error");
    return;
  }

  HTTPClient http;
  http.begin(upload_url);
    
  http.addHeader("Content-Type", "image/jpeg");
  http.addHeader("x-weight-grams", String(w, 1)); 
  http.addHeader("x-crop-type", "basil");
    
  int code = http.POST(fb->buf, fb->len);
    
  if (code > 0) {
    Serial.print("status: ");
    Serial.println(code);
  } else {
    Serial.println("error posting");
  }
    
  http.end();
  esp_camera_fb_return(fb);
  
  delay(5000);
}
