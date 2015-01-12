// http://www.kayaciklar.org

#include <user_prg>
const int in1 = 0;
const int in2 = 1;
const int in3 = 2;
const int in4 = 3;

const int out1 = 13;
const int out2 = 12;
const int out3 = 11;
const int out4 = 10;

int input1, input2, input3, input4, ex_in1, ex_in2, ex_in3, ex_in4;

int output1, output2, output3, output4;

int mem1, mem2, mem3, mem4, mem5, mem6, mem7, mem8, mem9, mem10;

int say1, say2, say3, say4, say5, say6, say7, say8, say9, say10;

unsigned long exMillis, scanTime, debounceMillis;
unsigned long timer1, timer2, timer3, timer4, timer5;

void setup(){
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);

  pinMode(out1, OUTPUT);
  pinMode(out1, OUTPUT);
  pinMode(out1, OUTPUT);
  pinMode(out1, OUTPUT);
  
  exMillis = millis();
  debounceMillis = exMillis;
}



void loop(){
  int tempi;
  if((millis() - debounceMillis) >= 50){
    tempi = digitalRead(in1);
    if(tempi == ex_in1) input1 = tempi;
    ex_in1 = tempi;
    tempi = digitalRead(in2);
    if(tempi == ex_in2) input2 = tempi;
    ex_in2 = tempi;
    tempi = digitalRead(in3);
    if(tempi == ex_in3) input3 = tempi;
    ex_in3 = tempi;
    tempi = digitalRead(in4);
    if(tempi == ex_in4) input4 = tempi;
    ex_in4 = tempi;
    debounceMillis = millis();
  }
  
  scanTime = millis() - exMillis;
  exMillis = millis();

  user_prg();

  digitalWrite(out1, output1);
  digitalWrite(out2, output2);
  digitalWrite(out3, output3);
  digitalWrite(out4, output4);
}

int cikanKenar(int *inpoint, int *mempoint){
  if (*inpoint == HIGH && *mempoint == LOW) {
    *mempoint = *inpoint;
    return(HIGH);
  } else {
    *mempoint = *inpoint;
    return(LOW);
  }
}

int inenKenar(int *inpoint, int *mempoint){
  if (*inpoint == LOW && *mempoint == HIGH) {
    *mempoint = *inpoint;
    return(HIGH);
  } else {
    *mempoint = *inpoint;
    return(LOW);
  }
}

void setReset(int setInput, int resetInput, int *outpoint){
  if(setInput == HIGH) *outpoint = HIGH;
  if(resetInput == HIGH) *outpoint = LOW;
  //return(*mempoint);
}

int gecikme(int inpoint, unsigned long *tim, unsigned long setpoint){
  if(inpoint == HIGH){
    *tim = *tim + scanTime;
  }else{
    *tim = 0;
  }
  if(*tim >= setpoint){
    *tim = setpoint;
    return(HIGH);
  }else{
    return(LOW);
  }
}

int say(int inpoint, int res, int *count, int setpoint){
  if(inpoint == HIGH){
    *count += 1;
  }
  if(res == HIGH) *count = 0;
  if(*count >= setpoint){
    *count = setpoint;
    return(HIGH);
  }else{
    return(LOW);
  }
}
