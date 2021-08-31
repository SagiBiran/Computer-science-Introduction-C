/* Assignment: 3
Author: Sagi Bitton, ID: 205620859*/

#include <stdio.h>
#define SIZE 5
void input(int arr[][SIZE],int size);
void Divide (int mat[SIZE][SIZE], int arr_lines[SIZE], int arr_cols[SIZE],int d);
void Printdata(int arr[],int size);

int main(){
int mat [SIZE][SIZE],d,arr_lines[SIZE]={0},arr_cols[SIZE]={0};
printf("please enter integers for matrix: \n");
input(mat,SIZE);
printf("please enter divider: \n");
scanf("%d",&d);
Divide(mat,arr_lines,arr_cols,d);
Printdata(arr_lines,SIZE);
printf("\n");
Printdata(arr_cols,SIZE);

    return 0;
}
void Divide (int mat[SIZE][SIZE], int arr_lines[SIZE], int arr_cols[SIZE],int d){ //small function that count every row and cols and see how many div by d.
   int i,j,l;
   if (d==0){ //statement if divider is 0.
   int arr_lines={0},arr_cols={0}; 
   }
   else { 
        for(i=0;i<SIZE;i++){
            for(j=0;j<SIZE;j++){
                if(mat[i][j]%d==0)
                    arr_lines[i]++;
            }
        }                            
        for(i=0;i<SIZE;i++){
            for(j=0;j<SIZE;j++){
                if(mat[j][i]%d==0)
                    arr_cols[i]++;
            }
        }
   }
}
void input(int arr[][SIZE],int size){ //small function to collect numbers from user.
    int i,j;
    for (i=0;i<size;i++){
        for (j=0;j<size;j++)
            scanf("%d",&arr[i][j]);
    }
    
}
void Printdata(int arr[],int size){ //small fucntion to print data.
     int i;
     for (i=0;i<size;i++)
        printf("%d ",arr[i]);
}