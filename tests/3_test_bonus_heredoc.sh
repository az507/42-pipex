#!/bin/bash

clear
echo Norminette for pipex
norminette ..
read
clear

cd .. && make bonus
clear

echo Bonus test: Here_doc
echo
echo Test 1: Here_doc with no args
echo 'valgrind ./pipex here_doc'
valgrind ./pipex here_doc
read
clear

echo Test 2: Here_doc with empty string as delimiter
echo 'valgrind ./pipex here_doc "" "cat" "grep a" "tr a-z A-Z" outfile'
valgrind ./pipex here_doc "" "cat" "grep a" "tr a-z A-Z" outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 3: Here_doc with numbers as delimiter
echo 'valgrind ./pipex here_doc 0123 "head -50" "cat" "tail -1" "wc -c" outfile'
valgrind ./pipex here_doc 0123 "head -50" "cat" "tail -1" "wc -c" outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 4: Here_doc with normal args
echo 'valgrind ./pipex here_doc END "grep a" "wc -l" outfile'
valgrind ./pipex here_doc END "grep a" "wc -l" outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 5: Here_doc with empty strings as commands
echo 'valgrind ./pipex here_doc END "" "" "" "" outfile'
valgrind ./pipex here_doc END "" "" "" "" outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 6: Here_doc with outfile that cant be written to
chmod -w outfile
echo 'valgrind ./pipex here_doc abc "cat" "tail -10" "wc -c" outfile'
valgrind ./pipex here_doc abc "cat" "tail -10" "wc -c" outfile
chmod +w outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 7: Here_doc with invalid commands
echo 'valgrind ./pipex here_doc p "cats" "greps a" "wcs -c" outfile'
valgrind ./pipex here_doc p "cats" "greps a" "wcs -c" outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 8: Here_doc with valid commands but invalid options
echo 'valgrind ./pipex here_doc ww "cat" "wc -abc" outfile'
valgrind ./pipex here_doc ww "cat" "wc -abc" outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 9: Here_doc with only 1 command
echo 'valgrind ./pipex here_doc l "cat" outfile'
valgrind ./pipex here_doc l "cat" outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 10: Here_doc with only delimiter entered in
echo 'valgrind ./pipex here_doc END "cat" "grep a" "tr a-z A-Z" outfile'
valgrind ./pipex here_doc END "cat" "grep a" "tr a-z A-Z" outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 11: Here_doc with environment variables put into it
echo 'var1=hello var2=world ; valgrind ./pipex here_doc end "echo $var1 $var2" "cat" outfile'
var1=hello var2=world ; valgrind ./pipex here_doc end "echo $var1 $var2" "cat" outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 12: Here_doc with command paths included in commands
echo 'valgrind ./pipex here_doc end "/usr/bin/cat" "/usr/bin/grep a" "tr a-z A-Z" outfile'
valgrind ./pipex here_doc end "/usr/bin/cat" "/usr/bin/grep a" "tr a-z A-Z" outfile
echo -n "Output of outfile: "
cat outfile 
read
clear

echo Test 13: Here_doc with missing outfile
echo 'valgrind ./pipex here_doc END "head -50" "cat" "tail -5" "wc -c"'
valgrind ./pipex here_doc END "head -50" "cat" "tail -5" "wc -c"
echo -n "Output of outfile: "
cat 'wc -c' && rm 'wc -c'
read
clear

echo Press enter to fclean
make fclean
#rm outfile
