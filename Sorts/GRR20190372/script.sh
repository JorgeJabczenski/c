#!/bin/bash

echo "#tam bolha selecao insercao" > dados_nao_ordenados.dat

mkdir tmp

for ((i=1000; i <= 50000; i+=1000))
do
	command time -o ./tmp/bubble    -a -f "%U" ./Bubble_Sort3/ecock        < ./entradas/nao_ordenadas/$i.txt
	command time -o ./tmp/insertion -a -f "%U" ./Insertion_Sort/einsertion < ./entradas/nao_ordenadas/$i.txt
	command time -o ./tmp/selection -a -f "%U" ./Selection_Sort/eselection < ./entradas/nao_ordenadas/$i.txt

done 

mapfile -t TBUBBLE < ./tmp/bubble
mapfile -t TSELECT < ./tmp/selection
mapfile -t TINSERT < ./tmp/insertion

for i in {0..49}
do
    let j=i+1;
    echo  "${j}000 ${TBUBBLE[$i]} ${TSELECT[$i]} ${TINSERT[$i]}" >> dados_nao_ordenados.dat
done
rm -r ./tmp
mkdir tmp

echo "#tam bolha selecao insercao" > dados_ordenados.dat
for ((i=1000; i <= 50000; i+=1000))
do
	command time -o ./tmp/bubble    -a -f "%U" ./Bubble_Sort3/ecock        < ./entradas/ordenadas/$i.txt
	command time -o ./tmp/insertion -a -f "%U" ./Insertion_Sort/einsertion < ./entradas/ordenadas/$i.txt
	command time -o ./tmp/selection -a -f "%U" ./Selection_Sort/eselection < ./entradas/ordenadas/$i.txt

done 

mapfile -t TBUBBLE < ./tmp/bubble
mapfile -t TSELECT < ./tmp/selection
mapfile -t TINSERT < ./tmp/insertion

for i in {0..49}
do
    let j=i+1
    echo  "${j}000 ${TBUBBLE[$i]} ${TSELECT[$i]} ${TINSERT[$i]}" >> dados_ordenados.dat
done
rm -r ./tmp
