#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> left, right;
    map<int,int> sim;
    string line;
    int first, second;
    int n = 0;
    int duplicates = 0;
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
    for(int i = 0, j =0; i < left.size(); i++)
    {
        duplicates = 0;
        while (j < right.size() && left[i] > right[j]) {
        j++;
        }

        while (j < right.size() && left[i] == right[j]) {
        duplicates++;
        j++;
        }
        sum += left[i] * duplicates;
    }

    cout << sum << endl;
}