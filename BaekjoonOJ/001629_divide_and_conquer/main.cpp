
#include <iostream>

using namespace std;

int C;

int pow(int a, int b) {
	if (b == 1) {
		return a % C;
	}
	int res_0, res_1, res_2;
	res_0 = pow(a, b/2);	
	res_1 = (1LL * (res_0 % C) * (res_0 % C)) % C;
	if (b % 2 == 1) {
		res_2 = (1LL * (res_1 % C) * (a % C)) % C;
	} else {
		res_2 = res_1 % C;
	}
	return res_2;
}

int main() {
	int A, B, res;

	cin >> A >> B >> C;

	res = pow(A, B);

	cout << res << '\n';

	return 0;
}
	
