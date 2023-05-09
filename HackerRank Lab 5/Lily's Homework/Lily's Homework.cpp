#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int lilysHomework(vector<int> arr_orig) {
    int result = INT_MAX;

    vector<int> sorted(arr_orig);
    sort(sorted.begin(), sorted.end(), greater<int>());

    for (int rev = 0; rev < 2; rev++) {
        int curSwap = 0;
        if (rev) {
            reverse(sorted.begin(), sorted.end());
        }
        vector<int> arr(arr_orig);
        // val, pos
        unordered_map<int, int> val2pos;
        for (int i = 0; i < arr.size(); i++) {
            val2pos[arr[i]] = i;
        }


        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == sorted[i]) {
                continue;
            }
            int ai = arr[i];
            int si = sorted[i];

            swap(arr[i], arr[val2pos[si]]);
            curSwap++;

            val2pos[ai] = val2pos[si];
            val2pos[si] = i;
        }

        result = min(result, curSwap);
    }

    return result;


}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}