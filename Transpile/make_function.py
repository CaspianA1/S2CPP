from random import choice
from string import ascii_letters

ascii_letters = ascii_letters.replace("T", "")

class CFunction:
	def __init__(self, name, args, body, scheme_equivalent, template_enabled = False):
		self.name = name
		self.args = args
		self.body = body
		self.scheme_equivalent = scheme_equivalent
		self.body_evaluator = None
		self.template_enabled = template_enabled
		self.arg_types = self._generate_template_types(self.args, set())


	# infinite recursion for funcs with more than 26 arguments
	def _generate_template_types(self, args, template_types) -> list:
		if len(args) == len(template_types):
			return list(template_types)
		else:
			# expand this later on to more typenames
			template_types.add(choice(ascii_letters))
			return self._generate_template_types(args, template_types)

	def __str__(self):
		outp = ""

		if self.template_enabled:
			outp += "template <typename T, "
			for index, arg_type in enumerate(self.arg_types):
				outp += f"typename {arg_type}, "

			outp = outp.rstrip(", ")
			outp += ">\n"

		outp += f"T {self.name}("
		for index in range(len(self.args)):
			outp += f"{self.arg_types[index]} {self.args[index]}, "
		outp = outp.rstrip(", ") + ") " + "{\n" + f"return {self.body_evaluator(self.body)};\n" + "}"
		return outp

	def _set_body_eval(self, body_evaluator):
		self.body_evaluator = body_evaluator

	@staticmethod
	def make_c_function(code, expression_evaluator):
		c_func = CFunction(code[1][0], code[1][1:], code[2], code)
		c_func._set_body_eval(expression_evaluator)
		return c_func
