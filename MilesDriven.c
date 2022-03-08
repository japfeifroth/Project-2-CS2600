#include <stdio.h>
#include <stdlib.h>

double getMilesDriven() {
    double milesDriven = -1;
    double cost;
    do {
        printf("Enter the number of Miles driven: \n");
        scanf(" %lf", &milesDriven);
        if (milesDriven < 0) {
            printf("Invalid Input, try again\n");
        } else {
            printf("Thank You!\n");
        }
    } while(milesDriven < 0);

    cost = milesDriven * 0.27;
    return cost;
}

//unit test
int main() {
    double cost;
    cost = getMilesDriven();
    printf("cost of miles driven: %0.2f", cost);
    return 0;
}
