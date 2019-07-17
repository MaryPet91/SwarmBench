
# 1 "<previous_module>"
unsigned __CPROVER_bitvector[1] __cs_active_thread[4] = {1};

# 2 "<previous_module>"
unsigned __CPROVER_bitvector[3] __cs_pc[4];

# 3 "<previous_module>"
unsigned __CPROVER_bitvector[4] __cs_pc_cs[4];

# 4 "<previous_module>"
unsigned __CPROVER_bitvector[2] __cs_last_thread;

# 5 "<previous_module>"
unsigned __CPROVER_bitvector[3] __cs_thread_lines[4] = {6, 3, 3, 3};

# 7 "<previous_module>"
void *__cs_safe_malloc(unsigned int __cs_size)
{
        
# 8 "<previous_module>"
void *__cs_ptr = (malloc(__cs_size));
        
# 9 "<previous_module>"
return __cs_ptr;
}


# 12 "<previous_module>"
void __cs_init_scalar(void *__cs_var, unsigned int __cs_size)
{
        
# 13 "<previous_module>"
if (__cs_size == (sizeof(int)))
                
# 14 "<previous_module>"
*((int *) __cs_var) = nondet_int();
        else

# 15 "<previous_module>"
        {
                
# 16 "<previous_module>"
__cs_var = malloc(__cs_size);
        }

}


# 20 "<previous_module>"
void __CSEQ_message(char *__cs_message)
{
        ;
}


# 22 "<previous_module>"
typedef int __cs_t;

# 24 "<previous_module>"
void *__cs_threadargs[4];

# 25 "<previous_module>"
void *__cs_thread_joinargs[4];

# 27 "<previous_module>"
int __cs_create(__cs_t *__cs_new_thread_id, void *__cs_attr, void *(*__cs_thread_function)(void *), void *__cs_arg, int __cs_threadID)
{
        
# 28 "<previous_module>"
if (__cs_threadID > THREADS)
                return 0;

        
# 29 "<previous_module>"
*__cs_new_thread_id = __cs_threadID;
        
# 30 "<previous_module>"
__cs_active_thread[__cs_threadID] = 1;
        
# 31 "<previous_module>"
__cs_threadargs[__cs_threadID] = __cs_arg;
        
# 32 "<previous_module>"
__CSEQ_message("thread spawned");
        
# 33 "<previous_module>"
return 0;
}


# 36 "<previous_module>"
int __cs_join(__cs_t __cs_id, void **__cs_value_ptr)
{
        
# 37 "<previous_module>"
__CPROVER_assume(__cs_pc[__cs_id] == __cs_thread_lines[__cs_id]);
        
# 38 "<previous_module>"
*__cs_value_ptr = __cs_thread_joinargs[__cs_id];
        
# 39 "<previous_module>"
return 0;
}


# 42 "<previous_module>"
int __cs_exit(void *__cs_value_ptr, unsigned int __cs_thread_index)
{
        
# 43 "<previous_module>"
__cs_thread_joinargs[__cs_thread_index] = __cs_value_ptr;
        
# 44 "<previous_module>"
return 0;
}


# 47 "<previous_module>"
int __cs_self(void)
{
        return 1;
}


# 49 "<previous_module>"
typedef int __cs_mutex_t;

# 51 "<previous_module>"
int __cs_mutex_init(__cs_mutex_t *__cs_m, int __cs_val)
{
        
# 52 "<previous_module>"
*__cs_m = -1;
        
# 53 "<previous_module>"
return 0;
}


# 56 "<previous_module>"
int __cs_mutex_destroy(__cs_mutex_t *__cs_mutex_to_destroy)
{
        
# 57 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_destroy) != 0, "attempt to destroy an uninitialized mutex");
        
# 58 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_destroy) != (-2), "attempt to destroy a previously destroyed mutex");
        
# 59 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_destroy) == (-1), "attempt to destroy a locked mutex");
        
# 60 "<previous_module>"
*__cs_mutex_to_destroy = -2;
        
# 61 "<previous_module>"
__CSEQ_message("lock destroyed");
        
# 62 "<previous_module>"
return 0;
}


