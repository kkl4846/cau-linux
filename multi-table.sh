
#!/bin/bash


if [ "$1" == '' ] || [ "$2" == '' ];then
 printf "Invalid input\n"
elif [ `expr $1` -lt 1 ] || [ `expr $2` -lt 1 ];then
 printf "Input must be greater than 0\n"
else
 for ((i=1;i<$1+1;i++))
  do
   for ((j=1;j<$2+1;j++))
    do
     printf "%2d*%2d=%2d  " "$i" "$j" "$(($i * $j))"
    done
   printf "\n"
  done
 fi
