//Roberto Vázquez Magdaleno y Gema Sánchez Sánchez
#define Sensibilidad 0.185; //sensibilidad en Voltios/Amperio para sensor de 5A
//ESCALAS 200uA; 2mA; 20mA; 200mA; 10A;

//Varios pulsadores para elegir lo que se mide
int boton_mv=3;
int boton_mi=4;
int boton_mr=5;
//para mentener el estado
bool estado1 = false;
bool estado2 = false;
bool estado3 = false;

void mode(void);
void medir_corriente(float);

void setup()
{
  pinMode(boton_mv,INPUT);
  pinMode(boton_mi,INPUT);
  pinMode(boton_mr,INPUT);
      
  Serial.begin(9600);
}

void loop() 
{
  mode();
}

void mode()
{
  float voltajeSensor;

  voltajeSensor = analogRead(A0) * (5.0 / 1023.0);
  
  if (digitalRead(boton_mv)==HIGH)
  {
    estado1 = !estado1;
    estado2 = false;
    estado3 = false;
    if(estado1==true)
    {
      //funcion de voltaje
      //pantalla lcd
    }
  }
  if (digitalRead(boton_mi)==HIGH)
  {
    estado2 = !estado2;
    estado1 = false;
    estado3 = false;
    if(estado2==true)
    {
      medir_corriente(voltajeSensor);
      //Mostrar en pantalla lcd
    }
  }
  if (digitalRead(boton_mr)==HIGH)
  {
    estado3 = !estado3;
    estado1 = false;
    estado2 = false;
    if(estado3==true)
    {
      //funcion de resistencia
    }
  }
}

void medir_corriente(float v)
{
  float corriente;

  corriente=(v-2.5)/Sensibilidad;

  Serial.print("Corriente: ");
  Serial.println(corriente);
  
  delay(200);  
}
