/*  DISPENSER ALCOHOL EN GEL V1     2/8/2020 
  
    AL SENSAR LA MANO SE EXPENDE ALCOHOL DURANTE CIERTO TIEMPO,
    Y SE ESPERA A QUE SE ALEJE LA MANO PARA VOLVER A EXPENDER
    
    OPCIONAL:TEMPORIZADOR DE PARPADEO DE LED,
    MIENTRAS SE ESPERA QUE LA MANO SE ALEJE(DESPUES DE 60 SEG)    

    SENSOR INFRARROJO TIPO FC-51
    HIGH(NO ACTIVIDAD)
    LOW(ACTIVIDAD SENSADA)
  
  ACCIONAMIENTO DE MINI BOMBA 12V MEDIANTE RELAY O TRANSISTOR
  
*/

//DECLARACION DE VARIABLES
 
int in_sensorIR = 3;        //PIN DE ENTRADA/ARDUINO CORRESPONDIENTE AL SENSOR IR
int relay = 4;        //PIN DE SALIDA/ARDUINO CORRESPONDIENTE AL RELAY/ACTUADOR BOMBA
int led = 5;        //PIN DE LED INDICADOR/ALARMA?

int delay_preventivo = 20;    //delay preventivo,falso accionamiento de sensor IR
int tiempo_accionamiento = 3000;    //tiempo de expendio de alcohol/accionamiento de minibomba 
int contador_alarma = 600;    //contador para accionar evento "alarma"?R

//FIN DE DECLARACION DE VARIABLES 


//----------------------- SECCION CONFIGURACION--------------------------------------

void setup() {  

    pinMode(in_sensorIR,INPUT);           //CONFIGURANDO PUERTO DE ENTRADA CORRESPONDIENTE A SENSOR IR
    pinMode(relay,OUTPUT);          //CONFIGURANDO PUERTO DE SALIDA CORRESPONDIENTE A REALAY DE BOMBA
    pinMode(led,OUTPUT);

    digitalWrite(led,HIGH);     //LED INDICADOR ACTIVIDAD/POWER                          
    digitalWrite(relay,LOW);    //BOMBA EN ESTADO CERO(LOW) /DESACTIVADA

}//-----------------------FIN SECCION CONFIGURACION----------------------------------


//-------------------------PROGRAMA PRINCIPAL----------------------------------------
void loop() {

  if(in_sensorIR==LOW){             //SENSOR IR ACCIONADO?     
      
    delay(delay_preventivo);                      //SI,SENSOR ACCIONADO-->DELAY PREVENTIVO(FALSO ACCIONAMIENTO)
    
    if(in_sensorIR==LOW){           //SIGUE EL SENSOR ACCIONADO?

      digitalWrite(relay,HIGH);     //ACCIONAMINETO DEL RELAY/BOMBA
      delay(tiempo_accionamiento);    //tiempo de expendio de alcohol minimo
      digitalWrite(relay,LOW);
     
      }//FALSO DISPARO DEL SENSOR IR
   }//SENSOR IR NO ACCIONADO


  while(in_sensorIR==LOW){          //ESPERANDO QUE EL SENSOR IR SE DEJE DE ACCIONAR EN CASO DE QUE SIGA ACCIONADO
        
    delay(100);        
    contador_alarma--;    //contador_alarma=contador_alarma-1;
  
    if(contador_alarma == 0){
      digitalWrite(led,LOW);
      delay(100);           
      digitalWrite(led,HIGH);
    }

  }//---------fin del while----


}//--------------------FIN LOOP

//---------------------FIN PROGRAMA PRINCIPAL------------------------------------------
