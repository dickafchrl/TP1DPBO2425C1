#include <iostream>
#include <string>
#include <vector>

using namespace std;

class menu {
    // Atribut bersifat rahasia
    private:
        vector<Produk> daftarProduk;

    // Method yang bersifat public
    public:

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

            // Memasukan hasil kedalam vector
            daftarProduk.push_back(p);
        }

        void tampilProduk() { 
            // Buat perulangan untuk membaca setiap data dari daftar produk
            for (int i = 0; i < daftarProduk.size(); i++) {
                cout << "----------------------" << endl;
                cout << daftarProduk[i].getId() << endl;
                cout << daftarProduk[i].getNama() << endl;
                cout << daftarProduk[i].getHarga() << endl;
                cout << daftarProduk[i].getStok() << endl;
            }
            cout << "----------------------" << endl;
        }

        void updateData() {
            // Membuat atribut penyimpan sementara
            string id_target;

            // Membuat konfismasi pemasukan id produk yang akan di ubah
            cout << "Masukan id dari produk :" << endl; cin >> id_target;

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
                cout << "Produk dengan ID tersebut tidak ditemukan" << endl;
            }
        }

        void hapusData() {
            // Membuat atribut penyimpan sementara
            string id_target;

            // Membuat konfismasi pemasukan id produk yang akan di ubah
            cout << "Masukan id dari produk :" << endl; cin >> id_target;

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
                    cout << "Produk dengan ID tersebut berhasil terhapus!" << endl;
                }
                // iterasikan tanda penghitung
                i++;
            }
            
            // Kondisi jika data tidak ditemukan
            if (found == false) {
                // Konfirmasi bahwa data tidak di temukan
                cout << "Produk dengan ID tersebut tidak ditemukan" << endl;
            }
        }

        void cariData() {
            // Membuat atribut penyimpan sementara
            string id_target;

            // Membuat konfismasi pemasukan id produk yang akan di ubah
            cout << "Masukan id dari produk :" << endl; cin >> id_target;

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
                cout << "Produk dengan ID tersebut tidak ditemukan" << endl;
            }
        }
};