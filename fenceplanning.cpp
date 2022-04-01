#include <fstream>
#include <vector>
using namespace std;
ifstream fin ("fenceplan.in");
ofstream fout ("fenceplan.out");
int n,m,input[100001][2],a,b,minx,maxx,miny,maxy,ans=1e9;//input[i] stores x & y of point i;
vector<int> v[100001];
bool visited[100001];
void dfs(int currentindex){
    visited[currentindex]=true;
    minx=min(minx,input[currentindex][0]);
    maxx=max(maxx,input[currentindex][0]);
    miny=min(miny,input[currentindex][1]);
    maxy=max(maxy,input[currentindex][1]);
    for(int i=0;i<v[currentindex].size();i++){
        if(visited[v[currentindex][i]]==false){
            dfs(v[currentindex][i]);
        }
    }
}
int main(){
    fin >> n >> m;
    for(int i=1;i<=n;i++){
        fin >> input[i][0] >> input[i][1];
    }
    for(int i=1;i<=m;i++){
        fin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            maxx=0; maxy=0; minx=1e9; miny=1e9;
            dfs(i);
            int perimeter=(maxx-minx)+(maxy-miny);
            perimeter*=2;
            //fout << "i: " << i << " perimeter: " << perimeter << endl;
            ans=min(ans,perimeter);
        }
    }
    fout << ans;
}
