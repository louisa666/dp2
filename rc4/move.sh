#! /bin/bash
rm -r rc_100000
mkdir rc_100000
count=1
while [ $count -lt 101 ]
do
./rc4 -n 100000 >> ./rc_100000/file"$count".txt

sleep 1
count=$[ $count + 1 ]
done