# 65 "<previous_module>"
int __cs_mutex_lock(__cs_mutex_t *__cs_mutex_to_lock, unsigned __CPROVER_bitvector[2] __cs_thread_index)
{
        
# 66 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_lock) != 0, "attempt to lock an uninitialized mutex");
        
# 67 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_lock) != (-2), "attempt to lock a destroyed mutex");
        
# 68 "<previous_module>"
__CPROVER_assume((*__cs_mutex_to_lock) == (-1));
        
# 69 "<previous_module>"
*__cs_mutex_to_lock = __cs_thread_index + 1;
        
# 70 "<previous_module>"
__CSEQ_message("lock acquired");
        
# 71 "<previous_module>"
return 0;
}


# 74 "<previous_module>"
int __cs_mutex_unlock(__cs_mutex_t *__cs_mutex_to_unlock, unsigned __CPROVER_bitvector[2] __cs_thread_index)
{
        
# 75 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_unlock) != 0, "attempt to unlock an uninitialized mutex");
        
# 76 "<previous_module>"
__CPROVER_assert((*__cs_mutex_to_unlock) != (-2), "attempt to unlock a destroyed mutex");
        
# 77 "<previous_module>"
__CPROVER_assume((*__cs_mutex_to_unlock) == (__cs_thread_index + 1));
        
# 78 "<previous_module>"
*__cs_mutex_to_unlock = -1;
        
# 79 "<previous_module>"
__CSEQ_message("lock released");
        
# 80 "<previous_module>"
return 0;
}


# 83 "<previous_module>"
typedef int __cs_cond_t;

# 85 "<previous_module>"
int __cs_cond_init(__cs_cond_t *__cs_cond_to_init, void *__cs_attr)
{
        
# 86 "<previous_module>"
*__cs_cond_to_init = -1;
        
# 87 "<previous_module>"
return 0;
}


# 90 "<previous_module>"
int __cs_cond_destroy(__cs_cond_t *__cs_cond_to_destroy)
{
        
# 91 "<previous_module>"
*__cs_cond_to_destroy = -2;
        
# 92 "<previous_module>"
return 0;
}


# 95 "<previous_module>"
int __cs_cond_wait_1(__cs_cond_t *__cs_cond_to_wait_for, __cs_mutex_t *__cs_m, unsigned int __cs_thread_index)
{
        
# 96 "<previous_module>"
__CPROVER_assert((*__cs_cond_to_wait_for) != 0, "attempt to use an uninitialized conditional variable");
        
# 97 "<previous_module>"
__CPROVER_assert((*__cs_cond_to_wait_for) != (-2), "attempt to use a destroyed conditional variable");
        
# 98 "<previous_module>"
__cs_mutex_unlock(__cs_m, __cs_thread_index);
        
# 99 "<previous_module>"
return 0;
}


# 102 "<previous_module>"
int __cs_cond_wait_2(__cs_cond_t *__cs_cond_to_wait_for, __cs_mutex_t *__cs_m, unsigned int __cs_thread_index)
{
        
# 103 "<previous_module>"
__CPROVER_assume((*__cs_cond_to_wait_for) == 1);
        
# 104 "<previous_module>"
__cs_mutex_lock(__cs_m, __cs_thread_index);
        
# 105 "<previous_module>"
return 0;
}


# 108 "<previous_module>"
int __cs_cond_signal(__cs_cond_t *__cs_cond_to_signal)
{
        
# 109 "<previous_module>"
*__cs_cond_to_signal = 1;
        
# 110 "<previous_module>"
__CSEQ_message("conditional variable signal");
        
# 111 "<previous_module>"
return 0;
}


# 114 "<previous_module>"
int __cs_cond_broadcast(__cs_cond_t *__cs_cond_to_broadcast)
{
        
# 115 "<previous_module>"
*__cs_cond_to_broadcast = 1;
        
# 116 "<previous_module>"
__CSEQ_message("conditional variable broadcast");
        
# 117 "<previous_module>"
return 0;
}


