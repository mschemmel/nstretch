#!/bin/bash
# run ./generate_fasta.sh > ./test_genome/genome.fa
for i in {1..5}; do
	echo ">chr$i" 
	tr -dc ATGC </dev/urandom | head -c 50 
	echo ""
done

