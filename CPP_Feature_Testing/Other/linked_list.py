# linked_list.py

# didn't do anything here
class Node:
	def __init__(self, head, tail):
		self.head = head
		self.tail = tail


def read_from_tokens(tokens: list) -> dict:
	if len(tokens) == 0: return

	current_token = tokens.pop(0)
	if current_token == "(":
		sub_expr = []

		while tokens[0] != ")":
			sub_expr.append(read_from_tokens(tokens))

		tokens.pop(0)  # remove last ")"
		return sub_expr

	elif current_token == ")": raise SyntaxError("Unexpected \")\"")

	else: return atom(current_token)


def atom(token: str):
	try:
		return int(token)
	except ValueError:
		try:
			return float(token)
		except ValueError:
			return str(token)

if __name__ == "__main__":
	# code = " ( 1 2 3  ( 4 5 )  )"
	code = "(1 2 3(4 5))"
