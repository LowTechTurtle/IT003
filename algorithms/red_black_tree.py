class Node(object):
    def __init__(self, color, key, value, parent, left = None, right = None):
        self.color = color #0 is black and 1 is red
        self.key = key
        self.value = value
        self.parent = parent
        self.left = left
        self.right = right
    
    def _rotation(self):
        pass

class Red_Black_Tree(object):
    def __init__(self, key, value):
        self.root = Node(0, key, value, None)
    
    def _get(self, node, key):
        if key == node.key:
            return node.value
        if node.left != None and key < node.key:
            return self._get(node.left, key)
        elif node.right != None and key > node.key:
            return self._get(node.right, key)
        else:
            return None

    def get(self, key):
        return self._get(self.root, key)

    def _uncle(self, node):
        if p.parent.parent != None:
            return node.parent.parent.right if node.parent.parent.left == node.parent else node.parent.parent.left
        return None

    def set(self, key, value):
        p = self.root
        while True:
            if key < p:
                if p.left == None:
                    break
                else:
                    p = p.left
            else:
                if p.right == None:
                    break
                else:
                    p = p.right

        node = Node(red, key, value, p)

        if p.color == 1:
            u = None
            if p.parent.left == p:
                uncle = p.parent.right
                u = 1
            else:
                uncle = p.parent.left
                u = 0
            
            if uncle == None:
                p.parent.color = 1
                p.color = 0
                self.recolor(p.parent, p.parent.parent, self._uncle(p.parent))

            if uncle.color == 1:
                self.recolor(node, p, uncle)
            else:
                if u == 1 and node == p.left:
                    self.right_rotation(node, p, uncle)
                elif u == 1 and node == p.right:
                    node.parent = p.parent
                    p.parent = node
                    node.left = p
                    p.right = None
                    self.right_rotation(node, p, uncle)
                if u == 0 and node == p.right:
                    self.left_rotation(node, p, uncle)
                elif u == 0 and node == p.left:
                    node.parent = p.parent
                    p.parent = node
                    node.right = p
                    p.left = None
                    self.left_rotation(node, p, uncle)

    def recolor(self, node, p, uncle):
        if p.parent == self.root:
            p.color = 0
            uncle.color = 0
        else:
            p.color = 0
            uncle.color = 0
            p.parent.color = 1
            self.recolor(p.parent, p.parent.parent, self._uncle(p.parent))


    def delete(self, key, value):
        pass