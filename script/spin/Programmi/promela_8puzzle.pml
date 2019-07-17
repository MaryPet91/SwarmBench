/*
 * Impossibility of the 8-Puzzle
 *
 * NOTICE: For full statespace search, run-time option -m230000 needed, e.g.
 *         $ spin -a promela_8puzzle.pml
 *         $ gcc -o pan pan.c
 *         $ ./pan -m230000
 */

#define SPACE 0
#define NROW 3    /* height of the board */
#define NCOL 3    /* width of the board */

#define COMP ( \
    pos[0] == 1 && pos[1] == 2 && pos[2] == 3 &&  \
    pos[3] == 4 && pos[4] == 5 && pos[5] == 6 &&  \
    pos[6] == 7 && pos[7] == 8 && pos[8] == SPACE \
)


active proctype Solver() {
    
    byte pos[NROW * NCOL];
    byte sp_row = NROW - 1;
    byte sp_col = NCOL - 1;
    
    /* problem */
    atomic {
        pos[0] = 1; pos[1] = 2; pos[2] = 3; 
        pos[3] = 4; pos[4] = 5; pos[5] = 6; 
        pos[6] = 8; pos[7] = 7; pos[8] = SPACE
    };
    
    do
    ::  if
        ::  sp_row > 0 ->             /* move downward */
                atomic {
                    pos[NCOL * sp_row + sp_col] = pos[NCOL * (sp_row - 1) + sp_col];
                    pos[NCOL * (sp_row - 1) + sp_col] = SPACE;
                    sp_row--
                }
        ::  sp_row < (NROW - 1) ->    /* move upward */
                atomic {
                    pos[NCOL * sp_row + sp_col] = pos[NCOL * (sp_row + 1) + sp_col];
                    pos[NCOL * (sp_row + 1) + sp_col] = SPACE;
                    sp_row++
                }
        ::  sp_col > 0 ->             /* move to left */
                atomic {
                    pos[NCOL * sp_row + sp_col] = pos[NCOL * sp_row + (sp_col - 1)];
                    pos[NCOL * sp_row + (sp_col - 1)] = SPACE;
                    sp_col--
                }
        ::  sp_col < (NCOL - 1) ->    /* move to right */
                atomic {
                    pos[NCOL * sp_row + sp_col] = pos[NCOL * sp_row + (sp_col + 1)];
                    pos[NCOL * sp_row + (sp_col + 1)] = SPACE;
                    sp_col++
                }
        fi;
        assert (!COMP)
    od
}

