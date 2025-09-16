class Produk:

    # Constructor inisialisasi atribut
    def __init__(self,id : str, nama : str, harga : str, stok : str):
        self.__id = str(id) # id barang elektronik
        self.__nama = str(nama) # id nama barang elektronik
        self.__harga = str(harga) # id harga barang elektronik
        self.__stok = str(stok) # id stok barang elektronik

    # Membuat getter dan setter untuk setiap atribut
    # Getter dari atribut id
    def getId(self) -> str: 
        return self.__id
    # Setter dari atribut id
    def setId(self, id : str) -> None: 
        self.__id = str(id)
    # Getter dari atribut nama
    def getNama(self) -> str: 
        return self.__nama
    # Setter dari atribut nama
    def setNama(self, nama : str) -> None: 
        self.__nama = str(nama)
    # Getter dari atribut harga
    def getHarga(self) -> str: 
        return self.__harga
    # Setter dari atribut harga
    def setHarga(self, harga : str) -> None: 
        self.__harga = str(harga)
    # Getter dari atribut stok
    def getStok(self) -> str: 
        return self.__stok
    # Setter dari atribut stok
    def setStok(self, stok : str) -> None: 
        self.__stok = str(stok)