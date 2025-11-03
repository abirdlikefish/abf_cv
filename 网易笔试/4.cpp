//又看错题了，但大部分锅是题目描述的，完全没讲清楚。有两种理解一种是走到终点时间最短，一种是路径连通时间最短。感觉前者更难所以我按前者写直接gg，改成后面的过了。
//题目: 网格地图，每个格子有高度，水面初始高度为0，每过一小时水面高度+1，给你起点终点坐标，问起点终点间有一条路全是水的时间。
//最短路变种，用的dijkstra


#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int N , M;
int dis[1000][1000];
int height[1000][1000];
bool isVisited[500000];
int lastPos[500000];

// minDis , gridIndex
priority_queue<pair<int , int> , vector<pair<int,int>> ,greater<pair<int,int>> > pq;

//gridIndex , x,y
// vector<pair<int,int>> gridMap;

int pairToIndex(pair<int,int> p)
{
    return (p.first - 1) * (M) + p.second - 1;
}

pair<int,int> indexToPair(int index)
{
    return {index / M + 1 , index % M + 1};
}

bool judge(pair<int,int> pos)
{
    if(pos.first < 1 || pos.second < 1 || pos.first > N || pos.second > M)
        return false;
    return true;
}

int dir_x[4] = {1,-1,0,0};
int dir_y[4] = {0,0,1,-1};


int main() {
    cin >> N >> M;
    pair<int,int> begPos;
    pair<int,int> endPos;
    cin >> begPos.first >> begPos.second;
    cin >> endPos.first >> endPos.second;
    for(int i = 1 ; i <= N ; i ++)
    {
        for(int j = 1 ; j <= M ; j ++)
        {
            cin >> height[i][j];
            dis[i][j] = 0x3f3f3f3f;
        }
    }
    dis[begPos.first][begPos.second] = height[begPos.first][begPos.second];
    pq.push({dis[begPos.first][begPos.second],pairToIndex(begPos)});

    while(pq.empty() == false)
    {
        auto mid = pq.top();
        pq.pop();
        auto pos = indexToPair(mid.second);
        // int curHeight = height[pos.first][pos.second];
        if(mid.first != dis[pos.first][pos.second])
            continue;
        // if(isVisited[mid.second])   continue;
        // isVisited[mid.second] = true;
        int curDis = mid.first;
        for(int i = 0 ; i < 4 ; i ++)
        {
            pair<int,int> nexPos = pos;
            nexPos.first += dir_x[i];
            nexPos.second += dir_y[i];
            if(judge(nexPos) == false)
                continue;
            int nexDis = max(curDis , height[nexPos.first][nexPos.second]);
            if(nexDis < dis[nexPos.first][nexPos.second])
            {
                dis[nexPos.first][nexPos.second] = nexDis;
                pq.push({nexDis , pairToIndex(nexPos)});
                lastPos[pairToIndex(nexPos)] = mid.second;
            }
        }
    }
    // cout << dis[endPos.first][endPos.second] << endl;
    int ans = height[begPos.first][begPos.second];
    auto ptr_beg = pairToIndex(endPos);
    auto ptr_end = pairToIndex(begPos);
    while(ptr_beg != ptr_end)
    {
        auto midPos = indexToPair(ptr_beg);
        ans = max(ans , height[midPos.first][midPos.second]);
        ptr_beg = lastPos[ptr_beg];
    }
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")
