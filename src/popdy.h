/*
 * popdy.h
 *
 *  Created on: 11 Nov 2011
 *      Author: simon
 */

#ifndef POPDY_H_
#define POPDY_H_





/* structure to hold the data (from Stringmol, alignment.h) */
typedef struct s_swt{
	int 	**adj;	//adjacency matrix values
	char  	*key;	//Instruction set list
	int	N;	//Number of instructions.
} swt;




/* function to load the data from a file into a global variable */
struct s_swt * load_mut(char *fn);


/* function to do the mutation */
//HpInst sw_mut(HpInst s); /*old way*/
unsigned char sw_mut(unsigned char s);
//unsigned char mut_from_table(unsigned char inst);





/* reporting the pop dynamics */

/*void FilePopStats(lsl, lsiz_sl);
SList Fp Fp lsl;
I32s lsiz_sl;*/
void FilePopStats(SList Fp Fp lsl, I32s lsiz_sl);



#endif /* POPDY_H_ */
