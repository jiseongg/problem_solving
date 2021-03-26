#include <iostream>

int is_prime(int n)
{
	if (n < 2)
		return false;
	
	for(int i = 2; i*i <= n; i++)
		if(n % i == 0)
			return false;
	
	return true;
}

int main() {
	int M, N;
	int cnt = 0;
	int res;
	
	std::cin >> M;
	
	for(int i = 0; i < M; i++) {
		std::cin >> N;
		res = is_prime(N);
		cnt += res ? 1 : 0;
	}

 	std::cout << cnt << std::endl;
	return 0;
}
