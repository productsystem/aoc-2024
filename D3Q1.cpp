#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    long long sum = 0;
    while(getline(cin, line))
    {
        regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
        

        auto it = sregex_iterator(line.begin(), line.end(), pattern);
        auto end = sregex_iterator();

        for (; it != end; ++it)
        {
            int x = stoi((*it)[1].str());
            int y = stoi((*it)[2].str());
            sum += x * y;
        }
    }
    cout << sum << endl;
}