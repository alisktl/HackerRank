#include <iostream>
#include <vector>

using namespace std;

const int max_n = 1e6;

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

int main(){
    set_primes();

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << primes[n-1] << "\n";
    }
    return 0;
}