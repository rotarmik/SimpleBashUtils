#!/bin/bash
script_dir=$(dirname "$(readlink -f "$0")")

cd "$script_dir" || exit

source test_cases.sh

MY_GREP=../grep/s21_grep
GREP=/bin/grep

TEST="test.txt"
TEST2="test2.txt"
REG_FILE="reg"

case_1 $TEST
case_2 $TEST
case_3 $TEST
case_4 $TEST
case_5 $TEST $TEST2
case_6 $TEST $TEST2
case_7 $TEST $TEST2
case_8 $TEST
case_9 $REG_FILE $TEST 
case_10 $TEST
case_11 $TEST
case_12 $TEST
echo --------------------------------------