// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void );
	//계좌인덱스 가져오기
	static int	getTotalAmount( void );
	// 전체 양 가져오기
	static int	getNbDeposits( void );
	// 입금 인덱스 가져오기
	static int	getNbWithdrawals( void );
	// 출금 인덱스 가져오기
	static void	displayAccountsInfos( void );
	// 계좌 정보 출력하기

	Account( int initial_deposit );
	// 초기 예금값이 들어간 생성자
	~Account( void );
	// 소멸자

	void	makeDeposit( int deposit );
	// 입금
	bool	makeWithdrawal( int withdrawal );
	// 출금 여부
	int		checkAmount( void ) const;
	// 양 체크
	void	displayStatus( void ) const;
	// 상태 디스플레이

private:

	static int	_nbAccounts;
	//계좌 인덱스
	static int	_totalAmount;
	// 전체 양
	static int	_totalNbDeposits;
	//전체 입금 수
	static int	_totalNbWithdrawals;
	//전체 출금 수

	static void	_displayTimestamp( void );
	// 타임스탬프 출력

	int				_accountIndex;
	// 현재 계좌 인덱스
	int				_amount;
	// 양
	int				_nbDeposits;
	// 입금 수
	int				_nbWithdrawals;
	// 출금 수

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
