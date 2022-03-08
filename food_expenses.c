#include <stdio.h>
#include <stdlib.h>
#include "conference_hotel_meal_functions.h"

/*5 functions that return: 
the inputs for each allowable meal price from command line as a 2-D array (meal.table) (takes time of departure, time of arrival, and number of days on trip as arguments)
the total amount of allowable meal fees covered by company for entire trip (takes meal price table and number of days on trip as arguments)
the total price of all allowable meals for entire trip (takes meal price table and number of days on trip as arguments)
the total amount the employee has to pay for allowable meals (takes meal price table and number of days on trip as arguments)
the total amount the employee saved on allowable meals (takes meal price table and number of days on trip as arguments)
*/

const double BF_COVERED = 9.00;
const double LN_COVERED = 12.00;
const double DN_COVERED = 16.00;

//function that gets inputs for each meal from command line and returns them as a 2-D array (meal.table)
mealPrices get_food_prices(int timeOfDeparture, int timeOfArrival, int days){
    mealPrices meal;
    double totalPrice = 0.0;
    double totalPaidByEmployee = 0.0;
    double totalSaved = 0.0;

//initializes array to be all 0
for (int i = 0; i < days; i++)
{
    for (int j = 0; j < 3; j++)
    {
        meal.table[i][j] = 0.0;
    }
}

for (int i = 0; i < days; i++){
        breakfast:
            if (i == 0){ 
                if (timeOfDeparture > 700){
                    meal.table[i][0] = 0.0; //breakfast not allowed as an exense
                    goto lunch;
                }
            }//day of departure

            else if (i == (days - 1)){ 
                if (timeOfArrival < 800){
                    meal.table[i][0] = 0.0; //breakfast not allowed as an exense
                    goto lunch;
                }
            }//day of arrival

            //not first or last day
                do{
                printf("price of breakfast for day %d: $", i+1);
                fflush(stdout);
                scanf("%lf", &meal.table[i][0]);
                if (meal.table[i][0] < 0) //checks if input is negative
                {
                    printf("input a value >= 0\n");
                }
                }while (meal.table[i][0] < 0); //checks if input is negative

        lunch:
            if (i == 0){ 
                if (timeOfDeparture > 1200){
                    meal.table[i][0] = 0.0; //breakfast not allowed as an exense
                    meal.table[i][1] = 0.0;     //lunch not allowed as an exense
                    goto dinner;
                }
            }//day of departure

            else if (i == (days - 1)){ 
                if (timeOfArrival < 1300){
                    meal.table[i][1] = 0.0;     //lunch not allowed as an exense
                    goto dinner;
                }
            }//day of arrival

            //not first or last day
                do{
                printf("price of lunch for day %d: $", i+1);
                fflush(stdout);
                scanf("%lf", &meal.table[i][1]);
                if (meal.table[i][1] < 0) //checks if input is negative
                {
                    printf("input a value >= 0\n");
                }
                }while (meal.table[i][1] < 0); //checks if input is negative

        dinner:
            if (i == 0){ 
                if (timeOfDeparture > 1800){
                    meal.table[i][0] = 0.0; //breakfast not allowed as an exense
                    meal.table[i][1] = 0.0; //lunch not allowed as an exense
                    meal.table[i][2] = 0.0;     //dinner not allowed as an exense
                    goto skip;
                }
            }//day of departure

            else if (i == (days - 1)){ 
                if (timeOfArrival < 1900){
                    meal.table[i][2] = 0.0;     //dinner not allowed as an exense
                    goto skip;
                }
            }//day of arrival
 
            //not first or last day
                do{
                printf("price of dinner for day %d: $", i+1);
                fflush(stdout);
                scanf("%lf", &meal.table[i][2]);
                if (meal.table[i][2] < 0) //checks if input is negative
                {
                    printf("input a value >= 0\n");
                }
                }while (meal.table[i][2] < 0); //checks if input is negative

        skip: continue;
}//for (int i = 0; i < days; i++), each day of the trip
return meal;
}

//returns total amount of allowable food fees covered by company for entire trip
double meals_total_covered(mealPrices meal, int days){
    double totalCovered = 0.0;
    for (int i = 0; i < days; i++)
    {
                if (meal.table[i][0] > 0)
                {
                totalCovered+= BF_COVERED;
                }
                else if (meal.table[i][0] == 0)
                {
                totalCovered+= 0;
                }

                if (meal.table[i][1] > 0)
                {
                totalCovered+= LN_COVERED;
                }
                else if (meal.table[i][1] == 0)
                {
                totalCovered+= 0;
                }

                if (meal.table[i][2] > 0)
                {
                totalCovered+= DN_COVERED;
                }
                else if (meal.table[i][2] == 0)
                {
                totalCovered+= 0;
                }
    }//for (int i = 0; i < days; i++) checking if each meal is allowable/covered as an expense. assumes $0 meals are non-allowable
    return totalCovered;
}

