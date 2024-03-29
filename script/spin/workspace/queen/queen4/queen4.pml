// Generated by MODEX Version 2.10 - 25 June 2016
// dom  3 feb 2019, 12.49.34, CET from queen1.c

# 1 "_modex_.drv"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "_modex_.drv"
# 1 "_modex_.h" 1
int par0_is_safe;
int par1_is_safe;
int par2_is_safe;
int par3_is_safe;
 c_state "long res_p_is_safe" "Global"
bool lck_p_is_safe_ret;
bool lck_p_is_safe;
int par0_nqueens;
int par1_nqueens;
 c_state "long res_p_nqueens" "Global"
bool lck_p_nqueens_ret;
bool lck_p_nqueens;
 c_state "void  * par0_start_thread" "Global"
 c_state "long res_p_start_thread" "Global"
bool lck_p_start_thread_ret;
bool lck_p_start_thread;
 c_state "long res_p_main" "Global"
bool lck_p_main_ret;
bool lck_p_main;
 c_state "int  * solutions" "Global"
 c_state "int  ** queen_on" "Global"
int nq;
int nthreads;
chan ret_p_is_safe = [1] of { pid };
chan exc_cll_p_is_safe = [0] of { pid };
chan req_cll_p_is_safe = [1] of { pid };
chan ret_p_nqueens = [1] of { pid };
chan exc_cll_p_nqueens = [0] of { pid };
chan req_cll_p_nqueens = [1] of { pid };
chan ret_p_start_thread = [1] of { pid };
chan exc_cll_p_start_thread = [0] of { pid };
chan req_cll_p_start_thread = [1] of { pid };
chan ret_p_main = [1] of { pid };
chan exc_cll_p_main = [0] of { pid };
chan req_cll_p_main = [1] of { pid };
 c_state "void  * arg" "Local p_start_thread"
 c_state "int  * thr_num" "Local p_main"
 c_state "int  * thr_ids" "Local p_main"
 c_state "char  ** argv" "Local p_main"
 c_state "char spin_heap[256]" "Global"
 c_state "int  spin_heap_n" "Global"
 c_code {
  extern void (*Uerror)(char *);
  char *
  spin_malloc(int n)
  { char *spin_heap_ptr = &(now.spin_heap[now.spin_heap_n]);
   if (now.spin_heap_n + n >= sizeof(now.spin_heap))
   { Uerror("spin_heap limit reached");
   }
   now.spin_heap_n += n;
   return spin_heap_ptr;
  }
  void
  spin_free(char *unused)
  { unused;
  }
 }
