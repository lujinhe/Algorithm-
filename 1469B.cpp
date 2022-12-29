#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int r[N], b[N];
int countTimes[N];
void start(){
    int n , m;
    int rSum = 0 , bSum = 0;
    cin>> n ;
    for(int i = 1;i <= n; i++){
       cin>> r[i];
       r[i] += r[i-1];
       rSum = max(r[i] , rSum);
    }
    cin >> m ;
    for(int i = 1;i <= m; i++){
        cin>>b[i];
        b[i] += b[i-1];
        bSum = max(b[i] , bSum);
    }
    cout<< max( 0 , max(rSum + bSum , max(rSum, bSum))) <<endl;
}
int main(){
    int t = 1;
    cin>> t;
    while(t--){
        start();
    }
    return 0;

}
