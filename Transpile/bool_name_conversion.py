# bool_name_conversion.py

def convert_bool_names(code):
	for index, argument in enumerate(code):
		if isinstance(argument, list):
			code[index] = convert_bool_names(argument)
		elif argument == "#t":
			code[index] = "true"
		elif argument == "#f":
			code[index] = "false"

	return code