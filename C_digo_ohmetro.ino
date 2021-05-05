int PinA0 = 0;  
int lectura = 0;
int Ve = 5; // Tensión en el Arduino.
float VR2 = 0;
float R1 = 10000;
float R2 = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    lectura = analogRead(PinA0);
    if (lectura)
    {
        VR2 = (lectura * Ve) / 1024.0;
        R2 = R1 * (Ve / VR2) - 1;
        Serial.print("VR2: ");
        Serial.println(VR2);
        Serial.print("R2: ");
        Serial.println(R2);
        Serial.print("Ω");
        delay(1000);
    }
}
