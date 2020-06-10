int rotateLeft(int x, int n)
{
	int t = ~0, w = ~n + 1;

	t = ((t << (32 + w) & x));
	t = t >> (32 + w);
	t = t & ~(~0 << n);
	x = (x << n) | t;
	return x;
}