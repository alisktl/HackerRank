#include <iostream>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7;

unordered_map<string, int> paths_map;

int lattice_paths(int x, int y) {
    if(x == 1 && y == 1) return 2;

    if(x > y) {
        int temp = x;
        x = y;
        y = temp;
    }

    if(paths_map.find(to_string(x) + '.' + to_string(y)) != paths_map.end()) {
        return paths_map[to_string(x) + '.' + to_string(y)];
    }

    if(x == 1) {
        paths_map[to_string(x) + '.' + to_string(y)] = (1 + lattice_paths(x, y-1)) % mod;
        return paths_map[to_string(x) + '.' + to_string(y)];
    }

    paths_map[to_string(x) + '.' + to_string(y)] = (lattice_paths(x-1, y) + lattice_paths(x, y-1)) % mod;
    return paths_map[to_string(x) + '.' + to_string(y)];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while(T --> 0) {
        int x, y;
        cin >> x >> y;

        cout << lattice_paths(x, y) << "\n";
    }

    return 0;
}
