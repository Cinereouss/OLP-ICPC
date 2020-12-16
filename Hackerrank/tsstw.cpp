#include <bits/stdc++.h>

using namespace std;

class a;

class a{
	private:
		string key;
		int value;
	public:
		a(){
		key = " ";
		value = 0;
		}
		void in();
		void out();
};
void a::in(){
	cout << "Nhap key: ";
	cin.ignore();
	getline(cin, key);
	cout << "Nhap value: ";
	cin >> value; 
}

void a::out(){
	cout << "Key: " << key << endl;
	cout << "Value: " << value << endl;
	cout << "================" << endl;
}

vector <a> arr;

main(){
	int check, dem = 1;
	a tmp;
	check = 1;
	cout << "size of vector before: " <<arr.size() << endl;
	do{
	cout << "Nhap phan tu thu " << dem << endl ;
	tmp.in();
	arr.push_back(tmp);
	dem ++;
	cout << "Nhap lai gia tri cua check: ";
	cin >> check;
	}while(check);
	cout << endl << "Size of vector after: " << arr.size() << endl;
	
	for(auto i : arr)
		arr(i).out;
}
