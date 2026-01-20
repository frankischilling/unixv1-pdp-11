buf(op, i, v)
{
	static b[512];
	if(op == 1)
		b[i] = v;
	if(op == 2)
		return(b);
	return(b[i]);
}

putnum(n)
{
	int d[12];
	int i;
	if(n == 0) {
		write(1, "0", 1);
		return;
	}
	if(n < 0) {
		write(1, "-", 1);
		n = -n;
	}
	i = 0;
	while(n > 0) {
		d[i] = 060 + (n % 10);
		i = i + 1;
		n = n / 10;
	}
	while(i > 0) {
		i = i - 1;
		write(1, &d[i], 1);
	}
}

main(argc, argv)
int argv[];
{
	int in, out, n;

	write(1, "argc=", 5);
	putnum(argc);
	write(1, "\n", 1);

	if(argc != 3) {
		write(2, "usage: mv f1 f2\n", 16);
		exit(1);
	}

	write(1, "open\n", 5);
	in = open(argv[1], 0);
	write(1, "in=", 3);
	putnum(in);
	write(1, "\n", 1);
	if(in < 0) {
		write(2, "cannot open\n", 12);
		exit(1);
	}

	write(1, "creat\n", 6);
	out = creat(argv[2], 0644);
	write(1, "out=", 4);
	putnum(out);
	write(1, "\n", 1);
	if(out < 0) {
		close(in);
		write(2, "cannot creat\n", 13);
		exit(1);
	}

	n = read(in, buf(2, 0, 0), 512);
	write(1, "n=", 2);
	putnum(n);
	write(1, "\n", 1);
	while(n > 0) {
		write(out, buf(2, 0, 0), n);
		n = read(in, buf(2, 0, 0), 512);
	}

	close(in);
	close(out);
	unlink(argv[1]);
	write(1, "done\n", 5);
	exit(0);
}
