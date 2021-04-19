/*
Volume Meter 2021-04-06
LED brightness is controlled by volume.
Amplifier uses 2N3904 transistor to amplify the electret mic output.
*/

const int yellowLedPin = 3;
const int adcInput = A0;

void setup() {
  // put your setup code here, to run once:

  pinMode(yellowLedPin, OUTPUT);
  digitalWrite(yellowLedPin, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int input = analogRead(adcInput);
  
  Serial.print("Analog value: ");
  float voltage = input * (2.5 / 1023.0);  //output of the electret mic is about 1V when the noise is loud. Not sure what value this should be.
  Serial.println(voltage);
  Serial.print("Input: ");
  Serial.println(input); //see the max and min values

  const float convertTo255Range = input * 255.0 / 1023.0; //or just divide by 4.
  const int conversion = int(convertTo255Range);
  Serial.print("conversion");
  Serial.println(conversion);
  analogWrite(yellowLedPin, conversion);
}
