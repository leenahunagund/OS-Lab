#create , concatenate and print strings

#!/bin/bash

str1=welcome

str2=to

str3=shell

str4=programming

echo "str1:$str1"

echo "str2:$str2"

echo "str3:$str3"

echo "str4:$str4"

res=$str1""$str2""$str3""$str4

echo "concatenated string:"

echo $res

echo "the length of the resultant string is:"

echo ${#res}

echo "performing various string operations"

str5="hello_welcome_to_shell_programming"

echo "str5:$str5"

echo "prints substring of str5 from index 4 to end"

echo ${str5:4}

echo "prints substring of length 10 of str5 from index 4"

echo ${str5:4:10}

echo "deletes the shortest matching substring from front(_)"

echo ${str5#*_}

echo "deletes the shortest matching substring from back(_)"

echo ${str5%_*}

echo "deletes the longest matching substring from front(_)"

echo ${str5##*_}

echo "deletes the largest matching substring from back(_)"

echo ${str5%%_*}



		

