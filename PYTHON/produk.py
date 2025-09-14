class Produk:

    # Constructor inisialisasi atribut
    def __init__(self,id : str, nama : str, harga : str, stok : str):
        self.__id = str(id)
        self.__nama = str(nama)
        self.__harga = str(harga)
        self.__stok = str(stok)

    # Membuat getter dan setter untuk setiap atribut
    def getId(self) -> str: 
        return self.__id
    
    def setId(self, id : str) -> None: 
        self.__id = str(id)

    def getNama(self) -> str: 
        return self.__nama
    
    def setNama(self, nama : str) -> None: 
        self.__nama = str(nama)

    def getHarga(self) -> str: 
        return self.__harga
    
    def setHarga(self, harga : str) -> None: 
        self.__harga = str(harga)

    def getStok(self) -> str: 
        return self.__stok
    
    def setStok(self, stok : str) -> None: 
        self.__stok = str(stok)