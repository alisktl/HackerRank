#include <iostream>

using namespace std;
/*
long long sum_of(int n, int k) {
    long long sum = 0;
    
    if(n < k) return sum;

    long long rem = n%k;
    long long last = n-rem;

    sum = last*(last/k+1)/2;

    return sum;
}
*/

long long sum_of(int n, int k) {
    long long sum = 0;
    
    if(n < k) return sum;

    long long rem = n%k;
    long long last = n-rem;
    long long div = last/k;
    long long add = 0;

    while((k+last)%2 != 0 && k < last) {
        add += last;
        last -= k;
        --div;
    }

    sum = (k + last)/2 * div + add;

    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
    
        long long sum = 0;    
        sum += sum_of(n-1, 3);
        sum += sum_of(n-1, 5);
        sum -= sum_of(n-1, 15);
        
        cout << sum << "\n";
    }
    
    return 0;
}