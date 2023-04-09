#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    int runningSum = 0; //initializing the sum of removed integers from both stacks
    
    int i = 0;  //location of an element in the stack a
    int j = 0;  //location of an element in the stack b
    
    int removeInt;
    
    while (maxSum > runningSum){
        removeInt = min(a[i],b[j]);        //minimum of the top elements of stacks a and b will be removed at each time
        runningSum += removeInt;
        
        if  (maxSum > runningSum){
            if (removeInt == a[i]){
                i++;                    //if the integer is removed from stack a, top of the stack a is changed
            }        
            else{
                j++;                   //if the integer is removed from stack b, top of the stack a is changed
            }
        }
        
    }
    return i+j;                     //return the number of integers removed from both stacks
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int maxSum = stoi(first_multiple_input[2]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        string b_temp_temp;
        getline(cin, b_temp_temp);

        vector<string> b_temp = split(rtrim(b_temp_temp));

        vector<int> b(m);

        for (int i = 0; i < m; i++) {
            int b_item = stoi(b_temp[i]);

            b[i] = b_item;
        }

        int result = twoStacks(maxSum, a, b);

        fout << result << "\n";
    }

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
