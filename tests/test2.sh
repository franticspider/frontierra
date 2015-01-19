#!bin/bash

#FRONTIERRA TEST 2
# TO BE RUN FROM THE 'tests' subdirectory
# Just do $ sh test2.sh

#create the execution directory
mkdir test2
cd test2

#copy the data we need to gb0
cp ../../config/tiemut_table.mtx . 
cp ../../config/test2_in .
cp -r ../../config/gb0 gb_test2

#generate the input data:
cd gb_test2
../../../src/arg c 0080.gen 0080aaa.tie

#now run tierra (test1_in just runs 10 million instructions - takes about 15 seconds)
cd ../
../../src/tierra test2_in

#TODO: need to create some diagnostics here...

