// visual studio 2017 in C.

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct interval
{
	int x;
	int y;
}interval;
typedef struct Degrees
{
	int max;
	int min;
}Degrees;

void sort_graph(interval *arr, int k);
void swap(interval *a, interval *b);
void GreedyColoring();
Degrees F_Edges(interval*arr, int* Degs, int* Edges, Degrees MMDegs, int k);
void Opt_Coloring(interval *arr, int colorMax, int *color, int k);
void IPrint(interval *arr, int k);

void swap(interval *a, interval *b)
{
	interval temp = *a;
	*a = *b;
	*b = temp;
}
void sort_graph(interval *arr, int k)
{
	int i, j;
	for (i = 0; i < k; i++) //loop to sort intervals
	{
		for (j = 0; j < k; j++)
		{
			if (arr[i].x < arr[j].x)
				swap(&(arr[i]), &(arr[j]));
		}
	}
}
int color_graph(interval *arr, int *color, int k) {//it has arr color colorMax
	int i, j, colorMax = 0;
	for (i = k - 1; i >= 0; i--) //loop to find edges, max deg, , min deg, and chromatic number
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[i].x > arr[j].y) continue;

			if (color[i] == color[j])
				color[j]++;
			if (colorMax < color[j])
				colorMax = color[j];
		}
	}
	return colorMax;
}
Degrees F_Edges(interval*arr, int* Degs, int* Edges,Degrees MMDegs,int k)
{
	int i, j;
	for (i = 0; i < k - 1; i++) //loop to find edges, max deg, , min deg
	{
		for (j = i + 1; j < k; j++)
		{

			if (arr[i].y < arr[j].x) continue;
			else
			{
				Degs[i]++;
				Degs[j]++;
				(*Edges)++;
			}
		}

	}

	for (i = 0; i < k; i++)
	{
		if (Degs[i] > MMDegs.max)
			MMDegs.max = Degs[i];
		if (Degs[i] < MMDegs.min)
			MMDegs.min = Degs[i];
	}

	return MMDegs;
}
void Opt_Coloring(interval *arr, int colorMax, int *color, int k)
{
	int i, j,flag=0, *count=(int*)calloc(colorMax,sizeof(int));
	for (i = 0; i <= colorMax; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (color[j] == i)
				count[i]++;
		}
	}
		for (i = 0; i <= colorMax; i++)
		{
			flag = 0;
			printf("{");
			for (j = 0; j  <  k;j++ )
			{
				if (color[j] == i) {
					printf("[%d,%d]", arr[j].x, arr[j].y);
					flag++;
					if (flag >= count[i])
						printf("}");
					else
						printf(",");
				}
			}
			printf(" = %d", i + 1);
			if (colorMax != i)
				printf(",  ");
		}
		printf("\n");
}
void IPrint(interval *arr, int k)
{
	int i, x, y;
	for (i = 0; i < k; i++) //loop to get intervals
	{
		printf("Input Interval number %d:\n", i + 1);
		scanf("%d%d", &x, &y);
		interval new = { x,y };
		arr[i] = new;
	}
	printf("The interval family is:\n");
	for (i = 0; i < k; i++)
	{
		printf("[%d,%d] ", arr[i].x, arr[i].y);
	}
	printf("\n");
	sort_graph(arr, k);//sorting the graph
}

void main()
{
	GreedyColoring();
}


void GreedyColoring()
{
	int k, i, j, Edges = 0, colorMax = 0;
	printf("Input number of intervals:\n");
	scanf("%d", &k);
	Degrees MMDegs = { 0,k - 1 };//min and max degree keeper
	int* Degs = (int*)calloc(k, sizeof(int));//array of all degrees
	int *color = (int*)calloc(k, sizeof(int));//array of all colors
	interval* arr = (interval*)calloc(k, sizeof(interval));//array of all intervals
	IPrint(arr, k);//prints the array of intervals as are
	MMDegs = F_Edges(arr, Degs, &Edges, MMDegs,k);//finding the edges and max min degrees
	printf("G Edges=%d\n", Edges);
	printf("Max Degree of G=%d\n", MMDegs.max);
	printf("min Degree of G=%d\n", MMDegs.min);
	colorMax = color_graph(arr, color, k);//coloring the graph
	printf("Chromatic number of G=%d\n", colorMax + 1);
	printf("G's compliment Edges=%d\n", ((k*(k - 1)) / 2) - Edges);
	printf("Max Degree of G's compliment=%d\n", k - MMDegs.min - 1);
	printf("Min Degree of G's compliment=%d\n", k - MMDegs.max - 1);
	printf("Optional coloring: ");
	Opt_Coloring(arr, colorMax, color, k);//prints the optional coloring
	system("pause");

}