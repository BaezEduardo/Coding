#include <stdio.h>

void leeMat(int x[3][3])
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("\nDeme el dato %d %d\n", i, j);
			scanf("%d", &x[i][j]);
		}
	}
}

void Matnula(int x[3][3])
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			x[i][j]=0;
		}
	}
}

void MatIden(int x[3][3])
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(i=j)
			{
				x[i][j]=1;
			}
			else
			{
				x[i][j]=0;
			}
		}
	}
}

void Escmat(int x[3][3])
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d", x[i][j]);
		}
		printf("\n");
	}
}

void suma(int x[3][3], int y[3][3], int z[3][3])
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			z[i][j]=x[i][j]+y[i][j];
		}
	}
}

void resta(int x[3][3], int y[3][3], int z[3][3])
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			z[i][j]=x[i][j]-y[i][j];
		}
	}
}

int main()
{
	int A[3][3], B[3][3], C[3][3], op;
	while(op!= 13)
	{
		printf("Opciones del menu:\n1. Lee A\n2. Lee B\n3. Lee C\n4. A = 0\n5. B = 0\n6. A = I\n7. B = I\n8. C = A + B\n9. C = A - B\n10. Escribe A\n11. Escribe B\n12. Escribe C\n13. Fin\n");
		printf("Deme su opcion:\n");
		scanf("%d", &op);
		if(op=1)
		{
			printf("\nDeme la matriz A");
			leeMat(A);
		}
		if(op=2)
		{
			printf("\nDeme la matriz B");
			leeMat(B);
		}
		if(op=3)
		{
			printf("\nDeme la matriz C");
			leeMat(C);
		}
		if(op=4)
		{
			Matnula(A);
		}
		if(op=5)
		{
			Matnula(B);
		}
		if(op=6)
		{
			MatIden(A);
		}
		if(op=7)
		{
			MatIden(B);
		}
		if(op=8)
		{
			suma(A, B, C);
		}
		if(op=9)
		{
			resta(A, B, C);
		}
		if(op=10)
		{
			Escmat(A); 
		}
		if(op=11)
		{
			Escmat(B);
		}
		if(op=12)
		{
			Escmat(C);
		}
	}
}
