/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(int id, unordered_map<int, Employee*> &um, int &sum) {
        sum += um[id]->importance;
        for(auto i : um[id]->subordinates) dfs(i, um, sum);
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> um;
        for(auto x : employees) um[x->id] = x;
        int sum = 0;
        dfs(id, um, sum);
        return sum;
    }
};