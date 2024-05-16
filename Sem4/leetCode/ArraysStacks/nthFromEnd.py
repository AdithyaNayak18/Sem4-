class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack=[]
        reqd=['(','{','[']
        for elem in s:
            if elem in reqd:
                stack.append(elem)
            elif elem== '}' or elem==']' or elem==')':
                if not stack:
                    return False
                chk=stack.pop()
                if (elem == '}' and chk!='{') or \
                   (elem == ']' and chk!= '[') or \
                   (elem == ')' and chk!='('):
                    return False
        return (len(stack)==0)


        
