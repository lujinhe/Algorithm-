#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int countTimes[N];
void start(){
    int realN , n = 0, allTimes = 0, x;
    cin>> realN;
    for(int i = 0;i < realN; i++){
        cin>> x;
        if(i == 0) {
        countTimes[x]++;
        a[n++] = x;
        }
        if(i > 0 && x != a[n-1]) { // 艹， 这里大E了，不然早tm过了
        a[n++] = x;
        countTimes[x]++;
        }
    }
    int theFirstPoint = -1;
    for(int i = n - 1;i >= 0; i--){
        if(i == n - 1){
            if(countTimes[a[i]] > 1){
                theFirstPoint = i;
                break;
            }
        }else {
            if(a[i] > a[i+1] || countTimes[a[i]] > 1) {
                theFirstPoint = i;
                break;
            }
        }
    }
    for(int i = theFirstPoint ; i >= 0; i--){
        if( countTimes[a[i]] ){
        allTimes += 1;
        countTimes[a[i]] = 0;
        }
    }
    for(int i = 0 ;i < n; i++) countTimes[a[i]] = 0;
    cout<<allTimes<<endl;
}
int main(){
    int t = 1;
    cin>> t;
    while(t--){
        start();
    }
    return 0;
}
