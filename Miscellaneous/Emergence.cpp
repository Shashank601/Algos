try optimization
and 
remove hard coded inputs 
use rand()

#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

void engine(vector<string>& grid, vector<string>& nextGen, vector<pair<int,int>>& neigh) {
    int n = grid.size();
    int m = grid[0].size();
	


  
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            bool state = (grid[i][j] == 'o') ? 1 : 0;
            
            int faith = 0;
            for (auto& [dx, dy] : neigh) {
                faith += (grid[i + dx][j + dy] == 'o') ? 1 : 0;
            }
            
            if (state) {
                if (faith == 2 || faith == 3) nextGen[i][j] = 'o';
                else nextGen[i][j] = '.';
				
      			} else {
                if (faith == 3) nextGen[i][j] = 'o';
                else nextGen[i][j] = '.';
            }
        }
    }
}

void render(vector<string>& grid) {
    for (auto& str : grid) {
        for (auto& c : str) {
            cout << c;
        }
        cout << '\n';
    }
	cout << '\n';
}


int main() {
    int rows = 20;  
    int cols = 100; 
    vector<string> grid(rows, string(cols, '.')), nextGen(rows, string(cols, '.'));
    vector<pair<int,int>> neigh = {{-1,-1}, {-1,0}, {-1,1},
                                    {0,-1},          {0,1}, 
                                    {1,-1},  {1,0},  {1,1}};
    vector<pair<int,int>> coords;
    int pattern;
    cin >> pattern;
    
    if (pattern == 1) {
        coords = {{1,2},{2,3},{3,1},{3,2},{3,3}};
    } else if (pattern == 2) {
        coords = {{5,5},{5,6},{5,7}};
    } else if (pattern == 3) {
        coords = {{10,10},{10,11},{10,12},{11,9},{11,10},{11,11}};
    //} else if (pattern == 4) {
       // coords = {{20,20},{20,21},{21,20},{21,21},{22,22},{22,23},{23,22},{23,23}};
    } else {
        cout << "INVALID VALUE\n";
        return 0;  
    }
    
    for (auto &[r,c] : coords) grid[r][c] = 'o';
	
    
    int gen = 0;
    while (gen < 1000) {
        
        cout << "Generation: " << gen << '\n';
        render(grid);
        this_thread::sleep_for(chrono::milliseconds(160)); // speed controller
        cout << flush;  // Force 
        engine(grid, nextGen, neigh);
		
        grid.swap(nextGen);

		    cout << "\033[2J\033[3J\033[1;1H";  
        cout << flush;  
        gen++;
    }
    
    return 0;
}
