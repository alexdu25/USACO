#include <iostream>
using namespace std;
int n,m,input[100001];
bool possible(int maxcost){
    int counter=1,currentsum=0;
    for(int i=0;i<n;i++){
        if(currentsum+input[i]>maxcost){
            if((counter==m)){
                return false;
            }
            if(input[i]<=maxcost){
                counter++;
                currentsum=input[i];
            }
            else if(input[i]>maxcost){
                return false;
            }
        }
        else{
            currentsum=currentsum+input[i];
        }
    }
    return true;
}
int binarysearch(int lower,int upper){
    while(lower!=upper){
        if(lower==upper-1){
            if(possible(lower)==true){
                return lower;
            }
            else{
                return upper;
            }
        }
        int newbound=((upper+lower+1)/2);
        if(possible(newbound)==true){
            return binarysearch(lower,newbound);
        }
        if(possible(newbound)==false){
            return binarysearch(newbound,upper);
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    cout << binarysearch(0,1000000000);
}
/*
Problem Statement:
Monthly Expense
===============

Farmer John is an astounding accounting wizard and has realized he
might run out of money to run the farm. He has already calculated
and recorded the exact amount of money (1 <= money_i <= 10,000) that
he will need to spend each day over the next N (1 <= N <= 100,000) days.

FJ wants to create a budget for a sequential set of exactly M
(1 <= M <= N) fiscal periods called "fajomonths". Each of these
fajomonths contains a set of 1 or more consecutive days. Every day
is contained in exactly one fajomonth.

FJ's goal is to arrange the fajomonths so as to minimize the expenses
of the fajomonth with the highest spending and thus determine his
monthly spending limit.

PROBLEM NAME: expense

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Line i+1 contains the number of dollars Farmer John
        spends on the ith day

SAMPLE INPUT:

7 5
100
400
300
100
500
101
400

OUTPUT FORMAT:

* Line 1: The smallest possible monthly limit Farmer John can afford
        to live with.

SAMPLE OUTPUT:

500

OUTPUT DETAILS:

If Farmer John schedules the months so that the first two days are a
month, the third and fourth are a month, and the last three are their
own months, he spends at most $500 in any month. Any other method of
scheduling gives a larger minimum monthly limit.
*/
