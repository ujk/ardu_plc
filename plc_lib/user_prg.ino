void user_prg(){
  //output1 = input1 & (input2 | output1);
  
  // PHOEX
  //LD(input[0]);
  //AND(input[1]);
  //ORB(input[0]);
  //AND(output[0]);
  //BE();
  //ST(output[0]);
  
  // DELTA
  DEVRE();
  YUKLE(input1);
  CIKAN(&mem2);
  SAY(&say1, mem1, 5);
  SAKLA(&output1);
  
  DEVRE();
  YUKLE(output1);
  GECIKME(&timer1, 2000);
  SAKLA(&mem1);
  
  //KINCO
  //YUKLE(input[0]);
  //VEB();
  //YUKLE(input[1]); 
  //VEYA(output[0]); 
  //BSON();
  //SAKLA(output[0]);
}

