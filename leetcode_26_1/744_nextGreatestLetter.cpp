//
// Created by zhongjiahui on 26-1-31.
//
#include <algorithm>
#include <iostream>
#include <ostream>
#include<vector>
using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char temp = letters[0];
        sort(letters.begin(), letters.end());
        int n = letters.size();
            auto it = lower_bound(letters.begin(), letters.end(), target);
        if (it == letters.end()) {
            return temp;
        }
            int index = it - letters.begin();
            for (int i = index; i < letters.size(); i++) {
                if (letters[i] != target) {
                    return letters[i];
                }
            }
            return temp;
    }
};

int main() {
    vector<char> a ={'c','f','j'};
    char b = 'd';
    Solution s;
    cout << s.nextGreatestLetter(a, b) << endl;
}