#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//========================================================

struct node {
	int data;
    struct node *next;
};
typedef struct node node;

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
  node *pNew;

  system("cls");
  fflush(stdin);
  printf("masukkan bilangan : ");
  fflush(stdin);
  scanf("%d", &bil);
  pNew = (node *)malloc(sizeof(node));

  if (pNew != NULL){
  	  pNew->data = bil;
      pNew->next = NULL;

	  pNew -> next = *head;
      *head = pNew;
  }
  else{
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

  pCur = *head;
  while (pCur != NULL && pCur -> data != pos) {
    pCur = pCur -> next;
  }

  pNew = (node *)malloc(sizeof(node));

  if (pCur == NULL){
     printf("\nnode tidak ditemukan");
     getch();
  }
  else if (pNew == NULL){
     printf("\nalokasi memeori gagal");
     getch();
  }
  else{
     pNew->data = bil;
     pNew->next = NULL;
     pNew -> next = pCur -> next;
     pCur -> next = pNew;
  }
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

  if (pNew != NULL){
    pNew->data = bil;
    pNew->next = NULL;

    if (*head == NULL){
        *head = pNew;
    } else {
        pCur = *head;
        while(pCur->next != NULL){
            pCur = pCur->next;
        }
        pCur->next = pNew;
            }
  } else{
      printf("Alokasi memori gagal");
      getch();
  }

}

//=======================================================

void hapusAwal(node **head){

  system("cls");
  if (*head == NULL){
    printf("List kosong, tidak ada data yang dapat dihapus");
    getch();
  }
  node *pCur = *head;
  *head = (*head)->next;
  free(pCur);
  printf("Node pertama berhasil dihapus");
  getch();

}

//=======================================================

void hapusData(node **head){
  int bil;
  node *pPre, *pCur;

  system("cls");
  tranverse(*head);
  printf("\nMasukkan node yang akan dihapus :");
  fflush(stdin);
  scanf("%d", &bil);

   pCur = *head;
   pPre = NULL;
  while (pCur != NULL && pCur -> data != bil){
    pPre = pCur;
    pCur = pCur -> next;
  }
  if (pCur == NULL){
    printf("Node %d tidak ditemukan\n", bil);
    getch();
  }
  if (pPre == NULL){
    *head = pCur->next;
  }
  else {
    pPre->next = pCur->next;
  }
  free(pCur);
  printf("Node dengan nilai %d telah dihapus",bil);
  getch();
}

//=======================================================

void hapusAkhir(node **head){

  node *pPre, *pCur;
  system("cls");
    pPre = *head;
    pCur = (*head)->next;

    while (pCur->next != NULL) {
        pPre = pCur;
        pCur = pCur->next;
    }

    pPre->next = NULL;
    free(pCur);
    printf("Node terakhir telah dihapus.\n");
    getch();

}

//=======================================================

void cariData(node *head) {
    int bil;
    node *pCur;
    int urutan = 1;

    system("cls");
    printf("Masukkan nilai yang ingin dicari: ");
    scanf("%d", &bil);

    pCur = head;
    while (pCur != NULL) {
        if (pCur->data == bil) {
            printf("Node dengan nilai %d ditemukan di urutan %d.\n", bil, urutan);
            getch();
            return;
        }
        pCur = pCur->next;
        urutan++;
    }

    printf("Node dengan nilai %d tidak ditemukan.\n", bil);
    getch();
}


//=======================================================

void totalData(node *head){
int count = 0;
    node *pCur = head;

    while (pCur != NULL) {
        count++;
        pCur = pCur->next;
    }
        system("cls");
        printf("Total data dalam list adalah: %d\n", count);
        getch();

}

//=======================================================

void jumlahData(node *head){
int total = 0;
    node *pCur = head;

    while (pCur != NULL) {
        total += pCur->data;
        pCur = pCur->next;
    }

    system("cls");
    tranverse(head);
    printf("\nJumlah nilai data dalam list adalah: %d\n", total);
    getch();
}

//=======================================================

void tranverse(node *head){
	node *pWalker;

   system("cls");
	pWalker = head;
	while (pWalker != NULL){
   	printf("%d\t", pWalker -> data);
   	pWalker = pWalker -> next;
      printf(" -> ");
	}
   printf("NULL");
}

//========================================================

void insertNode(node **head, node *pPre, node *pNew){
    if (pPre == NULL){

	    pNew -> next = *head;
       *head = pNew;
    }
    else {

       pNew -> next = pPre -> next;
       pPre -> next = pNew;
   }
}

//========================================================

