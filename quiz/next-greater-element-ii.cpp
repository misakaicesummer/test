/*
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
注意: 输入数组的长度不会超过 10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size()*2);
        stack<int> s;
        vector<int> nums1;
        nums1.insert(nums1.end(),nums.begin(),nums.end());
        nums1.insert(nums1.end(),nums.begin(),nums.end());
        for(int i=nums1.size()-1;i>=0;i--)
        {
            while (!s.empty()&&nums1[i]>=s.top())
            {
                s.pop();
            }
            res[i]=s.empty()?-1:s.top();
            s.push(nums1[i]);
        }
        auto iter1=res.begin();
        auto iter2=iter1+nums.size();
        return vector<int>(iter1,iter2);
    }
};
int main()
 {
     Solution a;
     vector<int> nums1={1,2,1};
     auto result=a.nextGreaterElements(nums1);
     return 0;
 }