#include <iostream>
#include <json/value.h>
#include <json/json.h>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <iomanip>
using namespace std;

struct flight
{
    string name;
    string code;
    string from;
    string to;
    string departureTime;
    string arrivalTime;
    string level;
    int price;
    bool seat[20][4];
};

unsigned int microsecond = 1000000;
bool isAsc = true;

vector<flight> getData()
{
    int input;
    ifstream file("airport.json");
    Json::Value actualJson;
    Json::Reader reader;

    reader.parse(file, actualJson);

    int totalFlight = actualJson["maskapai"].size();

    vector<flight> flights;
    for (int i = 0; i < totalFlight; i++)
    {
        flight plane;
        plane.name = actualJson["maskapai"][i]["nama"].asString();
        plane.code = actualJson["maskapai"][i]["kode"].asString();
        plane.from = actualJson["maskapai"][i]["asal"].asString();
        plane.to = actualJson["maskapai"][i]["tujuan"].asString();
        plane.departureTime = actualJson["maskapai"][i]["waktuKeberangkatan"].asString();
        plane.arrivalTime = actualJson["maskapai"][i]["waktuKedatangan"].asString();
        plane.level = actualJson["maskapai"][i]["kelas"].asString();
        plane.price = actualJson["maskapai"][i]["harga"].asInt64();
        for (int j = 0; j < 20; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                plane.seat[j][k] = actualJson["maskapai"][i]["kursi"][j][k].asBool();
            }
        }
        flights.push_back(plane);
    }
    return flights;
}

void askExit()
{
    string isYes;
    cout << "Ingin bertransaksi lagi? [Y/n]";
    cin.ignore();
    getline(cin, isYes);

    if (isYes == "Y" || isYes == "y")
    {
        system("clear");
    }
    else
    {
        exit(0);
        cout << "Terima kasih telah menggunakan layanan kami" << endl;
        usleep(2 * microsecond);
        exit(0);
    }
}

void noFlightHandler()
{
    cout << "Penerbangan tidak ditemukan" << endl;
}

void choice(vector<flight> flights)
{
    int choice;
    cout << "--------------------------------" << endl;
    cout << "1. Pilih penerbangan" << endl;
    cout << "2. Urutkan penerbangan" << endl;

falseSecondChoice:
    cout << "Masukkan angka pilihan: " << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        noFlightHandler();
        break;
    case 2:
        isAsc = false;
        break;
    default:
        goto falseSecondChoice;
    }
}

void sortList(vector<flight> flights)
{
    int choice;
    cout << "--------------------------------" << endl;
    cout << "1. Urutkan berdasarkan harga termurah" << endl;
    cout << "2. Urutkan berdasarkan harga termahal" << endl;

falseSortList:
    cout << "Masukkan angka pilihan: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        isAsc = true;
        break;
    case 2:
        isAsc = false;
        break;
    default:
        goto falseSortList;
    }
}

void sortByPrice(vector<flight> &flights, bool isAsc)
{
    int i, j;
    flight temp;
    for (i = 1; i < flights.size(); i++)
    {
        temp = flights[i];
        j = i - 1;
        while (j >= 0 && ((isAsc) ? (flights[j].price > temp.price) : (flights[j].price < temp.price)))
        {
            flights[j + 1] = flights[j];
            j--;
        }
        flights[j + 1] = temp;
    }
}

void printFlights(vector<flight> flights)
{
    for (int i = 0; i < flights.size(); i++)
    {
        cout << "----------------------------------" << endl;
        cout << "Nama: " << flights[i].name << endl;
        cout << "Kode: " << flights[i].code << endl;
        cout << "Asal: " << flights[i].from << endl;
        cout << "Tujuan: " << flights[i].to << endl;
        cout << "Waktu Keberangkatan: " << flights[i].departureTime << endl;
        cout << "Waktu Kedatangan: " << flights[i].arrivalTime << endl;
        cout << "Kelas: " << flights[i].level << endl;
        cout << "Harga: " << flights[i].price << endl;
    }
}

void printReceipt(flight flight, string seatCoordinate)
{
    usleep(0.5 * microsecond);
    cout << "------------ STRUK PEMBELIAN ---------------" << endl;
    cout << "Nama: " << flight.name << endl;
    cout << "Kode: " << flight.code << endl;
    cout << "Asal: " << flight.from << endl;
    cout << "Tujuan: " << flight.to << endl;
    cout << "Waktu Keberangkatan: " << flight.departureTime << endl;
    cout << "Harga: " << flight.price << endl;
    cout << "Kursi: " << seatCoordinate << endl;
    cout << "-0------------------------------------------" << endl;
}

void chooseSeat(flight &flight)
{
    char row;
    int column;
    cout << "----------------------------------" << endl;
    cout << "Nama pesawat: " << flight.name << endl;
    cout << "Asal pesawat: " << flight.from << endl;
    cout << "Waktu Keberangkatan: " << flight.departureTime << endl;
    cout << "Waktu Kedatangan: " << flight.arrivalTime << endl;
    cout << "Tujuan pesawat: " << flight.to << endl;
    cout << "Harga pesawat: " << flight.price << endl;
    cout << "Kelas pesawat: " << flight.level << endl;
    cout << "Pilih Kursi:\n"
         << "(X = Terpakai; O = Kosong)" << endl
         << " ";
    for (int i = 1; i <= 20; i++)
    {
        cout << setw(4) << i;
    }
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << char(i + 65);
        for (int j = 0; j < 20; j++)
        {
            cout << setw(4) << ((flight.seat[j][i]) ? "X" : "O");
        }
        cout << endl;
        if (i == 1)
            cout << endl;
    }
    cout << "Masukkan kolom kursi (Angka): ";
    cin >> column;
    cout << "Masukkan baris kursi (Huruf): ";
    cin >> row;
    if (column > 20 || column < 1 || row > 68 || row < 65)
    {
        cout << "Kursi tidak ditemukan" << endl;
        return;
    }

    if (flight.seat[column - 1][row - 65])
    {
        cout << "Kursi sudah terpakai" << endl;
        return;
    }
    else
    {
        flight.seat[column - 1][row - 65] = true;

        cout << "Kursi berhasil dipesan" << endl;
        printReceipt(flight, to_string(column) + string(1, row));
        usleep(3 * microsecond);
        askExit();
        return;
    }
}

