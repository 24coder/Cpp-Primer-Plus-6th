/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=20003
 *
 * [80] 删除有序数组中的重复项 II
 */


// @lcpr-template-start

using namespace std;
#include <cassert>
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <singleton.h>
// @lcpr-template-end
// @lc code=start

class Solution {
static int Solution_num;
public:
    Solution(int value) {
        Solution_num = value;
        cout << "Constructor called, sharedValue set to " << Solution_num << endl;
    }

    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0){
            return 0;
        }
        int slow = 1,count = 1;
        for(int fast = 1;fast < nums.size();fast++){
            if(nums[fast] ==nums[fast-1]){
                count++;
            }else{
                count=1;
            }
            if(count <= 2){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};




class SingletonSolution {
private:
    static SingletonSolution* instance;
    int Solution_num;

    // 私有构造函数防止外部实例化
    SingletonSolution(int value) : Solution_num(value) {
        cout << "Constructor called, sharedValue set to " << Solution_num << endl;
    }

public:
    // 删除拷贝构造函数和赋值操作符以防止复制
    SingletonSolution(const SingletonSolution&) = delete;
    SingletonSolution& operator=(const SingletonSolution&) = delete;

    // 获取单例实例的方法
    static SingletonSolution* getInstance(int value) {
        if (instance == nullptr) {
            instance = new SingletonSolution(value);
        }
        return instance;
    }

    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0){
            return 0;
        }
        int slow = 1, count = 1;
        for(int fast = 1; fast < nums.size(); fast++){
            if(nums[fast] == nums[fast-1]){
                count++;
            } else {
                count = 1;
            }
            if(count <= 2){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }

    ~SingletonSolution() {
        cout << "Destructor called" << endl;
    }
};




class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count = 0;
        
        // Step 1: Find the candidate
        for (auto num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */

void testRemoveDuplicates() {
    Solution solution();
    vector<int> nums;

    // 测试有超过两次重复元素
    nums = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4};
    // assert(solution.removeDuplicates(nums) == 9);
    // assert((nums == vector<int>{1, 1, 2, 2, 3, 3, 4, 4, 4}));
}
// 初始化静态成员变量
int Solution::Solution_num = 0;  // 默认值可以是任何你想要的初始值
SingletonSolution* SingletonSolution::instance = nullptr;
int main() {
    
    // testRemoveDuplicates();

    // Solution1 solution;
    // std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    // int expected = 2;

    // // Call the method and store the result
    // int result = solution.majorityElement(nums);
    // cout << result <<endl;
    // // Assert that the result matches the expected value
    // // assert(result == expected);
    Solution solution1(1);
    Solution solution2(2);


    vector<int> nums = {1, 1, 1, 2, 2, 3};
    SingletonSolution* solution = SingletonSolution::getInstance(42); // 设置共享值为42
    int result = solution->removeDuplicates(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < result; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;















    system("pasue");
    return 0;

}