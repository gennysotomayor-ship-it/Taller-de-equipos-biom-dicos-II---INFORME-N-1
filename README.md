# TEB2 LABORATORIO N°1 - Generación y calibración de señal analógica con ESP32

Repositorio del Laboratorio 1 del curso de Taller de Equipos Biomédicos II, en el cual se generó y calibró una señal analógica con el ESP32, comparando el DAC por hardware frente a una salida PWM acondicionada con un filtro RC pasabajos.

## Objetivo

- Programar un voltaje específico en la salida DAC del ESP32 (GPIO25) y verificar, con el osciloscopio y el multímetro, si el valor real coincide con el programado.
- Generar el mismo voltaje por modulación de ancho de pulso (PWM, GPIO27) y diseñar el filtro RC pasabajos necesario para reconstruirlo como una señal continua.
- Determinar experimentalmente el error y la resolución efectiva de cada uno de los dos métodos de salida.
- Construir la curva de calibración voltaje programado – voltaje medido, para el DAC y para el PWM filtrado.

## Cómo reproducir el experimento

1. Cargue el archivo de código `.ino` en el ESP32 usando el IDE de Arduino (board: "ESP32 Dev Module").
2. Arme el circuito siguiendo el esquemático:
   - **Etapa 1:** GPIO25 (DAC) y GPIO27 (PWM) del ESP32 conectados directamente al osciloscopio/multímetro, sin componentes adicionales.
   - **Etapas 2 y 3:** filtro RC pasabajos (R = 120 kΩ, C = 0.1 µF, fc ≈ 13.26 Hz) entre la salida PWM (GPIO27) y el nodo de medición.
3. Abra el Monitor Serial (115200 baudios) e ingrese un valor de voltaje objetivo entre 0.0 y 3.3 V.
4. Mida el voltaje en cada nodo (DAC y PWM filtrado) con el multímetro y el osciloscopio, para los puntos 0.5, 1.0, 1.5, 2.0, 2.5 y 3.0 V, y registre los valores.

## Autores

- Tito Fernández, Dante Adrián
- Lázaro Canales, Jair Renato
- Arroyo Ramos, Rosbeth Nayelhy
- Sotomayor Villanueva, Genny Solangch
