#sum of matrix
#!/bin/bash
declare -A X
declare -A Y
declare -A Z
echo "enter the order of the matrix"
read m n 
echo "enter X"
for (( i=0; i<m; i++ ))
do
for (( j=0; j<n; j++ ))
do
read X[$i,$j]
done
done
echo "enter Y"
for (( i=0; i<m; i++ ))
do
for (( j=0; j<n; j++ ))
do
read Y[$i,$j]
done
done
echo " X is .."
for (( i=0; i<m; i++ ))
do
for (( j=0; j<n; j++ ))
do 
echo -ne "${X[$i,$j]}  "
done
echo
done 
echo " Y is .."
for (( i=0; i<m; i++ ))
do
for (( j=0; j<n; j++ ))
do 
echo -ne "${Y[$i,$j]}  "
done
echo
done
echo " Z is .."
for (( i=0; i<m; i++ ))
do
for (( j=0; j<n; j++ ))
do 
Z[$i,$j]=$((X[$i,$j]+Y[$i,$j]))
echo -ne "${Z[$i,$j]}  "
done
echo
done

