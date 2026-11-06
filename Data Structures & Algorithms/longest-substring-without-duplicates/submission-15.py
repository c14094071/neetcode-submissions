class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if(len(s)==0): return 0
        if(len(s)==1): return 1
        l = 0
        r = 1
        res = 0
        c_list = [-1]*300
        c_list[ord(s[l])] = 0
        while(r<len(s)):
            asc = ord(s[r])
            if(c_list[asc] != -1): 
                res = max(res,r-l) 
                while(l < c_list[asc]+1):
                    c_list[ord(s[l])]=-1
                    l+=1
                c_list[asc] = r
            else:
                 
                c_list[asc] = r # store index
            r+=1
        res = max(res,r-l) 
        return res
