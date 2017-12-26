#include<stdio.h>

int max (int x, int y);

void main ()
{
  int items,W,i,j,index;
  int weights[20];
  int value[20];
  int array[20];
	
  printf("Enter number of elements : \n");
  scanf("%d",&items);
  
  printf("Enter weight of Knapsack : \n");
  scanf("%d",&W);
  
  for(i=1;i<=items;i++)
  {
  	printf("Enter the weight of item %d :",i);
  	scanf("%d",&weights[i]);
  }
  
  for(i=1;i<=items;i++)
  {
  	printf("Enter the value of item %d :",i);
  	scanf("%d",&value[i]);
  }

  int table[items+1][W+1];

  //Weight = 0
  for (i = 0; i <= items; i++)
    {
      table[i][0] = 0;
    }

  //items = 0
  for (j = 0; j <= W; j++)
    {
      table[0][j] = 0;
    }

  //Filling the table
  for (j = 1; j <= W; j++)
    {
      for (i = 1; i <= items; i++)
      	{
	
        	if(weights[i] <= W) {
        		if(j - weights[i]<0)
        			table[i][j] = table[i-1][j];
        		else
        			table[i][j] = max(table[i-1][j], value[i] + table[i-1][j - weights[i]]);
        	} 
        	else {
        		table[i][j] = table[i-1][j];
        	}	
        	
        }
    }

  //Printing the table
  printf("Printing table\n");
  for (i = 0; i <= items; i++)
    {
      for (j = 0; j <= W; j++)
      	{
	        printf ("%d\t", table[i][j]);
      	}
      printf ("\n");
    }

  printf("Total value : %d\n",table[items][W]);//print value of knapsack

  //Backtracking for finding the items to be included in Knapsack
  i=items;
  j=W;
  index = 1;
  
  while(i>0)
  {
    if(table[i][j]!=table[i-1][j])
    	{
    		array[index] = i;
    		index++;
    		j=j-weights[i];
    		i--;
    	}
    else
         i--;
 }
  
  printf("Items Included:\n");
 //Printing all the items included
  for(i=index-1;i>=1;i--)
    printf("%d\n",array[i]);
}
  
int max (int x, int y)//Function to find maximum of 2 numbers
  {
    if (x >= y)
      return x;
    else
      return y;
  }

