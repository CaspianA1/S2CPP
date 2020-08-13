# recognize_lambdas.py

"""
# make this work
# test for one little example at a time
def handle_lambdas(scheme_code, body_evaluator):
	return scheme_code  # this is tricky
	for index, argument in enumerate(scheme_code):
		if argument == "lambda":
			print("Scheme code:", scheme_code)
			scheme_code[index] = "identity"

			arguments = scheme_code[index + 1]
			body = scheme_code[index + 2]

			print("Body:", body)

			cpp_equiv = "[]("
			for index, argument in enumerate(arguments):
				cpp_equiv += f"auto {argument}"
				if index == len(arguments) - 1:
					cpp_equiv += ") {return "
				else:
					cpp_equiv += ", "

				cpp_equiv += body_evaluator(body) + ";}"

			scheme_code[index + 1] = cpp_equiv
			print("Scheme code at end:", scheme_code)
			print("Index:", index)
			del scheme_code[-1]  # may be bad later (?)


			#####
			print("Args and body:", arguments, body)

			cpp_equiv = "[]("  # make identity a separate token
			for index, argument in enumerate(arguments):
				cpp_equiv += f"auto {argument}"
				if index == len(arguments) - 1: cpp_equiv += ") {return "
				else: cpp_equiv += ", "
			cpp_equiv += body_evaluator(body) + ";}"

			print("Cpp equiv:", cpp_equiv)

			# del scheme_code[index + 2]
			scheme_code[index + 1] = cpp_equiv

			print("Scheme code:", scheme_code)
			###########

		elif isinstance(argument, list):
			scheme_code[index] = handle_lambdas(argument, body_evaluator)

	print("Scheme code:", scheme_code)
	return scheme_code

if __name__ == "__main__":
	anonymous = ['lambda', ['x'], ['+', 'x', 1]]
	# [](auto x) {return x + 4;};
	cpp_anonymous = handle_lambdas(anonymous)
	print(cpp_anonymous)
"""