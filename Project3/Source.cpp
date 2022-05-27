#include <iostream>
#include <chrono> 
using namespace std;
int swapcount = 0, ifcount = 0;
void sorty(const int n) {
    int* random = new int[n] {};
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        random[i] = rand() % 10;
    }
    //cout << "massive: " << endl;
    for (int i = 0; i < n; i++) {
        //cout << random[i];
    }
    cout << endl;
    auto start = chrono::high_resolution_clock::now();
    int x = 0;
    for (int j = n / 2; j > 0; j /= 2) {
        for (int k = j; k < n; k++) {
            ifcount++;
            x = random[k];
            int l;
            for (l = k; l >= j && random[l - j] > x; l -= j) {
                random[l] = random[l - j];
                swapcount++;
            }
            random[l] = x;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "sorting time: " << ((chrono::duration_cast<chrono::microseconds>)(end - start)).count() << " (microseconds)"<<endl;
    cout << "number of permutations: " << ifcount << endl << "number of comparisons: " << swapcount<< endl;

    //cout << "sort massive: " << endl;
    for (int i = 0; i < n; i++) {
        //cout << random[i];
    }
    delete[] random;
}

int main()
{
    cout << "For 100 elements:" << endl;
    sorty(100);
    cout << endl;
    cout << "For 1000 elements:" << endl;
    sorty(1000);
    cout << endl;
    cout << "For 10000 elements:" << endl;
    sorty(10000);
    cout << endl;
    cout << "For 100000 elements:" << endl;
    sorty(100000);
    cout << endl;
    cout << "For 1000000 elements:" << endl;
    sorty(1000000);
}
