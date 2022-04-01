#include <iostream>
using namespace std;
int totalsum,n,a[251],mind=1e9,counter;
bool chosen[251];
void recurse(int index,int currentsum){
    cout << "index: " << index << " currentsum: " << currentsum << endl;
    int othersum=totalsum-currentsum;
    if(currentsum>othersum||index>=n){
        return;
    }
    int difference = othersum-currentsum;
    if(difference<mind){
        mind=difference;
        counter=1;
    }
    if(difference==mind){
        counter++;
    }
    for(int i=index;i<n;i++){
        recurse(index+1,currentsum+a[i]);
        recurse(index+1,currentsum);
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        totalsum+=a[i];
    }
    recurse(0,0);
    cout << mind << endl;
    cout << counter << endl;
}
