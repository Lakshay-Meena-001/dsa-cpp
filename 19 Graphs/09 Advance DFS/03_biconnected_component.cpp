#include <bits/stdc++.h>
using namespace std;

class BiconnectedComponents
{
public:
    int timer = 0;

    vector<int> tin;
    vector<int> low;

    vector<pair<int, int>> edgeStack;

    vector<vector<pair<int, int>>> components;

    vector<vector<int>> graph;

    void dfs(int u, int parent)
    {

        tin[u] = low[u] = timer++;

        for (int v : graph[u])
        {

            // Ignore the edge through which we entered u
            if (v == parent)
                continue;

            // Tree Edge
            if (tin[v] == -1)
            {

                edgeStack.push_back({u, v});

                dfs(v, u);

                low[u] = min(low[u], low[v]);

                // If low[v] >= tin[u],
                // then one complete BCC is found
                if (low[v] >= tin[u])
                {

                    vector<pair<int, int>> component;

                    while (true)
                    {

                        auto edge = edgeStack.back();
                        edgeStack.pop_back();

                        component.push_back(edge);

                        if (edge.first == u &&
                            edge.second == v)
                        {
                            break;
                        }
                    }

                    components.push_back(component);
                }
            }

            // Back Edge
            else if (tin[v] < tin[u])
            {

                edgeStack.push_back({u, v});

                low[u] = min(low[u], tin[v]);
            }
        }
    }

