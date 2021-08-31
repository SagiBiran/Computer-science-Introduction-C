/* Assignment: 4
Author: Sagi Bitton, ID: 205620859*/

#define SIZE 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum {FALSE,TRUE} bool;
 
void Init(char*** names,int** grade,int* size); //small function that collect number of student and input names for student and grades into arraies.
int Find(char** names,int* grades,int size,char* name); //functin that gets student name and return his grade if student doesn't exist then grade is -1
void FreeText(char*** names, int ** grades, int size); //function that free all memory that allocated.
bool isUpper(char);//checks whether a character is a large letter
bool isLower(char);//checks whether a character is a small letter
bool isValid(char *string); //function that check if given names is Valid name (first letter is latin uppercase and other is latin lowercase)
bool DuplicateString(char***names,char *string,int i); //function that check whether student name is already inputed 


int main()
{
	char** names = NULL;
    int* grades=NULL;
	int size;
	char rNAME[SIZE];
	Init(&names, &grades,&size);
	printf("please enter any name to see his grade: \n");
	scanf("%s",rNAME);
	printf("%s grade is %d\n",rNAME,Find(names,grades,size,rNAME));
	FreeText(&names,&grades,size);
	names=NULL;
	grades=NULL;
	return 0;

}

void Init(char*** names,int** grade,int* size) //names=&names //size=&size //grade=
 {
	int i,t,temp=0;
    char bufferhelp[SIZE];
	printf("Please enter number of students: \n");
	scanf("%d", size);
 	*names = (char**)calloc(*size,sizeof(char*)); //allocating first array (numbers of student )
	if (*names == NULL) {
		printf(" Not enougth memory!\n");
		exit(1);
	}
    *grade = (int*)malloc(*size*sizeof(int)); //allocating grade array .
    if (*grade == NULL)
    {
		printf(" Not enougth memory!\n");
		exit(1);
    }
	for(i=0;i<*size;i++)
	{
		printf("Please enter student No.%d name: \n",i+1);
		scanf("%s",bufferhelp);
		while((DuplicateString(names,bufferhelp,i))||isValid(bufferhelp)) //loop the send to other function to check whther given string is valid!
		{
			printf("bad name. Try again\n");		//once failed then user request to input other name of student.														
			scanf("%s", bufferhelp);
		}
		(*names)[i] = (char*)malloc(strlen(bufferhelp) + 1); //+1 for '\0'
		if ((*names)[i] == NULL){
		printf(" Not enougth memory! \n");
		for(t=0;t<i;t++)
                free((*names)[i]);  //if in some step we falied allocate moemory then free what allocated.
            free((*names));
		exit(1);
		}
		strcpy((*names)[i], bufferhelp);
		printf("Enter student No.%d grade: \n",i+1);
		scanf("%d",&temp);
        while(!(temp>=0 && temp <=100)) //condition to check if given number is valid numbers that should look as valid grade
		{
			printf("please enter valid grade! \n");
			scanf("%d",&temp);

		}
       (*grade)[i]=temp;
	}

 }

void FreeText(char*** names, int ** grades, int size) { //small function that free all memory that allocated. 
	for (int i = 0; i < size; i++)
		free((*names)[i]);
	free(*names);
	free(*grades);
}

bool isUpper(char letter) {
	return letter >= 'A' && letter <= 'Z';
}
bool isLower(char letter) {
	return letter >= 'a' && letter <= 'z';
}

bool isValid(char *string) //function gets name of student and check if that name is valid
{
    int j=0;
        if(isUpper(string[0]))
        {
            for(j=1;j<strlen(string);j++) //checking if after first letter all letters are valid(latin lowercase letters/)
            {																																			//Sagi
                if(isLower(string[j]))
                    continue;
                else
                    return TRUE;
            }
            return FALSE;
        }
        else
            return TRUE;    
}

bool DuplicateString(char***names,char *string,int i)  //function that return false once user input duplicate student name!
{
	int j;
	for(j=0;j<i;j++)
	{
		if(strcmp((*names)[j],string)==0)
			return TRUE;
	}
	return FALSE;
}

int Find(char** names,int* grades,int size,char* name) //function that gets name of student and return his grade.
{
	int i;
	for(int i=0;i<size;i++)
	{
		if(strcmp((names)[i],name)==0)
			return grades[i];
		else
			continue;
	}
	return -1;
}