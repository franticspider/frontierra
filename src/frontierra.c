#include <stdlib.h>
#include <stdio.h>

/*#define TIERRA*/
//#define PLOIDY 1

#include "license.h"
#include "tierra.h"
#include "globals.h"

#include "frontierra.h"

extern struct s_swt *mut_table;


int intfrombinary(void){
	int bp = pow(2,InstBitNum);
	return bp;
}




struct s_swt  * load_mut(char *fn){
//int ** read_mut(const int N, char *fn){

	/*WARNING: This will only work for opcode sets of size 64!*/

	FILE *fp;
	int i,j,inN;
	char inst[70];
	struct s_swt *s;

	s = (struct s_swt *) malloc(sizeof(struct s_swt));

	/*reset the popdy file*/
	fp = fopen("tiepopdy.dat","w");
	fclose(fp);

	fp = fopen(fn,"r");

	if(fp==NULL){
		printf("error opening %s\n",fn);
	}


	fscanf(fp,"%d\n",&inN);

	if(inN!=32){
		printf("ERROR - input file has matrix size %d\n",inN);
		exit(-1);
	}

	s->N = inN;


	s->adj = (int**) malloc(s->N*sizeof(int*));
	for(i=0;i<s->N;i++){
		s->adj[i]=(int*)malloc(s->N*sizeof(int));
		fgets(inst,s->N+5,fp);
		for(j=0;j<s->N;j++){
			s->adj[i][j] = inst[j]-'0';
		}
	}

	fclose(fp);
	return s;

}
/*Untangling HpInst:
Instruction Hp HpInst
Hp *
Inst Instruction
unsigned char Inst;

therfore, 
HpInst == unsigned char *
*/


unsigned char sw_mut(unsigned char s){

	int j,in= s,mut;

	/* this is the official way of doing it: 
	s[0] ^= (1 << (tirand() % (I32s) InstBitNum));
	*/
	int count=0,muts,m;
	for(j=0;j<mut_table->N;j++)
		if(mut_table->adj[in][j])
			count++;

	muts = floor(count*(rand()/RAND_MAX));

	j=-1;m=-1;
	do{
		j++;
		if(mut_table->adj[in][j])
			m++;
	}while(m<muts);
/* for debugging (but can cause segfaults?):
	printf("mutating from %d to %d\ncount=%d\tmuts = %d\nrow=",in,j,count,muts);
	for(j=0;j<mut_table->N;j++)
		printf("%d",mut_table->adj[in][j]);
	printf("\n");
*/
	s=j;

	return s;
}






/*
 * FilePopStats(lsl, lsiz_sl)
 *
 * uses data in the rambank to take a snapshot of the population
 * AverageSize = (tNumCells) ? (AverageSize / tNumCells) : 0;
 *
 * Returns: void
 */
/*
void FilePopStats(lsl, lsiz_sl)
SList Fp Fp lsl;
I32s lsiz_sl;
*/
void FilePopStats(SList Fp Fp lsl, I32s lsiz_sl)
//void FilePopStats(lsl, lsiz_sl)
//SList Fp Fp lsl;
//I32s lsiz_sl;
{   I32s si, gi, pop;
    Pgl pgl;
	const int minpop = 0;//min pop size to bother reporting

    /*
     * sjh stuff
     * Assume the shell script resets these files...
     * */
    FILE *fp, *errf;
    fp = fopen("tiepopdy.dat","a");
    errf = fopen("tiepopdy.err","a");

    for(si=lsiz_sl-1;si>=0;si--){   /* for all the sizes in the soup */
    	if(lsl[si]){   				/* if a size has a record */
    		if(lsl[si]->num_c){     /* if a size has a current count */
    			if(GeneBnker){      /* if we are recording in the gene bank */

    				for(gi=lsl[si]->a_num-1;gi>=0;gi--){	/* for every gene in this size class */
    					if(!TNULL(pgl=lsl[si]->g[gi])){		/* if we can get a pointer to the gene class*/
							if(pgl->pop>minpop){	/*We aren't interested in plotting small numbers of genomes */
	    						fprintf(fp,"%d,%02d%s,%d\n", InstExe.m,pgl->gen.size,pgl->gen.label,pgl->pop);
							}
                        }
                    }
                }
            }
        }
    }
    fclose(fp);
    fclose(errf);
}


