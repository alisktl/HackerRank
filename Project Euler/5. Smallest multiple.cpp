#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    if(a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    return a/gcd(a, b) * b;
}

int solve(int n) {
    if(n == 1) return 1;

    int _lcm = 1;
    for(int i = 2; i <=n; i++) {
        _lcm = lcm(_lcm, i);
    }

    return _lcm;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << solve(n) << "\n";
    }
    return 0;
}
