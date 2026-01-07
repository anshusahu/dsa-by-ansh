class Node{
    public:
        bool isEnd;
        Node* children[26];
        
        Node(){
            isEnd = false;
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
        }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(auto ch:word){
            int ind = ch - 'a';
            if(!node->children[ind]){
                node->children[ind] = new Node();
            }
            node = node->children[ind];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto ch : word){
            int ind = ch - 'a';
            if(!node->children[ind]){
                return false;
            }
            node = node->children[ind];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto ch : prefix){
            int ind = ch - 'a';
            if(!node->children[ind]){
                return false;
            }
            node = node->children[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */