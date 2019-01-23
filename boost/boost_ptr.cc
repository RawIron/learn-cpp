// valgrind --tool=memcheck ./boost_ptr

#include <boost/scoped_ptr.hpp>
#include <string.h>
#include <string>
#include <iostream>

#define C_STRING(str_literal) ((char*) std::string(str_literal).c_str())

bool do_scope() {
	char const *value = "harmless";
    boost::scoped_ptr<char> name((char*) malloc(128));
    boost::scoped_ptr<char> c_empty(strdup(""));

	char* const args[] = {C_STRING("a c string literal"), NULL};

    //boost::scoped_ptr<char> null_name(NULL);
    //boost::scoped_ptr<char> bomb((value == NULL) ? NULL : strdup(value));
	//char* const args[] = {bomb.get(), null_name.get(), NULL};
	//if (bomb == NULL) std::cout << "a bomb is NULL";
	//if (null_name == NULL) std::cout << "a name is NULL";
	//if (null_name.get() == NULL) std::cout << "get on NULL";

	return true;
}

int main()
{
    do_scope();
}
