/* Assignment: 4
Author: Sagi Bitton, ID: 205620859*/

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 80
typedef enum {FASLE,TRUE} bool;

char* CreateString(char* string1, char* string2); //gets 2 string and return new string in spical version 
char* Palindroms(char* str); //get some sentence from user and return palindrom strings.
bool isPalindrom(char* string); //function that return true if given string is palindrom string

int main() { 

    char str1[SIZE], str2[SIZE],str3[SIZE];
    char* newstring;
    char* newpalindromstr;
    printf("please enter 2 strings: \n");
    fgets(str1, SIZE, stdin);
    fgets(str2, SIZE, stdin);
    str1[(int)strlen(str1) - 1]='\0';   
    str2[(int)strlen(str2) - 1] = '\0';
    newstring=CreateString(str1, str2);
    printf("%s\n", newstring);
    free(newstring);
    newstring=NULL;
    printf("now please enter another string: \n");
    fgets(str3, SIZE, stdin);
    str3[(int)strlen(str3) - 1]='\0';
    newpalindromstr=Palindroms(str3);
    printf("%s\n", newpalindromstr);
    free(newpalindromstr);
    newpalindromstr=NULL;
        return 0;
}

char* CreateString(char* string1, char* string2) { 
int size=(int)strlen(string1)* (int)strlen(string2)+ (int)strlen(string1); //maybe add +1 for '\0' later
char* newstr;
newstr = (char*)malloc(size * (sizeof(char)));
    if (newstr == NULL) 
    {
    printf("not enough memory in heap\n");
    exit(1);
    }
    for (int i = 0,j=0; i < (int)strlen(string1); i++,j+=4) {
    newstr[j]=string1[i];
    strcat(newstr, string2);
    }
    return newstr;
}

char* Palindroms(char* str){ //token=&str
    char delim[] = " ",temp[SIZE],buffer[SIZE]={}; //temp to send to isPalindrom function, buffer to collected whole palindrom word
    char* token;
    char* goodstring;
    for (token = strtok(str, delim); token; token = strtok(NULL, delim)) 
    {
        strcpy(temp,token); //temp will be token in order to send it into isPalindrom function
        if(isPalindrom(temp))
        {
            int length=strlen(temp);
            temp[length]=' ';
            temp[length+1]='\0';
            strcat(buffer,temp);
        }
        else //if it is not palindrom word continue looping
            continue;
        
    }
    buffer[strlen(buffer)-1]='\0'; //setting '/0' to last char in strings!
    goodstring=(char*)malloc(strlen(buffer)+1); 
    if (goodstring == NULL)
     {
		printf(" Not enough memory! ");
		exit(1);
	}
    else 
        strcpy(goodstring,buffer);
    
    return goodstring;
}

bool isPalindrom(char* string){ //string=&temp
    int s=0,e=(int)strlen(string)-1;
    while(e>s)
    {
        if(string[s++]!=string[e--])
            return FASLE;
    }
    return TRUE;
    
}

