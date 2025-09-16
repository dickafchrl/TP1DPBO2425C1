#include <iostream>
#include <string>
#include <vector>
#include "Produk.cpp"

using namespace std;

    vector<Produk> daftarProduk;

    void tambahProduk() {    
        // Membuat atribut untuk penyimpanan sementara
        string id, nama, harga, stok;

        // Membuat fungsi pemasukan data
        cout << "Masukan Id Produk:" << endl; cin >> id;

        cout << "Masukan Nama Produk:" << endl; cin >> nama;
        
        cout << "Masukan Harga Produk:" << endl; cin >> harga;
        
        cout << "Masukan Stok Produk:" << endl; cin >> stok;
    
        // Membuat objek dengan constructor
        Produk p(id, nama, harga, stok);

        int total = daftarProduk.size();

        // Memasukan hasil kedalam vector
        daftarProduk.push_back(p);

        // Konfirmasi user
        cout << "Produk berhasil ditambahkan!" << endl;
    }

    void tampilProduk() { 
        if (daftarProduk.size() > 0)
        {
            cout << "DATA KESELURUHAN PRODUK!" << endl;
            // Buat perulangan untuk membaca setiap data dari daftar produk
            for (int i = 0; i < daftarProduk.size(); i++) {
                cout << "----------------------" << endl;
                cout << daftarProduk[i].getId() << endl;
                cout << daftarProduk[i].getNama() << endl;
                cout << daftarProduk[i].getHarga() << endl;
                cout << daftarProduk[i].getStok() << endl;
            }
            cout << "----------------------" << endl;
        } else {
            cout << "Tidak ada produk!" << endl;
        }
    }

    void updateData() {
        // Membuat atribut penyimpan sementara
        string id_target;

        // Membuat konfismasi pemasukan id produk yang akan di ubah
        cout << "Masukan id dari produk yang ingin diupdate :" << endl; cin >> id_target;

        // Membuat tanda untuk hasil pencarian
        bool found = false;

        // Memulai operasi pencarian
        for (int i = 0; i < daftarProduk.size(); i++) {
            // Jika id target ditemukan
            if (daftarProduk[i].getId() == id_target) {
                // Ubah tanda menjadi true
                found = true;

                // Tampilkan data lama untuk perbandingan
                cout << "----------------------" << endl;
                cout << "Data lama:" << endl;
                cout << daftarProduk[i].getId() << endl;
                cout << daftarProduk[i].getNama() << endl;
                cout << daftarProduk[i].getHarga() << endl;
                cout << daftarProduk[i].getStok() << endl;
                cout << "----------------------" << endl;

                // Membuat konfirmasi untuk memasukan data baru
                cout << "Masukan data baru" << endl;
                string namaBaru, hargaBaru, stokBaru;
                
                // Pengisian data baru
                cout << "Nama baru :" << endl; cin >> namaBaru;
                cout << "harga baru :" << endl; cin >> hargaBaru;
                cout << "stok baru :" << endl; cin >> stokBaru;

                // Proses pengubahan data
                daftarProduk[i].setNama(namaBaru);
                daftarProduk[i].setHarga(hargaBaru);
                daftarProduk[i].setStok(stokBaru);

                // Konfirmasi bahwa data berhasil di update!!
                cout << "----------------------" << endl;
                cout << "Data berhasil diupdate!" << endl;
                cout << "----------------------" << endl;
            }
        }

        // Kondisi jika data tidak ditemukan
        if (found == false) {
            // Konfirmasi bahwa data tidak di temukan
            cout << "Produk tidak ditemukan." << endl;
        }
    }

    void hapusData() {
        // Membuat atribut penyimpan sementara
        string id_target;

        // Membuat konfismasi pemasukan id produk yang akan di hapus
        cout << "Masukan id produk yang ingin di hapus:" << endl; cin >> id_target;

        // Membuat tanda untuk hasil pencarian
        bool found = false;

        // Membuat tanda untuk iterasi
        int i = 0;
        // Memulai operasi pencarian
        while (found == false && i <= daftarProduk.size()) {
            // Jika id target ditemukan
            if (daftarProduk[i].getId() == id_target) {
                // Ubah tanda menjadi true
                found = true;

                // Tampilkan data yang akan di hapus
                cout << "----------------------" << endl;
                cout << "Data yang akan dihapus:" << endl;
                cout << daftarProduk[i].getId() << endl;
                cout << daftarProduk[i].getNama() << endl;
                cout << daftarProduk[i].getHarga() << endl;
                cout << daftarProduk[i].getStok() << endl;
                cout << "----------------------" << endl;

                // Memulai penghapusan data
                daftarProduk.erase(daftarProduk.begin() + i);

                // Konfirmasi bahwa data telah dihapus
                cout << "Produk berhasil terhapus!" << endl;
            }
            // iterasikan tanda penghitung
            i++;
        }
        
        // Kondisi jika data tidak ditemukan
        if (found == false) {
            // Konfirmasi bahwa data tidak di temukan
            cout << "Produk tidak ditemukan." << endl;
        }
    }

    void cariData() {
        // Membuat atribut penyimpan sementara
        string id_target;

        // Membuat konfismasi pemasukan id produk yang akan di cari
        cout << "Masukan id produk yang di cari:" << endl; cin >> id_target;

        // Membuat tanda untuk hasil pencarian
        bool found = false;

        // Memulai operasi pencarian
        for(int i = 0; i < daftarProduk.size(); i++) {
            // Jika id target ditemukan
            if (daftarProduk[i].getId() == id_target) {
                // Ubah tanda menjadi true
                found = true;

                // Tampilkan data 
                cout << "----------------------" << endl;
                cout << "Produk ditemukan :" << endl;
                cout << "----------------------" << endl;
                cout << daftarProduk[i].getId() << endl;
                cout << daftarProduk[i].getNama() << endl;
                cout << daftarProduk[i].getHarga() << endl;
                cout << daftarProduk[i].getStok() << endl;
                cout << "----------------------" << endl;
            }
        }
        // Kondisi jika data tidak ditemukan
        if (found == false) {
            // Konfirmasi bahwa data tidak di temukan
            cout << "Produk tidak ditemukan." << endl;
        }
    }

int main() {

    
    // Buat atribut sebagai penanda dan pilihan user
    bool start = false;
    int pilihan = 0;
    
    // Buat perulangan untuk keberjalanan program
    while (start == false) {
        // Tampilkan Menu pilihan untuk user
        cout << "===Menu===" << endl;
        cout << "1. Tambah Produk" << endl;
        cout << "2. Tampilkan Semua Produk" << endl;
        cout << "3. Upadate Data Produk" << endl;
        cout << "4. Hapus Produk" << endl;
        cout << "5. Cari Produk" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukan Pilihan anda :" << endl;
        
        cin >> pilihan;

        // Buat kondisi percabangan untuk pemilihan opsi
        if (pilihan == 1) {
            cout << "Tambah Data :" << endl;
            tambahProduk();
        } else if (pilihan == 2) {
            cout << "Tampil Data" << endl;
            tampilProduk();
        } else if (pilihan == 3) {
            cout << "Update Data" << endl;
            updateData();
        } else if (pilihan == 4) {
            cout << "Hapus Data" << endl;
            hapusData();
        } else if (pilihan == 5) {
            cout << "Cari Data" << endl;
            cariData();
        } else if (pilihan == 6) {
            start = true;
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi" << endl;
        }
    }
    // Konfirmasi user program telah selesai
    cout << "Program Selesai" << endl;

    return 0;
}