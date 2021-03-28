#include <iostream>
#include <vector>
#include <set>

using namespace std;
/*
int factors(int n) {
    if(n == 1) return 1;

    int count = 1;

    for(int i = 2; i <= sqrt(n); i++) {
        int _count = 0;
        while(n%i == 0) {
            ++_count;
            n /= i;
        }

        count *= (_count + 1);
    }

    if(n > 1) count *= (1 + 1);

    return count;
}
*/

int factors(int n) {
    if(n == 1) return 1;

    int count = 1;
    int i = 2;

    while(i * i <= n) {
        int _count = 0;
        while(n%i == 0) {
            ++_count;
            n /= i;
        }

        count *= (_count + 1);
        ++i;
    }

    if(n > 1) count *= (1 + 1);

    return count;
}
/*
int solve(int n) {
    int a = 0, count = 0;

    if(n > 800){
        a = 41000;
    } else if(n > 600){
        a = 14300;
    } else if(n > 400){
        a = 5900;
    } else if(n > 200){
        a = 2000;
    }

    while(count <= n) {
        ++a;
        count = factors(a * (a+1) / 2);
    }

    return a * (a+1) / 2;
}
*/

int solve(int n) {
    int a = 0, count = 0;
    int m = 1;

    while(count <= n) {
        a += m;
        ++m;
        count = factors(a);
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while(T --> 0) {
        int N;
        cin >> N;

        cout << solve(N) << "\n";
    }

    return 0;
}