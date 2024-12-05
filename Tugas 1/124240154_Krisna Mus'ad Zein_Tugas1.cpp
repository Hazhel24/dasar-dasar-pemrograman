#include <iostream>
using namespace std;
main()
{
    string nama, nim;
    int choice;
    bool check = false;
    cout << "SELAMAT DATANG\n";
    cout << "SIAPKAN NAMA & NIM UNTUK LOGIN\n";
    do
    {
        cout << "Masukkan nama : (Krisna / krisna) ";
        cin >> nama;
        cout << "Masukkan NIM : (124240154) ";
        cin >> nim;
        if ((nama == "Krisna" || nama == "krisna") && nim == "124240154")
        {
            check = true;
        }
        else
        {
            cout << "Nama & Nim anda salah\n";
        }
    } while (check != true);
    do
    {
        cout << "SELAMAT DATANG : " << nama;
        cout << "PILIH MENU : \n";
        cout << "1. Game Tebak Angka\n";
        cout << "2. Exit\n";
        cout << "Masukkan Angka : ";
        cin >> choice;
        if (choice == 1)
        {
            int angka_tebak, angka_benar = 7;
            cout << "SELAMAT DATANG PADA GAMES ANGKA TEBAK" << endl;
            do
            {
                cout << "TEBAK ANGKAT (1-10) = ";
                cin >> angka_tebak;
                if (angka_tebak > angka_benar)
                {
                    cout << "Angka anda terlalu besar" << endl;
                }
                else if (angka_tebak < angka_benar)
                {
                    cout << "Angka terlalu kecil" << endl;
                }
                else
                {
                    cout << "Anda angka benar = " << angka_benar;
                    break;
                }
            } while (angka_tebak != angka_benar);
        }
        else if (choice == 2)
        {
            system("pause");
            return 0;
        }
        else
        {
            cout << "Masukkan Angka (1/2)";
        }
    } while (choice != 2);
    return 0;
}