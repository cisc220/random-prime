#include "random.h"
#include<ctime>
#include<cstdlib>

unsigned int random_integer(unsigned int lower, unsigned int upper){
    return std::rand() % (upper - lower + 1) + lower;
}