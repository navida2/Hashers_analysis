#include <cmath>
#include "stats.h";

double compute_mean(const std::vector<int> &v){
    double sum = 0;
    for(auto &n:v){
        sum +=n;
    }
    return sum/v.size();
}

double compute_stddev(const std::vector<int> &v){
    double sum_squares=0;
    double mean = compute_mean(v);
    double len = v.size();
    for (auto n:v){
        double diff = n -mean;
        sum_squares+=diff*diff;
    }
    return std::sqrt(sum_squares/len);
}