#include<iostream>
#include<unordered_map>

using namespace std;

class TrieNode{

    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int count;
public:
    TrieNode(){
        isEndOfWord = false;
        count = 1;
    }

    void setEndOfWord(){
        isEndOfWord = true;
    }

    void unSetEndOfWord(){
        isEndOfWord = false;
    }

    bool isEnd(){
        return this->isEndOfWord;
    }

    void addChild(char c){
        children[c] = new TrieNode();
    }

    TrieNode* getChild(char c){
        return children[c];
    }

    bool hasChild(char c){
        return children.find(c) != children.end();
    }

    void incrementCount(){
        count++;
    }

    int getCount(){
        return count;
    }
    void decrementCount(){
        count--;
    }

    
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* current = root;
        for(int i = 0; i < word.length(); i++){
            if(!current->hasChild(word[i])){
                current->addChild(word[i]);
                current->incrementCount();
            }
            current = current->getChild(word[i]);
        }
        current->setEndOfWord();
    }

    bool search(string word){
        TrieNode* curr = root;
        for(int i = 0; i < word.length(); i++){
            if(!curr->hasChild(word[i])){
                return false;
            }
            curr = curr->getChild(word[i]);
        }
        return curr->isEnd();
    }

    bool startsWith(string prefix){
        TrieNode* curr = root;
        for(int i = 0; i < prefix.length(); i++){
            if(!curr->hasChild(prefix[i])){
                return false;
            }
            curr = curr->getChild(prefix[i]);
        }
        return true;
    }

    int getCount(string word){
        TrieNode* curr = root;
        for(int i = 0; i < word.length(); i++){
            if(!curr->hasChild(word[i])){
                return 0;
            }
            curr = curr->getChild(word[i]);
        }
        return curr->getCount();
    }

    //delete a word
    void deleteWord(string word){
        TrieNode* curr = root;
        for(int i = 0; i < word.length(); i++){
            if(!curr->hasChild(word[i])){
                return;
            }
            curr = curr->getChild(word[i]);
        }
        curr->unSetEndOfWord();
        curr->decrementCount();
    }



};


class PhoneDirectory{
    Trie* phoneBook;
    int maxNumbers;
    int availableNumbers;
public:
    PhoneDirectory(int maxNumbers){
        this->maxNumbers = maxNumbers;
        availableNumbers = maxNumbers;
        phoneBook = new Trie();
    }

    int getMaxNumbers(){
        return maxNumbers;
    }

    int getAvailableNumbers(){
        return availableNumbers;
    }

    bool checkAvailable(string number){
        return phoneBook->search(number);
    }

    void add(string number){
        phoneBook->insert(number);
        availableNumbers--;
    }

    void remove(string number){
        phoneBook->insert(number);
        availableNumbers++;
    }
};

class BloomFilter{
    //Space efficient probablistic data structure
    //Bloom filter is a probablistic data structure that is used to test whether an element is in a set or not.
    int size;
    int hashFunctions;
    int* array;
public:
    BloomFilter(int size, int hashFunctions){
        this->size = size;
        this->hashFunctions = hashFunctions;
        array = new int[size];
        for(int i = 0; i < size; i++){
            array[i] = 0;
        }
    }

    void add(string word){
        for(int i = 0; i < hashFunctions; i++){
            int hash = hashFunction(word, i);
            array[hash] = 1;
        }
    }

    bool check(string word){
        for(int i = 0; i < hashFunctions; i++){
            int hash = hashFunction(word, i);
            if(array[hash] == 0){
                return false;
            }
        }
        return true;
    }

    int hashFunction(string word, int i){
        int hash = 0;
        for(int j = 0; j < word.length(); j++){
            hash = (hash + word[j] * i) % size;
        }
        return hash;
    }
};

int countOfPrefixes(string prefix, vector<string>& words){
    Trie* trie = new Trie();
    int n = words.size();
    for(int i = 0; i < n; i++){
        trie->insert(words[i]);
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(trie->startsWith(prefix)){
            count++;
        }
    }
    return count;
}


int main(){
    Trie* t = new Trie();
    t->insert("hello");
    t->insert("hell");
    t->insert("he");
    t->insert("hel");
    t->insert("asia");
    t->insert("as");
    t->insert("India");

    cout<<t->search("hello")<<endl;
    cout<<t->search("hell")<<endl;
    cout<<t->search("helllll")<<endl;
    cout<<t->search("asia")<<endl;

    cout<<t->startsWith("he")<<endl;
    cout<<t->startsWith("hel")<<endl;
    cout<<t->startsWith("In")<<endl;

    return 0;

}