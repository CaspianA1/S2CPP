#include "../sexi/lib/parse.cpp"
#include <iostream>

void printExpr(const sexi::ValuePtr &expr){
	if(expr->isList()){
		std::cout << "List of " << expr->size() << " elements: " << expr->toStr() << '\n';
		// expr->at(idx) or (*expr)[idx] for element access
	}
	else if(expr->isId()){
		std::cout << "Id: " << expr->toStr() << '\n';
	}
	else if(expr->isStr()){
		std::cout << "Str: " << expr->toStr() << '\n';
		// expr->toStr() to get the unescaped string
	}
	else if(expr->isNum()){
		std::cout << "Num: " << expr->toStr() << '\n';
	}
	else{
		// this should never be possible
		std::cout << "Unknown: " << expr->toStr() << '\n';
	}
}

int main(){
	auto exprs = sexi::parseFile("test.se");
	
	for(auto &&expr : exprs){
		printExpr(expr);
	}
}

/*
1. update macOS 
2. get newest version of xcoce
3. fix <filesystem>
4. get car and cdr
5. build cons
6. reduce library size and clumpiness
7. integrate with my codebase
*/