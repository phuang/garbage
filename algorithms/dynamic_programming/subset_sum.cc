#include <iostream>
using namespace std;
const unsigned int MAX_SUM = 1024000;
unsigned long long int dyn[MAX_SUM];
int n = 0;

int main() {
    cin >> n;
    int s = n*(n+1);
    if (s % 4) {
        cout << 0 << endl;
        return 0;
    }

    s /= 4;
    int i, j;
    dyn [0] = 1;
    for (i = 1; i <= n; i++)
        for (j = s; j >= i; j--) 
            dyn[j] += dyn[j-i];
    cout << (dyn[s]/2) << endl;
    return 0;
}
