//Date: July-21-2022
//Name: Oleksandr Shyryayev
//Description: Descriptive Statistics

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int value, frequency;
long double input, sum, sum2, sum3, mean, median, v, s;
vector<double>vec;

void sortValues();
void getMean();
void getMedian();
void getMode();
void getVariance();
void getStandardDeviation();

int main()
{
    cout << "No. of values: ";
    cin >> value;
    cout << endl;
    for(int i = 0; i < value; i++){
        cout << i+1 << " value: ";
        cin >> input;
        vec.push_back(input);
    }
    cout << endl;
    cout << " -----------------------------------------------------------" << endl;
    cout << "| " << setw(20) << "Values";
    cout << "| ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << "; ";
    }
    cout << endl;
    cout << " -----------------------------------------------------------" << endl;
    sortValues();
    cout << " -----------------------------------------------------------" << endl;
    getMean();
    getMedian();
    getMode();
    getVariance();
    getStandardDeviation();
    cout << " -----------------------------------------------------------" << endl;

    return 0;
}

void sortValues(){
    sort(vec.begin(), vec.end());
    cout << "| " << setw(20) << "Sorted Values";
    cout << "| ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << "; ";
    }
    cout << endl;
}

void getMean(){
    for(int i = 0; i < vec.size(); i++){
        sum += vec[i];
    }
    mean = sum / vec.size();
    cout << "| " << setw(20) << "Mean ";
    cout << "| " << setw(35) << mean << " |" << endl;
}

void getMedian(){
    sort(vec.begin(), vec.end());
    if(vec.size() % 2 == 0){
        sum2 = vec[(vec.size() / 2) - 1] + vec[vec.size() / 2];
        median = sum2 / 2;
        cout << "| " << setw(20) << "Median ";
        cout << "| " << setw(35) << median << " |" << endl;
    }else{
        median = vec[value / 2];
        cout << "| " << setw(20) << "Median ";
        cout << "| " << setw(35) << median << " |" << endl;
    }
}

void getMode(){
    map<double, double> duplicate;
    vector<double> nums_sorted{vec};

    sort(begin(nums_sorted), end(nums_sorted));
    auto beg = begin(nums_sorted) + 1;

    for (;beg != end(nums_sorted); ++beg) {
        if (*beg == *(beg - 1)) {
            duplicate[*beg]++;
        }
    }

    for (const auto& i : duplicate){
        cout << "| " << setw(20) << "Mode ";
        cout << "| " << setw(20) << i.first << " (frequency: " << i.second + 1 << ") |" << endl;
    }
}

void getVariance(){
    for(int i = 0; i < vec.size(); i++){
        sum3 += pow(vec[i] - mean, 2);
    }
    v = sum3 / ((vec.size() - 1));
    cout << "| " << setw(20) << "Variance ";
    cout << "| " << setw(35) << v << " |" << endl;
}

void getStandardDeviation(){
    s = sqrt(v);
    cout << "| " << setw(20) << "Standard Deviation ";
    cout << "| " << setw(35) << s << " |" << endl;
}
