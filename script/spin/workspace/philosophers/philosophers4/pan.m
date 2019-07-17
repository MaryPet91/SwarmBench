#define rand	pan_rand
#define pthread_equal(a,b)	((a)==(b))
#if defined(HAS_CODE) && defined(VERBOSE)
	#ifdef BFS_PAR
		bfs_printf("Pr: %d Tr: %d\n", II, t->forw);
	#else
		cpu_printf("Pr: %d Tr: %d\n", II, t->forw);
	#endif
#endif
	switch (t->forw) {
	default: Uerror("bad forward move");
	case 0:	/* if without executable clauses */
		continue;
	case 1: /* generic 'goto' or 'skip' */
		IfNotBlocked
		_m = 3; goto P999;
	case 2: /* generic 'else' */
		IfNotBlocked
		if (trpt->o_pm&1) continue;
		_m = 3; goto P999;

		 /* PROC Phil */
	case 3: // STATE 1 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:47 - [printf('P%d is thinking\\n',me)] (0:0:0 - 1)
		IfNotBlocked
		reached[0][1] = 1;
		Printf("P%d is thinking\n", ((int)((P0 *)this)->me));
		_m = 3; goto P999; /* 0 */
	case 4: // STATE 2 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:52 - [want_to_eat[me] = 1] (0:0:1 - 1)
		IfNotBlocked
		reached[0][2] = 1;
		(trpt+1)->bup.oval = ((int)want_to_eat[ Index(((int)((P0 *)this)->me), 16) ]);
		want_to_eat[ Index(((P0 *)this)->me, 16) ] = 1;
#ifdef VAR_RANGES
		logval("want_to_eat[Phil:me]", ((int)want_to_eat[ Index(((int)((P0 *)this)->me), 16) ]));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 5: // STATE 3 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:53 - [printf('P%d wants to chow down\\n',me)] (0:0:0 - 1)
		IfNotBlocked
		reached[0][3] = 1;
		Printf("P%d wants to chow down\n", ((int)((P0 *)this)->me));
		_m = 3; goto P999; /* 0 */
	case 6: // STATE 4 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:55 - [((fork[me]>0))] (11:0:1 - 1)
		IfNotBlocked
		reached[0][4] = 1;
		if (!((((int)now.fork[ Index(((int)((P0 *)this)->me), 16) ])>0)))
			continue;
		/* merge: fork[me] = (fork[me]-1)(0, 5, 11) */
		reached[0][5] = 1;
		(trpt+1)->bup.oval = ((int)now.fork[ Index(((int)((P0 *)this)->me), 16) ]);
		now.fork[ Index(((P0 *)this)->me, 16) ] = (((int)now.fork[ Index(((int)((P0 *)this)->me), 16) ])-1);
#ifdef VAR_RANGES
		logval("fork[Phil:me]", ((int)now.fork[ Index(((int)((P0 *)this)->me), 16) ]));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 7: // STATE 8 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:56 - [((fork[((me+1)%16)]>0))] (12:0:1 - 1)
		IfNotBlocked
		reached[0][8] = 1;
		if (!((((int)now.fork[ Index(((((int)((P0 *)this)->me)+1)%16), 16) ])>0)))
			continue;
		/* merge: fork[((me+1)%16)] = (fork[((me+1)%16)]-1)(0, 9, 12) */
		reached[0][9] = 1;
		(trpt+1)->bup.oval = ((int)now.fork[ Index(((((int)((P0 *)this)->me)+1)%16), 16) ]);
		now.fork[ Index(((((P0 *)this)->me+1)%16), 16) ] = (((int)now.fork[ Index(((((int)((P0 *)this)->me)+1)%16), 16) ])-1);
#ifdef VAR_RANGES
		logval("fork[((Phil:me+1)%16)]", ((int)now.fork[ Index(((((int)((P0 *)this)->me)+1)%16), 16) ]));
#endif
		;
		_m = 3; goto P999; /* 1 */
	case 8: // STATE 12 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:58 - [want_to_eat[me] = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[0][12] = 1;
		(trpt+1)->bup.oval = ((int)want_to_eat[ Index(((int)((P0 *)this)->me), 16) ]);
		want_to_eat[ Index(((P0 *)this)->me, 16) ] = 0;
#ifdef VAR_RANGES
		logval("want_to_eat[Phil:me]", ((int)want_to_eat[ Index(((int)((P0 *)this)->me), 16) ]));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 9: // STATE 13 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:63 - [eating[me] = 1] (0:0:1 - 1)
		IfNotBlocked
		reached[0][13] = 1;
		(trpt+1)->bup.oval = ((int)eating[ Index(((int)((P0 *)this)->me), 16) ]);
		eating[ Index(((P0 *)this)->me, 16) ] = 1;
#ifdef VAR_RANGES
		logval("eating[Phil:me]", ((int)eating[ Index(((int)((P0 *)this)->me), 16) ]));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 10: // STATE 14 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:64 - [printf('P%d eating\\n',me)] (0:0:0 - 1)
		IfNotBlocked
		reached[0][14] = 1;
		Printf("P%d eating\n", ((int)((P0 *)this)->me));
		_m = 3; goto P999; /* 0 */
	case 11: // STATE 15 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:65 - [eating[me] = 0] (0:0:1 - 1)
		IfNotBlocked
		reached[0][15] = 1;
		(trpt+1)->bup.oval = ((int)eating[ Index(((int)((P0 *)this)->me), 16) ]);
		eating[ Index(((P0 *)this)->me, 16) ] = 0;
#ifdef VAR_RANGES
		logval("eating[Phil:me]", ((int)eating[ Index(((int)((P0 *)this)->me), 16) ]));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 12: // STATE 16 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:70 - [fork[me] = (fork[me]+1)] (0:0:1 - 1)
		IfNotBlocked
		reached[0][16] = 1;
		(trpt+1)->bup.oval = ((int)now.fork[ Index(((int)((P0 *)this)->me), 16) ]);
		now.fork[ Index(((P0 *)this)->me, 16) ] = (((int)now.fork[ Index(((int)((P0 *)this)->me), 16) ])+1);
#ifdef VAR_RANGES
		logval("fork[Phil:me]", ((int)now.fork[ Index(((int)((P0 *)this)->me), 16) ]));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 13: // STATE 18 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:71 - [fork[((me+1)%16)] = (fork[((me+1)%16)]+1)] (0:0:1 - 1)
		IfNotBlocked
		reached[0][18] = 1;
		(trpt+1)->bup.oval = ((int)now.fork[ Index(((((int)((P0 *)this)->me)+1)%16), 16) ]);
		now.fork[ Index(((((P0 *)this)->me+1)%16), 16) ] = (((int)now.fork[ Index(((((int)((P0 *)this)->me)+1)%16), 16) ])+1);
#ifdef VAR_RANGES
		logval("fork[((Phil:me+1)%16)]", ((int)now.fork[ Index(((((int)((P0 *)this)->me)+1)%16), 16) ]));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 14: // STATE 23 - /home/mary/tacs/Swarm-Project/script/spin/workspace/philosophers/philosophers4/philosophers4.pml:73 - [-end-] (0:0:0 - 1)
		IfNotBlocked
		reached[0][23] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */
	case  _T5:	/* np_ */
		if (!((!(trpt->o_pm&4) && !(trpt->tau&128))))
			continue;
		/* else fall through */
	case  _T2:	/* true */
		_m = 3; goto P999;
#undef rand
	}

