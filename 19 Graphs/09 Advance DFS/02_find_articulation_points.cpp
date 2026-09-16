#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timer = 0;

    void dfs(int u, int parent, vector<vector<int>> &graph, vector<int> &tin, vector<int> &low, vector<int> &isArticulation)
    {

        tin[u] = low[u] = timer++;

        int children = 0;

        for (int v : graph[u])
        {

            // Ignore parent edge
            if (v == parent)
            {
                continue;
            }

            // Tree Edge
            if (tin[v] == -1)
            {

                children++;

                dfs(v, u, graph, tin, low, isArticulation);

                // Get information from child
                low[u] = min(low[u], low[v]);

                // Non-root articulation condition
                if (parent != -1 && low[v] >= tin[u])
                {

                    isArticulation[u] = 1;
                }
            }

            // Back Edge
            else
            {
                low[u] = min(low[u], tin[v]);
            }
        }

        // Root articulation condition
        if (parent == -1 && children > 1)
        {
            isArticulation[u] = 1;
        }
    }

    vector<int> findArticulationPoints(int n, vector<pair<int, int>> &edges)
    {

        // Create adjacency list
        vector<vector<int>> graph(n);

        for (auto edge : edges)
        {
            int u = edge.first;
            int v = edge.second;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Initialize arrays
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<int> isArticulation(n, 0);

        timer = 0;

        // Graph can be disconnected,
        // so run DFS from every unvisited node
        for (int i = 0; i < n; i++)
        {
            if (tin[i] == -1)
            {
                dfs(i, -1, graph, tin, low, isArticulation);
            }
        }

        // Store articulation points
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (isArticulation[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main()
{

    // Number of vertices
    int n = 5;

    // Edges
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {1, 3},
        {3, 4}};

    Solution obj;

    vector<int> articulationPoints = obj.findArticulationPoints(n, edges);

    cout << "Articulation Points: ";

    for (int node : articulationPoints)
    {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}

/*
Bilkul. **Articulation Point** ko sabse simple way mein samjho:

### 1. Articulation Point kya hota hai?

Graph mein koi aisa **node/vertex** jisko remove karne par graph ke connections toot jaayein, usko **Articulation Point** kehte hain.

Example:

```text
0
|
1
/ \
2  3
    \
     4
```

Agar **1 remove** kar do:

```text
0     2

3
|
4
```

Graph toot gaya → **1 articulation point hai**.

Agar **3 remove** kar do:

```text
0
|
1
|
2

4
```

Graph toot gaya → **3 bhi articulation point hai**.

---

## 2. Code actually kya kar raha hai?

Code **DFS** chala raha hai aur har node ke liye do values calculate karta hai:

```cpp
tin[u]
low[u]
```

### `tin[u]`

Ye batata hai:

> DFS mein node `u` ko **kab visit kiya tha**.

Example:

```text
0 → 1 → 2 → 3
```

Toh:

```text
tin[0] = 0
tin[1] = 1
tin[2] = 2
tin[3] = 3
```

---

### `low[u]`

Ye thoda important hai.

`low[u]` batata hai:

> Node `u` ya uske subtree se DFS tree ke through **sabse upar/pehle wale node tak back edge se pahunch sakte hain ya nahi**.

Simple language mein:

**"Mere neeche wale nodes kisi alternate route se mere upar pahunch sakte hain?"**

---

## 3. Main condition

Ye line dekho:

```cpp
if (parent != -1 && low[v] >= tin[u]) {
    isArticulation[u] = 1;
}
```

Iska simple meaning:

> Agar `u` ko hata diya, toh uska child `v` wala portion kisi aur route se `u` ke upar nahi ja sakta.

Toh `u` ko remove karne par graph toot jayega.

Hence:

```text
u = Articulation Point
```

---

## 4. `low[v] >= tin[u]` ko example se samjho

Graph:

```text
      0
      |
      1
     / \
    2   3
        |
        4
```

DFS:

```text
0 → 1 → 2
      → 3 → 4
```

Maan lo hum `1` par hain.

`3` ke neeche:

```text
3 → 4
```

`4` ke paas **koi alternate edge nahi hai** jo `0` ya `1` ke upar ja sake.

Isliye:

```text
low[3] >= tin[1]
```

True hoga.

Therefore:

```text
1 = articulation point
```

---

## 5. Root ka special case

Ye condition:

```cpp
if (parent == -1 && children > 1) {
    isArticulation[u] = 1;
}
```

DFS ka first node **root** hota hai.

Root ke liye rule alag hai:

> Agar root ke **2 ya zyada independent DFS children** hain, toh root articulation point hai.

Example:

```text
      0
     / \
    1   2
```

Agar `0` remove:

```text
1     2
```

Graph toot gaya.

So:

```text
0 = articulation point
```

---

## 6. Pura code ek line mein kya kar raha hai?

Basically:

```text
DFS karo
   ↓
Har node ka tin aur low nikalo
   ↓
Check karo ki child ke paas
upar jaane ka alternate route hai ya nahi
   ↓
Agar alternate route nahi hai
   ↓
Current node = Articulation Point
```

### Sabse important intuition 🧠

`low[v] >= tin[u]` ko yaad rakhne ka easiest way:

> **"Agar child `v` ke subtree ke paas `u` ko bypass karke upar jaane ka koi rasta nahi hai, toh `u` ko hataate hi woh subtree disconnect ho jayega."**

Isliye `u` **Articulation Point** hai.

*/