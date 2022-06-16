#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 2147483647;
using namespace std;

int Cmax, D, Davg, N;//油箱容量， 杭州到目的地的距离， 单位油行驶距离，加油站数量
int CD;//满油能跑的距离

int cheapSta[500];//汽车从车站i行驶满油距离所经过的最便宜的油站
bool canReach = true;
double res_dis, res_cost;

struct Station{
    double price, distance;
};
Station sta[501];//车站数组

bool disCompare(Station s1, Station s2){
    return s1.distance < s2.distance;
}

void Travel(int cur_sta, double cur_dis, double cur_oil, double cur_cost){
    int next_sta = cheapSta[cur_sta];

    //到达目的地
    if(cur_sta==N){
        res_dis = cur_dis;
        res_cost = cur_cost;
        return;
    }

    //若到下一个站的距离大于当前距离加满油距离，返回当前距离加满油距离
    if(next_sta<0){
        res_dis = cur_dis+CD;
        res_cost = cur_cost + Cmax*sta[cur_sta].price;
        canReach = false;
        return;
    }


    double dis = sta[next_sta].distance - cur_dis;//到下一车站的距离
    double oil = dis / Davg;//到下一车站的油量
    //若下一站的价格比当前站低，加油使得刚好开到下一站
    if(sta[next_sta].price < sta[cur_sta].price){
        //若当前油箱的油不够，花钱加油，否则不用
        if(cur_oil < oil){
            cur_cost += (oil - cur_oil) * sta[cur_sta].price;
            cur_oil  = oil;
        }
        Travel(next_sta, sta[next_sta].distance, cur_oil-oil, cur_cost);
    }else{//下一站的价格比当前站价格高，在当前站加满油过去
        cur_cost += (Cmax-cur_oil) * sta[cur_sta].price;
        Travel(next_sta, sta[next_sta].distance, Cmax-oil, cur_cost);
    }


}

int main(){
    cin >> Cmax >> D >> Davg >> N;
    CD = Cmax * Davg;
    for(int pos=0; pos<N; pos++){
        cin >> sta[pos].price >> sta[pos].distance;
    }
    sta[N].distance = D;
    sta[N].price = 0;
    sort(sta, sta+N+1, disCompare);//根据距离排序

    //起始位置没有加油站，直接输出最大距离0；
    if(sta[0].distance>0){
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }

    for(int cur_sta=0; cur_sta<N; cur_sta++){
        int CD_dis = sta[cur_sta].distance + CD;//cur_sta开始满油能跑到的距离
        int i = cur_sta + 1;
        double min_price = MAX;//最低油价
        int cheap_sta = -1;//最低油价的站,-1表示满油开不到
        while(sta[i].distance<=CD_dis && i<=N){
            if(sta[i].price<sta[cur_sta].price){//若找到第一个比当前站更低价格的油站，直接更新cheapSta
                min_price = sta[i].price;
                cheap_sta = i;
                break;
            }
            if(sta[i].price<min_price){
                min_price = sta[i].price;
                cheap_sta = i;
            }
            i++;
        }
        cheapSta[cur_sta] = cheap_sta;
        
    }


    Travel(0, 0, 0, 0);

    if(canReach){
        printf("%.2f", res_cost);
    }else{
        printf("The maximum travel distance = %.2f", res_dis);
    }

    return 0;

}
