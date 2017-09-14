class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n = (n1 + n2 - 1) / 2;
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = min(n1, n);
        while(l < r) {
            int m = l + (r-l)/2, m2 = n - m;
            if (nums2[m2] <= nums1[m]) r = m;
            else l = m + 1;
        }
        // nums1[l-1], nums1[l], nums2[n-l], nums2[n-l+1]
        int smv = INT_MIN;
        if (l>0) smv = max(smv, nums1[l-1]);
        if (n-l>=0) smv = max(smv, nums2[n-l]);
        if ((n1+n2) & 1) return (double)smv;

        int lgv = INT_MAX;
        if (l<n1) lgv = min(lgv, nums1[l]);
        if (n-l+1<n2) lgv = min(lgv, nums2[n-l+1]);
        return (smv + lgv) / 2.0;
    }
};
