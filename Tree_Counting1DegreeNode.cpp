#include<bits/stdc++.h>
using namespace std;
struct node{
    node* lchild;
    int data;
    node* rchild;
};

struct Node{
    node* data;
    Node* next;
};

Node* front=NULL,*rare=NULL;
node* root=NULL;
void enqueue(node* x){
    Node* p=NULL;
    p=new Node;
    if(p){
        p->data=x;
        p->next=NULL;
        if(front==NULL){
            front=rare=p;
        }
        else{
            rare->next=p;
            rare=p;
        }
    }
    else{cout<<"Heap Overflow";}
}
node* dequeue(){
    node* value;
    value=front->data;
    front=front->next;
    return value;
}
//In similar fashion we can count total ,leaf,any degree node by just changing a little in the function
int count1degree(node* p){
    if(p!=NULL){
        int x=count1degree(p->lchild);
        int y=count1degree(p->rchild);
        if((p->lchild!=NULL)^(p->rchild!=NULL)){
            return x+y+1;
        }
        return x+y;
    }
    return 0;
}
int main(){
    cout<<"Input the root data : ";
    root=new node;
    cin>>root->data;
    root->lchild=root->rchild=0;
    enqueue(root);
    while(front){
        node* p;
        p=dequeue();
        cout<<"Input left child : ";
        int x;
        cin>>x;
        if(x!=-1){
            node* t;
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(t);
        }
        cout<<"Input right child : ";
        cin>>x;
        if(x!=-1){
            node* t;
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(t);
        }

    }
    cout<<count1degree(root)<<endl;
    return 0;
}
