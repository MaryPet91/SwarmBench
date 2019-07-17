CBMC version 5.6 64-bit x86_64 linux
Parsing examples/_cs_lazy_unsafe.c
Converting
Type-checking _cs_lazy_unsafe
Generating GOTO Program
Adding CPROVER library (x86_64)
Removal of function pointers and virtual functions
Partial Inlining
Generic Property Instrumentation
Starting Bounded Model Checking
size of program expression: 591 steps
simple slicing removed 199 assignments
Generated 13 VCC(s), 13 remaining after simplification
Passing problem to propositional reduction
converting SSA
Running propositional reduction
Post-processing
Solving with MiniSAT 2.2.1 with simplifier
1593 variables, 4225 clauses
SAT checker: instance is SATISFIABLE
Runtime decision procedure: 0.006s
Building error trace

Counterexample:

State 31 file examples/_cs_lazy_unsafe.c line 378 function main thread 0
----------------------------------------------------
  __cs_tmp_t0_r0=3 (011)

State 32 file examples/_cs_lazy_unsafe.c line 379 function main thread 0
----------------------------------------------------
  __cs_pc_cs[0]=3 (0011)

State 40 file examples/_cs_lazy_unsafe.c line 344 function main_thread thread 0
----------------------------------------------------
  __cs_m=&m (00000010000000000000000000000000)

State 41 file examples/_cs_lazy_unsafe.c line 344 function main_thread thread 0
----------------------------------------------------
  __cs_val=0 (00000000000000000000000000000000)

State 42 file examples/_cs_lazy_unsafe.c line 109 function __cs_mutex_init thread 0
----------------------------------------------------
  m=-1 (11111111111111111111111111111111)

State 47 file examples/_cs_lazy_unsafe.c line 354 function main_thread thread 0
----------------------------------------------------
  __cs_new_thread_id=&__cs_local_main_t1 (00000011000000000000000000000000)

State 48 file examples/_cs_lazy_unsafe.c line 354 function main_thread thread 0
----------------------------------------------------
  __cs_attr=NULL (00000000000000000000000000000000)

State 49 file examples/_cs_lazy_unsafe.c line 354 function main_thread thread 0
----------------------------------------------------
  __cs_thread_function=thread1_0 (00000100000000000000000000000000)

State 50 file examples/_cs_lazy_unsafe.c line 354 function main_thread thread 0
----------------------------------------------------
  __cs_arg=NULL (00000000000000000000000000000000)

State 51 file examples/_cs_lazy_unsafe.c line 354 function main_thread thread 0
----------------------------------------------------
  __cs_threadID=1 (00000000000000000000000000000001)

State 53 file examples/_cs_lazy_unsafe.c line 85 function __cs_create thread 0
----------------------------------------------------
  __cs_local_main_t1=1 (00000000000000000000000000000001)

State 54 file examples/_cs_lazy_unsafe.c line 86 function __cs_create thread 0
----------------------------------------------------
  __cs_active_thread[1]=1 (1)

State 55 file examples/_cs_lazy_unsafe.c line 87 function __cs_create thread 0
----------------------------------------------------
  __cs_threadargs[1]=NULL (00000000000000000000000000000000)

State 58 file examples/_cs_lazy_unsafe.c line 88 function __cs_create thread 0
----------------------------------------------------
  __cs_message="thread spawned" (00000101000000000000000000000000)

State 65 file examples/_cs_lazy_unsafe.c line 356 function main_thread thread 0
----------------------------------------------------
  __cs_new_thread_id=&__cs_local_main_t2 (00000110000000000000000000000000)

State 66 file examples/_cs_lazy_unsafe.c line 356 function main_thread thread 0
----------------------------------------------------
  __cs_attr=NULL (00000000000000000000000000000000)

State 67 file examples/_cs_lazy_unsafe.c line 356 function main_thread thread 0
----------------------------------------------------
  __cs_thread_function=thread2_0 (00000111000000000000000000000000)

State 68 file examples/_cs_lazy_unsafe.c line 356 function main_thread thread 0
----------------------------------------------------
  __cs_arg=NULL (00000000000000000000000000000000)

State 69 file examples/_cs_lazy_unsafe.c line 356 function main_thread thread 0
----------------------------------------------------
  __cs_threadID=2 (00000000000000000000000000000010)

State 71 file examples/_cs_lazy_unsafe.c line 85 function __cs_create thread 0
----------------------------------------------------
  __cs_local_main_t2=2 (00000000000000000000000000000010)

State 72 file examples/_cs_lazy_unsafe.c line 86 function __cs_create thread 0
----------------------------------------------------
  __cs_active_thread[2]=1 (1)

State 73 file examples/_cs_lazy_unsafe.c line 87 function __cs_create thread 0
----------------------------------------------------
  __cs_threadargs[2]=NULL (00000000000000000000000000000000)

