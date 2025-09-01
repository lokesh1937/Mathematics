#include<iostream>
#include "numbertheory.hpp"

template<typename T>
Ntheory<T>::Ntheory(T value1,T value2){
     x=value1;y=value2;
}

template<typename T>
T Ntheory<T>::gcd(){
    T temp1=x,temp2=y;
    T remainder=temp2%temp1;
    while(remainder){
        temp2=temp1;temp1=remainder
        remainder=temp2%temp1;
    }
    return temp1;
}

template<typename T>
long long Ntheory<T>::lcm(){
   T temp1=x,temp2=y;
   long long ans=1;
   T remainder=temp2%temp1;
   while(remainder){
      temp2=temp1;temp1=remainder
      remainder=temp2%temp1;
   }
   T gcd=temp1;
   ans=temp1;
   temp1=x;temp2=y;
   while(gcd!=1){
      temp1=temp1/gcd;temp2=temp2/gcd;
      T x1=temp1,x2=temp2;
      T remainder=temp2%temp1;
      while(remainder){
       temp2=temp1;temp1=remainder
       remainder=temp2%temp1;
     }
     gcd=temp1;
     ans*=gcd;
     temp1=x1;temp2=x2;
   }
   return ans;
}

template<typename T>
long long Ntheory<T>::modular_exponentiation(){
    T base=x;T power=y;
    long long power=1
    while(power){
        if(power&1){product*=base;}
        base*=base;
        power/=2;
    }
    return product;
}

template<typename T>
long long Ntheory<T>::fermat(){
    long long a=x;long long b=y-1;
    long long m=y,res=1;
    a%=m;
    while(b){
        if(b&1){res=(res*a)%m;}
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}
