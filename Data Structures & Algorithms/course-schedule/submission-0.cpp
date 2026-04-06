class Solution {
    //          course, list of prereqs
    unordered_map<int, vector<int>> pre_map;
    unordered_set<int> path; // nodes on current dfs path
    unordered_set<int> done; // fully processed nodes
public:

    bool dfs(int src) {
        if (done.count(src)) { return true; } //already verified
        if (path.count(src)) { return false; } // cycle

        path.insert(src);
        for (int dst: pre_map[src]) {
            if (!dfs(dst)) { return false ;}
        }
        path.erase(src);
        done.insert(src);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build adj list / map of preq
        for (const auto& prereq : prerequisites) {
            int a = prereq[0], b = prereq[1];
            pre_map[a].push_back(b);
        }
        
        // start from course 0;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) { return false; }
        }

        return true;
    }
};

/*

0 [1]
1 [0]

build an adj list of course and its prereq

if you ever make a cycle, return false. use the map to detect cycles

*/