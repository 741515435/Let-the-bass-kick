#include <bits/stdc++.h>
#define ll __int64
#define N 1000000+5

using namespace std;


int visit[505][505],dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char maze[505][505];
int m,n;
bool judge(int x,int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == '#' || visit[x][y] != 0)
        return false;
    return true;
}


struct nodes
{
    int x,y;
};
int BFS(int mark,int x,int y)
{
    queue<nodes>Q;
    int ans = 0;
    nodes cur,tmp;
    cur.x = x;
    cur.y = y;
    visit[cur.x][cur.y] = mark;
    Q.push(cur);
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        if(maze[cur.x][cur.y] == 'C')
            ans++;


        for(int i = 0; i < 4; i++)
        {
            tmp.x = cur.x + dir[i][0];
            tmp.y = cur.y + dir[i][1];
            if(judge(tmp.x,tmp.y))
            {
                visit[tmp.x][tmp.y] = mark;
                Q.push(tmp);
            }

        }
    }
    return ans;
}

void solve()
{
    int q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i = 0; i < n; i++)
        scanf("%s",maze[i]);
    map<int,int>locate;
    memset(visit,0,sizeof(visit));
    int mark = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(visit[i][j] == 0 && maze[i][j] != '#')
            {
                int ans = BFS(mark,i,j);
                //printf("%d %d %d\n",i,j,ans);
                locate[mark] = ans;
                mark++;
            }
        }
    }
    while(q--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        x--;
        y--;
        cout<<locate[visit[x][y]]<<endl;
    }
}

int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++cnt);
        solve();
    }
    return 0;
}
