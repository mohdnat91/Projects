using System;

namespace UserInterface
{
	public struct Command
	{
		public readonly string FullCommand;

		public readonly string MainCommand;
		public readonly string Argument;

		public Command (string FullCommand)
		{
			this.FullCommand = FullCommand;
			string[] parts = FullCommand.Split(' ');
			this.MainCommand = parts[0];
			this.Argument = null;
			if(parts.Length > 1)
				this.Argument = parts[1];
		}
	}

	public enum CommandType{
		Exit,
		List
	}
}

