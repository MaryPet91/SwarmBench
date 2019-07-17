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
         type 'pthread_mutex_t'  kind 'g'  arity '0'  
         size '[]'  
         ref '[183, 185, 191, 193, 199, 204, 210]'  
         deref '[]'  
         occurs '[183, 185, 191, 193, 199, 204, 210]'  
      id1  'data'  
         type 'int'  kind 'g'  arity '0'  
         size '[]'  
         ref '[]'  
         deref '[]'  
         occurs '[184, 192, 200]'  
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
   main
      id5  't1'  
         type 'pthread_t'  kind 'l'  arity '0'  
         size '[]'  
         ref '[214]'  
         deref '[]'  
         occurs '[214, 218]'  
      id6  't2'  
         type 'pthread_t'  kind 'l'  arity '0'  
         size '[]'  
         ref '[215]'  
         deref '[]'  
         occurs '[215, 219]'  
      id7  't3'  
         type 'pthread_t'  kind 'l'  arity '0'  
         size '[]'  
         ref '[216]'  
         deref '[]'  
         occurs '[216, 220]'  

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
    pthread_mutex_lock(&m);
    data++;
    pthread_mutex_unlock(&m);
}


void *arg
void *
function 'thread2' ----------------------------------:
void *thread2(void *arg)
{
    pthread_mutex_lock(&m);
    data += 2;
    pthread_mutex_unlock(&m);
}


void *arg
void *
function 'thread3' ----------------------------------:
void *thread3(void *arg)
{
    pthread_mutex_lock(&m);
    if (data >= 3)
    {
        ERROR:
        __VERIFIER_error();

        ;
    }

    pthread_mutex_unlock(&m);
}


void *arg
void *
function 'main' ----------------------------------:
int main()
{
    pthread_mutex_init(&m, 0);
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_create(&t1, 0, thread1, 0);
    pthread_create(&t2, 0, thread2, 0);
    pthread_create(&t3, 0, thread3, 0);
    pthread_join(t1, 0);
    pthread_join(t2, 0);
    pthread_join(t3, 0);
    return 0;
}



int
Last statement, by function:
function: thread1   stmt:     pthread_mutex_unlock(&m);

function: thread2   stmt:     pthread_mutex_unlock(&m);

function: thread3   stmt:     pthread_mutex_unlock(&m);

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
   (9, 'main')  
   (10, 't1')  
   (11, 't2')  
   (12, 't3')  
