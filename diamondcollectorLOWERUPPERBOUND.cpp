#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin ("diamond.in");
ofstream fout ("diamond.out");
int n,k,input[50001],l[50001],r[50001],ans;
int lastlesser(int q,int lower,int upper){
    while(lower!=upper){
        if(lower==upper-1){
            if(input[upper]<=q){
                return upper;
            }
            else{
                return lower;
            }
        }
        int newbound=((upper+lower+1)/2);
        if(input[newbound]>q){
            return lastlesser(q,lower,newbound);
        }
        if(input[newbound]<=q){
            return lastlesser(q,newbound,upper);
        }
    }
}
int firstgreater(int q,int lower, int upper){
    while(lower!=upper){
        if(lower==upper-1){
            if(input[lower]>=q){
                return lower;
            }
            else{
                return upper;
            }
        }
        int newbound=((upper+lower+1)/2);
        if(input[newbound]>=q){
            return firstgreater(q,lower,newbound);
        }
        if(input[newbound]<q){
            return firstgreater(q,newbound,upper);
        }
    }
}
int main(){
    fin >> n >> k;
    for(int i=0;i<n;i++){
        fin >> input[i];
    }
    sort(input,input+n);
    for(int i=0;i<n;i++){
        l[i]=i+1-firstgreater(input[i]-k,0,i);//want first number >=input[i]-k
    }
    for(int i=0;i<n;i++){
        r[i]=1+lastlesser(input[i]+k,i,n-1)-i;//want last number <=input[i]+k
    }
    int tempmax=0;
    for(int i=0;i<n;i++){
        if(l[i]>tempmax){
            tempmax=l[i];
        }
        else{
            l[i]=tempmax;
        }
    }
    tempmax=0;
    for(int i=n-1;i>=0;i--){
        if(r[i]>tempmax){
            tempmax=r[i];
        }
        else{
            r[i]=tempmax;
        }
    }
    for(int i=0;i<n-1;i++){
        int temp=l[i]+r[i+1];
        ans=max(ans,temp);
    }
    fout << ans;
}
/*
Problem Statement:
Bessie the cow, always a fan of shiny objects, has taken up a hobby of mining diamonds in her spare time! She has collected N diamonds (N≤50,000) of varying sizes, and she wants to arrange some of them in a pair of display cases in the barn.
Since Bessie wants the diamonds in each of the two cases to be relatively similar in size, she decides that she will not include two diamonds in the same case if their sizes differ by more than K (two diamonds can be displayed together in the same case if their sizes differ by exactly K). Given K, please help Bessie determine the maximum number of diamonds she can display in both cases together.

INPUT FORMAT (file diamond.in):
The first line of the input file contains N and K (0≤K≤1,000,000,000). The next N lines each contain an integer giving the size of one of the diamonds. All sizes will be positive and will not exceed 1,000,000,000.
OUTPUT FORMAT (file diamond.out):
Output a single positive integer, telling the maximum number of diamonds that Bessie can showcase in total in both the cases.
SAMPLE INPUT:
7 3
10
5
1
12
9
5
14
SAMPLE OUTPUT:
5
*/
