#include <iostream>
#include <vector>

#define IS_DOWN_OK(x, y)        (y+1 <= m_max_idx && m_matrix[x][y+1]&& !m_visited[x][y+1])
#define IS_LEFT_OK(x, y)        (x-1 >= 0 && m_matrix[x-1][y] && !m_visited[x-1][y])
#define IS_RIGHT_OK(x, y)       (x+1 <= m_max_idx && m_matrix[x+1][y] && !m_visited[x+1][y])
#define IS_UP_OK(x, y)          (y-1 >= 0 && m_matrix[x][y-1] && !m_visited[x][y-1])

using namespace std;

class Solution{
private:
    vector<vector<int>> m_matrix;
    vector<vector<bool>> m_visited;
    int m_max_idx;

    void findPath(int x, int y, string &path, vector<string> &ans) {
        if(m_max_idx == x && m_max_idx == y) {
            ans.push_back(path);
            return;
        }

        if(IS_DOWN_OK(x, y)) {
            m_visited[x][y] = true;
            path += "D";
            findPath(x, y+1, path, ans);
            path.pop_back();
            m_visited[x][y] = false;
        }

        if(IS_LEFT_OK(x, y)) {
            m_visited[x][y] = true;
            path += "L";
            findPath(x-1, y, path, ans);
            path.pop_back();
            m_visited[x][y] = false;
        }

        if(IS_RIGHT_OK(x, y)) {
            m_visited[x][y] = true;
            path += "R";
            findPath(x+1, y, path, ans);
            path.pop_back();
            m_visited[x][y] = false;
        }

        if(IS_UP_OK(x, y)) {
            m_visited[x][y] = true;
            path += "U";
            findPath(x, y-1, path, ans);
            path.pop_back();
            m_visited[x][y] = false;
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        m_matrix = m;
        m_max_idx = m.size() - 1;
        m_visited = vector<vector<bool>>(n, vector<bool>(n, false));
        string path;
        vector<string> ans;

        findPath(0, 0, path, ans);
        return ans;
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
