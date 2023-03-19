//{ Driver Code Starts
#include <bits/stdc++.h>

#define MAX_SIZE    10
using namespace std;


// } Driver Code Ends
class Solution{
private:
    bool colorGraph(bool graph[MAX_SIZE][MAX_SIZE], vector<int> &colors, int index, int m, int n) {
        if(index == n) {
            return true;
        }

        for(int i = 0; i < m; i++) {
            colors[index] = i;
            if(isValid(graph, colors, index)) {
                if(colorGraph(graph, colors, index+1, m, n) == true) {
                    return true;
                }
            }
            colors[index] = '.';
        }
        return false;
    }

    bool isValid(bool graph[MAX_SIZE][MAX_SIZE], vector<int> &colors, int index) {
        for(int i = 0; i < MAX_SIZE; i++) {
            if(graph[index][i] == true) {
                if(colors[index] == colors[i]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[MAX_SIZE][MAX_SIZE], int m, int n) {
        // your code here
        vector<int> colors(n, '.');
        return colorGraph(graph, colors, 0, m, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;

        int i;
        bool graph[MAX_SIZE][MAX_SIZE];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
