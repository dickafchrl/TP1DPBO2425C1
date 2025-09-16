<?php
session_start();
require_once 'Produk.php';

// init session list
if (!isset($_SESSION['daftarProduk'])) {
    $_SESSION['daftarProduk'] = [];
}

function handleFileUpload($file) {
    $uploadDir = 'uploads/';
    if (!is_dir($uploadDir)) {
        mkdir($uploadDir, 0777, true);
    }
    $uploadFile = $uploadDir . basename($file['name']);
    if (move_uploaded_file($file['tmp_name'], $uploadFile)) {
        return $uploadFile;
    }
    return '';
}

function findIndexById($id) {
    foreach ($_SESSION['daftarProduk'] as $i => $item) {
        if ($item['id'] == $id) {
            return $i;
        }
    }
    return -1;
}

function tambahProduk($id, $nama, $harga, $stok, $fotoFile) {
    if (findIndexById($id) != -1) {
        echo "<script>alert('ID sudah ada!');</script>";
        return;
    }

    $foto = '';
    if ($fotoFile && $fotoFile['error'] == 0) {
        $foto = handleFileUpload($fotoFile);
        if (empty($foto)) {
            echo "<script>alert('Gagal upload foto!');</script>";
            return;
        }
    }

    $produk = new Produk($id, $nama, $harga, $stok, $foto);
    $_SESSION['daftarProduk'][] = $produk->toArray();
    echo "<script>alert('Produk berhasil ditambahkan!');</script>";
}

function updateData($id, $nama, $harga, $stok, $fotoFile) {
    $index = findIndexById($id);
    if ($index == -1) {
        echo "<script>alert('Produk tidak ditemukan!');</script>";
        return;
    }

    if (!empty($nama))  $_SESSION['daftarProduk'][$index]['nama']  = $nama;
    if (!empty($harga)) $_SESSION['daftarProduk'][$index]['harga'] = $harga;
    if (!empty($stok))  $_SESSION['daftarProduk'][$index]['stok']  = $stok;

    if ($fotoFile && $fotoFile['error'] == 0) {
        $foto = handleFileUpload($fotoFile);
        if (!empty($foto)) {
            $_SESSION['daftarProduk'][$index]['foto'] = $foto;
        }
    }

    echo "<script>alert('Produk berhasil diupdate!');</script>";
}

function hapusData($id) {
    $index = findIndexById($id);
    if ($index == -1) {
        echo "<script>alert('Produk tidak ditemukan!');</script>";
        return;
    }

    array_splice($_SESSION['daftarProduk'], $index, 1);
    echo "<script>alert('Produk berhasil dihapus!');</script>";
}

function tampilProduk($search = '') {
    $list = $_SESSION['daftarProduk'];
    if (!empty($search)) {
        $search = strtolower($search);
        $list = array_filter($_SESSION['daftarProduk'], function($item) use ($search) {
            return strpos(strtolower($item['nama']), $search) !== false;
        });
    }

    if (empty($list)) {
        echo "<p>Tidak ada produk.</p>";
        return;
    }

    echo "<table border='1' cellpadding='8'>";
    echo "<tr><th>ID</th><th>Nama</th><th>Harga</th><th>Stok</th><th>Foto</th></tr>";
    foreach ($list as $p) {
        echo "<tr>";
        echo "<td>{$p['id']}</td>";
        echo "<td>{$p['nama']}</td>";
        echo "<td>{$p['harga']}</td>";
        echo "<td>{$p['stok']}</td>";
        echo "<td>" . (!empty($p['foto']) ? "<img src='{$p['foto']}' width='80'>" : "-") . "</td>";
        echo "</tr>";
    }
    echo "</table>";
}

// ============================
// Handle request
// ============================
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    if (isset($_POST['create'])) {
        tambahProduk($_POST['id'], $_POST['nama'], $_POST['harga'], $_POST['stok'], $_FILES['foto']);
    } elseif (isset($_POST['update'])) {
        updateData($_POST['id'], $_POST['nama'], $_POST['harga'], $_POST['stok'], $_FILES['foto']);
    } elseif (isset($_POST['delete'])) {
        hapusData($_POST['id']);
    }
}

$search = isset($_GET['search']) ? $_GET['search'] : '';
?>
<!DOCTYPE html>
<html>
<head>
    <title>CRUD Produk</title>
</head>
<body>
    <h1>Manajemen Produk</h1>

    <h2>Tambah Produk</h2>
    <form method="post" enctype="multipart/form-data">
        <input type="text" name="id" placeholder="ID"><br>
        <input type="text" name="nama" placeholder="Nama"><br>
        <input type="text" name="harga" placeholder="Harga"><br>
        <input type="text" name="stok" placeholder="Stok"><br>
        <input type="file" name="foto"><br>
        <button type="submit" name="create">Tambah</button>
    </form>

    <h2>Update Produk</h2>
    <form method="post" enctype="multipart/form-data">
        <input type="text" name="id" placeholder="ID (wajib)"><br>
        <input type="text" name="nama" placeholder="Nama baru (opsional)"><br>
        <input type="text" name="harga" placeholder="Harga baru (opsional)"><br>
        <input type="text" name="stok" placeholder="Stok baru (opsional)"><br>
        <input type="file" name="foto"><br>
        <button type="submit" name="update">Update</button>
    </form>

    <h2>Hapus Produk</h2>
    <form method="post">
        <input type="text" name="id" placeholder="ID"><br>
        <button type="submit" name="delete">Hapus</button>
    </form>

    <h2>Cari Produk</h2>
    <form method="get">
        <input type="text" name="search" placeholder="Cari nama..." value="<?= htmlspecialchars($search) ?>">
        <button type="submit">Cari</button>
    </form>

    <h2>Daftar Produk</h2>
    <?php tampilProduk($search); ?>
</body>
</html>