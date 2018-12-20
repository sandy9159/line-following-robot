int EL=6; // left motor enable pin
int ER=5; // right motor enable pin
int FL=4; // left motor forward pin
int RL=7; // left motor reverse pin
int FR=18; // right motor forward pin
int RR=8;  // right mootr reverse pin

int IR1=12; // IR sensor 1st
int IR2=3;  // IR sensor 2nd
int IR3=10; // IR sensor 3rd
int IR4=11; // IR sensor 4th
int IR5=2;  // IR sensor 5th
int IR6=9;  // IR sensor 6th

int val1, val2, val3, val4, val5, val6; // IR sensors value

int error=0;

void setup() {
  pinMode(EL,OUTPUT); // motor pins set as output
  pinMode(ER,OUTPUT);
  pinMode(FL,OUTPUT);
  pinMode(RL,OUTPUT);
  pinMode(FR,OUTPUT);
  pinMode(RR,OUTPUT);
  
   pinMode(IR1,INPUT); // IR pins set as input
   pinMode(IR2,INPUT);
   pinMode(IR3,INPUT);
   pinMode(IR4,INPUT);
   pinMode(IR5,INPUT);
   pinMode(IR6,INPUT);
   
  Serial.begin(9600);
}

void loop() {
  val1 = digitalRead(IR1);
  val2 = digitalRead(IR2);
  val3 = digitalRead(IR3);
  val4 = digitalRead(IR4);
  val5 = digitalRead(IR5);
  val6 = digitalRead(IR6);
  /*
  Serial.print(val1);
  Serial.print("--");
  Serial.print(val2);
  Serial.print("--");
  Serial.print(val3);
  Serial.print("--");
  Serial.print(val4);
  Serial.print("--");
  Serial.print(val5);
  Serial.print("--");
  Serial.print(val6);
  */
  
  if (val1==HIGH){
  error = 20;
}
if (val2==HIGH){
  error = 10;
} 
if (val3==HIGH){
  error = 0;
}
if (val4==HIGH){
  error = 0;
}
if (val5==HIGH){
  error = -10;
}
if (val6==HIGH){
  error = -20;
}


Serial.println(error);


if (error < 0){
  left_turn();
}

if (error > 0){
  right_turn();
}


if (error == 0){
 forward();
}

Serial.println(error);
}

void forward(){
  
    analogWrite(EL, 50);
   analogWrite(ER, 50);
    digitalWrite(FL, HIGH);
   digitalWrite(FR, HIGH);
   digitalWrite(RR, LOW);
   digitalWrite(RL, LOW);
   delay(10);
  
  
}


void left_turn(){
  
   analogWrite(EL, 150);
   analogWrite(ER, 150);
    digitalWrite(FR, HIGH);
   digitalWrite(RL, LOW);
   digitalWrite(RR, LOW);
   digitalWrite(FL, LOW);   
   
}

   
   
void right_turn(){
  
   analogWrite(EL, 150);
   analogWrite(ER, 150);
    digitalWrite(FR, LOW);
   digitalWrite(RL, LOW);
   digitalWrite(RR, LOW);
   digitalWrite(FL, HIGH);   
}
