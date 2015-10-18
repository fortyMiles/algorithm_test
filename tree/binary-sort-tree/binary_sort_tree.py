'''
Implements binary search tree in Python.
Author: Minchiuan Gao
Date: 2015-Oct-18
'''


class Queue:
    def __init__(self):
        self.list = []
        self.begin = 0
        self.end = 0

    def append(self, elements):
        self.list.append(elements)
        print "append %d" % elements.value
        self.end += 1

    def pop(self):
        result = self.list[self.begin]
        print "pop %d" % result.value
        self.begin += 1
        return result

    def is_empty(self):
        return self.begin >= self.end


class Node:
    def __init__(self, value):
        self.value = value
        self.left_slide = None
        self.right_slide = None
        self.level = 0

    def insert_one(self, node):
        if node.value < self.value:
            if self.left_slide:
                self.left_slide.insert_one(node)
            else:
                self.left_slide = node
                print "self %d 's left to be %d" % (self.value, node.value)
        else:
            if self.right_slide:
                self.right_slide.insert_one(node)
            else:
                self.right_slide = node
                print "self %d 's right to be %d" % (self.value, node.value)


def traver_tree(node):
    queue = Queue()
    queue.append(node)
    last_level = node.level
    while not queue.is_empty():
        node = queue.pop()
        if last_level != node.level:
            print('')
            last_level = node.level

        print(node.value),
        if node.left_slide:
            node.left_slide.level = node.level + 1
            queue.append(node.left_slide)
        if node.right_slide:
            node.right_slide.level = node.level + 1
            queue.append(node.right_slide)


def tarvese_tree_mid(node):
    if node is None:
        return

    tarvese_tree_mid(node.left_slide)
    print(node.value)
    tarvese_tree_mid(node.right_slide)

if __name__ == '__main__':
    data = [12, 43, 54, 65, 76, 34, 1]
    node = Node(value=30)
    for e in data:
        new_node = Node(value=e)
        node.insert_one(new_node)

    traver_tree(node)
    tarvese_tree_mid(node)
