#largest of 3 numbers
#!/bin/bash
f=0;
echo "Enter array elements"
read -a arr
echo "Array is"
echo ${arr[*]}
echo "Enter key to search"
read k
for i in ${a[*]}
do
 if [ arr[$i] == k ];then
 echo "Key found"
else
 echo "Not found"
fi
