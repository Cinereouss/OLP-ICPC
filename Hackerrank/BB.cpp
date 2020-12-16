#include <bits/stdc++.h> 
#include<string>

using namespace std;

int main(){
	string s1 ;
	string s2 ;
	cin >> s1 >> s2;
	string s1Fake = s1, s2Fake = s2;
	
	for(int i = 0 ; i < s1.length() ; i++){
		if(s1[i] == '0'){
			s1Fake[i] = '1';
		}else{
			s1Fake[i] = '0';
		}
	}	
	for(int i = 0 ; i < s2.length() ; i++){
		if(s2[i] == '0'){
			s2Fake[i] = '1';
		}else{
			s2Fake[i] = '0';
		}
	}
	string s3 = "";
	
	
	if(s1.length() > s2.length()){
		for(int i = 0 ; i < s1Fake.length() ; i++){
			s3 += s1Fake[i];
			if(s1.find(s3) == std::string::npos  && s2.find(s3) == std::string::npos){
				break;
			}
		}
	}else{
		for(int i = 0 ; i < s2Fake.length() ; i++){
			s3 += s2Fake[i];
			if(s1.find(s3) == std::string::npos  && s2.find(s3) == std::string::npos){
				break;
			}
		}
	}
	string s3Fake = s3;
	for(int i = 0 ; i < s3.length() ; i++){
		if(s3[i] == '1'){
			s3Fake[i] = '0';
			if(s1.find(s3Fake) == std::string::npos  && s2.find(s3Fake) == std::string::npos){
				s3 = s3Fake;
			}else{
				s3Fake[i] = '1';
			}
		}
	}
	cout << s3;
	
}

