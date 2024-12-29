#ifndef DATATYPE_H
#define DATATYPE_H

typedef struct {
    int id;
    char name[50];
} Category;

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
    int categoryId;
} Product;

typedef struct {
    int id;
    int productId;
    int quantity;
    float totalPrice;
    char date[20];
} Invoice;

#endif
