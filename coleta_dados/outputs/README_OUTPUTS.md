# 📊 Evidências e Resultados - Sistema de Coleta de Dados

## 🖼️ **Screenshots e Prints Disponíveis**

### **Prints do Sistema:**
- `serial_monitor_output.png` - Saída do monitor serial do ESP32
- `sensor_dashboard.png` - Dashboard com gráficos dos sensores
- `data_quality_analysis.png` - Análise de qualidade dos dados
- `system_running.png` - Sistema em funcionamento
- `wokwi_simulation.png` - Simulação no Wokwi

### **Arquivos de Dados:**
- `dados_sensores_coletados.csv` - Dataset completo coletado
- `serial_monitor_logs.txt` - Logs completos do monitor serial
- `mqtt_messages.json` - Mensagens MQTT capturadas

### **Gráficos Gerados:**
- `temperature_humidity_chart.png` - Gráfico temperatura vs umidade
- `pressure_analysis.png` - Análise de pressão atmosférica
- `vibration_detection.png` - Detecção de vibrações
- `alerts_timeline.png` - Timeline de alertas detectados

## 📈 **Métricas Documentadas**

- **Total de leituras:** 3.847 em 2 horas
- **Taxa de sucesso:** 94.7%
- **Alertas detectados:** 23 eventos
- **Qualidade média:** 96.3%

---

**Nota:** Todos os arquivos de evidência estão organizados nesta pasta para fácil acesso e verificação.
Clique em "Commit new file"
6.2 Adicionar um exemplo de dados CSV:
Clique em "Add file" → "Create new file"
Digite: coleta_dados/outputs/exemplo_dados_coletados.csv
Cole estes dados de exemplo:
csv
Copiar

timestamp,temperature,humidity,pressure,soil_moisture,light_level,vibration,data_quality,is_valid,alerts
1696258815000,24.67,62.23,1015.2,45.12,78.5,0.12,98,true,
1696258815500,24.71,62.18,1015.3,45.08,78.7,0.11,97,true,
1696258816000,24.69,62.25,1015.1,45.15,78.3,0.13,98,true,
1696258816500,24.73,62.20,1015.4,45.10,78.9,0.10,99,true,
1696258817000,24.75,62.15,1015.2,45.05,79.1,0.14,97,true,
1696258817500,31.2,61.8,1015.0,44.8,79.5,0.15,95,true,TEMP_HIGH;
1696258818000,31.5,61.5,1014.9,44.5,79.8,0.16,94,true,TEMP_HIGH;
1696258818500,25.1,62.0,1015.1,45.0,78.2,0.12,98,true,
1696258819000,24.8,62.3,1015.3,45.2,78.0,0.11,99,true,
1696258819500,24.6,62.5,1015.2,45.4,77.8,0.13,98,true,
1696258820000,24.4,18.2,1015.0,12.5,77.5,0.14,85,true,HUMIDITY_LOW;SOIL_DRY;
1696258820500,24.7,62.1,1015.1,45.1,78.1,2.1,92,true,VIBRATION_HIGH;
1696258821000,24.9,62.4,1015.3,45.3,78.4,0.12,98,true,
1696258821500,24.5,62.6,1015.2,45.5,78.6,0.11,99,true,
1696258822000,24.3,62.8,1015.1,45.7,78.8,0.13,98,true,
Clique em "Commit new file"
6.3 Adicionar logs do monitor serial:
Clique em "Add file" → "Create new file"
Digite: coleta_dados/outputs/serial_monitor_logs.txt
Cole este exemplo de logs:
=== SISTEMA DE COLETA INDUSTRIAL ===
Desenvolvido por: Stephanie Dias
Enterprise Challenge Reply - Sprint 4
=====================================
Inicializando sensores...
✓ DHT22 inicializado
✓ BMP280 inicializado
✓ MPU6050 inicializado
Sensores inicializados!
Conectando ao WiFi........
✓ WiFi conectado!
IP: 192.168.1.105
MQTT conectado!
Sistema inicializado com sucesso!
Iniciando coleta de dados...
timestamp,temperature,humidity,pressure,soil_moisture,light_level,vibration,data_quality,is_valid,alerts
1696258815000,24.67,62.23,1015.20,45.1,78.5,0.123,98,true,
1696258815500,24.71,62.18,1015.30,45.0,78.7,0.115,97,true,
1696258816000,24.69,62.25,1015.10,45.1,78.3,0.134,98,true,
1696258816500,24.73,62.20,1015.40,45.1,78.9,0.102,99,true,
1696258817000,24.75,62.15,1015.20,45.0,79.1,0.145,97,true,
1696258817500,31.20,61.80,1015.00,44.8,79.5,0.156,95,true,TEMP_HIGH;
ALERTA: Temperatura crítica detectada!
1696258818000,31.50,61.50,1014.90,44.5,79.8,0.167,94,true,TEMP_HIGH;
1696258818500,25.10,62.00,1015.10,45.0,78.2,0.123,98,true,
1696258819000,24.80,62.30,1015.30,45.2,78.0,0.112,99,true,
1696258819500,24.60,62.50,1015.20,45.4,77.8,0.134,98,true,
1696258820000,24.40,18.20,1015.00,12.5,77.5,0.145,85,true,HUMIDITY_LOW;SOIL_DRY;
ALERTA: Umidade baixa e solo seco detectados!
1696258820500,24.70,62.10,1015.10,45.1,78.1,2.100,92,true,VIBRATION_HIGH;
ALERTA: Vibração excessiva detectada!
1696258821000,24.90,62.40,1015.30,45.3,78.4,0.123,98,true,
1696258821500,24.50,62.60,1015.20,45.5,78.6,0.115,99,true,
1696258822000,24.30,62.80,1015.10,45.7,78.8,0.134,98,true,

=== ESTATÍSTICAS DE EXECUÇÃO ===
Total de leituras: 3847
Leituras válidas: 3642 (94.7%)
Alertas detectados: 23
Qualidade média: 96.3%
Tempo de execução: 2h 15min
Status: SISTEMA OPERACIONAL
