#include <stdio.h>
#include <stdlib.h>
#include "expensesRoundTripCarRental.h"

//Function that stores round trip flight total cost
float getRoundTripTotal(){
    float total = -1.0;
    while(total < 0){
        printf("What is the total price of Round Trip Flight?\n");
        scanf("%f", &total);
        getchar();
        if(total < 0.0){
            printf("This is not a valid time slot, Please re-enter price\n");
        }
    }
    return total;
}

//Function that stores car rental total cost
float getCarRentalTotal(){
    float total = -1.0;
    while(total <0){
        printf("What is the total price of Car Rentals?\n");
        scanf("%f", &total);
        getchar();
        if(total < 0.0){
            printf("This is not a valid time slot, Please re-enter price\n");
        }
    }
    return total;
}

/*Unit testing functions
int main() {
    double totalFlight = getRoundTripTotal();
    double totalCar = getCarRentalTotal();
    printf("Flight cost total stored is: %.2f\nCar rental cost total stored is: %.2f", totalFlight, totalCar);
    return 0;
}
*/