# conditional.py

def handle_cond(scheme_expr, within_function):
    for index, argument in enumerate(scheme_expr):
        if argument == "if":
            if within_function:
                scheme_expr[index] = "FUNCTION_IF"
            else:
                scheme_expr[index] = "STD_IF"
    return scheme_expr

if __name__ == "__main__":
    code = ["if", [["> x 5"], ["display", "\"Bigger!\""], ["display", "\"Not bigger!\""]]]
    print(handle_cond(code, False))