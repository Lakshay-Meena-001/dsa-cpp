#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    // hume to sum II m pata tha ki array sorted hai but yaha wo case nahi to isliye hum two pointers ko is tarah se move nahi kar skte hai 
    // to hum logic us ekarenge jais e ki humne sum II m kiya tha but yaha humne ek unordered_map ka use karenge jisme hum number ko key aur uska index ko value ke roop m store karenge
    //map kya store kar raha hai ki number aur uska index jisse hum easily check kar sake ki kya target - number map m exist karta hai ya nahi 
    unordered_map<int, int> mp;

    // ab hum array ko traverse karenge aur har number ke liye check karenge ki kya target - number map m exist karta hai ya nahi
    for (int i = 0; i < nums.size(); i++)
    {
        // to humne ye check karna hai ki kya target - number map m exist karta hai ya nahi
        int need = target - nums[i];

        // agar exist karta hai to hum uska index return karenge aur agar nahi to hum current number ko map m store karenge
        if (mp.find(need) != mp.end())
        {
            return {mp[need], i};
        }
        // agar exist nahi karta hai to hum current number ko map m store karenge
        mp[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> answer = twoSum(nums, target);

    cout << "[" << answer[0] << ", " << answer[1] << "]\n";

    return 0;
}