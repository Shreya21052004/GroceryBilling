#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "header.h"

#define DISCOUNT_THRESHOLD 599.0
#define DISCOUNT_PERCENTAGE 35.0
#define GST_PERCENTAGE 5.75

int main() {
    int choice;
    int count_digits = 0;
    float totalBill = 0;
    Item *items = malloc(10 * sizeof(Item));
    if (items == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialization of items
    strcpy(items[0].itemName, "Apple");
    items[0].stock = 50;
    items[0].price = 10.50; // Updated price for Apple

    strcpy(items[1].itemName, "Mango");
    items[1].stock = 30;
    items[1].price = 6.00; // Updated price for Mango

    strcpy(items[2].itemName, "Onions");
    items[2].stock = 40;
    items[2].price = 6.20; // Updated price for Onions

    strcpy(items[3].itemName, "Milk Packets");
    items[3].stock = 60;
    items[3].price = 5.00; // Updated price for Milk Packets

    strcpy(items[4].itemName, "Eggs");
    items[4].stock = 100;
    items[4].price = 10.20; // Updated price for Eggs

    strcpy(items[5].itemName, "Garlic");
    items[5].stock = 30;
    items[5].price = 5.00; // Updated price for Garlic

    strcpy(items[6].itemName, "Tomatoes");
    items[6].stock = 70;
    items[6].price = 4.50; // Updated price for Tomatoes

    strcpy(items[7].itemName, "Dark Chocolate");
    items[7].stock = 20;
    items[7].price = 3.50; // Updated price for Dark Chocolate

    strcpy(items[8].itemName, "Cheese");
    items[8].stock = 40;
    items[8].price = 5.80; // Updated price for Cheese

    strcpy(items[9].itemName, "Curd Packets");
    items[9].stock = 50;
    items[9].price = 7.80; // Updated price for Curd Packets

    printf("Welcome to our Grocery Shop\n");

    Customer customer;

    // Customer Name
    do {
        printf("\nEnter your name (alphabets only): ");
        scanf("%s", customer.name);
    } while (!isalpha(customer.name[0]));

    // Mobile Number
    do {
        printf("Enter your mobile number (10 digits only): ");
        scanf("%s", customer.mobile);

        count_digits = 0;
        for (int i = 0; customer.mobile[i] != '\0'; i++) {
            if (!isdigit(customer.mobile[i])) {
                count_digits = 0;
                break;
            }
            count_digits++;
        }
    } while (count_digits != 10);

    // Main billing loop
    do {
        printf("\n");
        printf("*\n");
        printf("Grocery Menu\n");
        // Print menu options...
        for (int i = 0; i < 10; i++) {
            printf("%d. %s - $%.2f\n", i + 1, items[i].itemName, items[i].price);
        }
        printf("11. Exit \n");
        printf("\n");

        printf("\nEnter item between (1-10) : ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 10) {
            calculateBill(&items[choice - 1]);
        } else if (choice != 11) {
            printf("*INVALID CHOICE*\n");
        }

    } while (choice != 11);

    // Print total bill
    printf("\n*\n");
    for (int i = 0; i < 10; i++) {
        printf("Total bill for %s: $%.2f\n", items[i].itemName, items[i].bill);
        totalBill += items[i].bill;
    }
    printf("Grocery Bill (Before Discount and GST) ----- $%.2f\n", totalBill);

    // Apply discount if applicable
    if (totalBill > DISCOUNT_THRESHOLD) {
        float discount = (DISCOUNT_PERCENTAGE * totalBill) / 100.0;
        printf("%.0f%% discount applied\n", DISCOUNT_PERCENTAGE);
        printf("Discount: -$%.2f\n", discount);
        totalBill -= discount;
    }

    // Calculate GST
    float gst = (GST_PERCENTAGE * totalBill) / 100.0;
    printf("GST @ %.0f%% : $%.2f\n", GST_PERCENTAGE, gst);

    totalBill += gst;

    printf("\nTotal Bill (After Discount and GST) ----- $%.2f\n", totalBill);
    printf(":)THANK YOU VISIT AGAIN !!!\n");

    free(items); // Free dynamically allocated memory

    return 0;
}