#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
// variabel fungsi
int a(int bawah, int atas);
int b(int bawah, int atas);
void tambah();
// variabel angka
int atas, bawah;
// pilihan mau bagian apa gamenya
void tambah()
{
    int hasil1, hasil2;
    int skor = 0;
    int jmlh_soal;

    cout << "Masukkan jumlah soal : ";
    cin >> jmlh_soal;
    cout << "Masukkan batas atas : ";
    cin >> atas;
    cout << "Masukkan batas bawah : ";
    cin >> bawah;
    // cetak soal
    for (int n = 0; n < jmlh_soal; n++)
    {
        int angka1 = a(bawah, atas);
        int angka2 = b(bawah, atas);
        hasil1 = angka1 + angka2;

        cout << angka1 << " + " << angka2 << " = .... " << endl;
        cout << "Jawaban : ";
        cin >> hasil2;
        if (hasil1 == hasil2)
        {
            cout << "jawaban anda benar" << endl;
            skor++;
        }
        else
        {
            cout << "goblok" << endl;
            cout << "jawaban " << angka1 << " + " << angka2 << " = " << hasil1 << endl;
        }
    }
    cout << "Selamat skor anda " << skor << endl;
}
void kurang()
{
    int hasil1, hasil2;
    int skor = 0;
    int jmlh_soal;

    cout << "Masukkan jumlah soal : ";
    cin >> jmlh_soal;
    cout << "Masukkan batas atas : ";
    cin >> atas;
    cout << "Masukkan batas bawah : ";
    cin >> bawah;
    // cetak soal
    for (int n = 0; n < jmlh_soal; n++)
    {
        int angka1 = a(bawah, atas);
        int angka2 = b(bawah, atas);

        hasil1 = angka1 - angka2;

        cout << angka1 << " - " << angka2 << " = .... " << endl;
        cout << "Jawaban : ";
        cin >> hasil2;
        if (hasil1 == hasil2)
        {
            cout << "jawaban anda benar" << endl;
            skor++;
        }
        else
        {
            cout << "goblok" << endl;
            cout << "jawaban " << angka1 << " - " << angka2 << " = " << hasil1 << endl;
        }
    }
    cout << "Selamat skor anda " << skor << endl;
}
// fungsi angka
int a(int bawah, int atas)
{
    int interval = atas - bawah + 1;
    int random = rand() % interval + bawah;
    return random;
}

int b(int bawah, int atas)
{
    int interval = atas - bawah + 1;
    int random = rand() % interval + bawah;
    return random;
}
// fungsi gui
void gui()
{
    // gui
    int pilih_gui;
    cout << "1. Pertambahan  2. Pengurangan.\n";
    cout << "Pilih game yang anda mainkan: ";
    cin >> pilih_gui;
    switch (pilih_gui)
    {
    case 1:
        tambah();
        break;
    case 2:
        kurang();
        break;
    default:
        break;
    }
}