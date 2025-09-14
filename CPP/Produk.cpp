#include <iostream>
#include <string>

using namespace std;

class Produk {
    // Atribut bersifat rahasia
    private:
        string id;  // Untuk id barang elektronik
        string nama; // Untuk nama barang elektronik
        string harga; // Untuk harga barang elektronik
        string stok; // Untuk stok barang elektronik

    // Method yang bersifat public
    public:
        // Constructor untuk inisiasi atribut
        Produk(string id, string nama, string harga, string stok) {
            this->id = id;
            this->nama = nama;
            this->harga = harga;
            this->stok = stok;
        }

        // Membuat Getter dan Setter untuk setiap atribut
        string getId() {return id;} // Getter dari atribut id

        void setId(string id) {this->id = id;} // Setter dari atribut id
        
        string getNama() {return nama;} // Getter dari atribut nama

        void setNama(string nama) {this->nama = nama;} // Setter dari atribut nama
        
        string getHarga() {return harga;} // Getter dari atribut harga

        void setHarga(string harga) {this->harga = harga;} // Setter dari atribut harga
        
        string getStok() {return stok;} // Getter dari atribut stok

        void setStok(string stok) {this->stok = stok;} // Setter dari atribut stok

        // Destruktor
        ~Produk() { }
};