# 123 "<previous_module>"
typedef struct __cs_barrier_t
{
        
# 121 "<previous_module>"
unsigned int init;
        
# 122 "<previous_module>"
unsigned int current;
} __cs_barrier_t;

# 125 "<previous_module>"
int __cs_barrier_init(__cs_barrier_t *__cs_barrier_to_init, void *__cs_attr, unsigned int count)
{
        
# 126 "<previous_module>"
__CPROVER_assert(count > 0, "count must be greater than 0");
        
# 127 "<previous_module>"
__cs_barrier_to_init->current = count;
        
# 128 "<previous_module>"
__cs_barrier_to_init->init = count;
        
# 129 "<previous_module>"
return 0;
}


# 132 "<previous_module>"
int __cs_barrier_destroy(__cs_barrier_t *__cs_barrier_to_destroy)
{
        
# 133 "<previous_module>"
__cs_barrier_to_destroy->init = -1;
        
# 134 "<previous_module>"
__cs_barrier_to_destroy->current = -1;
        
# 135 "<previous_module>"
return 0;
}


# 139 "<previous_module>"
int __cs_barrier_wait_1(__cs_barrier_t *__cs_barrier_to_wait)
{
        
# 140 "<previous_module>"
__CPROVER_assert(__cs_barrier_to_wait->init > 0, "attempt to use an uninitialized barrier variable");
        
# 141 "<previous_module>"
__cs_barrier_to_wait->current--;
        
# 142 "<previous_module>"
return 0;
}


# 145 "<previous_module>"
int __cs_barrier_wait_2(__cs_barrier_t *__cs_barrier_to_wait)
{
        
# 146 "<previous_module>"
__CPROVER_assert(__cs_barrier_to_wait->init > 0, "attempt to use an uninitialized barrier variable");
        
# 147 "<previous_module>"
__CPROVER_assume(__cs_barrier_to_wait->current == 0);
        
# 148 "<previous_module>"
__cs_barrier_to_wait->current = __cs_barrier_to_wait->init;
        
# 149 "<previous_module>"
return 0;
}


# 152 "<previous_module>"
typedef int __cs_attr_t;

# 153 "<previous_module>"
struct sched_param
{
        
# 154 "<previous_module>"
int sched_priority;
};

# 156 "<previous_module>"
int __cs_attr_init(__cs_attr_t *t)
{
        return 0;
}


# 157 "<previous_module>"
int __cs_attr_destroy(__cs_attr_t *t)
{
        return 0;
}


# 158 "<previous_module>"
int __cs_attr_getdetachstate(const __cs_attr_t *t, int *s)
{
        return 0;
}


# 159 "<previous_module>"
int __cs_attr_getguardsize(const __cs_attr_t *t, unsigned int *s)
{
        return 0;
}


# 160 "<previous_module>"
int __cs_attr_getinheritsched(const __cs_attr_t *t, int *s)
{
        return 0;
}


# 161 "<previous_module>"
int __cs_attr_getschedparam(const __cs_attr_t *t, struct sched_param *s)
{
        return 0;
}


# 162 "<previous_module>"
int __cs_attr_getschedpolicy(const __cs_attr_t *t, int *s)
{
        return 0;
}


# 163 "<previous_module>"
int __cs_attr_getscope(const __cs_attr_t *t, int *s)
{
        return 0;
}


# 164 "<previous_module>"
int __cs_attr_getstackaddr(const __cs_attr_t *t, void **s)
{
        return 0;
}


# 165 "<previous_module>"
int __cs_attr_getstacksize(const __cs_attr_t *t, unsigned int *s)
{
        return 0;
}


# 166 "<previous_module>"
int __cs_attr_setdetachstate(__cs_attr_t *t, int s)
{
        return 0;
}


# 167 "<previous_module>"
int __cs_attr_setguardsize(__cs_attr_t *t, unsigned int s)
{
        return 0;
}


