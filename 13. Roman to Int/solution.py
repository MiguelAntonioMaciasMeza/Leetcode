class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        romanDict = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L" : 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        total = 0
        i = 0
        flag = 0

        for i in range(len(s)):

            #Make sure we dont go out of bounds for subtraction condition
            if i + 1 < len(s):

                #Check if letter to left is smaller than right
                if romanDict[s[i]] < romanDict[s[i+1]] and flag == 0:
                    #If so subtract smaller number from bigger number and add into total
                    total += romanDict[s[i+1]] - romanDict[s[i]]
                    #Alert a flag to skip the next index 
                    flag = 1
                
                #Flag is raised, reset flag and skip current index
                elif flag == 1:
                    flag = 0
                    continue
                
                #If no flag and left is larger than right, just add to total
                else: 
                    total += romanDict[s[i]]
            
            #If last element and flag is not lit, simply add roman value
            elif flag == 0: 
                total += romanDict[s[i]]
            

        
        return total