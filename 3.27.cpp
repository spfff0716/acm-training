#include <bits/stdc++.h>
using namespace std;
bool vis[310][310];
int boom[310][310];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool allow(int x,int y)
{
if(x>=0&&x<=300&&y>=0&&y<=300)
return true;
return false;
}
const int N=10000000;
struct node
{
int x,y,time;
};
int main()
{
int m;
cin>>m;
int x,y,time;
for(int i=0;i<310;i++)
{
for(int j=0;j<310;j++)
{
boom[i][j]=N;
}
}
memset(vis,false,sizeof(vis));
for(int i=0;i<m;i++)
{
cin>>x>>y>>time;
if(x > 300 || y > 300) continue;
boom[x][y]=min(boom[x][y],time);
for(int j=0;j<4;j++)
{
int nx=x+dx[j];
int ny=y+dy[j];
if(allow(nx,ny))
boom[nx][ny]=min(boom[nx][ny],time);
}
}
queue<node>q;
q.push({0,0,0});
vis[0][0]=true;
while(!q.empty())
{
node now=q.front();
q.pop();
x=now.x;y=now.y;time=now.time;
if(time>=boom[x][y])
continue;
if(boom[x][y]==N)
{
cout<<time;
return 0;
}
for(int i=0;i<4;i++)
{
int nex=x+dx[i];
int ney=y+dy[i];
if(allow(nex,ney)&&!vis[nex][ney])
{
if(time+1<boom[nex][ney])
{
vis[nex][ney]=true;
q.push({nex,ney,time+1});
}
}
}
}
cout<<-1;
return 0;
}
