#ifndef MYSTATS_H
#define MYSTATS_H
#include<vector>

template<typename T>
class Stat{
    vector<T>data;
    public:
    Stat();
    void insert(T value);
    long double Mean();
    long double Min();
    long double Max();
    void Mode();
    long double Median();
    long double Variance();
    long double Std_deviation();
    long double Range();
    long double Percentile25th();
    long double Percentile50th();
    long double Percentile75th();
    long double Iqr();
    void Outlier_bound();
};

#include"Stats.tpp"

#endif