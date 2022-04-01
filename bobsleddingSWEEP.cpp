#include <bits/stdc++.h>
using namespace std;
int l,n,maxspeed[100002],ans,x;
struct point{
    int x,speedlimit;
};
point input[100002];
bool comp(point a,point b){
    return a.x<b.x;
}
int calculate(int index){
    int diff=input[index].x-input[index-1].x;
    if(maxspeed[index-1]+diff<=maxspeed[index]) return maxspeed[index-1]+diff;
    int newright=input[index].x+maxspeed[index],newleft=input[index-1].x-maxspeed[index-1];
    return (newright-newleft)/2;
}
int main(){
    cin >> l >> n;
    input[0].x=0; input[0].speedlimit=1e9; input[n+1].x=l; input[n+1].speedlimit=1e9;
    for(int i=1;i<=n;i++){
        cin >> input[i].x >> input[i].speedlimit;
    }
    maxspeed[n+1]=1e9;
    sort(input+1,input+n+1,comp);
    for(int i=n;i>0;i--){
        maxspeed[i]=min(maxspeed[i+1]+(input[i+1].x-input[i].x),input[i].speedlimit);
    }
    maxspeed[0]=1;
    for(int i=1;i<=n;i++){
        x=calculate(i);
        ans=max(ans,x);

    }
    ans=max(ans,x+(l-input[n].x));
    cout << ans;
}
/*
Problem Statement:
Bobsledding
===========

Bessie has entered a bobsled competition because she hopes her hefty
weight will give her an advantage over the L meter course (2 <= L
<= 1,000,000,000).

Bessie will push off the starting line at 1 meter per second, but
her speed can change while she rides along the course. Near the
middle of every meter Bessie travels, she can change her speed
either by using gravity to accelerate by one meter per second or
by braking to stay at the same speed or decrease her speed by one
meter per second.

Naturally, Bessie must negotiate N (1 <= N <= 100,000) turns on the
way down the hill. Turn i is located T_i meters from the course
start (1 <= T_i <= L-1), and she must be enter the corner meter at
a speed of at most S_i meters per second (1 <= S_i <= 1,000,000,000).
Bessie can cross the finish line at any speed she likes.

Help Bessie learn the fastest speed she can attain without exceeding
the speed limits on the turns.

Consider this course with the meter markers as integers and the
turn speed limits in brackets (e.g., '[3]'):

|   1   2   3   4   5   6   7[3]
|---+---+---+---+---+---+---+
|                            \
Start                         + 8
                               \
                                + 9
                                 \
                                  + 10       +++ 14 (finish)
                                   \         /
                              11[1] +---+---+
                                        12  13[8]

Below is a chart of Bessie's speeds at the beginning of each meter length
of the course:

Max:                              3               1       8
Mtrs: 0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
Spd:  1   2   3   4   5   5   4   3   4   3   2   1   2   3   4

Her maximum speed was 5 near the beginning of meter 4.

PROBLEM NAME: bobsled

INPUT FORMAT:

* Line 1: Two space-separated integers: L and N

* Lines 2..N+1: Line i+1 describes turn i with two space-separated
        integers: T_i and S_i

SAMPLE INPUT:

14 3
7 3
11 1
13 8

OUTPUT FORMAT:

* Line 1: A single integer, representing the maximum speed which
        Bessie can attain between the start and the finish line,
        inclusive.

SAMPLE OUTPUT:

5
*/
