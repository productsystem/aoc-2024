#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    int safe = 0;

    while (getline(cin, line))
    {
        stringstream ss(line);
        vector<int> row;
        int value;
        while (ss >> value)
        {
            row.push_back(value);
        }
        bool l = true, h = true , ans = true;;

        for(int i = 0; i < row.size()-1; i++)
        {
            if(row[i] < row[i+1])
            {
                h = false;
            }
        }
        for(int i = 0; i < row.size()-1; i++)
        {
            if(row[i] > row[i+1])
            {
                l = false;
            }
        }
        for(int i = 0; i < row.size()-1; i++)
        {
            if(abs(row[i] - row[i+1]) < 1 || abs(row[i] - row[i+1]) > 3)
            {
                ans = false;
            }
        }

        if((h || l) && ans)
        {
            safe++;
        }
    }
    cout << safe << endl;
}