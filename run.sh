#!/bin/bash

set -eu

# どこから実行しても reactive ディレクトリ基準で動かす
cd "$(dirname "$0")"

# 一つ上に main.cpp があればそれを解答として使う
if [ -f ../main.cpp ]; then
    src=../main.cpp
else
    src=solve.cpp
fi

# compile <ソース> <出力先>
compile() {
    echo -n "compile $1 ... "
    local start=$SECONDS
    local err
    if ! err=$(g++ "$1" -std=c++23 -O2 -o "$2" 2>&1); then
        echo "FAILED"
        echo "$err"
        exit 1
    fi
    echo "done ($((SECONDS - start))s)"
}

# judge.cpp は変更がなければコンパイルし直さない
if [ judge -nt judge.cpp ]; then
    echo "compile judge.cpp ... skipped (up to date)"
else
    compile judge.cpp judge
fi
compile "$src" solve

infiles=$(find data -name "*.in" | sort)
echo "run $(echo "$infiles" | wc -w) cases"

passed=0
total=0

for infile in $infiles; do
    if output=$(python3 reactive.py "$infile" 2>&1); then
        echo "PASS $infile"
        passed=$((passed + 1))
    else
        echo "===== $infile ====="
        echo "$output"
        echo "FAIL"
        echo
    fi

    total=$((total + 1))
done

echo "$passed / $total passed."
