#include <iostream>
#include "registrasi.h"
#include "gamemode.h"
#include <string>
using namespace std;
// menu utama
bool registrasi();
void menu_utama();
void gui();
void displayaccount();
void clearScreen();
string username, password;
// kembali menu utama
// fitur clearscreen
void clearScreen()
{
#ifdef _WIN32 // For windows
    system("cls");
#else
    system("clear"); // for linux
#endif
}
void menu_utama()
{
    int pilih;
    bool menu = true;
    while (menu)
    {
        cout << "SILAHKAN LOGIN" << endl;
        cout << "1. Sign up\n2. Sign in\n3. Log account" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            // sign up
            if (registrasi())
            {
                cout << "Registrasi berhasil.\n";
            }
            else
            {
                cout << "Registrasi gagal. Silahkan coba beberapa saat lagi.\n";
                menu = true;
            }
            system("pause");
            clearScreen();
            break;
        case 2:
            // sign in
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;
            if (login(username, password))
            {
                cout << "Login berhasil.\n";
                menu = false;
            }
            else
            {
                cout << "Login gagal. Username atau Password salah. Silahkan coba kembali.\n";
            }
            system("pause");
            clearScreen();
            break;
        case 3:
            // account log
            displayaccount();
            system("pause");
            clearScreen();
            break;
        default:
            cout << "Pilihan tidak valid. Silahkan coba lagi.\n";
        }
    }
}
int main()
{
    menu_utama();
    gui();
}
// bagian menu pilihan
// perhitungan skor
// menu keluar
// sertakan musik
// save data
// leaderboard