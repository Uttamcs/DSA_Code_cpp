// Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/description/

#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<vector<char>> board, char ch)
{
    for (int i = 0; i < 9; i++)
    {
        // row check
        if(board[row][i] == ch) return false;
        if(board[i][col] == ch) return false;

        // for 3X3 sub matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == ch) return false;
    }
    return true;
}
bool solveSudoku(vector<vector<char>>& board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if(isValid(i, j, board, ch))
                    {
                        board[i][j] = ch;
                        if(solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void printBoard(const vector<vector<char>>& board) {
    for (const auto& vec : board) {
        for (const auto& ch : vec) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (solveSudoku(board))
    {
        printBoard(board);
    }
    else
    {
        cout << "No solution exists";
    }
    return 0;
}