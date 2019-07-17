bool b = true;
active proctype main() {
	printf("hello world!\n");
	b = false;
}

ltl p1 { [] b }