#include<stdio.h>


void printMatrix(int arr[m][m])
{
for (int i =0; i< m; i++)
{
for(int j = 0; j < m; j++)
{
printf("%d\t",arr[i][j]);
}
}}


bool isSafe(int arr[N][N],int x , int y)
{
if(x >= 0 && x < N && y >=0 && y <N  && arr[x][y] == 1)
return true;

return false;

}


void solveMazeUtil(int maze[n][n],int x,int y,int solve[n][n])
{
if(x == n-1 && y = n-1)
{
solve[x][y] =1;
return true;
}

if(isSafe(maze,x,y)==true)
{
solve[x][y] =1;
 /* Move forward in x direction */
if (solveMazeUtil(maze, x+1, y, sol) == true)
    return true;

/* If moving in x direction doesn't give solution then
           Move down in y direction  */
if (solveMazeUtil(maze, x, y+1, sol) == true)
   return true;

// if none of the give right solution then mark it as 0 and backtrack
sol[x][y] = 0;
 return false;
 
}
return false;
}

void solveMaze(int arr[N][N])
{
int sol[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    if(solveMazeUtil(maze, 0, 0, sol) == false)
    {
        printf("Solution doesn't exist");
        return false;
    }
 
    printMatrix(sol);
    return true;
}

// driver program to test above function
int main()
{
    int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
 
    solveMaze(maze);
    getchar();
    return 0;
}

