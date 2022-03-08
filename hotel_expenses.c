#include <stdio.h>
#include <stdlib.h>
#include "conference_hotel_meal_functions.h"

/*5 functions that return: 
the input of the cost of the hotel room per day
the total cost of staying at the hotel for the entire trip (takes number of days on trip as an argument)
the total amount the company will cover for the entire trip (takes number of days on trip as an argument)
the amount the employee has to pay (takes number of days on trip, cost of the hotel room per day, and total expense of the hotel room for the entire trip as arguments)
the amount the employee saved if the cost per day was < $90 (takes number of days on trip, cost of the hotel room per day, and total expense of the hotel room for the entire trip as arguments)
*/

const double COVERED = 90.00; //amount the company covers per day

double hotel_cost_per_day(){
    double costPerDay = 0.0;
    do{
        printf("Cost of hotel room per day: $");
        fflush(stdout);
        scanf("%lf", &costPerDay);
        getchar();
        if (costPerDay < 0) //checks if input is negative
        {
            printf("input a value >= 0\n");
        }
    }while (costPerDay < 0);
    
    return costPerDay;
}

double hotel_total_expenses(int days, double cost){
    double totalCost = 0.0;
    totalCost = days * cost;
    return totalCost;
}

double hotel_total_covered(int days){
    double totalCovered = days * COVERED;
    return totalCovered;
}

double hotel_paid_by_employee(int days, double cost, double totalCost){
    double totalCovered = days * COVERED;
    double paidByEmployee = 0.0;
    if (cost > COVERED)
    {
     paidByEmployee = totalCost - totalCovered;   
    }
    else {
        paidByEmployee = 0;
    }
    return paidByEmployee;
}

double hotel_saved(int days, double cost, double totalCost){
    double totalCovered = days * COVERED;
    double amountSaved = 0.0;
    if (cost <= COVERED)
    {
     amountSaved = totalCovered - totalCost;   
    }
    else {
        amountSaved = 0;
    }
    return amountSaved;
}

/*
//unit test
int main(){
    //days would be from main, just redefining and asking for input here to test values
    int days;
    printf("days:");
    fflush(stdout);
    scanf("%d", &days);
    double hotelCostPerDay;
    double hotelTotalExpenses;
    double hotelTotalCovered;
    double hotelPaidByEmployee;
    double hotelSaved;
    hotelCostPerDay = hotel_cost_per_day();
    hotelTotalExpenses = hotel_total_expenses(days, hotelCostPerDay);
    hotelTotalCovered = hotel_total_covered(days);
    hotelPaidByEmployee = hotel_paid_by_employee(days, hotelCostPerDay, hotelTotalExpenses);
    hotelSaved = hotel_saved(days, hotelCostPerDay, hotelTotalExpenses);
    printf("Cost of hotel room per day: $%lf\n", hotelCostPerDay);
    printf("Cost of hotel for %d days: $%lf\n", days, hotelTotalExpenses);
    printf("Amount covered by company for %d days: $%lf\n", days, hotelTotalCovered);
    printf("Amount paid by the employee: $%lf\n", hotelPaidByEmployee);
    printf("Amount the employee saved: $%lf\n", hotelSaved);
    return 0;
}
*/