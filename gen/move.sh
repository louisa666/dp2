#! /bin/bash
count=1
sid=33333
while [ $count -lt 101 ]
do
./LCG-1 "$sid" 100000 >>lg_100000/file"$count".txt
count=$[ $count + 1 ]
sid=$[$sid + 1 ]
done
