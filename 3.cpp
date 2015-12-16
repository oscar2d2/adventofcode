#include <iostream>

using namespace std;

const int SIZE = 20001;

int main() {
    int** grid = new int*[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        grid[i] = new int[SIZE];
    }
    int sx = 10000;
    int sy = 10000;

    int rsx = 10000;
    int rsy = 10000;

    bool rTurn = false;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = 0;
        }
    }

    grid[sx][sy] = 1;
    grid[rsx][rsy] += 1;

    char dir;

    while (cin >> dir) {
        if (!rTurn) {
        if (dir == '<') {
           --sx;  
        } else if (dir == '^') {
           ++sy;
        } else if (dir == '>') {
           ++sx;
        } else if (dir == 'v') {
          --sy; 
        }

        grid[sx][sy] += 1;
        } else {
        if (dir == '<') {
           --rsx;  
        } else if (dir == '^') {
           ++rsy;
        } else if (dir == '>') {
           ++rsx;
        } else if (dir == 'v') {
          --rsy; 
        }

        grid[rsx][rsy] += 1;
 
        }
        rTurn = !rTurn;
    } 

    int count = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(grid[i][j] >= 1) { ++count; }
        }
    }

    cout << count << endl;

   return 0; 
}
