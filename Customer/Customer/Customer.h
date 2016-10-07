#ifdef CUSTOMER_EXPORTS
#define CUSTOMER_API   __declspec( dllexport ) 
#else
#define CUSTOMER_API __declspec(dllimport) 
#endif

#ifdef __cplusplus
extern "C" {
#endif

	CUSTOMER_API void print();

#ifdef __cplusplus
}
#endif

