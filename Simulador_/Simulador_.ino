// Pines de salida
const int pinDAC = 25;  // GPIO25 = salida DAC
const int pinPWM = 27;  // GPIO27 = salida PWM

// Configuración PWM
const int frecuenciaPWM = 5000;  // 5000 Hz
const int resolucion = 8;        // 8 bits: 0-255

void setup() {
  // Inicializar comunicación serie
  Serial.begin(115200);

  // Configurar PWM en GPIO27
  ledcAttach(pinPWM, frecuenciaPWM, resolucion);

  // Mensaje inicial
  Serial.println("=== LABORATORIO 1: DAC vs PWM en ESP32 ===");
  Serial.println("Ingrese un voltaje objetivo entre 0.0 y 3.3 V:");
}

void loop() {

  if (Serial.available() > 0) {

    // Leer voltaje ingresado
    float voltajeObjetivo = Serial.parseFloat();

    // Limpiar buffer serial
    while (Serial.available() > 0) {
      Serial.read();
    }

    // Limitar voltaje entre 0 y 3.3 V
    if (voltajeObjetivo < 0.0) {
      voltajeObjetivo = 0.0;
    }

    if (voltajeObjetivo > 3.3) {
      voltajeObjetivo = 3.3;
    }

    // Convertir voltaje a código de 8 bits
    int codigo8bits = (int)((voltajeObjetivo / 3.3) * 255.0);

    // Salida DAC en GPIO25
    dacWrite(pinDAC, codigo8bits);

    // Salida PWM en GPIO27
    ledcWrite(pinPWM, codigo8bits);

    // Mostrar información
    Serial.print("Voltaje Programado: ");
    Serial.print(voltajeObjetivo, 2);
    Serial.print(" V | ");

    Serial.print("Código 8-bits: ");
    Serial.print(codigo8bits);
    Serial.print(" | ");

    Serial.print("PWM Duty Cycle: ");
    Serial.print((codigo8bits / 255.0) * 100.0, 1);
    Serial.println(" %");
  }
}