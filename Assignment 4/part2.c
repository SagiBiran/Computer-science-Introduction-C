/* Assignment: 4
Author: Sagi Bitton, ID: 205620859*/

#include <stdio.h>
#include <stdlib.h>

void BuildGroup(int** group, int* count); //function that create desired group input by user
void InitArray(int* ar, int size); //function that input elements into group by valid format!
void PrintGroup(int* group, int size); //funtion that print given group elements.
int* Union(int* group1, int size1,int* group2,int size2, int* sizeUnion); //funtion that gets 2 groups and return group1 Union group2 result
int* intersection(int* group1,int size1,int* group2,int size2, int* sizeInter); //funtion that gets 2 groups and return intersection result
int* Minus(int* group1,int size1,int* group2,int size2, int* sizeMinus); //funtion that gets 2 groups and return group1 minus group2 result

int main(){ 
    int sizeGroup1=0,sizeGroup2=0,sizeUnion=0,sizeInter=0,sizeMinus=0;
    int *group1=NULL,*group2=NULL,*ptrUnionGroup,*ptrInterGroup,*ptrMinusGroup;
    printf("please enter size of group1: \n");
    BuildGroup(&group1,&sizeGroup1);
    printf("please enter size of group2: \n");
    BuildGroup(&group2,&sizeGroup2);
    ptrUnionGroup=Union(group1,sizeGroup1,group2,sizeGroup2,&sizeUnion);
    printf("Union group is: \n");
    PrintGroup(ptrUnionGroup,sizeUnion);
    free(ptrUnionGroup);
    ptrUnionGroup=NULL;
    ptrInterGroup=intersection(group1,sizeGroup1,group2,sizeGroup2,&sizeInter);
    printf("Intersection group is: \n");
    PrintGroup(ptrInterGroup,sizeInter);
    free(ptrInterGroup);
    ptrInterGroup=NULL;
    ptrMinusGroup=Minus(group1,sizeGroup1,group2,sizeGroup2,&sizeMinus);
    printf("Minus group is: \n");
    PrintGroup(ptrMinusGroup,sizeMinus);
    free(ptrMinusGroup);
    ptrMinusGroup=NULL;

    return 0;
}

void BuildGroup(int** group, int* count){      
    *group=(int*)malloc(sizeof(int)*(*count));
    if (*group == NULL) 
    {
    printf("error - unable to allocate required memory!\n");
    exit(1);
    }      
    InitArray(*group, *count);   
}

void InitArray(int* ar, int size){
	int i,j;
    printf("now please enter integers into group: \n");
	for (i = 0; i < size; i++){
		scanf("%d", &ar[i]);
        for(j=0;j<i;j++) //inner loop in order to see same integers
        {
            while((ar[i])==(ar[j]))   
            {
                printf("same integer as before, please input another integer!: \n");
                scanf("%d",&ar[i]);
            } 
        }    
	}
}

/*********** Print array in accepted format*******************/
void PrintGroup(int* group, int size){
	int i=0;
    if(!size)    //condition if group is empty then print {}
        printf("{}\n"); 
    else if(size==1){
        printf("{%d}",group[i]);
    }
    else
    {
        printf("{%d,", group[i]);
        for (i = 1; i < size-1; i++)
            printf("%d,", group[i]);  //inorder to print group as accepted format.
        printf("%d}", group[size-1]);
    }        
	printf("\n");
}

int* Union(int* group1,int size1,int* group2,int size2, int* sizeUnion) //*group1 in order to print element in array
{
    int* UnionGroup=NULL;
    int i,j,k=0,counter=0,flag=0;
    for(i=0;i<size1;i++) //nested loop in order to see how many common intergers there is to know excatly size of array i want to make
    {
        for(j=0;j<size2;j++)
        {
            if(group1[i]==group2[j])
                counter++;
        }
    }
    *sizeUnion=size1+size2-counter; //UPDATE SIZE OF THE NEW ARRAY THAT WILL COME
    UnionGroup=(int*)malloc((size1+size2-counter)*sizeof(int));
    if (UnionGroup == NULL) {
    printf("error - unable to allocate required memory!\n");
    exit(1);
    }      
    for(i=0;i<size1;i++){ //first copy all intergers from group1 into newarray
        UnionGroup[k]=group1[i];
        k++;
    }
    for(i=0;i<size2;i++) 
    {
    flag=0;
        for(j=0;j<size1;j++){
            if(group2[i]==group1[j])//affer copy group1 into new array,nested loop inorder to duplicate integers and delete them!
                flag++;
            }
        if(flag==0){
            UnionGroup[k]=group2[i];
            k++;
        }
    }
    return UnionGroup;
}

int* intersection(int* group1,int size1,int* group2,int size2, int* sizeInter)
{
    int* InterGroup=NULL;
    int i,j,k=0,counter=0;
    for(i=0;i<size1;i++) //nested loop in order to see how many common intergers there is to know excatly size of array i want to make
    {
        for(j=0;j<size2;j++)
        {
            if(group1[i]==group2[j])
                counter++;
        }
    }
    *sizeInter=counter;
    InterGroup=(int*)malloc((counter)*sizeof(int));
    if (InterGroup == NULL) {
    printf("error - unable to allocate required memory!\n");
    exit(1);
    }
    for(i=0;i<size1;i++) 
    {
        for(j=0;j<size2;j++)
        {
            if(group1[i]==group2[j]){
                InterGroup[k]=group1[i];
                k++;
            }
        }
    }
    return InterGroup;
}


int* Minus(int* group1,int size1,int* group2,int size2, int* sizeMinus)
{
    int* MinusGroup=NULL;
    int i,j,k=0,counter=0,flag;
    for(i=0;i<size1;i++) //nested loop in order to see how many common intergers there is to know excatly size of array i want to make
    {
        for(j=0;j<size2;j++)
        {
            if(group1[i]==group2[j])
                counter++;
        }
    }
    *sizeMinus=size1-counter;
    MinusGroup=(int*)malloc((*sizeMinus)*sizeof(int));
    if (MinusGroup == NULL) {
    printf("error - unable to allocate required memory!\n");
    exit(1);
    }
    for(i=0;i<size1;i++) 
    {
        flag=0;
        for(j=0;j<size2;j++)
            {
            if(group1[i]==group2[j])
                    flag++;
            }
        if(flag==0)
        {
            MinusGroup[k]=group1[i];
            k++;
        }
    }
    return MinusGroup;
}

