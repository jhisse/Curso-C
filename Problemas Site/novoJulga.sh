#!/bin/bash

# Adriano Cruz

# Parametros
# $1 nome do programa original 
#

PROGNAME=$1
#EXEMPLO -> PROGNAME=teste.c

EXTNS="c"


#TIRA A EXTENSAO DO NOME DO PROGRAMA
PROBNAME=`echo "$PROGNAME" | cut -d. -f1`
#EXEMPLO -> PROBNAME=teste

SRCDIR="$PROBNAME"
#EXEMPLO -> SRCDIR=teste

INFILE="./$SRCDIR/$PROBNAME.in"
#EXEMPLO -> INFILE=./teste/teste.in

SOLFILE="./$SRCDIR/$PROBNAME.sol"
#EXEMPLO -> SOLFILE=./teste/teste.sol

#echo SOLFILE = $SOLFILE

OUTFILE="./$SRCDIR/$PROBNAME.out"
#EXEMPLO -> OUTFILE=./teste/teste.out

#echo OUTFILE = $OUTFILE


SOURCE="./$SRCDIR/$PROBNAME.$EXTNS"
#EXEMPLO -> SOURCE=./teste/teste.c

SRCPREFIX="./$SRCDIR/$PROBNAME"
#EXEMPLO -> ./teste/teste

CHROOTDIR="$PWD/$SRCDIR"

ACCEPTED=0
PRESNTERROR=1
WRONGANSWER=2
TIMELIMIT=3
RTERROR=4
CMPLERROR=5
FSIZEEXCEEDED=6
OTHERERROR=10


CC=gcc
CFLAGS="-g -Wall -D_GNU_SOURCE=1 -D_REENTRANT"

echo -e "\n*** Compilando " $PROGNAME
$CC -o "$SRCPREFIX" "$SOURCE" $CFLAGS 2>/dev/null
if [ $? != 0 ]; then
	echo "*** Erro de Compilacao"
	exit $CMPLERROR
fi

res=$ACCEPTED

PROBTIMELIMIT=3
DISKLIMIT=4096
MEMORYLIMIT=65534


echo -e "\n*** Executando $PROGNAME (time limit: $PROBTIMELIMIT s)"


#ATRIBUI VALORES LIMITES DO SISTEMA
ulimit -S -t $PROBTIMELIMIT
ulimit -S -f $DISKLIMIT
ulimit -S -v $MEMORYLIMIT


time "$SRCPREFIX" < "$INFILE" > "$OUTFILE"
resultado=$?

#echo resultado = $resultado

#if [ $resultado = 3 ]; then


M_SIGXCPU=152
if [ $resultado -eq $M_SIGXCPU ]; then
	echo -e "\n*** Tempo Limite Esgotado.\n"
	exit $TIMELIMIT
fi

M_SIGXFSZ=153
if [ $resultado -eq $M_SIGXFSZ ]; then
	echo -e "\n*** Tamanho saida excedido.\n"
	exit $FSIZEEXCEEDED
fi

if [ $resultado = 2 ]; then
	echo -e "\n*** Erro de Execucao\n"
	exit $RTERROR
fi

if [ $resultado -gt 3 ]; then
	echo -e "\n*** Erro de Execucao\n"
	exit $RTERROR
fi


diff -q $SOLFILE $OUTFILE >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
	echo -e "\n*** Aceito\n"
	exit $ACCEPTED
fi

diff -q -b $SOLFILE $OUTFILE >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
	echo -e "\n*** Formato Incorreto\n"
	exit $PRESNTERROR
fi
diff -q -b -B $SOLFILE $OUTFILE >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
	echo -e "\n*** Formato Incorreto\n"
	exit $PRESNTERROR
fi
diff -q -i -b -B $SOLFILE $OUTFILE >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
	echo -e "\n*** Formato Incorreto\n"
	exit $PRESNTERROR
fi
diff -q -b -B -w $SOLFILE $OUTFILE >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
	echo -e "\n*** Formato Incorreto\n"
	exit $PRESNTERROR
fi
diff -q -i -b -B -w $SOLFILE $OUTFILE >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
	echo -e "\n*** Formato Incorreto\n"
	exit $PRESNTERROR
fi

echo -e "\n*** Resposta Incorreta\n"
exit $WRONGANSWER
