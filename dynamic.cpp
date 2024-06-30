#include <bits/bits-stdc++.h>
using namespace std;

int coinChangeAlgorithm(int n, const std::vector<int>& coins) {
    // Khởi tạo mảng A với kích thước n+1 và gán giá trị vô cực cho tất cả các phần tử
    vector<int> A(n + 1, INT_MAX);
    A[0] = 0;  // Số đồng xu cần thiết để đổi số tiền 0 là 0

   
    for (int x = 1; x <= n; ++x) {
        int howmanycoins = INT_MAX;  // Khởi tạo biến lưu số đồng xu tối thiểu cần cho số tiền x

        // Duyệt qua từng loại đồng xu
        for (int coin : coins) {
            if (x - coin >= 0) {
                // Tính số đồng xu tối thiểu cho số tiền x
                howmanycoins = min(howmanycoins, 1 + A[x - coin]);
            }
        }

        // Cập nhật mảng A với số đồng xu tối thiểu cho số tiền x
        A[x] = howmanycoins;
    }

    // Nếu A[n] là vô cực, điều đó có nghĩa không thể đổi được số tiền n với các mệnh giá đồng xu hiện có
    return (A[n] == INT_MAX) ? -1 : A[n];
}

int main() {
   
    vector<int> coins = {1, 2, 5};

   
    int amount = 11;

   
    int result = coinChangeAlgorithm(amount, coins);

    
    if (result != -1) {
        cout << "Số đồng xu tối thiểu cần để đổi " << amount << " là: " << result << std::endl;
    } else {
        cout << "Không thể đổi số tiền " << amount << " với các mệnh giá đồng xu hiện có.\n";
    }

    return 0;
}
