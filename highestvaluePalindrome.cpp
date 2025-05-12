string highestValuePalindrome(string s, int n, int k) {
    vector<int> diff(n, 0);

    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j] && k == 0) return "-1";

        if (s[i] != s[j] && k > 0) {
            s[i] = s[j] = max(s[i], s[j]);
            diff[i] = 1;
            k--;
        }
    }

    if (k == 0) {
        return s;
    }
    else {
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (k > 0 && s[i] != '9') {
                if (diff[i] == 1 || i == j) k--, s[i] = s[j] = '9';
                else if (k > 1) k -= 2, s[i] = s[j] = '9';
            }
        }
    }
    
    return s;
}
