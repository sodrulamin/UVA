#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const double eps = 1e-5;
const double PI = acos(-1.0);
const int MAXN = 10000 + 10;

double A[MAXN];
int N, F;

bool check(double lim) {
	int ret = 0;
	for (int i = 0; i < N; ++ i) ret += floor(A[i] / lim);
	return ret >= F + 1;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &F);
		double left = 0, right = 0;
		for (int i = 0; i < N; ++ i) {
			scanf("%lf", &A[i]);
			A[i] = A[i] * A[i] * PI;
			right = max(right, A[i]);
		}

//		for(int i=0;i<N;i++)
//            printf("%0.4f ",A[i]);
//        printf("\n");

		while (fabs(left - right) > eps) {

			double mid = (left + right) / 2;
            //printf("left: %0.4f right: %0.4f mid: %0.4f diff: %d\n",left,right,mid,fabs(left - right));
			if (check(mid)) left = mid;
			else right = mid;
		}
		printf("%.4f\n", left);
	}
	return 0;
}
