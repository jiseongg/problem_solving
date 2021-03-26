#include <iostream> 

bool is_prime[1000000];

int main()
{
	int M, N;
	
	std::cin >> N >> M;
	
	for(int i = 2; i <= M; i++)
		is_prime[i] = true;
	
	for(int i = 2; i <= M; i++) {
		if (!is_prime[i])
			continue;
		
		for(int j = i*2; j <= M; j += i)
			is_prime[j] = false;
	}
	
	for(int i = N; i <= M; i++)
		if (is_prime[i])
			std::cout << i << '\n';
	
	return 0;
}
