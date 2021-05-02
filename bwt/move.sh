#! /bin/bash
count=1
mkdir rcb_2900
while [ $count -lt 101 ]
do
./bwt41 < /home/louisa/diplome/rc4/rc_2900/file"$count".txt >./rcb_2900/file"$count".txt
count=$[ $count +1 ]
done
