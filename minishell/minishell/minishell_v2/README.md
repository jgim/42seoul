# Minishell



# Minishell Style Guide

Pogning에서 Minishell 프로젝트를 관리하는 컨벤션을 정의합니다.


## Project

- **MUST** 파일명과 디렉토리명, 변수명과 함수명은 알파벳 소문자, 숫자, '_' (Unix 문자) 로만 이루어져야 합니다.
  + ex) `error_handler, do_something`

- **SHOULD** 객체(변수, 함수, 매크로, 자료형, 파일과 디렉토리)는 가능한 한 명시적이고 알아보기 쉬운 이름을 사용해야 합니다. 인덱스 카운터만 원하는대로 이름지어도 됩니다.
  + ex) `is_valid_parameter, var_idx`

- **SHOULD** 주석은 파일과 함수별로 달되 파일에서는 요약 설명을 적고 함수에서는 함수, 리턴값, 함수의 인자의 설명을 간략히(norminette-v3 기준에 따라 영어로 작성 요망) 기록합니다.
  + ex)
```
@file         minishell.c
@description  파일의 설명
```
```
@description	함수의 설명
@return       리턴값에 대한 설명
@param        함수의 인자 설명
```

- **MUST** 함수 내부에 주석을 사용하는 것은 금지 되고, 주석의 시작과 끝은 별개의 줄로 표시되어야 합니다. 중간의 모든 줄은 정렬이 맞춰져야 하고, //이 아닌 '/\*'로 작성해야합니다.


## Branch

- **SHOULD** feature 개발 작업은 develop branch로부터 `feature/` 를 prefix로 갖는 feature branch를 checkout 하여 작업해야합니다.

- **SHOULD** develop branch의 commit log에는 Merge commit을 제외하고는 `feat:`, `hotfix:` 등과 같은 prefix가 선행되는 Conventional Commit Message만 남길 것을 권장합니다.

- **SHOULD** Git의 Built-in Convention에 맞춰 Commit Message 작성시에는 어떻게보다 무엇을, 왜에 맞춰 명령조로 'prefix:제목-본문' 형태로 작성합니다.
  + ex)
```
commit eb0b56b19017ab5c16c745e6da39c53126924ed6
Author: Sieun Lim <hello@pogning.com>
Date:   Mon Aug 15 22:57:55 2022 +0200

   fix: Remove deprecated methods

   Remove the deprecated methods of the header.h.
   and replace it with some methods.
```


# About Minishell

bash 기반의 간단한 쉘을 만드는 Minishell 프로젝트입니다.


## Description


## How to start
```
## Build
make

## Run
./minishell
```


## Authors
By silim124[https://github.com/silim124] && jgim[https://github.com/jgim]
