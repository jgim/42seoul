#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template <typename Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <typename Iterator>
	class iterator_traits<Iterator*>
	{
		public:
			//pointer간의 거리를 표현하는 타입
			typedef std::ptrdiff_t					difference_type;
			typedef Iterator						value_type;
			typedef Iterator*						pointer;
			typedef Iterator&						reference;
			typedef	ft::random_access_iterator_tag	iterator_category;
	};

	template <typename Iterator>
	class iterator_traits<const Iterator*>
	{
		public:
			typedef std::ptrdiff_t					difference_type;
			typedef const Iterator					value_type;
			typedef const Iterator*					pointer;
			typedef const Iterator&					reference;
			typedef	ft::random_access_iterator_tag	iterator_category;
	};
}
#endif
