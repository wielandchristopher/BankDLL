#ifdef CUSTOMER_EXPORTS
#define CUSTOMER_API __declspec(dllexport) 
#else
#define CUSTOMER_API __declspec(dllimport) 
#endif

namespace Customer
{
	// This class is exported from the Customer.dll
	class Functions
	{
	public:
		// Returns a + b
		static CUSTOMER_API double Add(double a, double b);

		// Returns a * b
		static CUSTOMER_API double Multiply(double a, double b);

		// Returns a + (a * b)
		static CUSTOMER_API double AddMultiply(double a, double b);
	};
}