using System;

namespace IPv4
{
	internal static class Validate
	{

		internal static bool IsValidSubnetMask (byte[] octets)
		{
			if(octets.Length != 4) return false;

			bool foundBoundry = false;

			for (int i = 0; i < 4; i++) {
				if(!foundBoundry){
					if(octets[i] == 255) continue;

					foundBoundry = true;

					if(Utils.validSM.IndexOf(octets[i]) != -1) continue;

					return false;
				} else {
					if(octets[i] != 0) return false;
				}
			}

			return true;
		}

		internal static bool IsValidWildcardMask (byte[] octets)
		{
			bool foundBoundry = false;

			for (int i = 0; i < 4; i++) {
				if(!foundBoundry){
					if(octets[i] == 0) continue;

					foundBoundry = true;

					if(Utils.validWM.IndexOf(octets[i]) != -1) continue;

					return false;
				} else {
					if(octets[i] != 255) return false;
				}
			}

			return true;
		}

		internal static bool IsValidBytes (string[] bytes)
		{
			for (int i = 0; i < bytes.Length; i++) {
				int val = int.Parse(bytes[i]);
				if(val > 255 || val < 0) return false;
			}

			return true;
		}
	}

	internal static class Convert
	{

		internal static int BytesToInt (byte[] octets)
		{
			int prefix = 0;

			for (int i = 0; i < 4; i++)
				prefix += Utils.validSM.IndexOf(octets[i]);

			return prefix;
		}

		internal static byte[] IntToBytes (int prefix)
		{
			byte[] octets = new byte[4];

			int i = 0;

			while (prefix > 8) { 
				octets [i++] = 255;
				prefix -= 8;
			}

			octets[i] = Utils.validSM[prefix];

			return octets;
		}
	}

	public static class Utils{
		static internal byte[] validSM = new byte[] {0, 128, 192, 224, 240, 248, 252, 254, 255};
		static internal byte[] validWM = new byte[] {255, 127, 63, 31, 15, 7, 3, 1, 0};

		public static int IndexOf(this byte[] array, byte item){
			for (int j = 0; j < array.Length; j++)
				if (array [j] == item) 
					return j;

			return -1;
		}
	}
}



