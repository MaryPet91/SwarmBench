/*
* Verify the property count reaches the value 10.
* Verify the property above under the fairness condition

*/
int count;
bool incr;
#define fair ([]<> \
	(incr && _last == 0))

active proctype counter() {
	do
		:: incr ->
			count++
	od
}

active proctype env() {
	do
		:: incr = false
		:: incr = true
	od
}

ltl p1 { <> (count > 9) }
ltl p2 { fair -> <> (count > 9) }s