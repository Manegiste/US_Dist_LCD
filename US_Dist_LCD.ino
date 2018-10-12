#define US_TRIG 2
#define US_ECHO 3

int US_Measure()
{
  long duration;
  long distance;

  Serial.println ("Mesure =============");
  // Clears the trigPin
  digitalWrite(US_TRIG, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(US_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIG, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(US_ECHO, HIGH);

  Serial.println (duration);
  
  // Calculating the distance
  distance = duration * 0.034 / 2;

  return distance;
}
void setup() {



  // Ultrasound: send on 0, get feedback on 1
  pinMode(US_TRIG, OUTPUT);
  pinMode(US_ECHO, INPUT);

  Serial.begin(9600);
  Serial.print ("************************************* Go ! Go ! Go !");


}

void loop() {

  int dist = 0;
  dist = US_Measure();

  Serial.print ("Distance: ");
  Serial.println (dist);

  delay (1000);



}
