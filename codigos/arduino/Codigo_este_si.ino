// C++ code
//
#include <SoftwareSerial.h>
SoftwareSerial SerialBT(3,2); //RX TX
char state;

//Ruedas derechas
int RD1 = 11; //delante
int RD2 = 12; //atras
//Ruedas izquierdas
int RI1 = 8; //delante
int RI2 = 10; //atras
//Taladro
int M1 = 4; // +
int M2 = 5 ; // -

String lectura;


void setup()
{
  
  pinMode(RD1, OUTPUT);
  pinMode(RD2, OUTPUT);
  pinMode(RI1, OUTPUT);
  pinMode(RI2, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  digitalWrite(RD1, LOW);
  digitalWrite(RD2, LOW);
  digitalWrite(RI1, LOW);
  digitalWrite(RI2, LOW);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  Serial.begin(9600);
  SerialBT.begin(9600);
}
 //GIRA ctm GIRA
void GIRAR(){
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
    
}

void APAGATETALADRO(){
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  
}
// RUEDAS LADO DERECHO AVANZA
void RD_avanza( ){
  digitalWrite(RD1, HIGH);
  digitalWrite(RD2, LOW);
    
  
}
// RUEDAS LADO DERECHO RETROCEDE
void RD_retrocede(){
  digitalWrite(RD2, HIGH);
  digitalWrite(RD1, LOW);
    
  
}
//RUEDA LADO IZQ AVANZA
void RI_avanza(){
  digitalWrite(RI1, HIGH);
  digitalWrite(RI2, LOW);
    
  
}
//RUEDA LADO IZQ RETROCEDE
void RI_retrocede(){
  digitalWrite(RI2, HIGH);
  digitalWrite(RI1, LOW);
    
  
}



void avanzar(){
  RD_avanza();
  RI_avanza();
  
 }

void retroceder(){
  RD_retrocede();
  RI_retrocede();
  
 }
// HORARIO
void dobla_derecha(){
  RI_avanza();
  RD_retrocede();
  
}
//ANTIHORARIO
void dobla_izquierda(){
  RD_avanza();
  RI_retrocede();
  
 
}


//PARA

void para(){
  
  digitalWrite(RD1, LOW);
  digitalWrite(RD2, LOW);

  digitalWrite(RI1, LOW);
  digitalWrite(RI2, LOW);

  
}
void leerSerial()
{ 
  SerialBT.listen();
  if(SerialBT.available()>0){
    state = SerialBT.read();
    Serial.println(state);
    if ( state == 'u'){ //arriba
       avanzar();
    }
    else if (state == 'd'){ //abajo
       retroceder();
    }
    else if (state == 's'){ //parar
       para();
    }
    else if (state == 'r'){ //derecha
       dobla_derecha();
    }
    else if (state == 'l'){ // izquierda
       dobla_izquierda();
    }
    else if (state == '1'){
      GIRAR();
       
    }
    else if (state == '0'){
      APAGATETALADRO();
    }
      
  }
  /*
  if (Serial.available()) { 
    String lectura = Serial.readStringUntil('\n');
      if (lectura == "u"){
        avanzar();
      }
      else if (lectura == "d"){
        retroceder();
      }
      else if (lectura == "s"){
        para();
      }
      else if (lectura == "r"){
        dobla_derecha();
      }
      else if (lectura == "l"){
        dobla_izquierda();
      }
      
  }
  
    */
}
void loop(){
  leerSerial();
}
