#include <iostream>
using namespace std;
int sortedarray[1000];
bool binarysearch(int query,int arraysize){
    int upper=arraysize;
    int lower=-1;
    while(lower!=upper){
        int newbound=((upper+lower+1)/2);
        if(sortedarray[newbound]==query){
            return true;
        }
        if(sortedarray[newbound]<=query){
            lower=newbound;
        }
        else{
            upper=newbound-1;
        }
    }
    return false;
}
int main(){
    for(int i=0;i<1000;i++){
        sortedarray[i]=i;
    }
    cout << binarysearch(0,1000);
}
