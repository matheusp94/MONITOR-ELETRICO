
// Configurações do Blynk
#define BLYNK_TEMPLATE_ID "TMPL2E3WzF9y4"
#define BLYNK_TEMPLATE_NAME "DeviceIOT"
#define BLYNK_AUTH_TOKEN "FJZdkXutCMC9UlA3qWz-ieHDPg7oKYn8"

#include <Arduino.h>
#include <Blynk/BlynkApi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Configurações da tela OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

// Credenciais Wi-Fi
const char *ssid = "Wokwi-GUEST";
const char *password = "";

// Pinos e variáveis
const int voltagePin = 35; // Pino analógico para medir a voltagem
const int currentPin = 34; // Pino analógico para medir a corrente
float voltage = 0.0;
float current = 0.0;
float power = 0.0;
float powerConsumption = 0.0;
float temperature = 0.0;
float costOfElectricity = 0.0;

const float electricityRate = 0.5; // Custo por kWh em £
unsigned long previousMillis = 0;
unsigned long totalMillis = 0;

BlynkTimer timer;

// Função para enviar dados ao Blynk
void sendDataToBlynk()
{
  // Leitura dos valores crus
  int rawVoltage = analogRead(voltagePin);
  int rawCurrent = analogRead(currentPin);

  // Conversão dos valores
  voltage = (rawVoltage / 4095.0) * 230;            // Supondo 230V
  float currentVoltage = (rawCurrent / 4095.0) * 5; // Supondo referência de 5V
  const float sensorSensitivity = 0.1;              // Sensibilidade do sensor (em V/A)
  current = currentVoltage / sensorSensitivity;
  power = voltage * current;

  // Cálculo do tempo decorrido
  unsigned long currentMillis = millis();
  unsigned long elapsedTime = currentMillis - previousMillis;
  previousMillis = currentMillis;
  totalMillis += elapsedTime;

  // Cálculo do consumo de energia e custo
  float elapsedTimeHours = totalMillis / 3600000.0;
  powerConsumption = (power / 1000.0) * elapsedTimeHours;
  costOfElectricity = powerConsumption * electricityRate;

  // Exibição no serial
  Serial.print("Voltagem: ");
  Serial.print(voltage);
  Serial.print(" V, Corrente: ");
  Serial.print(current);
  Serial.print(" A, Força consumida: ");
  Serial.print(powerConsumption);
  Serial.print(" kWh, Temperatura: ");
  Serial.print(temperature);
  Serial.print(" °C, Custo: R$");
  Serial.println(costOfElectricity, 2);

  // Envio para o Blynk
  Blynk.virtualWrite(V0, voltage);
  Blynk.virtualWrite(V1, current);
  Blynk.virtualWrite(V2, powerConsumption);
  Blynk.virtualWrite(V3, temperature);
  Blynk.virtualWrite(V4, costOfElectricity);
}

void setup()
{
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("Falha ao iniciar o OLED"));
    for (;;)
      ;
  }

  display.clearDisplay();
  display.setTextColor(WHITE);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  pinMode(voltagePin, INPUT);
  pinMode(currentPin, INPUT);

  timer.setInterval(5000L, sendDataToBlynk);
}

void loop()
{
  Blynk.run();
  timer.run();

  // Atualização da tela OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.print("Voltagem (V): ");
  display.println(voltage, 2);

  display.setCursor(0, 12);
  display.print("Corrente (A): ");
  display.println(current, 2);

  display.setCursor(0, 24);
  display.print("Watts (W): ");
  display.println(power, 2);

  display.setCursor(0, 36);
  display.print("Energia (kWh): ");
  display.println(powerConsumption, 4);

  display.setCursor(0, 48);
  display.print("Temperatura (C): ");
  display.println(temperature, 2);

  display.setCursor(0, 60);
  display.print("Custo: R$");
  display.println(costOfElectricity, 2);

  display.display();
}
