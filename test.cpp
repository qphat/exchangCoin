#include <bits/stdc++.h>
using namespace std;

int coinCount( const vector<int> C, int n) {
    vector<int> A(n + 1, 0);
    A[0] = 1;  // Có 1 cách để đổi số tiền 0, đó là không dùng đồng xu nào cả

    for(int c : C) {
        for(int i = 1; i <= n; ++i) {
            if(i >= c) {
                A[i] += A[i - c];
            }
        }
    }
}