State 76 file examples/_cs_lazy_unsafe.c line 88 function __cs_create thread 0
----------------------------------------------------
  __cs_message="thread spawned" (00000101000000000000000000000000)

State 83 file examples/_cs_lazy_unsafe.c line 358 function main_thread thread 0
----------------------------------------------------
  __cs_new_thread_id=&__cs_local_main_t3 (00001000000000000000000000000000)

State 84 file examples/_cs_lazy_unsafe.c line 358 function main_thread thread 0
----------------------------------------------------
  __cs_attr=NULL (00000000000000000000000000000000)

State 85 file examples/_cs_lazy_unsafe.c line 358 function main_thread thread 0
----------------------------------------------------
  __cs_thread_function=thread3_0 (00001001000000000000000000000000)

State 86 file examples/_cs_lazy_unsafe.c line 358 function main_thread thread 0
----------------------------------------------------
  __cs_arg=NULL (00000000000000000000000000000000)

State 87 file examples/_cs_lazy_unsafe.c line 358 function main_thread thread 0
----------------------------------------------------
  __cs_threadID=3 (00000000000000000000000000000011)

State 89 file examples/_cs_lazy_unsafe.c line 85 function __cs_create thread 0
----------------------------------------------------
  __cs_local_main_t3=3 (00000000000000000000000000000011)

State 90 file examples/_cs_lazy_unsafe.c line 86 function __cs_create thread 0
----------------------------------------------------
  __cs_active_thread[3]=1 (1)

State 91 file examples/_cs_lazy_unsafe.c line 87 function __cs_create thread 0
----------------------------------------------------
  __cs_threadargs[3]=NULL (00000000000000000000000000000000)

State 94 file examples/_cs_lazy_unsafe.c line 88 function __cs_create thread 0
----------------------------------------------------
  __cs_message="thread spawned" (00000101000000000000000000000000)

State 103 file examples/_cs_lazy_unsafe.c line 372 function main_thread thread 0
----------------------------------------------------
  __cs_value_ptr=NULL (00000000000000000000000000000000)

State 104 file examples/_cs_lazy_unsafe.c line 372 function main_thread thread 0
----------------------------------------------------
  __cs_thread_index=0u (00000000000000000000000000000000)

State 105 file examples/_cs_lazy_unsafe.c line 99 function __cs_exit thread 0
----------------------------------------------------
  __cs_thread_joinargs[0]=NULL (00000000000000000000000000000000)

State 110 file examples/_cs_lazy_unsafe.c line 383 function main thread 0
----------------------------------------------------
  __cs_pc[0]=3 (011)

State 111 file examples/_cs_lazy_unsafe.c line 385 function main thread 0
----------------------------------------------------
  __cs_tmp_t1_r0=3 (11)

State 113 file examples/_cs_lazy_unsafe.c line 388 function main thread 0
----------------------------------------------------
  __cs_pc_cs[1]=3 (0011)

State 117 file examples/_cs_lazy_unsafe.c line 390 function main thread 0
----------------------------------------------------
  __cs_param_thread1_arg=NULL (00000000000000000000000000000000)

State 121 file examples/_cs_lazy_unsafe.c line 289 function thread1_0 thread 0
----------------------------------------------------
  __cs_mutex_to_lock=&m (00000010000000000000000000000000)

State 122 file examples/_cs_lazy_unsafe.c line 289 function thread1_0 thread 0
----------------------------------------------------
  __cs_thread_index=1 (01)

State 126 file examples/_cs_lazy_unsafe.c line 126 function __cs_mutex_lock thread 0
----------------------------------------------------
  m=2 (00000000000000000000000000000010)

State 129 file examples/_cs_lazy_unsafe.c line 127 function __cs_mutex_lock thread 0
----------------------------------------------------
  __cs_message="lock acquired" (00001010000000000000000000000000)

State 134 file examples/_cs_lazy_unsafe.c line 291 function thread1_0 thread 0
----------------------------------------------------
  data=1 (00000000000000000000000000000001)

State 138 file examples/_cs_lazy_unsafe.c line 293 function thread1_0 thread 0
----------------------------------------------------
  __cs_mutex_to_unlock=&m (00000010000000000000000000000000)

State 139 file examples/_cs_lazy_unsafe.c line 293 function thread1_0 thread 0
----------------------------------------------------
  __cs_thread_index=1 (01)

State 143 file examples/_cs_lazy_unsafe.c line 135 function __cs_mutex_unlock thread 0
----------------------------------------------------
  m=-1 (11111111111111111111111111111111)

State 146 file examples/_cs_lazy_unsafe.c line 136 function __cs_mutex_unlock thread 0
----------------------------------------------------
  __cs_message="lock released" (00001011000000000000000000000000)

State 153 file examples/_cs_lazy_unsafe.c line 299 function thread1_0 thread 0
----------------------------------------------------
  __cs_value_ptr=NULL (00000000000000000000000000000000)

State 154 file examples/_cs_lazy_unsafe.c line 299 function thread1_0 thread 0
----------------------------------------------------
  __cs_thread_index=1u (00000000000000000000000000000001)

