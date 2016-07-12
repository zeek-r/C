/** Program to multiply two matrices and display the product as well **/
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int mat_A[10][10], mat_B[10][10], mat_C[10][10], n1, n2, m1, m2;
	printf("PLease enter the size of the matrix A: ");
	scanf("%d %d", &n1, &n2);
	printf("Please enter the size of the matrix B: ");
	scanf("%d %d", &m1, &m2);
	if(n2 != m1)
	{
		printf("\n!!The two matrices differ in size, can't mutiply!!\n**Please enter the size of the matrix in such a way that column of the first matches the row of the second\n");
		return 0;
	}
	//Matrix A builder:
	for(int i = 0; i < n1; i++)
	{
		for(int j = 0; j < n2; j++)
		{
			printf("Please enter the A %d %d element: ",i+1, j+1);
			scanf("%d", &mat_A[i][j]);
		}
	}
	//Matrix B builder:
	for(int i = 0; i < m1; i++)
	{
		for(int j = 0; j < m2; j++)
		{
			printf("Please enter the B %d %d element: ",i+1, j+1);
			scanf("%d", &mat_B[i][j]);
		}
	}
	//Matrix Multiplier
	for(int i = 0; i < n1; i++)
	{
		for(int j = 0; j < m2; j++)
		{
			int sum = 0;
			for(int k = 0; k < n2; k++)
			{
				sum = sum + (mat_A[i][k]*mat_B[k][j]);
			}
			mat_C[i][j] = sum;
		} 
	}
	//Matrix printing
	printf("The matrix after multiplication and its transpose is:\n");
	printf("Multiplied matrix:\t \tTranspose MAtrix:\n");
	for(int i = 0; i < n1; i++)
	{
		for(int j = 0; j < m2; j++)
		{
			printf("%d\t", mat_C[i][j]);
		}
		printf("\t \t");
		for(int j = 0; j < m2; j++)
		{
			printf("%d\t", mat_C[j][i]);
		}
		printf("\n");
	}
	
}
