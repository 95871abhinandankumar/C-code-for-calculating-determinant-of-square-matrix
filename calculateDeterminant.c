#include <stdio.h>
#include<math.h>
int N;
int determinantOfMatrix(int mat[N][N], int n)
{
    int num1, num2, det = 1, index,
                    total = 1; 
    int temp[n + 1];
    for (int i = 0; i < n; i++)
    {
        index = i;

        while (mat[index][i] == 0 && index < n)
        {
            index++;
        }
        if (index == n)
        {
            continue;
        }
        if (index != i)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = mat[index][j];
                mat[index][j] = mat[i][j];
                mat[i][j] = temp;
            }
            det = det * pow(-1, 2*(index - i) -1);
        }

        for (int j = 0; j < n; j++)
        {
            temp[j] = mat[i][j];
        }
        for (int j = i + 1; j < n; j++)
        {
            num1 = temp[i]; 
            num2 = mat[j][i]; 
            for (int k = 0; k < n; k++)
            {
                mat[j][k]
                    = (num1 * mat[j][k]) - (num2 * temp[k]);
            }
            total = total * num1; 
        }
    }
    for (int i = 0; i < n; i++)
    {
        det = det * mat[i][i];
    }
    return (det / total);
}

int main()
{

    scanf("%d", &N);
    int mat[N][N];
    
    for(int i = 0 ; i < N ; i++)
    {
        for(int j = 0 ; j < N ; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Determinant of the matrix is : %d",
           determinantOfMatrix(mat, N));
    return 0;
}
