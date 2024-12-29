#include <stdio.h>
#include <string.h>
#include "function.h"

// Hi?n th? menu chính
void displayStartMenu() {
    printf("========================================\n");
    printf("   *** Supermarket Management System ***\n");
    printf("========================================\n");
    printf("               CHOOSE YOUR ROLE          \n");
    printf("----------------------------------------\n");
    printf("[1] Admin\n");
    printf("[2] Employee\n");
    printf("[3] Customer\n");
    printf("[0] Exit the Program\n");
    printf("----------------------------------------\n");
    printf("Enter Your Choice: ");
}

// Hi?n th? menu qu?n l? danh m?c
void displayCategoryMenu() {
    printf("========================================\n");
    printf("   *** Category Management ***\n");
    printf("========================================\n");
    printf("[1] List Categories\n");
    printf("[2] Add Category\n");
    printf("[3] Edit Category\n");
    printf("[4] Delete Category\n");
    printf("[5] Search Category\n");
    printf("[6] Sort Categories\n");
    printf("[0] Back to Main Menu\n");
    printf("----------------------------------------\n");
    printf("Enter Your Choice: ");
}

// Hi?n th? menu qu?n l? s?n ph?m
void displayProductMenu() {
    printf("========================================\n");
    printf("   *** Product Management ***\n");
    printf("========================================\n");
    printf("[1] List Products\n");
    printf("[2] Add Product\n");
    printf("[3] Edit Product\n");
    printf("[4] Delete Product\n");
    printf("[5] Search Product\n");
    printf("[6] Sort Products\n");
    printf("[7] Filter Products\n");
    printf("[0] Back to Main Menu\n");
    printf("----------------------------------------\n");
    printf("Enter Your Choice: ");
}

// Hi?n th? menu qu?n l? hóa ðõn
void displayInvoiceMenu() {
    printf("========================================\n");
    printf("   *** Invoice Management ***\n");
    printf("========================================\n");
    printf("[1] List Invoices\n");
    printf("[2] Create Invoice\n");
    printf("[3] Search Invoice\n");
    printf("[4] Calculate Revenue\n");
    printf("[0] Back to Main Menu\n");
    printf("----------------------------------------\n");
    printf("Enter Your Choice: ");
}

// Các hàm qu?n l? danh m?c
void addCategory(Category *categories, int *categoryCount) {
    printf("Enter category ID: ");
    scanf("%d", &categories[*categoryCount].id);
    printf("Enter category name: ");
    scanf("%s", categories[*categoryCount].name);
    (*categoryCount)++;
    printf("Category added successfully!\n");
}

void editCategory(Category *categories, int categoryCount) {
    int id, i;
    printf("Enter category ID to edit: ");
    scanf("%d", &id);
    for (i = 0; i < categoryCount; i++) {
        if (categories[i].id == id) {
            printf("Current name: %s\n", categories[i].name);
            printf("Enter new name: ");
            scanf("%s", categories[i].name);
            printf("Category updated successfully!\n");
            return;
        }
    }
    printf("Category ID not found!\n");
}

void deleteCategory(Category *categories, int *categoryCount, Product *products, int *productCount) {
    int id, i, j;
    printf("Enter category ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < *categoryCount; i++) {
        if (categories[i].id == id) {
            for (j = 0; j < *productCount; j++) {
                if (products[j].categoryId == id) {
                    products[j] = products[--(*productCount)];
                }
            }
            categories[i] = categories[--(*categoryCount)];
            printf("Category and its products deleted successfully!\n");
            return;
        }
    }
    printf("Category ID not found!\n");
}

void listCategories(Category *categories, int categoryCount) {
    int i;
    printf("ID\tName\n");
    for (i = 0; i < categoryCount; i++) {
        printf("%d\t%s\n", categories[i].id, categories[i].name);
    }
}

