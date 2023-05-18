#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickSort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> quickSort(vector<int> arr) {
    //initialize vector arrays to add the elements and expand their size while adding the elements
    vector<int> equal;
    vector<int> left;
    vector<int> right;
    vector<int> partArr; //this is the array which has the pivot element at the correct position
    
    int ArrSize = arr.size(); //size of the unsorted array
    
    equal.push_back(arr[0]); //select the first element of the unsorted array as the pivot element
    
    //from this, the elements are added to left, equal, right arrays accordingly
    for (int i = 1; i < ArrSize ; i++){
        if (equal[0] == arr[i]){
            equal.push_back(arr[i]);
        }
        else if (equal[0] > arr[i]){
            left.push_back(arr[i]);
        }
        else{
            right.push_back(arr[i]);
        }
    }
    
    //sizes of the arrays created as left, equal and right
    int sizeLeft = left.size();
    int sizeEqual = equal.size();
    int sizeRight = right.size();
    
    //merge left, equal and right arrays to properly place the pivot element where it must belong
    for (int a = 0; a < sizeLeft ; a++ ){
        partArr.push_back(left[a]);
    } 
    
    for (int b = 0; b < sizeEqual; b++ ){
        partArr.push_back(equal[b]);
    }
    
    for (int c = 0; c < sizeRight; c++ ){
        partArr.push_back(right[c]);
    }
    
    return partArr; //output the partitioned array
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

    vector<int> result = quickSort(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
