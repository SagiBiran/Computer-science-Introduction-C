/* Assignment: 4
        Author: Sagi Bitton, ID: 205620859
 */
#include <stdio.h>
int main(){ //small program to check if given date is valid.
int day,month,year; 
printf("Please input the date: \n");
printf("Day: \n");
scanf("%d" ,&day);
printf("Month: \n");
scanf("%d" ,&month);
printf("Year (in formart: YYYY): \n");
scanf("%d" ,&year);
if(year>=1900){ //first checking if given year is valid.
	if (month==4||month==6||month==9||month==11){ //checking date for months that has 30 days
		if(day>=1&&day<=30)
			printf("The date is correct - %d/%d/%d\n",day,month,year);
		else
			printf("Incorrect date - %d/%d/%d\n ,input month has 30 days only!\n",day,month,year);}//checking date for months that has 31 days
	if (month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		if(day>=1&&day<=31)
			printf("The date is correct - %d/%d/%d\n",day,month,year);
		else
			printf("Incorrect date - %d/%d/%d\n ,input month has 31 days only!\n",day,month,year);}
	if (month==2){ //checking date for feburary with 28 days
		if(day>=1&&day<=28)
			printf("The date is correct - %d/%d/%d\n",day,month,year);}
	if (month==2){ //checking date for feburary with 29 days
        	if((day==29)&&((year%4==0)&&(year%100!=0))||((day==20)&&(year%400==0)))
			printf("The date is correct - %d/%d/%d\n",day,month,year);
		else if ((day==29)&&(year%4!=0)||((day==29)&&(year%400!=0)))
			printf("Incorrect date - %d/%d/%d\n ,current year has 28 days only in febuary\n",day,month,year);}}
else
	printf("incorrect date\n");
	return 0;}
