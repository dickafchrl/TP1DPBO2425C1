public class Produk {
    // Atribut bersifat rahasia :
    private String id; // Untuk id barang elektronik
    private String nama; // Untuk nama barang elektronik
    private String harga; // Untuk harga barang elektronik
    private String stok; // Untuk stok barang elektronik

    // Method bersigat public :
    public Produk(String id, String nama, String harga, String stok) {
        this.id = id;
        this.nama = nama;
        this.harga = harga;
        this.stok = stok;
    }

    // Membuat getter dan setter untuk setiap atribut
    // Getter pada atribut id :
    public String getId() {
        return id;
    }
    // Getter pada atribut nama :
    public String getNama() {
        return nama;
    }
    // Getter pada atribut harga :
    public String getHarga() {
        return harga;
    }
    // Getter pada atribut stok :
    public String getStok() {
        return stok;
    }

    // Setter pada atribut id :
    public void setId(String id) {
        this.id = id;
    }
    // Setter pada atribut nama :
    public void setNama(String nama) {
        this.nama = nama;
    }
    // Setter pada atribut harga :
    public void setHarga(String harga) {
        this.harga = harga;
    }
    // Setter pada atribut stok :
    public void setStok(String stok) {
        this.stok = stok;
    }

    // Tidak membuat destruktor pada java, karena
    // Java memiliki tempat destruktor nya sendiri.
}