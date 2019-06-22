 int  I11,I12,I13,I21,I22 = 0;
//Timer2 Prescaler :575; Preload = 62499; Actual Interrupt Time = 500 ms

//Place/Copy this part in declaration section
/*void InitTimer2(){
  RCC_APB1ENR.TIM2EN = 1;
  TIM2_CR1.CEN = 0;
  TIM2_PSC = 575;
  TIM2_ARR = 62499;
  NVIC_IntEnable(IVT_INT_TIM2);
  TIM2_DIER.UIE = 1;
  TIM2_CR1.CEN = 1;
}

void Timer2_interrupt() iv IVT_INT_TIM2 {
GPIO_Digital_Output(&GPIOD_ODR , _GPIO_PINMASK_LOW);
  TIM2_SR.UIF = 0;
  
  //Enter your code here
  GPIOD_ODR.B0= ~GPIOD_ODR.B0  ; // Toggle PORTD
  GPIOD_ODR.B1= ~GPIOD_ODR.B1  ; // Toggle PORTD
  GPIOD_ODR.B2= ~GPIOD_ODR.B2  ; // Toggle PORTD
  GPIOD_ODR.B3= ~GPIOD_ODR.B3  ; // Toggle PORTD
   GPIOD_ODR.B4= ~GPIOD_ODR.B4  ; // Toggle PORTD
  GPIOD_ODR.B5= ~GPIOD_ODR.B5  ; // Toggle PORTD
  GPIOD_ODR.B6= ~GPIOD_ODR.B6  ; // Toggle PORTD
  GPIOD_ODR.B7= ~GPIOD_ODR.B7 ;

}  */
        //Timer3 Prescaler :143; Preload = 62499; Actual Interrupt Time = 125 ms

//Place/Copy this part in declaration section
void InitTimer3(){
  RCC_APB1ENR.TIM3EN = 1;
  TIM3_CR1.CEN = 0;
  TIM3_PSC = 143;
  TIM3_ARR = 62499;
  NVIC_IntEnable(IVT_INT_TIM3);
  TIM3_DIER.UIE = 1;
  TIM3_CR1.CEN = 1;
}

void Timer3_interrupt() iv IVT_INT_TIM3 {
GPIO_Digital_Output(&GPIOD_ODR , _GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIOE_ODR , _GPIO_PINMASK_HIGH);
  TIM3_SR.UIF = 0;
  //Enter your code here
  GPIOD_ODR.B8= ~GPIOD_ODR.B8  ; // Toggle PORTD
  GPIOD_ODR.B9= ~GPIOD_ODR.B9  ; // Toggle PORTD
  GPIOD_ODR.B10= ~GPIOD_ODR.B10  ; // Toggle PORTD
  GPIOD_ODR.B11= ~GPIOD_ODR.B11  ; // Toggle PORTD
   GPIOD_ODR.B12= ~GPIOD_ODR.B12  ; // Toggle PORTD
  GPIOD_ODR.B13= ~GPIOD_ODR.B13 ; // Toggle PORTD
  GPIOD_ODR.B14= ~GPIOD_ODR.B14  ; // Toggle PORTD
  GPIOD_ODR.B15= ~GPIOD_ODR.B15 ;
  if(I11 == 0)
  {
      GPIOD_ODR.B0= ~GPIOD_ODR.B0  ; // Toggle PORTD
  GPIOD_ODR.B1= ~GPIOD_ODR.B1  ; // Toggle PORTD
  GPIOD_ODR.B2= ~GPIOD_ODR.B2  ; // Toggle PORTD
  GPIOD_ODR.B3= ~GPIOD_ODR.B3  ; // Toggle PORTD
   GPIOD_ODR.B4= ~GPIOD_ODR.B4  ; // Toggle PORTD
  GPIOD_ODR.B5= ~GPIOD_ODR.B5  ; // Toggle PORTD
  GPIOD_ODR.B6= ~GPIOD_ODR.B6  ; // Toggle PORTD
  GPIOD_ODR.B7= ~GPIOD_ODR.B7 ;
  I11 = 1 ;
  }
  else
  I11 = 0;
  
  if(I21 == 0)
  {
       GPIOE_ODR= ~GPIOE_ODR;
       I21 = 1; // Toggle PORTD
  }
  else
  {
   if(I22 = 0)
   I22 = 1;
   else
   {
     I22 = 0;
     I21 =0;
   }
  }
   // Toggle PORTD
}

                   //Timer4 Prescaler :1124; Preload = 63999; Actual Interrupt Time = 1

//Place/Copy this part in declaration section
/*void InitTimer4(){
  RCC_APB1ENR.TIM4EN = 1;
  TIM4_CR1.CEN = 0;
  TIM4_PSC = 1124;
  TIM4_ARR = 63999;
  NVIC_IntEnable(IVT_INT_TIM4);
  TIM4_DIER.UIE = 1;
  TIM4_CR1.CEN = 1;
}

void Timer4_interrupt() iv IVT_INT_TIM4 {
GPIO_Digital_Output(&GPIOE_ODR , _GPIO_PINMASK_HIGH);
  TIM4_SR.UIF = 0;
  GPIOE_ODR= ~GPIOE_ODR; // Toggle PORTD
  //Enter your code here
} */

void main() { 
             // InitTimer2();
              InitTimer3();
             // InitTimer4();
                      /*  TIM2_DIER.UIE = 1;
                        TIM2_CR1.CEN = 1; */
                        TIM3_DIER.UIE = 1;
                         TIM3_CR1.CEN = 1;
                       /*  TIM4_DIER.UIE = 1;
                          TIM4_CR1.CEN = 1; */





   while (1) ;
}
