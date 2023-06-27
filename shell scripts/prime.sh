#prime numbers
#!/bin/bash
echo "enter the value of N to find prime numbers from 1 to N"
read N
f=0
echo "prime numbers from 1 to $N are "
echo
for (( i=2 ; i<=$N ; i++ ))
do
for (( j=2 ; j<= $N ; j++ ))
do
if [ $((i%j))==0 ]
then 
f=1
break
fi
done
if [ f==0 ]
then
echo -ne "$i"
echo
fi
f=0
done 
