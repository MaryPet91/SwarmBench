int x = 1;

active proctype hundred(){
do
::x<=100 ->
	if
		:: (x % 2==0) -> printf("%u\n", x);
	fi
	::x++;
:: else ->
	break;
od;
}

init{
	run hundred();
}