#include <iostream>
#include <vector>

using namespace std;

vector<int> digit_sums(10001, -1);

vector<short> pow2(vector<short> n) {
    vector<short> res;

    int rem = 0;
    for(int i = n.size()-1; i>=0 ; i--) {
        int a = 2*n[i] + rem;
        res.push_back(a%10);
        rem = a/10;
    }

    if(rem > 0) {
        res.push_back(rem);
    }

    reverse(res.begin(), res.end());

    return res;
}

int digit_sum(vector<short> n) {
    int sum = 0;

    for(int i = 0; i < n.size(); i++) {
        sum += n[i];
    }

    return sum;
}

void solve_all_power_digit_sums() {
    vector<short> digits;

    digits.push_back(2);
    digit_sums[1] = 2;

    for(int i = 2; i <= 10000; i++) {
        digits = pow2(digits);
        digit_sums[i] = digit_sum(digits);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve_all_power_digit_sums();

    int T;
    cin >> T;

    while(T --> 0) {
        int n;
        cin >> n;
        cout << digit_sums[n] << "\n";
    }

    return 0;
}