/**Program to test whether both matrix are equal or not**/
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int mat_A[10][10], mat_B[10][10], n;
	printf("Please enter the size of the matrix: ");
	scanf("%d", &n);
	//Matrix A:
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("Please enter the A[%d] [%d] element: ", i+1, j+1);
			scanf("%d", &mat_A[i][j]);
		}
	}
	//Matrix B:
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("Please enter the B[%d] [%d] element: ", i+1, j+1);
			scanf("%d", &mat_B[i][j]);
		}
	}
	//Checking whether A and B are equal or not
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(mat_A[i][j] != mat_B[i][j])
			{
				printf("\nThe matrices are not equal!!\n");
				return 0;
			}
		}
	}
	printf("\n!!The matrices are equal\n");
	return 0;
}
