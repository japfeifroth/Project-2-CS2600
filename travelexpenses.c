#include <stdio.h>
#include <stdlib.h>
#include "amountOfDays.c"
#include "departureArrival.c"
#include "expensesRoundTripCarRental.c"
#include "MilesDriven.c"
#include "ParkingFees.c"
#include "TaxiFees.c"
#include "conference_seminar_fees.c"
#include "hotel_expenses.c"
#include "food_expenses.c"

int getDays(int);

int main()
{
    int days;
    int timeOfDeparture;
    int timeOfArrival;
    double airFare;
    float carRental;
    float milesDriven;
    double parkingFees;
    double allowableParking;
    double parkingReimbursed;
    double parkingSaved;
    double taxiFees;
    double allowableTaxi;
    double taxiReimbursed;
    double taxiSaved;
    double seminarFees;
    double hotelCostPerDay;
    double hotelTotalExpenses;
    double hotelTotalCovered;
    double hotelPaidByEmployee;
    double hotelSaved;
    mealPrices mealsPriceArray;
    double mealsTotalPrice;
    double mealsTotalCovered; 
    double mealsTotalPaidByEmployee;
    double mealsTotalSaved;
    double totalExpenses;
    double totalAllowable;
    double totalReimbursed;
    double totalSaved;
                           
    mealsPriceArray = get_food_prices(timeOfDeparture, timeOfArrival, days);
    mealsTotalPrice = meals_total_price(mealsPriceArray, days);
    mealsTotalCovered = meals_total_covered(mealsPriceArray, days);
    mealsTotalPaidByEmployee = meals_total_paid_by_employee(mealsPriceArray, days);
    mealsTotalSaved = meals_total_saved(mealsPriceArray, days);

    days = getDays(days);
    timeOfDeparture = getDeparture();
    timeOfArrival = getArrival();
    airFare = getRoundTripTotal();
    carRental= getCarRentalTotal();
    milesDriven = getMilesDriven();
    parkingFees = parkingFeesAcrossDays(days);
    allowableParking = allowableParkingExpenses(days);
    parkingReimbursed = parkingCostToBusinessman(days, parkingFees); 
    parkingSaved = parkingSavedToCompany(days, parkingFees);
    taxiFees = taxiFeesAcrossDays(days);
    allowableTaxi = allowableTaxiExpenses(days);
    taxiReimbursed = taxiCostToBusinessman(days, taxiFees);
    taxiSaved = taxiSavedToCompany(days, taxiFees);
    seminarFees = get_conference_seminar_fees();
    hotelCostPerDay = hotel_cost_per_day();
    hotelTotalExpenses = hotel_total_expenses(days, hotelCostPerDay);
    hotelTotalCovered = hotel_total_covered(days);
    hotelPaidByEmployee = hotel_paid_by_employee(days, hotelCostPerDay, hotelTotalExpenses);
    hotelSaved = hotel_saved(days, hotelCostPerDay, hotelTotalExpenses);
    mealsPriceArray = get_food_prices(timeOfDeparture, timeOfArrival, days);
    mealsTotalPrice = meals_total_price(mealsPriceArray, days);
    mealsTotalCovered = meals_total_covered(mealsPriceArray, days);
    mealsTotalPaidByEmployee = meals_total_paid_by_employee(mealsPriceArray, days);
    mealsTotalSaved = meals_total_saved(mealsPriceArray, days);

    totalExpenses = airFare + carRental + milesDriven + parkingFees 
                    + taxiFees + seminarFees + hotelTotalExpenses + mealsTotalPrice;
    totalAllowable = allowableParking + allowableTaxi + hotelTotalCovered + mealsTotalCovered;
    totalReimbursed = parkingReimbursed + taxiReimbursed + hotelPaidByEmployee + mealsTotalPaidByEmployee;
    totalSaved = parkingSaved + taxiSaved + hotelSaved + mealsTotalSaved;

    printf("\nTravel Expenses Report\n");
    printf("Total days of trip: %d\n", days);
    printf("Departure time (first day of trip): %d\n", timeOfDeparture);
    printf("Arrival time (last day of trip): %d\n", timeOfArrival);
    printf("Round trip airfare: $%.2f \n", airFare);
    printf("Car rental: $%.2f \n", carRental);
    printf("Vehicle expense: $%.2f \n", milesDriven);
    printf("Parking: $%.2f\n", parkingFees);
    printf("Taxi: $%.2f\n", taxiFees);
    printf("Registration: $%.2f\n", seminarFees);
    printf("Hotel: $%.2f\n", hotelTotalExpenses);
    printf("Meal: $%.2f\n", mealsTotalPrice);

    printf("\nTotal expenses: $%.2f\n", totalExpenses);
    printf("Allowable expenses: $%.2f\n", totalAllowable);
    printf("Amount to be reimbursed: $%.2f\n", totalReimbursed);
    printf("Amount saved: $%.2f\n", totalSaved);
    return 0;
}