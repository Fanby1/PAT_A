#include <iostream>
#include <vector>
#include <algorithm>

#define SORT(a) sort(a.begin(),a.end())
#define CALCULATE(long,short,result) for(int i = 0;i < short.size();++i){result += long[long.size() - i - 1] * short[short.size() - i - 1];}

using namespace std;

int calculation(vector<int> coupon, vector<int> product){
    int result = 0;
    if(coupon.size() < product.size()){
        CALCULATE(product,coupon,result)
    }else{
        CALCULATE(coupon,product,result)
    }
    return result;
}

int main(){
    int coupon,product;
    cin >> coupon;
    vector<int> coupons_p,coupons_v;
    for(int i = 0;i < coupon;++i){
        int value;
        cin >> value;
        if(value > 0){
            coupons_p.push_back(value);
        }else{
            coupons_v.push_back(-value);
        }
    }
    cin >> product;
    vector<int> products_p,products_v;
    for(int i = 0;i < product;++i){
        int value;
        cin >> value;
        if(value > 0){
            products_p.push_back(value);
        }else{
            products_v.push_back(-value);
        }
    }
    SORT(coupons_p);
    SORT(coupons_v);
    SORT(products_p);
    SORT(products_v);
    cout << calculation(coupons_p,products_p) + calculation(coupons_v,products_v) << endl;
}