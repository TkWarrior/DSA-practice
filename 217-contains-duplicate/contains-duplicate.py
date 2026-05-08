class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        freq = {}

        for num in nums:
            freq[num] = freq.get(num ,0)+1

        print(freq)
        
        for k,v in freq.items():
            if(v>1):
                return True
        
        return False