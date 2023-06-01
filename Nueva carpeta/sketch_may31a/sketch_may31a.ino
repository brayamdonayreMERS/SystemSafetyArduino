//Primera practica para sistema de seguridad con arduino
//Asignamos variales para los nuevos pin 
int trig=2;
int echo=3;
int distancia;
int tiempo;
int pir=4;
int motor=5;
int valorLDR=0;
int pinLDR=A0;
void setup()
{

  Serial.begin(9600); //Visualizacion de los valores por consola
  //Determinados el tipo de la variable que será, si recibirán la información (INPUT) o si enviarán información(OUTPUT)
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pir, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(pinLDR, INPUT);
}

void loop()
{
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  //Asignamos la la variable tiempo en la libreria pulseIn, esto hará que 
  tiempo=pulseIn(echo, HIGH);
  //Dividimos entre 58.2, puesto que el tiempo que transcurre en rebotar la onda recorre dos veces la distancia que está el sensor y el objeto y el numero 58.2 para que nos den en centimetros ya que una pulgada equivale a 29.1 cm  
  distancia=tiempo/58.2;
  Serial.println(distancia); //Imprimimos la variable distancia
  delay(500);
    if (distancia<=150)  //Si la distancia es menor o igual a 150
    {
       digitalWrite(motor,HIGH);                //Entonces el motor se encenderá
       digitalWrite(6,LOW);                     // Valor 0
       digitalWrite(7,HIGH);                    // valor 1
       Serial.println("!INTRUSOS POR SONIDO!"); //Inmediatamente se imprimirá que hay intrusos
       delay(2000);
       
      
     }
     else                           //Si la distancia respecto al sensor es mayor a 150
     {
      digitalWrite(motor,LOW);      //Entonces el motor se apagará
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      Serial.println("!NO HAY INTRUSOS POR SONIDO!"); //Se imprime en la pantalla que no hay intrusos
     }
  digitalRead(pir);         // Se lee los valores del sensor PIR
    if (digitalRead(pir)==HIGH) // Si los valores del PIR es 1==HIGH 
    {
      digitalWrite(motor,HIGH); // Entonces el motor se prende
      digitalWrite(6,LOW);
      digitalWrite(7,HIGH);
      Serial.println("!INTRUSOS POR PIR!"); //Inmediatamente se imprimirá que hay intrusos
    }
    else // Si los valores del PIR es 0==HIGH 
    {
      digitalWrite(motor,LOW);//Entonces el motor se apagará
      Serial.println("!NO HAY INTRUSOS POR PIR!");//Se imprime en la pantalla que no hay intrusos
    }
  valorLDR=analogRead(pinLDR); // Se lee los valores de la fotorresistencia
  delay(10);
   if (valorLDR<600) //Si el valor de la fotorresistencia es menor a 600 
   {
    digitalWrite(motor,HIGH); //Entonce el motor se prende
     digitalWrite(6,LOW);
     digitalWrite(7,HIGH);
     Serial.println("!INTRUSOS POR LDR!"); //Inmediatamente se imprimirá que hay intrusos
   }
   else    //Si el valor de la fotorresistencia es mayor a 600 
   {
     digitalWrite(motor,LOW);//Entonces el motor se apagará
     Serial.println("!NO HAY INTRUSOS POR LDR!");//Se imprime en la pantalla que no hay intrusos
   }
}
