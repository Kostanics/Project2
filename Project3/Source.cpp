#include <iostream>
#include <chrono> 
using namespace std;
int swapcount = 0, ifcount = 0;
void Merge(int* A, int first, int last) {
    int start, middle, final, j;
    int* mas = new int[last + 1];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (j = first; j <= last; j++) {
        if ((start <= middle) && ((final > last) || (A[start] < A[final]))) {
            mas[j] = A[start];
            start++;
        }
        else {
            mas[j] = A[final];
            final++;
        }
    }
    for (j = first; j <= last; j++) {
        A[j] = mas[j];
    }
    delete[]mas;
}

void MergeSort(int* A, int first, int last) {
    if (first < last) {
        MergeSort(A, first, (first + last) / 2);
        MergeSort(A, (first + last) / 2 + 1, last);
        Merge(A, first, last);
    }
}

void sorty(const int n) {
    int* A = new int[n + 1];
    //cout << "not sort:" << endl;
    for (int i = 1; i <= n; i++)
    {
        A[i] = rand() % 10;
        //cout << A[i];
    }
    auto start = chrono::high_resolution_clock::now();
    MergeSort(A, 1, n);
    auto end = chrono::high_resolution_clock::now();
    cout << "sorting time: " << ((chrono::duration_cast<chrono::microseconds>)(end - start)).count() << " (microseconds)" << endl;
    //cout << endl << "sort:" << endl;
    for (int i = 1; i <= n; i++) {
        //cout << A[i];
    }
    delete[]A;
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "For 100 elements:" << endl;
    sorty(n = 100);
    system("pause");

    cout << "For 1000 elements:" << endl;
    sorty(n = 1000);
    system("pause");

    cout << "For 10000 elements:" << endl;
    sorty(n = 10000);
    system("pause");

    cout << "For 100000 elements:" << endl;
    sorty(n = 100000);
    system("pause");

    cout << "For 1000000 elements:" << endl;
    sorty(n = 1000000);
    system("pause");
}
