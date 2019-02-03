#!/usr/bin/env bash


PROG="$(dirname $0)/../ft_ssl"
FILE="$0"

assert() {
	if [ $# -ne 2 ]; then
		echo "assert function should take 2 arguments: cmp1, cmp2" &&
		exit 1
	fi

	expected=$(eval $1)
	real=$(eval $2)

	if [ $? -ne 0 ]; then
		exit 1
	fi

	if [ "$expected" = "$real" ]; then
		printf '%-80s%s\n' "$2" " OK"
	else
		tmp1="/tmp/1"
		tmp2="/tmp/2"
		echo "$1" > tmp1
		echo "$2" > tmp2
		echo "$expected" >> tmp1
		echo "$real" >> tmp2
		vim -d tmp1 tmp2
		echo -e "failed case:\n\n $2";
		exit 1
	fi
}

function md5_tests {
	assert 	"echo lol | md5" 												\
			"echo lol | $PROG md5"

	assert 	"echo lol | md5 -p" 											\
			"echo lol | $PROG md5 -p"

	assert 	"md5 -q -s asd" 												\
			"$PROG md5 -q -s asd"

	assert 	"md5 -q -s asd -s qwe -s zxc" 									\
			"$PROG md5 -q -s asd -s qwe -s zxc"

	assert 	"md5 -q $(which md5)" 											\
			"$PROG md5 -q $(which md5)"

	assert 	"md5 -r $(which md5)" 											\
			"$PROG md5 -r $(which md5)"

	assert	"echo lol | md5 -p -r $(which md5)"								\
			"echo lol | $PROG md5  -p -r $(which md5)"

	assert	"echo 'GL HF lets go' | md5 -q -p -s foo $FILE"					\
			"echo 'GL HF lets go' | $PROG md5 -q -p -s foo $FILE"

	assert	"echo 'one more' | md5 -q -p -s foo -s bar $FILE"				\
			"echo 'one more' | $PROG md5 -q -p -s foo -s bar $FILE"

	assert	"echo 'just to be extra clear' | md5 -r -q -p -s foo $FILE"		\
			"echo 'just to be extra clear' | $PROG md5 -r -q -p -s foo $FILE"
}

function run {
	clear
	md5_tests
	echo "passed!"
}

run