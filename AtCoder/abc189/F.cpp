#include <bits/stdc++.h>
using namespace std;

// clang-format off
// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto &a : x)

#define L1(u, ...) [&](auto &&u) { return __VA_ARGS__; }
#define L2(u, v, ...) [&](auto &&u, auto &&v) { return __VA_ARGS__; }

#define sort_by(x, y) sort(all(x), [&](const auto &l, const auto &r) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template <typename T> void ckmin(T &a, const T &b) { a = min(a, b); }
template <typename T> void ckmax(T &a, const T &b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template <class T1, class T2> void re(pair<T1, T2> &p);
    template <class T> void re(vector<T> &a);
    template <class T, size_t SZ> void re(array<T, SZ> &a);

    template <class T> void re(T &x) { cin >> x; }
    void re(double &x) { string t; re(t); x = stod(t); }
    template <class Arg, class... Args> void re(Arg &first, Args &...rest) { re(first); re(rest...); }

    template <class T1, class T2> void re(pair<T1, T2> &p) { re(p.f, p.s); }
    template <class T> void re(vector<T> &a) { for (int i = 0; i < sz(a); i++) re(a[i]); }
    template <class T, size_t SZ> void re(array<T, SZ> &a) { for (int i = 0; i < SZ; i++) re(a[i]); }
}
using namespace __input;

namespace __output {
    template <typename T> struct is_outputtable { template <typename C> static constexpr decltype(declval<ostream &>() << declval<const C &>(), bool()) test(int) { return true; } template <typename C> static constexpr bool test(...) { return false; } static constexpr bool value = test<T>(int()); };
    template <class T, typename V = decltype(declval<const T &>().begin()), typename S = typename enable_if<!is_outputtable<T>::value, bool>::type> void pr(const T &x);

    template <class T, typename V = decltype(declval<ostream &>() << declval<const T &>())> void pr(const T &x) { cout << x; }
    template <class T1, class T2> void pr(const pair<T1, T2> &x);
    template <class Arg, class... Args> void pr(const Arg &first, const Args &...rest) { pr(first); pr(rest...); }

    template <class T, bool pretty = true> void prContain(const T &x) { if (pretty) pr("{"); bool fst = 1; for (const auto &a : x) pr(!fst ? pretty ? ", " : " " : "", a), fst = 0; if (pretty) pr("}"); }

    template <class T> void pc(const T &x) { prContain<T, false>(x); pr("\n"); }
    template <class T1, class T2> void pr(const pair<T1, T2> &x) { pr("{", x.f, ", ", x.s, "}"); }
    template <class T, typename V, typename S> void pr(const T &x) { prContain(x); }

    void ps() { pr("\n"); }
    template <class Arg> void ps(const Arg &first) { pr(first); ps(); }
    template <class Arg, class... Args> void ps(const Arg &first, const Args &...rest) { pr(first, " "); ps(rest...); }
}
using namespace __output;

#define __pn(x) pr(#x, " = ")
#ifdef ANAND_LOCAL
#define pd(...) pr("\033[1;31m"), __pn((__VA_ARGS__)), ps(__VA_ARGS__), pr("\033[0m"), cout << flush
#else
#define pd(...)
#endif

namespace __algorithm {
    template <typename T> void dedup(vector<T> &v) { sort(all(v)); v.erase(unique(all(v)), v.end()); }
    template <typename T> typename vector<T>::const_iterator find(const vector<T> &v, const T &x) { auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end(); }
    template <typename T> size_t index(const vector<T> &v, const T &x) { auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin(); }
    template <typename I> struct _reversed_struct { I &v_; explicit _reversed_struct(I &v) : v_{v} {} typename I::reverse_iterator begin() const { return v_.rbegin(); } typename I::reverse_iterator end() const { return v_.rend(); } };
    template <typename I> _reversed_struct<I> reversed(I &v) { return _reversed_struct<I>(v); }
}
using namespace __algorithm;

namespace __io {
    void setIO() { ios_base::sync_with_stdio(0); cin.tie(0); cout << setprecision(15); }
}
using namespace __io;
// }}}
// matrix {{{
#include <vector>
#include <iostream>
#include <iomanip>

template<typename T>
struct matrix {
    int N, M;
    std::vector<T> data;

    matrix(int _N, int _M, T value = T{}) : N(_N), M(_M), data(N * M, value) {}

