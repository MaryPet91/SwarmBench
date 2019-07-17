	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* PROC Phil */
;
		;
		
	case 4: // STATE 2
		;
		want_to_eat[ Index(((P0 *)this)->me, 16) ] = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 6: // STATE 5
		;
		now.fork[ Index(((P0 *)this)->me, 16) ] = trpt->bup.oval;
		;
		goto R999;

	case 7: // STATE 9
		;
		now.fork[ Index(((((P0 *)this)->me+1)%16), 16) ] = trpt->bup.oval;
		;
		goto R999;

	case 8: // STATE 12
		;
		want_to_eat[ Index(((P0 *)this)->me, 16) ] = trpt->bup.oval;
		;
		goto R999;

	case 9: // STATE 13
		;
		eating[ Index(((P0 *)this)->me, 16) ] = trpt->bup.oval;
		;
		goto R999;
;
		;
		
	case 11: // STATE 15
		;
		eating[ Index(((P0 *)this)->me, 16) ] = trpt->bup.oval;
		;
		goto R999;

	case 12: // STATE 16
		;
		now.fork[ Index(((P0 *)this)->me, 16) ] = trpt->bup.oval;
		;
		goto R999;

	case 13: // STATE 18
		;
		now.fork[ Index(((((P0 *)this)->me+1)%16), 16) ] = trpt->bup.oval;
		;
		goto R999;

	case 14: // STATE 23
		;
		p_restor(II);
		;
		;
		goto R999;
	}

