# nstretch
You're curious about the missing part of your genome? You need to know where the Ns are!

## Usage
```bash
# input
./nstretch genome.fa                    # file
cat genome.fa | ./nstretch              # stdin
gunzip -c genome.fa.gz | ./nstretch     # stdin using gzipped data
```

## Ouput
|id|start|end|range|
|---|---|---|---|
|Chr1|12|34|22|
|Chr2|13478|13582|104|
|...|...|...|...|


