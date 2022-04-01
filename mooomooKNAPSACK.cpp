#include <bits/stdc++.h>
using namespace std;
int n,b,weight[21],knapsack[101],dp[100001],ans;
int main(){
    cin >> n >> b;
    for(int i=1;i<=b;i++){
        cin >> weight[i];
    }
    for(int i=1;i<=n;i++){
        cin >> knapsack[i];
    }
    for(int i=n;i>1;i--){
        if(knapsack[i-1]!=0){
            knapsack[i]-=knapsack[i-1]-1;
        }
    }
    for(int i=0;i<100001;i++){
        dp[i]=1000000000;
    }
    dp[0]=0;
    for(int i=1;i<=b;i++){
        dp[weight[i]]=1;
    }
    for(int i=1;i<=b;i++){
        for(int j=0;j<100001;j++){
            if(dp[j]!=0){
                if(j+weight[i]<100001){
                    dp[j+weight[i]]=min(dp[j+weight[i]],dp[j]+1);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans+=dp[knapsack[i]];
    }
    cout << ans;
}
/*
Problem Statement:
Mooo Moo
========

Farmer John has completely forgotten how many cows he owns!  He is too
embarrassed to go to his fields to count the cows, since he doesn't want
the cows to realize his mental lapse.  Instead, he decides to count his
cows secretly by planting microphones in the fields in which his cows tend
to gather, figuring that he can determine the number of cows from the total
volume of all the mooing he hears.

FJ's N fields (1 <= N <= 100) are all arranged in a line along a long
straight road.  Each field might contain several types of cows; FJ
owns cows that come from B different breeds (1 <= B <= 20), and a cow
of breed i moos at a volume of V(i) (1 <= V(i) <= 100).  Moreover,
there is a strong wind blowing down the road, which carries the sound
of mooing in one direction from left to right: if the volume of mooing
in some field is X, then in the next field this will contribute X-1 to
the total mooing volume (and X-2 in the field after that, etc.).
Otherwise stated, the mooing volume in a field is the sum of the
contribution due to cows in that field, plus X-1, where X is the total
mooing volume in the preceding field.

Given the volume of mooing that FJ records in each field, please compute
the minimum possible number of cows FJ might own.

The volume FJ records in any field is at most 100,000.

PROBLEM NAME: mooomoo

INPUT FORMAT:

* Line 1: The integers N and B.

* Lines 2..1+B: Line i+1 contains the integer V(i).

* Lines 2+B..1+B+N: Line 1+B+i contains the total volume of all mooing
        in field i.

SAMPLE INPUT:

5 2
5
7
0
17
16
20
19

INPUT DETAILS:

FJ owns 5 fields, with mooing volumes 0,17,16,20,19.  There are two breeds
of cows; the first moos at a volume of 5, and the other at a volume of 7.

OUTPUT FORMAT:

* Line 1: The minimum number of cows owned by FJ, or -1 if there is no
        configuration of cows consistent with the input.

SAMPLE OUTPUT:

4

OUTPUT DETAILS:

There are 2 cows of breed #1 and 1 cow of breed #2 in field 2, and there is
another cow of breed #1 in field 4.
*/
