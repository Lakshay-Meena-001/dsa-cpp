#include<iostream>
using namespace std;

class Solution
{
public:

    // to nums 1 m empty space already diya hai hume bas nums 2 ko nums 1 m merge karna hai sorted order m ab hum kahi tarah se kar sakte hai but best approach ye hai ki hum nums 1 ke end se start karte hue aur nums 2 ke end se start karte hue compare karte hue largest element ko nums 1 ke end m dalte jaayein
    void merge(int nums1[], int m, int nums2[], int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0)
        {
            if(nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        // to bache hue elements ko nums 1 m dal do
        while(j >= 0)
        {
            nums1[k] = nums2[j];

            j--;
            k--;
        }
    }
};

int main()
{
    int nums1[6] = {1,2,3,0,0,0};

    int nums2[3] = {2,5,6};

    Solution obj;

    obj.merge(nums1,3,nums2,3);

    for(int x : nums1)
        cout<<x<<" ";

    return 0;
}