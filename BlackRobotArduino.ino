#define OUT6 6
#define OUT7 7
#define OUT8 8
#define OUT9 9
#define OUT10 10
#define OUT11 11
#define NUMCOMANDOS 7;

// Instrucciones permitidas: STOP, ADELANTE, ATRAS, IZQUIERDA, DERECHA, CLAXON Y LUCES
String comandos[] = {"ST", "AD", "AT", "IZ", "DE", "CL", "LU"};

void setup() {
  Serial.begin(57600);
  pinMode(LED_BUILTIN, OUTPUT);  
  pinMode(OUT6, OUTPUT);
  pinMode(OUT7, OUTPUT);
  pinMode(OUT8, OUTPUT);
  pinMode(OUT9, OUTPUT);
  pinMode(OUT10, OUTPUT);
  pinMode(OUT11, OUTPUT);
  digitalWrite(OUT6, LOW);
  digitalWrite(OUT7, LOW);
  digitalWrite(OUT8, LOW); 
  digitalWrite(OUT9, LOW);
  digitalWrite(OUT10, LOW);
  digitalWrite(OUT11, LOW);
  
  // Indicador visual de OK
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
}



void loop() {
  String msg;
  String comando;
  int accion; 
  byte val;

  if (Serial.available()) {
   msg=Serial.readString();  
   comando = msg.substring(0,2);
   comando.toUpperCase(); 
   accion = msg.substring(2).toInt(); // 0 apagar 1 encender 
   
   Serial.println(comando);
   Serial.println(accion);

    if (comandoValido(comando)) {
      if (comando.equals("ST")) motoresFrenar();
      if (comando.equals("AD")) motoresAdelante(0);
      if (comando.equals("AT")) motoresAtras(0);
      if (comando.equals("IZ")) motoresIzquierda(0);
      if (comando.equals("DE")) motoresDerecha(0);
      if (comando.equals("CL")) claxon();
      if (comando.equals("LU")) { 
        if (accion==1) 
          luzON(); 
        else 
          luzOFF(); } 
      }
   }  
}

bool comandoValido(String comando) {  
  int i;
  for (i=0;i<7;i++) {
      if (comando.equals(comandos[i]))
      return true; 
  }
  return false;
}

void motoresAdelante(int motorSpeed) { 
  //analogWrite(ENA, motorSpeed);
  //analogWrite(ENB, motorSpeed);
  digitalWrite(OUT8, HIGH);
  digitalWrite(OUT9, LOW); 
  digitalWrite(OUT10, LOW);
  digitalWrite(OUT11, HIGH);  
}
 
void motoresAtras(int motorSpeed) {
  //analogWrite(ENA, motorSpeed);
  //analogWrite(ENB, motorSpeed);
  digitalWrite(OUT8, LOW);
  digitalWrite(OUT9, HIGH);  
  digitalWrite(OUT10, HIGH);
  digitalWrite(OUT11, LOW);      
}

void motoresIzquierda(int motorSpeed) { 
  //analogWrite(ENA, motorSpeed);
  //analogWrite(ENB, motorSpeed);
  digitalWrite(OUT8, HIGH);
  digitalWrite(OUT9, LOW); 
  digitalWrite(OUT10, HIGH);
  digitalWrite(OUT11, LOW);  
}

void motoresDerecha(int motorSpeed) { 
  //analogWrite(ENA, motorSpeed);  
  //analogWrite(ENB, motorSpeed);
  digitalWrite(OUT8, LOW);
  digitalWrite(OUT9, HIGH);  
  digitalWrite(OUT10, LOW);
  digitalWrite(OUT11, HIGH);  
}

void motoresFrenar () {
  //digitalWrite(ENA, LOW);
  //digitalWrite(ENB, LOW);
  digitalWrite(OUT8, LOW);
  digitalWrite(OUT9, LOW);   
  digitalWrite(OUT10, LOW);
  digitalWrite(OUT11, LOW);   
}

void luzON() {  
  digitalWrite(OUT6, HIGH);
}

void luzOFF() { 
  digitalWrite(OUT6, LOW);
}

void claxon() {
  digitalWrite(OUT7, HIGH);
  delay(50);
  digitalWrite(OUT7,LOW);
}
