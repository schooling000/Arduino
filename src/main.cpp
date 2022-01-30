#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <DHT.h>

/* PHẦN KHAI BÁO CÁC HẰNG SỐ*/
#define DHT_PIN 2
#define DHT_TYPE DHT22

#define RADIO_CE   9
#define RADIO_CSN 10

/* PHẦN KHAI BÁO CÁC HÀM*/
void Show_Sensor_Info();

/* PHẦN KHAI BÁO CẢM BIẾN VÀ CÁC BIẾN TOÀN CỤC*/
DHT DHTSensor(DHT_PIN, DHT_TYPE);

RF24 radio(RADIO_CE, RADIO_CSN);

void setup()
{
  Serial.begin(9600);
  Serial.println("Khởi Tạo SERIAL");

  DHTSensor.begin();
  Serial.println("Khởi Tạo Cảm Biến DHT");

  if (!radio.begin())
  {
    Serial.println("Khởi Tạo FR24L01 Thất Bại");
    while (!radio.begin())
    {
      Serial.print(".");
      delay(1000);
    }
  }
  Serial.println("Khởi Tạo RF24L01");

}

void loop()
{
  float T = DHTSensor.readTemperature();
  float H = DHTSensor.readHumidity();
  Show_Sensor_Info(T, H);
  delay(1000);
}

void Show_Sensor_Info(float NhietDo, float DoAm)
{
  Serial.println("---------------------------------------");
  Serial.println("-------------DHT SENSOR----------------");
  Serial.println("---------------------------------------");
  Serial.print("NHIỆT ĐỘ: ");
  Serial.println(NhietDo);
  Serial.print("NHIỆT ĐỘ: ");
  Serial.println(DoAm);
  Serial.println("---------------------------------------");
  Serial.println("---------------------------------------");
  Serial.println("---------------------------------------");
}