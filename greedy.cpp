#include <bits/stdc++.h>     
using namespace std;

    set<int> cashierAlgorithm(int amount, const vector<int>& coins) {
    set<int> selectedCoins;  // Tập hợp các đồng xu đã chọn
    int n = coins.size();        // Số lượng loại đồng xu

    // Lặp cho đến khi số tiền còn lại cần đổi là 0
    while (amount > 0) {
        bool coinFound = false;

        // Tìm loại đồng xu lớn nhất nhỏ hơn hoặc bằng số tiền còn lại
        for (int i = 0; i < n; ++i) {
            if (coins[i] <= amount) {
                selectedCoins.insert(coins[i]);  // Thêm đồng xu vào tập hợp kết quả
                amount -= coins[i];  // Giảm số tiền còn lại theo giá trị đồng xu
                coinFound = true;
                break;  // Thoát khỏi vòng lặp sau khi tìm được đồng xu phù hợp
            }
        }

        // Nếu không tìm được đồng xu phù hợp, thông báo không có giải pháp
        if (!coinFound) {
            cout << "Không có giải pháp với các mệnh giá đồng xu hiện có.\n";
            return {};  // Trả về tập hợp rỗng nếu không có giải pháp
        }
    }

    return selectedCoins;  // Trả về tập hợp các đồng xu được sử dụng
}

int main() {
    
    vector<int> coins = {100, 50, 25, 10, 5, 1};

    int amount = 287;


    set<int> result = cashierAlgorithm(amount, coins);

   
    cout << "Các đồng xu được sử dụng để đổi " << amount << " là:\n";
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;

    return 0;
}
