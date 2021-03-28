#include <iostream>
#include <vector>

using namespace std;

vector<long long int> lengthes(5e6+100, -1);
vector<long long int> max_lengthes_num(5e6+100, -1);

int get_length(int n) {
    if(lengthes[n] != -1) return lengthes[n];

    long long int num = n;
    int count = 0;

    while(num > 0) {
        if(num < lengthes.size() && lengthes[num] != -1) {
            count += lengthes[num];
            break;
        }

        if(num%2 == 0) {
            num /= 2;
        } else {
            num = 3*num + 1;
        }

        ++count;
    }

    lengthes[n] = count;

    return count;
}

void set_lengthes() {
    lengthes[1] = 1;
    max_lengthes_num[1] = 1;

    for(int i = 2; i <= 5e6; i++) {
        int length = get_length(i);

        max_lengthes_num[i] = length >= lengthes[max_lengthes_num[i-1]] ? i : max_lengthes_num[i-1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set_lengthes();

    int T;
    cin >> T;

    while(T --> 0) {
        int N;
        cin >> N;

        cout << max_lengthes_num[N] << "\n";
    }

    return 0;
}
