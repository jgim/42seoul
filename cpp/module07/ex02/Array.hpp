/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgim <jgim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 02:03:12 by jgim              #+#    #+#             */
/*   Updated: 2022/02/04 02:03:17 by jgim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdlib.h>

template<typename T>
class Array
{
	private:
		unsigned int		_len;
		T					*_array;

	public:
		Array<T>(): _len(0), _array(NULL) {
			std::cout << "기본 생성자가 호출되었습니다. " << std::endl;
		}

		Array<T>(const unsigned int size): _len(size){
			std::cout << "생성자(size)가 생성되었습니다." << std::endl;
			if (size < 0)
				throw std::overflow_error("인덱스를 초과하였습니다.");
			_array = new T[_len];
		}

		Array<T>(const Array<T> &origin): _len(0), _array(NULL) {
			std::cout << "복사생성자가 호출되었습니다. " << std::endl;
			*this = origin;
		}

		T	&operator[](const unsigned int index) const{
			if (index >= _len || index < 0)
				throw std::overflow_error("인덱스를 초과하였습니다.");
			return _array[index];
		}

		Array<T>	&operator=(const Array<T> &origin){
			std::cout << "대입연산자가 호출되었습니다. " << std::endl;
			if (_len > 0)
				delete [] _array;
			_len = origin.size();
			_array = new T[_len];
			for (unsigned int i = 0; i < _len; i++)
				_array[i] = origin[i];
			return *this;
		}

		unsigned int	size() const{
			return _len;
		}

		void	printArray() const{
			std::cout << "배열을 출력합니다. " << std::endl << "\t";
			for (int i = 0; i < _len; i++)
				std::cout << _array[i] << " ";
			if (_len == 0)
				std::cout << "빈 배열입니다.";
			std::cout << std::endl;
		}

		~Array<T>( void ){
			if (_len > 0)
				delete [] _array;
			std::cout << "소멸자를 호출하였습니다. " << std::endl;
		}
};

#endif
