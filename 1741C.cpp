#include <iostream>
using namespace std;
const int N = 1e4 + 10;
long long a[N], pre[N];
void start(){
    int n ,ans = N;
    cin>> n;
    for(int i = 1;i <= n; i++){
        cin>> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        int aim = pre[i];
        int lastPoint = i;
        int theMaxSegment = i;
        for(int j = i+1; j <= n; j++){
            if( pre[j] - pre[lastPoint] < aim) continue;
            else if(pre[j] - pre[lastPoint] > aim) break;
            else {
                theMaxSegment = max(theMaxSegment , j - lastPoint);
                lastPoint = j;
            }
        }
        if(lastPoint == n) ans = min(ans , theMaxSegment);
    }
    cout<< ans << endl;
}
int main(){
    int t = 1;
    cin>> t;
    while(t--){
        start();
    }
    return 0;
}
