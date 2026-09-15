class RandomizedSet {
public:

    set<int> s;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (s.find(val) != s.end())
            return false;  

        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (s.find(val) == s.end())
            return false;   

        s.erase(val);
        return true;    
    }
    
    int getRandom() {
        int index = rand() % s.size();

        auto it = s.begin();
        advance(it, index);

        return *it;
    }
};