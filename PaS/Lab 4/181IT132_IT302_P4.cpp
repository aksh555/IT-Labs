#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair
#define vec vector<ll>
#define ppl vector<pair<ll, ll>>
#define fi first
#define si second
#define pr pair<ll, ll>

ll nCr(ll n, ll r)
{
    ll res = 1;
    if (r > n - r) r = n - r;
    for (ll i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

ll getvalue(ll x, ll y, ll z, ll b, ll r, ll g)
{
    ll res = 1;
    res *= nCr(b, x);
    res *= nCr(r, y);
    res *= nCr(g, z);
    return res;
}

bool isValid(string s)
{
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9') continue;
        else return false;
    }
    return true;
}

int main()
{
    ofstream f;
    f.open("181IT132_IT302_P4_Output_TC6.txt");

    string n, b, r, g;
    cout << "Enter the number of pens selected: ";
    cin >> n;
    cout << "Enter total number of Blue pens: ";
    cin >> b;
    cout << "Enter total number of Red pens: ";
    cin >> r;
    cout << "Enter total number of Green pens: ";
    cin >> g;
    f << "Number of pens selected: " << n << "\n";
    f << "Number of blue pens: " << b << "\n";
    f << "Number of red pens: " << r << "\n";
    f << "Number of green pens: " << g << "\n\n";

    ll num, br, red, gr;
    bool invalid = false;

    if (!isValid(n) || !isValid(b) || !isValid(r) || !isValid(g))
        invalid = true;
    else
    {
        num = stoi(n);
        br = stoi(b);
        red = stoi(r);
        gr = stoi(g);
        if (num > br + red + gr)
            invalid = true;

        else
        {
            ll x = 0;
            ll y = 0;
            ppl v;
            for (ll i = 0; i <= br; i++)
            {
                for (ll j = 0; j <= red; j++)
                    if (i + j <= num) v.pb(mp(i, j));
            }
            ll p = br + red + gr;
            ll tot = nCr(p, num);

            vector<vector<ll>> vi(num + 1, vector<ll>(num + 1, 0));
            ll sum = 0;
            for (ll i = 0; i < v.size(); i++)
            {
                ll rem = num - v[i].fi - v[i].si;
                ll val = getvalue(v[i].fi, v[i].si, rem, br, red, gr);
                sum += val;
                vi[v[i].fi][v[i].si] = val;
            }

            cout << "\nJoint Probability Distribution values\n";

            f << "\nJoint Probability Distribution values\n";
            for (ll i = 0; i <= num; i++)
            {
                for (ll j = 0; j <= num; j++)
                {
                    cout << "f(" << i << "," << j << ") = ";
                    f << "f(" << i << "," << j << ") = ";

                    ll q = vi[i][j];
                    if (q == 0)
                    {
                        cout << 0 << "\n";
                        f << 0 << "\n";
                    }
                    else
                    {
                        ll temp = tot;
                        ll gcd = __gcd(q, temp);
                        q /= gcd;
                        temp /= gcd;
                        cout << q << "/" << temp << " = " << (1.0) * q / temp << "\n";
                        f << q << "/" << temp << " = " << (1.0) * q / temp << "\n";
                    }
                }
                cout << "\n";
            }
            double ans;
            ans = double(sum) / tot;

            vector<ll> marginal_blue(num + 1);
            vector<ll> marginal_red(num + 1);
            for (ll i = 0; i <= num; i++)
            {
                ll sum = 0;
                for (ll j = 0; j <= num; j++)
                    sum += vi[i][j];
                marginal_blue[i] = sum;
            }
            for (ll j = 0; j <= num; j++)
            {
                ll sum = 0;
                for (ll i = 0; i <= num; i++)
                    sum += vi[i][j];
                marginal_red[j] = sum;
            }
            cout << "\nMarginal Table values for Blue alone i.e choosing from 0 to N is:"<< "\n";
            f << "\nMarginal Table values for Blue alone i.e choosing from 0 to N is:"<< "\n";
            for (ll i = 0; i <= num; i++)
            {
                ll x = marginal_blue[i];
                ll temp = tot;
                ll gcd = __gcd(x, temp);
                x /= gcd;
                temp /= gcd;
                cout << "g(" << i << ") = " << x << "/" << temp << " = " << (1.0) * x / temp << "\n";
                f << "g(" << i << ") = " << x << "/" << temp << " = " << (1.0) * x / temp << "\n";
            }
            cout << endl;
            cout << "Marginal Table for Red alone i.e choosing from 0 to N is:"<< "\n";
            f << "\nMarginal Table for Red alone i.e choosing from 0 to N is:"<< "\n";
            for (ll i = 0; i <= num; i++)
            {
                ll x = marginal_red[i];
                ll temp = tot;
                ll gcd = __gcd(x, temp);
                x /= gcd;
                temp /= gcd;
                cout << "h(" << i << ") = " << x << "/" << temp << " = " << (1.0) * x / temp << "\n";
                f << "h(" << i << ") = " << x << "/" << temp << " = " << (1.0) * x / temp << "\n";
            }
            cout << endl;
        }
    }

    if (invalid)
    {
        cout << "Invalid input!" << endl;
        f << "Invalid input!" << endl;
    }

    return 0;
}