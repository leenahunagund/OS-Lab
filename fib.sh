#fibonacci numbers
#!/bin/bash
echo "enter number of terms"
read n
n1=0
n2=1
if [ $n == 1 ]
then 
	echo "$n1"
elif [ $n == 2 ]
then
	echo "$n1 $n2"
else
	echo "$n1"
	echo "$n2"
for (( i=2 ; i<$n ; i++ ))
do
	n3=$((n1+n2))
	echo "$n3"
	n1=$n2
	n2=$n3
done
fi
