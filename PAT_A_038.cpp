#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct num {
	string original;
};


int comp2(num n1, num n2) {
	return n1.original + n2.original < n2.original + n1.original;
}

int main()
{
	int n;
	cin >> n;
	vector<num> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i].original;
	}
	sort(nums.begin(), nums.end(), comp2);
	string ans = "";
	for (int i = 0; i < nums.size() ; i++) {
		ans += nums[i].original;
	}
	bool isprit = false;
	int i = 0;
	for (i; i < ans.size(); i++) {
		if (ans[i] != '0') break;
	}
	if (i == ans.size()) {
		cout << 0;
		return 0;
	}
	ans = ans.substr(i);
	cout << ans;
    return 0;
}
