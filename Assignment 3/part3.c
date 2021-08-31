/* Assignment: 3
Author: Sagi Bitton, ID: 205620859*/

#include <stdio.h>
#define LEN 80
#define ENGLISH_LETTERS 26
typedef enum {False,True} Bool;

int StrLen(char[]);//returns the amount of characters 
Bool isUpper(char);//checks whether a character is a large letter
Bool isLower(char);//checks whether a character is a small letter

void Histogram(char[]);//print histogram for given string
void ReverseString(char str[LEN]);// reverse given string
void ReverseLetters(char str[LEN]); //reverse every letter for reversed string
void AsciiAddition(char str[LEN]); //add +1 ascii code by order for each letter
void enCode(char str[LEN]); //return string after lunched 3 last functions.

/*------------------------- Main ------------------------------*/

int main(){
    char str[LEN];
    printf("Enter your string :");
	fgets(str, LEN, stdin); //collect string from user.
	int len = StrLen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
    Histogram(str); //lunch histogram functions
    enCode(str); 
    printf("your new string is: %s \n",str); //printing new str (ex: 7,8,9 done)

    return 0;
}

int StrLen(char str[]) { 
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

Bool isUpper(char letter) {
	return letter >= 'A' && letter <= 'Z';
}
Bool isLower(char letter) {
	return letter >= 'a' && letter <= 'z';
}


void Histogram(char str[]) {
	int counters[ENGLISH_LETTERS] = {0};//Counter array, will count the number of impressions each character in the string
	int i = 0, maxIndex;
	while (str[i] != '\0') {
		if (isUpper(str[i]))
			counters[str[i] - 'A'] += 1;
		if (isLower(str[i]))
			counters[str[i] - 'a'] += 1;
		i++;
	}
    printf("letter \tHistogram\n"); //heading for histogram function.
    for(int j=0;j<ENGLISH_LETTERS;j++){
        if(counters[j]==0)
            continue; //skip letters with appearnaces.
        printf("%c \t",j+'a');
        for(int l=0;l<counters[j];l++)
            printf("*");
        printf("\n");
    }
}

void ReverseString(char str[LEN]){
    char str2[LEN]; //reverse given string.
    int len=StrLen(str),start,end=len-1,i=len-1,j,f=0;
    while(i>0){ //LOOP RUNING OVER INDEX ON STRING GIVEN
        for(i;i>=0;i--){ //loop over string
            if(str[i]==' '){//if we found an backspace over string.
                start=i+1; 
                for(start;start<=end;start++){ // loop to put every char by order.
                    str2[f]=str[start];
                        f++;}
                str2[f]=' '; //adding space after finish one word
                        f++;
                end=i-1; //move e to one before backspace
            }
            if(i==0){ //statement when index get to end of reverse(string) i.e 0
                start=i;
                for(start;start<=end;start++){
                    str2[f]=str[start];
                        f++;}
                    str2[f]='\0'; //end of string reversed.
            }    
        } 
    }
    int h;
    for(h=0;str2[h];h++) //in order to save last str
        str[h]=str2[h];
    str[h]=0;
} 
void ReverseLetters(char str[LEN]){
    char str2[LEN];
    int start=0,end,i=0,f=0; 
    while(str[i]!='\0'){ //LOOP RUNING OVER INDEX ON STRING GIVEN
        for(i=0;i<LEN;i++){ //loop over string
            if(str[i]==' '){//if we found an backspace over string.
                end=i-1; 
                for(end;end>=start;end--){ // loop to put every char by order.
                    str2[f]=str[end];
                        f++;}
                str2[f]=' '; 
                        f++;
                start=i+1; //move start to one after backspace
            }
            if(str[i]=='\0'){ //statement  when index get to end of reverse(string) i.e 0
                end=i-1;
                for(end;end>=start;end--){
                    str2[f]=str[end];
                        f++;}
                str2[f]='\0';
                break; //end of string reversed.
            }
        } 
    } 
    int h;
    for(h=0;str2[h];h++) //in order to save last str
        str[h]=str2[h];
    str[h]=0; 
}
void AsciiAddition(char str[LEN]) {
    int start=0,end,i=0,f=0; 
    char str2[LEN];
    while(str[i]!='\0'){ //LOOP RUNING OVER INDEX ON STRING GIVEN
        for(i=0;i<LEN;i++){ //loop over string
            int j=1; //Assign j and increase inorder to get next letter + 2 ascii code
            if(str[i]==' '){//if we found an backspace over string.
                end=i-1; //put s one before backspace
                for(start;start<=end;start++){ // loop to put every char by order.
                    str2[f]=str[start]+j;
                        j++; 
                        f++;} //increasing index in new string.
                str2[f]=' ';
                        f++;
                start=i+1; //move start to one before backspace
            }
            if(str[i]=='\0'){ //statement  when index get to end of reverse(string) i.e 0
                end=i-1;
                for(start;start<=end;start++){
                    str2[f]=str[start]+j;
                        j++;
                        f++;}
            str2[f]='\0';
            break;
                     //end of string reversed.
            }
        } 
    }
    int h;
    for(h=0;str2[h];h++)
        str[h]=str2[h]; //in order to save last str
    str[h]=0;
}
void enCode(char str[LEN]){ //function that do whole other functions.
    ReverseString(str);
    ReverseLetters(str);
    AsciiAddition(str);
}

