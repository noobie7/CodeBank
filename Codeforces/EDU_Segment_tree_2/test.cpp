struct Segtree{
    int size;
    vector<ll> op;
    vector<ll> values;
    ll neutral_element = -1;
    ll no_operation = LLONG_MAX;
    ll modify_op(ll a, ll b){ 
        if(b == no_operation) return a;
        return a | b ;
    }
    ll calc_op(ll a, ll b){
        return (a & b);
    }
    void apply_mod_op(ll &a, ll b){
        a = modify_op(a, b);
    }
    void propagate(int x, int l, int r){
        if(r - l == 1) return;
        int m = (l + r) / 2;
        apply_mod_op(op[x * 2 + 1], op[x], 1);
        apply_mod_op(values[x * 2 + 1], op[x], m - l);
        apply_mod_op(op[x * 2 + 2], op[x], 1);
        apply_mod_op(values[x * 2 + 2], op[x], r - m);
        op[x] = no_operation;
    }
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        op.assign(2 * size , 0);
        values.assign(2 * size, 0);
    }
    void modify(int x, int lx, int rx, int l, int r, ll v){
        propagate(x, lx, rx);
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            apply_mod_op(op[x], v);
            apply_mod_op(values[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        modify(x * 2 + 1, lx, m, l, r, v);
        modify(x * 2 + 2, m, rx, l, r, v);
        values[x] = calc_op(values[x * 2 + 1], values[x * 2 + 2]);
    }
    void modify(int l, int r, ll v){
        modify(0, 0, size, l, r, v);
    }
    ll calc(int x, int lx, int rx, int l, int r){
        propagate(x, lx, rx);
        if(lx >= r || rx <= l) return neutral_element;
        if(l <= lx && rx <= r) return values[x];
        int m = (lx + rx) / 2;
        ll res1 = calc(x * 2 + 1, lx, m, l, r);
        ll res2 = calc(x * 2 + 2, m, rx, l, r);
        ll res = calc_op(res1, res2);
        return res;
    }
    ll calc(int l, int r){
        return calc(0, 0, size, l, r);
    }
};