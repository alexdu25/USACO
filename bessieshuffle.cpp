#include <fstream>
#include <vector>
ifstream fin("shuffle.in");
ofstream fout("shuffle.out");
using namespace std;
int m,n,q,a[100000],query,deck[100000],deck2[100000],iterations;
void shuffle(int current,int index){
    if(remaining<m){
        return;
    }
    for(int i=0;i<m;i++){
        deck2[a[i]-1+index]=deck[a[i]-1+index];
        deck[a[i]-1+index]=deck2[i+index];
    }
    for(int i=index;i<n;i++){
        cout << deck[i] << " ";
    }
    cout << endl;
    shuffle(current*2,index+);
}
void shuffle1(void){
    for(int i=0;i<m;i++){
        deck[a[i]-1]=i+1;
        deck2[a[i]-1]=i+1;
    }
    for(int i=m;i<n;i++){
        deck[i]=i+1;
        deck2[i]=i+1;
    }
}
int main(){
    fin >> n >> m >> q;
    for(int i=0;i<m;i++){
        fin >> a[i];
    }
    iterations=n-m+1;
    shuffle1();
    shuffle(n-1,1);
    for(int i=0;i<q;i++){
        fin >> query;
        fout << deck[n-query] << endl;
    }
}
