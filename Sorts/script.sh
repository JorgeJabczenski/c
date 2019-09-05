#!/bin/bash

echo "tam bolha selecao insercao" > dados_nao_ordenados.dat

mkdir tmp

for ((i=1000; i <= 50000; i+=1000))
do
	command time -o ./tmp/bubble    -a -f "%U" ./Bubble_Sort/ebubble       < ./entradas/nao_ordenadas/$i.txt
	command time -o ./tmp/insertion -a -f "%U" ./Insertion_Sort/einsertion < ./entradas/nao_ordenadas/$i.txt
	command time -o ./tmp/selection -a -f "%U" ./Selection_Sort/eselection < ./entradas/nao_ordenadas/$i.txt

done 

mapfile -t TBUBBLE < ./tmp/bubble
mapfile -t TSELECT < ./tmp/selection
mapfile -t TINSERT < ./tmp/insertion

for i in {0..49}
do
    echo  "${i+1}000 ${TBUBBLE[$i]} ${TSELECT[$i]} ${TINSERT[$i]}" >> dados_nao_ordenados.dat
done