#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long int solve(vector<string> v) {
    string sum = "";
    int rem = 0;

    for(int i = v[0].size()-1; i >= 0; i--) {
        int k = 0;

        for(int j = 0; j < v.size(); j++) {
            k += (int(v[j][i]) - 48);
        }

        k += rem;
        sum = to_string(k%10) + sum;
        rem = k/10;
    }

    if(rem > 0) sum = to_string(rem) + sum;

    return stoll(sum.substr(0, 10), nullptr, 10);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    vector<string> v(T);

    int i = 0;
    while(T --> 0) {
        cin >> v[i++];
    }

    cout << solve(v) << "\n";

    return 0;
}
