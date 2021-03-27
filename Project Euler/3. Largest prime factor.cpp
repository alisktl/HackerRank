#include <iostream>

using namespace std;

long long max_prime_factor(long long n) {
    long long max_prime = 1;

    while(n%2 == 0) {
        max_prime = 2;
        n >>= 1;
    }

    for(long long i = 3; i <= sqrt(n); i+=2) {
        while(n%i == 0) {
            if(max_prime < i) max_prime = i;
            n /= i;
        }
    }

    if(max_prime < n) max_prime = n;

    return max_prime;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;

        cout << max_prime_factor(n) << "\n";
    }
    return 0;
}