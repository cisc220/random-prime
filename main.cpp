#include<iostream>
#include<cstdlib>
#include <ctime>
#include "primes.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
    
    srand(time(NULL));
    
    unsigned int lower = 1000000000;
    unsigned int upper = 2000000000;
    //cout << "Random Prime Generation:" << endl;
    //cout << "Please give upper and lower bounds, space separated: " << endl;
    //cin >> lower >> upper;
    for(auto i = 0; i < 10000; ++i){
        cout << random_prime(lower, upper) << endl;
    }
    return 0;
}