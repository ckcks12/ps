/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (28.47%)
 * Likes:    6153
 * Dislikes: 942
 * Total Accepted:    613K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int k = 0;
        double nums[nums1.size() + nums2.size()];
        while (i < nums1.size() && j < nums2.size()) {
            int n = nums1[i];
            int m = nums2[j];
            if (n <= m) {
                nums[k++] = n;
                i++;
            } else if (m < n) {
                nums[k++] = m;
                j++;
            }
        }
        for (; i < nums1.size(); i++) nums[k++] = nums1[i];
        for (; j < nums2.size(); j++) nums[k++] = nums2[j];
        if (k & 1) {
            return nums[k / 2];
        } else {
            int ia = k / 2.0 - 1;
            int ib = k / 2.0;
            double a = nums[ia];
            double b = nums[ib];
            return (a + b) / 2.0;
        }
    }
};
// @lc code=end
