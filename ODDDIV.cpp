#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int divCnt[100001] = {0}, cnt[1500] = {0}, start[1500] = {0};
ll ans[100001] = {0};

int numOfDivisors(int n) {
    int i, res = 1;
    for(i=2; i*i<=n; i++) {
        int cnt = 0;
        while (n%i == 0) {
            n /= i;
            cnt++;
        }
        res *= (2*cnt + 1);
    }
    if(n > 1) {
        res *= 3;
    }
    return res;
}

void calDivCount() {
    int i, k;
    for(i=2; i<=100000; i++) {
        divCnt[i] = numOfDivisors(i);
        cnt[divCnt[i]]++;
    }
    for (k=1, i=0; k<=1323; k+=2) {
        start[k] = i;
        if (!cnt[k])
            continue;
        for (int n = 2; n<100000; n++) {
            if(divCnt[n] == k) {
                ans[i++] = (ll)n*(ll)n;
            }
        }
    }
    start[k] = i;
}

int lower_bound(int k, ll n) {
    int lo, hi, mi;
    if(!cnt[k] || ans[start[k]]>=n) 
        return 0;
    lo = start[k]; 
    hi = start[k+2];
    while(lo < hi-1) {
        mi = (lo + hi)/2;
        if(ans[mi] >= n) 
            hi = mi;
        else 
            lo = mi;
    }
    return lo - start[k] + 1;
}
 
int upper_bound(int k, ll n) {
    int lo, hi, mi;
    if(!cnt[k] || ans[start[k]]>n)
        return 0;
    lo = start[k]; 
    hi = start[k+2];
    while(lo < hi-1) {
        mi = (lo + hi)/2;
        if(ans[mi] > n)
            hi = mi;
        else
            lo = mi;
    }
    return lo - start[k] + 1;
}

int main() {
    int t,k;
    ll low,high;
    calDivCount();
    scanf("%d", &t);
    while(t--) {
        scanf("%d %lld %lld", &k, &low, &high);
        if(k>1323 || !cnt[k]) {
            printf("0\n");
            continue;
        }
        printf("%d\n", upper_bound(k, high) - lower_bound(k, low));
    }
    return 0;
}
