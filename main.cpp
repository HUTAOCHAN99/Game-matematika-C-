#include <iostream>
#include "registrasi.h"
#include <string>
using namespace std;
// menu utama
int main()
{
    int pilih;
    cout << "SILAHKAN LOGIN" << endl;
    cout << "1. Sign up  2. Sign in" << endl;
    cout << "Pilih: ";
    cin >> pilih;
    switch (pilih)
    {
    case 1:
        // sign up
        registrasi();
        break;
    case 2:
        // sign in
        string username, password;
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;
        if (login(username, password))
        {
            cout << "Login berhasil.\n";
        }
        else
        {
            cout << "Login gagal. Username atau Password salah. Silahkan coba kembali.\n";
        }
        break;
    }
}
// kembali menu utama
void menu_utama();
void menu_utama()
{
    int pilih;
    int menu_keluar;
    bool menu;
    do
    {
        cout << "SILAHKAN LOGIN" << endl;
        cout << "1. Sign up  2. Sign in" << endl;
        cout << "Pilih: ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            // sign up
            registrasi();
            return;
        case 2:
            // sign in
            string username, password;
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;
            if (login(username, password))
            {
                cout << "Login berhasil.\n";
            }
            else
            {
                cout << "Login gagal. Username atau Password salah. Silahkan coba kembali.\n";
            }
            return;
        }
        if (menu_keluar == 1)
        {
            menu = true;
        }
        if (menu_keluar == 0)
        {
            menu = false;
        }
    } while (menu);
}

// bagian menu pilihan
// perhitungan skor
// menu keluar
// sertakan musik
// save data
// leaderboard