
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int m,num;
    cin >> m;
    vector<int> v;
    for (int i = 0;i < m;i++)
    {
        scanf("%d",&num);
        v.push_back(num);
    }
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        scanf("%d", &num);
        v.push_back(num);
    }//0 1 2 3 
    //0 1 2
    sort(v.begin(), v.end());
    cout << v[(v.size()-1)/2];
    return 0;
}
