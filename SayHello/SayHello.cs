using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SayHello
{
    public class SayHello
    {
		public string SayHelloTo(string yourName)
		{
			return string.Format("Hello, {0}!", yourName);
		}
    }
}
