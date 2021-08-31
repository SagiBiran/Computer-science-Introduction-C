/* Assignment: 2
Author: Sagi Bitton, ID: 205620859
*/

#include <stdio.h>
typedef enum {FALSE,TRUE} BOOL;

int Series();
int TwoPrimes();
void Rectangle(int height,int width);
long Omit(long number, int digit);
int Third();
/*-----------------------------------------------------------------Main-------------------------------------------------------*/
int main(){

int num,height,width,digit;
long number;
do		{
	printf("1-Series\n2-Two primes\n3-Rectangle\n4-Omit digit\n5-Third\n6-Quit\n");
	scanf("%d",&num); //choice for case
	switch (num)	{
		case 1:
			Series();
			break;
		case 2:
			printf("The amount of Three-digit numbers that have exactly 2 prime factros is: %d\n",TwoPrimes());
			break;
		case 3:
			do{
				printf("please enter height and width between 1-18 for drawing rectangle: \n");
				scanf("%d %d",&height,&width);}
			while (!((width>=1 && width<=18) && (height>=1 && height<=18)));
			Rectangle(height,width);
			break;
		case 4:
			printf("please enter a number and digit to omit from this number:\n");
			scanf("%ld\n%d",&number,&digit);
			printf("%ld\n",Omit(number,digit));
			break;
		case 5:
			printf("%d\n",Third());
			break;
		case 6:
			printf("Good bye!\n");
			break;

			}
	if (num<1 || num>6) //user get this messeage if entered wrong number!
		printf("\ninvalid number please try again!\n\n");
		}

while (num<1 || num>6); //if user entered illegal number then show menu again and again. 
	return 0;
	}
//***********************************targil 5***************************************************************************************
int Third(){ //function that get series of positive numbers and return third largest number from this series.
int num,max1=0,max2=0,max3=0,counter=0;
printf("please enter positive numbers: \n");
scanf("%d",&num);
if (num>0)	{ //condition for first input
	do		{ 
			counter++; //counter to identify serires of 3 numbers atleast.
		if (num>max1){ 
			max3=max2;	
			max2=max1;
			max1=num;
			     }
		else if (num>max2){ //manipulations inorder to get the third largest number.
			max3=max2;
			max2=num; }
		else if (num>max3)
			max3=num;
	scanf("%d",&num);
			}
	while (num>0);{ //program will receive numbers as long as its positive numbers.
	if (counter>=3) //codition if series has atleast 3 numbers on it.
		return max3;
	else
		return -1;
		      }
		}
else // if condition failed in first input 
    return -1;
	 }
//***********************************targil 4***************************************************************************************
long Omit(long number, int digit)    {//function that get number and digit and return number without this digit.
long result=0,multiplier=1; 
    while (number>0) { 
        int CurrentDigit=(int)number%10; //CurrentDigit collect last digit every iteration
        if (CurrentDigit!=digit) { 
            result+=multiplier*CurrentDigit; //if given digit from user is diff from currentdigit then take current digit multiply by 10th position and add to result.
            multiplier*=10;
        			 }
        number/=10;
    		     }
    return result;		     }
//***********************************targil 3***************************************************************************************
void Rectangle(int height,int width){ //function that gets width and height and print special Rectangle!
int i,j;
for (i=0;i<height;i++){ //loop for first colum.
	for(j=0;j<width;j++){ // loop for first row.
		 if((i+1<=j+1) && (i+1<=height-i) && (i+1<=width-j))
        		printf("%d",i+1);
   		 else if((j+1<=i+1) && (j+1<=height-i) && (j+1<=width-j))           /*4 conditions in order to find min variable and print him by order!!*/
       	 		printf("%d",j+1);
    		 else if((height-i<=j+1) && (height-i<=i+1) && (height-i<=width-j))
        		printf("%d",height-i);
    		 else if((width-j<=j+1) && (width-j<=height-i) && (width-j<=i+1))
        		printf("%d",width-j);
		
			    }
    	printf("\n");
		       }
				     }
//***********************************targil 2***************************************************************************************
int PrimeFactors(int num);
int isPrime(int div);
int TwoPrimes(){
int counter=0; //function that return amount of 3 digits numbers that has exactly 2 prime factors.
for(int num=100;num<=999;num++){ //loop to check prime factors only for 3 digit numbers!
	if(PrimeFactors(num)){
		counter++;
 			     }
			       }
	return counter;
	 	}
// function to check if given factor is prime factor or not.
int isPrime(int div) {
int i, isPrime = TRUE; //given factor is prime unless it will proof to be not!
for (i=2;i<=div/2;++i) 	       {
	if (div%i==FALSE) {
            isPrime=FALSE;
            break;	  }
                               }
    return isPrime;
                    }
// function to check if number is divide by exactly 2 prime numbers.
int PrimeFactors(int num){
int div,tempdiv=FALSE; //div = divider 
for (div=2;div<=num;div++){ //
	if (num%div==FALSE) {//condition for checking if num has factors!
		if(isPrime(div)==TRUE) //check if that factors are prime or not.
			tempdiv++;
			for(num=num/div;num%div==FALSE;num=num/div) //while loop inorder to check for similar prime factors!				
				tempdiv++;	
			    }		
			  }
if(tempdiv==2) //Checking if number has 2 exactly prime factors!
	return TRUE;
else
	return FALSE;
			}
//***********************************targil 1***************************************************************************************
int Series(){ //function that collect series of positive numbers only! and return details. 
int num,len=0,even=0,odd=0,min,max;
printf("please enter positive number: \n");
scanf("%d",&num);
if (num>0){ //condition if the first number is positive
	len++;
	if (num%2==0) //condition for even and odd.
		even++;
	else
		odd++;
	min=num; //collect min and max 
	max=num;
	printf("please enter positive number: \n");
	scanf("%d",&num);
	while(num>0){ //loop untill user enter non positive number to collect series of positive numbers.
		len++;
		if (num%2==0)
			even++;
		else
			odd++;
		if(num>max)  //update min and max
			max=num;
		if(num<min)
			min=num;
		printf("please enter positive number: \n");
		scanf("%d",&num);
		    }  
		printf("Length = %d\nEven = %d\nSum Odd = %d\nMin = %d\nMax = %d\n",len,even,odd,min,max);	
	}
else
	printf("invalid number!\n"); //user gets this messeage if entered non positive number first.
              }
