#ifndef SIEVE_OF_ERATOSHTENES_H_INCLUDED
#define SIEVE_OF_ERATOSHTENES_H_INCLUDED

#include <vector>

int sieve_of_eratosthenes(int n, std::vector<bool> is_prime){
    if(n<2)
        return 0;
        
    int primeCount = 0;
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            primeCount++;
            for(int j=2; (i*j)<=n; j++){
                is_prime[i*j] = false;
            }
        }
    }

    return primeCount;
}

#endif // SIEVE_OF_ERATOSHTENES_H_INCLUDED
