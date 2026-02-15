#include <bits/stdc++.h>
using namespace std;

void stock_span(vector<int> stock, vector<int> span)
{
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < stock.size(); i++)
    {

        int currEle = stock[i];

        while (!(s.empty()) && currEle >= stock[s.top()])
        {
            s.pop();
        }

        if (s.empty())
        {
            span[i] = i + 1;
        }

        else
        {
            int preHigh = s.top();
            span[i] = i - preHigh;
        }

        s.push(i);

        // for (int i = 0; i < span.size(); i++)
        // {
        //     cout << span[i] << " ";
        // }
        // cout << endl;
    }
    for (int i = 0; i < span.size(); i++)
    {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(stock.size(), 0);

    stock_span(stock, span);

    return 0;
}