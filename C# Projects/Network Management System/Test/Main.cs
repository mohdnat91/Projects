using System;
using IPv4;
using UserInterface;
using Modules;

namespace Test
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			SubnetMask m = new SubnetMask (new byte[] {255, 255, 192, 0});
			SubnetMask s = SubnetMask.Parse ("255.255.254.0");
			Console.WriteLine (m.ToString ());
			Console.WriteLine (s.ToString ());
			Console.WriteLine (s == m);
			Console.WriteLine (~m);

			IPAddress ip = IPAddress.Parse ("192.168.3.255");
			IPAddress ip2 = new IPAddress (new byte[] {193, 168, 1, 1});
			Console.WriteLine (ip);
			Console.WriteLine (ip2);
			Console.WriteLine (ip > ip2);

			Console.WriteLine ((ip & s));
			Console.WriteLine ((ip & s) + ~s);

			Subnet sn = Subnet.Parse ("192.168.10.0/24");
			Console.WriteLine (sn);
			Console.WriteLine (sn.IsWithin (IPAddress.Parse ("192.168.9.200")));

//			Terminal terminal = new Terminal (new string[] {"exit", "show", "ip"});
//	
//			Command command;
//
//			while (true) {
//				command = terminal.GetCommand();
//				if(command.MainCommand == "exit") break;
//				if(command.MainCommand == "show" && command.Argument == "ip"){
//					terminal.Print(ip.ToString()+"\n");
//					terminal.Print(ip2.ToString()+"\n");
//				}
//			}

			ReservationModule reservation = new ReservationModule();
			sn = Subnet.Parse("192.168.0.0/16");
			sn.Name = "Hello";
		}
	}
}
