#include <bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{

    int size = flowerbed.size();

    for (int i = 0; i < size; i++)
    {

        // Already space occupied hai
        if (flowerbed[i] == 1)
        {
            continue;
        }

        // check ki ye pehle flower bed to nahi kyuki iske left m kuch nahi hai ya || left m koi flower already planted to nahi hai
        bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
        
        // check ki ye last flower bed to nahi kyuki iske right m kuch nahi hai ya || left m koi flower already planted to nahi hai
        bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);

        // hn to agar ye condition true hai to plant karo or jitne flowers lagane the unko ek ek karke kam karte jynge
        if (leftEmpty && rightEmpty)
        {
            // flower laga diya current position par
            flowerbed[i] = 1;
            n--;

            // to jitne flowers diye gaye the utne to ho gaye hai
            if (n == 0)
            {
                return true;
            }
        }
    }

    
    return n <= 0;
}

int main()
{

    vector<int> flowerbed = {1, 0, 0, 0, 1};

    int n = 1;

    cout << boolalpha
         << canPlaceFlowers(flowerbed, n)
         << endl;

    return 0;
}