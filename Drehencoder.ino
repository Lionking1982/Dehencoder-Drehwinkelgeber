#define PinA 22
#define PinB 23
#define Speed 20
int zuvor,PIN,neu, FF, FR;
unsigned long Timer;


void setup() {

pinMode(PinA,INPUT);
pinMode(PinB,INPUT);

Serial.begin(9600);
Timer = millis();

}

void loop() {

PIN = digitalRead(PinA);

if(((millis() - Timer)> 2)&& (PIN != zuvor)){
Timer = millis();
zuvor = PIN;
neu = 1;
}

if(((millis() - Timer)> 2)&& ( neu == 1)){
  if(digitalRead(PinB) == zuvor){
    Serial.println("Rechts");
  }
if(digitalRead(PinB) != zuvor){
    Serial.println("Links");
  }
  neu = 0;
}
}
