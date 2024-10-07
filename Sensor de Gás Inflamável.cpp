#define PinSensor A0 // Entrada analógica do Arduino conectado ao sensor
#define PinLedVermelho 13 // Entrada digital do Arduino conectado ao LED vermelho
#define PinLedVerde 12 // Entrada digital do Arduino conectado ao LED verde

int valorLeituraSensor; // Variável que irá armazenar os valores de leitura do sensor 

void setup() {
  Serial.begin(9600); // Inicialização da comunicação serial
  pinMode(PinSensor, INPUT); // Declara o pino do sensor como pino de entrada
  pinMode(PinLedVermelho, OUTPUT); // Declara o pino do LED vermelho como pino de saída
  pinMode(PinLedVerde, OUTPUT); // Declara o pino do LED verde como pino de saída
}

void loop() {
  valorLeituraSensor = analogRead(PinSensor); // Leitura de dados do sensor
  Serial.print("Valor detectado pelo sensor: "); // Imprime a mensagem no monitor serial
  Serial.println(valorLeituraSensor); // Imprime valores de leitura encontrados no monitor serial
  
  // Verifique se o valor de leitura é maior ou igual a 320
  if (valorLeituraSensor >= 320) { // Se o valor de leitura analógica for maior ou igual a 320
    Serial.println("Fumaça/gás detectado"); // Imprime a mensagem no monitor serial
    digitalWrite(PinLedVerde, LOW); // Desliga o LED verde
    digitalWrite(PinLedVermelho, HIGH); // Liga o LED vermelho
  } else {
    Serial.println("Fumaça/gás não detectado"); // Imprime a mensagem no monitor serial
    digitalWrite(PinLedVerde, HIGH); // Liga o LED verde
    digitalWrite(PinLedVermelho, LOW); // Desliga o LED vermelho
  }

  delay(5000); // Repete a leitura a cada 5 segundos
}