#include <bits/stdc++.h>
using namespace std;

bool checkdiff(vector<int> &row)
{
    for(int i = 0; i < row.size()-1; i++)
        {
            if(abs(row[i] - row[i+1]) < 1 || abs(row[i] - row[i+1]) > 3)
            {
                return false;
            }
        }
    return true;
}

bool checkInc(vector<int> &row)
{
    for(int i = 0; i < row.size()-1; i++)
        {
            if(row[i] < row[i+1])
            {
                return false;
            }
        }
    return true;
}

bool checkDec(vector<int> &row)
{
    for(int i = 0; i < row.size()-1; i++)
        {
            if(row[i] > row[i+1])
            {
                return false;
            }
        }
    return true;
}

int main()
{
    string line;
    int safe = 0;
    int a = 0;
    while (getline(cin, line))
    {
        stringstream ss(line);
        vector<int> row;
        int value;
        while (ss >> value)
        {
            row.push_back(value);
        }
        bool l,h,ans;

        h = checkInc(row);
        l = checkDec(row);
        ans = checkdiff(row);
        if(!l)
        {
            for(int i = 0; i < row.size(); i++)
            {
                vector<int> temp = row;
                temp.erase(temp.begin() + i);
                if(checkDec(temp))
                {
                    l = true;
                    break;
                }

            }  
        }
        if(!h)
        {
            for(int i = 0; i < row.size(); i++)
            {
                vector<int> temp = row;
                temp.erase(temp.begin() + i);
                if(checkInc(temp))
                {
                    h = true;
                    break;
                }

            }
        }
        if(!ans)
        {
            for(int i = 0; i < row.size(); i++)
            {
                vector<int> temp = row;
                temp.erase(temp.begin() + i);
                if((checkDec(temp) || checkInc(temp)) && checkdiff(temp))
                {
                    ans = true;
                    break;
                }

            }
        }
        if((h || l) && ans)
        {
            safe++;
            
        }
        a++;
    }
    cout << safe << endl;
}