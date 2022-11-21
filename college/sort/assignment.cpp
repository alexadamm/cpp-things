#include <iostream>
using namespace std;

/* Fungsi selection sort dengan parameter array,
selection sort dengan parameter array, ukuran array,
dan parameter untuk menentukan urutan ascending atau descending */
int *selection(int arr[], int size, int isAsc)
{
    // Variabel penampung untuk swap;
    int temp;

    // Iterasi dari 0 hingga size - 1
    for (int i = 0; i < size - 1; i++)
    {
        // Deklarasi sekaligus inisialisi variabel edge dengan menyimpan index paling kiri
        int edge = i;
        for (int j = i + 1; j < size; j++)
        {
            // Jika isAsc bernilai true, maka akan melakukan sorting dari kecil ke besar
            // Jika isAsc bernilai false, maka akan melakukan sorting dari besar ke kecil
            if ((isAsc) ? arr[j] < arr[edge] : arr[j] > arr[edge])
            {
                /* Jika kondisi diatas terpenuhi, maka nilai edge akan
                diubah menjadi index dengan nilai yang lebih besar/kecil (sesuai isAsc) */
                edge = j;
            }
        }
        // Menukar nilai arr[i] dengan arr[edge]
        temp = arr[i];
        arr[i] = arr[edge];
        arr[edge] = temp;
    }
    // Mengembalikan nilai array yang telah diurutkan
    return arr;
}

/** Fungsi insertion sort dengan parameter array,
selection sort dengan parameter array, ukuran array,
dan parameter untuk menentukan urutan ascending atau descending **/
int *insertion(int arr[], int size, int isAsc)
{
    // Variabel penampung untuk swap;
    int temp;

    // Iterasi sebanyak ukuran array
    for (int i = 1; i < size; i++)
    {
        // Menyimpan nilai arr[i] ke variabel temp
        temp = arr[i];

        // Deklarasi sekaligus inisialisasi variabel j dengan nilai i - 1;
        int j = i - 1;

        /* Membuat kondisi dengan syarat selama j lebih besar dari 0 dan
            data pada j lebih besar dari data pada temp (ascending) atau
            data pada j lebih kecil dari data pada temp (descending)
        */
        while (j >= 0 && ((isAsc) ? (arr[j] > temp) : (arr[j] < temp)))
        {
            // Menukar nilai arr[j + 1] dengan arr[j] dan mengurangi j jika kondisi terpenuhi
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    // Mengembalikan nilai array yang telah diurutkan
    return arr;
}

/** Fungsi bubble sort dengan parameter array,
selection sort dengan parameter array, ukuran array,
dan parameter untuk menentukan urutan ascending atau descending **/
int *bubble(int arr[], int size, int isAsc)
{
    // Variabel penampung untuk swap;
    int temp;

    // Iterasi sebanyak ukuran array
    for (int i = 0; i < size; i++)
    {
        // Iterasi hingga selisih ukuran array dengan i dikurangi 1
        for (int j = 0; j < size - i - 1; j++)
        {
            /* Iterasi selama j lebih besar dari 0 dan
                data pada j lebih besar dari data pada temp (ascending) atau
                data pada j lebih kecil dari data pada temp (descending)
            */
            if ((isAsc) ? arr[j] > arr[j + 1] : arr[j] < arr[j + 1])
            {
                // Menukar nilai arr[j] dengan arr[j + 1] ketika kondisi terpenuhi
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Mengembalikan nilai array yang telah diurutkan
    return arr;
}

// Fungsi untuk melakukan print setiap value dari array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // Deklarasi variabel
    int size;
    bool isAsc = true;

    // Meminta input dari user untuk ukuran array
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Sort ascending or descending? (1/0): ";
    cin >> isAsc;

    // Mengacak nilai array
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }

    // Memanggil dan menampilkan fungsi insertion sort
    int *inSort = insertion(arr, size, isAsc);
    cout << "Insertion sort: ";
    printArray(inSort, size);

    // Memanggil dan menampilkan fungsi selection sort
    int *seSort = selection(arr, size, isAsc);
    cout << "Selection sort: ";
    printArray(seSort, size);

    // Memanggil dan menampilkan fungsi bubble sort
    int *buSort = bubble(arr, size, isAsc);
    cout << "Bubble sort: ";
    printArray(buSort, size);
}
