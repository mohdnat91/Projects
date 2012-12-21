#include <stdio.h>

long long gcd ( long long a, long long b ){
  long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

long long lcm(long long x ,long long y){
	return x * y / gcd(x, y);
}

int main(){

	long long a, b;
	long long c, d;
	long long g;

	while(1){
		scanf("%lld %lld", &c, &d);
		if(c == 0 && d == 0) break;

		g = gcd(c, d);

		a = c/g;
		b = d/g;

		if(a > b && a % b == 0) printf("%lld\n", a/b);
		else if (b > a && b % a == 0) printf("%lld\n", b/a);
		else printf("%lld\n", lcm(a, b));
	}

	return 0;
}