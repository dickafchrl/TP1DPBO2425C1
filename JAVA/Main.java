import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Menu mainMenu = new Menu();
        Scanner sc = new Scanner(System.in);
        boolean start = false;

        System.out.println("\n=== Input pilihan User ===");
        System.out.println("1. Tambah Produk");
        System.out.println("2. Tampilkan Semua Produk");
        System.out.println("3. Update Data Produk");
        System.out.println("4. Hapus Produk");
        System.out.println("5. Cari Produk");
        System.out.println("6. Keluar");
        System.out.print("Masukan Pilihan anda: ");
        
        while (!start) {

            int pilihan;
            try {
                pilihan = Integer.parseInt(sc.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Input tidak valid! Harus berupa angka.");
                continue;
            }

            switch (pilihan) {
                case 1:
                    mainMenu.tambahProduk();
                    break;
                case 2:
                    mainMenu.tampilProduk();
                    break;
                case 3:
                    mainMenu.updateData();
                    break;
                case 4:
                    mainMenu.hapusData();
                    break;
                case 5:
                    mainMenu.cariData();
                    break;
                case 6:
                    start = true;
                    break;
                default:
                    System.out.println("Pilihan tidak valid, silakan coba lagi");
            }
        }

        sc.close();
        System.out.println("Program selesai.");
    }
}