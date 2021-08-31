/* Assignment: 4
Author: Sagi Bitton, ID: 205620859*/

#include <stdio.h>
#include <stdlib.h>

void BuildMatrix(int*** matrix,int row,int column); //function that create matrix once user input row and col sizes.
void PrintMatrix(int **matrix,int row,int column); //function that print elements in matrix.
void InsertMatrix(int **matrix,int sizerow,int sizecol); //function that collect elements into matrix.
void FreeMatrix(int*** matrix,int row); //function that free all memory that allocated.
int** MultiplyMatrixes(int **a,int** b,int size1,int size2,int size3); //function that gets 2 matrices multiply them and return new matrix.

int main(){  //size1=row for matrix1, size2=col for matrix1 && size2=row for matrix2 , size3=col for matrix2; //don't forget to free malcos!
   int** Matrix1;
   int** Matrix2;
   int** NewMatrix;
   int size1,size2,size3;
   printf("please enter size for rows in matrix1: \n");
   scanf("%d",&size1);
   printf("please enter size for columns in matrix1 which will be also size for rows in matrix2: \n");
   scanf("%d",&size2);
   printf("please enter size for columns in matrix2: \n");
   scanf("%d",&size3);
   BuildMatrix(&Matrix1,size1,size2);
   BuildMatrix(&Matrix2,size2,size3);
   NewMatrix=MultiplyMatrixes(Matrix1,Matrix2,size1,size2,size3);
   PrintMatrix(NewMatrix,size1,size3);
   FreeMatrix(&NewMatrix,size1);
   NewMatrix=NULL;
   return 0;
}


void BuildMatrix(int*** matrix,int row,int column) 
{
    int i,j,t;
    (*matrix)=(int**)malloc(row*sizeof(int*)); //allocate array of pointes(row)
    if ((*matrix) == NULL) 
    {
    printf("error - unable to allocate required memory!\n");
    exit(1);
    } 
    for(i=0;i<row;i++)
    {
        (*matrix)[i]=(int*)malloc(column*sizeof(int)); //creating array of cols by order 
         if ((*matrix)[i] == NULL) 
        {
            for(t=0;t<i;t++)
                free((*matrix)[i]); //if in some step we falied allocate moemory then free what allocated.
            free((*matrix));
        printf("error - unable to allocate required memory!\n");
        exit(1);
        } 
    }
    InsertMatrix((*matrix),row,column);
}

void InsertMatrix(int **matrix,int sizerow,int sizecol) //small function the input elements into matrix.
{
    printf("Enter %d numbers into matrix: \n",sizerow*sizecol);
    int j,i;
    for(i=0;i<sizerow;i++)
        for(j=0;j<sizecol;j++)
            scanf("%d",&matrix[i][j]);
    
}

void PrintMatrix(int **matrix,int row,int column)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
            printf("%5d  ",matrix[i][j]);
        printf("\n");
    }
}

void FreeMatrix(int *** matrix,int row) 
{
     int i;
     for(i=0;i<row;i++)
         free((*matrix)[i]);
    free((*matrix));
}

int** MultiplyMatrixes(int** a,int** b,int size1,int size2,int size3) 
{
    int** NewMatrix=NULL;
    int i,j,t,k,sum=0;
    NewMatrix=(int**)malloc(size1*sizeof(int*));
    if ((NewMatrix) == NULL) 
    {
    printf("error - unable to allocate required memory!\n");
    exit(1);
    } 
    for(i=0;i<size1;i++)
    {
        (NewMatrix)[i]=(int*)malloc(size3*sizeof(int));
         if ((NewMatrix)[i] == NULL) 
        {
            for(t=0;t<i;t++)
                free((NewMatrix)[i]);
            free((NewMatrix));
        printf("error - unable to allocate required memory!\n");
        exit(1);
        } 
    }
    for(i=0;i<size1;i++)
    {
        for(j=0;j<size3;j++)
        {
            for(k=0;k<size1;k++)
                sum+=(a[i][k])*(b[k][j]); //3 nested loop inorder to multiply 2 matrices
             NewMatrix[i][j]=sum;
             sum=0;
        }
       
    }
        return NewMatrix;
}