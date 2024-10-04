int ledPin = 13; // Pin connected to the LED

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(6, LOW); 
  digitalWrite(7, LOW); 
  digitalWrite(8, LOW); 
  digitalWrite(9, LOW); 
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int finger_count = Serial.read();
    
    // Check the finger count and control the robot
    if (finger_count == '1') {
      //FORWARD
      digitalWrite(2, HIGH); 
      digitalWrite(3, LOW); 
      digitalWrite(4, HIGH); 
      digitalWrite(5, LOW);
      delay(2000); 
    } 

    else if (finger_count == '2') {
      //BACKWARD
      digitalWrite(2, LOW); 
      digitalWrite(3, HIGH); 
      digitalWrite(4, LOW); 
      digitalWrite(5, HIGH); 
    } 

    else if (finger_count == '3') {
      //RIGHT TURN
      digitalWrite(2, HIGH); 
      digitalWrite(3, LOW); 
      digitalWrite(4, LOW); 
      digitalWrite(5, HIGH); 
    } 

    else if (finger_count == '4') {
      //LEFT TURN
      digitalWrite(2, LOW); 
      digitalWrite(3, HIGH); 
      digitalWrite(4, HIGH); 
      digitalWrite(5, LOW); 
    } 

    else {
      //STOP
      digitalWrite(2, LOW); 
      digitalWrite(3, LOW); 
      digitalWrite(4, LOW); 
      digitalWrite(5, LOW); 
    }
  }
}
