struct TrieNode {
    unordered_map<char, TrieNode*> children; // think as neighboring letters
    bool end_word;

    TrieNode() {
        end_word = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for (const auto& c : word) {
            if (!curr->children.count(c)) { //if the current character is not a child of root
                curr->children[c] = new TrieNode(); // make it so
            }

            curr = curr->children[c]; // move to that char (either after the insert above or because it existed already)
        }

        // at this point, current is the last char in the word
        curr->end_word = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for (const auto& c : word) {
            if (!curr->children.count(c)) { return false; } // if curr doesnt have any matching children matching curr char

            curr = curr->children[c];
        }    

        return curr->end_word; // its true or false. no if else needed
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (const auto& c : prefix) {
            if (!curr->children.count(c)) { return false; }

            curr = curr->children[c];
        }

        return true;
    }
};





/*

vector<string> split(string path) {
    for (int i = 0; i < path.size(); i ++) {
        if (path[i] == '/') { path[i] = ' '}
    }

    stringstream ss(path);
    vector<string> words;
    string token;
    while (ss >> token) { words.push_back(token); }

    return words

special scenarios for path would be 

empty
/
/something/
something/something_else (initial l missing)


*/