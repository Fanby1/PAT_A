#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    int student_num,class_num;
    cin >> student_num >> class_num;
    set<int> classes;
    map<string,set<int>> students;
    for(int i = 0;i < class_num;++i){
        int class_name,num;
        cin >> class_name;
        cin >> num;
        for(int j = 0;j < num;++j){
            string student_name;
            cin >> student_name;
            if(students.find(student_name) != students.end()){
                (*students.find(student_name)).second.insert(class_name);
            }else{
                set<int> a;
                a.insert(class_name);
                students.insert({student_name,a});
            }
        }
    }
    for(int i = 0;i < student_num;++i){
        string name;
        cin >> name;
        cout << name;
        if(students.find(name) != students.end()){
            auto vessel = (*students.find(name)).second;
            cout << " " << vessel.size();
            for(auto a : vessel){
                cout << " " << a;
            }
        }else{
            cout << " " << '0';
        }

        cout << endl;
    }
}