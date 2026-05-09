#include <cstddef>
#include <unordered_map>
#include <vector>

class Solution
{
  public:
    std::vector<int>
    ToSum (std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> map;

        for (int i{ 0 }; static_cast<size_t> (i) < nums.size (); ++i)
            {
                int complement{ target - nums[static_cast<size_t> (i)] };

                // end() 返回的是指向 unordered_map 中 最后一个元素之后
                // 的迭代器（past-the-end
                // iterator）。这个迭代器本身不指向任何有效元素，不能解引用（即不能通过
                // *it
                // 访问）。它主要用作边界标记，例如在遍历或查找时判断是否到达容器末尾
                if (map.find (complement) != map.end ())
                    {
                        // 如果没找到
                        return { map[complement], i };
                    }
                map[nums[static_cast<size_t> (i)]] = i;
            }
        return {};
    }
};
