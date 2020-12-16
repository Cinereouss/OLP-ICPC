#include <bits/stdc++.h>

using namespace std;

class  Node{
	private:
		int data;
		Node *next;
	public:
		Node(int dt, Node *next1){
			data = dt;
			next = next1;
		}
		friend class DSLK;
};

class DSLK{
	private:
		Node *head;
		Node*tail;
		int spt;
	public:
		DSLK(){
			head = tail = NULL;
			spt = 0;
		}
		~DSLK();
		void push_front(int d);
		int operator[](int i);
		
};

DSLK::~DSLK(){
	Node *p = head;
	
	while ( p!=NULL){
		head = head->next;
		delete p;
		p = head;
	}
	spt = 0;
}

void DSLK::push_front(int d){
	head = new Node(d, head);
	spt++;
}

int DSLK::operator[](int i){
	int k = 0;
	Node *p = head;
	while (k<i && p!=NULL){
		p=p->next;
		k++;
	}
	if(k==1) return p->data; 
}
main(){
	
}
