#include <iostream>
using namespace std;

int main()
{
    int jumlah_data_nilai_pelajaran = 100;
    int jumlah_data_nama_pelajaran = 100;
    int total, pilih;
    int rata_rata = 0;
    int nilai_pelajaran[jumlah_data_nilai_pelajaran];
    string nama_pelajaran[jumlah_data_nama_pelajaran];

    do
    {
        cout << "Selamat datang!" << endl;
        cout << "Silahkan pilih menu: " << endl;
        cout << "1. Input Data Pelajaran" << endl;
        cout << "2. Output Data Pelajaran" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1)
        {
            cout << "Silahkan masukkan jumlah data nilai pelajaran: ";
            cin >> jumlah_data_nilai_pelajaran;

            for (int i = 0; i < jumlah_data_nilai_pelajaran; i++)
            {
                cout << "Nilai ke " << i + 1 << endl;
                cout << "Nama Pelajaran: ";
                cin >> nama_pelajaran[i];

                cout << "Nilai pelajaran: ";
                cin >> nilai_pelajaran[i];
                cout << endl;
            }
            system("pause");
            system("cls");
        }
        else if (pilih == 2)
        {
            cout << "Data Pelajaran" << endl;
            for (int i = 0; i < jumlah_data_nilai_pelajaran; i++)
            {
                cout << "Data ke-" << i + 1 << endl;
                cout << "Nama Pelajaran: " << nama_pelajaran[i] << endl;
                cout << "Nilai Pelajaran: " << nilai_pelajaran[i] << endl;
                cout << endl;

                rata_rata = rata_rata + nilai_pelajaran[i];
            }
            total = rata_rata / jumlah_data_nilai_pelajaran;
            cout << "Rata rata nilai: ";
            cout << total;
            cout << endl;
            system("pause");
            system("cls");
        }
        else if (pilih == 3)
        {
            cout << "Selamat tinggal!";
            exit(0);
        }
        else
        {
            cout << "Menu tidak ada!" << endl;
            system("pause");
            system("cls");
        }
    } while (pilih > !3);
}