//returns the total price of all allowable meals for entire trip
double meals_total_price(mealPrices meal, int days){
    double totalPrice = 0.0;
    for (int i = 0; i < days; i++)
    {
        for (int j = 0; j < 3; j++)
        {
                totalPrice+= meal.table[i][j];
        }
    }
    return totalPrice;
}

//total amount paid by the employee
double meals_total_paid_by_employee(mealPrices meal, int days){
    double totalPaidByEmployee = 0.0;
     for (int i = 0; i < days; i++)
    {
                if (meal.table[i][0] > BF_COVERED && meal.table[i][0] != 0)
                {
                totalPaidByEmployee+= meal.table[i][0] - BF_COVERED;
                }
                else if (meal.table[i][0] == 0 || meal.table[i][0] < BF_COVERED)
                {
                totalPaidByEmployee+= 0;
                }

                if (meal.table[i][1] > LN_COVERED && meal.table[i][1] != 0)
                {
                totalPaidByEmployee+= meal.table[i][1] - LN_COVERED;
                }
                else if (meal.table[i][1] == 0 || meal.table[i][1] < BF_COVERED)
                {
                totalPaidByEmployee+= 0;
                }

                if (meal.table[i][2] > DN_COVERED && meal.table[i][2] != 0)
                {
                totalPaidByEmployee+= meal.table[i][2] - DN_COVERED;
                }
                else if (meal.table[i][2] == 0 || meal.table[i][2] < BF_COVERED)
                {
                totalPaidByEmployee+= 0;
                }
    }//for (int i = 0; i < days; i++) checking if each meal is allowable/covered as an expense. assumes $0 meals are non-allowable
    return totalPaidByEmployee;
}

//
double meals_total_saved(mealPrices meal, int days){
    double totalSaved = 0.0;
    for (int i = 0; i < days; i++)
    {
                if (meal.table[i][0] < BF_COVERED && meal.table[i][0] != 0)
                {
                totalSaved+= BF_COVERED - meal.table[i][0];
                }
                else if (meal.table[i][0] == 0 || meal.table[i][0] > BF_COVERED)
                {
                totalSaved+= 0;
                }

                if (meal.table[i][1] < LN_COVERED && meal.table[i][1] != 0)
                {
                totalSaved+= LN_COVERED - meal.table[i][1];
                }
                else if (meal.table[i][1] == 0 || meal.table[i][1] > BF_COVERED)
                {
                totalSaved+= 0;
                }

                if (meal.table[i][2] < DN_COVERED && meal.table[i][2] != 0)
                {
                totalSaved+= DN_COVERED - meal.table[i][2];
                }
                else if (meal.table[i][2] == 0 || meal.table[i][2] > BF_COVERED)
                {
                totalSaved+= 0;
                }
    }//for (int i = 0; i < days; i++)checking if each meal is allowable/covered as an expense. assumes $0 meals are non-allowable
    return totalSaved;
}

/*
//unit test
int main(){
    //days and times of arrival and departure would be from main, just redefining and asking for input here to test values
    int days;
    int timeOfDeparture;
    int timeOfArrival;
    printf("time of departure:");
    fflush(stdout);
    scanf("%d", &timeOfDeparture);
    printf("time of arrival:");
    fflush(stdout);
    scanf("%d", &timeOfArrival);
    printf("days:");
    fflush(stdout);
    scanf("%d", &days);

    mealPrices mealsPriceArray;
    double mealsTotalPrice;
    double mealsTotalCovered; 
    double mealsTotalPaidByEmployee;
    double mealsTotalSaved;
    mealsPriceArray = get_food_prices(timeOfDeparture, timeOfArrival, days);
    mealsTotalPrice = meals_total_price(mealsPriceArray, days);
    mealsTotalCovered = meals_total_covered(mealsPriceArray, days);
    mealsTotalPaidByEmployee = meals_total_paid_by_employee(mealsPriceArray, days);
    mealsTotalSaved = meals_total_saved(mealsPriceArray, days);
    printf("Total cost of allowable meals: $%lf\n", mealsTotalPrice);
    printf("Total amount covered by company: $%lf\n", mealsTotalCovered);
    printf("Total amount paid by the employee: $%lf\n", mealsTotalPaidByEmployee);
    printf("Total amount the employee saved: $%lf\n", mealsTotalSaved);
    printf("Table of individual meal prices (rows are days, column 1 = breakfast, column 2 = lunch, column 3 = dinner, price of 0 = non-allowable meal\n");
    for (int i = 0; i < days; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%lf  ", mealsPriceArray.table[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/