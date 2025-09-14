<?php
class Produk {
    private $id;
    private $nama;
    private $harga;
    private $stok;
    private $foto;

    public function __construct($id, $nama, $harga, $stok, $foto = '') {
        $this->id = $id;
        $this->nama = $nama;
        $this->harga = $harga;
        $this->stok = $stok;
        $this->foto = $foto;
    }

    public function toArray() {
        return [
            'id' => $this->id,
            'nama' => $this->nama,
            'harga' => $this->harga,
            'stok' => $this->stok,
            'foto' => $this->foto
        ];
    }
}