# LINX-Arduino-ADC-Overclock
Optimización de bajo nivel para el conversor analógico-digital (ADC) del ATmega328P, encontrado en el Arduino UNO. Diseñada para romper las limitaciones de velocidad estándar del toolkit MakerHub LINX en LabVIEW.

## El Problema
Por defecto, el firmware de LINX utiliza un prescaler de 128 para el reloj del ADC, priorizando la resolución sobre la velocidad. Esto impide capturar señales de audio o vibraciones de alta frecuencia con fidelidad.

## La Solución
Modificamos el registro `ADCSRA` directamente en el firmware de Arduino para establecer un prescaler de **16**.
Por qué paramos en 16: Aunque existen prescalers de 8, 4 y 2, la circuitería del ADC del ATmega328P no puede cargar el condensador de muestreo lo suficientemente rápido. A partir de 16 (reloj de 1 MHz), la resolución de 10 bits empieza a degradarse significativamente.

