#include <bits/stdc++.h>

using namespace std;
 
class NODE{
	private:
		int data;
		NODE *link;
	public:
		NODE(int a = 0, NODE *llink = NULL){
			data = a;
			link = llink;
		}
		int get_dt(){return data;}
		NODE* get_lk(){return link;}
		friend class SET;
		
};

class SET{
	private:
		NODE *pH;
		NODE *pT;
		int spt;
	public:
		SET(){
			pH = pT = NULL;	
			spt = 0;
		}
		
		bool check(){
			return spt;
		}
		
		int find (int a){
			if(!check()) return -1;
			int vt = 0;
			NODE *i = pH;
			while(i != NULL){
				if(i->get_dt() == a)
					return vt;
				++vt;
				i = i->get_lk();
			}
			return -1;
		}
	
		bool insert(int a){
			NODE *tmp = new NODE(a);
			if(find(a)==-1){
				tmp->link = pH;
				pH = tmp;
				spt++;
			}
			else 
				cout << "[Error]: Value " << a << " existing!" << endl;		
		}
		
		NODE* get_end(){
			NODE* p;
			p = pH;
			while(true){
				if(p->get_lk() == NULL)
					return p;
			}
		}
		
		void show(){
				NODE *p = pH;
				cout << "{ ";
				while(p!=NULL){
					cout << p->get_dt() << ", ";
					p=p->get_lk();
				}
				cout << "}" << endl;
		}
		
		NODE* get_pH(){return pH;}
		NODE* get_pT(){return pT;}
		friend class NODE;
		friend istream &operator >>(istream &is, SET &a);
		friend ostream &operator <<(ostream &os, SET &a);
		friend SET &operator +(SET a, SET b);
		void tong(SET a,SET b){
			NODE *p; 
			p= a.get_pH();
			
			while(p != NULL){
				this->insert(p->get_dt());
				p = p->get_lk();
			}
			
			p= b.get_pH();
			
			while(p != NULL){
				this->insert(p->get_dt());
				p = p->get_lk();
			}
		}
};

istream &operator >>(istream &is, SET &a){
	cout << "Input value of SET: " << endl;
	int gt;
	do{
		cin >> gt;
		if(gt >= 0)
			a.insert(gt);
	}while(gt >= 0);
	return is;
}

ostream &operator <<(ostream &os, SET &a){
	a.show();
	return os << endl;
}

SET &operator +(SET a, SET b){
	SET c;
	NODE *p; 
			p= a.get_pH();
			
			while(p != NULL){
				c.insert(p->get_dt());
				p = p->get_lk();
			}
			
			p= b.get_pH();
			
			while(p != NULL){
				c.insert(p->get_dt());
				p = p->get_lk();
			}
	return c;
}

main(){
	SET a;
	cin >> a;
	cout << a;
	SET b;
	cin >> b;
	cout << b;
	SET c;
	c=a+b;
//	c.tong(a,b);
	cout << "A+B = " << endl;
	cout << c;
}
