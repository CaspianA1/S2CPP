# math_double_casting.py

int_funcs = "add", "sub", "mul", "div"
double_funcs = [func + "_d" for func in int_funcs]

def math_double_cast(code, convert_to_doubles = False):
	for index, arg in enumerate(code):
		if index == 0 and arg in ("add_d", "sub_d", "mul_d", "div_d"): # (arg in int_funcs or arg in double_funcs):
			convert_to_doubles = True
			# continue  # should this be there or not? probably not

		elif isinstance(arg, list):
			# print("Handle the list:", arg)
			# convert_to_doubles = False
			# jam it in there before somehow?
			# or make a toDouble function?
			# yeah, a toDouble solution is the answer

			# can this toDouble be made into a (double) declaration?
			caster = "(double)" if convert_to_doubles else "(int)"
			code[index] = [caster, math_double_cast(arg, False)]

		elif convert_to_doubles:
			# variable name
			# other arguments will already have been converted to floats
			if isinstance(arg, str) and not (arg.startswith("\"") and arg.endswith("\"")):
				code[index] = f"(double){arg}"

	return code