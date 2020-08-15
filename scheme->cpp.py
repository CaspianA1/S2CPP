import sys

from Front_End.lex_and_parse import parse
# parse should have the changing for the math functions
# maybe I deleted it?
# find it in Carbonite

from Transpile.variadic_input_appendage import append_input_num
from Transpile.make_function import CFunction
from Transpile.quotations import handle_quote
from Transpile.lambdas import handle_lambda
from Transpile.transform_expression import (make_c_expr, 
										   make_float_funcs,
										   modify_operators)

"""
TODO:
handle strings correctly - the double quotes disappear from the token, this may be a part of the problem - done
handle if-statements correctly - done
maybe 'if' can be a macro, if it takes in non-literal code? maybe not
or maybe the code has to be made to a string, and then run via an eval function, like this:
if_(eq?(x, 5), "display(five)", "display(not five)");
change the (if, and, or, not) function names to have an appended underscore - done
add imports - done
import scheme files as well
change variable names with dashes to have underscores - done
remove question marks and exclamation points from variable names - done
add quote function - done, but it may not work perfectly yet - completely done
test quote - not used anymore - or maybe not - done
make sure that variable definitions still work - done
turn contents inside quote into a string maybe? also if it's a list? or maybe not or something with that - done
make quote into a macro that returns its parameter name? - done
handle the number of elements being passed into a math function, and other variadic functions
implement cond instead of if
multiple-signature function problems, w/ math functions like add?
maybe generate a template for big nested lists?
template name is not being appended onto function name - done
figure out why the result "nan" is appearing for math.scm, in the middle expression

a new TODO:
- lists
- car, cdr, and cons
- cond-statements
- variadic function num arguments appendage
- import scheme files

important files:
- vadiadic input appendage - make it work
- finish writing transform_cond
- and think about nested_generic_list some more
- math.scm: write a test, test it - done
"""

class CodeStack:
	def __init__(self):
		self.main = ["int main() {"]
		self.func_list = []
		self.top_level = ["#include \"../Std_Lib/std_lib.hpp\""]

	def add(self, code_part, code):
		part_to_add_to = {"main": self.main, "funcs": self.func_list,
		"top level": self.top_level}[code_part]
		part_to_add_to.append(code)
		if not code.startswith("#"):
			part_to_add_to[-1] += ";"

	def __str__(self):
		code = ""

		for code_section in (self.top_level, self.func_list, self.main):
			for row in code_section:
				code += f"{row}\n"

		code += "return 0;\n}"
		return code


def read_from_file(file_name):
	file_contents = open(file_name).readlines()

	# remove comments
	for index, row in enumerate(file_contents):
		if (comment_spot := row.find(";")) != -1:
			file_contents[index] = row[:comment_spot]

	expression = ""
	for index, row in enumerate([i for i in [f.strip() for f in file_contents] if i not in " \n"]):
		expression += f" {row}"
		if (l := expression.count("(")) == (r := expression.count(")")):
			yield expression
			expression = ""
		elif l != r and index == len(file_contents) - 1:
			raise SyntaxError("Mismatched parentheses!")

def generate_cpp(code: CodeStack):
	c_file_name = sys.argv[1].rstrip("scm") + "cpp"
	with open(c_file_name, "w") as out_file:
		out_file.write(code.__str__())

def main(file_name):
	code_stack = CodeStack()
	eval_expr = lambda code: make_c_expr(modify_operators(code, make_float_funcs(code)))
	parsing = lambda expr: append_input_num(handle_lambda(handle_quote(parse(expr)), eval_expr))
	if len(sys.argv) > 1:
		for expression in read_from_file(file_name):
			"""
			parsed_scheme = parse(expression)
			parsed_scheme = handle_quote(parsed_scheme)
			parsed_scheme = handle_lambda(parsed_scheme, eval_expr)
			parsed_scheme = append_input_num(parsed_scheme)
			"""
			parsed_scheme = parsing(expression)

			if ((import_type := parsed_scheme[0]).startswith("import")):
				file_to_import = parsed_scheme[1]
				if import_type == "import-cpp":
					code_stack.add("top level", f"#include \"{file_to_import}\"")
				elif import_type == "import-sys":
					code_stack.add("top level", f"#include <{file_to_import}>")
				elif import_type == "import-scm":  # hm, this is not working
					main(file_to_import)  # I see why this shouldn't work, but it's hard to find a fix
				continue

				# account for "include-scm" as well

			if parsed_scheme[0] == "declare":
				if isinstance(parsed_scheme[1], list):
					function = CFunction.make_c_function(parsed_scheme, eval_expr, True)
					code_stack.add("funcs", function.__str__())
				else:
					if isinstance(parsed_scheme[2], list):
						value = eval_expr(parsed_scheme[2])
					else:
						value = parsed_scheme[2]
					code_stack.add("top level", f"auto {parsed_scheme[1]} = {value}")

			elif parsed_scheme[0] == "express":
				code_stack.add("main", f"auto {parsed_scheme[1]} = {eval_expr(parsed_scheme[2])}")

			else:
				code_stack.add("main", str(eval_expr(parsed_scheme)))

		generate_cpp(code_stack)

	else:
		print("Please specify a filename.")
		sys.exit()

if __name__ == "__main__":
	main(sys.argv[1])