void searchByCode(vector<flight> &flights)
{
    flight selectedPlane;
    string code;
    int index;
    cout << "Masukkan kode penerbangan: ";
    cin >> code;

    for (int i = 0; i < flights.size(); i++)
    {
        if (flights[i].code == code)
        {
            selectedPlane = flights[i];
            index = i;
            break;
        }
    }

    if (selectedPlane.code == code)
    {
        chooseSeat(selectedPlane);
        flights[index] = selectedPlane;
    }
    else
    {
        noFlightHandler();
    }
}

void searchByName(vector<flight> &flightsPtr)
{
    vector<flight> planes;
    string sortByCheapest;
    string name;
    cout << "Masukkan nama maskapai: ";
    cin >> name;
    cout << "Urutkan maskapai berdasarkan harga termurah? [Y/n] ";
    cin.ignore();
    getline(cin, sortByCheapest);

    for (int i = 0; i < flightsPtr.size(); i++)
    {
        if (name == flightsPtr[i].name)
        {
            planes.push_back(flightsPtr[i]);
        }
    }
    sortByPrice(planes, (sortByCheapest == "Y" || sortByCheapest == "y" || sortByCheapest == ""));
    (planes.size() != 0) ? printFlights(planes) : noFlightHandler();
    if (planes.size() != 0)
        searchByCode(planes);
}

void searchByOrigin(vector<flight> &flightsPtr)
{
    vector<flight> planes;
    string sortByCheapest;
    string from;
    cout << "Masukkan asal maskapai: ";
    cin >> from;
    cout << "Urutkan maskapai berdasarkan harga termurah? [Y/n] ";
    cin.ignore();
    getline(cin, sortByCheapest);
    for (int i = 0; i < flightsPtr.size(); i++)
    {
        if (from == flightsPtr[i].from)
        {
            planes.push_back(flightsPtr[i]);
        }
    }
    sortByPrice(planes, (sortByCheapest == "Y" || sortByCheapest == "y" || sortByCheapest == ""));
    (planes.size() != 0) ? printFlights(planes) : noFlightHandler();
    if (planes.size() != 0)
        searchByCode(planes);
}

void searchByClass(vector<flight> &flightsPtr)
{
    vector<flight> planes;
    string sortByCheapest;
    string level;
    cout << "Masukkan kelas maskapai: ";
    cin >> level;
    cout << "Urutkan maskapai berdasarkan harga termurah? [Y/n] ";
    cin.ignore();
    getline(cin, sortByCheapest);
    for (int i = 0; i < flightsPtr.size(); i++)
    {
        if (level == flightsPtr[i].level)
        {
            planes.push_back(flightsPtr[i]);
        }
    }
    sortByPrice(planes, (sortByCheapest == "Y" || sortByCheapest == "y" || sortByCheapest == ""));
    (planes.size() != 0) ? printFlights(planes) : noFlightHandler();
    if (planes.size() != 0)
        searchByCode(planes);
}

void searchByPriceRange(vector<flight> &flightsPtr)
{
    vector<flight> planes;
    string sortByCheapest;
    int minPrice, maxPrice;
    cout << "Masukkan harga minimum: ";
    cin >> minPrice;
    cout << "Masukkan harga maksimum: ";
    cin >> maxPrice;
    cout << "Urutkan maskapai berdasarkan harga termurah? [Y/n] ";
    cin.ignore();
    getline(cin, sortByCheapest);
    for (int i = 0; i < flightsPtr.size(); i++)
    {
        if (flightsPtr[i].price >= minPrice && flightsPtr[i].price <= maxPrice)
        {
            planes.push_back(flightsPtr[i]);
        }
    }
    sortByPrice(planes, (sortByCheapest == "Y" || sortByCheapest == "y" || sortByCheapest == ""));
    (planes.size() != 0) ? printFlights(planes) : noFlightHandler();
    if (planes.size() != 0)
        searchByCode(planes);
}

int main(int argc, char const *argv[])
{

    int input;

    vector<flight> flight = getData();

    while (true)
    {
        cout
            << "-------------------- Selamat datang di teaketdotkom --------------------" << endl;
        cout << "Ingin cari penerbangan berdasarkan apa?\n";
        cout << "1. Nama pesawat" << endl;
        cout << "2. Asal pesawat" << endl;
        cout << "3. Kelas pesawat" << endl;
        cout << "4. Harga tiket pesawat" << endl;
        cout << "0. Keluar dari program" << endl;
    mainQuestion:
        cout << "Masukkan angka pilihan: ";
        cin >> input;

        switch (input)
        {
        case 1:
            searchByName(flight);
            break;
        case 2:
            searchByOrigin(flight);
            break;
        case 3:
            searchByClass(flight);
            break;
        case 4:
            searchByPriceRange(flight);
            break;
        case 0:
            cout << "Terima kasih telah menggunakan layanan kami:)" << endl;
            exit(0);
            break;
        default:
            cout << "Input tidak valid" << endl;
            goto mainQuestion;
            break;
        }
    }
}