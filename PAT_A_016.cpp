#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct customer{
  string name;
  int month,day,hour,min,time,status;//考虑好哪些因素，比如cost和total不在结构体里
};
bool cmp(customer a,customer b){
  return a.name==b.name?a.time<b.time:a.name<b.name;
}

double count(customer call,int *cost){
  double total=cost[call.hour]*call.min+call.day*cost[24]*60;
  for(int i=0;i<call.hour;i++){
    total+=cost[i]*60;
  }
  
  return total/100.0;
}
int main(){
  int cost[25]={0};
  for(int i=0;i<24;i++){
    scanf("%d",&cost[i]);
    cost[24]+=cost[i];
  }
  int n;
  scanf("%d",&n);
  vector<customer> cus(n);
  for(int i=0;i<n;i++){
    //不能数据类型分开输入
    cin>>cus[i].name;
    scanf("%02d:%02d:%02d:%02d",&cus[i].month,&cus[i].day,&cus[i].hour,&cus[i].min);
    string temp;
    cin>>temp;
    cus[i].status=(temp=="on-line")?1:0;//这样可以少用if了
    //因为date的数据都在里面，可以顺便算个通话时间,后面是用挂电话分钟数-接电话分钟数
    cus[i].time=cus[i].day*24*60+cus[i].hour*60+cus[i].min;
  }
  sort(cus.begin(),cus.end(),cmp);
  map<string,vector<customer>> result;
  for(int i=1;i<n;i++){
    if(cus[i].name==cus[i-1].name&&cus[i-1].status==1&&cus[i].status==0){
      result[cus[i-1].name].push_back(cus[i-1]);
      result[cus[i].name].push_back(cus[i]);
    }
    
  }
  // 输出
  for(auto it:result){
   // vector auto::iterator it;
    vector<customer> temp=it.second;//加入map的倒入新的vector遍历完准备输出
    //printf(*it.first);
    cout<<it.first;
    printf(" %02d\n",temp[0].month);
    double total=0.0;
    for(int i=1;i<temp.size();i+=2){
      double t=count(temp[i],cost)-count(temp[i-1],cost);
      printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",temp[i-1].day,temp[i-1].hour,temp[i-1].min,temp[i].day,temp[i].hour,temp[i].min,temp[i].time-temp[i-1].time,t);
      total+=t;
    }
    printf("Total amount: $%.2f\n",total);
    
  }
  return 0;
}
