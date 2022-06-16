#include <iostream>
#include <array>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Vector
{
private:
    float* vessel;
    int max;
public:
    Vector();
    Vector(float* v, int m){
        vessel = new float[m];
        for(int i = 0;i < m;i++){
            vessel[i] = v[i];
        }
        max = m;
    }
    ~Vector();

    float* getVessel(){
        return vessel;
    }
    int getMax(){
        return max;
    }

    void setMax(int m){
        max = m;
    }

    Vector operator* (Vector &a);

    string tostring();
};

Vector::Vector()
{
}

Vector::~Vector()
{
}

Vector Vector::operator* (Vector &a){
    float newvessel[max + a.max] = {0};
    for(int i = 0;i < this->max;i++){
        for(int j = 0;j < a.max;j++){
            if(this->vessel[i] != 0 && a.vessel[j] != 0){
                newvessel[i + j] += vessel[i] * a.vessel[j];
            }
        }
    }
    return Vector(newvessel,max + a.max);
}

string Vector::tostring(){
    bool flag = false;
    string a = "";
    int count = 0;
    for(int i = max - 1;i > -1;--i){
        if(flag){
            
            if(vessel[i] != 0){
                char* buf = new char[100];
                sprintf(buf,"%.1f",vessel[i]);
                count++;
                a += " " + to_string(i) + " " + buf;
            }
        }else{
            
            if(vessel[i] != 0){
                char* buf = new char[100];
                sprintf(buf,"%.1f",vessel[i]);
                count++;
                a += to_string(i) + " " + buf;
                flag = true;
            }
        }
    }
    return to_string(count) + " " + a;
}

Vector in(Vector &a){
    int m = 0, n = 0;
    cin >> m >> n;
    float vessel[n + 1] = {0};
    cin >> vessel[n];
    for(int i = 0;i < m - 1;i++){
        int index;
        cin >> index;
        cin >> vessel[index];
    }
    a = Vector(vessel, n + 1);
    return a;
}

int main(){
    Vector first, second;
    in(first);
    in(second);
    cout << (first * second).tostring() << endl;
}

