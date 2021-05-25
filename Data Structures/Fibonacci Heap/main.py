import math
#source: https://www.geeksforgeeks.org/fibonacci-heap-set-1-introduction/
# Fibonacci heap are mainly called so because Fibonacci numbers are used in the running time analysis.
# Also, every node in Fibonacci Heap has degree at most O(log n) and the size of a subtree rooted in a node of degree k
# is at least Fk+2, where Fk is the kth Fibonacci number.

class FibonacciHeap:
    # internal node class
    class Node:
        def __init__(self, key):
            self.key = key
            self.parent = self.child = self.left = self.right = None
            self.degree = 0


    # function to iterate through a doubly linked list
    def iterate(self, head):
        lst = [head]
        node = head.right

        while node != head:
            lst.append(node)
            node = node.right
        return lst

    # pointer to the head and maximum node in the root list
    root_list, max_node = None, None

    # maintain total node count in full fibonacci heap
    total_nodes = 0

    # return max node in O(1) time
    def find_max(self):
        return self.max_node

    # extract (delete) the max node from the heap in O(log n) time
    def extract_max(self):
        z = self.max_node
        if z is not None:
            if z.child is not None:
                # attach child nodes to root list
                for child in list(self.iterate(z.child)):
                    self.merge_with_root_list(child)
                    child.parent = None
            self.remove_from_root_list(z)
            # set new max node in heap
            if z == z.right:                            ##it was the last node in the heap
                self.max_node = self.root_list = None
            else:                                       ##at its right it s the next max
                self.max_node = z.right
                self.consolidate()
            self.total_nodes -= 1
        return z

    # insert new node into the unordered root list in O(1) time
    # returns the node so that it can be used for decrease_key later
    def insert(self, key):
        n = self.Node(key)
        n.left = n.right = n
        self.merge_with_root_list(n)
        if self.max_node is None or n.key > self.max_node.key:
            self.max_node = n
        self.total_nodes += 1
        return n

    # merge two fibonacci heaps in O(1) time by concatenating the root lists
    # the root of the new root list becomes equal to the first list and the second
    # list is simply appended to the end (then the proper max node is determined)
    def merge(self, h2):
        H = FibonacciHeap()
        H.root_list, H.max_node = self.root_list, self.max_node
        # fix pointers when merging the two heaps
        last = h2.root_list.left
        h2.root_list.left = H.root_list.left
        H.root_list.left.right = h2.root_list
        H.root_list.left = last
        H.root_list.left.right = H.root_list
        # update max node if needed
        if h2.max_node.key > H.max_node.key:
            H.max_node = h2.max_node
        # update total nodes
        H.total_nodes = self.total_nodes + h2.total_nodes
        return H

    # combine root nodes of equal degree to consolidate the heap
    # by creating a list of unordered binomial trees
    def consolidate(self):
        A = [None] * int(math.log(self.total_nodes) * 2)                ##Each node in the heap has degree at most O(logn) : https://brilliant.org/wiki/fibonacci-heap/
        for x in list(self.iterate(self.root_list)):
            d = x.degree
            while A[d] != None:
                y = A[d]
                if x.key < y.key:
                    temp = x
                    x, y = y, temp
                self.heap_link(y, x)                                    ##x will be parent of y
                A[d] = None
                d += 1
            A[d] = x
        # find new max node
        for i in range(0, len(A)):
            if A[i] is not None:
                if A[i].key > self.max_node.key:
                    self.max_node = A[i]

    # actual linking of one node to another in the root list
    # while also updating the child linked list
    def heap_link(self, y, x):
        self.remove_from_root_list(y)
        y.left = y.right = y
        self.merge_with_child_list(x, y)
        x.degree += 1
        y.parent = x


    # merge a node with the doubly linked root list
    def merge_with_root_list(self, node):
        if self.root_list is None:                          ##if it s the firs node in the root_list
            self.root_list = node
        else:
            node.right = self.root_list.right               ##insert it at the right of the root_list
            node.left = self.root_list
            self.root_list.right.left = node
            self.root_list.right = node

    # merge a node with the doubly linked child list of a root node
    def merge_with_child_list(self, parent, node):
        if parent.child is None:                        ##if it s the first child
            parent.child = node
        else:
            node.right = parent.child.right
            node.left = parent.child
            parent.child.right.left = node
            parent.child.right = node

    # remove a node from the doubly linked root list
    def remove_from_root_list(self, node):
        if node == self.root_list:                  ##if it was the only node in the root list
            self.root_list = node.right
        node.left.right = node.right
        node.right.left = node.left

    # remove a node from the doubly linked child list
    def remove_from_child_list(self, parent, node):
        if parent.child == parent.child.right:              ##if it was the only child
            parent.child = None
        elif parent.child == node:
            parent.child = node.right
            node.right.parent = parent
        node.left.right = node.right
        node.right.left = node.left


class Main:
    def __init__(self, input_file="mergeheap.in", output_file="mergeheap.out"):
        self.input_file = input_file
        self.output_file = output_file
        self.output = None
        self.heaps = {}                         ##dictionary : heap_number: actual heap

    def convert_array_to_int(self, arr):
        arr = arr.strip("\n ").split(" ")
        return list(map(lambda x: int(x), arr))

    def write_to_file(self, text):
        if not self.output:
            self.output = open(self.output_file, "a")

        self.output.write(str(text) + "\n")

    def start(self):
        file = open(self.input_file)
        first_line = file.readline()

        [N, Q] = self.convert_array_to_int(first_line)

        for i in range(Q):
            line = file.readline()
            args = self.convert_array_to_int(line)

            operation = args[0]

            if (operation == 1):
                heap_num = args[1]
                elem = args[2]

                if (not heap_num in self.heaps):
                    self.heaps[heap_num] = FibonacciHeap()          ##he constructor if the heap doesn t exist yet
                    self.heaps[heap_num].insert(elem)
                else:
                    self.heaps[heap_num].insert(elem)

                # print(f"HEAP: {heap_num}", f"elem: {elem}")

            elif operation == 2:
                heap_num = args[1]

                maximum = self.heaps[heap_num].extract_max()
                self.write_to_file(maximum.key)
            else:
                heap1 = args[1]
                heap2 = args[2]

                self.heaps[heap1] = self.heaps[heap1].merge(self.heaps[heap2])              ##just concatenate the root_lists
                self.heaps.pop(heap2)
        file.close()


main = Main()
main.start()