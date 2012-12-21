using System;

namespace IPv4
{
	public class IPAddress
	{
		public readonly byte[] octets;

		public IPAddress(byte[] octets)
		{
			if(octets.Length != 4) throw new ArgumentException();
			this.octets = octets;
		}

		public static IPAddress Parse (string address)
		{
			string[] parts = address.Split ('.');
			if (parts.Length != 4 && !Validate.IsValidBytes (parts)) throw new ArgumentException();

			byte[] octets = new byte[4];
			for(int i = 0; i < 4; i++)
				octets[i] = byte.Parse(parts[i]);

			return new IPAddress(octets);
		}

		public static IPAddress operator & (IPAddress address, SubnetMask mask)
		{
			byte[] octets = new byte[4];

			for(int i = 0; i < 4; i++)
				octets[i] = (byte) (address.octets[i] & mask.octets[i]);

			return new IPAddress(octets);
		}

		public static IPAddress operator + (IPAddress address, WildcardMask mask)
		{
			byte[] octets = new byte[4];

			for (int i = 3; i >= 0; i--) {
				int temp = address.octets[i] + mask.octets[i] + octets[i];
				if(temp > 255){
					octets[i+1] +=(byte) (temp - 255);
					temp = 255;
				}

				octets[i] = (byte) temp;
			}

			return new IPAddress(octets);
		}

		public static bool operator == (IPAddress address1, IPAddress address2)
		{
			for(int i = 0; i < 4; i++)
				if(address1.octets[i] != address2.octets[i]) return false;
			return true;
		}

		public static bool operator != (IPAddress address1, IPAddress address2)
		{
			return !(address1 == address2);
		}

		public static bool operator > (IPAddress address1, IPAddress address2)
		{
			for (int i = 0; i < 4; i++) {
				if(address1.octets[i] > address2.octets[i]) return true;
				if(address1.octets[i] < address2.octets[i]) return false;
			}
			return false;
		}

		public static bool operator < (IPAddress address1, IPAddress address2)
		{
			for (int i = 0; i < 4; i++) {
				if(address1.octets[i] < address2.octets[i]) return true;
				if(address1.octets[i] > address2.octets[i]) return false;
			}
			return false;
		}

		public static bool operator >= (IPAddress address1, IPAddress address2)
		{
			return (address1 > address2 || address1 == address2);
		}

		public static bool operator <= (IPAddress address1, IPAddress address2)
		{
			return (address1 < address2 || address1 == address2);
		}

		public override bool Equals (object obj)
		{
			IPAddress temp = obj as IPAddress;
			if(temp == null) return false;

			return temp == this;
		}

		public override int GetHashCode ()
		{
			return ToString().GetHashCode();
		}

		public override string ToString ()
		{
			return string.Format("{0}.{1}.{2}.{3}", octets[0], octets[1], octets[2], octets[3]);
		}
	}
}

