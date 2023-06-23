#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact *CAddress;

typedef struct contact
{
    char name[50];
    char phone[50];
    CAddress Next;
} Contact;

CAddress *head = NULL;

void AddContact(char *name, char *phone) {
    CAddress new_contact = (CAddress)malloc(sizeof(CAddress));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    new_contact->Next = NULL;

    if (head == NULL) {
        head = new_contact;
    } else {
        CAddress current = head;
        while (current->Next != NULL) {
            current = current->Next;
        }
        current->Next = new_contact;
    }
}

void SearchContact(char *name) {
    CAddress current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Data ditemukan!\n");
            printf("Nama: %s\n", current->name);
            printf("Nomor Telepon: %s\n", current->phone);
            return;
        }
        current = current->Next;
    }
    printf("Data tidak ditemukan!\n");
}

void PrintContacts() {
    CAddress current = head;
    printf("Daftar Kontak Telepon:\n");
    while (current != NULL) {
        printf("Nama: %s\n", current->name);
        printf("Nomor Telepon: %s\n", current->phone);
        current = current->Next;
    }
}

int main() {
    int menu;
    char name[50];
    char phone[20];

    do {
        printf("Menu:\n");
        printf("1. Tambah Kontak\n");
        printf("2. Cari Kontak\n");
        printf("3. Cetak Daftar Kontak\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("Nama: ");
                scanf("%s", name);
                printf("Nomor Telepon: ");
                scanf("%s", phone);
                AddContact(name, phone);
                printf("Kontak berhasil ditambahkan.\n");
                break;
            case 2:
                printf("Nama: ");
                scanf("%s", name);
                SearchContact(name);
                break;
            case 3:
                PrintContacts();
                break;
            case 4:
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
        getchar();
        printf("Tekan tombol apa saja untuk melanjutkan...\n");
        getchar();
    } while (menu != 4);

    return 0;
}