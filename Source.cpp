#include <stdio.h>
void init(void);
void printsudoku(void);
int samecolumn(int, int, int);
int samesquare(int, int, int);
int samerow(int, int, int);
int solve( int row, int col);
void clear(void);
void play(void);
int puzzle0[9][9] ;
int clear0[9][9];
int play0[9][9];
int main()
{
    int x = 0,y=0;
    printf("\t\t\tWELCOME TO SUDOKU GAME\n\nPLEASE ENTER THE PUZZLE:\n(enter 0 for empty places)\n " );
   
    init();
    //play();
   // printf("finsh");
   

    solve( x, y);
    printsudoku();
    clear();
    printsudoku();
    return 0;
}
void init()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            scanf_s("%d", &puzzle0[i][j]);
            clear0[i][j] = puzzle0[i][j];
            play0[i][j] = puzzle0[i][j];
        }
   
  /* for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if (puzzle0[i][j] != 0)
            {
                if (!samesquare(i, j, puzzle0[i][j]) || !samecolumn(i, j, puzzle0[i][j]) || !samerow(i, j, puzzle0[i][j]))
                {
                    printf("wrong sudoku!!\nenter the sudoku again\n");
                    puzzle0[9][9] = { 0 };
                    init();
                }
            }

        }*/
    
}
void printsudoku()
{
    {
        printf("\n+-----+-----+-----+\n");
        for (int i = 1; i < 10; ++i)
        {
            for (int j = 1; j < 10; ++j) 
            printf("|%d", puzzle0[i - 1][j - 1]);
            printf("|\n");
            if (i % 3 == 0) printf("+-----+-----+-----+\n");
        }
    }
   
}
int samerow(int x, int y, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (puzzle0[x][i] == num)
            return 0;
    }
    return 1;
}
int samecolumn(int x, int y, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (puzzle0[i][y] == num)
            return 0;
    }
    return 1;
}
int samesquare(int x, int y, int num)
{
    if (x < 3)
    {
        x = 0;
    }
    else if (x < 6)
    {
        x = 3;
    }
    else
    {
        x = 6;
    }

    if (y < 3)
    {
        y = 0;
    }
    else if (y < 6)
    {
        y = 3;
    }
    else
    {
        y = 6;
    }
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (puzzle0[i][j] == num)
            {
                return 0;
            }
        }
    }
    return 1;
}
int solve( int row, int col)
{
    int i;
    if (row < 9 && col < 9)
    {
        if (puzzle0[row][col] != 0)
        {
            if ((col + 1) < 9) return solve( row, col + 1);
            else if ((row + 1) < 9) return solve( row + 1, 0);
            else return 1;
        }
        else
        {
            for (i = 1; i <= 9; ++i)
            {
                if (samesquare(row, col, i) && samecolumn(row, col, i) && samerow(row, col, i))

                {
                    puzzle0[row][col] = i;
                    if ((col + 1) < 9)
                    {
                        if (solve( row, col + 1))
                            return 1;
                        else puzzle0[row][col] = 0;
                    }
                    else if ((row + 1) < 9)
                    {
                        if (solve( row + 1, 0))
                            return 1;
                        else puzzle0[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}
void clear()
{
    for ( int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            puzzle0[i][j] = clear0[i][j];
            play0[i][j] = clear0[i][j];
        }

}
void play()
{
    int r0 = 0,  c0= 0,p=0;
    solve(r0,c0 );
    do
    {
        int x, y;
        printf("enter the row:\n");
        scanf_s("%d", &x);
        printf("enter the coulumn:\n");
        scanf_s("%d", &y);
        printf("enter the number:\n");
        scanf_s("%d", &play0[x][y]);
        if (puzzle0[x][y]==play0[x][y])
        {
            {
                printf("\n+-----+-----+-----+\n");
                for (int i = 1; i < 10; ++i)
                {
                    for (int j = 1; j < 10; ++j)
                        printf("|%d", play0[i - 1][j - 1]);
                    printf("|\n");
                    if (i % 3 == 0) printf("+-----+-----+-----+\n");
                }printf("right\n");
            }

        }
        else
        {
            {
                printf("\n+-----+-----+-----+\n");
                for (int i = 1; i < 10; ++i)
                {
                    for (int j = 1; j < 10; ++j)
                        printf("|%d", play0[i - 1][j - 1]);
                    printf("|\n");
                    if (i % 3 == 0) printf("+-----+-----+-----+\n");
                }printf("wrong\n");
            }
        }
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if (play0[i][j] == puzzle0[i][j])
                {
                    p++;
                }

            }
    } while (p!=81);
    

}


//printf("\033[1;3"); color