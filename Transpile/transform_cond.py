# transform_cond.py

# make sure that this will work properly

def make_arg_clause(arg_clause, cond_type, evaluator):
	return f"{cond_type} ({evaluator(arg_clause[0])})\n" + "{return " + evaluator(arg_clause[1]) + "\n}"

# test for 1-cond statement
def handle_cond(scheme_code, evaluator):
	for index, argument in enumerate(scheme_code):
		if argument == "cond":
			cpp_stmt = ""

			argument_set = scheme_code[index + 1:]
			if not len(argument_set) == 1:
				else_clause = argument_set.pop()
			else:
				else_clause = "Nonexistent"

			if len(argument_set) == 1:
				cpp_stmt += make_arg_clause(argument_set[0], "if", evaluator)
			elif len(argument_set) > 1:
				for elif_clause in argument_set[1:]:
					cpp_stmt += make_arg_clause(elif_clause, "else if", evaluator)
			else:
				continue

			if else_clause != "Nonexistent":
				cpp_stmt += make_arg_clause(else_clause, "else", evaluator)

			# add the c++ statement to the scheme code somehow

		elif isinstance(argument, list):
			scheme_code[index] = handle_cond(argument)

		return scheme_code

if __name__ == "__main__":
	code = ['cond', [['>', 'x', 5], ['display', '"bigger"']], [['<', 'x', 5], ['display', '"smaller"']], ['display', '"equal"']]
	handle_cond(code)