#!/bin/bash

clear
echo Norminette for pipex
norminette ..
read

cd .. && make re
ls -al ~ > infile
touch outfile
clear

echo Normal test
echo
#Normal test
echo Test 1: No args
echo 'valgrind ./pipex'
valgrind ./pipex
read
clear

echo Test 2: More than 4 args
echo 'valgrind ./pipex infile "cat" "grep a" "wc -c" outfile'
valgrind ./pipex infile "cat" "grep a" "wc -c" outfile
echo -n "Output of outfile :"
cat outfile && rm outfile 
read
clear

echo Test 3: Normal input
echo 'valgrind ./pipex infile "cat" "tr a-z A-Z" outfile'
valgrind ./pipex infile "cat" "tr a-z A-Z" outfile
echo -n "Output of outfile :"
cat outfile && rm outfile
read
clear

echo Test 4: Nonexisting infile
echo 'valgrind ./pipex notexisting "head -10" "grep p" outfile'
valgrind ./pipex notexisting "head -10" "grep p" outfile
echo -n "Output of outfile :"
cat outfile && rm outfile
read
clear

echo Test 5: Nonexisting command
echo 'valgrind ./pipex infile "cat" "tails -1" outfile'
valgrind ./pipex infile "cat" "tails -1" outfile
echo -n "Output of outfile :"
cat outfile && rm outfile
read
clear

echo Test 6: Nonexisting infile and command
echo 'valgrind ./pipex abcde "trs a-z" "wcs -p" outfile'
valgrind ./pipex abcde "trs a-z" "wcs -p" outfile
echo -n "Output of outfile :"
cat outfile && rm outfile
read
clear

echo Test 7: Valid command with invalid option
echo 'valgrind ./pipex infile "cat" "wcs -c" outfile'
valgrind ./pipex infile "cat" "wcs -c" outfile
echo -n "Output of outfile :"
cat outfile && rm outfile
read
clear

echo Test 8: Environment variables
echo 'var1=hello var2=abc ; valgrind ./pipex infile "cat" "echo $var1 $var2" outfile'
var1=hello var2=abc ; valgrind ./pipex infile "cat" "echo $var1 $var2" outfile
echo -n "Output of outfile: "
cat outfile && rm outfile
read
clear

echo Test 9: 4 args, with all invalid options
echo 'valgrind ./pipex var1=hello "faojfoa" "abc=123" p'
valgrind ./pipex var1=hello "faojfoa" "abc=123" p
echo -n "Output of outfile :"
cat p && rm p
read
clear

echo Test 10: Infile that cant be read from
chmod -r infile
echo 'valgrind ./pipex infile "cat" "wc -l" outfile'
valgrind ./pipex infile "cat" "wc -l" outfile
echo -n "Output of outfile: "
chmod +r infile
cat outfile && rm outfile
read
clear

echo Test 11: Outfile that cant be written to
chmod +r infile
touch outfile ; chmod -w outfile
echo 'valgrind ./pipex infile "cat "wc -l " outfile'
valgrind ./pipex infile "cat" "wc -l " outfile
echo -n "Output of outfile: "
cat outfile ; chmod +w outfile ; rm outfile
read
clear

echo Test 12: Both infile and outfile permissions error
chmod -r infile ; touch outfile ; chmod -w outfile
echo 'valgrind ./pipex infile "cat" "wc -c" outfile'
valgrind ./pipex infile "cat" "wc -c" outfile
echo -n "Output of outfile: "
cat outfile ; chmod +w outfile ; chmod +r infile ; rm outfile
read
clear

echo Test 13: Commands with path attached to it already e.g. /usr/bin/cat
echo 'valgrind ./pipex infile "/usr/bin/cat" "tr a-z A-Z" outfile'
valgrind ./pipex infile "/usr/bin/cat" "tr a-z A-Z" outfile
echo -n "Output of outfile: "
cat outfile && rm outfile
read
clear

echo Test 13-2: Commands with path attached to it already e.g. /usr/bin/cat
echo 'valgrind ./pipex infile "/usr/bin/cat" "/usr/bin/tr a-z A-Z" outfile'
valgrind ./pipex infile "/usr/bin/cat" "/usr/bin/tr a-z A-Z" outfile
echo -n "Output of outfile: "
cat outfile && rm outfile
read
clear

echo Test 14: 1 missing outfile
echo 'valgrind ./pipex infile "head -10" "tail -1" "wc -c"'
valgrind ./pipex infile "head -10" "tail -1" "wc -c"
echo -n "Output of outfile: "
cat 'wc -c' && rm 'wc -c'
read
clear

echo Test 15: 1 missing infile
echo 'valgrind ./pipex "head -10" "tail -1" "wc -c" outfile'
valgrind ./pipex "head -10" "tail -1" "wc -c" outfile
echo -n "Output of outfile: "
cat outfile && rm outfile
read
clear

echo Test 16: infile and outfile in the middle
echo 'valgrind ./pipex infile "outfile" "infile" outfile'
valgrind ./pipex infile "outfile" "infile" outfile
echo -n "Output of outfile: "
cat outfile && rm outfile
read
clear

echo Test 17: using shell builtins
echo 'valgrind ./pipex infile "cd /home/achak" "ls -al" outfile'
valgrind ./pipex infile "cd /home/achak" "ls -al" outfile
echo -n "Output of outfile: "
cat outfile && rm outfile
read
clear

echo Test 18: using infile from a different directory
echo 'valgrind ./pipex /home/achak "ls -al" "wc -l" outfile'
valgrind ./pipex /home/achak "ls -al" "wc -l" outfile
echo -n "Output of outfile: "
cat outfile && rm outfile
read
clear

echo Test 19: using outfile from a different directory
echo 'valgrind ./pipex infile "ls -al" "wc -l" /home/achak/tempfile'
valgrind ./pipex infile "ls -al" "wc -l" /home/achak/tempfile
echo -n "Output of outfile: "
cat /home/achak/tempfile && rm /home/achak/tempfile
read
clear

echo Test 20: using both files from a different directory
echo 'valgrind ./pipex /home/achak/Documents/libft "grep libft" "tr a-z A-Z" outfile'
valgrind ./pipex /home/achak/Documents/libft "grep libft" "tr a-z A-Z" ../temp
echo -n "Output of outfile: "
cat ../temp && rm ../temp
read
clear

echo Test 21: Empty strings as commands
echo 'valgrind ./pipex infile "cat" "" outfile'
valgrind ./pipex infile "cat" "" outfile
echo -n "Output of outfile: "
cat outfile && rm outfile
read
clear

echo Test 22: Empty strings as files
echo 'valgrind ./pipex "" "grep a" "ls -al" outfile'
valgrind ./pipex "" "grep a" "ls -al" outfile
echo -n "Output of outfile: "
cat outfile && rm outfile
read
clear

echo Test 23: Empty strings as everything
echo 'valgrind ./pipex "" "" "" ""'
valgrind ./pipex "" "" "" ""
read

echo Press enter to fclean
rm wc\ -c
make fclean
#rm infile outfile

#Bonus test - multiple pipes (no here_doc)
