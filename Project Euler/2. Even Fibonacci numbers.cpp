#include <iostream>

using namespace std;

long long sum_fib(long long n) {
    long long sum = 0;
    
    if(n < 2) return sum;
    
    long long last = 2;
    long long pre_last = 1;
    
    sum = last;
    
    while(pre_last + last <= n) {
        long long temp = last;
        last = last + pre_last;
        pre_last = temp;
        
        if(last%2 == 0) sum += last;
    }
    
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;
        
        cout << sum_fib(n) << "\n";
    }
    return 0;
}
