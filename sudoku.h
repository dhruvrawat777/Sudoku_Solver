#include<bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0
#define N 9

class Sudoku
{
    private:
        bool CheckRow(int grid[N][N],int row,int num);
        bool CheckCol(int grid[N][N],int col,int num);
        bool CheckBox(int grid[N][N],int boxStartRow,int boxStartCol,int num);
        void Printer(int grid[N][N]);
        bool IsSafe(int grid[N][N],int row,int col,int num);
        bool FindUnassignedLocation(int grid[N][N],int &row,int &col);
        bool SolveSudoku(int grid[N][N]);


    public:
        Sudoku();
        ~Sudoku()
        {

        }
};



void Sudoku:: Printer(int grid[N][N])
{
    for(int row=0;row<N;++row)
    {
        for(int col=0;col<N;++col)
        {
            cout<<grid[row][col]<<" ";
        }
        cout<<endl;
    }
}


bool Sudoku::CheckRow(int grid[N][N],int row,int num)
{
    for(int col=0;col<N;++col)
    {
        if(grid[row][col]==num)
            return true;
    }
    return false;
}

bool Sudoku::CheckCol(int grid[N][N],int col,int num)
{
    for(int row=0;row<N;++row)
    {
        if(grid[row][col]==num)
        {
            return true;
        }
    }
    return false;
}

bool Sudoku::CheckBox(int grid[N][N],int boxStartRow,int boxStartCol,int num)
{
    for(int row=0;row<3;++row)
    {
        for(int col=0;col<3;++col)
        {
            if(grid[row+boxStartRow][col+boxStartCol]==num)
            {
                return true;
    
            }
        }
    }
    return false;
}


bool Sudoku::FindUnassignedLocation(int grid[N][N],int &row,int &col)
{
    for(row=0;row<N;++row)
    {
        for(col=0;col<N;++col)
        {
            if(grid[row][col]==UNASSIGNED)
            {
                return true;
            }
        }
    }
    return false;
}

bool Sudoku::IsSafe(int grid[N][N],int row,int col,int num)
{
    return (!CheckRow(grid,row,num)&&
            !CheckCol(grid,col,num)&&
            !CheckBox(grid,row-row%3,col-col%3,num)
            );
}

bool Sudoku::SolveSudoku(int grid[N][N])
{
    int row,col;
    if(!FindUnassignedLocation(grid,row,col))
    {
        return true;
    }
    for(int num=1;num<=9;++num)
    {
        if(IsSafe(grid,row,col,num))
        {
            grid[row][col]=num;
            if(SolveSudoku(grid))
            {
                return true;
            }
            grid[row][col]=UNASSIGNED;
        }
    
    }
    return false;
}

Sudoku::Sudoku()
{
    int grid[N][N];
    cout<<"Enter grid\n";
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>grid[i][j];
        }
    }
    if(SolveSudoku(grid)==true)
    {
        cout<<"\n";
        Printer(grid);
    }
    else
    {
        cout<<"No solution";
    }
    
}