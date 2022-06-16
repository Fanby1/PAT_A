#include <iostream>

using namespace std;

int main(){
    int n,m,k,q,i;
    cin >> n >> m >> k >> q;
    int in_line[n] = {0};
    int end_time[k] = {0};
    int end_line[n] = {0};

    for(i = 0;i < n * m;i++){
        int time;
        cin >> time;
        end_line[i % n] += time;
        in_line[i % n]++;
        end_time[i] = end_line[i % n];
    }

    for(;i < k;i++){
        int time;
        cin >> time;
        int line = -1;
        int people = m;

        int min = 10000;
        for(size_t j = 0;j < n;j++){
            if(end_line[j] < min){
                min = end_line[j];
                line = j;
            }
        }
        end_line[line] += time;
        end_time[i] = end_line[line];
    }

    for (size_t j = 0; j < q; j++)
    {
        int client;
        cin >> client;
        client--;
        if(end_time[client] > 60 * 9){
            cout << "Sorry" << endl;
        }
        else if(end_time[client] / 60 < 2){
            cout << '0' << end_time[client] / 60 + 8 << ':' << end_time[client] % 60<< endl;
        }else{
            cout << end_time[client] / 60 + 8 << ':' << end_time[client] % 60<< endl;
        } 
    }
}