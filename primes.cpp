#include "primes.h"
#include "random.h"
#include <algorithm>
#include <iostream>
#include <cmath>

//utility function for computing base^power % modulus quickly
unsigned int pow_mod(unsigned int in_base, unsigned int power, unsigned int modulus){
    if (power == 0){
        return 1;
    }
    unsigned long y = 1;
    unsigned long base = in_base; //allowing overflow to avoid some nastiness
    while (power > 1){
        if (power % 2 == 0){
            base = ((base % modulus) * (base % modulus)) % modulus;
            power = power / 2;
        } else {
            y = (y * base) % modulus;
            base = ((base % modulus) * (base % modulus)) % modulus;
            power = (power - 1)/2;
        }
    }
    return ((base % modulus) * (y % modulus)) % modulus;;
}

//This is the Miller-Rabin primality test
bool is_prime_MR(unsigned int n){
    if (n == 2){
        return true;
    }
    if (n % 2 == 0){
        return false;
    }
    unsigned int bases[3] = {2, 7, 61};
    unsigned int d = n-1;
    int s = 0;
    //Goal is to find d and s such that n-1 = 2^s * d (d is odd)
    //So d & 1 == 0 implies that the lowest bit is 0 (so 2 divides it)
    while ((d & 1) == 0) { 
        d >>= 1; 
        s++; 
    }
    int i = 0;
    int j = 0;
    unsigned int a = 0;
    unsigned int test_result = 0;
    for (i = 0; i < 3; ++i){
        a = std::min(n-2, bases[i]);
        test_result = pow_mod(a, d, n);
        if (test_result == 1){
            continue;
        } 
        if (test_result == n - 1){
            continue;
        }
        for (j = 1; j < s; j++){
            test_result = pow_mod(test_result, 2, n);
            if (test_result == 1){
                return false;
            }
            if (test_result == n-1){
                break;
            }
        }
        if (j == s){
            return false;
        }
    }
    return true;  
};

//this is the brute force version
bool is_prime_brute_force(unsigned int n){
    unsigned int cutoff = int(std::sqrt(n));
    for(int i = 2; i <= cutoff; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

//just a wrapper so I can quickly change methods
bool is_prime(unsigned int n){
    return is_prime_MR(n);
}

//the handler for the outside world
unsigned int random_prime(unsigned int lower, unsigned int upper){
    unsigned int potential_prime = random_integer(lower, upper);
    int steam_valve = 0;
    int cutoff = 500;
    
    while (!is_prime(potential_prime) && steam_valve < cutoff){
        potential_prime = random_integer(lower, upper);
        steam_valve++;
    }
    
    if (steam_valve >= cutoff){
        return 0;
    }
    
    return potential_prime;
};