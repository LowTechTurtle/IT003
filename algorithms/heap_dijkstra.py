class heap(object):
    def __init__(self):
        self.HEAP = []
    
    def empty(self):
        if self.HEAP == []:
            return True
        else:
            return False
    
    def add(self, element):
        self.HEAP.append(element)
        i = len(self.HEAP)- 1
        element.index = i
        p = i//2 if i % 2 == 1 else i//2-1
        while (self.HEAP[i].key < self.HEAP[p].key):
            self.HEAP[p].index = i
            self.HEAP[i].index = p
            self.HEAP[i], self.HEAP[p] =  self.HEAP[p], self.HEAP[i]
            i = p
            p = i//2 if i % 2 == 1 else i//2-1

    def delete(self, index):
        if ((2*index+1) <= (len(self.HEAP) - 1)):
            #somehow index here is -1
            if (2*index+2 <= len(self.HEAP) - 1) and (self.HEAP[2*index+2].key < self.HEAP[2*index+1].key):
                self.HEAP[index], self.HEAP[2*index+2] = self.HEAP[2*index+2], self.HEAP[index]
                self.HEAP[index].index = 2*index+2 
                self.HEAP[2*index+2].index = index
                return self.delete(2*index+2)
            else:
                self.HEAP[index], self.HEAP[2*index+1] = self.HEAP[2*index+1], self.HEAP[index]
                self.HEAP[index].index = 2*index+1
                self.HEAP[2*index+1].index = index
                return self.delete(2*index+1)
        else:
            if (index == len(self.HEAP) - 1):
                node = self.HEAP.pop()
                return node
            self.HEAP[index].index, self.HEAP[len(self.HEAP)-1].index = self.HEAP[len(self.HEAP)-1].index, self.HEAP[index].index
            self.HEAP[index], self.HEAP[len(self.HEAP)-1] = self.HEAP[len(self.HEAP)-1], self.HEAP[index]
            node = self.HEAP.pop()
            p = index//2 if index % 2 == 1 else index//2-1
            while (self.HEAP[index].key < self.HEAP[p].key):
                self.HEAP[p].index = index
                self.HEAP[index].index = p
                self.HEAP[index], self.HEAP[p] =  self.HEAP[p], self.HEAP[index]
                index = p
                p = index//2 if index % 2 == 1 else index//2-1
        return node

    def extract_min(self):
        self.HEAP[len(self.HEAP) - 1], self.HEAP[0] = self.HEAP[0], self.HEAP[len(self.HEAP) - 1]
        self.HEAP[0].index = 0
        node = self.HEAP.pop()
        index = 0
        while 2*index+1 <= len(self.HEAP) - 1:
            if (2*index+2 <= len(self.HEAP) - 1) and (self.HEAP[2*index+2].key < self.HEAP[2*index+1].key):
                self.HEAP[index].index = 2*index+2 
                self.HEAP[2*index+2].index = index
                self.HEAP[index], self.HEAP[2*index+2] = self.HEAP[2*index+2], self.HEAP[index]
                index = 2*index+2
#                self.delete(2*index+2)
            else:
                self.HEAP[index].index = 2*index+1
                self.HEAP[2*index+1].index = index
                self.HEAP[index], self.HEAP[2*index+1] = self.HEAP[2*index+1], self.HEAP[index]
                index = 2*index+1
#                self.delete(2*index+1)
#        self.delete(index)
        return node