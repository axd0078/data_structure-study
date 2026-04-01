#include <iostream>
#include <vector>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

long getTime(int* piles, int x, int pilesSize){
    long hours = 0;
    for(int i = 0; i < pilesSize; i++){
        hours += piles[i] / x;
        if(piles[i] % x > 0){
            hours++;
        }
    }
    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = 0;
    for(int i = 0; i < pilesSize; i++){
        high = MAX(high, piles[i]);
    }

    int k = high;
    while(low < high){
        int speed = (high - low) / 2 + low;
        long time = getTime(piles, speed, pilesSize);
        if(time > h){
            low = speed + 1;
        }
        else{
            k = speed;
            high = speed;
        }
    }
    return k;
}

int main(){
    int pilesSize, h;
    cin >> pilesSize >> h;

    vector<int> piles(pilesSize);
    for(int i = 0; i < pilesSize; i++){
        cin >> piles[i];
    }

    cout << minEatingSpeed(piles.data(), pilesSize, h) << endl;
    return 0;
}
