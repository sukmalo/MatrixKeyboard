#define pin1_2 5 //Out
#define pin3_4 6 //Out
#define pin1_3 3 //In
#define pin2_4 4 //In

// bool lastbutton = LOW;
// bool currentbutton = LOW;

// bool debounce (bool last){
//   bool current = digitalRead(BUTTON);
//   if (last != current){
//     delay(5);
//     current = digitalRead(BUTTON);
//     return current;
//   }
// }

void setup() {

  Serial.begin(9600);

  pinMode(pin1_2, OUTPUT);
  pinMode(pin3_4, OUTPUT);
  
  pinMode(pin1_3, INPUT);
  pinMode(pin2_4, INPUT);
}

int val[4] = {0, 0, 0, 0};


void loop() {

  // currentbutton = debounce(lastbutton);
  // if (lastbutton == LOW && currentbutton == HIGH){
  //   ledOn = !ledOn;
  // }
  // lastbutton = currentbutton;

  digitalWrite(pin1_2, HIGH);
  digitalWrite(pin3_4, LOW);
  pinMode(pin3_4, INPUT);

  

  bool first = digitalRead(pin1_3);
  bool second = digitalRead(pin2_4);

  if (first == HIGH){
    val[0] = 1;
   // Serial.println("1");
  }
  else if (second == HIGH){
    val[1] = 1;
    //Serial.println("2");
  }

  digitalWrite(pin1_2, LOW);
  pinMode(pin3_4, OUTPUT);
  digitalWrite(pin3_4, HIGH);
  

  first = digitalRead(pin1_3);
  second = digitalRead(pin2_4);

  if (first == HIGH){
    val[2] = 1;
   // Serial.println("3");
  }
  else if (second == HIGH){
    val[3] = 1;
   // Serial.println("4");
  }

  
  for (int i = 0; i < 4; i++){
    if (val[i] == 1){
      Serial.println("BUTTON HIGH №" + String(i+1));
    }
    
  }
  Serial.println(" ");
  for (int i = 0; i < 4; i++){
    //Serial.print(val[i]);
    val[i] = 0;
  }
}
