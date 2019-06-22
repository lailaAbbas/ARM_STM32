
void RL();
void TP();
void main() {
     unsigned int oldstate;
     unsigned int old;
      GPIO_Digital_Output(&GPIOC_ODR,_GPIO_PINMASK_ALL);
       GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
        GPIO_Digital_Output(&GPIOE_ODR,_GPIO_PINMASK_HIGH);
       GPIO_Digital_Input(&GPIOA_IDR, _GPIO_PINMASK_0);
       GPIO_Digital_Input(&GPIOB_IDR, _GPIO_PINMASK_0);

     GPIOC_ODR =0x0;
     GPIOD_ODR =0x0;
     GPIOE_ODR =0x0;
      oldstate = 0;
      old = 0;
     
   while(1)
   {



    if (Button(&GPIOA_IDR, 0, 1, 1))                      // detect logical one on PA0 pin
      oldstate = 1;
    if (oldstate && Button(&GPIOA_IDR, 0, 1, 0)) {        // detect one-to-zero transition on PA0 pin
    RL();                       // invert PORTD value
      oldstate = 0;


   
   }
   
   if (Button(&GPIOB_IDR, 0, 1, 1))                      // detect logical one on PA0 pin
      old = 1;
    if (old && Button(&GPIOB_IDR, 0, 1, 0)) {        // detect one-to-zero transition on PA0 pin
    TP();                       // invert PORTD value
      old = 0;



   }
  }                                           // endless loop
     }

     void RL()
     {
     
     GPIOC_ODR =0x0;
     GPIOD_ODR =0x0;

     
     GPIOE_ODR = 0x0F00;
   Delay_ms(50);

   GPIOE_ODR = 0xF000;
   Delay_ms(50);
    GPIOE_ODR = 0x0000;

   GPIOD_ODR = 0x000F;
   Delay_ms(1);

   GPIOD_ODR = 0x00F0;

   Delay_ms(50);
   GPIOD_ODR = 0x0F00;
   Delay_ms(50);
   GPIOD_ODR = 0xF000;
   Delay_ms(50);
   GPIOD_ODR = 0x0000;

   GPIOC_ODR = 0x000F;
   Delay_ms(50);
   GPIOC_ODR = 0x00F0;
   Delay_ms(50);
   GPIOC_ODR = 0x0F00;
   Delay_ms(50);
   GPIOC_ODR = 0xF000;
   Delay_ms(50);
    GPIOC_ODR = 0x0000;
     }
     
     void TP()
     { GPIOE_ODR = 0x8888;
          GPIOD_ODR = 0x8888;
          GPIOC_ODR = 0x8888;
          Delay_ms(50);

          GPIOE_ODR = 0x4444;
          GPIOD_ODR = 0x4444;
          GPIOC_ODR = 0x4444;
          Delay_ms(50);
          }