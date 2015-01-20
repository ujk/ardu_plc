// http://www.kayaciklar.org

#include <user_prg>
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

const int out1 = 13;
const int out2 = 12;
const int out3 = 11;
const int out4 = 10;

int input1, input2, input3, input4, ex_in1, ex_in2, ex_in3, ex_in4;

int output1, output2, output3, output4;

int mem1, mem2, mem3, mem4, mem5, mem6, mem7, mem8, mem9, mem10;

int say1, say2, say3, say4, say5, say6, say7, say8, say9, say10;

unsigned long exMillis, scanTime, debounceMillis;

struct TMR {
  unsigned long timer; 
  int out;
};
TMR tmr1, tmr2, tmr3, tmr4, tmr5, tmr6, tmr7, tmr8, tmr9;

int aku;
int depo[10];
int depo_n = 0;


void setup(){
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);

  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  
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

  depo_n = 0;
  user_prg();

  digitalWrite(out1, output1);
  digitalWrite(out2, output2);
  digitalWrite(out3, output3);
  digitalWrite(out4, output4);
}



//YENİ NESİL KOMUTLAR
void CIKAN(int *mem){
  int a = depo_cek();
  if((a==HIGH)&(*mem==LOW)) depo_koy(HIGH); else depo_koy(LOW);
  *mem = a;
}
void depo_koy(int deger){
  depo[depo_n] = deger;
  depo_n++;
}
int depo_cek(){
  depo_n--;
  return(depo[depo_n]);
}
void DEVRE(){ depo_n = 0; }
void ESITLE(int *hedef, int deger){
  int a = depo_cek();
  if(a==HIGH){
    *hedef = deger;
  }
  depo_koy(a);
}
void ESMI(int op1, int op2){
  int a = depo_cek();
  if((a==HIGH) & (op1 == op2)){
    depo_koy(HIGH);
  }else{
    depo_koy(LOW);
  }
}
void SAKLA(int *hedef){
  *hedef = depo_cek();
  depo_koy(*hedef);
}
int SAY(int *count, int res, int setpoint){
  int a = depo_cek();
  if(a == HIGH){
    *count += 1;
  }
  if(res == HIGH) *count = 0;
  if(*count >= setpoint){
    *count = setpoint;
    depo_koy(HIGH);
  }else{
    depo_koy(LOW);
  }
}
void SIL(int *hedef){
  int a = depo_cek();
  if(a==HIGH) *hedef = LOW;
  depo_koy(a);
}
void VE(int deger){
  int a = depo_cek();
  depo_koy(a & deger);
}
void VEB(){
  int a = depo_cek();
  int b = depo_cek();
  depo_koy(a & b);
}
void VED(int deger){
  int a = depo_cek();
  depo_koy(a & !deger);
}
void VEYA(int deger){
  int a = depo_cek();
  depo_koy(a | deger);
}
void VEYAB(){
  int a = depo_cek();
  int b = depo_cek();
  depo_koy(a | b);
}
void YUKLE(int deger){
  depo_koy(deger);
}
void YAZ(int *hedef){
  int a = depo_cek();
  if(a==HIGH) *hedef = HIGH;
  depo_koy(a);
}
void ZAMANLA(void *tim, unsigned long setpoint){
  int a = depo_cek();
  TMR *time;
  time = (TMR *) tim;
  if(a == HIGH){
    time->timer = time->timer + scanTime;
  }else{
    time->timer = 0;
  }
  if(time->timer >= setpoint){
    time->timer = setpoint;
    time->out = HIGH;
  }else{
    time->out = LOW;
  }
  depo_koy(a);
}


// DELTA KOD KARŞILIKLARI
// "ANB" -> VEB();
// "AND= op1 op2" -> ESMI(op1,op2)
// "LD adres" -> YUKLE(adres)
// "LD timer" -> YUKLE(timer.out)
// "LD= op1 op2" -> YUKLE(HIGH); ESMI(op1,op2);
// "MOV kaynak hedef" -> ESITLE(&hedef,kaynak) --- hedef & ile
// "NP" -> CIKAN(&adres) --- çıkan kenara manual hafıza veriliyor
// "OR adres" -> VEYA(adres)
// "OUT adres" -> SAKLA(&adres) --- çıkış için & ile başlayacak
// "RST adres" -> SIL(&adres) --- çıkış & ile yazılır
// "TMR timer setpoint" -> ZAMANLA(&tmr, setpoint) --- tmr struct
