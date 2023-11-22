#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int barang = 0;

// Deklarasi struct untuk menyimpan informasi barang
struct Barang {
    char nama[50];
    char kategori[50];
    int harga;
    int stok;
};

// Deklarasi array untuk menyimpan barang
struct Barang list_barang[50];
int jumlah_barang = 0;

// Fungsi untuk menampilkan menu
void tampilkan_menu() {
    printf("Menu\n");
    printf("1. Tampilkan Data Barang\n");
    printf("2. Mencari Barang Berdasarkan Kategori\n");
    printf("3. Menambahkan Barang Baru\n");
    printf("4. Menghapus Barang\n");
    printf("5. Banyak Barang\n");
    printf("6. Keluar\n");
    printf("Pilihan Anda: ");
}

// Fungsi untuk menampilkan semua data barang
void tampilkan_data_barang() {
    printf("\nDaftar Barang\n");
    printf("-----------------------------------------------------------\n");
    printf("| No. | Nama Barang            | Kategori      | Harga | Stok |\n");
    printf("-----------------------------------------------------------\n");
    int i;
    for (i = 0; i < jumlah_barang; i++) {
        printf("| %-3d | %-22s | %-12s | %-5d | %-4d |\n", i+1, list_barang[i].nama, list_barang[i].kategori, list_barang[i].harga, list_barang[i].stok);
    }
    printf("-----------------------------------------------------------\n");
}

// Fungsi untuk mencari barang berdasarkan kategori
void cari_barang_berdasarkan_kategori() {
    char kategori[50];
    int ditemukan = 0;
    printf("\nMasukkan Kategori Barang: ");
    scanf("%s", kategori);
    printf("\nHasil Pencarian Barang dengan Kategori %s\n", kategori);
    printf("-----------------------------------------------------------\n");
    printf("| No. | Nama Barang            | Harga | Stok |\n");
    printf("-----------------------------------------------------------\n");
    int i;
    for (i = 0; i < jumlah_barang; i++) {
        if (strcmp(list_barang[i].kategori, kategori) == 0) {
            printf("| %-3d | %-22s | %-5d | %-4d |\n", i+1, list_barang[i].nama, list_barang[i].harga, list_barang[i].stok);
            ditemukan = 1;
        }
    }
    printf("-----------------------------------------------------------\n");
    if (!ditemukan) {
        printf("\nTidak ada barang dengan kategori %s\n", kategori);
    }
}

// Fungsi untuk menambahkan barang baru
void tambah_barang_baru() {
    printf("\nMasukkan Nama Barang: ");
    scanf("%s", list_barang[jumlah_barang].nama);
    printf("Masukkan Kategori Barang: ");
    scanf("%s", list_barang[jumlah_barang].kategori);
    printf("Masukkan Harga Barang: ");
    scanf("%d", &list_barang[jumlah_barang].harga);
    printf("Masukkan Stok Barang: ");
    scanf("%d", &list_barang[jumlah_barang].stok);
    jumlah_barang++;
    printf("\nBarang berhasil ditambahkan!\n");
}

// Fungsi untuk menghapus barang
void hapus_barang() {
int nomor_barang;
printf("\nMasukkan Nomor Barang yang Akan Dihapus: ");
scanf("%d", &nomor_barang);
if (nomor_barang < 1 || nomor_barang > jumlah_barang) {
printf("\nNomor barang tidak valid!\n");
return;
}
int i;
for (i = nomor_barang - 1; i < jumlah_barang - 1; i++) {
list_barang[i] = list_barang[i+1];
}
jumlah_barang--;
printf("\nBarang berhasil dihapus!\n");
}

int main() {
    int pilihan;
    do {
        tampilkan_menu();
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                tampilkan_data_barang();
                break;
            case 2:
                cari_barang_berdasarkan_kategori();
                break;
            case 3:
                tambah_barang_baru();
                break;
            case 4:
                hapus_barang();
                break;
            case 5:
                printf("Banyak barang = %d", &banyak);
                break;
            case 6:
                printf("\nTerima kasih!\n");
                break;
            default:
                printf("\nPilihan tidak valid! Silakan pilih lagi.\n");
                break;
        }
    } while (pilihan != 6);
    return 0;
}