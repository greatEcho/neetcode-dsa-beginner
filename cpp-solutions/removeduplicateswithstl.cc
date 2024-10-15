#include <iostream>
#include <vector>

using std::cout;

int main()
{
    std::vector<int> nums = {0,0,5,1,1,1};
    size_t len = nums.size();

    nums.push_back(7);
    nums.erase(nums.begin() + 2);
    //nums.erase(0);
    for (size_t i=0; i<nums.size();i++)
        cout << nums[i] << " ";
    cout << std::endl;

    cout << len << std::endl;

}
