#include<iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    int lg = 0;
    int sum = 0;
    int back = 0;
    cin >> n >> lg;
    vector<long long> v;
    long long temp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp <= lg)
        {
            v.push_back(temp);
        }
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > lg)
        {
            if (sum != 0)
            {
                back++;
            }
            back++;
            sum = 0;
        }
        if (sum + v[i] > lg)
        {
            sum = v[i];
            back++;
        }
        else
        {
            sum += v[i];
        }
    }



    cout << back << endl;

    return 0;
}