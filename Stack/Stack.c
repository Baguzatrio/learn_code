#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 20

//==================================================================
typedef struct stack {
    int data;
    struct stack *next;
    int count;
} stack;

//==================================================================
void pushdata(stack **top);
void popdata(stack **top);
void stacktop(stack *top);
void stackempty(stack *top);
void stackfull(stack *top);
void stackcount(stack *top);
void destroystack(stack **top);

//==================================================================
int main() {
    stack *top = NULL;
    int pilih;

    do {
        system("cls");
        printf("Pilih operasi stack:\n");
        printf("1. Push data\n");
        printf("2. Pop data\n");
        printf("3. Stack top\n");
        printf("4. Check if empty\n");
        printf("5. Check if full\n");
        printf("6. Stack count\n");
        printf("7. Destroy stack\n");
        printf("Masukkan pilihan (tekan 0 untuk keluar): ");
        scanf("%d", &pilih);

        if (pilih == 1) {
            pushdata(&top);
        } else if (pilih == 2) {
            popdata(&top);
        } else if (pilih == 3) {
            stacktop(top);
        } else if (pilih == 4) {
            stackempty(top);
        } else if (pilih == 5) {
            stackfull(top);
        } else if (pilih == 6) {
            stackcount(top);
        } else if (pilih == 7) {
            destroystack(&top);
        }
            getch();

    } while (pilih != 0);

    return 0;
}

//==================================================================
void pushdata(stack **top) {
    int bil;
    stack *pNew;

    if (*top != NULL && (*top)->count >= STACK_MAX) {
        printf("Stack penuh, tidak dapat menambahkan data.\n");
        getchar();
        return;
    }

    printf("Masukkan bilangan: ");
    scanf("%d", &bil);

    pNew = (stack *)malloc(sizeof(stack));
    if (pNew == NULL) {
        printf("Alokasi memori gagal.\n");
        getchar();
        return;
    }

    pNew->data = bil;
    pNew->next = *top;
    pNew->count = (*top == NULL) ? 1 : (*top)->count + 1;
    *top = pNew;

    printf("Bilangan %d ditambahkan ke stack.\n", bil);
    getchar();
}

//==================================================================
void popdata(stack **top) {
    if (*top == NULL) {
        printf("Stack kosong, tidak ada data yang bisa di-pop.\n");
        getchar();
        return;
    }

    stack *temp = *top;
    *top = (*top)->next;
    printf("Data %d di-pop dari stack.\n", temp->data);
    free(temp);

    if (*top != NULL) {
        (*top)->count = (*top)->count - 1;
    }

    getchar();
}

//==================================================================
void stacktop(stack *top) {
    if (top == NULL) {
        printf("Stack kosong.\n");
    } else {
        printf("Data teratas: %d\n", top->data);
    }
    getchar();
}

//==================================================================
void stackempty(stack *top) {
    if (top == NULL) {
        printf("Stack kosong.\n");
    } else {
        printf("Stack tidak kosong.\n");
    }
    getchar();
}

//==================================================================
void stackfull(stack *top) {
    if (top == NULL) {
        printf("Stack belum penuh.\n");
    } else if (top->count >= STACK_MAX) {
        printf("Stack penuh.\n");
    } else {
        printf("Stack masih memiliki ruang.\n");
    }
    getchar();
}

//==================================================================
void stackcount(stack *top) {
    if (top == NULL) {
        printf("Stack terisi: 0 elemen.\n");
    } else {
        printf("Stack terisi: %d elemen.\n", top->count);
    }
    getchar();
}

// ==================================================================
void destroystack(stack **top) {
    while (*top != NULL) {
        stack *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
    printf("Stack telah dikosongkan.\n");
    getchar();
}
