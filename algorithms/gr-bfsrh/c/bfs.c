#include<stdio.h>
int size;
void breadth_first_search(int adj[][size],int visited[],int start);

int main()
{
  printf("Enter the number of nodes to populate the graph: ");
  scanf("%d",&size);
  int visited[20] = {0};
  int adj[size][size],i,j;

  printf("\n Enter the adjacency matrix: ");
    for(i=0;i<size;i++)
      for(j=0;j<size;j++)
        scanf("%d",&adj[i][j]);
    breadth_first_search(adj,visited,0);
  return 0;
}

void breadth_first_search(int adj[][size],int visited[],int start)
{
	int queue[size],rear=-1,front=-1,i;
	queue[++rear]=start;
	visited[start]=1;
	while(rear!=front)
	{
		start=queue[++front];
		printf("%c\t",start+65);
		for(i=0;i<size;i++)
		{
			if(adj[start][i]==1 && visited[i]==0)
			{
				queue[++rear]=i;
				visited[i]=1;
			}
		}
	}
}
