class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack=[]
        dirs=path.split("/")
        for dir in dirs:
            if dir=="." or not dir:
                continue
            if dir== "..":
                if stack:
                    stack.pop()
            else: 
                stack.append(dir)
        return "/"+"/".join(stack) 
