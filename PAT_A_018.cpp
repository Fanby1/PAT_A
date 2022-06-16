#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 题目大意：
 * 输入：
 * 第一行：
 * c为每一个站承受的最大值，N为站的数量，s为存在问题的站的编号，M为站之间路径的总数
 * 第二行：n个站目前的自行车数量
 * 接下来M行，为站与站之间路径的权值
 * 输出：
 * 第一个数字是为保证最短路径上各个站达到完美状态（c的一半）所需要PBMC运送出自行车的数量；接下来是最短路径，由编号组成的路径；第三个数字是为保证最大UN路径上各个站达到完美状态需要运回PMBC的自行车数量
 * （注意：如果存在多个最短路径，需要按输出格式输出的是第三个数字为最小的那条最短路径）
 */

const int inf = 99999999;
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
//pre存放的是最短路径，以编号为索引，存放的是到达已知编号的站的最短距离情况下的前一站的编号
vector<int> pre[510];
vector<int> path, temppath;

/*
 * dfs主要对path和temppath进行更新
 * dfs里的递归可能有点难理解，但是你可以在递归到v==0开始思考，v==0时结束递归，返回上一个递归，以此返回，然后temppath为空
 * 为什么temppath必须pop，原因是需要保证在存在多条最短路径的时候，在另外路径上进行递归时不会存在temppath更新，导致答案错误
 */
void dfs(int v) {
    temppath.push_back(v);
    if(v == 0) {
        //need为需要PMBC运出的数量，back为需要运回PMBC的数量
        int need = 0, back = 0;
        //主要是对need和back进行更新
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            //判断是否多出来自行车，如果多出来，添加到back，否则从back中减去，如果不够减，则更新need
            if(weight[id] > 0) {
                back += weight[id];
            } else {
                if(back > (0 - weight[id])) {
                    back += weight[id];
                } else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        //更新minNeed和minBack，作为输出的第三个数字，并以此判断temppath是否为需要的最短路径
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        //需要pop的原因是为保证一开始temppath为空
        temppath.pop_back();
        return ;
    }
    //递归到v==0，然后结束
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    //需要pop的原因是为保证一开始temppath为空
    temppath.pop_back();
}
int main() {
    //初始化
    fill(e[0], e[0] + 510 * 510, inf);
    fill(dis, dis + 510, inf);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - cmax / 2;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%d", &e[a][b]);
        e[b][a] = e[a][b];
    }
    dis[0] = 0;
    //dijkstra算法的标准格式，寻找最短路径
    for(int i = 0; i <= n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        //主要是根据已知最短距离的确定点，开始对dis数组进行更新和对pre数组的更新
        for(int v = 0; v <= n; v++) {
            if(visit[v] == false) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(sp);
    printf("%d 0", minNeed);
    //注意，从倒数第二个元素开始的原因是为了保证输出格式，最后一个元素为0
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}
