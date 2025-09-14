from menu import Menu   # import class Menu dari menu.py
#from produk import produk
def main():
    # Buat object
    main_menu = Menu()
    
    # Buat atribut sebagai penanda dan pilihan user
    start = False
    pilihan = 0

    # Tampilkan menu pilihan untuk user
    print("=== Input pilihan User ===")
    print("1. Tambah Produk")
    print("2. Tampilkan Semua Produk")
    print("3. Update Data Produk")
    print("4. Hapus Produk")
    print("5. Cari Produk")
    print("6. Keluar")

    # Buat perulangan untuk keberjalanan program
    while not start:
        try:
            pilihan = int(input("Masukan Pilihan anda: "))
        except ValueError:
            print("Input harus berupa angka!")
            continue

        # Buat kondisi percabangan untuk pemilihan opsi
        if pilihan == 1:
            main_menu.tambahProduk()
        elif pilihan == 2:
            main_menu.tampilProduk()
        elif pilihan == 3:
            main_menu.updateData()
        elif pilihan == 4:
            main_menu.hapusData()
        elif pilihan == 5:
            main_menu.cariData()
        elif pilihan == 6:
            start = True
        else:
            print("Pilihan tidak valid, silakan coba lagi")

if __name__ == "__main__":
    main()