#define m1 4  //Right Motor MA1
#define m2 5  //Right Motor MA2
#define m3 2  //Left Motor MB1
#define m4 3  //Left Motor MB2
#define e1 9  //Right Motor Enable Pin EA
#define e2 10 //Left Motor Enable Pin EB

//**********5 Channel IR Sensor Connection**********//
#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4
//*************************************************//
int dth = 150;
int dth_2 = 200;
int dtime = 10;
void setup() {
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}

void loop() {
  //Reading Sensor Values
  int s1 = digitalRead(ir1);  //Left Most Sensor
  int s2 = digitalRead(ir2);  //Left Sensor
  int s3 = digitalRead(ir3);  //Middle Sensor
  int s4 = digitalRead(ir4);  //Right Sensor
  int s5 = digitalRead(ir5);  //Right Most Sensor

  //if only middle sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going forward with full speed 
    analogWrite(e1, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(m1, dth_2);
    analogWrite(m2, 0);
    analogWrite(m3, dth_2);
    analogWrite(m4, 0);
    delay(dtime);
  }
  
  //if only left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    analogWrite(e1, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(m1, 0);
    analogWrite(m2, 0);
    analogWrite(m3, dth);
    analogWrite(m4, 0);
    delay(dtime);
  }
  
  //if only left most sensor detects black line
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    analogWrite(e1, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(m1, 0);
    analogWrite(m2, dth);
    analogWrite(m3, dth);
    analogWrite(m4, 0);
    delay(dtime);
  }

  //if only right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1))
  {
    //going left with full speed 
    analogWrite(e1, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(m1, dth);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, 0);
    delay(dtime);
  }

  //if only right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    //going left with full speed 
    analogWrite(e1, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(m1, dth);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, dth);
    delay(dtime);
  }

  //if middle and right sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
    //going left with full speed 
    analogWrite(e1, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(m1, dth);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, 0);
    delay(dtime);
  }

  //if middle and left sensor detects black line
  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    analogWrite(e1, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(m1, 0);
    analogWrite(m2, 0);
    analogWrite(m3, dth);
    analogWrite(m4, 0);
  }

  //if middle, left and left most sensor detects black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    //going right with full speed 
    analogWrite(e1, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(m1, 0);
    analogWrite(m2, 0);
    analogWrite(m3, dth);
    analogWrite(m4, 0);
    delay(dtime);
  }

  //if middle, right and right most sensor detects black line
  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //going left with full speed 
    analogWrite(e1, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(e2, dth); //you can adjust the speed of the motors from 0-255
    analogWrite(m1, dth);
    analogWrite(m2, 0);
    analogWrite(m3, 0);
    analogWrite(m4, 0);
    delay(dtime);
  }

  //if all sensors are on a black line
  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //stop
    digitalWrite(m1, 0);
    digitalWrite(m2, 0);
    digitalWrite(m3, 0);
    digitalWrite(m4, 0);
    delay(dtime);
  }
}
