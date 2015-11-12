#include<stdio.h>
#define N 1000

int tabuleiro[N][N];
int colunas[N];
int rainhas[N][2];
int n;
int numSol = 0;

void setTabuleiro(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            tabuleiro[i][j] = 1;
        }
    }
}

void printTab(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(tabuleiro[i][j] == 1)
            {
                printf("0 ");
            }
            else if(tabuleiro[i][j] == 0)
            {
                printf("x ");
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

    if(tabuleiro[line][col])
    {
        for(int i=0; i<n; i++)
        {
            tabuleiro[i][col] = 0;
            tabuleiro[line][i] = 0;
        }
        for(int i=0; i<n; i++)
        {
            if(line+i<n)
            {
                if(col+i<n)
                {
                    tabuleiro[line+i][col+i] = 0;
                }
                if(col-i>=0)
                {
                    tabuleiro[line+i][col-i] = 0;
                }
            }
            if(line-i>=0)
            {
                if(col+i<n)
                {
                    tabuleiro[line-i][col+i] = 0;
                }
                if(col-i>=0)
                {
                    tabuleiro[line-i][col-i] = 0;
                }
            }
        }
        return true;
    }
    return false;
}

bool findSol(int line, int col)
{
    if(line==n)
    {
        return true;
    }
    else if(col==n)
    {
        return false;
    }
    if(putQueen(line, col))
    {
        tabuleiro[line][col] = 2;
        findSol(line+1, 0);
    }
    else
    {
        findSol(line, col+1);
    }
}

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
        setTabuleiro(n);
    }
    findSolLin(line, col+1, counter);
}

int main(void)
{
    while(true)
    {
        printf("Digite o n (tabuleiro nxn): ");
        scanf("%d", &n);
        setTabuleiro(n);
        printTab(n);
        printf("%d", findSolLin(0, 0, 0));
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
        setTabuleiro(n);
    }
    return 0;
}
