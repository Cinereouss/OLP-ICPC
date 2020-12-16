#include <bits/stdc++.h>

using namespace std;

string a,b,delimiter;
vector <char> aTemp, bTemp;

void split(string &s, string delimiter){
		cout << "delimiter: " << delimiter << endl;
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
	    token = s.substr(0, pos);
	    std::cout << token << std::endl;
	    s.erase(0, pos + delimiter.length());
	}
}

int lcs(string &a, string &b) {
    int m = a.size(), n = b.size();
    a = ' ' + a;
    b = ' ' + b;
    vector< vector<int> > f(m+1, vector<int>(n+1, 0));
    for (int i=1; i<=m; i++) 
		for (int j=1; j<=n; j++){
       		if (a[i] == b[j]) 
			   f[i][j] = f[i-1][j-1] + 1;
       		else 
			   f[i][j] = max(f[i-1][j], f[i][j-1]);
    	}
    return f[m][n];
}


void swapBit(string str, string temp){
	for(int i = 0; i < str.length(); i++){
		if(str[i] == '1')
			temp[i] == '0';
		else
			temp[i] == '1';
	}	
}


int main() {
    cin >> a; cout << a << endl;
    cin >> b; cout << b << endl;
	delimiter = lcs(a, b);

    split(a, delimiter);
    split(b, delimiter);
    cout << a << " " << b;
}
