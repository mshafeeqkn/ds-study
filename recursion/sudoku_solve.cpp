#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void print_sudoku(vector<vector<char>> &sudoku) {
    int count1 = 0;
    int count2 = 0;
    vector<vector<char>>::iterator itr1;
    vector<char>::iterator itr2;

    for(itr1 = sudoku.begin(); itr1 != sudoku.end(); itr1++) {
        if(count1 % 3 == 0)
            cout << "+-------+-------+-------+" << endl;
        for(itr2 = (*itr1).begin(); itr2 != (*itr1).end(); itr2++) {
            if(count2 % 3 == 0)
                cout << "| ";
            cout << *itr2 << " ";
            count2++;
        }
        cout << "|" << endl;
        count1++;
    }
    cout << "+-------+-------+-------+" << endl;
}

bool is_possible(char c, int row, int col, vector<vector<char>> &sudoku) {
    for(int i = 0; i < 9; i++) {
        if(sudoku[row][i] == c)
            return false;

        if(sudoku[i][col] == c)
            return false;

        if(sudoku[3 * (row/3) + (i/3)][3 * (col/3) + (i % 3)] == c)
            return false;
    }
    return true;
}

bool solve_sudoku(vector<vector<char>> &sudoku) {
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            if(sudoku[row][col] != '.')
                continue;

            for(char c = '1'; c <= '9'; c++) {
                if(is_possible(c, row, col, sudoku)) {
                    sudoku[row][col] = c;
                    if(solve_sudoku(sudoku) == false) {
                        sudoku[row][col] = '.';
                    } else {
                        return true;
                    }
                }
            }
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    vector<vector<char>> sudoku;

    sudoku.push_back(vector<char> {'5', '3', '.', '.', '7', '.', '.', '.', '.'});
    sudoku.push_back(vector<char> {'6', '.', '.', '1', '9', '5', '.', '.', '.'});
    sudoku.push_back(vector<char> {'.', '9', '8', '.', '.', '.', '.', '6', '.'});
    sudoku.push_back(vector<char> {'8', '.', '.', '.', '6', '.', '.', '.', '3'});
    sudoku.push_back(vector<char> {'4', '.', '.', '8', '.', '3', '.', '.', '1'});
    sudoku.push_back(vector<char> {'7', '.', '.', '.', '2', '.', '.', '.', '6'});
    sudoku.push_back(vector<char> {'.', '6', '.', '.', '.', '.', '2', '8', '.'});
    sudoku.push_back(vector<char> {'.', '.', '.', '4', '1', '9', '.', '.', '5'});
    sudoku.push_back(vector<char> {'.', '.', '.', '.', '8', '.', '.', '7', '9'});

    print_sudoku(sudoku);
    solve_sudoku(sudoku);
    print_sudoku(sudoku);
    return 0;
}


#if 0
                    solve(s, 0 , 2) -> |5|3| | |7| | | | |      -> (1), 2, 4
                
                    solve(s, 0 , 3) -> |5|3|1| |7| | | | |      -> (2), 6
                
                                                                                        solve(s, 0 , 5) -> |5|3|1|2|7| | | | |      -> (4), 6, 8
                
                     solve(s, 0 , 6) -> |5|3|1|2|7|4| | | |      -> (8), 9
                
// solve(s, 0 , 7) -> |5|3|1|2|7|4|8| | | -> (9)    solve(s, 0 , 7) -> |5|3|1|2|7|4|9| | |      -> (8)

// solve(s, 0 , 8) -> |5|3|1|2|7|4|8|9| | -> x
 
#endif
