#!/bin/bash

function vec_of_hist_sh {
    ./vec_of_hist
}

function printHelp {
    echo " --> ERROR in input arguments "
    echo " -d : default"
    echo " -c : compile"
}

if [ $# -eq 0 ]; then
    printHelp
else
    if [ "$1" = "-d" ]; then
	vec_of_hist_sh
    elif [ "$1" = "-c" ]; then
	make clean; make;
    else
        printHelp
    fi
fi
