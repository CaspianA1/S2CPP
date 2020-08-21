# handle_quotations.py

"""
def unparse(code_l: list, code_s: str = ""):
	code_s += "( "
	for index, item in enumerate(code_l):
		if isinstance(item, list):
			print("Found a list:", item)
			print("Code s:", code_s)
			code_s += unparse(item, code_s)[1] + ")"
		else:
			print("Make to string:", item)
			code_s += f"{item} "

	print("Finished iteration:", code_s)
	return code_l, code_s + ")"
"""

def unparse(code_l: list):
	code_s = str(code_l)
	for orig, replacement in {"[": " ( ", "]": " ) ",",": ""}.items():
		code_s = code_s.replace(orig, replacement)
	return code_s


# have unparsed list as string

def handle_quote(scheme_expr):
	for index, argument in enumerate(scheme_expr):
		if argument == "quote":
			scheme_expr[index] = "identity"

			if isinstance((to_quote := scheme_expr[index + 1]), list):
				print("Quote this:", to_quote)
				result = unparse(to_quote)
				print("Result from unparsed:", result)
				scheme_expr[index + 1] = f"\"{unparse(to_quote)}\""  # ["makeCharVector", f"\"{unparse(to_quote)}\""]
			else:
				scheme_expr[index] = str(to_quote)

		elif isinstance(argument, list):
			scheme_expr[index] = handle_quote(argument)

	return scheme_expr


if __name__ == "__main__":
	quote_value = ["quote", "5"]
	quote_list = ["define", "sequence", ["quote", [1, 2, 3, 4, 5]]]

	print(handle_quote(quote_value), handle_quote(quote_list))

	['define', 'sequence', ['[1, 2, 3, 4, 5]']]