#include<stdio.h>
void bfs(int);
int a[100][100],vis[100],n;

void main()
{
   int i,j,src;

   printf("enter the number of vertices : ");
   scanf("%d",&n);
   printf("enter the adjacency matrix\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
	 scanf("%d",&a[i][j]);

      }

      vis[i]=0;
   }

   printf("enter the scr vertex\n");
   scanf("%d",&src);
   printf("nodes reachable from scr vertex\n");
   bfs(src);

}

void bfs(int v)
{
    int q[100],f=1,r=1,u,i;
    q[r]=v;
    vis[v]=1;
    while(f<=r)
    {
       u=q[f];
       printf("%d ",u);
       for(i=1;i<=n;i++)
       {
	  if(a[v][i]==1 && vis[i]==0)
	  {
	     vis[i]=1;
	     r=r+1;
	     q[r]=i;
	  }
       }
       f=f+1;
    }
}
