#include <iostream>
#include <vector>

using namespace std;

int solve(vector< vector<int> > grid) {
    int mul = 0;

    mul = grid[0][0]*grid[0][1]*grid[0][2]*grid[0][3];

    int max_n = 99*99*99*99;

    for(int i = 0; i < 20; i++) {
        int j = 3;
        while(j < 20) {
            if(grid[i][j] != 0 && grid[i][j-1] != 0 && grid[i][j-2] != 0 && grid[i][j-3] != 0) {
                int mul_2 = grid[i][j]*grid[i][j-1]*grid[i][j-2]*grid[i][j-3];
                if(mul < mul_2) {
                    mul = mul_2;

                    if(mul == max_n) return mul;
                }

                ++j;
            } else {
                if(grid[i][j] == 0) j+=4;
                else if(grid[i][j-1] == 0) j+=3;
                else if(grid[i][j-2] == 0) j+=2;
                else if(grid[i][j-3] == 0) j+=1;
            }
        }
    }

    for(int i = 0; i < 20; i++) {
        int j = 3;
        while(j < 20) {
            if(grid[j][i] != 0 && grid[j-1][i] != 0 && grid[j-2][i] != 0 && grid[j-3][i] != 0) {
                int mul_2 = grid[j][i]*grid[j-1][i]*grid[j-2][i]*grid[j-3][i];
                if(mul < mul_2) {
                    mul = mul_2;

                    if(mul == max_n) return mul;
                }

                ++j;
            } else {
                if(grid[j][i] == 0) j+=4;
                else if(grid[j-1][i] == 0) j+=3;
                else if(grid[j-2][i] == 0) j+=2;
                else if(grid[j-3][i] == 0) j+=1;
            }
        }
    }
    
    for(int i = 0; i < 17; i++) {
        for(int j = 0; j < 17; j++) {
            if(grid[i][j] != 0 && grid[i+1][j+1] != 0 && grid[i+2][j+2] != 0 && grid[i+3][j+3] != 0) {
                int mul_2 = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
                if(mul < mul_2) {
                    mul = mul_2;

                    if(mul == max_n) return mul;
                }
            }
        }
    }

    for(int i = 3; i < 20; i++) {
        for(int j = 0; j < 17; j++) {
            if(grid[i][j] != 0 && grid[i-1][j+1] != 0 && grid[i-2][j+2] != 0 && grid[i-3][j+3] != 0) {
                int mul_2 = grid[i][j]*grid[i-1][j+1]*grid[i-2][j+2]*grid[i-3][j+3];
                if(mul < mul_2) {
                    mul = mul_2;

                    if(mul == max_n) return mul;
                }
            }
        }
    }

    return mul;
}

int main(){
    vector< vector<int> > grid(20,vector<int>(20));
    for(int grid_i = 0;grid_i < 20;grid_i++){
        for(int grid_j = 0;grid_j < 20;grid_j++){
            cin >> grid[grid_i][grid_j];
        }
    }

    cout << solve(grid) << "\n";

    return 0;
}