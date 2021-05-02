#! /bin/bash
for ((count=1; count<101; count++ ))
do
./bs -f "/home/louisa/diplome/bwt/rcb_2900/file"$count".txt" -w 8 -u 16 -q >> rcb_2900.txt
done



