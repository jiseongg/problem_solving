#include <iostream>

int comb[1001][1001];

int _comb(int n, int k)
{
	int res;

	if (comb[n][k] == -1) {
		res = (_comb(n-1, k-1) + _comb(n-1, k)) % 10007;
		comb[n][k] = res;
		return res;
	} else {
		return comb[n][k];
	}
}

int main()
{
	int N, K, res;
	std::cin >> N >> K;
	
	for(int n = 0; n <= N; n++) {
		for(int k = 0; k <= K; k++) {
			if(k == 0 || k ==n)
				comb[n][k] = 1;
			else
				comb[n][k] = -1;
		}
	}

	res = _comb(N, K);
	std::cout << res << '\n';
	
	return 0;
}
