# transform_expression.py

common_ends = {"+": "add", "-": "sub", "*": "mul", "/": "div"}

def function_is_present(function, scheme_expr):
	for argument in scheme_expr:
		if isinstance(argument, list):
			return function_is_present(argument, scheme_expr)
		elif argument == function:
			return True

def make_c_expr(scheme_expr):
	# if not isinstance(scheme_expr[0], str):
		# return scheme_expr  # for lists

	c_expr = scheme_expr.pop(0) + "("

	cast_to_floats = False

	for index, argument in enumerate(scheme_expr):
		if isinstance(argument, list):

			c_expr += make_c_expr(argument)
			if index != len(scheme_expr) - 1:
				c_expr += ", "
			# print("C expression:", c_expr)
		else:
			if isinstance(argument, int) and cast_to_floats:
				scheme_expr[index] = float(argument)
			elif isinstance(argument, float):
				cast_to_floats = True
			c_expr += str(scheme_expr[index])
			if index != len(scheme_expr) - 1:
				c_expr += ", "

	return c_expr + ")"

def make_float_funcs(scheme_expr):
	for index, argument in enumerate(scheme_expr):
		if (isinstance(argument, float) and scheme_expr[0] in common_ends.keys()) or scheme_expr[0] == "/":
			return True
		elif isinstance(argument, list):
			return make_float_funcs(argument)

def modify_operators(scheme_expr, make_float_operators):
	for index, argument in enumerate(scheme_expr):
		if isinstance(argument, list):
			scheme_expr[index] = modify_operators(argument, make_float_operators)

		elif index == 0 and (function := scheme_expr[0]) in common_ends.keys():
			scheme_expr[0] = common_ends[function]
			if make_float_operators or function == "/":
				scheme_expr[0] += "_d"

	return scheme_expr

if __name__ == "__main__":
	# scheme_expr = ['define', 'f', ['lambda', ['x', 'y'], ['+', 'x', 'y', 1]]]
	# scheme_expr = ['define', 'x', 5]
	# scheme_expr = ['func', 5, ['*', 25, 14, ['/', 382, 90]]]
	scheme_expr = ['define', 'x', 5]
	scheme_expr = modify_operators(scheme_expr, make_float_funcs(scheme_expr))
	c_expr = make_c_expr(scheme_expr)
	print(c_expr)
