/**Program for identity matrix **/
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int mat_A[10][10], n;
	
	printf("Please enter the size of the matrix: ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("PLease enter %d %d element: ", i+1,j+1);
			scanf("%d", &mat_A[i][j]);
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n;j++)
		{
			if(i == j && mat_A[i][j] != 1)
			{
				printf("The matrix is not identity\n");
				return 0;
			}
			
			else if(i != j && mat_A[i][j] != 0)
			{
				printf("The matrix is not identity\n ");
				return 0;
			}
		}
	}
	printf("The matrix is identity\n");
	return 0;
}
