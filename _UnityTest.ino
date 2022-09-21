const int buttonPin01 = 2;  //Button #1 for outputting to Unity
const int buttonPin02 = 3;  //Button #2 for outputting to Unity
const int potenPin = A0;  //Analog pin for Potentiometer, output to Unity
const int ledPin = 13;    //LED that turns on when Unity input is received

int unityData;  //Stores data received from Unity

void setup()
{
  Serial.begin(9600);
  //Specify inputs/outputs
  pinMode(buttonPin01, INPUT);
  pinMode(buttonPin02, INPUT);
  pinMode(potenPin, INPUT);
  pinMode(ledPin, OUTPUT);

  //Set default values for pins
  digitalWrite(buttonPin01, HIGH);
  digitalWrite(buttonPin02, HIGH);
  digitalWrite(ledPin, LOW);
}

void loop() 
{
  TestArduinoInput();     //Detect Input from Arduino
  TestUnityInput();       //Detect Input from Unity
}

//Detect input from Arduino, and serialize for Unity
void TestArduinoInput(){
  //If Button 01 is pressed
  if(digitalRead(buttonPin01) == LOW){
    Serial.write(9);  //Pass Unity a value
    Serial.flush();   //Empty the stream
    delay(20);      //Wait a bit so Unity doesn't lag/hang
  }
  //If Button 02 is pressed
  if(digitalRead(buttonPin02) == LOW){
    Serial.write(10);
    Serial.flush();
    delay(20);
  }
  //Output the Expediometer Value -> NOTE could not get pin Variable to work in the analogRead function
  //analogRead() remaps 0-1024 to the range 0-8. This allows us to send a customized range to unity
  Serial.write(map(analogRead(A0),0,1024,0,8));
  Serial.flush();
  delay(20);
}

//Detect input from Unity, and respond accordingly
void TestUnityInput(){
  //If input detected from Unity, do something
  if(Serial.available()){
    //Store the data, then react accordingly
    unityData = Serial.read();
    
    //Enable LED while specified input is detected
    if(unityData == 'A'){
      digitalWrite(ledPin,HIGH);
    } 
    if(unityData == 'B') {
      digitalWrite(ledPin,LOW);
    }
  }
}

