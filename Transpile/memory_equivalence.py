# memory_equivalence.py

def handle_mem_equivalence(code):
    for index, argument in enumerate(code):
        if index == 0 and argument == "eq_cond":
            code[index + 1] = f"&{code[index + 1]}"
            code[index + 2] = f"&{code[index + 2]}" 
        elif isinstance(argument, list):
            code[index] = handle_mem_equivalence(argument)
    return code