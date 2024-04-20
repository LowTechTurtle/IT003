class Node(object):
    def __init__(self, key, value, parent = None):
        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.parent = parent


class BSTree(object):
    def __init__(self, root_key, root_value):
        self.root = Node(root_key, root_value)
    
    def isempty(self):
        return self.root == None
    
    def _search(self, key, node):
        if key == node.key:
            return node.value
        elif key < node.key:
            return self._search(key, node.left)
        else:
            return self._search(key, node.right)
    
    def _search(self, key):
        return _search(key, self.root)
    
    def _insert(self, key, value, node):
        if key == node.key:
            node.value = value
        elif key < node.key:
            if node.left == None:
                new_node = Node(key, value, parent = node)
                node.left = new_node
            else:
                self._insert(key, value, node.left)
        elif key > node.key:
            if node.right == None:
                new_node = Node(key, value, parent = node)
                node.right = new_node
            else:
                self._insert(key, value, node.right)
    
    def insert(self, key, value):
        self._insert(key, value, self.root)
    
    def _count_a_b(self, a, b, node, count):
        if node.key < a:
            if node.right == None:
                return count
            else:
                return self._count_a_b(a, b, node.right, count)
        elif a <= node.key and node.key <= b:
            count += 1
            if node.left == None and node.right == None:
                return count
            elif node.left == None and node.right != None:
                return self._count_a_b(a, b, node.right, count) 
            elif node.right == None and node.left != None:
                return self._count_a_b(a, b, node.left, count) 
            else:
                c = self._count_a_b(a, b, node.left, count)
                return self._count_a_b(a, b, node.right, c)
        else:
            if node.left == None:
                return count
            else:
                return self._count_a_b(a, b, node.left, count)

    def count_a_b(self, a, b):
        return self._count_a_b(a, b, self.root, 0)
    
    def _print_tree(self, node, count):
        indent = "    "*count
        print(indent, end='')
        print(node.value)
        if node.left:
            self._print_tree(node.left, count+1)
        if node.right:
            self._print_tree(node.right, count+1)

    def print_tree(self):
        self._print_tree(self.root, 0)

t = BSTree(2, 3)
t.insert(1, 5)
t.insert(3, 4)
t.insert(8, 10)
print(t.count_a_b(2, 7))
t.print_tree()