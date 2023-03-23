#include <MsTimer2.h>

const int piezo = A0;
const int R = 11;
const int G = 9;
const int B = 10;
const int quiet = 4;
const int loud = 50;
boolean light = false;
boolean counter = false;
boolean timeron = true;
int r;
int g;
int b;
int knock;
int howmany;
unsigned long startTime;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  knock = 0;
  howmany = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(knock>loud){
    knock=0;
    }
    
     if(howmany >= 2){
          light = true;
          timeron = true;
          }
          else{}

  if(analogRead(piezo)>knock){
  knockvalue(analogRead(piezo));
  counter = true;
  }
  
  else{
    counter = false;
    }

    Serial.print(counter);
    Serial.print("\t");
    Serial.print(light);
    Serial.print("\t");
    Serial.print(howmany);
    Serial.print("\t");
    Serial.print(analogRead(piezo));
    Serial.print("\t");
    Serial.println(knock);

    
  if(light == false && counter == true){//ledがついてないとき
    
      
      if(check(knock) == true){
        howmany+=1;
        knock = quiet;
         if(timeron == true){
          timer();
              }
        delay(30);
        }
    }
    
    else if(millis()-startTime>5000){
              howmany = 0;
              knock = quiet;
              ;
              timeron = true;
              }
           
          
      if(light == true){
      led();
      light = false;
      }
      
      else {}
}
   

      

boolean check(int value){
  if(value > quiet && value < loud){
    return true;
    }
  else{
    return false;
    }
  }


void knockvalue(int value){

  knock = value;//knockに数値を入れる
  
  }

  void timer(){
      startTime = millis();
      timeron == false;
    }

  void led(){
    analogWrite(R,200);
    analogWrite(G, 180);
    analogWrite(B, 0);
    delay(10000);
    analogWrite(R,0);
    analogWrite(G, 0);
    analogWrite(B, 0);
    howmany = 0;
    }
    
