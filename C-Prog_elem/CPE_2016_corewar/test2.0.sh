#!/bin/zsh
output=${1}
green=$(tput setaf 2)
red=$(tput setaf 1)
white=$(tput setaf 7)
for i in `find ./error/ -name '*'`
do
    valgrind ./asm/asm $i > ${output} 2>&1
    ret=$?
    echo $i
    grep  "ERROR SUMMARY:" "$output"
    if  [[ "$ret" != 84 ]];
    then
	echo "${red}KO${white}"
	echo "Return value : "$ret
    else
	echo "${green}OK${white}"
    fi
    echo -ne "\n"
done
rm log
