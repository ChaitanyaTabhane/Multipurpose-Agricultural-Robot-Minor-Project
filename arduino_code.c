#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

#define pumpRelay 12
char data = 0;
//--------------------------------------------------------------------------
void setup(void)
{
  Serial.begin(9600);
  pinMode(pumpRelay, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(pumpRelay, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
//----------------------------------------------------------------------------
void loop(void) {
  analogWrite(5, 150);
  analogWrite(6, 150);
  
  if (Serial.available() > 0)     // Send data only when you receive data:
  {
    data = Serial.read();        //Read the incoming data & store into data
    Serial.print(data);          //Print Value inside data in Serial monitor
    Serial.print("\n");
    //=============================== FORWARD CONDITION
    if (data == 'X') {
      digitalWrite(pumpRelay, LOW);
      delay(5);
    }
    else if (data == 'x') {
      digitalWrite(pumpRelay, HIGH);
      delay(5);
    }

    //=============================== FORWARD CONDITION
    else if (data == 'F') {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(5);
    }

    //===============================================
    else if (data == 'B') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(5);
    }
    //===============================================
    else if (data == 'L') {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      delay(5);
    }
    //===============================================
    else if (data == 'R') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      delay(5);
    }
    //===============================================
    else if (data == 'S') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      delay(5);
    }
    //===============================================
  }
}
