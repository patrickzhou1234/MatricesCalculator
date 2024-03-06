#include <iostream>
#include <vector>

using namespace std;

char operation;
string c;
int i, j, m, sum;
vector<vector<int>> mat, mat2, ans;
vector<int> row;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("matrices.txt", "r", stdin);
    freopen("calculated.txt", "w", stdout);
    getline(cin, c);
    if (c == "[")
    {
        while (true)
        {
            getline(cin, c);
            if (c == "]")
            {
                break;
            }
            while (c.find(" ") != string::npos)
            {
                row.push_back(stoi(c.substr(0, c.find(" "))));
                c = c.substr(c.find(" ") + 1);
            }
            row.push_back(stoi(c.substr(0, c.find(" "))));
            c = c.substr(c.find(" ") + 1);
            mat.push_back(row);
            row.clear();
        }
    }
    getline(cin, c);
    operation = c[0];
    getline(cin, c);
    if (c == "[")
    {
        while (true)
        {
            getline(cin, c);
            if (c == "]")
            {
                break;
            }
            while (c.find(" ") != string::npos)
            {
                row.push_back(stoi(c.substr(0, c.find(" "))));
                c = c.substr(c.find(" ") + 1);
            }
            row.push_back(stoi(c.substr(0, c.find(" "))));
            c = c.substr(c.find(" ") + 1);
            mat2.push_back(row);
            row.clear();
        }
    }
    if (operation == '+')
    {
        if (mat.size() == mat2.size() && mat[0].size() == mat2[0].size())
        {
            for (i = 0; i < mat.size(); i++)
            {
                for (j = 0; j < mat[0].size(); j++)
                {
                    row.push_back(mat[i][j] + mat2[i][j]);
                }
                ans.push_back(row);
                row.clear();
            }
        }
    }
    if (operation == '-')
    {
        if (mat.size() == mat2.size() && mat[0].size() == mat2[0].size())
        {
            for (i = 0; i < mat.size(); i++)
            {
                for (j = 0; j < mat[0].size(); j++)
                {
                    row.push_back(mat[i][j] - mat2[i][j]);
                }
                ans.push_back(row);
                row.clear();
            }
        }
    }
    if (operation == '*')
    {
        if (mat[0].size() == mat2.size())
        {
            for (i = 0; i < mat.size(); i++)
            {
                sum = 0;
                for (j = 0; j < mat[i].size(); j++)
                {
                    for (m = 0; m < mat2[0].size(); m++)
                    {
                        sum += mat[i][j] * mat2[j][m];
                    }
                }
                row.push_back(sum);
                sum = 0;
                ans.push_back(row);
                row.clear();
            }
        }
    }
    cout << "[\n";
    for (i = 0; i < ans.size(); i++)
    {
        for (j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            if (j != ans[i].size() - 1)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    cout << "]";
    return 0;
}