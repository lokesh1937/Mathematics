#include<iostream>
#include "number_operations.hpp"

//testing all the methods

int main(){
    Number<long long>num(20);
    std::cout<<num.sum()<<"\n";
    std::cout<<num.divisors()<<"\n";
    std::cout<<num.squares()<<"\n";
    std::cout<<num.largest_divisor()<<"\n";
    std::cout<<num.cubes()<<"\n";
    std::cout<<num.even_divisors()<<"\n";
    std::cout<<num.odd_divisors()<<"\n";
    std::cout<<num.factorization()<<"\n";
    if(num.isprime()){std::cout<<"Number is prime!"<<"\n";}
    else{std::cout<<"Number is not a prime!"<<"\n";}
}