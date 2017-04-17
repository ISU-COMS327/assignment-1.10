#include <cstdlib>
#include <random>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string generateRandomString(int size);

vector<string> split(const string &text, string sep);

bool starts_with(const string& s1, const string& s2);

string vector_to_string(vector<string> vec);

int random_int(int min_num, int max_num);
