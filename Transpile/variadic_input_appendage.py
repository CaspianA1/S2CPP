# variadic_input_appendage.py

continue_twice = False

def append_input_num(scheme_code):
	"""
	this is called before function names are changed,
	so math names must be the traditional operator signs
	"""
	global continue_twice
	for index, argument in enumerate(scheme_code):
		if continue_twice:
			continue_twice = False
			continue
		elif isinstance(argument, list):
			scheme_code[index] = append_input_num(argument)
		elif str(argument) in "+-*/":
			scheme_code.insert(index + 1, len(scheme_code[index + 1:]))
			continue_twice = True
			continue

	print("Output scheme code:", scheme_code)
	return scheme_code

if __name__ == "__main__":
    func_call = ["add", 5, 2, 3, 4]
    print(append_input_num(func_call))