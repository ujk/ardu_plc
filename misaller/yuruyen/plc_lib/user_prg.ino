void user_prg(){
  
  DEVRE();
  YUKLE(!input2);
  YUKLE(input1);
  VEYA(mem1);
  VEB();
  SAKLA(&mem1);
  
  DEVRE();
  YUKLE(mem1);
  VED(tmr1.out);
  ZAMANLA(&tmr1,100);
  
  DEVRE();
  YUKLE(tmr1.out);
  TOPLA(mem2,1,&mem2);
  
  DEVRE();
  YUKLE(HIGH);
  BUYUKMU(mem2,3);
  ESITLE(&mem2,0);
  
  YUKLE(mem1);
  ESMI(mem2,0);
  SAKLA(&output1);
  
  YUKLE(mem1);
  YUKLE(HIGH);
  ESMI(mem2,1);
  YUKLE(HIGH);
  ESMI(mem2,3);
  VEYAB();
  VEB();
  SAKLA(&output2);
  
  YUKLE(mem1);
  ESMI(mem2,2);
  SAKLA(&output3);
}

