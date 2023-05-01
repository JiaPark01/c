
static int seed;		// prevent from affecting main.c


void my_srand(int s)
{
	seed = s;		// differentiate global var & local

}

int my_rand(void)
{
	seed = seed * 1103515245 + 12345;
	return((unsigned)(seed / 65536) % 32768); 
}
