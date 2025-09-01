#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<float.h>
#include "Stats.hpp"

template<typename T>
Stat<T>::Stat(){}

template<typename T>
void Stat<T>::insert(T value){
    data.push_back(value);
}

/*mean,mode,range,median..*/
template<typename T>
long double Stat<T>::Mean(){
    long long sum=0;
    for(auto x:data){sum+=x;}
    long double size=data.size();
    return sum/size;
}

template<typename T>
long double Stat<T>::Max(){
    sort(data.begin(),data.end());
    return data[data.size()-1];
}

template<typename T>
long double Stat<T>::Min(){
    sort(data.begin(),data.end());
    return data[0];
}

template<typename T>
void Stat<T>::Mode(){
    map<T,int>freq;
    for(auto x:data){freq[x]++;}
    priority_queue<pair<int,T>>pq;
    for(auto &pair:freq){T x=pair.first;int y=pair.second;pq.push({y,x});}
    int mode=pq.top().first;
    while(!pq.empty() && pq.top().first==mode){cout<<pq.top().first<<" ";pq.pop();}cout<<"\n";
}

template<typename T>
long double Stat<T>::Median(){
    int n=data.size();
    sort(data.begin(),data.end());
    if(n%2){return double(data[(n+1)/2]);}
    return (data[n/2]+data[(n/2)+1])/2.0;
}

/*
sample variance 
*/
template<typename T>
long double Stat<T>::Variance(){
    long long sum=0;
    for(auto x:data){sum+=x;}
    long double size=data.size();
    long double mean=sum/size;
    //residual squares
    long double residuals=0;
    for(auto x:data){residuals+=(x-mean)*(x-mean);}
    return residuals/(data.size()-1);
}

template<typename T>
long double Stat<T>::Std_deviation(){
    long long sum=0;
    for(auto x:data){sum+=x;}
    long double size=data.size();
    long double mean=sum/size;
    //residual squares
    long double residuals=0;
    for(auto x:data){residuals+=(x-mean)*(x-mean);}
    long double var=residuals/(data.size()-1);
    return sqrt(var);
}

template<typename T>
long double Stat<T>::Range(){
    long double min_ele=-LDBL_MAX;
    long double max_ele=LDBL_MAX;
    for(auto x:data){min_ele=min(min_ele,x);max_ele=max(max_ele,x);}
    return max_ele-min_ele;
}

/* percentiles 25th,50th and 75th */
/*
  precise definition of percentiles 
  100*(j/n)<=p<100*((j+1)/n)
*/
template<typename T>
long double Stat<T>::Percentile25th(){
    if(data.size()==0) return 0.0;
    sort(data.begin(),data.end());
    return data[data.size()/4];
}

template<typename T>
long double Stat<T>::Percentile50th(){
    if(data.size()==0) return 0.0;
    sort(data.begin(),data.end());
    return data[data.size()/2];
}

template<typename T>
long double Stat<T>::Percentile75th(){
    if(data.size()==0) return 0.0;
    sort(data.begin(),data.end());
    return data[3*data.size()/4];
}

/*
Inter quartile range*/
template<typename T>
long double Stat<T>::Iqr(){
    if(data.size()==0) return 0.0;
    sort(data.begin(),data.end());
    return data[3*data.size()/4]-data[data.size()/4];
}

/*outlier boundary*/
template<typename T>
void Stat<T>::Outlier_bound(){
   if(data.size()==0) return;
    sort(data.begin(),data.end());
    long double q1=data[data.size()/4];
    long double q3=data[3*data.size()/4];
    long double iqr=q3-q1;
    cout<<"["<<" "<<q1-1.5*iqr<<" "<<q3+1.5*iqr<<"\n";
    return;
}
