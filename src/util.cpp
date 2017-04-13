#include "util.h"
using namespace std;

static const string alphanum =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghipqrstuvwxyz";

string generateRandomString(int size) {
    string str = "";
    for (int i = 0; i < size; i++) {
       str += alphanum[random_int(0, alphanum.length())];
    }
    return str;
}


/*
 * This split function was taken online. Source:
 * http://stackoverflow.com/questions/236129/split-a-string-in-c/7408245#7408245
 */
vector<string> split(const string &text, string sep) {
    vector<string> tokens;
    size_t start = 0, end = 0;
    while ((end = text.find(sep, start)) != std::string::npos) {
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
    return tokens;
}

/*
 * This starts_with function was taken online. Source:
 * http://stackoverflow.com/a/7756105
 */
bool starts_with(const string& s1, const string& s2) {
    return s2.size() <= s1.size() && s1.compare(0, s2.size(), s2) == 0;
}

string vector_to_string(vector<string> vec) {
    stringstream ss;
    for (size_t i = 0; i < vec.size(); i++) {
        if (i != 0) {
            ss << " ";
        }
        ss << vec[i];
    }
    return ss.str();
}


/*
 * This random_int function was taken online. Source:
 * http://stackoverflow.com/a/19728404
 */
int random_int(int min_num, int max_num) {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(min_num, max_num);
    return uni(rng);
}
