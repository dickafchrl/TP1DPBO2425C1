import java.util.ArrayList;
import java.util.Scanner;

public class Menu {
    private ArrayList<Produk> daftarProduk;

    public Menu() {
        daftarProduk = new ArrayList<>();
    }

    public void tambahProduk() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Masukan Id Produk:");
        String id = sc.nextLine();

        System.out.println("Masukan Nama Produk:");
        String nama = sc.nextLine();

        System.out.println("Masukan Harga Produk:");
        String harga = sc.nextLine();

        System.out.println("Masukan Stok Produk:");
        String stok = sc.nextLine();

        Produk p = new Produk(id, nama, harga, stok);
        daftarProduk.add(p);
    }

    public void tampilProduk() {
        for (Produk p : daftarProduk) {
            System.out.println("----------------------");
            System.out.println(p.getId());
            System.out.println(p.getNama());
            System.out.println(p.getHarga());
            System.out.println(p.getStok());
        }
        System.out.println("----------------------");
    }

    public void updateData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Masukan id dari produk:");
        String id_target = sc.nextLine();

        boolean found = false;

        for (Produk p : daftarProduk) {
            if (p.getId().equals(id_target)) {
                found = true;

                System.out.println("----------------------");
                System.out.println("Data lama:");
                System.out.println(p.getId());
                System.out.println(p.getNama());
                System.out.println(p.getHarga());
                System.out.println(p.getStok());
                System.out.println("----------------------");

                System.out.println("Masukan data baru");
                System.out.print("Nama baru: ");
                String namaBaru = sc.nextLine();
                System.out.print("Harga baru: ");
                String hargaBaru = sc.nextLine();
                System.out.print("Stok baru: ");
                String stokBaru = sc.nextLine();

                p.setNama(namaBaru);
                p.setHarga(hargaBaru);
                p.setStok(stokBaru);

                System.out.println("----------------------");
                System.out.println("Data berhasil diupdate!");
                System.out.println("----------------------");
                break;
            }
        }

        if (!found) {
            System.out.println("Produk dengan ID tersebut tidak ditemukan");
        }
    }

    public void hapusData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Masukan id dari produk:");
        String id_target = sc.nextLine();

        boolean found = false;

        for (int i = 0; i < daftarProduk.size(); i++) {
            Produk p = daftarProduk.get(i);
            if (p.getId().equals(id_target)) {
                found = true;

                System.out.println("----------------------");
                System.out.println("Data yang akan dihapus:");
                System.out.println(p.getId());
                System.out.println(p.getNama());
                System.out.println(p.getHarga());
                System.out.println(p.getStok());
                System.out.println("----------------------");

                daftarProduk.remove(i);
                System.out.println("Produk dengan ID tersebut berhasil terhapus!");
                break;
            }
        }

        if (!found) {
            System.out.println("Produk dengan ID tersebut tidak ditemukan");
        }
    }

    public void cariData() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Masukan id dari produk:");
        String id_target = sc.nextLine();

        boolean found = false;

        for (Produk p : daftarProduk) {
            if (p.getId().equals(id_target)) {
                found = true;

                System.out.println("----------------------");
                System.out.println("Produk ditemukan:");
                System.out.println("----------------------");
                System.out.println(p.getId());
                System.out.println(p.getNama());
                System.out.println(p.getHarga());
                System.out.println(p.getStok());
                System.out.println("----------------------");
                break;
            }
        }

        if (!found) {
            System.out.println("Produk dengan ID tersebut tidak ditemukan");
        }
    }
}