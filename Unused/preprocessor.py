# preprocessor.py

"""
function_replacements = {
	"+": "add",
	"-": "sub",
	"*": "mult",
	"/": "div",
	">": "greater",
	"<": "smaller",
	">=": "greater-equal-to",
	"<=": "smaller-equal-to"
}

def change_operators(scheme_expr):
	if (func_rep := function_replacements.get(scheme_expr[0])) is not None:
		scheme_expr[0] = func_rep

	for index, argument in enumerate(scheme_expr):
		if isinstance(argument, list):
			scheme_expr[index] = change_operators(argument)

	return scheme_expr
"""

def change_operators(scheme_expr, c_expr):
	function = scheme_expr[0]
	if function in "+-*/":
		# scheme_expr = function.join(str(scheme_expr))

	print(scheme_expr)

if __name__ == "__main__":
	scheme_expr = ['func', 5, ['*', '25', '14', ['/', 38, 9, ["<=", 25, 2]]]]
	processed = change_operators(scheme_expr)
	print(processed)