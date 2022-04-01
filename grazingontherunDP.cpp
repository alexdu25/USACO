#include <bits/stdc++.h>
using namespace std;
int n,l,location[1001],dp[1001][1001][2];//left, right, position;
int recurse(int leftindex,int rightindex,int lr){
    if(leftindex==rightindex) return dp[leftindex][rightindex][lr];
    if(dp[leftindex][rightindex][lr]!=1000000000) return dp[leftindex][rightindex][lr];
    if(lr==0){//left side, go right
        int first=recurse(leftindex+1,rightindex,0)+( (location[leftindex+1]-location[leftindex])*(n-rightindex+leftindex+1) );
        int second=recurse(leftindex+1,rightindex,1)+( (location[rightindex]-location[leftindex])*(n-rightindex+leftindex+1) );
        dp[leftindex][rightindex][lr]=min(first,second);
    }
    if(lr==1){
        int first=recurse(leftindex,rightindex-1,0)+( (location[rightindex]-location[leftindex])*(n-rightindex+leftindex+1) );
        int second=recurse(leftindex,rightindex-1,1)+( (location[rightindex]-location[rightindex-1])*(n-rightindex+leftindex+1) );
        dp[leftindex][rightindex][lr]=min(first,second);
    }
    return dp[leftindex][rightindex][lr];
}
int main(){
    int idx=0;
    cin >> n >> l;
    for(int i=0;i<n;i++){
        cin >> location[i];
    }
    location[n]=l;
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k]=1000000000;
            }
        }
    }
    sort(location,location+n+1);
    for(int i=0;i<=n;i++){
        if(location[i]==l){
            idx=i;
        }
    }
    dp[idx][idx][0]=0; dp[idx][idx][1]=0;
    cout << min(recurse(0,n,0),recurse(0,n,1));
}
/*
Problem Statement:
Grazing on the Run
==================

A long, linear field has N (1 <= N <= 1,000) clumps of grass at
unique integer locations on what will be treated as a number line.
Think of the clumps as points on the number line.

Bessie starts at some specified integer location L on the number
line (1 <= L <= 1,000,000) and traverses the number line in the two
possible directions (sometimes reversing her direction) in order
to reach and eat all the clumps.  She moves at a constant speed
(one unit of distance in one unit of time), and eats a clump instantly
when she encounters it.

Clumps that aren't eaten for a while get stale.  We say the
``staleness'' of a clump is the amount of time that elapses from
when Bessie starts moving until she eats a clump.  Bessie wants to
minimize the total staleness of all the clumps she eats.

Find the minimum total staleness that Bessie can achieve while
eating all the clumps.

PROBLEM NAME: ontherun

INPUT FORMAT:

* Line 1 : Two space-separated integers: N and L.

* Lines 2..N+1: Each line contains a single integer giving the
        position P of a clump (1 <= P <= 1,000,000).

SAMPLE INPUT:

4 10
1
9
11
19

INPUT DETAILS:

Four clumps: at 1, 9, 11, and 19. Bessie starts at location 10.

OUTPUT FORMAT:

* Line 1: A single integer: the minimum total staleness Bessie can
        achieve while eating all the clumps.

SAMPLE OUTPUT:

44

OUTPUT DETAILS:

Bessie can follow this route:

* start at position 10 at time 0
* move to position 9, arriving at time 1
* move to position 11, arriving at time 3
* move to position 19, arriving at time 11
* move to position 1, arriving at time 29

giving her a total staleness of 1+3+11+29 = 44.  There are other routes
with the same total staleness, but no route with a smaller one.
*/
