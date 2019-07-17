list of functions:
   thread1_0(param: __cs_param_thread1_arg)  call count 0
   thread2_0(param: __cs_param_thread2_arg)  call count 0
   thread3_0(param: __cs_param_thread3_arg)  call count 0
   main(param: )  call count 0

list of thread functions:
   thread1_0  call count 1
   thread2_0  call count 1
   thread3_0  call count 1

parameters for main():
   (no params)

Variables:
   (global)
      id0  'm'  
         type '__cs_mutex_t'  kind 'g'  arity '0'  
         size '[]'  
         ref '[160, 162, 169, 171, 178, 187, 194]'  
         deref '[]'  
         occurs '[160, 162, 169, 171, 178, 187, 194]'  
      id1  'data'  
         type 'int'  kind 'g'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[161, 170, 181]'  
   thread1_0
      id2  '__cs_param_thread1_arg'  
         type 'void *'  kind 'p'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[]'  
   thread2_0
      id3  '__cs_param_thread2_arg'  
         type 'void *'  kind 'p'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[]'  
   thread3_0
      id4  '__cs_param_thread3_arg'  
         type 'void *'  kind 'p'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[]'  
      id5  '__cs_local_thread3___cs_tmp_if_cond_0'  
         type 'static _Bool'  kind 'l'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[181, 182]'  
   main
      id6  '__cs_local_main_t1'  
         type 'static __cs_t'  kind 'l'  arity '0'  
         size '[]'  
         ref '[201]'  
         deref '[]'  
         occurs '[201, 204]'  
      id7  '__cs_local_main_t2'  
         type 'static __cs_t'  kind 'l'  arity '0'  
         size '[]'  
         ref '[202]'  
         deref '[]'  
         occurs '[202, 205]'  
      id8  '__cs_local_main_t3'  
         type 'static __cs_t'  kind 'l'  arity '0'  
         size '[]'  
         ref '[203]'  
         deref '[]'  
         occurs '[203, 206]'  

Fields:

Typedefs:

Pointer variables:
   (global)
   thread1_0
       var '__cs_param_thread1_arg'   type 'void *'   kind 'p'   arity '0'   size '[]'   
   thread2_0
       var '__cs_param_thread2_arg'   type 'void *'   kind 'p'   arity '0'   size '[]'   
   thread3_0
       var '__cs_param_thread3_arg'   type 'void *'   kind 'p'   arity '0'   size '[]'   
   main

Function blocks:
function 'thread1_0' ----------------------------------:
void *thread1_0(void *__cs_param_thread1_arg)
{
    __cs_mutex_lock(&m);
    data++;
    __cs_mutex_unlock(&m);
    __exit_thread1:
    ;

    __cs_exit(0);
}


void *__cs_param_thread1_arg
void *
function 'thread2_0' ----------------------------------:
void *thread2_0(void *__cs_param_thread2_arg)
{
    __cs_mutex_lock(&m);
    data += 2;
    __cs_mutex_unlock(&m);
    __exit_thread2:
    ;

    __cs_exit(0);
}


void *__cs_param_thread2_arg
void *
function 'thread3_0' ----------------------------------:
void *thread3_0(void *__cs_param_thread3_arg)
{
    __cs_mutex_lock(&m);
    ;
    static _Bool __cs_local_thread3___cs_tmp_if_cond_0;
    __cs_local_thread3___cs_tmp_if_cond_0 = data >= 3;
    if (__cs_local_thread3___cs_tmp_if_cond_0)
    {
        __CSEQ_assert(0);
        ;
    }

    __cs_mutex_unlock(&m);
    __exit_thread3:
    ;

    __cs_exit(0);
}


void *__cs_param_thread3_arg
void *
function 'main' ----------------------------------:
int main()
{
    __cs_mutex_init(&m, 0);
    static __cs_t __cs_local_main_t1;
    ;
    static __cs_t __cs_local_main_t2;
    ;
    static __cs_t __cs_local_main_t3;
    ;
    __cs_create(&__cs_local_main_t1, 0, thread1_0, 0);
    __cs_create(&__cs_local_main_t2, 0, thread2_0, 0);
    __cs_create(&__cs_local_main_t3, 0, thread3_0, 0);
    __cs_join(__cs_local_main_t1, 0);
    __cs_join(__cs_local_main_t2, 0);
    __cs_join(__cs_local_main_t3, 0);
    goto __exit_main;
    __exit_main:
    ;

    __cs_exit(0);
}



int
Last statement, by function:
function: thread1_0   stmt:     __cs_exit(0);

function: thread2_0   stmt:     __cs_exit(0);

function: thread3_0   stmt:     __cs_exit(0);

function: main   stmt:     __cs_exit(0);


All symbols (new symbol table - work in progress):
   (0, '__VERIFIER_error')  
   (1, 'm')  
   (2, 'data')  
   (3, 'thread1_0')  
   (4, '__cs_param_thread1_arg')  
   (5, 'thread2_0')  
   (6, '__cs_param_thread2_arg')  
   (7, 'thread3_0')  
   (8, '__cs_param_thread3_arg')  
   (9, '__cs_local_thread3___cs_tmp_if_cond_0')  
   (10, 'main')  
   (11, '__cs_local_main_t1')  
   (12, '__cs_local_main_t2')  
   (13, '__cs_local_main_t3')  
