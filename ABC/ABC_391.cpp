#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
#define ll long long
#define lld long double
template <class T>
using ordered_set = tree<T, null_type,
                         less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void A()
{
    string D;
    cin >> D;

    if (D == "N")
    {
        cout << "S" << endl;
    }
    else if (D == "S")
    {
        cout << "N" << endl;
    }
    else if (D == "E")
    {
        cout << "W" << endl;
    }
    else if (D == "W")
    {
        cout << "E" << endl;
    }
    else if (D == "NE")
    {
        cout << "SW" << endl;
    }
    else if (D == "NW")
    {
        cout << "SE" << endl;
    }
    else if (D == "SE")
    {
        cout << "NW" << endl;
    }
    else if (D == "SW")
    {
        cout << "NE" << endl;
    }
}

bool check(ll I, ll J, vector<vector<char>> &S, vector<vector<char>> &T)
{
    for (ll i = I; i < I + T.size(); i++)
    {
        if (i >= S.size())
            return false;
        for (ll j = J; j < J + T.size(); j++)
        {
            if (j >= S.size())
                return false;
            if (S[i][j] != T[i - I][j - J])
                return false;
        }
    }
    return true;
}
void B()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> S(n, vector<char>(n));
    vector<vector<char>> T(m, vector<char>(m));
    for (auto &row : S)
    {
        for (auto &it : row)
        {
            cin >> it;
        }
    }
    for (auto &row : T)
    {
        for (auto &it : row)
        {
            cin >> it;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (S[i][j] == T[0][0])
            {
                if (check(i, j, S, T))
                {
                    cout << i + 1 << " " << j + 1 << "\n";
                    return;
                }
            }
        }
    }
    cout << "Something wrong in your execution.... answer exist";
}

void C()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> nests(n, 1);
    unordered_map<ll, ll> mpp;
    for (ll i = 0; i < n; i++)
    {
        nests[i] = i;
        mpp[i] = i;
    }
    ordered_set<pair<ll, ll>> st;
    vector<ll> st1;
    for (ll i = 0; i < n; i++)
    {
        st.insert({1, i});
        st1.push_back(1);
    }

    // cout << "***********************\n";
    // cout << st.size() << endl;
    // for (auto it = st.begin(); it != st.end(); ++it)
    // {
    //     cout << it->first << " " << it->second << " \n";
    // }
    // cout << endl;

    // cout << "\n***********************\n";
    for (ll k = 0; k < q; k++)
    {
        ll type;
        cin >> type;
        vector<ll> allInp;
        if (type == 2)
        {
            allInp.push_back(2);
        }
        else
        {
            ll p, h;
            cin >> p >> h;
            allInp.push_back(1);
            allInp.push_back(p);
            allInp.push_back(h);
        }

        if (allInp.size() == 1)
        {
            if (allInp[0] == 2ll)
            {
                // for (auto it = st.begin(); it != st.end(); ++it)
                // {
                //     cout << it->first << " " << it->second << " \n";
                // }

                cout << st.size() - (st.order_of_key({2, 0})) << endl;
            }
            else
            {
                throw runtime_error("value is not 2");
            }
        }
        else
        {
            if (allInp[0] == 1)
            {
                /// get intial whre the priegon was
                ll initialNest = mpp[allInp[1] - 1];
                // cout << "init nest : " << initialNest << endl;
                ll initialBirdInInitNest = st1[initialNest];

                ll finalNest = allInp[2] - 1;
                ll beforeAddIngFinalNestBirds = st1[finalNest];

                mpp[allInp[1] - 1] = finalNest;
                st1[initialNest]--;
                st1[finalNest]++;

                auto it1 = st.find({initialBirdInInitNest, initialNest});
                st.erase(it1);
                st.insert({st1[initialNest], initialNest});

                auto it2 = st.find({beforeAddIngFinalNestBirds, finalNest});
                st.erase(it2);
                st.insert({st1[finalNest], finalNest});

                // for (auto it = st.begin(); it != st.end(); ++it)
                // {
                //     cout << it->first << " " << it->second << " \n";
                // }
            }
            else
            {
                throw runtime_error("value is not 1");
            }
        }
    }
}

void D()
{
    // ll n, w;
    // cin >> n >> w;
    // vector<pair<ll, ll>> vec;

    // unordered_map<ll, ordered_set<ll>> mpp;
    // for (ll i = 0; i < n; i++)
    // {
    //     ll x, y;
    //     cin >> x >> y;
    //     vec.push_back({y, x});

    //     mpp[x].insert(i + 1);
    // }
    // ll q;
    // cin >> q;
    // vector<pair<ll, ll>> queries;
    // for (ll i = 0; i < q; i++)
    // {
    //     ll t, a;
    //     cin >> t >> a;
    //     queries.push_back({t, a});
    // }

    // // mini mum
    // ll mini = LONG_LONG_MAX;
    // ll extraT = -1;
    // for (auto it : mpp)
    // {
    //     mini = min(mini, static_cast<ll>(it.second.size()));

    //     cout << "om : " << *it.second.find_by_order(0) << " " << vec[*it.second.find_by_order(0) - 1].first << endl;
    //     extraT = max(extraT, vec[*it.second.find_by_order(0) - 1].first);
    // }

    // // find maximum distannt
    // cout << "extra T : " << extraT << endl;

    // for (auto it : queries)
    // {
    //     ll box = it.second;
    //     ll time = it.first;

    //     auto pos = vec[box - 1];

    //     auto index = mpp[pos.second].order_of_key(box) + 1;

    //     if (index <= mini)
    //     {
    //         // now find out time
    //         if (pos.first - 1 + (extraT - vec[*mpp[pos.second].find_by_order(0) - 1].first) >= time)
    //         {
    //             cout << "YES" << endl;
    //         }
    //         else
    //         {
    //             cout << "NO" << endl;
    //         }
    //     }
    //     else
    //     {
    //         cout << "YES" << endl;
    //     }
    // }
    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> vec;
    unordered_map<ll, ordered_set<ll>> mpp;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;

        vec.push_back({y, x});
        mpp[x].insert(i + 1);
    }
    ll q;
    cin >> q;
    vector<pair<ll, ll>> queries;
    for (ll i = 0; i < q; i++)
    {
        ll t, a;
        cin >> t >> a;
        queries.push_back({t, a});
    }

    ll mini = LONG_LONG_MAX;
    for (auto it : mpp)
    {
        mini = min(mini, static_cast<ll>(it.second.size()));
    }
    vector<ll> jod(mini);
    for (ll i = 0; i < mini; i++)
    {
        ll maxi = -1;
        for (auto it : mpp)
        {
            maxi = max(maxi, static_cast<ll>(vec[*it.second.find_by_order(i) - 1].first));
        }
        jod[i] = maxi;
    }

    // for (auto it : jod)
    // {
    //     cout << it << " **** ";
    // }
    // cout << endl;

    for (auto it : queries)
    {
        ll time = it.first;
        ll box = it.second;

        // find its index
        ll boxInd = mpp[vec[box - 1].second].order_of_key(box);

        // cout << "boxInd " << boxInd << endl;

        if (boxInd + 1 > mini)
        {
            cout << "Yes" << endl;
        }
        else
        {
            ll timeReq = jod[boxInd];

            // cout << "timeReq : " << timeReq << endl;
            if (timeReq > time)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}

void E()
{
    ll N;
    cin >> N;
    string s;
    cin >> s;
}

void solve()
{
    // A();
    // B();
    // C();
    D();
}

int main()
{
    // ll t;
    // cin >> t;
    // while (t--)
    {
        solve();
    }
}
