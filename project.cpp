#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxCategory =100;
const int maxName =50;

typedef struct {
    int id;
    char name[50];
    char description[50];
} Category;

Category categories[100];
int categoryCount = 0;

void displayMenu() {
    printf("==============================================\n");
    printf("           HE THONG QUAN LY DANH MUC    \n");
    printf("==============================================\n");
    printf("1. Hien thi danh muc\n");
    printf("2. Them danh muc\n");
    printf("3. Sua danh muc\n");
    printf("4. Xoa danh muc \n");
    printf("5. Tim kiem danh muc\n");
    printf("6. Sap xep danh muc theo ten\n");
    printf("7. Kiem tra du lieu nhap cho danh muc\n");
    printf("8. Luu tru du lieu\n");
    printf("0. Thoat\n");
    printf("==============================================\n");
    printf("Nhap lua chon cua ban : ");
}

void displayCategories() {
    if (categoryCount == 0) {
        printf("Khong co danh muc nao kha dung.\n");
        return;
    }
    printf("\n%-5s %-20s %-25s\n", "ID", "Name", "Description");
    printf("==============================================\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("%-5d %-20s %-30s\n", categories[i].id, categories[i].name, categories[i].description);
    }
}
void addCategory() {
    if (categoryCount >= maxCategory) {
        printf("Khong the them danh muc.\n");
        return;
    }
    Category newCategory;
    newCategory.id = categoryCount + 1;

    printf("Nhap ten danh muc: ");
    getchar();
    fgets(newCategory.name, maxName, stdin);
    newCategory.name[strcspn(newCategory.name, "\n")] = 0;
    
    printf("Nhap mo ta danh muc: ");
    fgets(newCategory.description, maxName, stdin);
    newCategory.description[strcspn(newCategory.description, "\n")] = 0;
    
    categories[categoryCount] = newCategory;
    categoryCount++;

    printf("Da them danh muc \n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCategories();
                break;
            case 2:
                addCategory();
                break;
            case 0:
                printf("Thoat khoi chuong trinh \n");
                exit(0);
            default:
                printf("Lua chon khong hop le .\n");
        }
        printf("\n");
    }

    return 0;
}

