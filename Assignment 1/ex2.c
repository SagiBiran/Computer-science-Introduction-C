/*Assignment: 2
        Author: Sagi Bitton, ID:205620859
        */
#include <stdio.h>
int main(){ //small program that print max digit and min digit from 3 digit number
int num;
printf("Enter a number: \n"); 
scanf("%d" ,&num);//collect 3 digit number from user.
int d1=num/100,d2=(num/10)%10,d3=num%10; //d1=left digit ,d2=middile digit ,d3=right digit
if (d1>d2){ //block to see which digit is the max
	if(d1>d3)
		printf("Max digit is: %d\n",d1);
	else
		printf("Max digit is: %d\n",d3);
}else{
	if(d2>d3) 
		printf("Max digit is: %d\n", d2);
	else
		printf("Max digit is: %d\n", d3);
} //block to see which digit is min
if (d1<d2){ 
	if (d1<d3)
		printf("Min digit is: %d\n", d1);
	else 
		printf("Min digit is: %d\n", d3);
}else
	if (d2<d3)
		printf("Min digit is: %d\n",d2);
	else
		printf("Min digit is: %d\n",d3);

        return 0;
}
