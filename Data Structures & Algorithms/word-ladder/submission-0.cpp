class Solution {
    unordered_map<string, vector<string>> adj_list; // pattern : possible words
    unordered_set<string> visited;
public:

    int bfs(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q; // word, level of bfs representing num of transformations
        q.push({beginWord, 1});
        visited.insert(beginWord);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [curr_word, curr_level] = q.front(); q.pop();
                if (curr_word == endWord) { return curr_level; }

                // explore possible neighbors by generating patterns for current word
                for (int j = 0; j < curr_word.length(); j++) {
                    string pattern = curr_word;
                    pattern[j] = '*';
                    
                    // if pattern exists, explore its possible words
                    if (adj_list.count(pattern)) {
                        for (const auto& neigh : adj_list[pattern]) {
                            if (!visited.count(neigh)) {
                                q.push({neigh, curr_level + 1});
                                visited.insert(neigh);
                            }
                        }
                    }
                }
            }
        }
        return 0; // word unreachable
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // if endword not in wordlist
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0; // no way to achieve end word
        }

        int n = beginWord.size();

        // generate map of patterns : possible words 
        for (auto word : wordList) { 
            for (int i = 0; i < word.length(); i++) {
                string pattern = word; // make a copy jus to be safe
                pattern[i] = '*';
                adj_list[pattern].push_back(word);
            }
        }

        return bfs(beginWord, endWord, wordList);
    }
};

/*

think of the words as a graph

if two wrods differer by a single character, there is an edge between them

use a bfs to find the shortest path

dont explore visited words as you'll ping pong


BFS II (generating words):

start with original word
    for each character in that word, generate a new word with letters a-z
    if this new word is in wordList, its a word that differes by one char
    explore it: push onto queue and 

    still a graph but way less explicit

BFS III (adjecency list):

create map of pattern : possible w

bfs starting from begin word, generate paterrns for that word, and explore words with that pattern
mark visited as you go

checking if word in words:

        bool flag = false; 
        for (const auto& word : wordList) { if (endWord == word) { flag = true; }}
        if (!flag) { return 0; }

creating a pattern:

    normal:

        for (int i = 0; i < word.length(); i++) {
            string copy = word;
            copy[i] = '*';
        }
    }

    slicing-like:

        for (int i = 0; i < word.length(); i++) {
            string copy = word;
            string pattern = copy.substr(0, i) + '*' + copy.substr(i+1, word.lenght()); //could omint word.lenght as it auyomatically goes to the end
        } 

         j
        0123
        catt

        'c' + '*' + tt
*/