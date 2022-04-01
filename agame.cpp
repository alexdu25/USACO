#include <iostream>
using namespace std;
int n;
int input[101];
int dp1[101][101],dp2[101][101];//stores max score of player1,player2 from time start to time end;
void loop(void){
    for(int i=0;i<n;i++){
        for(int k=1;k<n;k++){
            int j=i+k;
            if (j>=n) {
                break;
            }
            if(input[j]+dp2[i][j-1]>input[i]+dp2[i+1][j]){//take left
                dp1[i][j]=input[j]+dp2[i][j-1];
                dp2[i][j]=dp1[i][j-1];
            }
            else{//take right
                dp1[i][j]=input[i]+dp2[i+1][j];
                dp2[i][j]=dp1[i+1][j];
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    for(int i=0;i<n;i++){
        dp1[i][i]=input[i];
        dp2[i][i]=0;
    }
    loop();
    cout << dp1[0][n-1] << " "<< dp2[0][n-1] << endl;
}
