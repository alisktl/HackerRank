#include <iostream>
#include <unordered_map>

using namespace std;

bool is_palindrome(int n) {
    int size = log10(n)+1;

    if(size == 1) return true;

    int left = 0;
    int right = size-1;

    while(left <= right) {
        int l = (n/((int)pow(10, size-left-1)))%10;
        int r = right == size-1 ? n%10 : n/((int)pow(10, size-right-1))%10;

        if(l != r) return false;

        ++left;
        --right;
    }

    return true;
}

bool of_target_size(int n, int target_size) {
    int size = log10(n)+1;

    return target_size == size;
}

int largest_palindrome(int highest) {
    unordered_map<string, bool> cache;

    int max_palindrome = 0;

    int min_divisible_by_11 = 101;

    while(min_divisible_by_11 % 11 != 0) {
        ++min_divisible_by_11;
    }

    // at least one factor must divisible by 11
    for(int i = min_divisible_by_11; i <= 999; i+=11) {
        int k = floor(double(101*101)/i);
        for(int j = k; j <= 999; j++) {
            if(i*j < highest) {
                if(of_target_size(i*j, 6) && is_palindrome(i*j) && max_palindrome < i*j) {
                    max_palindrome = i*j;
                }
            } else {
                break;
            }
        }
    }

    return max_palindrome;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;

        cout << largest_palindrome(n) << "\n";
    }
    return 0;
}