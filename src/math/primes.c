#include "math.h"


Chain chain_primes(int bound) {
    Chain primes = new_chain(sizeof(int));
    Chain factors = new_chain(sizeof(int));
    
    int factor_bound = 2;

    for (int factor = 2; factor_bound <= bound; factor++) {
        for (
            int n = factor_bound; 
            n < factor * factor && n <= bound;
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

Chain unique_factors(int number) {
    Chain number_factors = new_chain(sizeof(int));
    Chain primes = new_chain(sizeof(int));
    Chain factors = new_chain(sizeof(int));

    int check = 1;
    int factor_bound = 2;

    for (int factor = 2; factor_bound <= number; factor++) {
        for (
            int n = factor_bound;
            n < factor * factor && n <= number;
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
                if (!(number % n)) {
                    *(int*)link(number_factors) = n;
                    check *= n;
                    if (check == number) return number_factors;
                }
            }
        }
        factor_bound = factor * factor;
        *(int*)link(factors) = factor;
    }
    return number_factors;
}

bool is_prime(int number) {
    return length(unique_factors(number)) == 1;
}

