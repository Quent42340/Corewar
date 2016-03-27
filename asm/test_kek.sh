#!/bin/bash
#
# A script to test the parser asm
# Made with <3 by grange_c@epitech.eu
#

./asm_reference kek
mv kek.cor kek.cor1 > /dev/null 2> /dev/null
./asm kek > /dev/null 2> /dev/null
mv kek.cor kek.cor2

diff kek.cor1 kek.cor2

if [ $? == 0 ]
then
    echo -e "[OK]"
else
    echo -e "[NOT OK]"
fi
