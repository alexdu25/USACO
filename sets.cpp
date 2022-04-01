#include <iostream>
#include <set>
#include <iterator>
using namespace std;
int main(){
    set<int, greater<int> > s;
    s.insert(10);
    s.insert(1);
    s.insert(3);
    s.insert(5);
    s.erase(s.find(3));
    if(s.find(7)==s.end()){
        cout << "not found" << endl;
    }
    set<int, greater <int> > :: iterator itr;
    for(itr=s.begin();itr!=s.end();itr++){
        cout << *itr << endl;
    }
    multiset<int> mset;
    for(int i=0;i<10;i++){
        mset.insert(10-i);
    }
    mset.insert(100);
    mset.erase(100);
    cout << mset.size() << endl;
    for(int i=0;i<10;i++){
        if(mset.find(i)!=mset.end()){
            cout << i << " is in the set" << endl;
        }
    }
    multiset<int> :: reverse_iterator itr2;
    itr2=mset.rbegin();
    cout << *itr2 << endl;
}
