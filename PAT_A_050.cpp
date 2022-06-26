/*
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int> test, int stack_len){
    int max = stack_len;
    for(int i = 0; i < test.size(); ++i){
        if(test[i] > max){
            return false;
        }
        max++;
    }
    return true;
}

int main(){
    int stack_len,orders,tests;
    cin >> stack_len >> orders >> tests;
    for(int i = 0;i < tests;++i){
        vector<int> test;
        test.resize(orders);
        for(int j = 0; j < orders;++j){
            cin >> test[j];
        }
        if(check(test,stack_len)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#define MAX 999999999
using namespace std;
int n,m,k;
int main()
{
    stack<int>s;
    cin>>m>>n>>k;
    while(k--)//top>x则是NO  top<x插入到x位置
    {
        while(!s.empty())
            s.pop();
        int cnt = 1;
        int a[n];
        for(int i = 0;i<n;i++)
            cin>>a[i];
        int flag = 0;
        for(int i = 0;i<n;i++){
            while((s.size() == 0 || s.top() < a[i]) && cnt<=n)
                s.push(cnt++);
            if(s.size() > m || s.top() > a[i])
            {
               flag = 1; break;
            }
            if(s.top() == a[i])
                s.pop();
            if(flag == 1)break;
        }
        if(flag == 1)
            cout<<"NO\n";
        else
            cout<<"YES\n";

    }
    return 0;
}
