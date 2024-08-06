
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Product list is full!\n");
        return;
    }
    Product p;
    p.id = productCount + 1;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    products[productCount++] = p;
    printf("Product added successfully!\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products available!\n");
        return;
    }
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

void purchaseProduct() {
    int id, quantity;
    printf("Enter product ID to purchase: ");
    scanf("%d", &id);
    printf("Enter quantity to purchase: ");
    scanf("%d", &quantity);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            if (products[i].quantity >= quantity) {
                products[i].quantity -= quantity;
                printf("Purchase successful! Total cost: %.2f\n", products[i].price * quantity);
            } else {
                printf("Insufficient stock!\n");
            }
            return;
        }
    }
    printf("Product not found!\n");
}

int main() {
    int choice;
    do {
        printf("\nSuperShop Menu:\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Purchase Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                purchaseProduct();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
