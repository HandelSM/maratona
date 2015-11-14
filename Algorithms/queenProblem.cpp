#include<stdio.h>
#define N 1000

int tabuleiro[N][N];
int colunas[N];
int rainhas[N][2];
int n;
int numSol = 0;

void setTabuleiro(int n, int l)
{
    for(int i=l; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
}

void printTab(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(tabuleiro[i][j] == 0)
            {
                printf("0 ");
            }
            else if(tabuleiro[i][j] > 0)
            {
                printf("%d ", tabuleiro[i][j]);
            }
            else
            {
                printf("R ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool putQueen(int line, int col)
{

    if(tabuleiro[line][col] == 0)
    {
        for(int i=0; i<n; i++)
        {
            tabuleiro[i][col]++;
            tabuleiro[line][i]++;
        }
        for(int i=0; i<n; i++)
        {
            if(line+i<n)
            {
                if(col+i<n)
                {
                    tabuleiro[line+i][col+i]++;
                }
                if(col-i>=0)
                {
                    tabuleiro[line+i][col-i]++;
                }
            }
            if(line-i>=0)
            {
                if(col+i<n)
                {
                    tabuleiro[line-i][col+i]++;
                }
                if(col-i>=0)
                {
                    tabuleiro[line-i][col-i]++;
                }
            }
        }
        return true;
    }
    return false;
}

void removeQueen(int line, int col)
{
	for(int i=0; i<n; i++)
	{
		tabuleiro[i][col]--;
		tabuleiro[line][i]--;
	}
	for(int i=0; i<n; i++)
	{
		if(line+i<n)
		{
			if(col+i<n)
			{
				tabuleiro[line+i][col+i]--;
			}
			if(col-i>=0)
			{
				tabuleiro[line+i][col-i]--;
			}
		}
		if(line-i>=0)
		{
			if(col+i<n)
			{
				tabuleiro[line-i][col+i]--;
			}
			if(col-i>=0)
			{
				tabuleiro[line-i][col-i]--;
			}
		}
	}
	tabuleiro[line][col]=0;
}

int findSol(int line, int col, int lastCol)
{
    if(line==n)
    {
        return col;
    }
    else if(col==n)
    {
        return -line-lastCol*1000;
    }
    if(putQueen(line, col))
    {
        tabuleiro[line][col] = -1;
        findSol(line+1, 0, col);
    }
    else
    {
        findSol(line, col+1, lastCol);
    }
}

int solve(int line, int col)
{
	int result = findSol(line, col, col-1);
	if(result < 0)
	{
		result = -result;
		int lineR = result%1000-1;
		int colR = (result-lineR)/1000;
		removeQueen(lineR, colR);
		tabuleiro[lineR][colR] = 1;
		solve(lineR, colR+1);
	}
	else
	{
		printTab(n);
		removeQueen(n-1, result);
		tabuleiro[n-1][result] = 1;
		solve(result, col+1);
	}
}
/*
int findSolLin(int line, int col, int counter)
{
    if(col>n)
    {
        return counter;
    }
    if(findSol(line, col))
    {
        printTab(n);
        counter = counter + 1;
    }
    else
    {
        setTabuleiro(n, 0);
    }
    findSolLin(line, col+1, counter);
}
*/
int main(void)
{
    while(true)
    {
        printf("Digite o n (tabuleiro nxn): ");
        scanf("%d", &n);
        setTabuleiro(n, 0);
        printTab(n);
        //printf("%d", findSolLin(0, 0, 0));
        solve(0,0);
		printf("\n");
       /* int col, line;
        printf("Digite linha e coluna: ");
        scanf("%d %d", &line, &col);
        if(findSol(line, col))
        {
            printf("FOI!\n");
        }
        else
        {
            printf("NAO FOI!\n");
        }
        printTab(n);*/
        setTabuleiro(n, 0);
    }
    return 0;
}
