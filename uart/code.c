#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

void configuration(){
  

UCSR0B=0b00011000;//enable transmit and recieve
  
  
UCSR0C=0b00000110;//asynchronous no parity one stop bit with 8 bit data 
  
//9600 baud rate associated with ubrr of 103 which is 0000 01100111 , ubbrh is four most significant bits 0000 , ubrr0l is 8 least significant bits 01100111 , 
UBRR0H=0b0000;
UBRR0L=0b01100111;
  
}
//UDR0=0b00100001;
void transmit(char data){
if (  ( (UCSR0A & 0b00100000)==0b00100000 ) ) //executes if Bit 5 USART Data Register Empty is one
{
  data+=1;
UDR0=data;
  UDR0='\n';

}

 
}

char recieve(){
  while ( !  ( (UCSR0A & 0b10000000)==0b10000000 )   );  //loops if Bit 7 USART Receive Complete is 0
return UDR0;
  
  
}


int main()
{

configuration();
 
  while (1){
  char data=recieve();
  transmit(data);
  }
  
    return 0;
}


