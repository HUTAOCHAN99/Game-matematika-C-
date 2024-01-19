#include <iostream>
#include <fstream>
using namespace std;
// Bagian awal login
// simpan data
struct UserData
{
    string username;
    string password;
};
// cek username
bool handlinguserNameexists(const string &username);
bool handlinguserNameexists(const string &username)
{
    ifstream file("savedata.txt");

    if (file.is_open())
    {
        string checkUsername;
        while (file >> checkUsername)
        {
            if (checkUsername == username)
            {
                file.close();
                return true;
            }
        }
    }
    return false;
}
// daftar
void registrasi();
void registrasi()
{
    UserData newUser;

    // input data
    cout << "Masukkan username : ";
    cin >> newUser.username;

    // penanganan kesalahan data pengguna ganda
    if (handlinguserNameexists(newUser.username))
    {
        cout << "Username sudah terdaftar. Pilih username lain.\n";
        return;
    }

    cout << "Masukkan password : ";
    cin >> newUser.password;

    // simpan dalam file savedata.txt
    ofstream file("savedata.txt", ios::app);

    if (file.is_open())
    {
        file << newUser.username << " " << newUser.password << endl;
        file.close();
        cout << "Registrasi berhasil.\n";
    }
    else
    {
        cout << "Registrasi gagal, silakan coba beberapa saat lagi.\n";
    }
}
// login
bool login(const string &username, const string &password)
{
    ifstream file("savedata.txt");

    if (file.is_open())
    {
        // variabel yang akan diinput
        string checkUsername, checkPassword;
        while (file >> checkUsername >> checkPassword)
        {
            if (checkUsername == username && checkPassword == password)
            {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}
