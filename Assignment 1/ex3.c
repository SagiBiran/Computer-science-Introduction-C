/*Assignment: 3
        Author: Sagi Bitton, ID:205620859
        */
#include <stdio.h>
int main(){ //small program to print similar digit in same location between two 4 digit numbers.
int  num1,num2,counter=0; 
printf("please enter two '4 digit' numbers: \n");
scanf ("%d %d" ,&num1,&num2);
if ((num1>=1000 && num1<=9999) && (num2>=1000 && num2<=9999)){ //checking if input is valid
	if (num1%10 == num2%10) 
		counter++;
	if ((num1/10)%10 == (num2/10)%10)
		counter++;
	if ((num1/100)%10 == (num2/100)%10) 
		counter++;
	if ((num1/1000) == (num2/1000))
		counter++;
	printf("%d \n",counter);} //print how many times digits were similar}

else
	printf("numbers are not valid!: \n"); //in case that user inputed invalid numbers.
        return 0;
}
