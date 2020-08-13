def handle_lambda(code, evaluator):
	for index, code_part in enumerate(code):
		if code_part == "lambda":  # +1 is args, +2 is body
			code[index] = "identity"
			arguments = code[index + 1]
			body = code[index + 2]

			cpp_equivalent = "[]("

			for ind, arg in enumerate(arguments):
				cpp_equivalent += f"auto {arg}"
				if ind == len(arguments) - 1:
					eval_body = evaluator(body)
					cpp_equivalent += ") {return " + eval_body + "};"
				else:
					cpp_equivalent += ", "

			code[index + 1] = cpp_equivalent
			del code[index + 2]

		elif isinstance(code_part, list):
			code[index] = handle_lambda(code_part, evaluator)

	return code