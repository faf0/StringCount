StringCount
===========

This program converts integers which are greater than zero
to strings over the alphabet A-Z and vice versa.

The following list shows equivalences between the string
and the integer representation:

A   = 1
B   = 2
...
Z   = 26
AA  = 1 * 26 + 1 = 27
...
BA  = 2 * 26 + 1 = 53
...
AAA = 1 * 26^2 + 1 * 26 + 1 = 703
...

Relationship between String Length and Number of Digits
-------------------------------------------------------

Let s := s\_ls\_\{l-1\}...s\_2s\_1 where A &lt;= s\_i &lt;= Z be a string over
the alphabet A-Z with length l.

For the integer representations a\_i of s\_i, it holds that:

	1 <= a_i <= 26 where 1 <= i <= l

Observe that the integer value a of the string s is:

	a = sum_{i = 0}^{l - 1} a_{i+1} * 26^i

We get the following lower bound for a (a\_i = 1 for all 1 &lt;= i &lt;= l):

	a >= sum_{i = 0}^{l - 1} 26^i

Using the formula for partial sums of geometric series, we get:

	v >= \frac{26^l - 1}{26 - 1}

Hence it holds:

	l <= \log_{26} (25 * v + 1)

The largest integer l that satisfies above inequality is:

	l = \floor (\log_{26} (25 * v + 1)) = \floor (\ln (25 * v + 1) / \ln (26))

How to Run
----------

Go to the directory containing the Makefile in a shell
and run `make`.

Examples
--------

	$ ./string_count 1
	A
	$ ./string_count 100
	CV
	$ ./string_count A
	1
	$ ./string_count CV
	100

Copyright
---------

Copyright 2013 Fabian Foerg

