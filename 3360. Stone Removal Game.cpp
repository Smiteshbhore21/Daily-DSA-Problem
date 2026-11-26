class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
      
        while (n >= remove) {
            n -= remove;
            remove--;
        }
      
        if (remove % 2 == 1)
            return true;

        return false;
    }
};
