class Solution {   
private: 
    unordered_map<int, vector<int>> prereq_map;
    unordered_set<int> visited;
    unordered_set<int> done;
    vector<int> res;
public:

    bool dfs(int course) {
        if (visited.count(course)) { return false; } // cycle, impossible
        if (done.count(course)) { return true; } // already processed (sort of like memo from previous problem)

        visited.insert(course);
        for (const auto& prereq : prereq_map[course]) {
            if(!dfs(prereq)) { return false; };
        }

        visited.erase(course);
        done.insert(course);
        res.push_back(course);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) { prereq_map[i] = { }; }
        for (const auto& prereq : prerequisites) {
            int a = prereq[0], b = prereq[1];
            prereq_map[a].push_back(b);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if(!dfs(i)) { return {}; }
        }
        return res;
    }
};


/*

if its acyclic, return the topo sort

if there is a cycle/impossile, ret empty list

*/