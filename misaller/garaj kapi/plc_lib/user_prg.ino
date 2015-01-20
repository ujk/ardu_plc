void user_prg(){
  
  //ADIMLAR
  DEVRE();
  YUKLE(input1);
  CIKAN(&mem3);
  SAKLA(&mem2);
  
  DEVRE();
  YUKLE(mem2);
  ESMI(mem1, 0);
  ESITLE(&mem1, 1);
  SIL(&mem2);
  
  DEVRE();
  YUKLE(HIGH);
  ESMI(mem1, 1);
  ZAMANLA(&tmr1, 30000);
  YUKLE(tmr1.out);
  VEYA(mem2);
  VEB();
  ESITLE(&mem1, 5);
  SIL(&mem2);
  
  DEVRE();
  YUKLE(mem2);
  ESMI(mem1,2);
  ESITLE(&mem1, 5);
  SIL(&mem2);
  
  DEVRE();
  YUKLE(HIGH);
  ESMI(mem1, 3);
  ZAMANLA(&tmr2, 30000);
  YUKLE(tmr2.out);
  VEYA(mem2);
  VEB();
  ESITLE(&mem1, 0);
  SIL(&mem2);

  DEVRE();
  YUKLE(mem2);
  ESMI(mem1,4);
  ESITLE(&mem1, 1);
  SIL(&mem2);
  
  DEVRE();
  YUKLE(mem2);
  ESMI(mem1,5);
  ESITLE(&mem1, 3);
  SIL(&mem2);
  
  DEVRE();
  YUKLE(input3);
  ESMI(mem1,1);
  ESITLE(&mem1, 2);
  
  DEVRE();
  YUKLE(!input4);
  ESMI(mem1,2);
  ZAMANLA(&tmr3, 10000);
  VE(tmr3.out);
  ESITLE(&mem1, 3);
  
  DEVRE();
  YUKLE(input2);
  ESMI(mem1,3);
  ESITLE(&mem1, 4);
  
  DEVRE();
  YUKLE(input4);
  ESMI(mem1,3);
  ESITLE(&mem1, 1);
  

  //AKTİVASYONLAR
  DEVRE();
  YUKLE(HIGH);
  ESMI(mem1, 1);
  ZAMANLA(&tmr4, 3000);
  VE(tmr4.out);
  SAKLA(&output1);

  DEVRE();
  YUKLE(HIGH);
  ESMI(mem1, 3);
  ZAMANLA(&tmr5, 3000);
  VE(tmr5.out);
  SAKLA(&output2);
  
  DEVRE();
  YUKLE(HIGH);
  ESMI(mem1, 1);
  YUKLE(HIGH);
  ESMI(mem1, 2);
  VEYAB();
  YUKLE(HIGH);
  ESMI(mem1, 3);
  VEYAB();
  VED(mem4);
  ZAMANLA(&tmr6, 500);
  VE(tmr6.out);
  SAKLA(&output3);
  
  DEVRE();
  YUKLE(output3);
  ZAMANLA(&tmr7, 500);
  VE(tmr7.out);
  SAKLA(&mem4);

}

