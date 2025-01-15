
#include<stdio.h>
int adj[10][10],count_v,s=-1,stack[100],top=-1;
void push (int val)
{
top = top +1;
stack[top] = val;
}
int pop ()
{
int v=stack[top];
top = top -1;
return(v);
}

void DFS()
{
int visit[count_v],i,j,vertex;
for(i=0;i<count_v;i++)
{
visit[i]=0;
}
while((s<0)||(s>count_v))
{
printf("Enter a source vertex :");
scanf("%d",&s);
}
push(s);
while(top!=-1)
{
vertex=pop(); //pop a vertex from queue
if(visit[vertex]==0) //visit
{
printf("%d ",vertex);
visit[vertex]=1;
for(i=0;i<count_v;i++) //explore
{
if(adj[vertex][i]==1)
{
push(i);
}
}
}
}
}

int main()
{
printf("Enter the no .of vertices of graph :");
scanf("%d",&count_v);
printf("Enter the %d X %d Adjacency matrix :",count_v,count_v);
for(int i=0;i<count_v;i++)
{
for(int j=0;j<count_v;j++)
{
printf("\nEnter '1' if tere is an edge from %d to %d otherwise enter '0' :",i,j);
scanf("%d",&adj[i][j]);
}
}
for(int i=0;i<count_v;i++)
{
for(int j=0;j<count_v;j++)
printf("%d ",adj[i][j]);
printf("\n");
}
DFS();
return 0;
}
