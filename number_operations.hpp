#ifndef NUMBER_OP_H
#define NUMBER_OP_H

template<typename T>
class Number{
    T n;
    public:
    Number(T x);
    long long sum();
    long long squares();
    long long cubes();
    long long odd_divisors();
    long long even_divisors();
    long long factorization();
    long long largest_divisor();
    long long divisors();
    bool isprime();

};

#include "number_operations_template.tpp"

#endif