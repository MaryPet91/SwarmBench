// Generated by MODEX Version 2.10 - 25 June 2016
// dom  3 feb 2019, 11.34.19, CET from bubblesort1.c

# 1 "_modex_.drv"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "_modex_.drv"
# 1 "_modex_.h" 1
 c_state "long res_p_main" "Global"
bool lck_p_main_ret;
bool lck_p_main;
int par0_bubble;
 c_state "long res_p_bubble" "Global"
bool lck_p_bubble_ret;
bool lck_p_bubble;
 c_state "long res_p_v_initiate" "Global"
bool lck_p_v_initiate_ret;
bool lck_p_v_initiate;
int thread[64];
int a[64];
int swapped = 0;
chan ret_p_main = [1] of { pid };
chan exc_cll_p_main = [0] of { pid };
chan req_cll_p_main = [1] of { pid };
chan ret_p_bubble = [1] of { pid };
chan exc_cll_p_bubble = [0] of { pid };
chan req_cll_p_bubble = [1] of { pid };
chan ret_p_v_initiate = [1] of { pid };
chan exc_cll_p_v_initiate = [0] of { pid };
chan req_cll_p_v_initiate = [1] of { pid };
# 2 "_modex_.drv" 2
# 1 "_modex_all.pml" 1
active proctype p_v_initiate()
{
# 1 "_modex_all_0.h" 1
int i;
pid lck_id;
# 9 "_modex_all.pml" 2
endRestart:
 atomic {
 nempty(req_cll_p_v_initiate) && !lck_p_v_initiate -> lck_p_v_initiate = 1;
 req_cll_p_v_initiate?lck_id; exc_cll_p_v_initiate?eval(lck_id);
 lck_p_v_initiate = 0;
 };
    c_code { srand(time(NULL)); };
    c_code { Pp_v_initiate->i=0; };
L_0:
    do
    :: c_expr { (Pp_v_initiate->i<4) };
        c_code [(Pp_v_initiate->i < 4)] { now.a[Pp_v_initiate->i]=(rand()%4); };
c_code { Pp_v_initiate->i++; };
    goto L_0;
c_code { Pp_v_initiate->i++; };
    :: c_expr { !(Pp_v_initiate->i<4) }; -> break
    od;
    c_code { Pp_v_initiate->i=0; };
L_1:
    do
    :: c_expr { (Pp_v_initiate->i<4) };
c_code { Pp_v_initiate->i++; };
    goto L_1;
c_code { Pp_v_initiate->i++; };
    :: c_expr { !(Pp_v_initiate->i<4) }; -> break
    od;
Return: skip;
 ret_p_v_initiate!lck_id;
 goto endRestart
}
active proctype p_bubble( )
{
# 1 "_modex_all_1.h" 1
int tmp;
int mod;
pid lck_id;
int i;
# 65 "_modex_all.pml" 2
endRestart:
 atomic {
 nempty(req_cll_p_bubble) && !lck_p_bubble -> lck_p_bubble = 1;
 req_cll_p_bubble?lck_id; exc_cll_p_bubble?eval(lck_id);
 c_code { Pp_bubble->i = now.par0_bubble; };
 lck_p_bubble = 0;
 };
    c_code { Pp_bubble->mod=(Pp_bubble->i%2); };
    if
    :: c_expr { (Pp_bubble->i!=(4-1)) };
        if
        :: c_expr { (now.a[Pp_bubble->i]>now.a[(Pp_bubble->i+1)]) };
            c_code [(Pp_bubble->i < 4)] { Pp_bubble->tmp=now.a[Pp_bubble->i]; };
            c_code [(Pp_bubble->i < 4) && ((Pp_bubble->i+1) < 4)] { now.a[Pp_bubble->i]=now.a[(Pp_bubble->i+1)]; };
            c_code [((Pp_bubble->i+1) < 4)] { now.a[(Pp_bubble->i+1)]=Pp_bubble->tmp; };
            c_code { now.swapped=1; };
        :: c_expr { !(now.a[Pp_bubble->i]>now.a[(Pp_bubble->i+1)]) };
 fi;
    :: c_expr { !(Pp_bubble->i!=(4-1)) };
 fi;
Return: skip;
 ret_p_bubble!lck_id;
 goto endRestart
}
active proctype p_main()
{
# 1 "_modex_all_2.h" 1
int i;
int par_impar = 0;
pid lck_id;
# 108 "_modex_all.pml" 2
# 121 "_modex_all.pml"
 atomic {
  lck_p_v_initiate == 0 && empty(req_cll_p_v_initiate) -> req_cll_p_v_initiate!_pid;
  exc_cll_p_v_initiate!_pid;
 }
 ret_p_v_initiate?eval(_pid);
 c_code { ; now.lck_p_v_initiate_ret = 0; };
L_2:
    do
    :: c_code { now.swapped=0; };
    c_code { Pp_main->i=0; };
L_3:
    do
    :: c_expr { (Pp_main->i<4) };
         atomic {
  lck_p_bubble == 0 && empty(req_cll_p_bubble) -> req_cll_p_bubble!_pid;
  c_code { now.par0_bubble = Pp_main->i; };
  exc_cll_p_bubble!_pid;
 }
    c_code { Pp_main->i+=2; };
    goto L_3;
        c_code { Pp_main->i+=2; };
    :: c_expr { !(Pp_main->i<4) }; -> break
    od;
    c_code { Pp_main->i=0; };
L_4:
    do
    :: c_expr { (Pp_main->i<4) };
         ret_p_bubble?eval(_pid);
 c_code { now.lck_p_bubble_ret = 0; };
    c_code { Pp_main->i+=2; };
    goto L_4;
        c_code { Pp_main->i+=2; };
    :: c_expr { !(Pp_main->i<4) }; -> break
    od;
    c_code { now.swapped=0; };
    c_code { Pp_main->i=1; };
L_5:
    do
    :: c_expr { (Pp_main->i<4) };
         atomic {
  lck_p_bubble == 0 && empty(req_cll_p_bubble) -> req_cll_p_bubble!_pid;
  c_code { now.par0_bubble = Pp_main->i; };
  exc_cll_p_bubble!_pid;
 }
    c_code { Pp_main->i+=2; };
    goto L_5;
        c_code { Pp_main->i+=2; };
    :: c_expr { !(Pp_main->i<4) }; -> break
    od;
    c_code { Pp_main->i=1; };
L_6:
    do
    :: c_expr { (Pp_main->i<4) };
         ret_p_bubble?eval(_pid);
 c_code { now.lck_p_bubble_ret = 0; };
    c_code { Pp_main->i+=2; };
    goto L_6;
        c_code { Pp_main->i+=2; };
    :: c_expr { !(Pp_main->i<4) }; -> break
    od;
        if
        :: c_expr { (now.swapped==1) };
        :: c_expr { !(now.swapped==1) }; break
 fi
    od;
    c_code { Pp_main->i=0; };
L_7:
    do
    :: c_expr { (Pp_main->i<4) };
c_code { Pp_main->i++; };
    goto L_7;
c_code { Pp_main->i++; };
    :: c_expr { !(Pp_main->i<4) }; -> break
    od;
    printf("line  69: F: exit(0)\n");
Return: skip;
# 249 "_modex_all.pml"
}
# 2 "_modex_.drv" 2
