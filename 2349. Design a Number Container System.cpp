class NumberContainers {
public:
    map<int, set<int>> numMap;
    map<int, int> indexMap;
    NumberContainers() {}

    void change(int index, int number) {
        if (indexMap.find(index) != indexMap.end()) {
            int prev = indexMap[index];
            numMap[prev].erase(index);
        }
        indexMap[index] = number;
        numMap[number].insert(index);
    }

    int find(int number) {
        if(numMap.find(number)==numMap.end() || numMap[number].empty())
            return -1;
        
        return *numMap[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