# 2 "_modex_.drv" 2
# 1 "_modex_all.pml" 1
active proctype p_main( )
{
# 1 "_modex_all_0.h" 1
int i;
int j;
int total;
pid lck_id;
int argc;
# 9 "_modex_all.pml" 2
# 23 "_modex_all.pml"
    c_code { now.nq=16; };
    c_code { now.nthreads=16; };
    c_code { Pp_main->thr_num=((int *)spin_malloc((int) (now.nthreads*sizeof(int )))); };
    c_code { Pp_main->thr_ids=((int *)spin_malloc((int) (now.nthreads*sizeof(int )))); };
    c_code { now.queen_on=((int **)spin_malloc((int) (now.nq*sizeof(int *)))); };
    c_code { now.solutions=((int *)spin_malloc((int) (now.nq*sizeof(int )))); };
    if
    :: c_expr { ((((Pp_main->thr_num==NULL)||(Pp_main->thr_ids==NULL))||(now.queen_on==NULL))||(now.solutions==NULL)) };
        printf("line 126: F: exit(EXIT_FAILURE)\n");
    :: c_expr { !((((Pp_main->thr_num==NULL)||(Pp_main->thr_ids==NULL))||(now.queen_on==NULL))||(now.solutions==NULL)) };
 fi;
    c_code { Pp_main->i=0; };
L_0:
    do
    :: c_expr { (Pp_main->i<now.nq) };
        c_code { now.queen_on[Pp_main->i]=((int *)spin_malloc((int) (now.nq*sizeof(int )))); };
        if
        :: c_expr { (now.queen_on[Pp_main->i]==NULL) };
            printf("line 136: F: exit(EXIT_FAILURE)\n");
        :: c_expr { !(now.queen_on[Pp_main->i]==NULL) };
 fi;
        c_code { Pp_main->j=0; };
L_1:
        do
        :: c_expr { (Pp_main->j<now.nq) };
            c_code { now.queen_on[Pp_main->i][Pp_main->j]=0; };
c_code { Pp_main->j++; };
    goto L_1;
c_code { Pp_main->j++; };
        :: c_expr { !(Pp_main->j<now.nq) }; -> break
        od;
c_code { Pp_main->i++; };
    goto L_0;
c_code { Pp_main->i++; };
    :: c_expr { !(Pp_main->i<now.nq) }; -> break
    od;
    c_code { Pp_main->i=0; };
L_2:
    do
    :: c_expr { (Pp_main->i<now.nthreads) };
        c_code { Pp_main->thr_num[Pp_main->i]=Pp_main->i; };
         atomic {
  lck_p_start_thread == 0 && empty(req_cll_p_start_thread) -> req_cll_p_start_thread!_pid;
  exc_cll_p_start_thread!_pid;
 }
c_code { Pp_main->i++; };
    goto L_2;
c_code { Pp_main->i++; };
    :: c_expr { !(Pp_main->i<now.nthreads) }; -> break
    od;
    c_code { Pp_main->total=0; };
    c_code { Pp_main->i=0; };
L_3:
    do
    :: c_expr { (Pp_main->i<now.nthreads) };
         ret_p_start_thread?eval(_pid);
 c_code { now.lck_p_start_thread_ret = 0; };
        c_code { Pp_main->total+=now.solutions[Pp_main->i]; };
c_code { Pp_main->i++; };
    goto L_3;
c_code { Pp_main->i++; };
    :: c_expr { !(Pp_main->i<now.nthreads) }; -> break
    od;
    c_code { Pp_main->i=0; };
L_4:
    do
    :: c_expr { (Pp_main->i<now.nq) };
        c_code { spin_free((char *) now.queen_on[Pp_main->i]); };
c_code { Pp_main->i++; };
    goto L_4;
c_code { Pp_main->i++; };
    :: c_expr { !(Pp_main->i<now.nq) }; -> break
    od;
    c_code { spin_free((char *) now.queen_on); };
    c_code { spin_free((char *) now.solutions); };
    c_code { spin_free((char *) Pp_main->thr_num); };
    c_code { spin_free((char *) Pp_main->thr_ids); };
     atomic { !lck_p_main_ret -> lck_p_main_ret = 1 };
 c_code { now.res_p_main = (long) EXIT_SUCCESS; }; goto Return;
Return: skip;
# 146 "_modex_all.pml"
}
active proctype p_start_thread( )
{
# 1 "_modex_all_1.h" 1
int thr_index;
pid lck_id;
# 152 "_modex_all.pml" 2
endRestart:
 atomic {
 nempty(req_cll_p_start_thread) && !lck_p_start_thread -> lck_p_start_thread = 1;
 req_cll_p_start_thread?lck_id; exc_cll_p_start_thread?eval(lck_id);
 c_code { Pp_start_thread->arg = now.par0_start_thread; };
 lck_p_start_thread = 0;
 };
    c_code [((int *)Pp_start_thread->arg)] { Pp_start_thread->thr_index=(*(((int *)Pp_start_thread->arg))); };
    c_code { now.solutions[Pp_start_thread->thr_index]=0; };
 atomic {
  lck_p_nqueens == 0 && empty(req_cll_p_nqueens) -> req_cll_p_nqueens!_pid;
  c_code { now.par0_nqueens = 0; };
  c_code { now.par1_nqueens = Pp_start_thread->thr_index; };
  exc_cll_p_nqueens!_pid;
 }
 ret_p_nqueens?eval(_pid);
 c_code { ; now.lck_p_nqueens_ret = 0; };
     goto Return;
Return: skip;
 ret_p_start_thread!lck_id;
 goto endRestart
# 191 "_modex_all.pml"
}
active proctype p_nqueens( )
{
# 1 "_modex_all_2.h" 1
int i;
int j;
int start;
int end;
pid lck_id;
int thr_index;
int col;
# 197 "_modex_all.pml" 2
endRestart:
 atomic {
 nempty(req_cll_p_nqueens) && !lck_p_nqueens -> lck_p_nqueens = 1;
 req_cll_p_nqueens?lck_id; exc_cll_p_nqueens?eval(lck_id);
 c_code { Pp_nqueens->thr_index = now.par1_nqueens; };
 c_code { Pp_nqueens->col = now.par0_nqueens; };
 lck_p_nqueens = 0;
 };
    if
    :: c_expr { (Pp_nqueens->col>0) };
        c_code { Pp_nqueens->start=0; };
    :: c_expr { !(Pp_nqueens->col>0) };
      c_code { Pp_nqueens->start=(Pp_nqueens->thr_index*(now.nq/now.nthreads)); };
 fi;
    if
    :: c_expr { ((Pp_nqueens->col>0)||(Pp_nqueens->thr_index==(now.nthreads-1))) };
        c_code { Pp_nqueens->end=(now.nq-1); };
    :: c_expr { !((Pp_nqueens->col>0)||(Pp_nqueens->thr_index==(now.nthreads-1))) };
      c_code { Pp_nqueens->end=(((Pp_nqueens->thr_index+1)*(now.nq/now.nthreads))-1); };
 fi;
    if
    :: c_expr { (Pp_nqueens->col==now.nq) };
c_code { now.solutions[Pp_nqueens->thr_index]++; };
    :: c_expr { !(Pp_nqueens->col==now.nq) };
 fi;
    c_code { Pp_nqueens->i=Pp_nqueens->start; };
L_5:
    do
    :: c_expr { (Pp_nqueens->i<=Pp_nqueens->end) };
        c_code { Pp_nqueens->j=0; };
L_6:
 atomic {
  lck_p_is_safe == 0 && empty(req_cll_p_is_safe) -> req_cll_p_is_safe!_pid;
  c_code { now.par0_is_safe = Pp_nqueens->i; };
  c_code { now.par1_is_safe = Pp_nqueens->j; };
  c_code { now.par2_is_safe = Pp_nqueens->col; };
  c_code { now.par3_is_safe = Pp_nqueens->thr_index; };
  exc_cll_p_is_safe!_pid;
 }
 ret_p_is_safe?eval(_pid);
  lck_p_is_safe_ret = 0;
        do
        :: c_expr { ((Pp_nqueens->j<Pp_nqueens->col)&& now.res_p_is_safe) };
c_code { Pp_nqueens->j++; };
    goto L_6;
c_code { Pp_nqueens->j++; };
        :: c_expr { !((Pp_nqueens->j<Pp_nqueens->col)&& now.res_p_is_safe) }; -> break
        od;
        if
        :: c_expr { (Pp_nqueens->j<Pp_nqueens->col) };
            c_code { Pp_nqueens->i++; };
            goto L_5;
        :: c_expr { !(Pp_nqueens->j<Pp_nqueens->col) };
 fi;
        c_code { now.queen_on[Pp_nqueens->thr_index][Pp_nqueens->col]=Pp_nqueens->i; };
 atomic {
  lck_p_nqueens == 0 && empty(req_cll_p_nqueens) -> req_cll_p_nqueens!_pid;
  c_code { now.par0_nqueens = (Pp_nqueens->col+1); };
  c_code { now.par1_nqueens = Pp_nqueens->thr_index; };
  exc_cll_p_nqueens!_pid;
 }
 ret_p_nqueens?eval(_pid);
 c_code { ; now.lck_p_nqueens_ret = 0; };
c_code { Pp_nqueens->i++; };
    goto L_5;
c_code { Pp_nqueens->i++; };
    :: c_expr { !(Pp_nqueens->i<=Pp_nqueens->end) }; -> break
    od;
Return: skip;
 ret_p_nqueens!lck_id;
 goto endRestart
# 305 "_modex_all.pml"
}
active proctype p_is_safe( )
{
# 1 "_modex_all_3.h" 1
pid lck_id;
int thr_index;
int col;
int j;
int i;
# 311 "_modex_all.pml" 2
endRestart:
 atomic {
 nempty(req_cll_p_is_safe) && !lck_p_is_safe -> lck_p_is_safe = 1;
 req_cll_p_is_safe?lck_id; exc_cll_p_is_safe?eval(lck_id);
 c_code { Pp_is_safe->thr_index = now.par3_is_safe; };
 c_code { Pp_is_safe->col = now.par2_is_safe; };
 c_code { Pp_is_safe->j = now.par1_is_safe; };
 c_code { Pp_is_safe->i = now.par0_is_safe; };
 lck_p_is_safe = 0;
 };
    if
    :: c_expr { (now.queen_on[Pp_is_safe->thr_index][Pp_is_safe->j]==Pp_is_safe->i) };
         atomic { !lck_p_is_safe_ret -> lck_p_is_safe_ret = 1 };
 c_code { now.res_p_is_safe = (long) 0; }; goto Return;
    :: c_expr { !(now.queen_on[Pp_is_safe->thr_index][Pp_is_safe->j]==Pp_is_safe->i) };
 fi;
    if
    :: c_expr { (abs((now.queen_on[Pp_is_safe->thr_index][Pp_is_safe->j]-Pp_is_safe->i))==(Pp_is_safe->col-Pp_is_safe->j)) };
         atomic { !lck_p_is_safe_ret -> lck_p_is_safe_ret = 1 };
 c_code { now.res_p_is_safe = (long) 0; }; goto Return;
    :: c_expr { !(abs((now.queen_on[Pp_is_safe->thr_index][Pp_is_safe->j]-Pp_is_safe->i))==(Pp_is_safe->col-Pp_is_safe->j)) };
 fi;
     atomic { !lck_p_is_safe_ret -> lck_p_is_safe_ret = 1 };
 c_code { now.res_p_is_safe = (long) 1; }; goto Return;
Return: skip;
 ret_p_is_safe!lck_id;
 goto endRestart
# 354 "_modex_all.pml"
}
# 2 "_modex_.drv" 2
