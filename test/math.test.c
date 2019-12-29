#include "math.h"
#include "unittest.h"



int main() {
    unit_test(length(unique_factors(1)) == 0, "Prime factorization of 1 is an empty product");

    int product = 2*3*5*17*31;
    unit_test(length(unique_factors(product)) == 5, "Product of multiple primes is factorized successfully");
    unit_test(length(unique_factors(product * 2)) == 5, "But adding duplicate prime doesn't change the nubmer of unique factors");

    Chain primes = chain_primes(1000);
    unit_test(length(primes) == 168, "There are exactly 168 primes up to 1000");
    
    bool accumulator = true;
    for (
        void** node = primes.head;
        (node = *node);
        node = advance(primes, node)
    ){
        if (length(unique_factors(*(int*)node)) != 1) {
            accumulator = false;
            break;
        }
    }
    unit_test(accumulator, "And each of these primes has only one factor of itself");
    unit_test(is_prime(44491), "44491 is prime");
    unit_test((!is_prime(2729*3)), "2729*3 is not prime");

    return report();
}

