using System;

namespace IPv4
{
	public class Subnet
	{
		public readonly IPAddress Network;
		public readonly IPAddress Broadcast;
		public readonly SubnetMask Mask;
		public string Name;

		public Subnet (IPAddress Network, SubnetMask Mask)
		{
			this.Network = Network;
			this.Mask = Mask;
			IPAddress temp = this.Network & this.Mask;
			if(temp != this.Network) throw new ArgumentException();
			this.Broadcast = Network + ~Mask;
		}

		public static Subnet Parse (string subnet)
		{
			string[] parts = subnet.Split('.', '/');

			if(parts.Length != 5 || !Validate.IsValidBytes(parts)) throw new ArgumentException();

			byte[] octets = new byte[4];
			for(int i = 0; i < 4; i++)
				octets[i] = byte.Parse(parts[i]);

			return new Subnet(new IPAddress(octets), new SubnetMask(int.Parse(parts[4])));
		}

		public bool IsWithin (IPAddress address)
		{
			if(address >= this.Network && address <= this.Broadcast) return true;
			return false;
		}

		public override string ToString ()
		{
			return string.Format ("{0}.{1}.{2}.{3}/{4}", Network.octets[0], Network.octets[1], Network.octets[2], Network.octets[3], Mask.prefixLength);
		}
	}
}

