class Trie {
public:
    bool isend;
    vector<Trie*> children;
    Trie() {
        isend = false;
        children.resize(26,nullptr);
    }
    
    void insert(string word) {
        Trie* crawl = this;
        for(int i=0;i<word.size();i++){
            if(crawl->children[word[i]-'a']==NULL){
                crawl->children[word[i]-'a'] = new Trie();  
            }
            crawl=crawl->children[word[i]-'a'];
        }
        crawl->isend = true;
    }
    
    bool search(string word) {
        Trie* crawl = this;
        for(int i=0;i<word.size();i++){
            if(crawl->children[word[i]-'a']==NULL) return false;
            crawl = crawl->children[word[i]-'a'];
        }
        return crawl->isend;
    }
    
    bool startsWith(string prefix) {
        Trie* crawl = this;
        for(int i=0;i<prefix.size();i++){
            if(crawl->children[prefix[i]-'a']==NULL) return false;
            crawl = crawl->children[prefix[i]-'a'];
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