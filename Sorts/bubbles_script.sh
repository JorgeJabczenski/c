#!/bin/bash

echo "#tam bolha selecao insercao" > bubbles_nao_ordenados.dat

mkdir tmp

for ((i=1000; i <= 50000; i+=1000))
do
	command time -o ./tmp/bubble1 -a -f "%U" ./Bubble_Sort1/ebubble  < ./entradas/nao_ordenadas/$i.txt
	command time -o ./tmp/bubble2 -a -f "%U" ./Bubble_Sort2/ebubble2 < ./entradas/nao_ordenadas/$i.txt
	command time -o ./tmp/bubble3 -a -f "%U" ./Bubble_Sort3/ecock    < ./entradas/nao_ordenadas/$i.txt

done 

mapfile -t TBUBBLE1 < ./tmp/bubble1
mapfile -t TBUBBLE2 < ./tmp/bubble2
mapfile -t TBUBBLE3 < ./tmp/bubble3

for i in {0..49}
do
    let j=i+1;
    echo  "${j}000 ${TBUBBLE1[$i]} ${TBUBBLE2[$i]} ${TBUBBLE3[$i]}" >> bubbles_nao_ordenados.dat
done
rm -r ./tmp
mkdir tmp

echo "#tam bolha selecao insercao" > bubbles_ordenados.dat
for ((i=1000; i <= 50000; i+=1000))
do
	command time -o ./tmp/bubble1 -a -f "%U" ./Bubble_Sort1/ebubble  < ./entradas/ordenadas/$i.txt
	command time -o ./tmp/bubble2 -a -f "%U" ./Bubble_Sort2/ebubble2 < ./entradas/ordenadas/$i.txt
	command time -o ./tmp/bubble3 -a -f "%U" ./Bubble_Sort3/ecock    < ./entradas/ordenadas/$i.txt

done 

mapfile -t TBUBBLE1 < ./tmp/bubble1
mapfile -t TBUBBLE2 < ./tmp/bubble2
mapfile -t TBUBBLE3 < ./tmp/bubble3

for i in {0..49}
do
    let j=i+1;
    echo  "${j}000 ${TBUBBLE1[$i]} ${TBUBBLE2[$i]} ${TBUBBLE3[$i]}" >> bubbles_ordenados.dat
done
rm -r ./tmp
