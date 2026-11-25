#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *pNext;
};

struct List{
    Node *pHead;
    int len=0;
};

Node* findLast(const List l){
    if (l.pHead == NULL) return l.pHead;
    Node *n = l.pHead;
    while (n->pNext != NULL){
        n = n->pNext;
    }
    return n;
}

Node* findAt(const List l, int i){
    if (l.pHead == NULL) return l.pHead;
    Node *n = l.pHead;
    int cnt=0;
    while (n->pNext!=NULL and cnt!=i){
        n = n->pNext;
        cnt++;
    } 
    return n->pNext;
    
}

void addNode(List &l, int x){
    Node *p= new Node;
    p->data = x; // (*p).data
    p->pNext = NULL;
    if (l.pHead == NULL) {
        l.pHead = p;
    } else {
        Node *q = findLast(l);
        q->pNext = p;
    }
    l.len++;
}

void reverseList(List &l){
    Node *cur = l.pHead;
    int cnt = 0;
    while (cur->pNext != NULL and cnt!=l.len/2){
        cur->pNext->data = findAt(l, l.len - cnt)->data;
        cnt++;
    }
}

void reverseKgroup(List &l, int k){
    int numberOfGroups = l.len/k;
    for (int i=0;i<numberOfGroups;i++){
        int cnt=0;
        Node *cur = findAt(l, i*k);        
        while (cur->pNext != NULL and cnt!=(i*k +k/2)){
            cur->pNext->data = findAt(l, (i+1)*k-cnt)->data;            
        }
    }
}

void removeAt(List &l, int i){
    Node *n=l.pHead;
    
}

void removeDupNodes(List &l){
    
}

int main(){
    
}