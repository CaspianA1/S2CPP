# form_wrapped_types.py

"""
sometimes, variables are passed in that are not floats-
that can not be inspected in the same way as literals
"""
def make_wrapped_types(code):
    for index, argument in enumerate(code):
        if argument in ("+", "-", "*", "/"):
            print("Change to wrapped types:", code[index + 1:])
            # how to deal with sub list now?
            cpp_generic_args = ""
            for a in code[index + 1:]:
                var_type = ""
                if a in ("#t", "#f"): var_type = "B"
                elif isinstance(a, str) and a.startswith("\"") and a.endswith("\""):
                    var_type = "S"
                elif isinstance(a, int):
                    var_type = "I"
                elif isinstance(a, float):
                    var_type = "F"
                elif isinstance(a, list):
                    print("Nested:", a)
                    # how to gather type info of result?
                    # WrappedType::make(tostring(identity(nestedstuff)), 
                else:
                    continue  # var name
                cpp_generic_args += f"WrappedType::make({var_type}, \"{a}\""
            

        elif isinstance(argument, list):
            code[index] = make_wrapped_types(argument)
    return code