State 155 file examples/_cs_lazy_unsafe.c line 99 function __cs_exit thread 0
----------------------------------------------------
  __cs_thread_joinargs[1]=NULL (00000000000000000000000000000000)

State 160 file examples/_cs_lazy_unsafe.c line 391 function main thread 0
----------------------------------------------------
  __cs_pc[1]=3 (011)

State 161 file examples/_cs_lazy_unsafe.c line 394 function main thread 0
----------------------------------------------------
  __cs_tmp_t2_r0=3 (11)

State 163 file examples/_cs_lazy_unsafe.c line 397 function main thread 0
----------------------------------------------------
  __cs_pc_cs[2]=3 (0011)

State 167 file examples/_cs_lazy_unsafe.c line 399 function main thread 0
----------------------------------------------------
  __cs_param_thread2_arg=NULL (00000000000000000000000000000000)

State 171 file examples/_cs_lazy_unsafe.c line 304 function thread2_0 thread 0
----------------------------------------------------
  __cs_mutex_to_lock=&m (00000010000000000000000000000000)

State 172 file examples/_cs_lazy_unsafe.c line 304 function thread2_0 thread 0
----------------------------------------------------
  __cs_thread_index=2 (10)

State 176 file examples/_cs_lazy_unsafe.c line 126 function __cs_mutex_lock thread 0
----------------------------------------------------
  m=3 (00000000000000000000000000000011)

State 179 file examples/_cs_lazy_unsafe.c line 127 function __cs_mutex_lock thread 0
----------------------------------------------------
  __cs_message="lock acquired" (00001010000000000000000000000000)

State 184 file examples/_cs_lazy_unsafe.c line 306 function thread2_0 thread 0
----------------------------------------------------
  data=3 (00000000000000000000000000000011)

State 188 file examples/_cs_lazy_unsafe.c line 308 function thread2_0 thread 0
----------------------------------------------------
  __cs_mutex_to_unlock=&m (00000010000000000000000000000000)

State 189 file examples/_cs_lazy_unsafe.c line 308 function thread2_0 thread 0
----------------------------------------------------
  __cs_thread_index=2 (10)

State 193 file examples/_cs_lazy_unsafe.c line 135 function __cs_mutex_unlock thread 0
----------------------------------------------------
  m=-1 (11111111111111111111111111111111)

State 196 file examples/_cs_lazy_unsafe.c line 136 function __cs_mutex_unlock thread 0
----------------------------------------------------
  __cs_message="lock released" (00001011000000000000000000000000)

State 203 file examples/_cs_lazy_unsafe.c line 314 function thread2_0 thread 0
----------------------------------------------------
  __cs_value_ptr=NULL (00000000000000000000000000000000)

State 204 file examples/_cs_lazy_unsafe.c line 314 function thread2_0 thread 0
----------------------------------------------------
  __cs_thread_index=2u (00000000000000000000000000000010)

State 205 file examples/_cs_lazy_unsafe.c line 99 function __cs_exit thread 0
----------------------------------------------------
  __cs_thread_joinargs[2]=NULL (00000000000000000000000000000000)

State 210 file examples/_cs_lazy_unsafe.c line 400 function main thread 0
----------------------------------------------------
  __cs_pc[2]=3 (011)

State 211 file examples/_cs_lazy_unsafe.c line 403 function main thread 0
----------------------------------------------------
  __cs_tmp_t3_r0=2 (10)

State 213 file examples/_cs_lazy_unsafe.c line 406 function main thread 0
----------------------------------------------------
  __cs_pc_cs[3]=2 (0010)

State 217 file examples/_cs_lazy_unsafe.c line 408 function main thread 0
----------------------------------------------------
  __cs_param_thread3_arg=NULL (00000000000000000000000000000000)

State 221 file examples/_cs_lazy_unsafe.c line 319 function thread3_0 thread 0
----------------------------------------------------
  __cs_mutex_to_lock=&m (00000010000000000000000000000000)

State 222 file examples/_cs_lazy_unsafe.c line 319 function thread3_0 thread 0
----------------------------------------------------
  __cs_thread_index=3 (11)

State 226 file examples/_cs_lazy_unsafe.c line 126 function __cs_mutex_lock thread 0
----------------------------------------------------
  m=4 (00000000000000000000000000000100)

State 229 file examples/_cs_lazy_unsafe.c line 127 function __cs_mutex_lock thread 0
----------------------------------------------------
  __cs_message="lock acquired" (00001010000000000000000000000000)

State 234 file examples/_cs_lazy_unsafe.c line 324 function thread3_0 thread 0
----------------------------------------------------
  __cs_local_thread3___cs_tmp_if_cond_0=TRUE (00000001)

Violated property:
  file examples/_cs_lazy_unsafe.c line 327 function thread3_0
  assertion 0
  0 != 0

VERIFICATION FAILED
