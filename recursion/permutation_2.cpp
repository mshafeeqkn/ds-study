#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
private:
    void swap(vector<int> &v, int &a, int &b) {
        if(a == b) return;

        int tmp = v[a];
        v[a] = v[b];
        v[b] = tmp;
    }

    string to_string(vector<int> &numList) {
        ostringstream oss;

        for(int i: numList) {
            oss << i;
        }

        return oss.str();
    }

    void permutation(int index, int n, vector<int> &numList, vector<string> &ans) {
        if(index == n) {
            ans.push_back(to_string(numList));
            return;
        }

        for(int i = index; i < n; i++) {
            swap(numList, index, i);
            permutation(index+1, n, numList, ans);
            swap(numList, index, i);
        }
    }

public:
    string getPermutation(int n, int k) {
        vector<int> numList;
        for(int i = 1; i <= n; i++) {
            numList.push_back(i);
        }

        vector<string> ans;
        permutation(0, n, numList, ans);
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};

class Solution2 {
private:
    int fact(int n) {
        if(n == 0)
            return 1;

        int f = 1;
        while(n--) {
            f = f * (n+1);
        }
        return f;
    }

    string getKthPermutation(int size, int k, vector<int> &v) {
        if(v.size() == 0)
            return "";

        ostringstream oss;
        int vectIndex = (k-1)/fact(size-1);
        oss << v[vectIndex];
        v.erase(v.begin() + vectIndex);
        oss << getKthPermutation(size-1, ((k-1)%fact(size-1)) + 1, v);
        return oss.str();
    }

public:
    string getPermutation(int size, int k) {
        vector<int> ds;
        for(int i = 1; i <= size; i++) {
            ds.push_back(i);
        }

        return getKthPermutation(size, k, ds);
    }
};

int main() {
	// Solution1 s;
    Solution2 s;
	cout << s.getPermutation(4, 16) << endl;
    return 0;
}


#if 0
[1 2 3 4]   - 16th
0-23        -> 15th

1    [ 2 3 4 ]  0-5
2    [ 1 3 4 ]  6-11
3    [ 1 2 4 ]  12-17   
        
  3 1   [ 2 4 ]   12-13
  3 2   [ 1 4 ]   14-15
    3 2 1 [4]   14
    3 2 4 [1]   15
        3 2 4 1 []         <---------------------Answ
  3 4   [ 1 2 ]   16-17

4    [ 1 2 3 ]  18-23


#endif
