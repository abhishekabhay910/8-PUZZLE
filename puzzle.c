#include<stdio.h>
#include<stdlib.h>
int difference(int arr_in[][3], int arr_fi[][3]) //heuristic funtion
{
	int counter =0 ,i,j;
	for(i=0;i<3; i++)
	for( j=0;j<3;j++)
	{
	if(arr_in[i][j]!=0)
	{
	if(arr_in[i][j] != arr_fi[i][j])
	counter++;
	}
	}
	return counter;
}
void display(int arr_in[][3]) //to display the puzzle
{
	int i,j;
	for(i=0;i<3;i++)
	{
	for(j=0;j<3;j++)
	printf("%d ", arr_in[i][j]);
	printf("\n");
	}
}
int diffup(int arr_in[][3], int arr_fi[][3]) //calculate heruristic value if up operation is done
{
	int temp[3][3], i, j;
	for(i=0;i<3;i++)
	for (j=0;j<3;j++)
	temp[i][j] = arr_in[i][j];
	for(i=1;i<3;i++)
	for (j=0;j<3;j++)
	if(arr_in[i][j]==0)
	{
		temp[i-1][j] = 0;
		temp[i][j] = arr_in[i-1][j];
	}
	return difference(temp, arr_fi);                        
}
int diffdown(int arr_in[][3], int arr_fi[][3]) //calculate heruristic value if down operation is done
{
	int temp[3][3], i, j;
	for(i=0;i<3;i++)
	for (j=0;j<3;j++)
	temp[i][j] = arr_in[i][j];
	for(i=0;i<2;i++)
	for (j=0;j<3;j++)
	if(arr_in[i][j]==0)
	{
		temp[i+1][j] = 0;
		temp[i][j] = arr_in[i+1][j];
	}
	return difference(temp, arr_fi);                        
}
int diffleft(int arr_in[][3], int arr_fi[][3]) //calculate heruristic value if left operation is done
{
	int temp[3][3], i, j;
	for(i=0;i<3;i++)
	for (j=0;j<3;j++)
	temp[i][j] = arr_in[i][j];
	for(i=0;i<3;i++)
	for (j=1;j<3;j++)
	if(arr_in[i][j]==0)
	{
		temp[i][j-1] = 0;
		temp[i][j] = arr_in[i][j-1];
	}
	return difference(temp, arr_fi);                        
}
int diffright(int arr_in[][3], int arr_fi[][3]) //calculate heruristic value if right operation is done
{
	int temp[3][3], i, j;
	for(i=0;i<3;i++)
	for (j=0;j<3;j++)
	temp[i][j] = arr_in[i][j];
	for(i=0;i<3;i++)
	for (j=0;j<2;j++)
	if(arr_in[i][j]==0)
	{
		temp[i][j+1] = 0;
		temp[i][j] = arr_in[i][j+1];
	}
	return difference(temp, arr_fi);                        
}
int minimum (int a, int b, int c , int d) //returns minimum value among all possible heuristic value
{
	int min = a;
	if(b<min)
	min= b;
	if(c<min)
	min = c;
	if(d<min)
	min = d;
	return min;
}
int puzzle(int arr_in[][3], int arr_fi[][3]) //solves puzzle
{
	int dup, ddown, dleft, dright;
	int temp, i , j,serial=0;
	char ran[4];
	dup = diffup(arr_in,arr_fi);
	ddown = diffdown(arr_in,arr_fi);
	dleft = diffleft(arr_in,arr_fi);
	dright = diffright(arr_in,arr_fi);
	printf("Right\tLeft\tUp\tDown\n");
	printf("%d\t%d\t%d\t%d\n",  dright, dleft, dup, ddown);
	int min = minimum(dup, ddown, dleft, dright);
	printf("%d\n", min);
	if (min == dright)
	ran[serial++] = 'r';
	if (min == dleft)
	ran[serial++] = 'l';
	if (min == dup)
	ran[serial++] = 'u';
	if (min == ddown)
	ran[serial++] = 'd';
	int sel = rand()%serial; //selects operation to be done
	char change = ran[sel];
	if(change == 'r')
	{
	for(i=0;i<3;i++) 
	for (j=0;j<2;j++) 
	if(arr_in[i][j]==0)
	{
	arr_in[i][j] = arr_in[i][j+1];
	arr_in[i][j+1] = 0;
	printf("right\n");
	return 0;
	}
	}
	else if(change == 'l')
	{
	for(i=0;i<3;i++) 
	for (j=1;j<3;j++) 
	if(arr_in[i][j]==0)
	{
	arr_in[i][j] = arr_in[i][j-1];
	arr_in[i][j-1] = 0;
	printf("left\n");
	return 0;
	}
	}
	else if(change == 'u')
	{
	for(i=1;i<3;i++) 
	for (j=0;j<3;j++) 
	if(arr_in[i][j]==0)
	{
	arr_in[i][j] = arr_in[i-1][j];
	arr_in[i-1][j] = 0;
	printf("up\n");
	return 0;
	}
	}
	else if(change == 'd')
	{
	for(i=0;i<2;i++) 
	for (j=0;j<3;j++) 
	if(arr_in[i][j]==0)
	{
	arr_in[i][j] = arr_in[i+1][j];
	arr_in[i+1][j] = 0;
	printf("down\n");
	return 0;
	}
	}
	return 0;
}
int main()
{
	int arr_in[3][3],arr_fi[3][3],i,j,d,steps=0;
	printf("enter puzzle's initial position: \n");
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
	scanf("%d",&arr_in[i][j]);
	}
	printf("enter puzzle's final position: \n");
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
	scanf("%d",&arr_fi[i][j]);
	}
	printf("Goal: \n");
	display(arr_fi);
	printf("Initial: \n");
	display(arr_in);
	d = difference(arr_in, arr_fi);
	printf("Initial Heuristic Value %d",d);
	while(1) //runs until goal state is not reached
	{
	d = difference(arr_in, arr_fi);
	if(d==0)
	{
	printf("Goal state is reached in %d steps.", steps);
	return 0;
	}
	steps++;
	printf("\nStep: %d \n", steps);
	if(steps==16)
	return 0;
	puzzle(arr_in, arr_fi);
	display(arr_in);
	}
	return 0;
}
