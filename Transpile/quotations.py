# handle_quotations.py

def handle_quote(scheme_expr):
	for index, argument in enumerate(scheme_expr):
		if argument == "quote":
			scheme_expr[index] = "identity"

			if isinstance((to_quote := scheme_expr[index + 1]), list):
				# print("List:", to_quote)

				# scheme_expr[index + 1] = str(to_quote).replace("[", "{").replace("]", "}")
				bracket_list = str(to_quote).replace("[", "{").replace("]", "}")
				ray_format = f"""
				template <typename T>
				vector <T> vect {bracket_list}
				"""
				scheme_expr[index + 1] = ray_format


				# ray_format = "vector <T> vect " + str(to_quote).replace("[", "{").replace("]", "}")
				# scheme_expr[index + 1] = f"\ntemplate <typename T>\n{ray_format}"
			else:
				scheme_expr[index + 1] = f"\"{to_quote}\""

		elif isinstance(argument, list):
			scheme_expr[index] = handle_quote(argument)

	return scheme_expr


if __name__ == "__main__":
	quote_value = ["quote", "5"]
	quote_list = ["define", "sequence", ["quote", [1, 2, 3, 4, 5]]]

	print(handle_quote(quote_value), handle_quote(quote_list))

	['define', 'sequence', ['[1, 2, 3, 4, 5]']]