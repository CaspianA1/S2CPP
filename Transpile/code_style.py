# code_style.py

def frm(code: str) -> str:
	next_tab = False
	new_code = ""
	for index, row in enumerate((as_lst := code.split("\n"))):
		if row.endswith("{"):
			next_tab = True

		elif next_tab:
			as_lst[index] = "\t" + row
			if as_lst[index][0] == "{":
				next_tab = False

	return "\n".join(as_lst)