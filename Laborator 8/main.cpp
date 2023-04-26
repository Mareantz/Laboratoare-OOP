#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
ifstream fin("input.txt");
int main()
{
    map<string, int> m;
    char chars[] = " ,?!.";
    string s;
    priority_queue<int> q;
    getline(fin, s);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    //split s without using strtok
    int start = 0;
    int end = 0;
    while (end != string::npos)
    {
        end = s.find_first_of(chars, start);
        string word = s.substr(start, end - start);
        if (word != "")
            m[word]++;
        start = end + 1;
    }
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
        q.push(it->second);
    }
    cout << "==============================" << endl;
    while (!q.empty())
    {
        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
            if (it->second == q.top())
            {
                cout << it->first << " => " << it->second << endl;
                q.pop();
                m.erase(it);
                break;
            }
    }
    return 0;
}