# 168 "<previous_module>"
int __cs_attr_setinheritsched(__cs_attr_t *t, int s)
{
        return 0;
}


# 169 "<previous_module>"
int __cs_attr_setschedparam(__cs_attr_t *t, const struct sched_param *s)
{
        return 0;
}


# 170 "<previous_module>"
int __cs_attr_setschedpolicy(__cs_attr_t *t, int s)
{
        return 0;
}


# 171 "<previous_module>"
int __cs_attr_setscope(__cs_attr_t *t, int s)
{
        return 0;
}


# 172 "<previous_module>"
int __cs_attr_setstackaddr(__cs_attr_t *t, void *s)
{
        return 0;
}


# 173 "<previous_module>"
int __cs_attr_setstacksize(__cs_attr_t *t, unsigned int s)
{
        return 0;
}


# 174 "<previous_module>"
void __VERIFIER_error();

# 175 "<previous_module>"
typedef int _____STARTSTRIPPINGFROMHERE_____;

# 176 "<previous_module>"
typedef int __cs_barrier_t;

# 177 "<previous_module>"
typedef int __cs_barrierattr_t;

# 178 "<previous_module>"
typedef int __cs_attr_t;

# 179 "<previous_module>"
typedef int __cs_cond_t;

# 180 "<previous_module>"
typedef int __cs_condattr_t;

# 181 "<previous_module>"
typedef int __cs_key_t;

# 182 "<previous_module>"
typedef int __cs_mutex_t;

# 183 "<previous_module>"
typedef int __cs_mutexattr_t;

# 184 "<previous_module>"
typedef int __cs_once_t;

# 185 "<previous_module>"
typedef int __cs_rwlock_t;

# 186 "<previous_module>"
typedef int __cs_rwlockattr_t;

# 187 "<previous_module>"
typedef int __cs_t;

# 188 "<previous_module>"
typedef int size_t;

# 189 "<previous_module>"
typedef int __builtin_va_list;

# 190 "<previous_module>"
typedef int __gnuc_va_list;

# 191 "<previous_module>"
typedef int __int8_t;

# 192 "<previous_module>"
typedef int __uint8_t;

# 193 "<previous_module>"
typedef int __int16_t;

# 194 "<previous_module>"
typedef int __uint16_t;

# 195 "<previous_module>"
typedef int __int_least16_t;

# 196 "<previous_module>"
typedef int __uint_least16_t;

# 197 "<previous_module>"
typedef int __int32_t;

# 198 "<previous_module>"
typedef int __uint32_t;

# 199 "<previous_module>"
typedef int __int64_t;

# 200 "<previous_module>"
typedef int __uint64_t;

# 201 "<previous_module>"
typedef int __int_least32_t;

# 202 "<previous_module>"
typedef int __uint_least32_t;

# 203 "<previous_module>"
typedef int __s8;

# 204 "<previous_module>"
typedef int __u8;

# 205 "<previous_module>"
typedef int __s16;

# 206 "<previous_module>"
typedef int __u16;

# 207 "<previous_module>"
typedef int __s32;

# 208 "<previous_module>"
typedef int __u32;

# 209 "<previous_module>"
typedef int __s64;

# 210 "<previous_module>"
typedef int __u64;

# 211 "<previous_module>"
typedef int _LOCK_T;

# 212 "<previous_module>"
typedef int _LOCK_RECURSIVE_T;

# 213 "<previous_module>"
typedef int _off_t;

# 214 "<previous_module>"
typedef int __dev_t;

# 215 "<previous_module>"
typedef int __uid_t;

# 216 "<previous_module>"
typedef int __gid_t;

# 217 "<previous_module>"
typedef int _off64_t;

# 218 "<previous_module>"
typedef int _fpos_t;

# 219 "<previous_module>"
typedef int _ssize_t;

# 220 "<previous_module>"
typedef int wint_t;

# 221 "<previous_module>"
typedef int _mbstate_t;

# 222 "<previous_module>"
typedef int _flock_t;

# 223 "<previous_module>"
typedef int _iconv_t;

