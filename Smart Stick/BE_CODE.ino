#define echoPin 7 // Echo Pin
#define trigPin 6// Trigger Pin
#define LEDPin 13// Onboard LED
#define key A0
#define buzzer 8
#define pot A5
#define LDR A4
#define d1 9
#define d2 10
#define water1  A1
#define water2  A2
#define water3  A3


long duration, distance; // Duration used to calculate distance
int key2,x =0,d22,d11,rf_sense=0,ldr_sense=0,ultra_sense=0,water_sense=0,ss=0;
int sensorVal = 0,maxVal=0,sensorVal2 = 0,maxVal2=0,sensorVal3 = 0,maxVal3=0,sensorVal4 = 0,maxVal4=0,sensorVal5 = 0,maxVal5=0,pwmVal = 0;

void setup()
{
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(LEDPin, OUTPUT);

pinMode(key, INPUT);
pinMode(echoPin, INPUT);
pinMode(pot, INPUT);
pinMode(LDR, INPUT);
pinMode(d1, INPUT);
pinMode(d2, INPUT);
pinMode(water1, INPUT);
pinMode(water2, INPUT);
pinMode(water3, INPUT);
digitalWrite(buzzer,LOW);
}

void loop()
{
ultrasonic();
ldr();
rf();
watersens();
buzzer_led();
key2=digitalRead(key);
if(key2==LOW && x==1)
{

x=0;
}
else if(key2==LOW && x==0)
{
x=1;
}
}

void ultrasonic()
{
/* The following trigPin/echoPin cycle is used to determine the
distance of the nearest object by bouncing soundwaves off of it. */
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
sensorVal = analogRead(pot);
// Serial.println(sensorVal);
maxVal = map(sensorVal, 0, 1023, 0, 25);
//Calculate the distance (in cm) based on the speed of sound.
distance = duration/58.2;
// Serial.println(distance);
if(distance<=maxVal)
{
ultra_sense=1;
}
else
{
ultra_sense=0;
}
}


void ldr()
{
if(x==1)
{
sensorVal2 = analogRead(LDR);
maxVal2 = map(sensorVal2, 0, 1023, 0, 255);
Serial.println(maxVal2);
if(maxVal2<=1)
{
ldr_sense=1;
}
else
{
ldr_sense=0;
}
}
}

void rf()
{
d11=digitalRead(d1);

if(d11==LOW)
{
rf_sense=1;
}
d22=digitalRead(d2);

if(digitalRead(d2)==LOW)
{
rf_sense=0;
}
}

void watersens()
{
sensorVal3 = analogRead(water1);
maxVal3 = map(sensorVal3, 0, 1023, 0, 255);

sensorVal4 = analogRead(water2);
maxVal4 = map(sensorVal4, 0, 1023, 0, 255);

sensorVal5 = analogRead(water3);
maxVal5 = map(sensorVal5, 0, 1023, 0, 255);

if(maxVal3>=180 || maxVal4>=180 || maxVal5>=180)
{
water_sense=1;
}

else if(maxVal3<=180 && maxVal4<=180 && maxVal5<=180)
{
water_sense=0;
}

}

void buzzer_led()
{//analogWrite(buzzer,0);
if(water_sense==1)
{
for(int i=0;i<1000;i++)
{
digitalWrite(buzzer,HIGH);
digitalWrite(LEDPin,HIGH);
delayMicroseconds(100);
digitalWrite(buzzer,LOW);
digitalWrite(LEDPin,LOW);
delayMicroseconds(100);
}
}
if(rf_sense==1)
{
pwmVal=0;
analogWrite(LEDPin,250);
analogWrite(buzzer,250);
delay(100);
}
else if(ldr_sense==1)
{

for(int i=0;i<1000;i++)
{
digitalWrite(buzzer,HIGH);
digitalWrite(LEDPin,HIGH);
delayMicroseconds(150);
digitalWrite(buzzer,LOW);
digitalWrite(LEDPin,LOW);
delayMicroseconds(150);
}
}
else if(ultra_sense==1)
{

analogWrite(LEDPin,250);
analogWrite(buzzer,250);
delay(1000);
analogWrite(LEDPin,0);
analogWrite(buzzer,0);
delay(500);

}
else if ( ldr_sense==0 && ultra_sense==0 && rf_sense==0 && water_sense==0)

{
pwmVal=0;
digitalWrite(buzzer,LOW);
digitalWrite(LEDPin,LOW);
delay(10);
}

}
