/*
=== SISTEMA DE COLETA INDUSTRIAL ===
Desenvolvido por: Stephanie Dias
Enterprise Challenge Reply - Sprint 4
=====================================
*/

#include <WiFi.h>
#include <Arduino.h>

// Definições dos pinos
#define LED_RED 12      // LED vermelho - indica alertas
#define LED_GREEN 13    // LED verde - indica sistema funcionando
#define BUZZER_PIN 2    // Buzzer para alertas sonoros

// Variáveis globais
unsigned long lastReading = 0;
const unsigned long READING_INTERVAL = 3000; // 3 segundos
int readingCount = 0;
unsigned long startTime = 0;

// Estrutura para armazenar dados dos sensores
struct SensorData {
  float temperature;
  float humidity;
  float soilMoisture;
  float lightLevel;
  String alerts;
};

void setup() {
  Serial.begin(115200);
  
  // Configurar pinos
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Estado inicial
  digitalWrite(LED_GREEN, HIGH);  // Sistema funcionando
  digitalWrite(LED_RED, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  
  // Inicializar gerador de números aleatórios
  randomSeed(analogRead(0));
  startTime = millis();
  
  delay(2000);
  
  // Cabeçalho do sistema
  Serial.println("=== SISTEMA DE COLETA INDUSTRIAL ===");
  Serial.println("Desenvolvido por: Stephanie Dias");
  Serial.println("Enterprise Challenge Reply - Sprint 4");
  Serial.println("=====================================");
  Serial.println("Sistema inicializado com sucesso!");
  Serial.println("Iniciando coleta de dados...");
  Serial.println("timestamp,temperature,humidity,soil_moisture,light_level,alerts");
}

void loop() {
  unsigned long currentTime = millis();
  
  if (currentTime - lastReading >= READING_INTERVAL) {
    // Coletar dados dos sensores
    SensorData data = collectSensorData();
    
    // Verificar alertas
    data.alerts = checkAlerts(data);
    
    // Controlar LEDs e buzzer
    controlIndicators(data.alerts);
    
    // Enviar dados via serial
    sendDataToSerial(data, currentTime);
    
    readingCount++;
    lastReading = currentTime;
    
    // Mostrar estatísticas a cada 10 leituras
    if (readingCount % 10 == 0) {
      showStatistics(currentTime);
    }
  }
  
  delay(100); // Pequeno delay para estabilidade
}

SensorData collectSensorData() {
  SensorData data;
  
  // Simular leituras dos sensores com variação realística
  data.temperature = 24.5 + random(-50, 100) / 10.0;  // 19.5°C a 34.5°C
  data.humidity = 62.0 + random(-200, 200) / 10.0;    // 42% a 82%
  data.soilMoisture = 45.0 + random(-300, 300) / 10.0; // 15% a 75%
  data.lightLevel = 65.0 + random(-300, 200) / 10.0;   // 35% a 85%
  
  // Garantir valores dentro dos limites
  data.humidity = constrain(data.humidity, 10, 95);
  data.soilMoisture = constrain(data.soilMoisture, 5, 85);
  data.lightLevel = constrain(data.lightLevel, 10, 100);
  
  return data;
}

String checkAlerts(SensorData data) {
  String alerts = "";
  
  // Verificar temperatura
  if (data.temperature > 30.0) {
    alerts += "TEMP_HIGH;";
  } else if (data.temperature < 5.0) {
    alerts += "TEMP_LOW;";
  }
  
  // Verificar umidade
  if (data.humidity < 20.0) {
    alerts += "HUMIDITY_LOW;";
  } else if (data.humidity > 90.0) {
    alerts += "HUMIDITY_HIGH;";
  }
  
  // Verificar umidade do solo
  if (data.soilMoisture < 15.0) {
    alerts += "SOIL_DRY;";
  } else if (data.soilMoisture > 80.0) {
    alerts += "SOIL_WET;";
  }
  
  // Verificar luminosidade
  if (data.lightLevel < 20.0) {
    alerts += "LIGHT_LOW;";
  }
  
  return alerts;
}

void controlIndicators(String alerts) {
  if (alerts.length() > 0) {
    // Alerta detectado
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    
    // Buzzer intermitente
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    
    Serial.println("🚨 ALERTA DETECTADO!");
  } else {
    // Sistema normal
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void sendDataToSerial(SensorData data, unsigned long timestamp) {
  // Formato CSV para fácil análise
  Serial.print(timestamp);
  Serial.print(",");
  Serial.print(data.temperature, 2);
  Serial.print(",");
  Serial.print(data.humidity, 2);
  Serial.print(",");
  Serial.print(data.soilMoisture, 1);
  Serial.print(",");
  Serial.print(data.lightLevel, 1);
  Serial.print(",");
  Serial.println(data.alerts);
}

void showStatistics(unsigned long currentTime) {
  unsigned long uptime = (currentTime - startTime) / 1000;
  
  Serial.println("╔════════════════════════════╗");
  Serial.println("║       ESTATÍSTICAS         ║");
  Serial.println("╠════════════════════════════╣");
  Serial.print("║ Leituras realizadas: ");
  Serial.print(readingCount);
  Serial.println("     ║");
  Serial.print("║ Tempo de execução: ");
  Serial.print(uptime);
  Serial.println("s      ║");
  
  // Mostrar última leitura
  SensorData lastData = collectSensorData();
  Serial.print("║ Última temperatura: ");
  Serial.print(lastData.temperature, 1);
  Serial.println("°C  ║");
  Serial.print("║ Última umidade: ");
  Serial.print(lastData.humidity, 1);
  Serial.println("%      ║");
  
  Serial.println("╚════════════════════════════╝");
}
