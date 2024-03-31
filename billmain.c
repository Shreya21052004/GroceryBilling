#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "grocery.h"

int main() {
    int choice;
    int q; // Quantity
    float bill[10] = {0};
    int stock[10] = {10, 20, 15, 45, 50, 20, 30, 10, 20, 35}; 
    float price[10] = {20.00, 10.00, 25.00, 20.00, 5.00, 15.00, 60.00, 20.00, 40.00, 12.00};

    printf("Welcome to our Grocery Shop\n");

    char name[100];
    char mobile[15];

    //Customer Name
    do {
        printf("\nEnter your name (alphabets only): ");
        scanf("%s", name);

        int valid_name = 1;
        for (int i = 0; name[i] != '\0'; i++) {
            if (!isalpha(name[i])) {
                valid_name = 0;
                break;
            }
        }

        if (!valid_name)
            printf("Invalid name! Please enter alphabets only.\n");
    } while (!isalpha(name[0]));

    // Mobile Number
    int count_digits = 0;
    do {
        printf("Enter your mobile number (10 digits only): ");
        scanf("%s", mobile);

        int valid_mobile = 1;
        count_digits = 0;
        for (int i = 0; mobile[i] != '\0'; i++) {
            if (!isdigit(mobile[i])) {
                valid_mobile = 0;
                break;
            }
            count_digits++;
        }

        if (valid_mobile && count_digits != 10)
            valid_mobile = 0;

        if (!valid_mobile)
            printf("Invalid mobile number! Please enter exactly 10 digits.\n");
    } while (count_digits != 10 || !isdigit(mobile[0]));

    do {
        printf("\n");
        printf("***********************\n");
        printf("Grocery Menu\n");
        printf("1. Apple - $%.2f\n 2. Mango - $%.2f\n 3. Onions per kg - $%.2f\n 4. Milk Packets(25g) - $%.2f\n 5. Eggs - $%.2f\n 6. Garlic - $%.2f\n 7. Tomatoes per kg - $%.2f\n 8. Dark Chocolate - $%.2f\n 9. Cheese  - $%.2f\n 10. Curd packets(25g) - $%.2f\n 11. Exit \n", price[0], price[1], price[2], price[3], price[4], price[5], price[6], price[7], price[8], price[9]);
        printf("\n");
        printf("Enter item between (1-10) : ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 10) {
            calculateBill(&stock[choice - 1], &bill[choice - 1], price[choice - 1]);
        } else if (choice != 11) {
            printf("**INVAlID CHOICE**\n");
        }

    } while (choice != 11);

    printf("\n");
    printf("***************************************\n");
    for (int i = 0; i < 10; i++) {
        switch (i) {
            case 0:
                printf("Total bill for Apple: $%.2f\n", bill[i]);
                break;
            case 1:
                printf("Total bill for Mango: $%.2f\n", bill[i]);
                break;
            case 2:
                printf("Total bill for Onions: $%.2f\n", bill[i]);
                break;
            case 3:
                printf("Total bill for Milk Packets(25g): $%.2f\n", bill[i]);
                break;
            case 4:
                printf("Total bill for Eggs: $%.2f\n", bill[i]);
                break;
            case 5:
                printf("Total bill for Garlic: $%.2f\n", bill[i]);
                break;
            case 6:
                printf("Total bill for Tomatoes: $%.2f\n", bill[i]);
                break;
            case 7:
                printf("Total bill for Dark Chocolate: $%.2f\n", bill[i]);
                break;
            case 8:
                printf("Total bill for Cheese: $%.2f\n", bill[i]);
                break;
            case 9:
                printf("Total bill for Curd: $%.2f\n", bill[i]);
                break;
        }
    }

    float totalBill = 0;
    for (int i = 0; i < 10; i++) {
        totalBill += bill[i];
    }

    printf("Grocery Bill ----- $%.2f\n", totalBill);

    if (totalBill > 999.0) {
        float discount = (10.00 * totalBill) / 100.0;
        printf("10%% discount applied\n");
        printf("Discount: -$%.2f\n", discount);
        totalBill -= discount;
    }

    float gst = (5.00 * totalBill) / 100.0;
    printf("GST          ----- $%.2f\n", gst);

    totalBill += gst;

    printf("\nTotal_Bill with GST applied: $%.2f\n", totalBill);

    static int customer_id = 1000;
    printf("Your customer ID: %d\n", customer_id++);

    return 0;
}
