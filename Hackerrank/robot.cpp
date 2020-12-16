#include <bits/stdc++.h>

using namespace std;

int arr[100][100], Red[100], Blue[100];
		
class robot{
	public:
	int x, y, huong, diem;
	robot(int a, int b, int c){
		x = a;
		y = b;
		huong = c; 
		diem = 0;
	}
	void tinh(int dk){
		if(dk == 1 && huong == 1){
			huong = 4;
		}
		else
			if(dk == 1 && huong == 2){
				huong = 1;
			}
			else
				if(dk == 1 && huong == 3){
					huong = 2;
				}
				else
					if(dk == 1 && huong == 4){
						huong = 3;
					}
		/**/
		if(dk == 2 && huong == 1){
			huong = 2;
		}
		else
			if(dk == 2 && huong == 2){
				huong = 3;
			}
			else
				if(dk == 2 && huong == 3){
					huong = 4;
				}
				else
					if(dk == 2 && huong == 4){
						huong = 1;
					}
		/**/
		if(dk == 0){
			if(huong == 1){
				y++;
			}
			if(huong == 2){
				x++;
			}
			if(huong == 3){
				y--;
			}
			if(huong == 4){
				x--;
			}
			diem += arr[x][y];
			arr[x][y] = 0;
		}
	}
};

main(){
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int T, N, M;
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				cin >> arr[i][j];
		for(int i = 0; i < M; ++i)
			cin >> Blue[i];
		for(int i = 0; i < M; ++i)
			cin >> Red[i];
			

		/***********************************/
		robot B(0,0,2);
		robot R(N-1,N-1,4);
		for(int i = 0; i < M; ++i){
			B.tinh(Blue[i]);
			R.tinh(Red[i]);
		}
		cout << B.diem<< " " << R.diem <<endl;
	}
}
