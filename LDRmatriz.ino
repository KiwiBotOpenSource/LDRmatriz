//74HC595 controla la matriz led
int pinLatch = 6;    //Pin para el latch de los 74CH495
int pinDatos = 5;    //Pin para Datos serie del 74CH495
int pinReloj = 9;     //Pin para reloj del 74CH495

//Variables para leer el Sensor de temperatura
int ldrPin=A0;
long ldrValue=0;

byte columna[7]= {
  B1000000, B0100000, B0010000, B0001000, B0000100, B0000010, B0000001};

byte fila[7]= {
  B1111110, B1111100, B1111100, B1111000, B1111000, B1110000, B1100000};

void setup(){
  pinMode(pinLatch,OUTPUT);
  pinMode(pinDatos,OUTPUT);
  pinMode(pinReloj,OUTPUT);
}

void loop(){
  ldrValue=analogRead(ldrPin)/145;
  for(int i=0; i<ldrValue; i++){
    digitalWrite(pinLatch, LOW);
    shiftOut(pinDatos, pinReloj, MSBFIRST, fila[i]); 
    shiftOut(pinDatos, pinReloj, MSBFIRST, columna[i]);
    digitalWrite(pinLatch, HIGH);
  }
}


