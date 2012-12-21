using System;
using System.Collections.Generic;
using System.Linq;

namespace Test
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			arr t = (x, y) => (Console.WriteLine(string.Format("{0} + {1} = {2}", x, y, x+y)));
			t += (x, y) => (Console.WriteLine(string.Format("{0} x {1} = {2}", x, y, x*y)));
			run (t, 4, 6);
		}

		public static void run (arr fn, int x, int y)
		{
			fn(x, y);
		}
	}

	delegate void arr(int x, int y);
}
