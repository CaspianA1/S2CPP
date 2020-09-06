## This is a Scheme to C++ transpiler.
- Templates and the 'auto' keyword are used to bring semi-generic behavior to C++.
- You can check out the Makefile to see which tests you can run.
- Note: this repository is a little bit messy, mostly due to how many corner cases that there are with transpilation.
- Lists and the ability to quote them is quite unstable, as a note. Beware when using them!
- Overall, I hope that you think this project is cool, and if so, feel free to contribute. If you dare, help me make quoted lists a thing!

## A few notes to how Scheme is modified:
- 1. "Declare" is used for top-level bindings.
- 2. "Express" is used for variables that store the result of a function.
- 3. "import-cpp" imports a c++ file, "import-scm" imports a Scheme file, and "import-sys" imports a C++ system-level file.
