# parse.py

var_name_replacements = {
	"~": "_approx", ":": "_colon", "-": "_",
	"!": "_impure", "@": "_at"  , "$": "_dollar",
	"&" : "_and", "?": "_cond"
}

operator_replacements = {
	">": "gt",
	"<": "lt",
	">=": "gte",
	"<=": "lte"
}

"""
def remove_comments(rows):
	for row in rows:
		if (comment_spot := row.find(";")) != -1:
			if (possibly_empty_row := row[:comment_spot]).strip() == "":
				continue
			yield row[:comment_spot]
		else:
			yield row
"""

def tokenize(chars: str) -> list:
	tokens = chars.replace('(', ' ( ').replace(')', ' ) ')  # .split()
	token_buffer = [""]

	string_find_started = False 
	str_buffer = ""
	for char in tokens:
		if char == "\"":
			if string_find_started:
				str_buffer += char
				token_buffer.append(str_buffer)
				str_buffer = ""
				string_find_started = False
				continue
			else:
				string_find_started = True
		if string_find_started:
			str_buffer += char
		else:
			if char == " ":
				token_buffer.append(char)
			else:
				token_buffer[-1] += char

	token_buffer = [a for a in [a.strip() for a in token_buffer] if a != ""]

	# non-list symbol support
	for index, token in enumerate(token_buffer):	
		if token != "'" and token.startswith("'"):
			tokens[index] = "'"
			tokens.insert(index + 1, token[1:])

	return token_buffer


def parse(program: str) -> list:
	return change_var_names(read_from_tokens(tokenize(program)))

def change_var_names(scheme_expr: list):
	for index, token in enumerate(scheme_expr):
		if isinstance(token, str) and not token.startswith("\""):
			for special_char, replacement in var_name_replacements.items():
				if scheme_expr[index] != special_char:
					scheme_expr[index] = scheme_expr[index].replace(special_char, replacement)

		if token in ("and", "or", "not"):
			scheme_expr[index] += "_"

		elif isinstance(token, list):
			scheme_expr[index] = change_var_names(token)

		elif (equiv_operator := operator_replacements.get(token)) is not None:
			scheme_expr[index] = equiv_operator

	return scheme_expr

def read_from_tokens(tokens: list) -> dict:
	if len(tokens) == 0: return

	current_token = tokens.pop(0)
	if current_token == "(":
		sub_expr = []

		while tokens[0] != ")":
			sub_expr.append(read_from_tokens(tokens))

		tokens.pop(0)  # remove last ")"
		return sub_expr

	elif current_token == ")": raise SyntaxError("Unexpected \")\"")

	else: return atom(current_token)

def atom(token: str):
	# if token[0] == "\"" and token.endswith("\""):
		# return token[1:-1]
	try:
		return int(token)
	except ValueError:
		try:
			return float(token)
		except ValueError:
			return str(token)