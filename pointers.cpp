#include <bits/stdc++.h>
using namespace std;
int& func(int &a){
    cout << "a: " << a << endl;
    cout << "&a: " << &a << endl;
    a+=1;
    return a;
}
int main(){
    int a = 10;
    cout << &a << endl;
    int *p = &a;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    int arr[4] = {0,1,2,3};
    int *p1 = arr;
    *(p1 + 1) = 2;
    cout << p1 << endl;
    int *p2 = &arr[0];
    cout << p2 << endl;
    if(*p1==*p2) cout << "1" << endl;
    int *p3 = &arr[1];
    cout << p3 << endl;
    cout << p2 + 1 << endl;
    for(int *i = &arr[0];i<p1+4;i++){
        cout << *i << " ";
    }
    cout << endl;
    p1[0] = 10;
    for(int *i = arr; i<arr + 4;i++){
        cout << *i << " ";
    }
    cout << endl << endl;
    int x = 100;
    int v = func(x) +=5;
    cout << x << endl;
    cout << v << endl;
}
