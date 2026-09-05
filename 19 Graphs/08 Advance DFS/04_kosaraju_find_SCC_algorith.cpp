#include <bits/stdc++.h>
using namespace std;

// ============================================================
// STEP 1 DFS
// ============================================================
// Original graph par DFS karta hai.
// DFS complete hone ke baad node ko stack mein push karta hai.
//
// Isse humein nodes ka finishing order milta hai.
void dfs1(int u, vector<vector<int>> &graph, vector<int> &visited, stack<int> &st)
{
    visited[u] = true;

    // u ke saare neighbours par DFS
    for (int v : graph[u])
    {

        if (!visited[v])
        {
            dfs1(v, graph, visited, st);
        }
    }

    // Jab u ki DFS complete ho gayi,
    // tab u ko stack mein push karo.
    st.push(u);
}

// ============================================================
// STEP 2 DFS
// ============================================================
// Transpose graph par DFS karta hai.
//
// Jo bhi nodes is DFS mein milenge,
// woh ek hi Strongly Connected Component (SCC) ke nodes hain.
void dfs2(int u, vector<vector<int>> &transpose, vector<int> &visited, vector<int> &component)
{
    visited[u] = true;

    // Current node ko current component mein save karo
    component.push_back(u);

    // Transpose graph ke neighbours par DFS
    for (int v : transpose[u])
    {

        if (!visited[v])
        {
            dfs2(v, transpose, visited, component);
        }
    }
}

// ============================================================
// PRINT COMPONENTS
// ============================================================
// Saari SCCs ko print karta hai.
void printComponents(vector<vector<int>> &components)
{
    cout << "\nStrongly Connected Components:\n";

    for (int i = 0; i < components.size(); i++)
    {

        cout << "Component " << i + 1 << ": ";

        for (int node : components[i])
        {
            cout << node << " ";
        }

        cout << "\n";
    }
}

// ============================================================
// KOSARAJU ALGORITHM
// ============================================================
// Directed graph ki saari Strongly Connected Components
// find karta hai.
//
// Return:
// vector<vector<int>>
// Har inner vector ek SCC/component ko represent karta hai.
vector<vector<int>> kosaraju(int n, vector<vector<int>> &graph)
{

    // --------------------------------------------------------
    // visited array
    // --------------------------------------------------------
    // visited[i] = true means node i already visited hai.
    vector<int> visited(n, false);

    // DFS finishing order store karne ke liye stack
    stack<int> st;

    // ========================================================
    // STEP 1: Original Graph par DFS
    // ========================================================
    for (int i = 0; i < n; i++)
    {
        // Agar node visit nahi hui,
        // to us node se DFS start karo.
        if (!visited[i])
        {

            dfs1(i, graph, visited, st);
        }
    }

    // ========================================================
    // STEP 2: Transpose Graph banao
    // ========================================================
    //
    // Original:
    //
    // u ----> v
    //
    // Transpose:
    //
    // u <---- v
    //
    vector<vector<int>> transpose(n);

    for (int u = 0; u < n; u++)
    {
        for (int v : graph[u])
        {
            // Edge u -> v ko reverse karke
            // v -> u bana rahe hain.
            transpose[v].push_back(u);
        }
    }

    // ========================================================
    // STEP 3: visited reset karo
    // ========================================================
    //
    // Ab transpose graph par fresh DFS karni hai.
    // Isliye visited ko dobara false karna padega.
    fill(visited.begin(), visited.end(), false);

    // ========================================================
    // STEP 4: Components save karna
    // ========================================================
    //
    // Ye vector saari SCCs ko store karega.
    //
    // Example:
    //
    // components = {
    //     {0, 1, 2},
    //     {3, 4},
    //     {5}
    // };
    //
    vector<vector<int>> components;

    // ========================================================
    // STEP 5: Stack ke order mein DFS
    // ========================================================
    while (!st.empty())
    {

        // Highest finishing-time wali node nikalo
        int u = st.top();
        st.pop();

        // Agar node already visited nahi hai,
        // to ye ek new SCC start karegi.
        if (!visited[u])
        {

            // Current SCC ke nodes yahan save honge
            vector<int> component;

            // Transpose graph par DFS
            dfs2(u, transpose, visited, component);

            // Complete SCC ko components mein save karo
            components.push_back(component);
        }
    }

    // ========================================================
    // STEP 6: Components print karo
    // ========================================================
    printComponents(components);

    // ========================================================
    // STEP 7: Components return karo
    // ========================================================
    return components;
}

// ============================================================
// MAIN FUNCTION
// ============================================================
int main()
{

    int n = 5;

    vector<vector<int>> graph(n);

    // Graph:
    //
    // 0 -> 1
    // 1 -> 2
    // 2 -> 0
    //
    // 2 -> 3
    // 3 -> 4
    // 4 -> 3
    //
    graph[0].push_back(1);
    graph[1].push_back(2);
    graph[2].push_back(0);

    graph[2].push_back(3);

    graph[3].push_back(4);
    graph[4].push_back(3);

    // ========================================================
    // Kosaraju call
    // ========================================================
    //
    // components variable mein saari SCCs save ho jaayengi.
    vector<vector<int>> components =
        kosaraju(n, graph);

    // ========================================================
    // Components ko main mein bhi access kar sakte hain
    // ========================================================
    cout << "\nTotal Components: "
         << components.size()
         << "\n";

    // Example: har component ke nodes access karna
    cout << "\nSaved Components:\n";

    for (int i = 0; i < components.size(); i++)
    {

        cout << "SCC " << i + 1 << " = { ";

        for (int node : components[i])
        {
            cout << node << " ";
        }

        cout << "}\n";
    }

    return 0;
}