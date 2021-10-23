//Coded By Vishal Mourya
#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define f(var,a,b) for(ll var = a ; var < b ; var++ )
#define fr(var,a,b) for(ll var = a ; var > b ; var-- )
#define fasthoja ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

const int SIZE = 26;

struct node {
    bool endOfWord;
    node *ar[SIZE];
};

node *getNode() {
    node *n = new node();
    n->endOfWord = false;

    f(i,0,SIZE)
        n->ar[i] = NULL;
    return n;
}

void insert( node *root , string st ) {
    node *temp_root = root;
    ll n = st.length();
    f(i,0,n) {
        ll index = st[i] - 'a';

        if( temp_root->ar[index] == NULL ) 
            temp_root->ar[index] = getNode();
        
        temp_root = temp_root->ar[index];
    }
    temp_root->endofWord = true;
}

bool search(node *root, string st) {
    node *tempRoot = root;

    f(i,0,st.size()) {
        int index = st[i] - 'a';

        if( tempRoot->ar[index] == NULL )
            return false;
        tempRoot = tempRoot->ar[index];
    }
    return tempRoot->endOfWord;
}

int main(void){
    node *root = getNode();
    int n, code;
    string st;

    while(true) {
        cin >> code;
        if( code == 1 ) {
            cout << "Enter String to insert : ";
            cin >> st;
            insert(root, st);
        }
        else if( code == 2 ) {
            cout << "Enter String to Search : ";
            cin >> st;
            cout << search(root, st) << "\n";
        }
        else break;
    }

    return 0;
}