#include <cstddef>
#include <vector>

class Solution
{
  public:
    std::vector<int>
    twoSum (std::vector<int> &nums, int target)
    {
        std::vector<int> Re;
        for (size_t j = 0; j < nums.size (); j++)
            {
                for (size_t i = j + 1; i < nums.size (); i++)
                    {
                        if (target == nums[j] + nums[i])
                            {
                                Re.push_back (static_cast<int> (j));
                                Re.push_back (static_cast<int> (i));
                                return Re;
                            }
                    }
            }
        return {};
    }
};

int
main ()
{
}
