public class Produk {
    private String id;
    private String nama;
    private String harga;
    private String stok;

    public Produk(String id, String nama, String harga, String stok) {
        this.id = id;
        this.nama = nama;
        this.harga = harga;
        this.stok = stok;
    }

    // Getter
    public String getId() {
        return id;
    }

    public String getNama() {
        return nama;
    }

    public String getHarga() {
        return harga;
    }

    public String getStok() {
        return stok;
    }

    // Setter
    public void setNama(String nama) {
        this.nama = nama;
    }

    public void setHarga(String harga) {
        this.harga = harga;
    }

    public void setStok(String stok) {
        this.stok = stok;
    }
}