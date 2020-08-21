
"""
def convert_oper_float(scheme_expr):
	for index, argument in enumerate(scheme_expr):
		if isinstance(argument, list):
			return convert_oper_float(argument)
		elif isinstance(argument, float):
			print("Argument is a float")
			print("Function:", scheme_expr[0])
			if scheme_expr[0] in common_ends.keys():
				return True

def change_operator_funcs(scheme_expr, ignore_1st_stmt = False):
	for index, argument in enumerate(scheme_expr):
		if index == 0 and argument in common_ends.keys():
			scheme_expr[0] = common_ends[argument]
			if ignore_1st_stmt:
				print("Ignoring 1st statement")
				scheme_expr[0] += "_d"
		elif isinstance(argument, list):
			scheme_expr[index] = change_operator_funcs(argument)

	if convert_oper_float(scheme_expr):
		print("Conv to float")
		return change_operator_funcs(scheme_expr, True)

	return scheme_expr

	######
	if ignore_1st_stmt:
		for index, argument in enumerate(scheme_expr):
			if index == 0 and argument in common_ends.keys():
					scheme_expr[0] = common_ends[argument] + "_d"
			elif isinstance(argument, list):
				scheme_expr[index] = change_operator_funcs(argument)
	else:
		for index, argument in enumerate(scheme_expr):
			if index == 0 and argument in common_ends.keys():
				scheme
	######

	# return change_operator_funcs(scheme_expr, convert_oper_float(scheme_expr))
"""

###################

"""
code_stack = []

def print_code():
	for row in code_stack:
		print(row)

function_registry = {}

# untyped for now
class CFunction:
	def __init__(self, name, args, body):
		self.name = name
		self.args = args
		self.body = body
		self.type_mapping = {}
		self.return_type = None

	def set_param_types(self, *params):
		self.param_types = list(dict(zip(list(map(lambda v: type(v), params)), self.args)))

	def set_return_type(self, return_type: type):
		pass

	def __str__(self):
		return "%s %s (%s) {\nreturn %s;\n}" % (self.return_type, self.name,
			", ".join([arg for arg in self.args]).rstrip(", "),  # change with type annotations
			" ".join(str(b) for b in self.body))

def make_c_function_object(scheme_proc):
	return CFunction(scheme_proc[1], scheme_proc[2][1], scheme_proc[2][2])

def is_a_func(expression):
	# only named functions at the moment
	try:
		if expression[0] == "define" and expression[2][0] == "lambda":
			return True
	except IndexError:
		return False

# at some point, accomodate for nested expressions - say (f 5 (g 2 3)) = f(5, g(2, 3))
def evaluate_expressions(expressions):
	global code_stack
	for expression in expressions:
		# first, sort out operator changes - actually no make this a c function in a std lib
		if is_a_func(expression):
			# print("Func:", expression)
			function_registry[expression[1]] = make_c_function_object(expression)
		else:
			# find function
			# print("Expres:", expression)
			function = function_registry[expression[0]]
			code_stack.append(function.__str__())
			code_stack.append(" ".join(expression) + ";")

if __name__ == "__main__":


	scheme_proc = ['define', 'f', ['lambda', ['x', 'y'], ['+', 'x', 'y', 1]]]
	function_call = ["f", "5", "6"]

	expressions = scheme_proc, function_call
	evaluate_expressions(expressions)

	print_code()
"""

###################

	"""
	def quote_lst(lst: list) -> str:
		for index, item in enumerate(lst):
			pass
	"""
		"""
		as_str = f"\"{lst}\""
		for orig, replacement in {"[": "(", "]": ")", ",": ""}.items():
			as_str = as_str.replace(orig, replacement)
		return as_str
		"""

		# print("lst:", to_quote)
				# scheme_expr[index + 1] = str(to_quote)

				# scheme_expr[index + 1] = quote_lst(to_quote)

				"""
				print("List:", to_quote)

				# scheme_expr[index + 1] = str(to_quote).replace("[", "{").replace("]", "}")
				bracket_list = str(to_quote).replace("[", "{").replace("]", "}")
				ray_format = f
				template <typename T>
				vector <T> vect {bracket_list}
				
				scheme_expr[index + 1] = ray_format
				"""
				# ray_format = "vector <T> vect " + str(to_quote).replace("[", "{").replace("]", "}")
				# scheme_expr[index + 1] = f"\ntemplate <typename T>\n{ray_format}"

###################
"""
// this is c++ code, but whatever

/*
// temporary
void displayStruct(struct Node n) {
	std::cout << "(";

	// if head == struct node: recursive call to print it
	// else: 

	try {
		// cast head to string
		std::string head_cast = std::any_cast<std::string>(n.head);
		std::cout << head_cast << ", ";
	}

	catch (bad_cast) {
		displayStruct(*n.tail);
		return;
	}


	displayStruct(*n.tail);
	std::cout << ")" << std::endl;

	/*
	try {std::cout << cast(n, int);}
	catch (bad_cast) {
		try {std::cout << cast(n, float);}
		catch (bad_cast) {
			try {std::cout << cast(n, std::string);}
				catch (bad_cast) {
					std::cerr << e.what() << std::endl;
				}
			}
		}
	std::cout << " ";
	*/

	/*
	// assumed that there is no car list

	try {
		std::cout << std::any_cast<std::string>(n.head) << " "; // use boost::any? or wrapperType?
	}
	catch (const std::bad_any_cast& s) {
		// wrong?
		std::cout << displayStruct(std::any_cast<struct Node>(n.head)) << " "; // use boost::any? or wrapperType?
	}

	if (n.tail != nullptr) displayStruct(*n.tail);
	std::cout << ")";
	*/
}
*/
"""

###################

###################

###################

###################

###################

###################

###################