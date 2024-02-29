#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("matrices.txt", "r", stdin);
    int i;
    string tmp;
    vector<int> v1, v2;
    char c, operation;
    cin >> c;
    if (c == '[')
    {
        while (true)
        {
            cin >> tmp;
            if (tmp == "]")
            {
                break;
            }
            if (tmp[tmp.size() - 1] == ']')
            {
                tmp.pop_back();
                v1.push_back(stoi(tmp));
                break;
            }
            else
            {
                v1.push_back(stoi(tmp));
            }
        }
        cin >> operation;
        cin >> c;
        if (c == '[')
        {
            while (true)
            {
                cin >> tmp;
                if (tmp == "]")
                {
                    break;
                }
                if (tmp[tmp.size() - 1] == ']')
                {
                    tmp.pop_back();
                    v2.push_back(stoi(tmp));
                    break;
                }
                else
                {
                    v2.push_back(stoi(tmp));
                }
            }
        }
    }
    cout << "[";
    if (operation == '+')
    {
        for (i = 0; i < v1.size(); i++)
        {
            cout << v1[i] + v2[i];
            if (i != v1.size() - 1)
            {
                cout << " ";
            }
        }
    }
    else if (operation == '-')
    {
        for (i = 0; i < v1.size(); i++)
        {
            cout << v1[i] - v2[i];
            if (i != v1.size() - 1)
            {
                cout << " ";
            }
        }
    }
    cout << "]\n";
    system("pause");
    return 0;
}