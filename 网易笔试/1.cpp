// 打卡题，没啥好说的


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> input;
int main() {
    int n,m;
    cin >>n  >> m;
    for(int i = 0 ; i < n ; i ++)
    {
        int beg , atk;
        cin >> beg >> atk;
        input.push_back({beg , atk});
        input.push_back({beg + m , -atk});
    }
    sort(input.begin() , input.end());
    int ret = 0;
    int ans = 0;
    for(int i = 0 ; i < input.size() ; i ++)
    {
        ans += input[i].second;
        ret = max(ret , ans);
    }
    cout << ret << endl;
    return 0;

}
// 64 位输出请用 printf("%lld")