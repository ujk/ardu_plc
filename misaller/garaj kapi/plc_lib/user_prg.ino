void user_prg(){
  mem2 = cikanKenar(&input1, &mem3);

  if (mem2 && (mem1 == 0)){
    mem1 = 1;
    mem2 = LOW;
  }
  
  if ((mem2 || gecikme((mem1 == 1), &timer1, 30000)) && (mem1 == 1)){
    mem1 = 5;
    mem2 = LOW;
  }
  
  if (mem2 && (mem1 == 2)){
    mem1 = 5;
    mem2 = LOW;
  }
  
  if ((mem2 || gecikme((mem1 == 3), &timer2, 30000)) && (mem1 == 3)){
    mem1 = 0;
    mem2 = LOW;
  }
  
  if (mem2 && (mem1 == 4)){
    mem1 = 1;
    mem2 = LOW;
  }
  
  if (mem2 && (mem1 == 5)){
    mem1 = 3;
    mem2 = LOW;
  }
  
  if (input3 && (mem1 == 1)){
    mem1 = 2;
  }
  
  if (gecikme(!input4 && (mem1 == 2), &timer3, 10000)){
    mem1 = 3;
  }
  
  if (input2 && (mem1 == 3)){
    mem1 = 4;
  }
  
  if (input4 && (mem1 == 3)){
    mem1 = 1;
  }
  
  output1 = gecikme((mem1 == 1), &timer4, 3000);
  
  output2 = gecikme((mem1 == 3), &timer5, 3000);
  
  output3 = gecikme(((mem1 == 1 || mem1 == 2 || mem1 == 3) && !mem4), &timer6, 500);
  mem4 = gecikme(output3, &timer7, 500);

}

