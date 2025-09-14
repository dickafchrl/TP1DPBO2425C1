
from produk import Produk

class Menu:
    def __init__(self):
        self.daftarProduk = []

    def tambahProduk(self):
        id_produk = input("Masukan Id Produk: ")
        nama = input("Masukan Nama Produk: ")
        harga = input("Masukan Harga Produk: ")
        stok = input("Masukan Stok Produk: ")

        p = Produk(id_produk, nama, harga, stok)
        self.daftarProduk.append(p)

    def tampilProduk(self):
        for produk in self.daftarProduk:
            print("----------------------")
            print(produk.getId())
            print(produk.getNama())
            print(produk.getHarga())
            print(produk.getStok())
        print("----------------------")

    def updateData(self):
        id_target = input("Masukan id dari produk: ")
        found = False

        for produk in self.daftarProduk:
            if produk.getId() == id_target:
                found = True
                print("----------------------")
                print("Data lama:")
                print(produk.getId())
                print(produk.getNama())
                print(produk.getHarga())
                print(produk.getStok())
                print("----------------------")

                namaBaru = input("Nama baru: ")
                hargaBaru = input("Harga baru: ")
                stokBaru = input("Stok baru: ")

                produk.setNama(namaBaru)
                produk.setHarga(hargaBaru)
                produk.setStok(stokBaru)

                print("----------------------")
                print("Data berhasil diupdate!")
                print("----------------------")
                break

        if not found:
            print("Produk dengan ID tersebut tidak ditemukan")

    def hapusData(self):
        id_target = input("Masukan id dari produk: ")
        found = False

        for i, produk in enumerate(self.daftarProduk):
            if produk.getId() == id_target:
                found = True
                print("----------------------")
                print("Data yang akan dihapus:")
                print(produk.getId())
                print(produk.getNama())
                print(produk.getHarga())
                print(produk.getStok())
                print("----------------------")

                del self.daftarProduk[i]
                print("Produk dengan ID tersebut berhasil terhapus!")
                break

        if not found:
            print("Produk dengan ID tersebut tidak ditemukan")

    def cariData(self):
        id_target = input("Masukan id dari produk: ")
        found = False

        for produk in self.daftarProduk:
            if produk.getId() == id_target:
                found = True
                print("----------------------")
                print("Produk ditemukan:")
                print("----------------------")
                print(produk.getId())
                print(produk.getNama())
                print(produk.getHarga())
                print(produk.getStok())
                print("----------------------")
                break

        if not found:
            print("Produk dengan ID tersebut tidak ditemukan")


# Contoh penggunaan
if __name__ == "__main__":
    menu = Menu()
    while True:
        print("\n=== Menu ===")
        print("1. Tambah Produk")
        print("2. Tampil Produk")
        print("3. Update Produk")
        print("4. Hapus Produk")
        print("5. Cari Produk")
        print("0. Keluar")
        pilihan = input("Pilih menu: ")

        if pilihan == "1":
            menu.tambahProduk()
        elif pilihan == "2":
            menu.tampilProduk()
        elif pilihan == "3":
            menu.updateData()
        elif pilihan == "4":
            menu.hapusData()
        elif pilihan == "5":
            menu.cariData()
        elif pilihan == "0":
            print("Keluar program...")
            break
        else:
            print("Pilihan tidak valid!")