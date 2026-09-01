#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Problem : Image Smoother (LC 661)
// Pattern : 8-Direction Matrix Traversal
//
// Time  : O(rows × cols)
// Space : O(rows × cols)
//
// Learning:
// 1. Traverse every cell.
// 2. Visit all 8 neighbours + current cell.
// 3. Ignore neighbours outside matrix.
// 4. Store average in a new matrix.
//--------------------------------------------------

vector<vector<int>> imageSmoother(const vector<vector<int>> &img)
{
    int rows = img.size();
    int cols = img[0].size();

    // Result matrix.
    vector<vector<int>> answer(rows, vector<int>(cols));

    //--------------------------------------------------
    // Direction arrays for 3x3 neighbourhood.
    //
    // ↖ ↑ ↗
    // ← X →
    // ↙ ↓ ↘
    //--------------------------------------------------

    int dr[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

    //--------------------------------------------------
    // Visit every cell.
    //--------------------------------------------------
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int sum = 0;
            int count = 0;

            //--------------------------------------------------
            // Visit all 9 positions.
            //--------------------------------------------------
            for (int k = 0; k < 9; k++)
            {
                int newRow = i + dr[k];
                int newCol = j + dc[k];

                // Ignore invalid neighbours.
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
                {
                    sum += img[newRow][newCol];
                    count++;
                }
            }

            // Integer division automatically floors the answer.
            answer[i][j] = sum / count;
        }
    }

    return answer;
}

//--------------------------------------------------
// Print matrix.
//--------------------------------------------------
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int value : row)
        {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main()
{
    int rows, cols;

    cin >> rows >> cols;

    vector<vector<int>> img(rows, vector<int>(cols));

    // Input image.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> img[i][j];
        }
    }

    vector<vector<int>> answer = imageSmoother(img);

    printMatrix(answer);

    return 0;
}