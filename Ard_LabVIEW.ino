#include <SPI.h>
#include <Wire.h>
#include <LinxArduinoUno.h>
#include <LinxSerialListener.h>

// Objetos globales para la comunicación
LinxArduinoUno* LinxDevice;
LinxSerialListener* LinxListener;

void setup() 
{
  // Inicialización de objetos
  LinxDevice = new LinxArduinoUno();
  LinxListener = new LinxSerialListener();

  // Inicio de comunicación serial (115200 bps)
  LinxListener->Start(LinxDevice, 0);

  // ADC: Prescaler a 16
  // Esto eleva la frecuencia de muestreo de ~9.6kHz a ~76.9kHz
  //Valores Prescaler
  //Prescaler: 0x07=128 (9.6kHz), 0x06=64 (19.2kHz), 0x05=32 (38.4kHz), 0x04=16 (76.9kHz)
  // LabVIEW podrá leer mucho más rápido mediante Analog Read
ADCSRA = (ADCSRA & 0xf8) | 0x04;
}

void loop() 
{
  // Escucha de comandos estándar de LINX
  LinxListener->CheckForCommands();
}