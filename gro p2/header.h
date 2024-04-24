#ifndef HEADER_H
#define HEADER_H

typedef struct {
    char name[100];
    char mobile[15];
} Customer;

typedef struct {
    char itemName[100];
    int stock;
    float price;
    float bill;
} Item;

// Function to calculate bill for an item
void calculateBill(Item *item);

#endif
