#include <iostream>

using namespace std;

int solve(int n) {
    int mul = -1;

    for(int a = n/3; a > 0; a--) {
        int rem = n-a;

        int min_b = (n-2*a)/2;

        for(int b = rem/2; b >= min_b; b--) {
            int c = n-a-b;

            if(a+b > c && a*a + b*b == c*c) {
                int mul_2 = a*b*c;

                if(mul < mul_2) {
                    mul = mul_2;
                    if(abs(a-b) < 2 && (abs(a-c) < 2 || abs(b-c) < 2)) return mul;
                }
            }
        }
    }

    return mul;
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