
#include <iostream>

using namespace std;

long long C;

long long multiply(long long a, long long b) {
	if (b == 1) {
		return a % C;
	}

	long long res_0, res_1, res_2;
	res_0 = multiply(a, b/2);
	res_1 = ((res_0 % C) + (res_0 % C)) % C;
	if (b % 2 == 1) {
		res_2 = ((res_1 % C) + (a % C)) % C;
	} else {
		res_2 = res_1;
	}
	return res_2;
}

long long pow(long long a, long long b) {
	if (b == 1) {
		return a % C;
	}
	long long res_0, res_1, res_2;
	res_0 = pow(a, b/2);	
	res_1 = multiply((res_0 % C), (res_0 % C)) % C;
	if (b % 2 == 1) {
		res_2 = multiply((res_1 % C), (a % C)) % C;
	} else {
		res_2 = res_1;
	}
	return res_2;
}

int main() {
	long long A, B, res;

	cin >> A >> B >> C;

	res = pow(A, B);

	cout << res << '\n';

	return 0;
}
	
