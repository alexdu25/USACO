#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(){
    map<int,int> m;
    m.insert(make_pair(0,1));
    m.insert(make_pair(1,0));
    m.insert(make_pair(0,0));
    m.insert(make_pair(1,1));
    m.insert(make_pair(2,2));
    m.insert(make_pair(3,3));
    map<int,int> m2(m.begin(),m.end());//copies m to m2
    m.erase(0);
    m2.erase(m2.find(0));
    map<int,int> :: iterator itr,itr2;
    for(itr=m.begin();itr!=m.end();itr++){
        cout << itr->first << " " << itr->second << endl;
    }
    for(itr=m2.begin();itr!=m2.end();itr++){
        cout << itr->first << " " << itr->second << endl;
    }
    map<string,int> m3;
    m3["Joe"]=4;
    if(m3.find("Alex")==m3.end()){
        cout << "not found" << endl;
    }
    if(m3.find("Joe")!=m3.end()){
        cout << "found" << endl;
    }
    cout << m3["Joe"] << endl;
}
