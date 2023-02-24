// use vector<int> to store the intersection of two arrays
// time complexity: O(n^2)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;
        for (int i = 0; i < nums1.size(); i++) {
            if ((count(nums2.begin(), nums2.end(), nums1[i])) && 
                !(count(intersection.begin(), intersection.end(), nums1[i]))) {
                intersection.emplace_back(nums1[i]);
            }
        }
        return intersection; 
    }
};

// use unordered_set to store the intersection of two arrays
// time complexity: O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> intersection;
        unordered_set<int> num1(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (num1.find(num) != intersection.end()) {
                intersection.insert(num);
            }
        }
        return vector<int>(intersection.begin(), intersection.end());
    }
};