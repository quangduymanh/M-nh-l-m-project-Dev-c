#include <stdio.h>
#include "function.h"

int main() {
    int choice, categoryCount = 0, productCount = 0, invoiceCount = 0;
    Category categories[100];
    Product products[100];
    Invoice invoices[100];

    while (1) {
        displayStartMenu();
        scanf("%d", &choice);

        if (choice == 0) {
            printf("\nExiting the Program. Goodbye!\n");
            break;
        }

        if (choice == 1) {
            int adminChoice;
            do {
                displayCategoryMenu();
                scanf("%d", &adminChoice);
                switch (adminChoice) {
                    case 1:
                        listCategories(categories, categoryCount);
                        break;
                    case 2:
                        addCategory(categories, &categoryCount);
                        break;
                    case 3:
                        editCategory(categories, categoryCount);
                        break;
                    case 4:
                        deleteCategory(categories, &categoryCount, products, &productCount);
                        break;
                    case 5:
                        searchCategory(categories, categoryCount);
                        break;
                    case 6:
                        sortCategories(categories, categoryCount);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
            } while (adminChoice != 0);

            int productChoice;
            do {
                displayProductMenu();
                scanf("%d", &productChoice);
                switch (productChoice) {
                    case 1:
                        listProducts(products, productCount);
                        break;
                    case 2:
                        addProduct(products, &productCount, categories, categoryCount);
                        break;
                    case 3:
                        editProduct(products, productCount);
                        break;
                    case 4:
                        deleteProduct(products, &productCount);
                        break;
                    case 5:
                        searchProduct(products, productCount);
                        break;
                    case 6:
                        sortProducts(products, productCount);
                        break;
                    case 7:
                        filterProducts(products, productCount, categories, categoryCount);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
            } while (productChoice != 0);

            int invoiceChoice;
            do {
                displayInvoiceMenu();
                scanf("%d", &invoiceChoice);
                switch (invoiceChoice) {
                    case 1:
                        listInvoices(invoices, invoiceCount);
                        break;
                    case 2:
                        createInvoice(invoices, &invoiceCount, products, productCount);
                        break;
                    case 3:
                        searchInvoice(invoices, invoiceCount);
                        break;
                    case 4:
                        calculateRevenue(invoices, invoiceCount);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Invalid choice! Please try again.\n");
                }
            } while (invoiceChoice != 0);
        } else if (choice == 2) {
            printf("\nEmployee functionalities are coming soon!\n");
        } else if (choice == 3) {
            printf("\nCustomer functionalities are coming soon!\n");
        } else {
            printf("\nInvalid role! Please restart the program.\n");
        }
    }

    return 0;
}
