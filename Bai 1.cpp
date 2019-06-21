#include<iostream>
#include<vector>
using namespace std;

vector<int> f(1000001, -1);
vector<int> s(1000001, 0);

int main(int argc, char** argv)
{
	int T, test_case;
	scanf("%d", &T);
	f[0] = 0; f[1] = 0;
	
	for(int i = 2; i <= 1000000; i++) {
		if(i%2 == 0) 
			f[i] = 1 + f[i >> 1];
		else  
			f[i] = 2 + f[(i + 1) >> 1];
		s[i] = s[i - 1] + f[i];
	}
	
	for(test_case = 0; test_case  < T; test_case++)
	{		
		int a, b;
		scanf("%d %d", &a, &b);			
		printf("Case #%d\n%d\n", test_case+1, s[b] - s[a - 1]);
	}
	return 0;
}
