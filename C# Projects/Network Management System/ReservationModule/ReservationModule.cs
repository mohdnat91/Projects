using System;
using System.Collections.Generic;
using System.Linq;
using IPv4;

namespace Modules
{
	public class ReservationModule
	{
		private List<Subnet> networks;
		private List<Subnet> reservedSubnets;

		public ReservationModule ()
		{
			networks = new List<Subnet>();
			reservedSubnets = new List<Subnet>();
		}

		public bool AddSubnet(Subnet subnet){
			var query = from s in networks
						where subnet.IsWithin(s.Network) || subnet.IsWithin(s.Broadcast) || s.IsWithin(subnet.Network) || s.IsWithin(subnet.Broadcast)
						select s;

			if(query.Any()) return false;

			query = from s in networks
					where s.Name == subnet.Name
					select s;

			if(query.Any()) return false;

			networks.Add(subnet);
			return true;
		}

		public bool RemoveSubnet(string Name){
			var query = from s in networks
						where s.Name = Name
						select s;

			Subnet temp = query.First();
			if(temp == null) return false;
			networks.Remove(temp);
			return true;
		}
//
//		public Subnet Reserve(int Mask, string Name){
//		}
//
//		public bool Delete(string Name){
//		}

	}
}

