#include <iostream>
using namespace std;

// int a, n, i;
long long a, n, i;

int main(int argc, char const *argv[])
{
    a = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        a += i;
        cout << a << " ";
    }
    cout << endl;
}

/** Alasan kenapa outputnya tidak sesuai ketika menggunakan tipe data
 * integer adalah karena limit dari integer sendiri adalah 32 bit atau angka ke 2147483647
 * ketika melebihi limit dari integer maka angka akan kembali menjadi ke -2147483647.
 * Sedangkan jika menggunakan tipe data long long, akan berjalan aman
 * selama angka masih kurang dari atau sama dengan 9223372036854775807,
 * yang mana merupakan limit dari tipe data long long. Hal ini dikarenakan oleh
 * limit dari tipe data long long adalah 64 bit atau angka ke 9223372036854775807,
 * jika melebihi angka tersebut maka akan kembali lagi ke angka -9223372036854775807.
 *
 * Beda halnya dengan tipe data long, tipe data ini bergantung pada platform yang digunakan.
 * Jika menggunakan platform 64 bit maka limit dari long adalah 64 bit, sedangkan jika
 * menggunakan platform selain 64 bit maka limit dari long adalah 32 bit.
 * */
