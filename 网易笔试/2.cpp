// 完全背包，题目描述有点绕一开始没看懂，我把其他题目写的差不多了再回头看才看明白，就是一个完全背包，问从几个数中可重复的取几个累加到某个区间的取的次数的最小值

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minCnt[2000];
vector<int> atk;

int main() {
    int M;
    cin >> M;
    while(M--)
    {
        atk.clear();
        int orgHP , lHP , uHP;
        cin >> orgHP >> lHP >> uHP;
        int lefHP = orgHP - uHP;
        int rigHP = orgHP - lHP;
        int N;
        cin >> N;
        for(int i = 0 ; i < N ; i ++)
        {
            int input;
            cin >> input;
            atk.push_back(input);
        }
        memset(minCnt , 0x3f , sizeof(minCnt));
        minCnt[0] = 0;
        for(int i = 0 ; i < N ; i ++)
        {
            for(int j = atk[i] ; j <= rigHP ; j ++)
            {
                minCnt[j] = min(minCnt[j] , minCnt[j - atk[i]] + 1);
            }
        }
        int ans = minCnt[lefHP];
        for(int i = lefHP ; i <= rigHP ; i ++)
        {
            ans = min(ans , minCnt[i]);
        }
        if(ans == 0x3f3f3f3f)
            cout << 0 << endl;
        else
            cout << ans << endl;
    }
}
// 64 位输出请用 printf("%lld")