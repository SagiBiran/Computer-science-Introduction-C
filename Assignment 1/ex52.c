/* Assignment: 52
        Author: Sagi Bitton, ID: 205620859
 */
#include <stdio.h>
int main(){//simple calculator using switch
char operato; 
int first, second;
printf("Hey, enter an operation (+,-, *, /,%%) please: \n");
scanf("%c", &operato);//colecting operator desired by user
if (operato == '+' || operato == '-' || operato == '*' || operato == '/' || operato == '%' ){ //useing if to collect operator that exist in list if this is fail then user gets error "input is incorrect!
printf("Enter a first operand: \n"); 
scanf("%d",&first); 
printf("Enter a second operand: \n");
scanf("%d" ,&second);
switch (operato){ //switch function. each case will do the aritmetic operation
	case '+':
		printf("i am a clever calculator: %d + %d = %d\n",first,second,first+second);
			break;
	case '-':
		printf("i am a clever calculator: %d - %d = %d\n",first,second,first-second);
			break;
	case '*':
        	printf("i am a clever calculator: %d * %d = %d\n",first,second,first*second);
        		break;
	case '/':
        	printf("i am a clever calculator: %d / %d = %d\n",first,second,first/second);
        		break;
	case '%':
        	printf("i am a clever calculator: %d %% %d = %d\n",first,second,first%second);
        		break;
	defualt:
		printf("Your input is incorrect!\n");}}
else{
printf("Your input is incorrect!\n");} //user will get this messseage if inputed wrong operator.
		return 0;
}

