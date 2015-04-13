class Node:
	def __init__(self,data,left=None,right= None):
		self.data = data
		self.left = None
		self.right = None

def printPath(node,key,s):
	if node == None:
		return ''
	if key == node.data:
		return s
	if key < node.data:
		return printPath(node.left,key,s+'1')
	else:
		return printPath(node.right,key,s+'0')
	return '-1'


def main():
	n = Node(10)
	n.left = Node(6)
	n.right = Node(20)
	n.right.right = Node(30)
	n.right.left  = Node(15)
	n.left.left   = Node(4)
	n.left.right = Node(9)
	n.left.left.left = Node(3)
	n.left.left.right = Node(5)
	n.left.right.left = Node(7)
	s = printPath(n,5,'')
	print s


		
if __name__ == '__main__':
	main()




