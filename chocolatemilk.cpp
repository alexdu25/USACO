#include <iostream>
using namespace std;
int n,input[100001][2],lastmergeindex=1,firstsplitindex=1,indegree[100001],outdegree[100001];
int main(){
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> input[i][0] >> input[i][1];
        indegree[input[i][1]]++;
        outdegree[input[i][0]]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]>1){
            lastmergeindex=i;
            firstsplitindex=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(outdegree[i]>1&&i>lastmergeindex){
            firstsplitindex=i;
            break;
        }
    }
    for(int i=lastmergeindex;i<=firstsplitindex;i++){
        if(i!=1){
            cout << i << endl;
        }
    }
}
