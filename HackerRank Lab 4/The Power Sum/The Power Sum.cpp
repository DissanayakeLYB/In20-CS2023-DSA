#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int powerSum(int X, int N) {
    int count = 0;
    int num = 1;
    int value = pow(num, N);
    stack<pair<int, int>> s;
    s.push(make_pair(X, num));
    while (!s.empty()) {
        pair<int, int> p = s.top();
        s.pop();
        int x = p.first;
        int n = p.second;
        if (x == 0) {
            count++;
        } else if (x > 0 && n <= X) {
            s.push(make_pair(x - pow(n, N), n + 1));
            s.push(make_pair(x, n + 1));
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
