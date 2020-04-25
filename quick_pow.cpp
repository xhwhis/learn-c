#include <iostream>
using namespace std;

typedef long long ll;

ll quick_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    ll a, b;
    while(cin >> a >> b) {
        cout << quick_pow(a, b) << endl;
    }
    return 0;
}
