#to check if the number is palindrome or not
#!/bin/bash
echo " enter the number to find the palindrome"
read str1
length=${#str1}
for (( i=$length-1; i>=0; i-- ))
do
rev="$rev${str1:i:1}"
done
echo "reverse is " 
echo $rev
if [ $str1 = $rev ]
then 
echo " $str1 is a palindrome "
else
echo " $str1 is not a palindrome"
fi 
