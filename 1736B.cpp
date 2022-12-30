#include <iostream>
using namespace std;
const int N = 1e6 + 10;
long long a[N], b[N];
int countTimes[N];
long long  gcd(long long a, long long b){
    if(b) return gcd(b,a%b);
    else return a;
}
void start(){
    int n;
    cin>> n;
    for(int i = 0;i < n; i++)
        cin>>a[i];
    if(n < 3) cout<<"Yes"<<endl;
    else {
        b[0] = a[0];
        b[1] = b[0];
        for(int i = 2; i <= n; i++){
            int j = i - 1;
            b[i] = a[j];
            long long theCommonPart = gcd(a[j],b[j]);
            b[j] = b[j] * a[j] / theCommonPart;
        }
    bool bad  = false;
    for(int i = 0; i < n ; i++)
        if( gcd(b[i+1],b[i]) != a[i]) bad = true;
    cout<< (bad?"No":"Yes")<<endl;
    }
}
int main(){
    int t = 1;
    cin>> t;
    while(t--){
        start();
    }
    return 0;
}
