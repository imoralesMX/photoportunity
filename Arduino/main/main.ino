// Pin de salida para la luz de neon del angel
int NEON_ANGEL = 12;

// Pin de salida para la luz de neon del diablo
int NEON_DIABLO = 13;

// Pin de entrada para el push button
int PUSH_BUTTON = 2;

// Numero de veces que se va apagar y encender de manera alternada el angel y el diablo
int INITIAL_ANIMATION = 20;

// Retardo entre cada vez que se apaga y prende el angel y el diablo
int INITIAL_ANIMATION_DELAY = 200;

// Bandera para saber si la animacion de generacion de numero aleatorio se esta ejecutando
bool generating = false;

// Numero aleatorio generado
long randNumber;

// Valores por default de las variables
int animation = 0;
int animationDelay = INITIAL_ANIMATION_DELAY;

void setup() {
  // Configuracion de puertos de entrada y salida
  pinMode(NEON_ANGEL, OUTPUT);
  pinMode(NEON_DIABLO, OUTPUT);
  pinMode(PUSH_BUTTON, INPUT);

  // Configuracion de generador de numeros aleatorio, tomando como semilla de generaion el valor que lea del puerto 0
  randomSeed(analogRead(0));

  // Al encender los luces neon estan apagadas
  digitalWrite(NEON_ANGEL, LOW);
  digitalWrite(NEON_DIABLO, LOW);
}

void loop() {
  // Si la animacion no se esta mostrando
  if(!generating){
    // Leer el estado del boton
    int buttonState = digitalRead(PUSH_BUTTON);

    // Si el boton de oprimio
    if(buttonState == HIGH){
      // Activar bandera de inicio de animacion
      generating = true;

      // Obtener un numero aleatorio entre 0 y 1
      randNumber = random(2);

      // Configurar variables de animacion
      animation = INITIAL_ANIMATION;
      animationDelay = INITIAL_ANIMATION_DELAY;

      // Apagar luces neon
      digitalWrite(NEON_ANGEL, LOW);
      digitalWrite(NEON_DIABLO, LOW);
    }
  }
  // Se muestra la animacion
  else{
    if(animation > 0){
      // Repetir mientras se tengan que mostrar animaciones de encendido y apagado
      while(animation > 0){
        // Encender angel
        digitalWrite(NEON_ANGEL, HIGH);
        digitalWrite(NEON_DIABLO, LOW);
  
        // Esperar el tiempo de la animacion
        delay(animationDelay);
  
        // Encender diablo
        digitalWrite(NEON_ANGEL, LOW);
        digitalWrite(NEON_DIABLO, HIGH);
  
        // Esperar animacion
        delay(animationDelay);
  
        // Eliminar una animacion del total de animaciones a mostar
        animation--;
  
        // Incrementar el tiempo entre que se apaga y prende angel y diablo
        animationDelay+=50;
      }
  
      // Cuando se termina la animacion
  
      // Si el numero aleatorio es 0 encender Angel
      if(randNumber==0){
        digitalWrite(NEON_ANGEL, HIGH);
        digitalWrite(NEON_DIABLO, LOW);
      }
      // Si el numero aleatorio es 1 encender Diablo
      else{
        digitalWrite(NEON_ANGEL, LOW);
        digitalWrite(NEON_DIABLO, HIGH);
      }
  
      // Apagar bandera de animacion
      generating = false;
    }
  }
}
