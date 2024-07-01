#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coinChange(int amount, const vector<int>& coins) {
    // Khởi tạo mảng dp với kích thước amount + 1 và gán giá trị vô cực cho tất cả các phần tử
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;  // Số đồng xu cần thiết để đổi số tiền 0 là 0

    // Duyệt qua từng số tiền từ 1 đến amount
    for (int i = 1; i <= amount; ++i) {
        // Duyệt qua từng loại đồng xu
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                // Tính số đồng xu tối thiểu cho số tiền i
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    // Nếu dp[amount] là vô cực, điều đó có nghĩa không thể đổi được số tiền amount với các mệnh giá đồng xu hiện có
    if (dp[amount] == INT_MAX) {
        return -1;
    }
    return dp[amount];
}

int main() {
   
    vector<int> coins = {1, 2, 5};

   
    int amount = 11;

   
    int result = coinChange(amount, coins);

    
    if (result != -1) {
        cout << "Số đồng xu tối thiểu cần để đổi " << amount << " là: " << result << std::endl;
    } else {
        cout << "Không thể đổi số tiền " << amount << " với các mệnh giá đồng xu hiện có.\n";
    }

    return 0;
}
