import java.util.ArrayList;
import java.util.Scanner;

class Menu {
    private ArrayList<Produk> daftarProduk;

    public Menu() {
        daftarProduk = new ArrayList<>();
    }

    public void tambahProduk() {
        // Membuat variabel input
        Scanner sc = new Scanner(System.in);

        // Membuat fungsi pemasukan data
        System.out.print("Masukan Id Produk: ");
        String id = sc.nextLine();  // Input user
        System.out.print("Masukan Nama Produk: ");
        String nama = sc.nextLine(); // Input user
        System.out.print("Masukan Harga Produk: ");
        String harga = sc.nextLine(); // Input user
        System.out.print("Masukan Stok Produk: ");
        String stok = sc.nextLine(); // Input user

        // Pembuatan objek dengan constructor
        Produk p = new Produk(id, nama, harga, stok);
        // Memasukan objek kedalam array
        daftarProduk.add(p);
        // Konfirmasi pada user
        System.out.println("Produk berhasil ditambahkan!");
    }

    public void tampilProduk() {
        // Kondisi jika array produk kosong
        if (daftarProduk.isEmpty()) {
            // konfirmasi pada use
            System.out.println("Tidak ada produk!");
            return;
        }
        // Perulangan untuk membaca dan menampilkan daftar produk
        for (Produk p : daftarProduk) {
            System.out.println("----------------------");
            System.out.println("ID   : " + p.getId());
            System.out.println("Nama : " + p.getNama());
            System.out.println("Harga: " + p.getHarga());
            System.out.println("Stok : " + p.getStok());
        }
        System.out.println("----------------------");
    }

    public void updateData() {
        // Variabel input
        Scanner sc = new Scanner(System.in);
        System.out.print("Masukan id produk yang ingin diupdate: ");
        // Variabel input untuk menyimpan id target
        String id_target = sc.nextLine();

        // Memulai operasi pencarian
        for (Produk p : daftarProduk) {
            if (p.getId().equals(id_target)) {
                System.out.print("Nama baru: ");
                p.setNama(sc.nextLine());
                System.out.print("Harga baru: ");
                p.setHarga(sc.nextLine());
                System.out.print("Stok baru: ");
                p.setStok(sc.nextLine());
                System.out.println("Produk berhasil diupdate!");
                return;
            }
        }
        // Jika hasil tidak di temukan
        System.out.println("Produk tidak ditemukan.");
    }

    public void hapusData() {
        // Variabel input
        Scanner sc = new Scanner(System.in);
        System.out.print("Masukan id produk yang ingin dihapus: ");
        // Variabel input untuk menyimpan id target
        String id_target = sc.nextLine();
        // Memulai operasi pencarian
        for (int i = 0; i < daftarProduk.size(); i++) {
            if (daftarProduk.get(i).getId().equals(id_target)) {
                daftarProduk.remove(i);
                System.out.println("Produk berhasil dihapus!");
                return;
            }
        }
        // Konfirmasi user
        System.out.println("Produk tidak ditemukan.");
    }

    public void cariData() {
        // Variabel input
        Scanner sc = new Scanner(System.in);
        System.out.print("Masukan id produk yang dicari: ");
        // Variabel input untuk menyimpan id target
        String id_target = sc.nextLine();
        // Memulai operasi pencarian
        for (Produk p : daftarProduk) {
            if (p.getId().equals(id_target)) {
                System.out.println("Produk ditemukan!");
                System.out.println("ID   : " + p.getId());
                System.out.println("Nama : " + p.getNama());
                System.out.println("Harga: " + p.getHarga());
                System.out.println("Stok : " + p.getStok());
                return;
            }
        }
        // konfirmasi user
        System.out.println("Produk tidak ditemukan.");
    }
}

// Class Main
public class Main {
    public static void main(String[] args) {
        Menu mainMenu = new Menu();
        // Variabel input
        Scanner sc = new Scanner(System.in);
        // flag program apakah mulai / tidak
        boolean start = true;
        
        
        while (start) {
            // Menampilkan menu pada user
            System.out.println("\n=== Menu ===");
            System.out.println("1. Tambah Produk");
            System.out.println("2. Tampilkan Semua Produk");
            System.out.println("3. Update Data Produk");
            System.out.println("4. Hapus Produk");
            System.out.println("5. Cari Produk");
            System.out.println("6. Keluar");
            System.out.print("Masukan Pilihan anda: ");

            // Variabel penentu pilihan
            int pilihan;
            // Fungsi cek variabel
            try {
                pilihan = Integer.parseInt(sc.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Input tidak valid! Harus berupa angka.");
                continue;
            }
            // Kondisi percabangan untuk pemilihan user
            switch (pilihan) {
                case 1 -> mainMenu.tambahProduk();
                case 2 -> mainMenu.tampilProduk();
                case 3 -> mainMenu.updateData();
                case 4 -> mainMenu.hapusData();
                case 5 -> mainMenu.cariData();
                case 6 -> start = false;
                default -> System.out.println("Pilihan tidak valid!");
            }
        }
        // Konfirmasi user program telah selesai
        System.out.println("Program selesai.");
    }
}