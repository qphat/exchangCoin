#include <bits/stdc++.h>
using namespace std;

int coincount(const vector<int> C, int n) {
    vector<int> A(n + 1, 0);
    A[0] = 1;  // Có 1 cách để đổi số tiền 0, đó là không dùng đồng xu nào cả

    // Duyệt qua từng loại đồng xu trong mảng C
    for (int c : C) {
        // Cập nhật số cách để đổi số tiền từ 1 đến n với mệnh giá đồng xu hiện tại
        for (int i = 1; i <= n; ++i) {
            if (i >= c) {
                A[i] += A[i - c];
            }
        }
    }

    return A[n];
}

int main() {
    vector<int> coins = {1, 5, 10};
    int amount = 10;

    int result = coincount(coins, amount);

    // In ra kết quả
    cout << "Số cách khác nhau để đổi " << amount << " với các mệnh giá đồng xu là: " << result << endl;

    return 0;
}
