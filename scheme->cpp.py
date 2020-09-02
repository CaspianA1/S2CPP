import sys
from os.path import abspath, isfile

from Front_End.lex_and_parse import parse

from Transpile.code_style import frm
from Transpile.variadic_input_appendage import append_input_num
from Transpile.make_function import CFunction
from Transpile.quotations import handle_quote
from Transpile.lambdas import handle_lambda
from Transpile.math_double_casting import math_double_cast as mdc
from Transpile.memory_equivalence import handle_mem_equivalence as hme
from Transpile.conditional import handle_cond
from Transpile.transform_expression import (make_c_expr, 
										   make_float_funcs,
										   modify_operators)

"""
TODO:
handle strings correctly - the double quotes disappear from the token, this may be a part of the problem - done
handle if-statements correctly - done
maybe 'if' can be a macro, if it takes in non-literal code? maybe not - done
or maybe the code has to be made to a string, and then run via an eval function, like this: - done
if_(eq?(x, 5), "display(five)", "display(not five)"); - done
change the (if, and, or, not) function names to have an appended underscore - done
add imports - done
import scheme files as well - still working on it - done
change variable names with dashes to have underscores - done
remove question marks and exclamation points from variable names - done
add quote function - done, but it may not work perfectly yet - still working on it
test quote - not used anymore - or maybe not - done
make sure that variable definitions still work - done
turn contents inside quote into a string maybe? also if it's a list? or maybe not or something with that - done
make quote into a macro that returns its parameter name? - done
handle the number of elements being passed into a math function, and other variadic functions - done
implement cond instead of if - still working on it
multiple-signature function problems, w/ math functions like add? - done
maybe generate a template for big nested lists? - still working on it
template name is not being appended onto function name - done
figure out why the result "nan" is appearing for math.scm, in the middle expression - done
proper error reporting - still working on it

a new TODO:
- lists
- car, cdr, and cons
- cond-statements - progress with macros
- variadic function num arguments appendage - done
- import scheme files - done

important files:
- vadiadic input appendage - make it work - done
- finish writing transform_cond - not needed anymore, macros are probably the way to go now
- and think about nested_generic_list some more
- math.scm: write a test, test it - done

another TODO:
- implement cond
- make pairs, symbols and lists, car, cdr, and cons - work more on this next
- proper error reporting
- formatter - mostly done
- eqv function - done
- import scheme files - done
- that template error with math.scm
- float and int problem with operators - done
- (int) being added to functions functions that are unrelated to math
- handle boolean values - i.e. "#t" to true, and "#f" to false
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
		return frm(code)


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

def generate_cpp(code: CodeStack, file_name):
	# c_file_name = sys.argv[1].rstrip("scm") + "cpp"
	with open(file_name, "w") as out_file:
		out_file.write(code.__str__())

def main(file_name):
	code_stack = CodeStack()
	eval_expr = lambda code: make_c_expr(mdc(modify_operators(code, make_float_funcs(code))))
	parsing = lambda expr: hme(append_input_num(handle_lambda(handle_quote(parse(expr)), eval_expr)))
	if isfile(file_name):
		for expression in read_from_file(file_name):
			"""
			parsed_scheme = parse(expression)
			parsed_scheme = handle_quote(parsed_scheme)
			parsed_scheme = handle_lambda(parsed_scheme, eval_expr)
			parsed_scheme = append_input_num(parsed_scheme)
			"""
			parsed_scheme = parsing(expression)

			# print("Parsed scheme:", parsed_scheme)

			if (import_type := parsed_scheme[0]).startswith("import"):
				rel_import_name = parsed_scheme[1].strip("\"")

				if import_type in ("import_cpp", "import_scm"):
					# absolute long name
					to_import = abspath(file_name[:file_name.rfind("/")]) + "/" + rel_import_name
					# to_import = abp(file_name) + rel_import_name

					if import_type == "import_cpp":
						code_stack.add("top level", f"#include \"{to_import}\"")
					else:  # import a scheme file here
						new_code_stack = main(to_import)
						new_filename = to_import.rstrip("scm") + "cpp"
						generate_cpp(new_code_stack, new_filename)  # not generating a file
						code_stack.add("top level", f"#include \"{new_filename}\"")
						# code_stack.add("top level", f"#include \"{new"")

				elif import_type == "import_sys":
					code_stack.add("top level", f"#include <{rel_import_name}>")
				
				continue

			if parsed_scheme[0] == "declare":
				if isinstance(parsed_scheme[1], list):
					# print("Function")
					function = CFunction.make_c_function(handle_cond(parsed_scheme, True), eval_expr, True)
					code_stack.add("funcs", function.__str__())
				else:
					# print("Declaration")
					parsed_scheme = handle_cond(parsed_scheme, False)
					if isinstance(parsed_scheme[2], list):
						value = eval_expr(parsed_scheme[2])
					else:
						value = parsed_scheme[2]
					code_stack.add("top level", f"auto {parsed_scheme[1]} = {value}")

			elif parsed_scheme[0] == "express":
				# print("Expression")
				parsed_scheme = handle_cond(parsed_scheme, False)
				code_stack.add("main", f"auto {parsed_scheme[1]} = {eval_expr(parsed_scheme[2])}")

			else:
				# print("Unassigned function call:", parsed_scheme)
				parsed_scheme = handle_cond(parsed_scheme, False)
				code_stack.add("main", str(eval_expr(parsed_scheme)))

		return code_stack
		# generate_cpp(code_stack)
	else:
		print("Invalid file path.")
		sys.exit()

if __name__ == "__main__":
	if len(sys.argv) > 1:
		code_stack = main(file_name := sys.argv[1])
		generate_cpp(code_stack, file_name.strip("scm") + "cpp")
	else:
		print("Please specify a filename.")