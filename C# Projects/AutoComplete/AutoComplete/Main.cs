using System;
using System.Linq;
using System.Text;
using System.Collections.Generic;

namespace AutoComplete
{
	class MainClass
	{
		static string[] keywords = new string[] {"list", "reserve", "remove", "add", "exit"};

		public static void Main (string[] args)
		{
			Terminal t = new Terminal (keywords);

			while (true) {
				Command temp = t.GetCommand();
				if (temp.MainCommand == "exit") break;
				t.Print("Got Command\n");
				t.Print("Main Command is: " + temp.MainCommand + "\n");
				t.Print("Argument is: " + temp.Argument + "\n");
				t.Print("========\n");
			}
		}


	}
}
