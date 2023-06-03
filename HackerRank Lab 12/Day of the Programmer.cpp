#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

string dayOfProgrammer(int year) {
    
    int programmersDay = 256;
    string d, m;
    int y = year;
    
    //{month number, number of days in the month} for both Calenders
    int monthsInLeap[12][2] = {{1,31},{2,29},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
    int monthsInNonLeap[12][2] = {{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};

    //use Julian calender
    if (y < 1918){
        
        //leap year 
        if (y % 4 == 0){
            for (auto days : monthsInLeap){
                if (programmersDay > days[1]){
                    programmersDay -= days[1];
                }
                
                else{
                    //day
                    d = to_string(programmersDay);
                    
                    //month
                    if (days[0] < 10){
                        m = "0" + to_string(days[0]);
                    }
                    else{
                        m = to_string(days[0]);
                    }
                    
                    break;
                }
            }
        }
        
        //not a leap year
        else{
            for (auto days : monthsInNonLeap){
                if (programmersDay > days[1]){
                    programmersDay -= days[1];
                }
                else{
                    //day
                    d = to_string(programmersDay);
                    
                    //month
                    if (days[0] < 10){
                        m = "0" + to_string(days[0]);
                    }
                    else{
                        m = to_string(days[0]);
                    }
                    
                    break;
                }
            }
        }
    }
    
    //use Gregorian calender
    else if (y > 1918){
        //leap year
        if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)){
            for (auto days : monthsInLeap){
                if (programmersDay > days[1]){
                    programmersDay -= days[1];
                }
                
                else{
                    //day
                    d = to_string(programmersDay);
                    
                    //month
                    if (days[0] < 10){
                        m = "0" + to_string(days[0]);
                    }
                    else{
                        m = to_string(days[0]);
                    }
                    break;
                }
            }
        }
        //not a leap year
        else{
            for (auto days : monthsInNonLeap){
                if (programmersDay > days[1]){
                    programmersDay -= days[1];
                }
                else{
                    //day
                    d = to_string(programmersDay);
                    
                    //month
                    if (days[0] < 10){
                        m = "0" + to_string(days[0]);
                    }
                    else{
                        m = to_string(days[0]);
                    }
                    
                    break;
                }
            }
        }
    }
    
    else {
        //{month number, number of days in the month} for transition between calenders
        int monthsInLeap[12][2] = {{1,31},{2,16},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};
        int monthsInNonLeap[12][2] = {{1,31},{2,15},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31}};

        if (y % 4 == 0){
            for (auto days : monthsInLeap){
                if (programmersDay > days[1]){
                    programmersDay -= days[1];
                }
                else{
                    //day
                    if (days[0] == 2){
                        d = to_string(programmersDay + 13);
                    }
                    else{
                        d = to_string(programmersDay);
                    }
                    
                    //month
                    if (days[0] < 10){
                        m = "0" + to_string(days[0]);
                    }
                    else{
                        m = to_string(days[0]);
                    }
                    
                    break;
                }
            }
        }
        else{
            for (auto days : monthsInNonLeap){
                if (programmersDay > days[1]){
                    programmersDay -= days[1];
                }
                
                else{
                    //day
                    if (days[0] == 2){
                        d = to_string(programmersDay + 13);
                    }
                    else{
                        d = to_string(programmersDay);
                    }
                    
                    //month
                    if (days[0] < 10){
                        m = "0" + to_string(days[0]);
                    }
                    else{
                        m = to_string(days[0]);
                    }
                    
                    break;
                }
            }
        }
    }
    
    
    string output = d + "." + m + "." + to_string(y);
    return output;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
