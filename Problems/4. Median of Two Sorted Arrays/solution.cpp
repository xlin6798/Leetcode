class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int numSize = nums1.size() + nums2.size();
        int mid = (numSize % 2 == 0) ? numSize / 2 - 1 : numSize / 2;
        if (nums1.size() == 0)
            return (nums2.size() % 2 == 0) ? ((double)nums2[mid] + nums2[mid + 1]) / 2 : nums2[mid];
        if (nums2.size() == 0)
            return (nums1.size() % 2 == 0) ? ((double)nums1[mid] + nums1[mid + 1]) / 2 : nums1[mid];
        int x = 0, y = 0;
        for (int i = 0; i < mid; i++)
        {
            if (x == nums1.size())
                y++;
            else if (y == nums2.size())
                x++;
            else if (nums1[x] > nums2[y])
                y++;
            else
                x++;
        }
        if (numSize % 2 == 1)
        {
            if (x == nums1.size())
                return nums2[y];
            else if (y == nums2.size())
                return nums1[x];
            return std::min(nums1[x], nums2[y]);
        }
        if (x == nums1.size())
            return ((double)nums2[y] + nums2[y + 1]) / 2;
        else if (y == nums2.size())
            return ((double)nums1[x] + nums1[x + 1]) / 2;
        if (nums1[x] > nums2[y])
        {
            if (y + 1 < nums2.size())
                return ((double)nums2[y] + std::min(nums2[y + 1], nums1[x])) / 2;
        }
        else
        {
            if (x + 1 < nums1.size())
                return ((double)nums1[x] + std::min(nums2[y], nums1[x + 1])) / 2;
        }
        return ((double)nums1[x] + nums2[y]) / 2;
    }
};
