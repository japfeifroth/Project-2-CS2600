#include <stdio.h>
#include <stdlib.h>

double getParkingFees() {
    double parkingFee = -1;
    double cost;

    do {
        printf("Enter parking fee: \n");
        scanf(" %lf", &parkingFee);
        if (parkingFee < 0) {
            printf("invalid input, try again\n");
        } else {
            printf("Thank You!\n");
        }
    } while (parkingFee < 0);

    if (parkingFee - 6 <= 0) {
        cost = 0;
    } else {
        cost = parkingFee - 6;
    }

    return cost;
}

//unit testing
int main() {
    double cost;
    cost = getParkingFees();
    printf("cost of parking fees to employee: %0.2f\n", cost);
    return 0;
}