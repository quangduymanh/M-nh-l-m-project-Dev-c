#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"

// Hi?n th? menu
void displayStartMenu();
void displayCategoryMenu();
void displayProductMenu();
void displayInvoiceMenu();

// Qu?n l? danh m?c
void addCategory(Category *categories, int *categoryCount);
void editCategory(Category *categories, int categoryCount);
void deleteCategory(Category *categories, int *categoryCount, Product *products, int *productCount);
void listCategories(Category *categories, int categoryCount);
void searchCategory(Category *categories, int categoryCount);
void sortCategories(Category *categories, int categoryCount);

// Qu?n l? s?n ph?m
void addProduct(Product *products, int *productCount, Category *categories, int categoryCount);
void editProduct(Product *products, int productCount);
void deleteProduct(Product *products, int *productCount);
void listProducts(Product *products, int productCount);
void searchProduct(Product *products, int productCount);
void sortProducts(Product *products, int productCount);
void filterProducts(Product *products, int productCount, Category *categories, int categoryCount);

// Qu?n l? hóa ðõn
void createInvoice(Invoice *invoices, int *invoiceCount, Product *products, int productCount);
void listInvoices(Invoice *invoices, int invoiceCount);
void searchInvoice(Invoice *invoices, int invoiceCount);
void calculateRevenue(Invoice *invoices, int invoiceCount);

#endif
