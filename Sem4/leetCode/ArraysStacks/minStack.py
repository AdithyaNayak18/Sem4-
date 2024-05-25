class MinStack(object):
    class Node(object):
        def __init__(self, val, minv):
            self.val = val
            self.minv = minv

    def __init__(self):
        self.stack = []
        self.top_node = None

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        if not self.top_node or val < self.top_node.minv:
            newN = self.Node(val, val)
        else:
            newN = self.Node(val, self.top_node.minv)
        self.top_node = newN
        self.stack.append(newN)

    def pop(self):
        """
        :rtype: None
        """
        if self.stack:
            self.stack.pop()
            if self.stack:
                self.top_node = self.stack[-1]
            else:
                self.top_node = None

    def top(self):
        """
        :rtype: int
        """
        if self.top_node is not None:
            return self.top_node.val
        else:
            return None

    def getMin(self):
        """
        :rtype: int
        """
        if self.top_node is not None:
            return self.top_node.minv
        else:
            return None


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
