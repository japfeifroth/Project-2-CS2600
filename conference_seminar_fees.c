#include <stdio.h>
#include <stdlib.h>
#include "conference_hotel_meal_functions.h"

//function that asks for and returns conference or seminar fees as a double
double get_conference_seminar_fees(){
    double conferenceSeminarFees = 0.0;
    do
    {
        printf("Enter conference or seminar registration fees: $");
        fflush(stdout);
        scanf("%lf", &conferenceSeminarFees);
        if (conferenceSeminarFees < 0) //checks if input is negative
        {
            printf("input a value >= 0\n");
        }
    } while (conferenceSeminarFees < 0);

    return conferenceSeminarFees;
}

//unit test
int main(){
    double conferencSeminarFees;
    conferencSeminarFees = get_conference_seminar_fees();
    printf("Conference or Seminar fees: $%lf\n", conferencSeminarFees);
    return 0;
}