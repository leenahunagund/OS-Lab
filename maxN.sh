#max number in an array of numbers
#!/bin/bash
echo "enter array elements"
read -a arr
echo ${arr[*]}
max=0
for i in ${arr[*]}
do
if [ $i -gt $max ]
then
max=$i
fi
done
echo "max : $max"
