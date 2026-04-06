class Solution {
    //          course, list of prereqs
    unordered_map<int, vector<int>> prereq_map;
    unordered_set<int> visited;
public:

    bool dfs(int course) {
        if (visited.count(course)) { return false; } // cycle
        //if (prereq_map.empty()) { return true; } // course that has no prereqs or its safe
        if (prereq_map[course].size() == 0) { return true; } // course that has no prereqs or its safe


        visited.insert(course); // mark as visited

        // dfs each prereq of src
        for (const auto& prereq : prereq_map[course]) { // for (int i = 0; i < prereq_map[course].size(); i++)
            if (!dfs(prereq)) { return false;}
        }
        visited.erase(course);
        prereq_map[course].clear(); // this course is safe. memoize it by clearing it. NOT NECCESSARY
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // make all courses keys (handles courses with no prereqs)
        for (int i = 0; i < numCourses; i++) {
            prereq_map[i] = {};
        }

        for (const auto& prereq : prerequisites) {
            int a = prereq[0], b = prereq[1];
            prereq_map[a].push_back(b);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) { return false; }
        }

        return true;
    }
};

/*

(check paper)
erase from set to stay on track with the status of the recursive stack!!
    - if you dont erase, any future dfs calls will see stale/old entries and think there is a cyle when there isnt

example: 
    0: []
    1: [0]
    2: [1]

keep in mind there are courses that have no prereqs:

e.g;
    prerequisites = [[1,0], [2,1], [3,1]]

	pre[0] = [] // if you just inser course a, you wouldn end up inserting 0 in the map
	pre[1] = [0]
	pre[2] = [1]
	pre[3] = [1]


build an adj list of course and its prereq

if you ever make a cycle, return false. use the map to detect cycles


*/