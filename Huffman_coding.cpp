#include <bits/stdc++.h>
using namespace std;

struct Node {

	char data;
  unsigned freq;
  Node *left, *right;

	Node(char data, unsigned freq, Node* l = NULL, Node* r = NULL)
 
	{

		this->left = l;
		this->right = r;
		this->data = data;
		this->freq = freq;
	}
};

struct compare {

	bool operator()(Node* l, Node* r)

	{
		return (l->freq > r->freq);
	}
};


void printCodes(struct Node* root, string str)
{

	if (!root)
		return;

	if (root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}


void printHcodes(char arr[], int freq[], int size)
{
	priority_queue<Node*, vector<Node*>, compare> h;

	for (int i = 0; i < size; ++i)
		h.push(new Node(arr[i], freq[i]));


	while (h.size() > 1) {

	
		Node *l = h.top();h.pop();

		Node *r = h.top();h.pop();

		
		Node *top = new Node('$', l->freq + r->freq, l, r);

		h.push(top);
	}
	printCodes(h.top(), "");
}
