#include <iostream>
using namespace std;
void sorty(const int n) {
    int *random = new int[n]{};
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        random[i] = rand() % 10;
    }
    cout << "massive: " << endl;
    for (int i = 0; i < n; i++) {
        cout << random[i];
    }
    cout << endl;
    int x = 0;
    for (int j = n/2; j > 0; j/=2) {
        for (int k = j; k < n; k++) {
            x = random[k];
            int l;
            for (l = k; l >= j && random[l - j] > x; l-=j)
            random[l] = random[l-j];
            random[l] = x;
        }
    }
    cout << "sort massive: " << endl;
    for (int i = 0; i < n; i++) {
        cout << random[i];
    }
    delete [] random;
}

int main()
{
    cout << "For 100 elements:" << endl;
    int n;
    cin >> n;
    sorty(n);
    cout << endl;
    cout << "For 1000 elements:" << endl;
    cin >> n;
    sorty(n);
    cout << endl;
    cout << "For 10000 elements:" << endl;
    cin >> n;
    sorty(n);
    cout << endl;
    cout << "For 100000 elements:" << endl;
    cin >> n;
    sorty(n);
    cout << endl;
    cout << "For 1000000 elements:" << endl;
    cin >> n;
    sorty(n);
}