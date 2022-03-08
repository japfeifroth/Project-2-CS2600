#include <stdio.h>
#include <stdlib.h>

//total allowable expenses
int allowableTaxiExpenses(int days) {
    return 10 * days;
}

//gets inputed taxi fee before deductions
double getTaxiFees() {
    double taxiFee = -1;
    double cost;

    do {
        scanf(" %lf", &taxiFee);

        if (taxiFee < 0) {
            printf("invalid input, try again\n");
        } else {
            printf("Thank You!\n");
        }
    } while (taxiFee < 0);

    return taxiFee;
}

//total expenses incurred
double taxiFeesAcrossDays(int days) {
    double cost = 0;
    for (int i = 0; i < days; i++) {
        printf("Enter taxi cost for day %d: \n", i+1);
        cost += getTaxiFees();
    }

    return cost;
}

//returns amount company saved
double taxiSavedToCompany(int days, double totalExpenses) {
    double cost = allowableTaxiExpenses(days) - totalExpenses;
    
    //if we spend more than given, company saves nothing 
    if (cost < 0) {
        cost = 0;
    }
    return cost;
}

//returns cost to businessman
double taxiCostToBusinessman(int days, double totalExpenses) {
    double cost = totalExpenses - allowableTaxiExpenses(days);
    
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
    cost = taxiFeesAcrossDays(days);
    printf("total taxi expenses: $%0.2f\n", cost);
    printf("money saved by company: $%0.2f\n", taxiSavedToCompany(days, cost));
    printf("money owed by businessman: $%0.2f\n", taxiCostToBusinessman(days, cost));
    return 0;
}