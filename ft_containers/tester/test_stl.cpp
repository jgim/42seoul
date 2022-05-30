/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stl.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:55:44 by jgim              #+#    #+#             */
/*   Updated: 2022/05/29 17:55:45 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_stl.hpp"

/*
 * ---------------------------------------------------------------------------- *
 *									vector										*
 * ----------------------------------------------------------------------------	*
*/

void print_vector(const std::vector<std::string>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void vector_test() {
	clock_t g_start = clock();

	std::vector<std::string> vector1;
	vector1.push_back("it's");
	vector1.push_back("42");
	vector1.push_back("seoul");
	vector1.push_back("test");
	std::cout << "vector1: ";
	print_vector(vector1);

	std::vector<std::string> vector2(vector1.begin(), vector1.end());
	std::cout << "vector2: ";
	print_vector(vector2);

	std::vector<std::string> vector3(vector2);
	std::cout << "vector3: ";
	print_vector(vector3);

	std::cout << "vector3[1]: " << vector3.at(1) << std::endl;
	std::cout << "vector3[2]: " << vector3[2] << std::endl;
	std::cout << "vector3 front: " << vector3.front() << std::endl;
	std::cout << "vector3 back: " << vector3.back() << std::endl;

	std::vector<std::string>::iterator it = vector3.begin();
	std::cout << "\n< reverse test >" << std::endl;
	for (int i = 0; it < vector3.end(); it++, i++) {
		std::cout << "[" << i << "] : " << *it << " ";
	}
	std::cout << std::endl;

	std::vector<std::string>::reverse_iterator rvrIt = vector3.rbegin();
	for (int i = 0; rvrIt < vector3.rend(); rvrIt++, i++) {
		std::cout << "[" << i << "] : " << *rvrIt << " ";
	}
	std::cout << "\n\n";

	std::cout << "vector3 empty: " << (vector3.empty() ? "true" : "false") << std::endl;
	std::cout << "vector3 size: " << vector3.size() << std::endl;
	std::cout << "vector3 max_size: " << vector3.max_size() << std::endl;
	std::cout << "vector3 capacity: " << vector3.capacity() << std::endl;

	std::cout << "vector3 clear\n";
	vector3.clear();
	std::cout << "vector3 size: " << vector3.size() << std::endl;
	std::cout << "vector3 insert (from vector2)\n";
	vector3.insert(vector3.begin(), vector2.begin(), vector2.end());
	std::cout << "vector3 size: " << vector3.size() << std::endl;
	std::cout << "vector3: ";
	print_vector(vector3);

	std::cout << "erase first\n";
	vector3.erase(vector3.begin() + 1);
	std::cout << "vector3: ";
	print_vector(vector3);

	vector3.push_back("today");
	vector3.push_back("is");
	vector3.push_back("goodday");
	std::cout << "vector3: ";
	print_vector(vector3);

	vector3.pop_back();
	std::cout << "vector3: ";
	print_vector(vector3);

	vector3.resize(4);
	std::cout << "vector3: ";
	print_vector(vector3);

	vector3.assign(3, "gaepo");
	std::cout << "vector3: ";
	print_vector(vector3);

	std::cout << "\n < vector2, vector3 swap >\n";
	vector3.swap(vector2);
	std::cout << "vector2: ";
	print_vector(vector2);
	std::cout << "vector3: ";
	print_vector(vector3);

	std::cout << "vector3 == vector2: " << (vector3 == vector2 ? "true" : "false") << std::endl;
	std::cout << "vector3 < vector2: " << (vector3 < vector2 ? "true" : "false") << std::endl;
	std::cout << "vector3 >= vector2: " << (vector3 >= vector2 ? "true" : "false") << std::endl;

	std::vector<int> vector4;
	for (int i = 0; i < 300000; i++) {
		vector4.push_back(i);
	}

	clock_t g_end = clock();
	printf("Execution time (ms): %.2fms\n",
				 (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000);
}

/*
 * ---------------------------------------------------------------------------- *
 *										map										*
 * ----------------------------------------------------------------------------	*
*/

void print_map(const std::map<std::string, int>& m) {
	std::map<std::string, int>::const_iterator b = m.begin();
	std::map<std::string, int>::const_iterator e = m.end();
	while (b != e) {
		std::cout << "[" << b->first << ':' << b->second << "] ";
		b++;
	}
	std::cout << std::endl;
}

void map_test() {
	clock_t g_start = clock();

	std::map<std::string, int> map1;
	map1["it's"] = 21;
	map1["42"] = 42;
	map1["seoul"] = 84;
	map1["test"] = 168;
	std::cout << "map1 : ";
	print_map(map1);

	std::map<std::string, int> map2(map1.find("42"), map1.end());
	std::cout << "map2 : ";
	print_map(map2);

	std::map<std::string, int> map3(map1);
	std::cout << "map3 : ";
	print_map(map3);

	std::cout << "map3[42] : " << map3["42"] << std::endl;
	std::cout << "map3[ecole] : " << map3["ecole"] << std::endl;
	print_map(map3);

	std::map<std::string, int>::reverse_iterator rvrIt = map3.rbegin();
	for (int i = 0; rvrIt != map3.rend(); rvrIt++, i++)
	{
		std::cout << "[" << rvrIt->first << ':' << rvrIt->second << "] ";
	}
	std::cout << std::endl;

	std::cout << "map3 empty: " << (map3.empty() ? "true" : "false") << std::endl;
	std::cout << "map3 size: " << map3.size() << std::endl;

	std::cout << "map3 clear\n";
	map3.clear();
	std::cout << "map3 size: " << map3.size() << std::endl;
	std::cout << "map3 insert (from map2)\n";
	map3.insert(map2.begin(), map2.end());
	std::cout << "map3 size: " << map3.size() << std::endl;
	std::cout << "map3: ";
	print_map(map3);

	std::cout << "erase 'seoul'\n";
	map3.erase(map3.find("seoul"));
	std::cout << "erase 'ecole'\n";
	map3.erase("ecole");
	std::cout << "map3 : ";
	print_map(map3);

	map3.swap(map2);
	std::cout << "map3 : ";
	print_map(map3);

	std::cout << "map3 == map2: " << (map3 == map2 ? "true" : "false") << std::endl;
	std::cout << "map3 < map2: " << (map3 < map2 ? "true" : "false") << std::endl;
	std::cout << "map3 >= map2: " << (map3 >= map2 ? "true" : "false") << std::endl;

	std::cout << "\n < operator test > \n";

	std::map<int, int> map4;
	for (int i = 0, j = 100; i < 300000; i++, j++) {
		map4.insert(std::make_pair(i * 2, j));
	}
	std::cout << "count 1 : " << map4.count(1) << std::endl;
	std::cout << "count 10 : " << map4.count(10) << std::endl;
	std::cout << "count 40001 : " << map4.count(30001) << std::endl;
	std::cout << "find 20 : " << map4.find(20)->first << std::endl;
	std::cout << "lower bound 42 : " << map4.lower_bound(42)->first << std::endl;
	std::cout << "upper bound 124 : " << map4.upper_bound(124)->first << std::endl;

	clock_t g_end = clock();
	printf("Execution time (ms): %.2fms\n",
				 (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000);
}

/*
 * ---------------------------------------------------------------------------- *
 *									stack										*
 * ----------------------------------------------------------------------------	*
*/

void stack_test() {
	clock_t g_start = clock();

	std::stack<int> st;
	for (int i = 0; i < 100000; i++) {
		st.push(i * 3);
	}
	std::cout << "Top element (st): " << st.top() << std::endl;
	std::cout << "stack size (st): " << (st.empty() ? "true" : "false")
						<< std::endl;

	std::stack<int> st2(st);
	std::cout << "Top element (st2): " << st2.top() << std::endl;
	std::cout << "stack size (st2): " << (st2.empty() ? "true" : "false")
						<< std::endl;
	std::cout << "stack empty (st2): " << (st2.empty() ? "true" : "false")
						<< std::endl;

	st2.push(99);
	st2.push(42);
	std::cout << "Top element (st2): " << st2.top() << std::endl;
	std::cout << "stack size (st2): " << (st2.empty() ? "true" : "false")
						<< std::endl;

	std::stack<int> st3 = st2;
	std::cout << "st2 == st3: " << (st2 == st3 ? "true" : "false") << std::endl;

	st3.pop();
	st3.pop();
	st3.pop();
	st3.pop();
	st3.pop();
	std::cout << "Top element (st3): " << st2.top() << std::endl;
	std::cout << "st2 == st3: " << (st2 == st3 ? "true" : "false") << std::endl;
	std::cout << "st2 != st3: " << (st2 != st3 ? "true" : "false") << std::endl;
	std::cout << "st2 < st3: " << (st2 < st3 ? "true" : "false") << std::endl;
	std::cout << "st2 >= st3: " << (st2 >= st3 ? "true" : "false") << std::endl;

	int count = 0;
	while (!st3.empty()) {
		count++;
		st3.pop();
	}
	std::cout << "Count of pop operations (st3): " << count << std::endl;
	std::cout << "stack empty (st3): " << (st3.empty() ? "true" : "false")
						<< std::endl;

	clock_t g_end = clock();
	printf("Execution time (ms): %.2fms\n",
				 (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000);
}

void test_stl() {
	std::cout << "\n ---------------------------------------- \n";
	std::cout << "                  test_stl                 " << std::endl;
	std::cout << " ---------------------------------------- \n";
	std::cout << "\n ---------------------------------------- \n";
	std::cout << "                stl_vector                 " << std::endl;
	std::cout << " ---------------------------------------- \n";
	vector_test();
	std::cout << std::endl;

	std::cout << "\n ---------------------------------------- \n";
	std::cout << "                   stl_stack                 " << std::endl;
	std::cout << " ---------------------------------------- \n";
	stack_test();
	std::cout << std::endl;

	std::cout << "\n ---------------------------------------- \n";
	std::cout << "                  stl_map                  " << std::endl;
	std::cout << " ---------------------------------------- \n";
	map_test();
	std::cout << std::endl;
}
