class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #Create a hashmap that will keep track of every value we iterate through
        dictionary = {}
        
        #Iterate through hashmap
        for i,j in enumerate(nums):
            
            #Get the difference needed to reach target
            difference = target - j
            
            #If the difference exist, return back the index tied with the number needed
            if difference in dictionary:
                
                #Return back a list with both indices
                return [dictionary[difference], i]
            
            #If the difference isn't in the dictionary add the current value into it and loop again
            dictionary[j] = i
