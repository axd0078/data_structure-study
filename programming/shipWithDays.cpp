#include <iostream>
#include <vector>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int getDays(int* weights, int capacity, int weightsSize){
    int day = 1;
    int load = 0;
    for(int i = 0; i < weightsSize; i++){
        if(load + weights[i] > capacity){   //capacity再多一个货物就已经装不下了
            day++;
            load = 0;
        }
        load += weights[i]; //  否则加load
    }
    return day;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = 0;
    int high = 0;
    for(int i = 0; i < weightsSize; i++){
        low = MAX(low, weights[i]);
        high += weights[i];
    }

    int k = high;
    while(low < high){
        int capacity = (high - low) / 2 + low;
        int needDays = getDays(weights, capacity, weightsSize);
        if(needDays > days){
            low = capacity + 1;
        }
        else{
            k = capacity;
            high = capacity;
        }
    }
    return k;
}

int main(){
    int weightsSize, days;
    cin >> weightsSize >> days;

    vector<int> weights(weightsSize);
    for(int i = 0; i < weightsSize; i++){
        cin >> weights[i];
    }

    cout << shipWithinDays(weights.data(), weightsSize, days) << endl;
    return 0;
}
