using System;

namespace IPv4
{
	public class SubnetMask
	{
		public readonly int prefixLength;
		public readonly byte[] octets;

		public SubnetMask(int prefixLength)
		{
			if(prefixLength > 32 || prefixLength < 0) throw new ArgumentException();

			this.prefixLength = prefixLength;
			octets = Convert.IntToBytes(prefixLength);
		}

		public SubnetMask(byte[] octets)
		{
			if(!Validate.IsValidSubnetMask(octets)) throw new ArgumentException();

			this.octets = octets;
			prefixLength = Convert.BytesToInt(octets);
		}

		public static SubnetMask Parse (string mask)
		{
			string[] parts = mask.Split ('.');
			if (parts.Length != 4 && !Validate.IsValidBytes (parts)) throw new ArgumentException();

			byte[] octets = new byte[4];
			for(int i = 0; i < 4; i++)
				octets[i] = byte.Parse(parts[i]);

			if(!Validate.IsValidSubnetMask(octets)) throw new ArgumentException();

			return new SubnetMask(octets);
		}

		public static WildcardMask operator ~ (SubnetMask mask)
		{
			byte[] octets = new byte[4];

			for(int i = 0; i < 4; i++)
				octets[i] = (byte) ~mask.octets[i];

			return new WildcardMask(octets);
		}

		public static bool operator == (SubnetMask mask1, SubnetMask mask2)
		{
			for(int i = 0; i < 4; i++)
				if(mask1.octets[i] != mask2.octets[i]) return false;
			return true;
		}

		public static bool operator != (SubnetMask mask1, SubnetMask mask2)
		{
			return !(mask1 == mask2);
		}

		public override bool Equals (object obj)
		{
			SubnetMask temp = obj as SubnetMask;
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

