#include <iostream>
#include <queue>
using namespace std;
typedef pair <int,int> p;
int main(){
    priority_queue< p, vector<p>, greater<p> > pq;
    int j=10;
    for(int i=0;i<10;i++){
        pq.push(make_pair(i,j));
        j--;
    }
    pq.push(make_pair(10,0));
    pq.push(make_pair(9,3));
    pq.push(make_pair(10,11));
    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
}
