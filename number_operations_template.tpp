#include<iostream>
#include "number_operations.hpp"

//constructor
template<typename T>
Number<T>::Number(T x){
    n=x;
}

//sum of naturals upto n
template<typename T>
long long Number<T>::sum(){
    long long sum=0;
    for(long long i=1;i<=n;i++){sum+=i;}
    return sum;
}

//sum of squares upto n
template<typename T>
long long Number<T>::squares(){
    long long sum=0;
    sum=(n*(n+1));
    sum=(sum*(2*n+1))/6;
    return sum;
}

//sum of cubes upto n
template<typename T>
long long Number<T>::cubes(){
    long long sum=0;
    long long sum1=(n*(n+1))/2;
    sum=sum1*sum1;
    return sum;
}

//factorization of n 
//n can be upto 20 only more than that will overflow
template<typename T>
long long Number<T>::factorization(){
    if(n>20) return -1;
    long long product=1;
    for(long long i=2;i<=n;i++){product*=i;}
    return product;
}

//largest divisor of n exceptself
template<typename T>
long long Number<T>::largest_divisor(){
    long long divisor=1;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            if(i>divisor){divisor=i;}
            if((n/i)>divisor){divisor=n/i;}
        }
    }
    return divisor;
}

//number of divisors of n
template<typename T>
long long Number<T>::divisors(){
    long long count=1;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            count++;
            if((n/i)!=i){count++;}
        }
    }
    return count;
}

//check if n is prime
template<typename T>
bool Number<T>::isprime(){
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){return false;}
    }
    return true;
}

//number of even divisors of n
template<typename T>
long long Number<T>::even_divisors(){
    long long count=0;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            if((i&1)==0){count++;}
            if(((n/i)&1)==0){count++;}
        }
    }
    return count;
}

//number of odd divisors of n
template<typename T>
long long Number<T>::odd_divisors(){
    long long count=0;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            if(i&1){count++;}
            if((n/i)&1){count++;}
        }
    }
    return count;
}