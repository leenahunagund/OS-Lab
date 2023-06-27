#arithmetic operations on numbers using switch cases
#!/bin/bash
echo "enter 2 numbers"
read n1 n2
echo "enter operator ( +,-,*,/) "
read op
case $op in
'+' ) echo "$n1 + $n2 = $((n1+n2)) "
;;
'-' ) echo "$n1 - $n2 = $((n1-n2)) "
;;
'+' ) echo "$n1 + $n2 = $((n1+n2)) "
;;
'*' ) echo "$n1 * $n2 = $((n1*n2)) "
;;
'/' ) echo "$n1 / $n2 = $((n1/n2)) "
;;
* ) echo "invalid"
esac


