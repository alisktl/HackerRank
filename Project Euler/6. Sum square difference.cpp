#include <iostream>

using namespace std;

long long sum_of_squares(int n) {
    long long sum = 1;

    for(int i = 2; i <= n; i++) {
        sum += pow(i, 2);
    }

    return sum;
}

long long square_of_sum(int n) {
    long long sum = n*(n+1)/2;

    return pow(sum, 2);
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << (square_of_sum(n) - sum_of_squares(n)) << "\n";
    }
    return 0;
}