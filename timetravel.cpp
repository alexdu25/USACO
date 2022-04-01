#include <iostream>
using namespace std;
struct nodething{
    int value;
    bool travel;
};
int n,parentnodeindex[80001];//index is the query number
nodething node[80001];
int main(){
    cin >> n;
    char c;
    int currentindex=-1,input,previousindex=-1;
    node[0]=-1;
    parentnodeindex[0]=-1; parentnodeindex[1]=-1;
    for(int i=1;i<=n;i++){
        cin >> c;
        if(c=='a'){
            cin >> input;
            node[i].value=input;
            parentnodeindex[i]=currentindex;
            currentindex=i;
        }
        if(c=='s'){
            while(true){
                if(node[currentindex].travel==true){
                    currentindex=parentnodeindex[node[currentindex].value];
                }
                else{
                    currentindex=parentnodeindex[currentindex];
                    node[i].value=node[currentindex].value;
                    if(node[currentindex].travel==false){
                        break;
                    }
                }
            }
        }
        if(c=='t'){
            cin >> input;
            node[i].value=input-1;
            node[i].travel=true;
            currentindex=input-1;
        }
        if(node[currentindex]==0){
            cout << "-1" << endl;
        }
        else{
            cout << node[currentindex].value << endl;
        }
    }
}

