#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // ============================================================
    // GLOBAL VARIABLES
    // ============================================================

    // Har node ko ek unique discovery time milega.
    //
    // Example:
    // tin[0] = 0
    // tin[1] = 1
    // tin[2] = 2
    //
    // -1 ka matlab node abhi visit nahi hui.
    int timer = 0;

    vector<int> tin;


    // low[u] batata hai ki node u se DFS ke through
    // sabse chhoti discovery time wali active node tak
    // pahunch sakte hain ya nahi.
    vector<int> low;


    // inStack[u] = true
    // matlab node u abhi current DFS stack mein active hai.
    vector<int> inStack;


    // Tarjan DFS ke active nodes ko store karne ke liye stack.
    stack<int> st;


    // Saari Strongly Connected Components yahan save hongi.
    //
    // Example:
    //
    // sccs = {
    //     {2, 1, 0},
    //     {4, 3}
    // };
    vector<vector<int>> sccs;


    // ============================================================
    // DFS FUNCTION
    // ============================================================
    void dfs(
        int u,
        vector<vector<int>>& graph
    ) {

        // --------------------------------------------------------
        // STEP 1: Discovery time assign karo
        // --------------------------------------------------------
        //
        // Jab node pehli baar visit hoti hai,
        // uska tin aur low initially same hota hai.
        //
        // timer++ ke baad timer next node ke liye increase ho jayega.
        //
        tin[u] = low[u] = timer++;


        // --------------------------------------------------------
        // STEP 2: Node ko stack mein daalo
        // --------------------------------------------------------
        //
        // Ye node abhi current SCC ke search mein active hai.
        //
        st.push(u);
        inStack[u] = true;


        // --------------------------------------------------------
        // STEP 3: u ke saare neighbours check karo
        // --------------------------------------------------------
        for (int v : graph[u]) {


            // ====================================================
            // CASE 1: v UNVISITED hai
            // ====================================================
            //
            // tin[v] == -1 ka matlab v abhi tak visit nahi hui.
            //
            if (tin[v] == -1) {

                // Pehle v par DFS karo.
                dfs(v, graph);


                // v ki DFS complete hone ke baad
                // low[u] ko update karo.
                //
                // Agar v kisi low-link ke through
                // u se pehle wali node tak pahunch sakta hai,
                // to u bhi us node tak indirectly pahunch sakta hai.
                low[u] = min(
                    low[u],
                    low[v]
                );
            }


            // ====================================================
            // CASE 2: v already active stack mein hai
            // ====================================================
            //
            // Agar v stack mein hai, iska matlab v current
            // DFS path/SCC ke active part mein hai.
            //
            // Is case mein low[u] ko v ke discovery time
            // se update karte hain.
            //
            else if (inStack[v]) {

                low[u] = min(
                    low[u],
                    tin[v]
                );
            }
        }


        // ========================================================
        // STEP 4: Check karo kya u SCC ka ROOT hai
        // ========================================================
        //
        // Agar:
        //
        //      low[u] == tin[u]
        //
        // to iska matlab u se koi aur active node
        // u se pehle nahi reachable hai.
        //
        // Therefore, u current SCC ka root hai.
        //
        if (low[u] == tin[u]) {

            // Current SCC ke nodes yahan save honge.
            vector<int> component;


            // ----------------------------------------------------
            // STEP 5: Stack se nodes pop karo
            // ----------------------------------------------------
            //
            // u tak ke saare nodes jo current SCC mein hain,
            // stack se pop karenge.
            //
            while (true) {

                // Stack ke top se node nikalo.
                int node = st.top();
                st.pop();


                // Node ab active stack mein nahi hai.
                inStack[node] = false;


                // Node ko current SCC mein save karo.
                component.push_back(node);


                // Jab root node u mil jaaye,
                // current SCC complete ho gayi.
                if (node == u)
                    break;
            }


            // ----------------------------------------------------
            // STEP 6: Complete SCC ko save karo
            // ----------------------------------------------------
            //
            // component ek SCC hai.
            //
            // Isko sccs ke andar store kar do.
            sccs.push_back(component);
        }
    }


    // ============================================================
    // PRINT ALL SCCs
    // ============================================================
    void printSCCs() {

        cout << "\nStrongly Connected Components:\n";

        for (int i = 0; i < sccs.size(); i++) {

            cout << "Component "
                 << i + 1
                 << ": ";

            for (int node : sccs[i]) {

                cout << node << " ";
            }

            cout << "\n";
        }
    }


    // ============================================================
    // TARJAN'S ALGORITHM
    // ============================================================
    vector<vector<int>> tarjan(
        int n,
        vector<vector<int>>& graph
    ) {

        // --------------------------------------------------------
        // STEP 1: Initialisation
        // --------------------------------------------------------

        // Sabhi nodes initially unvisited.
        tin.assign(n, -1);


        // low bhi initially -1.
        low.assign(n, -1);


        // Koi node stack mein active nahi hai.
        inStack.assign(n, false);


        // Timer ko reset karna important hai.
        timer = 0;


        // Agar same Solution object ko multiple times use kiya
        // jaaye, purani SCCs remove kar do.
        sccs.clear();


        // Stack bhi empty hona chahiye.
        while (!st.empty()) {
            st.pop();
        }


        // --------------------------------------------------------
        // STEP 2: Har node se DFS
        // --------------------------------------------------------
        //
        // Graph disconnected bhi ho sakta hai.
        // Isliye har node check karni padegi.
        //
        for (int i = 0; i < n; i++) {

            // Agar node unvisited hai,
            // to usse DFS start karo.
            if (tin[i] == -1) {

                dfs(i, graph);
            }
        }


        // --------------------------------------------------------
        // STEP 3: SCCs PRINT karo
        // --------------------------------------------------------
        printSCCs();


        // --------------------------------------------------------
        // STEP 4: SCCs RETURN karo
        // --------------------------------------------------------
        //
        // Ye vector<vector<int>> mein saari SCCs saved hain.
        return sccs;
    }
};


// ============================================================
// MAIN FUNCTION - Example
// ============================================================
int main() {

    int n = 5;

    vector<vector<int>> graph(n);


    // ------------------------------------------------------------
    // Graph:
    //
    // 0 -> 1
    // 1 -> 2
    // 2 -> 0
    //
    // 2 -> 3
    //
    // 3 -> 4
    // 4 -> 3
    //
    // SCC 1 = {0, 1, 2}
    // SCC 2 = {3, 4}
    // ------------------------------------------------------------

    graph[0].push_back(1);

    graph[1].push_back(2);

    graph[2].push_back(0);
    graph[2].push_back(3);

    graph[3].push_back(4);

    graph[4].push_back(3);


    // ============================================================
    // Tarjan Algorithm call
    // ============================================================

    Solution sol;

    // components mein saari SCCs save ho jaayengi.
    vector<vector<int>> components =
        sol.tarjan(n, graph);


    // ============================================================
    // Main ke andar bhi SCCs access kar sakte ho
    // ============================================================

    cout << "\nSaved Components:\n";

    for (int i = 0; i < components.size(); i++) {

        cout << "SCC " << i + 1 << " = { ";

        for (int node : components[i]) {

            cout << node << " ";
        }

        cout << "}\n";
    }


    // Total number of SCCs
    cout << "\nTotal Components = "
         << components.size()
         << "\n";


    return 0;
}