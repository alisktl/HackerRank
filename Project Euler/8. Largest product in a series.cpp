#include <iostream>

using namespace std;

int solve(int n, int k, string num) {
    int mul = 1;

    for(int i = 0; i < k; i++) {
        mul *= int(num[i]-48);
    }

    int prev_mul = mul;
    for(int i = k; i < n; i++) {
        int mul_2 = prev_mul;

        if(int(num[i-k]-48) != 0) {
            mul_2 /= int(num[i-k]-48);
            mul_2 *= int(num[i]-48);
        } else {
            mul_2 = 1;
            for(int j = i-k+1; j <= i; j++) {
                mul_2 *= int(num[j]-48);
            }
        }
        
        prev_mul = mul_2;

        if(mul < mul_2) {
            mul = mul_2;
        }
    }

    return mul;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;

        cout << solve(n, k, num) << "\n";
    }
    return 0;
}
