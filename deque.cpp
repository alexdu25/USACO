#include <iostream>
#include <deque>
using namespace std;
int main(){
    deque<int> dq;
    for(int i=0;i<10;i++){
        dq.push_back(i);
    }
    for(int i=9;i>=0;i--){
        dq.push_front(i);
    }
    deque<int> :: iterator itr;
    for(itr=dq.begin();itr!=dq.end();itr++){
        cout << *itr << " ";
    }
    cout << endl;
    dq.pop_back();
    dq.pop_front();
    for(itr=dq.begin();itr!=dq.end();itr++){
        cout << *itr << " ";
    }
    cout << endl;
    for(int i=0;i<dq.size();i++){
        cout << dq.at(i) << " ";
    }
}
