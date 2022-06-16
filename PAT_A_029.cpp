//未AC代码，在cost比较部分还没有写完
#include <iostream>
#include <algorithm>

#define INFINITY 0x3fffffff

using namespace std;

int main(){
    int n,m,s,d;
    cin >> n >> m >> s >> d;
    int len[n][n] = {INFINITY};
    int cost[n][n] = {INFINITY};
    for(int i = 0;i < n; ++ i){
        for(int j = 0;j < n;++j){
            len[i][j] = INFINITY;
            cost[i][j] = INFINITY;
        }
    }
    for(int i = 0;i < m;++i){
        int begin,end,l,c;
        cin >> begin >> end >> l >> c;
        len[begin][end] = l;
        len[end][begin] = l;
        cost[begin][end] = c;
        cost[end][begin] = c;
    }
    int dist[n],pre[n];
    bool isVisited[n] = {false};
    int current = s;
    isVisited[s] = true;
    copy(len[s],len[s] + n,dist);
    int index = -1;
    while (index != d)
    {
        int max = INFINITY;
        for(int i = 0;i < n;++i){
            if(!isVisited[i]){
                if(max > dist[i]){
                    max = dist[i];
                    index = i;
                }
            }
        }
        isVisited[index] = true;
        if(dist[index] > dist[current] + len[current][index]){
            dist[index] = dist[current] + len[current][index];
            pre[index] = current;
        }else{
            pre[index] = s;
        }
        current = index;
    }
    current = d;
    string result_l = "";
    int r_c = 0,r_l = 0;
    while (current != s)
    {
        result_l = " " + to_string(current) + result_l;
        r_c += cost[current][pre[current]];
        r_l += len[current][pre[current]];
        current = pre[current];  
    }
    result_l = to_string(s) + result_l;
    cout << result_l << " " << r_l <<" " << r_c << endl;
    
}