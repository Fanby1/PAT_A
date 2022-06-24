/*
这是快速写出来的普通算法。问题在于标准库的速度太慢，没有写出没人选的课
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    int class_num,stu_num;

    cin >> class_num >> stu_num;
    map<int,set<string>> pool;

    for(int i = 0;i < class_num;++i){
        string cla;
        cin >> cla;
        int num;
        cin >> num;
        for(int j = 0;j < num;++j){
            int stu;
            cin >> stu;
            pool[stu].insert(cla);
        }
    }
    for(auto a : pool){
        cout << a.first << " " << a.second.size() << endl;
        for(auto b : a.second){
            cout << b << endl;
        }
    }
}
*/

/*
用了两重的vector。可惜还是不够快，解决了课没人选的问题。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int stu_num,cla_num;
    cin >> stu_num >> cla_num;
    vector<vector<string>> pool;
    pool.resize(cla_num);
    for(int i = 0;i < stu_num;++i){
        string stu;
        int num;
        cin >> stu >> num;
        for(int j = 0;j < num;++j){
            int cla;
            cin >> cla;
            pool[cla - 1].push_back(stu);
        }
    }
    for(int i = 0;i < pool.size();++i){
        sort(pool[i].begin(),pool[i].end());
        cout << i + 1 << " " << pool[i].size() << endl;
        for(auto a : pool[i]){
            cout << a << endl;
        }
    }
}
*/

/*奇思妙想的时间换空间，快确实快，但是内存超限屁用没有。
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define MAX_STU_NUM 26 * 26 * 26 * 10

using namespace std;

bool pool[2500][MAX_STU_NUM] = {false};

int main(){
    int stu_num, cla_num;
    cin >> stu_num >> cla_num;
    int count[cla_num] = {0};
    for(int i = 0;i < stu_num;++i){
        string name;
        int stu = 0;
        cin >> name;
        for(int j = 0;j < name.size() - 1;++j){
            stu += (name[j] - 'A') * pow(26,2 - j) * 10;
        }
        stu += name[3] - '0';
        int num;
        cin >> num;
        for(int j = 0;j < num;++j){
            int cla;
            cin >> cla;
            pool[cla - 1][stu] = true;
            count[cla - 1] += 1;
        }
    }
    for(int i = 0;i < cla_num;++i){
        cout << i + 1 << " " << count[i] << endl;
        for(int j = 0;j < MAX_STU_NUM;++j){
            if(pool[i][j]){
                string name = "";
                int stu = j;
                name = to_string(stu % 10);
                stu /= 10;
                for(int k = 0;k < 3;++k){
                    name = char('A' + stu % 26) + name;
                    stu /= 26;
                }
                cout << name << endl;
            }
        }
    }
}
*/


//从网上抄了一个解答，总结：我是伞兵，没看清题目条件以为学生姓名是乱序的。
#include <bits/stdc++.h>

using namespace std;
const int maxs=40010;
const int maxc=2510;
char name[maxs][5];//存放学生姓名
vector<int> course[maxc];
bool cmp(int a,int b)
{
    return strcmp(name[a],name[b])<0;//按姓名字典序从小到大排序
}
int main()
{
    int n,k,c,cid;
    scanf("%d%d",&n,&k);//学生人数及课程数
    for(int i=0; i<n; i++)
    {
        scanf("%s%d",name[i],&c);//学生姓名及选课数
        for(int j=0; j<c; j++)
        {
            scanf("%d",&cid);
            course[cid].push_back(i);//将学生i加入第courseid门课中
        }
    }
    for(int i=1; i<=k; i++)
    {
        printf("%d %d\n",i,course[i].size());
        sort(course[i].begin(),course[i].end(),cmp);//对第i门课程的学生进行排序
        for(int j=0; j<course[i].size(); j++)
        {
            printf("%s\n",name[course[i][j]]);//输出学生姓名，其中i表示第i门课程，j表示这个课程的第i个学生。通过下标来找到对应nam中的名字；
        }
    }
    return 0;
}

