#!/bin/bash


function case_1 {
    file=$1
    echo "Testing file: $file"
    echo "Flag(s) for testing: -s"
    diff <($MY_CAT $file -s) <($CAT $file -s)
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
    echo "Flag(s) for testing: -b"
    diff <($MY_CAT $file -b) <($CAT $file -b)
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
    echo "Flag(s) for testing: -n"
    diff <($MY_CAT $file -n) <($CAT $file -n)
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
    echo "Flag(s) for testing: -e"
    diff <($MY_CAT $file -e) <($CAT $file -e)
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
    echo "Testing file: $file"
    echo "Flag(s) for testing: -E"
    diff <($MY_CAT $file -E) <($CAT $file -E)
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
    echo "Testing file: $file"
    echo "Flag(s) for testing: -t"
    diff <($MY_CAT $file -t) <($CAT $file -t)
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
    echo "Testing file: $file"
    echo "Flag(s) for testing: -T"
    diff <($MY_CAT $file -T) <($CAT $file -T)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_8 {
    file=$1
    echo "Testing file: $file"
    echo "Flag(s) for testing: -seEtT"
    diff <($MY_CAT $file -seEtT) <($CAT $file -seEtT)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}

function case_9 {
    file=$1
    echo "Testing file: $file"
    echo "Flag(s) for testing: -seEbn"
    diff <($MY_CAT $file -seEbn) <($CAT $file -seEbn)
    code=$?
    if [ $code -eq 0 ]; then
        echo -e "Result: \033[32mSuccess\033[0m"
    else
        echo -e "Result: \033[31mFailed\033[0m"
    fi
    echo
}