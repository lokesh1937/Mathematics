#ifndef MYNUMBERTHEORY_H
#define MYNUMBERTHEORY_H

template<typename T>
class Ntheory{
   T x,y;
   public:
   Ntheory(T value1,T value2);
   T gcd();
   long long lcm();
   long long modular_exponentiation();
   long long fermat();
};

#include "numbertheory.tpp";

#endif