# 224 "<previous_module>"
typedef int __ULong;

# 225 "<previous_module>"
typedef int __FILE;

# 226 "<previous_module>"
typedef int ptrdiff_t;

# 227 "<previous_module>"
typedef int wchar_t;

# 228 "<previous_module>"
typedef int __off_t;

# 229 "<previous_module>"
typedef int __pid_t;

# 230 "<previous_module>"
typedef int __loff_t;

# 231 "<previous_module>"
typedef int u_char;

# 232 "<previous_module>"
typedef int u_short;

# 233 "<previous_module>"
typedef int u_int;

# 234 "<previous_module>"
typedef int u_long;

# 235 "<previous_module>"
typedef int ushort;

# 236 "<previous_module>"
typedef int uint;

# 237 "<previous_module>"
typedef int clock_t;

# 238 "<previous_module>"
typedef int time_t;

# 239 "<previous_module>"
typedef int daddr_t;

# 240 "<previous_module>"
typedef int caddr_t;

# 241 "<previous_module>"
typedef int ino_t;

# 242 "<previous_module>"
typedef int off_t;

# 243 "<previous_module>"
typedef int dev_t;

# 244 "<previous_module>"
typedef int uid_t;

# 245 "<previous_module>"
typedef int gid_t;

# 246 "<previous_module>"
typedef int pid_t;

# 247 "<previous_module>"
typedef int key_t;

# 248 "<previous_module>"
typedef int ssize_t;

# 249 "<previous_module>"
typedef int mode_t;

# 250 "<previous_module>"
typedef int nlink_t;

# 251 "<previous_module>"
typedef int fd_mask;

# 252 "<previous_module>"
typedef int _types_fd_set;

# 253 "<previous_module>"
typedef int fd_set;

# 254 "<previous_module>"
typedef int clockid_t;

# 255 "<previous_module>"
typedef int timer_t;

# 256 "<previous_module>"
typedef int useconds_t;

# 257 "<previous_module>"
typedef int suseconds_t;

# 258 "<previous_module>"
typedef int FILE;

# 259 "<previous_module>"
typedef int fpos_t;

# 260 "<previous_module>"
typedef int cookie_read_function_t;

# 261 "<previous_module>"
typedef int cookie_write_function_t;

# 262 "<previous_module>"
typedef int cookie_seek_function_t;

# 263 "<previous_module>"
typedef int cookie_close_function_t;

# 264 "<previous_module>"
typedef int cookie_io_functions_t;

# 265 "<previous_module>"
typedef int div_t;

# 266 "<previous_module>"
typedef int ldiv_t;

# 267 "<previous_module>"
typedef int lldiv_t;

# 268 "<previous_module>"
typedef int sigset_t;

# 269 "<previous_module>"
typedef int __sigset_t;

# 270 "<previous_module>"
typedef int _sig_func_ptr;

# 271 "<previous_module>"
typedef int sig_atomic_t;

# 272 "<previous_module>"
typedef int __tzrule_type;

# 273 "<previous_module>"
typedef int __tzinfo_type;

# 274 "<previous_module>"
typedef int mbstate_t;

# 275 "<previous_module>"
typedef int sem_t;

# 276 "<previous_module>"
typedef int pthread_t;

# 277 "<previous_module>"
typedef int pthread_attr_t;

# 278 "<previous_module>"
typedef int pthread_mutex_t;

# 279 "<previous_module>"
typedef int pthread_mutexattr_t;

# 280 "<previous_module>"
typedef int pthread_cond_t;

# 281 "<previous_module>"
typedef int pthread_condattr_t;

# 282 "<previous_module>"
typedef int pthread_key_t;

# 283 "<previous_module>"
typedef int pthread_once_t;

# 284 "<previous_module>"
typedef int pthread_rwlock_t;

# 285 "<previous_module>"
typedef int pthread_rwlockattr_t;

# 286 "<previous_module>"
typedef int pthread_spinlock_t;

# 287 "<previous_module>"
typedef int pthread_barrier_t;

