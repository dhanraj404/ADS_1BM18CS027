class Node:
    def __init__(self, data):
        self.data = data
        self.next = None



# to Push Element

def push(head_ref, data):
    new_node = Node(data)
    new_node.next = head_ref
    head_ref = new_node
    return head_ref


# to Print a List

def Print_list(node):
    while(node != None):
        print(node.data, end=', ')
        node = node.next
    print()


# rev

def ReverseK(head, k):
    current = head
    next = None
    prev = None
    count = 0

    # rev first k nodes 

    while (current != None and count < k):
        next = current.next
        current.next = prev
        prev = current
        current = next
        count += 1
        Print_list(current)
    if(head!=None):
        head.next = current
    
    count = 0

    while (count < k-1 and current != None):
        current = current.next
    
    if (current!=None):
        current.next =  ReverseK(current.next, k)
    
    return prev


if __name__ == "__main__":
    head = None

    for i in reversed(input().split()):
        head = push(head, i)
    
    k  = int(input("Enter K Value :"))

    Print_list(head)
    head = ReverseK(head, k)
    Print_list(head)
