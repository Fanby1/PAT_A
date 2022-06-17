#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> transform(vector<string> cards, vector<int> transformer){
    vector<string> result;
    result.assign(54,"0");
    for(int i = 0;i < cards.size();++i){
        auto position = result.begin() + transformer[i] - 1;
        *position = cards[i];
    }
    return result;
}

int main(){
    vector<int> transformer;
    int times;
    vector<string> cards;

    transformer.resize(54);
    cin >> times;
    for(int i = 0;i < 54;++i){
        cin >> *(transformer.begin() + i);
    }
    for(int i = 0;i < 4;i++){
        string value;
        switch (i)
        {
        case 0:
            value = "S";
            break;
        case 1:
            value = "H";
            break;
        case 2:
            value = "C";
            break;
        case 3:
            value = "D";
        default:
            break;
        }
        for(int j = 0;j < 13;++j){
            cards.push_back(value + to_string(j + 1));
        }
    }
    cards.push_back("J1");
    cards.push_back("J2");
    for(int i = 0;i < times;i++){
        cards = transform(cards,transformer);
    }
    for(auto a : cards){
        if(a != *(cards.end() - 1)){
            cout << a << " ";
        }else{
            cout << a << endl;
        }
    }
}