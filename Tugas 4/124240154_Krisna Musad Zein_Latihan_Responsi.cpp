#include <iostream>
#include <iomanip>
using namespace std;
struct penulis
{
    string nama;
};
struct buku
{
    int id_buku;
    string judul_buku;
    penulis penulis;
    int harga;
};
buku bk[100];
void menu();
void tambah_buku(int &jumlah, buku bk[100]);
void tampilkan_buku(int jumlah, buku bk[100]);
void ubah_data_buku(int jumlah, buku bk[100]);
void hapus_buku(int &jumlah, buku bk[100]);
void hitung_total_diskon(int jumlah, buku bk[100]);
int jumlah = 0;
main()
{
    menu();
}
void menu()
{
    int choice;
    do
    {
        cout << "Selamat Datang" << '\n';
        cout << "Menu :" << '\n';
        cout << "1. Tambah Buku" << '\n';
        cout << "2. Tampilkan Daftar Buku" << '\n';
        cout << "3. Ubah Data Buku" << '\n';
        cout << "4. Hapus Buku" << '\n';
        cout << "5. Hitung Total Harga Pembelian dengan Diskon" << '\n';
        cout << "6. Keluar" << '\n';
        cout << "Pilih Opsi --> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            tambah_buku(jumlah, bk);
            break;
        case 2:
            tampilkan_buku(jumlah, bk);
            break;
        case 3:
            ubah_data_buku(jumlah, bk);
            break;
        case 4:
            hapus_buku(jumlah, bk);
            break;
        case 5:
            hitung_total_diskon(jumlah, bk);
            break;
        default:
            cout << "Masukkan Opsi (1-6)" << '\n';
        }
    } while (choice != 6);
}
void tambah_buku(int &jumlah, buku bk[100])
{
    int tambah;
    cout << "Masukkan jumlah buku yang ingin diinput : ";
    cin >> tambah;
    cout << setw(22) << setfill('=') << '\n';
    for (int a = jumlah; a < jumlah + tambah; a++)
    {
        cout << "Masukkan ID Buku               : ";
        cin >> bk[a].id_buku;
        cin.ignore();
        cout << "Judul Buku                     : ";
        getline(cin, bk[a].judul_buku);
        cout << "Nama Pengarang                 : ";
        getline(cin, bk[a].penulis.nama);
        cout << "Harga                          : ";
        cin >> bk[a].harga;
        cout << setw(22) << setfill('=') << '\n';
    }
    jumlah += tambah;
}
void tampilkan_buku(int jumlah, buku bk[100])
{
    if (jumlah >= 1)
    {
        cout << "Daftar Buku :" << '\n';
        for (int a = 0; a < jumlah; a++)
        {
            cout << "Buku ke-" << a + 1 << '\n';
            cout << "ID Buku            : " << bk[a].id_buku << '\n';
            cout << "Judul              : " << bk[a].judul_buku << '\n';
            cout << "Pengarang          : " << bk[a].penulis.nama << '\n';
            cout << "Harga              : " << bk[a].harga << '\n';
        }
    }
    else
    {
        cout << "Tidak ada data buku" << '\n';
    }
    system("pause");
}
void ubah_data_buku(int jumlah, buku bk[100])
{
    int ID;
    cout << "Masukkan ID buku yang ingin diubah : ";
    cin >> ID;
    for (int a = 0; a < jumlah; a++)
    {
        if (bk[a].id_buku == ID)
        {
            cout << "Data buku ditemukan !" << '\n';
            cout << "Masukkan data baru " << '\n';
            cin.ignore();
            cout << "Judul baru             : ";
            getline(cin, bk[a].judul_buku);
            cout << "Nama pengarang baru    : ";
            getline(cin, bk[a].penulis.nama);
            cout << "Harga baru             : ";
            cin >> bk[a].harga;
            cout << "Data berhasil diperbarui" << '\n';
        }
        else
        {
            cout << "Kode buku tidak ditemukan" << '\n';
        }
    }
    system("pause");
}
void hapus_buku(int &jumlah, buku bk[100])
{
    int ID;
    cout << "Masukkan ID buku yang ingin dihapus :";
    cin >> ID;
    for (int a = 0; a < jumlah; a++)
    {
        if (bk[a].id_buku == ID)
        {
            for (int b = a; b < jumlah - 1; b++)
            {
                bk[b] = bk[b + 1];
            }
            jumlah--;
            cout << "Buku berhasil dihapus" << '\n';
        }
    }
    system("pause");
}
void hitung_total_diskon(int jumlah, buku bk[100])
{
    int beli, ID;
    int total_harga = 0;
    string kode;
    bool diskon_penulis_sama = false;
    bool buku_ditemukan = false;
    int jumlah_buku_dengan_penulis_sama = 0;
    cout << "Masukkan jumlah buku yang ingin dibeli: ";
    cin >> beli;
    for (int a = 0; a < beli; a++)
    {
        cout << "Masukkan ID buku yang ingin dibeli: ";
        cin >> ID;

        for (int i = 0; i < jumlah; i++)
        {
            if (bk[i].id_buku == ID)
            {
                buku_ditemukan = true;
                total_harga += bk[i].harga;
                for (int j = 0; j < jumlah; j++)
                {
                    if (i != j && bk[i].penulis.nama == bk[j].penulis.nama)
                    {
                        jumlah_buku_dengan_penulis_sama++;
                    }
                }
                if (jumlah_buku_dengan_penulis_sama > 1)
                {
                    diskon_penulis_sama = true;
                }
                break;
            }
        }
        if (!buku_ditemukan)
        {
            cout << "Buku dengan ID " << ID << " tidak ditemukan.\n";
        }
    }
    if (buku_ditemukan)
    {
        if (diskon_penulis_sama) // jika ada pengarang yang sama
        {
            cout << "Masukkan kode voucher (kosongkan jika tidak ada)   : ";
            cin.ignore();
            getline(cin, kode);
            if (kode == "JPYUM")
            {
                double after_diskon = total_harga * 0.75;
                cout << "Diskon 10 persen dari voucher 'JPYUM' diterapkan." << '\n';
                cout << "Total harga setelah diskon     : " << after_diskon << '\n';
                system("pause");
            }
            else
            {
                double after_diskon = total_harga * 0.95;
                cout << "Total harga                    : " << after_diskon << '\n';
                system("pause");
            }
        }
        else // jika tidak ada pengarang yang sama
        {
            double after_diskon = 0;
            cout << "Masukkan kode voucher (kosongkan jika tidak ada)   : ";
            cin.ignore();
            getline(cin, kode);
            if (kode == "JPYUM")
            {
                double after_diskon = total_harga * 0.90;
                cout << "Diskon 10 persen dari voucher 'JPYUM' diterapkan." << '\n';
                cout << "Total harga setelah diskon     : " << after_diskon << '\n';
                system("pause");
            }
            else
            {
                cout << "Total harga                    : " << total_harga << '\n';
                system("pause");
            }
        }
    }
    else
    {
        cout << "Tidak ada informasi data atas buku -Silakan cek ulang daftar buku" << '\n';
    }
}
