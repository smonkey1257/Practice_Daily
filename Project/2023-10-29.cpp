// 1768. 交替合并字符串
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        string ret;
        ret.reserve(len1 + len2);
//reserve的作用是更改vector的容量（capacity），使vector至少可以容纳n个元素。
//如果n大于vector当前的容量，reserve会对vector进行扩容。其他情况下都不会重新分配vector的存储空间

        int i = 0;
        while(i < len1 || i < len2)
        {
            if(i < len1)
                ret += word1[i];    // += 字符串拼接

            if(i < len2)
                ret += word2[i];

            ++i;
        }
        return ret;
    }
};



// 389. 找不同
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ret = 0;
        for(auto i : s) {
            ret ^= i;
        }
        for(auto i : t) {
            ret ^= i;
        }
        return ret;
    }
};



// 28. 找出字符串中第一个匹配项的下标
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; i++) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
};



// 242. 有效的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 如果字符串长度不相同，不是异位词
        if(s.length() != t.length())
        {
            return false;   
        }
        // 使用hash法
        vector<int> hash(26, 0);
        for(auto& str : s)
        {
            ++hash[str - 'a'];
        }
        
        for(auto& str : t)
        {
            --hash[str - 'a'];
            if(hash[str - 'a'] < 0)
                return false;
        }
        return true;
    }
};



// 459. 重复的子字符串
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.length();
    }
};
