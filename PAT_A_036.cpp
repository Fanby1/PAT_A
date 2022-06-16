#include <iostream>
#include <vector>

using namespace std;

struct student
{
    string name = "",id = "";
    bool isMale = true;
    int score = -1;

    student(bool isMale):isMale(isMale){
        if(isMale){
            score = 101;
        }else{
            score = -1;
        }
    }
    student(string name, string id, int score, bool isMale):name(name),id(id),score(score),isMale(isMale){}

    bool operator<(student b){
        if(score < b.score){
            return true;
        }else if(score == b.score){
            return id < b.id;
        }
        return false;
    }
};

int main(){
    student male(true),famale(false);
    int num;
    cin >> num;
    for(int i = 0;i < num;++i){
        string name,id;
        char sex;
        int score;
        cin >> name >> sex >> id >> score;
        
        if(sex == 'M'){
            student n(name,id,score,true);
            if(n < male){
                male = n;
            }
        }else{
            student n(name,id,score,false);
            if(n < famale){
            }else{
                famale = n;
            }
        }
    }
    bool flag = true;
    if(famale.id == ""){
        cout << "Absent" << endl;
        flag = false;
    }else{
        cout << famale.name << " " << famale.id << endl;
    }

    if(male.id == ""){
        cout << "Absent" << endl;
        flag = false;
    }else{
        cout << male.name << " " << male.id << endl;
    }

    if(flag){
        cout << famale.score - male.score << endl;
    }else{
        cout << "NA" << endl;
    }
}