//use this to generate a random prime
unsigned int random_prime(unsigned int lower, unsigned int upper);

//this is a primality test
bool is_prime(unsigned int n);

//this is a slow primality test
bool is_prime_brute_force(unsigned int n);

//this is a fast (and loose) primality test
bool is_prime_miller_rabin(unsigned int n);

//this is utility method to compute base^power modulo modulus
unsigned int pow_mod(unsigned int base, unsigned int power, unsigned int modulus);