#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> left, right;
    string line;
    int first, second;
    int n = 0;
    while(getline(cin, line))
    {
        int wp1 = line.find_first_of(' ');
        int wp2 = line.find_last_of(' ');

        first = atoi(line.substr(0, wp1).c_str());
        second = atoi(line.substr(wp2, line.size()).c_str());

        left.push_back(first);
        right.push_back(second);

        n++;
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += abs(right[i] - left[i]);
    }

    cout << sum << endl;
}