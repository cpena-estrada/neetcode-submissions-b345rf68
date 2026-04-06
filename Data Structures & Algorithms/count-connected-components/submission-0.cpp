class Solution {
public:

   /* struct UF {
        vector<int> parent;
        find(){

        }

        union(){

        }
    }
    */

    /*you are a root if you are equal to yourself
    else, you pare a child, so keep looking a your parent's parents
    until you find the root */
    int find(int x, vector<int>& parent_arr) {
        if(x == parent_arr[x]) {
            return x;
        }
     return find(parent_arr[x], parent_arr);
    }

    void union_(int a, int b, vector<int>& parent_arr) {
        int root_a = find(a, parent_arr);
        int root_b = find(b, parent_arr);

        if(root_a != root_b){
            parent_arr[root_b] = root_a; //make the root of b (which its parent is itself equal to root of a)
            std::cout << "a U b" << std::endl;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        //each index represents the i-th node
        //the value inside each index represents the parent of node i
        vector<int> parent(n);

        //every node is a root and its parent is itself
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        /*
        for(int i=0; i<edges.size(); i++) {
            union(edges[i][0], edges[i][1]);
        } 
        */

        for(const auto& edge : edges) {
            union_(edge[0], edge[1], parent);
        }

        /* like pythons for a, b in edges:
        for(auto& [a, b] : edges){
            union(a, b)
        }
        */

        //now, the in the parent array, wherever i is equal to [i], thats a root note
        //therefore thats a unique cluster, so just count how many i = [i] there are
        int num_of_clusters = 0;
        for(int i=0; i<n; i++) {
            if(i == parent[i]) {
                num_of_clusters++;
            }
        }  
        return num_of_clusters; 
    }     
};
