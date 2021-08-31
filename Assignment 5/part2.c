/* Assignment: 5
Author: Sagi Bitton, ID: 205620859*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 30
typedef enum {FALSE,TRUE} bool;

/*Declaration of structures*/
typedef struct //size 40bytes
{
	char name[SIZE];
	int amount,price;
}Product;

typedef struct {
	int id;
    Product* pProd; //SIZE OF Product* is 8 bytes
    int numProd;
}Cart;

/*Declaration of functions*/
void InputProduct(Product* pProduct);
void PrintProduct(Product prod);
void InputCart(Cart* pCart);
void PrintCart(Cart crt);
int InitCashReg(Cart** ppQueue);
void FreeAll(Cart** ppQueue, int size);
void PrintAll(Cart* pQueue, int size);
void Payment(Cart* pQueue,int size);

int main(){ 
    Cart* pQueue=NULL;
    int size;
    size=InitCashReg(&pQueue);
    PrintAll(pQueue,size);
    Payment(pQueue,size);
    FreeAll(&pQueue,size);
    return 0;

}

void InputProduct(Product* pProduct) //pProduct == &prodct1 //*pProduct==prodct1 //*pProduct.name == pProduct->name // &(*pProduct.price) == inset someting into price //&pProduct.price
{
	/*A function that fills Product's fields*/
	printf("\nName of product, Quantity of items purchased and Price per product: \n");
	scanf("%s%d%d", (*pProduct).name,&pProduct->amount,&pProduct->price);
}

void PrintProduct(Product prod)
{
    printf("\nName of product: %s\nQuantity amount product purchased by Customer: %d\nPrice per product: %d\n",prod.name,prod.amount,prod.price);
}

void InputCart(Cart* pCart)
/*A function that fills the fields of a structure named Cart*/
{
    int i;
    printf("\nPlease enter id of Customer:\n");
	scanf("%d", (&(*pCart).id));
    printf("\nPlease enter number of different products purchased by Customer:\n");
	scanf("%d", (&(*pCart).numProd));
    (*pCart).pProd = (Product*)malloc(sizeof(Product)*pCart->numProd); //intialize dynamic array for different item purchased by Customer.
	if (pCart->pProd == NULL)
    {
		printf("Not enouth memory\n"); //MAYBE FREE ALL MEMORY ALLOCATED
	}
    printf("\nNow enter data for %d products:\n", pCart->numProd); //collecting information about each product that Customer bought
	for (i = 0; i < pCart->numProd; i++)
		InputProduct(&((*pCart).pProd)[i]);
}

void PrintCart(Cart crt) //crt == int id =205620859 product* - 2 array of product
{
    int i;
    printf("\nID number of Customer is: %d\n",crt.id);
    printf("\nData for %d products bought by this Customer: \n",crt.numProd);
    for(i=0;i<crt.numProd;i++)
    {
         PrintProduct(crt.pProd[i]); //will print every product bought by Customer - crt.pProd is type of PRODUCT as request in printproduct function.
    }
}

int InitCashReg(Cart** ppQueue)
/*A function that builds a dynamic array of elements from the type of struct Cart*/
{
    int size, i, status;
	printf("\nPlease enter number of Carts:\n");
	scanf("%d", &size);
    *ppQueue = (Cart*)malloc(sizeof(Cart)*size); //intialize dynamic array of CARTS.
	if (*ppQueue == NULL) {
		printf("Not enouth memory");
		exit(1);
	}
    printf("\nPlease enter data for %d carts:\n", size);
	for (i = 0; i < size; i++) {
		InputCart(&(*ppQueue)[i]);
	}
	return size;
}
void FreeAll(Cart** ppQueue, int size) //*ppQueue=ppQueue && ppQueue =&ppQ
/*A function that frees all of the dynamic memory*/
{
    int i;
    for (i=0;i<size;i++)
    {
        free((*ppQueue)[i].pProd);
            (*ppQueue)[i].pProd=NULL;
    }
    free(*ppQueue);
    *ppQueue=NULL;
}

void PrintAll(Cart* pQueue, int size) //pQueue==&&pQueue
/*function that prints all information about all carts*/
{
    int i;
    for(i=0;i<size;i++)
    {
        PrintCart(pQueue[i]);
    }
}

void Payment(Cart* pQueue,int size) 
{
    int i,j,count=0; //counter to count total price of product purchased by Costumer.
    for (i=0;i<size;i++) //first loop for amount of carts/
    {
       for(j=0;j<pQueue[i].numProd;j++) //second loop for amount of different products
        count+=pQueue[i].pProd[j].amount*pQueue[i].pProd[j].price; 
        printf("\nCustomer %d, Total Payment: %d\n",i+1,count);
        count=0;
    }
}
