#include <ESP8266WiFi.h>

#ifndef TEN_WIFI
#define TEN_WIFI "Cao"
#define MAT_KHAU_WIFI  "0795660069"
#endif

IPAddress  IP (192,168,1,30);
IPAddress  GETWAY (192,168,1,1);
IPAddress  SUBNET (255,255,255,0);

void setWifiIsAccessPoint(char* wifiName, char* wifiPass);  // CẤU HÌNH WIFI Ở CHẾ ĐỘ PHÁT WIFI
void setWifiIsStationPoint(char* wifiName, char* wifiPass); // CẤU HÌNH WIFI Ở CHẾ ĐỘ KÊT NỐI WIFI


void setup() {
  Serial.begin(9600);
  setWifiIsStationPoint(TEN_WIFI, MAT_KHAU_WIFI);  
}

void loop() {
  Serial.println(WiFi.localIP());
  delay(500);
}

void setWifiIsAccessPoint(char* wifiName, char* wifiPass){
  delay(500);
  Serial.println("");
  Serial.println(WiFi.softAPdisconnect() ? "Tắc Esp8266 Thành Công" : "Tắc Esp8266 Thất Bại");
  delay(500);
  Serial.println(WiFi.softAPConfig(IP, GETWAY, SUBNET) ? "Cấu Hình Esp8266 Thành Công" : "Cấu Hình Esp8266 Thất Bại");
  delay(500);
  Serial.println(WiFi.mode(WIFI_AP) ? "Cấu Hình Esp8266 Ở Chế Độ Phát WiFi Thành Công" : "Cấu Hình Esp8266 Ở Chế Độ Phát WiFi Thất Bại");
  delay(500);
  Serial.println(WiFi.softAP(wifiName, wifiPass) ? "Khởi Tạo Điểm Truy Cập WiFi Thành Công" : "Khởi Tạo Điểm Truy Cập WiFi Thất Bại");
}

void setWifiIsStationPoint(char* wifiName, char* wifiPass){
  delay(500);
  Serial.println("");
  Serial.println(WiFi.disconnect() ? "Tắc Esp8266 Thành Công" : "Tắc Esp8266 Thất Bại");
  delay(500);
  Serial.println(WiFi.config(IP, GETWAY, SUBNET) ? "Cấu Hình Esp8266 Thành Công" : "Cấu Hình Esp8266 Thất Bại");
  delay(500);
  Serial.println(WiFi.mode(WIFI_STA) ? "Cấu Hình Esp8266 Ở Chế Độ Kết Nối WiFi Thành Công" : "Cấu Hình Esp8266 Ở Chế Độ Kết Nối WiFi Thất Bại");
  delay(500);
  Serial.println(WiFi.begin(wifiPass, wifiPass) ? "Khởi Tạo Kết Nối WiFi Thành Công" : "Khởi Tạo Kết Nối WiFi Thất Bại");
  delay(500);
  while(WiFi.status() == WL_CONNECTED){
    Serial.print(".");
  }
  Serial.print("Esp8266 Kết Nối Thành Công Vào WiFi \"");
  Serial.print(TEN_WIFI);
  Serial.print("\" Với IP là: ");
  Serial.println(WiFi.localIP());
  WiFi.
}
