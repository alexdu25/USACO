#include <bits/stdc++.h>
using namespace std;
struct Node{
    int n;
    Node* next;
};
Node* head = new Node;

void insertNode(int value,int index){//the index it will be after insertion
    Node* newNode = new Node;
    (*newNode).n = value;
    Node* prevNode=head;
    for(int i=0;i<index-1;i++) prevNode = (*prevNode).next;
    (*newNode).next = (*prevNode).next;
    (*prevNode).next = newNode;
}
void deleteNode(int index){
    Node* prevNode = head;
    for(int i=0;i<index;i++) prevNode = (*prevNode).next;
    Node *tbd = (*prevNode).next;//to be deleted
    (*prevNode).next = prevNode->next->next;
    delete tbd;
}
int main(){
    (*head).n = 0;
    (*head).next = nullptr;
    insertNode(1,1);
    insertNode(2,1);
    for(Node *i=head;i!=nullptr;i=(*i).next){
        cout << (*i).n << endl;
    }

}
