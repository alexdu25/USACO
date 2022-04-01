#include <iostream>
using namespace std;
int adjmatrix[100][100];
bool visited[100];
int dist[100];
int main(){
    int v,ans=0;
    cin >> v;
    for(int i=0;i<v;i++){
        dist[i]=1000000000;
    }
    dist[0]=0;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin >> adjmatrix[i][j];
        }
    }
    for(int i=0;i<v;i++){
        int mind=1000000000,minindex=-1;
        for(int j=0;j<v;j++){
            if(visited[j]==false&&dist[j]<mind){
                mind=dist[j];
                minindex=j;
            }
        }
        visited[minindex]=true;
        ans+=mind;
        for(int j=0;j<v;j++){
            if(visited[j]==false){
                dist[j]=min(dist[j],adjmatrix[minindex][j]);
            }
        }
    }
    cout << ans << endl;
}
/*
Problem Statement:
Farmer John has been elected mayor of his town! One of his campaign
promises was to bring internet connectivity to all farms in the
area. He needs your help, of course.

Farmer John ordered a high speed connection for his farm and is
going to share his connectivity with the other farmers. To minimize
cost, he wants to lay the minimum amount of optical fiber to
connect his farm to all the other farms.

Given a list of how much fiber it takes to connect each pair of
farms, you must find the minimum amount of fiber needed to connect
them all together. Each farm must connect to some other farm such
that a packet can flow from any one farm to any other farm.

The distance between any two farms will not exceed 100,000.

PROGRAM NAME: agrinet

INPUT FORMAT:

* Line 1: The number of farms, N (3 <= N <= 100).

* Line 2..end: The subsequent lines contain the N x N connectivity
matrix, where each element shows the distance from on farm to
another. Logically, they are N lines of N space-separated integers.
Physically, they are limited in length to 80 characters, so some
lines continue onto others. Of course, the diagonal will be 0,
since the distance from farm i to itself is not interesting for
this problem.

SAMPLE INPUT:

4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0

OUTPUT FORMAT:

The single output contains the integer length that is the sum of
the minimum length of fiber required to connect the entire set of
farms.

SAMPLE OUTPUT:

28
*/
