#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<vector<int>> m_matrix;
    vector<vector<bool>> m_visited;
    
public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        m_matrix = m;
        m_visited = vector<vector<bool>>(n, vector<bool>(n, false));
        return vector<string>(3, "shafeeque");
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<int>> m {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
    };
    vector<string>::iterator itr;
    vector<string> ans = s.findPath(m, 4);
    for(itr = ans.begin(); itr != ans.end(); itr++) {
        cout << *itr << endl;
    }
}
