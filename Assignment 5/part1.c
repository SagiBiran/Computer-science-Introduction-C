/* Assignment: 5
Author: Sagi Bitton, ID: 205620859*/

#define SIZE 80
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum {FALSE,TRUE} bool;

bool CheckNumber(int number);
bool Equal(int number,int sum);
int sumdigit (int number); //help recursive function that find the sum digit of given number.
int Creator(int number);
void Reducing (char* string);
int MinMaxArray(int arr[],int size,int* pMin,int* pMax);
bool CheckString(char* pStart, char* pMiddle);
int Compare(char* string1 ,char* string2);
bool ignoreLowUpCaseChar (char **pStart,char **pMiddle); //small function that get 2 char and return TRUE/FALSE if they are equal
                                                            // that function ignore lower or uppercase!

int main(){
    int number,number2, sum ,number3,arr[]={1,5,6,3,9},sizeArray=5;
    int min=arr[0],max=0; 
    char string1[SIZE],string2[SIZE],string3[SIZE],string4[SIZE];
    /*Lunch assignment 1*/
    printf("please enter a number to check whether all his digits are even or not \n");
    scanf("%d",&number);
    if(CheckNumber(number))
        printf("All digits of the number are even!\n\n");
    else
        printf("Not all digits of the number are even!\n\n");

    /*Lunch assignment 2*/
    printf("now, please enter a number:\n");
    scanf("%d",&number2);
    printf("please enter another number to check if sum digit of last number are equal to this number: \n");
    scanf("%d",&sum);
    if(Equal(number2,sum))
        printf("The sum of the digits from first number are equal to the value of second number!\n\n");
    else
        printf("The sum of the digits from first number are NOT equal to the value of second number!\n\n");

    /*Lunch assignment 3*/
    printf("please enter a integer to see his new represent that composed from even digit only!\n");
    scanf("%d",&number3);
    printf("new integer is: %d\n\n",Creator(number3));
    
    /*Lunch assignment 4*/
    printf("now please enter any string: \n");
    scanf("%s",string1);
    printf("New reverse VALID string are: ");
    Reducing(string1);
    printf("\n\n");

    /*Lunch assignment 5*/
    printf("for assignment 5 i've already initialized an array and his size so the result from this function is: \n");
    printf("%d\n\n",MinMaxArray(arr,sizeArray,&min,&max));

    /*Lunch assignment 6*/
    printf("now please enter any string: \n");
    scanf("%s",string2);
    if(CheckString(string2,&string2[strlen(string2)/2])) //&string2[strlen(string2)/2]) means middle of string
        printf("string are composed from 2 inside equal strings! \n\n");
    else
        printf("string are NOT composed from 2 inside equal strings! \n\n");

    /*Lunch assignment 7*/
    printf("LAST REQUEST! please enter 2 string to count same digits between them : \n");
    scanf("%s",string3);
    scanf("%s",string4);
    printf("There is %d same chars in same position between 2 strings!\n\n",Compare(string3,string4));
    return 0;

}

bool CheckNumber(int number) //small function that gets number and checks every digit to see if he is even.
{
    if (number==0) //base case ,if given number is 0 then it's even or reach 0 by recursion.
        return TRUE;
    else
    {
        if (number%2 !=0) //once we face odd number then return FALSE and exit program.
            return FALSE;
        else
            CheckNumber(number/10);
    }
}
bool Equal(int number,int sum) //small function the count sumdigit of number and check if equal to other given number.
{
    int sDigits; //variable that holds sum digits of given number.
    sDigits=sumdigit(number);
    if (sDigits==sum)
        return TRUE;
    else
        return FALSE;

}

int sumdigit (int number) //help recursive function that find the sum digit of given number.
{
     if (number==0)
        return 0;
     else
        return number%10+sumdigit(number/10);
}

 int Creator(int n){
    if (n == 0)
        return 0;//we should always return a value
    if (n % 2 != 0)
        return Creator(n / 10);
    return n % 10+Creator(n / 10) * 10 ; //It is necessary to accumulate the call result.
}

void Reducing (char* string) //string =&str
{
    if(*string=='\0')
        return;
    if((*string>= 'A' && *string<='Z') || (*string >='a' && *string<='z'))
    {
        Reducing(string+1);
        printf("%c",*string); //neccesary %d in order to print character represent by int value
    }
    else
    {
        Reducing(string+1);
        return;
    }
}

int MinMaxArray(int arr[], int size, int* pMin, int* pMax) // pMin==&min
{
	if (arr[0] < *pMin)
		*pMin = arr[0];
	if (size == 1)
	{
		printf("Min digit in array is: %d | Max digit in array is: ", *pMin);
		return arr[0];
	}

	else
	{
		*pMax = MinMaxArray(arr + 1, size - 1, pMin, pMax);
		if (arr[0] > *pMax)
			return arr[0];
		else
			return *pMax;

	}
}

bool CheckString(char* pStart, char* pMiddle) //PeacePelce
{
    if(*pMiddle=='\0') //base case, pointer from middle string reach end of string.
        return TRUE;
    else
    {
        if(ignoreLowUpCaseChar(&pStart,&pMiddle)) //everytime check whether to char are equal, if so, then return same function .
            return CheckString(pStart+1,pMiddle+1);
        else
            return FALSE; //once we found 2 different char then return FALSE and exit.
    }
}

int Compare(char* string1 ,char* string2)
{
    int counter=1;
    if((*string1=='\0')||(*string2=='\0')) //base case once one of the string reach the end.
        return 0;
    else
    {
        if(ignoreLowUpCaseChar(&string1,&string2)) //everytime check whether to char are equal, if so, then return same function .
            return counter + Compare(string1+1,string2+1);
        else
            return Compare(string1+1,string2+1); //if this is not the same char at all , then dont count, just call same function.
    }
}

bool ignoreLowUpCaseChar (char **pStart,char **pMiddle) //small function that return TRUE/FALSE wheter char is equal (ignore low/up case letter)
{
    if(((*pStart)[0])>((*pMiddle)[0]))
    {
        if(((*pStart)[0])==(((*pMiddle)[0])+32)) //+32 means, add 32 to smaller char and check if the decimal value are equal
            return TRUE;
        else
            return FALSE;
    }
    if(((*pStart)[0])<((*pMiddle)[0]))
    {    
        if((((*pStart)[0])+32)==((*pMiddle)[0]))
            return TRUE;
        else
            return FALSE;
    }
    else // if we reach this, then we have same char in both pointers. 
        return TRUE;
}

