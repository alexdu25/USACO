#include <fstream>
using namespace std;
ifstream fin ("leftout.in");
ofstream fout ("leftout.out");
int n,l,r,ansx,ansy,counter;
char input[1001][1001],temp[1001][1001];
int main(){
    fin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fin >> input[i][j];
            temp[i][j]=input[i][j];
            if(temp[i][j]=='L'){
                l++;
            }
            else{
                r++;
            }
        }
    }
    if(l<=1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(input[i][j]=='L'){
                    fout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    if(r<=1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(input[i][j]=='R'){
                    fout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    while(true){//go for R
        bool z=false;
        if(l==1){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(temp[i][j]=='L'){
                        fout << i+1 << " " << j+1 << endl;
                        return 0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            counter=0;
            for(int j=0;j<n;j++){
                if(temp[i][j]=='L'){
                    counter++;
                }
            }
            if(counter>n/2){
                z=true;
                for(int j=0;j<n;j++){
                    if(temp[i][j]=='R'){
                        temp[i][j]='L';
                        ansx=i; ansy=j;
                        l++;
                    }
                    else{
                        temp[i][j]='R';
                        l--;
                    }
                }
            }
        }
        if(l==1){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(temp[i][j]=='L'){
                        fout << i+1 << " " << j+1 << endl;
                        return 0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            counter=0;
            for(int j=0;j<n;j++){
                if(temp[j][i]=='L'){
                    counter++;
                }
            }
            if(counter>n/2){
                z=true;
                for(int j=0;j<n;j++){
                    if(temp[j][i]=='R'){
                        temp[j][i]='L';
                        l++;
                        ansx=i; ansy=j;
                    }
                    else{
                        temp[j][i]='R';
                        l--;
                    }
                }
            }
        }
        if(z==false){
            break;
        }
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fout << temp[i][j] << " ";
        }
        fout << endl;
    }
    */
    fout << "-1" << endl;
}