    typename std::vector<T>::iterator operator[](int i) {
        return data.begin() + i * M;
    }
    typename std::vector<T>::const_iterator operator[](int i) const {
        return data.begin() + i * M;
    }

    friend matrix<T> operator * (const matrix<T>& a, const matrix<T>& b) {
        assert(a.M == b.N);
        matrix<T> res(a.N, b.M);
        for (int i = 0; i < a.N; i++)
            for (int k = 0; k < a.M; k++)
                for (int j = 0; j < b.M; j++)
                    res[i][j] += a[i][k] * b[k][j];
        return res;
    }

    friend std::vector<T> operator * (const std::vector<T>& v, const matrix<T>& m) {
        assert(sz(v) == m.N);
        std::vector<T> res(m.M);
        for (int i = 0; i < m.N; i++)
            for (int j = 0; j < m.M; j++)
                res[j] += v[i] * m[i][j];
        return res;
    }

    friend std::vector<T> operator * (const matrix<T>& m, const std::vector<T>& v) {
        assert(m.M == sz(v));
        std::vector<T> res(m.N);
        for (int i = 0; i < m.N; i++)
            for (int j = 0; j < m.M; j++)
                res[i] += m[i][j] * v[j];
        return res;
    }

    matrix pow(int64_t e) const {
        assert(N == M);
        if (e == 0) return matrix<T>(N, N, 0, 1);
        if (e&1) return *this * pow(e - 1);
        return (*this * *this).pow(e / 2);
    }

    friend void row_reduce(matrix<T> &m) {
        int rank = 0;
        for (int j = 0; j < m.M && rank < m.N; j++) {
            for (int i = rank; i < m.N; i++) {
                if (m[i][j] != 0) {
                    swap_ranges(m[rank], m[rank] + m.M, m[i]);
                    break;
                }
            }
            if (m[rank][j] == 0)
                continue;

            T inv = 1 / m[rank][j];
            for (int k = j; k < m.M; k++)
                m[rank][k] *= inv;

            for (int i = 0; i < m.N; i++) {
                if (i != rank) {
                    T c = m[i][j];
                    for (int k = j; k < m.M; k++)
                        m[i][k] -= c * m[rank][k];
                }
            }
            rank++;
        }

        m.N = rank;
        m.data.resize(m.N * m.M);
    }

    friend std::ostream& operator << (std::ostream& os, const matrix<T>& m) {
        for (int i = 0; i < m.N; i++) {
            os << (i ? i < m.N - 1 ? "\u2503" : "\u2517" : "\n\u250F");
            for (int j = 0; j < m.M; j++)
                os << std::setw(12) << m[i][j];
            os << "  " << (i ? i < m.N - 1 ? "\u2503" : "\u251B" : "\u2512") << "\n";
        }
        return os;
    }
};
// }}}

// clang-format on

using M = matrix<ll>;

int main() {
    setIO();

    auto op = [&](int type, int p = 0) {
        M op(3, 3);
        switch (type) {
        case 1:
            op[0][1] = 1;
            op[1][0] = -1;
            break;
        case 2:
            op[0][1] = -1;
            op[1][0] = 1;
            break;
        case 3:
            op[0][0] = -1;
            op[0][2] = 2 * p;
            op[1][1] = 1;
            break;
        case 4:
            op[0][0] = 1;
            op[1][1] = -1;
            op[1][2] = 2 * p;
            break;
        }
        op[2][2] = 1;
        return op;
    };

    int n;
    re(n);
    vector<vll> points(n, vll(3));
    for (int i = 0; i < n; i++) {
        int x, y;
        re(x, y);
        points[i][0] = x;
        points[i][1] = y;
        points[i][2] = 1;
    }

    int m;
    re(m);
    vector<M> ops(1, M(3, 3));
    ops[0][0][0] = ops[0][1][1] = ops[0][2][2] = 1;
    for (int i = 0; i < m; i++) {
        int t;
        re(t);
        int p = 0;
        if (t == 3 || t == 4)
            re(p);
        M cur = op(t, p);
        ops.push_back(cur * ops.back());
    }

    int q;
    re(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        re(a, b);
        b--;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << ops[a][i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i = 0; i < 3; i++){
            cout << points[b][i] << " ";
        }
        cout << endl << endl;
        vll ans = ops[a] * points[b];
        ps(ans[0], ans[1]);
    }
    
    return 0;
}