# 288 "<previous_module>"
typedef int pthread_barrierattr_t;

# 289 "<previous_module>"
typedef int jmp_buf;

# 290 "<previous_module>"
typedef int rlim_t;

# 291 "<previous_module>"
typedef int sa_family_t;

# 292 "<previous_module>"
typedef int sigjmp_buf;

# 293 "<previous_module>"
typedef int stack_t;

# 294 "<previous_module>"
typedef int siginfo_t;

# 295 "<previous_module>"
typedef int z_stream;

# 296 "<previous_module>"
typedef int int8_t;

# 297 "<previous_module>"
typedef int uint8_t;

# 298 "<previous_module>"
typedef int int16_t;

# 299 "<previous_module>"
typedef int uint16_t;

# 300 "<previous_module>"
typedef int int32_t;

# 301 "<previous_module>"
typedef int uint32_t;

# 302 "<previous_module>"
typedef int int64_t;

# 303 "<previous_module>"
typedef int uint64_t;

# 304 "<previous_module>"
typedef int int_least8_t;

# 305 "<previous_module>"
typedef int uint_least8_t;

# 306 "<previous_module>"
typedef int int_least16_t;

# 307 "<previous_module>"
typedef int uint_least16_t;

# 308 "<previous_module>"
typedef int int_least32_t;

# 309 "<previous_module>"
typedef int uint_least32_t;

# 310 "<previous_module>"
typedef int int_least64_t;

# 311 "<previous_module>"
typedef int uint_least64_t;

# 312 "<previous_module>"
typedef int int_fast8_t;

# 313 "<previous_module>"
typedef int uint_fast8_t;

# 314 "<previous_module>"
typedef int int_fast16_t;

# 315 "<previous_module>"
typedef int uint_fast16_t;

# 316 "<previous_module>"
typedef int int_fast32_t;

# 317 "<previous_module>"
typedef int uint_fast32_t;

# 318 "<previous_module>"
typedef int int_fast64_t;

# 319 "<previous_module>"
typedef int uint_fast64_t;

# 320 "<previous_module>"
typedef int intptr_t;

# 321 "<previous_module>"
typedef int uintptr_t;

# 322 "<previous_module>"
typedef int intmax_t;

# 323 "<previous_module>"
typedef int uintmax_t;

# 324 "<previous_module>"
typedef _Bool bool;

# 325 "<previous_module>"
typedef void BZFILE;

# 326 "<previous_module>"
typedef int va_list;

# 327 "<previous_module>"
typedef int loff_t;

# 328 "<previous_module>"
typedef int _____STOPSTRIPPINGFROMHERE_____;

# 329 "<previous_module>"
__cs_mutex_t m;

# 330 "<previous_module>"
int data = (0);

# 331 "<previous_module>"
void *thread1_0(void *__cs_param_thread1_arg)

# 332 "<previous_module>"
{
        
# 333 "<previous_module>"
IF(1,0,tthread1_0_1)__CSEQ_removeindent;
        
# 334 "<previous_module>"
__cs_mutex_lock(&m, 1);
        
# 335 "<previous_module>"
tthread1_0_1: IF(1,1,tthread1_0_2)__CSEQ_removeindent;
        
# 336 "<previous_module>"
data++;
        
# 337 "<previous_module>"
tthread1_0_2: IF(1,2,tthread1_0_3)__CSEQ_removeindent;
        
# 338 "<previous_module>"
__cs_mutex_unlock(&m, 1);
        
# 339 "<previous_module>"
__exit_thread1:
        __CPROVER_assume(__cs_pc_cs[1] >= 3);

        
# 340 "<previous_module>"
;
        ;
        
# 341 "<previous_module>"
tthread1_0_3: __CSEQ_removeindent;
        
# 342 "<previous_module>"
__cs_exit(0, 1);
}


# 344 "<previous_module>"
void *thread2_0(void *__cs_param_thread2_arg)

