#include <bits/stdc++.h>
using namespace std;
int n,d,input[50001],day[50001],ans[50001];
bool possible(int minhappiness){
    int currenthappiness=0,laststop=-1;
    for(int i=0;i<n;i++) day[i]=d;
    for(int i=1;i<=d;i++){
        currenthappiness/=2;
        for(int j=laststop+1;j<n;j++){
            if(currenthappiness>=minhappiness) break;
            currenthappiness+=input[j];
            day[j]=i;
            laststop=j;
        }
        if(currenthappiness<minhappiness) return false;
    }
    return true;
}
int binarysearch(int lower,int upper){
    while(lower!=upper){
        if(lower==upper-1){
            if(possible(upper)==true){
                return upper;
            }
            else{
                return lower;
            }
        }
        int newbound=((upper+lower+1)/2);
        if(possible(newbound)==false){
            return binarysearch(lower,newbound);
        }
        if(possible(newbound)==true){
            for(int i=0;i<n;i++) ans[i]=d;
            for(int i=0;i<n;i++) ans[i]=day[i];
            return binarysearch(newbound,upper);
        }
    }
}
int main(){
    cin >> n >> d;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    cout << binarysearch(0,1000000000000) << endl;
    for(int i=0;i<n;i++) cout << ans[i] << endl;
}
/*
Problem Statement:
Chocolate Eating
================

Bessie has received N (1 <= N <= 50,000) chocolates from the bulls,
but doesn't want to eat them too quickly, so she wants to plan out
her chocolate eating schedule for the next D (1 <= D <= 50,000)
days in order to maximize her minimum happiness level over the set
of those days.

Bessie's happiness level is an integer that starts at 0 and halves
(rounding down if necessary) over night as she sleeps. However,
when she eats chocolate i, her happiness level increases by integer
H_i (1 <= H_i <= 1,000,000). If she eats chocolates on a day, her
happiness for that day is considered the happiness level after she
eats the chocolates. Bessie insists that she eat the chocolates in
the order that she received them.

Consider a sequence of 5 chocolates to be eaten over a period of 5
days; they respectively bring happiness (10, 40, 13, 22, 7).

If Bessie eats the first chocolate (10 happiness) on the first day
and then waits to eat the others, her happiness level is 10 after
the first day.

Here is the complete schedule which turns out to maximize her minimum
happiness:

  Day  Wakeup happiness   Happiness from eating   Bedtime happiness
   1            0                10+40                  50
   2           25                 ---                   25
   3           12                  13                   25
   4           12                  22                   34
   5           17                   7                   24

The minimum bedtime happiness is 24, which turns out to be the best
Bessie can do.

PROBLEM NAME: ceating

INPUT FORMAT:

* Line 1: Two space separated integers: N and D

* Lines 2..N+1: Line i+1 contains a single integer: H_i

SAMPLE INPUT:

5 5
10
40
13
22
7

OUTPUT FORMAT:

* Line 1: A single integer, the highest Bessie's minimum happiness can
        be over the next D days

* Lines 2..N+1: Line i+1 contains an integer that is the day on which
        Bessie eats chocolate i

SAMPLE OUTPUT:

24
*/

