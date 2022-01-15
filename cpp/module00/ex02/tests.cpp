// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {
	typedef std::vector<Account::t>							  accounts_t;
	// 비어있는 Account::t 타입의 account_t생성
	typedef std::vector<int>								  ints_t;
	//int타입의 ints_t vector 생성
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;
	//account_t의 iterator와 ints_t의 iterator를 묶어줌

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	// amounts 배열을 42, 54, 957,432, 1234, 0, 754, 16575로 초기화
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	//amounts의 배열 크기는 sizeof(amounts) /sizeof(int)
	accounts_t				accounts( amounts, amounts + amounts_size );
	// accouts_t타입의 accounts에 배열 값을 복사
	accounts_t::iterator	acc_begin	= accounts.begin();
	//acc_begin accounts 첫번째 값
	accounts_t::iterator	acc_end		= accounts.end();
	//acc_end accounts 마지막값

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	//d배열 = 5, 765, 564, 2, 87, 23, 9, 20
	size_t const		d_size( sizeof(d) / sizeof(int) );
	//size d배열의 크기 d_size
	ints_t				deposits( d, d + d_size );
	//deposits vector에 값을 배열값을 복사
	ints_t::iterator	dep_begin	= deposits.begin();
	//deposits의 시작 iterator
	ints_t::iterator	dep_end		= deposits.end();
	//deposits의 끝 iterator

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	// w 배열
	size_t const		w_size( sizeof(w) / sizeof(int) );
	// w배열의 크기
	ints_t				withdrawals( w, w + w_size );
	// withdrawals에 w배열 복사
	ints_t::iterator	wit_begin	= withdrawals.begin();
	// withdrawals 시작 iteraotor
	ints_t::iterator	wit_end		= withdrawals.end();
	// withdrawals의 끝 iterator

	Account::displayAccountsInfos();
	// displayAccountsInofs 함수를 실행
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	//맴버 함수 어댑터(mem_fun, mem_fun_ref)를 사용하면 맴버 함수를 함수 객체처럼 호출 할 수 있다.  즉 for_each 와 같은 stl 알고리즘의 펑터로서 사용할 수 가있다.

	for ( acc_int_t it( acc_begin, dep_begin );
	// acc의 시작값
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
		// account iterator 위치에 deposit iterator의 값을 넣어줌
	}

	Account::displayAccountsInfos();
	// displayAccountsInofs 함수를 실행
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	//맴버 함수 어댑터(mem_fun, mem_fun_ref)를 사용하면 맴버 함수를 함수 객체처럼 호출 할 수 있다.  즉 for_each 와 같은 stl 알고리즘의 펑터로서 사용할 수 가있다.
	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
		// account iterator 위치에 withdrawal iterator의 값을 넣어줌
	}

	Account::displayAccountsInfos();
	// displayAccountsInofs 함수를 실행
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
