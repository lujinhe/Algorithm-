/*
The DP tutorial :  https://codeforces.com/blog/entry/47764
ProblemSource   :  https://codeforces.com/contest/453/problem/B
This is a part of dp tutorial .
For the problem , it enables person to understand the technique calls "dp whit the bitmasks".
use s = (s - 1) & s  to iterate through the subsets of the set s ;
For the dp , we need to record the prime we already use.
And the total numbers are less than 20.
So we choose bitMasks along with dp to solve this problem.
It's really fucking goooood problem for me .
*/
#include <iostream>
#include <cmath>
using namespace std;
const int INF = 1e9;
const int N = 1e2 + 10;
int primes[20] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int f[60];
int dp[N][1<<17];
int a[N],b[N],pre[N][1<<17];
void start(){
    int n , x,ans = N;
    cin>> n;
    for(int i = 1;i <= n; i++){
        cin>> a[i];
    }
    for(int k = 1;k < 59;k++){
      for(int i = 0 ; i < 16;i++){
        if( k%primes[i] == 0 ){
            f[k] = f[k] | (1 << i);
        }
      }
    }
    for(int i = 0; i <= n;i++){
        for(int s = 0; s < (1<<17); s++){
            dp[i][s] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k < 59;k++){
            int  x = (~f[k]) & ((1 << 17) - 1); // unused
            for(int s = x;  ; s = (s - 1) & x ){
                if( dp[i-1][s] + abs(k - a[i]) < dp[i][s|f[k]] ){
                    dp[i][s|f[k]]  = dp[i-1][s] + abs(k - a[i]);
                    pre[i][s|f[k]] = k;
                }
            if(s == 0) break;
            }
        }
    }
    int aim = 0;
    for(int i = 0;i < (1 << 17); i++){
        if(dp[n][i] < dp[n][aim]) aim = i;
    }
    //cout<< dp[n][aim] << endl;
    int cpN = n;
    while(cpN){
        int k = pre[cpN][aim];
        b[cpN--] = k;
        aim ^= f[k];
    }
    for(int i = 1; i <= n; i++)
        cout<< b[i] << " ";
    cout<<endl;
}
int main(){
    int t = 1;
    //cin>> t;
    while(t--){
        start();
    }
    return 0;
}
