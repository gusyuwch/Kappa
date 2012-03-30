
/*  Group: Kappa
    Authors: YUWEI CHEN & QINGJU LUO
    Usage:  Get data from two sonars at the same time.
    Reference: The ping example from Arduino. */

// this constant is the pin number
// of the sensor's output:


const int pingPin1 = 7;
const int pingPin2 = 6;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
}

void loop()
{
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration1, cm1;
  long duration2, cm2;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin1, OUTPUT);
  digitalWrite(pingPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin1, LOW);
  pinMode(pingPin1, INPUT);
  duration1 = pulseIn(pingPin1, HIGH);

  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);
  pinMode(pingPin2, INPUT);
  duration2 = pulseIn(pingPin2, HIGH);


  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.






  // convert the time into a distance

  cm1 = microsecondsToCentimeters(duration1);
  cm2 = microsecondsToCentimeters(duration2);

  Serial.print(cm1);
  Serial.print("cm1");
  Serial.println();

  Serial.print(cm2);
  Serial.print("cm2");
  Serial.println();

  delay(100);
}



long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
