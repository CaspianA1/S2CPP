# variadic_input_appendage.py

continue_twice = False

def append_input_num(scheme_code):
	global continue_twice
	for index, argument in enumerate(scheme_code):
		print("Argument:", argument)
		if continue_twice:
			continue_twice = False
			continue
		elif argument in ("add", "add_d", "sub", "sub_d", "mul", "mul_d", "div_d"):
			print("Caught a function:", argument)
			scheme_code.insert(index, len(scheme_code[index + 1:]))
			continue_twice = True
		elif isinstance(argument, list):
			scheme_code[index] = append_input_num(argument)
    
	print("Output scheme code:", scheme_code)
	return scheme_code

if __name__ == "__main__":
    func_call = ["add", 5, 2, 3, 4]
    print(append_input_num(func_call))