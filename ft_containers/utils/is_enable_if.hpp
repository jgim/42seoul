# ifndef IS_ENABLE_IF_HPP
#define IS_ENABLE_IF_HPP

#include <iostream>

namespace ft
{

	template <bool condition, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T>
	{ typedef T type; };
}

#endif