void searchCategory(Category *categories, int categoryCount) {
    char name[50];
    int i, found = 0;
    printf("Enter category name to search: ");
    scanf("%s", name);
    printf("ID\tName\n");
    for (i = 0; i < categoryCount; i++) {
        if (strstr(categories[i].name, name) != NULL) {
            printf("%d\t%s\n", categories[i].id, categories[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No category found with the given name!\n");
    }
}

void sortCategories(Category *categories, int categoryCount) {
    int choice, i, j;
    Category temp;
    printf("Sort categories: [1] Ascending [2] Descending\n");
    scanf("%d", &choice);
    for (i = 0; i < categoryCount - 1; i++) {
        for (j = i + 1; j < categoryCount; j++) {
            if ((choice == 1 && strcmp(categories[i].name, categories[j].name) > 0) ||
                (choice == 2 && strcmp(categories[i].name, categories[j].name) < 0)) {
                temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
            }
        }
    }
    printf("Categories sorted successfully!\n");
    listCategories(categories, categoryCount);
}

// Các hàm qu?n l? s?n ph?m
void addProduct(Product *products, int *productCount, Category *categories, int categoryCount) {
    printf("Enter product ID: ");
    scanf("%d", &products[*productCount].id);
    printf("Enter product name: ");
    scanf("%s", products[*productCount].name);
    printf("Enter product price: ");
    scanf("%f", &products[*productCount].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[*productCount].quantity);
    printf("Enter category ID: ");
    scanf("%d", &products[*productCount].categoryId);
    (*productCount)++;
    printf("Product added successfully!\n");
}

void editProduct(Product *products, int productCount) {
    int id, i;
    printf("Enter product ID to edit: ");
    scanf("%d", &id);
    for (i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            printf("Current name: %s\n", products[i].name);
            printf("Enter new name: ");
            scanf("%s", products[i].name);
            printf("Enter new price: ");
            scanf("%f", &products[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new category ID: ");
            scanf("%d", &products[i].categoryId);
            printf("Product updated successfully!\n");
            return;
        }
    }
    printf("Product ID not found!\n");
}

void deleteProduct(Product *products, int *productCount) {
    int id, i;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < *productCount; i++) {
        if (products[i].id == id) {
            products[i] = products[--(*productCount)];
            printf("Product deleted successfully!\n");
            return;
        }
    }
    printf("Product ID not found!\n");
}

void listProducts(Product *products, int productCount) {
    int i;
    printf("ID\tName\tPrice\tQuantity\tCategory ID\n");
    for (i = 0; i < productCount; i++) {
        printf("%d\t%s\t%.2f\t%d\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity, products[i].categoryId);
    }
}

void searchProduct(Product *products, int productCount) {
    char name[50];
    int i, found = 0;
    printf("Enter product name to search: ");
    scanf("%s", name);
    printf("ID\tName\tPrice\tQuantity\tCategory ID\n");
    for (i = 0; i < productCount; i++) {
        if (strstr(products[i].name, name) != NULL) {
            printf("%d\t%s\t%.2f\t%d\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity, products[i].categoryId);
            found = 1;
        }
    }
    if (!found) {
        printf("No product found with the given name!\n");
    }
}

void sortProducts(Product *products, int productCount) {
    int choice, i, j;
    Product temp;
    printf("Sort products: [1] Ascending by price [2] Descending by price\n");
    scanf("%d", &choice);
    for (i = 0; i < productCount - 1; i++) {
        for (j = i + 1; j < productCount; j++) {
            if ((choice == 1 && products[i].price > products[j].price) ||
                (choice == 2 && products[i].price < products[j].price)) {
                temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    printf("Products sorted successfully!\n");
    listProducts(products, productCount);
}

void filterProducts(Product *products, int productCount, Category *categories, int categoryCount) {
    int choice, id, i, found = 0;
    float startPrice, endPrice;
    printf("Filter products: [1] By category [2] By price range\n");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter category ID: ");
        scanf("%d", &id);
        for (i = 0; i < categoryCount; i++) {
            if (categories[i].id == id) {
                printf("ID\tName\tPrice\tQuantity\tCategory ID\n");
                for (i = 0; i < productCount; i++) {
                    if (products[i].categoryId == id) {
                        printf("%d\t%s\t%.2f\t%d\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity, products[i].categoryId);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No products found in this category!\n");
                }
                return;
            }
        }
        printf("Category ID not found!\n");
    } else if (choice == 2) {
        printf("Enter start price: ");
        scanf("%f", &startPrice);
        printf("Enter end price: ");
        scanf("%f", &endPrice);
        if (startPrice > endPrice) {
            printf("Invalid price range!\n");
            return;
        }
        printf("ID\tName\tPrice\tQuantity\tCategory ID\n");
        for (i = 0; i < productCount; i++) {
            if (products[i].price >= startPrice && products[i].price <= endPrice) {
                printf("%d\t%s\t%.2f\t%d\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity, products[i].categoryId);
                found = 1;
            }
        }
        if (!found) {
            printf("No products found in this price range!\n");
        }
    }
}

// Các hàm qu?n l? hóa ðõn
void createInvoice(Invoice *invoices, int *invoiceCount, Product *products, int productCount) {
    int productId, quantity, i;
    printf("Enter product ID: ");
    scanf("%d", &productId);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    for (i = 0; i < productCount; i++) {
        if (products[i].id == productId) {
            if (products[i].quantity < quantity) {
                printf("Insufficient quantity in stock!\n");
                return;
            }
            products[i].quantity -= quantity;
            invoices[*invoiceCount].id = *invoiceCount + 1;
            invoices[*invoiceCount].productId = productId;
            invoices[*invoiceCount].quantity = quantity;
            invoices[*invoiceCount].totalPrice = products[i].price * quantity;
            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", invoices[*invoiceCount].date);
            (*invoiceCount)++;
            printf("Invoice created successfully!\n");
            return;
        }
    }
    printf("Product ID not found!\n");
}

void listInvoices(Invoice *invoices, int invoiceCount) {
    int i;
    printf("ID\tProduct ID\tQuantity\tTotal Price\tDate\n");
    for (i = 0; i < invoiceCount; i++) {
        printf("%d\t%d\t%d\t%.2f\t%s\n", invoices[i].id, invoices[i].productId, invoices[i].quantity, invoices[i].totalPrice, invoices[i].date);
    }
}

void searchInvoice(Invoice *invoices, int invoiceCount) {
    int id, i;
    printf("Enter invoice ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < invoiceCount; i++) {
        if (invoices[i].id == id) {
            printf("ID: %d\n", invoices[i].id);
            printf("Product ID: %d\n", invoices[i].productId);
            printf("Quantity: %d\n", invoices[i].quantity);
            printf("Total Price: %.2f\n", invoices[i].totalPrice);
            printf("Date: %s\n", invoices[i].date);
            return;
        }
    }
    printf("Invoice ID not found!\n");
}

void calculateRevenue(Invoice *invoices, int invoiceCount) {
    char startDate[20], endDate[20];
    float totalRevenue = 0;
    int i;
    printf("Enter start date (YYYY-MM-DD): ");
    scanf("%s", startDate);
    printf("Enter end date (YYYY-MM-DD): ");
    scanf("%s", endDate);

    for (i = 0; i < invoiceCount; i++) {
        if (strcmp(invoices[i].date, startDate) >= 0 && strcmp(invoices[i].date, endDate) <= 0) {
            totalRevenue += invoices[i].totalPrice;
        }
    }
    printf("Total revenue from %s to %s: %.2f\n", startDate, endDate, totalRevenue);
}
