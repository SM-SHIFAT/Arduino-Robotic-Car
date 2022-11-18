char C;

void setup (){
    Serial.begin(9600);
    Serial1.begin(9600);

    pinMode(A0, OUTPUT);
    pinMode(A1, INPUT); 
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);

    pinMode(50, OUTPUT); //front white/blue
    pinMode(22, OUTPUT); //blue light
    pinMode(48, OUTPUT); //other green
    pinMode(46, OUTPUT); //Horn
    pinMode(52, OUTPUT); //blue light
  }
  void loop() {
if(Serial1.available()) {
  C=Serial1.read();
  Serial.println(C);
}  
   
   if(C=='F'){
     forward();
     backLightOFF();
   }
   else if(C=='R'){
    rotateLeft();
    backLightOFF();
   }
   else if(C=='L'){
     rotateRight();
     backLightOFF();

   }
   else if(C=='B'){
     backward();
     backLightON();
   }
   else if(C=='G'){
    
     forwardRight();
     backLightOFF();
   }
   else if(C=='I'){
    forwardLeft();
    backLightOFF();
   }
   else if(C=='J'){
     backwardRight();
     backLightON();
   }
   else if(C=='H'){
     backwardLeft();
     backLightON();
   }
   else if(C=='V' || C=='v'|| C=='W' || C=='w' || C=='U' || C=='u'){
     light(C);
     horn(C);
   }
   else{
     stop();
  }

   
  }
  void forward(){
    digitalWrite(12, LOW); //BLUE
     
  digitalWrite(2, LOW);
     digitalWrite(3, HIGH);
     digitalWrite(4, HIGH);
     digitalWrite(5, LOW);
}

void backward(){
  
    digitalWrite(12, HIGH); //BLUE
    

  digitalWrite(2, HIGH);
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
     digitalWrite(5, HIGH);
}
void forwardLeft(){
  digitalWrite(2, LOW);
     digitalWrite(3, LOW);
     digitalWrite(4, HIGH);
     digitalWrite(5, LOW);
}
void backwardLeft(){
  digitalWrite(2, LOW);
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
     digitalWrite(5, HIGH);
}
void forwardRight(){
  digitalWrite(2, LOW);
     digitalWrite(3, HIGH);
     digitalWrite(4, LOW);
     digitalWrite(5, LOW);
}
void backwardRight(){
  digitalWrite(2, HIGH);
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
     digitalWrite(5, LOW);
}
void rotateRight(){


  digitalWrite(2, LOW);
     digitalWrite(3, HIGH);
     digitalWrite(4, LOW);
     digitalWrite(5, HIGH);
}

void rotateLeft(){
  digitalWrite(2, HIGH);
     digitalWrite(3, LOW);
     digitalWrite(4, HIGH);
     digitalWrite(5, LOW);
}
void stop(){
    digitalWrite(12, HIGH); //BLUE
    //digitalWrite(13, LOW); //RED

  digitalWrite(2, LOW);
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
     digitalWrite(5, LOW);
}
void light(char x){
  if(x=='W'){
    digitalWrite(52, HIGH);
digitalWrite(22, HIGH);
    }
    else if(x=='w'){
    digitalWrite(52, LOW);
digitalWrite(22, LOW);
    }
    else if(x=='U'){
      
    
    digitalWrite(48, HIGH);
    

    
    }
    else if(x=='u'){
     
   
    digitalWrite(48, LOW);
    

    
    }
}
void backLightON(){
  digitalWrite(48, HIGH);
}
void backLightOFF(){
  digitalWrite(48, LOW);
}
void horn(char x){
  if(x=='V'){
    digitalWrite(14, HIGH);//ON
    }
    else if(x=='v'){
   digitalWrite(14, LOW); //OFF
    }  
}
