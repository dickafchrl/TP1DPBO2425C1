#include <iostream>
#include <string>
#include <vector>
#include "Produk.cpp"
#include "Menu.cpp"

using namespace std;

int main() {
    // Buat object
    menu MainMenu;
    
    // Tampilkan Menu pilihan untuk user
    cout << "Input pilihan User" << endl;
    cout << "1. Tambah Produk" << endl;
    cout << "2. Tampilkan Semua Produk" << endl;
    cout << "3. Upadate Data Produk" << endl;
    cout << "4. Hapus Produk" << endl;
    cout << "5. Cari Produk" << endl;
    cout << "6. Keluar" << endl;
    
    // Buat atribut sebagai penanda dan pilihan user
    bool start = false;
    int pilihan = 0;

    // Buat perulangan untuk keberjalanan program
    while (start == false) {
        cout << "Masukan Pilihan anda :" << endl;
        cin >> pilihan;

        // Buat kondisi percabangan untuk pemilihan opsi
        if (pilihan == 1) {
            MainMenu.tambahProduk();
        } else if (pilihan == 2) {
            MainMenu.tampilProduk();
        } else if (pilihan == 3) {
            MainMenu.updateData();
        } else if (pilihan == 4) {
            MainMenu.hapusData();
        } else if (pilihan == 5) {
            MainMenu.cariData();
        } else if (pilihan == 6) {
            start = true;
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi" << endl;
        }      
    }
    
    return 0;
}