# 345 "<previous_module>"
{
        
# 346 "<previous_module>"
IF(2,0,tthread2_0_1)__CSEQ_removeindent;
        
# 347 "<previous_module>"
__cs_mutex_lock(&m, 2);
        
# 348 "<previous_module>"
tthread2_0_1: IF(2,1,tthread2_0_2)__CSEQ_removeindent;
        
# 349 "<previous_module>"
data += 2;
        
# 350 "<previous_module>"
tthread2_0_2: IF(2,2,tthread2_0_3)__CSEQ_removeindent;
        
# 351 "<previous_module>"
__cs_mutex_unlock(&m, 2);
        
# 352 "<previous_module>"
__exit_thread2:
        __CPROVER_assume(__cs_pc_cs[2] >= 3);

        
# 353 "<previous_module>"
;
        ;
        
# 354 "<previous_module>"
tthread2_0_3: __CSEQ_removeindent;
        
# 355 "<previous_module>"
__cs_exit(0, 2);
}


# 357 "<previous_module>"
void *thread3_0(void *__cs_param_thread3_arg)

# 358 "<previous_module>"
{
        
# 359 "<previous_module>"
IF(3,0,tthread3_0_1)__CSEQ_removeindent;
        
# 360 "<previous_module>"
__cs_mutex_lock(&m, 3);
        
# 361 "<previous_module>"
;
        ;
        
# 362 "<previous_module>"
static _Bool __cs_local_thread3___cs_tmp_if_cond_0;
        
# 363 "<previous_module>"
tthread3_0_1: IF(3,1,tthread3_0_2)__CSEQ_removeindent;
        
# 364 "<previous_module>"
__cs_local_thread3___cs_tmp_if_cond_0 = data >= 3;
        
# 365 "<previous_module>"
if (__cs_local_thread3___cs_tmp_if_cond_0)

# 366 "<previous_module>"
        {
                
# 367 "<previous_module>"
assert(0);
                
# 368 "<previous_module>"
;
                ;
        }

        
# 370 "<previous_module>"
;
        
# 371 "<previous_module>"
tthread3_0_2: IF(3,2,tthread3_0_3)__CSEQ_removeindent;
        
# 372 "<previous_module>"
__cs_mutex_unlock(&m, 3);
        
# 373 "<previous_module>"
__exit_thread3:
        __CPROVER_assume(__cs_pc_cs[3] >= 3);

        
# 374 "<previous_module>"
;
        ;
        
# 375 "<previous_module>"
tthread3_0_3: __CSEQ_removeindent;
        
# 376 "<previous_module>"
__cs_exit(0, 3);
}


# 378 "<previous_module>"
int main_thread(void)

# 379 "<previous_module>"
{
        
# 380 "<previous_module>"
IF(0,0,tmain_1)__CSEQ_removeindent;
        
# 381 "<previous_module>"
__cs_mutex_init(&m, 0);
        
# 382 "<previous_module>"
static __cs_t __cs_local_main_t1;
        
# 383 "<previous_module>"
;
        ;
        
# 384 "<previous_module>"
static __cs_t __cs_local_main_t2;
        
# 385 "<previous_module>"
;
        ;
        
# 386 "<previous_module>"
static __cs_t __cs_local_main_t3;
        
# 387 "<previous_module>"
;
        ;
        
# 388 "<previous_module>"
__cs_create(&__cs_local_main_t1, 0, thread1_0, 0, 1);
        
# 389 "<previous_module>"
tmain_1: IF(0,1,tmain_2)__CSEQ_removeindent;
        
# 390 "<previous_module>"
__cs_create(&__cs_local_main_t2, 0, thread2_0, 0, 2);
        
# 391 "<previous_module>"
tmain_2: IF(0,2,tmain_3)__CSEQ_removeindent;
        
# 392 "<previous_module>"
__cs_create(&__cs_local_main_t3, 0, thread3_0, 0, 3);
        
# 393 "<previous_module>"
tmain_3: IF(0,3,tmain_4)__CSEQ_removeindent;
        
# 394 "<previous_module>"
__cs_join(__cs_local_main_t1, 0);
        
# 395 "<previous_module>"
tmain_4: IF(0,4,tmain_5)__CSEQ_removeindent;
        
# 396 "<previous_module>"
__cs_join(__cs_local_main_t2, 0);
        
# 397 "<previous_module>"
tmain_5: IF(0,5,tmain_6)__CSEQ_removeindent;
        
# 398 "<previous_module>"
__cs_join(__cs_local_main_t3, 0);
        
# 399 "<previous_module>"
goto __exit_main;
        ;
        
# 400 "<previous_module>"
__exit_main:
        __CPROVER_assume(__cs_pc_cs[0] >= 6);

        
# 401 "<previous_module>"
;
        ;
        
# 402 "<previous_module>"
tmain_6: __CSEQ_removeindent;
        
# 403 "<previous_module>"
__cs_exit(0, 0);
}


