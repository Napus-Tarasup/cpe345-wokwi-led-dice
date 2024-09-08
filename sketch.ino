#define SWT1 35 // random number switch (1-6)
#define SWT2 13 // clear switch (1)

int LEDpin[] = {4, 2, 15, 5, 18, 19, 21}; // LED

int swt1; 
int swt2; 
long ran; 

void setup() {

  Serial.begin(115200);

  pinMode(SWT1, INPUT);
  pinMode(SWT2, INPUT);

  // set LEDpin -> output
  for(int i=0; i<7; i++){
    pinMode(LEDpin[i], OUTPUT);
  }

  // set LEDpin -> dark
   for(int i=0; i<7; i++){
    digitalWrite(LEDpin[i], HIGH);
  }

}

void loop() {

  swt1 = digitalRead(SWT1);
  swt2 = digitalRead(SWT2);
  delay(180);

  if(swt1 != 1){
    ran = random(1, 7);
    Serial.println("Random number : " + String(ran));

    if(ran == 1){
      for(int i=0; i<7; i++){
        if(i != 3)
          digitalWrite(LEDpin[i], HIGH);
        else
          digitalWrite(LEDpin[i], LOW);
      }
    }
    
    else if(ran == 2){
      for(int i=0; i<7; i++){
        if(i != 0 && i != 6)
          digitalWrite(LEDpin[i], HIGH);
        else
          digitalWrite(LEDpin[i], LOW);
      }
    }

    else if(ran == 3){
      for(int i=0; i<7; i++){
        if(i != 0 && i != 3 && i != 6)
          digitalWrite(LEDpin[i], HIGH);
        else
          digitalWrite(LEDpin[i], LOW);
      }
    }

    else if(ran == 4){
      for(int i=0; i<7; i++){
        if(i != 1 && i != 3 && i != 5)
          digitalWrite(LEDpin[i], LOW);
        else
          digitalWrite(LEDpin[i], HIGH);
      }
    }

    else if(ran == 5){
      for(int i=0; i<7; i++){
        if(i != 1 && i != 5)
          digitalWrite(LEDpin[i], LOW);
        else
          digitalWrite(LEDpin[i], HIGH);
      }
    }

    else if(ran == 6){
      for(int i=0; i<7; i++){
        if(i != 3)
          digitalWrite(LEDpin[i], LOW);
        else
          digitalWrite(LEDpin[i], HIGH);
      }
    }
    
  }

 else if(swt2 != 1){
  for(int i=0; i<7; i++){
    if(i != 3)
      digitalWrite(LEDpin[i], HIGH);
    else
      digitalWrite(LEDpin[i], LOW);
  }
 }

}
