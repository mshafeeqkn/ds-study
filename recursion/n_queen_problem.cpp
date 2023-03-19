#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

void print_list(vector<string> &ds) {
    vector<string>::iterator itr;

    cout << "[";
    for(itr = ds.begin(); itr != ds.end(); itr++) {
        cout << *itr << ", ";
    }
    cout << "]" << endl;
}

bool is_insert_safe(int row, int col, vector<string> &board, int n) {
    if(board[row].find('Q') != string::npos) {
        return false;
    }

    int trow = row - 1;
    int tcol = col - 1;
    while(trow >= 0 && tcol >= 0) {
        if(board[trow][tcol] == 'Q')
            return false;
        trow--;
        tcol--;
    }

    trow = row + 1;
    tcol = col - 1;
    while(trow < n && tcol >= 0) {
        if(board[trow][tcol] == 'Q')
            return false;
        trow++;
        tcol--;
    }

    return true;
}

void solve_n_queen_problem(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    if(col == n) {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(is_insert_safe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve_n_queen_problem(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

int main(int argc, char *argv[]) {
    int board_size = 4;
    vector<string> board;
    vector<vector<string>> ans;
    vector<vector<string>>::iterator itr;

    for(int i = 0; i < board_size; i++) {
        board.push_back(string(board_size, '.'));
    }

    solve_n_queen_problem(0, board, ans, board_size);

    cout << "[" << endl;
    for(itr = ans.begin(); itr != ans.end(); itr++) {
        print_list(*itr);
    }
    cout << "]" << endl;
    return 0;
}
