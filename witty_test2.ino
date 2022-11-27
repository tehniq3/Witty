// intial sketch from https://github.com/amkuipers/witty
// other info from https://protosupplies.com/product/esp8266-witty-cloud-esp-12f-wifi-module/
// original implementation of Nicu FLORICA (niq_ro)


const int LDR = A0;
const int BUTTON = 4;
const int RED = 15;
const int GREEN = 12;
const int BLUE = 13;

int intensitate;
int culoare = 8;  // er = 1, ge = 1, be = 1
int er, ge, be;

void setup() 
{
    Serial.begin(115200);

    pinMode(LDR, INPUT);
    pinMode(BUTTON, INPUT);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

 er = culoare / 4;
    ge = (culoare % 4 ) / 2;
    be = (culoare % 4 ) % 2;    

}

void loop()
{
  int btn_Status = HIGH;  // define status of button
  
    intensitate = analogRead(LDR);
 
    btn_Status = digitalRead (BUTTON);  // Check status of button
    
  if (btn_Status == LOW) // Button pushed, so do something
   {                
    culoare = culoare + 1;
    if (culoare > 8) culoare = 1;
    er = culoare / 4;
    ge = (culoare % 4 ) / 2;
    be = (culoare % 4 ) % 2;    
    Serial.print("Colour: ");
    Serial.println(culoare);
    Serial.print(" -> R = ");
    Serial.print(er); 
    Serial.print(" -> G = ");
    Serial.print(ge);     
    Serial.print(" -> B = ");
    Serial.print(be); 
    Serial.println("  !");   
    delay(500);
   }

    Serial.print("Brightness: ");
    Serial.println(intensitate);

    analogWrite(RED, er * intensitate);
    analogWrite(GREEN, ge * intensitate);
    analogWrite(BLUE, be * intensitate);

  delay(100);
}  // end main loop
