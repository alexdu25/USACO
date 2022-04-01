#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin ("closing.in");
ofstream fout ("closing.out");
int n,m,a,b;
vector<int> v[3001];
bool visited[3001],gone[3001];
bool bfs(int startx,int starty){
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    queue<int> current;
    current.push(v[startx][starty]);
    while(!current.empty()){
        visited[current.front()]=true;
        for(int i=0;i<v[current.front()].size();i++){
            if(visited[v[current.front()][i]]==false&&gone[v[current.front()][i]]==false){
                current.push(v[current.front()][i]);
            }
        }
        current.pop();
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false&&gone[i]==false){
            return false;
        }
    }
    return true;
}
int main(){
    fin >> n >> m;
    for(int i=0;i<m;i++){
        fin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int z=0;
            for(int k=0;k<v[j].size();k++){
                if(gone[v[j][k]]==false){
                    if(bfs(j,k)==true){
                        fout << "YES" << endl;
                    }
                    else{
                        fout << "NO" << endl;
                    }
                    z=1;
                    break;
                }
            }
            if(z==1){
                break;
            }
            if(j==n-1){
                fout << "NO" << endl;
            }
        }
        fin >> temp; temp--;
        gone[temp]=true;
    }
}
