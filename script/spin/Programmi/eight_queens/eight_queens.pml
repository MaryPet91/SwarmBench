#define MAX_COL 8

byte result[MAX_COL];

bool hl[MAX_COL];  /* horizon line */
bool pdl[MAX_COL * 2 - 1]; /* positive diagonal line */
bool ndl[MAX_COL * 2 - 1]; /* negative diagonal line */

inline Choose(row) {
    if
    :: row = 0
    :: row = 1
    :: row = 2
    :: row = 3
    :: row = 4
    :: row = 5
    :: row = 6
    :: row = 7
    fi
}

active proctype Queens() {

  byte col = 0; /* 0 <= col <= 7 */
  byte row;     /* 0 <= row <= 7 */

  do
  :: Choose(row);
    endhl: !hl[row];
    endpdl: !pdl[row+col];
    endndl: !ndl[row-col+7];
    hl[row] = true;
    pdl[row+col] = true;
    ndl[row-col+7] = true;
    result[col] = row
    if
    :: col == MAX_COL - 1 -> break
    :: else -> col++
    fi
  od;

  _ = result[0]

  assert(false)

}
