#include "grocery.h"
#include <stdio.h>

// Function to calculate bill for an item
float calculateBill(int *stock, float *bill, float price) {
    int q;
    if (*stock > 0) {
        printf("Enter the quantity: ");
        scanf("%d", &q);
        if (q <= *stock) {
            *bill += q * price;
            *stock -= q;
        } else {
            printf("Sorry, we only have %d in stock\n", *stock);
        }
    } else {
        printf("Sorry, this item is out of stock\n");
    }
    return *bill;
}
