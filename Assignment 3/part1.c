/* Assignment: 3
Author: Sagi Bitton, ID: 205620859*/
#include <stdio.h>
#define SIZE 100 //define for first function
#define SIZE2 12 //define for second function
typedef enum { FALSE, TRUE } Boolean;

void Primes(int arr[], int size);
void PrintData1(int arr[], int size);
void Quick(float arr[], int size);
void input(float arr[], int size);
void PrintData(float arr[], int size);


int main() {
    int arr[SIZE] = { 0 }; //assign arr for 100 numbers
    float arr1[SIZE2] = { 0 }; //assign arr for 12 numbers.
    printf("100 prime numbers sorted ascending are: \n");
    Primes(arr, SIZE);
    PrintData1(arr, SIZE);
    printf("\n");
    printf("Please pill the arr with 12 real numbers: \n");
    input(arr1, SIZE2);
    Quick(arr1, SIZE2);
    PrintData(arr1, SIZE2);
    return 0;
}

void Primes(int arr[], int size) {
    int i, p, PrimeIndex, isPrime;
    arr[0] = 2;
    arr[1] = 3;
    PrimeIndex = 2;
    for (p = 5; p <= size; p = p + 2) {//iterrate over all odd numbers <=size
        isPrime = 1; //assume that it is prime
        for (i = 1; i < PrimeIndex; i++) {
            //if p is divisible by some prime i, then p is not prime
            if (p % arr[i] == 0)
                isPrime = 0;
        }
        if (isPrime == 1) {
            arr[PrimeIndex] = p;
            PrimeIndex++;
        }
    }

}

void Quick(float arr[], int size) { //function that sort positive and negative numbers puted negative in left side and positive in right side.
    int temp, l, i = 0, j = size - 1;
    while (TRUE)
    {
        while (arr[i] < 0 && i < j) //i run from first left intger.
            i++;
        while (arr[j] > 0 && i < j) //j run from last right intger.
            j--;
        if (i < j) { // if i is positive and j is negative swap them!
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            //after swawping increase i and descrease j/            
            i++;
            j--;
        }
        else
            break;   // go out from loop once i>=j.
    }

}

void input(float arr[], int size) { //small function to collect numbers from user.
    for (int i = 0; i < size; i++)
        scanf("%f", &arr[i]);
}

void PrintData1(int arr[], int size) { //function that prints 100 prime numbers sorted by acsending
    for (int i = 0; i < 25; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void PrintData(float arr[], int size) { //small function that prints numbers from array.
    for (int i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

}