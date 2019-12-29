#include "math/math.h"


Chain chain_primes(int bound) {
    Chain primes = new_chain(sizeof(int));
    Chain factors = new_chain(sizeof(int));
    
    int factor_bound = 1;

    for (int factor = 2; factor_bound < bound; factor++) {
        for (
            int n = factor_bound; 
            n < factor * factor && n < bound; 
            n++
        ){
            bool is_prime = true;
            for (
                void** f = factors.head;
                (f = *f);
                f = advance(factors, f)
            ){
                if (!(n % *(int*)f)) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) { 
                *(int*)link(primes) = n; 
            }
        }
        factor_bound = factor * factor;
        *(int*)link(factors) = factor;
    }
    return primes;
}
