using System;
using System.Text;
using System.Linq;

namespace AutoComplete
{
	public class Terminal
	{
		private string[] keywords;
		private string prompt;
		private int left;

		public Terminal (string[] keywords, string prompt = "$")
		{
			this.keywords = keywords;
			this.prompt = prompt;
			this.left = prompt.Length;
		}

		public Command GetCommand ()
		{
			StringBuilder now = new StringBuilder();
			int length = 0;
			int cursor = left;
			Console.Write(prompt);
			while (true) {
				ConsoleKeyInfo key = Console.ReadKey(true);
				if(key.Key == ConsoleKey.Tab) {
					int space = now.ToString().LastIndexOf(' ', cursor-left-1);
					string temp = now.ToString().Substring(space+1, cursor-left-space-1);

					var query = from w in keywords
								where w.StartsWith(temp)
								select w;

					if(query.Count() == 1){
						string g = query.First().Substring(temp.Length);

						now.Insert(cursor-left, g);
						length += g.Length;
						Console.Write(now.ToString().Substring(cursor-left));
						cursor += g.Length;
						Console.SetCursorPosition(cursor, Console.CursorTop);
					}

				} else if(key.Key == ConsoleKey.Enter){
					Console.WriteLine();
					return new Command(now.ToString().Trim());
				} else if(key.Key == ConsoleKey.Backspace || key.Key == ConsoleKey.Delete){
					if(length == 0) continue;
					if(key.Key == ConsoleKey.Backspace && cursor - left == 0) continue;
					if(key.Key == ConsoleKey.Delete && cursor == length + left) continue;

					length--;
					if(key.Key == ConsoleKey.Backspace)
						Console.SetCursorPosition(--cursor, Console.CursorTop);
					now = now.Remove(cursor-left, 1);
					Console.Write(now.ToString().Substring(cursor-left) + " ");
					Console.SetCursorPosition(cursor, Console.CursorTop);
				} else if(key.Key == ConsoleKey.LeftArrow){
					cursor = Console.CursorLeft-1 < left ? left : Console.CursorLeft-1;
					Console.SetCursorPosition(cursor, Console.CursorTop);
				} else if(key.Key == ConsoleKey.RightArrow){
					cursor = Console.CursorLeft == length + left ? length + left : Console.CursorLeft+1 ;
					Console.SetCursorPosition(cursor, Console.CursorTop);
				} else {
					Console.Write(key.KeyChar + now.ToString().Substring(cursor-left));
					now.Insert(cursor-left, key.KeyChar);
					length++;
					cursor++;
					Console.SetCursorPosition(cursor, Console.CursorTop);
				} 
			}
		}
	
		public void Print (string text)
		{
			Console.Write(text);
		}
	}
}

