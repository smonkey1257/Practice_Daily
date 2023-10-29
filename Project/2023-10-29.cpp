// 1768. ����ϲ��ַ���
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        string ret;
        ret.reserve(len1 + len2);
//reserve�������Ǹ���vector��������capacity����ʹvector���ٿ�������n��Ԫ�ء�
//���n����vector��ǰ��������reserve���vector�������ݡ���������¶��������·���vector�Ĵ洢�ռ�

        int i = 0;
        while(i < len1 || i < len2)
        {
            if(i < len1)
                ret += word1[i];    // += �ַ���ƴ��

            if(i < len2)
                ret += word2[i];

            ++i;
        }
        return ret;
    }
};



// 389. �Ҳ�ͬ
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



// 28. �ҳ��ַ����е�һ��ƥ������±�
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



// 242. ��Ч����ĸ��λ��
class Solution {
public:
    bool isAnagram(string s, string t) {
        // ����ַ������Ȳ���ͬ��������λ��
        if(s.length() != t.length())
        {
            return false;   
        }
        // ʹ��hash��
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



// 459. �ظ������ַ���
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.length();
    }
};
