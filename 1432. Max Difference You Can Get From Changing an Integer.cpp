class Solution {
public:
    int maxDiff(int num) {
        string strNum = to_string(num);
        int idx = strNum.find_first_not_of('9');
        string a = strNum, b = strNum;
        if (idx != string::npos) {
            replace(a.begin(), a.end(), strNum[idx], '9');
        }
        for (int i = 0; i < b.size(); i++) {
            char ch = b[i];
            if (i == 0 && ch != '1') {
                replace(b.begin(), b.end(), ch, '1');
                break;
            } else if (ch != '0' && ch != strNum[0]) {
                replace(b.begin(), b.end(), ch, '0');
                break;
            }
        }
        return stoi(a) - stoi(b);
    }
};

// class Solution {
// public:
//     int maxDiff(int num) {
//         string strNum = to_string(num);
//         int idx = strNum.find_first_not_of('9');
//         string a = strNum;
//         if (idx != string::npos) {
//             replace(a.begin(), a.end(), strNum[idx], '9');
//         }
//         for (char chx = '0'; chx <= '9'; chx++) {
//             for (char chy = '0'; chy <= '9'; chy++) {
//                 string t = strNum;
//                 replace(t.begin(), t.end(), chx, chy);
//                 if (t[0] == '0')
//                     continue;
//                 num = min(stoi(t), num);
//             }
//         }
//         return stoi(a) - num;
//     }
// };
