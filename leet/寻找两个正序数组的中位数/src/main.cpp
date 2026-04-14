#include <algorithm>
#include <climits>
#include <cstddef>
#include <vector>

class Solution
{
  public:
    double
    findMedianSortedArrays (std::vector<int> &nums1, std::vector<int> &nums2)
    {
        if (nums1.size () > nums2.size ())
            {
                return findMedianSortedArrays (nums2, nums1);
            }

        int m{ static_cast<int> (nums1.size ()) };
        int n{ static_cast<int> (nums2.size ()) };
        int total{ m + n };

        int low{ 0 };
        int high{ m };

        while (low <= high)
            {
                int i{ (low + high) / 2 };
                int j{ (total + 1) / 2 - i };

                int left1_max
                    = (i == 0) ? INT_MIN : nums1[static_cast<size_t> (i - 1)];
                int right1_min
                    = (i == m) ? INT_MAX : nums1[static_cast<size_t> (i)];
                int left2_max
                    = (j == 0) ? INT_MIN : nums2[static_cast<size_t> (j - 1)];
                int right2_min
                    = (j == n) ? INT_MAX : nums2[static_cast<size_t> (j)];

                if (left1_max > right2_min)
                    {
                        high = i - 1;
                    }
                else if (left2_max > right1_min)
                    {
                        low = i + 1;
                    }
                else
                    {
                        if (total % 2 == 1)
                            {
                                return (double)std::max (left1_max, left2_max);
                            }
                        else
                            {
                                return (std::max (left1_max, left2_max)
                                        + std::min (right1_min, right2_min))
                                       / 2.0;
                            }
                    }
            }
        return 0.0;
    }
};

int
main ()
{
    return 0;
}
