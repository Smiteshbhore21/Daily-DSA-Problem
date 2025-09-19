class Spreadsheet {
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) { grid.resize(rows, vector<int>(26, 0)); }

    void setCell(string cell, int value) {
        grid[stoi(cell.substr(1)) - 1][cell[0] - 'A'] = value;
    }

    void resetCell(string cell) { setCell(cell, 0); }

    int getValue(string formula) {
        int value = 0;
        int plusIdx = 2;
        string row1 = "";
        while ('+' != formula[plusIdx]) {
            row1 += formula[plusIdx];
            plusIdx++;
        }
        if (isalpha(formula[1])) {
            value = grid[stoi(row1)-1][formula[1] - 'A'];
        } else {
            value = stoi(formula.substr(1, plusIdx - 1));
        }
        plusIdx++;
        if (isalpha(formula[plusIdx])) {
            value += grid[stoi(formula.substr(plusIdx + 1))-1][formula[plusIdx] - 'A'];
        } else {
            value += stoi(formula.substr(plusIdx));
        }

        return value;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
