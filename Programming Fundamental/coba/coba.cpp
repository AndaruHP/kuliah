#include<iostream>
#include<limits>
#include<fstream>

using namespace std;

int pricemotor = 2000;
int pricemobil = 4000;
int pricesepeda = 1000;

struct Id {
    string plat;
    int pk;
};

int getDataSize(fstream &data){
	int start, end;
	data.seekg(0,ios::beg);
	start = data.tellg();
	data.seekg(0,ios::end);
	end = data.tellg();
	return (end-start)/sizeof(Id);
}

Id readData(fstream &data, int posisi){
    Id readPlat;
    data.seekg((posisi - 1)*sizeof(Id), ios::beg);
    data.read(reinterpret_cast<char*>(&readPlat), sizeof(Id));
    return readPlat;
}

void displayData(fstream &data){
    int size = getDataSize(data);
    Id showData;
    cout << "no.\tpk.\tPlat Nomor" << endl;
    for(int i = 1; i <= size; i++){
        showData = readData(data, i);
        cout << i << "\t";
        cout << showData.pk << "\t";
        cout << showData.plat << endl;
    }
}

void writedata(fstream &data, int posisi, Id &platmotor){
    data.seekp((posisi - 1)*sizeof(Id), ios::beg);
    data.write(reinterpret_cast<char*>(&platmotor), sizeof(Id));
}

void checkDataBase(fstream &data){
    data.open("data.bin", ios::in | ios::out | ios::binary);
    if (data.is_open()){
		cout << "database ditemukan" << endl;
	} else {
		cout << "database tidak ditemukan, buat database baru" << endl;
		data.close();
		data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
	}
}

int getoption1(){
    int input;
    system("cls");
    cout << "Selamat Datang di ParkIn" << endl;
    cout << "1. Check In" << endl;
    cout << "2. Check Out" << endl;
    cout << "3. Lihat Data" << endl;
    cout << "4. Close Program" << endl;
    cout << "Pilih [1 - 4]: ";
    cin >> input;
    return input;
}

int getoption2(){
    int input;
    system("cls");
    cout << "Pilih Jenis Kendaraan Anda" << endl;
    cout << "1. Motor" << endl;
    cout << "2. Mobil" << endl;
    cout << "3. Sepeda" << endl;
    cout << "Pilih [1 - 3]: ";
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return input;
}


void input_motor(fstream &data){
    Id platmotor, lastplat;
    int size = getDataSize(data);
    cout << "Sisa Slot = " << size << endl;
    if((size) == 1){
        platmotor.pk = 1;
    } else {
        lastplat = readData(data, size);
        cout << "pk = " << lastplat.pk << endl;
        platmotor.pk = lastplat.pk - 1;
    }
    
    cout << "Masukkan Plat motor : ";
    getline(cin, platmotor.plat);
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    writedata(data, size + 1, platmotor);
}

void checkout(fstream &data){
    int nomor,size,offset;
	Id blankPlat, tempPlat;
	fstream dataSementara;

	size = getDataSize(data);
	// 1. pilih nomor
	cout << "Hapus nomor: ";
	cin >> nomor;
	// 2. di posisi ini diisi dengan data kosong
	writedata(data,nomor,blankPlat);
	// 3. kita cek data yang ada dari file data.bin, kalau ada data
	//    kita pindahkan ke file sementara
	dataSementara.open("temp.dat", ios::trunc|ios::out|ios::in|ios::binary);

	offset = 0;

	for (int i=1 ; i <=size ; i++){
		tempPlat = readData(data,i);

		if (!tempPlat.plat.empty()){
			writedata(dataSementara,i - offset,tempPlat);
		} else {
			offset++;
			cout << "deleted item" << endl;
		}
	}
	// 4. kita pindahkan data dari file sementara ke data.bin
	size = getDataSize(dataSementara);
	data.close();
	data.open( "data.bin",ios::trunc|ios::out|ios::binary);
	data.close();
	data.open( "data.bin",ios::out|ios::in|ios::binary);

	for(int i = 1; i <= size; i++){
		tempPlat = readData(dataSementara,i);
		writedata(data,i,tempPlat);
	}
}

int main(){
    fstream data;
    checkDataBase(data);
    int pilihan = getoption1();

    switch(pilihan){
        case 1:
            cout << "Check In Kendaraan" << endl;
            pilihan = getoption2();

            switch(pilihan){
                case 1:
                    cout << "Pilihan Anda Motor" << endl;
                    input_motor(data);
                    break;
                case 2:
                    cout << "Pilihan Anda Mobil" << endl;

                    break;
                case 3:
                    cout << "Pilihan Anda Sepeda" << endl;
                    break;
            }
            break;
        case 2:
            cout << "Check Out Kendaraan" << endl;
            checkout(data);
            break;
        case 3:
            cout << "Lihat Data" << endl;
            displayData(data);
        case 4:
            cout << "Close Program" << endl;
            goto label_continue;
            break;
    }
    cout << "Lanjutkan?(y/n) : ";
    label_continue:
    cout << "Program Selesai" << endl;


}