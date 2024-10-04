#!/usr/bin/env bash
if [ $# -eq 0 ]; then
    echo "Usage: ./build_and_run.sh <exercise_name>"
    exit 1
fi

EXERCISE_NAME=$1

mkdir -p build

cd build

cmake ..

make ${EXERCISE_NAME}

cd ..

./build/${EXERCISE_NAME}