# 405 "<previous_module>"
int main(void)
{
        
# 406 "<previous_module>"
/* round  0 */__CSEQ_removeindent;
        
# 407 "<previous_module>"
    /* main */__CSEQ_removeindent;
        
# 408 "<previous_module>"
unsigned __CPROVER_bitvector[3] __cs_tmp_t0_r0;
        
# 409 "<previous_module>"
__cs_pc_cs[0] = __cs_tmp_t0_r0;
        
# 410 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] > 0);
        
# 411 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] <= 6);
        
# 412 "<previous_module>"
main_thread();
        
# 413 "<previous_module>"
__cs_pc[0] = __cs_pc_cs[0];
        
# 415 "<previous_module>"
    /* thread1_0 */__CSEQ_removeindent;
        
# 416 "<previous_module>"
unsigned __CPROVER_bitvector[2] __cs_tmp_t1_r0;
        
# 417 "<previous_module>"
if (__cs_active_thread[1])
        {
                
# 418 "<previous_module>"
__cs_pc_cs[1] = __cs_tmp_t1_r0;
                
# 419 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[1] <= 3);
                
# 420 "<previous_module>"
thread1_0(__cs_threadargs[1]);
                
# 421 "<previous_module>"
__cs_pc[1] = __cs_pc_cs[1];
        }

        
# 424 "<previous_module>"
    /* thread2_0 */__CSEQ_removeindent;
        
# 425 "<previous_module>"
unsigned __CPROVER_bitvector[2] __cs_tmp_t2_r0;
        
# 426 "<previous_module>"
if (__cs_active_thread[2])
        {
                
# 427 "<previous_module>"
__cs_pc_cs[2] = __cs_tmp_t2_r0;
                
# 428 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[2] <= 3);
                
# 429 "<previous_module>"
thread2_0(__cs_threadargs[2]);
                
# 430 "<previous_module>"
__cs_pc[2] = __cs_pc_cs[2];
        }

        
# 433 "<previous_module>"
    /* thread3_0 */__CSEQ_removeindent;
        
# 434 "<previous_module>"
unsigned __CPROVER_bitvector[2] __cs_tmp_t3_r0;
        
# 435 "<previous_module>"
if (__cs_active_thread[3])
        {
                
# 436 "<previous_module>"
__cs_pc_cs[3] = __cs_tmp_t3_r0;
                
# 437 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[3] <= 3);
                
# 438 "<previous_module>"
thread3_0(__cs_threadargs[3]);
                
# 439 "<previous_module>"
__cs_pc[3] = __cs_pc_cs[3];
        }

        
# 442 "<previous_module>"
unsigned __CPROVER_bitvector[3] __cs_tmp_t0_r1;
        
# 443 "<previous_module>"
if (__cs_active_thread[0] == 1)
        {
                
# 444 "<previous_module>"
__cs_pc_cs[0] = __cs_pc[0] + __cs_tmp_t0_r1;
                
# 445 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] >= __cs_pc[0]);
                
# 446 "<previous_module>"
__CPROVER_assume(__cs_pc_cs[0] <= 6);
                
# 447 "<previous_module>"
main_thread();
        }

        
# 449 "<previous_module>"
return 0;
}

