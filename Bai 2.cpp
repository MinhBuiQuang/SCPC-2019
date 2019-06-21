#include <bits/stdc++.h> 
using namespace std; 
  
#define PI 3.14159265 

int main(void)
{
	int T, test_case;
	
// 	freopen("input2.txt", "r", stdin);
	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		double Answer = 0;
		int R, S, E, N;
		scanf("%d %d %d %d", &R, &S, &E, &N);
		double pos = S;
		for(int i = 0; i < N; i++) {
			int l, r, h;
			scanf("%d %d %d", &l, &r, &h);			
			if(h >= R) {
				Answer += l - (pos + R);
				Answer += PI*R + (r - l) + 2*(h - R);
				pos = r + R;
			} else {
				double temp = sqrt(R*R - (R-h)*(R-h));
				Answer += l - (pos + temp);
				Answer += 2*acos((R - h)/(float)R)*R + (r-l);
				pos = r + temp;
			}
		}
		Answer += E - pos;
		printf("Case #%d\n%.10f\n", test_case+1, Answer);       
	}

	return 0;
}
