class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        if(len(s)!=len(t)):
            return False

        freq1 = {}
        freq2 = {}

        for s1 in s:
            freq1[s1] = freq1.get(s1,0) + 1
        
        for s2 in t:
            freq2[s2] = freq2.get(s2,0) + 1
        
        if(freq1 == freq2):
             return True

        return False