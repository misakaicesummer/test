//牛牛有一些字母卡片, 每张卡片上都有一个小写字母, 所有卡片组成一个字符串s。牛牛一直认为回文这种性质十分优雅, 于是牛牛希望用这些卡片拼凑出一些回文串, 但是有以下要求:
//1、每张卡片只能使用一次
//2、要求构成的回文串的数量最少
//牛牛想知道用这些字母卡片, 最少能拼凑出多少个回文串。
//例如 : s = "abbaa", 输出1, 因为最少可以拼凑出"ababa"这一个回文串
//	s = "abc", 输出3, 因为最少只能拼凑出"a", "b", "c"这三个回文串
//
//	输入描述 :
//输入包括一行, 一个字符串s, 字符串s长度length(1 ≤ length ≤ 1000).
//s中每个字符都是小写字母
//
//分析:
//统计每种字符的数量, 然后提取一个奇数个数的字符放在第一个回文串中心, 对于每个剩下的字符,
//两个相同字符放在回文串左右, 直接用每种字符的数量对2取余即可, 如果还有剩下的单一字符都只能单独为一个回文串。

#include <bits/stdc++.h>

using namespace std;

string s;
int main() {
	cin >> s;
	vector<int> t(26);
	for (char c : s) {
		t[c - 'a']++;
	}
	int ans = 1;
	for (int i = 0; i < 26; i++) {
		if (t[i] & 1) {
			t[i]--;
			break;
		}
	}
	for (int i = 0; i < 26; i++) {
		t[i] %= 2;
	}
	for (int i = 0; i < 26; i++) {
		if (t[i]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}