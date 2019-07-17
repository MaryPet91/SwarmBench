list of functions:
   thread1(param: arg)  call count 0
   thread2(param: arg)  call count 0
   thread3(param: arg)  call count 0
   main(param: )  call count 0

list of thread functions:
   thread1  call count 1
   thread2  call count 1
   thread3  call count 1

parameters for main():
   (no params)

Variables:
   (global)
      id0  'm'  
         type '__cs_mutex_t'  kind 'g'  arity '0'  
         size '[]'  
         ref '[160, 162, 166, 168, 172, 179, 183]'  
         deref '[]'  
         occurs '[160, 162, 166, 168, 172, 179, 183]'  
      id1  'data'  
         type 'int'  kind 'g'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[161, 167, 173]'  
   thread1
      id2  'arg'  
         type 'void *'  kind 'p'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[]'  
   thread2
      id3  'arg'  
         type 'void *'  kind 'p'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[]'  
   thread3
      id4  'arg'  
         type 'void *'  kind 'p'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[]'  
      id5  '__cs_tmp_if_cond_0'  
         type '_Bool'  kind 'l'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[173, 174]'  
   main
      id6  't1'  
         type '__cs_t'  kind 'l'  arity '0'  
         size '[]'  
         ref '[187]'  
         deref '[]'  
         occurs '[187, 190]'  
      id7  't2'  
         type '__cs_t'  kind 'l'  arity '0'  
         size '[]'  
         ref '[188]'  
         deref '[]'  
         occurs '[188, 191]'  
      id8  't3'  
         type '__cs_t'  kind 'l'  arity '0'  
         size '[]'  
         ref '[189]'  
         deref '[]'  
         occurs '[189, 192]'  

Fields:

Typedefs:

Pointer variables:
   (global)
   thread1
       var 'arg'   type 'void *'   kind 'p'   arity '0'   size '[]'   
   thread2
       var 'arg'   type 'void *'   kind 'p'   arity '0'   size '[]'   
   thread3
       var 'arg'   type 'void *'   kind 'p'   arity '0'   size '[]'   
   main

Function blocks:
function 'thread1' ----------------------------------:
void *thread1(void *arg)
{
    __cs_mutex_lock(&m);
    data++;
    __cs_mutex_unlock(&m);
}


void *arg
void *
function 'thread2' ----------------------------------:
void *thread2(void *arg)
{
    __cs_mutex_lock(&m);
    data += 2;
    __cs_mutex_unlock(&m);
}


void *arg
void *
function 'thread3' ----------------------------------:
void *thread3(void *arg)
{
    __cs_mutex_lock(&m);
    ;
    _Bool __cs_tmp_if_cond_0;
    __cs_tmp_if_cond_0 = data >= 3;
    if (__cs_tmp_if_cond_0)
    {
        __CSEQ_assert(0);
        ;
    }

    __cs_mutex_unlock(&m);
}


void *arg
void *
function 'main' ----------------------------------:
int main()
{
    __cs_mutex_init(&m, 0);
    __cs_t t1;
    __cs_t t2;
    __cs_t t3;
    __cs_create(&t1, 0, thread1, 0);
    __cs_create(&t2, 0, thread2, 0);
    __cs_create(&t3, 0, thread3, 0);
    __cs_join(t1, 0);
    __cs_join(t2, 0);
    __cs_join(t3, 0);
    return 0;
}



int
Last statement, by function:
function: thread1   stmt:     __cs_mutex_unlock(&m);

function: thread2   stmt:     __cs_mutex_unlock(&m);

function: thread3   stmt:     __cs_mutex_unlock(&m);

function: main   stmt:     return 0;


All symbols (new symbol table - work in progress):
   (0, '__VERIFIER_error')  
   (1, 'm')  
   (2, 'data')  
   (3, 'thread1')  
   (4, 'arg')  
   (5, 'thread2')  
   (6, 'arg')  
   (7, 'thread3')  
   (8, 'arg')  
   (9, '__cs_tmp_if_cond_0')  
   (10, 'main')  
   (11, 't1')  
   (12, 't2')  
   (13, 't3')  
