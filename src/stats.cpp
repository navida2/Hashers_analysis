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
//make cosntrcutor
Stats::Stats(string name, const vector<int> & chain_lengths) : name(name), chain_lengths(chain_lengths){
    //THIS IS EVERYTHING I NEED TO CALCUATER
    // int entries = 0;
    // int chains = 0;
    // double load_factor = 0;
    // int min = 0;
    // int max = 0;
    // int span = 0;
    // double mean = 0;
    // double stddev = 0;//
    min = chain_lengths[0];
    max = chain_lengths[0];
    for (int var:chain_lengths){
        if (var>max){
            max = var;
        }
        else if(var<min){
            min = var;
        }
    }
    chains = chain_lengths.size();
    for (int elem: chain_lengths){
        entries+=elem;
    }
    load_factor = static_cast<double>(entries) / chains;
    span = max-min;
   
    stddev = compute_stddev(chain_lengths);
    mean = compute_mean(chain_lengths);
}