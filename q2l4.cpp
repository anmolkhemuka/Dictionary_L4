/**
 * @file q2l4.cpp
 * @author Anmol Khemuka
 * @brief 
 * @version 0.1
 * @date 2019-09-04
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
/**
 * @brief Function to print the possible solituin
 * 
 * @param board passing the chess board of size n*n 
 */
void printSol(int **board, int N)
{
    static int k = 1;
    printf("Combination %d:\n", k++);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief to check if a queen can be placed on board[row][col]
 * @param board chess board of size n*n 
 * @param row 
 * @param col 
 * @return true 
 * @return false 
 */
bool isSafe(int **board, int row, int col, int N)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

/**
 * @brief A recursive utility function to solve N Queen problem 
 * @param board chess board of size n*n 
 * @param col 
 * @return true 
 * @return false 
 */
bool solveNQUtil(int **board, int col, int N)
{

    if (col == N)
    {
        printSol(board, N);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {

        if (isSafe(board, i, col, N))
        {
            board[i][col] = 1;

            res = solveNQUtil(board, col + 1, N) || res;

            board[i][col] = 0;
        }
    }

    return res;
}

/**
 * @brief  This function solves the N Queen problem using 
Backtracking. It mainly uses solveNQUtil() to 
solve the problem.
 * 
 */
void solve(int N)
{
    int **board = new int *[N];
    for (int i = 0; i < N; i++)
        board[i] = new int[N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQUtil(board, 0, N) == false)
    {
        printf("Solution does not exist");
        return;
    }

    return;
}

int main()
{
    clock_t t;
    t = clock();
    int N;
    cout << "\nEnter the board Dimension\n";
    cin >> N;
    solve(N);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("\ntotal execution time:%f seconds", time_taken);
    return 0;
}