    vector<vector<pair<int, int>>>
    findBiconnectedComponents(
        int n,
        vector<vector<int>> &edges)
    {

        // Reset everything
        timer = 0;
        edgeStack.clear();
        components.clear();

        graph.assign(n, {});

        // Build adjacency list
        for (auto &edge : edges)
        {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        tin.assign(n, -1);
        low.assign(n, -1);

        // DFS for every component
        for (int i = 0; i < n; i++)
        {

            if (tin[i] == -1)
            {
                dfs(i, -1);
            }
        }

        return components;
    }
};

int main()
{

    int n, m;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    BiconnectedComponents solver;

    vector<vector<pair<int, int>>> components =
        solver.findBiconnectedComponents(n, edges);

    cout << "\nBiconnected Components:\n";

    for (int i = 0; i < components.size(); i++)
    {

        cout << "Component " << i + 1 << ": ";

        for (auto &edge : components[i])
        {

            cout << "("
                 << edge.first
                 << ", "
                 << edge.second
                 << ") ";
        }

        cout << '\n';
    }

    return 0;
}
/*
Bilkul. Isko **ekdum zero se** samajhte hain. Pehle code bhool jao — pehle problem samjho, phir `tin`, `low`, `DFS`, `edgeStack` sab connect karenge.

## 1. Sabse pehle: Biconnected Component hota kya hai?

Humare paas ek **undirected graph** hai:

```text
      0
     / \
    1---2
    |
    3
    |
    4
```

Is graph mein:

```text
0 -- 1
1 -- 2
2 -- 0
```

ek cycle bana rahe hain.

Agar hum `1` ko hata dein:

```text
      0       2

      3
      |
      4
```

Graph toot jaata hai.

Lekin `0,1,2` wale part mein agar **kisi ek vertex ko hatao**, tab bhi baaki do vertices connected rehte hain.

Isi type ke tightly connected portions ko hum **Biconnected Components (BCCs)** kehte hain.

---

# 2. Is algorithm ka actual kaam kya hai?

Humein graph diya hai:

```text
0 -- 1
|  /
| /
2

1 -- 3 -- 4
```

Algorithm batayega:

```text
BCC 1:
(3,4)

BCC 2:
(1,3)

BCC 3:
(0,1)
(1,2)
(2,0)
```

Matlab graph ko aise portions mein todna jahan edges ek saath belong karte hain.

---

# 3. Ab DFS yaad karo

Ye algorithm basically **DFS + thodi extra information** hai.

Normal DFS mein hum kya karte hain?

```cpp
dfs(0)
```

phir:

```text
0 → 1 → 2 → ...
```

Har vertex ko visit karte hain.

Yahan bhi wahi karenge.

Lekin har vertex ke saath do values maintain karenge:

```cpp
tin[u]
low[u]
```

Ye dono algorithm ka **heart** hain.

---

# 4. `tin[u]` kya hai?

`tin` = **time of insertion**

Simple language mein:

> DFS mein vertex ko pehli baar kis time visit kiya tha?

Example:

```text
0
|
1
|
2
```

DFS:

```text
0 → 1 → 2
```

To:

```text
tin[0] = 0
tin[1] = 1
tin[2] = 2
```

Code:

```cpp
tin[u] = low[u] = timer++;
```

Starting mein:

```cpp
timer = 0;
```

To jab `0` par aaye:

```text
tin[0] = 0
timer = 1
```

Phir `1`:

```text
tin[1] = 1
timer = 2
```

Phir `2`:

```text
tin[2] = 2
timer = 3
```

Bas itna hi `tin` ka concept hai.

---

# 5. Ab sabse important: `low[u]`

`low` thoda confusing hota hai.

Beginner-friendly definition:

> `low[u]` batata hai ki DFS subtree of `u` se hum **sabse purane visited vertex** tak kitna upar ja sakte hain.

Example:

```text
      0
     / \
    1---2
```

DFS maan lo:

```text
0 → 1 → 2
```

To:

```text
tin[0] = 0
tin[1] = 1
tin[2] = 2
```

Ab edge:

```text
2 → 0
```

hai.

Ye ek **back edge** hai.

Matlab DFS tree se wapas kisi purane ancestor par ja sakte hain.

To `2` keh raha hai:

> "Main vertex 0 tak wapas pahunch sakta hoon."

Isliye:

```text
low[2] = 0
```

Aur ye information upar propagate hoti hai:

```text
low[1] = 0
low[0] = 0
```

---

# 6. DFS mein do types ki edges

Algorithm mein mainly do situations hain.

### Case 1: Tree Edge

Agar `v` abhi visit nahi hua:

```cpp
if (tin[v] == -1)
```

To:

```text
u → v
```

DFS tree ka edge hai.

Example:

```text
0 → 1 → 2
```

---

### Case 2: Back Edge

Agar `v` already visited hai aur `v` ancestor hai:

```cpp
else if (tin[v] < tin[u])
```

To ye back edge hai.

Example:

```text
0
|\
| \
1--2
```

DFS:

```text
0 → 1 → 2
```

Ab `2 → 0` ek back edge hai.

Because:

```text
tin[0] = 0
tin[2] = 2
```

and:

```text
tin[0] < tin[2]
```

---

# 7. `edgeStack` kyun hai?

Ab interesting part.

Humein sirf vertices nahi chahiye.

Humein **BCC ke edges** collect karne hain.

Isliye ek stack banaya:

```cpp
vector<pair<int, int>> edgeStack;
```

Example:

```text
0 -- 1
|  /
| /
2
```

DFS ke dauran edges stack mein jaayengi:

```text
(0,1)
(1,2)
(2,0)
```

Stack:

```text
TOP
(2,0)
(1,2)
(0,1)
```

Jab algorithm ko pata chalta hai ki ek BCC complete ho gaya hai, to stack se edges nikalta hai.

---

# 8. BCC kab complete hota hai?

Ye line sabse important hai:

```cpp
if (low[v] >= tin[u])
```

Isko samajhne ke liye example:

```text
      0
      |
      1
     / \
    2---3
```

Maan lo DFS:

```text
0 → 1 → 2 → 3
```

Aur `2-3` ki wajah se cycle hai.

Suppose DFS subtree:

```text
      1
     /
    2
     \
      3
```

Ab agar `low[v] >= tin[u]` ho gaya, iska matlab roughly:

> `v` ki subtree `u` se upar kisi ancestor tak back edge se nahi pahunch sakti.

Is point par jo edges stack mein hain, woh ek BCC bana rahe hain.

---

# 9. Chalo poora example manually karte hain

Graph:

```text
        0
       / \
      1---2
      |
      3
      |
      4
```

Edges:

```text
0-1
1-2
2-0
1-3
3-4
```

Start:

```cpp
dfs(0, -1);
```

---

## Step 1: Vertex 0

```text
tin[0] = 0
low[0] = 0
```

Graph:

```text
0
```

DFS goes to `1`.

Edge:

```text
0 → 1
```

Stack:

```text
(0,1)
```

---

# 10. Vertex 1

Now:

```text
tin[1] = 1
low[1] = 1
```

DFS goes to `2`.

Stack:

```text
(0,1)
(1,2)
```

---

# 11. Vertex 2

Now:

```text
tin[2] = 2
low[2] = 2
```

Vertex `2` sees edge to `0`.

`0` already visited hai.

And:

```text
tin[0] < tin[2]
```

So:

```cpp
else if (tin[v] < tin[u])
```

execute hoga.

Edge `(2,0)` stack mein:

```text
(0,1)
(1,2)
(2,0)
```

Aur:

```cpp
low[2] = min(low[2], tin[0]);
```

So:

```text
low[2] = min(2,0)
       = 0
```

---

# 12. Ab 2 se wapas 1

DFS return hota hai.

Ab:

```cpp
low[1] = min(low[1], low[2]);
```

So:

```text
low[1] = min(1,0)
       = 0
```

Ab check:

```cpp
if (low[2] >= tin[1])
```

Values:

```text
low[2] = 0
tin[1] = 1
```

So:

```text
0 >= 1
```

False.

Isliye BCC nahi niklega.

---

# 13. Ab 1 se 3

Edge:

```text
1 → 3
```

Stack mein:

```text
(0,1)
(1,2)
(2,0)
(1,3)
```

Vertex `3`:

```text
tin[3] = 3
low[3] = 3
```

---

# 14. Ab 3 se 4

Stack:

```text
(0,1)
(1,2)
(2,0)
(1,3)
(3,4)
```

Vertex `4`:

```text
tin[4] = 4
low[4] = 4
```

4 ke paas koi back edge nahi.

So return to `3`.

```cpp
low[3] = min(low[3], low[4]);
```

Still:

```text
low[3] = 3
```

Now:

```cpp
if (low[4] >= tin[3])
```

Check:

```text
4 >= 3
```

True!

So BCC mil gaya.

---

# 15. Stack se edges nikalenge

Current stack:

```text
TOP
(3,4)
(1,3)
(2,0)
(1,2)
(0,1)
```

Code:

```cpp
while (true) {

    auto edge = edgeStack.back();
    edgeStack.pop_back();

    component.push_back(edge);

    if (edge.first == u &&
        edge.second == v) {
        break;
    }
}
```

`u = 3`, `v = 4`.

Pehle nikla:

```text
(3,4)
```

Ye matching edge hai.

So stop.

BCC:

```text
(3,4)
```

---

# 16. Ab 3 → 1 return

Ab:

```text
low[1] = min(low[1], low[3])
```

Already:

```text
low[1] = 0
```

Now check:

```cpp
if (low[3] >= tin[1])
```

Values:

```text
low[3] = 3
tin[1] = 1
```

So:

```text
3 >= 1
```

True.

Ab stack mein:

```text
(0,1)
(1,2)
(2,0)
(1,3)
```

Pop karenge until `(1,3)` milta hai.

So second BCC:

```text
(1,3)
```

---

# 17. Ab 1 → 0 return

Finally DFS complete hone ke baad:

```text
(0,1)
(1,2)
(2,0)
```

ye teen edges stack mein hain.

Ye ek BCC hai:

```text
      0
     / \
    1---2
```

So:

```text
BCC 1 = {(3,4)}

BCC 2 = {(1,3)}

BCC 3 = {(0,1), (1,2), (2,0)}
```

---

# 18. Ab code ki important lines ko translate karte hain

### DFS start

```cpp
tin[u] = low[u] = timer++;
```

Meaning:

> Is vertex ko visit kar diya aur iska visiting time note kar liya.

---

### Unvisited neighbour

```cpp
if (tin[v] == -1)
```

Meaning:

> `v` ko abhi tak visit nahi kiya.

Then:

```cpp
edgeStack.push_back({u, v});
dfs(v, u);
```

Meaning:

> Edge ko save karo aur `v` par DFS chalao.

---

### DFS ke baad

```cpp
low[u] = min(low[u], low[v]);
```

Meaning:

> Mere child `v` jitna upar graph mein ja sakta hai, main bhi utna upar ja sakta hoon.

---

### Back edge

```cpp
else if (tin[v] < tin[u])
```

Meaning:

> `v` mujhse pehle visit hua tha, aur main us purane ancestor tak wapas pahunch sakta hoon.

Then:

```cpp
low[u] = min(low[u], tin[v]);
```

---

### BCC detection

```cpp
if (low[v] >= tin[u])
```

Meaning:

> Child `v` ki subtree `u` ke upar nahi ja sakti. Isliye `v` se lekar stack mein stored relevant edges ek BCC complete karte hain.

---

# 19. Ek line mein poora algorithm

Agar interview mein poochhein:

> **How does BCC algorithm work?**

To simple answer:

> **We run DFS and maintain `tin` and `low` values for every vertex. We push DFS tree edges and back edges onto a stack. Whenever `low[v] >= tin[u]`, the edges popped from the stack up to `(u,v)` form one biconnected component.**

---

# 20. Sabse important mental picture

Is algorithm ko yaad rakhne ke liye bas ye picture dimaag mein rakho:

```text
                 DFS
                  ↓
          ┌──────────────┐
          │              │
       tin[u]         low[u]
          │              │
          │              │
     Kab visit hua?   Kitna upar
                     wapas ja sakta?
          │              │
          └──────┬───────┘
                 ↓
            edgeStack
                 ↓
       low[v] >= tin[u] ?
                 ↓
             YES
                 ↓
          Stack se edges
             POP karo
                 ↓
              BCC
```

**`tin` = kab aaye**
**`low` = kitna peeche/uper ja sakte ho**
**`edgeStack` = kaunsi edges current BCC mein ho sakti hain**
**`low[v] >= tin[u]` = BCC mil gaya**

Agar ye 4 cheezein clear ho gayi, to poora code kaafi easy ho jaata hai.

*/