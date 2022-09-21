
 
//define the End Of Line delimiter
#define EOL "\n" 

const int ledPin =  7;      // the number of the LED pin

void setup() {
  //start listening for messages
  Serial.begin(9600);
  Serial.print("INITIALIZING");
  Serial.print(EOL);
 
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      

  //hardware ready
  Serial.print("READY");
  Serial.print(EOL);
  
}

void loop(){

  Serial.print(10, DEC);
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  
  Serial.print(4, DEC);
  digitalWrite(7, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);   
  Serial.print(EOL);

  
}//end main loop

