#include "header.h"
#include <stdio.h>

void calculateBill(Item *item) {
    int quantity;
    if (item->stock > 0) {
        printf("Enter the quantity of %s: ", item->itemName);
        scanf("%d", &quantity);
        if (quantity <= item->stock) {
            item->bill += quantity * item->price;
            item->stock -= quantity;
        } else {
            printf("Sorry, we only have %d %s in stock.\n", item->stock, item->itemName);
        }
    } else {
        printf("Sorry, %s is out of stock.\n", item->itemName);
    }
}