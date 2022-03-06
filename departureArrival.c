#include <stdio.h>
#include <stdlib.h>
#include "departureArrival.h"

//Function that stores departure
int getDeparture(){
    int time;
    int hour = -1;
    int min = -1;
    while(hour < 0 || hour > 23){
        printf("What hour will your flight depart?(From 0-23)\n");
        scanf("%d", &hour);
        if(hour < 0 || hour > 23){
            printf("This is not a valid time slot, Please re-enter time\n");
        }
    }
    while(min < 0 || min > 59){
        printf("What minute will your flight depart?(From 0-59)\n");
        scanf("%d", &min);
        if(min < 0 || min > 59){
            printf("This is not a valid time slot, Please re-enter time\n");
        }
    }
    time = hour*100 + min;
    return time;
}

//Function that stores arrival
int getArrival(){
    int time;
    int hour = -1;
    int min = -1;
    while(hour < 0 || hour > 23){
        printf("What hour will your flight arrive?(From 0-23)\n");
        scanf("%d", &hour);
        if(hour < 0 || hour > 23){
            printf("This is not a valid time slot, Please re-enter time\n");
        }
    }
    while(min < 0 || min > 59){
        printf("What minute will your flight arrive?(From 0-59)\n");
        scanf("%d", &min);
        if(min < 0 || min > 59){
            printf("This is not a valid time slot, Please re-enter time\n");
        }
    }
    time = hour*100 + min;
    return time;
}

//Unit testing functions
int main() {
    int departure = getDeparture();
    int arrival = getArrival();
    printf("Departure time stored is: %d\nArrival Time stored is: %d", departure, arrival);
    return 0;
}
