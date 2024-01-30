#include <fstream>
#include <vector>
#include <iostream>
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
bool registrasi();
bool registrasi()
{
    UserData newUser;

    // input data
    cout << "Masukkan username : ";
    cin >> newUser.username;

    // error handling username sudah terdaftar
    if (handlinguserNameexists(newUser.username))
    {
        cout << "Username sudah terdaftar. Pilih username lain.\n";
        return false;
    }

    cout << "Masukkan password : ";
    cin >> newUser.password;

    // simpan dalam file savedata.txt
    ofstream file("savedata.txt", ios::app);

    if (file.is_open())
    {
        file << newUser.username << " " << newUser.password << endl;
        file.close();
        return true;
    }
    else
    {
        return false;
    }
}
// login
bool login(const string &username, const string &password);
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
// display_account
void displayaccount()
{
    ifstream file("savedata.txt");
    if (file.is_open())
    {
        vector<UserData> users;
        UserData user;

        while (file >> user.username >> user.password)
        {
            users.push_back(user);
        }
        file.close();

        if (!users.empty())
        {
            cout << "Daftar akun yang tersimpan:\n";
            int l = 0;
            for (const auto &u : users)
            {
                cout << "Username " << l << " : " << u.username << endl;
                l++;
            }
        }
        else
        {
            cout << "Tidak ada akun yang tersimpan.\n";
        }
    }
    else
    {
        cout << "Gagal membuka file data savedata.txt.\n";
    }
}