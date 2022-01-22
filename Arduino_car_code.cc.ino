#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2,3); //RX, TX
char t;

#define Motor_Left_1 5 
#define Motor_Left_2 6
#define Motor_Right_1 10
#define Motor_Right_2 11

void setup() 
{
 Serial.begin(9600);  
 bluetooth.begin(9600);
 pinMode(Motor_Left_1, OUTPUT); // Left motor, Forward
 pinMode(Motor_Left_2, OUTPUT); // Left motor, Reverse
 pinMode(Motor_Right_1, OUTPUT); // Right motor, Forward
 pinMode(Motor_Right_2, OUTPUT); // Right motor, Reverse
}

void loop()
{
 //Serial.println("Inside Looop"); 
 //Serial.println(bluetooth.available());
 //delay(20000);

 //if(bluetooth.available()>0)

 if(Serial.available()) 
 {
  char t = Serial.read();
  Serial.println(t);
  //t = bluetooth.read();
  //Serial.println(t);
  //}
  switch(t)
  {
    case 'f':
    case 'F': 
        go_forward();
        break;
    case 'b':
    case 'B':
        go_back();
        break;
    case 'l':
    case 'L':
        go_left();
        break;
    case 'r':
    case 'R':
        go_right();
        break;
    case 's':
    case 'S':
        stop();    
        break;
    case 't':
    case 'T':
        make_triangle();
        break;
    case 'v':
    case 'V':
        make_square();
        break;
    case 'c':
    case 'C':   
        make_circle_towards_right();
        break;            
    case 'y':
    case 'Y':
        make_circle_towards_left();
  
    
  }
 }
}

void go_forward()
{
        digitalWrite(Motor_Left_1, HIGH);
        digitalWrite(Motor_Left_2, LOW);
        digitalWrite(Motor_Right_1, HIGH);
        digitalWrite(Motor_Right_2, LOW);    
}

void go_back()
{
        digitalWrite(Motor_Left_1, LOW);
        digitalWrite(Motor_Left_2, HIGH);
        digitalWrite(Motor_Right_1, LOW); 
        digitalWrite(Motor_Right_2, HIGH);
}

void go_left()
{
        digitalWrite(Motor_Left_1, LOW);
        digitalWrite(Motor_Left_2, LOW);
        digitalWrite(Motor_Right_1, HIGH);
        digitalWrite(Motor_Right_2, LOW);    
}

void go_right()
{
        digitalWrite(Motor_Left_1, HIGH);
        digitalWrite(Motor_Left_2, LOW);
        digitalWrite(Motor_Right_1, LOW);
        digitalWrite(Motor_Right_2, LOW);     
}

void stop()
{
        digitalWrite(Motor_Left_1, LOW);
        digitalWrite(Motor_Left_2, LOW);
        digitalWrite(Motor_Right_1, LOW);
        digitalWrite(Motor_Right_2, LOW);  
}

void make_triangle()
{
        int travel = 10000;
        int delay1 = 7000;

        go_forward();
        delay(travel);

        go_right();
        delay(delay1);

        go_forward();
        delay(travel);

        go_right();
        delay(delay1);

        go_forward();
        delay(travel);
}

void make_square()
{

        int travel = 10000;
        int delay1 = 5000;
  
        go_forward();
        delay(travel);

        go_right();
        delay(delay1);

        go_forward();
        delay(travel);

        go_right();
        delay(delay1);

        go_forward();
        delay(travel);

        go_right();
        delay(delay1);

        go_forward();
        delay(travel);

        go_right();
        delay(delay1);
} 

void make_circle_towards_right()
{
       
        int travel = 100;
        int delay1 = 50;
        int i = 0;
        
        for (i=0; i <35000; i++){
          go_forward();
          delay(travel);
  
          go_right();
          delay(delay1);
        }
       
}

void make_circle_towards_left()
{
       int travel = 100;
       int delay1 = 50;
       int i = 0;
        
        for (i=0; i <35000; i++){
          go_forward();
          delay(travel);
  
          go_left();
          delay(delay1);
        }
}




        
