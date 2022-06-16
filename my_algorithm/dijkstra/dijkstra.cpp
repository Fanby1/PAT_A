/*
    算法简介
    Dijkstra算法是解决**单源最短路径**问题的**贪心算法**
    它先求出长度最短的一条路径，再参照该最短路径求出长度次短的一条路径
	直到求出从源点到其他各个顶点的最短路径。

    基本思想
    首先假定源点为u，顶点集合V被划分为两部分：集合 S 和 V-S。	初始时S中仅含有源点u，其中S中的顶点到源点的最短路径已经确定。
    集合S 和V-S中所包含的顶点到源点的最短路径的长度待定，称从源点出发只经过S中的点到达V-S中的点的路径为特殊路径，
    并用dist[]记录当前每个顶点对应的最短特殊路径长度。

    贪心策略
    选择特殊路径长度最短的路径，将其连接的V-S中的顶点加入到集合S中，同时更新数组dist[]。一旦S包含了所有顶点，dist[]就是从源到所有其他顶点的最短路径长度。
    （1）数据结构。 
        设置地图的带权邻接矩阵为map[][]，即如果从源点u到顶点i有边，就令map[u][i]=<u,i>的权值，否则map[u][i]=∞；
        采用一维数组dist[i]来记录从源点到i顶点的最短路径长度：采用一维数组p[i]来记录最短路径上i顶点的前驱。
    （2）初始化。
        令集合S={u}，对于集合V-S中的所有顶点x，初始化dist[i]=map[u][i],如果源点u到顶点i有边相连，初始化p[i]=u(i的前驱是u),否则p[i]=-1
    （3）找最小。
        在集合V-S中依照贪心策略来寻找使得dist[j]具有最小值的顶点t,即dist[t]=min，则顶点t就是集合V-S中距离源点u最近的顶点。
    （4）加入S战队。
        将顶点t加入集合S，同时更新V-S
    （5）判结束。
        如果集合V-S为空，算法结束，否则转6
    （6）借东风。
        在（3）中已近找到了源点到t的最短路径，那么对集合V-S中所有与顶点t相邻的顶点j，都可以借助t走捷径。
	        如果dist[j]>dist[t]+map[t][j],则dist[j]=dist[t]+map[t][j]，记录顶点j的前驱为t，p[j]=t，转（3）。
	//我自己在这里理解就是，从u找到与它最近的点t，在从t找到与它最近的点j，在....按照这样持续下去，直到最后一个点
	    这里我再通俗的解释下这个借东风的意思。
	    源点为1，如果我们找到了距离源点最近的点2，且点2与3,4相连。
	    这样，我们如果要倒3,4有两种方法：
		    1->2->3(4)
		    1->3(4)
	    这里我们就要判断是从1直接到3(4)快，还是经过2后快。假设<1,2>=2 / <2,3>=3 / <1,3>=4
	    根据上面的数据，我们第一次找最小找到的是2结点，如果我们直接把2替换掉1当做源点继续找下一个最近的点，这种方法是错的。
	        因为可以看出1->3只用4，而过2的话要用5。
*/


#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

#define INFINITY 0x3fffffff
#define u 0

using namespace std;

bool dijkstra(int *dist,int *pre, int **map, int staions);

int main(){
    string filename = "C:\\Users\\cookie\\Desktop\\PAT\\my_algorithm\\dijkstra\\source.txt";
    ifstream ifst(filename,ios::binary);
    int stations,roads;
    ifst >> stations >> roads;
    stations++;
    int **map = new int*[stations];

    for(int i = 0;i < stations;i++){
        map[i] = new int[stations];

        for(int j = 0;j < stations;++j){
            map[i][j] = INFINITY;
        }
    }

    for(int i = 0;i < roads;++i){
        int begin,end;
        ifst >> begin >> end;
        ifst >> map[begin][end];
        map[end][begin] = map[begin][end];
    }

    int *dist = new int[stations],*pre = new int[stations];
    for(int i = 0;i < stations;i++){
        pre[i] = -1;
    }

    copy(map[u],map[u] + stations,dist);

    dijkstra(dist,pre,map,stations);

    for(int i = 0;i < stations;i++){
        cout << dist[i] << " " << pre[i] << endl;
    }

}

bool dijkstra(int *dist, int *pre, int **map, int stations){
    bool flag = true;
    int c = u;
    int min = INFINITY;
    int n = -1;
    set<int> vessel;
    for(int i = 1;i < stations;i++){
        vessel.insert(i);
    }
    while(flag){
         
        for(auto i : vessel){
            if(i != c){
                if(map[c][i] < min){
                    min = map[c][i];
                    n = i;
                }
            }
        }
        if(dist[n] < dist[c] + min){
            pre[n] = u;
        }else{
            pre[n] = c;
            dist[n] = dist[c] + min;
        }
        vessel.erase(n);
        if(vessel.size() == 0){
            break;
        }
        c = n;
        n = -1;
        min = INFINITY;
    }
    return true;
}
