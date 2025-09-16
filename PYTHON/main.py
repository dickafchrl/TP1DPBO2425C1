from produk import Produk
 
daftarProduk = []

#fungsi Create pada code python
def tambahProduk():
    id = input("Masukan Id Produk: ")
    nama = input("Masukan Nama Produk: ")
    harga = input("Masukan Harga Produk: ")
    stok = input("Masukan Stok Produk: ")

    p = Produk(id, nama, harga, stok)
    daftarProduk.append(p)
    # Konfirmasi pada user
    print("Produk berhasil ditambahkan!")

#fungsi read pada code python
def tampilProduk():
    # Kondisi apabila data tersebut ada
    if len(daftarProduk) > 0:
        # Tampilkan data
        print("DATA KESELURUHAN PRODUK!")
        for p in daftarProduk:
            print("----------------------")
            print(p.getId())
            print(p.getNama())
            print(p.getHarga())
            print(p.getStok())
        print("----------------------")
    else:
    # Kondisi jika data tidak ada
        print("Tidak ada produk!")

# fungsi update pada code python
def updateData():
    # variabel untuk penampung id yang akan di cari
    id_target = input("Masukan id dari produk yang ingin diupdate: ")

    # Variabel flag
    found = False
    # Perulangan untuk pencarian
    for p in daftarProduk:
        # Jika id target di temukan
        if p.getId() == id_target:
            # Mengubah flag menjadi true
            found = True

            # Tampilan data lama untuk perbandingan
            print("----------------------")
            print("Data lama:")
            print(p.getId(), p.getNama(), p.getHarga(), p.getStok(), sep="\n")
            print("----------------------")

            # Konfirmasi pemasukan data baru
            print("Masukan data baru")
            namaBaru = input("Nama baru: ")
            hargaBaru = input("Harga baru: ")
            stokBaru = input("Stok baru: ")

            # Memasukan data baru
            p.setNama(namaBaru)
            p.setHarga(hargaBaru)
            p.setStok(stokBaru)

            # Konfirmasi pada user
            print("----------------------")
            print("Data berhasil diupdate!")
            print("----------------------")
    
    # Jika kondisi tidak ditemukan
    if not found:
        # Konfirmasi pada user
        print("Produk tidak ditemukan.")

# fungsi delete pada code python
def hapusData():
    # Variabel input untuk menyimpan id target
    id_target = input("Masukan id produk yang ingin dihapus: ")

    # Flag penentu
    found = False
    # Perulangan
    for i, p in enumerate(daftarProduk):
        # Kondisi apabila id target tersebut ada
        if p.getId() == id_target:
            found = True
            print("----------------------")
            print("Data yang akan dihapus:")
            print(p.getId(), p.getNama(), p.getHarga(), p.getStok(), sep="\n")
            print("----------------------")

            # Hapus target
            del daftarProduk[i]
            # Konfirmasi pengguna
            print("Produk berhasil terhapus!")
    
    # Kondisi apabila tidak ada 
    if not found:
        print("Produk tidak ditemukan.")

# Fungsi find pada code python
def cariData():
    # Variabel input untuk menyimpan id target
    id_target = input("Masukan id produk yang dicari: ")
    # Variabel flag
    found = False
    # Perulangan pencarian target
    for p in daftarProduk:
        # Kondisi apabila target ada
        if p.getId() == id_target:
            found = True
            print("----------------------")
            print("Produk ditemukan:")
            print(p.getId(), p.getNama(), p.getHarga(), p.getStok(), sep="\n")
            print("----------------------")
            break
    # Kondisi apabila target tidak ada
    if not found:
        print("Produk tidak ditemukan.")


# Main program
def main():
    start = True
    while start:
        # Menampilkan menu pada user
        print("\n=== Menu ===")
        print("1. Tambah Produk")
        print("2. Tampilkan Semua Produk")
        print("3. Update Data Produk")
        print("4. Hapus Produk")
        print("5. Cari Produk")
        print("6. Keluar")
        # Variabel input untuk menyimpan pilihan user
        pilihan = input("Masukan Pilihan anda: ")

        # Kondisi percabangan pada pemilihan opsi
        if pilihan == "1":
            tambahProduk()
        elif pilihan == "2":
            tampilProduk()
        elif pilihan == "3":
            updateData()
        elif pilihan == "4":
            hapusData()
        elif pilihan == "5":
            cariData()
        elif pilihan == "6":
            start = False
        else:
            print("Pilihan tidak valid, silakan coba lagi")

    print("Program selesai.")


if __name__ == "__main__":
    main()