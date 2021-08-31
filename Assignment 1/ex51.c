/* Assignment: 51
	Author: Sagi Bitton, ID: 205620859
 */
#include <stdio.h>
int main(){ //simple calculator using if and if-else.
char operato; 
int first, second; 
printf("Hey, enter an operation (+,-, *, /,%%) please: \n"); 
scanf("%c", &operato);
if (operato == '+' || operato == '-' || operato == '*' || operato == '/' || operato == '%' ){ //using if to collect operator that exist in list if this is fail then user gets error "input is incorrect!
printf("Enter a first operand: \n"); 
scanf("%d",&first);
printf("Enter a second operand: \n");
scanf("%d" ,&second); // user inputed correct operator then program collect to operands
	if (operato=='+'){ //if user asked for '+' then do addition
                printf("i am a clever calculator: %d + %d = %d\n",first,second,first+second);}
        else if (operato == '-'){//if user asked for '-' then do substracion
                printf("i am a clever calculator: %d - %d = %d\n",first,second,first-second);}
        else if (operato == '*'){//if user asked for '*' then do multiply
                printf("i am a clever calculator: %d * %d = %d\n",first,second,first*second);}
	else if (operato == '/'){ //if user asked for '/' then do divide
                printf("i am a clever calculator: %d / %d = %d\n",first,second,first/second);}
	else if (operato == '%'){ //if user asked for '%' then do module
                printf("i am a clever calculator: %d %% %d = %d\n",first,second,first%second);}
}
else{ //if user inputed operator that doesn't exsist in list then print error message
printf("Your input is incorrect!\n");}
                return 0;
}

