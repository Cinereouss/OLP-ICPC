#include <bits/stdc++.h>

using namespace std;

class Date{
	private:
		int day, month, year;
	public:
		Date(){
			day = 0;
			month = 0; 
			year = 0;
		};
		void Handling();
		void Add_Day(int day);
		bool Check_Year(int Year);
		int Check_Month(int Month);
		void input();
		void output();
};

void Date::input(){
	cout << "input dd/mm/yyyy : ";
	if(cin >> day >> month >> year){
		cout << "Successful !" << endl;
		cout << "Date: " << day << "/" << month << "/" << year << endl; 
		cout <<"----------------------------" << endl;
	}
}

void Date::output(){
	cout << "Date dd/mm/yyyy : " << day << "/" << month << "/"  << year << endl;
}

int Date::Check_Month(int Month){
	switch(Month){
	case 1: {return 31; break;}
	case 2: {if(Date::Check_Year(year)) return 29;
			 else return 28;
			 break;
			 }
	case 3: {return 31; break;}
	case 4: {return 30; break;}
	case 5: {return 31; break;}
	case 6: {return 30; break;}
	case 7: {return 31; break;}
	case 8: {return 31; break;}
	case 9: {return 30; break;}
	case 10:{return 31; break;}
	case 11:{return 30; break;}
	case 12:{return 31; break;}
	}
}

bool Date::Check_Year(int Year){
	return Year % 4 == 0 && Year % 100 != 0 || Year % 100 == 0 && Year % 400 == 0 ? true : false;
}

void Date::Handling(){
	if(month>12){
		year += month/12;
		month = month%12;
	}
	while(day > Date::Check_Month(month)){
		if(day > Date::Check_Month(month)){
			day-=Date::Check_Month(month);
			if(day == 0) 
				day +=1;
			month+=1;
		}
		if(month>12){
			month = 1;
			year +=1;
		}
	}
}

void Date::Add_Day(int tmp_day){
	day += tmp_day;
	while(day <= 0){
		day+=Check_Month(month);
		month-=1;
		if(month <= 0){
			year-=1;
			month = 12;
		}
	}
	Date::Handling();
}
main(){
	int add_day;
	Date test;
	test.input();
	test.Handling();
	test.output();
	cout << endl << "Add day : ";
	cin >> add_day;
	test.Add_Day(add_day);
	test.output();
}

