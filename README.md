# frontierra
Coder-friendly version of tierra 6.02 for new alife experiments

#versions

v7.0 is the version that copies tierra 6.02, but has Mathias Rav's patch applied

v7.1 as above, but with added creation of popdy analysis files

v7.2 as 7.1 but with "debiasing" modifications (paper submitted)

#install notes

Tierra installs reasonably easily on Ubuntu 12 to 14:

`make clean`
`./configure`
`make`

should do the trick. This will build an executable called `tierra`. Note that you may get errors during make, but these are related to some of the analysis tools: `probe`, `soupupdtrc` and `threadtree` may give errors. If you need these, the errors can (sometimes) be fixed by installing some additional libraries:

`sudo apt-get install xorg-dev xutils-dev`

On some machines, you can get 'nested too deeply' errors on compilation. This is something to do with the bsd libraries /usr/include/bsd , although we haven't gotten to the bottom of this. The issue has been fixed at line 73 of Makefile.in with the following change: 

```
#COMCFLAGS+=-I/usr/include/bsd -Wall -Wstrict-prototypes -Wno-unused
#
COMCFLAGS+= -Wall -Wstrict-prototypes -Wno-unused
```


