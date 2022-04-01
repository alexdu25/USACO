#include <iostream>
#include <vector>
using namespace std;
int testans;
string a[2000];
void test(int p1,int p2){
    if(p1>p2){
        return;
    }
    if(a[p1+1]<a[p2-1]){
        testans=1;
    }
    else if(a[p1+1]>a[p2-1]){
        testans=2;
    }
    else if(a[p1+1]==a[p2-1]){
        return test(p1+1,p2-1);
    }
}
int main(){
    int first=0,last,n;
    cin >> n;
    last=n-1;
    vector<string> ans;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    while(first<=last){
        //cout << "first: " << first << " last: " << last << endl;
        if(a[first]<a[last]){
            ans.push_back(a[first]);
            first++;
        }
        if(a[first]>a[last]){
            ans.push_back(a[last]);
            last--;
        }
        if(a[first]==a[last]){
            test(first,last);
            if(testans==1){
                ans.push_back(a[first]);
                first++;
            }
            else{
                ans.push_back(a[last]);
                last--;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i];
        if((i+1)%80==0){
            cout << endl;
        }
    }
}
/*
Problem Statement:
Best Cow Line
=============

FJ is about to take his N (1 <= N <= 2,000) cows to the annual
"Farmer of the Year" competition. In this contest every farmer
arranges his cows in a line and herds them past the judges.

The contest organizers adopted a new registration scheme this year:
simply register the initial letter of every cow in the order they
will appear (i.e., If FJ takes Bessie, Sylvia, and Dora in that
order he just registers BSD). After the registration phase ends,
every group is judged in increasing lexicographic order according
to the string of the initials of the cows' names.

FJ is very busy this year and has to hurry back to his farm, so he
wants to be judged as early as possible. He decides to rearrange
his cows, who have already lined up, before registering them.

FJ marks a location for a new line of the competing cows. He then
proceeds to marshal the cows from the old line to the new one by
repeatedly sending either the first or last cow in the (remainder
of the) original line to the end of the new line. When he's finished,
FJ takes his cows for registration in this new order.

Given the initial order of his cows, determine the least lexicographic
string of initials he can make this way.

PROBLEM NAME: bcl

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single initial ('A'..'Z') of the
        cow in the ith position in the original line

SAMPLE INPUT:

6
A
C
D
B
C
B

INPUT DETAILS:

FJ has 6 cows in this order: ACDBCB

OUTPUT FORMAT:

The least lexicographic string he can make. Every line (except perhaps
the last one) contains the initials of 80 cows ('A'..'Z') in the new
line.

SAMPLE OUTPUT:

ABCBCD

OUTPUT DETAILS:

  Step   Original     New
   #1     ACDBCB
   #2      CDBCB     A
   #3      CDBC      AB
   #4      CDB       ABC
   #5      CD        ABCB
   #6       D        ABCBC
   #7                ABCBCD
*/
