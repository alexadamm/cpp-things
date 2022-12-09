        #include <iostream>
        #include <stdlib.h>
        #define NMAX 18
        #define RANGE 20

        using namespace std;

        int tree1[NMAX];
        int n1;

        void push_down(int T[], int n, int p) // T: pohon, n: jumlah elemen aktual, p: node
        {
            while (2 * p + 1 < n) // selama node-p punya anak
            {
                // cari anak dengan nilai yang lebih besar, misalnya diperoleh node-r
                int r = 2 * p + 1; // r diisi dengan anak kiri

                if (2 * p + 2 < n)                   // jika anak kanan ada
                    if (T[2 * p + 2] > T[2 * p + 1]) // jika nilai anak kanan > nilai anak kiri
                        r = 2 * p + 2;

                // Tukar isi node-p dan node-r jika isi node-r lebih besar
                if (T[r] > T[p])
                {
                    int temp = T[p];
                    T[p] = T[r];
                    T[r] = temp;
                }
                else
                {
                    break;
                }

                // jadikan r sebagai p sekarang (current-p)
                p = r;
            }
        }

        void convert_to_heap(int T[], int n)
        {
            for (int i = (n - 2) / 2; i >= 0; i--) // mulai dari induk terakhir ke induk yang pertama
                push_down(T, n, i);                // push_down masing-masing induk tersebut
        }

        void sort_heap(int H[], int n)
        {
            // ulangi sebanyak n kali
            for (int i = 0; i < n; i++)
            {
                // tampilkan root
                cout << H[0] << " ";
                // timpa root dengan elemen terakhir
                H[0] = H[n - i];
                // push_down root yang baru
                push_down(H, n, 0);
            }
        }

        int main()
        {
            cout << "Heapsort" << endl;

            for (int i = 0; i < NMAX; i++)
                tree1[i] = rand() % RANGE;

            for (int i = 0; i < NMAX; i++)
                cout << tree1[i] << " ";

            cout << endl;

            convert_to_heap(tree1, 18);

            for (int i = 0; i < NMAX; i++)
                cout << tree1[i] << " ";

            cout << endl;

            sort_heap(tree1, 18);

            cout << endl;

            return 0;
        }