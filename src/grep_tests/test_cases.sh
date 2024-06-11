#!/bin/bash


function case_1 {
    file=$1
    echo "Testing file: $file with rexp: ja"
    echo "Flag(s) for testing: -e"
    diff <($MY_GREP -e ja $file ) <($GREP -e ja $file)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_2 {
    file=$1
    echo "Testing file: $file"
    echo "Flag(s) for testing: -i with rexp: ja"
    diff <($MY_GREP -i ja $file) <($GREP -i ja $file)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_3 {
    file=$1
    echo "Testing file: $file"
    echo "Flag(s) for testing: -v with rexp: ja"
    diff <($MY_GREP -v ja $file) <($GREP -v ja $file)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_4 {
    file=$1
    echo "Testing file: $file"
    echo "Flag(s) for testing: -c with rexp: a"
    diff <($MY_GREP -c a $file) <($GREP -c a $file)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_5 {
    file=$1
    file2=$2
    echo "Testing files: $file $file2"
    echo "Flag(s) for testing: -l with rexp: zombie"
    diff <($MY_GREP -l zombie $file $file2) <($GREP -l zombie $file $file2)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_6 {
    file=$1
    file2=$2
    echo "Testing files: $file $file2"
    echo "Flag(s) for testing: -n with rexp: zombie"
    diff <($MY_GREP -n zombie $file $file2) <($GREP -n zombie $file $file2)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_7 {
    file=$1
    file2=$2
    echo "Testing files: $file $file2"
    echo "Flag(s) for testing: -h with rexp: zombie"
    diff <($MY_GREP -h zombie $file $file2) <($GREP -h zombie $file $file2)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_8 {
    echo "Testing file: testik (does not exist)"
    echo "Flag(s) for testing: -s"
    diff <($MY_GREP -s ja testik) <($GREP -s ja testik)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_9 {
    file=$2
    reg_file=$1
    echo "Testing file: $file with files with regex $reg_file"
    echo "Flag(s) for testing: -f"
    diff <($MY_GREP -f $reg_file $file) <($GREP -f $reg_file $file)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_10 {
    file=$1
   
    echo "Testing file: $file"
    echo "Flag(s) for testing: -o with regex: you"
    diff <($MY_GREP -o you $file) <($GREP -o you $file)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_11 {
    file=$1

    echo "Testing file: $file"
    echo "Flag(s) for testing: -vie with regex: you"
    diff <($MY_GREP -vie you $file) <($GREP -vie you $file)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_12 {
    file=$1

    echo "Testing file: $file"
    echo "Flag(s) for testing: -icvlne with regex: Eto"
    diff <($MY_GREP -icvlne Eto $file) <($GREP -icvlne Eto $file)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}