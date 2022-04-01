#include <iostream>
using namespace std;
int n,k,a[1001][101],ans;
int dp(int remaining, int index){//remaining is how much money left, index is how many integers left to choose from, if index = 3,means possible recursions are 1,2,3
    if(index==1){
        return 1;
    }
    if(a[remaining][index]!=0){
        return a[remaining][index];
    }
    int cases=0;
    for(int i=0;;i+=index){
        if(remaining-i>=0){
            cases+=dp(remaining-i,index-1);
        }
        else{
            break;
        }
    }
    a[remaining][index]=cases;
    return cases;
}
int main(){
    cin >> n >> k;
    cout << dp(n,k);
}
/*
Problem Statement:
Dollar Dayz
===========

Farmer John goes to Dollar Days at The Cow Store and discovers an
unlimited number of tools on sale. During his first visit, the tools
are selling variously for $1, $2, and $3. Farmer John has exactly
$5 to spend. He can buy 5 tools at $1 each or 1 tool at $3 and an
additional 1 tool at $2. Of course, there are other combinations
for a total of 5 different ways FJ can spend all his money on tools.
Here they are:

        1 @ US$3 + 1 @ US$2
        1 @ US$3 + 2 @ US$1
        1 @ US$2 + 3 @ US$1
        2 @ US$2 + 1 @ US$1
        5 @ US$1

Write a program than will compute the number of ways FJ can spend
N dollars (1 <= N <= 1000) at The Cow Store for tools on sale with
a cost of $1..$K (1 <= K <= 100).

PROBLEM NAME: ddayz

INPUT FORMAT:

A single line with two space-separated integers: N and K.

SAMPLE INPUT:

5 3

OUTPUT FORMAT:

A single line with a single integer that is the number of unique ways
FJ can spend his money.

SAMPLE OUTPUT:

5
*/
