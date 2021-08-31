/*Assignment: 1
	Author: Sagi Bitton, ID:205620859
	*/
#include <stdio.h>
#define initial_price 10.20 
#define price_per_km 1.30 
#define price_per_suitcase 2.00
int main(){ //small program that calculate price for taking taxi (depends on km and number of suitcases).
float req_km,req_sc; //declate 2 vairable . required km and number of suitcases
printf ("please enter your driving distance(km) and quantites of suitcases: \n");
scanf("%f %f",&req_km,&req_sc); 
float tprice=(initial_price + price_per_km*req_km + price_per_suitcase*req_sc);
printf("your driving price is %.2f: \n",tprice); //print total price for trip.
	return 0;
}
