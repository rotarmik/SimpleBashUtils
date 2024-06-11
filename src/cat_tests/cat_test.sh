#!/bin/bash
script_dir=$(dirname "$(readlink -f "$0")")

cd "$script_dir" || exit

source test_cases.sh

MY_CAT=../cat/s21_cat
CAT=/bin/cat

TEST="ultimate_test.txt"

case_1 $TEST
case_2 $TEST
case_3 $TEST
case_4 $TEST
case_5 $TEST
case_6 $TEST
case_7 $TEST
case_8 $TEST
case_9 $TEST
echo --------------------------------------
