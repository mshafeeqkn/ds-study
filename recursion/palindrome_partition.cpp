#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool is_palindrome(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return s == s1;
    }

    void solve_problem(string s, vector<vector<string>> &ans, vector<string> &parts) {
		if(s.length() == 0) {
            ans.push_back(parts);
            return;
        }

        int s_len = s.length();
        for(int i = 0; i < s_len; i++) {
            if(is_palindrome(s.substr(0, i+1))) {
                parts.push_back(s.substr(0, i+1));
                solve_problem(s.substr(i+1), ans, parts);
                parts.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;
        solve_problem(s, ans, parts);
        return ans;
    }
};

void print_list(vector<string> &strs) {
	vector<string>::iterator itr;
	cout << "[ ";
	for(itr = strs.begin(); itr != strs.end(); itr++) {
		cout << *itr << " ";
	}
	cout << "]";
}

int main(int argc, char *argv[]) {
	Solution sol;
	vector<vector<string>>::iterator itr1;


	vector<vector<string>> ans = sol.partition("shafeeque");
	cout << "[ ";
	for(itr1 = ans.begin(); itr1 != ans.end(); itr1++) {
		print_list(*itr1);
	}
	cout << "]" << endl;
}
