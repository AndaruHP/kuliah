#include<iostream>
#include<limits>
#include <fstream>

using namespace std;

void checkDataBase(fstream &data){
    data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
}

int getoption(){
    int input;
    system("cls");
    cout << "Selamat Datang di ParkIn" << endl;
    cout << "1. Check In" << endl;
    cout << "2. Check Out" << endl;
    cout << "3. Close Program" << endl;
    cout << "Pilih [1 - 3]: ";
    cin >> input;
    return input;
}

int get0ption(){
    int input;
    system("cls");
    cout << "Pilih Jenis Kendaraan Anda" << endl;
    cout << "1. Motor" << endl;
    cout << "2. Mobil" << endl;
    cout << "3. Sepeda" << endl;
    cout << "Pilih [1 - 3]: ";
    cin >> input;
    return input;
}

int main(){
    fstream data;

    checkDataBase(data);
    label_continue:
    int pilihan = getoption();
    char is_continue;

    switch(pilihan){
        case 1:
            cout << "Check in kendaraan" << endl;
            label_checkin:
            int i = get0ption();
            switch(i){
                case 1:
                   cout << "Kendaraan Anda Motor" << endl;
                   break;
                case 2:
                    cout << "Kendaraan Anda Mobil" << endl;
                    break;
                case 3:
                    cout << "Kendaraan Anda Sepeda" << endl;
                    break;
                default:
                    cout << "Pilihan tidak ditemukan" << endl;
                    goto label_checkin;
            }
        case 2:
            cout << "Check out kendaraan" << endl;
            break;
        case 3:
            cout << "Selamat Tinggal!" << endl;
            goto label_close;
            
        default:
            cout << "Pilihan tidak ditemukan" << endl;
            goto label_continue;
    }
    cout << "Lanjutkan? <y/n> : ";
		cin >> is_continue;
		if (is_continue == 'y'){
            goto label_continue;
        }
    label_close:
    cout << "Program Selesai" << endl;


    
}