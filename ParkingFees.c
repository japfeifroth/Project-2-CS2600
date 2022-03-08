#include <stdio.h>
#include <stdlib.h>

//total allowable expenses
int allowableParkingExpenses(int days) {
    return 6 * days;
}

//gets inputed parkingFee before deductions
double getParkingFees() {
    double parkingFee = -1;

    do {
        scanf(" %lf", &parkingFee);
        if (parkingFee < 0) {
            printf("invalid input, try again\n");
        } else {
            printf("Thank You!\n");
        }
    } while (parkingFee < 0);

    return parkingFee;
}

//total expenses incurred
double parkingFeesAcrossDays(int days) {
    double cost = 0;
    for (int i = 0; i < days; i++) {
        printf("Enter parking fee for day %d: \n", i+1);
        cost += getParkingFees();
    }

    return cost;
}

//returns amount company saved
double parkingSavedToCompany(int days, double totalExpenses) {
    double cost = allowableParkingExpenses(days) - totalExpenses;
    
    //if we spend more than given, company saves nothing 
    if (cost < 0) {
        cost = 0;
    }
    return cost;
}

//returns cost to businessman
double parkingCostToBusinessman(int days, double totalExpenses) {
    double cost = totalExpenses - allowableParkingExpenses(days);
    
    //if we spend less than given, businessman owes nothing 
    if (cost < 0) {
        cost = 0;
    }
    return cost;
}

//unit testing
int main() {
    double cost;
    int days = 3;
    cost = parkingFeesAcrossDays(days);
    printf("total parking expenses: $%0.2f\n", cost);
    printf("money saved by company: $%0.2f\n", parkingSavedToCompany(days, cost));
    printf("money owed by businessman: $%0.2f\n", parkingCostToBusinessman(days, cost));
    return 0;
}