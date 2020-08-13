# type_inference.py

sym_table = {"x": 5}

type_mapping = {int: "int", float: "float", "str": "char*"}

int_procs = "add", "sub", "mul"
float_procs = "add_d", "sub_d", "mul_d", "div_d"

def get_type(token):
	if token[0] == "\"" and token.endswith("\""):
		return token[1:-1]
	try: return int(token)
	except ValueError:
		try: return float(token)
		except ValueError: return str(token)  # a function


def get_type_name(var):
	ugly_name = str(type(var))
	return ugly_name[ugly_name.find("'"):len(ugly_name) - 1].strip("'")


# call after assigning special math functions
# scheme_code here is function body
def detect_return_type(scheme_code: list) -> str:
	for index, token in enumerate(scheme_code):
		if isinstance(token, list):
			return detect_return_type(token)

		if index == 0:
			if token in int_procs:
				return "int"  # int or float?
			elif token in float_procs:
				return "float"
			else:
				continue 

		if token in sym_table: 
			return get_type_name(sym_table[token])

		elif token in ("#t", "#f"):
			return "bool"

		var_type = get_type_name(token)

		if var_type in ("int", "float"):
			return var_type

		return "char*"

if __name__ == "__main__":
	expression = ["concat", "\"bob\"", "\"bob\""]# ['define', 'f', ['lambda', ['x'], ['add', 'x', 1]]]
	return_type = detect_return_type(expression)
	print(return_type)