#include <iostream>
#include <vector>
using namespace std;

// Problem: set_matrix_zeroes_lc_73.cpp
// Pattern : Matrix Marking
// Time : O(m*n)
// Space: O(m+n)

void setZeroesBetter(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // hume row or columns ko mark karna hai ki kaunsi row or column mein zero present hai. and usko zero karna hai. iske liye hum do extra arrays use karenge.
    vector<int> row(rows, 0);
    vector<int> col(cols, 0);

    // Mark rows and columns containing zero.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Update matrix using markers.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Problem: set_matrix_zeroes_lc_73.cpp
// Pattern : Matrix Marking
// Constraint:
// 1. Modify matrix in-place
// 2. First row & first column are used as markers
// Time : O(m*n)
// Space: O(1)

void setZeroesOptimal(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // to humn eye isliye banaya, matrix[0][0] first row ka marker bhi ho sakta hai. matrix[0][0] first column ka marker bhi ho sakta hai. to hume first column ke liye alag se marker banana padega. isliye col0 variable banaya.
    int col0 = 1;

    // Store markers in first row & first column.
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
        {
            col0 = 0;
        }

        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                // ye batyga ki konsi row or column mein zero present hai. isko zero karna hai.
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Traverse backwards so markers are not destroyed early.
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }

        if (col0 == 0)
        {
            matrix[i][0] = 0;
        }
    }
}

/*
Problem:
Ek M x N matrix diya gaya hai.
Agar kisi bhi cell mein 0 present hai,
toh uski complete row aur column ko 0 karna hai.

Input:
[
  [1, 1, 1],
  [1, 0, 1],
  [1, 1, 1]
]

Output:
[
  [1, 0, 1],
  [0, 0, 0],
  [1, 0, 1]
]

Approach: Two Extra Arrays (Row and Column Marking)

Steps:
1. Matrix ki total rows calculate karo.
   - rows = matrix.size()
2. Matrix ke total columns calculate karo.
   - cols = matrix[0].size()
3. Do extra arrays initialize karo:
   - vector<int> row(rows, 0)
   - vector<int> col(cols, 0)
4. Matrix ko nested loops se traverse karo.
5. Agar matrix[i][j] == 0 hai:
   - row[i] = 1 kar do.
   - col[j] = 1 kar do.
6. Isse pata chal jayega ki kaunsi row aur column mein
   initially zero present tha.
7. Ab matrix ko dobara traverse karo.
8. Har cell ke liye check karo:
   - Agar row[i] == 1 ya col[j] == 1 hai:
     - matrix[i][j] = 0 kar do.
9. Finally, updated matrix return ho jayega.
   - Function void hai, isliye matrix directly modify hota hai.

TC: O(rows * cols) - First nested loop matrix ko traverse karta hai.
     Second nested loop bhi matrix ko traverse karta hai.
     Dono operations O(rows * cols) time lete hain.
     Overall Time Complexity O(rows * cols) hai.

SC: O(rows + cols) - Row array mein rows elements aur
     column array mein cols elements store hote hain.
     Overall Auxiliary Space Complexity O(rows + cols) hai.

Important:
- row array batata hai ki kaunsi row zero honi chahiye.
- col array batata hai ki kaunsa column zero hona chahiye.
- row[i] = 1 ka matlab complete ith row zero hogi.
- col[j] = 1 ka matlab complete jth column zero hoga.
- Pehle marking karte hain, uske baad matrix update karte hain.
- Dono arrays mein initially 0 store hota hai.
- row[i] || col[j] ka matlab dono mein se koi ek condition true ho.
- Original matrix modify hota hai.
- Extra Space O(rows + cols) use hoti hai.
*/

/*
Problem:
Ek M x N matrix diya gaya hai.
Agar kisi bhi cell mein 0 present hai,
toh uski complete row aur column ko 0 karna hai.

Input:
[
  [1, 1, 1],
  [1, 0, 1],
  [1, 1, 1]
]

Output:
[
  [1, 0, 1],
  [0, 0, 0],
  [1, 0, 1]
]

Approach: In-place Marking (First Row & First Column)

Steps:
1. Matrix ki total rows aur columns calculate karo.
2. Ek variable col0 = 1 initialize karo.
   - Ye first column ke liye separate marker hai.
3. Matrix ko top to bottom traverse karo.
4. Har row ke liye sabse pehle check karo:
   - Agar matrix[i][0] == 0 hai:
     - col0 = 0 kar do.
5. Ab inner loop col = 1 se cols-1 tak chalao.
6. Agar matrix[i][j] == 0 hai:
   - matrix[i][0] = 0 kar do.
   - matrix[0][j] = 0 kar do.
7. Is tarah first column aur first row mein markers store ho jayenge.
8. Ab matrix ko reverse order mein traverse karo:
   - i = rows-1 se 0 tak.
   - j = cols-1 se 1 tak.
9. Har cell ke liye check karo:
   - Agar matrix[i][0] == 0 ya matrix[0][j] == 0 hai:
     - matrix[i][j] = 0 kar do.
10. Har row mein inner loop complete hone ke baad:
    - Agar col0 == 0 hai:
      - matrix[i][0] = 0 kar do.
11. Finally, matrix zeroes ke saath update ho jayega.

TC: O(rows * cols) - First traversal mein matrix ke saare
     elements check hote hain.
     Second traversal mein bhi matrix traverse hota hai.
     Overall Time Complexity O(rows * cols) hai.

SC: O(1) - Koi extra array ya matrix use nahi hoti.
     Sirf col0 variable use hota hai.
     Auxiliary Space Complexity O(1) hai.

Important:
- First row aur first column ko marker ki tarah use karte hain.
- col0 variable first column ki original zero condition store karta hai.
- matrix[i][0] row marker ka kaam karta hai.
- matrix[0][j] column marker ka kaam karta hai.
- First traversal mein sirf marking karte hain.
- Second traversal mein matrix update karte hain.
- Second traversal reverse order mein hota hai.
- Reverse traversal markers ko jaldi overwrite hone se bachata hai.
- col0 == 0 hone par first column ko zero karte hain.
- Is approach mein Auxiliary Space O(1) hoti hai.
*/

