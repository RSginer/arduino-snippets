
int TRIG = 10;
int ECO = 9;
int LED = 2;

int DURATION;
int DISTANCE;

void setup()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURATION = pulseIn(ECO, HIGH);
  DISTANCE = DURATION / 58.2; // CONSTANT OF MY SENSOR
  Serial.println(DISTANCE);
  delay(200);


}
