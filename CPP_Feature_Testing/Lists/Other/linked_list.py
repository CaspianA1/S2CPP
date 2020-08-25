class Pair:
	head = None
	tail = None



def makePairs(tokens: list):
	pair = Pair()

	head = tokens.pop(0)

	if head == "(":
		pass