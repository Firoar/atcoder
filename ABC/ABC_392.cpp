#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
#define ll long long
#define lld long double
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

void A()
{
    vector<ll> vec(3);
    for (auto &it : vec)
    {
        cin >> it;
    }
    sort(vec.begin(), vec.end());

    if (vec[0] * vec[1] == vec[2])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
void B()
{
    ll n, m;
    cin >> n >> m;
    unordered_set<ll> st;
    for (ll i = 0; i < m; i++)
    {
        ll z;
        cin >> z;
        st.insert(z);
    }
    vector<ll> ans;
    for (ll j = 1; j <= n; j++)
    {
        if (st.find(j) == st.end())
        {
            ans.push_back(j);
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

void C()
{
    ll n;
    cin >> n;
    vector<ll> p(n), q(n);
    unordered_map<ll, ll> mpp, mpq, mpr;
    for (ll i = 0; i < n; i++)
    {
        ll it;
        cin >> it;
        p[i] = it;
        mpp[i + 1] = it;
    }
    for (ll i = 0; i < n; i++)
    {
        ll it;
        cin >> it;
        q[i] = it;
        mpq[it] = i + 1;
        mpr[i + 1] = it;
    }

    for (int i = 0; i < n; i++)
    {
        ll jerseyP = mpq[i + 1];
        ll stareP = mpp[jerseyP];
        cout << mpr[stareP] << " ";
    }
    cout << endl;
}
void D()
{
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    vector<vector<ll>> vec;
    unordered_map<ll, unordered_map<ll, ll>> mpp;
    for (ll i = 0; i < n; i++)
    {
        ll k;
        cin >> k;
        vector<ll> v(k + 1);
        v[0] = k;
        unordered_map<ll, ll> mp;
        for (ll j = 1; j < k + 1; j++)
        {
            cin >> v[j];
            mp[v[j]]++;
        }
        mpp[i] = mp;
        vec.push_back(v);
    }
    // for (auto it : vec)
    // {
    //     for (auto ele : it)
    //     {
    //         cout << ele << " ";
    //     }
    //     cout << endl;
    // }
    long double maxi = -1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll total = vec[i][0] * vec[j][0];
            // cout << "total : " << total << endl;
            ll cnt = 0;
            for (ll k = 1; k < vec[i].size(); k++)
            {
                cnt += mpp[j][vec[i][k]];
            }
            // cout << cnt << " " << total;
            lld p = static_cast<lld>(cnt) / static_cast<lld>(total);
            maxi = max(maxi, p);
        }
    }
    cout << maxi << endl;
}

void E()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> vec(n + 1, vector<ll>(n + 1, 0));
    unordered_map<ll, queue<ll>> extras;
    unordered_map<ll, unordered_set<ll>> mpp;
    vector<pair<ll, ll>> all;

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        all.push_back({a, b});
        if (a == b)
        {
            extras[a].push(i);
        }
        else
        {
            if (mpp[min(a, b)].find(max(a, b)) == mpp[min(a, b)].end())
            {
                mpp[min(a, b)].insert(max(a, b));
                vec[a][b] = 1;
                vec[b][a] = 1;
            }
            else
            {
                extras[a].push(i);
            }
        }
    }

    // Check disjoint components
    vector<ll> disjoint;
    unordered_map<ll, bool> dj;
    vector<bool> visited(n + 1, false);
    // DFS function to visit nodes
    function<void(ll)> dfs = [&](ll node)
    {
        visited[node] = true;
        for (ll i = 1; i <= n; i++)
        {
            if (vec[node][i] && !visited[i])
            {
                dfs(i);
            }
        }
    };

    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            disjoint.push_back(i);
            dj[i] = true;
            dfs(i);
        }
    }

    // for (auto it : disjoint)
    // {
    //     cout << it << " ** ";
    // }

    // cout << endl;
    // cout << disjoint[0] << " ****** " << disjoint[1] << endl;

    if (disjoint.size() == 1)
    {
        cout << 0 << endl;
        return;
    }
    unordered_map<ll, bool> finished;
    cout << disjoint.size() - 1 << endl;

    for (ll i = 0; i < disjoint.size(); i++)
    {

        if (1)
        {
            // cout << "p : " << i << " " << extras[disjoint[i]].size() << endl;

            while (!extras[disjoint[i]].empty())
            {

                for (ll j = 0; j < disjoint.size(); j++)
                {
                    if (j != i)
                    {
                        if (!finished[j])
                        {

                            // cout << disjoint[j] << " om " << disjoint[i] << " " << i << " -- " << j << endl;
                            cout << extras[disjoint[i]].front() + 1 << " " << all[extras[i].front()].second << " " << disjoint[j] << endl;
                            extras[disjoint[i]].pop();
                            finished[j] = true;
                            if (extras[disjoint[i]].empty())
                                break;
                        }
                    }
                }
            }
        }
    }
}

void G()
{
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }
    ordered_set st;
    for (ll i = 0; i < n; i++)
    {
        st.insert(i);
    }
    vector<ll> ans(n);
    for (ll i = n - 1; i >= 0; i--)
    {
        ll ele = i + 1;
        ll ind = *st.find_by_order(vec[i] - 1);
        ans[ind] = ele;
        st.erase(ind);
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

void F()
{
}

void solve()
{
    G();
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
