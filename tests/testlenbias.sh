#!bin/bash

#FRONTIERRA TEST for LENGTH BIAS SETTINGS
# TO BE RUN FROM THE 'tests' subdirectory
# Just do $ sh testlenbias.sh

#clear out any previous tests:
rm -r testlenbias

#create the execution directory
mkdir testlenbias
cd testlenbias

#copy the data we need to gb0
cp ../../config/tiemut_table.mtx . 
cp ../../config/testlenbias_in .
cp -r ../../config/gb0 gb_test1

#generate the input data:
cd gb_test1
../../../src/arg c 0080.gen 0080aaa.tie

#now run tierra (test1_in just runs 10 million instructions - takes about 15 seconds)
cd ../
../../src/tierra testlenbias_in

#TODO: need to create some diagnostics here...

