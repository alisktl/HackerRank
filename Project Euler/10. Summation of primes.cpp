#include <iostream>
#include <vector>

using namespace std;

const int max_n = 1.6e7;

vector<int> arr(max_n+1, 0);
vector<int> primes;

void set_primes() {
    for(int i = 2; i <= max_n; i++) {
        if(arr[i] == 0) {
            primes.push_back(i);
        }

        for(auto p : primes) {
            if(p > i || p*i > max_n) break;

            arr[p*i] = p;
        }
    }
}

long long solve(int n) {
    long long sum = 0;

    for(auto p : primes) {
        if(p > n) break;
        sum += p;
    }

    return sum;
}

int main(){
    set_primes();

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << solve(n) << "\n";
    }
    return 0;
}