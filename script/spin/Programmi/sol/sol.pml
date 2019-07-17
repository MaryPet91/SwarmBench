int x = 0;
int y = 3;
active proctype P(){

do
::x<3->
	::x++
	::y--
:: else ->
	break
od
}

init{
	run P()
}