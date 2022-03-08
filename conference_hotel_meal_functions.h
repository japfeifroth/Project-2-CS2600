#ifndef CONFERENCEHOTELMEALS_H
#define CONFERENCEHOTELMEALS_H

//function definition for conference_seminar_fees.c
double get_conference_seminar_fees();

//function definitions for hotel_expenses.c
double hotel_cost_per_day();
double hotel_total_expenses(int days, double cost);
double hotel_total_covered(int days);
double hotel_paid_by_employee(int days, double cost, double totalCost);
double hotel_saved(int days, double cost, double totalCost);

//function definitions for food_expenses.c
typedef struct //allows arrays to be passed between functions
{
    double table[30][3]; //2-dimensional array, i = days j = meals, [i][j] is the price of j meal on i day; j=0 is breakfast, j=1 is lunch, j=2 is dinner; hard-coded to 30 days max
} mealPrices;
mealPrices get_food_prices(int timeOfDeparture, int timeOfArrival, int days);
double meals_total_covered(mealPrices meal, int days);
double meals_total_price(mealPrices meal, int days);
double meals_total_paid_by_employee(mealPrices meal, int days);
double meals_total_saved(mealPrices meal, int days);



#endif