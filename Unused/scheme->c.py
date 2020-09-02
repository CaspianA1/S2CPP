#scheme->c.py

import sys
from copy import deepcopy
from Transpile.transform_expression import *
from Transpile.make_function import CFunction
from Transpile.type_inference import get_type_name
from Transpile.transform_declaration import transform_declaration
from Interpreter.parse import *
from Interpreter.evaluate import evaluate

declared_functions = []

class CodeStack:
	def __init__(self):
		self.main = ["int main() {"]
		self.func_list = []
		self.top_level = ["#include \"clib.h\""]

	def add(self, code_part, code):
		{"main": self.main, "func_list": self.func_list,
		"top_level": self.top_level}[code_part].append(code + ";")

	def __str__(self):
		code = ""

		for code_section in (self.top_level, self.func_list, self.main):
			for row in code_section:
				code += f"{row}\n"

		code += "return 0;\n}"
		return code

def read_from_file(file_name):
	expression = ""
	for row in [i.strip() for i in open(file_name).readlines() if i != "\n"]:
		expression += f" {row}"
		if expression.count("(") == expression.count(")"):
			yield expression
			expression = ""

def main():
	code_stack = CodeStack()
	eval_expr = lambda code: make_c_expr(modify_operators(code, make_float_funcs(code)))
	if len(sys.argv) > 1:
		for expression in read_from_file(sys.argv[1]):
			parsed_scheme = read_from_tokens(tokenize(expression))

			print("Parsed scheme:", parsed_scheme)

			if parsed_scheme[0] == "define":  # definition 
				print("Definition:", parsed_scheme)
				if isinstance(parsed_scheme[2], list) and parsed_scheme[2][0] == "lambda":  # function
					declared_functions.append(CFunction.make_c_function(parsed_scheme, eval_expr))
				else:  # variable

					print("Variable:", parsed_scheme)

					used_functions = []

					for function in declared_functions:  # check if functions are present in assignment
						if function_is_present(function.name, parsed_scheme[2]):
							used_functions.append(function)
							# out_type = get_type_name(evaluate(function.scheme_equivalent))
							# function.return_type = out_type
							# print("Function:", function)
							# code_stack.add("func_list", function.__str__())
							# function.return_type = get_type_name(evaluate(deepcopy(parsed_scheme))  # resets return type each time
							# code_stack.add("func_list", function.__str__())  # but later, remove overlapping function names
	

					if isinstance(parsed_scheme[2], list):
						c_repr = eval_expr(deepcopy(parsed_scheme[2]))
					else:
						c_repr = parsed_scheme[2]

					output_type = get_type_name(evaluate(parsed_scheme[2]))
					declaration = f"{output_type} {parsed_scheme[1]} = {c_repr}"
					code_stack.add("top_level", declaration)

			else:  # unassigned function call
				print("Expression:", parsed_scheme)

			"""
			print("Parsed scheme:", parsed_scheme)
			try:
				if parsed_scheme[2][0] == "lambda" and parsed_scheme[0] == "define":
					print("Function:", parsed_scheme)  # WEIRD ERROR
					declared_functions.append(CFunction.make_c_function(parsed_scheme, eval_expr))  # no continue needed
				raise IndexError("")  # needed to continue flow
			except (IndexError, TypeError):  # detect variable declaration
				print("Expression:", parsed_scheme)
				if len(parsed_scheme) == 3 and parsed_scheme[0] == "define":
					c_declaration = transform_declaration(eval_expr(parsed_scheme))
					# hm, problems
					print("C declaration:", c_declaration)
					code_stack.add("top_level", c_declaration)
					continue

				for index, function in enumerate(declared_functions):
					if function.name == parsed_scheme[0]:  # see if already used?
						evaluate(function.scheme_equivalent)
						declared_functions[index].return_type = get_type_name(evaluate(parsed_scheme))
						code_stack.add("func_list", declared_functions[index].__str__())
						break

				code_stack.add("main", eval_expr(parsed_scheme))
			"""

	else:
		print("Please specify a filename.")
		sys.exit()


	c_file_name = sys.argv[1].rstrip("scm") + "c"
	with open(c_file_name, "w") as out_file:
		out_file.write(code_stack.__str__())


			# make to c expression:
			# add "include" "std_lib.h" to top of stack
			# if top-level def: put it there
			# or if main-def, put it there
			# if expression, put it in main
			# if function def, put it in in-between state
			# add to code stack
			# write code stack to a file


if __name__ == "__main__":
	main()