# evaluate.py

# assumed that procedure has already been identified


"""
(define f (lambda (x (+ x 1))))

int f(x) {
	return x + 1;
}

"""

function_log = {"define": None}

import interpred_evaluate


def gather_procedure_data(scheme_proc):
	""" returns name, paramaters, output type, body"""

	name, parameters, body = scheme_proc[1], scheme_proc[2][1], scheme_proc[2][2]

	# hm, get param types as well
	return_type = None
	declare_func = interpred_evaluate.evaluate(scheme_proc)
	for test_type in ("five", 5, 5.00):
		try:
			declare_func = interpred_evaluate.evaluate([name, test_type])
			return_type = type(test_type)
		except:
			continue

	if return_type is None:
		raise TypeError(f"Type error with gathering procedure {name}'s data")
		
	return name, parameters, return_type, body

def get_type_name(var):
	raw_name = str(type(var))
	return raw_name[raw_name.find("'") + 1:-2]

def make_c_function(name, inputs_, return_type, body):
	type_mapping = {}
	for input_ in inputs_:
		type_mapping[str(input_)] = get_type_name(input_)

	parameters = ""
	for var, type_ in type_mapping.items():
		parameters += f"{type_} {var}, "

	parameters = parameters.rstrip(", ")
	print(parameters)

	function = f"{return_type} {name}({parameters})" + "{" + body + ";}"

	print(function)


def detect_expression_type(expression):
	try:  # check for procedure def
		lambda_indicator = expression[2][0]
		function_log[(expression[1])] = expression
		print("Procedure def")
	finally:
		print("Function call")
		procedure_name = expression[0]
		function_body = function_log[procedure_name]
		arguments = expression[1:]

		argument_types = list(map(lambda t: type(t), arguments))
		procedure_info = gather_procedure_data(expression)
		c_function = make_c_function(procedure_info)



if __name__ == "__main__":
	# return_type, name, inputs_, body = gather_procedure_data(['define', 'f', ['lambda', ['x', 'y'], ['+', 'x', 'y', 1]]])
	
	detect_expression_type(['define', 'f', ['lambda', ['x', 'y'], ['+', 'x', 'y', 1]]])
	detect_expression_type(["f", "5"])