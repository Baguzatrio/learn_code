#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void cariData(node *head);
void totalData(node *head);
void jumlahData(node *head);
void tranverse(node *head);
void insertNode(node **head, node *pPre, node *pNew);

//========================================================

int main() {
  node *head;
  int pilih;

  head = NULL;
  do{
     system("cls");
     printf("masukkan pilihan\n");
     printf("1. tambah data di awal list\n");
     printf("2. tambah data di tengah list\n");
     printf("3. tambah data di akhir list\n");
     printf("4. hapus data di awal list\n");
     printf("5. hapus data di tengah list\n");
     printf("6. hapus data di akhir list\n");
     printf("7. mencari data di list\n");
     printf("8. total data dalam list\n");
     printf("9. penjumlahan seluruh nilai data\n");
     printf("99. cetak isi list\n");
     printf("MASUKKAN PILIHAN (tekan 0 untuk keluar) : ");
     fflush(stdin);
     scanf("%d", &pilih);
     if (pilih == 1){
     		tambahAwal(&head);
     } else if (pilih == 2){
			tambahData(&head);
     } else if (pilih == 3){
            tambahAkhir(&head);
     } else if (pilih == 4){
            hapusAwal(&head);
     } else if (pilih == 5){
            hapusData(&head);
     } else if (pilih == 6){
            hapusAkhir(&head);
     } else if (pilih == 7){
            cariData(head);
     } else if (pilih == 8){
            totalData(head);
     } else if (pilih == 9){
            jumlahData(head);
     } else if (pilih == 99){
     		tranverse(head);
         getch();
     }
  } while (pilih != 0);

  return 0;
}

//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================

void tambahAwal(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            *head = pNew;
            pNew->next = *head;
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pNew->next = *head;
            *head = pNew;
            pCur->next = *head;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}


//========================================================

void tambahData(node **head){
    int pos, bil;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nbilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("List kosong, tambahkan data di awal list terlebih dahulu.\n");
        getch();
        return;
    }

    pCur = *head;
    do {
        if (pCur->data == pos) {
            pNew = (node *)malloc(sizeof(node));
            if (pNew == NULL) {
                printf("Alokasi memori gagal\n");
                getch();
                return;
            }

            pNew->data = bil;
            pNew->next = pCur->next;
            pCur->next = pNew;


            if (pNew->next == *head) {
                pNew->next = *head;
            }
            return;
        }
        pCur = pCur->next;
    } while (pCur != *head);

    printf("Node dengan nilai %d tidak ditemukan.\n", pos);
    getch();
}


//========================================================

void tambahAkhir(node **head){
    int bil;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan yang akan ditambah di akhir list: ");
    fflush(stdin);
    scanf("%d", &bil);

    pNew = (node *)malloc(sizeof(node));
    if (pNew != NULL) {
        pNew->data = bil;
        if (*head == NULL) {
            *head = pNew;
            pNew->next = *head;
        } else {
            pCur = *head;
            while (pCur->next != *head) {
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *head;
        }
    } else {
        printf("Alokasi memori gagal");
        getch();
    }
}

//=======================================================

void hapusAwal(node **head){
    if (*head == NULL) {
        printf("List kosong, tidak ada data yang dapat dihapus");
        getch();
        return;
    }

    node *pCur = *head;
    if ((*head)->next == *head) {

        free(pCur);
        *head = NULL;
    } else {
        node *pTail = *head;
        while (pTail->next != *head) {
            pTail = pTail->next;
        }
        *head = (*head)->next;
        pTail->next = *head;
        free(pCur);
    }
    printf("Node pertama berhasil dihapus");
    getch();
}


//=======================================================

void hapusData(node **head){
    int bil;
    node *pCur, *pPre;

    system("cls");
    tranverse(*head);
    printf("\nMasukkan node yang akan dihapus : ");
    fflush(stdin);
    scanf("%d", &bil);

    if (*head == NULL) {
        printf("List kosong, tidak ada data yang dapat dihapus\n");
        getch();
        return;
    }

    pCur = *head;
    pPre = NULL;

    do {
        if (pCur->data == bil) {
            if (pPre == NULL) {
                hapusAwal(head);
            } else {
                pPre->next = pCur->next;
                if (pCur->next == *head && pPre->next == *head) {
                    pPre->next = *head;
                }
                free(pCur);
                printf("Node dengan nilai %d telah dihapus\n", bil);
                getch();
            }
            return;
        }
        pPre = pCur;
        pCur = pCur->next;
    } while (pCur != *head);

    printf("Node dengan nilai %d tidak ditemukan\n", bil);
    getch();
}

//=======================================================

void hapusAkhir(node **head){
    if (*head == NULL) {
        printf("List kosong, tidak ada data yang dapat dihapus");
        getch();
        return;
    }

    node *pCur = *head, *pPre = NULL;
    if ((*head)->next == *head) {

        free(pCur);
        *head = NULL;
    } else {
        while (pCur->next != *head) {
            pPre = pCur;
            pCur = pCur->next;
        }
        pPre->next = *head;
        free(pCur);
    }
    printf("Node terakhir berhasil dihapus.");
    getch();
}


//=======================================================

void cariData(node *head){
    int bil;
    node *pCur;
    int urutan = 1; // Indeks node

    system("cls");
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &bil);

    if (head == NULL) {
        printf("List kosong, tidak ada node yang dapat dicari.\n");
        getch();
        return;
    }

    pCur = head;

    do {
        if (pCur->data == bil) {
            printf("Node dengan nilai %d ditemukan pada node %d.\n", bil, urutan);
            getch();
            return;
        }
        pCur = pCur->next;
        urutan++;
    } while (pCur != head);

    printf("Node dengan nilai %d tidak ditemukan.\n", bil);
    getch();
}


//=======================================================

void totalData(node *head){
    int count = 0; // Inisialisasi penghitung
    node *pCur = head;

    if (head == NULL) {
        system("cls");
        printf("List kosong, tidak ada data dalam list.\n");
        getch();
        return;
    }

    do {
        count++;
        pCur = pCur->next;
    } while (pCur != head);
    system("cls");
    printf("Total data dalam list adalah: %d\n", count);
    getch();
}


//=======================================================

void jumlahData(node *head){
    int total = 0; // Inisialisasi total
    node *pCur = head;

    if (head == NULL) {
        system("cls");
        printf("List kosong, tidak ada data dalam list.\n");
        getch();
        return;
    }

    do {
        total += pCur->data;
        pCur = pCur->next;
    } while (pCur != head);
    system("cls");
    tranverse(head); // Cetak list
    printf("\nJumlah nilai data dalam list adalah: %d\n", total);
    getch();
}


//=======================================================

void tranverse(node *head){
    node *pWalker;

    system("cls");
    if (head == NULL) {
        printf("List kosong.");
        return;
    }

    pWalker = head;
    do {
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
        printf(" -> ");
    } while (pWalker != head);

    printf("(kembali ke head)");
}


//========================================================

void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){
       //add before first logical node or to an empty list
	    pNew -> next = *head;
       *head = pNew;
    }
    else {
       //add in the middle or at the end
       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}

//========================================================

