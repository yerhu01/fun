'''
SERIALIZE:
BFS

DESERIALIZE:
BFS
'''
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return 'null'

        ret = []
        q = deque([root])
        while q:
            node = q.popleft()
            if not node:
                ret.append('null')
            else:
                ret.append(str(node.val))
                q.append(node.left)
                q.append(node.right)
        return ','.join(ret)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data or data.startswith('null'):
            return None

        nodes = data.split(',')
        root = TreeNode(int(nodes[0]))

        q = deque([root])
        i = 1
        while q:
            node = q.popleft()
            if nodes[i] != 'null':
                node.left = TreeNode(int(nodes[i]))
                q.append(node.left)
            if nodes[i+1] != 'null':
                node.right = TreeNode(int(nodes[i+1]))
                q.append(node.right)
            i += 2
        return root

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
