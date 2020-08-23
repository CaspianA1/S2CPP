# make_pairs.py

def make_pairs(elem):
	car, cdr = elem[0], elem[1:]
	return [car] if not cdr else [car, make_pairs(cdr)]

"""
def parse(code_as_str):
	car = code_as_str.pop(0)
	
	if car == "(":
		ast = []
		while code_as_str[0] != ")":
			ast.append(parse(code_as_str))

	else:
		return str(code_as_str)
"""

if __name__ == "__main__":
	# print(make_pairs([1, 2, 3, 4, 5]))
	# raw_code = list(" ( 1 2 3 4 5 ) ")
	# print(parse(raw_code))

	# [1, [2, 3, 4, 5]]