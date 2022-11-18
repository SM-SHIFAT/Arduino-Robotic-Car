char C;
String voice = "";

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  // pinMode(A0, OUTPUT);
  // pinMode(A1, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // pinMode(50, OUTPUT); //front white/blue
  // pinMode(22, OUTPUT); //blue light
  // pinMode(48, OUTPUT); //other green
  // pinMode(46, OUTPUT); //Horn
  // pinMode(52, OUTPUT); //blue light
}
void loop() {

  while (Serial1.available()) {
    C = Serial1.read();
    voice = voice + C;  
  }
    delay(500);

  if (voice.length() > 0) {
    Serial.println(voice);
    
    if(voice == "go forward"){
      forward();
      backLightOFF();      
    }
    else if (voice == "go backward") {
    backward();
    backLightON();
    }
    else if (voice == "go right") {
    forwardLeft();
    delay(800);
    forward();
    }
    else if (voice == "go left") {
    forwardRight();
    delay(800);
    forward();

    }
    else if (voice == "light on") {
    frontLightON();

    }
    else if (voice == "light off") {
    frontLightOFF();

    }
    else if (voice == "stop") {
   
    stop();

    }
    

  }

  voice = "";

}

void forward() {
  digitalWrite(12, LOW);  //BLUE

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void backward() {

  digitalWrite(12, HIGH);  //BLUE


  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void forwardLeft() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void backwardLeft() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}
void forwardRight() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
void backwardRight() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
void rotateRight() {


  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void rotateLeft() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}
void stop() {
  digitalWrite(12, HIGH);  //BLUE
  //digitalWrite(13, LOW); //RED

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}
void light(char x) {
  if (x == 'W') {
    digitalWrite(52, HIGH);
    digitalWrite(22, HIGH);
  } else if (x == 'w') {
    digitalWrite(52, LOW);
    digitalWrite(22, LOW);
  } else if (x == 'U') {

    digitalWrite(48, HIGH);

  } else if (x == 'u') {

    digitalWrite(48, LOW);
  }
}
void backLightON() {
  digitalWrite(48, HIGH);
}
void backLightOFF() {
  digitalWrite(48, LOW);
}
void frontLightON() {
  digitalWrite(52, HIGH);
    digitalWrite(22, HIGH);
}
void frontLightOFF() {
  digitalWrite(52, LOW);
    digitalWrite(22, LOW);
}
void horn(char x) {
  if (x == 'V') {
    digitalWrite(14, HIGH);  //ON
  } else if (x == 'v') {
    digitalWrite(14, LOW);  //OFF
  }
}