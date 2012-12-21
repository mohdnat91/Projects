using System;

namespace IPv4
{
	public class WildcardMask
	{
		public readonly byte[] octets;

		public WildcardMask(byte[] octets)
		{
			if(!Validate.IsValidWildcardMask(octets)) throw new ArgumentException();

			this.octets = octets;
		}

		public static SubnetMask operator ~ (WildcardMask mask)
		{
			byte[] octets = new byte[4];

			for(int i = 0; i < 4; i++)
				octets[i] = (byte) ~mask.octets[i];

			return new SubnetMask(octets);
		}

		public static bool operator == (WildcardMask mask1, WildcardMask mask2)
		{
			for(int i = 0; i < 4; i++)
				if(mask1.octets[i] != mask2.octets[i]) return false;
			return true;
		}

		public static bool operator != (WildcardMask mask1, WildcardMask mask2)
		{
			return !(mask1 == mask2);
		}

		public override bool Equals (object obj)
		{
			WildcardMask temp = obj as WildcardMask;
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

