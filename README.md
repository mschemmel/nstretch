# nstretch
You're curious about the missing part of your genome? You need to know where the Ns are!
So far, only fasta files are supported.

## Usage
```bash
# input
./nstretch genome.fa                    # file
cat genome.fa | ./nstretch              # stdin
gunzip -c genome.fa.gz | ./nstretch     # stdin using gzipped data
```

## Output
The output is given in bed format consisting of `chr`, `start` and `end`.
|chr|start|end|
|---|---|---|
|Chr1|12|34|
|Chr2|13478|13582|
|...|...|...|...|


