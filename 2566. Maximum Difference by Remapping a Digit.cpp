class Solution {
public:
    int minMaxDifference(int num) {
        string strNum1 = to_string(num), strNum2 = strNum1;
        int firstNon9Index = strNum1.find_first_not_of('9');
        if (firstNon9Index != string::npos) {
            char ch = strNum1[firstNon9Index];
            replace(strNum1.begin(), strNum1.end(), ch, '9');
        }
        char ch = strNum2[0];
        replace(strNum2.begin(), strNum2.end(), ch, '0');
        return stoi(strNum1) - stoi(strNum2);
    }
};

// NO STL -->
// class Solution {
// public:
//     int minMaxDifference(int num) {
//         string strNum = to_string(num);
//         char maxStartChar = '-', minStartChar = '-';
//         int maxNum = 0, minNum = 0;
//         for (int i = 0; i < strNum.size(); i++) {
//             // Maximum Number
//             if (maxStartChar == '-' && strNum[i] != '9') {
//                 maxNum = maxNum * 10 + 9;
//                 maxStartChar = strNum[i];
//             } else if (maxStartChar == strNum[i]) {
//                 maxNum = maxNum * 10 + 9;
//             } else {
//                 maxNum = maxNum * 10 + (strNum[i] - '0');
//             }

//             // Minimum Number
//             if (minStartChar == '-' && strNum[i] != '0') {
//                 minNum = minNum * 10;
//                 minStartChar = strNum[i];
//             } else if (minStartChar == strNum[i]) {
//                 minNum = minNum * 10;
//             } else {
//                 minNum = minNum * 10 + (strNum[i] - '0');
//             }
//         }
//         return maxNum - minNum;
//     }
// };
