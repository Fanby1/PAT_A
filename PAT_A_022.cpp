#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct book
{
    string ID,name,author,publisher,publish_year;
    set<string> key_words;

    bool operator<(book a){
        if(ID < a.ID){
            return true;
        }
    }
};

map<string,set<string>> author,title,publisher,key_words,publish_years;

void insert(book a){
    if(title.find(a.name) != title.end()){
        (*title.find(a.name)).second.insert(a.ID);
    }else{
        set<string> b;
        b.insert(a.ID);
        title.insert({a.name,b});
    }
    if(author.find(a.author) != author.end()){
        (*author.find(a.author)).second.insert(a.ID);
    }else{
        set<string> b;
        b.insert(a.ID);
        author.insert({a.author,b});
    }
    if(publisher.find(a.publisher) != publisher.end()){
        (*publisher.find(a.publisher)).second.insert(a.ID);
    }else{
        set<string> b;
        b.insert(a.ID);
        publisher.insert({a.publisher,b});
    }
    if(publish_years.find(a.publish_year) != publish_years.end()){
        (*publish_years.find(a.publish_year)).second.insert(a.ID);
    }else{
        set<string> b;
        b.insert(a.ID);
        publish_years.insert({a.publish_year,b});
    }
    for(auto b : a.key_words){
        if(key_words.find(b) != key_words.end()){
            (*key_words.find(b)).second.insert(a.ID);
        }else{
            set<string> c;
            c.insert(a.ID);
            key_words.insert({b,c});
        }
    }
}

void find(string type,string value){
    switch (type[0])
    {
    case '1':
        if(title.find(value) != title.end()){
            for(auto a : (*title.find(value)).second){
                cout << a << endl;
            }
        }else{
            cout << "Not Found" << endl;
        }
        break;
    case '2':
        if(author.find(value) != author.end()){
            for(auto a : (*author.find(value)).second){
               cout << a << endl;
            }
        }else{
            cout << "Not Found" << endl;
        }
        break;
    case '3':
        if(key_words.find(value) != key_words.end()){
            for(auto a : (*key_words.find(value)).second){
                cout << a << endl;
            }
        }else{
            cout << "Not Found" << endl;
        }
        break;
    case '4':
        if(publisher.find(value) != publisher.end()){
            for(auto a : (*publisher.find(value)).second){
                cout << a << endl;
            }
        }else{
            cout << "Not Found" << endl;
        }
        break;
    case '5':
        if(publish_years.find(value) != publish_years.end()){
            for(auto a : (*publish_years.find(value)).second){
                cout << a << endl;
            }
        }else{
            cout << "Not Found" << endl;
        }
        break;
    
    default:
        break;
    }
}



int main(){
    string input;
    int num;
    getline(cin,input);
    
    for(auto a : input){
        num *= 10;
        num += a - '0';
    }
    for(int i = 0;i < num;++i){
        book a;
        getline(cin,a.ID);
        getline(cin,a.name);
        getline(cin,a.author);
        string key_words;
        getline(cin,key_words);
        string temp;
        for(auto b : key_words){
            if(b != ' '){
                temp += b;
            }else{
                a.key_words.insert(temp);
                temp.clear();
            }
        }
        a.key_words.insert(temp);
        temp.clear();
        getline(cin,a.publisher);
        getline(cin, a.publish_year);
        insert(a);
    }
    getline(cin,input);
    num = 0;
    for(auto a : input){
        num *= 10;
        num += a - '0';
    }
    for(int i = 0;i < num;++i){
        string input,type,value;
        getline(cin,input);
        bool flag = true;
        string::iterator index = input.begin();
        for(;index < input.end();index++){
            if(flag && (*index) == ' '){
                flag = false;
            }else if(flag){
                type += (*index);
            }else{
                value += (*index);
            }
        }
        cout << type << " " << value << endl;
        find(type,value);
    }
}